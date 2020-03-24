// CharServer.cpp: implementation of the ChatServer class.
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "ChatServer.h"
#include "GuildServer.h"

queue<LPREQUEST_CMD> g_FriendQueue;
CRITICAL_SECTION g_csFriend;

queue<LPREQUEST_CMD> g_MailQueue;
CRITICAL_SECTION g_csMail;

BOOL g_bExit = FALSE;
HANDLE hFriendThread, hMailThread;


int g_iMaxFriends = 50;

#pragma pack(1)

typedef struct _NAME
{
	char m_szName[11];
	_NAME()
	{
		ZeroMemory(this, sizeof(*this));
	}
	_NAME(char *szName)
	{
		ZeroMemory(this, sizeof(*this));
		strncpy(m_szName, szName, 10);
	}
}NAME, LPNAME;

typedef struct _FRIEND_MASTER
{
	int m_iGUID;
	int m_iMemoTotal;
	int m_iNumber;
	BYTE m_btState;
	int m_iServer;
	vector<NAME> m_vecFriends;

	_FRIEND_MASTER()
	{
		m_iGUID = -1;
		m_iMemoTotal = 0;
		m_iNumber = -1;
		m_btState = -1;
		m_iServer = -1;
		m_vecFriends.clear();
	}
}FRIEND_MASTER, *LPFRIEND_MASTER;
typedef map<string, FRIEND_MASTER, strCmp> MAP_FRIEND_MASTER;

CRITICAL_SECTION g_csMapFriendMaster;

MAP_FRIEND_MASTER g_mapFriendManager;

#pragma pack()


BOOL CreateFriendMaster(char *szMaster);
BOOL DeleteFriendMaster(char *szMaster);


// use only for FriendProtocolCore
LPFRIEND_MASTER GetFriendMaster(char *szMaster)
{
	if(szMaster == NULL)
		return NULL;

	if(strlen(szMaster) < 4)
		return NULL;

	MAP_FRIEND_MASTER::iterator it;
	it = g_mapFriendManager.find(szMaster);
	if(it == g_mapFriendManager.end())
		return NULL;

	return &it->second;
}

BOOL FriendExists(char *szMaster, char *szFriend)
{
	LPFRIEND_MASTER lpMaster;

	EnterCriticalSection(&g_csMapFriendMaster);
	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
	{
		LeaveCriticalSection(&g_csMapFriendMaster);
		return FALSE;
	}

	int size = lpMaster->m_vecFriends.size();
	int i = 0;

	for(i=0; i < size; i++)
	{
		if(strcmp(lpMaster->m_vecFriends[i].m_szName, szFriend) == 0)
			break;
	}

	LeaveCriticalSection(&g_csMapFriendMaster);
	if(i == size)
		return FALSE;
	else
		return TRUE;
}


BOOL CreateFriendMaster(char *szMaster, int iNumber, int iServer)
{
	LPFRIEND_MASTER lpM;
	lpM = GetFriendMaster(szMaster);
	if(lpM)
	{
		lpM->m_iNumber = iNumber;
		lpM->m_iServer = iServer;
		lpM->m_btState = iServer;
		return TRUE;
	}

	FRIEND_MASTER Master;
	Master.m_iNumber = iNumber;
	Master.m_iServer = iServer;
	Master.m_btState = iServer;

	EnterCriticalSection(&g_csMapFriendMaster);
	g_mapFriendManager[szMaster] = Master;
	LeaveCriticalSection(&g_csMapFriendMaster);

	return TRUE;
}

BOOL DeleteFriendMaster(char *szMaster)
{
	MAP_FRIEND_MASTER::iterator it;

	EnterCriticalSection(&g_csMapFriendMaster);
	it = g_mapFriendManager.find(szMaster);
	if(it == g_mapFriendManager.end())
	{
		LeaveCriticalSection(&g_csMapFriendMaster);
		return FALSE;
	}

	g_mapFriendManager.erase(it);
	LeaveCriticalSection(&g_csMapFriendMaster);

	return TRUE;

}

int GetFriendGuid(char *szMaster)
{
	int guid = -1;
	LPFRIEND_MASTER lpMaster;
	EnterCriticalSection(&g_csMapFriendMaster);

	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster)
		guid = lpMaster->m_iGUID;
	LeaveCriticalSection(&g_csMapFriendMaster);

	return guid;
}

BYTE GetFriendState(char *szMaster)
{
	BYTE btState = -1;
	LPFRIEND_MASTER lpMaster;

	EnterCriticalSection(&g_csMapFriendMaster);

	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster)
		btState = lpMaster->m_btState;
	LeaveCriticalSection(&g_csMapFriendMaster);

	return btState;
}

int GetFriendServer(char *szMaster)
{
	int iServer = -1;
	LPFRIEND_MASTER lpMaster;

	EnterCriticalSection(&g_csMapFriendMaster);

	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster)
		iServer = lpMaster->m_iServer;
	LeaveCriticalSection(&g_csMapFriendMaster);

	return iServer;
}

int GetFriendNumber(char *szMaster)
{
	int iNumber = -1;
	LPFRIEND_MASTER lpMaster;

	EnterCriticalSection(&g_csMapFriendMaster);

	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster)
		iNumber = lpMaster->m_iNumber;
	LeaveCriticalSection(&g_csMapFriendMaster);

	return iNumber;
}


BOOL AddReqToFriendQueue(int aIndex, LPBYTE lpReq)
{
	if(g_bExit)
		return FALSE;

	if(lpReq == NULL)
		return FALSE;

	LPREQUEST_CMD lpCMD;

	lpCMD = new REQUEST_CMD;
	if(lpCMD == NULL)
	{
		LogAddC(2, "Memory Allocation Error!");
		return FALSE;
	}

	int size;
	if(((PMSG_DEFAULT *)lpReq)->h.c == 0xC1)
		size = ((PMSG_DEFAULT *)lpReq)->h.size;
	else
		size = MAKE_NUMBERW(((PWMSG_HEAD *)lpReq)->sizeL, ((PWMSG_HEAD *)lpReq)->sizeH);

	memcpy(lpCMD->m_btData, lpReq, size);
	lpCMD->m_aIndex = aIndex;

	EnterCriticalSection(&g_csFriend);

	g_FriendQueue.push(lpCMD);

	LeaveCriticalSection(&g_csFriend);

	return TRUE;
}

