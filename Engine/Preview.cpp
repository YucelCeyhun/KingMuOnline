#include "StdAfx.h"

/*
cPreview gPreview;

void cPreview::MakeCharSet(int ObjectIndex,BYTE *CharSet,int Object,int Mode)
{
	pMakePreviewCharSet(ObjectIndex, CharSet, Object, Mode);
	// ----
	BYTE CustomWings	= CharSet[16] >> 2;
	BYTE CustomPets		= ((CharSet[11] & 2) == 2);
	// ----
	if(CustomWings > 0)
	{
		switch(CustomWings)
		{
			case HeavenWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,240);
			break;

			case DemonicWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,241);
			break;

			case BlossomWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,242);
			break;

			case ThunderWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,243);
			break;

			case RavenWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,244);
			break;

			case EternalWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,245);
			break;

			case LegendWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,246);
			break;

			case FlamingWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,247);
			break;

			case NightwishWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,248);
			break;

			case ImperialWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,249);
			break;

			case ConquerorWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,250);
			break;

			case AngelAndDevil:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,251);
			break;

			case DeathlessWings:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1C8) = ObjectId(12,252);
			break;
		}
	}

	if(CustomPets > 0)
	{
		switch(CustomPets)
		{
			case WolfPet:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1E8) = ObjectId(13,97);
			break;

			case SablePet:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1E8) = ObjectId(13,98);
			break;

			case TigerPet:
				*(WORD*)(1236 * ObjectIndex + *(DWORD*)0x7A7239C + 0x1E8) = ObjectId(13,99);
			break;
		}
	}
}
*/

/*void cPreview::Load()
{
	gToolKit.SetOp((LPVOID)0x0046D96B,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00611613,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x006177F5,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x006182D0,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x006188B6,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0063D4FC,this->MakeCharSet,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00640572,this->MakeCharSet,ASM::CALL);
}*/