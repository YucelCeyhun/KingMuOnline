#ifndef __POINT_H__
#define __POINT_H__

class cPoint
{
public:
	void Load();
	// ----
	struct sTYPE
	{
		int Type;
		int Index;
	};
	// ----
	struct sVALUE
	{
		int Value;
	};
	// ----
	int gItemPoint;
	// ----
	sTYPE	eTYPE[512];
	sVALUE	eVALUE[30000];
	// ----
	static int SetPCPointItemPrice(lpItemObj Item,int Points);
	void SetPCPointInvenColor();
};

extern cPoint gPoint;

#endif