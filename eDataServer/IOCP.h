#ifndef __IOCP_H__
#define __IOCP_H__

#include <Windows.h>
#include "Defines.h"

class cIOCP
{
	private:
	TSYNC				m_GSync;
	// ----
	OBJECTSTRUCT		m_Server[MAX_OBJECT];
	// ----
	HANDLE				m_hThread[MAX_IO_THREAD_HANDLES];
	HANDLE				m_hCmport;
	UINT				m_nThreadCount;
	SOCKET				m_Listen;
	// ----
	UINT				m_nPort;
	char				m_Name[30];
	UINT				m_AddedCount;
	bool				m_IsOneIpPerCon;
	// ----
	public:
	// ----
	cIOCP();
	~cIOCP();
	// ----
	void	SetDefaultSettings();
	// ----
	VVOID	OnError(const char*szMessage,...){};
	VVOID	OnMessage(const char*szMessage,...){};
	VVOID	OnRecv(int aIndex,BYTE HeadCode,LPBYTE aRecv,int iSize){};
	VVOID	OnSearch(int aIndex){};
	VVOID	OnConnect(int aIndex){};
	VVOID	OnDisconnect(int aIndex){};
	VVOID	OnConnected(int aIndex){};
	// ----
	bool	DataSend(int aIndex,UCHAR*lpMsg,DWORD dwSize);
};

extern cIOCP gIOCP;

#endif