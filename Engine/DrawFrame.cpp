#include "StdAfx.h"

cDrawFrame gDrawFrame;

void cDrawFrame::Init()
{
	// Draw Frame Fix
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed01),0xE9);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed01+1),0xFA);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed01+2),0x6E);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed01+3),0x28);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed01+4),0x00);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed01+5),0x90);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed01+6),0x90);

	// Sleep and jmp to Call Ebx
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02),0x6A);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+1),0x01);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+2),0xFF);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+3),0x15);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+4),0x78);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+5),0x91);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+6),0x88);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+7),0x00);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+8),0xE9);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+9),0xE7);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+10),0x90);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+11),0xD7);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+12),0xFF);
	gToolKit.SetByte((PVOID)(oDrawFrameFixAllowed02+13),0x90);
}

void cDrawFrame::Load()
{
	this->Init();
}