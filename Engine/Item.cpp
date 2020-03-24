#include "StdAfx.h"

cItem gItem;

void cItem::LoadModels()
{
	pInitModelData();
	// ----
	char Sets[256];
	char Wings[256];
	char Jewels[256];
	char Weapons[256];
	// ----
	char* CustomItem = "Data\\Item\\";
	char* CustomPlayer = "Data\\Player\\";
	// ----
	for (int i = 0; i < 256; i++)
	{
		if (i > 28 && i < 31 || i > 31)
		{
			sprintf_s(Weapons, "Sword%d", i + 1);
			pLoadModel(ObjectId(0, i), CustomItem, Weapons, -1);
		}
		if (i > 8)
		{
			sprintf_s(Weapons, "Axe%d", i + 1);
			pLoadModel(ObjectId(1, i), CustomItem, Weapons, -1);
		}
		if (i > 18)
		{
			sprintf_s(Weapons, "Mace%d", i + 1);
			pLoadModel(ObjectId(2, i), CustomItem, Weapons, -1);
		}
		if (i > 11)
		{
			sprintf_s(Weapons, "Spear%d", i + 1);
			pLoadModel(ObjectId(3, i), CustomItem, Weapons, -1);
		}
		if (i > 24 && i < 128)
		{
			sprintf_s(Weapons, "Bow%d", i + 1);
			pLoadModel(ObjectId(4, i), CustomItem, Weapons, -1);
		}
		if (i > 127 && i < 256)
		{
			sprintf_s(Weapons, "Crossbow%d", i + 1);
			pLoadModel(ObjectId(4, i), CustomItem, Weapons, -1);
		}
		if (i > 34)
		{
			sprintf_s(Weapons, "Staff%d", i + 1);
			pLoadModel(ObjectId(5, i), CustomItem, Weapons, -1);
		}
		if (i > 21)
		{
			sprintf_s(Weapons, "Shield%d", i + 1);
			pLoadModel(ObjectId(6, i), CustomItem, Weapons, -1);
		}
		if (i > 199 && i < 256)
		{
			sprintf_s(Wings, "Wing%d", i + 1);
			pLoadModel(ObjectId(12, i), CustomItem, Wings, -1);
		}
		if (i >= 240 && i <= 247)
		{
			sprintf_s(Jewels, "Jewel%d", i + 1);
			pLoadModel(ObjectId(14, i), CustomItem, Jewels, -1);
		}
		if (i > 53 && i < 256)
		{
			sprintf_s(Sets, "HelmMale%d", i + 1);
			pLoadModel(ObjectId(7, i), CustomPlayer, Sets, -1);
			// ----
			sprintf_s(Sets, "ArmorMale%d", i + 1);
			pLoadModel(ObjectId(8, i), CustomPlayer, Sets, -1);
			// ----
			sprintf_s(Sets, "PantMale%d", i + 1);
			pLoadModel(ObjectId(9, i), CustomPlayer, Sets, -1);
			// ----
			sprintf_s(Sets, "GloveMale%d", i + 1);
			pLoadModel(ObjectId(10, i), CustomPlayer, Sets, -1);
			// ----
			sprintf_s(Sets, "BootMale%d", i + 1);
			pLoadModel(ObjectId(11, i), CustomPlayer, Sets, -1);
		}
	}

	sprintf_s(Weapons, "Sword%d", 42);
	pLoadModel(ObjectId(0, 42), CustomItem, Weapons, -1);

	sprintf_s(Weapons, "Staff%d", 44);
	pLoadModel(ObjectId(5, 44), CustomItem, Weapons, -1);

	pLoadModel(ObjectId(13, 156), CustomItem, "Cube", -1);

	pLoadModel(ObjectId(12, 150), CustomItem, "bJewel_Level", -1);
	pLoadModel(ObjectId(12, 151), CustomItem, "bJewel_Luck", -1);
	pLoadModel(ObjectId(12, 152), CustomItem, "bJewel_Skill", -1);
	pLoadModel(ObjectId(12, 153), CustomItem, "bJewel_Option", -1);
	pLoadModel(ObjectId(12, 154), CustomItem, "bJewel_Excellent", -1);
	pLoadModel(ObjectId(12, 155), CustomItem, "bJewel_Ancient", -1);
	pLoadModel(ObjectId(12, 156), CustomItem, "bJewel_Socket", -1);
	// ----
	pLoadModel(ObjectId(13, 97), CustomItem, "claw_of_wolf", -1);
	pLoadModel(ObjectId(13, 98), CustomItem, "fang_of_sable", -1);
	// ----
	/*
	pLoadModel(ObjectId(13,99),CustomItem,"Mask_Mistic",-1);
	pLoadModel(ObjectId(13,100),CustomItem,"Lyon_King",-1);
	pLoadModel(ObjectId(13,101),CustomItem,"Wolf_Gang",-1);
	*/
	pLoadModel(ObjectId(13, 77), CustomItem, "Skeleton_Pet", -1);
	pLoadModel(ObjectId(13, 78), CustomItem, "Unicorn_Pet", -1);
	pLoadModel(ObjectId(13, 79), CustomItem, "Sparky_Pet", -1);
	//pLoadModel(ObjectId(13,81),CustomItem,"Chinlon_Pet",-1);
	/*
	pLoadModel(ObjectId(13,109),CustomItem,"Pegasus_Pet",-1);
	*/
	// ----
	pLoadModel(ObjectId(13, 140), CustomItem, "fire_horrocrux", -1);
	pLoadModel(ObjectId(13, 141), CustomItem, "water_horrocrux", -1);
	pLoadModel(ObjectId(13, 142), CustomItem, "earth_horrocrux", -1);
	pLoadModel(ObjectId(13, 143), CustomItem, "wind_horrocrux", -1);
	pLoadModel(ObjectId(13, 144), CustomItem, "thunder_horrocrux", -1);
	pLoadModel(ObjectId(13, 145), CustomItem, "ice_horrocrux", -1);
	// ----
	pLoadModel(ObjectId(13, 150), CustomItem, "Red_Fragment", -1);
	pLoadModel(ObjectId(13, 151), CustomItem, "Gold_Fragment", -1);
	pLoadModel(ObjectId(13, 152), CustomItem, "Blue_Fragment", -1);
	// ----
	pLoadModel(ObjectId(13, 153), CustomItem, "Ring_Chaos", -1);
	pLoadModel(ObjectId(13, 154), CustomItem, "Ring_Bless", -1);
	pLoadModel(ObjectId(13, 155), CustomItem, "Ring_Soul", -1);
	// ----
	pLoadModel(ObjectId(14, 101), CustomItem, "Pandora_Box", -1);
	pLoadModel(ObjectId(14, 102), CustomItem, "MagicBox09", -1);
	pLoadModel(ObjectId(14, 103), CustomItem, "MagicBox10", -1);
	pLoadModel(ObjectId(14, 104), CustomItem, "MagicBox11", -1);
	// ----
	pLoadModel(ObjectId(14, 170), CustomItem, "CrystalFeather", -1);
	pLoadModel(ObjectId(14, 171), CustomItem, "Legend_Amulet", -1);
	pLoadModel(ObjectId(14, 172), CustomItem, "Divine_Stone", -1);
	pLoadModel(ObjectId(14, 173), CustomItem, "DarkJewel15", -1);
	pLoadModel(ObjectId(14, 174), CustomItem, "Deathless_Amulet", -1);
	// ----
	pLoadModel(ObjectId(14, 200), CustomItem, "Red_Arct", -1);
	pLoadModel(ObjectId(14, 201), CustomItem, "Gold_Arct", -1);
	pLoadModel(ObjectId(14, 202), CustomItem, "Blue_Arct", -1);
	// ----
	pLoadModel(ObjectId(14, 210), CustomItem, "saint_sumbook", -1);
	pLoadModel(ObjectId(14, 211), CustomItem, "saint_sumbook", -1);
	pLoadModel(ObjectId(14, 212), CustomItem, "saint_sumbook", -1);
	// ----
	pLoadModel(ObjectId(14, 213), CustomItem, "saint_sumbook", -1);
	pLoadModel(ObjectId(14, 214), CustomItem, "saint_sumbook", -1);
	pLoadModel(ObjectId(14, 215), CustomItem, "saint_sumbook", -1);
	pLoadModel(ObjectId(14, 216), CustomItem, "saint_sumbook", -1);
	pLoadModel(ObjectId(14, 217), CustomItem, "saint_sumbook", -1);
}

