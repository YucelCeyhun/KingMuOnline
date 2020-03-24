// ServerEngine.h: interface for the CServerEngine class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#pragma once
enum eSERVER_STATE
{
	SS_CLOSED,
	SS_CONNECTED,
	SS_LOGGED,
	SS_GUILD,
	SS_CHAT,
};

#define MAX_SERVER_TYPE (ST_SHOPSERVER+1)
#define OBJECT_PER_SERVERTYPE 10
#define MAX_SERVEROBJECT	(OBJECT_PER_SERVERTYPE * MAX_SERVER_TYPE)

struct tagSERVER_ENGINE
{
	int m_Index;
	SOCKET m_Socket;
	eSERVER_STATE m_State;
	eSERVER_TYPE m_Type;
	char m_ServerIp[16];
	struct _PER_SOCKET_CONTEXT * PerSocketContext;
	void (*ProtocolCore)(int, BYTE, LPBYTE, int);	// For Classic Protocol
	WORD m_ServerCode;
};

void gObjServerInit();
int gObjServerAddSearch();
int gObjServerAdd(SOCKET Socket, char * Ip, int ServerIndex, eSERVER_TYPE eServerType);
void gObjServerDel(int aIndex);
extern tagSERVER_ENGINE * g_Server;