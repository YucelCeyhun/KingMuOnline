#include "StdAfx.h"
#include "user.h"
#include "NewOptions.h"

CNewOptions g_NewOptions;

CNewOptions::CNewOptions()
{
	/**/
}

CNewOptions::~CNewOptions()
{
	/**/
}

BOOL CNewOptions::RingOfSoul(LPOBJ lpObj)	// -> Ring of Soul Options (Modified: 26-12-16)
{
	if ( lpObj->Type != OBJ_USER )
	{
		return FALSE;
	}

	if ( lpObj->pInventory[8].IsItem() == FALSE )
	{
		return FALSE;
	}

	CItem * RingOfSoulSlot10 = &lpObj->pInventory[10];
	CItem * RingOfSoulSlot11 = &lpObj->pInventory[11];

	if ( RingOfSoulSlot10->m_Type == ITEMGET(13,155) && RingOfSoulSlot10->m_Durability > 0.0f )
	{
		return TRUE;
	}
	else if ( RingOfSoulSlot11->m_Type == ITEMGET(13,155) && RingOfSoulSlot11->m_Durability > 0.0f )
	{
		return TRUE;
	}
	else if ( RingOfSoulSlot10->m_Type == ITEMGET(13,155) && RingOfSoulSlot11->m_Type == ITEMGET(13,155) 
	&& RingOfSoulSlot10->m_Durability > 0.0f && RingOfSoulSlot11->m_Durability > 0.0f )
	{
		lpObj->AddLife					+= 250;
		lpObj->AddMana					+= 250;
		// ----
		return TRUE;
	}
	// ----
	return FALSE;
}

BOOL CNewOptions::RingOfBless(LPOBJ lpObj) // -> Ring of Bless Options (Modified: 22-12-16)
{
	if(lpObj->pInventory[EQUIPMENT_RING_RIGHT].m_Type == ITEMGET(13,154) || lpObj->pInventory[EQUIPMENT_RING_LEFT].m_Type == ITEMGET(13,154))
	{
		lpObj->SetOpAddDefence			+= 150;
		lpObj->SetOpImproveSheldDefence	+= 150;
		// ----
		return TRUE;
	}
	else if(lpObj->pInventory[EQUIPMENT_RING_RIGHT].m_Type == ITEMGET(13,154) && lpObj->pInventory[EQUIPMENT_RING_LEFT].m_Type == ITEMGET(13,154))
	{
		lpObj->SetOpAddDefence			+= 150;
		lpObj->SetOpImproveSheldDefence	+= 150;
		// ----
		return TRUE;
	}
	// ----
	return FALSE;
}

BOOL CNewOptions::RingOfChaos(LPOBJ lpObj) // -> Ring of Chaos Options (Modified: 22-12-16)
{
	if(lpObj->pInventory[EQUIPMENT_RING_RIGHT].m_Type == ITEMGET(13,153) || lpObj->pInventory[EQUIPMENT_RING_LEFT].m_Type == ITEMGET(13,153))
	{
		lpObj->DamageMinus			+= 100;
		lpObj->AddStrength			+= 100;
		// ----
		return TRUE;
	}
	else if(lpObj->pInventory[EQUIPMENT_RING_RIGHT].m_Type == ITEMGET(13,153) && lpObj->pInventory[EQUIPMENT_RING_LEFT].m_Type == ITEMGET(13,153))
	{
		lpObj->DamageMinus			+= 100;
		lpObj->AddStrength			+= 100;
		// ----
		return TRUE;
	}
	// ----
	return FALSE;
}

int CNewOptions::EvolveLegendary(struct OBJECTSTRUCT* gObj)	// -> Evolve Legendary Set Parts Special Option Damage Reflection
{
	if(gObj->pInventory[EQUIPMENT_HELM].m_Type == ITEMGET(7,102))
	{
		switch(gObj->pInventory[EQUIPMENT_HELM].m_Level)
		{
			case 10:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 10 / 100;
			break;
			case 11:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 11 / 100;
			break;
			case 12:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 12 / 100;
			break;
			case 13:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 13 / 100;
			break;
			case 14:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 14 / 100;
			break;
			case 15:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_ARMOR].m_Type == ITEMGET(8,102))
	{
		switch(gObj->pInventory[EQUIPMENT_ARMOR].m_Level)
		{
			case 10:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 10 / 100;
			break;
			case 11:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 11 / 100;
			break;
			case 12:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 12 / 100;
			break;
			case 13:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 13 / 100;
			break;
			case 14:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 14 / 100;
			break;
			case 15:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_PANTS].m_Type == ITEMGET(9,102))
	{
		switch(gObj->pInventory[EQUIPMENT_ARMOR].m_Level)
		{
			case 10:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 10 / 100;
			break;
			case 11:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 11 / 100;
			break;
			case 12:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 12 / 100;
			break;
			case 13:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 13 / 100;
			break;
			case 14:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 14 / 100;
			break;
			case 15:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_GLOVES].m_Type == ITEMGET(10,102))
	{
		switch(gObj->pInventory[EQUIPMENT_GLOVES].m_Level)
		{
			case 10:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 10 / 100;
			break;
			case 11:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 11 / 100;
			break;
			case 12:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 12 / 100;
			break;
			case 13:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 13 / 100;
			break;
			case 14:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 14 / 100;
			break;
			case 15:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_BOOTS].m_Type == ITEMGET(11,102))
	{
		switch(gObj->pInventory[EQUIPMENT_BOOTS].m_Level)
		{
			case 10:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 10 / 100;
			break;
			case 11:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 11 / 100;
			break;
			case 12:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 12 / 100;
			break;
			case 13:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 13 / 100;
			break;
			case 14:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 14 / 100;
			break;
			case 15:
				gObj->SetOpReflectionDamage += gObj->SetOpReflectionDamage * 15 / 100;
			break;
		}
	}
	// ----
	return 1;
}