void cItem::LoadTextures()
{
	pInitTextureData();
	// ----
	char* CustomItemTex = "Item\\";
	char* CustomPlayerTex = "Player\\";
	// ----
	for (int i = 0; i < 256; i++)
	{
		if (i > 28 && i < 31 || i > 31)
		{
			pLoadTexture(ObjectId(0, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i > 8)
		{
			pLoadTexture(ObjectId(1, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i > 18)
		{
			pLoadTexture(ObjectId(2, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i > 11)
		{
			pLoadTexture(ObjectId(3, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i > 24 && i < 128)
		{
			pLoadTexture(ObjectId(4, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i > 127 && i < 256)
		{
			pLoadTexture(ObjectId(4, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i > 34)
		{
			pLoadTexture(ObjectId(5, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i > 21)
		{
			pLoadTexture(ObjectId(6, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i > 199 && i < 256)
		{
			pLoadTexture(ObjectId(12, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i >= 240 && i <= 247)
		{
			pLoadTexture(ObjectId(14, i), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (i > 53 && i < 256)
		{
			pLoadTexture(ObjectId(7, i), CustomPlayerTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
			pLoadTexture(ObjectId(8, i), CustomPlayerTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
			pLoadTexture(ObjectId(9, i), CustomPlayerTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
			pLoadTexture(ObjectId(10, i), CustomPlayerTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
			pLoadTexture(ObjectId(11, i), CustomPlayerTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
	}
	pLoadTexture(ObjectId(0, 42), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);

	pLoadTexture(ObjectId(5, 44), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);

	pLoadTexture(ObjectId(12, 150), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(12, 151), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(12, 152), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(12, 153), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(12, 154), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(12, 155), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(12, 156), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 97), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 98), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);

	/*
	pLoadTexture(ObjectId(13,99),CustomItemTex,GL_REPEAT,GL_NEAREST,GL_TRUE);
	pLoadTexture(ObjectId(13,100),CustomItemTex,GL_REPEAT,GL_NEAREST,GL_TRUE);
	pLoadTexture(ObjectId(13,101),CustomItemTex,GL_REPEAT,GL_NEAREST,GL_TRUE);
	*/
	pLoadTexture(ObjectId(13, 77), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 78), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 79), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	//pLoadTexture(ObjectId(13,81),CustomItemTex,GL_REPEAT,GL_NEAREST,GL_TRUE);
	/*
	pLoadTexture(ObjectId(13,109),CustomItemTex,GL_REPEAT,GL_NEAREST,GL_TRUE);
	*/
	// ----
	pLoadTexture(ObjectId(13, 140), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 141), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 142), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 143), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 144), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 145), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	// ----
	pLoadTexture(ObjectId(13, 150), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 151), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 152), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	// ----
	pLoadTexture(ObjectId(13, 153), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 154), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 155), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(13, 156), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	// ----
	pLoadTexture(ObjectId(14, 101), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 102), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 103), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 104), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 170), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 171), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 172), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 173), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 174), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 200), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 201), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 202), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	// ----
	pLoadTexture(ObjectId(14, 210), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 211), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 212), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	// ----
	pLoadTexture(ObjectId(14, 213), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 214), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 215), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 216), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
	pLoadTexture(ObjectId(14, 217), CustomItemTex, GL_REPEAT, GL_NEAREST, GL_TRUE);
}

void cItem::FixUnicornArmor()
{
	gToolKit.SetByte((PVOID)(0x005A0D74 + 2), 0xBA);
	gToolKit.SetByte((PVOID)(0x005A0D74 + 3), 0x03);
}

void cItem::FixSeraphimArmor()
{
	gToolKit.SetByte((PVOID)(0x005C8B48 + 3), 0x00);
	gToolKit.SetByte((PVOID)(0x005C8B48 + 4), 0x00);
}

void cItem::FixCashShopButtons()
{
	gToolKit.SetByte((PVOID)(oCashShopPurchaseButtonCoordY + 1), 0x28);
	gToolKit.SetRange((LPVOID)oCashShopGiftButtonRemoveHook, 251, ASM::NOP);
}

static DWORD dwItemTitleColor_Set;
static WORD wItemTitleColor_Pointer;
static BOOL bItemTitleColor_Switcher;
static DWORD dwItemTitleColor_Stack = oItemTitleColor_Stack;
static DWORD dwItemTitleColor_Next = oItemTitleColor_Next;

void Naked cItem::ItemTitleColor()
{
	bItemTitleColor_Switcher = FALSE;
	dwItemTitleColor_Set = ItemColor::White;
	// ----
	_asm
	{
		MOV wItemTitleColor_Pointer, AX
	}
	// ----
	if (wItemTitleColor_Pointer == ItemId(12, 15))		// Jewel of Chaos
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(0, 35))	// Absolute Archangel Sword
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(0, 36))	// Divine Archangel Blade
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Violet;
	}
	else if (wItemTitleColor_Pointer == ItemId(0, 37))	// Darkness Sword
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(0, 38))	// Darkness Blade
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(0, 39))	// Blood Angel Sword
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(0, 40))	// Blood Angel Blade
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(2, 24))	// Absolute Archangel Scepter
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(2, 25))	// Darkness Scepter
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(4, 29))	// Darkness Bow
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(4, 30))	// Blood Angel Bow
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(4, 130))	// Absolute Archangel Crossbow
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(5, 39))	// Divine Archangel Stick
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Violet;
	}
	else if (wItemTitleColor_Pointer == ItemId(5, 40))	// Absolute Archangel Staff
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(5, 41))	// Darkness Staff
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(5, 42))	// Blood Angel Staff
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(7, 100))	// Evolve Dragon Helm
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteRed;
	}
	else if (wItemTitleColor_Pointer == ItemId(8, 100))	// Evolve Dragon Armor
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteRed;
	}
	else if (wItemTitleColor_Pointer == ItemId(9, 100))	// Evolve Dragon Pants
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteRed;
	}
	else if (wItemTitleColor_Pointer == ItemId(10, 100))	// Evolve Dragon Gloves
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteRed;
	}
	else if (wItemTitleColor_Pointer == ItemId(11, 100))	// Evolve Dragon Boots
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteRed;
	}
	else if (wItemTitleColor_Pointer == ItemId(7, 101))	// Evolve Guardian Helm
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBeige;
	}
	else if (wItemTitleColor_Pointer == ItemId(8, 101))	// Evolve Guardian Armor
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBeige;
	}
	else if (wItemTitleColor_Pointer == ItemId(9, 101))	// Evolve Guardian Pants
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBeige;
	}
	else if (wItemTitleColor_Pointer == ItemId(10, 101))	// Evolve Guardian Gloves
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBeige;
	}
	else if (wItemTitleColor_Pointer == ItemId(11, 101))	// Evolve Guardian Boots
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBeige;
	}
	else if (wItemTitleColor_Pointer == ItemId(7, 102))	// Evolve Legendary Helm
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBlue;
	}
	else if (wItemTitleColor_Pointer == ItemId(8, 102))	// Evolve Legendary Armor
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBlue;
	}
	else if (wItemTitleColor_Pointer == ItemId(9, 102))	// Evolve Legendary Pants
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBlue;
	}
	else if (wItemTitleColor_Pointer == ItemId(10, 102))	// Evolve Legendary Gloves
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBlue;
	}
	else if (wItemTitleColor_Pointer == ItemId(11, 102))	// Evolve Legendary Boots
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBlue;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 150))	// Bundled Jewel of Level
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 151))	// Bundled Jewel of Luck
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 152))	// Bundled Jewel of Skill
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 153))	// Bundled Jewel of Option
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 154))	// Bundled Jewel of Excellent
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 155))	// Bundled Jewel of Ancient
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 156))	// Bundled Jewel of Socket
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 236))	// Magic Wings (Added: 09-04-17)
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 237))	// Chaos Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 238))	// Life Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 239))	// Cape of Death
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 240))	// Heaven Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 241))	// Demonic Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 242))	// Red Spirit Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 243))  // Thunder Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 244))  // Raven Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 245))	// Eternal Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 246))	// Legend Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 247))	// Flaming Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 248))	// Nightwish Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 249))	// Imperial Dragon Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::WhiteBeige;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 250))	// Conqueror Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 251))	// Angel and Devil Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(12, 252))	// Deathless Wings
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 140))	// Horrocrux of Fire
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 141))	// Horrocrux of Water
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Blue;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 142))	// Horrocrux of Earth
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 143))	// Horrocrux of Wind
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Green;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 144))	// Horrocrux of Thunder
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Violet;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 145))	// Horrocrux of Ice
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gray;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 150))	// Fragment of Fire
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 151))	// Fragment of Earth
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 152))	// Fragment of Water
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Blue;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 153))	// Ring of Chaos
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 154))	// Ring of Bless
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 155))	// Ring of Soul
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 27))	// Ancient Metal
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 170))	// Crystal Feather 
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 171))	// Legend Amulet 
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 172))	// Divine Stone
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 173))	// Jewel of Dark Chaos
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 174))	// Deathless Amulet (Added: 22-12-16)
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 210))	// Book of Summon Dark Phoenix
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 211))	// Book of Summon Red Giant Dragon
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 212))	// Book of Summon Kundun Boss
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 213))	// Book of Summon Giant Drakan
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 214))	// Book of Summon Iron Knight
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 215))	// Book of Summon Selupan Boss
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 216))	// Book of Summon Thunder Nappin
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 217))	// Book of Summon Hell Maine
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 240))	// Jewel of Level
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 241))	// Jewel of Luck
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 242))	// Jewel of Skill
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 243))	// Jewel of Option
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 244))	// Jewel of Excellent
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 245))	// Jewel of Ancient
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 246))	// Jewel of Socket
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 97))	// Dark Wolf Pet
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 98))	// Sable Fang Pet
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 77))	// Skeleton Pet
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::White;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 78))	// Unicorn Pet
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::White;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 79))	// Sparky Pet
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::White;
	}
	else if (wItemTitleColor_Pointer == ItemId(13, 81))	// Chinlon Pet
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::White;
	}
	/*
	else if(wItemTitleColor_Pointer == ItemId(13,99))	// Mistic Tiger Pet
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::DarkViolet;
	}
	else if(wItemTitleColor_Pointer == ItemId(13,100))	// Giant Lyon Pet
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Green;
	}
	else if(wItemTitleColor_Pointer == ItemId(13,101))	// Lycan Wolf Pet
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	*/
	else if (wItemTitleColor_Pointer == ItemId(14, 101))	// Box of Pandora
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 102))	// Blue Legendary Box
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Blue;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 103))	// Red Legendary Box
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 104))	// Green Legendary Box
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Green;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 163))	// Vault Expansion Certificate
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Blue;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 200))	// Red Evolve Gem
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Red;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 201))	// Gold Evolve Gem
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Gold;
	}
	else if (wItemTitleColor_Pointer == ItemId(14, 202))	// Blue Evolve Gem
	{
		bItemTitleColor_Switcher = TRUE;
		dwItemTitleColor_Set = ItemColor::Blue;
	}
	// ----
	if (bItemTitleColor_Switcher == TRUE)
	{
		_asm
		{
			JE ColorSet
			JMP dwItemTitleColor_Next
			// ----
			ColorSet :
			// ----
			MOV EDI, dwItemTitleColor_Set
				MOV DWORD PTR SS : [ESP + 0x18] , EDI
				// ----
				JMP dwItemTitleColor_Stack
		}
	}
	else if (bItemTitleColor_Switcher == FALSE)
	{
		_asm
		{
			JMP dwItemTitleColor_Next
		}
	}
}

