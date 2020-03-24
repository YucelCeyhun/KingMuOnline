#include "StdAfx.h"
#include "NewsSystem.h"
#include "GameMain.h"
#include "TNotice.h"
#include "user.h"

CNewsSystem g_NewsSystem;

void CNewsSystem::AllSendServerMsgNews(char*chatmsg)
{
	PMSG_NOTICE pNotice;
	pNotice.type	= 0;	// 3
	pNotice.btCount	= 0;	// 4
	pNotice.wDelay	= 0;	// 6
	pNotice.dwColor	= 0;	// 8
	pNotice.btSpeed	= 0;	// C
	// ----
	TNotice::MakeNoticeMsg((TNotice*)&pNotice,0x00, chatmsg);
	// ----
	for(int n=OBJ_STARTUSERINDEX;n<OBJMAX;n++)
	{
		if(gObj[n].Connected == PLAYER_PLAYING)
		{
			if(gObj[n].Type == OBJ_USER)
			{
				DataSend(n,(unsigned char*)&pNotice,pNotice.h.size);
			}
		}
	}
}

void CNewsSystem::Load()
{    
	int IsNews = GetPrivateProfileIntA("NewsSystem","IsNewsSystem",0,NEWSSYSTEM_FILE);
	// ----
	if(IsNews!=0)
	{
	   _beginthread(&NewsSystem,0,0);
	}
}

void NewsSystem(void*lpParam)
{
	FILE *fp;
	fp=fopen(NEWSSYSTEM_FILE,"r");
	// ----
	while(true)
	{
		int Sections      = GetPrivateProfileInt("NewsSystem","NewsSections",5,NEWSSYSTEM_FILE);
		int time          = GetPrivateProfileInt("NewsSystem","NewsTime",10,NEWSSYSTEM_FILE)*60000;
		// ----
		if(Sections <= 0 || GetPrivateProfileInt("NewsSystem","IsNewsSystem",0,NEWSSYSTEM_FILE) > 0)
		{
			char MSG1[100],MSG2[100],MSG3[100];
			char Getter1[11],Getter2[11],Getter3[11];
			// ----
			for(int x=0;x<Sections;x++)
			{
				Sleep(time);
				sprintf(Getter1,"New%02d",((x*3)+1));
				sprintf(Getter2,"New%02d",((x*3)+2));
				sprintf(Getter3,"New%02d",((x*3)+3));
				GetPrivateProfileString("News",Getter1,"Ex406 MU Project",MSG1,100,NEWSSYSTEM_FILE);
				GetPrivateProfileString("News",Getter2,"Ex406 MU Project",MSG2,100,NEWSSYSTEM_FILE);
				GetPrivateProfileString("News",Getter3,"Ex406 MU Project",MSG3,100,NEWSSYSTEM_FILE);
				g_NewsSystem.AllSendServerMsgNews(MSG1);
				g_NewsSystem.AllSendServerMsgNews(MSG2);
				g_NewsSystem.AllSendServerMsgNews(MSG3);
			}
		}
		else
		{
			Sleep(60000);
		}
	}
	_endthread();
}