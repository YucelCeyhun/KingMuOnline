#include "StdAfx.h"

cComplete gComplete;

ObjMakePreviewCharSet	mObjMakePreviewCharSet		= (ObjMakePreviewCharSet)0x4FDFE0;    //Main 1.03Y+ JPN: 51564C ; Main 1.03k JPN: 4FDFE0
// ----
IsChaosCastle			gIsChaosCastle				= (IsChaosCastle)0x490280;            //Main 1.03Y+ JPN: 49A450 ; Main 1.03k JPN: 490280
ItemCharSetConvert		gItemCharSetConvert			= (ItemCharSetConvert)0x504A69;       //Main 1.03Y+ JPN: 51C4EC ; Main 1.03k JPN: 504A69
AmpersandConvert		gAmpersandConvert			= (AmpersandConvert)0x45A030;         //Main 1.03Y+ JPN: 463890 ; Main 1.03k JPN: 45A030
SetObjMaunt				gSetObjMaunt				= (SetObjMaunt)0x4AC2C4;              //Main 1.03Y+ JPN: 4B6B54 ; Main 1.03k JPN: 4AC2C4
SetObjMaunt2			gSetObjMaunt2               = (SetObjMaunt2)0x4ABF7C;             //Main 1.03Y+ JPN: 4B680C ; Main 1.03k JPN: 4ABF7C
ObjPetGetThis			gObjPetGetThis              = (ObjPetGetThis)0x81AB71;            //Main 1.03Y+ JPN: 8831F1 ; Main 1.03k JPN: 81AB71
SetObjPetOnSwitch		gSetObjPetOnSwitch          = (SetObjPetOnSwitch)0x81BA70;        //Main 1.03Y+ JPN: 884245 ; Main 1.03k JPN: 81BA70
SetObjPetReset			gSetObjPetReset             = (SetObjPetReset)0x81BDA7;           //Main 1.03Y+ JPN: 88457C ; Main 1.03k JPN: 81BDA7
CheckPetStatus			gCheckPetStatus             = (CheckPetStatus)0x4997AD;           //Main 1.03Y+ JPN: 4A3A7D ; Main 1.03k JPN: 4997AD
ReturnPetSlot			gReturnPetSlot              = (ReturnPetSlot)0x4ABEB0;            //Main 1.03Y+ JPN: 4B6740 ; Main 1.03k JPN: 4ABEB0
ObjPreviewDarkRaven		gObjPreviewDarkRaven        = (ObjPreviewDarkRaven)0x4A2AD6;      //Main 1.03Y+ JPN: 4ACDA6 ; Main 1.03k JPN: 4A2AD6
// ----
Objsub_49A50A			sub_49A50A                  = (Objsub_49A50A)0x49033A;            //Main 1.03Y+ JPN: 49A50A ; Main 1.03k JPN: 49033A
Objsub_514A21			sub_514A21                  = (Objsub_514A21)0x4FD4FD;            //Main 1.03Y+ JPN: 514A21 ; Main 1.03k JPN: 4FD4FD
Objsub_4ADABB			sub_4ADABB                  = (Objsub_4ADABB)0x4A3820;            //Main 1.03Y+ JPN: 4ADABB ; Main 1.03k JPN: 4A3820
Objsub_4A4750			sub_4A4750					= (Objsub_4A4750)0x4A4750;			  //Main 1.03Y+ JPN: 4AECB0 ; Main 1.03k JPN: 4A4750
//---------------------------------------------------------------------------

Objdword_7B65114		dword_7B65114               = (Objdword_7B65114)0x7A723B8;        //Main 1.03Y+ JPN: 7B65114 ; Main 1.03k JPN: 7A723B8
Objdword_7BA6278		dword_7BA6278               = (Objdword_7BA6278)0x7AB3518;        //Main 1.03Y+ JPN: 7BA6278 ; Main 1.03k JPN: 7AB3518
Objdword_7B650F8		dword_7B650F8               = (Objdword_7B650F8)0x7A7239C;        //Main 1.03Y+ JPN: 7B650F8 ; Main 1.03k JPN: 7A7239C

