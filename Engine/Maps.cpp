#include "StdAfx.h"

cMaps gMaps;

void Naked cMaps::NameLoad()
{
	static PCHAR cArkania_Map	= ARKANIA_MAP;
	static PCHAR cLoren_Market	= LOREN_MARKET;
	static PCHAR cKalimdor_Map	= KALIMDOR_MAP;
	static PCHAR cKarutan_Map	= KARUTAN_MAP;
	static PCHAR cAcheron_Map	= ACHERON_MAP;
	// ----
	static DWORD dwMapNameLoad_Call1 = 0x45FAD0;
	static DWORD dwMapNameLoad_Call2 = 0x409F10;
	static DWORD dwMapNameLoad_Jump  = 0x45F6A1;
	// ----
	_asm
	{
		MOV DWORD PTR SS:[EBP-0xD8],0x40 // 0x40 = 64 Duel Arena
		PUSH 0x008C1BE0					 // Arg1 = ASCII "Interface\duelarena.tga"
		LEA EDX,[EBP-0xD8]
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0xDC]
		ADD ECX,0x4
		CALL dwMapNameLoad_Call1
		MOV ECX,EAX
		CALL dwMapNameLoad_Call2
		// ---
		MOV DWORD PTR SS:[EBP-0xD8],0x42  // 0x42 = 66 Arkania
		PUSH cArkania_Map				  // Arg1 = ASCII "Interface\Arkania_Map.tga"
		LEA EDX,[EBP-0xD8]
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0xDC]
		ADD ECX,0x4
		CALL dwMapNameLoad_Call1
		MOV ECX,EAX
		CALL dwMapNameLoad_Call2
		// ---
		MOV DWORD PTR SS:[EBP-0xD8],0x43  // 0x43 = 67 Market
		PUSH cLoren_Market				  // Arg1 = ASCII "Interface\Loren_Market.tga"
		LEA EDX,[EBP-0xD8]
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0xDC]
		ADD ECX,0x4
		CALL dwMapNameLoad_Call1
		MOV ECX,EAX
		CALL dwMapNameLoad_Call2
		// ---
		MOV DWORD PTR SS:[EBP-0xD8],0x41  // 0x41 = 65 Kalimdor
		PUSH cKalimdor_Map				  // Arg1 = ASCII "Interface\Kalimdor.tga"
		LEA EDX,[EBP-0xD8]
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0xDC]
		ADD ECX,0x4
		CALL dwMapNameLoad_Call1
		MOV ECX,EAX
		CALL dwMapNameLoad_Call2
		// ---
		MOV DWORD PTR SS:[EBP-0xD8],0x44  // 0x44 = 68 Karutan
		PUSH cKarutan_Map				  // Arg1 = ASCII "Interface\Karutan.tga"
		LEA EDX,[EBP-0xD8]
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0xDC]
		ADD ECX,0x4
		CALL dwMapNameLoad_Call1
		MOV ECX,EAX
		CALL dwMapNameLoad_Call2
		// ----
		MOV DWORD PTR SS:[EBP-0xD8],0x45  // 0x45 = 69 Acheron
		PUSH cAcheron_Map				  // Arg1 = ASCII "Interface\Acheron.tga"
		LEA EDX,[EBP-0xD8]
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0xDC]
		ADD ECX,0x4
		CALL dwMapNameLoad_Call1
		MOV ECX,EAX
		CALL dwMapNameLoad_Call2
		// ----
		JMP dwMapNameLoad_Jump
	}
}

void cMaps::InitNameLoad()
{
	gToolKit.SetRange((LPVOID)0x0045F676,43,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0045F676,this->NameLoad);
}

