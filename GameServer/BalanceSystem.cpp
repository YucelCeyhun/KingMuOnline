#include "StdAfx.h"
#include "BalanceSystem.h"
#include "GameMain.h"
#include "user.h"
#include "LogProc.h"

cBalanceSystem gBalanceSystem;

cBalanceSystem::cBalanceSystem()	// -> Constructor
{
	this->Init();
}

cBalanceSystem::~cBalanceSystem()	// -> Destructor
{
	/**/
}

void cBalanceSystem::Init()
{
	this->Enable	= true;
	// ----
	this->DKvsDK	= 100;
	this->DKvsDW	= 100;
	this->DKvsFE	= 100;
	this->DKvsSM	= 100;
	this->DKvsMG	= 100;
	this->DKvsDL	= 100;
	// ----
	this->DWvsDW	= 100;
	this->DWvsDK	= 100;
	this->DWvsFE	= 100;
	this->DWvsSM	= 100;
	this->DWvsMG	= 100;
	this->DWvsDL	= 100;
	// ----
	this->FEvsFE	= 100;
	this->FEvsDK	= 100;
	this->FEvsDW	= 100;
	this->FEvsSM	= 100;
	this->FEvsMG	= 100;
	this->FEvsDL	= 100;
	// ----
	this->SMvsSM	= 100;
	this->SMvsDK	= 100;
	this->SMvsDW	= 100;
	this->SMvsFE	= 100;
	this->SMvsMG	= 100;
	this->SMvsDL	= 100;
	// ----
	this->MGvsMG	= 100;
	this->MGvsDK	= 100;
	this->MGvsDW	= 100;
	this->MGvsFE	= 100;
	this->MGvsSM	= 100;
	this->MGvsDL	= 100;
	// ----
	this->DLvsDL	= 100;
	this->DLvsDK	= 100;
	this->DLvsDW	= 100;
	this->DLvsFE	= 100;
	this->DLvsSM	= 100;
	this->DLvsMG	= 100;
}

void cBalanceSystem::ReadConfigs(char *File)
{
	this->Enable	= GetPrivateProfileInt("Common","Enable",0,File);
	// ----
	this->DKvsDK	= GetPrivateProfileInt("Common","DKvsDK",100,File);
	this->DKvsDW	= GetPrivateProfileInt("Common","DKvsDW",100,File);
	this->DKvsFE	= GetPrivateProfileInt("Common","DKvsFE",100,File);
	this->DKvsSM	= GetPrivateProfileInt("Common","DKvsSM",100,File);
	this->DKvsMG	= GetPrivateProfileInt("Common","DKvsMG",100,File);
	this->DKvsDL	= GetPrivateProfileInt("Common","DKvsDL",100,File);
	// ----
	this->DWvsDW	= GetPrivateProfileInt("Common","DWvsDW",100,File);
	this->DWvsDK	= GetPrivateProfileInt("Common","DWvsDK",100,File);
	this->DWvsFE	= GetPrivateProfileInt("Common","DWvsFE",100,File);
	this->DWvsSM	= GetPrivateProfileInt("Common","DWvsSM",100,File);
	this->DWvsMG	= GetPrivateProfileInt("Common","DWvsMG",100,File);
	this->DWvsDL	= GetPrivateProfileInt("Common","DWvsDL",100,File);
	// ----
	this->FEvsFE	= GetPrivateProfileInt("Common","FEvsFE",100,File);
	this->FEvsDK	= GetPrivateProfileInt("Common","FEvsDK",100,File);
	this->FEvsDW	= GetPrivateProfileInt("Common","FEvsDW",100,File);
	this->FEvsSM	= GetPrivateProfileInt("Common","FEvsSM",100,File);
	this->FEvsMG	= GetPrivateProfileInt("Common","FEvsMG",100,File);
	this->FEvsDL	= GetPrivateProfileInt("Common","FEvsDL",100,File);
	// ----
	this->SMvsSM	= GetPrivateProfileInt("Common","SMvsSM",100,File);
	this->SMvsDK	= GetPrivateProfileInt("Common","SMvsDK",100,File);
	this->SMvsDW	= GetPrivateProfileInt("Common","SMvsDW",100,File);
	this->SMvsFE	= GetPrivateProfileInt("Common","SMvsFE",100,File);
	this->SMvsMG	= GetPrivateProfileInt("Common","SMvsMG",100,File);
	this->SMvsDL	= GetPrivateProfileInt("Common","SMvsDL",100,File);
	// ----
	this->MGvsMG	= GetPrivateProfileInt("Common","MGvsMG",100,File);
	this->MGvsDK	= GetPrivateProfileInt("Common","MGvsDK",100,File);
	this->MGvsDW	= GetPrivateProfileInt("Common","MGvsDW",100,File);
	this->MGvsFE	= GetPrivateProfileInt("Common","MGvsFE",100,File);
	this->MGvsSM	= GetPrivateProfileInt("Common","MGvsSM",100,File);
	this->MGvsDL	= GetPrivateProfileInt("Common","MGvsDL",100,File);
	// ----
	this->DLvsDL	= GetPrivateProfileInt("Common","DLvsDL",100,File);
	this->DLvsDK	= GetPrivateProfileInt("Common","DLvsDK",100,File);
	this->DLvsDW	= GetPrivateProfileInt("Common","DLvsDW",100,File);
	this->DLvsFE	= GetPrivateProfileInt("Common","DLvsFE",100,File);
	this->DLvsSM	= GetPrivateProfileInt("Common","DLvsSM",100,File);
	this->DLvsMG	= GetPrivateProfileInt("Common","DLvsMG",100,File);
	// ----
	LogAddTD("[BalanceSystem] System Configs Setted!");
}

