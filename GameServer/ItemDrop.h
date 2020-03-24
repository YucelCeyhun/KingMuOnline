#ifndef __ITEMDROP_H__
#define __ITEMDROP_H__

#ifdef __IS_ITEMDROP__

#define TOKENS_ARRAY			15
#define TOKENS_ARRAY_			17
#define MAX_DROP_ITEMS			1000
#define ITEM_DROP_FILE			".\\ItemDrop.ini"

class cItemDrop
{
public:
	void Load();
	// ----
	void Process(int aIndex,int mIndex);
	void ClassProcessMob(int aIndex,int mIndex);
	void ClassProcessMap(int aIndex,int mIndex);
	// ----
	struct 
	{
		int Mob;
		int Type;
		int Index;
		int Level;
		int Options;
		int Luck;
		int LuckDropRate;
		int Skill;
		int SkillDropRate;
		int Exe;
		int ExeDropRate;
		int Anc;
		int AncDropRate;
		int ItemDropRate;
	}ItemMob[MAX_DROP_ITEMS];
	int CountMob;
	// ----
	struct 
	{
		int Map;
		int Type;
		int Index;
		int Level;
		int Options;
		int Luck;
		int LuckDropRate;
		int Skill;
		int SkillDropRate;
		int Exe;
		int ExeDropRate;
		int Anc;
		int AncDropRate;
		int MobMinLvl;
		int MobMaxLvl;
		int ItemDropRate;
	}ItemMap[MAX_DROP_ITEMS];
	int CountMap;
};

extern cItemDrop g_ItemDrop;

#endif	// __IS_ITEMDROP__
#endif	// __ITEMDROP_H__