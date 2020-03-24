#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOCOMM
#define _WIN32_WINNT 0x0502

#include <windows.h>
#include <iostream>
#include <map>
#include <atltime.h>
#include <sqlext.h>
#include <vector>
#include <DbgHelp.h>
#include <Commctrl.h>

#include "CougarEMU.h"
#include "LogProc.h"
#include "TServerInfoDisplayer.h"
#include "Defines.h"
#include "Settings.h"
#include "DataBase.h"
#include "IOCP.h"
#include "Structure.h"
#include "Functions.h"
#include "resource.h"
#include "Exception.h"
#include "prodef.h"
#include "Serial.h"

#define SEASON					4		// Switch Season (4,5,6)
#define ZEONWINDOW				1		// Change Window Visual Style
#define FIX_MAXSTAT				1		// Fix Character Max Stat (Visual Bug)
#define USE_RESETSYS			1		// Use Reset & GrandReset System (On/Off)
#define USE_ANTIHACK			1		// Use Anti-Hack System on DataServer (On/Off)
#define LINKSERVER_WIDTH		750		// Width of window
#define LINKSERVER_HEIGHT		600		// Height of window

#if(SEASON > 5)
#define INVERTORY_SIZE 3776
#define MAGICLIST_SIZE 450
#else
#define INVERTORY_SIZE 1728
#define MAGICLIST_SIZE 180
#endif

#include "JoinServer_Manager.h"
#include "JoinServer_Protocol.h"
#include "WzUpdSocket.h"
#include "EventServer_Manager.h"
#include "EventServer_Protocol.h"
#include "RankingServer_Manager.h"
#include "RankingServer_Protocol.h"
#include "DataServer_Manager.h"
#include "DataServer_Protocol.h"