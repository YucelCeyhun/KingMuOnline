// Query.cpp: implementation of the CQuery class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Query.h"
#include "LogProc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CQuery::CQuery()
{
	this->m_ColCount = -1;
	this->m_hConnection = NULL;
	this->m_hEnviroment = NULL;
	this->m_hStmt = NULL;
	memset(this->m_SQLColName, 0, sizeof(this->m_SQLColName));
	memset(this->m_SQLData, 0, sizeof(this->m_SQLData));
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &this->m_hEnviroment);
	SQLSetEnvAttr(this->m_hEnviroment,SQL_ATTR_ODBC_VERSION,(SQLPOINTER)SQL_OV_ODBC3, SQL_NTS);

}

CQuery::~CQuery()
{
	if ( this->m_hStmt != SQL_NULL_HANDLE )
		SQLFreeHandle(SQL_HANDLE_STMT, this->m_hStmt);

	if ( this->m_hConnection != SQL_NULL_HANDLE )
		SQLFreeHandle(SQL_HANDLE_DBC, this->m_hConnection);

	if ( this->m_hEnviroment != SQL_NULL_HANDLE )
		SQLFreeHandle(SQL_HANDLE_ENV, this->m_hEnviroment);
}


BOOL CQuery::Connect(TCHAR * lpszDNS, TCHAR * lpszUser, TCHAR * lpszPassword)
{
	lstrcpy(this->m_szDNS, lpszDNS);
	lstrcpy(this->m_szUser, lpszUser);
	lstrcpy(this->m_szPassword, lpszPassword);
	SQLHANDLE rgbValue;

	SQLAllocHandle(SQL_HANDLE_DBC, this->m_hEnviroment, &this->m_hConnection);
	SQLSetConnectAttr(this->m_hConnection, SQL_LOGIN_TIMEOUT, &rgbValue, 0);
	
	SQLRETURN Result = SQLConnect(this->m_hConnection, (SQLTCHAR *)this->m_szDNS, SQL_NTS,
		(SQLTCHAR *)this->m_szUser, SQL_NTS, (SQLTCHAR *)this->m_szPassword, SQL_NTS);


	if ( Result != SQL_SUCCESS && Result != SQL_SUCCESS_WITH_INFO )
	{
		SQLSMALLINT sRecord = 1, MsgLen;
		SQLTCHAR SqlState[6], SQLMsgError[SQL_MAX_MESSAGE_LENGTH];
		SQLINTEGER NativeError;

		while ( SQLGetDiagRec(SQL_HANDLE_DBC, this->m_hConnection, sRecord,
			SqlState, &NativeError, SQLMsgError, sizeof(SQLMsgError), &MsgLen) != SQL_NO_DATA )
		{
			if ( LogAddC != NULL )
				LogAddC(3, "SQLSTATE:%s, Diagnosis:%s", SqlState, SQLMsgError);
			else
				MsgBox("SQLSTATE:%s, Diagnosis:%s", SqlState, SQLMsgError);
		}

		return FALSE;
	}

	Result = SQLAllocHandle(SQL_HANDLE_STMT, this->m_hConnection, &this->m_hStmt);

	if ( Result != SQL_SUCCESS && Result != SQL_SUCCESS_WITH_INFO )
		return FALSE;

	return TRUE;
}


BOOL CQuery::ReConnect()
{
	return this->Connect(this->m_szDNS, this->m_szUser, this->m_szPassword);
}



BOOL CQuery::ExecQuery(TCHAR * lpszStatement, ...)
{
	TCHAR szStatement[1024];

	va_list pArguments;
	va_start(pArguments, lpszStatement);
	//wvsprintf(szStatement, lpszStatement, pArguments);
	vsprintf(szStatement, lpszStatement, pArguments);
	va_end(pArguments);

	LogAddTD(szStatement);

	SQLRETURN Result = SQLExecDirect(this->m_hStmt, (SQLTCHAR *)szStatement, SQL_NTS);

	if ( Result != SQL_SUCCESS && Result != SQL_SUCCESS_WITH_INFO && Result != SQL_NO_DATA )
	{
		this->Diagnosis();
		return FALSE;
	}

	SQLINTEGER RowCount;
	SQLRowCount(this->m_hStmt, &RowCount);
	SQLNumResultCols(this->m_hStmt, &this->m_ColCount);

	if ( this->m_ColCount >= MAX_COLUMNS-1 )
	{
		LogAddC(2, "[CQuery] ColCount >= MAX_COLUMNS-1");
		return FALSE;
	}

	// Case just EXEC
	if ( this->m_ColCount == 0 )
	{
		this->Close();
		return TRUE;
	}

	for(int iColPos=0; iColPos < this->m_ColCount ; iColPos++  )
	{
		SQLBindCol(this->m_hStmt, iColPos+1, SQL_CHAR, this->m_SQLData[iColPos],
			sizeof(this->m_SQLData[0])-1, &this->m_SQLDataLen[iColPos]);
		SQLDescribeCol( this->m_hStmt, iColPos+1, this->m_SQLColName[iColPos],
			sizeof(this->m_SQLColName[iColPos]), NULL, NULL, NULL, NULL, NULL);
	}

	return TRUE;
}


void CQuery::Close()
{
	SQLCloseCursor(this->m_hStmt);
	SQLFreeStmt(this->m_hStmt, 2);
}



SQLRETURN CQuery::Fetch()
{
	return SQLFetch(this->m_hStmt);
}


