#include "Stdafx.h"
#include "User.h"
#include "Configs.h"
#include "Commands.h"
#include "DSProtocol.h"
#include "ObjCalCharacter.h"
#include "DBSockMng.h"
#include "LogProc.h"
#include "Utilities.h"
//#include "HttpRequest.h";
CCommands Commands;

void CCommands::SendPost(int aIndex, LPCSTR Message)
{	
	LPOBJ lpObj = &gObj[aIndex];
	
	if(g_Configs.PostEnable != 1) return;

	char Buff[255];
	if(lpObj->Level < g_Configs.PostLevel)
	{
		sprintf_s(Buff,"You must have %d Level to use this command",g_Configs.PostLevel);
		GCServerMsgStringSend(Buff,aIndex,1);
		return;
	}

	if(lpObj->Money < g_Configs.PostCost)
	{
		sprintf_s(Buff,"You must have %d of Zen to use this command",g_Configs.PostCost);
		GCServerMsgStringSend(Buff,aIndex,1);
		return;
	}

	//Create new Msg
	char CMessage[100];

	//Create Packet!
	PMSG_CHATDATA pMsg;

	pMsg.h.set((LPBYTE)&pMsg,0x00,sizeof(pMsg));

	memset(&pMsg.chatid,0,sizeof(pMsg.chatid));
	memset(&pMsg.chatmsg,0,sizeof(pMsg.chatmsg));
	
	sprintf_s(CMessage,"[POST] %s: %s",lpObj->Name,Message); //Normal

	if(g_Configs.PostColor == 0) //Golden
	{
		pMsg.h.headcode = 0x02;
	}
	else if(g_Configs.PostColor == 1) //Blue
	{
		sprintf(CMessage,"~[POST] %s: %s",lpObj->Name,Message);
	}
	else if(g_Configs.PostColor == 2) //Green
	{
		sprintf(CMessage,"@[POST] %s: %s",lpObj->Name,Message);
	}
	else if(g_Configs.PostColor == 3) //Yellow
	{
		sprintf(CMessage,"@@[POST] %s: %s",lpObj->Name,Message);
	}
	
	memcpy(&pMsg.chatmsg,CMessage,strlen(CMessage));
	pMsg.h.size = (strlen(CMessage)+ 0x13);

	DataSendAll((LPBYTE)&pMsg,pMsg.h.size);

	lpObj->Money -= g_Configs.PostCost;
	GCMoneySend(aIndex,lpObj->Money);
}


/*void CCommands::DropItem(int aIndex, LPCSTR Message) // -> Old Drop Command (Backup)
{
	LPOBJ lpObj = &gObj[aIndex];

	if(g_Configs.DropEnable != 1) return;
	if(lpObj->Authority != 32) return;

	int iIndex=0,iID=0,iLevel=0,iLuck=0,iSkill=0,iOpt=0,iDur=0,iExe=0,iAcc=0;
	
	sscanf(Message," %d %d %d %d %d %d %d %d %d",&iIndex,&iID,&iLevel,&iDur,&iLuck,&iSkill,&iOpt,&iExe,&iAcc);
	ItemSerialCreateSend(aIndex,lpObj->MapNumber,lpObj->X,lpObj->Y,((iIndex*512)+iID),iLevel,iDur,iSkill,iLuck,iOpt,aIndex,iExe,iAcc);
	LogAddTD("[GameMaster][%s][%s] Item Drop [%d,%d,%d,%d,%d,%d,%d,%d,%d]",lpObj->AccountID,lpObj->Name,iIndex,iID,iLevel,iDur,iLuck,iSkill,iOpt,iExe,iAcc);
	GCServerMsgStringSend("[Drop] Item Created with Successfull!",aIndex,1);
}*/

