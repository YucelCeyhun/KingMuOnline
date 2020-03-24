#ifndef __STDAFX_H__
#define __STDAFX_H__

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x501
#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable:4060)
#pragma warning(disable:4091)
#pragma warning(disable:4129)
#pragma warning(disable:4244)
#pragma warning(disable:4309)
#pragma warning(disable:4482)
#pragma warning(disable:4804)
#pragma warning(disable:4838)
#pragma warning(disable:4996)

using namespace std;

#define USING_MFC_LIB_20170302

#ifdef USING_MFC_LIB_20170302
#include <afx.h>
#else
#include <windows.h>
#endif
#include <mmsystem.h>
#include <WinSock.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <malloc.h>
#include <process.h>
#include <vector>
#include <time.h>
#include <GL/cg.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glaux.h>
#include <GL/glext.h>
#include "Cg/cg.h"
#include "Cg/cgGL.h"

#pragma comment(lib,"Detours.lib")
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glaux.lib")
#pragma comment(lib,"Ws2_32.lib")

#include "LoadSound.h"
#include "PlaySound.h"

#include "Detours.h"
#include "Display.h"
//#include "Graphics.h"
#include "GlowTron.h"

#include "ProtoDef.h"
#include "Splash.h"
#include "Defines.h"
#include "Structs.h"
#include "Fixes.h"

#include "Mobs.h"
#include "Maps.h"
#include "User.h"
#include "Bags.h"
#include "Pets.h"
#include "Reset.h"
#include "Wings.h"
#include "Jewels.h"
#include "Bundles.h"
//#include "Preview.h"
#include "Protocol.h"
#include "Control.h"
#include "Camera.h"
#include "Enums.h"
#include "Monster.h"
#include "ReadScript.h"
#include "ScriptEncode.h"
#include "zzzMathLib.h"
#include "ItemSocket.h"
#include "Import.h"

#include "Complete.h"

#include "BMD.h"
#include "ExHP.h"
#include "Bows.h"
#include "Item.h"
#include "Glow.h"
#include "Font.h"
#include "Smoke.h"
#include "Effect.h"
#include "Engine.h"
#include "SkyBox.h"
#include "Damage.h"
#include "Skills.h"
#include "ToolTip.h"
#include "ToolKit.h"
#include "Launcher.h"
#include "WinTitle.h"
#include "ItemLevel.h"
#include "DrawFrame.h"
#include "Character.h"
#include "Connection.h"
#include "Interface.h"
#include "MiniMap.h"
#include "Loader.h"
#include "Point.h"

#include "VisualFix.h"

#define ENGINE_INI		".\\Engine.ini"
#define LAUNCH_FILE		".\\Data\\Custom\\Local\\LaunchGame.bmd"
#define TITLE_FILE		".\\Data\\Custom\\Local\\WinTitle.bmd"
#define FONT_FILE		".\\Data\\Custom\\Local\\FontText.bmd"
#define GLOW_FILE		".\\Data\\Custom\\Local\\ItemGlow.bmd"
#define SMOKE_FILE		".\\Data\\Custom\\Local\\ItemSmoke.bmd"
#define POINT_FILE		".\\Data\\Custom\\Local\\ItemPoint.bmd"
#define FLOOR_FILE		".\\Data\\Custom\\Local\\ItemFloor.bmd"
#define SOCKET_FILE		".\\Data\\Custom\\Local\\ItemSocket.bmd"
#define COMMON_FILE		".\\Data\\Custom\\Local\\Common.bmd"
#define ITEM_FILE		".\\Data\\Custom\\Local\\ItemColor.bmd"
#define SERVERLIST_FILE	".\\Data\\Custom\\Local\\ServerList.bmd"
#define MONSTER_FILE	".\\Data\\Custom\\Local\\MonsterLoad.bmd"

#define MOBSLOAD_FILE	".\\Data\\Custom\\Local\\MobsLoad.bmd"
#define MOBSPARAM_FILE	".\\Data\\Custom\\Local\\MobsParam.bmd"

#define CLOCK_FILE		".\\Data\\Custom\\Local\\ClockMod.bmd"
#define HPMOB_FILE		".\\Data\\Custom\\Local\\HealthMob.bmd"
#define GLOWTRON_FILE	".\\Data\\Custom\\Local\\GlowTron.bmd"
#define SIEGE_FILE		".\\Data\\Custom\\Local\\SiegeSkill.bmd"
#define PLUGIN_FILE		".\\Data\\Custom\\Local\\PluginLoad.bmd"

#define SPLASH_FILE		".\\Data\\Custom\\Logo\\Logo_Back.bmp"

//#define LICENSE_FILE	".\\Data\\Custom\\Local\\Connect.bmd"

#define SCRIPT_ENCODE	1

#if(SCRIPT_ENCODE == 0)
#define USE_ZTEAM_ENCODE
#endif

#if(SCRIPT_ENCODE >= 1)
#define USE_MYENCODE_100716
#endif

#define Naked				__declspec(naked)
#define ItemId(x, y)		((x * 512) + y)
#define ObjectId(x, y)		((x * 512) + y + 834)

#endif