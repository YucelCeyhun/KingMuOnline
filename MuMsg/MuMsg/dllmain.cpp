// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "MuMsg.h"
#pragma warning(disable : 4996);
BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	return TRUE;
}


CMsg::CMsg() // Correct
{
	memset(&this->szDefaultMsg, 0, sizeof(this->szDefaultMsg));
	this->Msghead = NULL;
	strcpy(this->szDefaultMsg, "Msg error");
}


CMsg::~CMsg() // Correct
{
	this->lMsgFree();
}
void  CMsg::XorBuffer(char* buff, int len) // Correct
{
	if (len <= 0)
	{
		return;
	}

	for (int iCounter = 0; iCounter < len; iCounter++)
	{
		buff[iCounter] = buff[iCounter] ^ 0xCA;	// Buffer
	}
}

void CMsg::DataFileLoadVer01(FILE* filename)	// SubIndex;Index;Len(WORD);LPSTR
{
	unsigned char szTemp[256];
	int Index;
	unsigned int Len;

	int Max = this->LoadHeader.count;

	if (Max <= 0)
	{

		return;
	}
	else
	{
		while (Max != 0)
		{
			memset(&szTemp, 0, sizeof(szTemp));
			fread(&Index, 2, 1, filename);
			fread(&Len, 2, 1, filename);
			fread(&szTemp[0], Len, 1, filename);
			szTemp[Len] = 0;

			this->XorBuffer((char*)szTemp, Len);
			this->lMsgListAdd(Index, (unsigned char*)szTemp);
			Max--;
		}
	}
}
void CMsg::LoadWTF(LPSTR filename)
{
	FILE* WTFFile;
	char szBufferError[128];

	WTFFile = fopen(filename, "rb");

	if (WTFFile == 0)
	{
		wsprintf((LPWSTR)szBufferError, L"Could not open %s.", filename);	// %s file does not exist
		MessageBox(NULL, (LPWSTR)szBufferError, L"Error", MB_OK | MB_APPLMODAL);
		return;
	}
	else
	{
		if (this->lMsgListInit() != 0)
		{
			fread(&this->LoadHeader, 28, 1, WTFFile);

			if (this->LoadHeader.headcode != 0xCC)
			{
				MessageBox(NULL, L"TextCode Type Wrong.", L"Error", MB_OK | MB_APPLMODAL);
			}
			else if ((this->LoadHeader.version - 1) != 0)
			{
				MessageBox(NULL, L"bla bla", L"Error", MB_OK | MB_APPLMODAL);
			}
			else
			{
				DataFileLoadVer01(WTFFile);
			}
			fclose(WTFFile);
		}
	}
}
int CMsg::lMsgListInit()
{
	MSG_STRUCT* msg;

	if ((msg = new MSG_STRUCT) == 0)
	{
		//	MessageBox(NULL, "Memory Allocation Error (MuMsg)", "Error", MB_OK);
		return 0;
	}
	else
	{
		msg->next = NULL;
		msg->number = 0;
		msg->msg = NULL;
		memset(this->MsgIndex, 0, sizeof(this->MsgIndex));
		return 1;
	}
	return 1;
}
void CMsg::lMsgFree()
{
	for (int n = 0; n < 32768; n++)
	{
		if (this->MsgIndex[n] != 0)
		{
			delete this->MsgIndex[n]->msg;
			delete this->MsgIndex[n];
		}
	}
}
MSG_STRUCT* CMsg::lMsgListNew()
{
	return new MSG_STRUCT;
}
int CMsg::lMsgListAdd(int index, UCHAR* smsg)
{
	int MsgLen = strlen((char*)smsg);
	char* pPointer;

	if (MsgLen > 0)
	{
		this->MsgIndex[index] = this->lMsgListNew();
		if (this->MsgIndex[index] == 0)
		{
			//MessageBox(NULL, "Memory Allocation Error #2(MuMsg)", "Error", MB_OK); // Memory Allocation Error
			return 0;
		}
		pPointer = new char[MsgLen + 1];

		if (pPointer != 0)
		{
			this->MsgIndex[index]->number = index;
			if (index >= 0 || index < 32767)
			{
				this->MsgIndex[index]->msg = (unsigned char*)pPointer;
				strcpy((char*)this->MsgIndex[index]->msg, (char*)smsg);
				return 1;
			}
			else
			{
				//MessageBox(NULL, "Message Index Table Make Error", "Error", MB_OK);
				return 0;
			}
		}
	}
	return 1;
}
void CMsg::lMsgListPrint()
{
	for (int n = 0; n < 32768; n++)
	{
		if (this->MsgIndex[n] != 0)
		{
			//MessageBox(NULL, (char*)this->MsgIndex[n]->msg, "Message", MB_OK);
		}
	}
}
LPSTR CMsg::Get(int index)
{
	if (index >= 0 && index < 32768)
	{
		if (this->MsgIndex[index] == 0)
		{
			return this->szDefaultMsg;
		}

		if (this->MsgIndex[index]->msg == 0)
		{
			return this->szDefaultMsg;
		}

		if (*this->MsgIndex[index]->msg == 0)
		{
			return this->szDefaultMsg;
		}

		return (char*)this->MsgIndex[index]->msg;
	}
	return (char*)this->szDefaultMsg;
}