void CCommands::MakeItem(int aIndex,LPCSTR Message)
{
	LPOBJ lpObj = &gObj[aIndex];
	// ----
	if(g_Configs.MakeEnable !=1) return;
	if(lpObj->Authority != 32) return;
	// ----
	int iCount=0,iType=0,iIndex=0,iLevel=0;
	// ----
	sscanf(Message," %d %d %d %d",&iCount,&iType,&iIndex,&iLevel);
	// ----
	if((iCount < 0) || (iCount > 20))
	{
		iCount = 1;
	}
	// ----
	if(iIndex < 0 || (iType < 12 || iType > 15) || (iLevel < 0 || iLevel > 15))
	{
		GCServerMsgStringSend("[Make] Usage: /make <Count> <Type> <Id> <Lvl>",aIndex,1);
	}
	else
	{
		int iEmptyCount=0;
		// ----
		for(int x = 0; x<(MAIN_INVENTORY_SIZE - INVETORY_WEAR_SIZE); x++)
		{
			if(gObj[aIndex].pInventoryMap[x] == 0xFF)
			{
				iEmptyCount++;
			}
		}
		// ----
		if(iEmptyCount < iCount)
		{
			LogAddTD("[Make][%s][%s] Is lacking inventory empty space: %d/%d",lpObj->AccountID,lpObj->Name,iEmptyCount,iCount);
			GCServerMsgStringSend("[Make] You don't have sufficient free space.",aIndex,1);
			return;
		}
		// ----
		for(int i = 0; i < iCount; i++)
		{
			ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,((iType*512)+iIndex),iLevel,0,0,0,0,aIndex,0,0);
		}
		// ----
		LogAddTD("[GameMaster][%s][%s](%d) Make Item [%d,%d,%d]",lpObj->AccountID,lpObj->Name,iCount,iType,iIndex,iLevel);
		// ----
		if(iCount == 1)
		{
			GCServerMsgStringSend("[Make] Item Created with successfully.",aIndex,1);
		}
		else
		{
			GCServerMsgStringSend("[Make] Items Created with successfully.",aIndex,1);
		}
	}
}

void CCommands::DropItem(int aIndex,LPCSTR Message)
{
	LPOBJ lpObj = &gObj[aIndex];
	// ----
	if(g_Configs.DropEnable != 1) return;
	if(lpObj->Authority != 32) return;
	// ----
	int iCount=0,iIndex=0,iID=0,iLevel=0,iLuck=0,iSkill=0,iOpt=0,iDur=0,iExe=0,iAcc=0;
	// ----
	sscanf(Message," %d %d %d %d %d %d %d %d %d %d",&iCount,&iIndex,&iID,&iLevel,&iDur,&iLuck,&iSkill,&iOpt,&iExe,&iAcc);
	// ----
	if((iCount < 0) || (iCount > 20))
	{
		iCount = 1;
	}
	// ----
	if(iID < 0 || (iIndex < 0 || iIndex > 15) || (iLevel < 0 || iLevel > 15) || (iOpt < 0 || iOpt > 7) || (iLuck < 0 || iLuck > 1) || (iSkill < 0 || iSkill > 1) || (iExe < 0 || iExe > 63) || (iAcc < 0 || iAcc > 40))
	{
		GCServerMsgStringSend("[Drop] Usage: /drop <Count> <Type> <Id> <Lvl> <Dur> <Skill> <Luck> <Opt> <Exc> <Anc>",aIndex,1);
	}
	else if((iDur < 0 || iDur > 255))
	{
		GCServerMsgStringSend("[Drop] Usage: If you don't know specific <Dur> value, can be: (255) on: 5th Position",aIndex,1);
	}
	else
	{
		for(int i = 0; i < iCount; i++)
		{
			ItemSerialCreateSend(aIndex,lpObj->MapNumber,lpObj->X,lpObj->Y,((iIndex*512)+iID),iLevel,iDur,iSkill,iLuck,iOpt,aIndex,iExe,iAcc);
		}
		// ----
		LogAddTD("[GameMaster][%s][%s] (%d) Item Drop [%d,%d,%d,%d,%d,%d,%d,%d,%d]",lpObj->AccountID,lpObj->Name,iCount,iIndex,iID,iLevel,iDur,iLuck,iSkill,iOpt,iExe,iAcc);
		// ----
		if(iCount == 1)
		{
			GCServerMsgStringSend("[Drop] Item Created with successfully.",aIndex,1);
		}
		else
		{
			GCServerMsgStringSend("[Drop] Items Created with successfully.",aIndex,1);
		}
	}
}

void CCommands::ClearInven(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if(g_Configs.ClearEnable !=1) return;
	if(lpObj->Authority != 32) return;

	int ItemCount = 0;

	for (int i = INVETORY_WEAR_SIZE; i < MAIN_INVENTORY_SIZE; i++)
	{
		if (lpObj->pInventory[i].IsItem() == 1)
		{
			gObjInventoryDeleteItem(lpObj->m_Index, i);
			ItemCount++;
		}
	}

	GCItemListSend(lpObj->m_Index);
	LogAddTD("[ClearInven][%s][%s] Game Master Inventory Deleted",lpObj->AccountID,lpObj->Name);
	GCServerMsgStringSend("[ClearInven] your Inventory has been deleted.",aIndex,1);
}

