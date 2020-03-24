//GameServer 1.00.90 JPN - Completed
//Modified by Nemesis (14-03-17)
#include "StdAfx.h"
#include "MonsterItemMng.h"
#include "MonsterAttr.h"
#include "GameMain.h"
#include "LogProc.h"
#include "CashShop.h"

#ifdef __IS_MONSTERDROP__
#include "..\common\winutil.h"
#include "gObjMonster.h"
#include "..\include\ReadScript.h"
#include "DSProtocol.h"
#include "CrywolfSync.h"
#include "Crywolf.h"

int IsLoadMobDropScript = GetPrivateProfileInt("Common","UseCustomItemDrop",0,CONFIG_FILE);

#endif	// __IS_MONSTERDROP__

CMonsterItemMng g_MonsterItemMng;


CMonsterItemMng::CMonsterItemMng()
{
	return;
}


CMonsterItemMng::~CMonsterItemMng()
{
	this->Clear();
}

#ifdef __IS_MONSTERDROP__

BOOL CMonsterItemMng::SendDropConfigItem(LPOBJ lpObj,LPOBJ lpMonObj)
{
	int OriginalDropRate = rand()%10000;
	OriginalDropRate -= 1;
	// ----
	if(OriginalDropRate >= 0)
	{
		//Loading Initial array with values
		int ItemDropList[MaxItemDropScript];
		int ItemFoundCounter = 0;
		int FinalItemPosition = 0;

		//Random used variables
		int DifferenceDropRate = rand()%10000;
		if (DifferenceDropRate + OriginalDropRate > 10000)
			DifferenceDropRate = 10000;
		else
			DifferenceDropRate = DifferenceDropRate + OriginalDropRate;

		//Getting all items with the drop rate bigger or equals to the RAND drop rate
		if ( this->ItemHighestDropRate >= OriginalDropRate )
		{
			for(int i=0;i<this->ItemDropRateCount;i++)
			{
				if(((this->DropRateConfig[i].DropMap == -1) || 
					(this->DropRateConfig[i].DropMap == lpObj->MapNumber )) && 
				   ((lpMonObj->Class == this->DropRateConfig[i].MobId) || 
				    ((lpMonObj->Level >=this->DropRateConfig[i].Minlvl) && 
					(lpMonObj->Level <=this->DropRateConfig[i].Maxlvl))))
				{
					if (lpObj->PartyNumber >= 0 && DropRateConfig[i].PartyRate > 0)
					{
						if (lpObj->Vip > 0)
						{
							if (DropRateConfig[i].VipRate >= 0)
							{
								if( (DropRateConfig[i].VipRate+DropRateConfig[i].PartyRate) >= OriginalDropRate &&
									(DropRateConfig[i].VipRate+DropRateConfig[i].PartyRate) <= DifferenceDropRate) 
								{	
									ItemDropList[ItemFoundCounter]=i;
									ItemFoundCounter += 1;
								}
							} else {
								if( (DropRateConfig[i].Rate+DropRateConfig[i].PartyRate) >= OriginalDropRate &&
									(DropRateConfig[i].Rate+DropRateConfig[i].PartyRate) <= DifferenceDropRate)
								{	
									ItemDropList[ItemFoundCounter]=i;
									ItemFoundCounter += 1;
								}
							}
						} else {
							if((DropRateConfig[i].Rate >= OriginalDropRate)&&(DropRateConfig[i].Rate <= (DifferenceDropRate))) 
							{	
								ItemDropList[ItemFoundCounter]=i;
								ItemFoundCounter += 1;
							}
						}
					} else {
						if (lpObj->Vip > 0)
						{
							if (DropRateConfig[i].VipRate >= 0)
							{
								if( DropRateConfig[i].VipRate >= OriginalDropRate &&
									DropRateConfig[i].VipRate <= DifferenceDropRate) 
								{	
									ItemDropList[ItemFoundCounter]=i;
									ItemFoundCounter += 1;
								}
							} else {
								if( DropRateConfig[i].Rate >= OriginalDropRate &&
									DropRateConfig[i].Rate <= DifferenceDropRate)
								{	
									ItemDropList[ItemFoundCounter]=i;
									ItemFoundCounter += 1;
								}
							}
						} else {
							if((DropRateConfig[i].Rate >= OriginalDropRate)&&(DropRateConfig[i].Rate <= (DifferenceDropRate))) 
							{	
								ItemDropList[ItemFoundCounter]=i;
								ItemFoundCounter += 1;
							}
						}
					}
				}
			}
		}

		if(ItemFoundCounter > 0)
		{
			if(ItemFoundCounter>1)
			{
				FinalItemPosition = rand()%ItemFoundCounter; //Generating a random item from array
			}
			else
			{
				FinalItemPosition = 0;
			}

			int result = ItemDropList[FinalItemPosition];
			int type = this->DropRateConfig[result].Type *512 + this->DropRateConfig[result].Index;

			if ( g_CrywolfSync.GetOccupationState() == CRYWOLF_OCCUPATION_FAILED && g_iCrywolfApplyMvpPenalty )
			{
				// Jewels
				if (type == ITEMGET(12,15) ||	//Jewel of Chaos
					type == ITEMGET(14,13) ||	//Jewel of Bless
					type == ITEMGET(14,14) ||	//Jewel of Soul
					type == ITEMGET(14,16) ||	//Jewel of Life
					type == ITEMGET(14,22) ||	//Jewel of Creation
					type == ITEMGET(14,31) ||	//Jewel of Guardian
					type == ITEMGET(14,42) ||	//Jewel of Harmony
					type == ITEMGET(14,53) ||	//Talisman of Luck
					type == ITEMGET(14,96) ||	//Talisman of Chaos Assembly 

					type == ITEMGET(14,240) ||	//Custom Jewel
					type == ITEMGET(14,241) ||	//Custom Jewel
					type == ITEMGET(14,242) ||	//Custom Jewel
					type == ITEMGET(14,243) ||	//Custom Jewel
					type == ITEMGET(14,244) ||	//Custom Jewel
					type == ITEMGET(14,245) ||	//Custom Jewel
					type == ITEMGET(14,246) ||	//Custom Jewel

					type == ITEMGET(12,30)  ||	//Bundled Jewel of Bless
					type == ITEMGET(12,31)  ||	//Bundled Jewel of Soul

					type == ITEMGET(12,150) ||	//Bundled Jewel of Level
					type == ITEMGET(12,151) ||	//Bundled Jewel of Luck
					type == ITEMGET(12,152) ||	//Bundled Jewel of Skill
					type == ITEMGET(12,153) ||	//Bundled Jewel of Option
					type == ITEMGET(12,154) ||	//Bundled Jewel of Excellent
					type == ITEMGET(12,155)	||	//Bundled Jewel of Ancient
					type == ITEMGET(12,156)		//Bundled Jewel of Socket
					)
				{
					if( (rand()%100) > g_CrywolfSync.GetGemDropPenaltiyRate() )
					{
						return 0;
					}
				}
			}

			//Exc Options
			BYTE ExcOptNum = GenExcOpt(this->DropRateConfig[result].ExcOptNum);

			//z28 option
			BYTE z28Opt = this->DropRateConfig[result].Opt * 100;
			if(this->DropRateConfig[result].Opt > 0)
			{
				z28Opt = (rand()%this->DropRateConfig[result].Opt) + 1;
				z28Opt = z28Opt / 100;
			}

			if(this->DropRateConfig[result].NoTrade == 1)
			{
				MapC[lpMonObj->MapNumber].MonsterItemDrop(type, this->DropRateConfig[result].Level, this->DropRateConfig[result].Duration, 
					lpMonObj->X, lpMonObj->Y, 
					this->DropRateConfig[result].Skill, this->DropRateConfig[result].Luck, z28Opt, ExcOptNum, 0,
					lpObj->m_Index, 
					0xFFFFFFF0,0,0,0);
			}
			else
			{
				ItemSerialCreateSend(lpMonObj->m_Index, lpMonObj->MapNumber, lpMonObj->X, lpMonObj->Y, type, this->DropRateConfig[result].Level, this->DropRateConfig[result].Duration,
					this->DropRateConfig[result].Skill, this->DropRateConfig[result].Luck, z28Opt, lpObj->m_Index, ExcOptNum, 0);
			}

			/*if(ReadConfig.DropLog == TRUE)
			{
				SCF_DROP_LOG.Output("[Drop System][%s][%s] Kill:%d[%d,%d,%d] Found:%d, Pos:[%d/%d], R:%d VR:%d PR:%d OR:%d DR:%d Item:[%s][%d][%d][%d][%d => %d] Exc:[%d => %d]", 
					lpObj->AccountID,lpObj->Name,
					lpMonObj->Class,lpMonObj->MapNumber,lpMonObj->X,lpMonObj->Y,
					ItemFoundCounter, FinalItemPosition, result, 
					DropRateConfig[result].Rate,
					DropRateConfig[result].VipRate,
					DropRateConfig[result].PartyRate,
					OriginalDropRate,DifferenceDropRate,
					ItemAttribute[type].Name,
					this->DropRateConfig[result].Level,
					this->DropRateConfig[result].Skill, 
					this->DropRateConfig[result].Luck, 
					this->DropRateConfig[result].Opt, z28Opt,
					this->DropRateConfig[result].ExcOptNum,
					ExcOptNum
				);
			}*/
			return TRUE;
		}
	}
	return FALSE;
}

