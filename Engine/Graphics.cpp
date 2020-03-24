//#include "StdAfx.h"

#include <Windows.h>
#include "Graphics.h"
#include "GlowTron.h"
#include "ToolKit.h"
#include "Interface.h"
#include "Import.h"

Graphics gGraphics;

Graphics::Graphics()
{
}

DWORD gTmpEax;
DWORD gTmpEcx;
DWORD gTmpEdx;
DWORD gTmpEbx;
DWORD gTmpEsp;
DWORD gTmpEbp;
DWORD gTmpEsi;
DWORD gTmpEdi;

DWORD gSelectASMJmp00 = 0x0040B00E;
DWORD gGraphicsASM00Jmp00 = 0x006E8D13;

void __declspec(naked) gSelectASM00()
{
	_asm
	{
		MOV gTmpEax,EAX
		MOV gTmpEsi,ESI
		MOV gTmpEdi,EDI
		MOV gTmpEcx,ECX
		MOV gTmpEdx,EDX
		MOV gTmpEbx,EBX
		MOV gTmpEsp,ESP
		MOV gTmpEbp,EBP
	}
	//----
	RenderScreenGlow();
	//----
	_asm
	{
		MOV EAX,gTmpEax
		MOV ESI,gTmpEsi
		MOV EDI,gTmpEdi
		MOV ECX,gTmpEcx
		MOV EDX,gTmpEdx
		MOV EBX,gTmpEbx
		MOV ESP,gTmpEsp
		MOV EBP,gTmpEbp
		ADD ECX,0x200
		//---
		JMP gSelectASMJmp00
	}
}

void __declspec(naked) gGraphicsASM00()
{
	_asm
	{
		MOV gTmpEax,EAX
		MOV gTmpEsi,ESI
		MOV gTmpEdi,EDI
		MOV gTmpEcx,ECX
		MOV gTmpEdx,EDX
		MOV gTmpEbx,EBX
		MOV gTmpEsp,ESP
		MOV gTmpEbp,EBP
	}
	//----
	RenderScreenGlow();
	//----
	_asm
	{
		MOV EAX,gTmpEax
		MOV ESI,gTmpEsi
		MOV EDI,gTmpEdi
		MOV ECX,gTmpEcx
		MOV EDX,gTmpEdx
		MOV EBX,gTmpEbx
		MOV ESP,gTmpEsp
		MOV EBP,gTmpEbp
		PUSH 0x0
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		//---
		JMP gGraphicsASM00Jmp00
	}
}

void Graphics::Load()
{
	//gToolKit.SetOp((LPVOID)oInitGraphics_Call,this->InitGraphics,ASM::CALL);
	gToolKit.SetOp((LPVOID)oSelectDraw_Call,this->SelectDraw,ASM::CALL);
	//---
	gToolKit.SetRange((LPVOID)0x0040B008,0x06,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0040B008,gSelectASM00);
	//---
	gToolKit.SetRange((LPVOID)0x006E8D0E,0x05,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x006E8D0E,gGraphicsASM00);
}

/*void Graphics::InitGraphics()
{
    InitScreenGlow();
	//---
	pInitGraphics();
}*/

int Graphics::SelectDraw(int value)
{
	RenderScreenGlow();
	//---
	return pSelectDraw(value);
}