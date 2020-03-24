#include "StdAfx.h"
#include "SummonBooks.h"
#include "LogProc.h"
#include "DevilSquare.h"
#include "BloodCastle.h"
#include "ChaosCastle.h"
#include "IllusionTempleEvent.h"

CSummonBooks g_SummonBooks;

BOOL CSummonBooks::CreateDarkPhoenixMonster(int iIndex)
{
	int iMapNumber;
	BYTE btMapAttr;
	int iMonsterType;
	int iMonsterIndex;
	// ----
	LPOBJ lpObj = &gObj[iIndex];
	// ----
	if( DS_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( BC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( CC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// -----
	if( IT_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	iMapNumber = gObj[iIndex].MapNumber;
	// ----
	btMapAttr = MapC[iMapNumber].GetAttr(gObj[iIndex].X, gObj[iIndex].Y);
	// ----
	if( btMapAttr &1 != 0 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Dark Phoenix - Called in Safety Area (Map:%d, X:%d, Y:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber,gObj[iIndex].X, gObj[iIndex].Y);
		return false;
	}
	// ----
	iMonsterType = 77;
	// ----
	if( gObj[iIndex].MapNumber == 10 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Dark Phoenix - Unable to Summon on this Map (MapNumber:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber);
		return false;
	}
	// ----
	iMonsterIndex = gObjAddMonster(iMapNumber);
	// ----
	if ( iMonsterIndex >= 0 )
	{
		BYTE X = lpObj->X;
		BYTE Y = lpObj->Y;
		// ----
		LPMONSTER_ATTRIBUTE lpMATTR = gMAttr.GetAttr(iMonsterType);
		// ----
		if ( lpMATTR == NULL )
		{
			gObjDel(iMonsterIndex);
			LogAddTD("[Summon Book] [%s][%s] Dark Phoenix Vanished - lpMATTR == NULL (SummonIndex:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,iMonsterIndex);
			return false;
		}
		// ----
		gObj[iMonsterIndex].m_PosNum = -1;
		gObj[iMonsterIndex].X = X;
		gObj[iMonsterIndex].Y = Y;
		gObj[iMonsterIndex].TX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].TY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].m_OldX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].m_OldY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].StartX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].StartY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
		gObj[iMonsterIndex].m_MoveRange = 5;
		// ----
		gObj[iMonsterIndex].Level = lpMATTR->m_Level;
		gObj[iMonsterIndex].Type = OBJ_MONSTER;
		gObj[iMonsterIndex].MaxRegenTime = 0;
		gObj[iMonsterIndex].Dir = rand() % 8;
		gObj[iMonsterIndex].m_Attribute = 60;
		// ----
		gObjSetMonster(iMonsterIndex,iMonsterType);
		// ----
		LogAddTD("[Summon Book] [%s][%s] Create Dark Phoenix Successfuly (Live:%d, GateTick:%u, DieRegen:%d, Map:%d, X:%d, Y:%d, SummonIndex:%d, OwnerIndex:%d, No.:%d)",
			gObj[iIndex].AccountID, gObj[iIndex].Name, gObj[iMonsterIndex].Live, gObj[iMonsterIndex].RegenTime,
			gObj[iMonsterIndex].DieRegen, gObj[iMonsterIndex].MapNumber, gObj[iMonsterIndex].X,
			gObj[iMonsterIndex].Y, iMonsterIndex, iIndex, 0);
	}
	// ----
	return true;
}