//15.03.2020
void CCommands::PkClear(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	lpObj->m_PK_Count = 0;
	lpObj->m_PK_Level = 0;
	lpObj->m_PK_Time = 0;

	GCPkLevelSend(aIndex,0);
	LogAddTD("pkclear operation is succeeded for [%s][%S]",lpObj->AccountID,lpObj->Name);
	//GCServerMsgStringSend(httpRequest.getVersion(),aIndex,1);
	//GCServerMsgStringSend("Pk Clear operation is succeeded",aIndex,1);
}

void CCommands::PackLevel(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.PackLevelEnable != 1) return;
	
	if (gObjFind10JewelLevel(aIndex) == TRUE)
	{
		gObjDelete10JewelLevel(aIndex);
		ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(12,150),0,0,0,0,0,aIndex,0,0);
		LogAddTD("[PackSystem][%s][%s] Bundled Jewel of Level Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Package has been made.", aIndex, 1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create Bundled Jewel of Level", lpObj->AccountID, lpObj->Name);
		GCServerMsgStringSend("You don't have correct count of Jewels.", aIndex, 1);
	}
}

void CCommands::PackLevel20(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];
	// ----
	if(g_Configs.PackLevel20Enable!=1) return;
	// ----
	if(gObjFind20JewelLevel(aIndex) == TRUE)
	{
		gObjDelete20JewelLevel(aIndex);
		ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(12,150),1,0,0,0,0,aIndex,0,0);
		LogAddTD("[PackSystem][%s][%s] Bundled Jewel of Level +1 Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Package has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create Bundled Jewel of Level +1",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have correct count of Jewels.",aIndex,1);
	}
}

void CCommands::PackLuck(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.PackLuckEnable != 1) return;

	if (gObjFind10JewelLuck(aIndex) == TRUE)
	{
		gObjDelete10JewelLuck(aIndex);
		ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(12,151),0,0,0,0,0,aIndex,0,0);
		LogAddTD("[PackSystem][%s][%s] Bundled Jewel of Luck Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Package has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create Bundled Jewel of Luck",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have correct count of Jewels.",aIndex,1);
	}
}

void CCommands::PackSkill(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.PackSkillEnable != 1) return;

	if (gObjFind10JewelSkill(aIndex) == TRUE)
	{
		gObjDelete10JewelSkill(aIndex);
		ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(12,152),0,0,0,0,0,aIndex,0,0);
		LogAddTD("[PackSystem][%s][%s] Bundled Jewel of Skill Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Package has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create Bundled Jewel of Skill",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have correct count of Jewels.",aIndex,1);
	}
}

void CCommands::PackOption(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.PackOptionEnable != 1) return;

	if (gObjFind10JewelOption(aIndex) == TRUE)
	{
		gObjDelete10JewelOption(aIndex);
		ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(12,153),0,0,0,0,0,aIndex,0,0);
		LogAddTD("[PackSystem][%s][%s] Bundled Jewel of Option Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Package has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create Bundled Jewel of Option",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have correct count of Jewels.",aIndex,1);
	}
}

void CCommands::PackExcellent(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.PackExcellentEnable != 1) return;

	if (gObjFind10JewelExcellent(aIndex) == TRUE)
	{
		gObjDelete10JewelExcellent(aIndex);
		ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(12,154),0,0,0,0,0,aIndex,0,0);
		LogAddTD("[PackSystem][%s][%s] Bundled Jewel of Excellent Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Package has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create Bundled Jewel of Excellent",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have correct count of Jewels.",aIndex,1);
	}
}

void CCommands::PackAncient(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.PackAncientEnable != 1) return;

	if (gObjFind10JewelAncient(aIndex) == TRUE)
	{
		gObjDelete10JewelAncient(aIndex);
		ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(12,155),0,0,0,0,0,aIndex,0,0);
		LogAddTD("[PackSystem][%s][%s] Bundled Jewel of Ancient Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Package has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create Bundled Jewel of Ancient",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have correct count of Jewels.",aIndex,1);
	}
}

void CCommands::PackSocket(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.PackSocketEnable != 1) return;

	if (gObjFind10JewelSocket(aIndex) == TRUE)
	{
		gObjDelete10JewelSocket(aIndex);
		ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(12,156),0,0,0,0,0,aIndex,0,0);
		LogAddTD("[PackSystem][%s][%s] Bundled Jewel of Socket Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Package has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create Bundled Jewel of Socket",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have correct count of Jewels.",aIndex,1);
	}
}

