#include "StdAfx.h"

cBows gBows;

/*
gToolKit.SetOp((LPVOID)0x0066CF08,this->CreateBowSkill,ASM::CALL);
gToolKit.SetOp((LPVOID)0x00699907,this->CreateBowSkill,ASM::CALL);
gToolKit.SetOp((LPVOID)0x006999CF,this->CreateBowSkill,ASM::CALL);
gToolKit.SetOp((LPVOID)0x00699A0A,this->CreateBowSkill,ASM::CALL);
gToolKit.SetOp((LPVOID)0x00699A45,this->CreateBowSkill,ASM::CALL);
gToolKit.SetOp((LPVOID)0x00699A80,this->CreateBowSkill,ASM::CALL);
gToolKit.SetOp((LPVOID)0x00699ADA,this->CreateBowSkill,ASM::CALL);
gToolKit.SetOp((LPVOID)0x00699B15,this->CreateBowSkill,ASM::CALL);
gToolKit.SetOp((LPVOID)0x00699B50,this->CreateBowSkill,ASM::CALL);
gToolKit.SetOp((LPVOID)0x00699BA7,this->CreateBowSkill,ASM::CALL);
*/

void Naked cBows::CreateBowSkill()
{
	static DWORD dwCreateBowSkill_Pointer;
	static DWORD dwCreateBowSkill_Buffer;
	static DWORD dwCreateEffect = 0x00650FF0;
	// ----
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x8]
		MOV DWORD PTR SS:[EBP-0x14],EDX
		MOV dwCreateBowSkill_Pointer,EDX
	}
	// ----
	if(dwCreateBowSkill_Pointer == ObjectId(4,25)) // -> Lightning Bow
	{
		_asm
		{
			PUSH -1
			PUSH 0
			PUSH 0
			MOV DX,WORD PTR SS:[EBP+0x18]
			PUSH EDX
			MOV AX,WORD PTR SS:[EBP+0x14]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			MOV DX,WORD PTR DS:[ECX+0x2C]
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x0C]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x0C]
			ADD EDX,0x9C
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			ADD EAX,0x108
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			ADD ECX,0xFC
			PUSH ECX
			PUSH ArrowDouble
			CALL dwCreateEffect
		}
	}
	else if(dwCreateBowSkill_Pointer == ObjectId(4,26)) // -> Divinity Bow
	{
		_asm
		{
			PUSH -1
			PUSH 0
			PUSH 0
			MOV DX,WORD PTR SS:[EBP+0x18]
			PUSH EDX
			MOV AX,WORD PTR SS:[EBP+0x14]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			MOV DX,WORD PTR DS:[ECX+0x2C]
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x0C]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x0C]
			ADD EDX,0x9C
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			ADD EAX,0x108
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			ADD ECX,0xFC
			PUSH ECX
			PUSH Sketbows_Arrows
			CALL dwCreateEffect
		}
	}
	else if(dwCreateBowSkill_Pointer == ObjectId(4,27)) // -> Angelic Bow
	{
		_asm
		{
			PUSH -1
			PUSH 0
			PUSH 0
			MOV DX,WORD PTR SS:[EBP+0x18]
			PUSH EDX
			MOV AX,WORD PTR SS:[EBP+0x14]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			MOV DX,WORD PTR DS:[ECX+0x2C]
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x0C]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x0C]
			ADD EDX,0x9C
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			ADD EAX,0x108
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			ADD ECX,0xFC
			PUSH ECX
			PUSH CW_Bow_Skill
			CALL dwCreateEffect
		}
	}
	else if(dwCreateBowSkill_Pointer == ObjectId(4,28)) // -> Thunder Bow
	{
		_asm
		{
			PUSH -1
			PUSH 0
			PUSH 0
			MOV DX,WORD PTR SS:[EBP+0x18]
			PUSH EDX
			MOV AX,WORD PTR SS:[EBP+0x14]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			MOV DX,WORD PTR DS:[ECX+0x2C]
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x0C]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x0C]
			ADD EDX,0x9C
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			ADD EAX,0x108
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			ADD ECX,0xFC
			PUSH ECX
			PUSH Carrow
			CALL dwCreateEffect
		}
	}
	else if(dwCreateBowSkill_Pointer == ObjectId(4,29)) // -> Darkness Bow
	{
		_asm
		{
			PUSH -1
			PUSH 0
			PUSH 0
			MOV DX,WORD PTR SS:[EBP+0x18]
			PUSH EDX
			MOV AX,WORD PTR SS:[EBP+0x14]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			MOV DX,WORD PTR DS:[ECX+0x2C]
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x0C]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x0C]
			ADD EDX,0x9C
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			ADD EAX,0x108
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			ADD ECX,0xFC
			PUSH ECX
			PUSH LaceArrow
			CALL dwCreateEffect
		}
	}
	else if(dwCreateBowSkill_Pointer == ObjectId(4,30)) // -> Blood Angel Bow
	{
		_asm
		{
			PUSH -1
			PUSH 0
			PUSH 0
			MOV DX,WORD PTR SS:[EBP+0x18]
			PUSH EDX
			MOV AX,WORD PTR SS:[EBP+0x14]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			MOV DX,WORD PTR DS:[ECX+0x2C]
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x0C]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x0C]
			ADD EDX,0x9C
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			ADD EAX,0x108
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			ADD ECX,0xFC
			PUSH ECX
			PUSH HDK_Arrow
			CALL dwCreateEffect
		}
	}
	_asm
	{
		MOV dwCreateBowSkill_Buffer,oCreateBowSkill_Return
		JMP dwCreateBowSkill_Buffer
	}
}

