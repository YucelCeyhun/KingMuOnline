#ifndef _VISUAL_FIX_
#define _VISUAL_FIX_

#include "StdAfx.h"

struct PMSG_JOINRESULT
{
	PBMSG_HEAD h;		// C1:F1
	BYTE scode;			// 3
	BYTE result;		// 4
	BYTE NumberH;		// 5
	BYTE NumberL;		// 6
	BYTE CliVersion[5];	// 7
};

struct PMSG_VERSION
{
	PBMSG_HEAD h;		// C1:70
	BYTE scode;			// 3
	BYTE result;		// 4
	BYTE NumberH;		// 5
	BYTE NumberL;		// 6
	BYTE ClientVersion[5];	// 7
};

struct PMSG_VERSION_CHECKED
{
	PBMSG_HEAD h;
	BOOL VersionChecked;
};

struct PMSG_REFILL
{
	PBMSG_HEAD h;		// C1:26
	BYTE IPos;			// 3
	BYTE LifeH;			// 4
	BYTE LifeL;			// 5
	BYTE Flag;			// 6
	BYTE btShieldH;		// 7
	BYTE btShieldL;		// 8
	int Life;
	int Shield;
};

struct PMSG_MANASEND
{
	PBMSG_HEAD h;		// C1:27
	BYTE IPos;			// 3
	BYTE ManaH;			// 4
	BYTE ManaL;			// 5
	BYTE BPH;			// 6
	BYTE BPL;			// 7
	int Mana;
	int BP;
};

struct PMSG_CHARMAPJOINRESULT
{
	PBMSG_HEAD h;		// C3:F3:03
	BYTE subcode;		// 3
	BYTE MapX;			// 4
	BYTE MapY;			// 5
	BYTE MapNumber;		// 6
	BYTE Dir;			// 7

	BYTE ExpHHH;		//
	BYTE ExpHHL;		//
	BYTE ExpHLH;		//
	BYTE ExpHLL;		//
	BYTE ExpLHH;		//
	BYTE ExpLHL;		//
	BYTE ExpLLH;		//
	BYTE ExpLLL;		//

	BYTE NextExpHHH;	//
	BYTE NextExpHHL;	//
	BYTE NextExpHLH;	//
	BYTE NextExpHLL;	//
	BYTE NextExpLHH;	//
	BYTE NextExpLHL;	//
	BYTE NextExpLLH;	//
	BYTE NextExpLLL;	//

	WORD LevelUpPoint;	// 10
	WORD Str;			// 12
	WORD Dex;			// 14
	WORD Vit;			// 16
	WORD Energy;		// 18
	WORD Life;			// 1A
	WORD MaxLife;		// 1C
	WORD Mana;			// 1E
	WORD MaxMana;		// 20
	WORD wShield;		// 22
	WORD wMaxShield;	// 24
	WORD BP;			// 26
	WORD MaxBP;			// 28
	int Money;			// 2C
	BYTE PkLevel;		// 30
	BYTE CtlCode;		// 31
	short AddPoint;		// 32
	short MaxAddPoint;	// 34
	WORD Leadership;	// 36
	WORD wMinusPoint;	// 38
	WORD wMaxMinusPoint;// 3A
	int UpPoint;
};

struct PMSG_LEVELUP
{
	PBMSG_HEAD h;			// C1:F3:05
	BYTE subcode;			// 3
	WORD Level;				// 4
	WORD LevelUpPoint;		// 6
	WORD MaxLife;			// 8
	WORD MaxMana;			// A
	WORD wMaxShield;		// C
	WORD MaxBP;				// E
	short AddPoint;			// 10
	short MaxAddPoint;		// 12
	short MinusPoint;		// 14
	short MaxMinusPoint;	// 16
	int UpPoint;
};

struct PMSG_LVPOINTADDRESULT
{
	PBMSG_HEAD h;			// C1:F3:06
	BYTE subcode;			// 3
	BYTE ResultType;		// 4

