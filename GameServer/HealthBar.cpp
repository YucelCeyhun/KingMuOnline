#include "StdAfx.h"
#include "HealthBar.h"
#include "protocol.h"
#include "GameMain.h"

#ifdef __IS_HPBAR__

cHealthBar gHealthBar;

cHealthBar::cHealthBar()	// Constructor
{
	/**/
}

cHealthBar::~cHealthBar()	// Destructor
{
	/**/
}

void cHealthBar::Info(LPOBJ lpObj)
{
	int tObjNum		= 0;
	LPOBJ lpTarget	= NULL;
	
	for(int i = 0;i < MAX_VIEWPORT;i++)
	{
		if(lpObj->VpPlayer[i].state)
		{
			tObjNum		= lpObj->VpPlayer2[i].number;
			lpTarget	= &gObj[tObjNum];

			if(tObjNum > 0)
			{
				if(lpTarget->Live && (lpTarget->Type == OBJ_MONSTER))
				{
					BYTE btAttr = MapC[lpTarget->MapNumber].GetAttr(lpTarget->X,lpTarget->Y);

					if((btAttr & 1) == FALSE)
					{
						if((gObjCalDistance(lpObj,lpTarget) <= 10) && (gObjCheckAttackArea(lpObj->m_Index,lpTarget->m_Index) == false))
						{
							this->Send(lpObj->m_Index,lpTarget->m_Index);
						}
					}
				}
			}
		}
	}
}

void cHealthBar::Send(int aIndex,int tIndex)
{
	if((gObj[aIndex].Type == OBJ_USER) && (gObj[tIndex].Type == OBJ_MONSTER))
	{
		MSG_ANS_LIFEBAR_SEND pMsg = {};
		pMsg.h.set((LPBYTE)&pMsg,eMSG_GS_CLIENT_CUSTOM,eMSG_GS_CLIENT_LIFE_BAR,sizeof(MSG_ANS_LIFEBAR_SEND));

		pMsg.NumberH	= SET_NUMBERH(tIndex);
		pMsg.NumberL	= SET_NUMBERL(tIndex);

		pMsg.Life		= gObj[tIndex].Life;
		pMsg.MaxLife	= gObj[tIndex].MaxLife;
		pMsg.Class		= gObj[tIndex].Class;
		pMsg.Level		= gObj[tIndex].Level;
		pMsg.SendSD		= TRUE;

		DataSend(aIndex,(LPBYTE)&pMsg,pMsg.h.size);
	}
}

#endif // __IS_HPBAR__