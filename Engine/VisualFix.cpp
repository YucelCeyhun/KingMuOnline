#include "StdAfx.h"

cVisualFix gVisualFix;

cVisualFix::cVisualFix()
{
	this->aIndex = 0;
	this->AttackHP = 0;
	this->AttackSD = 0;
	this->Life = 0;
	this->SD = 0;
	this->Mana = 0;
	this->AG = 0;
	this->MaxLife = 0;
	this->MaxSD = 0;
	this->MaxMana = 0;
	this->MaxAG = 0;
	this->UpPoint = 0;
	this->PlayerKill = TRUE;
	this->AttackRate = 0;
	this->DamageRate = 0;
}

void cVisualFix::Load()
{
	gToolKit.SetOp((LPVOID)0x0061A29E, (LPVOID)this->DrawDamageHP, ASM::CALL); // 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x0061A2FE, (LPVOID)this->DrawDamageSD, ASM::CALL); // 1.03K (100%)

	gToolKit.SetOp((LPVOID)0x0073A26F, (LPVOID)this->DrawHp, ASM::CALL); // 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x0073A3B0, (LPVOID)this->DrawMp, ASM::CALL); // 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x0073A651, (LPVOID)this->DrawAg, ASM::CALL); // 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x0073A8F5, (LPVOID)this->DrawSd, ASM::CALL); // 1.03K (100%)

	gToolKit.SetOp((LPVOID)0x0073A2F6, (LPVOID)this->DrawTabHP, ASM::CALL); // 1.03K (100%) ! Easy to find
	gToolKit.SetOp((LPVOID)0x0073A438, (LPVOID)this->DrawTabMP, ASM::CALL); // 1.03K (100%) ! Easy to find
	gToolKit.SetOp((LPVOID)0x0073A98E, (LPVOID)this->DrawTabSD, ASM::CALL); // 1.03K (100%) ! Easy to find
	gToolKit.SetOp((LPVOID)0x0073A6DC, (LPVOID)this->DrawTabAG, ASM::CALL); // 1.03K (100%) ! Easy to find

	gToolKit.SetOp((LPVOID)0x006F115C, (LPVOID)this->InfoHp, ASM::CALL);	// 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x006F1197, (LPVOID)this->InfoHp, ASM::CALL);	// 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x006F14C7, (LPVOID)this->InfoMp, ASM::CALL);	// 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x006F1501, (LPVOID)this->InfoMp, ASM::CALL);	// 1.03K (100%)

	gToolKit.SetOp((LPVOID)0x006EEE8D, (LPVOID)this->InfoPoint, ASM::CALL); // 1.03K (100%)

	gToolKit.SetOp((LPVOID)0x006C78EC, (LPVOID)this->DrawCircle, ASM::CALL);	// - hp
	gToolKit.SetOp((LPVOID)0x006C7933, (LPVOID)this->DrawCircle, ASM::CALL);	// - hp
	gToolKit.SetOp((LPVOID)0x006C7B1A, (LPVOID)this->DrawCircle, ASM::CALL);	// - mp
	gToolKit.SetOp((LPVOID)0x006C7E85, (LPVOID)this->DrawCircle, ASM::CALL);	// - ag
	gToolKit.SetOp((LPVOID)0x006C8481, (LPVOID)this->DrawCircle, ASM::CALL);	// - sd

	gToolKit.SetOp((LPVOID)0x00513803, (LPVOID)this->CalculateAttackRate, ASM::CALL);	// 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x005137CB, (LPVOID)this->CalculateDamageRate, ASM::CALL);	// 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x004DDEEF, (LPVOID)this->CalculateAttackSpeed, ASM::CALL); // 1.03K (100%)

	gToolKit.SetRange((LPVOID)0x006EF861, 9, ASM::NOP); // 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x006EF861, (LPVOID)this->GetAttackRate, ASM::CALL); // 1.03K (100%)

	gToolKit.SetRange((LPVOID)0x006EF99C, 9, ASM::NOP); // 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x006EF99C, (LPVOID)this->GetAttackRate, ASM::CALL); // 1.03K (100%)

	gToolKit.SetRange((LPVOID)0x006EF84A, 10, ASM::NOP);
	gToolKit.SetOp((LPVOID)0x006EF84A, (LPVOID)this->GetDamageRate, ASM::CALL); // 1.03K (100%)

	gToolKit.SetRange((LPVOID)0x006EF8C8, 10, ASM::NOP); // 1.03K (100%)
	gToolKit.SetOp((LPVOID)0x006EF8C8, (LPVOID)this->GetDamageRate, ASM::CALL); // 1.03K (100%)
}

