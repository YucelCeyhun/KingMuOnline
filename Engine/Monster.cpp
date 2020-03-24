#include "StdAfx.h"

int IsMob = GetPrivateProfileInt("Engine", "UseCustomMonster", 0, ENGINE_INI);

cMonster gMonster;

/*
void cMonster::Load()
{
	if(IsMob == 1)
	{
		if(gScriptEncode.ReadScript(MONSTER_FILE))
		{
			ZeroMemory(this->lpNpcName,sizeof(this->lpNpcName));
			ZeroMemory(this->Data,sizeof(Data));
			// ----
			int Token;
			Token = gScriptEncode.GetToken();
			// ----
			this->Count = 0;
			// ----
			while(TRUE)
			{
				Token = gScriptEncode.GetToken();
				// ----
				if ((Token == END)) break;
				// ----
				if(this->Count >= MAX_MONSTER)
				{
					MessageBox(NULL,"MAX Monsters Memory Overflow!","Error",MB_OK);
					break;
				}
				// ----
				this->Data[this->Count].ID = gScriptEncode.TokenNumber;
				// ----
				gScriptEncode.GetToken();
				this->Data[this->Count].Type = gScriptEncode.TokenNumber;
				// ----
				gScriptEncode.GetToken();
				memcpy(this->Data[this->Count].Name,gScriptEncode.TokenString,sizeof(this->Data[this->Count].Name));
				// ----
				gScriptEncode.GetToken();
				memcpy(this->Data[this->Count].Dir,gScriptEncode.TokenString,sizeof(this->Data[this->Count].Dir));
				// ----
				gScriptEncode.GetToken();
				memcpy(this->Data[this->Count].Folder,gScriptEncode.TokenString,sizeof(this->Data[this->Count].Folder));
				// ----
				gScriptEncode.GetToken();
				memcpy(this->Data[this->Count].BMDFile,gScriptEncode.TokenString,sizeof(this->Data[this->Count].BMDFile));
				// ----
				gScriptEncode.GetToken();
				this->Data[this->Count].Size = gScriptEncode.TokenNumber;
				// ----
				this->Count++;
			}
			// -> Fix Monster Kill Animation
			gToolKit.SetByte((PVOID)(0x004DE4F0+3),0xFF);
			gToolKit.SetByte((PVOID)(0x004DE4F0+4),0xFF);
			// -> Fix Monster Attr Limiter
			//gToolKit.SetByte((PVOID)(0x006393F4+1),0x00);
			//gToolKit.SetByte((PVOID)(0x006393F4+2),0x04);
			// ----
			//gToolKit.SetOp((LPVOID)0x005DD811,(LPVOID)this->ModelLoad,ASM::CALL);
			//gToolKit.SetOp((LPVOID)0x005DD8C0,(LPVOID)this->TextureOpen,ASM::CALL);
			// ----
			gToolKit.SetOp((LPVOID)0x0048C6C6,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x005045F9,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x0050F1C0,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x00581BF1,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x0061860F,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x00618EE5,(LPVOID)this->ShowMonster,ASM::CALL); //THIS USING SIMILAR METHOD FROM YOU I MEAN.. FUNCTION C++ STYLE I HAVE ANOTHER CRASH HERE:
			gToolKit.SetOp((LPVOID)0x006192F0,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x0063D1F0,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x008037E9,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x00803803,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x0080381D,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x00803837,(LPVOID)this->ShowMonster,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x00803851,(LPVOID)this->ShowMonster,ASM::CALL);
			// ----
			gToolKit.SetOp((LPVOID)0x004FF182,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF1C3,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF204,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF245,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF286,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF2C7,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF308,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF349,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF38A,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF3CB,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF410,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF455,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF496,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF4D7,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF51C,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004FF561,(LPVOID)this->SetMainAttr,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x00503ED6,(LPVOID)this->SetMainAttr,ASM::CALL);
		}
		else
		{
			MessageBox(NULL,"MonsterLoad.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
}
*/

