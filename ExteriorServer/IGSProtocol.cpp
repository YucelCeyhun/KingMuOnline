#include "stdafx.h"
#include "IGSProtocol.h"
#include "LogProc.h"
#include "winutil.h"
#include "readscript.h"

using namespace std;

ISS_ITEM	iss_ItemList[MAX_ITEM_CATEGORY * MAX_CATEGORY] = {}; //Max Item count per category * Number of categories;
BOOL		shopLoaded = FALSE;

void IGSServerInit()
{
	CHAR szInGameShopFilePath[MAX_PATH] = {};
	GetPrivateProfileString("MISC", "InGameShopFilePath", ".\\CashShopList.txt", szInGameShopFilePath, MAX_PATH, nConfig);

	if(GetPrivateProfileInt("ExteriorServer","UseShopServer",1,nConfig) != TRUE)
	{
		return;
	}
	else if (GetPrivateProfileInt("ExteriorServer","UseShopServer",1,nConfig) ==TRUE && CreateGIocp(g_CashShopServerListPort,ST_SHOPSERVER) == TRUE)
	{
		ISSLoadFile(szInGameShopFilePath);
		LogAddTD("[IOCP] SHOPSERVER Start! PORT [ %d ]", g_CashShopServerListPort);
	}

	if ( g_MuOnlineDB.Connect(g_MuOnlineDNS, g_UserID, g_Password) == TRUE )
	{
		LogAddC(4, "[ShopServer] Connection Successfull!");
	}
	else
	{
		LogAddC(2, "[ShopServer] Error On Connection!");
	}

}

void ISSLoadFile(char* file)
{
	//First lets invalidade all items;
	for (int i = 0; i < MAX_ITEM_CATEGORY * MAX_CATEGORY; i++)
	{
		iss_ItemList[i].btItemGroup = 0xFF; //Since there is no group 0xFF, we can use it to see if this ISS_ITEM is valid;
	}

	shopLoaded = FALSE;

	SMDToken Token;

	//Open file
	SMDFile = fopen(file, "r");

	if (SMDFile == NULL) //If there is a failure on opening that file, lets cancel the operation and raise an error.
	{
		LogAddC(2,"[IngameShopServer] Failed to load file: %s", file);
		return;
	}

	int itemCount = 0; //Just a logging information.
	int category = -1;

	while(true)
	{
		Token = GetToken();

		if (Token == END) //If we had reached at the end of file, lets break this loop;
			break;

		if (Token != NUMBER) //We are expecting a categoryID, but if this isnt the frist thing there, we got a problem or a warning.
		{
			LogAddC(2,"[IngameShopServer] Unexpected token on file: %s"); //We dont need to brak, just print this warning and skip it.
		}
		else
		{
			category = TokenNumber; //Get current token as Int, which may be our categoryID.

			if (category >= MAX_CATEGORY) //If this category is valid
			{
				LogAddC(2,"[IngameShopServer] Max category reached (%d). Skipping category %d", MAX_CATEGORY, category);
				break;
			}

			int itemIndex = category * MAX_ITEM_CATEGORY; //To avoid using a multidimessional array, we do this trick.

			while (true) //Now we are inside a category, so lets read all items info inside it.
			{
				Token = GetToken();

				//If current itemIndex overflow our buffer, we need to break this category reading and go to next one.
				if (itemIndex >= (category+1) * MAX_ITEM_CATEGORY)
				{
					LogAddC(2,"[IngameShopServer] Max item count per category reached (%d). Skipping item %d on category %d", MAX_CATEGORY, itemIndex-(category * MAX_ITEM_CATEGORY), category);
					break;
				}

				 //If we reached at end of file or we got the "end" string, the category have ended.
				if (Token == END || (Token == NAME && strcmp("end", TokenString) == 0))
					break;

				//If current token isnt the EOF nor the "end" string nor a NUMBER, we dont need it. Just skip.
				if (Token != NUMBER)
					continue;

				//Now lets read our item info.
				iss_ItemList[itemIndex].btItemGroup			= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemID			= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemLevel			= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemSkill			= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemLuck			= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemOpt			= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemExcOpt		= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemAnc			= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemAncAdd		= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemSock[0]		= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemSock[1]		= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemSock[2]		= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemSock[3]		= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemSock[4]		= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemDur			= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].wItemPrice			= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].btItemSpecialOpt	= TokenNumber; Token = GetToken();
				iss_ItemList[itemIndex].dwItemDuration		= TokenNumber;

				//Ansure Ancient Add is correct. Values are 4 or 8.
				iss_ItemList[itemIndex].btItemAncAdd = iss_ItemList[itemIndex].btItemAncAdd & 0x0F;
				if (iss_ItemList[itemIndex].btItemAncAdd > 0) //So we should have something
				{
					//Lets check if the info is located on two first bits (1100)
					if ((iss_ItemList[itemIndex].btItemAncAdd & 0x0C) == 0) //if isnt
					{
						//Lets convert. They should be on 3rd and 4th bits (0000 1100)
						iss_ItemList[itemIndex].btItemAncAdd = iss_ItemList[itemIndex].btItemAncAdd << 2;
					}
					else
					{
						//The info is on right place, lets cut the unwanted bits;
						iss_ItemList[itemIndex].btItemAncAdd &= 0x0C; //(0000 1100)
					}
					//If add is 8 (000 1000) then it should be it else it'll be 4 (0000 0100)
					iss_ItemList[itemIndex].btItemAncAdd = (iss_ItemList[itemIndex].btItemAncAdd != 8) ? 4 : 8;
				}
				//The last item info is itemPrice, so lets go to next item.
				itemIndex++;

				itemCount++; //Lets increase also the itemCount to be logged on sucessfull event.
			}
		}
	}

	fclose(SMDFile);

	shopLoaded = TRUE;

	//Everything seems to be fine.
	LogAddC(4,"[IngameShop Server] Loaded %d items from file %s", itemCount, file);
}