void cItem::InitItemTitleColor()
{
	gToolKit.SetRange((LPVOID)oItemTitleColor, 10, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemTitleColor, this->ItemTitleColor);
}

static BOOL bItemDropTitleColor_Switcher;
static BOOL bItemDropTitleColor_Original;

float clR = 0.0f;
float clG = 0.0f;
float clB = 0.0f;

void Naked cItem::ItemDropTitleColor()
{
	static DWORD dwItemDropTitleColor_Pointer;
	static DWORD dwItemDropTitleColor_Buffer;
	// ----
	static DWORD dwItemDropTitleColor_Jump = 0x0059CC5D;
	static DWORD dwItemDropTitleColor_Call = 0x00851348;
	// ----
	bItemDropTitleColor_Original = FALSE;
	bItemDropTitleColor_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwItemDropTitleColor_Pointer, EAX
	}
	// ----
	if (dwItemDropTitleColor_Pointer == ObjectId(14, 15)) // Zen
	{
		bItemDropTitleColor_Switcher = FALSE;
		bItemDropTitleColor_Original = TRUE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 27)) // Ancient Metal
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 170)) // Crystal Feather
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 1.000000f;
		clG = 0.000000f;
		clB = 0.000000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 171)) // Legend Amulet
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 1.000000f;
		clG = 0.000000f;
		clB = 0.000000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 172)) // Divine Stone
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 1.000000f;
		clG = 0.640000f;
		clB = 1.000000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 173)) // Jewel of Dark Chaos
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 174)) // Deathless Amulet (Added: 22-12-16)
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 1.000000f;
		clG = 0.000000f;
		clB = 0.000000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 101)) // Pandora Box
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 1.000000f;
		clG = 0.900000f;
		clB = 0.000000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 102)) // Blue Legendary Box
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 0.000000f;
		clG = 0.095000f;
		clB = 1.000000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 103)) // Red Legendary Box
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 1.000000f;
		clG = 0.095000f;
		clB = 0.000000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 104)) // Green Legendary Box
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---
		clR = 0.000000f;
		clG = 1.000000f;
		clB = 0.095000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 240)) // Jewel of Level
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 241)) // Jewel of Luck
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 242)) // Jewel of Skill
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 243)) // Jewel of Option
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 244)) // Jewel of Excellent
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 245)) // Jewel of Ancient
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 246)) // Jewel of Socket
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(12, 150)) // Bundled Jewel of Level
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(12, 151)) // Bundled Jewel of Luck
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(12, 152)) // Bundled Jewel of Skill
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(12, 153)) // Bundled Jewel of Option
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(12, 154)) // Bundled Jewel of Excellent
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(12, 155)) // Bundled Jewel of Ancient
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(12, 156)) // Bundled Jewel of Socket
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	/*else if(dwItemDropTitleColor_Pointer == ObjectId(12,247)) // Flaming Wings
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.000000f;
		clB = 0.000000f;
	}
	else if(dwItemDropTitleColor_Pointer == ObjectId(12,248)) // Nightwish Wings
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.000000f;
		clB = 0.000000f;
	}
	else if(dwItemDropTitleColor_Pointer == ObjectId(12,249)) // Imperial Dragon Wings
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if(dwItemDropTitleColor_Pointer == ObjectId(12,250)) // Conqueror Wings
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if(dwItemDropTitleColor_Pointer == ObjectId(12,251)) // Angel and Devil Wings
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	*/
	// ----
	else if (dwItemDropTitleColor_Pointer == ObjectId(13, 150)) // -> Fragment of Fire
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.000000f;
		clB = 0.000000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(13, 151)) // -> Fragment of Earth
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(13, 152)) // -> Fragment of Water
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 0.000000f;
		clG = 0.000000f;
		clB = 1.000000f;
	}
	// ----
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 200)) // -> Red Evolve Gem
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.000000f;
		clB = 0.000000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 201)) // -> Gold Evolve Gem
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 1.000000f;
		clG = 0.800000f;
		clB = 0.100000f;
	}
	else if (dwItemDropTitleColor_Pointer == ObjectId(14, 202)) // -> Blue Evolve Gem
	{
		bItemDropTitleColor_Switcher = TRUE;
		bItemDropTitleColor_Original = FALSE;
		// ---------------
		clR = 0.000000f;
		clG = 0.000000f;
		clB = 1.000000f;
	}
	// ----
	if (bItemDropTitleColor_Original == TRUE)
	{
		_asm
		{
			PUSH clB
			PUSH clG
			PUSH clR
			CALL DWORD PTR DS : [0x8893CC]
			MOV EAX, DWORD PTR DS : [ESI + 0x30]
			MOV EDX, DWORD PTR DS : [0x7AB3514]
			SUB EAX, 0x342
			PUSH EBX
			LEA ECX, [EAX * 0x8]
			SUB ECX, EAX
			LEA ECX, [ECX * 0x2 + ECX]
			LEA EAX, [ECX * 0x4 + EDX]
			LEA ECX, [ESP + 0x1C]
			PUSH EAX
			PUSH 0x008C5A10
			PUSH ECX
			CALL dwItemDropTitleColor_Call
			ADD ESP, 0x10
			JMP dwItemDropTitleColor_Jump
		}
	}
	// ----
	if (bItemDropTitleColor_Switcher == TRUE)
	{
		_asm
		{
			PUSH clB
			PUSH clG
			PUSH clR
			CALL DWORD PTR DS : [0x8893CC]
			MOV EAX, DWORD PTR DS : [ESI + 0x30]
			MOV EDX, DWORD PTR DS : [0x7AB3514]
			SUB EAX, 0x342
			PUSH EBX
			LEA ECX, [EAX * 0x8]
			SUB ECX, EAX
			LEA ECX, [ECX * 0x2 + ECX]
			LEA EAX, [ECX * 0x4 + EDX]
			LEA ECX, [ESP + 0x1C]
			PUSH EAX
			PUSH 0x008C5A18
			PUSH ECX
			CALL dwItemDropTitleColor_Call
			ADD ESP, 0x10
			JMP dwItemDropTitleColor_Jump
		}
	}
	else
	{
		_asm
		{
			MOV dwItemDropTitleColor_Buffer, oItemDropTitleColor_Return
			JMP dwItemDropTitleColor_Buffer
		}
	}
}

