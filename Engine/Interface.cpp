#include "StdAfx.h"

int UseClockMod = GetPrivateProfileInt("Engine","UseCustomClock",0,ENGINE_INI);
//int IsClk = GetPrivateProfileInt("Clock","UseClockMod",0,CLOCK_FILE);

cInterface gInterface;

cInterface::cInterface()
{
	this->EnabledClock = TRUE;
}

cInterface::~cInterface()
{
	/**/
}

void cInterface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

bool cInterface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(),WindowID);
}

void cInterface::LoadImages()
{
	pLoadImage("Custom\\Interface\\CameraUI_Switch.tga",0x7881,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\CameraUI_Reset.tga",0x7882,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\CameraUI_BG.tga",0x7883,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\GlowTron_Uncheck.tga",0x7890,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\GlowTron_Check.tga",0x7891,GL_LINEAR,GL_CLAMP,GL_TRUE);
	/*
	pLoadImage("Custom\\Interface\\Antialising_Box.tga",0x7892,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\Antialising_Plus.tga",0x7893,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\Antialising_Minus.tga",0x7894,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\Antialising_X2.tga",0x7895,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\Antialising_X4.tga",0x7896,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\Antialising_X6.tga",0x7897,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\Antialising_X8.tga",0x7898,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\ChangeFPS_Uncheck.tga",0x7899,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\ChangeFPS_Check.tga",0x789A,GL_LINEAR,GL_CLAMP,GL_TRUE);
	*/
	pLoadImage("Custom\\Interface\\TimeBarUI.tga",0x787E,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\GlowTron_Uncheck.tga",0x787F,GL_LINEAR,GL_CLAMP,GL_TRUE);
	pLoadImage("Custom\\Interface\\GlowTron_Check.tga",0x7880,GL_LINEAR,GL_CLAMP,GL_TRUE);
	// ----
	InitScreenGlow();
	// ----
	pLoadSomeForm();
}

void cInterface::intcpy(int i,char*buffer,...)
{
	itoa(i,buffer,10);
}

void cInterface::charcpy(char x,char*buffer)
{
	ltoa(x,buffer,10);
}

void cInterface::fltcpy(float f,char*buffer)
{
	gcvt(f,10,buffer);
}

void cInterface::fltptrcpy(float*f,char*buffer)
{
	gcvt(*f,10,buffer);
}

void cInterface::DrawTextColor(BYTE Red,BYTE Green,BYTE Blue,BYTE Alpha)
{
	pSetTextColor(pTextThis(),Red,Green,Blue,Alpha);
}

void cInterface::DrawBackGround(BYTE Red,BYTE Green,BYTE Blue,BYTE Alpha)
{
	pSetBackGround(pTextThis(),Red,Green,Blue,Alpha);
}

void cInterface::DrawGUI(short ObjectID, float PosX, float PosY, float Width, float Height)
{
	if ((this->Data[ObjectID].X == -1) || (this->Data[ObjectID].Y == -1))
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + Width;
		this->Data[ObjectID].MaxY = PosY + Height;
	}
	// ----
	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY, Width, Height);
}

void cInterface::DrawColoredGUI(short ObjectID, float PosX, float PosY, float Width, float Height, float StartX, float StartY, DWORD Color)
{
	if ((this->Data[ObjectID].X == -1) || (this->Data[ObjectID].Y == -1))
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + Width;
		this->Data[ObjectID].MaxY = PosY + Height;
	}
	// ----
	if (StartX == 0.0f) // Do not touch here.
	{
		this->Data[ObjectID].MaxX = (PosX + Width - StartX);
	}
	// ----
	if (StartY == 0.0f)
	{
		this->Data[ObjectID].MaxY = (PosY + Height - StartY);
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, PosX, PosY, Width, Height, StartX, StartY, Color);
}

int cInterface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	int LineCount = 0;
	// ----
	char * Line = strtok(Buff, "\n");
	// ----
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	// ----
	return PosY;
}

int cInterface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawToolTip(X, Y, Buff);
}

int cInterface::DrawToolTipEx(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen = sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	int LineCount = 0;
	// ----
	char * Line = strtok(Buff, "\n");
	// ----
	while (Line != NULL)
	{
		pDrawToolTip(X, Y, Line);
		Y += 10;
		Line = strtok(NULL, "\n");
	}
	// ----
	return Y;
}

void cInterface::TimeSwitch()
{
	if(this->IsClk == TimeOn && pPlayerState == GameProcess)
	{
		gLoadSound.LoadInterfaceWindowTick();
		gPlaySound.PlayInterfaceWindowTick();
		this->EnabledClock = !this->EnabledClock;
	}
}