void ISSReloadFile()
{
	memset(iss_ItemList, 0, MAX_ITEM_CATEGORY * MAX_CATEGORY);

	CHAR szInGameShopFilePath[MAX_PATH] = {};

	GetPrivateProfileString("MISC", "InGameShopFilePath", ".\\CashShopList.txt", szInGameShopFilePath, MAX_PATH, nConfig);

	ISSLoadFile(szInGameShopFilePath);
}


void IGSProtocolCore(int aIndex, BYTE HeadCode, LPBYTE aRecv, int iSize)
{
#if (TRACE_PACKET == 1 )
	LogAddHeadHex("CASHSHOP_SERVER", aRecv, iSize);
#endif
	g_Displayer.CheckIGSConnection(TRUE);
	switch (HeadCode)
	{
	case eMSG_REQ_IGS_GETPOINTS:
		{
			ISSGetPoints(aIndex, (LPMSG_REQ_ISS_GETPOINTS) aRecv);
			break;
		}
	case eMSG_REQ_IGS_ITEMLIST:
		{
			ISSGetItemList(aIndex, (LPMSG_REQ_ISS_ITEMLIST) aRecv);
			break;
		}
	case eMSG_REQ_IGS_ITEMBUY:
		{
			ISSBuyItem(aIndex, (LPMSG_REQ_ISS_ITEMBUY) aRecv);
			break;
		}
	case eMSG_REQ_ISS_ADDPOINTS:
		{
			ISSAddPoints(aIndex, (LPMSG_REQ_ISS_ADDPOINTS) aRecv);
			break;
		}
	}
	g_Displayer.CheckIGSConnection(FALSE);
}

void ISSGetPoints(int aIndex, LPMSG_REQ_ISS_GETPOINTS pMsg)
{
	MSG_ANS_ISS_GETPOINTS pResult = {};
	pResult.dwIndex = pMsg->dwIndex;

	//if(g_DBConnection.Query("SELECT IGSPoints FROM dbo.MEMB_INFO WHERE memb_guid = %d", &dbResultSet, pMsg->dwUserGuid))
	if(g_MuOnlineDB.ExecQuery("SELECT cspoints FROM MEMB_INFO WHERE memb_guid = %d", pMsg->dwUserGuid) == TRUE && g_MuOnlineDB.Fetch() != SQL_NO_DATA)
	{
		pResult.dwIGSPoints = g_MuOnlineDB.GetAsInteger("cspoints");
	}
	else
	{
		LogAddC(2,"[IngameShopServer] Failed to get CashPoints");
	}
	g_MuOnlineDB.Close();

	pResult.head.set((LPBYTE)&pResult, eMSG_ANS_IGS_GETPOINTS, sizeof(MSG_ANS_ISS_GETPOINTS));
	DataSend(aIndex, (LPBYTE)&pResult, pResult.head.size);
}

