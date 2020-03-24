#include "StdAfx.h"

cJewels gJewels;

static BOOL bJewelsDropSound_Switcher;

void Naked cJewels::JewelsDropSound()
{
	static DWORD dwJewelsDropSound_Pointer;
	static DWORD dwJewelsDropSound_Buffer;
	// ----
	bJewelsDropSound_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x4]
		MOV dwJewelsDropSound_Pointer,EAX
	}
	// ----
	if(dwJewelsDropSound_Pointer == ItemId(14,14)) // Jewel of Soul
	{
		bJewelsDropSound_Switcher = TRUE;
	}
	else if(dwJewelsDropSound_Pointer == ItemId(14,27)) // Ancient Metal
	{
		bJewelsDropSound_Switcher = TRUE;
	}
	else if(dwJewelsDropSound_Pointer >= ItemId(14,42) && dwJewelsDropSound_Pointer <= ItemId(14,44) || dwJewelsDropSound_Pointer == ItemId(14,173)) // Jewel of Harmony + Lower and Higher Refining Stones + Dark Chaos
	{
		bJewelsDropSound_Switcher = TRUE;
	}
	else if(dwJewelsDropSound_Pointer >= ItemId(14,240) && dwJewelsDropSound_Pointer <= ItemId(14,246)) // All Custom Jewels
	{
		bJewelsDropSound_Switcher = TRUE;
	}
	else if(dwJewelsDropSound_Pointer >= ItemId(14,200) && dwJewelsDropSound_Pointer <= ItemId(14,202)) // -> All Evolve Gems
	{
		bJewelsDropSound_Switcher = TRUE;
	}
	else if(dwJewelsDropSound_Pointer >= ItemId(13,150) && dwJewelsDropSound_Pointer <= ItemId(13,152))	// -> All Elemental Fragments
	{
		bJewelsDropSound_Switcher = TRUE;
	}
	// ----
	else if(dwJewelsDropSound_Pointer >= ItemId(13,140) && dwJewelsDropSound_Pointer <= ItemId(13,145)) // -> All Horrocrux Items
	{
		bJewelsDropSound_Switcher = FALSE;
		// ----
		gLoadSound.LoadDropHorrocruxsSound();
		gPlaySound.PlayDropHorrocruxsSound();
	}
	// ----
	else if(dwJewelsDropSound_Pointer >= ItemId(14,210) && dwJewelsDropSound_Pointer <= ItemId(14,217)) // -> All Summon Books (Updated: 28-03-17)
	{
		bJewelsDropSound_Switcher = FALSE;
		// ----
		gLoadSound.LoadDropHorrocruxsSound();
		gPlaySound.PlayDropHorrocruxsSound();
	}
	// ----
	else if(dwJewelsDropSound_Pointer >= ItemId(13,153) && dwJewelsDropSound_Pointer <= ItemId(13,159))	// -> All Legendary Jeweled Rings
	{
		bJewelsDropSound_Switcher = FALSE;
		// ----
		gLoadSound.LoadDropHorrocruxsSound();
		gPlaySound.PlayDropHorrocruxsSound();
	}
	// ----
	else if(dwJewelsDropSound_Pointer == ItemId(14,171) || dwJewelsDropSound_Pointer == ItemId(14,174)) // -> Legend & Deathless Amulets
	{
		bJewelsDropSound_Switcher = FALSE;
		// ----
		gLoadSound.LoadDropHorrocruxsSound();
		gPlaySound.PlayDropHorrocruxsSound();
	}
	// ----
	else if(dwJewelsDropSound_Pointer == ItemId(13,77) || dwJewelsDropSound_Pointer == ItemId(13,78) 
	|| dwJewelsDropSound_Pointer == ItemId(13,79) || dwJewelsDropSound_Pointer == ItemId(13,81))	// -> Skeleton Pet, Unicorn Pet, Sparky Pet & Chinlon Pet
	{
		bJewelsDropSound_Switcher = FALSE;
		// ----
		gLoadSound.LoadDropHorrocruxsSound();
		gPlaySound.PlayDropHorrocruxsSound();
	}
	// ----
	if(bJewelsDropSound_Switcher == TRUE)
	{
		_asm
		{
			MOV dwJewelsDropSound_Buffer,oJewelsDropSound_Allowed
			JMP dwJewelsDropSound_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwJewelsDropSound_Buffer,oJewelsDropSound_Return
			JMP dwJewelsDropSound_Buffer
		}
	}
}