void CMonsterItemMng::ItemDropLoadScript(char * FilePath)
{
	this->ItemDropRateCount		= 0;
	this->ItemHighestDropRate	= 0;
	// ----
	int i = 0;
	// ----
	if(IsLoadMobDropScript == 1)
	{
		int Token;
		// ----
		SMDFile = fopen(FilePath,"r");
		// ----
		if( SMDFile == NULL )
		{
			MsgBox("%s file corrupted.",FilePath);
			return;
		}
		// ----
		while(true)
		{
			int iType = GetToken();
			iType = TokenNumber;
			// ----
			if ( iType == 0 )
			{
				while(true)
				{
					if( (i+1) >= MaxItemDropScript)
						break; 
					// ----
					Token = GetToken();
					if ( strcmp("end", TokenString) == 0 )
					{
						break;
					}else
					{
						this->DropRateConfig[i].Type		= TokenNumber;
						Token = GetToken();
						this->DropRateConfig[i].Index		= TokenNumber;
						Token = GetToken();
						this->DropRateConfig[i].Level		= TokenNumber;
						Token = GetToken();
						this->DropRateConfig[i].Opt			= TokenNumber;
						Token = GetToken();
						this->DropRateConfig[i].Luck		= TokenNumber;
						Token = GetToken();	
						this->DropRateConfig[i].Skill		= TokenNumber;
						Token = GetToken();
						this->DropRateConfig[i].Duration	= TokenNumber;
						Token = GetToken();	
						this->DropRateConfig[i].ExcOptNum	= TokenNumber;
						Token = GetToken();	
						this->DropRateConfig[i].Rate		= TokenNumber;
						Token = GetToken();	
						this->DropRateConfig[i].VipRate		= TokenNumber;
#if (DSGN_DROP_PARTYEXTRA == 1)
						Token = GetToken();	
						this->DropRateConfig[i].PartyRate	= TokenNumber;
#else
						this->DropRateConfig[i].PartyRate	= 0;
#endif						
						Token = GetToken();	
						this->DropRateConfig[i].NoTrade		= TokenNumber;
						Token = GetToken();	
						this->DropRateConfig[i].MobId		= TokenNumber;
						Token = GetToken();	
						this->DropRateConfig[i].Minlvl		= TokenNumber;
						Token = GetToken();
						this->DropRateConfig[i].Maxlvl		= TokenNumber;	
						Token = GetToken();
						this->DropRateConfig[i].DropMap		= TokenNumber;

						if (this->ItemHighestDropRate < this->DropRateConfig[i].Rate)
						{
							this->ItemHighestDropRate = this->DropRateConfig[i].Rate;
						}

						if (this->ItemHighestDropRate < this->DropRateConfig[i].VipRate)
						{
							this->ItemHighestDropRate = this->DropRateConfig[i].VipRate;
						}

						i++;
					}
				}
			}
			break;
		}
		// ----
		this->ItemDropRateCount = i;
		fclose(SMDFile);
		LogAddTD("[ItemDropLoadScript][Items: %d] - %s file is Loaded",i,FilePath);
		// ----
		this->ShuffleDropScript(3);
	}
}

