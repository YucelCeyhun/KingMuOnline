#ifndef __DAMAGE_H__
#define __DAMAGE_H__

class cDamage
{
public:
	// ----
	void Load();
	// ----
	static void DamageRot(float& X,float& Y,float D);
};

extern cDamage gDamage;

#endif