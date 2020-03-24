#include "StdAfx.h"

cBags gBags;

void Naked cBags::AddInventoryPosition()
{
	static DWORD dwAddInventoryPosition_Pointer;
	static DWORD dwAddInventoryPosition_Buffer;
	static DWORD dwAddInventoryPosition_Jump = 0x0059F9EC;
	// ----
	_asm
	{
		MOV dwAddInventoryPosition_Pointer,ESI
	}
	// ----
	if(dwAddInventoryPosition_Pointer == ObjectId(14,65))	// -> Flame of Death Beam Knight
	{
		_asm
		{
			FLD DWORD PTR SS:[ESP+0x18]
			FADD DWORD PTR DS:[0x88B4F0]
			JMP dwAddInventoryPosition_Jump
		}
	}
	else if(dwAddInventoryPosition_Pointer >= ObjectId(14,101) && dwAddInventoryPosition_Pointer <= ObjectId(14,104))	// -> All Custom Boxs
	{
		_asm
		{
			FLD DWORD PTR SS:[ESP+0x18]
			FADD DWORD PTR DS:[0x88B4EC]			// FLOAT 0.02000000
			FSTP DWORD PTR SS:[ESP+0x18]
			MOV DWORD PTR DS:[0x7C12D68],0x43870000
			MOV DWORD PTR DS:[0x7C12D6C],0
			MOV DWORD PTR DS:[0x7C12D70],0
			JMP dwAddInventoryPosition_Jump
		}
	}
	else if(dwAddInventoryPosition_Pointer >= ObjectId(14,210) && dwAddInventoryPosition_Pointer <= ObjectId(14,212))
	{
		_asm
		{
			FLD DWORD PTR SS:[ESP+0x18]
			FSUB DWORD PTR DS:[0x88B4F0]			// FLOAT 0.05000000
			JMP dwAddInventoryPosition_Jump
		}
	}
	_asm
	{
		MOV dwAddInventoryPosition_Buffer,oItemAddInventoryPosition_Exit
		JMP dwAddInventoryPosition_Buffer
	}
}

void cBags::InitAddInventoryPosition()
{
	gToolKit.SetRange((LPVOID)oItemAddInventoryPosition_Hook,23,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemAddInventoryPosition_Hook,this->AddInventoryPosition);
}

static BOOL bAddInventorySize_Switcher;
static BOOL bAddInventorySize_Custom;

void Naked cBags::AddInventorySize()
{
	static DWORD dwAddInventorySize_Pointer;
	static DWORD dwAddInventorySize_Buffer;
	static DWORD dwOffsetJumpSize_Buffer = 0x005A0998;
	// ----
	bAddInventorySize_Custom = FALSE;
	bAddInventorySize_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwAddInventorySize_Pointer,ESI
	}
	// ----
	if(dwAddInventorySize_Pointer == ObjectId(14,65))	// -> Flame of Death Beam Knight
	{
		bAddInventorySize_Custom = FALSE;
		bAddInventorySize_Switcher = TRUE;
	}
	else if(dwAddInventorySize_Pointer >= ObjectId(14,101) && dwAddInventorySize_Pointer <= ObjectId(14,104))	// -> All Custom Event Item Bags
	{
		bAddInventorySize_Custom = TRUE;
		bAddInventorySize_Switcher = FALSE;
	}
	// ----
	if(bAddInventorySize_Switcher == TRUE)
	{
		_asm
		{
			MOV DWORD PTR SS:[ESP+0x10],0x3B449BA6
			JMP dwOffsetJumpSize_Buffer
		}
	}
	// ----
	if(bAddInventorySize_Custom == TRUE)
	{
		_asm
		{
			MOV DWORD PTR SS:[ESP+0x10],0x3AB78034
			JMP dwOffsetJumpSize_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwAddInventorySize_Buffer,oItemAddInventorySize_Return
			JMP dwAddInventorySize_Buffer
		}
	}
}

void cBags::InitAddInventorySize()
{
	gToolKit.SetRange((LPVOID)oItemAddInventorySize_Hook,21,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemAddInventorySize_Hook,this->AddInventorySize);
}

static BOOL bAddBoxOfLuckThis_Switcher;

void Naked cBags::AddBoxOfLuckThis()
{
	static DWORD dwAddBoxOfLuckThis_Pointer;
	static DWORD dwAddBoxOfLuckThis_Buffer;
	// ----
	bAddBoxOfLuckThis_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwAddBoxOfLuckThis_Pointer,ESI
	}
	// ----
	if(dwAddBoxOfLuckThis_Pointer == ItemId(14,11))	// -> Box of Luck
	{
		bAddBoxOfLuckThis_Switcher = TRUE;
	}
	else if(dwAddBoxOfLuckThis_Pointer >= ItemId(14,101) && dwAddBoxOfLuckThis_Pointer <= ItemId(14,104))	// -> All Custom Event Item Bags
	{
		bAddBoxOfLuckThis_Switcher = TRUE;
	}
	// ----
	if(bAddBoxOfLuckThis_Switcher == TRUE)
	{
		_asm
		{
			MOV dwAddBoxOfLuckThis_Buffer,oItemAddBoxOfLuckThis_Allowed
			JMP dwAddBoxOfLuckThis_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwAddBoxOfLuckThis_Buffer,oItemAddBoxOfLuckThis_Return
			JMP dwAddBoxOfLuckThis_Buffer
		}
	}
}

void cBags::InitAddBoxOfLuckThis()
{
	gToolKit.SetRange((LPVOID)oItemAddBoxOfLuckThis_Hook,8,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemAddBoxOfLuckThis_Hook,this->AddBoxOfLuckThis);
}

static BOOL bAddFloorSize_Switcher;

void Naked cBags::AddFloorSize()
{
	static DWORD dwAddFloorSize_Pointer;
	static DWORD dwAddFloorSize_Buffer;
	// ----
	bAddFloorSize_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOV EAX,DWORD PTR DS:[EDX+0x30]
		MOV dwAddFloorSize_Pointer,EAX
	}
	// ----
	if(dwAddFloorSize_Pointer >= ObjectId(14,55) && dwAddFloorSize_Pointer <= ObjectId(14,57))			// -> Red, Green & Purple Chaos Box
	{
		bAddFloorSize_Switcher = TRUE;
	}
	else if(dwAddFloorSize_Pointer >= ObjectId(14,101) && dwAddFloorSize_Pointer <= ObjectId(14,104))	// -> All Custom Event Item Bags
	{
		bAddFloorSize_Switcher = TRUE;
	}
	// ----
	if(bAddFloorSize_Switcher == TRUE)
	{
		_asm
		{
			MOV dwAddFloorSize_Buffer,oItemAddFloorSize_Allowed
			JMP dwAddFloorSize_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwAddFloorSize_Buffer,oItemAddFloorSize_Return
			JMP dwAddFloorSize_Buffer
		}
	}
}

void cBags::InitAddFloorSize()
{
	gToolKit.SetRange((LPVOID)oItemAddFloorSize_Hook,12,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemAddFloorSize_Hook,this->AddFloorSize);
}

void cBags::Load()
{
	this->InitAddBoxOfLuckThis();
	this->InitAddInventorySize();
	this->InitAddFloorSize();
	//this->InitAddInventoryPosition();
}