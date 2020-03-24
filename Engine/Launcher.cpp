#include "StdAfx.h"

int IsLauncher = GetPrivateProfileInt("Engine","UseCustomLauncher",0,ENGINE_INI);

cLauncher gLauncher;

cLauncher::cLauncher()
{
	memset(this->LauncherName,0,sizeof(this->LauncherName));
}

cLauncher::~cLauncher()
{
	/**/
}

void cLauncher::Init()
{
	if(IsLauncher == 1)
	{
		if(gScriptEncode.ReadScript(LAUNCH_FILE))
		{
			this->dwLauncher = oLauncherName;
			// ----
			WZSMDToken Token = gScriptEncode.GetToken();
			// ----
			Token = gScriptEncode.GetToken();
			this->iLauncher = gScriptEncode.GetNumber();
			// ----
			Token = gScriptEncode.GetToken();
			memcpy(this->LauncherName,gScriptEncode.GetString(),sizeof(this->LauncherName));
			// ----
			if(this->iLauncher == 1)
			{
				gToolKit.SetByte((PVOID)(0x005FA1DF),ASM::JNE);
				memcpy((void*)this->dwLauncher,this->LauncherName,sizeof(this->LauncherName));
			}
		}
		else
		{
			MessageBox(NULL,"LaunchGame.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
}

void cLauncher::Load()
{
	this->Init();
}

/*
DWORD cLauncher::Select()
{
	const int iLauncherName = 0x008D668C;
	static char LauncherPath[MAX_PATH] = {'\0'};
	GetPrivateProfileString("Launcher","LauncherName",LAUNCHER_DEFAULT,this->Launcher,50,LAUNCH_FILE);
	sprintf_s(LauncherPath,this->Launcher);
	*(DWORD*)iLauncherName = (DWORD)&LauncherPath;
	return (DWORD)&LauncherPath;
}

void cLauncher::Usage()
{
	static DWORD dwLauncher = this->Select();
	memcpy(this->Launcher,(void*)dwLauncher,50);
	memcpy((DWORD*)0x00888FD1,this->Launcher,50);
	gToolKit.SetByte((PVOID)(0x005FA1DF),ASM::JNE);
	gToolKit.HookExactOffset(0x00888FD1,0x005FA1F3,ASM::PUSH);
}

void cLauncher::Load()
{
	if(IsLauncher == 1)
	{
		if(gToolKit.FileExists(LAUNCH_FILE))
		{
			this->Usage();
		}
		else
		{
			MessageBox(NULL,"Launcher.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
	else
	{
		return;
	}
}
*/