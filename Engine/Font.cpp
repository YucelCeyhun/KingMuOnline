#include "StdAfx.h"

int IsCustomFont = GetPrivateProfileInt("Engine","UseCustomFont",0,ENGINE_INI);

cFont gFont;

cFont::cFont()
{
	this->Height	= 15;
	this->Width		= 0;
	this->Bold		= 0;
	this->Italic	= 0;
	this->Quality	= 3;
	this->UnderLine = 0;
	this->StrikeOut = 0;
	this->Unicode	= 0;
	// ----
	memset(this->FontName,0,sizeof(this->FontName));
}

cFont::~cFont()
{
	/**/
}

void cFont::Load()
{
	if(IsCustomFont == 1)
	{
		if(gToolKit.FileExists(FONT_FILE) && gScriptEncode.ReadScript(FONT_FILE))
		{
			this->LoadNewFont();
		}
		else
		{
			MessageBox(NULL,"FontText.bmd file not found","Error",MB_OK);
			::ExitProcess(0);
		}
	}
	else
	{
		return;
	}
}

void cFont::LoadNewFont()
{
	gToolKit.SetNop(oLoadMainFont1,5);	// Default -> 400 (Normal)
	gToolKit.SetNop(oLoadMainFont2,5);	// Default -> 700 (Bold)
	gToolKit.SetNop(oLoadMainFont3,5);	// Default -> 700 (Bold)
	gToolKit.SetNop(oLoadMainFont4,5);	// Default -> 400 (Normal)
	// ----
	WZSMDToken Token = gScriptEncode.GetToken();
	// ----
	Token			= gScriptEncode.GetToken();
	gFont.Bold		= gScriptEncode.GetNumber();
	// ----
	Token			= gScriptEncode.GetToken();
	gFont.Width		= gScriptEncode.GetNumber();
	// ----
	Token			= gScriptEncode.GetToken();
	gFont.Height	= gScriptEncode.GetNumber();
	// ----
	Token			= gScriptEncode.GetToken();
	gFont.Italic	= gScriptEncode.GetNumber();
	// ----
	Token			= gScriptEncode.GetToken();
	gFont.Unicode	= gScriptEncode.GetNumber();
	// ----
	Token			= gScriptEncode.GetToken();
	gFont.Quality	= gScriptEncode.GetNumber();
	// ----
	Token			= gScriptEncode.GetToken();
	gFont.UnderLine	= gScriptEncode.GetNumber();
	// ----
	Token			= gScriptEncode.GetToken();
	gFont.StrikeOut	= gScriptEncode.GetNumber();
	// ----
	Token			= gScriptEncode.GetToken();
	memcpy(gFont.FontName,gScriptEncode.GetString(),sizeof(gFont.FontName));
	// ----
	if(gFont.Bold == 0)
	{
		if(gFont.Unicode == 1)
		{
			pLoadMainFont1 = CreateFont(gFont.Height,gFont.Width,0,0,FW_NORMAL,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont2 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont3 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont4 = CreateFont(gFont.Height,gFont.Width,0,0,FW_NORMAL,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
		}
		else
		{
			pLoadMainFont1 = CreateFont(gFont.Height,gFont.Width,0,0,FW_NORMAL,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont2 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont3 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont4 = CreateFont(gFont.Height,gFont.Width,0,0,FW_NORMAL,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
		}
	}
	else
	{
		if(gFont.Unicode == 1)
		{
			pLoadMainFont1 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont2 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont3 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont4 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
		}
		else
		{
			pLoadMainFont1 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont2 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont3 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
			pLoadMainFont4 = CreateFont(gFont.Height,gFont.Width,0,0,FW_BOLD,gFont.Italic,gFont.UnderLine,gFont.StrikeOut,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,gFont.Quality,DEFAULT_PITCH|FF_DONTCARE,gFont.FontName);
		}
	}
}