BOOL CSummonBooks::CreateGiantDragonMonster(int iIndex)
{
	int iMapNumber;
	BYTE btMapAttr;
	int iMonsterType;
	int iMonsterIndex;
	// ----
	LPOBJ lpObj = &gObj[iIndex];
	// ----
	if( DS_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( BC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( CC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// -----
	if( IT_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	iMapNumber = gObj[iIndex].MapNumber;
	// ----
	btMapAttr = MapC[iMapNumber].GetAttr(gObj[iIndex].X, gObj[iIndex].Y);
	// ----
	if( btMapAttr &1 != 0 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Giant Dragon - Called in Safety Area (Map:%d, X:%d, Y:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber,gObj[iIndex].X, gObj[iIndex].Y);
		return false;
	}
	// ----
	iMonsterType = 42;
	// ----
	if( gObj[iIndex].MapNumber == 10 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Giant Dragon - Unable to Summon on this Map (MapNumber:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber);
		return false;
	}
	// ----
	iMonsterIndex = gObjAddMonster(iMapNumber);
	// ----
	if ( iMonsterIndex >= 0 )
	{
		BYTE X = lpObj->X;
		BYTE Y = lpObj->Y;
		// ----
		LPMONSTER_ATTRIBUTE lpMATTR = gMAttr.GetAttr(iMonsterType);
		// ----
		if ( lpMATTR == NULL )
		{
			gObjDel(iMonsterIndex);
			LogAddTD("[Summon Book] [%s][%s] Giant Dragon Vanished - lpMATTR == NULL (SummonIndex:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,iMonsterIndex);
			return false;
		}
		// ----
		gObj[iMonsterIndex].m_PosNum = -1;
		gObj[iMonsterIndex].X = X;
		gObj[iMonsterIndex].Y = Y;
		gObj[iMonsterIndex].TX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].TY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].m_OldX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].m_OldY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].StartX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].StartY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
		gObj[iMonsterIndex].m_MoveRange = 5;
		// ----
		gObj[iMonsterIndex].Level = lpMATTR->m_Level;
		gObj[iMonsterIndex].Type = OBJ_MONSTER;
		gObj[iMonsterIndex].MaxRegenTime = 0;
		gObj[iMonsterIndex].Dir = rand() % 8;
		gObj[iMonsterIndex].m_Attribute = 60;
		// ----
		gObjSetMonster(iMonsterIndex,iMonsterType);
		// ----
		LogAddTD("[Summon Book] [%s][%s] Create Giant Dragon Successfuly (Live:%d, GateTick:%u, DieRegen:%d, Map:%d, X:%d, Y:%d, SummonIndex:%d, OwnerIndex:%d, No.:%d)",
			gObj[iIndex].AccountID, gObj[iIndex].Name, gObj[iMonsterIndex].Live, gObj[iMonsterIndex].RegenTime,
			gObj[iMonsterIndex].DieRegen, gObj[iMonsterIndex].MapNumber, gObj[iMonsterIndex].X,
			gObj[iMonsterIndex].Y, iMonsterIndex, iIndex, 0);
	}
	// ----
	return true;
}

