#ifndef __ITEMSOCKET_H__
#define __ITEMSOCKET_H__

#define MAX_ITEM 7680

class cItemSocket
{
public:
	void Load();
	void Start();
	// ----
	struct sITEM
	{
		int Type;
		int Index;
	};
	// ----
	int gItemSocketCount;
	// ----
	sITEM eITEM[MAX_ITEM];
	// ----
	static int ItemSocketInit(int ItemId);
};

extern cItemSocket gItemSocket;

#endif