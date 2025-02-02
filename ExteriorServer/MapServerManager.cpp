#include "stdafx.h"
#include "MapServerManager.h"
//#include "MapClass.h"
#include "Readscript.h"
//#include "GameMain.h"
#include "LogProc.h"
//#include "user.h"

// GS-N 0.99.60T 0x0051BF30
//	GS-N	1.00.18	JPN	0x0054D8C0	-	Completed


_MAPSVR_DATA::_MAPSVR_DATA()
{
	this->Clear(1);
}

_MAPSVR_DATA::~_MAPSVR_DATA()
{
	return;
}

void _MAPSVR_DATA::Clear(int iInitSetVal)
{
	this->m_bIN_USE = FALSE;
	this->m_btMAPSVR_GROUP = -1;
	this->m_sSVR_CODE = -1;
	memset(this->m_cIPADDR, 0, sizeof(this->m_cIPADDR));
	this->m_wPORT = 0;

	for ( int iMAP_COUNT =0;iMAP_COUNT<MAX_NUMBER_MAP;iMAP_COUNT++)
	{
		switch ( iInitSetVal )
		{
		case -1:
			this->m_sMAP_MOVE[iMAP_COUNT] = -2;
			break;
		case 0:
			this->m_sMAP_MOVE[iMAP_COUNT] = -1;
			break;
		default:
			this->m_sMAP_MOVE[iMAP_COUNT] = -3;
		}
	}
}

CMapServerManager::CMapServerManager()
{
	srand(time(NULL)); 
	this->m_bMapDataLoadOk=FALSE;
	this->m_lpThisMapSvrData = NULL;

	InitializeCriticalSection(&this->m_critSVRCODE_MAP);
}


CMapServerManager::~CMapServerManager()
{
	DeleteCriticalSection(&this->m_critSVRCODE_MAP);
}


void CMapServerManager::Clear()
{
	this->m_bMapDataLoadOk = FALSE;

	for ( int iGROUP_COUNT=0;iGROUP_COUNT<MAX_MAP_GROUPS;iGROUP_COUNT++)
	{
		this->m_iMAPSVR_GROUP_COUNT[iGROUP_COUNT] = 0;

		for ( int iSUB_GROUP_COUNT=0;iSUB_GROUP_COUNT<MAX_MAP_SUBGROUPS;iSUB_GROUP_COUNT++)
		{
			this->m_MAPSVR_DATA[iGROUP_COUNT][iSUB_GROUP_COUNT].Clear(1);
		}
	}

	this->m_mapSVRCODE_MAP.clear();
}


