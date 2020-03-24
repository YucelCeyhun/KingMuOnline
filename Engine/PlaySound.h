#ifndef __PLAYSOUND_H__
#define __PLAYSOUND_H__

class cPlaySound
{
public:
	static int PlayInterfaceWindowTick();
	static int PlayClearCommandSoundGM();
	static int PlayMixsJewelsPackSound();
	static int PlayGetItemOnZenCommand();
	static int PlayDropHorrocruxsSound();
};

extern cPlaySound gPlaySound;

#endif