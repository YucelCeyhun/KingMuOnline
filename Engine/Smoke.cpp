#include "StdAfx.h"

int IsCustomSmoke = GetPrivateProfileInt("Engine","UseCustomSmoke",0,ENGINE_INI);

DWORD pItemType = 0;

float R = 0.0f;
float G = 0.0f;
float B = 0.0f;

int g_iItemCount = 0;

cSmoke::sEffect eColor[256];

cSmoke gSmoke;

INT cSmoke::GetLineId(DWORD ItemType)
{
	for(int i = 0;i < g_iItemCount;i++)
	{
		if(pItemType == ObjectId(11,eColor[i].Id)) // Boots type (11)
		{
			return i;
		}
	}

	return -1;
}

void Naked cSmoke::SetItemEffect()
{
	static DWORD dwSetItemEffect_Buffer;
	// ----
	_asm
	{
		MOV pItemType, ECX
	}

	if(gSmoke.GetLineId(pItemType) > -1)
	{
		_asm
		{
			MOV dwSetItemEffect_Buffer,oSetSmokeAllowed
			JMP dwSetItemEffect_Buffer
		}
	}

	_asm
	{
		MOV dwSetItemEffect_Buffer,oSetSmokeNotAllowed
		JMP dwSetItemEffect_Buffer
	}
}

void Naked cSmoke::SetColorEffect()
{
	static DWORD dwSetColorEffect_Buffer;
	// ----
    _asm
    {
        MOV pItemType,ECX
    }
	// ----
	int i;
	i = gSmoke.GetLineId(pItemType);
	// ----
	for(int i = 0; i < g_iItemCount; i++)
	{
		if(pItemType == ObjectId(11,eColor[i].Id))
		{
		    R = eColor[i].R;
		    G = eColor[i].G;
		    B = eColor[i].B;
			// ----
			_asm
			{
				MOV ECX,DWORD PTR SS:[EBP+0xC]
				MOV EDX,R
				MOV DWORD PTR DS:[ECX+0x9C],EDX
				MOV EDX,DWORD PTR SS:[EBP+0xC]
				MOV EAX,G
				MOV DWORD PTR DS:[EDX+0xA0],EAX
				MOV EAX,DWORD PTR SS:[EBP+0xC]
				MOV ECX,B
				MOV DWORD PTR DS:[EAX+0xA4],ECX
			}
		}
	}
	// ----
    _asm
    {
        MOV dwSetColorEffect_Buffer,oSetSmokeReturn
        JMP dwSetColorEffect_Buffer
    }
}

void cSmoke::Load()
{
	if(IsCustomSmoke == 1)
	{
		if(gScriptEncode.ReadScript(SMOKE_FILE))
		{
			int Token;
			Token = gScriptEncode.GetToken();

			g_iItemCount = 0;
			memset(eColor,-1,sizeof(eColor));

			while(true)
			{
				Token = gScriptEncode.GetToken();

				if((Token == END)) break;

				eColor[g_iItemCount].Id		= gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eColor[g_iItemCount].R		= gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eColor[g_iItemCount].G		= gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eColor[g_iItemCount].B		= gScriptEncode.TokenNumber;

				g_iItemCount++;
			}

			if(g_iItemCount > 0)
			{
				gToolKit.SetRange((LPVOID)oSetSmokeEffect,12,ASM::NOP);
				gToolKit.SetJmp((LPVOID)oSetSmokeEffect,this->SetItemEffect);
				// ----
				gToolKit.SetRange((LPVOID)oSetSmokeColor,46,ASM::NOP);
				gToolKit.SetJmp((LPVOID)oSetSmokeColor,this->SetColorEffect);
			}
		}
		else
		{
			MessageBox(NULL,"ItemSmoke.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
}