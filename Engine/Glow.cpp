#include "StdAfx.h"

int IsCustomGlows = GetPrivateProfileInt("Engine","UseCustomGlows",0,ENGINE_INI);

cGlow gGlow;

void cGlow::ItemGlowEx(int ObjectId,float Arg2,float Arg3,vec3_t Color,bool Mode)
{
	for(int i = 0;i <= gGlow.gItemCount;i++)
	{
		if(ObjectId == ObjectId(gGlow.eITEM[i].Type,gGlow.eITEM[i].Index))
		{
			Vector(gGlow.eGLOW[i].R,gGlow.eGLOW[i].G,gGlow.eGLOW[i].B,Color);
			break;
		}
		else
		{
			pItemGlowColor(ObjectId,Arg2,Arg3,Color,Mode);
		}
	}
}

void cGlow::Load()
{
	if(IsCustomGlows == 1)
	{
		if(gScriptEncode.ReadScript(GLOW_FILE))
		{
			int Token;
			Token = gScriptEncode.GetToken();

			gItemCount = 0;
			memset(eITEM,-1,sizeof(eITEM));

			while(TRUE)
			{
				Token = gScriptEncode.GetToken();

				if((Token == END)) break;

				eITEM[gItemCount].Type	= gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eITEM[gItemCount].Index	= gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();

				eGLOW[gItemCount].R	= gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eGLOW[gItemCount].G	= gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eGLOW[gItemCount].B	= gScriptEncode.TokenNumber;

				gItemCount++;
			}

			if(gItemCount > 0)
			{
				gToolKit.SetOp((LPVOID)0x004F9E1B,this->ItemGlowEx,ASM::CALL);
				gToolKit.SetOp((LPVOID)0x005CD032,this->ItemGlowEx,ASM::CALL);
			}
		}
		else
		{
			MessageBox(NULL,"ItemGlow.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
}