void CCommands::UnpackLevel(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.UnpackLevelEnable != 1) return;

	if (gObjFindBundledJewelLevel(aIndex) == TRUE)
	{
		int iEmptyCount = 0;
		int iJewelCount = 9;
		// ----
		for (int x = 0; x<(MAIN_INVENTORY_SIZE - INVETORY_WEAR_SIZE); x++)
		{
			if (gObj[aIndex].pInventoryMap[x] == 0xFF)
			{
				iEmptyCount++;
			}
		}
		// ----
		if (iEmptyCount < iJewelCount)
		{
			LogAddTD("[PackSystem] [%s][%s] Lack of Empty Slot to Unpack: %d/%d", lpObj->AccountID, lpObj->Name, iEmptyCount, iJewelCount);
			GCServerMsgStringSend("You don't have sufficient free space.", aIndex, 1);
			return;
		}
		// ----
		gObjDeleteBundledJewelLevel(aIndex);
		// ----
		for (int i = 0; i < 10; i++)
		{
			ItemSerialCreateSend(aIndex, 235, lpObj->X, lpObj->Y, ITEMGET(14, 240), 0, 0, 0, 0, 0, aIndex, 0, 0);
		}
		// ----
		LogAddTD("[PackSystem][%s][%s] (10) Jewel of Level Created", lpObj->AccountID, lpObj->Name);
		GCServerMsgStringSend("Unpackage has been made.", aIndex, 1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create (10) Jewel of Level", lpObj->AccountID, lpObj->Name);
		GCServerMsgStringSend("You don't have a: Bundled Jewel of Level.", aIndex, 1);
	}
}

void CCommands::UnpackLuck(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.UnpackLuckEnable != 1) return;

	if (gObjFindBundledJewelLuck(aIndex) == TRUE)
	{
		int iEmptyCount=0;
		int iJewelCount=9;
		// ----
		for (int x=0;x<(MAIN_INVENTORY_SIZE-INVETORY_WEAR_SIZE);x++)
		{
			if (gObj[aIndex].pInventoryMap[x] == 0xFF)
			{
				iEmptyCount++;
			}
		}
		// ----
		if (iEmptyCount < iJewelCount)
		{
			LogAddTD("[PackSystem] [%s][%s] Lack of Empty Slot to Unpack: %d/%d",lpObj->AccountID,lpObj->Name,iEmptyCount,iJewelCount);
			GCServerMsgStringSend("You don't have sufficient free space.",aIndex,1);
			return;
		}
		// ----
		gObjDeleteBundledJewelLuck(aIndex);
		// ----
		for (int i = 0; i < 10; i++)
		{
			ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(14,241),0,0,0,0,0,aIndex,0,0);
		}
		// ----
		LogAddTD("[PackSystem][%s][%s] (10) Jewel of Luck Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Unpackage has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create (10) Jewel of Luck",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have a: Bundled Jewel of Luck.",aIndex,1);
	}
}

void CCommands::UnpackSkill(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.UnpackSkillEnable != 1) return;

	if (gObjFindBundledJewelSkill(aIndex) == TRUE)
	{
		int iEmptyCount=0;
		int iJewelCount=9;
		// ----
		for (int x=0;x<(MAIN_INVENTORY_SIZE-INVETORY_WEAR_SIZE);x++)
		{
			if (gObj[aIndex].pInventoryMap[x] == 0xFF)
			{
				iEmptyCount++;
			}
		}
		// ----
		if (iEmptyCount < iJewelCount)
		{
			LogAddTD("[PackSystem] [%s][%s] Lack of Empty Slot to Unpack: %d/%d",lpObj->AccountID,lpObj->Name,iEmptyCount,iJewelCount);
			GCServerMsgStringSend("You don't have sufficient free space.",aIndex,1);
			return;
		}
		// ----
		gObjDeleteBundledJewelSkill(aIndex);
		// ----
		for (int i = 0; i < 10; i++)
		{
			ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(14,242),0,0,0,0,0,aIndex,0,0);
		}
		// ----
		LogAddTD("[PackSystem][%s][%s] (10) Jewel of Skill Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Unpackage has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create (10) Jewel of Skill",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have a: Bundled Jewel of Skill.",aIndex,1);
	}
}

