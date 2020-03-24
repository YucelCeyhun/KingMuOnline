// stdafx.h: archivo de inclusión de los archivos de inclusión estándar del sistema
// o archivos de inclusión específicos de un proyecto utilizados frecuentemente,
// pero rara vez modificados
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows
#define _CRT_SECURE_NO_WARNINGS
// Archivos de encabezado de Windows:

// Windows Header Files:
#include <windows.h>
#include <winsock2.h>
#include <commctrl.h>

#pragma comment ( lib , "comctl32.lib" )
#pragma comment ( lib , "WS2_32.lib" )

#define CS_CURRENT_VERSION "1.00.93 (eX406)"
#define CS_CURRENT_EDITION "Sunday 11-09-2016"

#pragma warning(disable:4996)
#pragma warning(disable:4646)
#pragma warning(disable:4091)
#pragma warning(disable:4018)
#pragma warning(disable:4244)
#pragma warning(disable:4101)

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include "ReadScript.h"

#define SET_NUMBERH(x) ( (BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x) ( (BYTE)((DWORD)(x) & 0xFF) )
#define SET_NUMBERHW(x) ( (WORD)((DWORD)(x)>>(DWORD)16) )
#define SET_NUMBERLW(x) ( (WORD)((DWORD)(x) & 0xFFFF) )
#define MAKE_NUMBERW(x,y)  ( (WORD)(((BYTE)((y)&0xFF)) |   ((BYTE)((x)&0xFF)<<8 ))  )
#define MAKE_NUMBERDW(x,y) ( (DWORD)(((WORD)((y)&0xFFFF)) | ((WORD)((x)&0xFFFF)<<16))  )