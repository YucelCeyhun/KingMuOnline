#include "StdAfx.h"

cToolTip gToolTip;

void cToolTip::AddText(PCHAR Text, INT Color, INT Weight)
{
	*(&*(DWORD*)oItemDescriptionText_Color + *(DWORD*)oItemDescriptionText_Line) = Color;
	*(&*(DWORD*)oItemDesctiptionText_Weight + *(DWORD*)oItemDescriptionText_Line) = Weight;
	// ----
	pSetItemTextLine(100 * (*(DWORD*)oItemDescriptionText_Line) + oItemDescriptionText_Point, Text);
	// ----
	*(DWORD*)oItemDescriptionText_Line += 1;
}

static DWORD dwGetTextFromLineByNumber = 0x00402F50;
static DWORD dwGetItemLevelTarget = (0x00595D48 + 3);

void Naked cToolTip::ItemDescriptionFixRena()
{
	static WORD wItem_Pointer;
	static DWORD dwItem_Buffer;
	// ----
	_asm
	{
		MOV wItem_Pointer, CX
		MOV dwGetItemLevelTarget, EBP
	}
	// ----
	if (wItem_Pointer == ItemId(14, 21) && dwGetItemLevelTarget == 0)
	{
		gToolTip.AddText("It is used to exchange with Golden Archer", ItemColor::DarkViolet, ItemWeight::Normal);
	}
	if (wItem_Pointer == ItemId(14, 21) && dwGetItemLevelTarget == 1)
	{
		gToolTip.AddText("Can be used to Create Dark Horrocrux", ItemColor::White, ItemWeight::Normal);
	}
	if (wItem_Pointer == ItemId(14, 21) && dwGetItemLevelTarget == 3)
	{
		gToolTip.AddText("Use in siege registration", ItemColor::White, ItemWeight::Normal);
	}
	// ----
	else if (wItem_Pointer == ItemId(5, 35) && dwGetItemLevelTarget == 10)	// -> Angelical Staff +10
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Item Level +10: (Increase Wizardry Dmg +10%%)", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(5, 35) && dwGetItemLevelTarget == 11)	// -> Angelical Staff +11
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Item Level +11: (Increase Wizardry Dmg +11%%)", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(5, 35) && dwGetItemLevelTarget == 12)	// -> Angelical Staff +12
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Item Level +12: (Increase Wizardry Dmg +12%%)", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(5, 35) && dwGetItemLevelTarget == 13)	// -> Angelical Staff +13
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Item Level +13: (Increase Wizardry Dmg +13%%)", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(5, 35) && dwGetItemLevelTarget == 14)	// -> Angelical Staff +14
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Item Level +14: (Increase Wizardry Dmg +14%%)", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(5, 35) && dwGetItemLevelTarget == 15)	// -> Angelical Staff +15
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Item Level +15: (Increase Wizardry Dmg +15%%)", ItemColor::Blue, ItemWeight::Normal);
	}
	// Helm
	else if (wItem_Pointer == ItemId(7, 100) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 100) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 100) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 100) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 100) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 100) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Armor
	else if (wItem_Pointer == ItemId(8, 100) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 100) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 100) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 100) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 100) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 100) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Pants
	else if (wItem_Pointer == ItemId(9, 100) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 100) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 100) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 100) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 100) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 100) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Gloves
	else if (wItem_Pointer == ItemId(10, 100) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 100) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 100) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 100) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 100) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 100) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Boots
	else if (wItem_Pointer == ItemId(11, 100) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 100) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 100) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 100) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 100) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 100) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Decrease +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Helm
	else if (wItem_Pointer == ItemId(7, 101) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 101) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 101) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 101) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 101) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 101) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Armor
	else if (wItem_Pointer == ItemId(8, 101) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 101) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 101) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 101) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 101) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 101) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Pants
	else if (wItem_Pointer == ItemId(9, 101) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 101) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 101) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 101) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 101) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 101) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Gloves
	else if (wItem_Pointer == ItemId(10, 101) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 101) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 101) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 101) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 101) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 101) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Boots
	else if (wItem_Pointer == ItemId(11, 101) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 101) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 101) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 101) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 101) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 101) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Helm
	else if (wItem_Pointer == ItemId(7, 102) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 102) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 102) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 102) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 102) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(7, 102) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Armor
	else if (wItem_Pointer == ItemId(8, 102) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 102) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 102) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 102) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 102) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(8, 102) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Pants
	else if (wItem_Pointer == ItemId(9, 102) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 102) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 102) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 102) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 102) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(9, 102) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Gloves
	else if (wItem_Pointer == ItemId(10, 102) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 102) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 102) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 102) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 102) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(10, 102) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// Boots
	else if (wItem_Pointer == ItemId(11, 102) && dwGetItemLevelTarget == 10)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +10%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 102) && dwGetItemLevelTarget == 11)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +11%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 102) && dwGetItemLevelTarget == 12)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +12%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 102) && dwGetItemLevelTarget == 13)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +13%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 102) && dwGetItemLevelTarget == 14)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +14%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItem_Pointer == ItemId(11, 102) && dwGetItemLevelTarget == 15)
	{
		gToolTip.AddText("Item Level Option:", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Increase Damage Reflection +15%%", ItemColor::Blue, ItemWeight::Normal);
	}
	// ----
	_asm
	{
		MOV dwItem_Buffer, 0x00595D87
		JMP dwItem_Buffer
	}
}

static BOOL bCreateLostMap_Switcher;
static DWORD dwCreateLostMapItem = 0x007F6680;