void CMonsterItemMng::ShuffleDropScript(BYTE runs)
{
	if ( this->ItemDropRateCount > 0 )
	{
		srand(time(0)); 
		int i = this->ItemDropRateCount;

		for (int rnd=0; rnd < runs; rnd++)
		{
			//--- Shuffle elements by randomly exchanging each with one other.
			for (int j=0; j < (i-1); j++) 
			{
				int r = j + (rand() % (i-1)); // Random remaining position.

				BYTE Type = this->DropRateConfig[i].Type;
				BYTE Index = this->DropRateConfig[i].Index;
				BYTE Level = this->DropRateConfig[i].Level;
				BYTE Opt = this->DropRateConfig[i].Opt;
				BYTE Luck = this->DropRateConfig[i].Luck;
				BYTE Skill = this->DropRateConfig[i].Skill;
				BYTE Duration = this->DropRateConfig[i].Duration;
				BYTE ExcOptNum = this->DropRateConfig[i].ExcOptNum;
				WORD Rate = this->DropRateConfig[i].Rate;
				WORD VipRate = this->DropRateConfig[i].VipRate;
				BYTE NoTrade = this->DropRateConfig[i].NoTrade;
				short MobId = this->DropRateConfig[i].MobId;
				BYTE Minlvl = this->DropRateConfig[i].Minlvl;
				BYTE Maxlvl = this->DropRateConfig[i].Maxlvl;
				short DropMap = this->DropRateConfig[i].DropMap;

				this->DropRateConfig[i].Type = this->DropRateConfig[r].Type;
				this->DropRateConfig[i].Index = this->DropRateConfig[r].Index;
				this->DropRateConfig[i].Level = this->DropRateConfig[r].Level;
				this->DropRateConfig[i].Opt = this->DropRateConfig[r].Opt;
				this->DropRateConfig[i].Luck = this->DropRateConfig[r].Luck;
				this->DropRateConfig[i].Skill = this->DropRateConfig[r].Skill;
				this->DropRateConfig[i].Duration = this->DropRateConfig[r].Duration;
				this->DropRateConfig[i].ExcOptNum = this->DropRateConfig[r].ExcOptNum;
				this->DropRateConfig[i].Rate = this->DropRateConfig[r].Rate;
				this->DropRateConfig[i].VipRate = this->DropRateConfig[r].VipRate;
				this->DropRateConfig[i].NoTrade = this->DropRateConfig[r].NoTrade;
				this->DropRateConfig[i].MobId = this->DropRateConfig[r].MobId;
				this->DropRateConfig[i].Minlvl = this->DropRateConfig[r].Minlvl;
				this->DropRateConfig[i].Maxlvl = this->DropRateConfig[r].Maxlvl;
				this->DropRateConfig[i].DropMap = this->DropRateConfig[r].DropMap;

				this->DropRateConfig[r].Type = Type;
				this->DropRateConfig[r].Index = Index;
				this->DropRateConfig[r].Level = Level;
				this->DropRateConfig[r].Opt = Opt;
				this->DropRateConfig[r].Luck = Luck;
				this->DropRateConfig[r].Skill = Skill;
				this->DropRateConfig[r].Duration = Duration;
				this->DropRateConfig[r].ExcOptNum = ExcOptNum;
				this->DropRateConfig[r].Rate = Rate;
				this->DropRateConfig[r].VipRate = VipRate;
				this->DropRateConfig[r].NoTrade = NoTrade;
				this->DropRateConfig[r].MobId = MobId;
				this->DropRateConfig[r].Minlvl = Minlvl;
				this->DropRateConfig[r].Maxlvl = Maxlvl;
				this->DropRateConfig[r].DropMap = DropMap;
			}
		}
		// ----
		LogAddTD("[ItemDropLoadScript] Item Shuffle completed, Items:%d, Runs: %d",this->ItemDropRateCount,runs);
	}
}

