// Displayer.h: interface for the Displayer class.
//////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Displayer
{
public:
	Displayer();
	virtual ~Displayer();
	// ----
	void Run(HWND hWnd);
	// ----
	void CheckJSConnection(BOOL bActive)
	{
		this->m_bValidJSConnection = bActive;
	}//JoiSerber
	void CheckEXDSConnection(BOOL bActive)
	{
		this->m_bValidEXDSConnection = bActive;
	}//ExDb
	void CheckIGSConnection(BOOL bActive)
	{
		this->m_bValidIGSConnection = bActive;
	}//cashshop
	void InitGDIObject();
	void DelGDIObject();
	void PaintAllInfo(HWND hWnd, int iTopLeftX, int iTopLeftY);

private:

	BOOL m_bValidJSConnection;	// 4
	BOOL m_bValidEXDSConnection;	// 10
	BOOL m_bValidIGSConnection;	// 8
	HFONT m_hFont;	// 1C
	HBRUSH m_hNormalBrush;	// 20
	HBRUSH m_hAbnormalBrush;	// 24
};

extern Displayer g_Displayer;