void cBalanceSystem::Load()
{
	this->Init();
	this->ReadConfigs(gDirPath.GetNewPath(BALANCESYSTEM_FILE));
}

void cBalanceSystem::Main(LPOBJ lpObj, LPOBJ lpTarget, int & AttackDamage)
{
	if(!this->Enable) return;

	if(lpObj->Type != OBJ_USER || lpTarget->Type != OBJ_USER)
	{
		return;
	}

	if(lpObj->Class == CLASS_KNIGHT)
	{
		switch(lpTarget->Class)
		{
			case CLASS_KNIGHT:		AttackDamage = ( AttackDamage * this->DKvsDK ) / 100; break;
			case CLASS_WIZARD:		AttackDamage = ( AttackDamage * this->DKvsDW ) / 100; break;
			case CLASS_ELF:			AttackDamage = ( AttackDamage * this->DKvsFE ) / 100; break;
			case CLASS_SUMMONER:	AttackDamage = ( AttackDamage * this->DKvsSM ) / 100; break;
			case CLASS_MAGUMSA:		AttackDamage = ( AttackDamage * this->DKvsMG ) / 100; break;
			case CLASS_DARKLORD:	AttackDamage = ( AttackDamage * this->DKvsDL ) / 100; break;
			default:return;
		}
	}
	else if(lpObj->Class == CLASS_WIZARD)
	{
		switch(lpTarget->Class)
		{
			case CLASS_WIZARD:		AttackDamage = ( AttackDamage * this->DWvsDW ) / 100; break;
			case CLASS_KNIGHT:		AttackDamage = ( AttackDamage * this->DWvsDK ) / 100; break;
			case CLASS_ELF:			AttackDamage = ( AttackDamage * this->DWvsFE ) / 100; break;
			case CLASS_SUMMONER:	AttackDamage = ( AttackDamage * this->DWvsSM ) / 100; break;
			case CLASS_MAGUMSA:		AttackDamage = ( AttackDamage * this->DWvsMG ) / 100; break;
			case CLASS_DARKLORD:	AttackDamage = ( AttackDamage * this->DWvsDL ) / 100; break;
			default:return;
		}
	}
	else if(lpObj->Class == CLASS_ELF)
	{
		switch(lpTarget->Class)
		{
			case CLASS_ELF:			AttackDamage = ( AttackDamage * this->FEvsFE ) / 100; break;
			case CLASS_KNIGHT:		AttackDamage = ( AttackDamage * this->FEvsDK ) / 100; break;
			case CLASS_WIZARD:		AttackDamage = ( AttackDamage * this->FEvsDW ) / 100; break;
			case CLASS_SUMMONER:	AttackDamage = ( AttackDamage * this->FEvsSM ) / 100; break;
			case CLASS_MAGUMSA:		AttackDamage = ( AttackDamage * this->FEvsMG ) / 100; break;
			case CLASS_DARKLORD:	AttackDamage = ( AttackDamage * this->FEvsDL ) / 100; break;
			default:return;
		}
	}
	else if(lpObj->Class == CLASS_SUMMONER)
	{
		switch(lpTarget->Class)
		{
			case CLASS_SUMMONER:	AttackDamage = ( AttackDamage * this->SMvsSM ) / 100; break;
			case CLASS_KNIGHT:		AttackDamage = ( AttackDamage * this->SMvsDK ) / 100; break;
			case CLASS_WIZARD:		AttackDamage = ( AttackDamage * this->SMvsDW ) / 100; break;
			case CLASS_ELF:			AttackDamage = ( AttackDamage * this->SMvsFE ) / 100; break;
			case CLASS_MAGUMSA:		AttackDamage = ( AttackDamage * this->SMvsMG ) / 100; break;
			case CLASS_DARKLORD:	AttackDamage = ( AttackDamage * this->SMvsDL ) / 100; break;
			default:return;
		}
	}
	else if(lpObj->Class == CLASS_MAGUMSA)
	{
		switch(lpTarget->Class)
		{
			case CLASS_MAGUMSA:		AttackDamage = ( AttackDamage * this->MGvsMG ) / 100; break;
			case CLASS_KNIGHT:		AttackDamage = ( AttackDamage * this->MGvsDK ) / 100; break;
			case CLASS_WIZARD:		AttackDamage = ( AttackDamage * this->MGvsDW ) / 100; break;
			case CLASS_ELF:			AttackDamage = ( AttackDamage * this->MGvsFE ) / 100; break;
			case CLASS_SUMMONER:	AttackDamage = ( AttackDamage * this->MGvsSM ) / 100; break;
			case CLASS_DARKLORD:	AttackDamage = ( AttackDamage * this->MGvsDL ) / 100; break;
			default:return;
		}
	}
	else if(lpObj->Class == CLASS_DARKLORD)
	{
		switch(lpTarget->Class)
		{
			case CLASS_DARKLORD:	AttackDamage = ( AttackDamage * this->DLvsDL ) / 100; break;
			case CLASS_KNIGHT:		AttackDamage = ( AttackDamage * this->DLvsDK ) / 100; break;
			case CLASS_WIZARD:		AttackDamage = ( AttackDamage * this->DLvsDW ) / 100; break;
			case CLASS_ELF:			AttackDamage = ( AttackDamage * this->DLvsFE ) / 100; break;
			case CLASS_SUMMONER:	AttackDamage = ( AttackDamage * this->DLvsSM ) / 100; break;
			case CLASS_MAGUMSA:		AttackDamage = ( AttackDamage * this->DLvsMG ) / 100; break;
			default:return;
		}
	}
}