#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#define MAX_IP_LENGHT 100
#define MAX_SE_LENGHT 100
#define MAX_VE_LENGHT 100

class cConnection
{
public:
	void Load();
	void Init();
	// ----
	static void Changer();
	// ----
	DWORD dwIPConnection;
	DWORD dwSEConnection;
	DWORD dwVEConnection;
	// ----
	char IP[MAX_IP_LENGHT];
	char SE[MAX_SE_LENGHT];
	char VE[MAX_VE_LENGHT];
};

extern cConnection gConnection;

#endif