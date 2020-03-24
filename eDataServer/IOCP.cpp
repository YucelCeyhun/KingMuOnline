#include "StdAfx.h"
#include "IOCP.h"
#include "LogProc.h"
#include "Structs.h"
#include "TSynchro.h"

cIOCP gIOCP;

cIOCP::cIOCP()
{
	this->SetDefaultSettings();
}

cIOCP::~cIOCP()
{
	// ----
}

void cIOCP::SetDefaultSettings()
{
	m_GSync.Lock();
	// ----
	memset(m_Name,0,sizeof(m_Name));
	// ----
	m_Name[0]		= 'I';
	m_Name[1]		= 'O';
	m_Name[2]		= 'C';
	m_Name[3]		= 'P';
	// ----
	m_nPort			= 44405;
	m_hCmport		= 0;	
	m_nThreadCount	= 0;
	m_AddedCount	= 0;
	m_Listen		= INVALID_SOCKET;
	m_IsOneIpPerCon	= false;
	// ----
	for(int i = 0; i != MAX_OBJECT; i++)
    {
		m_Server[i].m_Index             = SOCKET_ERROR;
		m_Server[i].m_Socket            = INVALID_SOCKET;
		m_Server[i].m_State             = SS_CLOSED;
		m_Server[i].PerSocketContext	= new _PER_SOCKET_CONTEXT;
    }
	// ----
	m_GSync.Unlock();
}

bool cIOCP::DataSend(int aIndex,UCHAR*lpMsg,DWORD dwSize)
{
	ULONG SendBytes		= NULL;
	// ----
	OBJECTSTRUCT lpObj	= m_Server[aIndex];
	// ----
	LPPERSOCKET			= lpObj->PerSocketContext;
	// ----
	if((aIndex < 0) || (aIndex > MAX_OBJECT))
	{
		OnError("[%s][DataSend] (DataSend) Index(%d) %x %x %x ",m_Name,dwSize,lpMsg[0],lpMsg[1],lpMsg[2]);
		// ----
		return false;
	}
	// ----
	if(lpObj->m_State < SS_CONNECTED)
	{
		return false;
	}
	// ----
	if(dwSize > sizeof(lpPerSocketContext->IOContext[0].Buffer))
	{
		OnError("[%s][DataSend] Error Max msg(%d) %s %d",m_Name,dwSize,__FILE__,__LINE__);
		// ----
		CloseClient(aIndex);
		// ----
		return false;
	}
	// ----
	_PER_IO_CONTEXT * lpIoCtxt = &lpPerSocketContext->IOContext[1];
	// ----
	if(lpIoCtxt->nWaitIO > 0)
	{
		if((lpIoCtxt->nSecondOfs + dwSize) > MAX_IO_BUFFER_SIZE-1)
		{
			OnError("[%s][DataSend] (Index->%d) Max Buffer Overflow %d %d %d",m_Name,aIndex,lpIoCtxt->nTotalBytes,lpIoCtxt->nSecondOfs,dwSize);
			// ----
			lpIoCtxt->nWaitIO = 0;
			// ----
			CloseClient(aIndex);
			// ----
			return true;
		}
		// ----
		memcpy(&lpIoCtxt->BufferSecond[lpIoCtxt->nSecondOfs],lpMsg,dwSize);
		// ----
		lpIoCtxt->nSecondOfs += dwSize;
		// ----
		return true;
	}
	// ----
	lpIoCtxt->nTotalBytes = 0;
	// ----
	if(lpIoCtxt->nSecondOfs > 0)
	{
		memcpy(lpIoCtxt->Buffer,lpIoCtxt->BufferSecond,lpIoCtxt->nSecondOfs);
		// ----
		lpIoCtxt->nTotalBytes	= lpIoCtxt->nSecondOfs;
		lpIoCtxt->nSecondOfs	= 0;
	}
	// ----
	if((lpIoCtxt->nTotalBytes + dwSize) > (MAX_IO_BUFFER_SIZE-1))
	{
		OnError("[%s][DataSend] (Index->%d) MAX BUFFER OVER %d %d %d",m_Name,aIndex,lpIoCtxt->nTotalBytes,dwSize);
		// ----
		lpIoCtxt->nWaitIO = 0;
		// ----
		CloseClient(aIndex);
		// ----
		return false;
	}
	memcpy(&lpIoCtxt->Buffer[lpIoCtxt->nTotalBytes],lpMsg,dwSize);
	// ----
	lpIoCtxt->nTotalBytes	+= dwSize;
	lpIoCtxt->wsabuf.buf	= (char*)&lpIoCtxt->Buffer;
	lpIoCtxt->wsabuf.len	= lpIoCtxt->nTotalBytes;
	lpIoCtxt->nSentBytes	= 0;
	lpIoCtxt->IOOperation	= OP_RECV;
	// ----
	if(WSASend(lpObj->m_Socket,&lpIoCtxt->wsabuf,1,&SendBytes,0,&lpIoCtxt->Overlapped,NULL) == SOCKET_ERROR)
	{
		if(WSAGetLastError() != WSA_IO_PENDING)
		{
			lpIoCtxt->nWaitIO = 0;
			// ----
			if(lpIoCtxt->wsabuf.buf[0] == 0xC1)
			{
				OnError("[%s][DataSend] (%d)WSASend(%d) failed with error [%x][%x] %d %s ",m_Name,__LINE__,aIndex,(BYTE)lpIoCtxt->wsabuf.buf[0],
					(BYTE)lpIoCtxt->wsabuf.buf[2],WSAGetLastError(),lpObj->m_ServerIp);
			}
			else if(lpIoCtxt->wsabuf.buf[0] == 0xC2)
			{
				OnError("[%s][DataSend] (%d)WSASend(%d) failed with error [%x][%x] %d %s ",m_Name,__LINE__,aIndex,(BYTE)lpIoCtxt->wsabuf.buf[0],
					(BYTE)lpIoCtxt->wsabuf.buf[3],WSAGetLastError(),lpObj->m_ServerIp);
			}
			// ----
			CloseClient(aIndex);
			// ----
			return false;
		}
	}
	else
	{
		lpPerSocketContext->dwIOCount++;
	}
	// ----	
	lpIoCtxt->nWaitIO = 1;
	// ----
	return true;
}