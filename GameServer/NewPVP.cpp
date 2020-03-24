#include "StdAfx.h"
#include "NewPVP.h"
#include "user.h"

cNewPVP g_NewPVP;

BOOL cNewPVP::IsVulcanusMap(int nMapNumber)
{
	return (nMapNumber==MAP_INDEX_VULCANUS) ? TRUE : FALSE;
}