#endif	// __IS_MONSTERDROP__

void CMonsterItemMng::Init()
{
	memset(this->m_iMonsterInvenItemCount, 0, sizeof(this->m_iMonsterInvenItemCount));

	for ( int i=0 ; i< MAX_LEVEL_MONSTER ; i++ )
	{
		this->m_MonsterInvenItems[i] = new CItem[MAX_ITEM_IN_MONSTER];
	}

	LPMONSTER_ATTRIBUTE lpm;

	for ( int i = 0; i< MAX_MONSTER_TYPE ; i++ )
	{
		lpm = gMAttr.GetAttr(i);

		if ( lpm != NULL )
		{
			strcpy( this->MonsterName, lpm->m_Name);

			if ( lpm->m_Level != 0 )
			{
				this->gObjGiveItemSearch(lpm->m_Level, lpm->m_MaxItemLevel);
			}
		}
	}
}


void CMonsterItemMng::Clear()
{
	memset(this->m_iMonsterInvenItemCount, 0, sizeof(this->m_iMonsterInvenItemCount));

	for ( int i =0 ; i< MAX_LEVEL_MONSTER ; i++ )
	{
		delete this->m_MonsterInvenItems[i];
	}
}

BYTE CMonsterItemMng::InsertItem(int monsterlevel, int type, int index, int itemlevel, int op1, int op2 ,int op3 )
{
	if ( monsterlevel > MAX_LEVEL_MONSTER || monsterlevel < 0 )
	{
		return -1;
	}

	int itemcount = this->m_iMonsterInvenItemCount[monsterlevel];

	if ( itemcount >= MAX_ITEM_IN_MONSTER )
	{
		return -1;
	}

	CItem * item = &this->m_MonsterInvenItems[monsterlevel][itemcount];
	int item_type = (type * MAX_SUBTYPE_ITEMS) + index;
	item->m_Level = itemlevel;
	item->Convert(item_type, op1, op2, op3, 0, 0,0, NULL, 0xFF, CURRENT_DB_VERSION);

	if ( type == 13 && index == 10 )
	{
		int rd = rand() % 100;
		item->m_Durability = rd + 100.0f;
	}
	else
	{
		item->m_Durability = item->m_BaseDurability;
	}

	itemcount ++;
	this->m_iMonsterInvenItemCount[monsterlevel] = itemcount;
	return 0;
}


