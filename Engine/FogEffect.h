#ifndef __FOGEFFECT_H__
#define __FOGEFFECT_H__

class cFogEffect
{
public:
	static void Load();
	// ----
	BOOL EventMaps();
};

extern cFogEffect gFogEffect;

#endif