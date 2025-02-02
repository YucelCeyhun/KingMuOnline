//GameServer 1.00.77 JPN - Completed
#include "stdafx.h"
#include "MonsterHerd.h"
#include "resource.h"
#include "GameServer.h"
#include "Gamemain.h"
#include "Giocp.h"
#include "logproc.h"
#include "GameServerAuth.h"
#include "RingAttackEvent.h"
#include "XMasAttackEvent.h"
#include "CWhatsUpDummyServer.h"
#include "DBSockMng.h"
#include "DSProtocol.h"
#include "EDSProtocol.h"
#include "SProtocol.h"
#include "ChaosCastle.h"
#include "Protocol.h"
#include "AcceptIP.h"
#include "user.h"
#include "closeplayer.h"
#include "MapServerManager.h"
#include "protocol.h"
#include "Shop.h"
#include "Weapon.h"
#include "CastleSiegeSync.h"
#include "BloodCastle.h"
#include "EledoradoEvent.h"
#include "EventManagement.h"
#include "CashShop.h"
#include "TServerInfoDisplayer.h"
#include "TMonsterAI.h"
#include "Kanturu.h"
#include "IllusionTempleEvent.h"
#include "MiniDump.h"
#include "Raklion.h"
#include "Configs.h"
//#include "ResetSystem.h"
#include "BalanceSystem.h"
#include "NewsSystem.h"

#ifdef __IS_ITEMDROP__
#include "ItemDrop.h"
#endif	// __IS_ITEMDROP__

//Customs

char ExDbIp[256];
char DataServerIp2[256];
char DataServerIp[256];
char JoinServerIp[256];
int gServerReady;
int gCloseMsg;
int gCloseMsgTime;
int gCurPaintPlayer;
int gCurPaintType;
int gCurPaintMapNumber;

CRingMonsterHerd g_MonsterHerdTest;
CRingAttackEvent g_RingAttackEvent;
CXMasAttackEvent g_XMasAttackEvent;
CWhatsUpDummyServer gWhatsUpDummyServer;


HINSTANCE hInst;
HWND ghWnd;

char szTitle[100];
char szWindowClass[64];

HWND g_hCsLogDlgProc = NULL;

BOOL GameServerStart(void);
int InitInstance(HINSTANCE, int);
ATOM MyRegisterClass(HINSTANCE);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK About(HWND hInst, UINT message, WPARAM wParam, LPARAM lParam);

HBRUSH hBrushDrakGray;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CMiniDump::Begin();
	MSG msg;
	HACCEL hAccelTable;

	if(gLanguage==0)
	{
		WIN32_FIND_DATA  wfd;
		if (FindFirstFile(COMMONSERVER_PATH,&wfd)==INVALID_HANDLE_VALUE)
		{
			MessageBox(NULL, "Cannot find M:\\ Drive.", "Error", MB_OK|MB_ICONHAND|MB_APPLMODAL);
			return 0; 
		}
		// ----
		/*if (FindFirstFile(CUSTOMSERVER_PATH,&wfd)==INVALID_HANDLE_VALUE)
		{
			MessageBox(NULL, "Cannot find M:\\ Drive.", "Error", MB_OK|MB_ICONHAND|MB_APPLMODAL);
			return 0; 
		}*/
	}

	LoadString(hInstance,IDS_APP_TITLE, szTitle, 100);
	LoadString(hInstance,IDS_GAMESERVER, szWindowClass, 100);

	MyRegisterClass(hInstance);

	InitCommonControls();

	g_Configs.LoadConfigs(); // LOAD CONFIGS
	g_NewsSystem.Load();	 // LOAD NOTICES

	#ifdef __IS_ITEMDROP__
	g_ItemDrop.Load();		 // LOAD ITEMDROP
	#endif
	
	if (!InitInstance(hInstance, nCmdShow))
	{
		return 0;
	}

	ShowWindow(ghWnd, SW_NORMAL);

	hAccelTable=LoadAccelerators(hInstance,(LPCSTR)IDA_GAMESERVER);

	hBrushDrakGray = CreateSolidBrush(RGB(30, 30, 30));
	
	LPSTR	szConfigFilePath = new char[256];

	GameServerPort		= GetPrivateProfileInt("Connection","GameServerPort",55900,CONFIG_FILE);