void cItem::InitItemDropTitleColor()
{
	gToolKit.SetRange((LPVOID)oItemDropTitleColor_Hook, 82, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemDropTitleColor_Hook, this->ItemDropTitleColor);
}

void Naked cItem::BladesWizardryDmg()
{
	static WORD wBladesWizardryDmg_Pointer = 0;
	static DWORD dwBladesWizardryDmg_Allowed = oBladesWizardryDmg_Allowed;
	static DWORD dwBladesWizardryDmg_Return = oBladesWizardryDmg_Return;
	// ----
	_asm
	{
		MOV wBladesWizardryDmg_Pointer, CX
		// ----
		CMP wBladesWizardryDmg_Pointer, DarkReignBlade
		JE AddWizardryDmgText
		CMP wBladesWizardryDmg_Pointer, RuneSacredBlade
		JE AddWizardryDmgText
		CMP wBladesWizardryDmg_Pointer, BlastBreak
		JE AddWizardryDmgText
		CMP wBladesWizardryDmg_Pointer, DivineBlade
		JE AddWizardryDmgText
		CMP wBladesWizardryDmg_Pointer, DarknessBlade
		JE AddWizardryDmgText
		// ----
		JMP ReturnWizardryDmgLoad
		// ----
		AddWizardryDmgText :
		// ----
		JMP dwBladesWizardryDmg_Allowed
			// ----
			ReturnWizardryDmgLoad :
		// ----
		JMP dwBladesWizardryDmg_Return
	}
}

void cItem::InitBladesWizardryDmg()
{
	gToolKit.SetRange((LPVOID)oBladesWizardryDmg_Hook, 6, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oBladesWizardryDmg_Hook, this->BladesWizardryDmg);
}

void Naked cItem::BladesWizardryAdd()
{
	static WORD wBladesWizardryAdd_Pointer = 0;
	static DWORD dwBladesWizardryAdd_Allowed = oBladesWizardryAdd_Allowed;
	static DWORD dwBladesWizardryAdd_Return = oBladesWizardryAdd_Return;
	// ----
	_asm
	{
		MOV wBladesWizardryAdd_Pointer, CX
		// ----
		CMP wBladesWizardryAdd_Pointer, DarkReignBlade
		JE AddWizardryAddText
		CMP wBladesWizardryAdd_Pointer, RuneSacredBlade
		JE AddWizardryAddText
		CMP wBladesWizardryAdd_Pointer, BlastBreak
		JE AddWizardryAddText
		CMP wBladesWizardryAdd_Pointer, DivineBlade
		JE AddWizardryAddText
		CMP wBladesWizardryAdd_Pointer, DarknessBlade
		JE AddWizardryAddText
		// ----
		JMP ReturnWizardryAddLoad
		// ----
		AddWizardryAddText :
		// ----
		JMP dwBladesWizardryAdd_Allowed
			// ----
			ReturnWizardryAddLoad :
		// ----
		JMP dwBladesWizardryAdd_Return
	}
}

void cItem::InitBladesWizardryAdd()
{
	gToolKit.SetRange((LPVOID)oBladesWizardryAdd_Hook, 6, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oBladesWizardryAdd_Hook, this->BladesWizardryAdd);
}