LPREQUEST_CMD GetFriendReq()
{
	LPREQUEST_CMD lpCmd = NULL;
	EnterCriticalSection(&g_csFriend);

	if(!g_FriendQueue.empty())
	{
		lpCmd = g_FriendQueue.front();
		g_FriendQueue.pop();
	}

	LeaveCriticalSection(&g_csFriend);

	return lpCmd;
}

void ClearFriendQueue()
{
	LPREQUEST_CMD lpCmd = NULL;
	EnterCriticalSection(&g_csFriend);

	while(!g_FriendQueue.empty())
	{
		lpCmd = g_FriendQueue.front();
		g_FriendQueue.pop();
		if(lpCmd)
			delete [] lpCmd;
	}

	LeaveCriticalSection(&g_csFriend);
}

BOOL AddReqToMailQueue(int aIndex, LPBYTE lpReq)
{
	if(g_bExit)
		return FALSE;

	if(lpReq == NULL)
		return FALSE;

	LPREQUEST_CMD lpCMD;

	lpCMD = new REQUEST_CMD;
	if(lpCMD == NULL)
	{
		LogAddC(2, "Memory Allocation Error!");
		return FALSE;
	}

	int size;
	if(((PMSG_DEFAULT *)lpReq)->h.c == 0xC1)
		size = ((PMSG_DEFAULT *)lpReq)->h.size;
	else
		size = MAKEWORD(((PWMSG_HEAD *)lpReq)->sizeL, ((PWMSG_HEAD *)lpReq)->sizeH);

	memcpy(lpCMD->m_btData, lpReq, size);
	lpCMD->m_aIndex = aIndex;


	EnterCriticalSection(&g_csMail);

	g_MailQueue.push(lpCMD);

	LeaveCriticalSection(&g_csMail);

	return TRUE;
}

LPREQUEST_CMD GetMailReq()
{
	LPREQUEST_CMD lpCmd = NULL;
	EnterCriticalSection(&g_csMail);

	if(!g_MailQueue.empty())
	{
		lpCmd = g_MailQueue.front();
		g_MailQueue.pop();
	}

	LeaveCriticalSection(&g_csMail);

	return lpCmd;
}

void ClearMailQueue()
{
	LPREQUEST_CMD lpCmd = NULL;

	EnterCriticalSection(&g_csMail);

	while(!g_MailQueue.empty())
	{
		lpCmd = g_MailQueue.front();
		g_MailQueue.pop();
		if(lpCmd)
			delete [] lpCmd;
	}

	LeaveCriticalSection(&g_csMail);
}

BOOL InitFriendServer()
{
	InitializeCriticalSection(&g_csMapFriendMaster);
	InitializeCriticalSection(&g_csFriend);
	InitializeCriticalSection(&g_csMail);

	DWORD threadID;
	hFriendThread = CreateThread(NULL, 0, &FriendProtocolCore, NULL, 0, &threadID );
	hMailThread = CreateThread(NULL, 0, &MailProtocolCore, NULL, 0, &threadID );
	return TRUE;
}

void CloseFriendServer()
{

	g_bExit = TRUE;

	ClearFriendQueue();
	ClearMailQueue();

	if(WaitForSingleObject(hFriendThread, 200) == WAIT_TIMEOUT)
		TerminateThread(hFriendThread, 0);

	if(WaitForSingleObject(hMailThread, 200) == WAIT_TIMEOUT)
		TerminateThread(hMailThread, 0);


	DeleteCriticalSection(&g_csMail);
	DeleteCriticalSection(&g_csFriend);
	DeleteCriticalSection(&g_csMapFriendMaster);
}

DWORD __stdcall FriendProtocolCore(void *pArg)
{

	LPREQUEST_CMD lpCmd;
	do
	{
		lpCmd = (LPREQUEST_CMD)GetFriendReq();
		if(lpCmd)
		{
			BYTE headcode;
			if(((PMSG_DEFAULT *)&lpCmd->m_btData)->h.c == 0xC1)
				headcode = ((PMSG_DEFAULT *)&lpCmd->m_btData)->h.headcode;
			else
				headcode = ((PWMSG_HEAD *)&lpCmd->m_btData)->headcode;

			switch( headcode )
			{
			case 0x02:
				DGFriendOfflineSend(lpCmd->m_aIndex, (LPBYTE)&lpCmd->m_btData);
				break;
			case 0x60:
				GDFrinedListReq( lpCmd->m_aIndex, (FHP_FRIENDLIST_REQ*)&lpCmd->m_btData);
				break;
			case 0x62:
				GDFriendStateChange( lpCmd->m_aIndex, (FHP_FRIEND_STATE_C*)&lpCmd->m_btData);
				break;
			case 0x63:
				GDFriendAddReq( lpCmd->m_aIndex, (FHP_FRIEND_ADD_REQ*)&lpCmd->m_btData);
				break;
			case 0x64:
				GDWaitFriendAddReq( lpCmd->m_aIndex, (FHP_WAITFRIEND_ADD_REQ*)&lpCmd->m_btData);
				break;
			case 0x65:
				GDFriendDelReq( lpCmd->m_aIndex, (FHP_FRIEND_ADD_REQ*)&lpCmd->m_btData);
				break;
			}
			delete [] lpCmd;
		}
		Sleep(1);
	}
	while(g_bExit != TRUE);
	return 0;
}