void Naked cMaps::NameText()
{
	static DWORD dwMapNameText_Pointer;
	// ----
	static DWORD dwMapTextLoad_Call		= 0x402FF0;
	static DWORD dwMapTextLoad_Jump		= 0x5A4BDC;
	static DWORD dwMapTextLoad_Return	= 0x5A48FF;
	// ----
	_asm
	{
		MOV ESI,DWORD PTR SS:[ESP+0x0C]
		MOV dwMapNameText_Pointer,ESI
	}
	// ----
	if(dwMapNameText_Pointer == Crywolf)
	{
		_asm
		{
			PUSH 0x73B
			MOV ECX,0x07AAD828
			CALL dwMapTextLoad_Call
			JMP dwMapTextLoad_Jump
		}
	}
	else if(dwMapNameText_Pointer == Arkania)
	{
		_asm
		{
			PUSH 0x741				// Text.bmd number line: 1857
			MOV ECX,0x07AAD828
			CALL dwMapTextLoad_Call
			JMP dwMapTextLoad_Jump
		}
	}
	else if(dwMapNameText_Pointer == Vulcanus)
	{
		_asm
		{
			PUSH 0x742				// Text.bmd number line: 1858
			MOV ECX,0x07AAD828
			CALL dwMapTextLoad_Call
			JMP dwMapTextLoad_Jump
		}
	}
	else if(dwMapNameText_Pointer == Market)
	{
		_asm
		{
			PUSH 0x743				// Text.bmd number line: 1859
			MOV ECX,0x07AAD828
			CALL dwMapTextLoad_Call
			JMP dwMapTextLoad_Jump
		}
	}
	else if(dwMapNameText_Pointer == Kalimdor)
	{
		_asm
		{
			PUSH 0x739				// Text.bmd number line: 1849
			MOV ECX,0x07AAD828
			CALL dwMapTextLoad_Call
			JMP dwMapTextLoad_Jump
		}
	}
	else if(dwMapNameText_Pointer == Karutan)
	{
		_asm
		{
			PUSH 0x738				// Text.bmd number line: 1848
			MOV ECX,0x07AAD828
			CALL dwMapTextLoad_Call
			JMP dwMapTextLoad_Jump
		}
	}
	else if(dwMapNameText_Pointer == Acheron)
	{
		_asm
		{
			PUSH 0xBEA				// Text.bmd number line: 3050
			MOV ECX,0x07AAD828
			CALL dwMapTextLoad_Call
			JMP dwMapTextLoad_Jump
		}
	}
	else if(dwMapNameText_Pointer == Silent)
	{
		_asm
		{
			PUSH 0x737				// Text.bmd number line: 1847
			MOV ECX,0x07AAD828
			CALL dwMapTextLoad_Call
			JMP dwMapTextLoad_Jump
		}
	}
	// ----
	_asm
	{
		JMP dwMapTextLoad_Return
	}
}

void cMaps::InitNameText()
{
	gToolKit.SetRange((LPVOID)0x005A48E6,25,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x005A48E6,this->NameText);
}

void cMaps::CountAttFix()
{
	gToolKit.SetByte((PVOID)(0x005E9720+2),0x68);
}

void cMaps::CountMapFix()
{
	gToolKit.SetByte((PVOID)(0x005E94C9+2),0x68);
}

void cMaps::CountObjFix()
{
	gToolKit.SetByte((PVOID)(0x005E97C3+2),0x68);
}

void cMaps::CheckAttFix()
{
	gToolKit.SetByte((LPVOID)0x005E9723,ASM::JMPS);
	gToolKit.SetByte((LPVOID)0x005E9729,ASM::JMPS);
}

void cMaps::CheckMapFix()
{
	gToolKit.SetByte((LPVOID)0x005E94CC,ASM::JMPS);
	gToolKit.SetByte((LPVOID)0x005E94D2,ASM::JMPS);
}

void cMaps::CheckObjFix()
{
	gToolKit.SetByte((LPVOID)0x005E97C6,ASM::JMPS);
	gToolKit.SetByte((LPVOID)0x005E97CC,ASM::JMPS);
}

