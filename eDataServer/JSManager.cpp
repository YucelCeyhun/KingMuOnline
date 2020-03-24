#include "StdAfx.h"
#include "JSManager.h"
#include "Structs.h"
#include "Defines.h"
#include "LogProc.h"

LPJOIN_SERVERDATA	m_ServObj[MAX_OBJECT];
LPJOIN_SERVERUSER	m_UserObj[MAX_USER];

cJSManager gJSManager;

void JOIN_SERVERDATA::Clear()
{
	memset(m_szServerName,0,sizeof(m_szServerName));
	// ----
	m_Index					= SLOT_FREE;
	m_ServerCode			= SLOT_FREE;
	m_Port					= SLOT_FREE;
	m_ConnectedCount		= 0;
	m_MaxUser				= 0;
}

void JOIN_SERVERUSER::Clear()
{
	memset(m_szAccountID,0,sizeof(m_szAccountID));
	// ----
	m_ServerIndex			= SLOT_FREE;
	m_ServerCode			= SLOT_FREE;
	iUserNumber				= SLOT_FREE;
	nNumber					= 0;
	BillCheckTimer			= 0;
	BillCheckSendTimer		= 0;
	m_bRequestMapSvrMove	= false;
}

bool cJSManager::IsCodeExist(int ServerCode)
{
	this->bReturn = false;
	// ----
	for(int i = 0; i != MAX_OBJECT; i++)
	{
		LPJOIN_SERVERDATA lpServ = &m_ServObj[i];
		// ----
		if(lpServ->m_ServerCode == ServerCode)
		{
			this->bReturn = true;
			// ----
			break;
		}
	}
	// ----
	return this->bReturn;
}

bool cJSManager::AddServer(int ServerIndex,int ServerCode,char*szServerName,int Port)
{
	this->bReturn = false;
	// ----
	LogAddTD("[JoinServerManager][AddServer] Index(%d) Code(%d) Name(%s)",ServerIndex,ServerCode,szServerName);
	// ----
	if(IsCodeExist(ServerCode) == false)
	{
		LPJOIN_SERVERDATA lpServ = &m_ServObj[ServerIndex];
		// ----
		memcpy(lpServ->m_szServerName,szServerName,sizeof(lpServ->m_szServerName));
		// ----
		lpServ->m_Port			= Port;
		lpServ->m_ServerCode	= ServerCode;
		lpServ->m_Index			= ServerIndex;
		// ----
		m_ServerLoggedCount++;
		// ----
		this->bReturn = true;
	}
	else
	{
		LogAddTD("[JoinServerManager][AddServer] GS(%s) trying to connect with a ServerCode(%d) already used",szServerName,ServerCode);
	}
	// ----
	return this->bReturn;
}