DWORD __stdcall MailProtocolCore(void *pArg)
{
	LPREQUEST_CMD lpCmd;
	do
	{
		lpCmd = (LPREQUEST_CMD)GetMailReq();
		if(lpCmd)
		{
			BYTE headcode;
			if(((PMSG_DEFAULT *)&lpCmd->m_btData)->h.c == 0xC1)
				headcode = ((PMSG_DEFAULT *)&lpCmd->m_btData)->h.headcode;
			else
				headcode = ((PWMSG_HEAD *)&lpCmd->m_btData)->headcode;

			switch( headcode )
			{

			case 0x70:
				FriendMemoSend( lpCmd->m_aIndex, (FHP_FRIEND_MEMO_SEND*)&lpCmd->m_btData);
				break;

			case 0x71:
				FriendMemoListReq( lpCmd->m_aIndex, (FHP_FRIEND_MEMO_LIST_REQ*)&lpCmd->m_btData);
				break;

			case 0x72:
				FriendMemoReadReq( lpCmd->m_aIndex, (FHP_FRIEND_MEMO_RECV_REQ*)&lpCmd->m_btData);
				break;

			case 0x73:
				FriendMemoDelReq( lpCmd->m_aIndex, (FHP_FRIEND_MEMO_DEL_REQ*)&lpCmd->m_btData);
				break;
			}

			delete [] lpCmd;
		}


		Sleep(1);

	}while(g_bExit != TRUE);

	return 0;
}


int ExDBGetIndexByCode(int iServerCode)
{
	if(iServerCode < 0)
		return -1;

	for(int i=0; i < MAX_SERVEROBJECT; i++)
	{
		if(g_Server[i].m_Index != -1
			&& g_Server[i].m_Type == ST_EXDATASERVER
			&& g_Server[i].m_State == SS_GUILD
			&& g_Server[i].m_ServerCode == iServerCode)
		{
			return i;
		}
	}

	return -1;
}

void DGFriendOfflineSend(int aIndex, LPBYTE lpMsg)
{
	char szMaster[11] = {0};

	strncpy(szMaster, ((SDHP_USERCLOSE *)lpMsg)->CharName, 10);

	LPFRIEND_MASTER lpMaster;
	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
		return;

	lpMaster->m_btState = -1;
	SendStateToAllFriends(aIndex, szMaster);
	DeleteFriendMaster(szMaster);
}

BOOL UserGuidDBCreate(char *szName)
{

	BOOL res = g_ExDB.ExecQuery("WZ_UserGuidCreate '%s'", szName);
	g_ExDB.Close();

	return res;
}

BOOL GetDBGuidAndMemoTotal(char *szName, int& guid, int& memo_total)
{
	BOOL res = FALSE;
	if(g_ExDB.ExecQuery("SELECT GUID, MemoTotal FROM T_FriendMain where Name = '%s'", szName))
	{
		if(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			guid = g_ExDB.GetAsInteger("GUID");
			memo_total = g_ExDB.GetAsInteger("MemoTotal");
			res = TRUE;
		}
	}

	g_ExDB.Close();

	return res;
}

BOOL GetDBFriendList(char *szMaster)
{
	LPFRIEND_MASTER lpMaster;

	BOOL res = TRUE;
	lpMaster = GetFriendMaster(szMaster);
	if(szMaster == NULL)
		return FALSE;

	if(GetDBGuidAndMemoTotal(szMaster, lpMaster->m_iGUID, lpMaster->m_iMemoTotal) == FALSE)
	{
		res = FALSE;
		if(UserGuidDBCreate(szMaster))
		{
			res = GetDBGuidAndMemoTotal(szMaster, lpMaster->m_iGUID, lpMaster->m_iMemoTotal);
		}
	}

	if(res == FALSE)
		return FALSE;

	res = FALSE;
	int i=0;
	char szFriend[11] = {0};

	if(g_ExDB.ExecQuery("SELECT FriendGuid, FriendName, Del FROM T_FriendList where GUID = %d", lpMaster->m_iGUID))
	{
		while(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			if(i == g_iMaxFriends)
			{
				LogAddC(2, "DB contains more then %d friends for [%s] character", g_iMaxFriends, szMaster);
				break;
			}

			g_ExDB.GetAsString("FriendName", szFriend, 10);
			if(FriendExists(szMaster, szFriend) == FALSE)
			{
				lpMaster->m_vecFriends.push_back(szFriend);
				i++;
			}
		}
	}

	g_ExDB.Close();

	return res;
}

void FriendListSend(int aIndex, char *szMaster)
{
	LPFRIEND_MASTER lpMaster;

	LogAddTD("[Friend List Send] Name[%s].", szMaster);
	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
	{
		LogAddTD("[Friend List Send] FrienMaster[%s] not found.", szMaster);
		return;
	}

	FHP_FRIENDLIST_COUNT* lpFriendListCnt;
	FHP_FRIENDLIST* lpFriendList;

	int cnt = lpMaster->m_vecFriends.size();
	int size = sizeof(*lpFriendListCnt)+sizeof(*lpFriendList)*cnt;
	LPBYTE lpData = new BYTE[size];
	ZeroMemory(lpData, size);

	lpFriendListCnt = (FHP_FRIENDLIST_COUNT*)lpData;
	lpFriendList = (FHP_FRIENDLIST*)(lpData+sizeof(*lpFriendListCnt));
	PHeadSetW(lpData, 0x60, size);
	lpFriendListCnt->Count = cnt;
	lpFriendListCnt->MailCount = lpMaster->m_iMemoTotal;
	lpFriendListCnt->Number = lpMaster->m_iNumber;
	strncpy(lpFriendListCnt->Name, szMaster, 10);

	LogAddTD("[Friend List Send] Friend Count[%d].", cnt);
	for(int i=0; i < cnt; i++)
	{
		LPFRIEND_MASTER lpFr;
		int iServ = -1;
		lpFr = GetFriendMaster(lpMaster->m_vecFriends[i].m_szName);
		if(lpFr)
		{
			// check if friendship is established
			if(FriendExists(lpMaster->m_vecFriends[i].m_szName, szMaster))
				iServ = lpFr->m_btState;
		}

		lpFriendList[i].Server = iServ;
		strncpy(lpFriendList[i].Name, lpMaster->m_vecFriends[i].m_szName, 10);

		char szFriend[11] = {0};
		strncpy(szFriend, lpFriendList[i].Name, 10);
		LogAddTD("[Friend List Send] Friend[%s] send.", szFriend);
	}

	DataSend(aIndex, lpData, size);

	delete [] lpData;
}

