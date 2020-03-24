#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#define MAX_OBJECT			100
#define MAX_WIN_WIDTH		640
#define MAX_WIN_HEIGHT		480

struct InterfaceObject
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
};

class cInterface
{
public:
	cInterface();
	virtual ~cInterface();
	// ----
	void Load();
	static void	Work();
	static void	LoadImages();
	void BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	// ----
	bool CheckWindow(int WindowID);
	void DrawTime();
	// ----
	BOOL EnabledClock;
	// ----
	void TimeSwitch();
	// ----
	//bool RestStop;
	//bool CamActive;
	// ----
	//void EventWareHouseUI(DWORD Event);
	void EventCameraUI(DWORD Event);
	void DrawCameraUI();
	//void DrawHealthMonsterBar();
	// ----
	void DrawGlowTronButton();
	void EventGlowTronButton(DWORD Event);
	// ----
	void DrawHPMobCheck();
	void EventHPMobCheck(DWORD Event);
	// ----
	//void DrawChangeFPSCheckBox();
	//void EventChangeFPSCheckBox(DWORD Event);
	// ----
	//void DrawAntialisingInterface();
	//void EventAntialisingInterface(DWORD Event);
	// ----
	//void DrawGlowSelecterUI();
	// ----
	//void EventGlowSelecterEffectPlus(DWORD Event);
	//void EventGlowSelecterEffectMinus(DWORD Event);
	// ----
	void DrawUserHelp();
	void UserHelpState();
	// ----
	static void ChatHandler(char* Command);
	// ----
	int GlowPointCounter;
	// ----
	//bool CombinedChecks();
	//bool MiniMapCheck();
	bool WinKeyChecks();
	// ----
	float GetResizeX(short ObjectID);
	bool IsWorkZone(short ObjectID);
	void DrawButtonText();
	//void DrawWareHouse();
	// ----
	int IsClk;
	// ----
	int DrawToolTipEx(int X, int Y, LPCSTR Text, ...);
	int	DrawToolTip(int X, int Y, LPCSTR Text, ...);
	int	DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	//void DrawPicture(char Path[64], float X, float Y, float Width, float Height, int U1, int U2, float ScaleX, float ScaleY, int HL, int U3, GLfloat Alpha);
	//void DrawPictureAlpha(char Path[64], float X, float Y, float Width, float Height, int U1, int U2, float ScaleX, float ScaleY, int HL, int U3, GLfloat Alpha);
	void DrawGUI(short ObjectID, float PosX, float PosY, float Width, float Height);
	void DrawColoredGUI(short ObjectID, float PosX, float PosY, float Width, float Height, float StartX, float StartY, DWORD Color);
	// ----
	void DrawTextColor(BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha);
	void DrawBackGround(BYTE Red, BYTE Green, BYTE Blue, BYTE Alpha);
	// ----
	void intcpy(int i, char* buffer, ...);
	void charcpy(char x, char* buffer);
	void fltcpy(float f, char* buffer);
	void fltptrcpy(float* f, char* buffer);
	// ----
private:
	InterfaceObject Data[MAX_OBJECT];
	// ----
};

extern cInterface gInterface;

#endif