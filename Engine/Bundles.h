#ifndef __BUNDLES_H__
#define __BUNDLES_H__

class cBundles
{
public:
	void Load();
	void Init();
	// ----
	void InitDrawNumber();
	//void InitDrawColors();
	static void DrawColors(int iColor);
	static BOOL DrawNumber(int pObj);
	//static void OnDisplayItemStack(cBundles*Item);
	//static char DrawInventoryNumber(int ItemId);
	static void BundledBlessInventoryPos();
	static void BundledBlessInventorySize();
	//static void BundledBlessInventoryPrice();	// -> This is Lahap UnMix
//private:
	//short Index;
};

extern cBundles gBundles;

#endif