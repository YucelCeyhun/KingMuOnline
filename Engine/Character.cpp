#include "StdAfx.h"

cCharacter gCharacter;

void cCharacter::FixTextStats()
{
	gToolKit.SetByte((PVOID)(oCharStrengthTextNumberLine + 2), 0x0B);		// -> Strength New Text Line
	gToolKit.SetByte((PVOID)(oCharStrengthTextNumberLine + 1), 0xE0);		// -> Strength New Text Line
	// ----
	gToolKit.SetByte((PVOID)(oCharAgilityTextNumberLine + 2), 0x0B);		// -> Agility New Text Line
	gToolKit.SetByte((PVOID)(oCharAgilityTextNumberLine + 1), 0xE1);		// -> Agility New Text Line
	// ----
	gToolKit.SetByte((PVOID)(oCharVitalityTextNumberLine + 2), 0x0B);		// -> Vitality New Text Line
	gToolKit.SetByte((PVOID)(oCharVitalityTextNumberLine + 1), 0xE2);		// -> Vitality New Text Line
	// ----
	gToolKit.SetByte((PVOID)(oCharEnergyTextNumberLine + 2), 0x0B);		// -> Energy New Text Line
	gToolKit.SetByte((PVOID)(oCharEnergyTextNumberLine + 1), 0xE3);		// -> Energy New Text Line
}

void cCharacter::FixTextOnSelect()
{
	gToolKit.SetByte((PVOID)(0x00404640 + 1), 0x00);
	gToolKit.SetByte((PVOID)(0x00404640 + 2), 0x00);
	gToolKit.SetByte((PVOID)(0x00404640 + 3), 0x00);
	gToolKit.SetByte((PVOID)(0x00404640 + 4), 0x00);
	gToolKit.SetRange((LPVOID)0x004045ED, 5, ASM::NOP);
}

BOOL cCharacter::CheckSafeZone()
{
	if (SafeZone)
		return TRUE;
	else
		return FALSE;
}