BOOL GetDBWaitFriend(char *szMaster, OUT char *szWaitFriend)
{
	LPFRIEND_MASTER lpMaster;
	lpMaster = GetFriendMaster(szMaster);

	if(lpMaster == NULL)
		return FALSE;

	BOOL res = FALSE;
	if(g_ExDB.ExecQuery("SELECT FriendName FROM T_WaitFriend where GUID=%d", lpMaster->m_iGUID))
	{
		if(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			g_ExDB.GetAsString("FriendName", szWaitFriend, 10);
			res = TRUE;
		}
	}

	g_ExDB.Close();

	return res;
}

BOOL FriendWaitSend(int aIndex, char *szMaster)
{
	FHP_WAITFRIENDLIST_COUNT WaitFr;
	ZeroMemory(&WaitFr, sizeof(WaitFr));
	PHeadSetB((LPBYTE)&WaitFr, 0x61, sizeof(WaitFr));


	char szWaitFriend[11] = {0};

	LPFRIEND_MASTER lpMaster;
	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
		return FALSE;

	if(GetDBWaitFriend(szMaster, szWaitFriend) == FALSE)
		return FALSE;

	strncpy(WaitFr.FriendName, szWaitFriend, 10);
	strncpy(WaitFr.Name, szMaster, 10);
	WaitFr.Number = lpMaster->m_iNumber;

	DataSend(aIndex, (LPBYTE)&WaitFr, WaitFr.h.size);

	return TRUE;
}


void SendState(int aIndex, char *szMaster, int iNumber, char *szName, BYTE btState)
{
	FHP_FRIEND_STATE State;
	ZeroMemory(&State, sizeof(State));

	PHeadSetB((LPBYTE)&State, 0x62, sizeof(State));

	strncpy(State.Name, szMaster, 10);
	strncpy(State.FriendName, szName, 10);
	State.Number = iNumber;
	State.State = btState;

	DataSend(aIndex, (LPBYTE)&State, State.h.size);
}

void SendStateToAllFriends(int aIndex, char *szMaster)
{
	LPFRIEND_MASTER lpMaster;
	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
		return;

	int cnt = lpMaster->m_vecFriends.size();

	for(int i=0; i < cnt; i++)
	{
		LPFRIEND_MASTER lpFr;
		lpFr = GetFriendMaster(lpMaster->m_vecFriends[i].m_szName);
		if(lpFr)
		{
			// check if friendship is established
			if(FriendExists(lpMaster->m_vecFriends[i].m_szName, szMaster))
			{
				int index = ExDBGetIndexByCode(lpFr->m_iServer);
				if(index != -1)
				{
					SendState(index, 
						lpMaster->m_vecFriends[i].m_szName, 
						lpFr->m_iNumber, szMaster, lpMaster->m_btState);
				}
			}
		}
	}
}


void GDFrinedListReq(int aIndex, FHP_FRIENDLIST_REQ* lpMsg)
{

	char szMaster[11]={0};
	strncpy(szMaster, lpMsg->Name, 10);

	LogAddTD("[Friend List Request] Name[%s].", szMaster);
	if(CreateFriendMaster(szMaster, lpMsg->Number, lpMsg->pServer) == FALSE)
		return;


	GetDBFriendList(szMaster);
	FriendListSend(aIndex, szMaster);
	FriendWaitSend(aIndex, szMaster);
	SendStateToAllFriends(aIndex, szMaster);

	FHP_FRIEND_MEMO_LIST_REQ req;
	ZeroMemory(&req, sizeof(req));
	PHeadSetB((LPBYTE)&req, 0x71, sizeof(req));

	strncpy(req.Name, lpMsg->Name, 10);
	req.Number = lpMsg->Number;

	AddReqToMailQueue(aIndex, (LPBYTE)&req);
}


BOOL AddFriend(char *szMaster, char *szFriend)
{
	LPFRIEND_MASTER lpMaster;
	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
		return FALSE;

	if( lpMaster->m_vecFriends.size() == g_iMaxFriends)
	{
		LogAddC(0, "[%s]'s friend list is full - %d", szMaster, g_iMaxFriends);
		return FALSE;
	}

	lpMaster->m_vecFriends.push_back(szFriend);

	LogAddTD("[%s] became [%s]'s friend.", szFriend, szMaster);
	return TRUE;
}

int AddDBWaitFriend(char *szMaster, char *szFriend)
{
	int res = 1;
	if(g_ExDB.ExecQuery("EXEC WZ_WaitFriendAdd '%s', '%s'", szMaster, szFriend))
	{
		if(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			res = g_ExDB.GetResult(0);
			if(res != 0)
			{
				if(res == 6)
					LogAddTD("[%s]'s level is too low.", szFriend);
				else if(res == 3)
					LogAddTD("GUID for [%s] doesn't exists.", szFriend);
				else if(res != 8)
					LogAddC(2, "WZ_WaitFriendAdd returned: %d", res);
			}
		}
		else
			LogAddC(2, "WZ_WaitFriendAdd no result returned.");
	}
	else
		LogAddC(2, "Error executing WZ_WaitFriendAdd.");

	g_ExDB.Close();

	return res;
}


