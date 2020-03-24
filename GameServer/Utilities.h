#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include "User.h"

class cUtilits
{
public:
	void PHeadSetB(LPBYTE lpBuf,BYTE head,int size);
    void SendEffect(LPOBJ gObj,BYTE btType);
};

extern cUtilits gUtilits;

#endif