#ifndef __MOBS_H__
#define __MOBS_H__

#define MONSTER_MODEL						521
//#define MAX_MONSTER							1024
#define MAX_LOAD_MOBS						32

#define NONE								-1
#define MONSTER_DIR							"Data\\Monster\\"

#define OFFST_MODELRES_SIZEOF				0x005D5F44 //1.03K
#define OFFST_MODELRES_COUNT				0x005D5F3F //1.03K
#define OFFST_MODELRES_MOBS_ID				0x005DD7C5 //1.03K

#define HPROC_OPENMONSTERMODEL_BULL			0x00501696 //1.03K
#define HARGS_BULL_PUSH						0x00501694 //1.03K
#define HPROC_CONSTMONSTERMODEL_BULL		0x005016B1 //1.03K
#define HPROC_LOADBMDMODEL					0x005DD811 //1.03K
#define HPROC_LOADPLAYERBMD					0x005D5FCA //1.03K
#define HPROC_SETMOBNAMESTYLE				0x00503ED6 //1.03K

#define pOpenMonsterModel					((DWORD(__cdecl*)(DWORD dwMobNumber))0x005DD7BC)
#define pConstructMonsterModel				((DWORD(__cdecl*)(DWORD Arg1,DWORD dwResInx,DWORD dwResOffst,DWORD Arg4,DWORD Arg5))0x004FD3A4)
#define pLoadBMDModel						((DWORD(__cdecl*)(DWORD Arg1,LPSTR Arg2,LPSTR Arg3,DWORD Arg4))0x005D5DC3)
#define pSetMonsterNameStyle				((DWORD(__cdecl*)(DWORD dwMemAddr,DWORD dwMobID,DWORD Arg3,DWORD Arg4))0x004FEDE7)

static DWORD *lpModelResBase				= (DWORD*)0x6AC7AA8;
static DWORD *lpModelResArray				= (DWORD*)0x596CB28;

//struct Unit_Struct
//{
//	BYTE Unknown1[32];
//	/*+32*/		BYTE	bPKStatus;
//	BYTE Unknown2[23];
//	/*+56*/		char	cName[32];
//	/*+89*/		BYTE	bMoveOut;
//	BYTE Unknown5[302];
//	/*+392*/	signed short sItem1ResID;
//	/*+394*/	signed char bItem1IsLevel;
//	/*+395*/	signed char bItem1IsExc;
//	/*+396*/	signed char bItem1IsAnc;
//	/*+397*/	signed char bItem1JoinID;
//	BYTE Unknown9[26];
//	/*+424*/	signed short sItem2ResID;
//	/*+426*/	signed char bItem2IsLevel;
//	/*+427*/	signed char bItem2IsExc;
//	/*+428*/	signed char bItem2IsAnc;
//	/*+429*/	signed char bItem2JoinID;
//	BYTE Unknown12[292];
//	/*+722*/	BYTE bMobType;
//	BYTE Unknown13[73];
//	/*+796*/	float fSize;
//};

/*
struct Unit_Struct
{
	BYTE Unknown1[32];
	BYTE bPKStatus;
	BYTE Unknown2[23];
	char cName[32];
	BYTE bMoveOut;
	BYTE Unknown5[303];
	signed short sItem1ResID;
	BYTE Unknown7;
	signed char bItem1IsExc;
	BYTE Unknown8;
	signed char bItem1JoinID;//6
	BYTE Unknown9[26];//26
	signed short sItem2ResID;
	BYTE Unknown10;
	signed char bItem2IsExc;
	BYTE Unknown11;
	signed char bItem2JoinID;//6
	BYTE Unknown12[292];
	BYTE bMobType;
	BYTE Unknown13[73];
	float fSize;
};
*/

#pragma pack(push,1)
typedef struct
{
	BYTE Shift1[32];
	/*+32*/		BYTE bPKStatus;
	BYTE Shift2[23];
	/*+56*/		char cName[32];
	/*+88*/		BYTE bMoveOut;
	BYTE Shift3[634];
	/*+722*/	BYTE bMobType;
	BYTE Shift4[73];
	/*+796*/	float fSize;
} MonsterStruct, *lpMonsterStruct;
#pragma pack(pop)

struct MobParam_Struct
{
	DWORD dwMobID;
	LPSTR lpName;
	signed char bMobType;
	signed char bPKStatus;
	signed char bMoveOut;
	//signed short sItem1ResID;
	//signed char bItem1IsExcl;
	//signed char bItem1JoinID;
	//signed short sItem2ResID;
	//signed char bItem2IsExcl;
	//signed char bItem2JoinID;
	float fSize;
};

/*struct MonsterAdd_Struct
{
	DWORD dwMobID;
	CHAR  lpDir[32];
	CHAR  lpFile[32];
};*/

/*
void	OpenMonsterModel(DWORD dwMobNumber);
DWORD	ConstructMonsterModel(DWORD Arg1,DWORD dwResInx,DWORD dwResOffst,DWORD Arg4,DWORD Arg5);
void	FixLoadBMDModel(DWORD dwResInx,LPSTR lpDir,LPSTR lpBaseName,DWORD Arg4);
void	LoadModels(DWORD dwResInx,LPSTR lpDir,LPSTR lpBaseName,DWORD Arg4);
void	SetMonsterNameStyle(DWORD dwMemAddr,DWORD dwMobID,DWORD Arg3,DWORD Arg4);
void	ModifMonsParams(DWORD lpUnit,DWORD dwMobID);

void	LoadMobs();
*/

/*
class cMobs
{
public:
	cMobs();
	virtual ~cMobs();
	// ----
	void				InitLoad();
	void				InitParam();
	void				Load();
	// ----
	void				OpenMonsterModel(DWORD dwMobNumber);
	DWORD				ConstructMonsterModel(DWORD Arg1,DWORD dwResInx,DWORD dwResOffst,DWORD Arg4,DWORD Arg5);
	void				FixLoadBMDModel(DWORD dwResInx,LPSTR lpDir,LPSTR lpBaseName,DWORD Arg4);
	void				LoadModels(DWORD dwResInx,LPSTR lpDir,LPSTR lpBaseName,DWORD Arg4);
	void				SetMonsterNameStyle(DWORD dwMemAddr,DWORD dwMobID,DWORD Arg3,DWORD Arg4);
	void				ModifMonsParams(DWORD lpUnit,DWORD dwMobID);
	// ----
	int					iCount;
	DWORD				dwModelResInx;
	DWORD				dwModelMobsID;
	DWORD				dwModelResSizeof;
	DWORD				dwModelResCount;
	int					iTempMobID;
	DWORD				dwNewMobResInx[MAX_LOAD_MOBS];
	MonsterAdd_Struct	s_AddMob[MAX_LOAD_MOBS];
	MobParam_Struct		s_ParamMob[MAX_LOAD_MOBS];
};

extern cMobs gMobs;
*/

#endif //__MOBS_H__