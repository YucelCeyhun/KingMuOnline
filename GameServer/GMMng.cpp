//GameServer 1.00.77 JPN - Completed
//GameServer 1.00.90 JPN - Completed
#include "stdafx.h"
#include "GMMng.h"
#include "LogToFile.h"
#include "logproc.h"
#include "GameMain.h"
#include "protocol.h"
#include "..\common\winutil.h"
#include "MoveCommand.h"
#include "GuildClass.h"
#include "TNotice.h"
#include "BattleSoccerManager.h"
#include "giocp.h"
#include "Kanturu.h"
#include "SkillAdditionInfo.h"
#include "DSProtocol.h"
#include "BuffManager.h"
#include "MasterLevelSystem.h"
#include "ObjCalCharacter.h"
#include "MasterSkillSystem.h"
#include "MapClass.h"
#include "MonsterAttr.h"
#include "..\common\SetItemOption.h"
#include "ItemAddOption.h"
#include "DarkSpirit.h"
#include "IllusionTempleEvent.h"
#include "Raklion.h"
#include "RaklionBattleUserMng.h"
#include "ChaosCard.h"
#include "PCBangPointSystem.h"
#include "Utilities.h"

CLogToFile KUNDUN_GM_LOG( "KUNDUN_EVENT_GM_LOG", ".\\KUNDUN_EVENT_GM_LOG", 1);

CGMMng cManager;

CGMMng::CGMMng()
{
	this->ManagerInit();
}

CGMMng::~CGMMng()
{
	return;
}

void CGMMng::Init()
{
	this->cCommand.Init();

	this->cCommand.Add("/gmove", 102, 0x32);
	this->cCommand.Add("/move", 101, 1);

	this->WatchTargetIndex = -1;
}

void CGMMng::ManagerInit()
{
	for ( int n = 0;n<MAX_GAME_MASTER ; n++ )
	{
		this->ManagerIndex[n] = -1;
	}
}

int CGMMng::ManagerAdd(char* name, int aIndex)
{
	for ( int n=0 ; n<MAX_GAME_MASTER ; n++ )
	{
		if ( this->ManagerIndex[n] == -1 )
		{
			strcpy(this->szManagerName[n], name);
			this->ManagerIndex[n] = aIndex;
			return n;
		}
	}

	return -1;
}

void CGMMng::ManagerDel(char* name)
{
	for ( int n=0;n<MAX_GAME_MASTER;n++)
	{
		if ( this->ManagerIndex[n] != -1 )
		{
			if ( strcmp(this->szManagerName[n], name) == 0 )
			{
				this->ManagerIndex[n] = -1;
				return;
			}
		}
	}
}

void CGMMng::ManagerSendData(LPSTR szMsg, int size)
{
	for ( int n=0;n<MAX_GAME_MASTER;n++ )
	{
		if ( this->ManagerIndex[n] != -1 )
		{
			GCServerMsgStringSend(szMsg, this->ManagerIndex[n], 0);
		}
	}
}

void CGMMng::DataSend(LPBYTE szMsg, int size)
{
	for ( int n=0;n<MAX_GAME_MASTER;n++ )
	{
		if ( this->ManagerIndex[n] != -1 )
		{
			::DataSend(this->ManagerIndex[n], szMsg, size);
		}
	}
}

void CGMMng::BattleInfoSend(char* Name1, BYTE score1, char* Name2, BYTE score2)
{
	for ( int n=0;n<MAX_GAME_MASTER;n++ )
	{
		if ( this->ManagerIndex[n] != -1 )
		{
			GCGoalSend(this->ManagerIndex[n], Name1, score1, Name2, score2);
		}
	}
}

int CGMMng::GetCmd(char* szCmd)
{
	for ( int n	=0; n< MAX_GM_COMMAND ; n++ )
	{
		if ( this->cCommand.nCmdCode[n] > 0 )
		{
			if ( stricmp(szCmd, this->cCommand.szCmd[n]) == 0 )
			{
				return this->cCommand.nCmdCode[n];
			}
		}
	}

	return 0;
}

BYTE CGMMng::GetData(char *szCmd,int &command_code,int &gamemaster_code)
{
	for ( int n	=0; n< MAX_GM_COMMAND ; n++ )
	{
		if ( this->cCommand.nCmdCode[n] > 0 )
		{
			if ( stricmp(szCmd, this->cCommand.szCmd[n]) == 0 )
			{
				command_code = this->cCommand.nCmdCode[n];
				gamemaster_code = this->cCommand.nGMCode[n];

				return TRUE;
			}
		}
	}

	return 0;
}

