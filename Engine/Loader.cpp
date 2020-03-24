#include "StdAfx.h"

cLoader gLoader;

typedef int(*InitDLLPtr)();
InitDLLPtr InitDLL = NULL;

cLoader::cLoader()
{
	memset(this->szPlugin,NULL,sizeof(this->szPlugin));
}

cLoader::~cLoader()
{
}

//void cLoader::DecryptError()
//{
//	if(IsDecryptLogs == 1)
//	{
//		BYTE DecryptLog[5] = {0x90,0x90,0x90,0x90,0x90};
//		memcpy((int*)0x006BD88D,DecryptLog,sizeof(DecryptLog));
//		memcpy((int*)0x006BDAA0,DecryptLog,sizeof(DecryptLog));
//	}
//}

void cLoader::DefenseError()
{
	BYTE RemoveLog[6] = { 0x90,0x90,0x90,0x90,0x90,0x90 };
	memcpy((int*)0x006BD877,RemoveLog,sizeof(RemoveLog));	// -> Remove Write Event on: MuError.log File
	gToolKit.SetRange((LPVOID)0x006BD747,44,ASM::NOP);		// -> Remove Creation from: MuError.log File
}

void cLoader::Load()
{
	this->DefenseError();
	// ----
	if(gScriptEncode.ReadScript(PLUGIN_FILE))
	{
		WZSMDToken Token = gScriptEncode.GetToken();
		// ----
		Token = gScriptEncode.GetToken();
		memcpy(this->szPlugin,gScriptEncode.GetString(),sizeof(this->szPlugin));
		// ----
		Token = gScriptEncode.GetToken();
		memcpy(this->szFuncti,gScriptEncode.GetString(),sizeof(this->szFuncti));
		// ----
		gScriptEncode.Close();
	}
	else
	{
		MessageBox(NULL,"PluginLoad.bmd file not found","Error",MB_OK);
		::ExitProcess(0);
	}
	// ----
	if((strlen(this->szPlugin) > 0) && (strlen(this->szFuncti) > 0))
	{
		HMODULE hMod = LoadLibrary(this->szPlugin);
		// ----
		if(hMod != NULL)
		{
			InitDLL = (InitDLLPtr)GetProcAddress(hMod,this->szFuncti);
			// ----
			if(InitDLL != NULL)
			{
				InitDLL();
			}
			else
			{
				MessageBox(NULL,"Cannot Initialize Library: %d",this->szPlugin,MB_OK);
				::ExitProcess(0);
			}
			// ----
			FreeLibrary(hMod);
		}
		else
		{
			MessageBox(NULL,"Cannot load %d.dll",this->szPlugin,MB_OK);
			::ExitProcess(0);
		}
	}
}