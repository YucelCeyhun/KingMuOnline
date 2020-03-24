#ifndef __LOADSOUND_H__
#define __LOADSOUND_H__

#define LOAD_INTERFACE_TICK		"Data\\Custom\\Sound\\Tick.wav"
#define LOAD_CLEARINVEN_CMD		"Data\\Custom\\Sound\\Clear.wav"
#define LOAD_MIXSJEWELS_CMD		"Data\\Custom\\Sound\\Mix.wav"
#define LOAD_GETSOUND_CMD		"Data\\Custom\\Sound\\Get.wav"
#define LOAD_DROPHORRO_SND		"Data\\Custom\\Sound\\Drop.wav"

class cLoadSound
{
public:
	static int LoadInterfaceWindowTick();
	static int LoadClearCommandSoundGM();
	static int LoadMixsJewelsPackSound();
	static int LoadGetItemOnZenCommand();
	static int LoadDropHorrocruxsSound();
};

extern cLoadSound gLoadSound;

#endif