char* CGMMng::GetTokenString()
{
	char seps[] = " ";
	return strtok(NULL, seps);
}

int CGMMng::GetTokenNumber()
{
	char seps[] = " ";
	char * szToken;

	szToken = strtok(NULL, seps);

	if( szToken != NULL )
	{
		return atoi(szToken);
	}
	return 0;
}

void CGMMng::MsgYellow(int aIndex,char* szMsg,...)
{
	char szTemp[1024];
	BYTE *Packet;

	va_list pArguments;
	va_start(pArguments,szMsg);
	vsprintf(szTemp,szMsg,pArguments);
	va_end(pArguments);

	Packet = (BYTE*)malloc(200);
	memset(Packet,0x00,200);
	*Packet=0xC1;
	*(Packet+2)=0x02;

	memcpy((Packet+13),szTemp,strlen(szTemp));

	int Len=(strlen(szTemp)+0x13);
	*(Packet+1)=Len;

	::DataSend(aIndex,Packet,Len);
	free(Packet);
}

void MsgSrv(char *Sender,char *Message, int Type)
{		 
	BYTE *Packet;
	Packet = (BYTE*) malloc(200);
	memset(Packet, 0x00, 200);
	*Packet = 0xC1;
	if(Type)
		*(Packet+2) = 0x02;	  
	else				   
		*(Packet+2) = 0x00;
	memcpy((Packet+3), Sender, strlen(Sender));
	memcpy((Packet+13), Message, strlen(Message));
	int Len = (strlen(Message) + 0x13);
	*(Packet+1) = Len;
	DataSendAll(Packet, Len);
	free (Packet);
}

void MessageSendEx(int Type, char * Sender, char * Message, ...)
{
	char szTemp[1024];
	va_list pArguments;
	va_start(pArguments, Message);
	vsprintf(szTemp, Message, pArguments);
	va_end(pArguments);
	// ----
	CHAT_WHISPER_EX pMessage;
	memcpy(pMessage.Name, Sender, 10);
	memcpy(pMessage.Message, szTemp, 90);
	pMessage.Type = Type;
	pMessage.Head.set((LPBYTE)&pMessage, 2, sizeof(CHAT_WHISPER_EX));
	DataSendAll((LPBYTE)&pMessage, pMessage.Head.size);
}

void CGMMng::MessageAll(int Type, int Type2, char *Sender, char *Msg,...)
{					  
	char Messages[1024];
	ZeroMemory(Messages, sizeof(Messages));
	char Temp[255]; 
	strcpy(Temp,Msg);
	va_list pArguments1;
	va_start(pArguments1, Msg);
	vsprintf_s(Messages, Temp, pArguments1);
	va_end(pArguments1); 

	if(Type == 2)
	{
		MsgSrv(Sender, Messages, Type2);
	}
	else
	{
		for(int i = OBJMAX - OBJMAXUSER; i <= OBJMAX; i++)
		{  	 			
			LPOBJ lpObj = &gObj[i];
			if(lpObj->Connected < PLAYER_PLAYING)	continue;
			GCServerMsgStringSend(Messages, i, Type);
		}
	}
}

