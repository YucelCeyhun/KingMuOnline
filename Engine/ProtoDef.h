#ifndef __PROTODEF_H__
#define __PROTODEF_H__

#include <windows.h>

#define PROTOCOL_MOVE			0x1D
#define PROTOCOL_POSITION		0xD6
#define PROTOCOL_ATTACK			0xDC
#define PROTOCOL_BEATTACK		0xD7

#define PROTOCOL_KILLED			0x17
#define PROTOCOL_VIEWPORTCHAR	0x14
#define PROTOCOL_TELEPORT		0x1C
#define PROTOCOL_CHARJOINMAP	0x03
#define PROTOCOL_CHARJOINRESULT	0x00
#define PROTOCOL_CHARRESPAWN	0x04
#define PROTOCOL_CHARLEVELUP	0x05
#define PROTOCOL_CHARPOINTDOWN	0x06

#define PROTOCOL_RECVHPTOSD		0x26
#define PROTOCOL_RECVMPTOAG		0x27

#define PROTO_CUSTOM_RESETDATA	0x05
#define PROTO_CUSTOM_UPDATECHAR	0x08
#define PROTO_CUSTOM_LIFEBAR	0x02

#define SET_NUMBERH(x) ( (BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x) ( (BYTE)((DWORD)(x) & 0xFF) )
#define SET_NUMBERHW(x) ( (WORD)((DWORD)(x)>>(DWORD)16) )
#define SET_NUMBERLW(x) ( (WORD)((DWORD)(x) & 0xFFFF) )

#define MAKE_NUMBERW(x,y)  ( (WORD)(((BYTE)((y)&0xFF)) |   ((BYTE)((x)&0xFF)<<8 ))  )
#define MAKE_NUMBERDW(x,y) ( (DWORD)(((WORD)((y)&0xFFFF)) | ((WORD)((x)&0xFFFF)<<16))  )

#ifndef _QWORD_DEFINED 
#define _QWORD_DEFINED 
typedef __int64 QWORD, *LPQWORD;
#endif

#define MAKEQWORD(a, b)      ((__int64)(((DWORD)((__int64)(a) & 0xffffffff)) | ((__int64)((DWORD)((__int64)(b) & 0xffffffff))) << 32))  
#define LODWORD(l)           ((DWORD)(__int64(l) & __int64(0xffffffff)))   
#define HIDWORD(l)           ((DWORD)(__int64(l) >> __int64(32)))   

#pragma pack(push, 1)
typedef struct _PHEADB
{
	unsigned char uPacketType;
	unsigned char uSize;
	unsigned char uHead;
} PHEADB, PHEADBE, *LPHEADB, *LPHEADBE;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct _PHEADSUBB
{
	unsigned char uPacketType;
	unsigned char uSize;
	unsigned char uHead;
	unsigned char uSubHead;

} PHEADSUBB, *LPPHEADSUBB;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct _PHEADW
{
	unsigned char uPacketType;
	unsigned char uSize[2];
	unsigned char uHead;
} PHEADW, *LPPHEADW;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct _PHEADSUBW
{
	unsigned char uPacketType;
	unsigned char uSize[2];
	unsigned char uHead;
	unsigned char uSubHead;
} PHEADSUBW, *LPPHEADSUBW;
#pragma pack(pop)

#pragma pack(push, 1)
struct PBMSG_HEAD
{
public:
	void set(LPBYTE lpBuf, BYTE head, BYTE size)
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};
	void setE(LPBYTE lpBuf, BYTE head, BYTE size)
	{
		lpBuf[0] = 0xC3;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};
	BYTE c;
	BYTE size;
	BYTE headcode;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PWMSG_HEAD
{
public:
	void set(LPBYTE lpBuf, BYTE head, int size)
	{
		lpBuf[0] = 0xC2;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};
	void setE(LPBYTE lpBuf, BYTE head, int size)
	{
		lpBuf[0] = 0xC4;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PBMSG_HEAD2
{
public:
	void set(LPBYTE lpBuf, BYTE head, BYTE sub, BYTE size)
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = size;
		lpBuf[2] = head;
		lpBuf[3] = sub;
	};

	BYTE c;
	BYTE size;
	BYTE headcode;
	BYTE subcode;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PWMSG_HEAD2
{
public:
	void set(LPBYTE lpBuf, BYTE head, BYTE sub, int size)
	{
		lpBuf[0] = 0xC2;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
		lpBuf[4] = sub;
	}

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
	BYTE subcode;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PMSG_DEFAULT2
{
	PBMSG_HEAD h;
	BYTE subcode;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct MAIN_CHECKSUM_SEND
{
	PBMSG_HEAD2 h;
	int checksum;
};
#pragma pack(pop)

struct PMSG_ATTACKRESULT
{
	PBMSG_HEAD	h;					// C1:DC
	BYTE		NumberH;			// 3
	BYTE		NumberL;			// 4
	BYTE		DamageH;			// 5
	BYTE		DamageL;			// 6
	BYTE		DamageType;			// 7
	BYTE		btShieldDamageH;	// 8
	BYTE		btShieldDamageL;	// 9
	float		Life;				// A
	float		MaxLife;			// E
	int			Class;
	int			AttackHP;
	int			AttackSD;
};

struct PMSG_DIEPLAYER
{
	PBMSG_HEAD h;
	BYTE NumberH;
	BYTE NumberL;
	BYTE SkillH;
	BYTE SkillL;
	BYTE KillerNumberH;
	BYTE KillerNumberL;
};

#endif