void cMonster::GlobalMessage(INT ColorID, PCHAR Message)
{
	static DWORD dwPrintGlobal = 0x00515180;
	// ----
	_asm
	{
		PUSH ColorID
		PUSH Message
		CALL dwPrintGlobal
		ADD ESP, 0x8
	}
}

enum eNewMobs
{
	BULL_MONSTER = 0,
	BOLO_MERCHANT = 600,
	KUNDUN_MECHNANT = 275,
};

enum eGlobalColorID
{
	GLOBAL_GOLD = 0,
	GLOBAL_GREEN = 1,
};

/*int cMonster::ShowMonster(int MonsterID, int CoordX, int CoordY, int Arg4)
{
	char Message[256];
	sprintf_s(Message, "%d %d %d %d", MonsterID, CoordX, CoordY, Arg4);
	gMonster.GlobalMessage(GLOBAL_GOLD, Message);
	// ----
	if (MonsterID == BOLO_MERCHANT)
	{
		gMonster.GlobalMessage(GLOBAL_GREEN, "Bolo O_O");
		gMonster.GlobalMessage(GLOBAL_GREEN, "Cooooool");
	}
	// ----
	return pShowMonster(MonsterID, CoordX, CoordY, Arg4);
}*/

/*int cMonster::SetMainAttr(lpViewMob Object, signed int MonsterID)
{
	if (MonsterID == BOLO_MERCHANT)
	{
		Object->ObjectType = 4;
	}
	// ----
	return pSetMainAttr(Object, MonsterID);
}*/

#define BULL_MODEL_ARRAY 0x209
#define BOLO_MODEL_ARRAY 0x461

/*
void cMonster::LoadModel(signed int ResourceID,char *Path,char *File,signed int Index)
{
	int MonsterID = ResourceID - MONSTER_MODEL;
	// ----
	for(int i = 0; i < MAX_MONSTER; i++)
	{
		if(MonsterID == BOLO_MERCHANT)
		{
			pLoadModel(ResourceID,"Data\\Monster\\","Monster600",-1);
			return;
		}
	}
	// ----
	pLoadModel(ResourceID,Path,File,Index);
}

void cMonster::LoadTexture(signed int ResourceID,char *SubFolder,int Wrap,int Type,bool Check)
{
	int MonsterID = ResourceID - MONSTER_MODEL;
	// ----
	for(int i = 0; i < MAX_MONSTER; i++)
	{
		if(MonsterID == BOLO_MERCHANT)
		{
			pLoadTexture(ResourceID,"Monster\\",GL_REPEAT,GL_NEAREST,GL_TRUE);
			return;
		}
	}
	// ----
	pLoadTexture(ResourceID,SubFolder,Wrap,Type,Check);
}
*/

#define pCreateObjectView	((int(__cdecl*)(int ViewportID,int ResourceID,BYTE MapPosX,BYTE MapPosY,float Size))0x004FC216)
#define pViewportThis		((void(__thiscall*)(LPVOID This))0x006054D7)

#define sub_487FE6			((int(__cdecl*)(int Arg1))0x00487FE6)
#define sub_4A33B8			((int(__cdecl*)(int Arg1))0x004A33B8)

#define sub_4997AD			((void(__cdecl*)(int Arg1))0x004997AD)
#define sub_4DD069			((void(__cdecl*)(int Arg1,int Arg2,int Arg3))0x004DD069)

