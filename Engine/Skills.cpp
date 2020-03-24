#include "StdAfx.h"

cSkills gSkills;

cSkills::cSkills()
{
	this->iIsSiegeSkill = 0;
}

cSkills::~cSkills()
{
	/**/
}

void cSkills::Init()
{
	// -> Castle Siege Skills (in All Maps)
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed01+1),0x2B);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed02+1),0x26);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed03+1),0x21);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed04+1),0x1C);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed05+1),0x17);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed06+2),0x00);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed07+2),0x00);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed08+2),0x00);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed09+2),0x00);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed10+2),0x00);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed11+2),0x00);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed12+1),0x33);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed13+1),0x2E);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed14+1),0x29);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed15+1),0x24);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed16+1),0x1F);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed17+1),0x33);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed18+1),0x2E);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed19+1),0x29);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed20+1),0x24);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed21+1),0x1F);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed22+3),0x01);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed23),0xEB);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed24),0xEB);
	gToolKit.SetByte((PVOID)(oSiegeSkillsAllowed25),0xEB);
}

void cSkills::Load()
{
	if(gScriptEncode.ReadScript(SIEGE_FILE))
	{
		WZSMDToken Token = gScriptEncode.GetToken();
		// ----
		Token = gScriptEncode.GetToken();
		this->iIsSiegeSkill = gScriptEncode.GetNumber();
		// ----
		if(this->iIsSiegeSkill == 1)
		{
			this->Init();
		}
		// ----
		gScriptEncode.Close();
	}
	else
	{
		MessageBox(NULL,"SiegeSkill.bmd file not found","Error",MB_OK);
		::ExitProcess(0);
	}
}