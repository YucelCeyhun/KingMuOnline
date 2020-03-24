#include "StdAfx.h"

cLoadSound gLoadSound;

int cLoadSound::LoadInterfaceWindowTick()
{
	return pLoadWavSound(0x2FC,LOAD_INTERFACE_TICK,1,1);
}

int cLoadSound::LoadClearCommandSoundGM()
{
	return pLoadWavSound(0x2FD,LOAD_CLEARINVEN_CMD,1,1);
}

int cLoadSound::LoadMixsJewelsPackSound()
{
	return pLoadWavSound(0x2FE,LOAD_MIXSJEWELS_CMD,1,1);
}

int cLoadSound::LoadGetItemOnZenCommand()
{
	return pLoadWavSound(0x2FF,LOAD_GETSOUND_CMD,1,1);
}

int cLoadSound::LoadDropHorrocruxsSound()
{
	return pLoadWavSound(0x2FB,LOAD_DROPHORRO_SND,1,1);
}