int cMonster::Viewport(int ViewportID, int ResourceID, BYTE MapPosX, BYTE MapPosY, float Size)
{
	/*
	char Message1[256];
	sprintf_s(Message1,"[BULL VIEW PROC]: %d %d %d %d %.2f",ViewportID,ResourceID,MapPosX,MapPosY,Size);
	gMonster.GlobalMessage(GLOBAL_GOLD,Message1);
	// ----
	return pViewportObject(ViewportID,ResourceID,MapPosX,MapPosY,Size);
	*/

	DWORD dwPreview = *(DWORD*)0x7A7239C;

	int WorldPosition; //v8
	int ObjectPreview; //v9

	for (signed int i = 0; i < 400; i++)
	{
		ObjectPreview = 1236 * i + dwPreview;
		WorldPosition = ObjectPreview + 700;
		// ----
		if (*(BYTE*)(ObjectPreview + 704) && *(WORD*)(ObjectPreview + 94) == ViewportID)
		{
			pCreateObjectView(ObjectPreview, ResourceID, MapPosX, MapPosY, Size);
			pViewportThis((void*)(WorldPosition + 484));
			return ObjectPreview;
		}
	}
	for (signed int j = 0; j < 400; j++)
	{
		ObjectPreview = 1236 * j + dwPreview;
		WorldPosition = ObjectPreview + 700;
		// ----
		if (!*(BYTE*)(ObjectPreview + 704))	// -> No Monster
		{
			sub_487FE6(ObjectPreview);
			sub_4A33B8(ObjectPreview);
			sub_4DD069(ObjectPreview, WorldPosition, 0);
			sub_4997AD(ObjectPreview);
			pCreateObjectView(ObjectPreview, ResourceID, MapPosX, MapPosY, Size);
			pViewportThis((void*)(WorldPosition + 484));
			*(WORD*)(ObjectPreview + 94) = ViewportID;
			return ObjectPreview;
		}
	}
	return dwPreview + 0x0078B40;
}

//int cMonster::ShowMonster(int MonsterID, BYTE MapPosX, BYTE MapPosY, int ViewportID)
//{
	/*
	char Message2[256];
	sprintf_s(Message2,"[BULL SHOW PROC]: %d %d %d %d",MonsterID,MapPosX,MapPosY,ViewportID);
	gMonster.GlobalMessage(GLOBAL_GOLD,Message2);
	*/
	// ----
//	return pShowMonster(MonsterID, MapPosX, MapPosY, ViewportID);
//}

static BOOL bSetMainAttr_Switcher;

void Naked cMonster::SetMainAttr()
{
	static DWORD dwSetMainAttr_Pointer;
	static DWORD dwSetMainAttr_Buffer;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP + 0x0C]
		MOV dwSetMainAttr_Pointer, EDX
	}
	// ----
	if (dwSetMainAttr_Pointer == 0x1DF)			// -> (479) Gate Keeper Titus
	{
		_asm
		{
			MOV dwSetMainAttr_Buffer, oSetMainAttr_Allowed
			JMP dwSetMainAttr_Buffer
		}
	}
	else if (dwSetMainAttr_Pointer == 0x258)		// -> (600) Bolo The Merchant
	{
		_asm
		{
			MOV dwSetMainAttr_Buffer, oSetMainAttr_Allowed
			JMP dwSetMainAttr_Buffer
		}
	}
	/*else if (dwSetMainAttr_Pointer == 0x113)		// -> (275) Kundun The Merchant
	{
		_asm
		{
			MOV dwSetMainAttr_Buffer, oSetMainAttr_Allowed
			JMP dwSetMainAttr_Buffer
		}
	}*/
	_asm
	{
		MOV dwSetMainAttr_Buffer, oSetMainAttr_Return
		JMP dwSetMainAttr_Buffer
	}
}


//gToolKit.SetOp((LPVOID)0x00618EE5,this->ShowMonster,ASM::CALL);