void cBows::InitCreateBowSkill()
{
	gToolKit.SetRange((LPVOID)oCreateBowSkill_Hook,6,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oCreateBowSkill_Hook,this->CreateBowSkill);
}

void Naked cBows::CreateCrossSkill()
{
	static DWORD dwCreateCrossSkill_Pointer;
	static DWORD dwCreateCrossSkill_Buffer;
	static DWORD dwCreateEffect = 0x00650FF0;
	// ----
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x4]
		MOV DWORD PTR SS:[EBP-0x10],EDX
		MOV dwCreateCrossSkill_Pointer,EDX
	}
	// ----
	if(dwCreateCrossSkill_Pointer == ObjectId(4,129)) // -> Devil Crossbow
	{
		_asm
		{
			PUSH -1
			PUSH 0
			PUSH 0
			MOV DX,WORD PTR SS:[EBP+0x18]
			PUSH EDX
			MOV AX,WORD PTR SS:[EBP+0x14]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			MOV DX,WORD PTR DS:[ECX+0x2C]
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x0C]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x0C]
			ADD EDX,0x9C
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0xC]
			ADD EAX,0x108
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0xC]
			ADD ECX,0xFC
			PUSH ECX
			PUSH Stars_Shoot
			CALL dwCreateEffect
			ADD ESP,0x30
		}
	}
	if(dwCreateCrossSkill_Pointer == ObjectId(4,130)) // -> Absolute Archangel Crossbow
	{
		_asm
		{
			PUSH -1
			PUSH 0
			PUSH 0
			MOV DX,WORD PTR SS:[EBP+0x18]
			PUSH EDX
			MOV AX,WORD PTR SS:[EBP+0x14]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0x0C]
			MOV DX,WORD PTR DS:[ECX+0x2C]
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0x0C]
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x0C]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP+0x0C]
			ADD EDX,0x9C
			PUSH EDX
			MOV EAX,DWORD PTR SS:[EBP+0xC]
			ADD EAX,0x108
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP+0xC]
			ADD ECX,0xFC
			PUSH ECX
			PUSH Arrow_Divine
			CALL dwCreateEffect
			ADD ESP,0x30
		}
	}
	_asm
	{
		MOV dwCreateCrossSkill_Buffer,0x006990E3
		JMP dwCreateCrossSkill_Buffer
	}
}

void cBows::InitCreateCrossSkill()
{
	gToolKit.SetRange((LPVOID)0x006990DD,6,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x006990DD,this->CreateCrossSkill);
}

static BOOL bCreateInvenPos_Switcher;

