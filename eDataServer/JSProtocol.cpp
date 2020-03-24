#include "StdAfx.h"
#include "JSProtocol.h"
#include "Display.h"
#include "Structs.h"
#include "Enums.h"
#include "LogProc.h"
#include "JSManager.h"
#include "IOCP.h"

cJSProtocol gJSProtocol;

void cJSProtocol::ProtocolCore(int aIndex,BYTE HeadCode,LPBYTE aRecv,int iSize)
{
	gDisplay.CheckJSConnection(TRUE);
	// ----
	switch(HeadCode)
	{
		case JMSG_SERVER_LOGIN:
			this->AccountLogin(aIndex,(LPSDHP_SERVERINFO)aRecv);
		break;
		case JMSG_IDPASS:

		break;
	}
	// ----
	gDisplay.CheckJSConnection(FALSE);
}

void cJSProtocol::AccountLogin(int aIndex,LPSDHP_SERVERINFO lpMsg)
{
	SDHP_RESULTINFO pMsg = {0};
	// ----
	pMsg.h.set(JMSG_SERVER_LOGIN,sizeof(pMsg));
	pMsg.Result = 0;
	// ----
	if(gJSManager.AddServer(aIndex,lpMsg->ServerCode,lpMsg->ServerName,lpMsg->Port) == true)
	{
		LogAddTD("[JSProtocol][AccountLogin] GS(%s) Index(%d) Port(%d) Connected",lpMsg->ServerName,lpMsg->ServerCode,lpMsg->Port);
		pMsg.Result = 1;
	}
	// ----
	gIOCP.DataSend(aIndex,(LPBYTE)&pMsg,pMsg.h.size);
}

void cJSProtocol::AccountRequest(int aIndex,LPSDHP_ACCOUNTINFO lpMsg)
{
	char	szAccountID[11]		= {0};
	char	szIp[16]			= {0};
	char	szPass[11]			= {0};
	char	szTemp[100]			= {0};
	char	JoominNumber[14]	= {0};
	DWORD	dwAccKey			= {0};
	// ----
	int		Number				= lpMsg->Number;
	int		DBNumber			= 0;
	int		UserNumber			= 0;
	int		BlocCode			= 0;
	UCHAR	Result				= (UCHAR)eIDPASSRESULT_SUCCESS;
	// ----
	BuxConvert(lpMsg->Id,10);
	BuxConvert(lpMsg->Pass,10);
	// ----
	memcpy(szAccountID,lpMsg->Id,10);
	memcpy(szPass,lpMsg->Pass,10);
	memcpy(szIp,lpMsg->IpAddress,15);
	// ----
	if((SQLSyntexCheck(szAccountID) == true) && (SQLSyntexCheck(szPass) == true) && (SpaceSyntexCheck(szAccountID) == true))
	{
		if(g_ServerManager.CheckUser(szAccountID) == false)
		{
			if(g_DbManager.ExecFormat("SELECT * FROM MEMB_INFO WHERE memb___id='%s'",szAccountID) == true)
			{
				if(g_DbManager.Fetch() == SQL_SUCCESS)
				{
					DBNumber = g_DbManager.GetInt("memb_guid");
					BlocCode = g_DbManager.GetInt("bloc_code");
					// ----
					g_DbManager.GetStr("sno__numb",JoominNumber);
					// ----
					// # NORMAL Login
					// ----
					char szPassword[11] = {0};
					// ----
					g_DbManager.GetStr("memb__pwd", szPassword);
					// ----
					if(strcmp(szPass, szPassword) == 0)
					{
						Result = (UCHAR)eIDPASSRESULT_SUCCESS;
					}
					else
					{
						Result = eIDPASSRESULT_BADPASS;
						// ----
						g_Log.LogAdd(g_Colors.BlueViolet(), "[GProtocol][JGPAccountRequest][NON-MD5] :: Wrong Password - ID : %s",
							szAccountID);
					}
				}
				// ----
				g_DbManager.Clear();
				// ----
				if(Result == (UCHAR)eIDPASSRESULT_SUCCESS)
				{
					if(BlocCode > 0)
					{
						Result = (UCHAR)eIDPASSRESULT_ACCBANED;
					}
					else
					{
						if(g_ServerManager.AddUser(aIndex, szAccountID, szIp, lpMsg->Number) == false)
						{
							Result = (UCHAR)eIDPASSRESULT_MAXSERVER;
						}
					}
				}
			}																							// ####
			else
			{
				Result = (UCHAR)eIDPASSRESULT_BADID;
				// ----
				g_Log.LogAdd(g_Colors.BlueViolet(), "[GProtocol][JGPAccountRequest] :: Account doesn't exist - ID : %s", szAccountID);
			}
		}																								// ###
		else
		{
			g_Log.LogAdd(g_Colors.BlueViolet(), "[GProtocol][JGPAccountRequest] :: Fail ExecFormat ID : %s",
				szAccountID);
			// ----
			Result = (UCHAR)eIDPASSRESULT_TEMPBLOCK;
		}
		// ----
		g_DbManager.Clear();
	}																									// ##
	else
	{
		g_Log.LogAdd(g_Colors.BlueViolet(), "[GProtocol][JGPAccountRequest] :: Account already connected ID : %s",
			szAccountID);
		// ----
		Result = (UCHAR)eIDPASSRESULT_INUSE;
	}
}																										// #
	else
	{
		g_Log.LogAdd(g_Colors.BlueViolet(), "[GProtocol][JGPAccountRequest] :: (ANTIHACK) Special characters in... ID : %s",
				szAccountID);
		// ----
		Result = (UCHAR)eIDPASSRESULT_TEMPBLOCK;
	}
	// ----
	//g_Log.LogAdd(g_Colors.Orange(), "(DEBUG) got passwd %s && compare with %s || acc %s", lpMsg->Pass,
		//szPassword, szAccountID);
	// ----
	SDHP_IDPASSRESULT msg(Result, Number, UserNumber, DBNumber, szAccountID, JoominNumber);
	g_ServerManager.DataSend(aIndex, (LPBYTE)&msg, msg.h.size);
}