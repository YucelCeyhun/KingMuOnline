#ifndef __BOWS_H__
#define __BOWS_H__

class cBows
{
public:
	void Load();
	void InitCreateBowSkill();
	void InitCreateInvenPos();
	void InitCreateCrossSkill();
	void InitCreateBowDimension();
	void InitCreateBowAndCrossBowPos();
	// ----
	static void CreateBowSkill();
	static void CreateInvenPos();
	static void CreateCrossSkill();
	static void CreateBowDimension();
	static void CreateBowAndCrossBowPos();
};

extern cBows gBows;

#endif