BOOL cCharacter::CheckCharacterLevel(int Level)
{
	if (pPlayerLevel < Level)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void cCharacter::FixCharacterExSize()
{
	gToolKit.SetByte((PVOID)(oFixCharacterEx_Width + 1), 0x7D);	// -> Texture Load New Width
	gToolKit.SetByte((PVOID)(oFixCharacterEx_Height + 1), 0x39);	// -> Texture Load New Height
	// ----
	/*
	gToolKit.SetByte((PVOID)(oFixCharacterEx_PosX+4),0x3F);		// -> Texture Position X Axis (1)
	gToolKit.SetByte((PVOID)(oFixCharacterEx_PosX+3),0x7A);		// -> Texture Position X Axis (2)
	gToolKit.SetByte((PVOID)(oFixCharacterEx_PosX+2),0xE1);		// -> Texture Position X Axis (3)
	gToolKit.SetByte((PVOID)(oFixCharacterEx_PosX+1),0x48);		// -> Texture Position X Axis (4)
	*/
}

/*
#define pDrawCharSelection		((char(__cdecl*)(int pObject))0x00611670)

char cCharacter::DrawCharSelection(int pObject) // -> Preview Struct
{
	int v1,v3;
	int v13;//PosX
	int v14;//PosY
	char Result;
	// ----
	v1 = pObject;
	// ----
	Result = *(BYTE*)(v1 + 4);  // Unknown4
	// ----
	if(Result == 1)
	{
		v3 = *(BYTE*)(v1 + 15); // pVisible
		// ----
		switch(v3)
		{
			case DrawSlotPos1:
				v13 = 1185990656;
				v14 = 1181388800;
				v1 = 1120403456;
			break;
			case DrawSlotPos2:
				v13 = 1186027520;
				v14 = 1301582336;// 1181582336;
				v1 = 1117126656;
			break;
			case DrawSlotPos3:
				v13 = 1186099200;
				v14 = 1181740032;
				v1 = 1112014848;
			break;
			case DrawSlotPos4:
				v13 = 1186190848;
				v14 = 1181830144;
				v1 = 1103626240;
			break;
			case DrawSlotPos5:
				v13 = 1186289459;
				v14 = 1181854720;
				v1 = 0;
			break;
		}
	}
	// ----
	return pDrawCharSelection(pObject);
}

void cCharacter::Init()
{
	gToolKit.SetOp((LPVOID)0x0064030E,this->DrawCharSelection,ASM::CALL);
}
*/

/*
#define oHeroNameColorR 0x006EF27C
#define oHeroNameColorG 0x006EF27E
#define oHeroNameColorB 0x006EF280

void cCharacter::TestHeroState()
{
	if(pPlayerState == GameProcess && gCharacter.CheckCharacterLevel(400))
	{
		gToolKit.SetByte((PVOID)(oHeroNameColorR + 1), 0x58);
		gToolKit.SetByte((PVOID)(oHeroNameColorG + 1), 0x98);
		gToolKit.SetByte((PVOID)(oHeroNameColorB + 1), 0x12);
	}
	else
	{
		return;
	}
}
*/

/*
bool cCharacter::CheckLicensed()
{
	static BOOL bLicense = FALSE;
	// ----
	if (!gToolKit.FileExists(LICENSE_FILE))
	{
		MessageBox(0,"You don't buy a License","eX406",0);
		::ExitProcess(0);
	}
	else
	{
		bLicense = TRUE;
		// ----
		if(bLicense == TRUE)
		{
			return true;
		}
	}
	return false;
}
*/

/*
BOOL cCharacter::TextBoxMolesto()
{
	static DWORD dwPresedButton = 0x00404A4B;
	// ----
	if(pPlayerState ==
	&& dwPresedButton)
	{
		MessageBox(0,"You don't buy a License","eX406",0);
		return FALSE;
	}
	return TRUE;
}
*/

/*
#define pDrawOnScreen	((void(__cdecl*)(GLint Arg1,int Arg2,GLsizei width,GLsizei height))0x5F4045)

void cCharacter::DrawNewCreateChar(GLint Arg1,int Arg2,GLsizei width,GLsizei height)
{
	static BOOL bLicense = FALSE;
	// ----
	if(gCharacter.CheckLicensed() == false)
	{
		gToolKit.SetRange((LPVOID)0x00404A4B,5,ASM::NOP);	// -> NO Character Creation Menu :D
		// ----
		if (bLicense == FALSE)
		{
			gCharacter.TextBoxMolesto();
		}
	}
	else
	{
		bLicense = TRUE;
	}
	// ----
	if(bLicense == TRUE)
	{
		gCharacter.FixTextStats();
		gCharacter.FixTextOnSelect();
	}
	// ----
	pDrawOnScreen(Arg1,Arg2,width,height);
}*/

/*void cCharacter::InitDrawNewCreateChar()
{
	gToolKit.SetOp((LPVOID)0x00404A4B,this->DrawNewCreateChar,ASM::CALL);//test
	gToolKit.SetOp((LPVOID)0x0040F7DB,this->DrawNewCreateChar,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00461D05,this->DrawNewCreateChar,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x005FEEA1,this->DrawNewCreateChar,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x005FF822,this->DrawNewCreateChar,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x005FF87E,this->DrawNewCreateChar,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0060011A,this->DrawNewCreateChar,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x006015C3,this->DrawNewCreateChar,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x006017E7,this->DrawNewCreateChar,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00601853,this->DrawNewCreateChar,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00766CB5,this->DrawNewCreateChar,ASM::CALL);
}*/

void cCharacter::Load()
{
	//this->Init();
	this->FixTextStats();
	this->FixTextOnSelect();
	this->FixCharacterExSize();
	//this->TestHeroState();
	//this->InitDrawNewCreateChar();
}