static BOOL bSceptersPetAttack_Switcher;

void Naked cItem::SceptersPetAttack()
{
	static DWORD dwSceptersPetAttack_Pointer;
	static DWORD dwSceptersPetAttack_Buffer;
	// ----
	bSceptersPetAttack_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOV dwSceptersPetAttack_Pointer, EAX
	}
	// ----
	if (dwSceptersPetAttack_Pointer == ItemId(2, 17))
	{
		bSceptersPetAttack_Switcher = TRUE;
	}
	else if (dwSceptersPetAttack_Pointer == ItemId(2, 22))
	{
		bSceptersPetAttack_Switcher = TRUE;
	}
	else if (dwSceptersPetAttack_Pointer == ItemId(2, 24))
	{
		bSceptersPetAttack_Switcher = TRUE;
	}
	else if (dwSceptersPetAttack_Pointer == ItemId(2, 25))
	{
		bSceptersPetAttack_Switcher = TRUE;
	}
	// ----
	if (bSceptersPetAttack_Switcher == TRUE)
	{
		_asm
		{
			MOV dwSceptersPetAttack_Buffer, oSceptersPetAttack_Allowed
			JMP dwSceptersPetAttack_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwSceptersPetAttack_Buffer, oSceptersPetAttack_Return
			JMP dwSceptersPetAttack_Buffer
		}
	}
}

void cItem::InitSceptersPetAttack()
{
	gToolKit.SetRange((LPVOID)oSceptersPetAttack_Hook, 9, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oSceptersPetAttack_Hook, this->SceptersPetAttack);
}

void cItem::InitCustomItemsLoad()
{
	gToolKit.SetOp((LPVOID)0x005EE102, this->LoadModels, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x005EE117, this->LoadTextures, ASM::CALL);
}

int cItem::SetItemSpecialStat(short ItemID, int Arg2, BYTE SpecialOption, BYTE SpecialValue, int Arg5)
{
	switch (ItemID)
	{
	case ItemId(12, 236):	// Wings of Magic (Added: 09-04-17)
	case ItemId(12, 237):	// Wings of Chaos (Added: 09-04-17)
	case ItemId(12, 238):	// Wings of Life (Added: 09-04-17)
	case ItemId(12, 239):	// Cape of Death (Added: 09-04-17)
	{
		switch (SpecialOption)
		{
		case IgnorOpDefense:
		{
			SpecialValue = 6;
		}
		break;

		case ReturnAttack:
		{
			SpecialValue = 6;
		}
		break;

		case CompleteLife:
		{
			SpecialValue = 6;
		}
		break;

		case CompleteMana:
		{
			SpecialValue = 6;
		}
		break;

		case CurseSpell:
		{
			SpecialValue = 6;
		}
		break;

		case Defense:
		{
			SpecialValue = 6;
		}
		break;
		}
	}
	break;
	case ItemId(12, 240):
	case ItemId(12, 241):
	case ItemId(12, 242):
	case ItemId(12, 243):
	case ItemId(12, 244):
	case ItemId(12, 245):
	{
		switch (SpecialOption)
		{
		case IgnorOpDefense:
		{
			SpecialValue = 7;
		}
		break;

		case ReturnAttack:
		{
			SpecialValue = 7;
		}
		break;

		case CompleteLife:
		{
			SpecialValue = 7;
		}
		break;

		case CompleteMana:
		{
			SpecialValue = 7;
		}
		break;

		case CurseSpell:
		{
			SpecialValue = 7;
		}
		break;

		case Defense:
		{
			SpecialValue = 7;
		}
		break;
		}
	}
	break;
	// ------------------------------------------
	case ItemId(12, 246):
	case ItemId(12, 247):
	case ItemId(12, 248):
	case ItemId(12, 249):
	case ItemId(12, 252):	// -> Deathless Wings (Added: 22-12-16)
	{
		switch (SpecialOption)
		{
		case IgnorOpDefense:
		{
			SpecialValue = 8;
		}
		break;

		case ReturnAttack:
		{
			SpecialValue = 8;
		}
		break;

		case CompleteLife:
		{
			SpecialValue = 8;
		}
		break;

		case CompleteMana:
		{
			SpecialValue = 8;
		}
		break;

		case CurseSpell:
		{
			SpecialValue = 8;
		}
		break;

		case Defense:
		{
			SpecialValue = 8;
		}
		break;
		}
	}
	break;
	// --------------------------
	// Modified (08-08-16)
	case ItemId(12, 250):
	case ItemId(12, 251):
	{
		switch (SpecialOption)
		{
		case IgnorOpDefense:
		{
			SpecialValue = 9;
		}
		break;

		case ReturnAttack:
		{
			SpecialValue = 9;
		}
		break;

		case CompleteLife:
		{
			SpecialValue = 9;
		}
		break;

		case CompleteMana:
		{
			SpecialValue = 9;
		}
		break;

		case CurseSpell:
		{
			SpecialValue = 9;
		}
		break;

		case Defense:
		{
			SpecialValue = 9;
		}
		break;
		}
	}
	break;
	}
	// ----
	return pSetItemSpecialStat(ItemID, Arg2, SpecialOption, SpecialValue, Arg5);
}

void cItem::InitItemSetSpecialStat()
{
	gToolKit.SetOp((LPVOID)oSetItemSpecialStat_Hook, this->SetItemSpecialStat, ASM::CALL);
}

static BOOL bItemAddGoldSmelt_Switcher;

void Naked cItem::ItemAddGoldSmelt()
{
	static DWORD dwItemAddGoldSmelt_Pointer;
	static DWORD dwItemAddGoldSmelt_Buffer;
	// ----
	bItemAddGoldSmelt_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x10]
		MOV dwItemAddGoldSmelt_Pointer, EAX
	}
	// ----
	if (dwItemAddGoldSmelt_Pointer == ObjectId(2, 14))		// -> Solay Scepter
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	else if (dwItemAddGoldSmelt_Pointer == ObjectId(13, 97))	// -> Dark Wolf
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	else if (dwItemAddGoldSmelt_Pointer == ObjectId(13, 98))	// -> Sable Fang
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	/*
	else if(dwItemAddGoldSmelt_Pointer == ObjectId(13,99))	// -> Mistic Mask
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	*/
	/*
	else if(dwItemAddGoldSmelt_Pointer == ObjectId(13,101))	// -> Lycan Pet
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	*/
	else if (dwItemAddGoldSmelt_Pointer >= ObjectId(13, 140)	// -> Horrocrux of Fire
		&& dwItemAddGoldSmelt_Pointer <= ObjectId(13, 145))		// -> Horrocrux of Ice
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	else if (dwItemAddGoldSmelt_Pointer == ObjectId(14, 171)) // -> Legend Amulet
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	else if (dwItemAddGoldSmelt_Pointer >= ObjectId(14, 210)
		&& dwItemAddGoldSmelt_Pointer <= ObjectId(14, 217))		// -> All Summon Monsters Books
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	else if (dwItemAddGoldSmelt_Pointer == ObjectId(5, 41))	// -> Darkness Staff
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	else if (dwItemAddGoldSmelt_Pointer == ObjectId(6, 27))	// -> Sphere Shield
	{
		bItemAddGoldSmelt_Switcher = TRUE;
	}
	// ----
	if (bItemAddGoldSmelt_Switcher == TRUE)
	{
		_asm
		{
			MOV dwItemAddGoldSmelt_Buffer, oItemAddGoldSmelt_Allowed
			JMP dwItemAddGoldSmelt_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwItemAddGoldSmelt_Buffer, oItemAddGoldSmelt_Return
			JMP dwItemAddGoldSmelt_Buffer
		}
	}
}

