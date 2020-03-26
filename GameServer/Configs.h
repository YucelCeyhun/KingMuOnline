#ifndef CONFIGS_H
#define	CONFIGS_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StdAfx.h"

struct CConfigs
{
	public:
		void LoadConfigs();
		// ----
		int m_iLifeRate;
		// ----
		char patchVersion[5];
		//----
		int m_iSoulRate;
		int m_iSoulRateWithLuck;
		// ----
		int PostEnable;
		int PostLevel;
		int PostCost;
		int PostColor;
		int DropEnable;
		int MakeEnable;
		int ClearEnable;
		int SkinEnable;
		int SetZenEnable;
		int AddStatsEnable;
		int AddStatsMaxPoints;
		int AddStatsLevel;
		int AddStatsCost;
		//int MultiVaultEnable;
		//int MultiVaultMax;
		//int MultiVaultTime;
		int PackLevelEnable;
		int PackLevel20Enable;
		int PackLuckEnable;
		int PackSkillEnable;
		int PackOptionEnable;
		int PackExcellentEnable;
		int PackAncientEnable;
		int PackSocketEnable;
		int UnpackLevelEnable;
		int UnpackLevel20Enable;
		int UnpackLuckEnable;
		int UnpackSkillEnable;
		int UnpackOptionEnable;
		int UnpackExcellentEnable;
		int UnpackAncientEnable;
		int UnpackSocketEnable;
		// ----
		int LevelUpPointsForDW;
		int LevelUpPointsForDK;
		int LevelUpPointsForFE;
		int LevelUpPointsForMG;
		int LevelUpPointsForDL;
		int LevelUpPointsForSM;
};

extern CConfigs g_Configs;

#endif