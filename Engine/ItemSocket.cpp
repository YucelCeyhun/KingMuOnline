#include "StdAfx.h"

int IsCustomSocketItems = GetPrivateProfileInt("Engine","UseCustomSockets",0,ENGINE_INI);

cItemSocket gItemSocket;

int cItemSocket::ItemSocketInit(int ItemId)
{
	for(int i = 0; i <= gItemSocket.gItemSocketCount; i++)
	{
		if(ItemId == ItemId(gItemSocket.eITEM[i].Type,gItemSocket.eITEM[i].Index))
		{
			return 1;
		}
		else if(gItemSocket.eITEM[i].Type == -1)
		{
			for(int Category = 7; Category < 12; Category++)
			{
				if(ItemId == ItemId(Category,gItemSocket.eITEM[i].Index))
				{
					return 1;
				}
			}
		}
	}
	return pItemSocketSet(ItemId);
}

void cItemSocket::Load()
{
	if(IsCustomSocketItems == 1)
	{
		if(gScriptEncode.ReadScript(SOCKET_FILE))
		{
			int Token;
			Token = gScriptEncode.GetToken();

			gItemSocket.gItemSocketCount = 0;
			memset(gItemSocket.eITEM,-1,sizeof(gItemSocket.eITEM));

			while(TRUE)
			{
				Token = gScriptEncode.GetToken();

				if((Token == END)) break;

				gItemSocket.eITEM[gItemSocket.gItemSocketCount].Type = gScriptEncode.TokenNumber;

				Token = gScriptEncode.GetToken();
				gItemSocket.eITEM[gItemSocket.gItemSocketCount].Index = gScriptEncode.TokenNumber;

				gItemSocket.gItemSocketCount++;
			}

			gToolKit.SetOp((LPVOID)0x004C2CBD,this->ItemSocketInit,ASM::CALL);
			gToolKit.SetOp((LPVOID)0x004C2CDF,this->ItemSocketInit,ASM::CALL);
		}
		else
		{
			MessageBox(NULL,"ItemSocket.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
}