void cJewels::InitJewelsDropSound()
{
	gToolKit.SetRange((LPVOID)oJewelsDropSound_Hook,9,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oJewelsDropSound_Hook,this->JewelsDropSound);
}

static BOOL bJewelsPickSound_Switcher;

void Naked cJewels::JewelsPickSound()
{
	static DWORD dwJewelsPickSound_Pointer;
	static DWORD dwJewelsPickSound_Buffer;
	// ----
	bJewelsPickSound_Switcher = FALSE;
	// ----
	_asm
	{
		MOV dwJewelsPickSound_Pointer,EAX
	}
	// ----
	if(dwJewelsPickSound_Pointer == ItemId(14,14)) // Jewel of Soul
	{
		bJewelsPickSound_Switcher = TRUE;
	}
	else if(dwJewelsPickSound_Pointer == ItemId(14,27)) // Ancient Metal
	{
		bJewelsPickSound_Switcher = TRUE;
	}
	else if(dwJewelsPickSound_Pointer >= ItemId(14,42) && dwJewelsPickSound_Pointer <= ItemId(14,44) || dwJewelsPickSound_Pointer == ItemId(14,173)) // Jewel of Harmony + Lower and Higher Refining Stones + Dark Chaos
	{
		bJewelsPickSound_Switcher = TRUE;
	}
	else if(dwJewelsPickSound_Pointer >= ItemId(14,240) && dwJewelsPickSound_Pointer <= ItemId(14,246)) // All Custom Jewels
	{
		bJewelsPickSound_Switcher = TRUE;
	}
	else if(dwJewelsPickSound_Pointer >= ItemId(14,200) && dwJewelsPickSound_Pointer <= ItemId(14,202)) // -> All Evolve Gems
	{
		bJewelsPickSound_Switcher = TRUE;
	}
	else if(dwJewelsPickSound_Pointer >= ItemId(13,150) && dwJewelsPickSound_Pointer <= ItemId(13,152))	// -> All Elemental Fragments
	{
		bJewelsPickSound_Switcher = TRUE;
	}
	// ----
	else if(dwJewelsPickSound_Pointer >= ItemId(13,140) && dwJewelsPickSound_Pointer <= ItemId(13,145)) // -> All Horrocrux Items
	{
		bJewelsPickSound_Switcher = FALSE;
		// ----
		gLoadSound.LoadDropHorrocruxsSound();
		gPlaySound.PlayDropHorrocruxsSound();
	}
	// ----
	else if(dwJewelsPickSound_Pointer >= ItemId(13,153) && dwJewelsPickSound_Pointer <= ItemId(13,159))	// -> All Legendary Jeweled Rings
	{
		bJewelsPickSound_Switcher = FALSE;
		// ----
		gLoadSound.LoadDropHorrocruxsSound();
		gPlaySound.PlayDropHorrocruxsSound();
	}
	// ----
	else if(dwJewelsPickSound_Pointer == ItemId(14,171) || dwJewelsPickSound_Pointer == ItemId(14,174)) // -> Legend & Deathless Amulets
	{
		bJewelsPickSound_Switcher = FALSE;
		// ----
		gLoadSound.LoadDropHorrocruxsSound();
		gPlaySound.PlayDropHorrocruxsSound();
	}
	// ----
	if(bJewelsPickSound_Switcher == TRUE)
	{
		_asm
		{
			MOV dwJewelsPickSound_Buffer,oJewelsPickSound_Allowed
			JMP dwJewelsPickSound_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwJewelsPickSound_Buffer,oJewelsPickSound_Return
			JMP dwJewelsPickSound_Buffer
		}
	}
}

void cJewels::InitJewelsPickSound()
{
	gToolKit.SetRange((LPVOID)oJewelsPickSound_Hook,7,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oJewelsPickSound_Hook,this->JewelsPickSound);
}

static BOOL bJewelsMoveOnItem_Switcher;

