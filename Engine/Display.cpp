#include "StdAfx.h"

int Ani = GetPrivateProfileInt("Engine", "UseCustomAnisotropy", 0, ENGINE_INI);
int Tri = GetPrivateProfileInt("Engine", "UseCustomTrilinear", 0, ENGINE_INI);
int Lin = GetPrivateProfileInt("Engine", "UseCustomLinear", 0, ENGINE_INI);

typedef void (APIENTRY* FUNC_GLENABLE) (GLenum mode);
FUNC_GLENABLE glEnable_o = NULL;

cDisplay gDisplay;

cDisplay::cDisplay()
{
	/**/
}

cDisplay::~cDisplay()
{
	/**/
}

int cDisplay::GameLoad()
{
	pGameLoad();
	// ----
	switch (pGameResolutionMode)
	{
	case 5:
		pWinWidth = 1280;
		pWinHeight = 720;
		break;
		// --
	case 6:
		pWinWidth = 1280;
		pWinHeight = 800;
		break;
		// --
	case 7:
		pWinWidth = 1366;
		pWinHeight = 768;
		break;
		// --
	case 8:
		pWinWidth = 1440;
		pWinHeight = 900;
		break;
		// --
	case 9:
		pWinWidth = 1680;
		pWinHeight = 1050;
		break;
		// --
	case 10:
		pWinWidth = 1920;
		pWinHeight = 1080;
		break;
		// --
	case 11:
		pWinWidth = 1920;
		pWinHeight = 1200;
		break;
		// --
	case 12:
		pWinWidth = 1600;
		pWinHeight = 880;
		break;
		// --
	case 13:
		pWinWidth = 1600;
		pWinHeight = 900;
		break;
		// --
	}
	// ----
	pWinFontHeight = 15;
	pWinWidthReal = (float)pWinWidth / MAX_WIN_WIDTH;
	pWinHeightReal = (float)pWinHeight / MAX_WIN_HEIGHT;
	// ----
	return 1;
	return pGameLoad();
}

void cDisplay::MoveListInit(LPVOID This, LPVOID EDX, int Arg1, int Arg2)
{
	GLsizei TempWidth = pWinWidth;
	pWinWidth = 1280;
	pMoveListInit(This, Arg1, Arg2);
	pWinWidth = TempWidth;
	return pMoveListInit(This, Arg1, Arg2);
}

void APIENTRY glEnable_h(GLenum mode)
{
	if (Lin != 0)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	// ----
	if (Tri != 0)
	{
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	// ----
	if (Ani != 0)
	{
		glGetIntegerv(0x84FF, &Ani);
		glTexParameteri(GL_TEXTURE_2D, 0x84FE, Ani - 0.1);
		/*switch(gDisplay.Counter)
		{
			case 1:
			{
				Ani = 2;
				glGetIntegerv(0x84FF,&Ani);
				glTexParameteri(GL_TEXTURE_2D,0x84FE,Ani-0.1);
			}
			break;

			case 2:
			{
				Ani = 4;
				glGetIntegerv(0x84FF,&Ani);
				glTexParameteri(GL_TEXTURE_2D,0x84FE,Ani-0.1);
			}
			break;

			case 3:
			{
				Ani = 6;
				glGetIntegerv(0x84FF,&Ani);
				glTexParameteri(GL_TEXTURE_2D,0x84FE,Ani-0.1);
			}
			break;

			case 4:
			{
				Ani = 8;
				glGetIntegerv(0x84FF,&Ani);
				glTexParameteri(GL_TEXTURE_2D,0x84FE,Ani-0.1);
			}
			break;
		}
		*/
	}
	// ----
	glEnable_o(mode);
}

/*
bool g_iFrapsSwitcher = false;

bool cDisplay::SwitchFrapsState()
{
	if(pPlayerState == GameProcess)
	{
		if(g_iFrapsSwitcher)
		{
			g_iFrapsSwitcher = false;
			gDisplay.FrapsSwitcher = false;
			// ----
			*(BYTE*)(0x006020BF+2) = 0x28;
			*(BYTE*)(0x006020C8+2) = 0x28;
			//gToolKit.SetByte((PVOID)(0x006020BF+2),0x28);
			//gToolKit.SetByte((PVOID)(0x006020C8+2),0x28);
		}
		else
		{
			g_iFrapsSwitcher = true;
			gDisplay.FrapsSwitcher = true;
			// ----
			*(BYTE*)(0x006020BF+2) = 0x1F;
			*(BYTE*)(0x006020C8+2) = 0x1F;
			//gToolKit.SetByte((PVOID)(0x006020BF+2),0x1F);
			//gToolKit.SetByte((PVOID)(0x006020C8+2),0x1F);
		}
		return true;
	}
	else
	{
		return false;
	}
}
*/



void cDisplay::Load()
{
	//this->SwitchFrapsState();
	// ----
	gToolKit.SetOp((LPVOID)0x005FA4D0, this->GameLoad, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x007512CC, this->MoveListInit, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0075316C, this->MoveListInit, ASM::CALL);
	// ----
	glEnable_o = (FUNC_GLENABLE)DetourFunction((PBYTE)DetourFindFunction("Opengl32.dll", "glBegin"), (PBYTE)glEnable_h);
}