void cItem::InitItemAddGoldSmelt()
{
	gToolKit.SetRange((LPVOID)oItemAddGoldSmelt_Hook, 9, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemAddGoldSmelt_Hook, this->ItemAddGoldSmelt);
}

static BOOL bItemArmorPosition_Switcher;

void Naked cItem::ItemArmorPosition()
{
	static DWORD dwItemArmorPosition_Pointer;
	static DWORD dwItemArmorPosition_Buffer;
	// ----
	bItemArmorPosition_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwItemArmorPosition_Pointer, ESI
	}
	// ----
	if (dwItemArmorPosition_Pointer == ItemId(8, 3))			// -> Legendary Armor
	{
		bItemArmorPosition_Switcher = TRUE;
	}
	else if (dwItemArmorPosition_Pointer == ItemId(8, 14))	// -> Guardian Armor
	{
		bItemArmorPosition_Switcher = TRUE;
	}
	else if (dwItemArmorPosition_Pointer == ItemId(8, 19))	// -> Divine Armor
	{
		bItemArmorPosition_Switcher = TRUE;
	}
	else if (dwItemArmorPosition_Pointer == ItemId(8, 24))	// -> Red Spirit Armor
	{
		bItemArmorPosition_Switcher = TRUE;
	}
	else if (dwItemArmorPosition_Pointer == ItemId(8, 31))	// -> Sylphid Ray Armor
	{
		bItemArmorPosition_Switcher = TRUE;
	}
	else if (dwItemArmorPosition_Pointer == ItemId(8, 49))	// -> Seraphim Armor
	{
		bItemArmorPosition_Switcher = TRUE;
	}
	else if (dwItemArmorPosition_Pointer == ItemId(8, 53))	// -> Queen Armor
	{
		bItemArmorPosition_Switcher = TRUE;
	}
	else if (dwItemArmorPosition_Pointer == ItemId(8, 101))	// -> Evolve Guardian Armor
	{
		bItemArmorPosition_Switcher = TRUE;
	}
	else if (dwItemArmorPosition_Pointer == ItemId(8, 102))	// -> Evolve Legendary Armor
	{
		bItemArmorPosition_Switcher = TRUE;
	}
	// ----
	if (bItemArmorPosition_Switcher == TRUE)
	{
		_asm
		{
			MOV dwItemArmorPosition_Buffer, oItemArmorPosition_Allowed
			JMP dwItemArmorPosition_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwItemArmorPosition_Buffer, oItemArmorPosition_Return
			JMP dwItemArmorPosition_Buffer
		}
	}
}

void cItem::InitItemArmorPosition()
{
	gToolKit.SetRange((LPVOID)oItemArmorPosition_Hook, 8, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemArmorPosition_Hook, this->ItemArmorPosition);
}

static BOOL bItemDivineNameOnFloor_Switcher;
static BOOL bItemRedNameOnFloor_Switcher;
static BOOL bItemPinkNameOnFloor_Switcher;
static BOOL bItemGoldNameOnFloor_Switcher;
static BOOL bItemBlueNameOnFloor_Switcher;
static BOOL bItemGreenNameOnFloor_Switcher;
static BOOL bItemOrangeNameOnFloor_Switcher;
static BOOL bItemLightBlueNameOnFloor_Switcher;

static BOOL bItemIceBlueNameOnFloor_Switcher;
static BOOL bItemDarkVioletNameOnFloor_Switcher;
static BOOL bItemLightGreenNameOnFloor_Switcher;
static BOOL bItemThunderBlueNameOnFloor_Switcher;

void Naked cItem::ItemDivineNameOnFloor()
{
	static DWORD dwItemDivineNameOnFloor_Pointer;
	static DWORD dwItemDivineNameOnFloor_Buffer;
	// ----
	bItemDivineNameOnFloor_Switcher = FALSE;
	bItemPinkNameOnFloor_Switcher = FALSE;
	bItemGoldNameOnFloor_Switcher = FALSE;
	bItemBlueNameOnFloor_Switcher = FALSE;
	bItemRedNameOnFloor_Switcher = FALSE;
	bItemGreenNameOnFloor_Switcher = FALSE;
	bItemOrangeNameOnFloor_Switcher = FALSE;
	bItemLightBlueNameOnFloor_Switcher = FALSE;
	bItemIceBlueNameOnFloor_Switcher = FALSE;
	bItemDarkVioletNameOnFloor_Switcher = FALSE;
	bItemLightGreenNameOnFloor_Switcher = FALSE;
	bItemThunderBlueNameOnFloor_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwItemDivineNameOnFloor_Pointer, EAX
	}
	// ----
	if (dwItemDivineNameOnFloor_Pointer == ObjectId(0, 19)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(0, 36)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(2, 13)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(4, 18)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(5, 10)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(5, 39))
	{
		bItemDivineNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(0, 35)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(0, 37)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(0, 38)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(2, 24)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(4, 29)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(4, 130)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(2, 25)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(5, 40)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(5, 41))
	{
		bItemPinkNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer >= ObjectId(12, 240)
		&& dwItemDivineNameOnFloor_Pointer <= ObjectId(12, 245)
		|| dwItemDivineNameOnFloor_Pointer >= ObjectId(12, 249)
		&& dwItemDivineNameOnFloor_Pointer <= ObjectId(12, 251)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 98)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(14, 210))
	{
		bItemGoldNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(12, 246)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(12, 247)			// -> Flamming Wings (Added: 09-04-17)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(12, 248)			// -> Nightwish Wings (Added: 09-04-17)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(12, 252)			// -> Deathless Wings (Added: 22-12-16)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 97)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(14, 217))			// -> Summon Book of Hell Maine (Added: 28-03-17)
	{
		bItemRedNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(7, 100)		// -> Evolve Dragon Set
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(8, 100)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(9, 100)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(10, 100)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(11, 100)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(0, 39)			// -> Added Blood Swords
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(0, 40)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(4, 30)			// -> Added Blood Bow
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(5, 42))			// -> Added Blood Staff
	{
		bItemRedNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(7, 101)		// -> Evolve Guardian Set
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(8, 101)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(9, 101)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(10, 101)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(11, 101))
	{
		bItemGoldNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(7, 102)		// -> Evolve Legendary Set
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(8, 102)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(9, 102)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(10, 102)
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(11, 102))
	{
		bItemBlueNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer >= ObjectId(13, 140)		// -> Horrocrux of Fire
		&& dwItemDivineNameOnFloor_Pointer <= ObjectId(13, 145)			// -> Horrocrux of Ice
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 153)			// -> Ring of Chaos
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 154)			// -> Ring of Bless
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 155)			// -> Ring of Soul
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(14, 211)			// -> Summon Book of Giant Dragon
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 77)			// -> Skeleton Pet
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 78)			// -> Unicorn Pet
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 79)			// -> Sparky Pet
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 81)			// -> Chinlon Pet
		|| dwItemDivineNameOnFloor_Pointer == ObjectId(13, 156))		// -> Cube
	{
		bItemOrangeNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(14, 212))	// -> Summon Book of Kundun Boss
	{
		bItemLightBlueNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(14, 213))	// -> Summon Book of Giant Drakan
	{
		bItemDarkVioletNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(14, 214))	// -> Summon Book of Iron Knight
	{
		bItemIceBlueNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(14, 215))	// -> Summon Book of Selupan Boss
	{
		bItemLightGreenNameOnFloor_Switcher = TRUE;
	}
	else if (dwItemDivineNameOnFloor_Pointer == ObjectId(14, 216))	// -> Summon Book of Thunder Nappin
	{
		bItemThunderBlueNameOnFloor_Switcher = TRUE;
	}
	// ----
	if (bItemDivineNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropPurple);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemRedNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropRed);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemBlueNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropBlue);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemPinkNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropPink);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemGreenNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropGreen);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemGoldNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropGold);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemOrangeNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropOrange);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemLightBlueNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropLightBlue);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemIceBlueNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropIceBlue);
		// -----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemDarkVioletNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropDarkViolet);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemLightGreenNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropLightGreen);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	// ----
	if (bItemThunderBlueNameOnFloor_Switcher == TRUE)
	{
		gToolTip.ItemNameColorDrop(DropThunderBlue);
		// ----
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Allowed
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwItemDivineNameOnFloor_Buffer, oItemDivineNameOnFloor_Return
			JMP dwItemDivineNameOnFloor_Buffer
		}
	}
}