void Naked cJewels::JewelsMoveOnItem()
{
	static DWORD dwJewelsMoveOnItem_Pointer;
	static DWORD dwJewelsMoveOnItem_Buffer;
	// ----
	bJewelsMoveOnItem_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x70]
		MOVSX EAX,WORD PTR DS:[EDX]
		MOV dwJewelsMoveOnItem_Pointer,EAX
	}
	// ----
	if(dwJewelsMoveOnItem_Pointer == ItemId(14,14)) // Jewel of Soul
	{
		bJewelsMoveOnItem_Switcher = TRUE;
	}
	else if(dwJewelsMoveOnItem_Pointer >= ItemId(14,42) && dwJewelsMoveOnItem_Pointer <= ItemId(14,44)) // Jewel of Harmony
	{
		bJewelsMoveOnItem_Switcher = TRUE;
	}
	else if(dwJewelsMoveOnItem_Pointer >= ItemId(14,240) && dwJewelsMoveOnItem_Pointer <= ItemId(14,246)) // All Custom Jewels
	{
		bJewelsMoveOnItem_Switcher = TRUE;
	}
	else if(dwJewelsMoveOnItem_Pointer >= ItemId(14,200) && dwJewelsMoveOnItem_Pointer <= ItemId(14,202)) // -> All Evolve Gems
	{
		bJewelsMoveOnItem_Switcher = TRUE;
	}
	else if(dwJewelsMoveOnItem_Pointer == ItemId(14,171)) // -> Legend Amulet
	{
		bJewelsMoveOnItem_Switcher = TRUE;
	}
	else if(dwJewelsMoveOnItem_Pointer == ItemId(14,174)) // -> Deathless Amulet
	{
		bJewelsMoveOnItem_Switcher = TRUE;
	}
	// ----
	if(bJewelsMoveOnItem_Switcher == TRUE)
	{
		_asm
		{
			MOV dwJewelsMoveOnItem_Buffer,oJewelsMoveOnItem_Allowed
			JMP dwJewelsMoveOnItem_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwJewelsMoveOnItem_Buffer,oJewelsMoveOnItem_Return
			JMP dwJewelsMoveOnItem_Buffer
		}
	}
}

void cJewels::InitJewelsMoveOnItem()
{
	gToolKit.SetRange((LPVOID)oJewelsMoveOnItem_Hook,7,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oJewelsMoveOnItem_Hook,this->JewelsMoveOnItem);
}

static BOOL bJewelsAllowOnItem_Switcher;

void Naked cJewels::JewelsAllowOnItem()
{
	static DWORD dwJewelsAllowOnItem_Pointer;
	static DWORD dwJewelsAllowOnItem_Buffer;
	// ----
	bJewelsAllowOnItem_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOVSX EAX,WORD PTR DS:[EDX]
		MOV dwJewelsAllowOnItem_Pointer,EAX
	}
	// ----
	if(dwJewelsAllowOnItem_Pointer == ItemId(14,14)) // Jewel of Soul
	{
		bJewelsAllowOnItem_Switcher = TRUE;
	}
	else if(dwJewelsAllowOnItem_Pointer >= ItemId(14,42) && dwJewelsAllowOnItem_Pointer <= ItemId(14,44)) // Jewel of Harmony + Lower & Higher Refining Stones
	{
		bJewelsAllowOnItem_Switcher = TRUE;
	}
	else if(dwJewelsAllowOnItem_Pointer >= ItemId(14,240) && dwJewelsAllowOnItem_Pointer <= ItemId(14,246)) // All Custom Jewels
	{
		bJewelsAllowOnItem_Switcher = TRUE;
	}
	else if(dwJewelsAllowOnItem_Pointer >= ItemId(14,200) && dwJewelsAllowOnItem_Pointer <= ItemId(14,202)) // -> All Evolve Gems
	{
		bJewelsAllowOnItem_Switcher = TRUE;
	}
	else if(dwJewelsAllowOnItem_Pointer == ItemId(14,171)) // -> Legend Amulet
	{
		bJewelsAllowOnItem_Switcher = TRUE;
	}
	else if(dwJewelsAllowOnItem_Pointer == ItemId(14,174)) // -> Deathless Amulet
	{
		bJewelsAllowOnItem_Switcher = TRUE;
	}
	// ----
	if (bJewelsAllowOnItem_Switcher == TRUE)
	{
		_asm
		{
			MOV dwJewelsAllowOnItem_Buffer,oJewelsAllowOnItem_Allowed
			JMP dwJewelsAllowOnItem_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwJewelsAllowOnItem_Buffer,oJewelsAllowOnItem_Return
			JMP dwJewelsAllowOnItem_Buffer
		}
	}
}

void cJewels::InitJewelsAllowOnItem()
{
	gToolKit.SetRange((LPVOID)oJewelsAllowOnItem_Hook,7,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oJewelsAllowOnItem_Hook,this->JewelsAllowOnItem);
}

static BOOL bJewelsInvenSwitch_Switcher;