void CCommands::UnpackOption(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.UnpackOptionEnable != 1) return;

	if (gObjFindBundledJewelOption(aIndex) == TRUE)
	{
		int iEmptyCount=0;
		int iJewelCount=9;
		// ----
		for (int x=0;x<(MAIN_INVENTORY_SIZE-INVETORY_WEAR_SIZE);x++)
		{
			if (gObj[aIndex].pInventoryMap[x] == 0xFF)
			{
				iEmptyCount++;
			}
		}
		// ----
		if (iEmptyCount < iJewelCount)
		{
			LogAddTD("[PackSystem] [%s][%s] Lack of Empty Slot to Unpack: %d/%d",lpObj->AccountID,lpObj->Name,iEmptyCount,iJewelCount);
			GCServerMsgStringSend("You don't have sufficient free space.",aIndex,1);
			return;
		}
		// ----
		gObjDeleteBundledJewelOption(aIndex);
		// ----
		for (int i = 0; i < 10; i++)
		{
			ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(14,243),0,0,0,0,0,aIndex,0,0);
		}
		// ----
		LogAddTD("[PackSystem][%s][%s] (10) Jewel of Option Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Unpackage has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create (10) Jewel of Option",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have a: Bundled Jewel of Option.",aIndex,1);
	}
}

void CCommands::UnpackExcellent(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.UnpackExcellentEnable != 1) return;

	if (gObjFindBundledJewelExcellent(aIndex) == TRUE)
	{
		int iEmptyCount=0;
		int iJewelCount=9;
		// ----
		for (int x=0;x<(MAIN_INVENTORY_SIZE-INVETORY_WEAR_SIZE);x++)
		{
			if (gObj[aIndex].pInventoryMap[x] == 0xFF)
			{
				iEmptyCount++;
			}
		}
		// ----
		if (iEmptyCount < iJewelCount)
		{
			LogAddTD("[PackSystem] [%s][%s] Lack of Empty Slot to Unpack: %d/%d",lpObj->AccountID,lpObj->Name,iEmptyCount,iJewelCount);
			GCServerMsgStringSend("You don't have sufficient free space.",aIndex,1);
			return;
		}
		// ----
		gObjDeleteBundledJewelExcellent(aIndex);
		// ----
		for (int i = 0; i < 10; i++)
		{
			ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(14,244),0,0,0,0,0,aIndex,0,0);
		}
		// ----
		LogAddTD("[PackSystem][%s][%s] (10) Jewel of Excellent Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Unpackage has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create (10) Jewel of Excellent",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have a: Bundled Jewel of Excellent.",aIndex,1);
	}
}

void CCommands::UnpackAncient(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.UnpackAncientEnable != 1) return;

	if (gObjFindBundledJewelAncient(aIndex) == TRUE)
	{
		int iEmptyCount=0;
		int iJewelCount=9;
		// ----
		for (int x=0;x<(MAIN_INVENTORY_SIZE-INVETORY_WEAR_SIZE);x++)
		{
			if (gObj[aIndex].pInventoryMap[x] == 0xFF)
			{
				iEmptyCount++;
			}
		}
		// ----
		if (iEmptyCount < iJewelCount)
		{
			LogAddTD("[PackSystem] [%s][%s] Lack of Empty Slot to Unpack: %d/%d",lpObj->AccountID,lpObj->Name,iEmptyCount,iJewelCount);
			GCServerMsgStringSend("You don't have sufficient free space.",aIndex,1);
			return;
		}
		// ----
		gObjDeleteBundledJewelAncient(aIndex);
		// ----
		for (int i = 0; i < 10; i++)
		{
			ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(14,245),0,0,0,0,0,aIndex,0,0);
		}
		// ----
		LogAddTD("[PackSystem][%s][%s] (10) Jewel of Ancient Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Unpackage has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create (10) Jewel of Ancient",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have a: Bundled Jewel of Ancient.",aIndex,1);
	}
}

