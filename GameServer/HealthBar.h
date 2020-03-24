#ifndef __HEALTHBAR_H__
#define __HEALTHBAR_H__

#ifdef __IS_HPBAR__

#include "StdAfx.h"
#include "..\include\prodef.h"
#include "user.h"

enum ePROTO_HEALTH_BAR
{
	eMSG_GS_CLIENT_CUSTOM	= 0xBB,
	eMSG_GS_CLIENT_LIFE_BAR	= 0x2,
};

/*
	PACKET:			MSG_ANS_LIFEBAR_SEND
	DIRECTION:		GAMESERVER to CLIENT
	DESCRIPTION:
					aIndex			- Index of target;
					Level			- Level of target;
					Life			- Current life of target;
					MaxLife			- Maximum life of target;
					SD				- Current SD of target;
					MaxSD			- Maximum SD of target;
*/
typedef struct
{
	PBMSG_HEAD2	h;
	INT			NumberH;
	INT			NumberL;
	INT			Level;
	FLOAT		Life;
	INT			MaxLife;
	INT			Class;
	BOOL		SendSD;
} MSG_ANS_LIFEBAR_SEND, *LPMSG_ANS_LIFEBAR_SEND;

/*
	PACKET:			MSG_ANS_LIFEBAR_SEND
	DIRECTION:		GAMESERVER to CLIENT
	DESCRIPTION:
					aIndex			- Index of target;
					Level			- Level of target;
					Life			- Current life of target;
					MaxLife			- Maximum life of target;
					SD				- Current SD of target;
					MaxSD			- Maximum SD of target;
*/
typedef struct
{
	PBMSG_HEAD2	h;
	INT			NumberH;
	INT			NumberL;
	INT			Level;
	FLOAT		Life;
	INT			MaxLife;
	INT			Class;
} MSG_ANS_LIFEBAR_SEND2, *LPMSG_ANS_LIFEBAR_SEND2;

class cHealthBar
{
public:
	cHealthBar();
	virtual ~cHealthBar();
	// ----
	void Info(LPOBJ lpObj);
	void Send(int aIndex,int tIndex);
};

extern cHealthBar gHealthBar;

#endif // __IS_HPBAR__
#endif // __HEALTHBAR_H__