BOOL CMapServerManager::LoadData(char* lpszFileName)
{
	if ( (lpszFileName == NULL) || ( strcmp(lpszFileName, "")== 0 ) ) 
	{
		MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : File Name Error");
		return FALSE;
	}

	EnterCriticalSection(&this->m_critSVRCODE_MAP);

	try
	{
		this->Clear();

		SMDFile = fopen(lpszFileName, "r");

		if ( SMDFile == NULL )
		{
			MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : fopen() : %s",
				lpszFileName);

			return FALSE;
		}

		int type = -1;
		SMDToken Token;

		while ( true )
		{
			Token = GetToken();

			if ( Token == END )
				break;

			type = int(TokenNumber);

			while ( true )
			{
				if ( type == 0 )
				{
					short sSVR_CODE = -1;
					short sMAPSVR_GROUP = -1;
					int iInitSetVal = 1;
					char szIpAddr[16]={0};
					WORD wPortNum = 0;
					WORD 
					Token = GetToken();

					if ( !strcmp("end", TokenString))
						break;

					sSVR_CODE = short(TokenNumber);

					Token = GetToken();
					sMAPSVR_GROUP = short(TokenNumber);

					Token = GetToken();
					iInitSetVal = int(TokenNumber);

					Token = GetToken();
					memcpy(szIpAddr, &TokenString[1], 16);
					szIpAddr[15] =0;

					Token = GetToken();
					wPortNum = (WORD)(TokenNumber);

					if ( sSVR_CODE < 0 )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : sSVR_CODE < 0 (SVR:%d) - 1",
							sSVR_CODE);

						return FALSE;
					}

					if ( iInitSetVal != -1 && iInitSetVal != 0 && iInitSetVal != 1 )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : iInitSetting Value:%d (SVR:%d) - 1",
							iInitSetVal, sSVR_CODE);

						return FALSE;
					}

					if ( !strcmp(szIpAddr, ""))
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : No IpAddress (SVR:%d)",
							sSVR_CODE);

						return FALSE;
					}

					if ( CHECK_LIMIT(sMAPSVR_GROUP, MAX_MAP_GROUPS) == FALSE )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : Map Server Group Index (IDX:%d)",
							sMAPSVR_GROUP);

						return FALSE;
					}

					if ( this->m_iMAPSVR_GROUP_COUNT[sMAPSVR_GROUP] >= MAX_MAP_SUBGROUPS )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : No Space to Save SvrInfo (SVR:%d)",
							sSVR_CODE);

						return FALSE;
					}

					_MAPSVR_DATA * lpMapSvrData = NULL;

					lpMapSvrData= &this->m_MAPSVR_DATA[sMAPSVR_GROUP][this->m_iMAPSVR_GROUP_COUNT[sMAPSVR_GROUP]];

					lpMapSvrData->Clear(iInitSetVal);
					lpMapSvrData->m_bIN_USE = TRUE;
					lpMapSvrData->m_sSVR_CODE = sSVR_CODE;
					lpMapSvrData->m_btMAPSVR_GROUP = sMAPSVR_GROUP;
					lpMapSvrData->m_wPORT = wPortNum;
					memcpy(lpMapSvrData->m_cIPADDR, szIpAddr, 16);
					lpMapSvrData->m_cIPADDR[15] = 0;

					this->m_mapSVRCODE_MAP.insert(std::pair<int,_MAPSVR_DATA *>(sSVR_CODE, lpMapSvrData));
					this->m_iMAPSVR_GROUP_COUNT[sMAPSVR_GROUP]++;
				}
				else if ( type == 1 )
				{
					short sSVR_CODE = -1;
					BYTE btNotMoveOption = 0;
					WORD wMapNum = 0;
					short sDEST_SVR_CODE = -1;
					_MAPSVR_DATA * lpMapSvrData = NULL;

					Token = GetToken();

					if ( !strcmp("end", TokenString))
						break;

					sSVR_CODE = TokenNumber;

					Token = GetToken();
					btNotMoveOption = TokenNumber;

					Token = GetToken();
					wMapNum = TokenNumber;

					Token = GetToken();
					sDEST_SVR_CODE = TokenNumber;

					if ( sSVR_CODE < 0 )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : sSVR_CODE < 0 (SVR:%d) - 2",
							sSVR_CODE);

						return FALSE;
					}

					if ( sDEST_SVR_CODE < -2 )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : sDEST_SVR_CODE < -1 (SVR:%d, DEST_SVR:%d) - 2",
							sSVR_CODE, sDEST_SVR_CODE);

						return FALSE;
					}

					std::map<int  ,_MAPSVR_DATA *>::iterator it = this->m_mapSVRCODE_MAP.find(sSVR_CODE);

					if ( it == this->m_mapSVRCODE_MAP.end() )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : sSVR_CODE wasn't registered (SVR:%d)",
							sSVR_CODE);

						return FALSE;
					}

					lpMapSvrData = it->second;

					if ( lpMapSvrData == NULL )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : lpMapSvrData == NULL (SVR:%d)",
							sSVR_CODE);

						return FALSE;
					}

					if ( lpMapSvrData->m_bIN_USE == FALSE )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : lpMapSvrData->m_bIN_USE == FALSE (SVR:%d)",
							sSVR_CODE);

						return FALSE;
					}

					if ( lpMapSvrData->m_sSVR_CODE != sSVR_CODE )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : lpMapSvrData->m_sSVR_CODE != sSVR_CODE (SVR:%d)",
							sSVR_CODE);

						return FALSE;
					}

					if ( btNotMoveOption != 0 && btNotMoveOption != 1 )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : lpMapSvrData->m_sSVR_CODE != sSVR_CODE (SVR:%d, OPT:%d)",
							sSVR_CODE, btNotMoveOption);

						return FALSE;
					}

					if ( CHECK_LIMIT(wMapNum, MAX_NUMBER_MAP) == FALSE )
					{
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : Map Number is out of bound (SVR:%d, MAP:%d)",
							sSVR_CODE, wMapNum);

						return FALSE;
					}

					switch ( btNotMoveOption )
					{
					case 0:
						lpMapSvrData->m_sMAP_MOVE[wMapNum] = sDEST_SVR_CODE;
						break;
					case 1:
						lpMapSvrData->m_sMAP_MOVE[wMapNum] = -3;
						break;
					default:
						MsgBox("[MapServerMng] CMapServerManager::LoadData() - file load error : lpMapSvrData->m_sSVR_CODE != sSVR_CODE (SVR:%d, OPT:%d)",
							sSVR_CODE, btNotMoveOption);
						break;
					}
				}	// if type
			}	// while ( true )
		}	// while ( true )

		fclose(SMDFile);

		this->m_bMapDataLoadOk = TRUE;
	}
	catch(...)
	{
	}

	LeaveCriticalSection(&this->m_critSVRCODE_MAP);

	return TRUE;
}

BOOL MapNumberCheck(int map)
{
	if ( map < 0 || map > MAX_NUMBER_MAP-1 )
	{
		return FALSE;
	}
	return TRUE;
}

BOOL CMapServerManager::CheckMapCanMove(int iMAP_NUM)
{
	if ( MapNumberCheck(iMAP_NUM) == 0 )
	{
		return FALSE;
	}

	_MAPSVR_DATA * lpMapSvrData = this->m_lpThisMapSvrData;

	if ( lpMapSvrData == NULL )
	{
		return FALSE;
	}

	if ( lpMapSvrData->m_bIN_USE == FALSE )
	{
		return FALSE;
	}

	short sMAP_MOVE_INFO = lpMapSvrData->m_sMAP_MOVE[iMAP_NUM];

	if ( sMAP_MOVE_INFO != -3 )
	{
		return FALSE;
	}

	return TRUE;
}

short CMapServerManager::CheckMoveMapSvr(int iIndex, int iMAP_NUM, short sSVR_CODE_BEFORE)
{
	return -1;
}

BOOL CMapServerManager::GetSvrCodeData(WORD wServerCode, char* lpszIpAddress, WORD * lpwPort)
{
	if ( !lpszIpAddress || !lpwPort )
		return FALSE;

	_MAPSVR_DATA * lpMapSvrData = NULL;

	EnterCriticalSection(&this->m_critSVRCODE_MAP);

	std::map<int, _MAPSVR_DATA *>::iterator it = this->m_mapSVRCODE_MAP.find(wServerCode);

	if ( it != this->m_mapSVRCODE_MAP.end() )
	{
		lpMapSvrData = it->second;
	}

	LeaveCriticalSection(&this->m_critSVRCODE_MAP);

	if ( lpMapSvrData == NULL )
		return FALSE;

	strcpy(lpszIpAddress, lpMapSvrData->m_cIPADDR);
	*lpwPort = lpMapSvrData->m_wPORT;

	return TRUE;
}

CMapServerManager g_MapServerManager;