void GDFriendAddReq( int aIndex, FHP_FRIEND_ADD_REQ* lpMsg)
{
	FHP_FRIEND_ADD_RESULT Result;
	ZeroMemory(&Result, sizeof(Result));
	PHeadSetB((LPBYTE)&Result, 0x63, sizeof(Result));

	strncpy(Result.Name, lpMsg->Name, 10);
	strncpy(Result.FriendName, lpMsg->FriendName, 10);
	Result.Result = 2;
	Result.Server = -1;
	Result.Number = lpMsg->Number;

	char szMaster[11] = {0};
	char szFriend[11] = {0};
	strncpy(szMaster, Result.Name, 10);
	strncpy(szFriend, Result.FriendName, 10);

	LogAddTD("[Friend Add Request] Name[%s] FriendName[%s].", szMaster, szFriend);

	if(strcmp(szMaster, szFriend) == 0)
	{
		// own id
		Result.Result = 5;

		LogAddTD("[Friend Add Request] Send Result [%d].", Result.Result);
		DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
		return;
	}

	LPFRIEND_MASTER lpMaster;
	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
	{
		LogAddTD("[Friend Add Request] Send Result [%d].", Result.Result);
		DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
		return;
	}

	if(FriendExists(szMaster, szFriend))
	{
		Result.Result = 4;

		LogAddTD("[Friend Add Request] Send Result [%d].", Result.Result);
		DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
		return;
	}

	if(lpMaster->m_vecFriends.size() == g_iMaxFriends)
	{
		Result.Result = 3;

		LogAddTD("[Friend Add Request] Send Result [%d].", Result.Result);
		DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
		return;
	}

	int res = AddDBWaitFriend(szMaster, szFriend);

	// DB result, GUID doesn't exists, or select error
	if(res > 1 && res < 6)
	{
		Result.Result = 0;

		LogAddTD("[Friend Add Request] Send Result [%d].", Result.Result);
		DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
		return;
	}

	// DB result, lvl< 6
	if(res == 6)
	{
		Result.Result = 6;
		LogAddTD("[Friend Add Request] Send Result [%d].", Result.Result);
		DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
		return;
	}

	// DB, other errors
	if(res != 0 && res != 8)
	{
		Result.Result = 2;
		LogAddTD("[Friend Add Request] Send Result [%d].", Result.Result);
		DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
		return;
	}


	LPFRIEND_MASTER lpFr;
	lpFr = GetFriendMaster(szFriend);

	Result.Server = -1;
	BYTE btState = 0;
	if(lpFr)
	{
		// check if friendship is established
		if(FriendExists(szFriend, szMaster))
		{
			Result.Server = lpFr->m_btState;
			SendState(aIndex, szFriend, lpFr->m_iNumber, szMaster, lpMaster->m_btState);
		}

		int index = ExDBGetIndexByCode(lpFr->m_iServer);
		if(index != -1)
			FriendWaitSend(aIndex, szFriend);
	}



	AddFriend(szMaster, szFriend);

	Result.Result = 1;

	LogAddTD("[Friend Add Request] Send Result [%d].", Result.Result);
	DataSend(aIndex, (LPBYTE)&Result, Result.h.size);

}


int DelDBWaitFriend(char *szMaster, char *szFriend)
{
	int res = 1;

	if(g_ExDB.ExecQuery("EXEC WZ_WaitFriendDel '%s', '%s'", szMaster, szFriend))
	{
		if(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			res = g_ExDB.GetResult(0);
			if(res != 0)
				LogAddC(2, "WZ_WaitFriendDel returned: %d", res);
		}
		else
			LogAddC(2, "WZ_WaitFriendDel no result returned.");
	}
	else
		LogAddC(2, "Error executing WZ_WaitFriendDel.");

	g_ExDB.Close();


	return res;
}


BOOL AddDBFriend(char *szMaster, char *szFriend)
{
	int res = -1;

	if(g_ExDB.ExecQuery("EXEC WZ_FriendAdd '%s', '%s'", szMaster, szFriend))
	{
		if(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			res = g_ExDB.GetResult(0);
			if(res != 1)
				LogAddC(2, "WZ_FriendAdd returned: %d", res);

		}
		else
			LogAddC(2, "WZ_FriendAdd no result returned.");

	}
	else
		LogAddC(2, "Error executing WZ_FriendAdd.");

	g_ExDB.Close();

	if(res == 1)
		return TRUE;


	return FALSE;

}

BOOL DelDBFriend(char *szMaster, char *szFriend)
{
	int res = -1;


	if(g_ExDB.ExecQuery("EXEC WZ_FriendDel '%s', '%s'", szMaster, szFriend))
	{
		if(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			res = g_ExDB.GetResult(0);
			if(res != 1)
				LogAddC(2, "WZ_FriendDel returned: %d", res);

		}
		else
			LogAddC(2, "WZ_FriendDel no result returned.");

	}
	else
		LogAddC(2, "Error executing WZ_FriendDel.");

	g_ExDB.Close();

	if(res == 1)
		return TRUE;


	return FALSE;
}


int WaitFriendAdd(char *szMaster, char *szFriend)
{
	LPFRIEND_MASTER lpMaster;

	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
		return 0;

	if(FriendExists(szMaster, szFriend))
		return 4;

	if(lpMaster->m_vecFriends.size() == g_iMaxFriends)
	{
		LogAddC(0, "[%s]'s friend list is full - %d", szMaster, g_iMaxFriends);
		return 3;
	}

	if(AddDBFriend(szMaster, szFriend) == FALSE)
		return 0;

	if(AddFriend(szMaster, szFriend) == FALSE)
		return 0;

	LPFRIEND_MASTER lpFr;
	lpFr = GetFriendMaster(szMaster);
	if(lpFr)
	{
		int index = ExDBGetIndexByCode(lpFr->m_iServer);
		if(index != -1)
			SendState(index, szFriend, lpFr->m_iNumber, szMaster, lpMaster->m_btState);
	}

	return 1;
}

void GDWaitFriendAddReq( int aIndex,  FHP_WAITFRIEND_ADD_REQ* lpMsg)
{
	FHP_WAITFRIEND_ADD_RESULT Result;
	ZeroMemory(&Result, sizeof(Result));

	PHeadSetB((LPBYTE)&Result, 0x64, sizeof(Result));
	Result.Number = lpMsg->Number;

	strncpy(Result.Name, lpMsg->Name, 10);
	strncpy(Result.FriendName, lpMsg->FriendName, 10);
	Result.pServer = -1;

	char szMaster[11] = {0};
	char szFriend[11] = {0};

	strncpy(szMaster, lpMsg->Name, 10);
	strncpy(szFriend, lpMsg->FriendName, 10);

	LogAddTD("[WaitFriend Add Request] Name[%s], FriendName[%s].", szMaster, szFriend);

	if(lpMsg->Result == 0)
	{
		Result.Result = 2;
		LogAddTD("[WaitFriend Add Request] [%s] declined [%s]'s request to be a friend.", szMaster, szFriend);
		DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
		return;
	}

	LogAddTD("[WaitFriend Add Request] [%s] accepted [%s]'s request to be a friend.", szMaster, szFriend);

	LPFRIEND_MASTER lpFr;
	lpFr = GetFriendMaster(szFriend);
	if(lpFr)
		Result.pServer = lpFr->m_btState;

	Result.Result = WaitFriendAdd(szMaster, szFriend);
	if(Result.Result != 1)
		DelDBWaitFriend(szMaster, szFriend);


	FriendWaitSend(aIndex, szMaster);
	DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
}