BOOL CSummonBooks::CreateKundunBossMonster(int iIndex)
{
	int iMapNumber;
	BYTE btMapAttr;
	int iMonsterType;
	int iMonsterIndex;
	// ----
	LPOBJ lpObj = &gObj[iIndex];
	// ----
	if( DS_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( BC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( CC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// -----
	if( IT_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	iMapNumber = gObj[iIndex].MapNumber;
	// ----
	btMapAttr = MapC[iMapNumber].GetAttr(gObj[iIndex].X, gObj[iIndex].Y);
	// ----
	if( btMapAttr &1 != 0 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Kundun Boss - Called in Safety Area (Map:%d, X:%d, Y:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber,gObj[iIndex].X, gObj[iIndex].Y);
		return false;
	}
	// ----
	iMonsterType = 275;
	// ----
	if( gObj[iIndex].MapNumber == 10 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Kundun Boss - Unable to Summon on this Map (MapNumber:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber);
		return false;
	}
	// ----
	iMonsterIndex = gObjAddMonster(iMapNumber);
	// ----
	if ( iMonsterIndex >= 0 )
	{
		BYTE X = lpObj->X;
		BYTE Y = lpObj->Y;
		// ----
		LPMONSTER_ATTRIBUTE lpMATTR = gMAttr.GetAttr(iMonsterType);
		// ----
		if ( lpMATTR == NULL )
		{
			gObjDel(iMonsterIndex);
			LogAddTD("[Summon Book] [%s][%s] Kundun Boss Vanished - lpMATTR == NULL (SummonIndex:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,iMonsterIndex);
			return false;
		}
		// ----
		gObj[iMonsterIndex].m_PosNum = -1;
		gObj[iMonsterIndex].X = X;
		gObj[iMonsterIndex].Y = Y;
		gObj[iMonsterIndex].TX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].TY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].m_OldX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].m_OldY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].StartX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].StartY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
		gObj[iMonsterIndex].m_MoveRange = 5;
		// ----
		gObj[iMonsterIndex].Level = lpMATTR->m_Level;
		gObj[iMonsterIndex].Type = OBJ_MONSTER;
		gObj[iMonsterIndex].MaxRegenTime = 0;
		gObj[iMonsterIndex].Dir = rand() % 8;
		gObj[iMonsterIndex].m_Attribute = 60;
		// ----
		gObjSetMonster(iMonsterIndex,iMonsterType);
		// ----
		LogAddTD("[Summon Book] [%s][%s] Create Kundun Boss Successfuly (Live:%d, GateTick:%u, DieRegen:%d, Map:%d, X:%d, Y:%d, SummonIndex:%d, OwnerIndex:%d, No.:%d)",
			gObj[iIndex].AccountID, gObj[iIndex].Name, gObj[iMonsterIndex].Live, gObj[iMonsterIndex].RegenTime,
			gObj[iMonsterIndex].DieRegen, gObj[iMonsterIndex].MapNumber, gObj[iMonsterIndex].X,
			gObj[iMonsterIndex].Y, iMonsterIndex, iIndex, 0);
	}
	// ----
	return true;
}

BOOL CSummonBooks::CreateGiantDrakanMonster(int iIndex)
{
	int iMapNumber;
	BYTE btMapAttr;
	int iMonsterType;
	int iMonsterIndex;
	// ----
	LPOBJ lpObj = &gObj[iIndex];
	// ----
	if( DS_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( BC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( CC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// -----
	if( IT_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	iMapNumber = gObj[iIndex].MapNumber;
	// ----
	btMapAttr = MapC[iMapNumber].GetAttr(gObj[iIndex].X, gObj[iIndex].Y);
	// ----
	if( btMapAttr &1 != 0 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Giant Drakan - Called in Safety Area (Map:%d, X:%d, Y:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber,gObj[iIndex].X, gObj[iIndex].Y);
		return false;
	}
	// ----
	iMonsterType = 75;
	// ----
	if( gObj[iIndex].MapNumber == 10 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Giant Drakan - Unable to Summon on this Map (MapNumber:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber);
		return false;
	}
	// ----
	iMonsterIndex = gObjAddMonster(iMapNumber);
	// ----
	if ( iMonsterIndex >= 0 )
	{
		BYTE X = lpObj->X;
		BYTE Y = lpObj->Y;
		// ----
		LPMONSTER_ATTRIBUTE lpMATTR = gMAttr.GetAttr(iMonsterType);
		// ----
		if ( lpMATTR == NULL )
		{
			gObjDel(iMonsterIndex);
			LogAddTD("[Summon Book] [%s][%s] Giant Drakan Vanished - lpMATTR == NULL (SummonIndex:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,iMonsterIndex);
			return false;
		}
		// ----
		gObj[iMonsterIndex].m_PosNum = -1;
		gObj[iMonsterIndex].X = X;
		gObj[iMonsterIndex].Y = Y;
		gObj[iMonsterIndex].TX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].TY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].m_OldX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].m_OldY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].StartX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].StartY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
		gObj[iMonsterIndex].m_MoveRange = 5;
		// ----
		gObj[iMonsterIndex].Level = lpMATTR->m_Level;
		gObj[iMonsterIndex].Type = OBJ_MONSTER;
		gObj[iMonsterIndex].MaxRegenTime = 0;
		gObj[iMonsterIndex].Dir = rand() % 8;
		gObj[iMonsterIndex].m_Attribute = 60;
		// ----
		gObjSetMonster(iMonsterIndex,iMonsterType);
		// ----
		LogAddTD("[Summon Book] [%s][%s] Create Giant Drakan Successfuly (Live:%d, GateTick:%u, DieRegen:%d, Map:%d, X:%d, Y:%d, SummonIndex:%d, OwnerIndex:%d, No.:%d)",
			gObj[iIndex].AccountID, gObj[iIndex].Name, gObj[iMonsterIndex].Live, gObj[iMonsterIndex].RegenTime,
			gObj[iMonsterIndex].DieRegen, gObj[iMonsterIndex].MapNumber, gObj[iMonsterIndex].X,
			gObj[iMonsterIndex].Y, iMonsterIndex, iIndex, 0);
	}
	// ----
	return true;
}

