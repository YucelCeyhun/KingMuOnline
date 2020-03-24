#include "StdAfx.h"

cDisplay gDisplay;

static char * ServerTypeText[] =
{
	"[-  Standby  -]",
	"[-  Active  -]"

};

static char * ErrorMessge[] = 
{
	"0) JoinServer - Active",
	"1) ShopServer - Active",
	"2) DataServer - Active",
	"3) GuildServer - Active",
	"4) EventServer - Active",
	"5) RankingServer - Active"
};

cDisplay::cDisplay()
{
	this->m_bValidJSConnection = FALSE;
	this->m_bValidCSConnection = FALSE;
	this->m_bValidDSConnection = FALSE;
	this->m_bValidEXDSConnection = FALSE;
	this->m_bValidEVDSConnection = FALSE;
	this->m_bValidRKDSConnection = FALSE;
	// ----
	this->InitGDIObject();
}

cDisplay::~cDisplay()
{
	this->DelGDIObject();
}

void cDisplay::InitGDIObject()
{
#if(USE_NEW_WINDOW_STYLE == 1)
	this->m_hFont = CreateFont(60, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE,
		1, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Times");
#else
	this->m_hFont = CreateFont(80, 0, 0, 0, FW_THIN, FALSE, TRUE, FALSE,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Times");
#endif

	this->m_hNormalBrush = CreateSolidBrush(RGB(110, 240, 120));	// GREEN
	this->m_hAbnormalBrush = CreateSolidBrush(RGB(105, 105, 105));	// GRAY
}

void cDisplay::DelGDIObject()
{
	DeleteObject(this->m_hFont);
	DeleteObject(this->m_hNormalBrush);
	DeleteObject(this->m_hAbnormalBrush);
}

void cDisplay::Run(HWND hWnd)
{
	this->PaintAllInfo(hWnd,0,20);
}

void cDisplay::PaintAllInfo(HWND hWnd,int iTopLeftX,int iTopLeftY)
{
	HDC hDC = GetDC(hWnd);
	RECT rect;
	GetClientRect(hWnd,&rect);
	rect.top = 20;
#if(USE_NEW_WINDOW_STYLE == 1)
	rect.bottom = 80;
#else
	rect.bottom = 100;
#endif
	int iLineCount = 0;
	int iIndex=0;

	int iOldBkMode = SetBkMode(hDC, TRANSPARENT);

	if ( this->m_bValidJSConnection != FALSE ||
		 this->m_bValidCSConnection != FALSE ||
		 this->m_bValidDSConnection != FALSE ||
		 this->m_bValidEXDSConnection != FALSE ||
		 this->m_bValidEVDSConnection!= FALSE ||
		 this->m_bValidRKDSConnection != FALSE )
	{
		FillRect(hDC, &rect, this->m_hNormalBrush);
		iIndex = 1;
	}
	else
		FillRect(hDC, &rect, this->m_hAbnormalBrush);

	if ( this->m_bValidJSConnection == TRUE )
	{
		SetTextColor(hDC, RGB(0, 0, 255));
		TextOut(hDC, iTopLeftX, iTopLeftY+iLineCount*15, ErrorMessge[0], strlen(ErrorMessge[0]));
		iLineCount++;
	}

	if ( this->m_bValidCSConnection == TRUE )
	{
		SetTextColor(hDC, RGB(0, 0, 255));
		TextOut(hDC, iTopLeftX,  iTopLeftY+iLineCount*15, ErrorMessge[1], strlen(ErrorMessge[1]));
		iLineCount++;
	}

	if ( this->m_bValidDSConnection == TRUE )
	{
		SetTextColor(hDC, RGB(0, 0, 255));
		TextOut(hDC, iTopLeftX, iTopLeftY+iLineCount*15, ErrorMessge[2], strlen(ErrorMessge[2]));
		iLineCount++;
	}

	if ( this->m_bValidEXDSConnection == TRUE )
	{
		SetTextColor(hDC, RGB(0, 0, 255));
		TextOut(hDC, iTopLeftX, iTopLeftY+iLineCount*15, ErrorMessge[3], strlen(ErrorMessge[3]));
		iLineCount++;
	}

	if ( this->m_bValidEVDSConnection == TRUE )
	{
		SetTextColor(hDC, RGB(0, 0, 255));
		TextOut(hDC, iTopLeftX,  iTopLeftY+iLineCount*15, ErrorMessge[4], strlen(ErrorMessge[4]));
		iLineCount++;
	}

	if ( this->m_bValidRKDSConnection == TRUE )
	{
		SetTextColor(hDC, RGB(0, 0, 255));
		TextOut(hDC, iTopLeftX, iTopLeftY+iLineCount*15, ErrorMessge[5], strlen(ErrorMessge[5]));
		iLineCount++;
	}
	// ----
	HFONT pOldFont = (HFONT)SelectObject(hDC,this->m_hFont);
	SetTextColor(hDC,RGB(250,250,250));
	// ----
#if(USE_NEW_WINDOW_STYLE == 1)
	TextOut(hDC,175,18,ServerTypeText[iIndex],strlen(ServerTypeText[iIndex]));
#else
	TextOut(hDC,240,20,ServerTypeText[iIndex],strlen(ServerTypeText[iIndex]));
#endif
	// ----
	SelectObject(hDC,pOldFont);
	SetBkMode(hDC,iOldBkMode);
	ReleaseDC(hWnd,hDC);
}