#include "StdAfx.h"
#include "GameMain.h"
#include "Configs.h"

CConfigs g_Configs;

void CConfigs::LoadConfigs()
{
	WIN32_FIND_DATAA wFileData;
	// ----
	if(FindFirstFileA(CONFIG_FILE,&wFileData)==INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"Configs.ini file not found","Error",MB_OK);
		ExitProcess(0);
	}
	else if(FindFirstFileA(JEWELS_FILE,&wFileData)==INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"Jewels.ini file not found","Error",MB_OK);
		ExitProcess(0);
	}
	else if(FindFirstFileA(COMMANDS_FILE,&wFileData)==INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"Commands.ini file not found","Error",MB_OK);
		ExitProcess(0);
	}
	/*else if(FindFirstFileA(WAREHOUSE_FILE,&wFileData) == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"WareHouse.ini file not found","Error",MB_OK);
		ExitProcess(0);
	}*/
	/*else if(FindFirstFileA(RESETSYSTEM_FILE,&wFileData) == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"ResetSystem.ini file not found","Error",MB_OK);
		ExitProcess(0);
	}*/
	else if(FindFirstFileA(BALANCESYSTEM_FILE,&wFileData) == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"BalanceSystem.ini file not found","Error",MB_OK);
		ExitProcess(0);
	}
	else if(FindFirstFileA(NEWSSYSTEM_FILE,&wFileData) == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"NewsSystem.ini file not found","Error",MB_OK);
		ExitProcess(0);
	}
	else if(FindFirstFileA(ELEMENTALGEMS_FILE,&wFileData) == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"ElementalGems.ini file not found","Error",MB_OK);
		ExitProcess(0);
	}
	else if(FindFirstFileA(CHARACTERS_FILE,&wFileData) == INVALID_HANDLE_VALUE)
	{
		MessageBoxA(0,"Character.ini file not found","Error",MB_OK);
		ExitProcess(0);
	}

	//Jewel of Life
	this->m_iLifeRate			= GetPrivateProfileInt("JewelOfLife","LifeRateWithoutLuck",50,JEWELS_FILE);

	//Jewel of Soul
	this->m_iSoulRate			= GetPrivateProfileInt("JewelOfSoul","SoulRateWithoutLuck",50,JEWELS_FILE);
	this->m_iSoulRateWithLuck	= GetPrivateProfileInt("JewelOfSoul","SoulRateWithLuck",75,JEWELS_FILE);

	//Post
	this->PostEnable			= GetPrivateProfileInt("Post","IsEnable",0,COMMANDS_FILE);
	this->PostLevel				= GetPrivateProfileInt("Post","IsLevel",0,COMMANDS_FILE);
	this->PostCost				= GetPrivateProfileInt("Post","IsCost",0,COMMANDS_FILE);
	this->PostColor				= GetPrivateProfileInt("Post","IsColor",0,COMMANDS_FILE);

	//Drop
	this->DropEnable			= GetPrivateProfileInt("Drop","IsEnable",0,COMMANDS_FILE);

	//Make
	this->MakeEnable			= GetPrivateProfileInt("Make","IsEnable",0,COMMANDS_FILE);

	//Clear
	this->ClearEnable			= GetPrivateProfileInt("Clear","IsEnable",0,COMMANDS_FILE);

	//Skin
	this->SkinEnable			= GetPrivateProfileInt("SetSkin","IsEnable",0,COMMANDS_FILE);

	//SetZen
	this->SetZenEnable			= GetPrivateProfileInt("SetZen","IsEnable",0,COMMANDS_FILE);

	//Add
	this->AddStatsEnable		= GetPrivateProfileInt("Add","IsEnable",0,COMMANDS_FILE);
	this->AddStatsLevel			= GetPrivateProfileInt("Add","IsLevel",0,COMMANDS_FILE);
	this->AddStatsCost			= GetPrivateProfileInt("Add","IsCost",0,COMMANDS_FILE);
	this->AddStatsMaxPoints		= GetPrivateProfileInt("Add","IsMaxPoints",0,COMMANDS_FILE);

	//Ware
	//this->MultiVaultEnable		= GetPrivateProfileInt("Ware","IsEnable",0,COMMANDS_FILE);
	//this->MultiVaultMax			= GetPrivateProfileInt("Ware","IsMaxWare",9,COMMANDS_FILE);
	//this->MultiVaultTime			= GetPrivateProfileInt("Ware","IsFloodTime",3,COMMANDS_FILE);

	//Pack
	this->PackLevelEnable		= GetPrivateProfileInt("PackLevel","IsEnable",0,COMMANDS_FILE);
	this->PackLevel20Enable		= GetPrivateProfileInt("PackLevel","Is20Enable",0,COMMANDS_FILE);
	// ----
	this->PackLuckEnable		= GetPrivateProfileInt("PackLuck","IsEnable",0,COMMANDS_FILE);
	this->PackSkillEnable		= GetPrivateProfileInt("PackSkill","IsEnable",0,COMMANDS_FILE);
	this->PackOptionEnable		= GetPrivateProfileInt("PackOption","IsEnable",0,COMMANDS_FILE);
	this->PackExcellentEnable	= GetPrivateProfileInt("PackExcellent","IsEnable",0,COMMANDS_FILE);
	this->PackAncientEnable		= GetPrivateProfileInt("PackAncient","IsEnable",0,COMMANDS_FILE);
	this->PackSocketEnable		= GetPrivateProfileInt("PackSocket","IsEnable",0,COMMANDS_FILE);

	//Unpack
	this->UnpackLevelEnable		= GetPrivateProfileInt("UnpackLevel","IsEnable",0,COMMANDS_FILE);
	this->UnpackLevel20Enable	= GetPrivateProfileInt("UnpackLevel","Is20Enable",0,COMMANDS_FILE);
	this->UnpackLuckEnable		= GetPrivateProfileInt("UnpackLuck","IsEnable",0,COMMANDS_FILE);
	this->UnpackSkillEnable		= GetPrivateProfileInt("UnpackSkill","IsEnable",0,COMMANDS_FILE);
	this->UnpackOptionEnable	= GetPrivateProfileInt("UnpackOption","IsEnable",0,COMMANDS_FILE);
	this->UnpackExcellentEnable	= GetPrivateProfileInt("UnpackExcellent","IsEnable",0,COMMANDS_FILE);
	this->UnpackAncientEnable	= GetPrivateProfileInt("UnpackAncient","IsEnable",0,COMMANDS_FILE);
	this->UnpackSocketEnable	= GetPrivateProfileInt("UnpackSocket","IsEnable",0,COMMANDS_FILE);

	//Character
	this->LevelUpPointsForDW	= GetPrivateProfileInt("CLASS_DW","LevelUpPoints",5,CHARACTERS_FILE);
	this->LevelUpPointsForDK	= GetPrivateProfileInt("CLASS_DK","LevelUpPoints",5,CHARACTERS_FILE);
	this->LevelUpPointsForFE	= GetPrivateProfileInt("CLASS_FE","LevelUpPoints",5,CHARACTERS_FILE);
	this->LevelUpPointsForMG	= GetPrivateProfileInt("CLASS_MG","LevelUpPoints",7,CHARACTERS_FILE);
	this->LevelUpPointsForDL	= GetPrivateProfileInt("CLASS_DL","LevelUpPoints",7,CHARACTERS_FILE);
	this->LevelUpPointsForSM	= GetPrivateProfileInt("CLASS_SM","LevelUpPoints",5,CHARACTERS_FILE);
}