BYTE gLevelSmallConvert(int SmallValue)
{
	BYTE ResultValue;
	// ----
	switch (SmallValue)
	{
	case 0:
		ResultValue = 0;
		break;
		// --
	case 1:
		ResultValue = 3;
		break;
		// --
	case 2:
		ResultValue = 5;
		break;
		// --
	case 3:
		ResultValue = 7;
		break;
		// --
	case 4:
		ResultValue = 9;
		break;
		// --
	case 5:
		ResultValue = 12;
		break;
		// --
	case 6:
		ResultValue = 14;
		break;
		// --
	case 7:
		ResultValue = 15;
		break;
		// --
	default:
		ResultValue = 0;
		break;
	}
	// ----
	return ResultValue;
}

int cComplete::MakeCharSet(int Index,BYTE *CharSet,int UseStruct,int Mode)
{
	int Result;
	int ObjPreview;
	// ----
	if (UseStruct)
	{
		ObjPreview = UseStruct;
	}
	else
	{
		ObjPreview = CS_GET_STRUCT(Index, dword_7B650F8);
	}
	// ----
	Result = ObjPreview + 700;
	// ----
	Preview * gPreview = &*(Preview*)ObjPreview;
	// ----
	if (gPreview->Unknown748 == (834 - 8))
	{
		short WeaponFirstType = CS_GET_WEAPON(CharSet[11], CharSet[0]);
		// ----
		if (WeaponFirstType == CS_EMPTY_WEAPON)
		{
			gPreview->WeaponFirstSlot = CS_EMPTY_SLOT;
			gPreview->WeaponFirstExcellent = NULL;
			gPreview->WeaponFirstAncient = NULL;
		}
		else
		{
			gPreview->WeaponFirstSlot = WeaponFirstType + 834;
		}
		// ----
		short WeaponSecondType = CS_GET_WEAPON(CharSet[12], CharSet[1]);
		// ----
		if (WeaponSecondType == CS_EMPTY_WEAPON)
		{
			gPreview->WeaponSecondSlot = CS_EMPTY_SLOT;
			gPreview->WeaponSecondExcellent = NULL;
			gPreview->WeaponSecondAncient = NULL;
		}
		else
		{
			if (gAmpersandConvert(pPlayerClass(ObjPreview)) != DarkLordChar || WeaponSecondType != ItemId(5,5))
			{
				gPreview->WeaponSecondSlot = WeaponSecondType + 834;
			}
			else
			{
				gObjPreviewDarkRaven(ObjPreview);
			}
		}
		if ((CS_SET_1(CharSet[4]) & 3) == 3)
		{
			BYTE SecondWingsType = CharSet[8] & 7;
			// ----
			if (SecondWingsType)
			{
				switch (SecondWingsType)
				{
				case 5: // Cape Of Lord
					gPreview->WingsSlot = ObjectId(13,30);
					break;
					// --
				case 6: // Wings Of Curse
					gPreview->WingsSlot = ObjectId(12,41);
					break;
					// --
				case 7: // Wings Of Despair
					gPreview->WingsSlot = ObjectId(12,42);
					break;
					// --
				default: // Other Wings
					gPreview->WingsSlot = ObjectId(12,2) + SecondWingsType;
					break;
				}
			}
			else
			{
				gPreview->WingsSlot = CS_EMPTY_SLOT;
				gPreview->Unknown459 = NULL;
				gPreview->Unknown460 = NULL;
			}
		}
		else
		{
			gPreview->WingsSlot = ObjectId(12,0) + (CS_SET_1(CharSet[4]) & 3);
		}
		// ----
		BYTE ThirdWingsType = CS_SET_1(CharSet[15]) & 7;
		// ----
		if (ThirdWingsType > 0)
		{
			if (ThirdWingsType == 6)
			{
				gPreview->WingsSlot = ObjectId(12,43);
			}
			else
			{
				gPreview->WingsSlot = ObjectId(12,35) + ThirdWingsType;
			}
		}
		// ----
		BYTE CustomWings = CharSet[16] >> 2;
		// ----
		if(CustomWings > 0)
		{
			switch(CustomWings)
			{
				case MagicWings:
					gPreview->WingsSlot = ObjectId(12,236);
				break;
				// --
				case ChaosWings:
					gPreview->WingsSlot = ObjectId(12,237);
				break;
				// --
				case LifeWings:
					gPreview->WingsSlot = ObjectId(12,238);
				break;
				// --
				case DeathCape:
					gPreview->WingsSlot = ObjectId(12,239);
				break;
				// --
				case HeavenWings:
					gPreview->WingsSlot = ObjectId(12,240);
				break;
				// --
				case DemonicWings:
					gPreview->WingsSlot = ObjectId(12,241);
				break;
				// --
				case BlossomWings:
					gPreview->WingsSlot = ObjectId(12,242);
				break;
				// --
				case ThunderWings:
					gPreview->WingsSlot = ObjectId(12,243);
				break;
				// --
				case RavenWings:
					gPreview->WingsSlot = ObjectId(12,244);
				break;
				// --
				case EternalWings:
					gPreview->WingsSlot = ObjectId(12,245);
				break;
				// --
				case LegendWings:
					gPreview->WingsSlot = ObjectId(12,246);
				break;
				// --
				case FlamingWings:
					gPreview->WingsSlot = ObjectId(12,247);
				break;
				// --
				case NightwishWings:
					gPreview->WingsSlot = ObjectId(12,248);
				break;
				// --
				case ImperialWings:
					gPreview->WingsSlot = ObjectId(12,249);
				break;
				// --
				case ConquerorWings:
					gPreview->WingsSlot = ObjectId(12,250);
				break;
				// --
				case AngelAndDevil:
					gPreview->WingsSlot = ObjectId(12,251);
				break;
				// --
				case DeathlessWings:
					gPreview->WingsSlot = ObjectId(12,252);
				break;
			}
		}
		// ----
		if(Mode)
		{
			*(BYTE*)(Mode+4) = NULL;
		}
		else
		{
			ReturnPetSlot(ObjPreview+700);
			gSetObjPetReset(gObjPetGetThis(),ObjPreview,pPetSlot(ObjPreview),1);
		}
		// ----
		BYTE NormalPetType = CharSet[4] & 3;
		// ----
		if(NormalPetType == 3)
		{
			if((CharSet[9] & 1) == 1)
			{
				gPreview->PetSlot = ObjectId(13,3);
				// ----
				if(Mode)
				{
					gSetObjMaunt2(Dinorant,ObjPreview+952,ObjPreview+700,Mode,0);
				}
				else
				{
					gObjCreateBug(Dinorant,ObjPreview+952,ObjPreview+700,0,0);
				}
			}
			else
			{
				gPreview->PetSlot		= CS_EMPTY_SLOT;
				gPreview->FenrirCharSet = NULL;
				gPreview->ExpectPet		= 1;
			}
		}
		else
		{
			BYTE PetCharSet = CharSet[15] & 0xE0;
			// ----
			if(PetCharSet != 0x20 && PetCharSet != 0x40 && PetCharSet != 0x60 
			&& PetCharSet != 0x80 && PetCharSet != 0xA0 && PetCharSet != 0xC0 
			&& PetCharSet != 0xE0 && PetCharSet != 0x100)
			{
				gPreview->PetSlot = ObjectId(13,0) + NormalPetType;
				int MauntCode = NULL;
				bool Check = true;
				// ----
				if(NormalPetType)
				{
					if(NormalPetType == 2)
					{
						MauntCode = Uniria;
					}
					else
					{
						if(NormalPetType == 3)
						{
							MauntCode = Dinorant;
						}
						else
						{
							Check = false;
						}
					}
				}
				else
				{
					MauntCode = ObjectId(13,0);
				}
				// ----
				if(Check == true)
				{
					if(Mode)
					{
						gSetObjMaunt2(MauntCode,ObjPreview+952,ObjPreview+700,Mode,0);
					}
					else
					{
						gObjCreateBug(MauntCode,ObjPreview+952,ObjPreview+700,0,0);
					}
				}
			}
			else
			{
				short ShopPetType = NULL;
				// ----
				switch(PetCharSet)
				{
					case 0x20: // Demon
						ShopPetType = 64;
					break;
					// --
					case 0x40: // Fairy
						ShopPetType = 65;
					break;
					// --
					case 0x60: // Skeleton
						ShopPetType = 77;
					break;
					// --
					case 0x80: // Rudolf
						ShopPetType = 67;
					break;
					// --
					case 0xA0: // Unicorn
						ShopPetType = 78;
					break;
					// --
					case 0xC0: // Sparky
						ShopPetType = 79;
					break;
					// --
					case 0xE0: // Panda
						ShopPetType = 80;
					break;
					// --
					case 0x100: // Chinlon
						ShopPetType = 81;
					break;
				}
				// ----
				gPreview->PetSlot = ObjectId(13,0) + ShopPetType;
				// ----
				if(pPlayerState == SwitchCharacter || ObjPreview == LODWORD(dword_7B65114))
				{
					gObjCreatePet(gObjPetGetThis(),ItemId(13,0)+ShopPetType,pPetSlot(ObjPreview),ObjPreview+952,ObjPreview,0,0);
				}
			}
		}
		// ----
		if((CharSet[11] & 1) == 1)
		{
			gPreview->PetSlot = ObjectId(13,4);
			// ----
			if(Mode)
			{
				gSetObjMaunt2(DarkHorse,ObjPreview+952,ObjPreview+700,Mode,0);
			}
			else
			{
				gObjCreateBug(DarkHorse,ObjPreview+952,ObjPreview+700,0,0);
			}
		}
		// ----
		if((CharSet[11] & 2) == 2)
		{
			gPreview->PetSlot = ObjectId(13,97);
			// ----
			if(Mode)
			{
				gSetObjMaunt2(DarkWolf,ObjPreview+952,ObjPreview+700,Mode,0);
			}
			else
			{
				gObjCreateBug(DarkWolf,ObjPreview+952,ObjPreview+700,0,0);
			}
		}
		// ----
		if((CharSet[11] & 4) == 4)
		{
			gPreview->PetSlot = ObjectId(13,37);
			gPreview->FenrirCharSet = CharSet[15] & 3;
			// ----
			if((CharSet[16] & 1) == 1)
			{
				gPreview->FenrirCharSet = 4;
			}
			if((CharSet[16] & 2) == 2)
			{
				gPreview->FenrirCharSet = 8;
			}
			// ----
			switch(gPreview->FenrirCharSet)
			{
				case 1: // Black Fenrir
				{
					if(Mode)
					{
						gSetObjMaunt2(BlackFenrir,ObjPreview+952,ObjPreview+700,Mode,0);
					}
					else
					{
						gObjCreateBug(BlackFenrir,ObjPreview+952,ObjPreview+700,0,0);
					}
				}
				break;
				// --
				case 2: // Blue Fenrir
				{
					if(Mode)
					{
						gSetObjMaunt2(BlueFenrir,ObjPreview+952,ObjPreview+700,Mode,0);
					}
					else
					{
						gObjCreateBug(BlueFenrir,ObjPreview+952,ObjPreview+700,0,0);
					}
				}
				break;
				// --
				case 4: // Golden Fenrir
				{
					if(Mode)
					{
						gSetObjMaunt2(GoldenFenrir,ObjPreview+952,ObjPreview+700,Mode,0);
					}
					else
					{
						gObjCreateBug(GoldenFenrir,ObjPreview+952,ObjPreview+700,0,0);
					}
				}
				break;
				// --
				case 8: // Orange Fenrir
				{
					if(Mode)
					{
						gSetObjMaunt2(OrangeFenrir,ObjPreview+952,ObjPreview+700,Mode,0);
					}
					else
					{
						gObjCreateBug(OrangeFenrir,ObjPreview+952,ObjPreview+700,0,0);
					}
				}
				break;
				// --
				default: // Red Fenrir
				{
					if(Mode)
					{
						gSetObjMaunt2(RedFenrir,ObjPreview+952,ObjPreview+700,Mode,0);
					}
					else
					{
						gObjCreateBug(RedFenrir,ObjPreview+952,ObjPreview+700,0,0);
					}
				}
				break;
			}
		}
		// ----
		if((CharSet[11] & 8) == 8)
		{
			gPreview->PetSlot = ObjectId(13,98);
			// ----
			if(Mode)
			{
				gSetObjMaunt2(FangSable,ObjPreview+952,ObjPreview+700,Mode,0);
			}
			else
			{
				gObjCreateBug(FangSable,ObjPreview+952,ObjPreview+700,0,0);
			}
		}
		/*
		// ----
		if((CharSet[11] & 16) == 16)
		{
			gPreview->PetSlot = ObjectId(13,99);
			// ----
			if(Mode)
			{
				gSetObjMaunt2(MisticTiger,ObjPreview+952,ObjPreview+700,Mode,0);
			}
			else
			{
				gObjCreateBug(MisticTiger,ObjPreview+952,ObjPreview+700,0,0);
			}
		}
		// ----
		if((CharSet[11] & 64) == 64)
		{
			gPreview->PetSlot = ObjectId(13,100);
			// ----
			if(Mode)
			{
				gSetObjMaunt2(GiantLyon,ObjPreview+952,ObjPreview+700,Mode,0);
			}
			else
			{
				gObjCreateBug(GiantLyon,ObjPreview+952,ObjPreview+700,0,0);
			}
		}
		// ----
		if((CharSet[11] & 128) == 128)
		{
			gPreview->PetSlot = ObjectId(13,101);
			// ----
			if(Mode)
			{
				gSetObjMaunt2(LycanPet,ObjPreview+952,ObjPreview+700,Mode,0);
			}
			else
			{
				gObjCreateBug(LycanPet,ObjPreview+952,ObjPreview+700,0,0);
			}
		}*/
		// ----
		gCheckPetStatus(ObjPreview);
		// ----
		if (((CharSet[11] >> 1) & 1) == 1)
		{
			if (gPreview->PetStatus <= NULL || gPreview->PetStatus > 3)
			{
				gPreview->PetStatus = AtFenrir;
			}
		}
		else
		{
			if (gPreview->PetStatus <= NULL || gPreview->PetStatus > 3)
			{
				gPreview->PetStatus = NULL;
			}
		}
		// ----
		if (((CharSet[11] >> 2) & 2) == 2)
		{
			if (gPreview->PetStatus <= NULL || gPreview->PetStatus > 3)
			{
				gPreview->PetStatus = AtFenrir;
			}
		}
		else
		{
			if (gPreview->PetStatus <= NULL || gPreview->PetStatus > 3)
			{
				gPreview->PetStatus = NULL;
			}
		}
		// ----
		int TempBuff = CharSet[7] + (CharSet[6] << 8) + (CharSet[5] << 16);
		gPreview->WeaponFirstLevel = gLevelSmallConvert(CharSet[7] & 7);
		gPreview->WeaponSecondLevel = gLevelSmallConvert((TempBuff >> 3) & 7);
		gPreview->Unknown458 = NULL;
		gPreview->Unknown490 = NULL;
		Result = ObjPreview;
		// ----
		if(!pVisible(ObjPreview))
		{
			short HelmType = CS_GET_HELM(CharSet[8],CharSet[2],CharSet[12]);
			// ----
			if(HelmType == CS_EMPTY_ITEM)
			{
				gPreview->HelmSlot = (BYTE)gItemCharSetConvert(gPreview->Class) + CS_HELM;
			}
			else
			{
				gPreview->HelmSlot = ObjectId(7,0) + HelmType;
			}
			// ----
			short ArmorType = CS_GET_ARMOR(CharSet[8],CharSet[2],CharSet[13]);
			// ----
			if(ArmorType == CS_EMPTY_ITEM)
			{
				gPreview->ArmorSlot = (BYTE)gItemCharSetConvert(gPreview->Class) + CS_ARMOR;
			}
			else
			{
				gPreview->ArmorSlot = ObjectId(8,0) + ArmorType;
			}
			// ----
			short PantsType = CS_GET_PANTS(CharSet[8], CharSet[3], CharSet[13]);
			// ----
			if(PantsType == CS_EMPTY_ITEM)
			{
				gPreview->PantsSlot = (BYTE)gItemCharSetConvert(gPreview->Class) + CS_PANTS;
			}
			else
			{
				gPreview->PantsSlot = ObjectId(9,0) + PantsType;
			}
			// ----
			short GlovesType = CS_GET_GLOVES(CharSet[8], CharSet[3], CharSet[14]);
			// ----
			if(GlovesType == CS_EMPTY_ITEM)
			{
				gPreview->GlovesSlot = (BYTE)gItemCharSetConvert(gPreview->Class) + CS_GLOVES;
			}
			else
			{
				gPreview->GlovesSlot = ObjectId(10,0) + GlovesType;
			}
			// ----
			short BootsType = CS_GET_BOOTS(CharSet[8], CharSet[4], CharSet[14]);
			// ----
			if(BootsType == CS_EMPTY_ITEM)
			{
				gPreview->BootsSlot = (BYTE)gItemCharSetConvert(gPreview->Class) + CS_BOOTS;
			}
			else
			{
				gPreview->BootsSlot = ObjectId(11,0) + BootsType;
			}
			// ----
			gPreview->HelmLevel = gLevelSmallConvert((TempBuff >> 6) & 7);
			gPreview->HelmExcellent = (CharSet[9] & 0x80) >> 7;
			gPreview->HelmAncient = (CharSet[9] & 0x80) >> 7;
			// ----
			gPreview->ArmorLevel = gLevelSmallConvert((TempBuff >> 9) & 7);
			gPreview->ArmorExcellent = (CharSet[9] & 0x40) >> 6;
			gPreview->ArmorAncient = (CharSet[9] & 0x40) >> 6;
			// ----
			gPreview->PantsLevel = gLevelSmallConvert((TempBuff >> 12) & 7);
			gPreview->PantsExcellent = (CharSet[9] & 0x20) >> 5;
			gPreview->PantsAncient = (CharSet[9] & 0x20) >> 5;
			// ----
			gPreview->GlovesLevel = gLevelSmallConvert((TempBuff >> 15) & 7);
			gPreview->GlovesExcellent = (CharSet[9] & 0x10) >> 4;
			gPreview->GlovesAncient = (CharSet[9] & 0x10) >> 4;
			// ----
			gPreview->BootsLevel = gLevelSmallConvert((TempBuff >> 18) & 7);
			gPreview->BootsExcellent = (CharSet[9] & 8) >> 3;
			gPreview->BootsAncient = (CharSet[9] & 8) >> 3;
			// ----
			gPreview->WeaponFirstExcellent = (CharSet[9] & 4) >> 2;
			gPreview->WeaponFirstAncient = (CharSet[10] & 4) >> 2;
			// ----
			gPreview->WeaponSecondExcellent = (CharSet[9] & 2) >> 1;
			gPreview->WeaponSecondAncient = (CharSet[10] & 2) >> 1;
			// ----
			gPreview->AncientEffect = CharSet[10] & 1;
			// ----
			sub_49A50A(ObjPreview);
			// ----
			Result = sub_514A21(ObjPreview);
		}
	}
	// ----
	return Result;
}

void cComplete::Load()
{
	gToolKit.SetOp((LPVOID)0x0046D96B,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00611613,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x006177F5,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x006182D0,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x006188B6,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0063D4FC,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00640572,this->MakeCharSet,ASM::CALL);
}