void Naked cToolTip::ItemDescriptionFixSymbolKundun()
{
	static WORD wItem_Pointer;
	static DWORD dwItem_Buffer;
	static DWORD dwItem_CondJump = 0x005960C4;
	// ----
	bCreateLostMap_Switcher = FALSE;
	// ----
	_asm
	{
		MOV wItem_Pointer, CX
		MOV dwGetItemLevelTarget, EBP
	}
	// ----
	if (wItem_Pointer == ItemId(14, 28) && dwGetItemLevelTarget == 0)
	{
		bCreateLostMap_Switcher = TRUE;
	}
	// ----
	if (bCreateLostMap_Switcher == TRUE)
	{
		_asm
		{
			PUSH EAX
			PUSH EDI
			CALL dwCreateLostMapItem
			ADD ESP, 0x8
		}
	}
	_asm
	{
		MOV dwItem_Buffer, 0x00595DA4
		JMP dwItem_Buffer
	}
}

void cToolTip::InitItemDescriptionFixSymbolKundun()
{
	gToolKit.SetRange((LPVOID)0x00595D87, 24, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x00595D87, this->ItemDescriptionFixSymbolKundun);
}

void cToolTip::InitItemDescriptionFixRena()
{
	gToolKit.SetRange((LPVOID)0x00595D41, 70, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x00595D41, this->ItemDescriptionFixRena);
}

