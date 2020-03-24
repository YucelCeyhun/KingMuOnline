#pragma once

#include <Windows.h>
#include "..\include\prodef.h"

/*
enum
{
	eMSG_HEADER_WAREHOUSE = 0xE1,

	eMSG_DS_WAREHOUSE_INFO = 0x01,
	eMSG_DS_WAREHOUSE_INFO_SAVE = 0x02,
	eMSG_DS_WAREHOUSE_CHANGE = 0x03,
};
*/

/*
PACKET:			MSG_REQ_DS_WAREHOUSE_INFO
DIRECTION:		GAMESERVER to DATASERVER
DESCRIPTION:
dwIndex			- Index of user obj;
szAccountID		- Name of account to retrieve information about;
*/

/*typedef struct
{
	PBMSG_HEAD2	h;
	DWORD		dwIndex;
	TCHAR		szAccountID[MAX_ACCOUNT_LEN + 1];
} MSG_REQ_DS_WAREHOUSE_INFO, *LPMSG_REQ_DS_WAREHOUSE_INFO;*/

/*
PACKET:			MSG_ANS_DS_WAREHOUSE_INFO
DIRECTION:		DATASERVER to GAMESERVER
DESCRIPTION:
dwIndex				- Index of user obj;
iExpandCount		- Current warehouse expansion number;
iCurrentWarehouseId	- Current warehouse used slot;
*/

/*typedef struct
{
	PBMSG_HEAD2	h;
	DWORD		dwIndex;
	INT			iExpandCount;
	INT			iCurrentWarehouseId;
} MSG_ANS_DS_WAREHOUSE_INFO, *LPMSG_ANS_DS_WAREHOUSE_INFO;*/

/*
PACKET:			MSG_REQ_DS_WAREHOUSE_INFO_SAVE
DIRECTION:		GAMESERVER to DATASERVER
DESCRIPTION:
szAccountID		- Name of account to retrieve information about;
wId				- Number of warehouse expansion for this account;
*/

/*typedef struct
{
	PBMSG_HEAD2	h;
	TCHAR		szAccountID[MAX_ACCOUNT_LEN + 1];
	WORD		wId;
} MSG_REQ_DS_WAREHOUSE_INFO_SAVE, *LPMSG_REQ_DS_WAREHOUSE_INFO_SAVE;*/

/*
PACKET:			MSG_REQ_DS_WAREHOUSE_CHANGE
DIRECTION:		GAMESERVER to DATASERVER
DESCRIPTION:
dwIndex			- Index of user obj;
szAccountID		- Name of account to change warehouse;
wId				- Id of new warehouse to change;
bOpen			- Open warehouse after change it;
*/

/*typedef struct
{
	PBMSG_HEAD2	h;
	DWORD		dwIndex;
	TCHAR		szAccountID[MAX_ACCOUNT_LEN + 1];
	WORD		wId;
	BOOL		bOpen;
} MSG_REQ_DS_WAREHOUSE_CHANGE, *LPMSG_REQ_DS_WAREHOUSE_CHANGE;*/

/*
PACKET:			MSG_ANS_DS_WAREHOUSE_CHANGE
DIRECTION:		DATASERVER to GAMESERVER
DESCRIPTION:
dwIndex			- Index of user obj;
wId				- Id of new warehouse to change;
bOpen			- Open warehouse after change it;
*/

/*typedef struct
{
	PBMSG_HEAD2	h;
	DWORD		dwIndex;
	WORD		wId;
	BOOL		bOpen;
} MSG_ANS_DS_WAREHOUSE_CHANGE, *LPMSG_ANS_DS_WAREHOUSE_CHANGE;*/

/*
PACKET:			MSG_REQ_GS_WAREHOUSE_CHANGE
DIRECTION:		CLIENT to GAMESERVER
DESCRIPTION:
iNext			- If used next button at warehouse, 1 is set;
iPrevious		- If used previous button at warehouse, 1 is set;
*/

/*typedef struct
{
	PBMSG_HEAD2 h;
	INT iNext;
	INT iPrevious;
} MSG_REQ_GS_WAREHOUSE_CHANGE, *LPMSG_REQ_GS_WAREHOUSE_CHANGE;
*/