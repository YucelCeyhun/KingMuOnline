#include "StdAfx.h"

cWings gWings;

void Naked cWings::FixMoveKanturu()
{
	static DWORD dwFixMoveKanturu_Buffer;
	// ----
	_asm
	{
		MOV dwFixMoveKanturu_Buffer,ECX
	}
	// ----
	if(dwFixMoveKanturu_Buffer < ItemId(12,236) && dwFixMoveKanturu_Buffer > ItemId(12,252) 
	|| dwFixMoveKanturu_Buffer != ItemId(13,37) || dwFixMoveKanturu_Buffer != ItemId(13,97) 
	|| dwFixMoveKanturu_Buffer != ItemId(13,98) || dwFixMoveKanturu_Buffer != ItemId(13,99))
	{
		_asm
		{
			MOV dwFixMoveKanturu_Buffer,oFixMoveKanturu_Return
			JMP dwFixMoveKanturu_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwFixMoveKanturu_Buffer,oFixMoveKanturu_Allowed
			JMP dwFixMoveKanturu_Buffer
		}
	}
}

void cWings::InitFixMoveKanturu()
{
	gToolKit.SetRange((LPVOID)oFixMoveKanturu_Hook,8,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oFixMoveKanturu_Hook,this->FixMoveKanturu);
}

void Naked cWings::ShowDurability()
{
	static WORD wShowDurability_Pointer;
	static DWORD dwShowDurability_Buffer;
	// ----
	_asm
	{
		MOV wShowDurability_Pointer,AX
	}
	// ----
	if(wShowDurability_Pointer < ItemId(12,0)
	|| wShowDurability_Pointer >= ItemId(12,236) && wShowDurability_Pointer <= ItemId(12,252)
	|| wShowDurability_Pointer >= ItemId(13,0) && wShowDurability_Pointer < ItemId(14,0))
	{
		_asm
		{
			MOV dwShowDurability_Buffer,oShowDurability_Allowed
			JMP dwShowDurability_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwShowDurability_Buffer,oShowDurability_Return
			JMP dwShowDurability_Buffer
		}
	}
}

void cWings::InitShowDurability()
{
	gToolKit.SetRange((LPVOID)oShowDurability_Hook,18,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oShowDurability_Hook,this->ShowDurability);
}

void Naked cWings::ShowAdditionals()
{
	static DWORD dwShowAdditionals_Buffer;
	// ----
	_asm
	{
		CMP CX,ItemId(12,36)
		JL EXIT
		CMP CX,ItemId(12,40)
		JLE SET_ADD
		CMP CX,ItemId(12,43)
		JE SET_ADD
		CMP CX,ItemId(12,236)
		JL EXIT
		CMP CX,ItemId(12,239)
		JLE SET_ADD_43
		CMP CX,ItemId(12,240)
		JL EXIT
		CMP CX,ItemId(12,245)
		JLE SET_ADD_45
		CMP CX,ItemId(12,246)
		JL EXIT
		CMP CX,ItemId(12,252)
		JLE SET_ADD_52
		// ----
		JMP EXIT
		// ----
		SET_ADD:
		// ----
		LEA ESI,[EBP+EBP+39]
		MOV dwShowAdditionals_Buffer,oShowAdditionals_Allowed
		JMP dwShowAdditionals_Buffer
		// ----
		SET_ADD_43:
		// ----
		LEA ESI,[EBP+EBP+43]
		MOV dwShowAdditionals_Buffer,oShowAdditionals_Allowed
		JMP dwShowAdditionals_Buffer
		// ----
		SET_ADD_45:
		// ----
		LEA ESI,[EBP+EBP+45]
		MOV dwShowAdditionals_Buffer,oShowAdditionals_Allowed
		JMP dwShowAdditionals_Buffer
		// ----
		SET_ADD_52:
		// ----
		LEA ESI,[EBP+EBP+52]
		MOV dwShowAdditionals_Buffer,oShowAdditionals_Allowed
		JMP dwShowAdditionals_Buffer
		// ----
		EXIT:
		// ----
		MOV dwShowAdditionals_Buffer,oShowAdditionals_Return
		JMP dwShowAdditionals_Buffer
	}
}

void cWings::InitShowAdditionals()
{
	gToolKit.SetRange((LPVOID)oShowAdditionals_Hook,29,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oShowAdditionals_Hook,this->ShowAdditionals);
}