CItem * CMonsterItemMng::GetItem(int monsterlevel)
{
	if ( monsterlevel > MAX_LEVEL_MONSTER || monsterlevel < 0 )
	{
		return NULL;
	}

	int itemcount = this->m_iMonsterInvenItemCount[monsterlevel];

	if ( itemcount <= 0 )
	{
		return NULL;
	}

	int itemindex = rand() % itemcount;
	return &this->m_MonsterInvenItems[monsterlevel][itemindex];
}

void CMonsterItemMng::gObjGiveItemSearch(int monsterlevel, int maxlevel)
{
	int result;
	int incount = 0;
	int type;
	int index;

	if ( monsterlevel > MAX_LEVEL_MONSTER-1 )
	{
		LogAdd("error-L3 : Monster Level Overflow~ %s %d", __FILE__, __LINE__ );
		return;
	}

	int BallTable[22]; //season 4.5 changed

	BallTable[0] = 7;
	BallTable[1] = 8;
	BallTable[2] = 9;
	BallTable[3] = 10;
	BallTable[4] = 11;
	BallTable[5] = 12;
	BallTable[6] = 13;
	BallTable[7] = 14;
	BallTable[8] = 16;
	BallTable[9] = 17;
	BallTable[10] = 18;
	BallTable[11] = 19;
	BallTable[12] = 21;
	BallTable[13] = 22;
	BallTable[14] = 23;
	BallTable[15] = 24;
	BallTable[16] = 35;
	BallTable[17] = 44;//Season 4.5 addon
    BallTable[18] = 45;//Season 4.5 addon
    BallTable[19] = 46;//Season 4.5 addon
    BallTable[20] = 47;//Season 4.5 addon
    BallTable[21] = 48;//Season 4.5 addon

	while ( true )
	{
		if ( (rand() % 20) ==  0 ) 
		{
			if ( (rand() % 2)	!= 0 )
			{
				type = MAX_TYPE_ITEMS-1;
				index = rand() % (g_MaxItemIndexOfEachItemType[type]+1);
			}
			else
			{
				type = 12;
				index = BallTable[rand() % 17];
			}
		}
		else
		{
			type = rand() % MAX_TYPE_ITEMS;
			int iMaxItemIndex = g_MaxItemIndexOfEachItemType[type]+1;
			index = rand() % iMaxItemIndex;

			if ( type == 15 || (type == 12 && index != 15 ) )
			{
				continue;
			}
		}

		if ( type == 13 && index == 3 )
		{
			continue;
		}

		if ( (type == 13 && index == 32)
          || (type == 13 && index == 33)
          || (type == 13 && index == 34)
          || (type == 13 && index == 35)
          || (type == 13 && index == 36)
          || (type == 13 && index == 37) )
		{
			continue;
		}

        if ( (type == 14 && index == 35)
          || (type == 14 && index == 36)
          || (type == 14 && index == 37)
          || (type == 14 && index == 38)
          || (type == 14 && index == 39)
          || (type == 14 && index == 40) )
		{
			continue;
		}

        if ( IsCashItem(ITEMGET(type, index)) == TRUE )
		{
			continue;
		}

		if ( CanItemTouchCash(ITEMGET(type, index)) == TRUE )
		{
			continue;
		}
        
		//season 3.0 add-on
		if( (type == 14 && index == 45) ||
			(type == 14 && index == 46) ||
			(type == 14 && index == 47) ||
			(type == 14 && index == 48) ||
			(type == 14 && index == 49) ||
			(type == 14 && index == 50) ) 
		{
			continue;
		}

		//season 2.5 add-on
		if( (type == 13 && index == 41) ) 
		{
			continue;
		}

		if ( (type == 13 && index < 8) || 
			( (type == 14) && (index == 9 || index == 10 ||	index == 13 || index == 14 || index ==16 || index == 17 || index == 18 || index == 22 ) ) ||
			(type == 12 && index == 15) || 
			(type == 13 && index == 14) || 
			(type == 14 && index == 31 ) )
		{
			int perc = rand() % 11;
			BOOL bCheckDevil = FALSE;

			if ( type == 12 && index == 15 )
			{
				if ( monsterlevel >= 13 && monsterlevel <= 66 )
				{
					perc = rand() % 7 ;
					
					if ( perc < 3 )
					{
						perc = 0;
					}
				}
				else
				{
					perc = 1;
				}
			}

			if ( type == 14 && index == 17 )
			{
				if ( gEyesOfDevilSquareDropRate <= 0 )
				{
					gEyesOfDevilSquareDropRate = 1;
				}

				perc = rand() % gEyesOfDevilSquareDropRate;
				bCheckDevil = 1;

				if ( gDevilSquareEvent == 0 )
				{
					perc = 1;
				}
			}

			if ( type == 14 && index == 18 )
			{
				perc = rand() % gKeyOfDevilSquareDropRate;
				bCheckDevil = 1;

				if ( gDevilSquareEvent == 0 )
				{
					perc = 1;
				}

			}

			if ( perc == 0 )
			{
				if ( bCheckDevil == 1 )
				{
					int devilitemlevel = 0;

					if ( (rand() % 5) != 0 )
					{
						if ( monsterlevel < 3 )
						{
							devilitemlevel = 0;
						}
						else if ( monsterlevel < 36 ) 
						{
							devilitemlevel = 1;
						}
						else if ( monsterlevel < 47 )
						{
							devilitemlevel = 2;
						}
						else if ( monsterlevel < 60 )
						{
							devilitemlevel = 3;
						}
						else if ( monsterlevel < 70 )
						{
							devilitemlevel = 4;
						}
						else if ( monsterlevel < 80 )
						{
							devilitemlevel = 5;
						}
						else 
						{
							devilitemlevel = 6;
						}

						if ( devilitemlevel != 0 )
						{
							if ( this->InsertItem(monsterlevel, type, index, devilitemlevel, 0, 0, 0) != 0xFF )
							{
								incount++;

								if ( incount > MAX_ITEM_IN_MONSTER -1 )
								{
									return;
								}
							}
						}
					}
				}
				else if ( zzzItemLevel(type, index, monsterlevel ) == TRUE )
				{
					if ( this->InsertItem(monsterlevel, type, index, 0, 0, 0, 0) != (BYTE)-1 )
					{
						incount++;

						if ( incount > MAX_ITEM_IN_MONSTER -1 )
						{
							return;
						}
					}
				}
			}
		}
		else
		{
			result = GetLevelItem(type, index, monsterlevel);

			if ( result >= 0 )
			{
				if ( (type == 13 && index == 10) || (type == 12 && index == 11 ) )
				{
					if ( this->InsertItem(monsterlevel, type, index, result, 0,0,0) != 0xFF )
					{
						incount++;

						if ( incount > MAX_ITEM_IN_MONSTER -1 )
						{
							return;
						}
					}
				}
				else if ( result <= maxlevel )
				{
					if ( type == 12 )
					{
						if ( index != 11 )
						{
							result = 0;
						}
					}

					if ( type == 12 && index == 11 )
					{

					}
					else
					{
						if ( result > maxlevel )
						{
							result = maxlevel;
						}
					}

					if ( (type == 4 && index == 7) || (type == 4 && index == 15) )
					{
						result = 0;
					}
				

					if ( this->InsertItem(monsterlevel, type, index,result, 0,0,0) != (BYTE)-1 )
					{
						incount++;

						if ( incount > MAX_ITEM_IN_MONSTER-1 )
						{
							return;
						}
					}
				}
			}
		}
		
		if ( this->m_iMonsterInvenItemCount[monsterlevel] >= MAX_ITEM_IN_MONSTER )
		{
			return;
		}
		
	}
}
