#ifndef __JSPROTOCOL_H__
#define __JSPROTOCOL_H__

class cJSProtocol
{
public:
	void	AccountLogin(int aIndex,LPSDHP_SERVERINFO lpMsg);
	void	AccountRequest(int aIndex,LPSDHP_ACCOUNTINFO lpMsg);
	void	ProtocolCore(int aIndex,BYTE HeadCode,LPBYTE aRecv,int iSize);
};

extern cJSProtocol gJSProtocol;

#endif