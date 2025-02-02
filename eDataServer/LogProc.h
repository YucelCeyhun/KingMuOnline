#ifndef __LOGPROC_H__
#define __LOGPROC_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define LOG_TEXT_LENGTH	80
#define LOG_TEXT_LINE	30

// Variables
extern void (*LogAdd)(char* szLog,...);
extern void (*LogAddC)(BYTE, char*, ...);
extern void (*LogAddTD)(char* szLog, ...);
extern void (*LogAddHeadHex)(char*,unsigned char*, int);
extern void (*LogTextPaint)(HWND);
extern void (*LogAddL)(char * szLog, ...);


void LogInit(int logprint);
void LogDataSet();
int LogDateChange();
void LogTextAdd(BYTE type, char* msg, int len);
void LogAddFuncVoid(char* szLog, ...);
void LogAddTimeDateVoid(char* szLog, ...);
void LogAddFunc(char* szLog, ...);
void LogAddFuncColor(BYTE Color, char* szLog, ...);
void LogAddLocalFunc(char * szLog, ...);
void LogAddLocalFuncVoid(char * szLog, ...);
void LogAddTimeDateFunc(char* szLog, ...);
void LogAddHeadHexFuncVoid(char* str,unsigned char* data,int len);
void LogAddHeadHexFunc(int Type,char* data,int len);
void LogAddStrHexFunc(char* str,unsigned char* data, int len);
void LogTextClear();
void LogTextPaintProcVoid(HWND hWnd);
void LogTextPaintProc(HWND hWnd);
int LogGetFileName();
void LogClose();
void MsgBox(char *szlog, ...);


#endif