void GDFriendStateChange( int aIndex, FHP_FRIEND_STATE_C* lpMsg)
{

	char szMaster[11] = {0};
	strncpy(szMaster, lpMsg->Name, 10);

	LogAddTD("[Friend State Receive] Name[%s], State[%d].", szMaster, lpMsg->State);
	LPFRIEND_MASTER lpMaster; 
	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
	{
		LogAddTD("[Friend State Receive] error: FriendMaster[%s] not found.", szMaster);
		return;
	}

	//	lpMaster->m_iNumber = lpMsg->Number;

	switch(lpMsg->State)
	{
	case 0:
		// refuse chat
		lpMaster->m_btState = -2;
		break;

	case 2:
		// ???, client shows "Cannot Use"
		lpMaster->m_btState = -3;
		break;

	default:
		// display server
		lpMaster->m_btState = lpMaster->m_iServer;
	}

	SendStateToAllFriends(aIndex, szMaster);
}

BOOL DelFriend(char *szMaster, char *szFriend)
{
	LPFRIEND_MASTER lpMaster;
	lpMaster = GetFriendMaster(szMaster);
	if(lpMaster == NULL)
		return FALSE;

	if(FriendExists(szMaster, szFriend) == FALSE)
		return FALSE;


	int cnt = lpMaster->m_vecFriends.size();
	for(int i=0; i < cnt; i++)
	{
		if(strcmp(lpMaster->m_vecFriends[i].m_szName, szFriend) == 0)
		{
			lpMaster->m_vecFriends.erase(lpMaster->m_vecFriends.begin()+i);
			LogAddTD("[%s] dropped [%s] from his friend list.", szMaster, szFriend);
			break;
		}

	}
	return TRUE;
}


void GDFriendDelReq( int aIndex, FHP_FRIEND_ADD_REQ* lpMsg)
{
	FHP_FRIEND_DEL_RESULT Result;
	ZeroMemory(&Result, sizeof(Result));

	PHeadSetB((LPBYTE)&Result, 0x65, sizeof(Result));

	Result.Number = lpMsg->Number;

	char szMaster[11] = {0};
	char szFriend[11] = {0};

	strncpy(Result.Name, lpMsg->Name, 10);
	strncpy(Result.FriendName, lpMsg->FriendName, 10);

	strncpy(szMaster, lpMsg->Name, 10);
	strncpy(szFriend, lpMsg->FriendName, 10);

	LogAddTD("[Friend Delete Request] Name[%s], FriendName[%s].", szMaster, szFriend);

	Result.Result = DelFriend(szMaster, szFriend);
	if(Result.Result)
		Result.Result = DelDBFriend(szMaster, szFriend);


	LogAddTD("[Friend Delete Request] Send Result [%d].", Result.Result);
	DataSend(aIndex, (LPBYTE)&Result, Result.h.size);

	LPFRIEND_MASTER lpFr;
	lpFr = GetFriendMaster(szFriend);
	if(lpFr)
	{
		int index = ExDBGetIndexByCode(lpFr->m_iServer);

		if(index != -1)
			SendState(index, szFriend, lpFr->m_iNumber, szMaster, -1);
	}
}

void MemoHeaderSend(int aIndex, WORD wNumber, LPMEMO_HEADER lpMemoHead )
{
	FHP_FRIEND_MEMO_LIST MemoHead;
	ZeroMemory(&MemoHead, sizeof(MemoHead));

	PHeadSetW((LPBYTE)&MemoHead, 0x71, sizeof(MemoHead));
	MemoHead.Number = wNumber;
	memcpy(&(MemoHead.MemoIndex), lpMemoHead, sizeof(*lpMemoHead));

	DataSend(aIndex, (LPBYTE)&MemoHead, sizeof(MemoHead));
}

void MemoListSend(int aIndex, WORD wNumber, char *szName)
{

	char szMaster[11] = {0};
	strncpy(szMaster, szName, 10);

	LogAddTD("[Mail List Send] Name[%s].", szMaster);
	int guid = GetFriendGuid(szMaster);
	if(guid == -1)
	{
		LogAddTD("[Mail List Send] error: GUID = -1.");
		return;
	}

	int cnt = 0;
	if(g_ExDB.ExecQuery("SELECT MemoIndex, FriendName, wDate, Subject, bRead FROM T_FriendMail where GUID=%d", guid))
	{
		while(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			MEMO_HEADER head;
			ZeroMemory(&head, sizeof(head));
			strncpy(head.RecvName, szName, 10);

			head.MemoIndex = g_ExDB.GetAsInteger("MemoIndex");
			g_ExDB.GetAsString("FriendName", head.SendName, 10);
			g_ExDB.GetAsString("wDate", head.Date, 30);
			g_ExDB.GetAsString("Subject", head.Subject, 32);
			head.read = g_ExDB.GetAsInteger("bRead");
			MemoHeaderSend(aIndex, wNumber, &head);
			cnt++;
		}
	}

	g_ExDB.Close();

	LogAddTD("[Mail List Send] Mail Count: %d.", cnt);
}


void FriendMemoListReq( int aIndex, FHP_FRIEND_MEMO_LIST_REQ* lpMsg)
{

	char szName[11] = {0};
	strncpy(szName, lpMsg->Name, 10);

	LogAddTD("[Mail List Request] Name[%s].", szName);
	MemoListSend(aIndex, lpMsg->Number, szName);
}