void Naked cWings::AddLuckOption()
{
	static DWORD dwAddLuckOption_Pointer;
	static DWORD dwAddLuckOption_Buffer;
	// ----
	_asm
	{
		MOV dwAddLuckOption_Pointer,ECX
	}
	// ----
	if(dwAddLuckOption_Pointer == ItemId(12,43) || dwAddLuckOption_Pointer >= ItemId(12,236) && dwAddLuckOption_Pointer <= ItemId(12,252))
	{
		_asm
		{
			MOV dwAddLuckOption_Buffer,oAddLuckOption_Allowed
			JMP dwAddLuckOption_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwAddLuckOption_Buffer,oAddLuckOption_Return
			JMP dwAddLuckOption_Buffer
		}
	}
}

void cWings::InitAddLuckOption()
{
	gToolKit.SetRange((LPVOID)oAddLuckOption_Hook,8,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oAddLuckOption_Hook,this->AddLuckOption);
}

void Naked cWings::AddExcellentStatus()
{
	static DWORD dwAddExcellentStatus_Pointer;
	static DWORD dwAddExcellentStatus_Buffer;
	// ----
	_asm
	{
		MOV dwAddExcellentStatus_Pointer,ECX
	}
	// ----
	if(dwAddExcellentStatus_Pointer == ItemId(12,43) || dwAddExcellentStatus_Pointer >= ItemId(12,236) && dwAddExcellentStatus_Pointer <= ItemId(12,252))
	{
		_asm
		{
			MOV dwAddExcellentStatus_Buffer,oAddExcellentStatus_Allowed
			JMP dwAddExcellentStatus_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwAddExcellentStatus_Buffer,oAddExcellentStatus_Return
			JMP dwAddExcellentStatus_Buffer
		}
	}
}

void cWings::InitAddExcellentStatus()
{
	gToolKit.SetRange((LPVOID)oAddExcellentStatus_Hook,12,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oAddExcellentStatus_Hook,this->AddExcellentStatus);
}

void Naked cWings::HideExcellentText()
{
	static WORD wHideExcellentText_Pointer;
	static DWORD dwHideExcellentText_Buffer;
	// ----
	_asm
	{
		MOV wHideExcellentText_Pointer,AX
	}
	// ----
	if(wHideExcellentText_Pointer == ItemId(13,30) || wHideExcellentText_Pointer >= ItemId(12,236) && wHideExcellentText_Pointer <= ItemId(12,252)
	|| wHideExcellentText_Pointer == ItemId(0,35) || wHideExcellentText_Pointer == ItemId(0,36) || wHideExcellentText_Pointer == ItemId(2,24)
	|| wHideExcellentText_Pointer == ItemId(4,130) || wHideExcellentText_Pointer == ItemId(5,39) || wHideExcellentText_Pointer == ItemId(5,40)
	|| wHideExcellentText_Pointer >= ItemId(13,77) && wHideExcellentText_Pointer <= ItemId(13,79) || wHideExcellentText_Pointer >= ItemId(13,81) 
	&& wHideExcellentText_Pointer <= ItemId(13,94))	// -> Fix Excellent Text for All Custom Added Pets
	{
		_asm
		{
			MOV dwHideExcellentText_Buffer,oHideExcellentText_Allowed
			JMP dwHideExcellentText_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwHideExcellentText_Buffer,oHideExcellentText_Return
			JMP dwHideExcellentText_Buffer
		}
	}
}

void cWings::InitHideExcellentText()
{
	gToolKit.SetRange((LPVOID)oHideExcellentText_Hook,6,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oHideExcellentText_Hook,this->HideExcellentText);
}

void Naked cWings::HideExcellentGlow()
{
	static DWORD dwHideExcellentGlow_Pointer;
	static DWORD dwHideExcellentGlow_Buffer;
	// ----
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		MOV ECX,DWORD PTR DS:[EAX+0x30]
		MOV dwHideExcellentGlow_Pointer,ECX
	}
	// ----
	if(dwHideExcellentGlow_Pointer >= ObjectId(12,36) && dwHideExcellentGlow_Pointer <= ObjectId(12,43) 
	|| dwHideExcellentGlow_Pointer >= ObjectId(12,236) && dwHideExcellentGlow_Pointer <= ObjectId(12,252)
	|| dwHideExcellentGlow_Pointer >= ObjectId(13,77) && dwHideExcellentGlow_Pointer <= ObjectId(13,79)
	|| dwHideExcellentGlow_Pointer >= ObjectId(13,81) && dwHideExcellentGlow_Pointer <= ObjectId(13,94))	// -> Fix Excellent Glow on All Custom Pets
	{
		_asm
		{
			MOV dwHideExcellentGlow_Buffer,oHideExcellentGlow_Allowed
			JMP dwHideExcellentGlow_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwHideExcellentGlow_Buffer,oHideExcellentGlow_Return
			JMP dwHideExcellentGlow_Buffer
		}
	}
}