/*void Naked cMonster::SetEventKanturuMap()
{
	static DWORD dwSetEventKanturuMap_Pointer;
	static DWORD dwSetEventKanturuMap_Buffer;
	// ----
	_asm
	{
		MOV EAX,DWORD PTR DS:[0x008C5CF8]
		MOV dwSetEventKanturuMap_Pointer,EAX
	}
	// ----
	if(dwSetEventKanturuMap_Pointer == Kanturu_Event || dwSetEventKanturuMap_Pointer == Lorencia)
	{
		_asm
		{
			MOV dwSetEventKanturuMap_Buffer,0x007CCAFA
			JMP dwSetEventKanturuMap_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwSetEventKanturuMap_Buffer,0x007CCAFD
			JMP dwSetEventKanturuMap_Buffer
		}
	}
	// ----
	_asm
	{
		MOV dwSetEventKanturuMap_Buffer,0x007CCAFD
		JMP dwSetEventKanturuMap_Buffer
	}
}

void cMonster::InitSetEventKanturuMap()
{
	gToolKit.SetRange((LPVOID)0x007CCAF3,7,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x007CCAF3,this->SetEventKanturuMap);
}*/

/*BOOL cMonster::IsKanturuMobEffects(int nMapNumber)
{
	nMapNumber = pMapNumber;
	// ----
	switch(nMapNumber)
	{
		case Kanturu_Event:
			return TRUE;
		break;
		case Lorencia:
			return TRUE;
		break;
		default:
			return FALSE;
		break;
	}
}*/

/*
DWORD dwModelResInx,dwModelMobsID,dwModelResSizeof,dwModelResCount;
int iTempMobID = NONE;

#define ADD_MOBS_COUNT 1
MonsterAdd_Struct s_AddMob[ADD_MOBS_COUNT] =
{
	{ 600,MONSTER_DIR,"volvo" },
	//{ 601,MONSTER_DIR,"Elementalist" },
	//{ 602,MONSTER_DIR,"adniel" },
	//{ 610,MONSTER_DIR,"Anubis" },
};
DWORD dwNewMobResInx[ADD_MOBS_COUNT];

void __cdecl LoadPlayerBMD(DWORD dwResInx, LPSTR lpDir, LPSTR lpBaseName, DWORD Arg4)
{
	DWORD dwDiff, dwSize;
	// ----
	dwSize = dwModelResSizeof * dwModelResCount;
	dwDiff = *lpModelResArray - *lpModelResBase;
	dwModelResInx = (dwSize - dwDiff) / dwModelResSizeof;
	// ----
	for (int i = 0; i<ADD_MOBS_COUNT; i++)
	{
		dwNewMobResInx[i] = dwModelResInx - i - 1;
		s_AddMob[i].dwMobID -= 1;
	}
	// ----
	pLoadBMDModel(dwResInx, lpDir, lpBaseName, Arg4);
}

int __cdecl OpenMonsterModel(DWORD dwMobNumber)
{
	if(dwMobNumber != NONE)
	{
		for(int i=0;i<ADD_MOBS_COUNT;i++)
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
		dwMobNumber=0;
	// ----
	return pOpenMonsterModel(dwMobNumber);
}

void __cdecl FixLoadBMDModel(DWORD dwResInx, LPSTR lpDir, LPSTR lpBaseName, DWORD Arg4)
{
	if (iTempMobID != NONE)
	{
		lpDir = s_AddMob[iTempMobID].lpDir;
		lpBaseName = s_AddMob[iTempMobID].lpFile;
		Arg4 = -1;
	}
	// ----
	pLoadBMDModel(dwResInx, lpDir, lpBaseName, Arg4);
}

DWORD __cdecl ConstructMonsterModel(DWORD Arg1, DWORD dwResInx, DWORD dwResOffst, DWORD Arg4, DWORD Arg5)
{
	if (iTempMobID != NONE)
	{
		dwResInx = dwNewMobResInx[iTempMobID];
		iTempMobID = NONE;
	}
	// ----
	return pConstructMonsterModel(Arg1, dwResInx, dwResOffst, Arg4, Arg5);
}
*/

