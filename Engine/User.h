#ifndef __USER_H__
#define __USER_H__

class cUser
{
public:
	void Load();
	lpCharObj lpPlayer;
	// ----
	int	m_Reset;
	int	m_GrandReset;
	// ----
	void InitSetItemOptionUpdate();
	static void SetItemOptionUpdate();
	// ----
	//static void CharacterExternInfo();
	//static void CharacterExternPoint();
	// ----
	//void RecvAttackResult(PMSG_ATTACKRESULT* aRecv);
	//void RecvKilledObject(PMSG_DIEPLAYER* aRecv);
	// ----
	//TargetObj TargetData[9000];
};

extern cUser gUser;

#endif