void Naked cToolTip::ItemDescriptionFixLostMap()
{
	static WORD wItemDescriptionFixFinal_Pointer;
	static DWORD dwItemDescriptionFixFinal_Buffer;
	// ----
	_asm
	{
		MOV wItemDescriptionFixFinal_Pointer, CX
		MOV dwGetItemLevelTarget, EBP
	}
	// ----
	if (wItemDescriptionFixFinal_Pointer == ItemId(14, 42))
	{
		_asm
		{
			MOV dwItemDescriptionFixFinal_Buffer, 0x00595196
			JMP dwItemDescriptionFixFinal_Buffer
		}
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(14, 28) && dwGetItemLevelTarget == 1)
	{
		gToolTip.AddText("Kalima                   Level", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("1                      40~400", ItemColor::WhiteBeige, ItemWeight::Normal);
		gToolTip.AddText("2                    131~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("3                    181~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("4                    231~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("5                    281~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("6                    331~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("7                    350~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Magic stone will appear when you throw it in the screen", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(14, 28) && dwGetItemLevelTarget == 2)
	{
		gToolTip.AddText("Kalima                   Level", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("1                      40~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("2                    131~400", ItemColor::WhiteBeige, ItemWeight::Normal);
		gToolTip.AddText("3                    181~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("4                    231~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("5                    281~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("6                    331~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("7                    350~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Magic stone will appear when you throw it in the screen", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(14, 28) && dwGetItemLevelTarget == 3)
	{
		gToolTip.AddText("Kalima                   Level", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("1                      40~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("2                    131~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("3                    181~400", ItemColor::WhiteBeige, ItemWeight::Normal);
		gToolTip.AddText("4                    231~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("5                    281~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("6                    331~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("7                    350~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Magic stone will appear when you throw it in the screen", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(14, 28) && dwGetItemLevelTarget == 4)
	{
		gToolTip.AddText("Kalima                   Level", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("1                      40~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("2                    131~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("3                    181~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("4                    231~400", ItemColor::WhiteBeige, ItemWeight::Normal);
		gToolTip.AddText("5                    281~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("6                    331~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("7                    350~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Magic stone will appear when you throw it in the screen", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(14, 28) && dwGetItemLevelTarget == 5)
	{
		gToolTip.AddText("Kalima                   Level", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("1                      40~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("2                    131~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("3                    181~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("4                    231~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("5                    281~400", ItemColor::WhiteBeige, ItemWeight::Normal);
		gToolTip.AddText("6                    331~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("7                    350~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Magic stone will appear when you throw it in the screen", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(14, 28) && dwGetItemLevelTarget == 6)
	{
		gToolTip.AddText("Kalima                   Level", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("1                      40~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("2                    131~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("3                    181~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("4                    231~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("5                    281~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("6                    331~400", ItemColor::WhiteBeige, ItemWeight::Normal);
		gToolTip.AddText("7                    350~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Magic stone will appear when you throw it in the screen", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(14, 28) && dwGetItemLevelTarget == 7)
	{
		gToolTip.AddText("Kalima                   Level", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("1                      40~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("2                    131~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("3                    181~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("4                    231~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("5                    281~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("6                    331~400", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("7                    350~400", ItemColor::WhiteBeige, ItemWeight::Normal);
		gToolTip.AddText("Magic stone will appear when you throw it in the screen", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 150) && dwGetItemLevelTarget == 0) // Bundled Jewel of Level +0
	{
		gToolTip.AddText("10 Jewel of Level is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 150) && dwGetItemLevelTarget == 1) // Bundled Jewel of Level +1
	{
		gToolTip.AddText("20 Jewel of Level is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 150) && dwGetItemLevelTarget == 2) // Bundled Jewel of Level +2
	{
		gToolTip.AddText("30 Jewel of Level is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 150) && dwGetItemLevelTarget == 3) // Bundled Jewel of Level +3
	{
		gToolTip.AddText("40 Jewel of Level is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 150) && dwGetItemLevelTarget == 4) // Bundled Jewel of Level +4
	{
		gToolTip.AddText("50 Jewel of Level is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 150) && dwGetItemLevelTarget == 5) // Bundled Jewel of Level +5
	{
		gToolTip.AddText("60 Jewel of Level is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 151) && dwGetItemLevelTarget == 0) // Bundled Jewel of Luck +0
	{
		gToolTip.AddText("10 Jewel of Luck is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 151) && dwGetItemLevelTarget == 1) // Bundled Jewel of Luck +1
	{
		gToolTip.AddText("20 Jewel of Luck is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 151) && dwGetItemLevelTarget == 2) // Bundled Jewel of Luck +2
	{
		gToolTip.AddText("30 Jewel of Luck is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 151) && dwGetItemLevelTarget == 3) // Bundled Jewel of Luck +3
	{
		gToolTip.AddText("40 Jewel of Luck is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 151) && dwGetItemLevelTarget == 4) // Bundled Jewel of Luck +4
	{
		gToolTip.AddText("50 Jewel of Luck is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 151) && dwGetItemLevelTarget == 5) // Bundled Jewel of Luck +5
	{
		gToolTip.AddText("60 Jewel of Luck is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 152) && dwGetItemLevelTarget == 0) // Bundled Jewel of Skill +0
	{
		gToolTip.AddText("10 Jewel of Skill is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 152) && dwGetItemLevelTarget == 1) // Bundled Jewel of Skill +1
	{
		gToolTip.AddText("20 Jewel of Skill is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 152) && dwGetItemLevelTarget == 2) // Bundled Jewel of Skill +2
	{
		gToolTip.AddText("30 Jewel of Skill is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 152) && dwGetItemLevelTarget == 3) // Bundled Jewel of Skill +3
	{
		gToolTip.AddText("40 Jewel of Skill is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 152) && dwGetItemLevelTarget == 4) // Bundled Jewel of Skill +4
	{
		gToolTip.AddText("50 Jewel of Skill is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 152) && dwGetItemLevelTarget == 5) // Bundled Jewel of Skill +5
	{
		gToolTip.AddText("60 Jewel of Skill is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 153) && dwGetItemLevelTarget == 0) // Bundled Jewel of Option +0
	{
		gToolTip.AddText("10 Jewel of Option is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 153) && dwGetItemLevelTarget == 1) // Bundled Jewel of Option +1
	{
		gToolTip.AddText("20 Jewel of Option is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 153) && dwGetItemLevelTarget == 2) // Bundled Jewel of Option +2
	{
		gToolTip.AddText("30 Jewel of Option is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 153) && dwGetItemLevelTarget == 3) // Bundled Jewel of Option +3
	{
		gToolTip.AddText("40 Jewel of Option is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 153) && dwGetItemLevelTarget == 4) // Bundled Jewel of Option +4
	{
		gToolTip.AddText("50 Jewel of Option is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 153) && dwGetItemLevelTarget == 5) // Bundled Jewel of Option +5
	{
		gToolTip.AddText("60 Jewel of Option is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 154) && dwGetItemLevelTarget == 0) // Bundled Jewel of Excellent +0
	{
		gToolTip.AddText("10 Jewel of Excellent is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 154) && dwGetItemLevelTarget == 1) // Bundled Jewel of Excellent +1
	{
		gToolTip.AddText("20 Jewel of Excellent is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 154) && dwGetItemLevelTarget == 2) // Bundled Jewel of Excellent +2
	{
		gToolTip.AddText("30 Jewel of Excellent is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 154) && dwGetItemLevelTarget == 3) // Bundled Jewel of Excellent +3
	{
		gToolTip.AddText("40 Jewel of Excellent is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 154) && dwGetItemLevelTarget == 4) // Bundled Jewel of Excellent +4
	{
		gToolTip.AddText("50 Jewel of Excellent is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 154) && dwGetItemLevelTarget == 5) // Bundled Jewel of Excellent +5
	{
		gToolTip.AddText("60 Jewel of Excellent is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 155) && dwGetItemLevelTarget == 0) // Bundled Jewel of Ancient +0
	{
		gToolTip.AddText("10 Jewel of Ancient is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 155) && dwGetItemLevelTarget == 1) // Bundled Jewel of Ancient +1
	{
		gToolTip.AddText("20 Jewel of Ancient is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 155) && dwGetItemLevelTarget == 2) // Bundled Jewel of Ancient +2
	{
		gToolTip.AddText("30 Jewel of Ancient is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 155) && dwGetItemLevelTarget == 3) // Bundled Jewel of Ancient +3
	{
		gToolTip.AddText("40 Jewel of Ancient is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 155) && dwGetItemLevelTarget == 4) // Bundled Jewel of Ancient +4
	{
		gToolTip.AddText("50 Jewel of Ancient is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 155) && dwGetItemLevelTarget == 5) // Bundled Jewel of Ancient +5
	{
		gToolTip.AddText("60 Jewel of Ancient is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 156) && dwGetItemLevelTarget == 0) // Bundled Jewel of Socket +0
	{
		gToolTip.AddText("10 Jewel of Socket is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 156) && dwGetItemLevelTarget == 1) // Bundled Jewel of Socket +1
	{
		gToolTip.AddText("20 Jewel of Socket is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 156) && dwGetItemLevelTarget == 2) // Bundled Jewel of Socket +2
	{
		gToolTip.AddText("30 Jewel of Socket is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 156) && dwGetItemLevelTarget == 3) // Bundled Jewel of Socket +3
	{
		gToolTip.AddText("40 Jewel of Socket is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 156) && dwGetItemLevelTarget == 4) // Bundled Jewel of Socket +4
	{
		gToolTip.AddText("50 Jewel of Socket is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(12, 156) && dwGetItemLevelTarget == 5) // Bundled Jewel of Socket +5
	{
		gToolTip.AddText("60 Jewel of Socket is combined", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 0) // Dark Wolf +0
	{
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 1)	// Dark Wolf +1
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +30%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +5%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 2)	// Dark Wolf +2
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +31%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +6%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 3)	// Dark Wolf +3
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +32%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +7%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 4)	// Dark Wolf +4
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +33%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +8%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 5)	// Dark Wolf +5
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +34%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +9%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 6)	// Dark Wolf +6
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +35%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +15%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 7)	// Dark Wolf +7
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +36%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +16%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 8)	// Dark Wolf +8
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +37%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +17%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget == 9)	// Dark Wolf +9
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +38%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +18%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 97) && dwGetItemLevelTarget >= 10 && dwGetItemLevelTarget <= 15)	// Dark Wolf +10 ~ +15
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +39%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +19%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Dark Wolf", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 0) // Sable Pet +0
	{
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 1)	// Sable Pet +1
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +30%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +5%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 2)	// Sable Pet +2
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +31%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +6%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 3)	// Sable Pet +3
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +32%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +7%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 4)	// Sable Pet +4
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +33%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +8%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 5)	// Sable Pet +5
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +34%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +9%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 6)	// Sable Pet +6
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +35%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +15%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 7)	// Sable Pet +7
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +36%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +16%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 8)	// Sable Pet +8
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +37%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +17%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget == 9)	// Sable Pet +9
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +38%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +18%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 98) && dwGetItemLevelTarget >= 10 && dwGetItemLevelTarget <= 15)	// Sable Pet +10 ~ +15
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +39%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +19%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Sable Fang", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 0) // Tiger Pet +0
	{
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 1) // Tiger Pet +1
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +30%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +5%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 2) // Tiger Pet +2
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +31%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +6%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 3) // Tiger Pet +3
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +32%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +7%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 4) // Tiger Pet +4
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +33%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +8%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 5) // Tiger Pet +5
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +34%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +9%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 6) // Tiger Pet +6
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +35%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +15%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 7) // Tiger Pet +7
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +36%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +16%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 8) // Tiger Pet +8
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +37%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +17%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget == 9) // Tiger Pet +9
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +38%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +18%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 99) && dwGetItemLevelTarget >= 10 && dwGetItemLevelTarget <= 15) // Tiger Pet +10~+15
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +39%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +19%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Mistic Tiger", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 0) // Lyon Pet +0
	{
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 1) // Lyon Pet +1
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +30%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +5%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 2) // Lyon Pet +2
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +31%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +6%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 3) // Lyon Pet +3
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +32%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +7%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 4) // Lyon Pet +4
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +33%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +8%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 5) // Lyon Pet +5
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +34%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +9%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 6) // Lyon Pet +6
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +35%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +15%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 7) // Lyon Pet +7
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +36%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +16%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 8) // Lyon Pet +8
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +37%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +17%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget == 9) // Lyon Pet +9
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +38%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +18%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 100) && dwGetItemLevelTarget >= 10 && dwGetItemLevelTarget <= 15) // Lyon Pet +10~+15
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +39%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +19%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Giant Lyon", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 0) // Lycan Pet +0
	{
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 1) // Lycan Pet +1
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +30%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +5%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 2) // Lycan Pet +2
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +31%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +6%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 3) // Lycan Pet +3
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +32%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +7%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 4) // Lycan Pet +4
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +33%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +8%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 5) // Lycan Pet +5
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +34%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +9%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 6) // Lycan Pet +6
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +35%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +15%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 7) // Lycan Pet +7
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +36%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +16%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +11%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 8) // Lycan Pet +8
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +37%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +17%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +12%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget == 9) // Lycan Pet +9
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +38%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +18%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +13%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 101) && dwGetItemLevelTarget >= 10 && dwGetItemLevelTarget <= 15) // Lycan Pet +10~+15
	{
		gToolTip.AddText("Increase Damage\\Wizardry Dmg +39%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defense Success Rate +19%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increased Damage Absorbtion +14%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Can be used to Summon Lycan Wolf", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 78) && dwGetItemLevelTarget >= 0 && dwGetItemLevelTarget <= 15)	// Unicorn Pet +0~+15
	{
		gToolTip.AddText("Auto-collects zen arround you.", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increases Zen by 50%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defensive skill +50", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Muun Pet System", ItemColor::Green, ItemWeight::Bold);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 77) && dwGetItemLevelTarget >= 0 && dwGetItemLevelTarget <= 15)	// Skeleton Pet +0~+15
	{
		gToolTip.AddText("Auto-collects zen arround you.", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increases Zen by 50%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defensive skill +50", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Muun Pet System", ItemColor::Green, ItemWeight::Bold);
	}
	else if (wItemDescriptionFixFinal_Pointer == ItemId(13, 79) && dwGetItemLevelTarget >= 0 && dwGetItemLevelTarget <= 15)	// Sparky Pet +0~+15
	{
		gToolTip.AddText("Auto-collects zen arround you.", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increases Zen by 50%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Defensive skill +50", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Muun Pet System", ItemColor::Green, ItemWeight::Bold);
	}
	// ----
	_asm
	{
		MOV dwItemDescriptionFixFinal_Buffer, 0x005951A0
		JMP dwItemDescriptionFixFinal_Buffer
	}
}

void cToolTip::InitItemDescriptionFixLostMap()
{
	gToolKit.SetRange((LPVOID)0x0059518F, 7, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0059518F, this->ItemDescriptionFixLostMap);
}

void Naked cToolTip::ItemDescriptionText()
{
	static WORD wItemDescriptionText_Pointer;
	static DWORD dwItemDescriptionText_Buffer;
	// ----
	_asm
	{
		MOV AX, WORD PTR DS : [EDI]
		MOV wItemDescriptionText_Pointer, AX
	}
	// ----
	if (wItemDescriptionText_Pointer == ItemId(14, 14))
	{
		gToolTip.AddText("It is used to increase your item level up to 7,8,9", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(0, 29) || wItemDescriptionText_Pointer == ItemId(0, 30))
	{
		gToolTip.AddText("Nemesis Custom Weapon", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(0, 32) && wItemDescriptionText_Pointer <= ItemId(0, 255))
	{
		gToolTip.AddText("Nemesis Custom Weapon", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(1, 9) && wItemDescriptionText_Pointer <= ItemId(1, 255))
	{
		gToolTip.AddText("Nemesis Custom Weapon", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(2, 19) && wItemDescriptionText_Pointer <= ItemId(2, 255))
	{
		gToolTip.AddText("Nemesis Custom Weapon", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(3, 12) && wItemDescriptionText_Pointer <= ItemId(3, 255))
	{
		gToolTip.AddText("Nemesis Custom Weapon", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(4, 25) && wItemDescriptionText_Pointer <= ItemId(4, 255))
	{
		gToolTip.AddText("Nemesis Custom Weapon", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(5, 35) && wItemDescriptionText_Pointer <= ItemId(5, 255))
	{
		gToolTip.AddText("Nemesis Custom Weapon", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(6, 22) && wItemDescriptionText_Pointer <= ItemId(6, 255))
	{
		gToolTip.AddText("Nemesis Custom Weapon", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(7, 54) && wItemDescriptionText_Pointer <= ItemId(7, 99)
		|| wItemDescriptionText_Pointer >= ItemId(7, 103) && wItemDescriptionText_Pointer <= ItemId(7, 255))
	{
		gToolTip.AddText("Nemesis Custom Set", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(8, 54) && wItemDescriptionText_Pointer <= ItemId(8, 99)
		|| wItemDescriptionText_Pointer >= ItemId(8, 103) && wItemDescriptionText_Pointer <= ItemId(8, 255))
	{
		gToolTip.AddText("Nemesis Custom Set", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(9, 54) && wItemDescriptionText_Pointer <= ItemId(9, 99)
		|| wItemDescriptionText_Pointer >= ItemId(9, 103) && wItemDescriptionText_Pointer <= ItemId(9, 255))
	{
		gToolTip.AddText("Nemesis Custom Set", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(10, 54) && wItemDescriptionText_Pointer <= ItemId(10, 99)
		|| wItemDescriptionText_Pointer >= ItemId(10, 103) && wItemDescriptionText_Pointer <= ItemId(10, 255))
	{
		gToolTip.AddText("Nemesis Custom Set", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(11, 54) && wItemDescriptionText_Pointer <= ItemId(11, 99)
		|| wItemDescriptionText_Pointer >= ItemId(11, 103) && wItemDescriptionText_Pointer <= ItemId(11, 255))
	{
		gToolTip.AddText("Nemesis Custom Set", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer >= ItemId(12, 236) && wItemDescriptionText_Pointer <= ItemId(12, 238)	// -> 2.5 Level Wings
		|| wItemDescriptionText_Pointer >= ItemId(12, 240) && wItemDescriptionText_Pointer <= ItemId(12, 248)			// -> 4th Level Wings
		|| wItemDescriptionText_Pointer == ItemId(12, 252))	// -> Wings of Deathless (Added: 22-12-16)
	{
		gToolTip.AddText("Nemesis Custom Wing", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(12, 249))	// -> Imperial Dragon Wings
	{
		gToolTip.AddText("Special Wings Limited Edition", ItemColor::Gold, ItemWeight::Normal);
		gToolTip.AddText("Wings from Valakias Dragon God", ItemColor::Gold, ItemWeight::Normal);
		//gToolTip.AddText("God Item Option:",ItemColor::Green,ItemWeight::Normal);
		//gToolTip.AddText("Option 1: Absorb Extra Dmg +50",ItemColor::Blue,ItemWeight::Normal);
		//gToolTip.AddText("Option 2: Reflect Extra Dmg +40",ItemColor::Blue,ItemWeight::Normal);
		//gToolTip.AddText("Option 3: Increase Defense Rate +30",ItemColor::Blue,ItemWeight::Normal);
		gToolTip.AddText("Nemesis Custom Wing", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(12, 250) || wItemDescriptionText_Pointer == ItemId(12, 251))
	{
		gToolTip.AddText("Limited Edition Wings", ItemColor::Gold, ItemWeight::Bold);
		gToolTip.AddText("Season 8 Special Wings", ItemColor::Gold, ItemWeight::Bold);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 156))
	{
		gToolTip.AddText("My dreaming ends.Your nightmare begins", ItemColor::Gold, ItemWeight::Bold);
		gToolTip.AddText("Time has come.You will burn", ItemColor::Red, ItemWeight::Bold);
	}
	/*
	else if(wItemDescriptionText_Pointer == ItemId(12,150))
	{
		gToolTip.AddText("10 Jewel of Level is combined",ItemColor::White,ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling",ItemColor::White,ItemWeight::Normal);
	}
	else if(wItemDescriptionText_Pointer == ItemId(12,151))
	{
		gToolTip.AddText("10 Jewel of Luck is combined",ItemColor::White,ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling",ItemColor::White,ItemWeight::Normal);
	}
	else if(wItemDescriptionText_Pointer == ItemId(12,152))
	{
		gToolTip.AddText("10 Jewel of Skill is combined",ItemColor::White,ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling",ItemColor::White,ItemWeight::Normal);
	}
	else if(wItemDescriptionText_Pointer == ItemId(12,153))
	{
		gToolTip.AddText("10 Jewel of Option is combined",ItemColor::White,ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling",ItemColor::White,ItemWeight::Normal);
	}
	else if(wItemDescriptionText_Pointer == ItemId(12,154))
	{
		gToolTip.AddText("10 Jewel of Excellent is combined",ItemColor::White,ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling",ItemColor::White,ItemWeight::Normal);
	}
	else if(wItemDescriptionText_Pointer == ItemId(12,155))
	{
		gToolTip.AddText("10 Jewel of Ancient is combined",ItemColor::White,ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling",ItemColor::White,ItemWeight::Normal);
	}
	else if(wItemDescriptionText_Pointer == ItemId(12,156))
	{
		gToolTip.AddText("10 Jewel of Socket is combined",ItemColor::White,ItemWeight::Normal);
		gToolTip.AddText("Can be used after of dismantling",ItemColor::White,ItemWeight::Normal);
	}
	*/
	else if (wItemDescriptionText_Pointer == ItemId(13, 51)) // Scroll of Blood
	{
		gToolTip.AddText("Required to Enter on Illusion Temple", ItemColor::Red, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 9)) // Ale
	{
		gToolTip.AddText("It is used to increase speed attack", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 10)) // Town Portal Scroll
	{
		gToolTip.AddText("It is used to move to the city", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 20)) // Remedy of Love
	{
		gToolTip.AddText("It is used to increase speed attack", ItemColor::DarkViolet, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 27)) // Ancient Metal
	{
		gToolTip.AddText("Can be used to Mix Ancient Items", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 29)) // Symbol of Kundun
	{
		gToolTip.AddText("Can be used to Create Lost Map", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 101)) // Box of Pandora
	{
		gToolTip.AddText("Drop it and you will receive items or zen", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 102)) // Blue Legendary Box
	{
		gToolTip.AddText("Drop it and you will receive items or zen", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 103)) // Red Legendary Box
	{
		gToolTip.AddText("Drop it and you will receive items or zen", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 104)) // Green Legendary Box
	{
		gToolTip.AddText("Drop it and you will receive items or zen", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 170)) // Crystal Feather
	{
		gToolTip.AddText("It is used to Mix 4th Wings", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 171)) // Legend Amulet
	{
		gToolTip.AddText("Can be used to create Wings of Legend", ItemColor::Gold, ItemWeight::Normal);
		gToolTip.AddText("Success Rate: 100%%", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 172)) // Divine Stone
	{
		gToolTip.AddText("Can be used to create Absolute Items", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 173))	// Jewel of Dark Chaos
	{
		gToolTip.AddText("It is used to combine Chaos and Dark Items", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 174)) // Deathless Amulet
	{
		gToolTip.AddText("Can be used to create Wings of Deathless", ItemColor::Gold, ItemWeight::Normal);
		gToolTip.AddText("Success Rate: 100%%", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 240))
	{
		gToolTip.AddText("It is used to up your item level +15", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 241))
	{
		gToolTip.AddText("It is used to add luck to your item", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 242))
	{
		gToolTip.AddText("It is used to add skill to your item", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 243))
	{
		gToolTip.AddText("It is used to up your item option +28", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 244))
	{
		gToolTip.AddText("It is used to add excellent status to your item", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 245))
	{
		gToolTip.AddText("It is used to add ancient status to your item", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 246))
	{
		gToolTip.AddText("It is used to add socket slots to your item", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(7, 100))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteRed, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(8, 100))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteRed, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(9, 100))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteRed, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(10, 100))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteRed, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(11, 100))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteRed, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(7, 101))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(8, 101))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(9, 101))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(10, 101))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(11, 101))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBeige, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(7, 102))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(8, 102))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(9, 102))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(10, 102))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(11, 102))
	{
		gToolTip.AddText("Defense Increased 20%%", ItemColor::WhiteBlue, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 200))
	{
		gToolTip.AddText("It is used to evolve your 'Dragon Set' Parts", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 201))
	{
		gToolTip.AddText("It is used to evolve your 'Guardian Set' Parts", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 202))
	{
		gToolTip.AddText("It is used to evolve your 'Legendary Set' Parts", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 150)) // -> Fragment of Fire
	{
		gToolTip.AddText("Collect this item to create 'Gem of Life (Fire)'", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 151)) // -> Fragment of Earth
	{
		gToolTip.AddText("Collect this item to create 'Gem of Life (Earth)'", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 152)) // -> Fragment of Water
	{
		gToolTip.AddText("Collect this item to create 'Gem of Life (Water)'", ItemColor::White, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 140)) // -> Horrocrux of Fire
	{
		gToolTip.AddText("Increase Min Attack Damage Rate +10%%", ItemColor::Red, ItemWeight::Normal);
		gToolTip.AddText("Increase Max Attack Damage Rate +30%%", ItemColor::Red, ItemWeight::Normal);
		gToolTip.AddText("Increase Reflect Damage Rate Chance +5%%", ItemColor::Red, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 141)) // -> Horrocrux of Water
	{
		gToolTip.AddText("Increase Min Attack Damage Rate +10%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Max Defense Success Rate +30%%", ItemColor::Blue, ItemWeight::Normal);
		gToolTip.AddText("Increase Reflect Damage Rate Chance +5%%", ItemColor::Blue, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 142))	// -> Horrocrux of Earth
	{
		gToolTip.AddText("Increase Max Attack Damage Rate +20%%", ItemColor::Gold, ItemWeight::Normal);
		gToolTip.AddText("Increase Min Defense Success Rate +10%%", ItemColor::Gold, ItemWeight::Normal);
		gToolTip.AddText("Increase Reflect Damage Rate Chance +3%%", ItemColor::Gold, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 143))	// -> Horrocrux of Wind
	{
		gToolTip.AddText("Increase Excellent Damage Rate Chance +5%%", ItemColor::Green, ItemWeight::Normal);
		gToolTip.AddText("Increase Critical Damage Rate Change +8%%", ItemColor::Green, ItemWeight::Normal);
		gToolTip.AddText("Increase Reflect Damage Rate Chance +1%%", ItemColor::Green, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 144)) // -> Horrocrux of Thunder
	{
		gToolTip.AddText("Increase Excellent Damage Rate Chance +9%%", ItemColor::Violet, ItemWeight::Normal);
		gToolTip.AddText("Increase Health Recuperation Chance +4%%", ItemColor::Violet, ItemWeight::Normal);
		gToolTip.AddText("Increase Reflect Damage Rate Chance +4%%", ItemColor::Violet, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(13, 145)) // -> Horrocrux of Ice
	{
		gToolTip.AddText("Increase Excellent Damage Rate Chance +6%%", ItemColor::Gray, ItemWeight::Normal);
		gToolTip.AddText("Increase Critical Damage Rate Chance +3%%", ItemColor::Gray, ItemWeight::Normal);
		gToolTip.AddText("Increase Reflect Damage Rate Chance +2%%", ItemColor::Gray, ItemWeight::Normal);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 210))	// -> Book of Summon Dark Phoenix
	{
		gToolTip.AddText("Can be used to Summon Dark Phoenix", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Cannot be used on Safety Zones", ItemColor::WhiteRed, ItemWeight::Bold);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 211))	// -> Book of Summon Red Giant Dragon
	{
		gToolTip.AddText("Can be used to Summon Red Giant Dragon", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Cannot be used on Safety Zones", ItemColor::WhiteRed, ItemWeight::Bold);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 212))	// -> Book of Summon Kundun Boss
	{
		gToolTip.AddText("Can be used to Summon Kundun Boss", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Cannot be used on Safety Zones", ItemColor::WhiteRed, ItemWeight::Bold);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 213))	// -> Book of Summon Giant Drakan
	{
		gToolTip.AddText("Can be used to Summon Giant Drakan", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Cannot be used on Safety Zones", ItemColor::WhiteRed, ItemWeight::Bold);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 214))	// -> Book of Summon Iron Knight
	{
		gToolTip.AddText("Can be used to Summon Iron Knight", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Cannot be used on Safety Zones", ItemColor::WhiteRed, ItemWeight::Bold);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 215))	// -> Book of Summon Selupan Boss
	{
		gToolTip.AddText("Can be used to Summon Selupan Boss", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Cannot be used on Safety Zones", ItemColor::WhiteRed, ItemWeight::Bold);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 216))	// -> Book of Summon Thunder Nappin
	{
		gToolTip.AddText("Can be used to Summon Thunder Nappin", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Cannot be used on Safety Zones", ItemColor::WhiteRed, ItemWeight::Bold);
	}
	else if (wItemDescriptionText_Pointer == ItemId(14, 217))	// -> Book of Summon Hell Maine
	{
		gToolTip.AddText("Can be used to Summon Hell Maine", ItemColor::White, ItemWeight::Normal);
		gToolTip.AddText("Cannot be used on Safety Zones", ItemColor::WhiteRed, ItemWeight::Bold);
	}
	// ----
	_asm
	{
		MOV dwItemDescriptionText_Buffer, oItemDescriptionText_Next
		JMP dwItemDescriptionText_Buffer
	}
}

void cToolTip::InitItemDescriptionText()
{
	gToolKit.SetRange((LPVOID)oItemDescriptionText_Hook, 75, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemDescriptionText_Hook, this->ItemDescriptionText);
}

void Naked cToolTip::ItemDescriptionFixSymbolKundunAdd()
{
	static DWORD dwItem_Load = 0x00595F58;
	static DWORD dwItem_Jump = 0x005960C4;
	// ----
	_asm
	{
		CMP AX, ItemId(13, 34)
		JE AddClawOfBeast
		CMP AX, ItemId(14, 29)
		JE AddSymbolOfKundun
		CMP AX, ItemId(13, 150)
		JE AddElementalFragment
		CMP AX, ItemId(13, 151)
		JE AddElementalFragment
		CMP AX, ItemId(13, 152)
		JE AddElementalFragment
		// ----
		JNZ ReturnLabel
		// ----
		AddElementalFragment :
		// ----
		XOR ECX, ECX
			PUSH 0x1E
			MOV CL, BYTE PTR DS : [ESI + 0x16]
			PUSH ECX
			PUSH 0x49D
			JMP dwItem_Jump
			// ----
			AddSymbolOfKundun :
		// ----
		XOR ECX, ECX
			PUSH 0x05
			MOV CL, BYTE PTR DS : [ESI + 0x16]
			PUSH ECX
			PUSH 0x49D
			JMP dwItem_Jump
			// ----
			AddClawOfBeast :
		// ----
		XOR ECX, ECX
			PUSH 0x0A
			MOV CL, BYTE PTR DS : [ESI + 0x16]
			PUSH ECX
			PUSH 0x49D
			JMP dwItem_Jump
			// ----
			ReturnLabel :
		// ----
		JMP dwItem_Load
	}
}

void cToolTip::InitItemDescriptionFixSymbolKundunAdd()
{
	gToolKit.SetRange((LPVOID)0x00595F40, 24, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x00595F40, this->ItemDescriptionFixSymbolKundunAdd);
}

void Naked cToolTip::ItemDescriptionAddOptionTypePosText()
{
	static DWORD dwItemAddDescription_Search = 0x00402F50;
	static DWORD dwItemAddDescription_Decrypt = 0x00851348;
	static DWORD dwItemAddDescription_Jumping = 0x005979F0;
	static DWORD dwItemAddDescription_Return = 0x005978D5;
	// ----
	_asm
	{
		CMP CX, 0x1A2A
		JNZ NextItem1
		XOR ESI, ESI
		// ----
		AddDescriptionLabel1 :
		// ----
		LEA EDX, [ESI + 0x3D0]
			PUSH 0xFF
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , EBP
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x07
			JL AddDescriptionLabel1
			JMP dwItemAddDescription_Jumping
			// ----
			NextItem1 :
		// ----
		CMP CX, 0x1A99				// -> ItemId(13,153)
			JNZ NextItem2
			XOR ESI, ESI
			// ----
			AddDescriptionLabel1E :
		// ----
		LEA EDX, [ESI + 0xAE6]			// -> Text.bmd Number Line from: 2790
			PUSH 0x0					// -> +0
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , 0x03
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x01
			JL AddDescriptionLabel1E
			JMP AddDescriptionLabel1B
			JMP dwItemAddDescription_Jumping
			// ----
			AddDescriptionLabel1B :
		// ----
		LEA EDX, [ESI + 0xAE8]			// -> Text.bmd Number Line from: 2792
			PUSH 0x64					// +100
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , EBP
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x04
			JL AddDescriptionLabel1B
			JMP dwItemAddDescription_Jumping
			// ----
			NextItem2 :
		// ----
		CMP CX, 0x1A9A				// -> ItemId(13,154)
			JNZ NextItem3
			XOR ESI, ESI
			// ----
			AddDescriptionLabel1D :
		// ----
		LEA EDX, [ESI + 0xAEC]			// -> Text.bmd Number Line from: 2796
			PUSH 0x0					// -> +0
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , 0x0B
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x01
			JL AddDescriptionLabel1D
			JMP AddDescriptionLabel1C
			JMP dwItemAddDescription_Jumping
			// ----
			AddDescriptionLabel1C :
		// ----
		LEA EDX, [ESI + 0xAEE]			// -> Text.bmd Number Line from: 2798
			PUSH 0x96					// -> +150
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , EBP
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x04
			JL AddDescriptionLabel1C
			JMP dwItemAddDescription_Jumping
			// ----
			NextItem3 :
		// ----
		CMP CX, 0x1A9B				// -> ItemId(13,155)
			JNZ NextItem4
			XOR ESI, ESI
			// ----
			AddDescriptionLabel1A :
		// ----
		LEA EDX, [ESI + 0xAF3]			// -> Text.bmd Number Line from: 2803
			PUSH 0x0					// -> +0
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , 0x06
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x01
			JL AddDescriptionLabel1A
			JMP AddDescriptionLabel1F
			JMP dwItemAddDescription_Jumping
			// ----
			AddDescriptionLabel1F :
		// ----
		LEA EDX, [ESI + 0xAF5]			// -> Text.bmd Number Line from: 2805
			PUSH 0xFA					// -> +250
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , EBP
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x04
			JL AddDescriptionLabel1F
			JMP dwItemAddDescription_Jumping
			// ----
			NextItem4 :
		// ----
		CMP CX, 0x18F9				// -> ItemId(12,249)
			JNZ ReturnLoad
			XOR ESI, ESI
			// ----
			AddDescriptionLabel_Wing01 :
		// ----
		LEA EDX, [ESI + 0xAFA]			// -> Text.bmd Number Line from: 2810
			PUSH 0x0					// -> +0
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , 0x03
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x01
			JL AddDescriptionLabel_Wing01
			JMP AddDescriptionLabel_Wing02
			JMP dwItemAddDescription_Jumping
			// ----
			AddDescriptionLabel_Wing02 :
		// ----
		LEA EDX, [ESI + 0xAFC]			// -> Text.bmd Number Line from: 2812
			PUSH 0x32					// -> +50
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , EBP
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x01
			JL AddDescriptionLabel_Wing02
			JMP AddDescriptionLabel_Wing03
			JMP dwItemAddDescription_Jumping
			// ----
			AddDescriptionLabel_Wing03 :
		// ----
		LEA EDX, [ESI + 0xAFE]			// -> Text.bmd Number Line from: 2812
			PUSH 0x28					// -> +40
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , EBP
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x01
			JL AddDescriptionLabel_Wing03
			JMP AddDescriptionLabel_Wing04
			JMP dwItemAddDescription_Jumping
			// ----
			AddDescriptionLabel_Wing04 :
		// ----
		LEA EDX, [ESI + 0xB00]			// -> Text.bmd Number Line from: 2816
			PUSH 0x1E					// -> +30
			PUSH EDX
			MOV ECX, 0x7AAD828
			CALL dwItemAddDescription_Search
			PUSH EAX
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA EAX, [EAX * 0x4 + EAX]
			LEA ECX, [EAX * 0x4 + 0x7BE1238]
			PUSH ECX
			CALL dwItemAddDescription_Decrypt
			MOV EAX, DWORD PTR DS : [0x7C13C7C]
			ADD ESP, 0xC
			MOV DWORD PTR DS : [EAX * 0x4 + 0x7BE239C] , EBP
			INC EAX
			INC ESI
			MOV DWORD PTR DS : [0x7C13C7C] , EAX
			CMP ESI, 0x01
			JL AddDescriptionLabel_Wing04
			JMP dwItemAddDescription_Jumping
			// ----
			ReturnLoad :
		// ----
		JMP dwItemAddDescription_Return
	}
}

void cToolTip::InitItemDescriptionAddOptionTypePosText()
{
	gToolKit.SetRange((LPVOID)oItemAddDescriptionOpt_Hook, 88, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemAddDescriptionOpt_Hook, this->ItemDescriptionAddOptionTypePosText);
}

void cToolTip::ItemNameColorDrop(INT ColorId)
{
	if (ColorId == DropWhite)	// -> White Item Name
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x00);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x00);
	}
	if (ColorId == DropBlue)	// -> Blue Item Name
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x00);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x00);
	}
	if (ColorId == DropRed)		// -> Red Item Name
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x00);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x00);
	}
	if (ColorId == DropGold)	// -> Gold Item Name
	{
		//clR = 1.000000f;
		//clG = 0.800000f;
		//clB = 0.100000f;	// -> TRUE GOLD
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x00);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3D);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0xCC);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0xCC);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0xCD);
	}
	if (ColorId == DropGreen)	// -> Green Item Name
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x00);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x00);
	}
	if (ColorId == DropPurple)	// -> Purple Item Name
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3D);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0xCC);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0xCC);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0xCD);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x00);
	}
	if (ColorId == DropPink)	// -> Pink Item Name
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x68);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0xF5);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0xC3);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x0B);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0xC6);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0xA8);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x3B);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0xED);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0xFA);
	}
	if (ColorId == DropOrange) // -> Orange Item Name
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x66);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x66);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x66);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x07);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0xAE);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x14);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3E);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x05);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0x1E);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0xB8);
	}
	if (ColorId == DropLightBlue)	// -> Light Blue Item Name
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x3C);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x20);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x90);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x2E);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x2C);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x3C);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x9F);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x7A);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0xE1);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x48);
	}
	if (ColorId == DropIceBlue)
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x00);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x6E);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0xEC);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0xC0);
	}
	if (ColorId == DropDarkViolet)
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x66);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x66);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x66);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x00);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x00);
	}
	if (ColorId == DropLightGreen)
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x00);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x1D);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0xE0);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x0D);
	}
	if (ColorId == DropThunderBlue)
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3E);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0xE6);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x66);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x66);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x00);
	}
	// ----
	if (ColorId > 12 || ColorId < 1)	// -> DEFAULT: White
	{
		// Red
		gToolKit.SetByte((PVOID)(oItemNameColorR + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorR + 1), 0x00);
		// Green
		gToolKit.SetByte((PVOID)(oItemNameColorG + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorG + 1), 0x00);
		// Blue
		gToolKit.SetByte((PVOID)(oItemNameColorB + 4), 0x3F);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 3), 0x80);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 2), 0x00);
		gToolKit.SetByte((PVOID)(oItemNameColorB + 1), 0x00);
	}
}

void cToolTip::Load()
{
	this->InitItemDescriptionText();
	this->InitItemDescriptionFixRena();
	this->InitItemDescriptionFixLostMap();
	this->InitItemDescriptionFixSymbolKundun();
	this->InitItemDescriptionFixSymbolKundunAdd();
	this->InitItemDescriptionAddOptionTypePosText();
}