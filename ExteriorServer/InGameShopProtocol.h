#pragma once

#define		MAX_PAGE_ITEM_COUNT	9
#include "stdafx.h"

//class PBMSG_HEAD2;

// This enum handles all messages headers and subheaders about InGameShop protocol.
enum 
{
	eMSG_REQ_IGS_CHECKSTATUS	= 0x01,
	eMSG_ANS_IGS_CHECKSTATUS	= 0x02,
	eMSG_REQ_IGS_GETPOINTS		= 0x03,
	eMSG_ANS_IGS_GETPOINTS		= 0x04,
	eMSG_REQ_IGS_ITEMLIST		= 0x05,
	eMSG_ANS_IGS_ITEMLIST		= 0x06,
	eMSG_REQ_IGS_ITEMBUY		= 0x07,
	eMSG_ANS_IGS_ITEMBUY		= 0x08,

	eMSG_REQ_ISS_ADDPOINTS		= 0x10,
	eMSG_ANS_ISS_ADDPOINTS		= 0x11,

	eMSG_HEADER_CASHSHOP		= 0xF5
};


/*
	PACKET:			MSG_REQ_IGS_CHECKSTATUS
	DIRECTION:		CLIENT to GAMESERVER
	DESCRIPTION:
					btShopOpenType		- Dont know
					btShopOpenAlready	- Dont know
*/
typedef struct 
{
	PBMSG_HEAD2		head;
	BYTE			btShopOpenType;
	BYTE			btShopOpenAlready;
} MSG_REQ_IGS_CHECKSTATUS, * LPMSG_REQ_IGS_CHECKSTATUS;


/*
	PACKET:			MSG_REQ_AMS_CHECKSTATUS
	DIRECTION:		GAMESERVER to CLIENT
	DESCRIPTION:
					btResult		- 0: OK; 6: OFF; 8: Unable to Open (other interface in use, like Personal Shop);
*/
typedef struct
{
	PBMSG_HEAD2		head;
	BYTE			btResult;
} MSG_ANS_IGS_CHECKSTATUS, * LPMSG_ANS_IGS_CHECKSTATUS;


/*
	PACKET:			MSG_REQ_ISS_GETPOINTS
	DIRECTION:		GAMESERVER to INGAMESHOPSERVER
	DESCRIPTION:
					dwIndex			- Object index, to identify client connection;
					dwUserGuid		- Game User ID, DBNumber on LPOBJ or memb_guid on accounts table;
					
*/
typedef struct
{
	PBMSG_HEAD		head;
	DWORD			dwIndex;
	DWORD			dwUserGuid;
} MSG_REQ_ISS_GETPOINTS, * LPMSG_REQ_ISS_GETPOINTS;


/*
	PACKET:			MSG_ANS_ISS_GETPOINTS
	DIRECTION:		INGAMESHOPSERVER to GAMESERVER
	DESCRIPTION:
					dwIndex			- Object index, to identify client connection;
					dwUserGuid		- Game User ID, DBNumber on LPOBJ or memb_guid on accounts table;
*/
typedef struct
{
	PBMSG_HEAD		head;
	DWORD			dwIndex;
	DWORD			dwIGSPoints;
} MSG_ANS_ISS_GETPOINTS, * LPMSG_ANS_ISS_GETPOINTS;


/*
	PACKET:			MSG_ANS_IGS_GETPOINTS
	DIRECTION:		GAMESERVER to CLIENT
	DESCRIPTION:
					dwIGSPoints		- InGameShop balance;
*/
typedef struct
{
	PBMSG_HEAD2		head;
	DWORD			dwIGSPoints;
} MSG_ANS_IGS_GETPOINTS, * LPMSG_ANS_IGS_GETPOINTS;


