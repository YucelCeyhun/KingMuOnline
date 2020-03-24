#ifndef __WINGS_H__
#define __WINGS_H__

class cWings
{
public:
	void Load();
	// ----
	void InitFixMoveKanturu();
	void InitShowDurability();
	void InitShowAdditionals();
	void InitAddLuckOption();
	void InitDisableLevelShine();
	void InitAddExcellentStatus();
	void InitHideExcellentText();
	void InitHideExcellentGlow();
	void InitAddAdditionalOption();
	void InitSetMaxDurability();
	void InitAllowRepair();
	// ----
	static void FixMoveKanturu();
	static void ShowDurability();
	static void ShowAdditionals();
	static void AddLuckOption();
	static void DisableLevelShine();
	static void AddExcellentStatus();
	static void HideExcellentText();
	static void HideExcellentGlow();
	static void AddAdditionalOption();
	static void AllowRepair();
	// ----
	static int SetMaxDurability(ObjectItem*lpItem,int ScriptStruct,int Level);
};

extern cWings gWings;

#endif