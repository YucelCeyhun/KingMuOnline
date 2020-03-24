// CSprotocol.h: interface for the CCSprotocol class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#include "InGameShopProtocol.h"
#include "common\zzzitem.h"
#include "stdafx.h"

#define	MAX_ITEM_CATEGORY		512
#define	MAX_CATEGORY			12

typedef struct
{
	BYTE	btItemGroup;
	BYTE	btItemID;
	BYTE	btItemLevel;
	BYTE	btItemSkill;
	BYTE	btItemLuck;
	BYTE	btItemOpt;
	BYTE	btItemExcOpt;
	BYTE	btItemAnc;
	BYTE	btItemAncAdd;
	BYTE	btItemSock[5];
	BYTE	btItemDur;
	WORD	wItemPrice;
	BYTE	btItemSpecialOpt; //Flag to show a special tag on InGame Item Shop, which can be (0:None, 1:New, 2:Hot and 3:Sale)
	DWORD	dwItemDuration;
} ISS_ITEM, * LPISS_ITEM;

void IGSServerInit();
void ISSLoadFile(char* file);
void ISSReloadFile();
void IGSProtocolCore(int aIndex, BYTE HeadCode, LPBYTE aRecv, int iSize);
void ISSGetPoints(int aIndex, LPMSG_REQ_ISS_GETPOINTS pMsg);
void ISSGetItemList(int aIndex, LPMSG_REQ_ISS_ITEMLIST pMsg);
void ISSBuyItem(int aIndex, LPMSG_REQ_ISS_ITEMBUY pMsg);
void ISSAddPoints(int aIndex, LPMSG_REQ_ISS_ADDPOINTS pMsg);

void ISSItemToItemUnit(LPISS_ITEM issItem, LPMSG_ANS_IGS_ITEM_UNIT unitItemInfo);
void ItemByteConvert(LPBYTE buf, int type, BYTE Option1, BYTE Option2, BYTE Option3, BYTE level, BYTE dur, BYTE Noption, BYTE SetOption, BYTE JewelOfHarmonyOption, BYTE ItemEffectEx, BYTE SocketOption[5], BYTE SocketIndex);