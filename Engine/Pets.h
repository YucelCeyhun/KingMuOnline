#ifndef __PETS_H__
#define __PETS_H__

#define FENRIR_BLACK	1
#define FENRIR_BLUE		2
#define FENRIR_RED		0
#define FENRIR_GOLD		4
#define FENRIR_ORANGE	63

//typedef LPVOID(__cdecl *ObjPetGetThis)(void);
//extern ObjPetGetThis gObjPetGetThis;

typedef void(__thiscall *ObjCreatePet)(LPVOID This, int Arg1, int Arg2, int Arg3, int Arg4, int Arg5, int Arg6);
extern ObjCreatePet gObjCreatePet;

typedef int(__cdecl *ObjCreateBug)(int BugId, int Arg2, int Arg3, int Arg4, int Arg5);
extern ObjCreateBug gObjCreateBug;

typedef void(__cdecl *Objsub_4997AD)(int Arg1);
extern Objsub_4997AD gObjsub_4997AD;

typedef void(__cdecl *Objsub_4DD069)(int Arg1, int Arg2, int Arg3);
extern Objsub_4DD069 gObjsub_4DD069;

typedef int(__cdecl *Objsub_4FD6C5)(int a1);
extern Objsub_4FD6C5 gObjsub_4FD6C5;

// -------------------------------------------------------------------------------------

typedef char(__cdecl *Objsub_5AB975)(float Arg1, float Arg2, float Arg3);
extern Objsub_5AB975 gObjsub_5AB975;

typedef bool(__thiscall *Objsub_604FCD)(LPVOID This, char Arg2);
extern Objsub_604FCD gObjsub_604FCD;

#define pObjItemName(x)					*(DWORD*)(x + 48)
#define pObjModelScale(x)				*(DWORD*)(x + 96)
#define pObjPositionX(x)				*(int*)(x + 252)
#define pObjPositionY(x)				*(int*)(x + 256)
#define pObjPositionZ(x)				*(int*)(x + 260)
#define pObjGetAngle(x)					*(int*)(x + 264)
#define pMaxObjectCount					((bool(__thiscall*)(LPVOID This,char CharSetSize))0x604FCD)

typedef void(__cdecl *Objsub_5B81A9)(int Arg1, char Arg2, int Arg3, int Arg4);
extern Objsub_5B81A9 gObjsub_5B81A9;

typedef int(*Objsub_85151D)();
extern Objsub_85151D gObjsub_85151D;

typedef int(__cdecl *CreateSpriteEx)(int Arg1, int Arg2, int Arg3, int Arg4, int Arg5, int Arg6, int Arg7);
extern CreateSpriteEx pCreateSpriteEx;

typedef int(__cdecl *CreateParticleEx)(int Arg1, int Arg2, int Arg3, int Arg4, int Arg5, float Arg6, int Arg7);
extern CreateParticleEx pCreateParticleEx;

typedef int(__cdecl *Objsub_4C91E7)(int Arg1, signed int Arg2, char Arg3);
extern Objsub_4C91E7 gObjsub_4C91E7;

typedef bool(__cdecl *Objsub_490280)(signed int a1);
extern Objsub_490280 gObjsub_490280;

typedef double(__cdecl *Objsub_5A84C3)(float Arg1, float Arg2);
extern Objsub_5A84C3 gObjsub_5A84C3;

class cPets
{
public:
	void Load();
	void Init();
	// ----
	static void CreatePetInventorySizeEx();
	static void CreatePetInvenModelPosEx();
	static void CreatePetInvenNewNameExc();
	static void CreatePetFunctionUnknown();//FenrirProp1
	static void CreatePetAllowedWalkOnMap();//FenrirProp5
	static void CreatePetSetPlayerActions();
	static void CreatePetMovementOnWalk();//???
	static void FunctionUnknown1();//?
	static void FunctionUnknown2();//?
	static void CreatePetFollowChar();
	static void FollowCharacter();
	static void CreatePetTypeFenrir();
	// ----
	void InitCreateCodeMountEx();
	void InitCreateFenrirThis1();
	void InitCreateFenrirThis2();
	void InitCreateFenrirThis3();
	void InitCreateFenrirThis4();
	void InitCreateFenrirThis5();
	void InitCreateFenrirThis6();
	void InitCreateFenrirThis7();
	void InitCreateFenrirThis8();
	void InitCreateFenrirThis9();
	void InitCreateFenrirThis10();
	void InitCreateFenrirThis11();
	void InitCreateFenrirThis12();
	void InitCreateFenrirThis13();
	void InitCreateFenrirThis14();
	// ----
	void InitDemonShowLife();
	void InitDrawHPBarOnScreen();
	void InitDrawObjectOnViewport();
	void InitDrawAngelMovement();
	// ----
	static void DemonShowLife();
	static void LoadObjSkillModel();
	static bool ChaosCastleMapRange(int Map);
	static void CreatePetObjectEx(int ItemId);
	//static void CreatePetObjectEx2(lpItemObj lpObj);
	static bool ResetPetPreviewEx(int ItemId);
	static char CreatePetEffectEx(int Arg1,char Arg2);
	static int CreatePetMountEx(int Arg1,int Arg2);
	static void CreateCodeMountEx();
	static void CreateFenrirThis1();
	static void CreateFenrirThis2();
	static void CreateFenrirThis3();//Atlans ?
	static void CreateFenrirThis4();//Fenrir MUEVE LOS PIES! :D
	static void CreateFenrirThis5();//Fenrir HACE RUIDO AL CAMINAR :D
	static void CreateFenrirThis6();//
	static void CreateFenrirThis7();//
	static void CreateFenrirThis8();//
	static void CreateFenrirThis9();
	static void CreateFenrirThis10();
	static void CreateFenrirThis11();//
	static void CreateFenrirThis12();//
	static void CreateFenrirThis13();//
	static void CreateFenrirThis14();//
	static void DrawHPBarOnScreen();
	static char CreatePetStatics(int Arg1,int Arg2,int Arg3,int Arg4,int Arg5);
	static int DrawObjectOnViewport(lpObjViewport lpObjView);
	// ----
	static void DrawAngelMovement();
	static void RedrawObjViewport();
	void InitRedrawObjViewport();
	// ----
	static void RudolfSearchZen();
	void InitRudolfSearchZen();
	// ----
	static void DrawPetSkillEffect();
	void InitDrawPetSkillEffect();
	// ----
	static int GetFenrirSkillColor(int Arg1);
	void InitGetFenrirSkillColor();
	// ----
	struct sTYPE
	{
		int Type;
		int Index;
	};
	// ----
	struct sVALUE
	{
		float RotX;
		float RotY;
		float RotZ;
		float Size;
	};
	// ----
	int gItemFloor;
	// ----
	sTYPE	eTYPE[512];
	sVALUE	eVALUE[30000];
};

extern cPets gPets;

#endif