void Naked cBows::CreateInvenPos()
{
	static DWORD dwCreateInvenPos_Pointer;
	static DWORD dwCreateInvenPos_Buffer;
	// ----
	bCreateInvenPos_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwCreateInvenPos_Pointer,ESI
	}
	// ----
	if(dwCreateInvenPos_Pointer == ObjectId(4,24))		// -> Gamble Bow (Original)
	{
		bCreateInvenPos_Switcher = TRUE;
	}
	else if(dwCreateInvenPos_Pointer == ObjectId(4,25)) // -> Lightning Bow (Custom)
	{
		bCreateInvenPos_Switcher = TRUE;
	}
	else if(dwCreateInvenPos_Pointer == ObjectId(4,26)) // -> Divinity Bow (Custom)
	{
		bCreateInvenPos_Switcher = TRUE;
	}
	else if(dwCreateInvenPos_Pointer == ObjectId(4,27)) // -> Angelic Bow (Custom)
	{
		bCreateInvenPos_Switcher = TRUE;
	}
	else if(dwCreateInvenPos_Pointer == ObjectId(4,28)) // -> Thunder Bow (Custom)
	{
		bCreateInvenPos_Switcher = TRUE;
	}
	else if(dwCreateInvenPos_Pointer == ObjectId(4,29))	// -> Darkness Bow (Custom)
	{
		bCreateInvenPos_Switcher = TRUE;
	}
	else if(dwCreateInvenPos_Pointer == ObjectId(4,30))	// -> Blood Angel Bow (Season XI Episode 2)
	{
		bCreateInvenPos_Switcher = TRUE;
	}
	// ----
	if(bCreateInvenPos_Switcher == TRUE)
	{
		_asm
		{
			MOV dwCreateInvenPos_Buffer,oCreateInvenPos_Allowed
			JMP dwCreateInvenPos_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwCreateInvenPos_Buffer,oCreateInvenPos_Return
			JMP dwCreateInvenPos_Buffer
		}
	}
}

void cBows::InitCreateInvenPos()
{
	gToolKit.SetRange((LPVOID)oCreateInvenPos_Hook,8,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oCreateInvenPos_Hook,this->CreateInvenPos);
}

void Naked cBows::CreateBowDimension()
{
	static DWORD dwCreateBowDimension_Jump = oCreateBowDimension_Next;
	// ----
	_asm
	{
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,0)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,1)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,2)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,3)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,4)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,5)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,6)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,7)		// -> Bolt... Extrange but yes. :D
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,17)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,20)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,21)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,22)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,23)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,24)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,25)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,26)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,27)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,28)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,29)
		JE ReturnLoad
		CMP DWORD PTR SS:[EBP+0x1C],ObjectId(4,30)
		JE ReturnLoad
		// ----
		ReturnLoad:
		// ----
		JMP dwCreateBowDimension_Jump
	}
}

void cBows::InitCreateBowDimension()
{
	gToolKit.SetRange((LPVOID)oCreateBowDimension_Hook,7,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oCreateBowDimension_Hook,this->CreateBowDimension);
}

static BOOL bCreateBowPos_Switcher;
static BOOL bCreateCrossPos_Switcher;

