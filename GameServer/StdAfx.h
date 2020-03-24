#ifndef __STDAFX_H__
#define __STDAFX_H__

#if _MSC_VER > 1000
#pragma once
#endif

#define WIN32_LEAN_AND_MEAN			// Exclude rarely-used stuff from Windows headers
#define _WIN32_WINNT 0x501

#define ZEONWINDOW					// Zeon Custom window mode
#define GAMESERVER_WIDTH		750	// Width of gameserver window
#define GAMESERVER_HEIGHT		600 // Height of gameserver window
#define GS_LIFE_28_UP			1	// Use 28 life addition option
#define FIX_MAXSTAT				1   // Use 65000 Max character stats
#define LOG_INMEDIATLY			0	// Use Inmediatly log system
#define REMOVE_CHECKSUM			1	// Removing CheckSum checking
#define DEBUG_IT				0	// Write debug of Illusion Temple
#define DEBUG_BUFF_EFFECT		0	// Write debug of Buff Effect
#define DEBUG_SUMMONER_SKILL	0	// Write debug of Summoner skills
#define DEBUG_EVENT_COUNTER		0	// Write debug of Event counter
#define USE_M_DRIVE				0	// Test M: drive use
#define TESTSERVER				0	// Test server status
#define USE_HPBAR_MOB			1	// Use Monster HP Bar Custom
#define USE_ITEMDROP_SYSTEM		0	// Use Monster Item Drop Custom
#define USE_MONSTERDROP_SYSTEM	1	// Use Monster Item Drop (SCF) Custom
#define ADD_PET_PANDA			1	// Use Aditional Percent of Exp on Panda Pet
#define ADD_GLADIATOR_GLORY		1	// Use Gladiator Glory Buff Effect (Vulcanus)

#if (USE_MONSTERDROP_SYSTEM == 1)
#define __IS_MONSTERDROP__
#endif

#if (USE_HPBAR_MOB == 1)
#define __IS_HPBAR__
#endif

#if (USE_ITEMDROP_SYSTEM == 1)
#define __IS_ITEMDROP__
#endif

#if (USE_M_DRIVE == 1)
#define FINAL_PATH				"M:\\"
#define COMMONSERVER_PATH		"M:\\commonserver.cfg"
#define CUSTOMSERVER_PATH		"M:\\customserver.cfg"
#define SERVER_INFO_PATH		"..\\data\\Serverinfo.dat"
#else
#define FINAL_PATH				"..\\Data\\"
#define COMMONSERVER_PATH		"..\\Data\\CommonServer.cfg"
#define CUSTOMSERVER_PATH		"..\\Data\\CustomServer.cfg"
#define SERVER_INFO_PATH		"Data\\Serverinfo.dat"
#endif

#ifdef INTERNATIONAL_KOREA	
#define PROTOCOL_MOVE			0xD3
#define PROTOCOL_POSITION		0xDF
#define PROTOCOL_ATTACK			0xD7
#define PROTOCOL_BEATTACK		0x10
#endif

#ifdef INTERNATIONAL_ENGLISH
#define PROTOCOL_MOVE			0xD4
#define PROTOCOL_POSITION		0x11
#define PROTOCOL_ATTACK			0x15
#define PROTOCOL_BEATTACK		0xDB
#endif

#ifdef INTERNATIONAL_JAPAN
#define PROTOCOL_MOVE			0x1D
#define PROTOCOL_POSITION		0xD6
#define PROTOCOL_ATTACK			0xDC
#define PROTOCOL_BEATTACK		0xD7
#endif

#ifdef INTERNATIONAL_CHINA
#define PROTOCOL_MOVE			0xD7
#define PROTOCOL_POSITION		0xDD
#define PROTOCOL_ATTACK			0xD9
#define PROTOCOL_BEATTACK		0x1D
#endif

#ifdef INTERNATIONAL_TAIWAN
#define PROTOCOL_MOVE			0xD6
#define PROTOCOL_POSITION		0xDF
#define PROTOCOL_ATTACK			0xDD
#define PROTOCOL_BEATTACK		0xD2
#endif

#ifdef INTERNATIONAL_VIETNAM
#define PROTOCOL_MOVE			0xD9
#define PROTOCOL_POSITION		0xDC
#define PROTOCOL_ATTACK			0x15
#define PROTOCOL_BEATTACK		0x1D
#endif

#ifdef INTERNATIONAL_PHILIPPINES
#define PROTOCOL_MOVE			0xDD
#define PROTOCOL_POSITION		0xDF
#define PROTOCOL_ATTACK			0xD6
#define PROTOCOL_BEATTACK		0x11
#endif

#include <afxwin.h>
#include <afxext.h>
#include <afxdisp.h>

#include <windows.h>
#include <winbase.h>
#include <winsock2.h>
#include "COMMCTRL.h"

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <time.h>
#include <math.h>
#include <process.h>

#include <map>
#include <string>
#include <ios>

#include <iostream>

#include <algorithm>
#include <vector>
#include <set>

#include "..\common\Msg.h"
#include "..\common\Defines.h"

extern CMsg	lMsg;

#define MSGGET(x,y)	(x*256)+y

#endif