void ISSGetItemList(int aIndex, LPMSG_REQ_ISS_ITEMLIST pMsg)
{
	MSG_ANS_ISS_ITEMLIST pResult = {};

	//Copy received data to send back this message;
	pResult.dwIndex = pMsg->dwIndex;
	pResult.btCategoryID = pMsg->btCategoryID;
	pResult.btPageIndex = pMsg->btPageIndex;
	
	if (shopLoaded) //If InGameShop Server sucessfull loaded file;
	{
		//Lets get current itemIndex on item list array;
		int itemIndex = (pResult.btCategoryID * MAX_ITEM_CATEGORY) + (pResult.btPageIndex * MAX_PAGE_ITEM_COUNT);

		//Now lets iterate over it and get item information
		for (int i = itemIndex; i < itemIndex + MAX_PAGE_ITEM_COUNT; i++)
		{
			LPISS_ITEM issItem = &iss_ItemList[i]; //Get item information according to current index;
			LPMSG_ANS_IGS_ITEM_UNIT unitItemInfo = &pResult.ItemInfo[pResult.btItemCount];

			if (i >= ((pResult.btCategoryID+1) * MAX_ITEM_CATEGORY)) //If current item index overflow max item per category.
				break;
			
			if (issItem->btItemGroup == 0xFF) //If item is invalid;
				break;

			unitItemInfo->dwItemGuid = i+1; //Item GUID cannot be 0.
			unitItemInfo->btCategoryID = pResult.btCategoryID;

			ISSItemToItemUnit(issItem, unitItemInfo); //Helper function which converts one to another;

			pResult.btItemCount++; //Lets increase the current item count;
		}
	}

	pResult.head.set((LPBYTE) &pResult, eMSG_ANS_IGS_ITEMLIST, sizeof(MSG_ANS_ISS_ITEMLIST));

	DataSend(aIndex, (LPBYTE) &pResult, pResult.head.size);
}

void ISSBuyItem(int aIndex, LPMSG_REQ_ISS_ITEMBUY pMsg)
{
	BYTE btResult = 0;
	LPISS_ITEM issItem = NULL;

	if (!shopLoaded)
	{
		btResult = 6; //Ingame Shop Server is in a loading process;
	}
	#pragma warning(disable:4018)
	else if (pMsg->btCategoryID < 0 || pMsg->btCategoryID > MAX_CATEGORY || ////If categoryID is invalid  or out of range
		pMsg->dwItemGuid >= (pMsg->btCategoryID+1) * MAX_ITEM_CATEGORY || pMsg->dwItemGuid < (pMsg->btCategoryID-1) * MAX_ITEM_CATEGORY)  //Or item GUID doesnt belong to this category
	{
		btResult = 3; //Invalid item;
	}
	else
	{
		issItem = &iss_ItemList[pMsg->dwItemGuid-1]; //Remever, itemGuid is ItemIndex +1;

		if (issItem == NULL || issItem->btItemGroup == 0xFF) //If item doesnt exists or slot item isnt loaded (which menas a Empoty Slot);
		{
			btResult = 3; //Invalid item;
		}
		//else if(g_DBConnection.Query("SELECT IGSPoints FROM dbo.MEMB_INFO WHERE memb_guid = %d", &dbResultSet, pMsg->dwUserGuid))
		else if(g_MuOnlineDB.ExecQuery("SELECT cspoints FROM MEMB_INFO WHERE memb_guid = %d",pMsg->dwUserGuid) == TRUE && g_MuOnlineDB.Fetch() != SQL_NO_DATA)
		{
			//int IGSPoints = dbResultSet.GetAsInteger("IGSPoints");
			int IGSPoints = g_MuOnlineDB.GetAsInteger("cspoints");
			g_MuOnlineDB.Close();

			IGSPoints = (IGSPoints < 0) ? 0 : IGSPoints; //If for some reason the IGSPoints is negative, lets set it to 0.

			if (issItem->wItemPrice > IGSPoints) btResult = 1; //TODO: Check if result 1 is really insufience balance;
		}
		else 
		{
			btResult = 9; //General error result.
		}

	}

	//Now lets setup the answer message;
	MSG_ANS_ISS_ITEMBUY pResult = {};

	pResult.dwIndex = pMsg->dwIndex;
	pResult.btResult = btResult;

	if (pResult.btResult == 0) //If everything was fine.
	{
		LPMSG_ANS_IGS_ITEM_UNIT unitItemInfo = &pResult.ItemInfo; //Get item info

		unitItemInfo->btCategoryID = pMsg->btCategoryID;
		unitItemInfo->dwItemGuid = pMsg->dwItemGuid;

		ISSItemToItemUnit(issItem, unitItemInfo); //And fill its information

	}

	pResult.head.set((LPBYTE) &pResult, eMSG_ANS_IGS_ITEMBUY, sizeof(MSG_ANS_ISS_ITEMBUY));

	//Send information back to GAMESERVER
	DataSend(aIndex, (LPBYTE) &pResult, pResult.head.size);
}