bool cInterface::WinKeyChecks()
{
	if (this->CheckWindow(FriendList) || this->CheckWindow(ChatWindow))
		return true;
	return false;
}

void cInterface::DrawTime()
{
	if(this->IsClk == TimeOn)
	{
		if(this->CheckWindow(CashShop) || this->CheckWindow(ChatWindow) || this->CheckWindow(SkillTree) || this->CheckWindow(OtherStore))
		{
			return;
		}
		// ----
		time_t TimeLocal;
		struct tm LocalT;
		// ----
		time(&TimeLocal);
		localtime_s(&LocalT,&TimeLocal);
		// ----
		this->DrawGUI(eTIME,0.0f,390.0f,this->Data[eTIME].Width,this->Data[eTIME].Height);
		this->DrawFormat(pMakeColor(255,189,25,255),30,412,50,1,"Local: ");
		this->DrawFormat(pMakeColor(255,255,255,255),50,412,100,1," %2d:%02d:%02d",LocalT.tm_hour,LocalT.tm_min,LocalT.tm_sec);
	}
}

float cInterface::GetResizeX(short ObjectID)
{
	return this->Data[ObjectID].X;
}

bool cInterface::IsWorkZone(short ObjectID)
{
	float PosX = this->Data[ObjectID].X;
	float MaxX = PosX + this->Data[ObjectID].Width;
	// ----
	if ((pCursorX < PosX || pCursorX > MaxX) || (pCursorY < this->Data[ObjectID].Y || pCursorY > this->Data[ObjectID].MaxY))
	{
		return false;
	}
	// ----
	return true;
}

void cInterface::DrawButtonText()
{
	if ((this->CheckWindow(CashShop) == true) || (this->CheckWindow(SkillTree) == true) || (this->CheckWindow(MoveList) == true))
	{
		return;
	}
	// ----
	for(int i = 1; i < eLAST_OBJECT_ID; i++)
	{
		if (this->IsWorkZone(i) == true)
		{
			switch(i)
			{
				case eCAMERA_BUTTON1:
				{
					this->DrawToolTipEx((int)this->Data[i].X, (int)this->Data[i].Y + (int)this->Data[i].Height + 10, gCamera.Enabled ? "Cam Disable [HOME]" : "Cam Enable [HOME]");
					break;
				}
				case eCAMERA_BUTTON2:
				{
					this->DrawToolTipEx((int)this->Data[i].X, (int)this->Data[i].Y + (int)this->Data[i].Height + 10, "Cam Retore [END]");
					break;
				}
				/*
				case eCHANGEFPS_UNCHECKED:
				{
					if ((this->CheckWindow(Options) == false))
					{
						return;
					}
					else
					{
						this->DrawToolTipEx((int)this->Data[i].X,(int)this->Data[i].Y+(int)this->Data[i].Height+10,gDisplay.FrapsSwitcher ? "Current FPS Limiter: 31" : "Current FPS Limiter: 40");
					}
					break;
				}
				*/
				/*case eGLOWSELECTER_POINT:
				{
					if ((this->CheckWindow(ObjWindow::Inventory) == false))
					{
						return;
					}
					else
					{
						CHAR szGlowPoint[64];
						gInterface.intcpy(gInterface.GlowPointCounter, szGlowPoint);
						this->DrawToolTipEx((int)this->Data[i].X, (int)this->Data[i].Y + (int)this->Data[i].Height + 20, "Glow Selecter: (%s)", szGlowPoint);
					}
				}*/
				/*
				case eWARE_BUTTON_RIGHT:
				{
					if (this->CheckWindow(Warehouse) == true)
					{
						MU_OutText((int)this->Data[i].X, (int)this->Data[i].Y - 7, "Next Warehouse");
					}
					break;
				}
				case eWARE_BUTTON_LEFT:
				{
					if (this->CheckWindow(Warehouse) == true)
					{
						MU_OutText((int)this->Data[i].X, (int)this->Data[i].Y - 7, "Previous Warehouse");
					}
					break;
				}*/
				/*case eMINI_BUTTON_RIGHT:
				{
					if (Ext == 1)
					{
						if (this->MiniMapCheck() || this->CombinedChecks())
						{
							return;
						}
						// ----
						MU_OutText((int)this->Data[i].X, (int)this->Data[i].Y - 15, "Alpha(+)");
						break;
					}
				}
				case eMINI_BUTTON_LEFT:
				{
					if (Ext == 1)
					{
						if (this->MiniMapCheck() || this->CombinedChecks())
						{
							return;
						}
						// ----
						MU_OutText((int)this->Data[i].X, (int)this->Data[i].Y - 15, "Alpha(-)");
						break;
					}
				}*/
			}
		}
	}
}