#if(GS_CASTLE == 1)
	GameServerUdpPort	= GetPrivateProfileInt("Connection","GameServerUdpPort", 60010,CONFIG_FILE);
#else
	GameServerUdpPort	= GetPrivateProfileInt("Connection","GameServerUdpPort", 60005,CONFIG_FILE);
#endif
	JoinServerPort		= GetPrivateProfileInt("Connection","JoinServerPort",55970,CONFIG_FILE);
	DataServerPort		= GetPrivateProfileInt("Connection","DataServerPort",55960,CONFIG_FILE);
	DataServerPort2		= GetPrivateProfileInt("Connection","DataServerPort2",55962,CONFIG_FILE);
	GuildServerPort		= GetPrivateProfileInt("Connection","GuildServerPort",55906,CONFIG_FILE);
	CashShopServerPort	= GetPrivateProfileInt("Connection","CashShopServerPort",55821,CONFIG_FILE);
	RankingServerPort	= GetPrivateProfileInt("Connection","RankingServerPort",44455,CONFIG_FILE);
	EventServerPort		= GetPrivateProfileInt("Connection","EventServerPort",44456,CONFIG_FILE);

	GetPrivateProfileString("Connection","DataServerIP","127.0.0.1", DataServerIp, sizeof(DataServerIp),CONFIG_FILE);
	GetPrivateProfileString("Connection","DataServerIP2","127.0.0.1", DataServerIp2, sizeof(DataServerIp2),CONFIG_FILE);

	GiocpInit();
	GameMainInit(ghWnd);

	gWhatsUpDummyServer.Start(ghWnd, GameServerPort+1);

	AllServerStart();

	while(GetMessage(&msg, NULL, 0, 0) != 0)
	{
		if (!TranslateAccelerator(msg.hwnd,hAccelTable,&msg))
		{
		    TranslateMessage(&msg);
		    DispatchMessage(&msg);
		}
	}

	CMiniDump::End();
	return msg.wParam;
}

BOOL AllServerStart(void){
	
	if (JoinServerConnected==0)
	{
		if (GMJoinServerConnect(JoinServerIp, WM_GM_JOIN_CLIENT_MSG_PROC) == 0)
		{	
			// LoginServer connect fail
			MsgBox(lMsg.Get(MSGGET(1, 144)));
			return 0;
		}
	}

	if ((DevilSquareEventConnect==0) && (IsDevilSquareEventConnected==0))
	{
		if (GMRankingServerConnect(gDevilSquareEventServerIp, WM_GM_RANKING_CLIENT_MSG_PROC) == 0)
		{
			MsgBox("RankingServer");
			return 0;
		}
		IsDevilSquareEventConnected=1;
	}

	if ((EventChipServerConnect!=0) && (IsEventChipServerConnected==0))
	{
		if (GMEventChipServerConnect(gEventChipServerIp, WM_GM_EVENTCHIP_CLIENT_MSG_PROC) == 0)
		{
			MsgBox("EventServer");
			return 0;
		}
		IsEventChipServerConnected=1;
	}

	
	cDBSMng.Connect();
	return TRUE;
}