BOOL CSummonBooks::CreateIronKnightMonster(int iIndex)
{
	int iMapNumber;
	BYTE btMapAttr;
	int iMonsterType;
	int iMonsterIndex;
	// ----
	LPOBJ lpObj = &gObj[iIndex];
	// ----
	if( DS_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( BC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( CC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// -----
	if( IT_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	iMapNumber = gObj[iIndex].MapNumber;
	// ----
	btMapAttr = MapC[iMapNumber].GetAttr(gObj[iIndex].X, gObj[iIndex].Y);
	// ----
	if( btMapAttr &1 != 0 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Iron Knight - Called in Safety Area (Map:%d, X:%d, Y:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber,gObj[iIndex].X, gObj[iIndex].Y);
		return false;
	}
	// ----
	iMonsterType = 458;
	// ----
	if( gObj[iIndex].MapNumber == 10 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Iron Knight - Unable to Summon on this Map (MapNumber:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber);
		return false;
	}
	// ----
	iMonsterIndex = gObjAddMonster(iMapNumber);
	// ----
	if ( iMonsterIndex >= 0 )
	{
		BYTE X = lpObj->X;
		BYTE Y = lpObj->Y;
		// ----
		LPMONSTER_ATTRIBUTE lpMATTR = gMAttr.GetAttr(iMonsterType);
		// ----
		if ( lpMATTR == NULL )
		{
			gObjDel(iMonsterIndex);
			LogAddTD("[Summon Book] [%s][%s] Iron Knight Vanished - lpMATTR == NULL (SummonIndex:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,iMonsterIndex);
			return false;
		}
		// ----
		gObj[iMonsterIndex].m_PosNum = -1;
		gObj[iMonsterIndex].X = X;
		gObj[iMonsterIndex].Y = Y;
		gObj[iMonsterIndex].TX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].TY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].m_OldX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].m_OldY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].StartX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].StartY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
		gObj[iMonsterIndex].m_MoveRange = 5;
		// ----
		gObj[iMonsterIndex].Level = lpMATTR->m_Level;
		gObj[iMonsterIndex].Type = OBJ_MONSTER;
		gObj[iMonsterIndex].MaxRegenTime = 0;
		gObj[iMonsterIndex].Dir = rand() % 8;
		gObj[iMonsterIndex].m_Attribute = 60;
		// ----
		gObjSetMonster(iMonsterIndex,iMonsterType);
		// ----
		LogAddTD("[Summon Book] [%s][%s] Create Iron Knight Successfuly (Live:%d, GateTick:%u, DieRegen:%d, Map:%d, X:%d, Y:%d, SummonIndex:%d, OwnerIndex:%d, No.:%d)",
			gObj[iIndex].AccountID, gObj[iIndex].Name, gObj[iMonsterIndex].Live, gObj[iMonsterIndex].RegenTime,
			gObj[iMonsterIndex].DieRegen, gObj[iMonsterIndex].MapNumber, gObj[iMonsterIndex].X,
			gObj[iMonsterIndex].Y, iMonsterIndex, iIndex, 0);
	}
	// ----
	return true;
}