void CCommands::UnpackSocket(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (g_Configs.UnpackSocketEnable != 1) return;

	if (gObjFindBundledJewelSocket(aIndex) == TRUE)
	{
		int iEmptyCount=0;
		int iJewelCount=9;
		// ----
		for (int x=0;x<(MAIN_INVENTORY_SIZE-INVETORY_WEAR_SIZE);x++)
		{
			if (gObj[aIndex].pInventoryMap[x] == 0xFF)
			{
				iEmptyCount++;
			}
		}
		// ----
		if (iEmptyCount < iJewelCount)
		{
			LogAddTD("[PackSystem] [%s][%s] Lack of Empty Slot to Unpack: %d/%d",lpObj->AccountID,lpObj->Name,iEmptyCount,iJewelCount);
			GCServerMsgStringSend("You don't have sufficient free space.",aIndex,1);
			return;
		}
		// ----
		gObjDeleteBundledJewelSocket(aIndex);
		// ----
		for (int i = 0; i < 10; i++)
		{
			ItemSerialCreateSend(aIndex,235,lpObj->X,lpObj->Y,ITEMGET(14,246),0,0,0,0,0,aIndex,0,0);
		}
		// ----
		LogAddTD("[PackSystem][%s][%s] (10) Jewel of Socket Created",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("Unpackage has been made.",aIndex,1);
	}
	else
	{
		LogAddTD("[PackSystem][%s][%s] Fail trying to Create (10) Jewel of Socket",lpObj->AccountID,lpObj->Name);
		GCServerMsgStringSend("You don't have a: Bundled Jewel of Socket.",aIndex,1);
	}
}

void CCommands::AddStats(int aIndex, LPCSTR AddPoints, DWORD Type)
{
	char Message[255];

	int Points = atoi(AddPoints);
	if(Points < 1) return;

	LPOBJ lpObj = &gObj[aIndex];
	
	if(g_Configs.AddStatsEnable == 0) return;
	
	if(Points > g_Configs.AddStatsMaxPoints)
	{
		sprintf(Message,"You can add %d point(s)",g_Configs.AddStatsMaxPoints);
		GCServerMsgStringSend(Message,aIndex,1);
		return;
	}

	if(g_Configs.AddStatsLevel > lpObj->Level)
	{
		sprintf(Message,"You must be %d level to use this command",g_Configs.AddStatsLevel);
		GCServerMsgStringSend(Message,aIndex,1);
		return;
	}

	if(g_Configs.AddStatsCost > lpObj->Money)
	{
		sprintf(Message,"You need %d of Zen to use this command",g_Configs.AddStatsCost);
		GCServerMsgStringSend(Message,aIndex,1);
		return;
	}

	if(Type == 4 && lpObj->DbClass != 64 && lpObj->DbClass != 66)
	{
		GCServerMsgStringSend("Command is only to DarkLord",aIndex,1);
		return;
	}

	if(lpObj->LevelUpPoint < Points)
	{
		GCServerMsgStringSend("Don't have you sufficient points",aIndex,1);
		return;
	}

	if(checkMaxStat((BYTE)Type,lpObj,Points) == false)
	{
		sprintf(Message,"Maximum stats %d",MAX_STATS);
		GCServerMsgStringSend(Message,aIndex,1);
		return;
	}

	lpObj->Money -= g_Configs.AddStatsCost;
	GCMoneySend(aIndex,lpObj->Money);
	
	switch(Type)
	{
		case 3:
			lpObj->Strength += Points;
		break;
		case 2:
			lpObj->Dexterity += Points;
		break;
		case 1:
			lpObj->Vitality += Points;
			lpObj->MaxLife += lpObj->VitalityToLife * Points;
			GCReFillSend(lpObj->m_Index,lpObj->MaxLife + lpObj->AddLife,0xFE,0,lpObj->iMaxShield+lpObj->iAddShield);
		break;
		case 0:
			lpObj->Energy += Points;
			lpObj->MaxMana += lpObj->EnergyToMana * Points;
			gObjSetBP(lpObj->m_Index);
			GCManaSend(lpObj->m_Index,lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP);
		break;
		case 4:
			lpObj->Leadership += Points;
		break;
	}
	// ----
	BYTE PMSG_USE_STAT_FRUIT[8] = { 0xC1,0x08,0x2C,0x00,0x01,0x00,0x03,0x00 };
	PMSG_USE_STAT_FRUIT[4] = LOBYTE(Points);
	PMSG_USE_STAT_FRUIT[5] = HIBYTE(Points);
	PMSG_USE_STAT_FRUIT[6] = (BYTE)Type;
	DataSend(aIndex,(unsigned char*)PMSG_USE_STAT_FRUIT,8);
	// ----
	lpObj->LevelUpPoint -= Points;
	GCLevelUpMsgSend(lpObj->m_Index,1);
	// ----
	gObjCalCharacter(aIndex);
	// ----
	sprintf(Message,"%d Added points!",Points);
	GCServerMsgStringSend(Message,aIndex,1);
	sprintf(Message,"Already have you %d Points",lpObj->LevelUpPoint);
	GCServerMsgStringSend(Message,aIndex,1);
}

void CCommands::ServerInfo(int aIndex)
{
	char Temp[255];
	GCServerMsgStringSend("Engine Ex406 Emulator Project",aIndex,0);
	GCServerMsgStringSend("Developed by Nemesis",aIndex,0);
	wsprintf(Temp,"Special Thanks: Deathway, eRRoR, HermeX, Crazzy");
	GCServerMsgStringSend(Temp,aIndex,0);
}

void CCommands::SkinCommand(int aIndex,LPCSTR Message)
{
	LPOBJ lpObj = &gObj[aIndex];
	// ----
	if(g_Configs.SkinEnable!=1) return;
	if(lpObj->Authority!=32) return;
	// ----
	int iNumSkin=0;
	// ----
	sscanf(Message,"%d",&iNumSkin);
	// ----
	lpObj->m_Change = iNumSkin;
	gObjViewportListProtocolCreate(lpObj);
	// ----
	GCServerMsgStringSend("[SetSkin] Your skin was changed with successfully.",aIndex,1);
}

void CCommands::SetZenCommand(int aIndex,LPCSTR Message)
{
	LPOBJ lpObj = &gObj[aIndex];
	// ----
	if(g_Configs.SetZenEnable!=1) return;
	if(lpObj->Authority!=32) return;
	// ----
	DWORD Zen=0;
	// ----
	sscanf(Message,"%d",&Zen);
	// ----
	if(Zen < 0 || Zen > 2000000000)
	{
		GCServerMsgStringSend("[SetZen] Your Zen count cannot be less than: 0 or more than: 2000000000",aIndex,1);
	}
	else
	{
		lpObj->Money=Zen;
		GCMoneySend(lpObj->m_Index,Zen);
		GCServerMsgStringSend("[SetZen] Your Zen was changed with successfully.",aIndex,1);
	}
}

/*void CCommands::ChangeVault(int aIndex, LPCSTR Message)
{
	if(strlen(Message) < 1) return;
	// ----
	if(g_Configs.MultiVaultEnable != 1) return;
	// ----
	int VaultID = 0, VaultInUse = 0;
	sscanf(Message,"%d",&VaultID);
	// ----
	if(VaultID < 0 || VaultID > (g_Configs.MultiVaultMax-1)) return;
	// ----
	LPOBJ lpObj = &gObj[aIndex];
	// ----
	if(lpObj->WarehouseSave != 0 || (lpObj->m_IfState.use && lpObj->m_IfState.type == 6))
	{
		GCServerMsgStringSend("[MultiVault] You must close your ware first!",aIndex,1);
		return;
	}
	// ----
	if(lpObj->MultiVautFloodTime > 0)
	{
		return;
	}
	// ----
	if(lpObj->VaultInUse == VaultID)
	{
		GCServerMsgStringSend("[MultiVault] You are using this ware",aIndex,1);
		return;
	}
	// ----
	lpObj->MultiVautFloodTime = GetTickCount() + (1000 * g_Configs.MultiVaultTime);
	// ----
	PMSG_REQ_CHANGEWAREHOUSE pMsg;
	pMsg.h.set((LPBYTE)&pMsg,0xAA,0x01,sizeof(pMsg));
	pMsg.Change = VaultID;
	pMsg.InUse = lpObj->VaultInUse;
	pMsg.aIndex = aIndex;
	memcpy(pMsg.Account,lpObj->AccountID,sizeof(pMsg.Account)-1);
	// ----
	cDBSMng.Send((char*)&pMsg,pMsg.h.size);
	// ----
	char Buff[255];
	sprintf(Buff,"[MultiVault] Changed ware from %d to %d",lpObj->VaultInUse,VaultID);
	GCServerMsgStringSend(Buff,aIndex,1);
	// ----
	LogAddTD("[MultiVault][%s][%s] Warehouse Changed %d -> %d",lpObj->AccountID,lpObj->Name,lpObj->VaultInUse,VaultID);
	lpObj->VaultInUse = VaultID;
}*/

BOOL CCommands::IsGameMaster(int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

    if(lpObj->Connected < PLAYER_PLAYING)
        return false;
    if((gObj->Authority == 32 || gObj->Authority == 8))
        return true;

    return false;
}

BOOL CCommands::Manager(int aIndex,PMSG_CHATDATA*lpMsg)
{
	LPOBJ lpObj = &gObj[aIndex];

	//Guild SQL Injection Fix!
	if(lpMsg->chatmsg[0] == '@' && lpMsg->chatmsg[1] == '>')
	{
		for(int X=0; X < (int)strlen(lpMsg->chatmsg);X++)
		{
			if(lpMsg->chatmsg[X] == '\'')
			{
				LogAddTD("[ANTI-HACK][%s][%s] Try to do SQL Injection with Guild Notice!",lpObj->AccountID,lpObj->Name);
				lpMsg->chatmsg[X] = '"';
			}
		}
	}

	char String[60];
	char * Msg;

	memset(String,0,sizeof(String));
	strcpy(String,lpMsg->chatmsg);

	if((Msg = strtok(String," ")) == NULL)
	{
		return FALSE;
	}

	int CLen = strlen(Msg);

	if(_stricmp("/post",Msg) == 0)
	{
		this->SendPost(aIndex,&lpMsg->chatmsg[CLen+1]);
		return TRUE;
	}

	if(_stricmp("/serverinfo",Msg) == 0)
	{
		this->ServerInfo(aIndex);
		return TRUE;
	}

	if(_stricmp("/setskin",Msg) == 0)
	{
		this->SkinCommand(aIndex,&lpMsg->chatmsg[CLen+1]);
		return TRUE;
	}

	if(_stricmp("/drop",Msg) == 0)
	{
		this->DropItem(aIndex,&lpMsg->chatmsg[CLen+1]);
		return TRUE;
	}

	if(_stricmp("/make",Msg) == 0)
	{
		this->MakeItem(aIndex,&lpMsg->chatmsg[CLen+1]);
		return TRUE;
	}

	if(_stricmp("/clearinven",Msg) == 0)
	{
		this->ClearInven(aIndex);
		return TRUE;
	}

	if(_stricmp("/pkclear",Msg) == 0)
	{
		this->PkClear(aIndex);
		return TRUE;
	}

	if(_stricmp("/setzen",Msg) == 0)
	{
		this->SetZenCommand(aIndex,&lpMsg->chatmsg[CLen+1]);
		return TRUE;
	}

	if(_stricmp("/addstr",Msg) == 0)
	{
		this->AddStats(aIndex,&lpMsg->chatmsg[CLen+1],3);
		return TRUE;
	}

	if(_stricmp("/addagi",Msg) == 0)
	{
		this->AddStats(aIndex,&lpMsg->chatmsg[CLen+1],2);
		return TRUE;
	}

	if(_stricmp("/addvit",Msg) == 0)
	{
		this->AddStats(aIndex,&lpMsg->chatmsg[CLen+1],1);
		return TRUE;
	}

	if(_stricmp("/addene",Msg) == 0)
	{
		this->AddStats(aIndex,&lpMsg->chatmsg[CLen+1],0);
		return TRUE;
	}

	if(_stricmp("/addcmd",Msg) == 0)
	{
		this->AddStats(aIndex,&lpMsg->chatmsg[CLen+1],4);
		return TRUE;
	}

	/*if(_stricmp("/ware",Msg) == 0)
	{
		this->ChangeVault(aIndex,&lpMsg->chatmsg[CLen+1]);
		return TRUE;
	}*/

	if (_stricmp("/packlevel",Msg) == 0)
	{
		this->PackLevel(aIndex);
		return TRUE;
	}

	if (_stricmp("/packlevel20",Msg) == 0)
	{
		this->PackLevel20(aIndex);
		return TRUE;
	}

	if (_stricmp("/packluck",Msg) == 0)
	{
		this->PackLuck(aIndex);
		return TRUE;
	}

	if (_stricmp("/packskill",Msg) == 0)
	{
		this->PackSkill(aIndex);
		return TRUE;
	}

	if (_stricmp("/packoption",Msg) == 0)
	{
		this->PackOption(aIndex);
		return TRUE;
	}

	if (_stricmp("/packexcellent",Msg) == 0)
	{
		this->PackExcellent(aIndex);
		return TRUE;
	}

	if (_stricmp("/packancient",Msg) == 0)
	{
		this->PackAncient(aIndex);
		return TRUE;
	}

	if (_stricmp("/packsocket",Msg) == 0)
	{
		this->PackSocket(aIndex);
		return TRUE;
	}

	if (_stricmp("/unpacklevel",Msg) == 0)
	{
		this->UnpackLevel(aIndex);
		return TRUE;
	}

	if (_stricmp("/unpackluck",Msg) == 0)
	{
		this->UnpackLuck(aIndex);
		return TRUE;
	}

	if (_stricmp("/unpackskill",Msg) == 0)
	{
		this->UnpackSkill(aIndex);
		return TRUE;
	}

	if (_stricmp("/unpackoption",Msg) == 0)
	{
		this->UnpackOption(aIndex);
		return TRUE;
	}

	if (_stricmp("/unpackexcellent",Msg) == 0)
	{
		this->UnpackExcellent(aIndex);
		return TRUE;
	}

	if (_stricmp("/unpackancient",Msg) == 0)
	{
		this->UnpackAncient(aIndex);
		return TRUE;
	}

	if (_stricmp("/unpacksocket",Msg) == 0)
	{
		this->UnpackSocket(aIndex);
		return TRUE;
	}

	return FALSE;
}