#include "StdAfx.h"

/*
int					iCount;
DWORD				dwModelResInx;
DWORD				dwModelMobsID;
DWORD				dwModelResSizeof;
DWORD				dwModelResCount;
int					iTempMobID;
DWORD				dwNewMobResInx[MAX_LOAD_MOBS];
MonsterAdd_Struct	s_AddMob[MAX_LOAD_MOBS];
MobParam_Struct		s_ParamMob[MAX_LOAD_MOBS];
*/

//cMobs gMobs;

//cMobs::cMobs()
//{
	//this->InitLoad();
	//this->InitParam();
//}

//cMobs::~cMobs()
//{
	// ----
//}

/*void cMobs::InitLoad()
{
	iCount				= 0;
	dwModelResInx		= 0;
	dwModelMobsID		= 0;
	dwModelResSizeof	= 0;
	dwModelResCount		= 0;
	iTempMobID			= NONE;
	// ----
	memset(dwNewMobResInx,0,sizeof(dwNewMobResInx));
	memset(s_AddMob,0,sizeof(s_AddMob));
}*/

/*
void InitLoad()
{
	iCount				= 0;
	dwModelResInx		= 0;
	dwModelMobsID		= 0;
	dwModelResSizeof	= 0;
	dwModelResCount		= 0;
	iTempMobID			= NONE;
	// ----
	memset(dwNewMobResInx,0,sizeof(dwNewMobResInx));
	memset(s_AddMob,0,sizeof(s_AddMob));
}
*/

/*void cMobs::InitParam()
{
	iCount				= 0;
	// ----
	memset(s_ParamMob,0,sizeof(s_ParamMob));
}*/

