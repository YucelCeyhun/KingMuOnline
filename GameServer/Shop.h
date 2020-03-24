#ifndef ___SHOP_H
#define ___SHOP_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\common\zzzitem.h"

#define MAX_SHOP			26		// MAX_SHOP : "Data\ShopXX.txt"
#define MAX_ITEM_IN_SHOP	120

class CShop
{
public:
	CShop();
	virtual ~CShop();
	// ----
	void Init();
	BOOL LoadShopItem(int Shopnumber);
	BOOL LoadShopItem(char* filename);
	int InsertItem(int type,int index,int level,int dur,int op1,int op2,int op3,int exc,int anc);
	int InentoryMapCheck(int sx,int sy,int width,int height);
public:
	BYTE ShopInventoryMap[MAX_ITEM_IN_SHOP];
	int ItemCount;
	CItem m_item[MAX_ITEM_IN_SHOP];
	BYTE SendItemData[MAX_ITEM_IN_SHOP*(MAX_ITEM_INFO+1)];
	int SendItemDataLen;
};

BOOL ShopDataLoad();
extern CShop ShopC[MAX_SHOP];

#endif