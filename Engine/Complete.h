#ifndef __COMPLETE_H__
#define __COMPLETE_H__

//bool __cdecl sub_49A450(signed int a1) -> return bool
typedef bool(__cdecl *IsChaosCastle)(int MapNumber);
extern IsChaosCastle gIsChaosCastle;
//---------------------------------------------------------------------------

//char __cdecl sub_51C4EC(BYTE a1) -> return WORD
typedef WORD(__cdecl *ItemCharSetConvert)(BYTE Pointer);
extern ItemCharSetConvert gItemCharSetConvert;
//---------------------------------------------------------------------------

//int __cdecl sub_463890(char a1) -> return BYTE or WORD
typedef BYTE(__cdecl *AmpersandConvert)(BYTE Pointer);
extern AmpersandConvert gAmpersandConvert;
//---------------------------------------------------------------------------

typedef int(__cdecl *ObjMakePreviewCharSet)(int a1, BYTE * CharSet, int a3, int a4);
extern ObjMakePreviewCharSet mObjMakePreviewCharSet;
//---------------------------------------------------------------------------

//int __cdecl sub_49A50A(int a1)
typedef int(__cdecl *Objsub_49A50A)(int Arg1);
extern Objsub_49A50A sub_49A50A;
//---------------------------------------------------------------------------

//int __cdecl sub_514A21(int a1)
typedef int(__cdecl *Objsub_514A21)(int Arg1);
extern Objsub_514A21 sub_514A21;
//---------------------------------------------------------------------------

//int __thiscall sub_4A4750(int this, int a2);
typedef int(__thiscall *Objsub_4A4750)(int This, int Arg2);
extern Objsub_4A4750 sub_4A4750;

//---------------------------------------------------------------------------

//int __cdecl sub_4A3A7D(int a1) -> return int
typedef int(__cdecl *CheckPetStatus)(int Arg1);
extern CheckPetStatus gCheckPetStatus;
//---------------------------------------------------------------------------

//int __cdecl sub_4B6740(int a1) -> return int
typedef int(__cdecl *ReturnPetSlot)(int Arg1);
extern ReturnPetSlot gReturnPetSlot;
//---------------------------------------------------------------------------

//int __cdecl sub_4B6B54(int a1, int a2, int a3, int a4) -> return int
typedef int(__cdecl *SetObjMaunt)(int MauntCode, int Arg2, int Arg3, int Arg4, int Arg5);
extern SetObjMaunt gSetObjMaunt;
//---------------------------------------------------------------------------

//char __cdecl sub_4B680C(int a1, int a2, int a3, int a4, int a5) -> return bool
typedef bool(__cdecl *SetObjMaunt2)(int Arg1, int Arg2, int Arg3, int Arg4, int Arg5);
extern SetObjMaunt2 gSetObjMaunt2;
//---------------------------------------------------------------------------

//int __cdecl sub_8831F1() -> return THIS
typedef LPVOID(__cdecl *ObjPetGetThis)(void);
extern ObjPetGetThis gObjPetGetThis;
//---------------------------------------------------------------------------

//void __stdcall sub_88457C(int a1, int a2, char a3)
typedef void(__thiscall *SetObjPetReset)(LPVOID This, int Arg1, int Arg2, int Arg3);
extern SetObjPetReset gSetObjPetReset;
//---------------------------------------------------------------------------

//char __thiscall sub_884245(void *this, int a2, int a3, int a4, int a5, int a6, int a7) -> return bool
typedef void(__thiscall *SetObjPetOnSwitch)(LPVOID This, int Arg1, int Arg2, int Arg3, int Arg4, int Arg5, int Arg6);
extern SetObjPetOnSwitch gSetObjPetOnSwitch;
//---------------------------------------------------------------------------

//int *__cdecl sub_4ADABB(int a1) -> return int const
typedef int * (__cdecl *Objsub_4ADABB)(int Arg1);
extern Objsub_4ADABB sub_4ADABB;
//---------------------------------------------------------------------------

//int __cdecl sub_4ACDA6(int Preview * gPreview) -> return int
typedef int(__cdecl *ObjPreviewDarkRaven)(int Struct);
extern ObjPreviewDarkRaven gObjPreviewDarkRaven;
//---------------------------------------------------------------------------

typedef DWORD(*Objdword_7B65114);
extern Objdword_7B65114 dword_7B65114;
//---------------------------------------------------------------------------

typedef DWORD(*Objdword_7BA6278);
extern Objdword_7BA6278 dword_7BA6278;
//---------------------------------------------------------------------------

typedef DWORD(*Objdword_7B650F8);
extern Objdword_7B650F8 dword_7B650F8;
//---------------------------------------------------------------------------

class cComplete
{
public:
	void Load();
	// ----
	static int MakeCharSet(int Index,BYTE *CharSet,int UseStruct,int Mode);
};

extern cComplete gComplete;

#endif