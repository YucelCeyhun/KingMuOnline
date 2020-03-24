#include "StdAfx.h"

cBundles gBundles;

/*
char cBundles::DrawInventoryNumber(int ItemId) // -> (0048B93A)
{
	char Result;

	switch (*(WORD*)ItemId)
	{
	case ItemId(12,30)://Bundled Jewel of Bless
		Result = 2;
		break;
	case ItemId(12,31)://Bundled Jewel of Soul
		Result = 3;
		break;
	case ItemId(14,13)://Jewel of Bless
		Result = 0;
		break;
	case ItemId(14,14)://Jewel of Soul
		Result = 1;
		break;
	case ItemId(12,150)://Bundled Jewel of Level
		Result = 4;
		break;
	case ItemId(12,151)://Bundled Jewel of Luck
		Result = 5;
		break;
	case ItemId(12,152)://Bundled Jewel of Skill
		Result = 6;
		break;
	case ItemId(12,153)://Bundled Jewel of Option
		Result = 7;
		break;
	case ItemId(12,154)://Bundled Jewel of Excellent
		Result = 8;
		break;
	case ItemId(12,155)://Bundled Jewel of Ancient
		Result = 9;
		break;
	case ItemId(12,156)://Bundled Jewel of Socket
		Result = 10;
		break;
	default:
		Result = -1;
		break;
	}
	return Result;
}
*/

static BOOL bBundledBlessInvenPos_Switcher;

void Naked cBundles::BundledBlessInventoryPos()
{
	static DWORD dwBundledBlessInvenPos_Pointer;
	static DWORD dwBundledBlessInvenPos_Buffer;
	// ----
	bBundledBlessInvenPos_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwBundledBlessInvenPos_Pointer,ESI
	}
	// -----
	if(dwBundledBlessInvenPos_Pointer == ItemId(12,30))
	{
		bBundledBlessInvenPos_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenPos_Pointer >= ItemId(12,150) && dwBundledBlessInvenPos_Pointer <= ItemId(12,156))
	{
		bBundledBlessInvenPos_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenPos_Pointer >= ItemId(13,150) && dwBundledBlessInvenPos_Pointer <= ItemId(13,152))	// -> All Elemental Fragments
	{
		bBundledBlessInvenPos_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenPos_Pointer == ItemId(14,172))	// -> Divine Stone
	{
		bBundledBlessInvenPos_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenPos_Pointer == ItemId(14,173))	// -> Jewel of Dark Chaos
	{
		bBundledBlessInvenPos_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenPos_Pointer == ItemId(0,36))		// -> Divine Archangel Blade (Small Fix)
	{
		bBundledBlessInvenPos_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenPos_Pointer == ItemId(5,38))		// -> Summon Spirit Stick (Small Fix)
	{
		bBundledBlessInvenPos_Switcher = TRUE;
	}
	// ----
	if(bBundledBlessInvenPos_Switcher == TRUE)
	{
		_asm
		{
			MOV dwBundledBlessInvenPos_Buffer,oBundledBlessInvenPos_Allowed
			JMP dwBundledBlessInvenPos_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwBundledBlessInvenPos_Buffer,oBundledBlessInvenPos_Return
			JMP dwBundledBlessInvenPos_Buffer
		}
	}
}

static BOOL bBundledBlessInvenSize_Switcher;

void Naked cBundles::BundledBlessInventorySize()
{
	static DWORD dwBundledBlessInvenSize_Pointer;
	static DWORD dwBundledBlessInvenSize_Buffer;
	// ----
	bBundledBlessInvenSize_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwBundledBlessInvenSize_Pointer,ESI
	}
	// ----
	if(dwBundledBlessInvenSize_Pointer == ObjectId(12,30))
	{
		bBundledBlessInvenSize_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenSize_Pointer >= ObjectId(12,150) && dwBundledBlessInvenSize_Pointer <= ObjectId(12,156))
	{
		bBundledBlessInvenSize_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenSize_Pointer >= ObjectId(13,150) && dwBundledBlessInvenSize_Pointer <= ObjectId(13,152))		// -> All Elemental Fragments
	{
		bBundledBlessInvenSize_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenSize_Pointer == ObjectId(14,172)) // -> Divine Stone
	{
		bBundledBlessInvenSize_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenSize_Pointer == ObjectId(14,173)) // -> Jewel of Dark Chaos
	{
		bBundledBlessInvenSize_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenSize_Pointer == ObjectId(0,36))	// -> Divine Archangel Blade (Small Fix)
	{
		bBundledBlessInvenSize_Switcher = TRUE;
	}
	else if(dwBundledBlessInvenSize_Pointer == ObjectId(5,38))	// -> Summon Spirit Stick (Small Fix)
	{
		bBundledBlessInvenSize_Switcher = TRUE;
	}
	// ----
	if(bBundledBlessInvenSize_Switcher == TRUE)
	{
		_asm
		{
			MOV dwBundledBlessInvenSize_Buffer,oBundledBlessInvenSize_Allowed
			JMP dwBundledBlessInvenSize_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwBundledBlessInvenSize_Buffer,oBundledBlessInvenSize_Return
			JMP dwBundledBlessInvenSize_Buffer
		}
	}
}

