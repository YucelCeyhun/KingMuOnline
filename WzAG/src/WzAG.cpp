#include "StdAfx.h"

FILE* fstream1, * fstream2;
char* Lsrvname, * Lsrvver, * Lpartition, * Laddrarg7, * FileBuffer, * szLanguage;
// ----
unsigned long FileLen;
// ----
unsigned char szServerKey[19] = { 0x29,0x23,0xBE,0x00,
								0xE1,0x6C,0xD6,0xAE,
								0x52,0x90,0x49,0xF1,
								0xF1,0xBB,0xE9,0xEB,
								0xB3,0xA6,0xDB };


BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
	return TRUE;
}

WZAG_API int AGConnectSetFS()
{
	_asm
	{
		xor eax, eax
	}
	return 0;
}

WZAG_API int AGGetClientVersion(int unknown, char* VerBuff, char* SerialBuff)
{
	char Version[0x14];
	char Serial[0x14];
	char CommonServerPath[] = "..\\Data\\CommonServer.cfg";
	// ----
	GetPrivateProfileString("GameServerInfo", "ClientExeVersion", "", &Version[0], 0x14, CommonServerPath);
	GetPrivateProfileString("GameServerInfo", "ClientExeSerial", "", &Serial[0], 0x14, CommonServerPath);
	// ----
	memcpy(VerBuff, Version, 0x14);
	memcpy(SerialBuff, Serial, 0x14);
	// ----
	return 0;
}

WZAG_API char* AGGetDataBuffer()
{
	return FileBuffer;
}

WZAG_API int AGGetDataBufferSize()
{
	return FileLen;
}

WZAG_API void AGGetKey(HANDLE handle, char* key, int startindex, int len)
{
	memcpy(key, szServerKey, sizeof(szServerKey));
}

WZAG_API int AGReleaseHandle()
{
	_asm
	{
		xor eax, eax
	}
	return 0;
}

