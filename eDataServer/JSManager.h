#ifndef __JSMANAGER_H__
#define __JSMANAGER_H__

#include "Defines.h"

class cJSManager
{
public:
	// ----
	void	Load();
	// ----
	bool	IsCodeExist(int ServerCode);
	bool	AddServer(int ServerIndex,int ServerCode,char*szServerName,int Port);
	// ----
	bool	bReturn;
	int		m_ServerLoggedCount;
};

extern cJSManager gJSManager;

extern JOIN_SERVERDATA	m_ServObj[MAX_OBJECT];
extern JOIN_SERVERUSER	m_UserObj[MAX_USER];

#endif