void cVisualFix::RecvIndex(PMSG_JOINRESULT* Data)
{
	this->aIndex = MAKE_NUMBERW(Data->NumberH, Data->NumberL);
	this->PlayerKill = FALSE;
}

void cVisualFix::RecvDamage(PMSG_ATTACKRESULT* Data)
{
	this->AttackHP = Data->AttackHP;
	this->AttackSD = Data->AttackSD;

	short tIndex = MAKE_NUMBERW(Data->NumberH, Data->NumberL);

	if (this->aIndex == tIndex)
	{
		this->Life -= this->AttackHP;
		this->SD -= this->AttackSD;

		if (this->Life < 0)
		{
			this->Life = 0;
		}
	}
}

void cVisualFix::RecvHPSD(PMSG_REFILL* Data)
{
	if (Data->IPos == 0xFF)
	{
		this->Life = Data->Life;
		this->SD = Data->Shield;
	}
	else if (Data->IPos == 0xFE)
	{
		this->MaxLife = Data->Life;
		this->MaxSD = Data->Shield;
	}

	if (this->Life > this->MaxLife)
	{
		this->Life = this->MaxLife;
	}

	if (this->PlayerKill == TRUE)
	{
		this->Life = 0;
		this->SD = 0;
	}
}

void cVisualFix::RecvMPAG(PMSG_MANASEND* Data)
{
	if (Data->IPos == 0xFF)
	{
		this->Mana = Data->Mana;
		this->AG = Data->BP;
	}
	else if (Data->IPos == 0xFE)
	{
		this->MaxMana = Data->Mana;
		this->MaxAG = Data->BP;
	}

	if (this->Mana > this->MaxMana)
	{
		this->Mana = this->MaxMana;
	}
}

void cVisualFix::RecvUpPoint(PMSG_CHARMAPJOINRESULT* Data)
{
	this->UpPoint = Data->UpPoint;
}

void cVisualFix::RecvUpLevel(PMSG_LEVELUP* Data)
{
	this->UpPoint = Data->UpPoint;
}

void cVisualFix::RecvDownPoint(PMSG_LVPOINTADDRESULT* Data)
{
	if (Data->ResultType != 0)
	{
		this->UpPoint--;
	}
}

void cVisualFix::RecvRespawn()
{
	this->PlayerKill = FALSE;
	this->Life = this->MaxLife;
	this->SD = this->MaxSD;
}

void cVisualFix::RecvKilledObject(PMSG_DIEPLAYER* Data) // check if is sent
{
	short tIndex = MAKE_NUMBERW(Data->NumberH, Data->NumberL);

	if (this->aIndex == tIndex)
	{
		this->Life = 0;
		this->SD = 0;
		this->PlayerKill = TRUE;
	}
}

void cVisualFix::DrawDamageHP(int a1, int a2, int a3, float a4, char a5)
{
	pDrawDamage(a1, gVisualFix.AttackHP, a3, a4, a5);
}

void cVisualFix::DrawDamageSD(int a1, int a2, int a3, float a4, char a5)
{
	pDrawDamage(a1, gVisualFix.AttackSD, a3, a4, a5);
}

double cVisualFix::DrawHp(float a1, float a2, int Value, float a4)
{
	return pDrawBar(a1, a2 - 10.0f, gVisualFix.Life, 1.0f);
}

double cVisualFix::DrawMp(float a1, float a2, int Value, float a4)
{
	return pDrawBar(a1, a2 - 10.0f, gVisualFix.Mana, 1.0f);
}

double cVisualFix::DrawAg(float a1, float a2, int a3, float a4)
{
	return pDrawBar(a1, a2, gVisualFix.AG, a4);
}