WZAG_API int AGRequestData(int NoneUse, int GetType)
{
	char* filename = { 0 };
	// ----
	switch (GetType)
	{
		//Item
	case 0x00:
		filename = "..\\Data\\Lang\\Kor\\Item(Kor).txt";
		break;
	case 0x01:
		filename = "..\\Data\\Lang\\Jpn\\Item(Jpn).txt";
		break;
		//Skill
	case 0x02:
		filename = "..\\Data\\Lang\\Kor\\Skill(Kor).txt";
		break;
	case 0x03:
		filename = "..\\Data\\Lang\\Jpn\\Skill(Jpn).txt";
		break;
		//Quest
	case 0x04:
		filename = "..\\Data\\Lang\\Kor\\Quest(Kor).txt";
		break;
	case 0x05:
		filename = "..\\Data\\Lang\\Jpn\\Quest(Jpn).txt";
		break;
		//Checksum
	case 0x06:
		filename = "..\\Data\\CheckSum.dat";
		break;
		//Monster
	case 0x07:
		filename = "..\\Data\\Monster.txt";
		break;
		//Gates
	case 0x08:
		filename = "..\\Data\\Gate.txt";
		break;
		//Position of Monsters
	case 0x09:
#ifdef COMPILE_FOR_GSCS
		filename = "..\\Data\\MonsterSetBaseCS.txt";
#endif //COMPILE_FOR_GSCS
#ifdef COMPILE_FOR_GS
		filename = "..\\Data\\MonsterSetBase.txt";
#endif //COMPILE_FOR_GS
		break;
		//Reserved for GameGuard
	case 0x0A:
		break;
		//Shops
	case 0x0B:
		filename = "..\\Data\\Shop0.txt";
		break;
	case 0x0C:
		filename = "..\\Data\\Shop1.txt";
		break;
	case 0x0D:
		filename = "..\\Data\\Shop2.txt";
		break;
	case 0x0E:
		filename = "..\\Data\\Shop3.txt";
		break;
	case 0x0F:
		filename = "..\\Data\\Shop4.txt";
		break;
	case 0x10:
		filename = "..\\Data\\Shop5.txt";
		break;
	case 0x11:
		filename = "..\\Data\\Shop6.txt";
		break;
	case 0x12:
		filename = "..\\Data\\Shop7.txt";
		break;
	case 0x13:
		filename = "..\\Data\\Shop8.txt";
		break;
	case 0x14:
		filename = "..\\Data\\Shop9.txt";
		break;
	case 0x15:
		filename = "..\\Data\\Shop10.txt";
		break;
	case 0x16:
		filename = "..\\Data\\Shop11.txt";
		break;
	case 0x17:
		filename = "..\\Data\\Shop12.txt";
		break;
	case 0x18:
		filename = "..\\Data\\Lang\\Kor\\MoveReq(Kor).txt";
		break;
	case 0x19:
		filename = "..\\Data\\Lang\\Jpn\\MoveReq(Jpn).txt";
		break;
	case 0x1A:
		filename = "..\\Data\\Lang\\Kor\\ItemSetOption(Kor).txt";
		break;
	case 0x1B:
		filename = "..\\Data\\Lang\\Jpn\\ItemSetOption(Jpn).txt";
		break;
	case 0x1C:
		filename = "..\\Data\\Lang\\Kor\\ItemSetType(Kor).txt";
		break;
	case 0x1D:
		filename = "..\\Data\\Lang\\Jpn\\ItemSetType(Jpn).txt";
		break;
	case 0x1E:
		filename = "..\\Data\\Shop13.txt";
		break;
	case 0x1F:
		filename = "..\\Data\\Shop14.txt";
		break;
	case 0x20:
		filename = "..\\Data\\Shop15.txt";
		break;
	case 0x21:
		filename = "..\\Data\\Shop16.txt";
		break;
	case 0x22:
		filename = "..\\Data\\Shop17.txt";
		break;
	case 0x23://Moss
		filename = "..\\Data\\Shop18.txt";
		break;
	case 0x24://Stadium Guard
		filename = "..\\Data\\Shop19.txt";
		break;
	case 0x25://Leo The Helper
		filename = "..\\Data\\Shop20.txt";
		break;
	case 0x26://Luke The Helper
		filename = "..\\Data\\Shop21.txt";
		break;
	case 0x27://Bolo The Merchant
		filename = "..\\Data\\Shop22.txt";
		break;
	case 0x28://Dina The Merchant
		filename = "..\\Data\\Shop23.txt";
		break;
	case 0x29://Adniel Princess
		filename = "..\\Data\\Shop24.txt";
		break;
	case 0x2A://Kundun
		filename = "..\\Data\\Shop25.txt";
		break;
		//Verify
	default:
		filename = "Error!";
		::ExitProcess(0);
		break;
	}
	// ----
	if (fstream1 = fopen(filename, "rb"))
	{
		fseek(fstream1, 0, SEEK_END);
		// ----
		if (FileLen = ftell(fstream1))
		{
			fseek(fstream1, 0, SEEK_SET);
			FileBuffer = new char[FileLen + 1];
			fread(FileBuffer, FileLen, 1, fstream1);
		}
		else
		{
			MessageBox(NULL, filename, "Error.", MB_OK);
			::ExitProcess(0);
		}
		// ----
		fclose(fstream1);
	}
	else
	{
		MessageBox(NULL, filename, "Error.", MB_OK);
		::ExitProcess(0);
	}
	// ----
	return 0;
}

WZAG_API int AGSetInfo(int Language, char* Partition, int un0, char* SrvVer, char* SrvName, int SrvType, char* Addr7)
{
	switch (Language)
	{
	case KOR:
	{
		szLanguage = "Kor";
		break;
	}
	case JPN:
	{
		szLanguage = "Jpn";
		break;
	}
	default:
	{
		MessageBox(0, "Language Selected is not Supported\nChange Language in CommonServer.cfg", "Error", MB_OK | MB_ICONERROR);
		::ExitProcess(0);
		break;
	}
	}
	// ----
	Lsrvname = SrvName;
	Lsrvver = SrvVer;
	Lpartition = Partition;
	Laddrarg7 = Addr7;
	return 0;
}

WZAG_API int AGSetSubInfo()
{
	_asm
	{
		xor eax, eax
	}
	return 0;
}
