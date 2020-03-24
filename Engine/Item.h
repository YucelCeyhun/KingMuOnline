#ifndef __ITEM_H__
#define __ITEM_H__

//char __stdcall ItemStack(int ItemStartId,int ItemEndId);

class cItem
{
public:
	void Load();
	// ----
	void InitCustomItemsLoad();
	void InitItemTitleColor();
	void InitItemDropTitleColor();
	void InitBladesWizardryDmg();
	void InitBladesWizardryAdd();
	void InitSceptersPetAttack();
	void InitItemSetSpecialStat();
	void InitItemAddGoldSmelt();
	void FixUnicornArmor();
	void FixSeraphimArmor();
	void FixCashShopButtons();
	void InitItemArmorPosition();
	void InitItemDivineNameOnFloor();
	void InitItemRingInventoryPos();
	void InitItemSummonBookInvenPos();
	void InitItemSummonBookInvenRot();
	//void InitItemStack();
	// ----
	static void LoadModels();
	static void LoadTextures();
	static void ItemTitleColor();
	static void ItemDropTitleColor();
	static void BladesWizardryDmg();
	static void BladesWizardryAdd();
	static void SceptersPetAttack();
	static void ItemAddGoldSmelt();
	static void ItemArmorPosition();
	static void ItemDivineNameOnFloor();
	static void ItemRingInventoryPos();
	static void ItemSummonBookInvenPos();
	static void ItemSummonBookInvenRot();
	// ----
	static int SetItemSpecialStat(short ItemID,int Arg2,BYTE SpecialOption,BYTE SpecialValue,int Arg5);
	// ----
	CustomItem m_Item[MAX_CUSTOM_ITEMS];
};

extern cItem gItem;

#endif