double cVisualFix::DrawSd(float a1, float a2, int a3, float a4)
{
	return pDrawBar(a1, a2, gVisualFix.SD, a4);
}

int cVisualFix::DrawTabHP(signed int a1, signed int a2, LPCSTR lpMultiByteStr)
{
	sprintf_s(gVisualFix.LifeTab, "Life: %d/%d", gVisualFix.Life, gVisualFix.MaxLife);
	return pDrawTab(a1, a2, gVisualFix.LifeTab);
}

int cVisualFix::DrawTabMP(signed int a1, signed int a2, LPCSTR lpMultiByteStr)
{
	sprintf_s(gVisualFix.ManaTab, "Mana: %d/%d", gVisualFix.Mana, gVisualFix.MaxMana);
	return pDrawTab(a1, a2, gVisualFix.ManaTab);
}

int cVisualFix::DrawTabSD(signed int a1, signed int a2, LPCSTR lpMultiByteStr)
{
	sprintf_s(gVisualFix.SDTab, "SD: %d/%d", gVisualFix.SD, gVisualFix.MaxSD);
	return pDrawTab(a1, a2, gVisualFix.SDTab);
}

int cVisualFix::DrawTabAG(signed int a1, signed int a2, LPCSTR lpMultiByteStr)
{
	sprintf_s(gVisualFix.AGTab, "AG: %d/%d", gVisualFix.AG, gVisualFix.MaxAG);
	return pDrawTab(a1, a2, gVisualFix.AGTab);
}

int cVisualFix::InfoHp(int a1, const char* a2, ...)
{
	return pInfo(a1, a2, gVisualFix.Life, gVisualFix.MaxLife);
}

int cVisualFix::InfoMp(int a1, const char* a2, ...)
{
	return pInfo(a1, a2, gVisualFix.Mana, gVisualFix.MaxMana);
}

int cVisualFix::InfoPoint(int a1, const char* a2, ...)
{
	if ((gVisualFix.UpPoint == 0) && (pPlayerPoint != 0)) // Marlon add stat fix
	{
		gVisualFix.UpPoint = pPlayerPoint;
	}

	return pInfo(a1, a2, gVisualFix.UpPoint);
}

void cVisualFix::DrawCircle(DWORD ModelID, float Arg2, float Arg3, float Arg4, float Arg5, float Arg6, float Arg7, float Arg8, float Arg9, bool Arg10, bool Arg11, float Arg12)
{
	float Height = 39.0f;
	float PosY = 432.0f;

	float LifeFill = (float)(gVisualFix.MaxLife - gVisualFix.Life) / (float)gVisualFix.MaxLife;
	float ManaFill = (float)(gVisualFix.MaxMana - gVisualFix.Mana) / (float)gVisualFix.MaxMana;
	float AgFill = (float)(gVisualFix.MaxAG - gVisualFix.AG) / (float)gVisualFix.MaxAG;
	float SdFill = (float)(gVisualFix.MaxSD - gVisualFix.SD) / (float)gVisualFix.MaxSD;

	if ((ModelID == 0x7A41) || (ModelID == 0x7A42))
	{
		float StartY = LifeFill * Height + PosY;
		float StartHeight = Height - LifeFill * Height;
		float SourceY = LifeFill * Height / 64.0f;
		float SouceHeight = (1.0f - LifeFill) * Height / 64.0f;

		return pDrawCircle(ModelID, Arg2, StartY, Arg4, StartHeight, 0, SourceY, Arg8, SouceHeight, 1, 1, 0);
	}

	if (ModelID == 0x7A40)
	{
		float StartY = ManaFill * Height + PosY;
		float StartHeight = Height - ManaFill * Height;
		float SourceY = ManaFill * Height / 64.0f;
		float SouceHeight = (1.0f - ManaFill) * Height / 64.0f;

		return pDrawCircle(ModelID, Arg2, StartY, Arg4, StartHeight, 0, SourceY, Arg8, SouceHeight, 1, 1, 0);
	}

	if (ModelID == 0x7A43)
	{
		float StartY = AgFill * Height + PosY;
		float StartHeight = Height - AgFill * Height;
		float SourceY = AgFill * Height / 64.0f;
		float SouceHeight = (1.0f - AgFill) * Height / 64.0f;

		return pDrawCircle(ModelID, Arg2, StartY, Arg4, StartHeight, 0, SourceY, Arg8, SouceHeight, 1, 1, 0);
	}

	if (ModelID == 0x7A44)
	{
		float StartY = SdFill * Height + PosY;
		float StartHeight = Height - SdFill * Height;
		float SourceY = SdFill * Height / 64.0f;
		float SouceHeight = (1.0f - SdFill) * Height / 64.0f;

		return pDrawCircle(ModelID, Arg2, StartY, Arg4, StartHeight, 0, SourceY, Arg8, SouceHeight, 1, 1, 0);
	}
	// ----
	pDrawCircle(ModelID, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12);
}

