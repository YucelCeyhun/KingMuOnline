#include "StdAfx.h"

cPlaySound gPlaySound;

int cPlaySound::PlayInterfaceWindowTick()
{
	return pPlayWavSound(0x2FC,0,0);
}

int cPlaySound::PlayClearCommandSoundGM()
{
	return pPlayWavSound(0x2FD,0,0);
}

int cPlaySound::PlayMixsJewelsPackSound()
{
	return pPlayWavSound(0x2FE,0,0);
}

int cPlaySound::PlayGetItemOnZenCommand()
{
	return pPlayWavSound(0x2FF,0,0);
}

int cPlaySound::PlayDropHorrocruxsSound()
{
	return pPlayWavSound(0x2FB,0,0);
}