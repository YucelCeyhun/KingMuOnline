#ifndef __EXHP_H__
#define __EXHP_H__

//extern int IsHpm;
extern bool g_ExEnabled;
#define MAX_VIEWPORT_MOBS 400
#define MAX_VIEWPORT_PETS 50

/*
PACKET:			MSG_ANS_LIFEBAR_SEND
DIRECTION:		GAMESERVER to CLIENT
DESCRIPTION:
aIndex			- Index of target;
Level			- Level of target;
Life			- Current life of target;
MaxLife			- Maximum life of target;
SD				- Current SD of target;
MaxSD			- Maximum SD of target;
*/
typedef struct
{
	PBMSG_HEAD2	h;
	INT			NumberH;
	INT			NumberL;
	INT			Level;
	FLOAT		Life;
	INT			MaxLife;
	INT			Class;
	BOOL		SendSD;
} MSG_ANS_LIFEBAR_SEND, *LPMSG_ANS_LIFEBAR_SEND;

class cExHP
{
public:
	cExHP();
	virtual ~cExHP();
	// ----
	void Init();
	void Load();
	void InfoRecv(LPMSG_ANS_LIFEBAR_SEND aRecv);
	void Switcher();
	bool HPMobEnabled;
	// ----
	int IsHpm;
	// ----
	static void Draw();
	//static void DrawPetFollow(lpObjViewport lpObjView);
	// ----
private:
	pTargetObj Data[9000];
};

extern cExHP gExHP;

#endif