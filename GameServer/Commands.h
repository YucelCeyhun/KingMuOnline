#ifndef __COMMANDS_H__
#define __COMMANDS_H__

/*
typedef struct
{
	PBMSG_HEAD2 h;
	int aIndex;
	char Account[11];
	BYTE InUse;
	BYTE Change;
} PMSG_REQ_CHANGEWAREHOUSE, *LPMSG_REQ_CHANGEWAREHOUSE;
*/

struct CCommands
{
	public:
	// ---
	void SendPost(int aIndex,LPCSTR Message);
	void AddStats(int aIndex,LPCSTR AddPoints,DWORD Type);
	void DropItem(int aIndex,LPCSTR Message);
	void MakeItem(int aIndex,LPCSTR Message);
	void ClearInven(int aIndex);
	void PkClear(int aIndex);
	void ServerInfo(int aIndex);
	void SkinCommand(int aIndex,LPCSTR Message);
	//void ChangeVault(int aIndex,LPCSTR Message);
	void SetZenCommand(int aIndex,LPCSTR Message);
	void PackLevel(int aIndex);
	void PackLevel20(int aIndex);
	void PackLuck(int aIndex);
	void PackSkill(int aIndex);
	void PackOption(int aIndex);
	void PackExcellent(int aIndex);
	void PackAncient(int aIndex);
	void PackSocket(int aIndex);
	void UnpackLevel(int aIndex);
	void UnpackLuck(int aIndex);
	void UnpackSkill(int aIndex);
	void UnpackOption(int aIndex);
	void UnpackExcellent(int aIndex);
	void UnpackAncient(int aIndex);
	void UnpackSocket(int aIndex);
	// ----
	BOOL IsGameMaster(int aIndex);
	BOOL Manager(int aIndex,PMSG_CHATDATA*lpMsg);
};

extern CCommands Commands;

#endif