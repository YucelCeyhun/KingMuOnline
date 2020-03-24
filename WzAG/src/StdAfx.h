#ifndef __STDAFX_H__
#define __STDAFX_H__

#if _MSC_VER > 1000
#pragma once
#endif

#define WIN32_LEAN_AND_MEAN
#define CRT_SECURE_NO_WARNINGS

// -> Windows Includes
#include "windows.h"
#include <stdio.h>

// -> Project Includes
#include "WzAG.h"

#pragma warning(disable:4996)

#if(COMPILATION_CS)
#define COMPILE_FOR_GSCS
#endif

#if(COMPILATION_GS)
#define COMPILE_FOR_GS
#endif

#endif