int CNewOptions::EvolveGuardian(struct OBJECTSTRUCT* gObj)	// -> Evolve Guardian Set Parts Special Option Success Rate
{
	if(gObj->pInventory[EQUIPMENT_HELM].m_Type == ITEMGET(7,101))
	{
		switch(gObj->pInventory[EQUIPMENT_HELM].m_Level)
		{
			case 10:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
			break;
			case 11:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
			break;
			case 12:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
			break;
			case 13:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
			break;
			case 14:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
			break;
			case 15:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_ARMOR].m_Type == ITEMGET(8,101))
	{
		switch(gObj->pInventory[EQUIPMENT_ARMOR].m_Level)
		{
			case 10:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
			break;
			case 11:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
			break;
			case 12:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
			break;
			case 13:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
			break;
			case 14:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
			break;
			case 15:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_PANTS].m_Type == ITEMGET(9,101))
	{
		switch(gObj->pInventory[EQUIPMENT_PANTS].m_Level)
		{
			case 10:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
			break;
			case 11:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
			break;
			case 12:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
			break;
			case 13:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
			break;
			case 14:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
			break;
			case 15:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_GLOVES].m_Type == ITEMGET(10,101))
	{
		switch(gObj->pInventory[EQUIPMENT_GLOVES].m_Level)
		{
			case 10:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
			break;
			case 11:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
			break;
			case 12:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
			break;
			case 13:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
			break;
			case 14:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
			break;
			case 15:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_BOOTS].m_Type == ITEMGET(11,101))
	{
		switch(gObj->pInventory[EQUIPMENT_BOOTS].m_Level)
		{
			case 10:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
			break;
			case 11:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
			break;
			case 12:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
			break;
			case 13:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
			break;
			case 14:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
			break;
			case 15:
				gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
			break;
		}
	}
	// ----
	return 1;
}

int CNewOptions::EvolveDragon(struct OBJECTSTRUCT* gObj)	// -> Evolve Dragon Set Parts Special Option Decrease
{
	if(gObj->pInventory[EQUIPMENT_HELM].m_Type == ITEMGET(7,100))
	{
		switch(gObj->pInventory[EQUIPMENT_HELM].m_Level)
		{
			case 10:
				gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
			break;
			case 11:
				gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
			break;
			case 12:
				gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
			break;
			case 13:
				gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
			break;
			case 14:
				gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
			break;
			case 15:
				gObj->DamageMinus += gObj->DamageMinus * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_ARMOR].m_Type == ITEMGET(8,100))
	{
		switch(gObj->pInventory[EQUIPMENT_ARMOR].m_Level)
		{
			case 10:
				gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
			break;
			case 11:
				gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
			break;
			case 12:
				gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
			break;
			case 13:
				gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
			break;
			case 14:
				gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
			break;
			case 15:
				gObj->DamageMinus += gObj->DamageMinus * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_PANTS].m_Type == ITEMGET(9,100))
	{
		switch(gObj->pInventory[EQUIPMENT_PANTS].m_Level)
		{
			case 10:
				gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
			break;
			case 11:
				gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
			break;
			case 12:
				gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
			break;
			case 13:
				gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
			break;
			case 14:
				gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
			break;
			case 15:
				gObj->DamageMinus += gObj->DamageMinus * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_GLOVES].m_Type == ITEMGET(10,100))
	{
		switch(gObj->pInventory[EQUIPMENT_GLOVES].m_Level)
		{
			case 10:
				gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
			break;
			case 11:
				gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
			break;
			case 12:
				gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
			break;
			case 13:
				gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
			break;
			case 14:
				gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
			break;
			case 15:
				gObj->DamageMinus += gObj->DamageMinus * 15 / 100;
			break;
		}
	}
	if(gObj->pInventory[EQUIPMENT_BOOTS].m_Type == ITEMGET(11,100))
	{
		switch(gObj->pInventory[EQUIPMENT_BOOTS].m_Level)
		{
			case 10:
				gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
			break;
			case 11:
				gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
			break;
			case 12:
				gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
			break;
			case 13:
				gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
			break;
			case 14:
				gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
			break;
			case 15:
				gObj->DamageMinus += gObj->DamageMinus * 15 / 100;
			break;
		}
	}
	// ----
	return 1;
}

