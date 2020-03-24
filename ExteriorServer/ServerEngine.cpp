// ServerEngine.cpp: implementation of the CServerEngine class.
//////////////////////////////////////////////////////////////////////
#include "StdAfx.h"
#include "GuildServer.h"

tagSERVER_ENGINE * g_Server = NULL;

void gObjServerInit()
{
	g_Server = new tagSERVER_ENGINE[MAX_SERVEROBJECT]; 

	if ( g_Server == NULL )
	{
		MsgBox("[Server Engine] Memory Allocation Error");
		return;
	}
	memset(g_Server, 0, sizeof(tagSERVER_ENGINE) * MAX_SERVEROBJECT);

	for(int i=0;i<MAX_SERVEROBJECT;i++)
	{
		g_Server[i].m_Index = -1;
		g_Server[i].m_Socket = INVALID_SOCKET;
		g_Server[i].m_State = SS_CLOSED;
		g_Server[i].m_Type = ST_NONE;
		g_Server[i].ProtocolCore = NULL;
		g_Server[i].PerSocketContext = new _PER_SOCKET_CONTEXT;
		g_Server[i].m_ServerCode = -1;
	}
}


int gObjServerAddSearch()
{
	if ( g_Server == NULL )
		return -1;

	for(int i=0;i<MAX_SERVEROBJECT;i++)
	{
		if ( g_Server[i].m_Index == -1 )
		{
			return i;
		}
	}
	return -1;
}


int gObjServerAdd(SOCKET Socket, char * Ip, int ServerIndex, eSERVER_TYPE eServerType)
{
	g_Server[ServerIndex].m_Index = ServerIndex;
	memcpy(g_Server[ServerIndex].m_ServerIp, Ip, 16);
	g_Server[ServerIndex].m_State = SS_CONNECTED;
	g_Server[ServerIndex].m_Type = eServerType;
	g_Server[ServerIndex].m_Socket = Socket;

	switch ( g_Server[ServerIndex].m_Type )
	{
	case ST_JOINSERVER:
		g_Server[ServerIndex].ProtocolCore = SProtocolCore;
		break;
	case ST_EXDATASERVER:
		g_Server[ServerIndex].ProtocolCore = EDSProtocolCore;
		break;
	case ST_SHOPSERVER:
		g_Server[ServerIndex].ProtocolCore = IGSProtocolCore;
		break;
	}
	
	LogAddTD("[Server Engine] Connect : Index : %d - IP : %s - ServerType : %d",ServerIndex, Ip, eServerType);

	return ServerIndex;
}

void gObjServerDel(int aIndex)
{
	g_Server[aIndex].m_Index = -1;
	g_Server[aIndex].m_Socket = INVALID_SOCKET;
	g_Server[aIndex].m_ServerIp[0];
	g_Server[aIndex].m_State = SS_CLOSED;
	g_Server[aIndex].m_Type = ST_NONE;
	g_Server[aIndex].ProtocolCore = NULL;

	MuLoginDeleteServer(g_Server[aIndex].m_ServerCode);

	g_Server[aIndex].m_ServerCode = 0xFF;
}