BOOL CSummonBooks::CreateSelupanBossMonster(int iIndex)
{
	int iMapNumber;
	BYTE btMapAttr;
	int iMonsterType;
	int iMonsterIndex;
	// ----
	LPOBJ lpObj = &gObj[iIndex];
	// ----
	if( DS_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( BC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( CC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// -----
	if( IT_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	iMapNumber = gObj[iIndex].MapNumber;
	// ----
	btMapAttr = MapC[iMapNumber].GetAttr(gObj[iIndex].X, gObj[iIndex].Y);
	// ----
	if( btMapAttr &1 != 0 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Selupan Boss - Called in Safety Area (Map:%d, X:%d, Y:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber,gObj[iIndex].X, gObj[iIndex].Y);
		return false;
	}
	// ----
	iMonsterType = 459;
	// ----
	if( gObj[iIndex].MapNumber == 10 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Selupan Boss - Unable to Summon on this Map (MapNumber:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber);
		return false;
	}
	// ----
	iMonsterIndex = gObjAddMonster(iMapNumber);
	// ----
	if ( iMonsterIndex >= 0 )
	{
		BYTE X = lpObj->X;
		BYTE Y = lpObj->Y;
		// ----
		LPMONSTER_ATTRIBUTE lpMATTR = gMAttr.GetAttr(iMonsterType);
		// ----
		if ( lpMATTR == NULL )
		{
			gObjDel(iMonsterIndex);
			LogAddTD("[Summon Book] [%s][%s] Selupan Boss Vanished - lpMATTR == NULL (SummonIndex:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,iMonsterIndex);
			return false;
		}
		// ----
		gObj[iMonsterIndex].m_PosNum = -1;
		gObj[iMonsterIndex].X = X;
		gObj[iMonsterIndex].Y = Y;
		gObj[iMonsterIndex].TX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].TY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].m_OldX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].m_OldY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].StartX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].StartY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
		gObj[iMonsterIndex].m_MoveRange = 5;
		// ----
		gObj[iMonsterIndex].Level = lpMATTR->m_Level;
		gObj[iMonsterIndex].Type = OBJ_MONSTER;
		gObj[iMonsterIndex].MaxRegenTime = 0;
		gObj[iMonsterIndex].Dir = rand() % 8;
		gObj[iMonsterIndex].m_Attribute = 60;
		// ----
		gObjSetMonster(iMonsterIndex,iMonsterType);
		// ----
		LogAddTD("[Summon Book] [%s][%s] Create Selupan Boss Successfuly (Live:%d, GateTick:%u, DieRegen:%d, Map:%d, X:%d, Y:%d, SummonIndex:%d, OwnerIndex:%d, No.:%d)",
			gObj[iIndex].AccountID, gObj[iIndex].Name, gObj[iMonsterIndex].Live, gObj[iMonsterIndex].RegenTime,
			gObj[iMonsterIndex].DieRegen, gObj[iMonsterIndex].MapNumber, gObj[iMonsterIndex].X,
			gObj[iMonsterIndex].Y, iMonsterIndex, iIndex, 0);
	}
	// ----
	return true;
}

