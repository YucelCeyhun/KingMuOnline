#include "StdAfx.h"

//int IsItemLevelFix = GetPrivateProfileInt("Engine","UseExtendItemLevel",0,ENGINE_INI);

cItemLevel gItemLevel;

void cItemLevel::Load()
{
	//if(IsItemLevelFix == 1)
	//{
		// Fix Item Level +14 & +15 (Glow)
		gToolKit.SetByte((PVOID)(oItemExtendLevelGlow01+2),0x0D);
		gToolKit.SetByte((PVOID)(oItemExtendLevelGlow02+2),0x0D);
		gToolKit.SetByte((PVOID)(oItemExtendLevelGlow03+2),0x0D);
		gToolKit.SetByte((PVOID)(oItemExtendLevelGlow04+2),0x0D);
		// Fix Item Level Extend to +16
		gToolKit.SetByte((PVOID)(oItemExtendLevelPlus16+3),0x10);
		// Fix +14 & +15 Levels (Damage / Defense)
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr01+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr02+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr03+2),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr04+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr05+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr06+2),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr07+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr08+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr09+2),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr10+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr11+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr12+2),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr13+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr14+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr15+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr16+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr17+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr18+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr19+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr20+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr21+2),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr22+2),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr23+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr24+3),0x0B);
		gToolKit.SetByte((PVOID)(oItemExtendLevelAttr25+2),0x0B);
	//}
}