void cMonster::Load()
{
	//this->Init();
	// ----
	// Get Resource ID
	//dwModelResSizeof = *(DWORD*)(OFFST_MODELRES_SIZEOF+1);
	//dwModelResCount = *(DWORD*)(OFFST_MODELRES_COUNT+1);
	//dwModelMobsID = *(DWORD*)(OFFST_MODELRES_MOBS_ID+2);
	// ----
	gToolKit.SetByte((PVOID)(0x004DE4F0 + 3), 0xFF);
	gToolKit.SetByte((PVOID)(0x004DE4F0 + 4), 0xFF);
	// ----
	//gToolKit.SetOp((LPVOID)HPROC_LOADPLAYERBMD,LoadPlayerBMD,ASM::CALL);
	//gToolKit.SetOp((LPVOID)HPROC_OPENMONSTERMODEL_BULL,OpenMonsterModel,ASM::CALL);
	//gToolKit.SetRange((LPVOID)HARGS_BULL_PUSH,2,ASM::NOP);
	//gToolKit.SetByte((PVOID)(HARGS_BULL_PUSH),ASM::EAX);
	//gToolKit.SetOp((LPVOID)HPROC_CONSTMONSTERMODEL_BULL,ConstructMonsterModel,ASM::CALL);
	//gToolKit.SetOp((LPVOID)HPROC_LOADBMDMODEL,FixLoadBMDModel,ASM::CALL);
	// ----
	//gToolKit.SetRange((LPVOID)0x00501694,2,ASM::NOP);
	//gToolKit.SetByte((PVOID)(0x00501694),ASM::EAX);
	// ----
	//gToolKit.SetOp((LPVOID)0x005DD811,this->LoadModel,ASM::CALL);
	//gToolKit.SetOp((LPVOID)0x005DD8C0,this->LoadTexture,ASM::CALL);
	// ----
	//gToolKit.SetOp((LPVOID)0x7CEF85,this->IsKanturuMobEffects,ASM::CALL);
	//gToolKit.SetOp((LPVOID)0x7D3354,this->IsKanturuMobEffects,ASM::CALL);
	// ----
	//gToolKit.SetOp((LPVOID)0x005016B1,this->Viewport,ASM::CALL);//Y
	//gToolKit.SetOp((LPVOID)0x00618EE5, this->ShowMonster, ASM::CALL);//X
	//gToolKit.SetOp((LPVOID)0x00501696, this->ShowMonster, ASM::CALL);
	// ----
	gToolKit.SetOp((LPVOID)oSetMainAttr_Hook, this->SetMainAttr, ASM::JMP);
}

/*void cMonster::LoadMonsterModel(signed int ResourceID,char *Path,char *File,signed int Index)
{
	int MonsterID = ResourceID - MONSTER_MODEL;
	// ----
	for(int i = 0; i < MAX_MONSTER; i++)
	{
		if(MonsterID ==
		_MERCHANT)
		{
			pLoadModel(ResourceID,"Data\\Monster\\","Monster600",-1);
			return;
		}
	}
	// ----
	pLoadModel(ResourceID,Path,File,Index);
}

void cMonster::LoadMonsterTexture(signed int ResourceID,char *SubFolder,int Wrap,int Type,bool Check)
{
	int MonsterID = ResourceID - MONSTER_MODEL;
	// ----
	for(int i = 0; i < MAX_MONSTER; i++)
	{
		if(MonsterID == BOLO_MERCHANT)
		{
			pLoadTexture(ResourceID,"Monster\\",GL_REPEAT,GL_NEAREST,GL_TRUE);
			return;
		}
	}
	// ----
	pLoadTexture(ResourceID,SubFolder,Wrap,Type,Check);
}*/

