#pragma once
#include "resource.h"

extern HFONT uFont;
extern HWND ghWnd;
#define	WM_LOG_PAINT	(0x101)
#define WM_LOG_DATE_CHANGE	(0x102)

//extern int MAX_SERVEROBJECT;
extern WORD g_JoinServerListPort;
extern WORD g_ExDataServerListPort;
extern WORD g_CashShopServerListPort;

//SQL
extern BOOL g_UseMD5;
extern TCHAR g_UserID[64];
extern TCHAR g_Password[64];
extern TCHAR g_MeMuOnlineDNS[64];
extern TCHAR g_MuOnlineDNS[64];
extern BOOL g_QueryLog;

extern TCHAR g_UserID[64];
extern TCHAR g_Password[64];

bool InitnExtraServer();

BOOL CALLBACK JSDisconnect (HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);