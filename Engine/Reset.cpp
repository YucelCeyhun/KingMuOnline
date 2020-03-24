#include "StdAfx.h"

cReset gReset;

void cReset::SetData(RESET_ANS_USERDATA * aRecv)
{
	gUser.m_Reset = aRecv->Reset;
	gUser.m_GrandReset = aRecv->GrandReset;
}