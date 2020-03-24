// Query.h: interface for the CQuery class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUERY_H__8A3116E5_E735_4FF9_A61D_5566130C3610__INCLUDED_)
#define AFX_QUERY_H__8A3116E5_E735_4FF9_A61D_5566130C3610__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define MAX_COLUMNS	100

class CQuery  
{
public:

	CQuery();
	virtual ~CQuery();

	BOOL Connect(LPTSTR lpszDNS, LPTSTR lpszUser, LPTSTR lpszPassword);
	BOOL ExecQuery(LPTSTR lpszStatement, ...);
	void Close();
	void GetAsString(LPTSTR ColName, LPTSTR pOutBuffer);
	DWORD GetAsInteger(LPTSTR ColName);
	float GetAsFloat(LPTSTR ColName);
	void Disconnect();
	int GetAsBinary(LPSTR lpszStatement, LPBYTE OUT lpszReturnBuffer);
	SQLRETURN Fetch();
	int GetResult(int iIndex);
	void SetAsBinary(LPTSTR lpszStatement, LPBYTE lpBinaryBuffer, SQLUINTEGER BinaryBufferSize);

private:

	BOOL ReConnect();
	
	int FindIndex(LPTSTR ColName);
	void Diagnosis();

protected:

	SQLHANDLE m_hEnviroment;
	SQLHANDLE m_hConnection;
	SQLHANDLE m_hStmt;
	TCHAR m_szDNS[64];
	TCHAR m_szUser[64];
	TCHAR m_szPassword[64];
	SQLSMALLINT m_ColCount;
	SQLTCHAR m_SQLColName[MAX_COLUMNS][30];
	TCHAR m_SQLData[MAX_COLUMNS][256];
	SQLINTEGER m_SQLDataLen[MAX_COLUMNS];

};

#endif // !defined(AFX_QUERY_H__8A3116E5_E735_4FF9_A61D_5566130C3610__INCLUDED_)