void cInterface::DrawCameraUI()
{
	if(!this->CheckWindow(OtherStore) && !this->CheckWindow(SkillTree) && !this->CheckWindow(MoveList) && !this->CheckWindow(CashShop))
	{
		float PosX = this->GetResizeX(eCAMERA_MAIN);
		// ----
		this->DrawGUI(eCAMERA_MAIN,PosX,0.0f,this->Data[eCAMERA_MAIN].Width,this->Data[eCAMERA_MAIN].Height);
		// ----
		CHAR szCamPosZ[64];
		gInterface.fltptrcpy(Camera_PosZ,szCamPosZ);
		// ----
		CHAR szCamRotY[64];
		gInterface.fltptrcpy(Camera_RotY,szCamRotY);
		// ----
		CHAR szMap[64];
		strcpy(szMap,pGetMapName(pMapNumber));
		// ----
		int xPos = (pGameResolutionMode * 2) + 95;
		// ----
		if(pMapNumber == Market)
		{
			xPos -= strlen(szMap-7);
		}
		else if(pMapNumber == DevilSquare || pMapNumber == DevilSquare6)
		{
			xPos -= strlen(szMap-10);
		}
		else if(pMapNumber >= BloodCastle1 && pMapNumber <= BloodCastle7 || pMapNumber == BloodCastle8)
		{
			xPos -= strlen(szMap-12);
		}
		// ----
		if(strlen(szMap) >= 13)
		{
			xPos -= strlen(szMap);
		}
		// ----
		DrawFormat(eWhite,xPos,3,100,1,szMap);
		// ----
		this->DrawGUI(eCAMERA_BUTTON1,PosX+122.0f,2.0f,this->Data[eCAMERA_BUTTON1].Width,this->Data[eCAMERA_BUTTON1].Height);
		this->DrawGUI(eCAMERA_BUTTON2,PosX+140.0f,2.0f,this->Data[eCAMERA_BUTTON2].Width,this->Data[eCAMERA_BUTTON2].Height);
		// ----
		if(gCamera.Enabled)
		{
			this->DrawColoredGUI(eCAMERA_BUTTON1,PosX+122.0f,2.0f,this->Data[eCAMERA_BUTTON1].Width,this->Data[eCAMERA_BUTTON1].Height,0,0,pMakeColor(172,255,56,255));
			// ----
			/*
			if (gCamera.DevMod() == true)
			{
				DrawFormat(eExcellent, xPos, 20, 150, 1, szCamPosZ);
				DrawFormat(eExcellent, xPos, 30, 150, 1, szCamRotY);
			}*/
		}
		// ----
		if(IsWorkZone(eCAMERA_BUTTON1))
		{
			if(this->Data[eCAMERA_BUTTON1].OnClick)
			{
				this->DrawColoredGUI(eCAMERA_BUTTON1,PosX+122.0f,2.0f,this->Data[eCAMERA_BUTTON1].Width,this->Data[eCAMERA_BUTTON1].Height,0,0,pMakeColor(40,20,3,130));
				return;
			}
			// ----
			this->DrawColoredGUI(eCAMERA_BUTTON1,PosX+122.0f,2.0f,this->Data[eCAMERA_BUTTON1].Width,this->Data[eCAMERA_BUTTON1].Height,0,0,pMakeColor(255,204,20,200));
		}
		else if(IsWorkZone(eCAMERA_BUTTON2))
		{
			if(this->Data[eCAMERA_BUTTON2].OnClick)
			{
				this->DrawColoredGUI(eCAMERA_BUTTON2,PosX+140.0f,2.0f,this->Data[eCAMERA_BUTTON2].Width,this->Data[eCAMERA_BUTTON2].Height,0,0,pMakeColor(40,20,3,130));
				return;
			}
			// ----
			this->DrawColoredGUI(eCAMERA_BUTTON2,PosX+140.0f,2.0f,this->Data[eCAMERA_BUTTON2].Width,this->Data[eCAMERA_BUTTON2].Height,0,0,pMakeColor(255,204,20,200));
		}
		// ----
		if(gCamera.RestStop == true)
		{
			this->DrawColoredGUI(eCAMERA_BUTTON2,PosX+140.0f,2.0f,this->Data[eCAMERA_BUTTON2].Width,this->Data[eCAMERA_BUTTON2].Height,0,0,pMakeColor(255,0,0,200));
		}
	}
}

