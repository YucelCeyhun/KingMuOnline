#ifndef __JEWELS_H__
#define __JEWELS_H__

class cJewels
{
public:
	void Load();
	// ----
	void InitJewelsDropSound();
	void InitJewelsPickSound();
	void InitJewelsMoveOnItem();
	void InitJewelsAllowOnItem();
	void InitJewelsInvenSwitch();
	void InitJewelsPricesOnShop();
	void InitJewelsShineEffect();
	void InitJewelsUpdateFlags();
	void InitJewelsBlockDrop();
	// ----
	static void JewelsDropSound();
	static void JewelsPickSound();
	static void JewelsMoveOnItem();
	static void JewelsAllowOnItem();
	static void JewelsInvenSwitch();
	static void JewelsPricesOnShop();
	static void JewelsShineEffect();
	static void JewelsUpdateFlags();
	static void JewelsBlockDrop();
};

extern cJewels gJewels;

#endif