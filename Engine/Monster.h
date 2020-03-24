#ifndef __MONSTER_H__
#define __MONSTER_H__

#define MAX_MONSTER							768//512
#define MONSTER_MODEL						521

#define pModelLoad							((void(__cdecl*)(signed int Arg1,char* Arg2,char* Arg3,signed int Arg4)) 0x005D5DC3)
#define pOpenTexture						((void(__cdecl*)(int Arg1,char* Arg2,int Arg3,signed int Arg4)) 0x005D5710)
#define pViewportObject						((int(__cdecl*)(int ViewportID,int ResourceID,BYTE MapPosX,BYTE MapPosY,float Size)) 0x004FD3A4)
#define pLoadMonsterID						((int(__cdecl*)(signed int MonsterID)) 0x005DD7BC)
#define pShowMonster						((int(__cdecl*)(int MonsterID,BYTE MapPosX,BYTE MapPosY,int ViewportID)) 0x004FF128)
#define pSetMainAttr						((int(__cdecl*)(lpViewMob Object,signed int MonsterID)) 0x004FEDE7)

//#define pShowMonster						((int(__cdecl*)(int MobId,int Arg2,int Arg3,int Arg4)) 0x004FF128)
//#define pVieweObject						((int(__cdecl*)(int Arg1,int Arg2,unsigned __int8 Arg3,unsigned __int8 Arg4,float Arg5))0x4FD3A4)
//#define pLoadMonsterID					((int(__cdecl*)(signed int Arg1))0x5DD7BC)

struct ObjMonster
{
	WORD ID;
	BYTE Type;
	char Name[25];
	char Dir[50];
	char Folder[50];
	char BMDFile[50];
	float Size;
};

int __cdecl OpenMonsterModel(DWORD dwMobNumber);

struct MonsterAdd_Struct {
	DWORD dwMobID;
	char* lpDir;
	char* lpFile;
};

class cMonster
{
public:
	void Load();
	//void Init();
	//static BOOL IsKanturuMobEffects(int nMapNumber);
	//void InitOpenMonsterMod();
	// ----
	static void SetMainAttr();
	//static void LoadModel(signed int ResourceID,char *Path,char *File,signed int Index);
	//static void LoadTexture(signed int ResourceID,char *SubFolder,int Wrap,int Type,bool Check);
	//static int ShowMonster(int MonsterID, BYTE MapPosX, BYTE MapPosY, int ViewportID);
	//static int SetMainAttr(lpViewMob Object, signed int MonsterID);
	static int Viewport(int ViewportID, int ResourceID, BYTE MapPosX, BYTE MapPosY, float Size);
	//static int ShowMonster(int MonsterID, int CoordX, int CoordY, int Arg4);
	static void GlobalMessage(INT ColorID, PCHAR Message);
	//static void OpenMonsterModification();
	//static void OpenMonsterModification1();
	// ----
private:
	NpcNameList	lpNpcName[MAX_MONSTER];
	ObjMonster Data[MAX_MONSTER];
	int	Count;
};

extern cMonster gMonster;

/*
class cMonster
{
public:
	void Load();
	// ----
	//void InitLoadMonsterModel();
	//void InitLoadMonsterTexture();
	void InitShowMonsterModel();
	// ----
	//static void LoadMonsterModel(signed int ResourceID,char *Path,char *File,signed int Index);
	//static void LoadMonsterTexture(signed int ResourceID,char *SubFolder,int Wrap,int Type,bool Check);
	//static void ShowMonsterModel();
	//static int Construct(int MonsterID,int Arg2,int Arg3,int Arg4);

	static void Message_Glob(int ColorId, char* Message); // 1 Azul, 0 dourada
	static int ShowMonster(int MonsterID, int CoordX, int CoordY, int Arg4);
	static int MonsterID(signed int ResourceID);
	static int ViewportObject(int Arg1,int ResourceID,unsigned char CoordX,unsigned char CoordY,float Size);
};

extern cMonster gMonster;
*/

#endif