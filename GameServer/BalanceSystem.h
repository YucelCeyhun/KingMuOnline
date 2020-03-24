#ifndef __BALANCESYSTEM_H__
#define __BALANCESYSTEM_H__

#include "StdAfx.h"
#include "user.h"

class cBalanceSystem
{
public:
	// ----
	cBalanceSystem();
	virtual ~cBalanceSystem();
	// ----
	void Load();
	void Init();
	void ReadConfigs(char *File);
	// ----
	void Main(LPOBJ lpObj,LPOBJ lpTarget,int &AttackDamage);
	// ----
private:
	// ----
	bool Enable;
	// ----
	int DKvsDK;
	int DKvsDW;
	int DKvsFE;
	int DKvsSM;
	int DKvsMG;
	int DKvsDL;
	// ----
	int DWvsDW;
	int DWvsDK;
	int DWvsFE;
	int DWvsSM;
	int DWvsMG;
	int DWvsDL;
	// ----
	int FEvsFE;
	int FEvsDK;
	int FEvsDW;
	int FEvsSM;
	int FEvsMG;
	int FEvsDL;
	// ----
	int SMvsSM;
	int SMvsDK;
	int SMvsDW;
	int SMvsFE;
	int SMvsMG;
	int SMvsDL;
	// ----
	int MGvsMG;
	int MGvsDK;
	int MGvsDW;
	int MGvsFE;
	int MGvsSM;
	int MGvsDL;
	// ----
	int DLvsDL;
	int DLvsDK;
	int DLvsDW;
	int DLvsFE;
	int DLvsSM;
	int DLvsMG;
};

extern cBalanceSystem gBalanceSystem;

#endif