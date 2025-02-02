//GameServer 1.00.77 JPN - Completed
#include "stdafx.h"
#include "winutil.h"

static BYTE bBuxCode[3]={0xFC, 0xCF, 0xAB};

void BuxConvert(char* buf, int size)
{
	int n;

	for (n=0;n<size;n++)
	{
		buf[n]^=bBuxCode[n%3] ;
	}
}


BOOL SQLSyntexCheck(char* SQLString)
{
	char* temp;

	temp=strchr(SQLString, 39);
	if (temp==0)
	{
		temp=strchr(SQLString, 32);
		if (temp==0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}

BOOL SQLSyntexCheckConvert(char* SQLString)
{
	char tempSQL[256];
	char* temp;
	char* temp2;

	temp2 = SQLString;
	int lOfs=0;
	int tOfs=0;
	int sOfs=0;

	

	if (SQLString==0)
	{
		return FALSE;
	}
	while (true)
	{
		temp = strchr(temp2, 39);
		if (temp != 0 )
		{
			if (temp - temp2 != 0)
			{
				memcpy(&tempSQL[tOfs], temp2, temp-temp2);
			}
			lOfs = temp - (temp2 + sOfs);
			tOfs += lOfs;
			temp2 += lOfs;

			tempSQL[tOfs]=0;

			tOfs += 2;
			temp2++;

			strcat(tempSQL, "''");
			
		}
		else
		{
			strcpy(&tempSQL[tOfs], temp2);
			break;
		}
	}

	
	strcpy(SQLString, tempSQL);
	return TRUE;
}


BOOL SpaceSyntexCheck(char* string)
{
	char* temp;
	
	temp = strchr(string, 32);
	if (temp ==0 )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


BOOL StrHangulCheck(char* str)
{
	BYTE code1;
	BYTE code2;
	BYTE code;
	int i = 0;
	int n = 0;
	char	szTemp[256] = "";
	int result = 1;
	int count = 0xFF;


	while ((count--) != 0)
	{
	
		code1=str[i];
		i++;

		if (code1==0)
		{
			break;
		}
		else
		{
			if (code1<128)
			{
				szTemp[n]=code1;
				n++;
				continue;
			}
			else
			{
				code2=str[i];
				i++;
				code=code2 | (code1<<8);

				if ((code)>0)
				{
					szTemp[n]=code1;
					n++;
					szTemp[n]=code2;
					n++;
				}
				else
				{
					result =0;
				}
				if(code2==0)
				{
					break;
				}
			}
		}
	}
	
	
	strcpy(str, szTemp);
	return TRUE;
}


void FileSaveString(char* filename, char* string)
{
	FILE* fp;
	
	fp=fopen(filename, "at");

	if (fp==0)
	{
		return;
	}
	else
	{
		fprintf(fp, string);
		fprintf(fp, "\n");
		fclose(fp);
	}
}

#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool IsBadFileLine(char *FileLine, int &Flag)
{
	if(Flag == 0)
	{
		if(isdigit(FileLine[0]))
		{
			Flag = FileLine[0] - 48;
			return true;
		}
	}
	else if(Flag < 0 || Flag > 9)
	{
		Flag = 0;
	}

	if(!strncmp(FileLine, "end", 3))
	{
		Flag = 0;
		return true;
	}

	if(FileLine[0] == '/' || FileLine[0] == '\n')
		return true;

	for(UINT i = 0; i < strlen(FileLine); i++)
	{
		if(isalnum(FileLine[i]))
			return false;
	}
	return true;
}

int GenExcOpt(int amount)
{
	// User input errors
	if (amount > 6) amount = 6;
	if (amount < 1) amount = 1;

	int opt_db[6]  = {1, 2, 4, 8, 16, 32};
	int exc = 0;

	std::random_shuffle(opt_db, opt_db + 6);

	for(int n=0; n < amount; n++)
		exc += opt_db[n];

	return exc;
}

BOOL IsFile(char* filename)
{
FILE *fp;
	
	fp=fopen(filename,"rb");
	if (fp==0)
	{
		return FALSE;
	}
	else
	{
		fclose(fp);
		return TRUE;
	}
}


void GetTodayString(char* szDate)
{
	tm* today;
	time_t ltime;
	

	time(&ltime);
	today=localtime(&ltime);

	today->tm_year = today->tm_year +1900;

	wsprintf(szDate, "%02d%02d%02d", today->tm_year , today->tm_mon +1 , today->tm_mday );
}


void PHeadSetB(LPBYTE lpBuf, BYTE head, int size)
{
	lpBuf[0] =0xC1;		// Packets
	lpBuf[1] =size;
	lpBuf[2] =head;
}
	

void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size)
{
	lpBuf[0] =0xC1;	// Packets
	lpBuf[1] =size;
	lpBuf[2] =head;
	lpBuf[3] =sub;
}

void PHeadSetW(LPBYTE lpBuf, BYTE head,  int size) 
{
	lpBuf[0] = 0xC2;	// Packets Header
	lpBuf[1]= SET_NUMBERH(size);
	lpBuf[2]= SET_NUMBERL(size);
	lpBuf[3]= head;
}

void PHeadSubSetW(LPBYTE lpBuf, BYTE head, BYTE sub,  int size)
{
	lpBuf[0]=0xC2;	// packet header
	lpBuf[1]=SET_NUMBERH(size);
	lpBuf[2]=SET_NUMBERL(size);
	lpBuf[3]=head;
	lpBuf[4]=sub;
}


void PHeadSetBE( LPBYTE lpBuf, BYTE head,int size)
{
	lpBuf[0] =0xC3;
	lpBuf[1] =size;
	lpBuf[2] =head;
}

void PHeadSubSetBE(LPBYTE lpBuf, BYTE head,BYTE sub, int size)
{
	lpBuf[0] =0xC3;
	lpBuf[1] =size;
	lpBuf[2] =head;
	lpBuf[3] =sub;
}



