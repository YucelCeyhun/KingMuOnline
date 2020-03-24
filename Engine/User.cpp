#include "StdAfx.h"

cUser gUser;

#ifdef __FOR_104E__
void Naked cUser::SetItemOptionUpdate()
{
	static DWORD dwSetItemOption_Jump	= 0x004E8CEA;
	static DWORD dwSetItemOption_Call	= 0x009CF1C0;
	// ----
	static UINT uiSetItemOption_Adition	= 0xBF;			// -> 0xBF = 191 (255 - 64) = 191
	// ----
	_asm
	{
		MOV uiSetItemOption_Adition,EAX
		// ----
		LEA ECX,[EDX+EAX+0x8004]
		PUSH ECX
		CALL dwSetItemOption_Call
		ADD ESP,0xC
		// ----
		JMP dwSetItemOption_Jump
	}
}

void cUser::InitSetItemOptionUpdate()
{
	gToolKit.SetOp((LPVOID)0x004E8CDA,this->SetItemOptionUpdate,ASM::JMP);
}
#else
void Naked cUser::SetItemOptionUpdate()
{
	static DWORD dwSetItemOption_Jump		= 0x00492723;
	static DWORD dwSetItemOption_Call		= 0x00850990;
	// ----
	static int uiSetItemOption_Adition		= 0x19;			// -> 0xBF = 191 (255 - 64) = 191
	// ----
	_asm
	{
		MOV uiSetItemOption_Adition,EAX
	}
	// ----
	_asm
	{
		LEA ECX,[EDX+EAX+0x8004]
		PUSH ECX
		CALL dwSetItemOption_Call
		ADD ESP,0xC
		// ----
		JMP dwSetItemOption_Jump
	}
}

void cUser::InitSetItemOptionUpdate()
{
	gToolKit.SetByte((PVOID)(0x004926DD+6),0x0FE);
	gToolKit.SetOp((LPVOID)0x00492713,this->SetItemOptionUpdate,ASM::JMP);
}
#endif

/*
void Naked cUser::CharacterExternInfo()
{
	static DWORD CharacterInfoExtern_Buff;
	static CHAR CharacterInfoExtern_LevelBuff[40];
	// ----
	sprintf(CharacterInfoExtern_LevelBuff,"Level: %d | Reset: %d(%d)",pPlayerLevel,gUser.m_Reset,gUser.m_GrandReset);
	// ----
	_asm
	{
		LEA EDX,CharacterInfoExtern_LevelBuff
		PUSH EDX
		// ----
		MOV CharacterInfoExtern_Buff,0x006EEE05
		JMP CharacterInfoExtern_Buff
	}
}

void Naked cUser::CharacterExternPoint()
{
	static DWORD CharacterExternPoint_Buff;
	static CHAR CharacterExternPoint_LevelBuff[40];
	// ----
	sprintf(CharacterExternPoint_LevelBuff,"  Points: %d",pPlayerPoint);
	// ----
	_asm
	{
		LEA EAX,CharacterExternPoint_LevelBuff
		PUSH EAX
		// ----
		MOV CharacterExternPoint_Buff,0x006EEEFE
		JMP CharacterExternPoint_Buff
	}
}
*/

/*
void cUser::RecvAttackResult(PMSG_ATTACKRESULT * aRecv)
{
	short aIndex = MAKE_NUMBERW(aRecv->NumberH,aRecv->NumberL);
	
	if(pGetViewPortId(aIndex) < 400)
	{
		this->TargetData[aIndex].Life			= aRecv->Life;
		this->TargetData[aIndex].Live			= (aRecv->Life <= 0.0f) ? FALSE : TRUE; 
		this->TargetData[aIndex].Class			= aRecv->Class;
		this->TargetData[aIndex].TickCount		= GetTickCount();
		this->TargetData[aIndex].MaxLife		= aRecv->MaxLife;
		this->TargetData[aIndex].LifePercent	= ((aRecv->Life / aRecv->MaxLife) * 100.0f);
	}
}

void cUser::RecvKilledObject(PMSG_DIEPLAYER* aRecv)
{
	short aIndex = MAKE_NUMBERW(aRecv->NumberH,aRecv->NumberL);
	
	if(pGetViewPortId(aIndex) < 400)
	{
		this->TargetData[aIndex].Life			= 0.0f;
		this->TargetData[aIndex].Live			= FALSE;
		this->TargetData[aIndex].LifePercent	= 0.0f;
	}
}
*/

void cUser::Load()
{
	//ZeroMemory(&this->TargetData,sizeof(this->TargetData));
	// ----
	this->m_Reset		= 0;
	this->m_GrandReset	= 0;
	// ----
	//this->InitSetItemOptionUpdate();
	//gToolKit.SetByte((PVOID)(0x0049265F),ASM::JMPS);
	//gToolKit.SetOp((LPVOID)0x006EEDFE,this->CharacterExternInfo,ASM::JMP);
	//gToolKit.SetOp((LPVOID)0x006EEEF7,this->CharacterExternPoint,ASM::JMP);
}