void Naked cJewels::JewelsInvenSwitch()
{
	static DWORD dwJewelsInvenSwitch_Pointer;
	static DWORD dwJewelsInvenSwitch_Buffer;
	// ----
	bJewelsInvenSwitch_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x14]
		MOVSX EAX,WORD PTR DS:[EDX]
		MOV dwJewelsInvenSwitch_Pointer,EAX
	}
	// ----
	if(dwJewelsInvenSwitch_Pointer == ItemId(14,13)) // Jewel of Bless
	{
		bJewelsInvenSwitch_Switcher = TRUE;
	}
	else if(dwJewelsInvenSwitch_Pointer >= ItemId(14,240) && dwJewelsInvenSwitch_Pointer <= ItemId(14,246)) // All Custom Jewels
	{
		bJewelsInvenSwitch_Switcher = TRUE;
	}
	else if(dwJewelsInvenSwitch_Pointer >= ItemId(14,200) && dwJewelsInvenSwitch_Pointer <= ItemId(14,202)) // -> All Evolve Gems
	{
		bJewelsInvenSwitch_Switcher = TRUE;
	}
	else if(dwJewelsInvenSwitch_Pointer == ItemId(14,171)) // -> Legend Amulet
	{
		bJewelsInvenSwitch_Switcher = TRUE;
	}
	else if(dwJewelsInvenSwitch_Pointer == ItemId(14,174)) // -> Deathless Amulet
	{
		bJewelsInvenSwitch_Switcher = TRUE;
	}
	// ----
	if(bJewelsInvenSwitch_Switcher == TRUE)
	{
		_asm
		{
			MOV dwJewelsInvenSwitch_Buffer,oJewelsInvenSwitch_Allowed
			JMP dwJewelsInvenSwitch_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwJewelsInvenSwitch_Buffer,oJewelsInvenSwitch_Return
			JMP dwJewelsInvenSwitch_Buffer
		}
	}
}

void cJewels::InitJewelsInvenSwitch()
{
	gToolKit.SetRange((LPVOID)oJewelsInvenSwitch_Hook,13,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oJewelsInvenSwitch_Hook,this->JewelsInvenSwitch);
}

static DWORD dwJewelsPricesOnShop_Pointer;
static DWORD dwJewelsPricesOnShop_Buffer;
static DWORD dwJewelsPricesOnShop_Set;

