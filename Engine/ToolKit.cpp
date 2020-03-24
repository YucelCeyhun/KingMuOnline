#include "StdAfx.h"

ToolKit gToolKit;

void ToolKit::Protect(DWORD dwSrcOffset, int Size, DWORD dwNewProtect)
{
	DWORD OldProtect = 0;
	VirtualProtect((LPVOID)dwSrcOffset, Size, dwNewProtect, &OldProtect);
};

DWORD ToolKit::UnProtect(DWORD dwSrcOffset, int Size)
{
	DWORD OldProtect = 0;
	VirtualProtect((LPVOID)dwSrcOffset, Size, PAGE_EXECUTE_READWRITE, &OldProtect);
	return OldProtect;
};

void ToolKit::SetNop(DWORD dwSrcOffset, int Size)
{
	for (int i = 0; i < Size; i++) 
		*(BYTE*)(dwSrcOffset + i) = 0x90;
};

void ToolKit::SetByteOld(DWORD dwSrcOffset, BYTE bOpCode)
{
	__try 
	{
		DWORD dwProtect = this->UnProtect(dwSrcOffset, 1);
		*(BYTE*)(dwSrcOffset) = bOpCode;
		this->Protect(dwSrcOffset, 1, dwProtect);
	}
	__finally {}
};

void ToolKit::WriteJmp(DWORD dwSrcOffset, DWORD dwDstOffset)
{
	if (dwSrcOffset)
	{
		__try
		{
			DWORD dwOffset = UnProtect(dwSrcOffset, 10);
			SetByteOld(dwSrcOffset, 0xE9);
			HookThis(dwDstOffset, dwSrcOffset);
			Protect(dwSrcOffset, 10, dwOffset);
		}
		__finally {}
	}
};

void ToolKit::HookThis(DWORD dwDstOffset, DWORD dwSrcOffset)
{
	*(DWORD*)(dwSrcOffset + 1) = dwDstOffset - (dwSrcOffset + 5);
};

void ToolKit::HookExactOffset(DWORD my, DWORD tohook, BYTE type)
{
	*(BYTE*)tohook = type;
	*(DWORD*)(tohook+1) = my;
};

void ToolKit::HookOffset(DWORD my, DWORD tohook, BYTE type)
{
	*(BYTE*)tohook = type;
	*(DWORD*)(tohook+1) = my - (tohook+5);
};

bool ToolKit::FileExists(char * name)
{
	if(CreateFile(name,0,0,0,OPEN_EXISTING,0,0) == INVALID_HANDLE_VALUE)
		return false;
	return true;
};

DWORD ToolKit::WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize)
{
    DWORD dwErrorCode   = 0;
    DWORD dwOldProtect  = 0;
	// ----
    int iRes = VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, & dwOldProtect);
	// ----
    if ( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }
	// ----
    memcpy(lpAddress, lpBuf, uSize);
	// ----
    DWORD dwBytes   = 0;
	// ----
    iRes = VirtualProtect(lpAddress, uSize, dwOldProtect, & dwBytes);
	// ----
    if ( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }
	// ----
    return 0x00;
};

DWORD ToolKit::ReadMemory(const LPVOID lpAddress, LPVOID lpBuf, const UINT uSize)
{
    DWORD dwErrorCode   = 0;
    DWORD dwOldProtect  = 0;
	// ----
    int iRes = VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, & dwOldProtect);
	// ----
    if ( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }
	// ----
    memcpy(lpBuf, lpAddress, uSize);
	// ----
    DWORD dwBytes   = 0;
	// ----
    iRes = VirtualProtect(lpAddress, uSize, dwOldProtect, & dwBytes);
	// ----
    if ( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }
	// ----
    return 0x00;
};

DWORD ToolKit::SetByte(const LPVOID dwOffset, const BYTE btValue)
{
	return WriteMemory(dwOffset, (LPVOID) & btValue, sizeof(BYTE));
};

DWORD ToolKit::GetByte(const LPVOID dwOffset, BYTE & btValue)
{
	return ReadMemory(dwOffset, (LPVOID) btValue, sizeof(BYTE));
};

DWORD ToolKit::SetWord(const LPVOID dwOffset, const WORD wValue)
{
	return WriteMemory(dwOffset, (LPVOID) wValue, sizeof(WORD));
};

DWORD ToolKit::GetWord(const LPVOID dwOffset, WORD & wValue)
{
	return ReadMemory(dwOffset, (LPVOID) wValue, sizeof(WORD));
};

DWORD ToolKit::SetDword(const LPVOID dwOffset, const DWORD dwValue)
{
	return WriteMemory(dwOffset, (LPVOID) dwValue, sizeof(DWORD));
};

