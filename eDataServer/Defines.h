#ifndef __DEFINES_H__
#define __DEFINES_H__

#define MAX_OBJECT				20
#define MAX_USER				(MAX_OBJECT * 1000)
#define SLOT_FREE				-1

#define WSA_VERSION				0x22
#define MAX_OBJECT				20
#define MAX_EXSENDBUF_SIZE		7024
#define MAX_IO_BUFFER_SIZE		100000
#define MAX_IO_THREAD_HANDLES	16
#define OP_SEND 				0
#define OP_RECV 				1
#define	DWAPI					static DWORD WINAPI 
#define VVOID					virtual void
#define	LPTHREAD				LPTHREAD_START_ROUTINE
#define LPPERSOCKET				_PER_SOCKET_CONTEXT * lpPerSocketContext
#define	TSYNC					TSynchroCriticalSection

#endif