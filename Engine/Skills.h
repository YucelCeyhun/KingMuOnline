#ifndef __SKILLS_H__
#define __SKILLS_H__

class cSkills
{
public:
	cSkills();
	virtual ~cSkills();
	// ----
	void Init();
	void Load();
	// ----
	int iIsSiegeSkill;
};

extern cSkills gSkills;

#endif