void Naked cMaps::AllowFire()
{
	static DWORD dwAllowFireEffect = 0x00806CC7;
	// ----
	_asm
	{
		CMP DWORD PTR DS:[0x008C5CF8],Calmness
		JE AllowFireEffect
		CMP DWORD PTR DS:[0x008C5CF8],Arkania
		JE AllowFireEffect
		CMP DWORD PTR DS:[0x008C5CF8],Market
		JE AllowFireEffect
		CMP DWORD PTR DS:[0x008C5CF8],Kalimdor
		JE AllowFireEffect
		CMP DWORD PTR DS:[0x008C5CF8],Karutan
		JE AllowFireEffect
		CMP DWORD PTR DS:[0x008C5CF8],Acheron
		JE AllowFireEffect
		// ----
		AllowFireEffect:
		// ----
		JMP dwAllowFireEffect
	}
}

void cMaps::InitAllowFire()
{
	gToolKit.SetRange((LPVOID)0x00806CC0,7,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x00806CC0,this->AllowFire);
}

void Naked cMaps::PlayMusic()
{
	static DWORD dwPlayMusic_Call1	= 0x005F7325;
	static DWORD dwPlayMusic_Call2	= 0x005F72E3;
	static DWORD dwPlayMusic_Return = 0x00602545;
	// ----
	static PCHAR cKalimdor_Music	= KALIMDOR_MUSIC;
	static PCHAR cArkania_Music		= ARKANIA_MUSIC;
	static PCHAR cMarket_Music		= LOREN_MARKET_MUSIC;
	static PCHAR cKarutanA_Music	= KARUTAN_A_MUSIC;
	static PCHAR cAcheron_Music		= ACHERON_MUSIC;
	// ----
	_asm
	{
		CMP DWORD PTR DS:[0x8C5CF8],3			// -> Noria = 03
		JNZ Label_1
		MOV EDX,DWORD PTR DS:[0x7A723B8]
		MOV AL,BYTE PTR DS:[EDX+0x0E]
		TEST AL,AL
		JE Label_1
		MOV EAX,DWORD PTR DS:[0x8D6F90]
		PUSH 0
		PUSH EAX
		CALL dwPlayMusic_Call1
		JMP Label_2
		Label_1:
		MOV ECX,DWORD PTR DS:[0x8D6F90]
		PUSH 0
		PUSH ECX
		CALL dwPlayMusic_Call2
		Label_2:
		MOV EAX,DWORD PTR DS:[0x8C5CF8]
		ADD ESP,0x08
		// ----
		CMP DWORD PTR DS:[0x8C5CF8],0x42		// -> Arkania = 66
		JNZ Label_1A
		MOV EDX,DWORD PTR DS:[0x7A723B8]
		MOV AL,BYTE PTR DS:[EDX+0x0E]
		TEST AL,AL
		JE Label_1A
		MOV EAX,DWORD PTR DS:[cArkania_Music]
		PUSH 0
		PUSH EAX
		CALL dwPlayMusic_Call1
		JMP Label_2A
		Label_1A:
		MOV ECX,DWORD PTR DS:[cArkania_Music]
		PUSH 0
		PUSH ECX
		CALL dwPlayMusic_Call2
		Label_2A:
		MOV EAX,DWORD PTR DS:[0x8C5CF8]
		ADD ESP,0x08
		// ----
		CMP DWORD PTR DS:[0x8C5CF8],0x43		// -> Market = 67
		JNZ Label_1B
		MOV EDX,DWORD PTR DS:[0x7A723B8]
		MOV AL,BYTE PTR DS:[EDX+0x0E]
		TEST AL,AL
		JE Label_1B
		MOV EAX,DWORD PTR DS:[cMarket_Music]
		PUSH 0
		PUSH EAX
		CALL dwPlayMusic_Call1
		JMP Label_2B
		Label_1B:
		MOV ECX,DWORD PTR DS:[cMarket_Music]
		PUSH 0
		PUSH ECX
		CALL dwPlayMusic_Call2
		Label_2B:
		MOV EAX,DWORD PTR DS:[0x8C5CF8]
		ADD ESP,0x08
		// ----
		CMP DWORD PTR DS:[0x8C5CF8],0x44		// -> Karutan 1 = 68
		JNZ Label_1C
		MOV EAX,DWORD PTR DS:[cKarutanA_Music]
		PUSH 0
		PUSH EAX
		CALL dwPlayMusic_Call1
		JMP Label_2C
		Label_1C:
		MOV ECX,DWORD PTR DS:[cKarutanA_Music]
		PUSH 0
		PUSH ECX
		CALL dwPlayMusic_Call2
		Label_2C:
		MOV EAX,DWORD PTR DS:[0x8C5CF8]
		ADD ESP,0x08
		// ----
		CMP DWORD PTR DS:[0x8C5CF8],0x41		// -> Kalimdor = 65
		JNZ Label_1D
		MOV EAX,DWORD PTR DS:[cKalimdor_Music]
		PUSH 0
		PUSH EAX
		CALL dwPlayMusic_Call1
		JMP Label_2D
		Label_1D:
		MOV ECX,DWORD PTR DS:[cKalimdor_Music]
		PUSH 0
		PUSH ECX
		CALL dwPlayMusic_Call2
		Label_2D:
		MOV EAX,DWORD PTR DS:[0x8C5CF8]
		ADD ESP,0x08
		// ----
		CMP DWORD PTR DS:[0x8C5CF8],0x45		// -> Acheron = 69
		JNZ Label_1E
		MOV EAX,DWORD PTR DS:[cAcheron_Music]
		PUSH 0
		PUSH EAX
		CALL dwPlayMusic_Call1
		JMP Label_2E
		Label_1E:
		MOV ECX,DWORD PTR DS:[cAcheron_Music]
		PUSH 0
		PUSH ECX
		CALL dwPlayMusic_Call2
		Label_2E:
		MOV EAX,DWORD PTR DS:[0x8C5CF8]
		ADD ESP,0x08
		// ----
		JMP dwPlayMusic_Return
	}
}

