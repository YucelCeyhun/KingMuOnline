#ifndef __STDAFX_H__
#define __STDAFX_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN
#define USE_NEW_WINDOW_STYLE		1
#define TRACE_PACKET				1	
#define CURRENT_DB_VERSION			3
#define MAX_TYPE_PLAYER				5
#define MAX_NUMBER_MAP				100
#define AIOSERVER_WIDTH				750
#define AIOSERVER_HEIGHT			600
#define CHECK_LIMIT(value,limit)	(((value)< 0)?FALSE:((value)> limit-1)?FALSE:TRUE)

// My Custom Defines
#define AIOSRV_LOG					"AIOServer"
#define CONFIG_INI					".\\Config.ini"

// Windows Header Files
#include <windows.h>
#include <winsock2.h>
#include <commctrl.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>

#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"WS2_32.lib")

#pragma warning(disable:4091)
#pragma warning(disable:4101)
#pragma warning(disable:4244)
#pragma warning(disable:4646)
#pragma warning(disable:4786)
#pragma warning(disable:4996)

// C Runtime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <map>

// Local Header Files
#include "prodef.h"
#include "ServerEngine.h"
#include "eDataServer.h"
#include "Query.h"
#include "Display.h"
#include "MapServerManager.h"

#endif // __STDAFX_H__
