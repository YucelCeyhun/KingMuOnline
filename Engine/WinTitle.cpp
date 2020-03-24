#include "StdAfx.h"

int IsWinTitle = GetPrivateProfileInt("Engine","UseCustomTitle",0,ENGINE_INI);

cWinTitle gWinTitle;

cWinTitle::cWinTitle()
{
	this->dwTitleName = 0;
	memset(this->WindowName,0,sizeof(this->WindowName));
}

cWinTitle::~cWinTitle()
{
	/**/
}

void cWinTitle::Load()
{
	if(IsWinTitle == 1)
	{
		if(gScriptEncode.ReadScript(TITLE_FILE))
		{
			this->dwTitleName = oGameWindowText;
			// ----
			WZSMDToken Token = gScriptEncode.GetToken();
			// ----
			Token = gScriptEncode.GetToken();
			memcpy(this->WindowName,gScriptEncode.GetString(),sizeof(this->WindowName));
			sprintf((char*)this->dwTitleName,this->WindowName,sizeof(this->WindowName));
			// ----
			gScriptEncode.Close();
		}
		else
		{
			MessageBox(NULL,"WinTitle.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
}