void cMaps::InitPlayMusic()
{
	gToolKit.SetRange((LPVOID)0x0060250A,59,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0060250A,this->PlayMusic);
}

static BOOL bAlphaTileMap_Switcher;

void Naked cMaps::AlphaTile()
{
	static DWORD dwAlphaTileMap_Pointer;
	static DWORD dwAlphaTileMap_Buffer;
	// ----
	bAlphaTileMap_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX,DWORD PTR DS:[0x8C5CF8]
		MOV dwAlphaTileMap_Pointer,EAX
	}
	// ----
	if(dwAlphaTileMap_Pointer == ElbelandSwitch)	// -> Map: 78 (Switch Character)
	{
		bAlphaTileMap_Switcher = TRUE;
	}
	else if(dwAlphaTileMap_Pointer == Acheron)		// -> Map: 70 (Acheron)
	{
		bAlphaTileMap_Switcher = TRUE;
	}
	// ----
	if(bAlphaTileMap_Switcher == TRUE)
	{
		_asm
		{
			MOV dwAlphaTileMap_Buffer,0x005E9A0B
			JMP dwAlphaTileMap_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwAlphaTileMap_Buffer,0x005E9A3F
			JMP dwAlphaTileMap_Buffer
		}
	}
}

void cMaps::InitAlphaTile()
{
	gToolKit.SetRange((LPVOID)0x005E9A02,9,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x005E9A02,this->AlphaTile);
}

/*
DWORD cMaps::ChangeAlphaName()
{
	const int AlphaTileName = 0x008D2770;
	static char AlphaNew[MAX_PATH] = {'\0'};
	sprintf(AlphaNew,MINI_MAP_FILE_LOAD,pMapNumber+1);
}
*/

void cMaps::Load()
{
	this->CountAttFix();
	this->CountMapFix();
	this->CountObjFix();
	this->CheckAttFix();
	this->CheckMapFix();
	this->CheckObjFix();
	this->InitNameLoad();
	this->InitNameText();
	this->InitAllowFire();
	this->InitPlayMusic();
	this->InitAlphaTile();//TEST
}