int CGMMng::ManagementProc(LPOBJ lpObj, char* szCmd, int aIndex)
{
	char seps[] = " ";
	char *szCmdToken;
	char string[256];
	char szId[20];
	char *pId = szId;

	int len= strlen(szCmd);
	if( len < 1 || len > 250 ) return FALSE;

	memset(szId, 0, 20);

	strcpy(string, szCmd);
	
	szCmdToken = strtok(string, seps);
	int command_number = GetCmd(szCmdToken);

	int command_code,gamemaster_code;

	if(this->GetData(szCmdToken,command_code,gamemaster_code) == FALSE)
	{
		return FALSE;
	}
	
	if(CheckAuthorityCondition(gamemaster_code,lpObj) == FALSE)
	{
		return FALSE;
	}

	switch ( command_code )
	{
		case 101: // MOVE
		{
			pId = this->GetTokenString();
			
			if ( pId != NULL )
			{
				int lc165 = -1;
				int lc166 = 0;
				int lc167 = 0;
				
				if ( lpObj->Teleport != 0 )
				{
					GCServerMsgStringSend(lMsg.Get(MSGGET(6, 68)), lpObj->m_Index, 1);
					return 0;
				}
				
				if ( (lpObj->m_IfState.use) != 0 )
				{
					if ( lpObj->m_IfState.type  == 3 )
					{
						lpObj->TargetShopNumber = -1;
						lpObj->m_IfState.type = 0;
						lpObj->m_IfState.use = 0;
					}
				}
				
				if ( lpObj->m_IfState.use > 0 )
				{
					GCServerMsgStringSend(lMsg.Get(MSGGET(6, 68)), lpObj->m_Index, 1);
					return 0;
				}
				
				if ( gObj[aIndex].IsInBattleGround != false )
				{
					GCServerMsgStringSend(lMsg.Get(MSGGET(6, 68)), lpObj->m_Index, 1);
					return 0;
				}
				
				BOOL bPlayerKiller = FALSE; //Season 2.5 add-on
				
				if(gObj[aIndex].PartyNumber >= 0) //Season 2.5 add-on
				{
					if(gParty.GetPkLevel(gObj[aIndex].PartyNumber) >= 5)
					{
						bPlayerKiller = TRUE;
					}
				}
				else if(gObj[aIndex].m_PK_Level >= 5)
				{
					bPlayerKiller = TRUE;
				}
				
				if ( bPlayerKiller == TRUE )
				{
					GCServerMsgStringSend(lMsg.Get(MSGGET(4, 101)), lpObj->m_Index, 1);
					return 0;
				}

				gMoveCommand.Move(lpObj, pId);
			}
		}
		break;

		case 102: // MOVE GM
		{
			if(CheckAuthorityCondition(34,lpObj) == 1)
			{
				pId = this->GetTokenString();

				if ( pId == NULL )
				{
					return 0;
				}

				int iTokenNumber1 = this->GetTokenNumber();
				int iTokenNumber2 = this->GetTokenNumber();
				int iTokenNumber3 = this->GetTokenNumber();
				int iIndex = gObjGetIndex(pId);
				LPOBJ lpTargetObj;

				if ( iIndex >= 0 )
				{
					lpTargetObj = gObjFind(pId);

					if ( lpTargetObj == NULL )
					{
						return 0;
					}

					LogAddTD("Use GM Command -> [ %s ]\t[ %s ]\t[ %s ] / Target : [%s][%s] : %s", lpObj->Ip_addr, lpObj->AccountID, lpObj->Name, lpTargetObj->AccountID, lpTargetObj->Name, "User SetPosition");
					gObjTeleport(iIndex, iTokenNumber1, iTokenNumber2, iTokenNumber3);
				}
			}
		}
		break;
		
        case 503:
   		{
			char * szName = this->GetTokenString();
			int ct = this->GetTokenNumber();
			this->CmdSummonMonster(lpObj,szName,ct);
		}
		break;

        case 504:
		{
			this->CmdClearMonster(lpObj,this->GetTokenNumber());
		}
		break;

        case 505:
		{
			this->CmdClearItem(lpObj,this->GetTokenNumber());
		}
		break;

        case 506:
		{
			this->CmdClearInven(lpObj);
		}
		break;

        case 507:
		{
			this->CmdSummonChar(lpObj,this->GetTokenString());
		}
		break;
	}
	return 0;
}

void CGMMng::GetInfinityArrowMPConsumption(LPOBJ lpObj)
{
	MsgOutput(lpObj->m_Index, "인피니티 애로우 MP 소모량[+0:%d] [+1:%d] [+2:%d]",
		g_SkillAdditionInfo.GetInfinityArrowMPConsumptionPlus0(),
		g_SkillAdditionInfo.GetInfinityArrowMPConsumptionPlus1(),
		g_SkillAdditionInfo.GetInfinityArrowMPConsumptionPlus2());
}

void CGMMng::ControlInfinityArrowMPConsumption0(LPOBJ lpObj, int iValue)
{
	g_SkillAdditionInfo.SetInfinityArrowMPConsumptionPlus0(iValue);
	MsgOutput(lpObj->m_Index, "인피니티 애로우 MP 소모량 변경(+0) : %d",iValue);

}	

void CGMMng::ControlInfinityArrowMPConsumption1(LPOBJ lpObj, int iValue)
{
	g_SkillAdditionInfo.SetInfinityArrowMPConsumptionPlus1(iValue);
	MsgOutput(lpObj->m_Index, "인피니티 애로우 MP 소모량 변경(+1) : %d",iValue);

}

void CGMMng::ControlInfinityArrowMPConsumption2(LPOBJ lpObj, int iValue)
{
	g_SkillAdditionInfo.SetInfinityArrowMPConsumptionPlus2(iValue);
	MsgOutput(lpObj->m_Index, "인피니티 애로우 MP 소모량 변경(+2) : %d",iValue);

}

void CGMMng::ControlInfinityArrowMPConsumption3(LPOBJ lpObj, int iValue)
{
	g_SkillAdditionInfo.SetInfinityArrowMPConsumptionPlus3(iValue);
	MsgOutput(lpObj->m_Index, "인피니티 애로우 MP 소모량 변경(+3) : %d",iValue);
}