void Naked cJewels::JewelsPricesOnShop()
{
	dwJewelsPricesOnShop_Set = 0;
	// ----
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		MOVSX EDX,WORD PTR DS:[ECX]
		MOV dwJewelsPricesOnShop_Pointer,EDX
	}
	// ----
	if(dwJewelsPricesOnShop_Pointer == ItemId(14,13)) // Jewel of Bless
	{
		dwJewelsPricesOnShop_Set = 9000000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(14,27)) // Ancient Metal
	{
		dwJewelsPricesOnShop_Set = 3000000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(14,170)) // Crystal Feather
	{
		dwJewelsPricesOnShop_Set = 3000000;
	}
	else if(dwJewelsPricesOnShop_Pointer >= ItemId(14,171) && dwJewelsPricesOnShop_Pointer <= ItemId(14,172)) // Legend Amulet & Divine Stone
	{
		dwJewelsPricesOnShop_Set = 6000000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(14,240) || dwJewelsPricesOnShop_Pointer >= ItemId(14,244) && dwJewelsPricesOnShop_Pointer <= ItemId(14,246)) // Jewel of Level, Jewel of Excellent, Jewel of Ancient, Jewel of Socket
	{
		dwJewelsPricesOnShop_Set = 60000000;
	}
	else if(dwJewelsPricesOnShop_Pointer >= ItemId(14,241) && dwJewelsPricesOnShop_Pointer <= ItemId(14,243)) // Jewel of Luck, Jewel of Skill, Jewel of Option
	{
		dwJewelsPricesOnShop_Set = 30000000;
	}
	else if(dwJewelsPricesOnShop_Pointer >= ItemId(12,150) && dwJewelsPricesOnShop_Pointer <= ItemId(12,156)) // All Custom Jewels Bundleds
	{
		dwJewelsPricesOnShop_Set = 90000000;
	}
	else if(dwJewelsPricesOnShop_Pointer >= ItemId(14,42) && dwJewelsPricesOnShop_Pointer <= ItemId(14,44)) // Jewel of Harmony, Lower & Higher Crystals
	{
		dwJewelsPricesOnShop_Set = 9000000;
	}
	else if(dwJewelsPricesOnShop_Pointer >= ItemId(14,101) && dwJewelsPricesOnShop_Pointer <= ItemId(14,104)) // Pandora Box and All Legendary Boxes
	{
		dwJewelsPricesOnShop_Set = 6000000;
	}
	else if(dwJewelsPricesOnShop_Pointer >= ItemId(14,200) && dwJewelsPricesOnShop_Pointer <= ItemId(14,202)) // -> All Evolve Gems
	{
		dwJewelsPricesOnShop_Set = 30000000;
	}
	else if(dwJewelsPricesOnShop_Pointer >= ItemId(14,210) && dwJewelsPricesOnShop_Pointer <= ItemId(14,217)) // -> All Custom Summon Monster Books (Updated: 28-03-17)
	{
		dwJewelsPricesOnShop_Set = 12000000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(14,171)) // -> Legend Amulet
	{
		dwJewelsPricesOnShop_Set = 6000000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(14,174)) // -> Deathless Amulet
	{
		dwJewelsPricesOnShop_Set = 6000000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(13,76))	// -> Panda Ring
	{
		dwJewelsPricesOnShop_Set = 3000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(13,64) || dwJewelsPricesOnShop_Pointer == ItemId(13,65))	// -> Demon Pet & Fairy Pet
	{
		dwJewelsPricesOnShop_Set = 22000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(13,77) || dwJewelsPricesOnShop_Pointer == ItemId(13,78) 
	|| dwJewelsPricesOnShop_Pointer == ItemId(13,79) || dwJewelsPricesOnShop_Pointer == ItemId(13,81)) // -> Skeleton Pet, Unicorn Pet, Sparky Pet
	{
		dwJewelsPricesOnShop_Set = 22000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(13,80))	// -> Panda Pet
	{
		dwJewelsPricesOnShop_Set = 22000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(13,97) || dwJewelsPricesOnShop_Pointer == ItemId(13,98))	// -> Dark Wolf Pet & Sable Fang Pet
	{
		dwJewelsPricesOnShop_Set = 50000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(13,150) || dwJewelsPricesOnShop_Pointer == ItemId(13,151) || dwJewelsPricesOnShop_Pointer == ItemId(13,152))	// -> All Elemental Fragments
	{
		dwJewelsPricesOnShop_Set = 15000;
	}
	else if(dwJewelsPricesOnShop_Pointer == ItemId(14,173))	// -> Jewel of Dark Chaos
	{
		dwJewelsPricesOnShop_Set = 180000;
	}
	// ----
	if(dwJewelsPricesOnShop_Set == 0)
	{
		_asm
		{
			MOV dwJewelsPricesOnShop_Buffer,oJewelsPricesOnShop_Return
			JMP dwJewelsPricesOnShop_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV EAX,dwJewelsPricesOnShop_Set
			MOV DWORD PTR SS:[EBP-0x8],EAX
			MOV DWORD PTR SS:[EBP-0x4],0x0
			// ----
			MOV dwJewelsPricesOnShop_Buffer,oJewelsPricesOnShop_Allowed
			JMP dwJewelsPricesOnShop_Buffer
		}
	}
}

void cJewels::InitJewelsPricesOnShop()
{
	gToolKit.SetRange((LPVOID)oJewelsPricesOnShop_Hook,33,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oJewelsPricesOnShop_Hook,this->JewelsPricesOnShop);
}

static BOOL bJewelsBlockDrop_Switcher;

void Naked cJewels::JewelsBlockDrop()
{
	static DWORD dwJewelsBlockDrop_Pointer;
	static DWORD dwJewelsBlockDrop_Buffer;
	// ----
	bJewelsBlockDrop_Switcher = TRUE;
	// ----
	_asm
	{
		MOV dwJewelsBlockDrop_Pointer,EAX
	}
	// ----
	if(dwJewelsBlockDrop_Pointer == ItemId(14,13)) // Jewel of Bless
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer == ItemId(14,27)) // Ancient Metal
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer >= ItemId(14,240) && dwJewelsBlockDrop_Pointer <= ItemId(14,246)) // All Custom Jewels
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer >= ItemId(12,150) && dwJewelsBlockDrop_Pointer <= ItemId(12,156)) // All Custom Jewels Bundleds
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer >= ItemId(14,200) && dwJewelsBlockDrop_Pointer <= ItemId(14,202)) // -> All Evolve Gems
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer == ItemId(14,171)) // -> Legend Amulet
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer == ItemId(14,172)) // -> Divine Stone
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer == ItemId(14,173)) // -> Jewel of Dark Chaos
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer == ItemId(14,174)) // -> Deathless Amulet
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer >= ItemId(13,150) && dwJewelsBlockDrop_Pointer <= ItemId(13,152))	// -> All Elemental Fragments
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	else if(dwJewelsBlockDrop_Pointer == ItemId(13,77) || dwJewelsBlockDrop_Pointer == ItemId(13,78)
	|| dwJewelsBlockDrop_Pointer == ItemId(13,79) || dwJewelsBlockDrop_Pointer == ItemId(13,81))	// -> Skeleton Pet, Unicorn Pet, Sparky Pet & Chinlon Pet
	{
		bJewelsBlockDrop_Switcher = FALSE;
	}
	// ----
	if(bJewelsBlockDrop_Switcher == FALSE)
	{
		_asm
		{
			MOV dwJewelsBlockDrop_Buffer,oJewelsBlockDrop_Allowed
			JMP dwJewelsBlockDrop_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwJewelsBlockDrop_Buffer,oJewelsBlockDrop_Return
			JMP dwJewelsBlockDrop_Buffer
		}
	}
}