void cItem::InitItemDivineNameOnFloor()
{
	gToolKit.SetRange((LPVOID)oItemDivineNameOnFloor_Hook, 11, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemDivineNameOnFloor_Hook, this->ItemDivineNameOnFloor);
}

static BOOL bItemRingInventoryPos_Switcher;

void Naked cItem::ItemRingInventoryPos()
{
	static DWORD dwItemRingInventoryPos_Pointer;
	static DWORD dwItemRingInventoryPos_Buffer;
	// ----
	bItemRingInventoryPos_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwItemRingInventoryPos_Pointer, ESI
	}
	// ----
	if (dwItemRingInventoryPos_Pointer == ObjectId(13, 42))		// -> Ring of Game Master
	{
		bItemRingInventoryPos_Switcher = TRUE;
	}
	else if (dwItemRingInventoryPos_Pointer >= ObjectId(13, 140)	// -> Horrocrux of Fire
		&& dwItemRingInventoryPos_Pointer <= ObjectId(13, 145))		// -> Horrocrux of Ice
	{
		bItemRingInventoryPos_Switcher = TRUE;
	}
	else if (dwItemRingInventoryPos_Pointer == ObjectId(13, 153))	// -> Ring of Chaos
	{
		bItemRingInventoryPos_Switcher = TRUE;
	}
	else if (dwItemRingInventoryPos_Pointer == ObjectId(13, 154)) // -> Ring of Bless
	{
		bItemRingInventoryPos_Switcher = TRUE;
	}
	else if (dwItemRingInventoryPos_Pointer == ObjectId(13, 155)) // -> Ring of Soul
	{
		bItemRingInventoryPos_Switcher = TRUE;
	}
	// ----
	if (bItemRingInventoryPos_Switcher == TRUE)
	{
		_asm
		{
			MOV dwItemRingInventoryPos_Buffer, oItemRingInventoryPos_Allowed
			JMP dwItemRingInventoryPos_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwItemRingInventoryPos_Buffer, oItemRingInventoryPos_Return
			JMP dwItemRingInventoryPos_Buffer
		}
	}
}

void cItem::InitItemRingInventoryPos()
{
	gToolKit.SetRange((LPVOID)oItemRingInventoryPos_Hook, 6, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemRingInventoryPos_Hook, this->ItemRingInventoryPos);
}

void Naked cItem::ItemSummonBookInvenPos()
{
	static DWORD dwItemSummonBookInvenPos_Pointer;
	// ----
	// dwItemSummonBookInvenPos_Jump -> MOV DWORD PTR SS:[ESP+0x10],0x3B83126F
	static DWORD dwItemSummonBookInvenPos_Jump = oItemSummonBookInvenPos_Jump;
	static DWORD dwItemSummonBookInvenPos_Buffer = oItemSummonBookInvenPos_Return;
	// ----
	_asm
	{
		MOV dwItemSummonBookInvenPos_Pointer, ESI
	}
	// ----
	if (dwItemSummonBookInvenPos_Pointer >= ObjectId(5, 21)
		&& dwItemSummonBookInvenPos_Pointer <= ObjectId(5, 29))		// -> Summoner Books
	{
		_asm
		{
			JMP dwItemSummonBookInvenPos_Jump
		}
	}
	else if (dwItemSummonBookInvenPos_Pointer >= ObjectId(14, 210)
		&& dwItemSummonBookInvenPos_Pointer <= ObjectId(14, 217))	// -> All Summon Books (Monsters)
	{
		_asm
		{
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3B656042
		}
	}
	else
	{
		_asm
		{
			JMP dwItemSummonBookInvenPos_Buffer
		}
	}
}

void cItem::InitItemSummonBookInvenPos()
{
	gToolKit.SetRange((LPVOID)oItemSummonBookInvenPos_Hook, 20, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemSummonBookInvenPos_Hook, this->ItemSummonBookInvenPos);
}

void Naked cItem::ItemSummonBookInvenRot()
{
	static DWORD dwItemSummonBookInvenRot_Pointer;
	// ----
	static DWORD dwItemSummonBookInvenRot_Jump = oItemSummonBookInvenRot_Jump;
	static DWORD dwItemSummonBookInvenRot_Buffer = oItemSummonBookInvenRot_Return;
	// ----
	_asm
	{
		MOV dwItemSummonBookInvenRot_Pointer, ESI
	}
	// ----
	if (dwItemSummonBookInvenRot_Pointer >= ObjectId(5, 21)
		&& dwItemSummonBookInvenRot_Pointer <= ObjectId(5, 29))		// -> Summoner Books
	{
		_asm
		{
			MOV DWORD PTR DS : [0x7C12D68] , 0
			MOV DWORD PTR DS : [0x7C12D6C] , 0
			MOV DWORD PTR DS : [0x7C12D70] , 0
			JMP dwItemSummonBookInvenRot_Jump
		}
	}
	else if (dwItemSummonBookInvenRot_Pointer >= ObjectId(14, 210)
		&& dwItemSummonBookInvenRot_Pointer <= ObjectId(14, 212))	// -> All Summon Books (Monsters)
	{
		_asm
		{
			MOV DWORD PTR DS : [0x7C12D68] , 0
			MOV DWORD PTR DS : [0x7C12D6C] , 0x42B40000
			MOV DWORD PTR DS : [0x7C12D70] , 0
			JMP dwItemSummonBookInvenRot_Jump
		}
	}
	else
	{
		_asm
		{
			JMP dwItemSummonBookInvenRot_Buffer
		}
	}
}

void cItem::InitItemSummonBookInvenRot()
{
	gToolKit.SetRange((LPVOID)oItemSummonBookInvenRot_Hook, 51, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oItemSummonBookInvenRot_Hook, this->ItemSummonBookInvenRot);
}

