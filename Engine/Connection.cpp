#include "StdAfx.h"

int IsConnection = GetPrivateProfileInt("Engine","UseCustomConnect",0,ENGINE_INI);

cConnection gConnection;

void cConnection::Changer()
{
	//"cs.muonline.jp"
	char IP[30];
	//"NemesisDeveloper"
	char SE[19];
	//"22656"
	char VE[8];
	// ----
	if(!gScriptEncode.ReadScript(COMMON_FILE))
	{
		MessageBox(NULL,"Common.bmd file not found","Error",ERROR);
		return;
	}
	// ----
	gScriptEncode.GetToken();
	memcpy(IP,gScriptEncode.GetString(),sizeof(IP)-1);
	// ----
	gScriptEncode.GetToken();
	memcpy(SE,gScriptEncode.GetString(),sizeof(SE)-1);
	// ----
	gScriptEncode.GetToken();
	memcpy(VE,gScriptEncode.GetString(),sizeof(VE)-1);
	// ----
	gToolKit.WriteMemory((LPVOID)0x008C2FC4,IP,sizeof(IP));
	gToolKit.WriteMemory((LPVOID)0x008D7D34,SE,sizeof(SE));
	gToolKit.WriteMemory((LPVOID)0x008D7D2C,VE,sizeof(VE));
}

void cConnection::Init()
{
	if(IsConnection == 1)
	{
		if(gScriptEncode.ReadScript(SERVERLIST_FILE))
		{
			this->dwIPConnection = oIPConnection;
			this->dwSEConnection = oSEConnection;
			this->dwVEConnection = oVEConnection;
			// ----
			WZSMDToken Token = gScriptEncode.GetToken();
			// ----
			Token = gScriptEncode.GetToken();
			memcpy(this->IP,gScriptEncode.GetString(),sizeof(this->IP));
			sprintf((char*)this->dwIPConnection,this->IP,sizeof(this->IP));
			// ----
			Token = gScriptEncode.GetToken();
			memcpy(this->SE,gScriptEncode.GetString(),sizeof(this->SE));
			sprintf((char*)this->dwSEConnection,this->SE,sizeof(this->SE));
			// ----
			Token = gScriptEncode.GetToken();
			memcpy(this->VE,gScriptEncode.GetString(),sizeof(this->VE));
			sprintf((char*)this->dwVEConnection,this->VE,sizeof(this->VE));
			// ----
			gScriptEncode.Close();
		}
		else
		{
			MessageBox(NULL,"ServerList.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
	else
	{
		this->Changer();
	}
}

void cConnection::Load()
{
	this->Init();
}