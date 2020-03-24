#ifndef __LOADER_H__
#define __LOADER_H__

class cLoader
{
public:
	cLoader();
	virtual ~cLoader();
	// ----
	void Load();
	// ----
	//void Libraries();
	//void DecryptError();
	void DefenseError();
	// ----
	CHAR szPlugin[64];
	CHAR szFuncti[64];
};

extern cLoader gLoader;

#endif