DWORD ToolKit::GetDword(const LPVOID dwOffset, DWORD & dwValue)
{
	return ReadMemory(dwOffset, (LPVOID) dwValue, sizeof(DWORD));
};

DWORD ToolKit::SetFloat(const LPVOID dwOffset, float fValue)
{
	return WriteMemory(dwOffset, &fValue, sizeof(float));
};

DWORD ToolKit::GetFloat(const LPVOID dwOffset, float & fValue)
{
	return ReadMemory(dwOffset, &fValue, sizeof(float));
};

DWORD ToolKit::SetDouble(const LPVOID dwOffset, double dValue)
{
	return WriteMemory(dwOffset, &dValue, sizeof(double));
};

DWORD ToolKit::GetDouble(const LPVOID dwOffset, double & dValue)
{
	return ReadMemory(dwOffset, &dValue, sizeof(double));
};

DWORD ToolKit::SetJmp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress)
{
	BYTE btBuf[5];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;
	// ----
	btBuf[0]	= 0xE9;
	memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));
	// ----
	return WriteMemory(dwEnterFunction, (LPVOID) btBuf, sizeof(btBuf));
};

DWORD ToolKit::SetJg(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress)
{
	BYTE btBuf[6];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 6;
	// ----
	btBuf[0]	= 0x0F;
	btBuf[1]	= 0x8F;
	memcpy( (LPVOID) & btBuf[2], (LPVOID) & dwShift, sizeof(ULONG_PTR));
	// ----
	return WriteMemory(dwEnterFunction, (LPVOID) btBuf, sizeof(btBuf));
};

DWORD ToolKit::SetJa(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress)
{
	BYTE btBuf[6];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 6;
	// ----
	btBuf[0]	= 0x0F;
	btBuf[1]	= 0x87;
	memcpy( (LPVOID) & btBuf[2], (LPVOID) & dwShift, sizeof(ULONG_PTR));
	// ----
	return WriteMemory(dwEnterFunction, (LPVOID) btBuf, sizeof(btBuf));
};

DWORD ToolKit::SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd)
{
	BYTE btBuf[5];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;
	// ----
	btBuf[0]		= cmd;
	memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));
	// ----
	return WriteMemory(dwEnterFunction, (LPVOID) btBuf, sizeof(btBuf));
};

DWORD ToolKit::SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue)
{
	BYTE * lpBuf	= new BYTE[wCount];
	// ----
	memset(lpBuf, btValue, wCount);
	// ----
	return WriteMemory( dwAddress, (LPVOID) lpBuf, wCount);
};

DWORD ToolKit::SetHook(const LPVOID dwMyFuncOffset, const LPVOID dwJmpOffset, const BYTE cmd)
{
	BYTE btBuf[5];
	// ----
	DWORD dwShift	= (ULONG_PTR)dwMyFuncOffset - ( (ULONG_PTR)dwJmpOffset + 5 );
	// ----
	btBuf[0] = cmd;
	// ----
	memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));
	// ----
	return WriteMemory(dwJmpOffset, (LPVOID) btBuf, sizeof(btBuf));
};

void ToolKit::MemorySet(DWORD offset, DWORD value, DWORD size)
{
	DWORD OldProtect;
	VirtualProtect((void*)offset, size, PAGE_EXECUTE_READWRITE, &OldProtect);
	memset((void*)offset, value, size);
	VirtualProtect((void*)offset, size, OldProtect, &OldProtect);
};

void ToolKit::SetCompleteHook(BYTE head, DWORD offset, ...)
{
	DWORD OldProtect;
	VirtualProtect((void*)offset, 5, PAGE_EXECUTE_READWRITE, &OldProtect);
	// ----
	if (head != 0xFF)
	{
		*(BYTE*)(offset) = head;
	}
	// ----
	DWORD* function = &offset + 1;
	*(DWORD*)(offset + 1) = (*function) - (offset + 5);
	// ----
	VirtualProtect((void*)offset, 5, OldProtect, &OldProtect);
};

void ToolKit::Access(DWORD dwOffset,int t_size)
{
	DWORD OldProtect;
	VirtualProtect((LPVOID)dwOffset,t_size,PAGE_EXECUTE_READWRITE,&OldProtect);
};

void ToolKit::HookAddress(DWORD dwAddrOffst,DWORD dwNewOffst,BYTE new_Cmd)
{
	this->Access(dwAddrOffst,5);
	// ---
	if (new_Cmd)
		memset((void*)dwAddrOffst,new_Cmd,1);
	// ----
	*(DWORD*)(dwAddrOffst+1) = dwNewOffst - (dwAddrOffst+5);
};