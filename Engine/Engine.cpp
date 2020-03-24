#include "StdAfx.h"
#include "Engine.h"
#include "Graphics.h"
#include "FogEffect.h"


BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{


	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		DWORD OldProtect;
		// ----
		VirtualProtect(LPVOID(0x401000), VIRTUAL_PROTECT_OFFSET, PAGE_EXECUTE_READWRITE, &OldProtect);
		{
			//*(BYTE*)(0x006020BF+2) = 0x1F;
			//*(BYTE*)(0x006020C8+2) = 0x1F;
			// ----
			gControl.hModule = hModule;
			// ----
			gProtocol.Load();
			gInterface.Load();
			gConnection.Load();
			gControl.Load();
			// ----
			gUser.Load();
			gExHP.Load();
			gMaps.Load();
			gFont.Load();
			gGlow.Load();
			gPets.Load();
			gBags.Load();
			gBows.Load();
			gItem.Load();
			gPoint.Load();
			gFixes.Load();
			gWings.Load();
			gSmoke.Load();
			gEffect.Load();
			gLoader.Load();
			gJewels.Load();
			gSkills.Load();
			gSkyBox.Load();
			gDamage.Load();
			gMonster.Load();
			gDisplay.Load();
			gToolTip.Load();
			gBundles.Load();
			gMiniMap.Load();
			gComplete.Load();
			gLauncher.Load();
			gWinTitle.Load();
			gGraphics.Load();
			gVisualFix.Load();
			gCharacter.Load();
			gItemLevel.Load();
			gDrawFrame.Load();
			gFogEffect.Load();
			gItemSocket.Load();
			// ----
			//gPreview.Load();
		}
	}
	break;
	}

	return TRUE;
}