void cWings::InitHideExcellentGlow()
{
	gToolKit.SetRange((LPVOID)oHideExcellentGlow_Hook,28,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oHideExcellentGlow_Hook,this->HideExcellentGlow);
}

void Naked cWings::DisableLevelShine()
{
	static DWORD dwDisableLevelShine_Pointer;
	static DWORD dwDisableLevelShine_SubPointer;
	static DWORD dwDisableLevelShine_Buffer;
	// ----
	_asm
	{
		MOV dwDisableLevelShine_Pointer,EDX
		SUB EDX,ObjectId(12,15)
		MOV dwDisableLevelShine_SubPointer,EDX
		MOV DWORD PTR SS:[EBP-0x4CC],EDX
	}
	// ----
	if(dwDisableLevelShine_Pointer >= ObjectId(12,236) && dwDisableLevelShine_Pointer <= ObjectId(12,252))
	{
		_asm
		{
			MOV DWORD PTR SS:[EBP-0x8],0	// -> Shine Level 0
		}
	}
	else if(dwDisableLevelShine_Pointer >= ObjectId(12,150) && dwDisableLevelShine_Pointer <= ObjectId(12,156))	// -> Custom Bundles
	{
		_asm
		{
			MOV DWORD PTR SS:[EBP-0x8],0	// -> Shine Level 0
		}
	}
	else if(dwDisableLevelShine_Pointer >= ObjectId(13,77) && dwDisableLevelShine_Pointer <= ObjectId(13,79))	// -> Custom Unicorn & Skeleton
	{
		_asm
		{
			MOV DWORD PTR SS:[EBP-0x8],0	// -> Shine Level 0
		}
	}
	else if(dwDisableLevelShine_Pointer >= ObjectId(13,81) && dwDisableLevelShine_Pointer <= ObjectId(13,94))	// -> All Custom Guardian Type Pets
	{
		_asm
		{
			MOV DWORD PTR SS:[EBP-0x8],0	// -> Shine Level 0
		}
	}
	// ----
	if(dwDisableLevelShine_SubPointer > 32)
	{
		_asm
		{
			MOV dwDisableLevelShine_Buffer,oDisableLevelShine_Allowed
			JMP dwDisableLevelShine_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwDisableLevelShine_Buffer,oDisableLevelShine_Return
			JMP dwDisableLevelShine_Buffer
		}
	}
}

void cWings::InitDisableLevelShine()
{
	gToolKit.SetRange((LPVOID)oDisableLevelShine_Hook,19,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oDisableLevelShine_Hook,this->DisableLevelShine);
}

void Naked cWings::AddAdditionalOption()
{
	static BYTE btAddAdditionalOption_Value;
	static BYTE btAddAdditionalOption_Stat;
	static BYTE btAddAdditionalOption_Number;
	// ----
	static DWORD dwAddAdditionalOption_Pointer;
	static DWORD dwAddAdditionalOption_NewOption;
	static DWORD dwAddAdditionalOption_Buffer;
	// ----
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		// ----
		MOVSX EAX,WORD PTR DS:[EDX]
		MOV dwAddAdditionalOption_Pointer,EAX
		// ----
		MOV EDX,DWORD PTR SS:[EBP-0x14]
		MOV dwAddAdditionalOption_NewOption,EDX
		// ----
		MOV CL,BYTE PTR SS:[EBP-0x10]
		MOV btAddAdditionalOption_Value,CL
	}
	// ----
	switch(dwAddAdditionalOption_Pointer)
	{
		case ItemId(12,43):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = WizardryDamage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = CurseSpell;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,236):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = WizardryDamage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,237):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,238):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,239):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,240):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = WizardryDamage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,241):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,242):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,243):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = WizardryDamage;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,244):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,245):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = WizardryDamage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = CurseSpell;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,246):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = WizardryDamage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,247):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = WizardryDamage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,248):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = WizardryDamage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,249):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,250):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,251):
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = WizardryDamage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		case ItemId(12,252):	// -> Deathless Wings (Added: 22-12-16)
		{
			if((dwAddAdditionalOption_NewOption >> 4) & 1)
			{
				btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
				btAddAdditionalOption_Number = Damage;
			}
			else
			{
				if((dwAddAdditionalOption_NewOption >> 5) & 1)
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value * 4;
					btAddAdditionalOption_Number = Defense;
				}
				else
				{
					btAddAdditionalOption_Stat = btAddAdditionalOption_Value;
					btAddAdditionalOption_Number = HPRecovery;
				}
			}
		}
		break;
		// ----
		default:
		{
			_asm
			{
				MOV dwAddAdditionalOption_Buffer,oAddAdditionalLife_Default
				JMP dwAddAdditionalOption_Buffer
			}
		}
		break;
	}
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x10]
		SHL EDX,2
		// ----
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		XOR ECX,ECX
		// ----
		MOV CL,BYTE PTR DS:[EAX+0x25]
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		MOV DL,btAddAdditionalOption_Stat
		MOV BYTE PTR DS:[ECX+EAX+0x2E],DL
		// ----
		XOR EDX,EDX
		MOV DL,BYTE PTR DS:[EAX+0x25]
		MOV CL,btAddAdditionalOption_Number
		MOV BYTE PTR DS:[EDX+EAX+0x26],CL
		// ----
		ADD DL,1
		MOV BYTE PTR DS:[EAX+0x25],DL
		// ----
		MOV dwAddAdditionalOption_Buffer,oAddAdditionalLife_Default
		JMP dwAddAdditionalOption_Buffer
	}
}