BOOL GameServerStart(void) 
{
	if (GameMainServerCreate(WM_GM_SERVER_MSG_PROC, WM_GM_CLIENT_MSG_PROC) == FALSE )
	{
		MsgBox(lMsg.Get(MSGGET( 1, 142) ));
		return FALSE;
	}

	CreateGIocp(GameServerPort);

	SetTimer(ghWnd, WM_LOG_PAINT, 2000, NULL);
	SetTimer(ghWnd, WM_FIRST_MSG_PROCESS, 1000, NULL);

	SetTimer(ghWnd, WM_SET_DATE, 60000, NULL);
	SetTimer(ghWnd, WM_LOG_DATE_CHANGE, 60000, NULL);
	SetTimer(ghWnd, WM_CONNECT_DATASERVER, 10000, NULL);


	SetTimer(ghWnd, WM_SECOND_MSG_PROCESS, 1000, NULL);
	SetTimer(ghWnd, WM_GS_CLOSE, 1000, NULL);
	SetTimer(ghWnd, WM_MONSTER_AND_MSG_PROC, 500, NULL);


	SetTimer(ghWnd, WM_MOVE_MONSTER_PROC, 300, NULL);
	SetTimer(ghWnd, WM_EVENT_RUN_PROC, 100, NULL);

	SetTimer(ghWnd, WM_AI_MONSTER_MOVE_PROC, 100, NULL);
	SetTimer(ghWnd, WM_AI_MONSTER_PROC, 1011, NULL);

	SetTimer(ghWnd, WM_GUILD_LIST_REQUEST, 1000, NULL);

	return TRUE;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_NORMAL_V1);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDR_MENU;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_ICON_MINIMIZED);

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{

	HWND hWnd;
	hInst=hInstance;

#ifdef ZEONWINDOW
	hWnd = CreateWindowEx(
		0,
		szWindowClass,
		szTitle,
		WS_OVERLAPPED+WS_CAPTION+WS_SYSMENU+WS_MINIMIZEBOX+WS_VISIBLE,
		CW_USEDEFAULT, 0, GAMESERVER_WIDTH, GAMESERVER_HEIGHT,
		NULL, NULL, hInstance, NULL);
#else
    hWnd = CreateWindowEx(
        0,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT,0,
        NULL, NULL, hInstance, NULL);
#endif
	
	if (hWnd==0) 
	{
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	ghWnd=hWnd;
	return TRUE;
}

BOOL CALLBACK CsLogDlgProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	INT wmId, wmEvent;
	
	switch (message) 
	{
		case WM_CREATE:
#if(GS_CASTLE==1)
			g_hCsLogDlgProc = CreateDialogParam(hInst, LPCTSTR(IDD_CASTLE_SIEGE_LOG), hWnd, CsLogDlgProc, 0);
#endif
			return 0;
		case WM_COMMAND:
			wmId    = wParam & 0xFFFF & 0xFFFF; 
			wmEvent = (wParam >> 16) & 0xFFFF; 
					
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUT_BOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   SendMessage(hWnd, WM_CLOSE, 0, 0);
				   break;
				case IDM_CLOSE_PLAYER:
					{
						Ccloseplayer closeplayer;
						closeplayer.Load("closeplayer.txt");
					}
					break;
				case IDM_ALL_USER_CLOSE:
					gObjAllDisconnect();
					break;
				case IDM_ALL_USER_LOGOUT:
					gObjAllLogOut();
					break;
				case IDM_MONSTER_POSITION_RELOAD:
					GameMonsterAllCloseAndReLoad();
					break;
				case IDM_SHOP_RELOAD:
					ShopDataLoad();
					break;
				case IDM_MAP_SERVER_INFO_RELOAD:
					g_MapServerManager.LoadData(gDirPath.GetNewPath("MapServerInfo.dat") );
					break;
#if(GS_CASTLE==1)					
				case IDM_CASTLE_SIEGE_RELOAD: //GS-CS Decompiled 100%
					if( g_CastleSiege.Ready(g_MapServerManager.GetMapSvrGroup()) == TRUE )
					{
						if( g_CastleSiege.LoadData(gDirPath.GetNewPath("MuCastleData.dat")) )
						{
							g_CastleSiege.LoadPreFixData(gDirPath.GetNewPath("commonserver.cfg"));
							g_CastleSiege.SetDataLoadState(CASTLESIEGE_DATALOAD_2);
						}
					}
					break;
#endif
				case IDM_IP_LOAD:
					acceptIP.Load(gDirPath.GetNewPath("Iplist.dat"));
					break;
				case IDM_OPTION_RELOAD:
					ReadCommonServerInfo();
					break;
				case IDM_LOAD_CUSTOMSRELOAD:
					gBalanceSystem.Load();
					//gResetSystem.Load();
					break;
				case IDM_CASHSHOP_OPTION_RELOAD:
					g_CashShop.CashShopOptioNReload();
					break;
				case IDM_LOG_PAINT:
					gCurPaintType=0;
					break;
#if(GS_CASTLE==1)
				case IDM_LOG_CASTLESIEGE:
					SendMessage(GetDlgItem(g_hCsLogDlgProc,	IDE_EDIT_LOG), LB_ADDSTRING, 0, (rand() % 2) ? (LONG)"HELLO WORLD" : (LONG)"�ȳ�");
					ShowWindow(g_hCsLogDlgProc, SW_SHOWNORMAL);
					break;
#endif
				case IDM_MAP1:
					gCurPaintMapNumber = 0;	// Lorencia
					gCurPaintType=1;
					break;
				case IDM_MAP2:
					gCurPaintType=1;
					gCurPaintMapNumber = 1;	// Dungeon
					break;
				case IDM_MAP3:
					gCurPaintType=1;
					gCurPaintMapNumber = 2;	// Devias
					break;
				case IDM_MAP4:
					gCurPaintType=1;
					gCurPaintMapNumber = 3;	// Noria
					break;
				case IDM_CRYWOLF:
					gCurPaintType=1;
					gCurPaintMapNumber = 34;	// Crywolf
					break;
				case IDM_DRAGON_EVENT:
					if (  DragonEvent->GetState() != 0 )
						DragonEvent->End();
					else
						DragonEvent->Start();
					break;
				case IDM_STARTOFXMAS_EVENT:
					if ( gXMasEvent != 0 )
						gXMasEvent = 0;
					else
						gXMasEvent=1;
					break;
				case IDM_FIRECRACKER:
					if ( gFireCrackerEvent != 0 )
						gFireCrackerEvent = 0;
					else
						gFireCrackerEvent=1;
					break;
				case IDM_5_MINUTE_CLOSE:
					if ( gCloseMsg == 0 )
					{
						gCloseMsgTime = 300;
						gCloseMsg=1;
						AllSendServerMsg( lMsg.Get(MSGGET(4, 104)) );
					}
					break;
				case IDM_3_MINUTE_CLOSE:
					if ( gCloseMsg == 0 )
					{
						gCloseMsgTime = 180;
						gCloseMsg=2;
						AllSendServerMsg(lMsg.Get(MSGGET(4, 105)) );
					}
					break;
				case IDM_1_MINUTE_CLOSE:
					if ( gCloseMsg == 0 )
					{
						gCloseMsgTime = 60;
						gCloseMsg=3;
						AllSendServerMsg(lMsg.Get(MSGGET(4, 106)) );
					}
					break;
				case IDM_RELOAD_ALL_EVENT:
					ReadEventInfo(MU_EVENT_ALL );
					break;
				case IDM_RELOAD_DEVILSQUARE:
					ReadEventInfo(MU_EVENT_DEVILSQUARE );
					break;
				case IDM_RELOAD_BLOODCASTLE:
					ReadEventInfo(MU_EVENT_BLOODCASTLE );
					break;
				case IDM_RELOAD_UNDERWORLD_ATTACK:
					ReadEventInfo(MU_EVENT_ATTACKEVENTTROOP );
					break;
				case IDM_RELOAD_GOLDENTROOP_ATTACK:
					ReadEventInfo(MU_EVENT_GOLDENTROOP );
					break;
				case IDM_RELOAD_WHITEMAGE_ATTACK:
					ReadEventInfo(MU_EVENT_WHITEMAGETROOP );
					break;
				case IDM_RELOAD_LOVE_PANGPANG:
					ReadEventInfo(MU_EVENT_LOVEPANGPANG );
					break;
				case IDM_RELOAD_FIRECRACKER:
					ReadEventInfo(MU_EVENT_FIRECRACKER );
					break;
				case IDM_RELOAD_XMAS_STAR:
					ReadEventInfo(MU_EVENT_XMASSTAR );
					break;
				case IDM_RELOAD_HEART_OF_LOVE:
					ReadEventInfo(MU_EVENT_HEARTOFLOVE );
					break;
				case IDM_RELOAD_NPC_SAY_HAPPY_NEW_YEAR:
					ReadEventInfo(MU_EVENT_SAY_HAPPYNEWYEAR );
					break;
				case IDM_RELOAD_NPC_SAY_MERRY_XMAS:
					ReadEventInfo(MU_EVENT_SAY_MERRYXMAS );
					break;
				case IDM_RELOAD_CHAOSCASTLE:
					ReadEventInfo(MU_EVENT_CHAOSCASTLE );
					break;
				case IDM_RELOAD_CHRISTMAS_RIBBONBOX:
					ReadEventInfo(MU_EVENT_CHRISTMAS_RIBBONBOX );
					break;
				case IDM_RELOAD_VALENTINE_DAY_CHOCOLATE_BOX:
					ReadEventInfo(MU_EVENT_VALENTINESDAY_CHOCOLATEBOX );
					break;
				case IDM_RELOAD_WHITE_DAY_CANDY_BOX:
					ReadEventInfo(MU_EVENT_WHITEDAY_CANDYBOX  );
					break;
				case IDM_RELOAD_ALL_ETC_OPTION:
					ReadGameEtcInfo(MU_ETC_ALL );
					break;
				case IDM_RELOAD_CREATE_CHARACTER:
					ReadGameEtcInfo(MU_ETC_CREATECHARACTER );
					break;
				case IDM_RELOAD_GUILD:
					ReadGameEtcInfo(MU_ETC_GUILD );
					break;
				case IDM_RELOAD_TRADE:
					ReadGameEtcInfo(MU_ETC_TRADE );
					break;
				case IDM_RELOAD_CHAOSBOX:
					ReadGameEtcInfo(MU_ETC_USECHAOSBOX );
					break;
				case IDM_RELOAD_PERSONAL_SHOP:
					ReadGameEtcInfo(MU_ETC_PERSONALSHOP );
					break;
				case IDM_RELOAD_PK_ITEM_DROP:
					ReadGameEtcInfo(MU_ETC_PKITEMDROP );
					break;
				case IDM_RELOAD_ITEM_DROP_RATE:
					ReadGameEtcInfo(MU_ETC_ITEMDROPRATE );
					break;
				case IDM_RELOAD_SPEEDHACK:
					ReadGameEtcInfo(MU_ETC_SPEEDHACK );
					break;
				case IDM_RELOAD_GAMEGUARD_CHECKSUM_CHECK:
					ReadGameEtcInfo(MU_ETC_GAMEGUARD );
					break;
				default:
					return DefWindowProc(hWnd, message, wParam, lParam);
					break;
			}
			break;
		case WM_GM_SERVER_MSG_PROC:
			GMServerMsgProc(wParam, lParam);
			break;
		case WM_GM_CLIENT_MSG_PROC:
			{
				int wp = wParam;
				int lp = lParam;
				GMClientMsgProc(wParam, lParam);
			}
			break;
		case WM_GM_JOIN_CLIENT_MSG_PROC:
			GMJoinClientMsgProc(wParam, lParam);
			break;
		case WM_GM_RANKING_CLIENT_MSG_PROC:
			GMRankingClientMsgProc(wParam, lParam);
			break;
		case WM_GM_EVENTCHIP_CLIENT_MSG_PROC:
			GMEventChipClientMsgProc(wParam, lParam);
			break;
		case WM_GM_DATA1_CLIENT_MSG_PROC:
			cDBSMng.MsgProc(0, wParam, lParam);
			break;
		case WM_GM_DATA2_CLIENT_MSG_PROC:
			cDBSMng.MsgProc(1, wParam, lParam);
			break;
		case WM_GM_EXDATA_CLIENT_MSG_PROC:
			ExDataClientMsgProc(wParam, lParam);
			break;
		case WM_START_SERVER:
			if ( gServerReady == 2 )
				GameServerStart();
			break;
		case WM_TIMER:
			switch ( wParam )
			{
				case WM_GUILD_LIST_REQUEST:
					DGGuildListRequest();
					KillTimer(ghWnd, WM_GUILD_LIST_REQUEST);
					break;
				case WM_LOG_PAINT:
					{
						RECT rect;
						HDC hdc = GetDC(hWnd);
						GetClientRect(hWnd, &rect);
						FillRect(hdc, &rect, (HBRUSH)GetStockObject(0));
						ReleaseDC(hWnd, hdc);

						if ( gCurPaintType == 0)
						{
							if ( LogTextPaint != NULL )
							{
								LogTextPaint(hWnd);
							}
						}
						
						gObjViewportPaint(hWnd, gCurPaintPlayer);
						g_ServerInfoDisplayer.Run(hWnd);
						GJNotifyMaxUserCount();
					}
					break;
				case WM_MONSTER_AND_MSG_PROC:
					MonsterAndMsgProc();
					break;
				case WM_MOVE_MONSTER_PROC:
					MoveMonsterProc();
#if(GS_CASTLE==0)
					g_Kanturu.UserMonsterCountCheck();
#endif
					break;
				case WM_EVENT_RUN_PROC:
					g_BloodCastle.Run();
					g_RingAttackEvent.Run();
					g_ChaosCastle.Run();
#if (GS_CASTLE==1)
					g_CastleSiege.Run();
					g_CastleDeepEvent.Run();
#endif
					g_CsNPC_Weapon.WeaponAttackProc();
#if (GS_CASTLE==1)
					g_Crywolf.Run();
#else
					g_Kanturu.Run();
#endif
					g_CashShop.CheckShopServerConnectState();
					//gs-cs 56 one new??
					g_IllusionTempleEvent.Run();
					//season4.5 add-on
					g_Raklion.Run();
					g_XMasAttackEvent.Run();
					break;
				case WM_AI_MONSTER_MOVE_PROC:
					TMonsterAI::MonsterMoveProc();
					break;
				case WM_AI_MONSTER_PROC:
					TMonsterAI::MonsterAIProc();
					break;
				case WM_FIRST_MSG_PROCESS:
					{
						for (int n=0;n<OBJMAX;n++)
						{
							gObjStateSetCreate(n);
						}
						for (int n=0;n<OBJMAX;n++)
						{
							gObjViewportListDestroy(n);
						}
						for (int n=0;n<OBJMAX;n++)
						{
							gObjViewportListCreate(n);
						}
						for (int n=0;n<OBJMAX;n++)
						{
							gObjViewportListProtocol(n);
						}

						if ( gDoPShopOpen != FALSE )
						{
							for (int n= OBJ_STARTUSERINDEX;n<OBJMAX;n++)
							{
								PShop_ViewportListRegenarate(n);
							}
							for (int n=OBJ_STARTUSERINDEX;n<OBJMAX;n++)
							{
								if (gObjIsConnected(n) != PLAYER_EMPTY )
								{
									gObj[n].m_bPShopItemChange = false;
								}
							}
						}

						for (int n=OBJ_STARTUSERINDEX;n<OBJMAX;n++)
						{
							gObjUnionUpdateProc(n);
						}

						gObjSetState();
						GameServerInfoSend();
					}
					break;
				case WM_SECOND_MSG_PROCESS:
					{
						for (int n = 0;n<MAX_NUMBER_MAP;n++)
						{
							MapC[n].WeatherVariationProcess();
						}

						wsGServer.m_SendSec = wsGServer.m_SendSecTmp;
						wsGServer.m_RecvSec = wsGServer.m_RecvSecTmp;

						wsGServer.m_SendSecTmp = 0;
						wsGServer.m_RecvSecTmp = 0;

						DragonEvent->Run();
						AttackEvent->Run();
						gEledoradoEvent.Run();
						g_EventManager.Run();
					}
					break;
				case WM_GS_CLOSE:
					if ( gCloseMsg != 0 )
					{
						gCloseMsgTime--;

						if ( gCloseMsgTime <= 1 )
						{
							if ( gCloseMsgTime == 1 )
							{
								AllSendServerMsg(lMsg.Get(MSGGET(1, 193)));
								LogAddC(2, lMsg.Get(MSGGET(1, 193)));
							}
						}
						else
						{
							if ( (gCloseMsgTime % 10) == 0 )
							{
								char szTemp[256];

								wsprintf( szTemp, lMsg.Get(MSGGET(1, 194)), gCloseMsgTime);
								AllSendServerMsg(szTemp);
								LogAddC(2, szTemp);
							}
						}

						if ( gCloseMsgTime < 0 )
						{
							KillTimer(ghWnd, WM_GS_CLOSE);
							gObjAllLogOut();
							gCloseMsgTime = 0;
							gCloseMsg = 0;
						}
					}
					gObjSecondProc();
#if (GS_CASTLE == 1 )
					if( cDBSMng.GetActiveDS() > DS_UNINITIALIZED && g_CastleSiege.GetDataLoadState() == 2 )
					{
						g_CastleSiege.DataRequest();
					}
					
					g_CastleSiege.SendCastleStateSync();

#endif
					g_CastleSiegeSync.AdjustTributeMoney();
#if(GS_CASTLE == 1)
					g_Crywolf.CrywolfSecondAct();
#endif
					break;
				case WM_SET_DATE:
					gSetDate();
					WhisperCash.TimeCheckCashDelete();
					break;
				case WM_CONNECT_DATASERVER:
					cDBSMng.Connect();
					gObjCheckAllUserDuelStop();
					break;
				case WM_LOG_DATE_CHANGE:
#if (GS_CASTLE == 1 )
					if( LogDateChange() == TRUE )
					{
						g_iCastleItemMixLimit = 1;
					}
#else
					LogDateChange();
#endif
					break;
			}
			break;
		case WM_CLOSE:
			if ( gLanguage != 3 )
			{
				if (MessageBox(ghWnd, "GameServer close?", "Close", MB_YESNO|MB_APPLMODAL) == IDYES)
				{
					DestroyWindow(hWnd);
				}
			}
			else
			{
				DestroyWindow(hWnd);
			}
			break;
		case WM_KEYDOWN:
			switch ( wParam )
			{
			case VK_F1 :
				gCurPaintPlayer--;
				if( gCurPaintPlayer < 0 ) gCurPaintPlayer = 0;
				break;
			case VK_F2 :
				gCurPaintPlayer++;
				if( gCurPaintPlayer > OBJMAX-1 ) gCurPaintPlayer = OBJMAX-1;
				break;
			case VK_F4 :
				//GameMainServerCreate(WM_ASS_SERVERMSG, WM_ASS_CLIENTMSG);
				//TestDSSend();
				{
				/*PMSG_IDPASS Msg;
				strcpy(Msg.Id,"saemsong");
				strcpy(Msg.Pass,"ssman");	
				Msg.CliVersion[0] = szClientVersion[0];
				Msg.CliVersion[1] = szClientVersion[1];
				Msg.CliVersion[2] = szClientVersion[2];
				CSPJoinIdPassRequest(&Msg, 0);
				*/
				}
				break;
			case VK_F5 : 
				gServerMaxUser-=10;
				if( gServerMaxUser < 10 ) gServerMaxUser = 10;
				break;
			case VK_F6 :
				gServerMaxUser+=10;
				if( gServerMaxUser > 1500 ) gServerMaxUser = 1500;
				break;
			case VK_F7 :
				{
					PMSG_CHARMAPJOIN Msg;
					strcpy(Msg.Name,"�׽�Ʈ");
					CGPCharacterMapJoinRequest(&Msg, 0);
				}
				break;
				case VK_F11:
					{
						DialogBox(hInst, (LPCTSTR)IDD_ABOUT_BOX, hWnd, (DLGPROC)About);
					}
					break;
			}
			break;
		case WM_DESTROY:
			GameMainFree();
			GiocpDelete();
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if ( ( wParam & 0xFFFF & 0xFFFF ) == IDOK || (wParam & 0xFFFF & 0xFFFF ) == IDCANCEL) 
			{
				EndDialog(hDlg, (wParam& 0xFFFF & 0xFFFF ));
				return TRUE;
			}
			break;
	}
    return FALSE;
}

#if(GS_CASTLE == 1)
BOOL CALLBACK CsLogDlgProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch ( uMessage )
	{
		case WM_INITDIALOG:	
			SendMessage(hWnd, WM_SIZE, 0, 0);
			break;
		case WM_CLOSE:
			ShowWindow(hWnd, SW_HIDE);
			return TRUE;
		case WM_SIZE:
			{
				RECT pRect;
				GetClientRect(hWnd, &pRect);
				MoveWindow(GetDlgItem(hWnd, IDE_EDIT_LOG), pRect.left, pRect.top, pRect.right, pRect.bottom, TRUE);
			}
			return TRUE;
	}
	return FALSE;
}
#endif