#include "StdAfx.h"

cDamage gDamage;

void cDamage::DamageRot(float& X,float& Y,float D)
{
	const float Rad = 0.01745329;
	// ----
	float sinTh = sin(Rad * (*Camera_RotZ));
	float cosTh = cos(Rad * (*Camera_RotZ));
	// ----
	X += D / 0.7071067 * cosTh / 2;
	Y -= D / 0.7071067 * sinTh / 2;
}

void cDamage::Load()
{
	const DWORD DamgRotCall_Offset	= 0x005F4F9C;
	const DWORD DamgRotPatch_Offset	= 0x005F4F91;
	// ----
	char Hook[] = { 0x8D,0x45,0xF8,0x8D,0x4D,0xF4,0xFF,0x75,0x18,0x50,0x51,0xE8,0x6F,0xA1,0xA0,0xFF,0x83,0xC4,0x0C,0xE9,0x07,0xFF,0xFF,0xFF };
	// ----
	memcpy((LPVOID)DamgRotPatch_Offset,Hook,sizeof(Hook));
	gToolKit.SetOp((LPVOID)DamgRotCall_Offset,this->DamageRot,ASM::CALL);
}