/*
static BOOL bBundledBlessPrice_Switcher;

void Naked cBundles::BundledBlessInventoryPrice() // -> Esto es para el Lahap la Desmescla...
{
	static DWORD dwBundledBlessPrice_Pointer;
	static DWORD dwBundledBlessPrice_Buffer;
	static DWORD dwBundledBlessPrice_Jump = oBundledBlessInvenPrice_Jump;
	// ----
	bBundledBlessPrice_Switcher = FALSE;
	// ----
	_asm
	{
		MOV DWORD PTR SS:[EBP-0x8],EAX
		MOV EDX,DWORD PTR SS:[EBP-0x8]
		MOVSX EAX,WORD PTR DS:[EDX]
		MOV dwBundledBlessPrice_Pointer,EAX
	}
	// ----
	if(dwBundledBlessPrice_Pointer == ItemId(12,30))
	{
		bBundledBlessPrice_Switcher = TRUE;
	}
	else if(dwBundledBlessPrice_Pointer >= ItemId(12,150) && dwBundledBlessPrice_Pointer <= ItemId(12,156))
	{
		bBundledBlessPrice_Switcher = TRUE;
	}
	else if(dwBundledBlessPrice_Pointer >= ItemId(14,42) && dwBundledBlessPrice_Pointer <= ItemId(14,44))
	{
		bBundledBlessPrice_Switcher = TRUE;
	}
	// ----
	if(bBundledBlessPrice_Switcher == TRUE)
	{
		_asm
		{
			MOVSX ECX,BYTE PTR DS:[0x8C2080]
			TEST ECX,ECX
			JE BundledBlessPrice_Label
			// ----
			BundledBlessPrice_Label:
			// ----
			JMP dwBundledBlessPrice_Jump
		}
	}
	else
	{
		_asm
		{
			MOV dwBundledBlessPrice_Buffer,oBundledBlessInvenPrice_Return
			JMP dwBundledBlessPrice_Buffer
		}
	}
}
*/

void cBundles::Init()
{
	gToolKit.SetRange((LPVOID)oBundledBlessInvenPos_Hook,12,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oBundledBlessInvenPos_Hook,this->BundledBlessInventoryPos);
	// ----
	gToolKit.SetRange((LPVOID)oBundledBlessInvenSize_Hook,12,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oBundledBlessInvenSize_Hook,this->BundledBlessInventorySize);
	// ----
	//gToolKit.SetRange((LPVOID)oBundledBlessInvenPrice_Hook,27,ASM::NOP);
	//gToolKit.SetJmp((LPVOID)oBundledBlessInvenPrice_Hook,this->BundledBlessInventoryPrice);
}

#define pDrawNumber		((bool(__cdecl*)(int pObj))0x005146C0)
//#define pDisplayStack	((void(__stdcall*)(cBundles*Item))0x007343C7)

/*
void cBundles::OnDisplayItemStack(cBundles*Item)	// -> 007343C7
{
	pSetBlend(1);
	glColor3f(1.0f,1.0f,1.0f);
	// ----
	if(Item->Index == ItemId(12,150)) // -> Bundled Jewel of Level
	{
		glColor3f(0.576f,0.439f,0.859f);
	}
	else if(Item->Index == ItemId(12,151))	// -> Bundled Jewel of Luck
	{
		glColor3f(0.0f,0.75f,1.0f);
	}
	else if(Item->Index == ItemId(12,152))	// -> Bundled Jewel of Skill
	{
		glColor3f(0.824f,0.412f,0.118f);
	}
	else if(Item->Index == ItemId(12,153))	// -> Bundled Jewel of Option
	{
		glColor3f(0.863f,0.078f,0.235f);
	}
	// ----
	glColor3f(1.0f,1.0f,1.0f);
	pGLSwitch();
	// ----
	pDisplayStack(Item);
}
*/

