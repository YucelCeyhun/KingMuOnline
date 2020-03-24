#include <Windows.h>
#include <math.h>
#include <gl\gl.h>
#include "Interface.h"
#include "Control.h"
#include "Camera.h"
#include "Import.h"
#include "Defines.h"
#include "Enums.h"
#include "FogEffect.h"
#include "NewDetours.h"

#pragma comment(lib,"NewDetours.lib")

void APIENTRY glEnable_Hooked(GLenum);
typedef void (APIENTRY *ptr_glEnable)(GLenum);
ptr_glEnable glEnable_Real = (ptr_glEnable)&glEnable;

int IsFog = GetPrivateProfileInt("Engine","UseCustomFogEffect",0,".\\Engine.ini");

cFogEffect gFogEffect;

BOOL cFogEffect::EventMaps()
{
	if(pMapNumber == Kalima1 || pMapNumber == Kalima2 || pMapNumber == Kalima3 || pMapNumber == Kalima4 || pMapNumber == Kalima5 || pMapNumber == Kalima6 || pMapNumber == Kalima7)
	{
		return FALSE;
	}
	// ----
	return TRUE;
}

#define ON_CASHSHOP			gInterface.CheckWindow(ObjWindow::CashShop)
#define ON_FRIEND			gInterface.CheckWindow(ObjWindow::FriendList)

#pragma warning(disable:4244)
void APIENTRY glEnable_Hooked(GLenum cap)
{
	if(pPlayerState == SelectServer)
	{
		glDisable(GL_FOG);
	}
	// ----
	if(pPlayerState == GameProcess && gFogEffect.EventMaps() == TRUE)
	{
		if(cap == GL_BLEND || cap == GL_TEXTURE_2D || cap == GL_DEPTH_TEST)
		{
			glDisable(GL_FOG);
		}
		if(ON_CASHSHOP)
		{
			glDisable(GL_FOG);
		}
		// ----
		GLfloat FogColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		// ----
		glEnable_Real(GL_FOG);
		glFogi(GL_FOG_MODE, GL_LINEAR);
		glFogf(GL_FOG_DENSITY, 0.01f);
		glHint(GL_FOG_HINT, GL_NICEST);
		glFogfv(GL_FOG_COLOR, FogColor);
		glFogf(GL_FOG_START, 1200.0f);
		glFogi(GL_FOG_END, 1500.0f + (floor(*Camera_PosZ - 150.0f) * 1.5f) + 3000.0f);
		// ----
		if(cap == GL_BLEND || cap == GL_TEXTURE_2D || cap == GL_DEPTH_TEST)
		{
			glDisable(GL_FOG);
		}
		if(ON_CASHSHOP)
		{
			glDisable(GL_FOG);
		}
	}
	glEnable_Real(cap);
}

void cFogEffect::Load()
{
	if(IsFog == FogOn)
	{
		DisableThreadLibraryCalls(gControl.hModule);
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)glEnable_Real,glEnable_Hooked);
		DetourTransactionCommit();
	}
}