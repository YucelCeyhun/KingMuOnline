// eDataServer.cpp : Defines the entry point for the application.

#include "stdafx.h"
#include "resource.h"
#include "eDataServer.h"
#include "ServerEngine.h"
#include "DSprotocol.h"
#include "Sprotocol.h"
#include "RSprotocol.h"
#include "Eprotocol.h"
#include "LogProc.h"
#include "Giocp.h"
#include "Display.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
HWND ghWnd;
TCHAR szTitle[MAX_LOADSTRING];
TCHAR szWindowClass[MAX_LOADSTRING];
// ----
int g_dwMaxServerGroups				= GetPrivateProfileInt("SETTINGS","MAX_SERVER",10,CONFIG_INI) * MAX_SERVER_TYPE;	
// ----
WORD g_FSGateServerListPort			= GetPrivateProfileInt("SETTINGS","FSGatePort",55909,CONFIG_INI);
WORD g_JoinServerListPort			= GetPrivateProfileInt("SETTINGS","JoinServerPort",55970,CONFIG_INI);
WORD g_ConnectServerListPort		= GetPrivateProfileInt("SETTINGS","ConnectServerPort",44405,CONFIG_INI);
WORD g_DataServer1ListPort			= GetPrivateProfileInt("SETTINGS","DataServer1Port",55960,CONFIG_INI);
WORD g_DataServer2ListPort			= GetPrivateProfileInt("SETTINGS","DataServer2Port",55962,CONFIG_INI);
WORD g_ExDataServerListPort			= GetPrivateProfileInt("SETTINGS","ExDataServerPort",55906,CONFIG_INI);
WORD g_ChatServerListPort			= GetPrivateProfileInt("SETTINGS","ChatServerPort",55980,CONFIG_INI);
WORD g_EventServerListPort			= GetPrivateProfileInt("SETTINGS","EventServerPort",44456,CONFIG_INI);
WORD g_RankingServerListPort		= GetPrivateProfileInt("SETTINGS","RankingServerPort",44455,CONFIG_INI);
WORD g_CashShopServerListPort		= GetPrivateProfileInt("SETTINGS","CashShopServerPort",55821,CONFIG_INI);
// ----
TCHAR g_MuOnlineDNS[64];
TCHAR g_MeMuOnlineDNS[64];
TCHAR g_EventServerDNS[64];
TCHAR g_RankingServerDNS[64];
TCHAR g_UserID[64];
TCHAR g_Password[64];
// ----
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE,int);
LRESULT CALLBACK	WndProc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK	About(HWND,UINT,WPARAM,LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;
	// ----
	LoadString(hInstance,IDS_APP_TITLE,szTitle,MAX_LOADSTRING);
	LoadString(hInstance,IDC_EDATASERVER,szWindowClass,MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	// ----
	if(!InitInstance(hInstance,nCmdShow)) 
	{
		return FALSE;
	}
	// ----
	InitCommonControls();
	CreateDirectory("LOG",NULL);
	hAccelTable = LoadAccelerators(hInstance,(LPCTSTR)IDC_EDATASERVER);
	LogInit(TRUE);
	LogAddC(2,"Initializing...");
	LogDateChange();
	SendMessage(ghWnd,WM_TIMER,WM_LOG_PAINT,NULL);
	gObjServerInit();
	IniteDataServer();
	IocpServerStart();
	// ----
	while(GetMessage(&msg,NULL,0,0)) 
	{
		if(!TranslateAccelerator(msg.hwnd,hAccelTable,&msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	// ----
	return msg.wParam;
}

bool IniteDataServer()
{
	SetTimer(ghWnd,WM_LOG_PAINT,1000,NULL);
	SetTimer(ghWnd,WM_LOG_DATE_CHANGE,300,NULL);
	// ----
	GetPrivateProfileString("SQL","MuOnlineDNS","",g_MuOnlineDNS,sizeof(g_MuOnlineDNS),CONFIG_INI);
	GetPrivateProfileString("SQL","MeMuOnlineDNS","",g_MeMuOnlineDNS,sizeof(g_MeMuOnlineDNS),CONFIG_INI);
	GetPrivateProfileString("SQL","EventDNS","",g_EventServerDNS,sizeof(g_EventServerDNS),CONFIG_INI);
	GetPrivateProfileString("SQL","RankingDNS","",g_RankingServerDNS,sizeof(g_RankingServerDNS),CONFIG_INI);
	GetPrivateProfileString("SQL","User","",g_UserID,sizeof(g_UserID),CONFIG_INI);
	GetPrivateProfileString("SQL","Pass","",g_Password,sizeof(g_Password),CONFIG_INI);
	// ----
	InitMuOnlineDB();
	InitMeMuOnlineDB();
	InitRankingDB();
	InitEventDB();
	// ----
	SetWindowText(ghWnd,"[1.00.93] AIO Server");
	// ----
	return true;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	// ----
	wcex.cbSize = sizeof(WNDCLASSEX); 
	// ----
	wcex.style			= CS_HREDRAW|CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance,(LPCTSTR)IDI_EDATASERVER);
	wcex.hCursor		= LoadCursor(NULL,IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_EDATASERVER;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance,(LPCTSTR)IDI_SMALL);
	// ----
	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
   // ----
   hInst = hInstance;
   // ----
#if(USE_NEW_WINDOW_STYLE == 1)
   hWnd = CreateWindowEx(
	   0,
	   szWindowClass,
	   szTitle,
	   WS_OVERLAPPED + WS_CAPTION + WS_SYSMENU + WS_MINIMIZEBOX + WS_VISIBLE,
	   CW_USEDEFAULT, 0, AIOSERVER_WIDTH, AIOSERVER_HEIGHT,
	   NULL, NULL, hInstance, NULL);
#else
   hWnd = CreateWindowEx(
	   0,
	   szWindowClass,
	   szTitle,
	   WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
	   NULL, NULL, hInstance, NULL);
#endif
   // ----
   if(!hWnd)
   {
      return FALSE;
   }
   // ----
   ghWnd = hWnd;
   // ----
   ShowWindow(hWnd,nCmdShow);
   UpdateWindow(hWnd);
   // ----
   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	int wmId, wmEvent;
	// ----
	switch(message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst,(LPCTSTR)IDD_ABOUTBOX,hWnd,(DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd,message,wParam,lParam);
			}
			break;
		case WM_TIMER:
			switch(wParam)
			{
				case WM_LOG_PAINT:
					{
						RECT rect;
						HDC hdc = GetDC(hWnd);
						GetClientRect(hWnd,&rect);
						FillRect(hdc,&rect,(HBRUSH)GetStockObject(0));
						ReleaseDC(hWnd,hdc);
						// ----
						if(LogTextPaint!=NULL)
							LogTextPaint(hWnd);
						// ----
						gDisplay.Run(hWnd);
					}
					break;
				case WM_LOG_DATE_CHANGE:
					LogDateChange();
					break;
			}
			break;
		case WM_DESTROY:
			DestroyGIocp();
			PostQuitMessage(0);
			break;
		case WM_CLOSE:
			if(MessageBox(NULL,"Are you sure to Close?","Confirmation",MB_YESNO|MB_ICONQUESTION)==IDYES)
				DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd,message,wParam,lParam);
   }
   return 0;
}

LRESULT CALLBACK About(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam)
{
	switch(message)
	{
		case WM_INITDIALOG:
			return TRUE;
		// ----
		case WM_COMMAND:
			if(LOWORD(wParam)==IDOK||LOWORD(wParam)==IDCANCEL) 
			{
				EndDialog(hDlg,LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}