/*
char StdCall ItemStack(int ItemStartId,int ItemEndId)
{
	char result;

	if(!ItemStartId || !ItemEndId)
	{
		return 0;
	}
	// ----
	int ItemStartRange			= *(WORD*)ItemStartId;
	int ItemEndRange			= *(WORD*)ItemEndId;
	int ItemDurInByte1			= *(BYTE*)(ItemStartId+22);
	int ItemDurInByte2			= *(BYTE*)(ItemEndId+22);
	// ---------------------------------------------------------
	// for Elf Bolts & Arrows
	// ---------------------------------------------------------
	int ItemStartSpecialRange	= *(DWORD*)(ItemStartId+2);
	int ItemEndSpecialRange		= *(DWORD*)(ItemEndId+2);
	// ----
	if(ItemStartRange != ItemEndRange)
	{
		goto REGRESO;
	}
	// ----
	if(ItemStartRange == ItemId(14,7) && ItemEndRange == ItemId(14,7)
	&& ItemDurInByte1 < 250 && ItemDurInByte2 < 250)						// -> Siege Potion
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,0) && ItemEndRange == ItemId(14,0)
	&& ItemDurInByte1 < 255 && ItemDurInByte2 < 255)
	{
		return 1;
	}
	// ----
	if(ItemStartRange >= ItemId(14,1) && ItemStartRange <= ItemId(14,8)
	&& ItemStartRange != ItemId(14,7) && ItemEndRange >= ItemId(14,1)
	&& ItemEndRange <= ItemId(14,8) && ItemEndRange != ItemId(14,7)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> From: Apple to: Antidote
	{
		return 1;
	}
	// ----
	if(ItemStartRange >= ItemId(14,38) && ItemStartRange <= ItemId(14,40)
	&& ItemEndRange >= ItemId(14,38) && ItemEndRange <= ItemId(14,40)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Small, Medium, Large Rejuvenation Potion
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(4,7) && ItemEndRange == ItemId(4,7)
	&& ItemStartSpecialRange == ItemEndSpecialRange)						// -> Elf Bolts
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(4,15) && ItemEndRange == ItemId(4,15)
	&& ItemStartSpecialRange == ItemEndSpecialRange)						// -> Elf Arrows
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,28) && ItemEndRange == ItemId(14,28))	// -> Symbol of Kundun
	{
		return 1;
	}
	// ----
	if(ItemStartRange >= ItemId(13,32) && ItemStartRange <= ItemId(13,34)
	&& ItemEndRange >= ItemId(13,32) && ItemEndRange <= ItemId(13,34))		// -> Splinter of Armor, Bless of Guardian & Claw of Beast
	{
		return 1;
	}
	// ----
	if(ItemStartRange >= ItemId(14,46) && ItemStartRange <= ItemId(14,50)
	&& ItemEndRange >= ItemId(14,46) && ItemEndRange <= ItemId(14,50)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Jack O'Lantern: Bless, Rage, Scream, Food & Drink Scrolls
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,70) && ItemEndRange == ItemId(14,70)
	&& ItemDurInByte1 < 50 && ItemDurInByte2 < 50)							// -> Elite Healing Potion
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,71) && ItemEndRange == ItemId(14,71)
	&& ItemDurInByte1 < 50 && ItemDurInByte2 < 50)							// -> Elite Mana Potion
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,78) && ItemEndRange == ItemId(14,78)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Leap of Strenght
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,79) && ItemEndRange == ItemId(14,79)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Leap of Agility
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,80) && ItemEndRange == ItemId(14,80)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Leap of Vitality
	{
		return 1;
	}

	if(ItemStartRange == ItemId(14,81) && ItemEndRange == ItemId(14,81)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Leap of Energy
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,82) && ItemEndRange == ItemId(14,82)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Leap of Command
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,94) && ItemEndRange == ItemId(14,94)
	&& ItemDurInByte1 < 50 && ItemDurInByte2 < 50)							// -> Medium Elite Healing Potion
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,85) && ItemEndRange == ItemId(14,85)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Cherry Blossom Wine
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,86) && ItemEndRange == ItemId(14,86)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Cherry Blossom Rice Cake
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,87) && ItemEndRange == ItemId(14,87)
	&& ItemDurInByte1 < 3 && ItemDurInByte2 < 3)							// -> Cherry Blossom Flower Petal
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,88) && ItemEndRange == ItemId(14,88)
	&& ItemDurInByte1 < 10 && ItemDurInByte2 < 10)							// -> White Cherry Blossom Branch (x10)
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,89) && ItemEndRange == ItemId(14,89)
	&& ItemDurInByte1 < 30 && ItemDurInByte2 < 30)							// -> Red Cherry Blossom Branch (x30)
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,90) && ItemEndRange == ItemId(14,90)
	&& ItemDurInByte1 < 50 && ItemDurInByte2 < 50)							// -> Golden Cherry Blossom Branch (x50)
	{
		return 1;
	}
	// ----
	if(ItemStartRange == ItemId(14,200) && ItemEndRange == ItemId(14,200)
	&& ItemDurInByte1 < 10 && ItemDurInByte2 < 10)							// -> Gem of Life (Fire)
	{
		if(ItemDurInByte1 < 10 || ItemDurInByte2 < 10)
		{
			return 1;
		}
		else if(ItemDurInByte1 >= 10 || ItemDurInByte2 >= 10)
		{
			return 0;
		}
		else
		{
			return 0;
		}
	}
	// ----
	if(ItemStartRange != ItemId(14,100) || ItemDurInByte1 >= 255 || ItemDurInByte2 >= 255)	// -> Restore normal durability from other types of items gets from: Item(Kor).txt
	REGRESO:
	result = 0;
	else
		result = 1;
	return result;
}
*/

/*void cItem::InitItemStack()
{
	//gToolKit.SetOp((LPVOID)oItemStackAttachCall01,ItemStack,ASM::CALL);
	//gToolKit.SetOp((LPVOID)oItemStackAttachCall02,ItemStack,ASM::CALL);
	//gToolKit.SetOp((LPVOID)oItemStackAttachCall03,ItemStack,ASM::CALL);
	gToolKit.SetHook((LPVOID)oItemStackAttachCall01,(LPVOID)ItemStack,ASM::CALL);
	gToolKit.SetHook((LPVOID)oItemStackAttachCall02,(LPVOID)ItemStack,ASM::CALL);
	gToolKit.SetHook((LPVOID)oItemStackAttachCall03,(LPVOID)ItemStack,ASM::CALL);
}*/

void cItem::Load()
{
	this->FixUnicornArmor();
	this->FixSeraphimArmor();
	this->FixCashShopButtons();
	this->InitItemTitleColor();
	this->InitCustomItemsLoad();
	this->InitItemAddGoldSmelt();
	this->InitItemArmorPosition();
	this->InitBladesWizardryDmg();
	this->InitBladesWizardryAdd();
	this->InitSceptersPetAttack();
	this->InitItemDropTitleColor();
	this->InitItemSetSpecialStat();
	this->InitItemRingInventoryPos();
	this->InitItemDivineNameOnFloor();
	//this->InitItemSummonBookInvenRot();
	this->InitItemSummonBookInvenPos();
	// ----
	//gToolKit.SetOp((LPVOID)oItemStackAttachCall01,ItemStack,ASM::CALL);
	//gToolKit.SetOp((LPVOID)oItemStackAttachCall02,ItemStack,ASM::CALL);
	//gToolKit.SetOp((LPVOID)oItemStackAttachCall03,ItemStack,ASM::CALL);
}