void cInterface::EventCameraUI(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if(this->CheckWindow(CashShop) || this->CheckWindow(ChatWindow) || this->CheckWindow(SkillTree) || this->CheckWindow(OtherStore) || this->CheckWindow(MoveList))
	{
		return;
	}

	if(IsWorkZone(eCAMERA_BUTTON1))
	{
		pSetCursorFocus = true;
		DWORD Delay = (CurrentTick - this->Data[eCAMERA_BUTTON1].EventTick);
		// ----
		if(Event == WM_LBUTTONDOWN)
		{
			this->Data[eCAMERA_BUTTON1].OnClick = true;
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON1].OnClick = false;
		// ----
		if(Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON1].EventTick = GetTickCount();
		// ----
		gCamera.SwitchState();
	}
	else if(IsWorkZone(eCAMERA_BUTTON2))
	{
		pSetCursorFocus = true;
		DWORD Delay = (CurrentTick - this->Data[eCAMERA_BUTTON2].EventTick);
		// ----
		if(Event == WM_LBUTTONDOWN)
		{
			this->Data[eCAMERA_BUTTON2].OnClick = true;
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON2].OnClick = false;
		// ----
		if(Delay < 500)
		{
			return;
		}
		// ----
		this->Data[eCAMERA_BUTTON2].EventTick = GetTickCount();
		// ----
		gCamera.ResetZoom();
	}
	else
	{
		pSetCursorFocus = false;
	}
}

void cInterface::DrawHPMobCheck()
{
	if(gExHP.IsHpm == HealthBarOn)
	{
		if(!this->CheckWindow(Options))
		{
			return;
		}
		// ----
		float PosX = 375.0f;
		float PosY = 156.0f;
		// ----
		if(gExHP.HPMobEnabled == true) // -> Switcher
		{
			this->DrawGUI(eHPMOB_CHECKED,PosX,PosY,this->Data[eHPMOB_CHECKED].Width,this->Data[eHPMOB_CHECKED].Height);
			this->DrawFormat(eWhite,(int)PosX-71,(int)PosY+6,150,1,"Health Bar:");
			this->DrawFormat(eShinyGreen,(int)PosX-28,(int)PosY+6,150,1,"Enabled");
		}
		else
		{
			this->DrawGUI(eHPMOB_UNCHECKED,PosX,PosY,this->Data[eHPMOB_UNCHECKED].Width,this->Data[eHPMOB_UNCHECKED].Height);
			this->DrawFormat(eWhite,(int)PosX-71,(int)PosY+6,150,1,"Health Bar:");
			this->DrawFormat(eRed,(int)PosX-28,(int)PosY+6,150,1,"Disabled");
		}
	}
}

void cInterface::EventHPMobCheck(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if(!this->CheckWindow(Options))
	{
		return;
	}

	if(IsWorkZone(eHPMOB_UNCHECKED))
	{
		DWORD Delay = (CurrentTick - this->Data[eHPMOB_UNCHECKED].EventTick);

		if(Event == WM_LBUTTONDOWN)
		{
			this->Data[eHPMOB_UNCHECKED].OnClick = true;
			return;
		}

		this->Data[eHPMOB_UNCHECKED].OnClick = false;

		if (Delay < 500)
		{
			return;
		}

		this->Data[eHPMOB_UNCHECKED].EventTick = GetTickCount();

		gExHP.Switcher();
	}
	else if(IsWorkZone(eHPMOB_CHECKED))
	{
		DWORD Delay = (CurrentTick - this->Data[eHPMOB_CHECKED].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eHPMOB_CHECKED].OnClick = true;
			return;
		}

		this->Data[eHPMOB_CHECKED].OnClick = false;

		if (Delay < 500)
		{
			return;
		}

		this->Data[eHPMOB_CHECKED].EventTick = GetTickCount();

		gExHP.Switcher();
	}
}

