#pragma once

class TServerInfoDisplayer
{

public:

    TServerInfoDisplayer();
    virtual ~TServerInfoDisplayer();

    void Run(HWND hWnd);
    void InitGDIObject();
    void DelGDIObject();
    void PaintAllInfo(HWND hWnd, int iTopLeftX, int iTopLeftY);

private:
    HFONT m_hFont;
    HBRUSH m_hNormalBrush;
    HBRUSH m_hAbnormalBrush;
};

extern TServerInfoDisplayer g_ServerInfoDisplayer;