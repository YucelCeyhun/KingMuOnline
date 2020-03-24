#include "StdAfx.h"

cCamera gCamera;

cCamera::cCamera()
{
	this->Enabled = FALSE;

	this->Zoom = *Camera_Zoom;
	this->RotY = *Camera_RotY;
	this->RotZ = *Camera_RotZ;
	this->PosZ = *Camera_PosZ;
	this->ClipX = *Camera_ClipX;
	this->ClipY = *Camera_ClipY;
	this->ClipZ = *Camera_ClipZ;
	this->ClipV = *Camera_ClipV;
	this->ClipU = *Camera_ClipU;
	this->ClipW = *Camera_ClipW;
	this->ClipS = *Camera_ClipS;
	this->ClipT = *Camera_ClipT;
	this->ClipS = *Camera_ClipR;
}

cCamera::~cCamera()
{
	/**/
}

void Motion(void *lpParam)
{
	while(*Camera_PosZ != 150.0f || *Camera_RotZ != -45.0f || *Camera_RotY != -48.5f || *Camera_Zoom != 35.0f)
	{
		gCamera.RestStop = true;
		// ----
		(*Camera_PosZ > 150.0f) ? *Camera_PosZ -= 5.0f : *Camera_PosZ += 5.0f;
		// ----
		if (*Camera_PosZ > 146.0f && *Camera_PosZ < 152.0f)
		{
			*Camera_PosZ = 150.0f;
		}
		// ----
		(*Camera_RotZ > -45.0f) ? *Camera_RotZ -= 1.0f : *Camera_RotZ += 1.0f;
		// ----
		if (*Camera_RotZ > -47.0f && *Camera_RotZ < -43.0f)
		{
			*Camera_RotZ = -45.0f;
		}
		// ----
		(*Camera_RotY > -48.5f) ? *Camera_RotY -= 0.5f : *Camera_RotY += 0.5f;
		// ----
		if (*Camera_RotY > -50.5f && *Camera_RotY < -46.5f)
		{
			*Camera_RotY = -48.5f;
		}
		// ----
		(*Camera_Zoom > 35.0f) ? *Camera_Zoom -= 1.0f : *Camera_Zoom += 1.0f;
		// ----
		if (*Camera_Zoom > 33.0f && *Camera_Zoom < 37.0f)
		{
			*Camera_Zoom = 35.0f;
		}
		// ----
		Sleep(3);
	}
	// ----
	gCamera.RestStop = false;
	// ----
	_endthread();
}

bool cCamera::DevMod()
{
	if(pPlayerState == GameProcess)
	{
		return true;
	}

	return false;
}

void cCamera::SwitchState()
{
	if(pPlayerState == GameProcess)
	{
		gLoadSound.LoadInterfaceWindowTick();
		gPlaySound.PlayInterfaceWindowTick();
		this->Enabled = !this->Enabled;
	}
}

void cCamera::ResetZoom()
{
	if(pPlayerState == GameProcess)
	{
		_beginthread(Motion,0,NULL);
	}
	// ----
	Sleep(3);
	// ----
	if(Sleep == 0)
	{
		*Camera_ClipR = 2250.0f;
		*Camera_ClipS = 330.0f;
		*Camera_ClipT = 1250.0f;
		*Camera_ClipU = 580.0f;
		*Camera_ClipV = 660.0f;
		*Camera_ClipW = 540.0f;
		*Camera_ClipX = 1190.0f;
		*Camera_ClipY = 2400.0f;
		*Camera_ClipZ = 2000.0f;
	}
}

void cCamera::SetClips()
{
	if(pPlayerState == GameProcess)
	{
		*Camera_ClipU = 3580.0f;
		*Camera_ClipV = 3660.0f;//1660;
		*Camera_ClipW = 3540.0f;//1540;
		*Camera_ClipS = 3330.0f;//1330;
		*Camera_ClipT = 3250.0f;
		*Camera_ClipX = 3190.0f;
		*Camera_ClipY = 4400.0f;
		*Camera_ClipZ = 5000.0f;
	}
	else
	{
		*Camera_ClipU = 580.0f;
		*Camera_ClipV = 660.0f;
		*Camera_ClipW = 540.0f;
		*Camera_ClipS = 330.0f;
		*Camera_ClipT = 1250.0f;
		*Camera_ClipX = 1190.0f;
		*Camera_ClipY = 2400.0f;
		*Camera_ClipZ = 3000.0f;
	}
}

bool cCamera::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}

void cCamera::Run(MOUSEHOOKSTRUCTEX*Mouse,WPARAM wParam)
{
	switch(wParam)
	{
		case WM_MBUTTONDOWN:
		{
			if(!gCamera.Enabled) break;

			gCamera.MoveCamera = true;

			break;
		}
		case WM_MBUTTONUP:
		{
			if(!gCamera.Enabled) break;

			gCamera.MoveCamera = false;

			break;
		}
		case WM_MOUSEWHEEL:
		{
			if(gCamera.CheckWindow(ObjWindow::MoveList)) break;
			if(gCamera.CheckWindow(ObjWindow::FriendList)) break;

			if(!gCamera.Enabled) break;

			int direction = Mouse->mouseData;

			if(direction < 0)
			{
				if(*Camera_Zoom < 60)
				{
					*Camera_Zoom += 2;
				}

			}
			else if(direction > 0)
			{
				if(*Camera_Zoom > 12)
				{
					*Camera_Zoom -= 2;
				}
			}
			// ----
			this->SetClips();
			// ----
			break;
		}
		case WM_MOUSEMOVE:
		{
			if (!gCamera.Enabled) break;

			if (gCamera.MoveCamera)
			{
				if (gCamera.MouseX < Mouse->pt.x)
				{
					*Camera_RotZ += 8;

					if (*Camera_RotZ > 315)
					{
						*Camera_RotZ = -45;
					}
				}
				else if (gCamera.MouseX > Mouse->pt.x)
				{
					*Camera_RotZ -= 8;

					if (*Camera_RotZ < -405)
					{
						*Camera_RotZ = -45;
					}
				}
				if (gCamera.MouseY < Mouse->pt.y)
				{
					if (*Camera_RotY < -45)
					{
						*Camera_PosZ -= 44;
						*Camera_RotY += (float)2.42;
					}
				}
				else if (gCamera.MouseY > Mouse->pt.y)
				{
					if (*Camera_RotY > -90)
					{
						*Camera_PosZ += 44;
						*Camera_RotY -= (float)2.42;
					}
				}
				// ----
				gCamera.MouseX = Mouse->pt.x;
				gCamera.MouseY = Mouse->pt.y;
				// ----
				this->SetClips();
				// ----
			}
			break;
		}
	}
}