/*
void cInterface::DrawChangeFPSCheckBox()
{
	if(!this->CheckWindow(Options))
	{
		return;
	}
	// ----
	float PosX = 375.0f;
	float PosY = 156.0f;
	// ----
	if(gDisplay.FrapsSwitcher == true)
	{
		this->DrawGUI(eCHANGEFPS_CHECKED,PosX,PosY,this->Data[eCHANGEFPS_CHECKED].Width,this->Data[eCHANGEFPS_CHECKED].Height);
		this->DrawFormat(eWhite,(int)PosX-71,(int)PosY+6,150,1,"Game Frap:");
		this->DrawFormat(eShinyGreen,(int)PosX-28,(int)PosY+6,150,1,"Enabled");
	}
	else
	{
		this->DrawGUI(eCHANGEFPS_UNCHECKED,PosX,PosY,this->Data[eCHANGEFPS_UNCHECKED].Width,this->Data[eCHANGEFPS_UNCHECKED].Height);
		this->DrawFormat(eWhite,(int)PosX-71,(int)PosY+6,150,1,"Game Frap:");
		this->DrawFormat(eRed,(int)PosX-28,(int)PosY+6,150,1,"Disabled");
	}
}
*/

/*
void cInterface::EventChangeFPSCheckBox(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->CheckWindow(Options))
	{
		return;
	}

	if (IsWorkZone(eCHANGEFPS_UNCHECKED))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGEFPS_UNCHECKED].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGEFPS_UNCHECKED].OnClick = true;
			return;
		}

		this->Data[eCHANGEFPS_UNCHECKED].OnClick = false;

		if (Delay < 500)
		{
			return;
		}

		this->Data[eCHANGEFPS_UNCHECKED].EventTick = GetTickCount();

		gDisplay.SwitchFrapsState();
	}
	else if (IsWorkZone(eCHANGEFPS_CHECKED))
	{
		DWORD Delay = (CurrentTick - this->Data[eCHANGEFPS_CHECKED].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eCHANGEFPS_CHECKED].OnClick = true;
			return;
		}

		this->Data[eCHANGEFPS_CHECKED].OnClick = false;

		if (Delay < 500)
		{
			return;
		}

		this->Data[eCHANGEFPS_CHECKED].EventTick = GetTickCount();

		gDisplay.SwitchFrapsState();
	}
}
*/

void cInterface::DrawGlowTronButton()
{
	if(IsGlt == GlowTronOn)
	{
		if(!this->CheckWindow(Options))
		{
			return;
		}
		// ----
		float PosX = 375.0f;
		float PosY = 220.0f;
		// ----
		if(gGlowTron.Enabled == true)
		{
			this->DrawGUI(eGLOWTRON_CHECKED,PosX,PosY,this->Data[eGLOWTRON_CHECKED].Width,this->Data[eGLOWTRON_CHECKED].Height);
			this->DrawFormat(eWhite,(int)PosX-72,(int)PosY+4,150,1,"Glow Tron:");
			this->DrawFormat(eShinyGreen,(int)PosX-30,(int)PosY+4,150,1,"Enabled");
		}
		else
		{
			this->DrawGUI(eGLOWTRON_UNCHECKED,PosX,PosY,this->Data[eGLOWTRON_UNCHECKED].Width,this->Data[eGLOWTRON_UNCHECKED].Height);
			this->DrawFormat(eWhite,(int)PosX-72,(int)PosY+4,150,1,"Glow Tron:");
			this->DrawFormat(eRed,(int)PosX-30,(int)PosY+4,150,1,"Disabled");
		}
	}
}

void cInterface::EventGlowTronButton(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->CheckWindow(Options))
	{
		return;
	}

	if (IsWorkZone(eGLOWTRON_UNCHECKED))
	{
		DWORD Delay = (CurrentTick - this->Data[eGLOWTRON_UNCHECKED].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGLOWTRON_UNCHECKED].OnClick = true;
			return;
		}

		this->Data[eGLOWTRON_UNCHECKED].OnClick = false;

		if (Delay < 500)
		{
			return;
		}

		this->Data[eGLOWTRON_UNCHECKED].EventTick = GetTickCount();

		gGlowTron.SwitchState();
	}
	else if(IsWorkZone(eGLOWTRON_CHECKED))
	{
		DWORD Delay = (CurrentTick - this->Data[eGLOWTRON_CHECKED].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eGLOWTRON_CHECKED].OnClick = true;
			return;
		}

		this->Data[eGLOWTRON_CHECKED].OnClick = false;

		if (Delay < 500)
		{
			return;
		}

		this->Data[eGLOWTRON_CHECKED].EventTick = GetTickCount();

		gGlowTron.SwitchState();
	}
}

