// ExteriorServer.cpp : Defines the entry point for the application.
#include "StdAfx.h"

#define MAX_LOADSTRING 100
HFONT uFont;
// Global Variables:
HINSTANCE hInst;								// current instance
HWND ghWnd;
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

TCHAR g_MeMuOnlineDNS[64];
TCHAR g_MuOnlineDNS[64];
TCHAR g_UserID[64];
TCHAR g_Password[64];

BOOL g_QueryLog;

WORD g_JoinServerListPort		= GetPrivateProfileInt("ExteriorServer", "JoinServerPort", 55970, nConfig);
WORD g_ExDataServerListPort		= GetPrivateProfileInt("ExteriorServer", "GuildServerPort", 55906, nConfig);
WORD g_CashShopServerListPort	= GetPrivateProfileInt("ExteriorServer", "ShopServerPort", 55821, nConfig);
BOOL g_UseMD5					= GetPrivateProfileInt("SQL", "UseMD5Encrypt", 1, nConfig);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	//UNREFERENCED_PARAMETER(hPrevInstance);
	//UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_NEXTRASERVER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	InitCommonControls();
	CreateDirectory("LOG", NULL);
	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_NEXTRASERVER);
	LogInit(TRUE);
	LogAddC(2, "Initializing...");
	LogDateChange();
	SendMessage(ghWnd, WM_TIMER, WM_LOG_PAINT, NULL);
	gObjServerInit();
	IocpServerStart();
	InitnExtraServer();
	
	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int) msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_ICON2);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_NEXTRASERVER;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

#if(ZEONWINDOW == 1)
   HWND hWnd = CreateWindowEx(
	   0,
	   szWindowClass,
	   szTitle,
	   WS_OVERLAPPED + WS_CAPTION + WS_SYSMENU + WS_MINIMIZEBOX + WS_VISIBLE,
	   CW_USEDEFAULT, 0, EXTERIORSERVER_WIDTH, EXTERIORSERVER_HEIGHT,
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

   if (!hWnd)
   {
      return FALSE;
   }

   ghWnd = hWnd;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;

	switch (message) 
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam); 
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
			break;
		case ID_JSDC_MENU:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_JSDC_DIALOG), hWnd, (DLGPROC)JSDisconnect);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_RELOAD_CASHSHOPLIST:
			ISSReloadFile();
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_TIMER:
		switch ( wParam )
		{
		case WM_LOG_PAINT:
			{
				RECT rect;
				HDC hdc = GetDC(hWnd);
				GetClientRect(hWnd, &rect);
				FillRect(hdc, &rect, (HBRUSH)GetStockObject(0));
				ReleaseDC(hWnd, hdc);

				if ( LogTextPaint != NULL )
					LogTextPaint(hWnd);

				g_Displayer.Run(hWnd);
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
		if ( MessageBox(NULL, "Are you sure to Close?", "Confirmation", MB_YESNO|MB_ICONQUESTION) == IDYES )
			DestroyWindow(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

bool InitnExtraServer()
{
	SetTimer(ghWnd, WM_LOG_PAINT, 1000, NULL);
	SetTimer(ghWnd, WM_LOG_DATE_CHANGE, 300, NULL);

	GetPrivateProfileString("SQL", "MuOnlineDNS", "MuOnline", g_MuOnlineDNS, sizeof(g_MuOnlineDNS), nConfig);
	GetPrivateProfileString("SQL", "MeMuOnlineDNS", "MuOnline", g_MeMuOnlineDNS, sizeof(g_MeMuOnlineDNS), nConfig);
	GetPrivateProfileString("SQL", "User", "sa", g_UserID, sizeof(g_UserID), nConfig);
	GetPrivateProfileString("SQL", "Pass", "123456", g_Password, sizeof(g_Password), nConfig);

	//JoinServerInit();//for joinserver
	InitExDataServer();//for exdb
	//IGSServerInit();//for CashShop
	SetWindowText(ghWnd,"[1.00.93] ExteriorServer (eX406)");

	return true;
}
// Handler for disconnect box.
BOOL CALLBACK JSDisconnect(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
	case WM_COMMAND:
		{
			switch (LOWORD(wParam)) 
			{
			case IDC_JSDC_BUTTON:
				{
					char szAccount[11];
					int sLen = GetDlgItemText(hWnd,IDC_JSDC_ACCOUNT,szAccount,sizeof(szAccount));
					szAccount[10] = 0;

					if(sLen <= 0 || sLen > sizeof(szAccount))
					{
						LogAddC(2,"[JoinServer] could not read account name");
					}
					else
					{
						if(MuLoginFindUser(szAccount) != -1)
						{
							MuLoginDeleteUser(szAccount);
							LogAddC(3,"[JoinServer] Account(%s) disconnected",szAccount);
						}
						else
						{
							LogAddC(2,"[JoinServer] Account(%s) not found online",szAccount);
						}
					}
				}
				EndDialog(hWnd, 0);
				break;
			}
		}
		return true;
	case WM_CLOSE:
		{
			EndDialog(hWnd, 0);
			return true;
		}
	}
	return false;
}