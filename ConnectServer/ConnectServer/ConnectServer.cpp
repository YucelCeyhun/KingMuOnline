// ConnectServer.cpp: define el punto de entrada de la aplicaci�n.
//

#include "stdafx.h"
#include "ConnectServer.h"
#include "iocp.h"
#include "Obj.h"
#include "Log.h"
#include "Protocol.h"
#include "ServerManager.h"
#include "UDPProtocol.h"


#define MAX_LOADSTRING 100

// Variables globales:
HWND ghWnd;
HINSTANCE hInst;								// Instancia actual
TCHAR szTitle[MAX_LOADSTRING];					// Texto de la barra de t�tulo
TCHAR szWindowClass[MAX_LOADSTRING];			// nombre de clase de la ventana principal

// Declaraciones de funciones adelantadas incluidas en este m�dulo de c�digo:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

void UpdateInstanceWindowTitle() 
{
	char sWindowTitle[1024]={0};
	wsprintf(sWindowTitle,"ConnectServer Port: %d - %s - Compiled Date: %s", g_ServerPort,CS_CURRENT_VERSION, CS_CURRENT_EDITION);
	SetWindowText(ghWnd,sWindowTitle);
}

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine,int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: colocar c�digo aqu�.
	MSG msg;
	HACCEL hAccelTable;

	// Inicializar cadenas globales
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CONNECTSERVER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Realizar la inicializaci�n de la aplicaci�n:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CONNECTSERVER));
	
	gLogOutType = GetPrivateProfileInt("General", "GenerateLogs",0,CONFIGFILE ) ;
	LogInit(TRUE);
	LogAddC(4,"Initializing...");
	serverManager.Init();
	LogDateChange();
	SendMessage(ghWnd, WM_TIMER, WM_LOG_PAINT, NULL);
	OBJInit();
	UDPInit();
	iocpInit();
	//
	UpdateInstanceWindowTitle();

	// Bucle principal de mensajes:
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
//  FUNCI�N: MyRegisterClass()
//
//  PROP�SITO: registrar la clase de ventana.
//
//  COMENTARIOS:
//
//    Esta funci�n y su uso son s�lo necesarios si desea que el c�digo
//    sea compatible con sistemas Win32 anteriores a la funci�n
//    'RegisterClassEx' que se agreg� a Windows 95. Es importante llamar a esta funci�n
//    para que la aplicaci�n obtenga iconos peque�os bien formados
//    asociados a ella.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CONNECTSERVER));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_CONNECTSERVER);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCI�N: InitInstance(HINSTANCE, int)
//
//   PROP�SITO: guardar el identificador de instancia y crear la ventana principal
//
//   COMENTARIOS:
//
//        En esta funci�n, se guarda el identificador de instancia en una variable com�n y
//        se crea y muestra la ventana principal del programa.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Almacenar identificador de instancia en una variable global

   ghWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!ghWnd)
   {
      return FALSE;
   }

   ShowWindow(ghWnd, nCmdShow);
   UpdateWindow(ghWnd);
   SetTimer(ghWnd, WM_LOG_PAINT,1500, NULL);
   SetTimer(ghWnd, WM_LOG_DATE_CHANGE, 60000, NULL);
   SetTimer(ghWnd, WM_SECONDPROC, 1000, NULL);

   return TRUE;
}

//
//  FUNCI�N: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PROP�SITO: procesar mensajes de la ventana principal.
//
//  WM_COMMAND	: procesar el men� de aplicaci�n
//  WM_PAINT	: pintar la ventana principal
//  WM_DESTROY	: enviar un mensaje de finalizaci�n y volver
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Analizar las selecciones de men�:
		switch (wmId)
		{
		case IDM_BLIST:
				serverManager.ReadBlackList(BLISTFILE);
			break;
		case IDM_SLIST:
				serverManager.ReadList(SLISTFILE);
			break;
		case IDM_ULIST:
				serverManager.ReadUpdateConfig();
			break;

		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
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

						//g_ServerInfoDisplayer.Run(hWnd);
					}
					break;
				case WM_LOG_DATE_CHANGE:
					LogDateChange();
					break;
				case WM_SECONDPROC:
				{
					OBJSecondProc();
				}break;
			}
		break;
	//case WM_PAINT:
	//	hdc = BeginPaint(hWnd, &ps);
	//	// TODO: agregar c�digo de dibujo aqu�...
	//	EndPaint(hWnd, &ps);
	//	break;
	case WM_DESTROY:
		DestroyIocp();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Controlador de mensajes del cuadro Acerca de.
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
