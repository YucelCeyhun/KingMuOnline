#ifndef __SUMMONBOOKS_H__
#define __SUMMONBOOKS_H__

#include "GameMain.h"

enum eEffectPacket
{
	SH_PLAYER_EFFECT	= 1,
	LV_PLAYER_EFFECT	= 2,
	SD_PLAYER_EFFECT	= 3,
};

class CSummonBooks
{
public:
	BOOL CreateDarkPhoenixMonster(int iIndex);
	BOOL CreateGiantDragonMonster(int iIndex);
	BOOL CreateKundunBossMonster(int iIndex);
	BOOL CreateGiantDrakanMonster(int iIndex);
	BOOL CreateIronKnightMonster(int iIndex);
	BOOL CreateSelupanBossMonster(int iIndex);
	BOOL CreateThunderNappinMonster(int iIndex);
	BOOL CreateHellMaineBossMonster(int iIndex);
	// ----
	void CreateSummonEffect(int aIndex,BYTE btType);
};

extern CSummonBooks g_SummonBooks;

#endif