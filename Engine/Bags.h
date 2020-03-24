#ifndef __BAGS_H__
#define __BAGS_H__

class cBags
{
public:
	void Load();
	void InitAddInventoryPosition();
	void InitAddInventorySize();
	void InitAddBoxOfLuckThis();
	void InitAddFloorSize();
	// ----
	static void AddBoxOfLuckThis();
	static void AddInventoryPosition();
	static void AddInventorySize();
	static void AddFloorSize();
};

extern cBags gBags;

#endif