void cJewels::InitJewelsBlockDrop()
{
	gToolKit.SetRange((LPVOID)oJewelsBlockDrop_Hook,10,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oJewelsBlockDrop_Hook,this->JewelsBlockDrop);
}

static BOOL bJewelsShineEffect_Switcher;

void Naked cJewels::JewelsShineEffect()
{
	static DWORD dwJewelsShineEffect_Pointer;
	static DWORD dwJewelsShineEffect_Buffer;
	// ----
	bJewelsShineEffect_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0x10]
		MOV dwJewelsShineEffect_Pointer,EAX
	}
	// ----
	if(dwJewelsShineEffect_Pointer >= ObjectId(14,55) && dwJewelsShineEffect_Pointer <= ObjectId(14,57)) // Green, Red & Purple Chaos Boxes
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer >= ObjectId(14,240) && dwJewelsShineEffect_Pointer <= ObjectId(14,246)) // All Custom Jewels
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer >= ObjectId(12,150) && dwJewelsShineEffect_Pointer <= ObjectId(12,156)) // All Custom Jewels Bundles
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer >= ObjectId(14,200) && dwJewelsShineEffect_Pointer <= ObjectId(14,202)) // -> All Evolve Gems
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer == ObjectId(13,97)) // -> Tear of Dark
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer == ObjectId(13,100)) // -> Eye of Lyon
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer == ObjectId(14,27)) // -> Ancient Metal
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer == ObjectId(14,172)) // -> Divine Stone
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer == ObjectId(14,173)) // -> Jewel of Dark Chaos
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer >= ObjectId(13,150) && dwJewelsShineEffect_Pointer <= ObjectId(13,152))	// -> All Elemental Fragments
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	else if(dwJewelsShineEffect_Pointer >= ObjectId(13,153) && dwJewelsShineEffect_Pointer <= ObjectId(13,159))	// -> All Jeweled Custom Rings
	{
		bJewelsShineEffect_Switcher = TRUE;
	}
	// ----
	if(bJewelsShineEffect_Switcher == TRUE)
	{
		_asm
		{
			MOV dwJewelsShineEffect_Buffer,oJewelsShineEffect_Allowed
			JMP dwJewelsShineEffect_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwJewelsShineEffect_Buffer,oJewelsShineEffect_Return
			JMP dwJewelsShineEffect_Buffer
		}
	}
}

void cJewels::InitJewelsShineEffect()
{
	gToolKit.SetRange((LPVOID)oJewelsShineEffect_Hook,9,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oJewelsShineEffect_Hook,this->JewelsShineEffect);
}

static BOOL bJewelsUpdateFlags_Switcher;

