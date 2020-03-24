#include "StdAfx.h"

cFixes gFixes;

void cFixes::FixMoveWithoutSeal()
{
	gToolKit.SetByte((PVOID)(oMoveWithoutSealAllowed),ASM::JMPS);
	gToolKit.SetByte((PVOID)(oMoveWithoutSealAllowed+1),0x27);
}

void cFixes::ScreenShotFolder()
{
	char ImagesDirectory[MAX_PATH];
	strcpy_s(ImagesDirectory,this->CurrentDir);
	strcat_s(ImagesDirectory,"Images");
	CreateDirectory(ImagesDirectory,NULL);
	// ----
	char SSPath[50];
	memcpy(SSPath,"Images\\Screen(%02d_%02d-%02d_%02d)-%04d.jpg",50);
	memcpy((DWORD*)0x008D775C,SSPath,50);
	gToolKit.HookExactOffset(0x008D775C,0x00888FD0,ASM::PUSH);
}

void cFixes::ImageSplashMode()
{
	CSplash splash1(TEXT(SPLASH_FILE),RGB(256,256,256));
	splash1.ShowSplash();
	Sleep(900);
	splash1.CloseSplash();
}

void cFixes::FixUseMultiClient()
{
	gToolKit.SetByte((PVOID)(0x005FA130),ASM::JMPS);
}

void cFixes::FixMaxZenCountOnWare()
{
	gToolKit.SetByte((PVOID)(0x0071646A+1),9);
	gToolKit.SetByte((PVOID)(0x007166F8+1),9);
	gToolKit.SetByte((PVOID)(0x00716A5B+1),9);
	gToolKit.SetByte((PVOID)(0x007175AB+1),9);
}

void Naked cFixes::FixDeleteCharASM()
{
	static DWORD dwSearchTextNumberLine = 0x00402F50;
	static DWORD dwCreateInterfaceLoops = 0x0040D31A;
	// ----
	_asm
	{
		PUSH 0x620
		MOV ECX,0x07AAD828
		CALL dwSearchTextNumberLine
		MOV DWORD PTR SS:[EBP-0x90],EAX
		JMP dwCreateInterfaceLoops
	}
}

void cFixes::FixDeleteCharWithoutId()
{
	gToolKit.SetRange((LPVOID)0x0040D166,44,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0040D166,this->FixDeleteCharASM);
}

void cFixes::FixRemoveFruitMessages()
{
	gToolKit.SetRange((LPVOID)oFruitRemoveMsgBox01,5,ASM::NOP);
	gToolKit.SetRange((LPVOID)oFruitRemoveMsgBox02,5,ASM::NOP);
	gToolKit.SetRange((LPVOID)oFruitRemoveMsgBox03,5,ASM::NOP);
	gToolKit.SetRange((LPVOID)oFruitRemoveMsgBox04,5,ASM::NOP);
	// -> Delete Fruit Cash Shop Messages
	gToolKit.SetRange((LPVOID)oCashShopFruitRemove,5,ASM::NOP);
}

void cFixes::FixMixBmdMaxLineCount()
{
	gToolKit.SetByte((PVOID)(0x004B6028+2),0xC8);
}

void cFixes::FixBeepSoundWhispMsg()
{
	gToolKit.SetByte((PVOID)(0x0040E750+1),0xE5);
	gToolKit.SetByte((PVOID)(0x0040E750+2),0x0B);
}

void Naked cFixes::AncientMainToolTip()
{
	static DWORD dwSearchTextNumberLine = 0x00402F50;
	static DWORD dwFixAncientTextReturn = 0x0049610D;
	// ----
	_asm
	{
		PUSH 0xAC5						// -> "Option Info" (Number Line: 2757)
		MOV ECX,0x7AAD828
		CALL dwSearchTextNumberLine
		PUSH EAX
		PUSH 0xAC4						// -> "Ancient Item" (Number Line: 2756)
		MOV ECX,0x7AAD828
		CALL dwSearchTextNumberLine
		JMP dwFixAncientTextReturn
	}
}

void cFixes::FixAncientMainToolTip()
{
	gToolKit.SetRange((LPVOID)0x004960EE,31,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004960EE,this->AncientMainToolTip);
}

void cFixes::FixAgilityCharacterBug()
{
	gToolKit.SetByte((PVOID)(0x007884EF+3),0x14);	// -> Method 1
	//gToolKit.SetByte((PVOID)(0x),);
}

void StartAddress(LPVOID lpThreadParameter)
{
	HANDLE v1;
	HANDLE v2;
	// ----
	while(TRUE)
	{
		Sleep(5000);
		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1,0xFFFFFFFF,0xFFFFFFFF);
		v2 = GetCurrentProcess();
		SetThreadPriority(v2,-2);
	}
}

void cFixes::Load()
{
	this->ImageSplashMode();
	this->ScreenShotFolder();
	this->FixUseMultiClient();
	this->FixMoveWithoutSeal();
	this->FixMaxZenCountOnWare();
	this->FixBeepSoundWhispMsg();
	this->FixMixBmdMaxLineCount();
	this->FixAncientMainToolTip();
	this->FixDeleteCharWithoutId();
	this->FixRemoveFruitMessages();
	this->FixAgilityCharacterBug();
	// ----
	CreateThread(0,0,(LPTHREAD_START_ROUTINE)StartAddress,0,0,0);
}