	WORD MaxLifeAndMana;	// 6
	WORD wMaxShield;		// 8
	WORD MaxBP;				// A
};

// 1.03K (100%)
#define pUserStat			((LPVOID(*)()) 0x00505FE0)													
#define pUpdateUserStat		((void(__thiscall*)(LPVOID This, int * Value, int Code)) 0x0049404D)

#define pDrawDamage			((void(__cdecl*)(int a1, int a2, int a3, float a4, char a5)) 0x006BA450)
#define pDrawBar			((double(__cdecl*)(float a1, float a2, int a3, float a4)) 0x006FBF97)
#define pDrawTab			((int(__cdecl*)(signed int a1, signed int a2, LPCSTR lpMultiByteStr)) 0x00514E80)
#define pInfo				((int(*)(int a1, const char *a2, ...)) 0x004B69F0)
#define pDrawCircle			((void(__cdecl*)(DWORD ModelID, float Arg2, float Arg3, float Arg4, float Arg5, float Arg6, float Arg7, float Arg8, float Arg9, bool Arg10, bool Arg11, float Arg12)) 0x005F5459)
#define pDamageRate			*(DWORD*)0x5966DCC;

class cVisualFix
{
public:
	cVisualFix();

	short aIndex;
	int AttackHP;
	int AttackSD;
	int Life;
	int SD;
	int Mana;
	int AG;
	int MaxLife;
	int MaxSD;
	int MaxMana;
	int MaxAG;
	int UpPoint;
	int AttackRate;
	int DamageRate;

	bool PlayerKill;

	char LifeTab[50];
	char ManaTab[50];
	char SDTab[50];
	char AGTab[50];

	void Load();

	void RecvIndex(PMSG_JOINRESULT* Data);
	void RecvClientVersion(PMSG_VERSION* Data);
	void RecvDamage(PMSG_ATTACKRESULT* Data);
	void RecvHPSD(PMSG_REFILL* Data);
	void RecvMPAG(PMSG_MANASEND* Data);
	void RecvUpPoint(PMSG_CHARMAPJOINRESULT* Data);
	void RecvUpLevel(PMSG_LEVELUP* Data);
	void RecvDownPoint(PMSG_LVPOINTADDRESULT* Data);
	void RecvRespawn();
	void RecvKilledObject(PMSG_DIEPLAYER* Data);

	static void DrawDamageHP(int a1, int a2, int a3, float a4, char a5);
	static void DrawDamageSD(int a1, int a2, int a3, float a4, char a5);

	static double DrawHp(float a1, float a2, int a3, float a4);
	static double DrawMp(float a1, float a2, int a3, float a4);
	static double DrawAg(float a1, float a2, int a3, float a4);
	static double DrawSd(float a1, float a2, int a3, float a4);

	static int DrawTabHP(signed int a1, signed int a2, LPCSTR lpMultiByteStr);
	static int DrawTabMP(signed int a1, signed int a2, LPCSTR lpMultiByteStr);
	static int DrawTabSD(signed int a1, signed int a2, LPCSTR lpMultiByteStr);
	static int DrawTabAG(signed int a1, signed int a2, LPCSTR lpMultiByteStr);

	static int InfoHp(int a1, const char* a2, ...);
	static int InfoMp(int a1, const char* a2, ...);
	static int InfoPoint(int a1, const char* a2, ...);

	static void DrawCircle(DWORD ModelID, float Arg2, float Arg3, float Arg4, float Arg5, float Arg6, float Arg7, float Arg8, float Arg9, bool Arg10, bool Arg11, float Arg12);

	static void __fastcall CalculateAttackRate(lpCharObj lpUser, LPVOID EDX);
	static void __fastcall CalculateDamageRate(lpCharObj lpUser, LPVOID EDX);
	static void __fastcall CalculateAttackSpeed(lpCharObj lpUser, LPVOID EDX);

	static int GetAttackRate();
	static int GetDamageRate();
};

extern cVisualFix gVisualFix;

#endif