void Naked cBows::CreateBowAndCrossBowPos()
{
	static DWORD CallFuncOffset = 0x006BC835;
	static DWORD JumpFuncOffset = 0x004E99E8;
	// ----
	static DWORD dwCreateBowAndCrossBowPos_Pointer;
	static DWORD dwCreateBowAndCrossBowPos_Buffer;
	// ----
	bCreateBowPos_Switcher		= FALSE;						// -> For Bows
	bCreateCrossPos_Switcher	= FALSE;						// -> For CrossBows
	// ----
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0x1C]
		MOV dwCreateBowAndCrossBowPos_Pointer,EAX
	}
	// ----
	if(dwCreateBowAndCrossBowPos_Pointer >= ObjectId(4,8)		// -> Crossbow
	&& dwCreateBowAndCrossBowPos_Pointer <= ObjectId(4,14)		// -> Aquagold Crossbow
	|| dwCreateBowAndCrossBowPos_Pointer == ObjectId(4,16)		// -> Saint Crossbow
	|| dwCreateBowAndCrossBowPos_Pointer == ObjectId(4,18)		// -> Divine Crossbow of Archangel
	|| dwCreateBowAndCrossBowPos_Pointer == ObjectId(4,19))		// -> Great Reign Crossbow
	{
		bCreateCrossPos_Switcher = TRUE;
	}
	else if(dwCreateBowAndCrossBowPos_Pointer >= ObjectId(4,0)	// -> Short Bow
	&& dwCreateBowAndCrossBowPos_Pointer <= ObjectId(4,6)		// -> Chaos Nature Bow
	|| dwCreateBowAndCrossBowPos_Pointer == ObjectId(4,17)		// -> Celestial Bow 
	|| dwCreateBowAndCrossBowPos_Pointer >= ObjectId(4,20)		// -> Arrow Viper Bow
	&& dwCreateBowAndCrossBowPos_Pointer <= ObjectId(4,24)		// -> Gamble Bow
	|| dwCreateBowAndCrossBowPos_Pointer == ObjectId(4,15)		// -> Arrow
	|| dwCreateBowAndCrossBowPos_Pointer == ObjectId(4,7))		// -> Bolt ?? =)
	{
		bCreateBowPos_Switcher = TRUE;
	}
	// ----
	else if(dwCreateBowAndCrossBowPos_Pointer >= ObjectId(4,25) && dwCreateBowAndCrossBowPos_Pointer <= ObjectId(4,128))	// -> Custom Bows
	{
		bCreateBowPos_Switcher = TRUE;
	}
	else if(dwCreateBowAndCrossBowPos_Pointer >= ObjectId(4,129) && dwCreateBowAndCrossBowPos_Pointer <= ObjectId(4,255))	// -> Custom CrossBows
	{
		bCreateCrossPos_Switcher = TRUE;
	}
	// ----
	if(bCreateBowPos_Switcher == TRUE)
	{
		_asm
		{
			MOV DWORD PTR SS:[EBP-0x0B0],0x428C0000
			MOV DWORD PTR SS:[EBP-0x0AC],0x0
			MOV DWORD PTR SS:[EBP-0x0A8],0x42B40000
			LEA ECX,[EBP-0x0A4]
			PUSH ECX
			LEA EDX,[EBP-0x0B0]
			PUSH EDX
			CALL CallFuncOffset
			ADD ESP,0x8
			MOV DWORD PTR SS:[EBP-0x98],0xC1200000
			MOV DWORD PTR SS:[EBP-0x88],0x41000000
			MOV DWORD PTR SS:[EBP-0x78],0x42200000
			JMP JumpFuncOffset
		}
	}
	// ----
	if(bCreateCrossPos_Switcher == TRUE)
	{
		_asm
		{
			MOV DWORD PTR SS:[EBP-0x0B0],0x0
			MOV DWORD PTR SS:[EBP-0x0AC],0x41A00000
			MOV DWORD PTR SS:[EBP-0x0A8],0x43340000
			LEA ECX,[EBP-0x0A4]
			PUSH ECX
			LEA EDX,[EBP-0x0B0]
			PUSH EDX
			CALL CallFuncOffset
			ADD ESP,0x8
			MOV DWORD PTR SS:[EBP-0x98],0xC1200000
			MOV DWORD PTR SS:[EBP-0x88],0x41000000
			MOV DWORD PTR SS:[EBP-0x78],0x42200000
			JMP JumpFuncOffset
		}
	}
	// ----
	_asm
	{
		MOV dwCreateBowAndCrossBowPos_Buffer,0x004E966E
		JMP dwCreateBowAndCrossBowPos_Buffer
	}
}

void cBows::InitCreateBowAndCrossBowPos()
{
	gToolKit.SetRange((LPVOID)0x004E95E4,138,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004E95E4,this->CreateBowAndCrossBowPos);
}

void cBows::Load()
{
	this->InitCreateInvenPos();
	this->InitCreateBowSkill();
	this->InitCreateCrossSkill();
	this->InitCreateBowDimension();
	this->InitCreateBowAndCrossBowPos();
}