/*void Naked cMonster::ShowMonsterModel()
{
	//static DWORD dwShowMobBull	= 0x00501694;
	//static DWORD dwShowMobReturn	= 0x00503EC6;
	//static DWORD dwShowMobJumping	= 0x004FF599;
	//static DWORD dwViewportObject	= 0x004FD3A4;
	//static DWORD dwLoadMonsterId	= 0x005DD7BC;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x0E4],0x258
		JA CargarNpcBolo
		// --------------------------------
		CargarNpcBolo:
		// --------------------------------
		PUSH 0x258												// -> MonsterID: (600)
		CALL dwLoadMonsterId
		ADD ESP,0x04
		PUSH 0
		MOV CL,BYTE PTR SS:[EBP+0x10]
		PUSH ECX
		MOV DL,BYTE PTR SS:[EBP+0x0C]
		PUSH EDX
		PUSH 0x461												// -> Calc: MonsterID + 521
		MOV EAX,DWORD PTR SS:[EBP+0x14]
		PUSH EAX
		CALL dwViewportObject
		ADD ESP,0x14
		MOV DWORD PTR SS:[EBP-0x10],EAX
		JMP dwShowMobReturn
		JMP dwShowMobJumping
	}
}*/

/*void cMonster::InitLoadMonsterModel()
{
	gToolKit.SetOp((LPVOID)0x005DD811,(LPVOID)this->LoadMonsterModel,ASM::CALL);
}*/

/*void cMonster::InitLoadMonsterTexture()
{
	gToolKit.SetOp((LPVOID)0x005DD8C0,(LPVOID)this->LoadMonsterTexture,ASM::CALL);
}*/

/*void cMonster::InitShowMonsterModel()
{
	gToolKit.SetRange((LPVOID)0x004FF589,16,ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004FF589,cMonster::ShowMonsterModel);
}*/

/*void cMonster::Load()
{
	//this->InitLoadMonsterModel();
	//this->InitLoadMonsterTexture();
	//this->InitShowMonsterModel();


	//gToolKit.SetOp((LPVOID)0x00618EE5,(LPVOID)this->ShowMonster,ASM::CALL);//here


	//gToolKit.SetOp((LPVOID)0x00501696,(LPVOID)this->MonsterID,ASM::CALL);
	//gToolKit.SetOp((LPVOID)0x005016B1,(LPVOID)this->ViewportObject,ASM::CALL);
}

// Test
#define Main_PrintGlobal 00515180H; // H on end is the same as 0x shits :D

void cMonster::Message_Glob(int ColorId, char* Message) // 1 Azul, 0 dourada
{
	_asm
	{
		Mov Edi, Main_PrintGlobal
		Push ColorId
		Push Message
		Call Edi
		Add Esp, 0x8
	}
}

#define pViewportObject		((int(__cdecl*)(int Arg1,int ResourceID,unsigned char CoordX,unsigned char CoordY,float Size)) 0x004FD3A4)
#define pLoadMonsterID		((int(__cdecl*)(signed int Arg1)) 0x005DD7BC)
#define pShowMonster		((int(__cdecl*)(int MonsterID,int CoordX,int CoordY,int Arg4)) 0x004FF128)

int cMonster::ViewportObject(int Arg1,int ResourceID,unsigned char CoordX,unsigned char CoordY,float Size)
{
	char Message[256];
	sprintf_s(Message,"%d %d %d %d %f",Arg1,ResourceID,CoordX,CoordY,Size);
	Message_Glob(0,Message);

	return pViewportObject(Arg1,ResourceID,CoordX,CoordY,Size);
}

int cMonster::MonsterID(signed int ResourceID)
{
	char Message[256];
	sprintf_s(Message,"%d",ResourceID);
	Message_Glob(0,Message);

	return pLoadMonsterID(ResourceID);
}

#define MONSTER_ARRAY 521

int cMonster::ShowMonster(int MonsterID,int CoordX,int CoordY,int Arg4)
{
	//char Message[256];
	//sprintf_s(Message,"%d %d %d %d",MonsterID,CoordX,CoordY,Arg4);

	//Message_Glob(0,Message);

	// ----
	if(MonsterID == BOLO_MERCHANT)
	{
		pLoadMonsterID(BOLO_MERCHANT);
		pViewportObject(Arg4,BOLO_MERCHANT+MONSTER_ARRAY,CoordX,CoordY,0.0f);
	}

	return pShowMonster(MonsterID,CoordX,CoordY,Arg4);
}*/