/*
void cInterface::DrawAntialisingInterface()
{
	if(!this->CheckWindow(Options))
	{
		return;
	}
	// ----
	float BoxPosX = 375.0f;
	float BoxPosY = 290.0f;
	// ----
	float PlusPosX = 354.0f;
	float PlusPosY = 284.0f;
	// ----
	float MinusPosX = 354.0f;
	float MinusPosY = 300.0f;
	// ----
	this->DrawFormat(eWhite,(int)BoxPosX-4,(int)BoxPosY-10,150,1,"Antialising:");
	// ----
	this->DrawGUI(eANTIALISING_BOX,BoxPosX,BoxPosY,this->Data[eANTIALISING_BOX].Width,this->Data[eANTIALISING_BOX].Height);
	this->DrawGUI(eANTIALISING_PLUS,PlusPosX,PlusPosY,this->Data[eANTIALISING_PLUS].Width,this->Data[eANTIALISING_PLUS].Height);
	this->DrawGUI(eANTIALISING_MINUS,MinusPosX,MinusPosY,this->Data[eANTIALISING_MINUS].Width,this->Data[eANTIALISING_MINUS].Height);
	// ----
	if(IsWorkZone(eANTIALISING_PLUS))
	{
		if (this->Data[eANTIALISING_PLUS].OnClick)
		{
			this->DrawColoredGUI(eANTIALISING_PLUS,PlusPosX,PlusPosY,this->Data[eANTIALISING_PLUS].Width,this->Data[eANTIALISING_PLUS].Height,0.0f,0.0f,pMakeColor(40,20,3,130));
			return;
		}
		this->DrawColoredGUI(eANTIALISING_PLUS,PlusPosX,PlusPosY,this->Data[eANTIALISING_PLUS].Width,this->Data[eANTIALISING_PLUS].Height,0.0f,0.0f,pMakeColor(20,204,20,200));
	}
	else if(IsWorkZone(eANTIALISING_MINUS))
	{
		if (this->Data[eANTIALISING_MINUS].OnClick)
		{
			this->DrawColoredGUI(eANTIALISING_MINUS,MinusPosX,MinusPosY,this->Data[eANTIALISING_MINUS].Width,this->Data[eANTIALISING_MINUS].Height,0.0f,0.0f,pMakeColor(40,20,3,130));
			return;
		}
		this->DrawColoredGUI(eANTIALISING_MINUS,MinusPosX,MinusPosY,this->Data[eANTIALISING_MINUS].Width,this->Data[eANTIALISING_MINUS].Height,0.0f,0.0f,pMakeColor(204,20,20,200));
	}
	// ----
	switch(gDisplay.Counter)
	{
		case 1:
		{
			this->DrawGUI(eANTIALISING_X2,BoxPosX+1,BoxPosY,this->Data[eANTIALISING_X2].Width,this->Data[eANTIALISING_X2].Height);
		}
		break;
		// ----
		case 2:
		{
			this->DrawGUI(eANTIALISING_X4,BoxPosX+1,BoxPosY,this->Data[eANTIALISING_X4].Width,this->Data[eANTIALISING_X4].Height);
		}
		break;
		// ----
		case 3:
		{
			this->DrawGUI(eANTIALISING_X6,BoxPosX+1,BoxPosY,this->Data[eANTIALISING_X6].Width,this->Data[eANTIALISING_X6].Height);
		}
		break;
		// ----
		case 4:
		{
			this->DrawGUI(eANTIALISING_X8,BoxPosX+1,BoxPosY,this->Data[eANTIALISING_X8].Width,this->Data[eANTIALISING_X8].Height);
		}
		break;
	}
}
*/

/*
void cInterface::EventAntialisingInterface(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();

	if (!this->CheckWindow(Options))
	{
		return;
	}

	if (IsWorkZone(eANTIALISING_PLUS))
	{
		DWORD Delay = (CurrentTick - this->Data[eANTIALISING_PLUS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eANTIALISING_PLUS].OnClick = true;
			return;
		}

		this->Data[eANTIALISING_PLUS].OnClick = false;

		if (Delay < 500)
		{
			return;
		}

		this->Data[eANTIALISING_PLUS].EventTick = GetTickCount();

		gDisplay.Counter = gDisplay.Counter++;
		// ----
		if (gDisplay.Counter > 4)
		{
			gDisplay.Counter = 4;
		}
	}
	else if (IsWorkZone(eANTIALISING_MINUS))
	{
		DWORD Delay = (CurrentTick - this->Data[eANTIALISING_MINUS].EventTick);

		if (Event == WM_LBUTTONDOWN)
		{
			this->Data[eANTIALISING_MINUS].OnClick = true;
			return;
		}

		this->Data[eANTIALISING_MINUS].OnClick = false;

		if (Delay < 500)
		{
			return;
		}

		this->Data[eANTIALISING_MINUS].EventTick = GetTickCount();

		gDisplay.Counter = gDisplay.Counter--;
		// ----
		if (gDisplay.Counter < 1)
		{
			gDisplay.Counter = 1;
		}
	}
}
*/