int DBWriteMail(LPMEMO_SEND_HEADER lpMemoSendHdr, LPBYTE Photo, BYTE btPhotoSize, char *sMemo, int memo_size)
{
	char szSendName[11] = {0};
	char szRecvName[11] = {0};

	strncpy(szSendName, lpMemoSendHdr->Name, 10);
	strncpy(szRecvName, lpMemoSendHdr->ToName, 10);


	if(g_ExDB.ExecQuery("EXEC WZ_WriteMail '%s', '%s', '%s', %d, %d", 
		szSendName, szRecvName, NULL, lpMemoSendHdr->Dir,  lpMemoSendHdr->Action))
	{
		if(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			int memo_index;
			int guid;

			memo_index = g_ExDB.GetResult(0);
			guid = g_ExDB.GetResult(1);
			g_ExDB.Close();

			if(memo_index <= 10)
			{
				if(memo_index == 2 || memo_index == 3)
					return -3;

				if(memo_index == 5)
					return -2;

				if(memo_index == 6)
					return -6;


				LogAddC(2, "WZ_WriteMail returned: %d", memo_index);
				return - 1;
			}

			if(guid < 0)
			{
				LogAddC(2, "WZ_WriteMail returned guid: %d", guid);
				return - 1;
			}

			char szMsg[1500];

			ZeroMemory(szMsg, 1500);
			wsprintf(szMsg, "UPDATE T_FriendMail SET Photo=? where MemoIndex=%d AND GUID=%d", memo_index, guid);
			g_ExDB.SetAsBinary(szMsg, Photo, btPhotoSize);
			g_ExDB.Close();


			ZeroMemory(szMsg, 1500);
			wsprintf(szMsg, "UPDATE T_FriendMail SET Subject=? where MemoIndex=%d AND GUID=%d", memo_index, guid);
			g_ExDB.SetAsBinary(szMsg, (LPBYTE)lpMemoSendHdr->Subject, 32);
			g_ExDB.Close();


			ZeroMemory(szMsg, 1500);
			wsprintf(szMsg, "UPDATE T_FriendMail SET Memo=? where MemoIndex=%d AND GUID=%d", memo_index, guid);
			g_ExDB.SetAsBinary(szMsg, (LPBYTE)sMemo, memo_size);
			g_ExDB.Close();

			return memo_index;
		}
		else
		{
			LogAddC(2, "WZ_WriteMail no result returned.");
			g_ExDB.Close();
		}
	}
	else
	{
		LogAddC(2, "Error executing WZ_WriteMail");
		g_ExDB.Close();
	}
	return -1;
}

void FriendMemoSend( int aIndex, FHP_FRIEND_MEMO_SEND* lpMsg)
{
	FHP_FRIEND_MEMO_SEND_RESULT Result;
	ZeroMemory(&Result, sizeof(Result));
	PHeadSetB((LPBYTE)&Result, 0x70, sizeof(Result));

	Result.Number = lpMsg->Number;
	Result.WindowGuid = lpMsg->WindowGuid;
	strncpy(Result.Name, lpMsg->Name, 10);

	char szName[11] = {0};
	strncpy(szName, Result.Name, 10);

	MEMO_SEND_HEADER head;
	ZeroMemory(&head, sizeof(head));

	memcpy(&head, lpMsg->Name, sizeof(head));

	int photo_size;
	int msg_size = MAKEWORD(lpMsg->h.sizeL, lpMsg->h.sizeH);
	LPBYTE lpMemo;
	LPBYTE lpPhoto;


	if(sizeof(*lpMsg) - sizeof(lpMsg->Memo) != msg_size - lpMsg->MemoSize)
	{
		photo_size = 13;
		lpMemo = (LPBYTE)((FHP_FRIEND_MEMO_SEND_OLD*)lpMsg)->Memo;
		lpPhoto = ((FHP_FRIEND_MEMO_SEND_OLD*)lpMsg)->Photo;
	}
	else
	{
		photo_size = 18;
		lpMemo = (LPBYTE)lpMsg->Memo;
		lpPhoto = lpMsg->Photo;

	}

	char szMaster[11]={0};
	strncpy(szMaster, lpMsg->ToName, 10);

	LogAddTD("[Mail Send Request] Name[%s], ToName[%s], MailSize[%d], PhotoSize[%d].", 
		szName, szMaster, lpMsg->MemoSize, photo_size);

	int res = -1;

	if(lpMsg->MemoSize <= 1000)
		res = DBWriteMail(&head, lpPhoto, photo_size, (char *)lpMemo, lpMsg->MemoSize);
	else
		LogAddTD("[Mail Send Request] error: Mail Size > 1000.");

	if(res == -2)
		Result.Result = 2;
	else if(res == -3)
		Result.Result = 3;
	else if(res == -6)
		Result.Result = 6;
	else if(res < 0)
		Result.Result = 0;
	else
		Result.Result = 1;


	LogAddTD("[Mail Send Request] Send Result [%d].", Result.Result);
	DataSend(aIndex, (LPBYTE)&Result, Result.h.size);

	if(Result.Result != 1)
		return;


	int iNumber = GetFriendNumber(szMaster);
	if(iNumber < 0 )
		return;

	MEMO_HEADER memo_head;
	memo_head.MemoIndex = res;
	memo_head.read = 0;
	strncpy(memo_head.Subject, lpMsg->Subject, 32);
	strncpy(memo_head.RecvName, lpMsg->ToName, 10);
	strncpy(memo_head.SendName, lpMsg->Name, 10);

	SYSTEMTIME st;
	GetLocalTime(&st);

	wsprintf(memo_head.Date, "%04d-%02d-%02d %02d:%02d:%02d", st.wYear, st.wMonth, st.wDay,
		st.wHour, st.wMinute, st.wSecond);

	memo_head.read = 2;
	MemoHeaderSend(aIndex, iNumber, &memo_head);
}

