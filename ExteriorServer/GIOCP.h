// Giocp.h
//------------------------------------------
// Decompiled by Deathway
// Date : 2007-03-09
//------------------------------------------
#ifndef GIOCP_H
#define GIOCP_H
#pragma once

enum eSERVER_TYPE
{
	ST_NONE				= 0,
	ST_DATASERVER		= 1,
	ST_JOINSERVER		= 2,
	ST_EVENTSERVER		= 3,
	ST_RANKINGSERVER	= 4,
	ST_CHATSERVER		= 5,
	ST_EXDATASERVER		= 6,
	ST_SHOPSERVER		= 7,
};

#define HIDE_ERRORL10
//#define MAX_EXSENDBUF_SIZE 7024
#define MAX_IO_BUFFER_SIZE	8192*2 //webzen doubled in dataserver :)	6000
#define MAX_IO_THREAD_HANDLES	16

struct _PER_IO_CONTEXT
{ 
	WSAOVERLAPPED Overlapped; // 0
	WSABUF wsabuf; 
	unsigned char Buffer[MAX_IO_BUFFER_SIZE]; // 1C
	unsigned char BufferSecond[MAX_IO_BUFFER_SIZE]; // 178C
	int nSecondOfs; // 2EFC
	int nTotalBytes;	// 2F00
	int nSentBytes; // 2F04
	int IOOperation; // 2F08
	int nWaitIO; // 2F0C
}; 

typedef struct tagIocpServerParameter
{
	DWORD dwServerCount;
	eSERVER_TYPE eServerType;

} IocpServerParameter;


struct _PER_SOCKET_CONTEXT
{
	SOCKET m_socket;	// 0
	int nIndex;	// 4
	_PER_IO_CONTEXT IOContext[2];	// 8
	int dwIOCount;	// 5E28
}; 

BOOL IocpServerStart();
BOOL CreateGIocp(int server_port, eSERVER_TYPE eServerType);
void DestroyGIocp();
BOOL CreateListenSocket(DWORD dwServerCountIndex);
unsigned long __stdcall IocpServerWorker(DWORD pIocpServerParameter);
unsigned long __stdcall ServerWorkerThread(HANDLE CompletionPortID);
BOOL RecvDataParse(_PER_IO_CONTEXT * lpIOContext, int uIndex);
BOOL DataSend(int aIndex, unsigned char* lpMsg, DWORD dwSize);
BOOL IoSendSecond(_PER_SOCKET_CONTEXT * lpPerSocketContext);
BOOL IoMoreSend(_PER_SOCKET_CONTEXT * lpPerSocketContext);
BOOL UpdateCompletionPort(SOCKET sd, int ClientIndex, DWORD dwServerTypeCount);
void CloseClient(_PER_SOCKET_CONTEXT * lpPerSocketContext, int result);
void CloseClient(int index);
void ResponErrorCloseClient(int index);

#endif