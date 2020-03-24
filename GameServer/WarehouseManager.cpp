#include "StdAfx.h"
#include "WarehouseManager.h"
#include "user.h"
#include "GameMain.h"
#include "..\include\ReadScript.h"
#include "WarehouseProtocol.h"
#include "LogProc.h"
#include "DSProtocol.h"
#include "DBSockMng.h"

/*
cWareHouseManager gWareHouseManager;

void cWareHouseManager::Init()
{
	this->bEnabled = FALSE;
	this->bShoudLog = FALSE;
}

void cWareHouseManager::Load(LPSTR szFilePath)
{
	this->bEnabled = GetPrivateProfileInt("MultiVault", "Enabled", TRUE, WAREHOUSE_FILE);
	this->bShoudLog = GetPrivateProfileInt("MultiVault", "Log", TRUE, WAREHOUSE_FILE);

	Log(LOG_LEVEL_INFO, "[WarehouseManager] Configuration loaded: System %s", this->bEnabled ? "Enabled" : "Disabled");
}

void cWareHouseManager::Connect(LPOBJ lpObj)
{
	MSG_REQ_DS_WAREHOUSE_INFO pMsg = {};
	pMsg.h.set((LPBYTE)&pMsg, eMSG_HEADER_WAREHOUSE, eMSG_DS_WAREHOUSE_INFO, sizeof(MSG_REQ_DS_WAREHOUSE_INFO));

	pMsg.dwIndex = lpObj->m_Index;
	memcpy(pMsg.szAccountID, lpObj->AccountID, sizeof(pMsg.szAccountID));

	cDBSMng.Send((LPSTR)&pMsg, pMsg.h.size);
}

void cWareHouseManager::DGAnsWareHouseInfo(LPMSG_ANS_DS_WAREHOUSE_INFO aRecv)
{
	if (OBJMAX_RANGE(aRecv->dwIndex) == FALSE)
	{
		return;
	}

	if (!gObjIsConnected(aRecv->dwIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aRecv->dwIndex];

	if (aRecv->iExpandCount > 0)
	{
		lpObj->m_iWarehouseExpandCount = aRecv->iExpandCount;
	}

	if (aRecv->iCurrentWarehouseId > 0)
	{
		lpObj->m_iCurrentWarehouseId = aRecv->iCurrentWarehouseId;
	}

	lpObj->m_iCurrentWarehouseId = 0;
	lpObj->m_iWarehouseExpandCount = 10; // teen vaults by test

	if (this->bShoudLog == TRUE) 
	{
		Log(LOG_LEVEL_INFO, "[WarehouseManager] Account status: %d expansions, current warehouse id %d.", lpObj->m_iWarehouseExpandCount - 1, lpObj->m_iCurrentWarehouseId);
	}
}

BOOL cWareHouseManager::Change(LPOBJ lpObj, WORD Id, BOOL AutoOpen)
{
	if (this->bEnabled == FALSE)
	{
		MsgOutput(lpObj->m_Index, lMsg.Get(5169));
		return FALSE;
	}

	if (lpObj->m_iWarehouseExpandCount < 2)
	{
		MsgOutput(lpObj->m_Index, lMsg.Get(5166));
		return FALSE;
	}
	else if (Id > lpObj->m_iWarehouseExpandCount)
	{
		MsgOutput(lpObj->m_Index, lMsg.Get(5167), lpObj->m_iWarehouseExpandCount);
		return FALSE;
	}

	if (lpObj->m_iCurrentWarehouseId == Id)
	{
		MsgOutput(lpObj->m_Index, lMsg.Get(5206), Id);

		if (this->bShoudLog == TRUE)
		{
			Log(LOG_LEVEL_INFO, "[WarehouseManager] Account %s already using warehouse id %d", lpObj->AccountID, Id);
		}

		return FALSE;
	}

	if (AutoOpen == TRUE)
	{
		CGWarehouseUseEnd(lpObj->m_Index);
	}

	MSG_REQ_DS_WAREHOUSE_CHANGE pMsg = {};
	pMsg.h.set((LPBYTE)&pMsg, eMSG_HEADER_WAREHOUSE, eMSG_DS_WAREHOUSE_CHANGE, sizeof(MSG_REQ_DS_WAREHOUSE_CHANGE));

	pMsg.dwIndex = lpObj->m_Index;
	memcpy(pMsg.szAccountID, lpObj->AccountID, sizeof(pMsg.szAccountID));
	pMsg.wId = Id;
	pMsg.bOpen = AutoOpen;

	cDBSMng.Send((LPSTR)&pMsg, pMsg.h.size);

	return TRUE;
}

void cWareHouseManager::DGAnsWarehouseChange(LPMSG_ANS_DS_WAREHOUSE_CHANGE aRecv)
{
	if (OBJMAX_RANGE(aRecv->dwIndex) == FALSE)
	{
		return;
	}

	if (!gObjIsConnected(aRecv->dwIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aRecv->dwIndex];

	lpObj->m_iCurrentWarehouseId = aRecv->wId;
	MsgOutput(lpObj->m_Index, lMsg.Get(5170), lpObj->m_iCurrentWarehouseId);

	if (aRecv->bOpen == TRUE)
	{
		lpObj->m_ReqWarehouseOpen = 1;
		lpObj->m_IfState.type = 6;
		lpObj->m_IfState.use = 1;
		lpObj->m_IfState.state = 0;
		lpObj->WarehouseSave = TRUE;
		lpObj->WarehouseCount = 0;
		lpObj->m_ShopTime = 0;
		lpObj->TargetShopNumber = -1; // No :D let me check it is corect here

		GDGetWarehouseList(lpObj->m_Index, lpObj->AccountID);
	}

	Log(LOG_LEVEL_INFO, "[WarehouseManager] %s account changed warehouse id to %d.", lpObj->AccountID, lpObj->m_iCurrentWarehouseId);
}

void cWareHouseManager::SaveExpansionCount(LPOBJ lpObj)
{
	MSG_REQ_DS_WAREHOUSE_INFO_SAVE pMsg = {};
	pMsg.h.set((LPBYTE)&pMsg, eMSG_HEADER_WAREHOUSE, eMSG_DS_WAREHOUSE_INFO_SAVE, sizeof(MSG_REQ_DS_WAREHOUSE_INFO_SAVE));

	memcpy(pMsg.szAccountID, lpObj->AccountID, sizeof(pMsg.szAccountID));
	pMsg.wId = lpObj->m_iWarehouseExpandCount;

	cDBSMng.Send((LPSTR)&pMsg, pMsg.h.size);
}

void cWareHouseManager::WarehouseChangeRequest(LPMSG_REQ_GS_WAREHOUSE_CHANGE aRecv, int aIndex)
{
	if (OBJMAX_RANGE(aIndex) == FALSE)
	{
		return;
	}

	if (!gObjIsConnected(aIndex))
	{
		return;
	}

	LPOBJ lpObj = &gObj[aIndex];

	if (this->bEnabled == FALSE)
	{
		MsgOutput(lpObj->m_Index, "[MultiVault] System disabled.");
		return;
	}

	int NewId = 1;

	if (aRecv->iNext > 0)
	{
		if ((lpObj->m_iCurrentWarehouseId + 1) > lpObj->m_iWarehouseExpandCount)
		{
			NewId = 1;
		}
		else
		{
			NewId = lpObj->m_iCurrentWarehouseId + 1;
		}

		this->Change(lpObj, NewId, TRUE);
	}
	else if (aRecv->iPrevious > 0)
	{
		if ((lpObj->m_iCurrentWarehouseId - 1) < 1)
		{
			NewId = lpObj->m_iWarehouseExpandCount;
		}
		else
		{
			NewId = lpObj->m_iCurrentWarehouseId - 1;
		}

		this->Change(lpObj, NewId, TRUE);
	}
	else
	{
		if (this->bShoudLog == TRUE)
		{
			Log(LOG_LEVEL_WARNING, "[WarehouseManager] Error-L1: Button action not detected for user index %d.");
		}
	}
}
*/