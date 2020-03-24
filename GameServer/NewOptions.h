#ifndef NEWOPTIONS_H
#define	NEWOPTIONS_H

#include "StdAfx.h"
#include "user.h"

struct CNewOptions
{
public:
	CNewOptions();
	virtual ~CNewOptions();
	// ----
	int Init(struct OBJECTSTRUCT* lpObj);
	int Evolve(struct OBJECTSTRUCT* lpObj);
	int Imperial(struct OBJECTSTRUCT* lpObj);
	int Mistic(struct OBJECTSTRUCT* lpObj);
	int DarkWolf(struct OBJECTSTRUCT* lpObj);
	int FangSable(struct OBJECTSTRUCT* lpObj);
	int GiantLyon(struct OBJECTSTRUCT* lpObj);
	int LycanWolf(struct OBJECTSTRUCT* lpObj);
	int EvolveDragon(struct OBJECTSTRUCT* lpObj);
	int EvolveGuardian(struct OBJECTSTRUCT* lpObj);
	int EvolveLegendary(struct OBJECTSTRUCT* lpObj);
	// ----
	BOOL RingOfChaos(LPOBJ lpObj);
	BOOL RingOfBless(LPOBJ lpObj);
	BOOL RingOfSoul(LPOBJ lpObj);
};

extern CNewOptions g_NewOptions;

#endif
