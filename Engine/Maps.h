#ifndef __MAPS_H__
#define __MAPS_H__

#define ARKANIA_MAP				"Interface\\Arkania_Map.tga"
#define LOREN_MARKET			"Interface\\Loren_Market.tga"
#define KALIMDOR_MAP			"Interface\\Kalimdor.tga"
#define KARUTAN_MAP				"Interface\\Karutan.tga"
#define ACHERON_MAP				"Interface\\Acheron.tga"

#define ARKANIA_MUSIC			"data\\music\\Arkania.mp3"
#define LOREN_MARKET_MUSIC		"data\\music\\Market.mp3"
#define KALIMDOR_MUSIC			"data\\music\\Kalimdor.mp3"
#define KARUTAN_A_MUSIC			"data\\music\\Karutan_A.mp3"
#define ACHERON_MUSIC			"data\\music\\Acheron.mp3"

//#define ALPHA_TILE				"Custom\\"

class cMaps
{
public:
	void Load();
	// ----
	void InitNameLoad();
	void InitNameText();
	void InitAllowFire();
	void InitPlayMusic();
	void InitAlphaTile();
	// ----
	void CountAttFix();
	void CountMapFix();
	void CountObjFix();
	// ----
	void CheckAttFix();
	void CheckMapFix();
	void CheckObjFix();
	// ----
	//DWORD ChangeAlphaName();
	// ----
	static void NameLoad();
	static void NameText();
	static void AllowFire();
	static void PlayMusic();
	static void AlphaTile();
	// ----

};

extern cMaps gMaps;

#endif