void cWings::InitAddAdditionalOption()
{
	gToolKit.SetRange((LPVOID)oAddAdditionalLife_Hook,199,ASM::NOP);
	gToolKit.SetJmp((LPVOID)oAddAdditionalLife_Hook,this->AddAdditionalOption);
}

void Naked cWings::AllowRepair()
{
	static DWORD dwAllowRepair_Pointer;
	static DWORD dwAllowRepair_Buffer;
	// ----
	_asm
	{
		MOV EAX,DWORD PTR SS:[ESP+0x04]
		MOVSX EAX,WORD PTR DS:[EAX]
		MOV dwAllowRepair_Pointer,EAX
	}
	// ----
	if(dwAllowRepair_Pointer >= ItemId(12,236) && dwAllowRepair_Pointer <= ItemId(12,255))
	{
		_asm
		{
			XOR AL,AL
			MOV dwAllowRepair_Buffer,0x0059E1B0
			JMP dwAllowRepair_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwAllowRepair_Buffer,0x0059E187	// Return TEST
			JMP dwAllowRepair_Buffer
		}
	}
}

void cWings::InitAllowRepair()
{
	gToolKit.SetRange((LPVOID)0x0059E180,7,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0059E180,this->AllowRepair);
}

#define pSetMaxDurability ((int(__cdecl*)(ObjectItem*lpItem,int ScriptStruct,int Level))0x0058E5C0)

int cWings::SetMaxDurability(ObjectItem*lpItem,int ScriptStruct,int Level)
{
	if(lpItem->Index >= ItemId(12,236) && lpItem->Index <= ItemId(12,255))
	{
		switch(Level)
		{
			case 15:
			case 14:
				return 255;
			break;
			// ----
			case 13:
				return 252;
			break;
			// ----
			case 12:
				return 246;
			break;
			// ----
			case 11:
				return 241;
			break;
			// ----
			case 10:
				return 237;
			break;
			// ----
			case 9:
				return 234;
			break;
			// ----
			case 8:
				return 232;
			break;
			// ----
			case 7:
				return 230;
			break;
			// ----
			case 6:
				return 228;
			break;
			// ----
			case 5:
				return 226;
			break;
			// ----
			case 4:
				return 224;
			break;
			// ----
			case 3:
				return 223;
			break;
			// ----
			case 2:
				return 222;
			break;
			// ----
			case 1:
				return 221;
			break;
		}
	}
	// ----
	if(lpItem->Index >= ItemId(12,36) && lpItem->Index <= ItemId(12,40) || lpItem->Index == ItemId(12,43))
	{
		switch(Level)
		{
			case 14:
			case 15:
				return 255;
			break;
		}
	}
	// ----
	if(lpItem->Index == ItemId(13,51)) // -> Scroll of Blood
	{
		if(Level >= 1 && Level <= 15)
		{
			return 0;
		}
	}
	// ----
	return pSetMaxDurability(lpItem,ScriptStruct,Level);
}

void cWings::InitSetMaxDurability()
{
	gToolKit.SetOp((LPVOID)0x004B7E30,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0050E886,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0058E20D,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0058E2DA,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x005960AE,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0059897C,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00598E3A,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00731DCF,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00735E83,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00736459,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00736E22,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x007370BD,this->SetMaxDurability,ASM::CALL);
	gToolKit.SetOp((LPVOID)0x007567E4,this->SetMaxDurability,ASM::CALL);
}

void cWings::Load()
{
	this->InitAllowRepair();
	this->InitAddLuckOption();
	this->InitFixMoveKanturu();
	this->InitShowDurability();
	this->InitShowAdditionals();
	this->InitSetMaxDurability();
	this->InitDisableLevelShine();
	this->InitHideExcellentText();
	this->InitHideExcellentGlow();
	this->InitAddExcellentStatus();
	this->InitAddAdditionalOption();
}