#include "StdAfx.h"
#include "Utilities.h"
#include "../include/prodef.h"

cUtilits gUtilits;

void cUtilits::PHeadSetB(LPBYTE lpBuf,BYTE head,int size)
{
	lpBuf[0] = 0xC1;		// Packets
	lpBuf[1] = size;
	lpBuf[2] = head;
}

void cUtilits::SendEffect(LPOBJ gObj,BYTE btType)
{
	PMSG_EFFECTINFO pMsg;
	// ----
	switch(btType)
	{
		case 1:
		{
			btType = 3;		// Effect
			break;
		}
		case 2:
		{
			btType = 16;	// Effect LevelUp
			break;
		}
		case 3:
		{
			btType = 17;	// Effect Gelo
			break;
		}
	}
	// ----
	pMsg.h.c = 0xC1;
	pMsg.h.headcode = 0x48;
	pMsg.h.size = sizeof(pMsg);
	pMsg.NumberH = SET_NUMBERH(gObj->m_Index);
	pMsg.NumberL = SET_NUMBERL(gObj->m_Index);
	pMsg.btType = btType;
	// ----
	DataSend(gObj->m_Index,(LPBYTE)&pMsg,pMsg.h.size);
	MsgSendV2(gObj,(LPBYTE)&pMsg,pMsg.h.size);
}