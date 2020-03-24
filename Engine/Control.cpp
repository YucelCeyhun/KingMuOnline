#include "StdAfx.h"

cControl gControl;

cControl::cControl()
{
	this->MouseHook = NULL;
	this->KeyboardHook = NULL;
}

cControl::~cControl()
{
	/**/
}

bool cControl::Load()
{
	if (!this->MouseHook)
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, (HOOKPROC)this->MouseProc, gControl.hModule, GetCurrentThreadId());
		// ----
		if (!this->MouseHook)
		{
			return false;
		}
	}
	// ----
	if (!this->KeyboardHook)
	{
		this->KeyboardHook = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)this->KeyboardProc, gControl.hModule, GetCurrentThreadId());
		// ----
		if (!this->KeyboardHook)
		{
			return false;
		}
	}
	// ----
	return true;
}

LRESULT CALLBACK cControl::MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (GetForegroundWindow() != pGameWindow)
	{
		return CallNextHookEx(gControl.MouseHook, nCode, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX* Mouse = (MOUSEHOOKSTRUCTEX*)lParam;
	gCamera.Run(Mouse, wParam);
	// ----
	switch (wParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
	{
		gInterface.EventCameraUI(wParam);
		gInterface.EventGlowTronButton(wParam);
		gInterface.EventHPMobCheck(wParam);
		//gInterface.EventChangeFPSCheckBox(wParam);
		//gInterface.EventAntialisingInterface(wParam);
		break;
	}
	}
	// ----
	return CallNextHookEx(gControl.MouseHook, nCode, wParam, lParam);
}

LRESULT CALLBACK cControl::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (((lParam >> 31) & 1) && (nCode == HC_ACTION) && (pPlayerState == GameProcess))
	{
		switch (wParam)
		{
		case VK_HOME:
		{
			gCamera.SwitchState();
			break;
		}
		case VK_END:
		{
			gLoadSound.LoadInterfaceWindowTick();
			gPlaySound.PlayInterfaceWindowTick();
			gCamera.ResetZoom();
			break;
		}
		case VK_H:
		{
			if (gInterface.WinKeyChecks() == false)
			{
				gInterface.TimeSwitch();
			}
			break;
		}
		case VK_TAB:
		{
			gMiniMap.Toggle();
			break;
		}
		}
	}
	// ----
	return CallNextHookEx(gControl.KeyboardHook, nCode, wParam, lParam);
}