/*
	PACKET:			MSG_REQ_ISS_ADDPOINTS
	DIRECTION:		GAMESERVER to INGAMESHOPSERVER
	DESCRIPTION:
					dwUserGuid		- Game User ID, DBNumber on LPOBJ or memb_guid on accounts table;
					dwIndex			- Object index, to identify client connection;
					dwIGSPoints		- Amount to add (or remove if a negetive value is set) on IGSPoints;
*/
typedef struct
{
	PBMSG_HEAD		head;
	DWORD			dwIndex;
	DWORD			dwUserGuid;
	int				dwAddIGSPoints;
} MSG_REQ_ISS_ADDPOINTS, * LPMSG_REQ_ISS_ADDPOINTS;


/*
	PACKET:			MSG_REQ_IGS_ITEMLIST
	DIRECTION:		CLIENT to GAMESERVER
	DESCRIPTION:
					btCategoryID	- Current InGameShop category ID;
					btPageIndex		- Current page on above category;
					btPageLoaded	- Dunno, maybe flag last page was loaded?
*/
typedef struct
{
	PBMSG_HEAD2		head;
	BYTE			btCategoryID;
	BYTE			btPageIndex;
	BYTE			btPageLoaded;
} MSG_REQ_IGS_ITEMLIST, * LPMSG_REQ_IGS_ITEMLIST;


/*
	PACKET:			MSG_REQ_ISS_ITEMLIST
	DIRECTION:		GAMESERVER to INGAMESHOPSERVER
	DESCRIPTION:
					dwIndex			- Object index, to identify client connection;
					btCategoryID	- Current InGameShop category ID;
					btPageIndex		- Current page on above category;
*/
typedef struct
{
	PBMSG_HEAD	head;
	DWORD		dwIndex;
	BYTE		btCategoryID;
	BYTE		btPageIndex;
} MSG_REQ_ISS_ITEMLIST, * LPMSG_REQ_ISS_ITEMLIST;

#pragma pack(1)

/*
	PACKET:			MSG_ANS_IGS_ITEMLIST_UNIT
	DIRECTION:		INGAMESHOPSERVER to GAMESERVER (inside MSG_ANS_IGS_ITEMLIST)
	DESCRIPTION:	
					dwItemGuid			- Unique ItemID - non-zero;
					btCategoryID		- Item category ID;
					btItemDur			- Item durability (not duration);
					btItemSaleRatio		- Dont know;
					wItemPrice			- Item price, max is 65535;
					btSpecialOption		- Dont know;
					btItemInfo[12]		- Item information array, which is:
																			[0]		- ItemCode (ItemGroup * 512 + ItemID);
																			[1]		- Level, Skill, Luck and Add
																			[2]		- Item durability;
																			[3]		- ExcOption and +16 info;
																			[4]		- Ancient options;
																			[5]		- Item380 PVP Add;
																			[6]		- Jewel of Harmony option + Socket Index;
																			[7]		- Socket 1
																			[8]		- Socket 2
																			[9]		- Socket 3
																			[10]	- Socket 4
																			[11]	- Socket 5
					dwItemUsePeriod		- Item Use Period in minutes.
			
*/
typedef	struct
{
	DWORD		dwItemGuid;
	BYTE		btCategoryID;
	BYTE		btItemDur;
	BYTE		btItemSaleRatio;
	WORD		wItemPrice;
	BYTE		btSpecialOption;
	BYTE		arItemInfo[12];
	DWORD		dwItemUsePeriod;

} MSG_ANS_IGS_ITEM_UNIT, * LPMSG_ANS_IGS_ITEM_UNIT; //Just added an Alias to a better reading;

/*
	PACKET:			MSG_ANS_ISS_ITEMLIST
	DIRECTION:		INGAMESHOPSERVER to GAMESERVER
	DESCRIPTION:	
					dwIndex			- Object index, to identify client connection;
					btCategoryID	- Current InGameShop category ID;
					btPageIndex		- Current page on above category;
					btItemCount		- How many items info it has, max 9;
					ItemInfo		- An array containing item infos (struct MSG_ANS_IGS_ITEMLIST_UNIT);
*/
typedef struct
{
	PBMSG_HEAD					head;
	DWORD						dwIndex;
	BYTE						btCategoryID;
	BYTE						btPageIndex;
	BYTE						btItemCount;
	MSG_ANS_IGS_ITEM_UNIT		ItemInfo[MAX_PAGE_ITEM_COUNT];
} MSG_ANS_ISS_ITEMLIST, * LPMSG_ANS_ISS_ITEMLIST;

