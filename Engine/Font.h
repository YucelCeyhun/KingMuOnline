#ifndef __FONT_H__
#define __FONT_H__

#define MAX_CHAR_FONT 100

class cFont
{
public:
	cFont();
	virtual ~cFont();
	// ----
	void Load();
	// ----
	int Bold;
	int Width;
	int Height;
	int Italic;
	int Unicode;
	int Quality;
	int UnderLine;
	int StrikeOut;
	// ----
	char FontName[MAX_CHAR_FONT];
	// ----
	static void LoadNewFont();
};

extern cFont gFont;

#endif