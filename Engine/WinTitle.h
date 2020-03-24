#ifndef __WINTITLE_H__
#define __WINTITLE_H__

#define MAX_CHAR_WINDOW_TEXT	100

class cWinTitle
{
public:
	cWinTitle();
	virtual ~cWinTitle();
	// ----
	void Load();
	// ----
	DWORD dwTitleName;
	char WindowName[MAX_CHAR_WINDOW_TEXT];
};

extern cWinTitle gWinTitle;

#endif