void cInterface::ChatHandler(char *Command)
{
	if(!strcmp(Command,"/glowtron"))
	{
		gGlowTron.SwitchState();
	}
	/*else if(!strcmp(Command,"/gamefrap"))
	{
		gDisplay.SwitchFrapsState();
	}
	else if(!strcmp(Command,"/antiplus"))
	{
		gDisplay.Counter = gDisplay.Counter++;
		// ----
		if(gDisplay.Counter > 4)
		{
			gDisplay.Counter = 4;
		}
	}
	else if(!strcmp(Command,"/antiminus"))
	{
		gDisplay.Counter = gDisplay.Counter--;
		// ----
		if(gDisplay.Counter < 1)
		{
			gDisplay.Counter = 1;
		}
	}*/
	else if(!strcmp(Command,"/help"))
	{
		gInterface.UserHelpState();
		gLoadSound.LoadInterfaceWindowTick();
		gPlaySound.PlayInterfaceWindowTick();
	}
	else if(!strcmp(Command,"/clearinven"))
	{
		gLoadSound.LoadClearCommandSoundGM();
		gPlaySound.PlayClearCommandSoundGM();
	}
	else if(!strcmp(Command,"/packlevel"))
	{
		gLoadSound.LoadMixsJewelsPackSound();
		gPlaySound.PlayMixsJewelsPackSound();
	}
	else if(!strcmp(Command,"/packlevel20"))
	{
		gLoadSound.LoadMixsJewelsPackSound();
		gPlaySound.PlayMixsJewelsPackSound();
	}
	else if(!strcmp(Command,"/packluck"))
	{
		gLoadSound.LoadMixsJewelsPackSound();
		gPlaySound.PlayMixsJewelsPackSound();
	}
	else if(!strcmp(Command,"/packskill"))
	{
		gLoadSound.LoadMixsJewelsPackSound();
		gPlaySound.PlayMixsJewelsPackSound();
	}
	else if(!strcmp(Command,"/packoption"))
	{
		gLoadSound.LoadMixsJewelsPackSound();
		gPlaySound.PlayMixsJewelsPackSound();
	}
	else if(!strcmp(Command,"/packexcellent"))
	{
		gLoadSound.LoadMixsJewelsPackSound();
		gPlaySound.PlayMixsJewelsPackSound();
	}
	else if(!strcmp(Command,"/packancient"))
	{
		gLoadSound.LoadMixsJewelsPackSound();
		gPlaySound.PlayMixsJewelsPackSound();
	}
	else if(!strcmp(Command,"/packsocket"))
	{
		gLoadSound.LoadMixsJewelsPackSound();
		gPlaySound.PlayMixsJewelsPackSound();
	}
	else if(!strcmp(Command,"/setzen"))
	{
		gLoadSound.LoadGetItemOnZenCommand();
		gPlaySound.PlayGetItemOnZenCommand();
	}
	// ----
	pChatHandler(Command);
}

bool g_bUserHelpSwitcher = false;

void cInterface::UserHelpState()
{
	if(pPlayerState == GameProcess)
	{
		if(g_bUserHelpSwitcher)
		{
			gLoadSound.LoadInterfaceWindowTick();
			gPlaySound.PlayInterfaceWindowTick();
			g_bUserHelpSwitcher = false;
		}
		else
		{
			gLoadSound.LoadInterfaceWindowTick();
			gPlaySound.PlayInterfaceWindowTick();
			g_bUserHelpSwitcher = true;
		}
	}
}

void cInterface::DrawUserHelp()
{
	if(g_bUserHelpSwitcher == true)
	{
		this->DrawFormat(eRed,MAX_WIN_WIDTH/3,MAX_WIN_HEIGHT/2,400,1,"Engine User Help:");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+10,400,1,"Commands:");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+20,400,1,"/packluck - Pack (10) Jewel of Luck");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+30,400,1,"/unpackluck - Unpack (1) Bundled Jewel of Luck");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+40,400,1,"/packskill - Pack (10) Jewel of Skill");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+50,400,1,"/unpackskill - Unpack (1) Bundled Jewel of Skill");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+60,400,1,"/packoption - Pack (10) Jewel of Option");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+70,400,1,"/unpackoption - Unpack (1) Bundled Jewel of Option");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+80,400,1,"/packexcellent - Pack (10) Jewel of Excellent");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+90,400,1,"/unpackexcellent - Unpack (1) Bundled Jewel of Excellent");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+100,400,1,"/packancient - Pack (10) Jewel of Ancient");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+110,400,1,"/unpackancient - Unpack (1) Bundled Jewel of Ancient");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+120,400,1,"/packsocket - Pack (10) Jewel of Socket");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+130,400,1,"/unpacksocket - Unpack (1) Bundled Jewel of Socket");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+140,400,1,"/packlevel - Pack (10) Jewel of Level");
		this->DrawFormat(eGold,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+150,400,1,"/unpacklevel - Unpack (1) Bundled Jewel of Level");
		this->DrawFormat(eRed,MAX_WIN_WIDTH/3,(MAX_WIN_HEIGHT/2)+160,400,1,"Open/Close this Window: /help");
	}
	else
	{
		return;
	}
}

