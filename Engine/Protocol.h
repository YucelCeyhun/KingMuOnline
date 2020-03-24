#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

class cProtocol
{
public:
	void Load();
	// ----
	static void	DataRecv(DWORD Case,LPBYTE lpMsg,int Len,int aIndex);
	void DataSend(LPBYTE Data,int Size);
	void XorData(LPBYTE &Data,int iStart,int iSize);
};

extern cProtocol gProtocol;

#endif