void Naked cJewels::JewelsUpdateFlags()
{
	static DWORD dwJewelsUpdateFlags_Pointer;
	static DWORD dwJewelsUpdateFlags_Target;
	static DWORD dwJewelsUpdateFlags_Buffer;
	static DWORD dwJewelsUpdateFlags_Set;
	// ----
	bJewelsUpdateFlags_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x14]
		MOVSX EAX,WORD PTR DS:[EDX]
		MOV dwJewelsUpdateFlags_Pointer,EAX
		MOV EDX,DWORD PTR SS:[EBP-0x30]
		MOV dwJewelsUpdateFlags_Target,EDX
	}
	// ----
	if(dwJewelsUpdateFlags_Pointer == ItemId(14,245)) // -> Jewel of Ancient
	{
		if(dwJewelsUpdateFlags_Target == ItemId(13,8) || dwJewelsUpdateFlags_Target == ItemId(13,9) ||	// -> All Pendants & Rings
		dwJewelsUpdateFlags_Target == ItemId(13,12) || dwJewelsUpdateFlags_Target == ItemId(13,13) ||
		dwJewelsUpdateFlags_Target == ItemId(13,21) || dwJewelsUpdateFlags_Target == ItemId(13,22) ||
		dwJewelsUpdateFlags_Target == ItemId(13,23) || dwJewelsUpdateFlags_Target == ItemId(13,24) ||
		dwJewelsUpdateFlags_Target == ItemId(13,25) || dwJewelsUpdateFlags_Target == ItemId(13,26) ||
		dwJewelsUpdateFlags_Target == ItemId(13,27) || dwJewelsUpdateFlags_Target == ItemId(13,28))
		{
			bJewelsUpdateFlags_Switcher = TRUE;
		}
	}
	// ----
	if(dwJewelsUpdateFlags_Pointer == ItemId(14,240) || dwJewelsUpdateFlags_Pointer == ItemId(14,13) || dwJewelsUpdateFlags_Pointer == ItemId(14,14))	// -> Jewel of Level || Jewel of Bless || Jewel of Soul
	{
		if(dwJewelsUpdateFlags_Target == ItemId(13,99) || dwJewelsUpdateFlags_Target == ItemId(13,97) || dwJewelsUpdateFlags_Target == ItemId(13,98) || dwJewelsUpdateFlags_Target == ItemId(13,100) || dwJewelsUpdateFlags_Target == ItemId(13,101))
		{
			bJewelsUpdateFlags_Switcher = TRUE;
		}
	}
	// ----
	if(dwJewelsUpdateFlags_Pointer == ItemId(14,240) || dwJewelsUpdateFlags_Pointer == ItemId(14,13) || dwJewelsUpdateFlags_Pointer == ItemId(14,14))	// -> Jewel of Level || Jewel of Bless || Jewel of Soul
	{
		if(dwJewelsUpdateFlags_Target == ItemId(13,10))	// -> Ring of Transformation
		{
			bJewelsUpdateFlags_Switcher = TRUE;
			gLoadSound.LoadMixsJewelsPackSound();
			gPlaySound.PlayMixsJewelsPackSound();
		}
	}
	// ----
	if(dwJewelsUpdateFlags_Pointer == ItemId(14,13) || dwJewelsUpdateFlags_Pointer == ItemId(14,14) || dwJewelsUpdateFlags_Pointer == ItemId(14,16))	// -> Jewel of Bless || Jewel of Soul || Jewel of Life
	{
		if(dwJewelsUpdateFlags_Target == ItemId(13,8) || dwJewelsUpdateFlags_Target == ItemId(13,9) ||	// -> All Pendants & Rings
		dwJewelsUpdateFlags_Target == ItemId(13,12) || dwJewelsUpdateFlags_Target == ItemId(13,13) ||
		dwJewelsUpdateFlags_Target == ItemId(13,21) || dwJewelsUpdateFlags_Target == ItemId(13,22) ||
		dwJewelsUpdateFlags_Target == ItemId(13,23) || dwJewelsUpdateFlags_Target == ItemId(13,24) ||
		dwJewelsUpdateFlags_Target == ItemId(13,25) || dwJewelsUpdateFlags_Target == ItemId(13,26) ||
		dwJewelsUpdateFlags_Target == ItemId(13,27) || dwJewelsUpdateFlags_Target == ItemId(13,28))
		{
			bJewelsUpdateFlags_Switcher = TRUE;
		}
	}
	// ----
	if(dwJewelsUpdateFlags_Pointer == ItemId(14,240) || dwJewelsUpdateFlags_Pointer == ItemId(14,243) || dwJewelsUpdateFlags_Pointer == ItemId(14,244)) // -> Jewel of Level || Jewel of Option || Jewel of Excellent
	{
		if(dwJewelsUpdateFlags_Target == ItemId(13,8) || dwJewelsUpdateFlags_Target == ItemId(13,9) ||	// -> All Pendants & Rings
		dwJewelsUpdateFlags_Target == ItemId(13,12) || dwJewelsUpdateFlags_Target == ItemId(13,13) ||
		dwJewelsUpdateFlags_Target == ItemId(13,21) || dwJewelsUpdateFlags_Target == ItemId(13,22) ||
		dwJewelsUpdateFlags_Target == ItemId(13,23) || dwJewelsUpdateFlags_Target == ItemId(13,24) ||
		dwJewelsUpdateFlags_Target == ItemId(13,25) || dwJewelsUpdateFlags_Target == ItemId(13,26) ||
		dwJewelsUpdateFlags_Target == ItemId(13,27) || dwJewelsUpdateFlags_Target == ItemId(13,28) ||
		dwJewelsUpdateFlags_Target >= ItemId(12,0) && dwJewelsUpdateFlags_Target <= ItemId(12,6) ||		// -> All Wings Levels
		dwJewelsUpdateFlags_Target >= ItemId(12,36) && dwJewelsUpdateFlags_Target <= ItemId(12,43) ||
		dwJewelsUpdateFlags_Target >= ItemId(12,240) && dwJewelsUpdateFlags_Target <= ItemId(12,252) ||
		dwJewelsUpdateFlags_Target == ItemId(13,30))
		{
			bJewelsUpdateFlags_Switcher = TRUE;
		}
	}
	// ----
	if(dwJewelsUpdateFlags_Pointer == ItemId(14,13) || dwJewelsUpdateFlags_Pointer == ItemId(14,14) || dwJewelsUpdateFlags_Pointer == ItemId(14,16) || dwJewelsUpdateFlags_Pointer == ItemId(14,241)) // -> Jewel of Bless || Jewel of Soul || Jewel of Life || Jewel of Luck
	{
		if(dwJewelsUpdateFlags_Target >= ItemId(12,0) && dwJewelsUpdateFlags_Target <= ItemId(12,6) ||		// -> All Wings Levels
		dwJewelsUpdateFlags_Target >= ItemId(12,36) && dwJewelsUpdateFlags_Target <= ItemId(12,43) ||
		dwJewelsUpdateFlags_Target >= ItemId(12,236) && dwJewelsUpdateFlags_Target <= ItemId(12,239) ||
		dwJewelsUpdateFlags_Target >= ItemId(12,240) && dwJewelsUpdateFlags_Target <= ItemId(12,252) ||
		dwJewelsUpdateFlags_Target == ItemId(13,30))
		{
			bJewelsUpdateFlags_Switcher = TRUE;
		}
	}
	// ----
	if(dwJewelsUpdateFlags_Pointer == ItemId(14,171)) // -> Legend Amulet
	{
		if(dwJewelsUpdateFlags_Target >= ItemId(12,240) && dwJewelsUpdateFlags_Target <= ItemId(12,245)) // -> 4th Level Wings
		{
			bJewelsUpdateFlags_Switcher = TRUE;
			gLoadSound.LoadMixsJewelsPackSound();
			gPlaySound.PlayMixsJewelsPackSound();
		}
	}
	// ----
	if(dwJewelsUpdateFlags_Pointer == ItemId(14,174)) // -> Deathless Amulet
	{
		if(dwJewelsUpdateFlags_Target >= ItemId(12,240) && dwJewelsUpdateFlags_Target <= ItemId(12,245)) // -> 4th Level Wings
		{
			bJewelsUpdateFlags_Switcher = TRUE;
			gLoadSound.LoadMixsJewelsPackSound();
			gPlaySound.PlayMixsJewelsPackSound();
		}
	}
	// ----
	if(bJewelsUpdateFlags_Switcher == TRUE)
	{
		_asm
		{
			MOV ECX,oJewelsUpdateFlags_Call
			JMP ECX
		}
	}
	else
	{
		_asm
		{
			MOV ECX,DWORD PTR SS:[EBP-0x28]
			AND ECX,0x0FF
			TEST ECX,ECX
			JE ReturnLabel
			MOV dwJewelsUpdateFlags_Buffer,oJewelsUpdateFlags_Call
			JMP dwJewelsUpdateFlags_Buffer
			// ----
			ReturnLabel:
			// ----
			MOV dwJewelsUpdateFlags_Buffer,oJewelsUpdateFlags_Return
			JMP dwJewelsUpdateFlags_Buffer
		}
	}
}

void cJewels::InitJewelsUpdateFlags()
{
	gToolKit.SetRange((LPVOID)oJewelsUpdateFlags_Hook,17,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oJewelsUpdateFlags_Hook,this->JewelsUpdateFlags);
}

void cJewels::Load()
{
	this->InitJewelsBlockDrop();
	this->InitJewelsDropSound();
	this->InitJewelsPickSound();
	this->InitJewelsMoveOnItem();
	this->InitJewelsUpdateFlags();
	this->InitJewelsShineEffect();
	this->InitJewelsAllowOnItem();
	this->InitJewelsInvenSwitch();
	this->InitJewelsPricesOnShop();
}