void ISSAddPoints(int aIndex, LPMSG_REQ_ISS_ADDPOINTS pMsg)
{
	//if (g_DBConnection.Exec("UPDATE dbo.MEMB_INFO SET IGSPoints = IGSPoints+(%d) WHERE memb_guid = %d", pMsg->dwAddIGSPoints, pMsg->dwUserGuid))
	if(g_MuOnlineDB.ExecQuery("UPDATE MEMB_INFO SET cspoints = cspoints+(%d) WHERE memb_guid = %d",pMsg->dwAddIGSPoints, pMsg->dwUserGuid)/* == TRUE && g_MuOnlineDB.Fetch() != SQL_NO_DATA*/)
	{
		g_MuOnlineDB.Close();
		MSG_REQ_ISS_GETPOINTS pResult = {};

		pResult.dwIndex = pMsg->dwIndex;
		pResult.dwUserGuid = pMsg->dwUserGuid;

		pResult.head.set((LPBYTE) &pResult, eMSG_REQ_IGS_GETPOINTS, sizeof(LPMSG_REQ_ISS_GETPOINTS));
		ISSGetPoints(aIndex, &pResult);
	}
	else
	{
		LogAddC(2,"[IngameShopServer] Failed to add %d CashPoints on account guid %d", pMsg->dwAddIGSPoints, pMsg->dwUserGuid);
	}
}

void ISSItemToItemUnit(LPISS_ITEM issItem, LPMSG_ANS_IGS_ITEM_UNIT unitItemInfo)
{
	if (issItem == NULL || unitItemInfo == NULL) return;

	unitItemInfo->btItemDur = issItem->btItemDur; //TODO: Check what is this value, maybe quantity?
	unitItemInfo->btItemSaleRatio = 100; //TODO: Check what is this value
	unitItemInfo->wItemPrice = issItem->wItemPrice;
	unitItemInfo->btSpecialOption = issItem->btItemSpecialOpt;

	//This function will convert the item info on ISS_ITEM to a 12 bytes array to be sent back to GAMESERVER.
	ItemByteConvert(unitItemInfo->arItemInfo, ITEMGET(issItem->btItemGroup, issItem->btItemID), issItem->btItemSkill, 
					issItem->btItemLuck, issItem->btItemOpt, issItem->btItemLevel, issItem->btItemDur, issItem->btItemExcOpt,
					issItem->btItemAnc+issItem->btItemAncAdd, 0, 0, issItem->btItemSock, 0);

	unitItemInfo->dwItemUsePeriod = issItem->dwItemDuration; //TODO: Add this config on file.
}

void ItemByteConvert(LPBYTE buf, int type, BYTE Option1, BYTE Option2, BYTE Option3, BYTE level, BYTE dur, BYTE Noption, BYTE SetOption, BYTE JewelOfHarmonyOption, BYTE ItemEffectEx, BYTE SocketOption[5], BYTE SocketIndex)
{
	memset(buf, 0, MAX_ITEM_INFO);
	int n = 0;

	buf[n] = type & 0xFF;
	n++;
	buf[n] = 0;
	buf[n] |= level * 8;
	buf[n] |= Option1 * 128;
	buf[n] |= Option2 * 4;
	buf[n] |= Option3 & 3;
	n++;
	buf[n] = dur;
	n++;
	buf[n] = 0;
	buf[n] |= ((type& 0x100) >> 1);

	if ( Option3 > 3 )
	{
		buf[n] |= 0x40;
	}

	buf[n] |= Noption;
	n++;
	buf[n] = SetOption;
	n++;
	buf[n] |= (type & 0x1E00 ) >> 5;

	BYTE btItemEffectFor380 = 0;
	btItemEffectFor380 = (ItemEffectEx  & 0x80 ) >> 4;
	buf[n] |= btItemEffectFor380;
	n++;
	buf[n] = JewelOfHarmonyOption;

	//Season4 add-on (wz bugged -.-)
	if(SocketOption != NULL)
	{
		buf[n] = SocketIndex;
		n++;
		buf[n] = SocketOption[0];
		n++;
		buf[n] = SocketOption[1];
		n++;
		buf[n] = SocketOption[2];
		n++;
		buf[n] = SocketOption[3];
		n++;
		buf[n] = SocketOption[4];
	}
	else
	{
		n++; //wz fixed here -.-
		buf[n] = 0xFF;
		n++;
		buf[n] = 0xFF;
		n++;
		buf[n] = 0xFF;
		n++;
		buf[n] = 0xFF;
		n++;
		buf[n] = 0xFF;
	}
}