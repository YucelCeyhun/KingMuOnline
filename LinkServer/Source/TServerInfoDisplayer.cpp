#include "stdafx.h"

TServerInfoDisplayer g_ServerInfoDisplayer;

static char * ServerTypeText[1] =
{
    "[-  LinkServer  -]",
};

TServerInfoDisplayer::TServerInfoDisplayer()
{
    this->InitGDIObject();
}

TServerInfoDisplayer::~TServerInfoDisplayer()
{
    this->DelGDIObject();
}

void TServerInfoDisplayer::InitGDIObject()
{
#if(ZEONWINDOW == 1)
	this->m_hFont = CreateFont(60, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE,
		1, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Times");
#else
	this->m_hFont = CreateFont(80, 0, 0, 0, FW_THIN, FALSE, TRUE, FALSE,
		ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Times");
#endif
	this->m_hNormalBrush = CreateSolidBrush(RGB(0, 150, 240));
}

void TServerInfoDisplayer::DelGDIObject()
{
    DeleteObject(this->m_hFont);
    DeleteObject(this->m_hNormalBrush);
    DeleteObject(this->m_hAbnormalBrush);
}

void TServerInfoDisplayer::Run(HWND hWnd)
{
    this->PaintAllInfo(hWnd, 0, 20);
}

void TServerInfoDisplayer::PaintAllInfo(HWND hWnd, int iTopLeftX, int iTopLeftY)
{
    HDC hDC = GetDC(hWnd);
    RECT rect = {0};
    GetClientRect(hWnd, &rect);
    rect.top = 20;
#if(ZEONWINDOW == 1)
	rect.bottom = 80;
#else
	rect.bottom = 100;
#endif
	int iLineCount = 0;

	int iOldBkMode = SetBkMode(hDC, TRANSPARENT);
	FillRect(hDC, &rect, this->m_hNormalBrush);

	HFONT pOldFont = (HFONT)SelectObject(hDC, this->m_hFont);
	SetTextColor(hDC, RGB(250, 250, 250));

#if(ZEONWINDOW == 1)
	TextOutA(hDC, LINKSERVER_WIDTH / 2 - 200, 18, ServerTypeText[0], strlen(ServerTypeText[0]));
#else
	TextOut(hDC, 240, 20, ServerTypeText[0], strlen(ServerTypeText[0]));
#endif

	SelectObject(hDC, pOldFont);
	SetBkMode(hDC, iOldBkMode);
	ReleaseDC(hWnd, hDC);
}