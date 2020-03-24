#include "StdAfx.h"

int IsCustomExHP = GetPrivateProfileInt("Engine","UseCustomHpBar",0,ENGINE_INI);

cExHP gExHP;

cExHP::cExHP()
{
	this->IsHpm = 0;
	ZeroMemory(this->Data,sizeof(this->Data));
}

cExHP::~cExHP()
{
	/**/
}

void cExHP::InfoRecv(LPMSG_ANS_LIFEBAR_SEND aRecv)
{
	short aIndex = MAKE_NUMBERW(aRecv->NumberH, aRecv->NumberL);

	if(pGetViewPortId(aIndex) < 400)
	{
		this->Data[aIndex].Class		= aRecv->Class;
		this->Data[aIndex].Live			= (aRecv->Life <= 0.0f) ? FALSE : TRUE;
		this->Data[aIndex].Life			= aRecv->Life;
		this->Data[aIndex].MaxLife		= aRecv->MaxLife;
		this->Data[aIndex].LifePercent	= ((aRecv->Life / aRecv->MaxLife) * 100.0f);
		this->Data[aIndex].Level		= aRecv->Level;

		if(aRecv->SendSD == TRUE)
		{
			/**/
		}
	}
}

bool g_ExEnabled = false;

void cExHP::Switcher()
{
	if(this->IsHpm == HealthBarOn && pPlayerState == GameProcess)
	{
		if(g_ExEnabled)
		{
			g_ExEnabled = false;
			gExHP.HPMobEnabled = false;
			gLoadSound.LoadInterfaceWindowTick();
			gPlaySound.PlayInterfaceWindowTick();
		}
		else
		{
			g_ExEnabled = true;
			gExHP.HPMobEnabled = true;
			gLoadSound.LoadInterfaceWindowTick();
			gPlaySound.PlayInterfaceWindowTick();
		}
	}
}

void cExHP::Draw()
{
	VAngle Angle;
	int PosX,PosY;
	DWORD aIndex,pView;
	// ----
	if(!g_ExEnabled)
		return;
	// ----
	if(pPlayerState == GameProcess)
	{
		for(int i = 0; i < MAX_VIEWPORT_MOBS; i++)
		{
			pView = (1236 * i + pViewMonsterStruct);
			// ----
			if((*(BYTE*)(pView + 704) != 0x0) && (*(BYTE*)(pView + 722) == emMonster))
			{
				aIndex = *(WORD*)(pView + 94);
				// ----
				if(!gExHP.Data[aIndex].Live)
				{
					continue;
				}
				// ----
				Angle.X = *(float*)(pView+952);
				Angle.Y = *(float*)(pView+956);
				Angle.Z = *(float*)(pView+960) + *(float*)(pView+924)+100.0f;
				// ----
				pGetPosFromAngle(&Angle,&PosX,&PosY);
				float BarWidth = 48.0f * (gExHP.Data[aIndex].Life / (gExHP.Data[aIndex].MaxLife * 1.0f));
				PosX -= (int)floor(50.0f/(double)2.0);
				pSetBlend(true);
				// ----
				gInterface.DrawFormat(pMakeColor(255,189,25,255),PosX-25,PosY-8,100,3,(char*)(pView+56));
				pDrawColorButton(0x7B2E,(float)PosX,(float)(PosY+1),50.0,5.0,0,0,pMakeColor(255,255,255,255));
				pDrawColorButton(0x7B2F,(float)(PosX+2),(float)(PosY+2),BarWidth,3.0,0,0,pMakeColor(255,255,255,255));
				pGLSwitchBlend();
			}
		}
		pGLSwitch();
		glColor3f(1.0,1.0,1.0);
	}
}

/*
#define pGetPlayerPosXY				((double(__cdecl*)(float PosX,float PosY))0x5A84C3)

void cExHP::DrawPetFollow(lpObjViewport lpObjView)
{
	//VAngle Angle;
	//int PosX, PosY;
	//DWORD aIndex, pView;
	//DWORD pView;
	// ----
	if(pPlayerState == GameProcess)
	{
		for(int i = 0; i < MAX_VIEWPORT_PETS; i++)
		{
			//pView = (1236 * i + pViewMonsterStruct);
			// ----
			if(lpObjView->ObjIndex == ObjectId(13,106))	// Unicorn Pet
			{
				lpObjView->PositionX += pGetPlayerPosXY(lpObjView->PositionX+100.f,lpObjView->PositionY);		//pPlayerPosX + 2;
				lpObjView->PositionY += pGetPlayerPosXY(lpObjView->PositionX,lpObjView->PositionY+0.5f);		//pPlayerPosY + 5;
			}
		}
	}
}
*/

void cExHP::Init()
{
	gToolKit.SetOp((LPVOID)0x0057FF65,this->Draw,ASM::CALL);
	//gToolKit.SetOp((LPVOID)0x0057FF65,this->DrawPetFollow,ASM::CALL);
}

void cExHP::Load()
{
	if(IsCustomExHP == HealthBarOn)
	{
		if(gScriptEncode.ReadScript(HPMOB_FILE))
		{
			WZSMDToken Token = gScriptEncode.GetToken();
			// ----
			Token		= gScriptEncode.GetToken();
			gExHP.IsHpm	= gScriptEncode.GetNumber();
			// ----
			if(gExHP.IsHpm == HealthBarOn)
			{
				this->Init();
			}
			// ----
			gScriptEncode.Close();
		}
		else
		{
			MessageBox(NULL,"HealthMob.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
	else
	{
		return;
	}
}