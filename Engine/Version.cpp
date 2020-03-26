#include "StdAfx.h"
#include <fstream>
#include <iostream>

Version gVControl;

BOOL Version::getVersion(BYTE* clinetVersion) {
	char vcPtr[4];
	ifstream version(VERSION_INI);

	if (!version.is_open()) {
		MessageBox(NULL, "version.ini is not found", "Error", MB_OK);
		return false;
	}
	version >> vcPtr;

	for (int i = 0; i < 4; i++)
	{
		if (vcPtr[i] != clinetVersion[i])
			return false;
	}

	return true;
}