void cVisualFix::CalculateAttackRate(lpCharObj lpUser, LPVOID EDX)
{
	float AttackRate = 0.0f;
	int Dexterity = lpUser->Dexterity + lpUser->AddDexterity;

	switch (lpUser->Class & 7)
	{
	case DarkWizard:
	case DarkLord:
	{
		AttackRate = (float)(lpUser->Level * 3 + Dexterity * 4);
		break;
	}
	case DarkKnight:
	{
		AttackRate = (float)(lpUser->Level * 3 + (Dexterity * 45) / 10);
		break;
	}
	case Elf:
	{
		AttackRate = (float)(lpUser->Level * 3 + (Dexterity * 6) / 10);
		break;
	}
	case MagicGladiator:
	case Summoner:
	{
		AttackRate = (float)(lpUser->Level * 3 + (Dexterity * 35) / 10);
		break;
	}
	}

	gVisualFix.AttackRate = (int)AttackRate;
	lpUser->AttackRate = (WORD)gVisualFix.AttackRate;
}

void cVisualFix::CalculateDamageRate(lpCharObj lpUser, LPVOID EDX)
{
	int Strength = lpUser->Strength + lpUser->AddStrength;
	int Dexterity = lpUser->Dexterity + lpUser->AddDexterity;
	int Leadership = lpUser->Leadership + lpUser->AddLeadership;

	switch (lpUser->Class & 7)
	{
	case DarkLord:
	{
		gVisualFix.DamageRate = (Leadership / 10) + (Strength / 6) + (5 * Dexterity / 2) + (5 * lpUser->Level);
		break;
	}
	default:
	{
		gVisualFix.DamageRate = (Strength >> 2) + (3 * Dexterity / 2) + (5 * lpUser->Level);
		break;
	}
	}

	pUpdateUserStat(pUserStat(), &gVisualFix.DamageRate, 177);
	gVisualFix.DamageRate += pDamageRate;
	lpUser->DamageRate = (WORD)gVisualFix.DamageRate;
}

void cVisualFix::CalculateAttackSpeed(lpCharObj lpUser, LPVOID EDX)
{
	pGetAttackSpeed();

	switch (lpUser->Class)
	{
	case eObjClass::DarkKnight:
	case eObjClass::BladeKnight:
	case eObjClass::BladeMaster:
	{
		if (lpUser->Dexterity >= 28250)
		{
			gToolKit.SetFloat((PVOID)oFrameSpeed, 0.0040000f);
			gToolKit.SetFloat((PVOID)oFrameSpeed2, 0.0020000f);
		}

		break;
	}
	case eObjClass::MagicGladiator:
	case eObjClass::DuelMaster:
	{
		//if(gObjUser.GetActiveSkill() != 9 && gObjUser.GetActiveSkill() != 385 && gObjUser.GetActiveSkill() != 487)
		{
			if (lpUser->Dexterity >= 28250)
			{
				gToolKit.SetFloat((PVOID)oFrameSpeed, 0.0007000f);
			}
		}
	}
	break;
	}
}

int cVisualFix::GetAttackRate()
{
	return gVisualFix.AttackRate;
}

int cVisualFix::GetDamageRate()
{
	return gVisualFix.DamageRate;
}