int CNewOptions::DarkWolf(struct OBJECTSTRUCT* gObj)	// -> Dark Wolf Pet Options
{
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level == 1) // +1 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 30 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 30 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 5 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level == 2) // +2 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 31 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 31 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 6 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level == 3) // +3 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 32 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 32 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 7 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level == 4) // +4 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 33 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 33 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 8 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level == 5) // +5 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 34 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 34 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 9 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level == 6) // +6 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 35 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 35 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level == 7) // +7 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 36 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 36 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 16 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level == 8) // +8 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 37 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 37 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 17 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level == 9) // +9 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 38 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 38 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 18 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,97) && gObj->pInventory[8].m_Level >= 10 && gObj->pInventory[8].m_Level <= 15) // +10,+11,+12,+13,+14,+15 cases
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 39 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 39 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 19 / 100;
	}
	// ----
	return 1;
}

int CNewOptions::Mistic(struct OBJECTSTRUCT* gObj) // -> Mistic Tiger Pet Options
{
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level == 1) // +1 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 30 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 30 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 5 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level == 2) // +2 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 31 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 31 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 6 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level == 3) // +3 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 32 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 32 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 7 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level == 4) // +4 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 33 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 33 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 8 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level == 5) // +5 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 34 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 34 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 9 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level == 6) // +6 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 35 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 35 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level == 7) // +7 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 36 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 36 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 16 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level == 8) // +8 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 37 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 37 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 17 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level == 9) // +9 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 38 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 38 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 18 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,99) && gObj->pInventory[8].m_Level >= 10 && gObj->pInventory[8].m_Level <= 15) // +10,+11,+12,+13,+14,+15 cases
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 39 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 39 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 19 / 100;
	}
	// ----
	return 1;
}

int CNewOptions::FangSable(struct OBJECTSTRUCT* gObj) // -> Fang Sable Pet Options
{
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level == 1) // +1 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 30 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 30 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 5 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level == 2) // +2 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 31 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 31 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 6 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level == 3) // +3 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 32 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 32 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 7 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level == 4) // +4 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 33 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 33 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 8 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level == 5) // +5 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 34 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 34 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 9 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level == 6) // +6 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 35 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 35 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level == 7) // +7 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 36 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 36 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 16 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level == 8) // +8 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 37 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 37 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 17 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level == 9) // +9 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 38 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 38 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 18 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,98) && gObj->pInventory[8].m_Level >= 10 && gObj->pInventory[8].m_Level <= 15) // +10,+11,+12,+13,+14,+15 cases
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 39 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 39 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 19 / 100;
	}
	// ----
	return 1;
}

int CNewOptions::GiantLyon(struct OBJECTSTRUCT* gObj) // -> Giant Lyon Pet Options
{
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level == 1) // +1 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 30 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 30 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 5 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level == 2) // +2 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 31 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 31 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 6 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level == 3) // +3 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 32 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 32 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 7 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level == 4) // +4 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 33 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 33 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 8 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level == 5) // +5 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 34 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 34 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 9 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level == 6) // +6 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 35 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 35 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level == 7) // +7 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 36 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 36 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 16 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level == 8) // +8 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 37 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 37 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 17 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level == 9) // +9 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 38 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 38 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 18 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,100) && gObj->pInventory[8].m_Level >= 10 && gObj->pInventory[8].m_Level <= 15) // +10,+11,+12,+13,+14,+15 cases
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 39 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 39 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 19 / 100;
	}
	// ----
	return 1;
}

