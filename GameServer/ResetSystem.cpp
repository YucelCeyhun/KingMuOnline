#include "StdAfx.h"
#include "ResetSystem.h"
#include "user.h"
#include "GameMain.h"
#include "..\include\ReadScript.h"
#include "ResetProtocol.h"
#include "LogProc.h"
#include "DSProtocol.h"
#include "DBSockMng.h"

/*
cResetSystem gResetSystem;

cResetSystem::cResetSystem()	// -> Constructor
{
	this->Init();
}

cResetSystem::~cResetSystem()	// -> Destructor
{
}

void cResetSystem::Init()
{
	this->bEnabled = true;
}

void cResetSystem::Load()
{
	this->Init();
	this->ReadConfigs(gDirPath.GetNewPath(RESETSYSTEM_FILE));
}

void cResetSystem::ReadConfigs(char *File)
{
	this->bEnabled = GetPrivateProfileInt("ResetSystem","Enabled",true,File);
	LogAddTD("[ResetSystem] System Configs Setted!");
}

void cResetSystem::SendResetData(LPOBJ lpUser)
{
	if(bEnabled = true)
	{
		RESET_ANS_USERDATA pSend;
		pSend.h.set((LPBYTE)&pSend,ResetProtocol::Case,ResetProtocol::UserData,sizeof(pSend));
		// ----
		pSend.Reset = lpUser->Reset;
		pSend.GrandReset = lpUser->GrandReset;
		// ----
		DataSend(lpUser->m_Index, (LPBYTE)&pSend, pSend.h.size);
	}
}
*/