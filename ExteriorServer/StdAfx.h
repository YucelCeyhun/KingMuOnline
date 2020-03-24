// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#pragma warning ( disable : 4091 4786 4996 4244 4267 4838 4646  )

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#define _WIN32_WINNT		0x501
#define _CRT_SECURE_NO_WARNINGS
#define TRACE_PACKET		0
#define CURRENT_DB_VERSION	3
#define MAX_TYPE_PLAYER		6
#define MAX_NUMBER_MAP		100
#define CHECK_LIMIT(value, limit) (((value)< 0)?FALSE:((value)> limit-1)?FALSE:TRUE)

#define ZEONWINDOW				1	// Change Window Visual Style
#define EXTERIORSERVER_WIDTH	750	// Width of window
#define EXTERIORSERVER_HEIGHT	600 // Height of window

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <queue>
#include <string.h>
using namespace std;

// Windows Header Files:
#include <windows.h>
#include <winsock2.h>
#include <commctrl.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <WinDef.h>

#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"WS2_32.lib")

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

// Local Header Files
#include "prodef.h"
#include "Query.h"
#include "MD5.h"
#include "md5_keyval.h"
#include "Displayer.h"
#include "LogProc.h"
#include "WzUdp.h"
#include "winutil.h"
#include "GIOCP.h"
#include "ServerEngine.h"
#include "ExteriorServer.h"
#include "GuildServer.h"
#include "JoinServer.h"
#include "IGSProtocol.h"
#include "MapServerManager.h"

#define nConfig	".\\ExteriorServer.ini"

// TODO: reference additional headers your program requires here