/*
	PACKET:			MSG_ANS_IGS_ITEMLIST
	DIRECTION:		INGAMESHOPSERVER to GAMESERVER
	DESCRIPTION:	
					btCategoryID	- Current InGameShop category ID;
					btPageIndex		- Current page on above category;
					btItemCount		- How many items info it has, max 9;
					ItemInfo		- An array containing item infos (struct MSG_ANS_IGS_ITEMLIST_UNIT);
*/
typedef struct
{
	PBMSG_HEAD2					head;
	BYTE						btCategoryID;
	BYTE						btPageIndex;
	BYTE						btItemCount;
	MSG_ANS_IGS_ITEM_UNIT		ItemInfo[MAX_PAGE_ITEM_COUNT];
} MSG_ANS_IGS_ITEMLIST, * LPMSG_ANS_IGS_ITEMLIST;


/*
	PACKET:			MSG_ANS_IGS_ITEMLIST
	DIRECTION:		CLIENT to GAMESERVER
	DESCRIPTION:
					dwItemGuid		- Unique item GUID;
					btCategoryID	- Current InGameShop category ID;
*/
typedef struct
{
	PBMSG_HEAD2		head;
	DWORD			dwItemGuid;
	BYTE			btCategoryID;

} MSG_REQ_IGS_ITEMBUY, * LPMSG_REQ_IGS_ITEMBUY;


/*
	PACKET:			MSG_REQ_ISS_ITEMBUY
	DIRECTION:		GAMESERVER to INGAMESHOPSERVER
	DESCRIPTION:
					dwIndex			- Object index, to identify client connection;
					dwUserGuid		- User db guid, to identify his registry on db;
					dwItemGuid		- Unique item GUID;
					btCategoryID	- Current InGameShop category ID;
*/
typedef struct
{
	PBMSG_HEAD		head;
	DWORD			dwIndex;
	DWORD			dwUserGuid;
	DWORD			dwItemGuid;
	BYTE			btCategoryID;
} MSG_REQ_ISS_ITEMBUY, * LPMSG_REQ_ISS_ITEMBUY;

/*
	PACKET:			MSG_ANS_ISS_ITEMBUY
	DIRECTION:		INGAMESHOPSERVER to GAMESERVER
	DESCRIPTION:
					dwIndex			- Object index, to identify client connection;
					dwIGSPoints		- Current IGCSPoints on DB;
					ItemInfo		- Information of selected item to buy;
					btResult		- Item buy result code, which can be:
																			0 - Success;
																			1 - Dont know;
																			2 - Insufficient inventory space;
																			3 - Invalid selected item;
																			4 - Dont know;
																			5 - Dont know;
																			6 - Ingame Shop Server unavailable;
																			7 - Ingame Shop Server loading;
																			8 - Dont know;
																			9 - General error;
*/
typedef struct
{
	PBMSG_HEAD				head;
	DWORD					dwIndex;
	WORD					dwIGSPoints;			
	MSG_ANS_IGS_ITEM_UNIT	ItemInfo;
	BYTE					btResult;
} MSG_ANS_ISS_ITEMBUY, * LPMSG_ANS_ISS_ITEMBUY;


/*
	PACKET:			MSG_ANS_IGS_ITEMBUY
	DIRECTION:		GAMESERVER to CLIENT
	DESCRIPTION:
					btResult		- Item buy result code, which can be:
																			0 - Success;
																			1 - Dont know;
																			2 - Insufficient inventory space;
																			3 - Invalid selected item;
																			4 - Dont know;
																			5 - Dont know;
																			6 - Ingame Shop Server unavailable;
																			7 - Ingame Shop Server loading;
																			8 - Dont know;
																			9 - General error;

*/
typedef struct
{
	PBMSG_HEAD2		head;
	BYTE			btResult;
} MSG_ANS_IGS_ITEMBUY, * LPMSG_ANS_IGS_ITEMBUY;
#pragma pack()