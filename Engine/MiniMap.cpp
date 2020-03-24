#include "StdAfx.h"

cMiniMap gMiniMap;

bool cMiniMap::CheckThis()
{
	if (gInterface.CheckWindow(FastMenu) || gInterface.CheckWindow(FriendList) || gInterface.CheckWindow(SkillTree))
	{
		return false;
	}
	return this->minimapToggle;
}

bool cMiniMap::FileCheck(int Map)
{
	//if(pMapNumber == Loren) { return 1; }
	// ----
	char buff[MAX_PATH];
	// ----
	wsprintf(buff, MINI_MAP_FILE_CHECK, (pMapNumber + 1));
	// ----
	FILE* file;
	// ----
	this->CreateNewDir();
	// ----
	if (fopen_s(&file, buff, "r") != 0)
	{
		return 0;
	}
	else
	{
		fclose(file);
		return 1;
	}
}

void cMiniMap::Core()
{
	pLoadSomeMapObject();
	gMiniMap.Path();
}

DWORD cMiniMap::CreateNewDir()
{
	const int MiniMapFolder = 0x008DC270;
	// ----
	static char Mini_Map_New[MAX_PATH] = { '\0' };
	// ----
	sprintf(Mini_Map_New, MINI_MAP_FILE_LOAD, pMapNumber + 1);
	// ----
	*(DWORD*)MiniMapFolder = (DWORD)&Mini_Map_New;
	// ----
	return (DWORD)&Mini_Map_New;
}

void cMiniMap::Path()
{
	static DWORD dwMiniMapFolder = gMiniMap.CreateNewDir();
	// ----
	if (pMapNumber < MAX_MINI_MAP)
	{
		if (gMiniMap.FileCheck(pMapNumber) != 0)
		{
			gMiniMap.Table[pMapNumber] = 1;
			pLoadImage((char*)dwMiniMapFolder, 0x7B69, GL_LINEAR, GL_CLAMP, GL_TRUE);
		}
	}
}

bool cMiniMap::CoreCheck(int Map)
{
	if (/*Map == 30 || */(Map < MAX_MINI_MAP && gMiniMap.Table[Map] != 0))
	{
		if (gMiniMap.CheckThis() == false)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

void cMiniMap::Toggle() {
	this->minimapToggle = !this->minimapToggle;
}

void cMiniMap::Init()
{
	memset(this->Table, 0, sizeof(this->Table));
	// ----
	gToolKit.MemorySet(0x00614069, 0x90, 0x02);
	gToolKit.MemorySet(0x006E0402, 0x90, 0x1E);
	// ----
	gToolKit.SetByte((PVOID)(oMiniMapKeyPush + 1), 0x10);
	// ----
	gToolKit.SetCompleteHook(0xFF, 0x005E93F2, &Core);
	gToolKit.SetCompleteHook(0xE8, 0x006E0402, &Path);
	gToolKit.SetCompleteHook(0xFF, 0x006DE41A, &CoreCheck);
	gToolKit.SetCompleteHook(0xFF, 0x00730AB9, &CoreCheck);
}

void cMiniMap::Load()
{
	this->Init();
}