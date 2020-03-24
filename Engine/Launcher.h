#ifndef __LAUNCHER_H__
#define __LAUNCHER_H__

#define LAUNCHER_DEFAULT		"MU.exe"
#define MAX_CHAR_LAUNCHER_NAME	100

class cLauncher
{
public:
	cLauncher();
	virtual ~cLauncher();
	// ----
	void Init();
	void Load();
	// ----
private:
	int iLauncher;
	DWORD dwLauncher;
	char LauncherName[MAX_CHAR_LAUNCHER_NAME];
};

extern cLauncher gLauncher;

#endif