BOOL CSummonBooks::CreateThunderNappinMonster(int iIndex)
{
	int iMapNumber;
	BYTE btMapAttr;
	int iMonsterType;
	int iMonsterIndex;
	// ----
	LPOBJ lpObj = &gObj[iIndex];
	// ----
	if( DS_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( BC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( CC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// -----
	if( IT_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	iMapNumber = gObj[iIndex].MapNumber;
	// ----
	btMapAttr = MapC[iMapNumber].GetAttr(gObj[iIndex].X, gObj[iIndex].Y);
	// ----
	if( btMapAttr &1 != 0 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Thunder Nappin - Called in Safety Area (Map:%d, X:%d, Y:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber,gObj[iIndex].X, gObj[iIndex].Y);
		return false;
	}
	// ----
	iMonsterType = 447;
	// ----
	if( gObj[iIndex].MapNumber == 10 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Thunder Nappin - Unable to Summon on this Map (MapNumber:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber);
		return false;
	}
	// ----
	iMonsterIndex = gObjAddMonster(iMapNumber);
	// ----
	if ( iMonsterIndex >= 0 )
	{
		BYTE X = lpObj->X;
		BYTE Y = lpObj->Y;
		// ----
		LPMONSTER_ATTRIBUTE lpMATTR = gMAttr.GetAttr(iMonsterType);
		// ----
		if ( lpMATTR == NULL )
		{
			gObjDel(iMonsterIndex);
			LogAddTD("[Summon Book] [%s][%s] Thunder Nappin Vanished - lpMATTR == NULL (SummonIndex:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,iMonsterIndex);
			return false;
		}
		// ----
		gObj[iMonsterIndex].m_PosNum = -1;
		gObj[iMonsterIndex].X = X;
		gObj[iMonsterIndex].Y = Y;
		gObj[iMonsterIndex].TX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].TY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].m_OldX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].m_OldY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].StartX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].StartY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
		gObj[iMonsterIndex].m_MoveRange = 5;
		// ----
		gObj[iMonsterIndex].Level = lpMATTR->m_Level;
		gObj[iMonsterIndex].Type = OBJ_MONSTER;
		gObj[iMonsterIndex].MaxRegenTime = 0;
		gObj[iMonsterIndex].Dir = rand() % 8;
		gObj[iMonsterIndex].m_Attribute = 60;
		// ----
		gObjSetMonster(iMonsterIndex,iMonsterType);
		// ----
		LogAddTD("[Summon Book] [%s][%s] Create Thunder Nappin Successfuly (Live:%d, GateTick:%u, DieRegen:%d, Map:%d, X:%d, Y:%d, SummonIndex:%d, OwnerIndex:%d, No.:%d)",
			gObj[iIndex].AccountID, gObj[iIndex].Name, gObj[iMonsterIndex].Live, gObj[iMonsterIndex].RegenTime,
			gObj[iMonsterIndex].DieRegen, gObj[iMonsterIndex].MapNumber, gObj[iMonsterIndex].X,
			gObj[iMonsterIndex].Y, iMonsterIndex, iIndex, 0);
	}
	// ----
	return true;
}

