#ifndef __CONTROL_H__
#define __CONTROL_H__

class cControl
{
public:
	cControl();
	virtual ~cControl();
	// ----
	bool Load();
	// ----
	static LRESULT CALLBACK MouseProc(int Code,WPARAM wParam,LPARAM lParam);
	static LRESULT CALLBACK KeyboardProc(int Code,WPARAM wParam,LPARAM lParam);
	// ----
	HINSTANCE hModule;
	// ----
private:
	HHOOK MouseHook;
	HHOOK KeyboardHook;
};

extern cControl gControl;

#endif