BOOL DBReadMail(int iMemoId, int iGuid, LPMEMO_READ lpMemoRead, LPDWORD lpdwMemoSize, LPBYTE lpPhoto, LPBYTE lpPhotoSize)
{
	if(g_ExDB.ExecQuery("SELECT bRead, Dir, Act FROM T_FriendMail where MemoIndex=%d AND GUID =%d", iMemoId, iGuid))
	{
		int bRead = 0;
		if(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			bRead = g_ExDB.GetAsInteger("bRead");
			lpMemoRead->Dir = g_ExDB.GetAsInteger("Dir");
			lpMemoRead->Action = g_ExDB.GetAsInteger("Act");
		}

		g_ExDB.Close();

		char szMsg[1500];
		ZeroMemory(szMsg, 1500);

		wsprintf(szMsg, "SELECT Photo FROM T_FriendMail where MemoIndex='%d' AND GUID=%d", iMemoId, iGuid);
		*lpPhotoSize = g_ExDB.GetAsBinary(szMsg, lpPhoto);
		g_ExDB.Close();

		if(*lpPhotoSize >= 18)
			*lpPhotoSize = 18;
		else if(*lpPhotoSize < 18)
			*lpPhotoSize = 13;


		ZeroMemory(szMsg, 1500);
		wsprintf(szMsg, "SELECT Memo FROM T_FriendMail where MemoIndex='%d' AND GUID=%d", iMemoId, iGuid);
		*lpdwMemoSize = g_ExDB.GetAsBinary(szMsg, (LPBYTE)lpMemoRead->Memo);
		g_ExDB.Close();

		if(*lpdwMemoSize < 0)
			*lpdwMemoSize = 0;
		if(bRead == 0)
		{
			g_ExDB.ExecQuery("UPDATE T_FriendMail SET bRead = 1 where MemoIndex=%d AND GUID=%d", iMemoId, iGuid);
			g_ExDB.Close();
		}

		return TRUE;

	}
	else
	{
		g_ExDB.Close();
		return FALSE;
	}
}


void FriendMemoReadReq( int aIndex, FHP_FRIEND_MEMO_RECV_REQ* lpMsg)
{

	MEMO_READ memo;
	ZeroMemory(&memo, sizeof(memo));
	DWORD memo_size=0;
	BYTE Photo[30]={-1};
	BYTE btPhotoSize=18;
	char szMaster[11]={0};
	strncpy(szMaster, lpMsg->Name, 10);

	LogAddTD("[Mail Read Request] Name[%s], MemoIndex[%d].", szMaster, lpMsg->MemoIndex);
	int guid = -1;
	guid = GetFriendGuid(szMaster);
	if(guid < 0)
	{
		LogAddTD("[Mail Read Request] error: GUID = -1.");
		return;
	}

	if(DBReadMail(lpMsg->MemoIndex, guid, &memo, &memo_size, Photo, &btPhotoSize))
	{
		if(btPhotoSize == 13)
		{
			FHP_FRIEND_MEMO_RECV_OLD Result;
			ZeroMemory(&Result, sizeof(Result));

			PHeadSetW((LPBYTE)&Result, 0x72, sizeof(Result)-sizeof(Result.Memo)+memo_size);

			Result.MemoIndex = lpMsg->MemoIndex;
			Result.Number = lpMsg->Number;
			strncpy(Result.Name, lpMsg->Name, 10);

			Result.MemoSize = memo_size;
			memcpy(&Result.Dir, &memo, sizeof(memo));
			memcpy(Result.Photo, Photo, 13);

			DataSend(aIndex, (LPBYTE)&Result, sizeof(Result)-sizeof(Result.Memo)+memo_size);
		}
		else
		{
			FHP_FRIEND_MEMO_RECV Result;
			ZeroMemory(&Result, sizeof(Result));

			PHeadSetW((LPBYTE)&Result, 0x72, sizeof(Result)-sizeof(Result.Memo)+memo_size);

			Result.MemoIndex = lpMsg->MemoIndex;
			Result.Number = lpMsg->Number;
			strncpy(Result.Name, lpMsg->Name, 10);

			Result.MemoSize = memo_size;
			memcpy(&Result.Dir, &memo, sizeof(memo));
			memcpy(Result.Photo, Photo, 18);

			DataSend(aIndex, (LPBYTE)&Result, sizeof(Result)-sizeof(Result.Memo)+memo_size);
		}

		LogAddTD("[Mail Read Request] Send Mail: size[%d], photo size[%d].", memo_size, btPhotoSize);
	}
}

BOOL DBDelMail(char *szName, int iMemoId)
{
	int res = FALSE;
	if(g_ExDB.ExecQuery("EXEC WZ_DelMail '%s', %d", szName, iMemoId))
	{
		if(g_ExDB.Fetch() != SQL_NO_DATA)
		{
			res = g_ExDB.GetResult(0);
			if(res != 1)
			{
				LogAddC(2, "WZ_DelMail returned: %d", res);
				res = FALSE;
			}
			else
				res = TRUE;
		}
		else
			LogAddC(2, "WZ_DelMail no result returned.");
	}
	else
		LogAddC(2, "Error executing WZ_DelMail");

	g_ExDB.Close();

	return res;
}

void FriendMemoDelReq( int aIndex, FHP_FRIEND_MEMO_DEL_REQ* lpMsg)
{

	FHP_FRIEND_MEMO_DEL_RESULT Result;
	ZeroMemory(&Result, sizeof(Result));
	PHeadSetB((LPBYTE)&Result, 0x73, sizeof(Result));

	Result.MemoIndex = lpMsg->MemoIndex;
	Result.Number = lpMsg->Number;
	strncpy(Result.Name, lpMsg->Name, 10);

	char szName[11]={0};
	strncpy(szName, lpMsg->Name, 10);


	LogAddTD("[Mail Delete Request] Name[%s], MamoIndex[%d].", szName, lpMsg->MemoIndex);

	Result.Result = DBDelMail(szName, lpMsg->MemoIndex);

	LogAddTD("[Mail Delete Request] Send Result [%d].", Result.Result);
	DataSend(aIndex, (LPBYTE)&Result, Result.h.size);
}