void CGMMng::SetInfinityArrowTime(LPOBJ lpObj, int iValue)
{
	if ( lpObj->Class == CLASS_ELF && lpObj->Type == OBJ_USER && lpObj->ChangeUP == 1 )
	{
		MsgOutput(lpObj->m_Index, "인피니티 애로우 시간 강제 설정 : %d초", iValue);
	}
	else
	{
		MsgOutput(lpObj->m_Index, "220레벨 이상 뮤즈엘프만 사용가능합니다.");
	}
}

void CGMMng::ControlFireScreamDoubleAttackDistance(LPOBJ lpObj, int iValue)
{
	g_SkillAdditionInfo.SetFireScreamExplosionAttackDistance(iValue);
	MsgOutput(lpObj->m_Index, "파이어스크림 더블데미지 폭발거리 변경:%d", iValue);
}

void CGMMng::CmdSummonMonster(LPOBJ lpObj,char *szMonsterName,int MonsterCount)
{
	char szText[256];

	memset(szText,0,sizeof(szText));

	if(MonsterCount < 1)
	{
		MonsterCount = 1;
	}

	if(szMonsterName == NULL)
	{
		GCServerMsgStringSend("Result-Invalid Argument", lpObj->m_Index, 1);
		return;
	}

	if(MonsterCount > 20)
	{
		GCServerMsgStringSend("Result-Too Manay Count", lpObj->m_Index, 1);
		return;
	}

	BYTE MapAttr = MapC[lpObj->MapNumber].GetAttr(lpObj->X, lpObj->Y);

	if ( (MapAttr &1) == 1 )
	{
		GCServerMsgStringSend("Result-Is Safetyzone", lpObj->m_Index, 1);
		return;
	}
	
	int MonsterClass = atoi(szMonsterName);//loc67
	LPMONSTER_ATTRIBUTE lpMonsterAttr = NULL;//loc68

	if(MonsterClass != 0)
	{
		lpMonsterAttr = gMAttr.GetAttr(MonsterClass);
	}
	else
	{
		lpMonsterAttr = gMAttr.GetAttr(szMonsterName);
	}

	if(lpMonsterAttr == NULL)
	{
		GCServerMsgStringSend("Result-Monster Not Found", lpObj->m_Index, 1);
		return;
	}

	if(this->GetType(lpMonsterAttr->m_Index) != OBJ_MONSTER)
	{
		GCServerMsgStringSend("Result-Monster Not Found", lpObj->m_Index, 1);
		return;	
	}

	for(int i = 0; i < MonsterCount; i++)
	{
		BYTE X = lpObj->X;
		BYTE Y = lpObj->Y;

		int iMonsterIndex = gObjAddMonster(lpObj->MapNumber);

		if ( iMonsterIndex >= 0 )
		{
			gObj[iMonsterIndex].m_btSummonedbyGM = 1;//i think its m_btSummonedbyGM
			gObj[iMonsterIndex].m_PosNum = -1;
			gObj[iMonsterIndex].X = X;
			gObj[iMonsterIndex].Y = Y;
			gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
			gObj[iMonsterIndex].TX = gObj[iMonsterIndex].X;
			gObj[iMonsterIndex].TY = gObj[iMonsterIndex].Y ;
			gObj[iMonsterIndex].m_OldX = gObj[iMonsterIndex].X;
			gObj[iMonsterIndex].m_OldY = gObj[iMonsterIndex].Y;
			gObj[iMonsterIndex].StartX = gObj[iMonsterIndex].X;
			gObj[iMonsterIndex].StartY = gObj[iMonsterIndex].Y;
			gObj[iMonsterIndex].Level = lpMonsterAttr->m_Level;
			gObj[iMonsterIndex].m_Attribute = 60;
			gObj[iMonsterIndex].MaxRegenTime = 0;
			gObj[iMonsterIndex].Dir = rand() % 8;
			gObjSetMonster(iMonsterIndex,lpMonsterAttr->m_Index );
		}
	}

	wsprintf(szText, "Result-SummonMonster(%s:%d)", lpMonsterAttr->m_Name, MonsterCount);
	GCServerMsgStringSend(szText, lpObj->m_Index, 1);
}

