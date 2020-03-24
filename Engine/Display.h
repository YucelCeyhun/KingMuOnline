#ifndef __DISPLAY_H__
#define __DISPLAY_H__

//extern bool g_iFrapsSwitcher;

//#define oFrapsPetSecondMain	0x006020B9

class cDisplay
{
public:
	cDisplay();
	virtual ~cDisplay();
	// ----
	void Load();
	// ----
	//int	Counter;
	// ----
	//bool FrapsSwitcher;
	// ----
	//bool SwitchFrapsState();
	static int GameLoad();
	static void __fastcall MoveListInit(LPVOID This,LPVOID EDX,int Arg1,int Arg2);
};

extern cDisplay gDisplay;

#endif