#define oDrawColorB_Buff 0x007347EE
#define oDrawColorG_Buff 0x007347F3
#define oDrawColorR_Buff 0x007347F8

void cBundles::DrawColors(int iColor)
{
	if(iColor == eNormalNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x66);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x66);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x66);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0x33);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x33);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x33);
	}
	else if(iColor == eBlueNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x00);
	}
	else if(iColor == eRedNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x00);
	}
	else if(iColor == eGoldenNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x3D);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0xCC);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0xCC);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0xCD);
	}
	else if(iColor == eGreenNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x00);
	}
	else if(iColor == eLBlueNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x7B);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0xB9);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x8C);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x00);
	}
	else if(iColor == eLGreenNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x3E);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0xB3);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x33);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x33);
	}
	else if(iColor == eOrangeNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x40);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x00);
	}
	else if(iColor == eBlueJewelNumb)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x15);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x53);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x26);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x00);
	}
	else if(iColor == eLRedNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x80);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x3E);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0xEB);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x85);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x1F);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x3E);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0xEB);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x85);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x1F);
	}
	else if(iColor == ePinkNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x68);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0xF5);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0xC3);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x0B);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0xC6);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0xA8);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0x3B);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0xED);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0xFA);
	}
	else if(iColor == ePurpleNumber)
	{
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+3),0x6E);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+2),0x14);
		gToolKit.SetByte((PVOID)(oDrawColorR_Buff+1),0x7B);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+4),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+3),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+2),0x00);
		gToolKit.SetByte((PVOID)(oDrawColorG_Buff+1),0x00);
		// ----
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+4),0x3F);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+3),0x4E);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+2),0x56);
		gToolKit.SetByte((PVOID)(oDrawColorB_Buff+1),0x04);
	}
}

BOOL cBundles::DrawNumber(int pObj) // -> 005146C0
{
	int pObject = *(WORD*)pObj;
	// ----
	switch(pObject)
	{
		case ItemId(12,30):
			gBundles.DrawColors(eNormalNumber);
			return TRUE;
		break;

		case ItemId(12,31):
			gBundles.DrawColors(eNormalNumber);
			return TRUE;
		break;

		case ItemId(12,150):
			gBundles.DrawColors(ePinkNumber);
			return TRUE;
		break;

		case ItemId(12,151):
			gBundles.DrawColors(eLRedNumber);
			return TRUE;
		break;

		case ItemId(12,152):
			gBundles.DrawColors(eBlueJewelNumb);
			return TRUE;
		break;

		case ItemId(12,153):
			gBundles.DrawColors(eOrangeNumber);
			return TRUE;
		break;

		case ItemId(12,154):
			gBundles.DrawColors(eLGreenNumber);
			return TRUE;
		break;

		case ItemId(12,155):
			gBundles.DrawColors(eLBlueNumber);
			return TRUE;
		break;

		case ItemId(12,156):
			gBundles.DrawColors(ePurpleNumber);
			return TRUE;
		break;

		default:
			return pDrawNumber(pObj) >= 2;
		break;
	}
}

/*void cBundles::InitDrawColors()
{
	gToolKit.SetOp((LPVOID)0x007349B5,this->OnDisplayItemStack,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0075AD39,this->OnDisplayItemStack,ASM::CALL);
}*/

void cBundles::InitDrawNumber()
{
	gToolKit.SetOp((LPVOID)0x0050D089,this->DrawNumber,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x007347CE,this->DrawNumber,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x007777DF,this->DrawNumber,ASM::CALL);
}

void cBundles::Load()
{
	this->Init();
	//this->InitDrawColors();
	this->InitDrawNumber();
	// ----
	//gToolKit.HookOffset((DWORD)&this->DrawInventoryNumber,0x0048BCF5,ASM::CALL);	// -> ?
	//gToolKit.HookOffset((DWORD)&this->DrawInventoryNumber,0x0048BD38,ASM::CALL);	// -> ?
	//gToolKit.HookOffset((DWORD)&this->DrawInventoryNumber,0x005146C7,ASM::CALL);	// -> Draw Inventory Number Call
	//gToolKit.HookOffset((DWORD)&this->DrawInventoryNumber,0x0059050D,ASM::CALL);	// -> Draw Golden Name on Inventory
	//gToolKit.HookOffset((DWORD)&this->DrawInventoryNumber,0x00594B4F,ASM::CALL);	// -> ?
	//gToolKit.HookOffset((DWORD)&this->DrawInventoryNumber,0x0059887E,ASM::CALL);
}