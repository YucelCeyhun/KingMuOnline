#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <Windows.h>

struct PBMSG_HEAD
{
public:
	void set(UCHAR head,UCHAR size)
	{
		this->c			= 0xC1;
		this->size		= size;
		this->headcode	= head;
	};
	// ----
	void setE(UCHAR head,UCHAR size)
	{
		this->c			= 0xC3;
		this->size		= size;
		this->headcode	= head;
	};
	// ----
	UCHAR c;
	UCHAR size;
	UCHAR headcode;
};

// -----------------------------------------
// XXXXServer Info Result Struct [C1:00]
// -----------------------------------------
typedef struct
{
	struct PBMSG_HEAD	h;
	// ----
	UCHAR				Result;
	ULONG				ItemCount;
	// ----
} SDHP_RESULTINFO, *LPSDHP_RESULTINFO;

// -----------------------------------------
// JoinServer Server Info Struct [C1:00]
// -----------------------------------------
typedef struct
{
	struct PBMSG_HEAD	h;
	// -----
	UCHAR				Type;
	USHORT				Port;
	CHAR				ServerName[50];
	USHORT				ServerCode;
	// ----
} SDHP_SERVERINFO, *LPSDHP_SERVERINFO;

// -----------------------------------------
// JoinServer Account Info Struct [C1:01]
// -----------------------------------------
typedef struct
{
	PBMSG_HEAD			h;
	// ----
	CHAR				Id[10];
	CHAR				Pass[10];
	SHORT				Number;
	CHAR				IpAddress[17];
	// ----
} SDHP_ACCOUNTINFO, *LPSDHP_ACCOUNTINFO;

typedef struct
{
	void	Clear();
	char	m_szServerName[50];
	int		m_Index;
	int		m_ServerCode;
	int		m_Port;
	int		m_ConnectedCount;
	int		m_MaxUser;
} JOIN_SERVERDATA, *LPJOIN_SERVERDATA;

typedef struct
{
	void	Clear();
	char	m_szAccountID[10];
	int		m_ServerIndex;
	int		m_ServerCode;
	bool	m_bRequestMapSvrMove;
	int		m_nMoveMapTime;
	int		iUserNumber;
	short	nNumber;
	DWORD	BillCheckTimer;
	DWORD	BillCheckSendTimer;
	int		iJoinAuthCode1;
	int		iJoinAuthCode2;
	int		iJoinAuthCode3;
	int		iJoinAuthCode4;
	WORD	wPrevMapSvrCode;
	WORD	wMapNumber;
	BYTE	btX;
	BYTE	btY;
} JOIN_SERVERUSER, *LPJOIN_SERVERUSER;

typedef struct
{
	int				m_Index;
	char			m_ServerIp[16];
	// ----
	STATE			m_State;
	SOCKET			m_Socket;
	// ----
	struct _PER_SOCKET_CONTEXT * PerSocketContext;
	// ----
} OBJECT, *OBJECTSTRUCT;

#endif