BOOL CSummonBooks::CreateHellMaineBossMonster(int iIndex)
{
	int iMapNumber;
	BYTE btMapAttr;
	int iMonsterType;
	int iMonsterIndex;
	// ----
	LPOBJ lpObj = &gObj[iIndex];
	// ----
	if( DS_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( BC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	if( CC_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// -----
	if( IT_MAP_RANGE(gObj[iIndex].MapNumber) )
	{
		return false;
	}
	// ----
	iMapNumber = gObj[iIndex].MapNumber;
	// ----
	btMapAttr = MapC[iMapNumber].GetAttr(gObj[iIndex].X, gObj[iIndex].Y);
	// ----
	if( btMapAttr &1 != 0 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Hell Maine - Called in Safety Area (Map:%d, X:%d, Y:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber,gObj[iIndex].X, gObj[iIndex].Y);
		return false;
	}
	// ----
	iMonsterType = 309;
	// ----
	if( gObj[iIndex].MapNumber == 10 )
	{
		LogAddTD("[Summon Book] [%s][%s] Failed to Summon Hell Maine - Unable to Summon on this Map (MapNumber:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,gObj[iIndex].MapNumber);
		return false;
	}
	// ----
	iMonsterIndex = gObjAddMonster(iMapNumber);
	// ----
	if ( iMonsterIndex >= 0 )
	{
		BYTE X = lpObj->X;
		BYTE Y = lpObj->Y;
		// ----
		LPMONSTER_ATTRIBUTE lpMATTR = gMAttr.GetAttr(iMonsterType);
		// ----
		if ( lpMATTR == NULL )
		{
			gObjDel(iMonsterIndex);
			LogAddTD("[Summon Book] [%s][%s] Hell Maine Vanished - lpMATTR == NULL (SummonIndex:%d)",gObj[iIndex].AccountID,gObj[iIndex].Name,iMonsterIndex);
			return false;
		}
		// ----
		gObj[iMonsterIndex].m_PosNum = -1;
		gObj[iMonsterIndex].X = X;
		gObj[iMonsterIndex].Y = Y;
		gObj[iMonsterIndex].TX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].TY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].m_OldX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].m_OldY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].StartX = gObj[iMonsterIndex].X;
		gObj[iMonsterIndex].StartY = gObj[iMonsterIndex].Y;
		gObj[iMonsterIndex].MapNumber = lpObj->MapNumber;
		gObj[iMonsterIndex].m_MoveRange = 5;
		// ----
		gObj[iMonsterIndex].Level = lpMATTR->m_Level;
		gObj[iMonsterIndex].Type = OBJ_MONSTER;
		gObj[iMonsterIndex].MaxRegenTime = 0;
		gObj[iMonsterIndex].Dir = rand() % 8;
		gObj[iMonsterIndex].m_Attribute = 60;
		// ----
		gObjSetMonster(iMonsterIndex,iMonsterType);
		// ----
		LogAddTD("[Summon Book] [%s][%s] Create Hell Maine Successfuly (Live:%d, GateTick:%u, DieRegen:%d, Map:%d, X:%d, Y:%d, SummonIndex:%d, OwnerIndex:%d, No.:%d)",
			gObj[iIndex].AccountID, gObj[iIndex].Name, gObj[iMonsterIndex].Live, gObj[iMonsterIndex].RegenTime,
			gObj[iMonsterIndex].DieRegen, gObj[iMonsterIndex].MapNumber, gObj[iMonsterIndex].X,
			gObj[iMonsterIndex].Y, iMonsterIndex, iIndex, 0);
	}
	// ----
	return true;
}

void CSummonBooks::CreateSummonEffect(int aIndex,BYTE btType)
{
	LPOBJ lpObj = &gObj[aIndex];
	// ----
	PMSG_EFFECTINFO pMsg;
	// ----
	switch(btType)
	{
		case 1:
		{
			btType = 3;		// Small Shine Effect
			break;
		}
		case 2:
		{
			btType = 16;	// Level Up Effect
			break;
		}
		case 3:
		{
			btType = 17;	// Shield Effect
			break;
		}
	}
	// ----
	/*
	FIREWORKS
	// ----
	PMSG_SERVERCMD ServerCmd;
	// ----
	PHeadSubSetB((LPBYTE)&ServerCmd,0xF3,0x40,sizeof(ServerCmd));
	ServerCmd.CmdType = 0;
	ServerCmd.X = lpObj->X;
	ServerCmd.Y = lpObj->Y;
	// ----
	MsgSendV2(lpObj,(LPBYTE)&ServerCmd,sizeof(ServerCmd));
	DataSend(lpObj->m_Index,(LPBYTE)&ServerCmd,sizeof(ServerCmd));
	*/
	pMsg.h.c		= 0xC1;
	pMsg.h.headcode	= 0x48;
	pMsg.h.size		= sizeof(pMsg);
	pMsg.NumberH	= SET_NUMBERH(lpObj->m_Index);
	pMsg.NumberL	= SET_NUMBERL(lpObj->m_Index);
	pMsg.btType		= btType;
	// ----
	MsgSendV2(lpObj,(LPBYTE)&pMsg,pMsg.h.size);
	DataSend(lpObj->m_Index,(LPBYTE)&pMsg,pMsg.h.size);
}