/*
void InitParam()
{
	iCount				= 0;
	// ----
	memset(s_ParamMob,0,sizeof(s_ParamMob));
}

void LoadMobs()
{
	if(gScriptEncode.ReadScript(MOBSPARAM_FILE))
	{
		WZSMDToken Token = gScriptEncode.GetToken();
		// ----
		InitParam();
		// ----
		for(int j = 0; j < MAX_MONSTER; j++)
		{
			Token = gScriptEncode.GetToken();
			// ----
			if((Token == END)) break;
			// ----
			s_ParamMob[j].dwMobID = gScriptEncode.GetInt();
			gScriptEncode.GetToken();
			// ----
			memcpy(s_ParamMob[j].lpName,gScriptEncode.GetString(),sizeof(s_ParamMob[j].lpName));
			gScriptEncode.GetToken();
			// ----
			s_ParamMob[j].bMobType		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[j].bPKStatus		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[j].bMoveOut		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[j].fSize			= gScriptEncode.GetFloat();
			// ----
			iCount;
		}
		// ----
		if(iCount > 0)
		{
			// Hook set mob name style, for change mob params
			gToolKit.SetOp((LPVOID)HPROC_SETMOBNAMESTYLE,(LPVOID)SetMonsterNameStyle,ASM::CALL);
		}
		// ----
		gScriptEncode.Close();
	}
	else
	{
		MessageBox(NULL,"MobsParam.bmd file not found","Error",MB_OK);
		::ExitProcess(0);
	}
	// ------------------------------------------------------------------------------------------------------
	if(gScriptEncode.ReadScript(MOBSLOAD_FILE))
	{
		WZSMDToken Token = gScriptEncode.GetToken();
		// ----
		InitLoad();
		// ----
		for(int i = 0;i < MAX_LOAD_MOBS;i++)
		{
			Token = gScriptEncode.GetToken();
			// ----
			if((Token == END)) break;
			// ----
			s_AddMob[i].dwMobID = gScriptEncode.GetInt();
			gScriptEncode.GetToken();
			// ----
			memcpy(s_AddMob[i].lpDir,gScriptEncode.GetString(),sizeof(s_AddMob[i].lpDir));
			gScriptEncode.GetToken();
			// ----
			memcpy(s_AddMob[i].lpFile,gScriptEncode.GetString(),sizeof(s_AddMob[i].lpFile));
			gScriptEncode.GetToken();
			// ----
			s_ParamMob[i].sItem1ResID		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].bItem1IsExcl		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].bItem1JoinID		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].sItem2ResID		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].bItem2IsExcl		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].bItem2JoinID		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			// ----
			iCount++;
		}
		// ----
		if(iCount > 0)
		{
			// Get resource ID
			dwModelResSizeof = *(DWORD*)(OFFST_MODELRES_SIZEOF+1);
			dwModelResCount = *(DWORD*)(OFFST_MODELRES_COUNT+1);
			dwModelMobsID = *(DWORD*)(OFFST_MODELRES_MOBS_ID+2);

			// Hook some proc for calc resource id
			gToolKit.SetOp((LPVOID)HPROC_LOADPLAYERBMD,(LPVOID)LoadModels,ASM::CALL);

			// Set New Monster Model Compare (512)
			//gToolKit.SetByte((PVOID)(0x004FF589+6),0x59);
			//gToolKit.SetByte((PVOID)(0x004FF589+7),0x02);

			// Fix Monster Model Kill Animation
			gToolKit.SetByte((LPVOID)(0x004DE4F0+3),0xFF);
			gToolKit.SetByte((LPVOID)(0x004DE4F0+4),0xFF);

			// Hook zero-bull load
			gToolKit.SetOp((LPVOID)HPROC_OPENMONSTERMODEL_BULL,(LPVOID)OpenMonsterModel,ASM::CALL);
	
			// Change and NOP Bull PUSH 0 to EAX
			gToolKit.SetRange((LPVOID)HARGS_BULL_PUSH,2,ASM::NOP);
			gToolKit.SetByte((PVOID)(HARGS_BULL_PUSH),ASM::EAX);

			// Hook construct zero-bull model
			gToolKit.SetOp((LPVOID)HPROC_CONSTMONSTERMODEL_BULL,(LPVOID)ConstructMonsterModel,ASM::CALL);

			// Fix load resurce id in OpenMonsterModel() HPROC_LOADBMDMODEL
			gToolKit.SetOp((LPVOID)HPROC_LOADBMDMODEL,(LPVOID)FixLoadBMDModel,ASM::CALL);

			// Hook set mob name style, for change mob params
			//gToolKit.SetOp((LPVOID)HPROC_SETMOBNAMESTYLE,(LPVOID)SetMonsterNameStyle,ASM::CALL);
		}
		// ----
		gScriptEncode.Close();
	}
	else
	{
		MessageBox(NULL,"MobsLoad.bmd file not found","Error",MB_OK);
		::ExitProcess(0);
	}
}

/*void cMobs::Load()
{
	if(gScriptEncode.ReadScript(MOBSPARAM_FILE))
	{
		WZSMDToken Token = gScriptEncode.GetToken();
		// ----
		this->InitParam();
		// ----
		for(int j = 0; j < MAX_MONSTER; j++)
		{
			Token = gScriptEncode.GetToken();
			// ----
			if((Token == END)) break;
			// ----
			s_ParamMob[j].dwMobID = gScriptEncode.GetInt();
			gScriptEncode.GetToken();
			// ----
			memcpy(s_ParamMob[j].lpName,gScriptEncode.GetString(),sizeof(s_ParamMob[j].lpName));
			gScriptEncode.GetToken();
			// ----
			s_ParamMob[j].bMobType		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[j].bPKStatus		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[j].bMoveOut		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[j].fSize			= gScriptEncode.GetFloat();
			// ----
			iCount;
		}
		// ----
		if(iCount > 0)
		{
			// Hook set mob name style, for change mob params
			gToolKit.SetOp((LPVOID)HPROC_SETMOBNAMESTYLE,(LPVOID)SetMonsterNameStyle,ASM::CALL);
		}
		// ----
		gScriptEncode.Close();
	}
	else
	{
		MessageBox(NULL,"MobsParam.bmd file not found","Error",MB_OK);
		::ExitProcess(0);
	}
	// ------------------------------------------------------------------------------------------------------
	if(gScriptEncode.ReadScript(MOBSLOAD_FILE))
	{
		WZSMDToken Token = gScriptEncode.GetToken();
		// ----
		this->InitLoad();
		// ----
		for(int i = 0;i < MAX_LOAD_MOBS;i++)
		{
			Token = gScriptEncode.GetToken();
			// ----
			if((Token == END)) break;
			// ----
			s_AddMob[i].dwMobID = gScriptEncode.GetInt();
			gScriptEncode.GetToken();
			// ----
			memcpy(s_AddMob[i].lpDir,gScriptEncode.GetString(),sizeof(s_AddMob[i].lpDir));
			gScriptEncode.GetToken();
			// ----
			memcpy(s_AddMob[i].lpFile,gScriptEncode.GetString(),sizeof(s_AddMob[i].lpFile));
			gScriptEncode.GetToken();
			// ----
			s_ParamMob[i].sItem1ResID		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].bItem1IsExcl		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].bItem1JoinID		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].sItem2ResID		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].bItem2IsExcl		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			s_ParamMob[i].bItem2JoinID		= gScriptEncode.GetInt(); gScriptEncode.GetToken();
			// ----
			iCount++;
		}
		// ----
		if(iCount > 0)
		{
			// Get resource ID
			dwModelResSizeof = *(DWORD*)(OFFST_MODELRES_SIZEOF+1);
			dwModelResCount = *(DWORD*)(OFFST_MODELRES_COUNT+1);
			dwModelMobsID = *(DWORD*)(OFFST_MODELRES_MOBS_ID+2);

			// Hook some proc for calc resource id
			gToolKit.SetOp((LPVOID)HPROC_LOADPLAYERBMD,(LPVOID)LoadModels,ASM::CALL);

			// Set New Monster Model Compare (512)
			//gToolKit.SetByte((PVOID)(0x004FF589+6),0x59);
			//gToolKit.SetByte((PVOID)(0x004FF589+7),0x02);

			// Fix Monster Model Kill Animation
			gToolKit.SetByte((LPVOID)(0x004DE4F0+3),0xFF);
			gToolKit.SetByte((LPVOID)(0x004DE4F0+4),0xFF);

			// Hook zero-bull load
			gToolKit.SetOp((LPVOID)HPROC_OPENMONSTERMODEL_BULL,(LPVOID)OpenMonsterModel,ASM::CALL);
	
			// Change and NOP Bull PUSH 0 to EAX
			gToolKit.SetRange((LPVOID)HARGS_BULL_PUSH,2,ASM::NOP);
			gToolKit.SetByte((PVOID)(HARGS_BULL_PUSH),ASM::EAX);

			// Hook construct zero-bull model
			gToolKit.SetOp((LPVOID)HPROC_CONSTMONSTERMODEL_BULL,(LPVOID)ConstructMonsterModel,ASM::CALL);

			// Fix load resurce id in OpenMonsterModel() HPROC_LOADBMDMODEL
			gToolKit.SetOp((LPVOID)HPROC_LOADBMDMODEL,(LPVOID)FixLoadBMDModel,ASM::CALL);

			// Hook set mob name style, for change mob params
			//gToolKit.SetOp((LPVOID)HPROC_SETMOBNAMESTYLE,(LPVOID)SetMonsterNameStyle,ASM::CALL);
		}
		// ----
		gScriptEncode.Close();
	}
	else
	{
		MessageBox(NULL,"MobsLoad.bmd file not found","Error",MB_OK);
		::ExitProcess(0);
	}
}

void __cdecl LoadModels(DWORD dwResInx,LPSTR lpDir,LPSTR lpBaseName,DWORD Arg4)
{
	DWORD dwDiff,dwSize;
	// ----
	dwSize					= dwModelResSizeof * dwModelResCount;
	dwDiff					= *lpModelResArray - *lpModelResBase;
	dwModelResInx			= (dwSize - dwDiff) / dwModelResSizeof;
	// ----
	for(int i = 0;i < iCount;i++)
	{
		dwNewMobResInx[i]			= dwModelResInx - i - 1;
		s_AddMob[i].dwMobID			-= 1;
	}
	// ----
	pLoadBMDModel(dwResInx,lpDir,lpBaseName,Arg4);
}

void __cdecl OpenMonsterModel(DWORD dwMobNumber)
{
	if(dwMobNumber != NONE)
	{
		for(int i = 0; i < iCount; i++)
		{
			if(dwMobNumber == s_AddMob[i].dwMobID)
			{
				dwMobNumber = dwNewMobResInx[i] - dwModelMobsID;
				iTempMobID = i;
				break;
			}
		}
	}
	else
	{
		dwMobNumber = 0;
	}
	// ----
	pOpenMonsterModel(dwMobNumber);
}

void __cdecl FixLoadBMDModel(DWORD dwResInx,LPSTR lpDir,LPSTR lpBaseName,DWORD Arg4)
{
	if(iTempMobID != NONE)
	{
		lpDir		= s_AddMob[iTempMobID].lpDir;
		lpBaseName	= s_AddMob[iTempMobID].lpFile;
		Arg4		= NONE;
	}
	// ----
	pLoadBMDModel(dwResInx,lpDir,lpBaseName,Arg4);
}

DWORD __cdecl ConstructMonsterModel(DWORD Arg1,DWORD dwResInx,DWORD dwResOffst,DWORD Arg4,DWORD Arg5)
{
	if(iTempMobID != NONE)
	{
		dwResInx = dwNewMobResInx[iTempMobID];
		iTempMobID = NONE;
	}
	// ----
	return pConstructMonsterModel(Arg1,dwResInx,dwResOffst,Arg4,Arg5);
}

void __cdecl SetMonsterNameStyle(DWORD dwMemAddr,DWORD dwMobID,DWORD Arg3,DWORD Arg4)
{
	pSetMonsterNameStyle(dwMemAddr,dwMobID,Arg3,Arg4);
	ModifMonsParams(dwMemAddr,dwMobID);
}

void ModifMonsParams(DWORD lpUnit,DWORD dwMobID)
{
	for(int i = 0; i< iCount; i++)
	{
		if(s_ParamMob[i].dwMobID == dwMobID)
		{
			lpMonsterStruct pUnit = &*(MonsterStruct*)lpUnit;
			// ----
			if(s_ParamMob[i].lpName != NULL)
			{
				memcpy(pUnit->cName,s_ParamMob[i].lpName,sizeof(pUnit->cName));
			}

			if(s_ParamMob[i].bMoveOut != NONE)
			{
				pUnit->bMoveOut = s_ParamMob[i].bMoveOut;
			}

			if(s_ParamMob[i].bMobType != NONE)
			{
				pUnit->bMobType = s_ParamMob[i].bMobType;
			}

			if(s_ParamMob[i].fSize != NULL)
			{
				pUnit->fSize = s_ParamMob[i].fSize;
			}

			if(s_ParamMob[i].bPKStatus != NONE)
			{
				pUnit->bPKStatus = s_ParamMob[i].bPKStatus;
			}

			//Hand first
			if(s_ParamMob[i].sItem1ResID != NONE)
			{
				pUnit->sItem1ResID = s_ParamMob[i].sItem1ResID;
			}

			if(s_ParamMob[i].bItem1IsExcl != NONE)
			{
				pUnit->bItem1IsExc = s_ParamMob[i].bItem1IsExcl;
			}

			if(s_ParamMob[i].bItem1JoinID != NONE)
			{
				pUnit->bItem1JoinID = s_ParamMob[i].bItem1JoinID;
			}

			//Hand second
			if(s_ParamMob[i].sItem2ResID != NONE)
			{
				pUnit->sItem2ResID = s_ParamMob[i].sItem2ResID;
			}

			if(s_ParamMob[i].bItem2IsExcl != NONE)
			{
				pUnit->bItem2IsExc = s_ParamMob[i].bItem2IsExcl;
			}

			if(s_ParamMob[i].bItem2JoinID != NONE)
			{
				pUnit->bItem2JoinID = s_ParamMob[i].bItem2JoinID;
			}
		}
	}
}
*/