int CQuery::FindIndex(LPTSTR ColName)
{
	for(short i=0;i<this->m_ColCount;i++)
	{
		if ( this->m_SQLColName[i][0] == ColName[0] )
		{
			if ( lstrcmp((TCHAR *)this->m_SQLColName[i], (TCHAR *)ColName) == 0 )
			{
				return i;
			}
		}
	}

	return -1;
}


void CQuery::GetAsString(LPTSTR ColName, LPTSTR pOutBuffer)
{
	int iIndex = this->FindIndex(ColName);

	if ( iIndex != -1 )
	{
		lstrcpy(pOutBuffer, this->m_SQLData[iIndex]);
	}
	else
	{
		pOutBuffer[0] = 0;
	}
}


DWORD CQuery::GetAsInteger(LPTSTR ColName)
{
	int iIndex =this->FindIndex(ColName);

	if ( iIndex != -1 )
	{
		return atoi(this->m_SQLData[iIndex]);
	}

	return -1;
}



float CQuery::GetAsFloat(LPTSTR ColName)
{
	int iIndex =this->FindIndex(ColName);

	if ( iIndex != -1 )
	{
		return (float)atof(this->m_SQLData[iIndex]);
	}

	return -1;
}



void CQuery::Diagnosis()
{
	SQLSMALLINT sRecord = 1, MsgLen;
	SQLTCHAR SqlState[6], SQLMsgError[SQL_MAX_MESSAGE_LENGTH];
	SQLINTEGER NativeError;

	while ( SQLGetDiagRec(SQL_HANDLE_STMT, this->m_hStmt, sRecord,
		SqlState, &NativeError, SQLMsgError, sizeof(SQLMsgError), &MsgLen) != SQL_NO_DATA )
	{
		if ( LogAddC != NULL )
			LogAddC(3, "SQLSTATE:%s, Diagnosis:%s", SqlState, SQLMsgError);
		else
			MsgBox("SQLSTATE:%s, Diagnosis:%s", SqlState, SQLMsgError);

		sRecord++;
	}

	if ( !lstrcmp((TCHAR *)SqlState, "08S01"))	// Communication Link Failure
		this->ReConnect();
}


int CQuery::GetResult(int iIndex)
{
	return atoi(this->m_SQLData[iIndex]);
}

int CQuery::GetAsBinary(LPTSTR lpszStatement, LPBYTE OUT lpszReturnBuffer)
{
	SQLCHAR * pSQLBuf;
	SQLINTEGER BufLen;
	SQLCHAR SQLBinary[10000];
	SQLINTEGER lOfs = 0;
	SQLINTEGER SQLLen;
	SQLRETURN SQLResult;

	//SQLAllocHandle(SQL_HANDLE_STMT, this->m_hConnection, &this->m_hStmt);

	SQLResult = SQLExecDirect(this->m_hStmt, (SQLTCHAR *)lpszStatement, SQL_NTS);

	if ( SQLResult != SQL_SUCCESS )
	{
		this->Diagnosis();
		return -1;
	}

	while ( true )
	{
		SQLResult = SQLFetch(this->m_hStmt);

		if ( SQLResult == SQL_NO_DATA )
			break;

		pSQLBuf = lpszReturnBuffer;

		while ( true )
		{

			SQLResult = SQLGetData(this->m_hStmt,
				1, SQL_C_BINARY , SQLBinary, sizeof(SQLBinary), &SQLLen);

			if ( SQLResult == SQL_NO_DATA )
				break;

			if ( SQLLen == -1 )
			{
				this->Close();
				return 0;
			}

			if ( SQLResult == SQL_SUCCESS )
			{
				BufLen = SQLLen;
			}
			else
			{
				BufLen = sizeof(SQLBinary);
			}

			lOfs += BufLen;
			memcpy(pSQLBuf, SQLBinary, BufLen);
			pSQLBuf = &pSQLBuf[lOfs];
		}
	}

	//SQLFreeHandle(SQL_HANDLE_STMT, this->m_hStmt);
	return BufLen;
}


void CQuery::SetAsBinary(LPTSTR lpszStatement, LPBYTE lpBinaryBuffer, SQLUINTEGER BinaryBufferSize)
{
	SQLINTEGER cbValueSize = -0x64 - BinaryBufferSize;
	SQLPOINTER pToken;
	BYTE cBUFFER[10000];
	SQLRETURN Result;

	SQLBindParameter(this->m_hStmt, 1, SQL_PARAM_INPUT,
		SQL_C_BINARY , SQL_LONGVARBINARY, BinaryBufferSize, 0, (SQLPOINTER)1, 0, &cbValueSize);

	SQLExecDirect(this->m_hStmt, (SQLTCHAR *)lpszStatement, SQL_NTS);
	Result = SQLParamData(this->m_hStmt, &pToken);

	int lOfs=0;

	while ( Result == SQL_NEED_DATA )
	{
		memcpy(cBUFFER, lpBinaryBuffer, sizeof(cBUFFER));
		Result = SQLPutData(this->m_hStmt, cBUFFER, BinaryBufferSize);
		Result = SQLParamData(this->m_hStmt, &pToken);
		lOfs += sizeof(cBUFFER);
	}

	SQLParamData(this->m_hStmt, &pToken);
	this->Close();
}

void CQuery::Disconnect()
{
	if ( this->m_hStmt )
		SQLFreeHandle(SQL_HANDLE_STMT, this->m_hStmt);

	if ( this->m_hConnection )
		SQLDisconnect(this->m_hConnection);

	if ( this->m_hConnection )
		SQLFreeHandle(SQL_HANDLE_DBC, this->m_hConnection);

	this->m_hStmt = NULL;
	this->m_hConnection = NULL;
}