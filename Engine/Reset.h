#ifndef __RESET_H__
#define __RESET_H__

struct RESET_REQ_USERDATA
{
	PBMSG_HEAD2 h;
};

struct RESET_ANS_USERDATA
{
	PBMSG_HEAD2 h;
	int	Reset;
	int GrandReset;
};

class cReset
{
public:
	void SetData(RESET_ANS_USERDATA * aRecv);
};

extern cReset gReset;

#endif