void cInterface::Load()
{
	this->BindObject(eCAMERA_MAIN,0x7883,200.0f,17.0f,50.0f,0.0f);
	this->BindObject(eCAMERA_BUTTON1,0x7881,16.0f,12.0f,175.5f,1.0f);
	this->BindObject(eCAMERA_BUTTON2,0x7882,16.0f,12.0f,192.5f,1.0f);
	// ----
	if(UseClockMod == TimeOn)
	{
		if(gScriptEncode.ReadScript(CLOCK_FILE))
		{
			WZSMDToken Token = gScriptEncode.GetToken();
			// ----
			Token = gScriptEncode.GetToken();
			this->IsClk = gScriptEncode.GetNumber();
			// ----
			if(this->IsClk == TimeOn)
			{
				this->BindObject(eTIME,0x787E,131.0f,39.0f,-10.0f,359.0f);
			}
			// ----
			gScriptEncode.Close();
		}
		else
		{
			MessageBox(NULL,"ClockMod.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
	this->BindObject(eGLOWTRON_UNCHECKED,0x7890,15.0f,15.0f,375.0f,220.0f);
	this->BindObject(eGLOWTRON_CHECKED,0x7891,15.0f,15.0f,375.0f,220.0f);
	this->BindObject(eHPMOB_UNCHECKED,0x787F,15.0f,15.0f,375.0f,156.0f);
	this->BindObject(eHPMOB_CHECKED,0x7880,15.0f,15.0f,375.0f,156.0f);
	/*
	this->BindObject(eANTIALISING_BOX,0x7892,20.0f,20.0f,375.0f,290.0f);
	this->BindObject(eANTIALISING_PLUS,0x7893,12.0f,12.0f,354.0f,284.0f);
	this->BindObject(eANTIALISING_MINUS,0x7894,12.0f,12.0f,354.0f,300.0f);
	this->BindObject(eANTIALISING_X2,0x7895,18.0f,18.0f,375.0f,290.0f);
	this->BindObject(eANTIALISING_X4,0x7896,18.0f,18.0f,375.0f,290.0f);
	this->BindObject(eANTIALISING_X6,0x7897,18.0f,18.0f,375.0f,290.0f);
	this->BindObject(eANTIALISING_X8,0x7898,18.0f,18.0f,375.0f,290.0f);
	this->BindObject(eCHANGEFPS_UNCHECKED,0x7899,15.0f,15.0f,375.0f,156.0f);
	this->BindObject(eCHANGEFPS_CHECKED,0x789A,15.0f,15.0f,375.0f,156.0f);
	*/
	// ----
	gToolKit.SetOp((LPVOID)oDrawInterface_Call,this->Work,ASM::CALL);
	gToolKit.SetOp((LPVOID)oLoadSomeForm_Call,this->LoadImages,ASM::CALL);
	gToolKit.SetOp((LPVOID)oChatHandler01_Call,this->ChatHandler,ASM::CALL);
	gToolKit.SetOp((LPVOID)oChatHandler02_Call,this->ChatHandler,ASM::CALL);
	gToolKit.SetOp((LPVOID)oChatHandler03_Call,this->ChatHandler,ASM::CALL);
	gToolKit.SetOp((LPVOID)oChatHanlder04_Call,this->ChatHandler,ASM::CALL);
}

void cInterface::Work()
{
	if(gInterface.EnabledClock == TRUE)
	{
		gInterface.DrawTime();
	}
	// ----
	gInterface.DrawCameraUI();
	gInterface.DrawButtonText();
	gInterface.DrawGlowTronButton();
	gInterface.DrawHPMobCheck();
	//gInterface.DrawChangeFPSCheckBox();
	//gInterface.DrawAntialisingInterface();
	gInterface.DrawUserHelp();
	// ----
	pDrawInterface();
}