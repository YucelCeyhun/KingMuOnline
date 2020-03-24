#ifndef __NEWSSYSTEM_H__
#define __NEWSSYSTEM_H__

void NewsSystem(void*lpParam);

class CNewsSystem
{
public:
	void Load();
	void AllSendServerMsgNews(char*chatmsg);
};

extern CNewsSystem g_NewsSystem;

#endif