void CGMMng::CmdClearMonster(LPOBJ lpObj,int Dis)
{
	char szText[256];

	memset(szText,0,sizeof(szText));
	
	if(Dis <= 0)
	{
		GCServerMsgStringSend("Result-Invalid Argument", lpObj->m_Index, 1);
		return;
	}

	int MapNumber = lpObj->MapNumber;//loc66
	int DeletedMonCount = 0;

	for(int i = 0;i<OBJ_MAXMONSTER;i++)
	{
		LPOBJ lpMonObj = &gObj[i];//loc69

		if( lpMonObj->MapNumber == MapNumber && 
			gObj[i].Connected == PLAYER_PLAYING &&
			gObj[i].Type == OBJ_MONSTER &&
			lpMonObj->Live != 0 &&
			lpMonObj->m_State == 2 )
		{
			if(gObjCalDistance(lpObj, lpMonObj) <= Dis)
			{
				if(lpMonObj->m_btSummonedbyGM == 1)
				{
					gObjDel(lpMonObj->m_Index);
				}
				else
				{
					lpMonObj->Live = 0;
					lpMonObj->m_State = 4;
					lpMonObj->RegenTime = GetTickCount();
					lpMonObj->DieRegen = 1;
					lpMonObj->PathCount = 0;
					GCDiePlayerSend( lpMonObj, lpMonObj->m_Index, 0, lpObj->m_Index);
				}

				DeletedMonCount++;
			}
		}
	}
	
	wsprintf(szText, "Result-ClearMonster(%d)", DeletedMonCount);
	GCServerMsgStringSend(szText, lpObj->m_Index, 1);
}

void CGMMng::CmdClearItem(LPOBJ lpObj,int Dis)
{
	char szText[256];

	memset(szText,0,sizeof(szText));

	if(Dis <= 0)
	{
		GCServerMsgStringSend("Result-Invalid Argument", lpObj->m_Index, 1);
		return;
	}
	
	int MapNumber = lpObj->MapNumber;//loc66
	MapClass * lpMap = &MapC[MapNumber];//loc67

	int ItemCount = lpMap->GetVisibleItemCount(lpObj,Dis);

	wsprintf(szText, "Result-ClearItem(%d)", ItemCount);
	GCServerMsgStringSend(szText, lpObj->m_Index, 1);

}

void CGMMng::CmdClearInven(LPOBJ lpObj)
{
	char szText[256];
	memset(szText,0,sizeof(szText));

	int ItemCount = 0;

	for(int i = INVETORY_WEAR_SIZE;i < MAIN_INVENTORY_SIZE ; i++)
	{
		if(lpObj->pInventory[i].IsItem() == 1)
		{
			gObjInventoryDeleteItem(lpObj->m_Index, i);
			ItemCount++;
		}
	}

	GCItemListSend(lpObj->m_Index);

	wsprintf(szText, "Result-ClearInven(%d)", ItemCount);

	GCServerMsgStringSend(szText, lpObj->m_Index, 1);
}

void CGMMng::CmdSummonChar(LPOBJ lpObj,char * szName)
{
	LPOBJ lpTargetObj = 0;
	int tIndex = -1;

	char szText[256];
	memset(szText,0,sizeof(szText));

	if(szName == NULL)
	{
		GCServerMsgStringSend("Result-Invalid Argument", lpObj->m_Index, 1);
		return;
	}

	tIndex = gObjGetIndex(szName);

	if(tIndex <= 0)
	{
		GCServerMsgStringSend("Result-User Not Found", lpObj->m_Index, 1);
		return;
	}
	
	if(gObj[tIndex].Connected != PLAYER_PLAYING)
	{
		GCServerMsgStringSend("Result-Disconnect User", lpObj->m_Index, 1);
		return;
	}

	int MapNum = lpObj->MapNumber;//loc68
	int X = lpObj->X + 1;//loc69
	int Y = lpObj->Y + 1;//loc70

	BYTE MapAttr = MapC[MapNum].GetAttr(X, Y);
	
	if((MapAttr&4) == 4 || (MapAttr&8) == 8)
	{
		GCServerMsgStringSend("Result-Invalid Area", lpObj->m_Index, 1);
		return;
	}
	
	wsprintf(szText, "Result-SummonCharacter(%s)", szName);

	GCServerMsgStringSend(szText, lpObj->m_Index, 1);
	
	gObjTeleport(tIndex, MapNum,X, Y);

}

int CGMMng::GetType(WORD wClass)
{
	WORD Type = 0xFF;

	for(int i = 0; i< OBJ_MAXMONSTER; i++)
	{
		LPOBJ lpMonsterObj = &gObj[i];

		if(lpMonsterObj == NULL)
		{
			continue;
		}
		
		if(lpMonsterObj->Class == wClass)
		{
			Type = lpMonsterObj->Type;
			break;
		}
	}

	return Type;
}