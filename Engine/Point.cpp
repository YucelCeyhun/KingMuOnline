#include "StdAfx.h"

int IsCustomPoint = GetPrivateProfileInt("Engine","UseCustomPoint",0,ENGINE_INI);

cPoint gPoint;

int cPoint::SetPCPointItemPrice(lpItemObj Item,int Arg2)
{
	for(int i=0;i<gPoint.gItemPoint;i++)
	{
		while(Item->Index == ItemId(gPoint.eTYPE[i].Type,gPoint.eTYPE[i].Index))
		{
			return gPoint.eVALUE[i].Value;
		}
	}
	// ----
	return pItemPriceOnPCShop(Item,Arg2);
}

void cPoint::SetPCPointInvenColor()
{
	gToolKit.SetByte((PVOID)(oPCPointMessageByteB+1),0xFE);
	gToolKit.SetByte((PVOID)(oPCPointMessageByteG+1),0x80);
	gToolKit.SetByte((PVOID)(oPCPointMessageByteR+1),0xFE);
}

void cPoint::Load()
{
	this->SetPCPointInvenColor();
	// ----
	if(IsCustomPoint == 1)
	{
		if(gScriptEncode.ReadScript(POINT_FILE))
		{
			int Token;
			Token = gScriptEncode.GetToken();
			// ----
			gItemPoint = 0;
			// ----
			memset(eTYPE,-1,sizeof(eTYPE));
			memset(eVALUE,-1,sizeof(eVALUE));
			// ----
			while(TRUE)
			{
				Token = gScriptEncode.GetToken();
				// ----
				if((Token == END)) break;
				// ----
				eTYPE[gItemPoint].Type		= gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eTYPE[gItemPoint].Index		= gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eVALUE[gItemPoint].Value	= gScriptEncode.TokenNumber;
				// ----
				gItemPoint++;
			}
			// ----
			if(gItemPoint > 0)
			{
				gToolKit.SetOp((LPVOID)0x00590730,this->SetPCPointItemPrice,ASM::CALL);
			}
		}
		else
		{
			MessageBox(NULL,"ItemPoint.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
}