int CNewOptions::LycanWolf(struct OBJECTSTRUCT* gObj) // -> Lycan Wolf Pet Options
{
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level == 1) // +1 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 30 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 30 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 5 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 10 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level == 2) // +2 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 31 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 31 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 6 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 11 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level == 3) // +3 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 32 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 32 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 7 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 12 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level == 4) // +4 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 33 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 33 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 8 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 13 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level == 5) // +5 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 34 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 34 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 9 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 14 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level == 6) // +6 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 35 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 35 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 10 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 15 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level == 7) // +7 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 36 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 36 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 11 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 16 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level == 8) // +8 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 37 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 37 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 12 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 17 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level == 9) // +9 case
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 38 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 38 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 13 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 18 / 100;
	}
	if(gObj->pInventory[8].m_Type == ITEMGET(13,101) && gObj->pInventory[8].m_Level >= 10 && gObj->pInventory[8].m_Level <= 15) // +10,+11,+12,+13,+14,+15 cases
	{
		if(gObj->Class == CLASS_SUMMONER || gObj->Class == CLASS_WIZARD)
		{
			gObj->m_MagicDamageMax += gObj->m_MagicDamageMax * 39 / 100;
		}
		else
		{
			gObj->m_AttackDamageMax += gObj->m_AttackDamageMax * 39 / 100;
		}
		// ----
		gObj->DamageMinus += gObj->DamageMinus * 14 / 100;
		gObj->SetOpAddDefenceRate += gObj->SetOpAddDefenceRate * 19 / 100;
	}
	// ----
	return 1;
}

int CNewOptions::Imperial(struct OBJECTSTRUCT* gObj)
{
	if(gObj->pInventory[7].m_Type == ITEMGET(12,249))
	{
		gObj->DamageMinus += 50;
		gObj->SetOpReflectionDamage += 40;
		gObj->SetOpAddDefenceRate += 30;
	}
	// ----
	return 1;
}

int CNewOptions::Evolve(struct OBJECTSTRUCT* gObj)
{
	if(gObj->pInventory[2].m_Type == ITEMGET(7,100)
	|| gObj->pInventory[2].m_Type == ITEMGET(7,101)
	|| gObj->pInventory[2].m_Type == ITEMGET(7,102))
	{
		gObj->SetOpAddDefenceRate += 20;
	}
	if(gObj->pInventory[3].m_Type == ITEMGET(8,100)
	|| gObj->pInventory[3].m_Type == ITEMGET(8,101)
	|| gObj->pInventory[3].m_Type == ITEMGET(8,102))
	{
		gObj->SetOpAddDefenceRate += 20;
	}
	if(gObj->pInventory[4].m_Type == ITEMGET(9,100)
	|| gObj->pInventory[4].m_Type == ITEMGET(9,101)
	|| gObj->pInventory[4].m_Type == ITEMGET(9,102))
	{
		gObj->SetOpAddDefenceRate += 20;
	}
	if(gObj->pInventory[5].m_Type == ITEMGET(10,100)
	|| gObj->pInventory[5].m_Type == ITEMGET(10,101)
	|| gObj->pInventory[5].m_Type == ITEMGET(10,102))
	{
		gObj->SetOpAddDefenceRate += 20;
	}
	if(gObj->pInventory[6].m_Type == ITEMGET(11,100)
	|| gObj->pInventory[6].m_Type == ITEMGET(11,101)
	|| gObj->pInventory[6].m_Type == ITEMGET(11,102))
	{
		gObj->SetOpAddDefenceRate += 20;
	}
	// ----
	return 1;
}

int CNewOptions::Init(struct OBJECTSTRUCT* gObj)
{
	if (gObj->pInventory[0].m_Type == ITEMGET(0,29) || gObj->pInventory[1].m_Type == ITEMGET(0,29) ||
		gObj->pInventory[0].m_Type == ITEMGET(0,30) || gObj->pInventory[1].m_Type == ITEMGET(0,30))
	{
		gObj->SetOpAddCriticalDamage += 5;
	}
	// ----
	if (gObj->pInventory[0].m_Type == ITEMGET(2,19) || gObj->pInventory[1].m_Type == ITEMGET(2,19) ||
		gObj->pInventory[0].m_Type == ITEMGET(2,20) || gObj->pInventory[1].m_Type == ITEMGET(2,20) ||
		gObj->pInventory[0].m_Type == ITEMGET(2,21) || gObj->pInventory[1].m_Type == ITEMGET(2,21))
	{
		gObj->SetOpAddExDamage += 5;
	}
	// ----
	if (gObj->pInventory[0].m_Type == ITEMGET(3,12) || gObj->pInventory[1].m_Type == ITEMGET(3,12))
	{
		gObj->SetOpAddCriticalDamage += 5;
	}
	// ----
	if (gObj->pInventory[1].m_Type == ITEMGET(4,25) ||
		gObj->pInventory[1].m_Type == ITEMGET(4,26) ||
		gObj->pInventory[1].m_Type == ITEMGET(4,28))
	{
		gObj->SetOpDoubleDamage += 5;
	}
	// ----
	if (gObj->pInventory[0].m_Type == ITEMGET(5,35) || gObj->pInventory[1].m_Type == ITEMGET(5,35))
	{
		gObj->SetOpAddMagicPower += 5;
	}
	// ----
	if (gObj->pInventory[1].m_Type == ITEMGET(6,22))
	{
		gObj->SetOpAddDefenceRate += 5;
	}
	// ----
	return 1;
}