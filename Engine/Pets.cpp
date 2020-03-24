#include "StdAfx.h"

int IsCustomFloor = GetPrivateProfileInt("Engine", "UseCustomFloor", 0, ENGINE_INI);

cPets gPets;

bool cPets::ChaosCastleMapRange(int Map)
{
	if (Map >= ChaosCastle1 && Map <= ChaosCastle6 || Map == ChaosCastle7)
	{
		return true;
	}
	return false;
}

void cPets::LoadObjSkillModel()
{
	pInitSkillData();
	// ----
	pLoadModel(OrangeFenrir, "Data\\Skill\\", "fenril_orange", -1);
	pLoadTexture(OrangeFenrir, "Skill\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
	// ----
	pLoadModel(DarkWolf, "Data\\Skill\\", "darkwolf_pet", -1);
	pLoadTexture(DarkWolf, "Skill\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
	// ----
	pLoadModel(FangSable, "Data\\Skill\\", "sablefang_pet", -1);
	pLoadTexture(FangSable, "Skill\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
	// ----
	//pLoadModel(MisticTiger,"Data\\Skill\\","mistictiger_pet",-1);
	//pLoadTexture(MisticTiger,"Skill\\",GL_REPEAT,GL_NEAREST,GL_TRUE);
	// ----
	//pLoadModel(GiantLyon,"Data\\Skill\\","giantlyon_pet",-1);
	//pLoadTexture(GiantLyon,"Skill\\",GL_REPEAT,GL_NEAREST,GL_TRUE);
	// ----
	//pLoadModel(LycanPet,"Data\\Skill\\","Wolf_Gang",-1);
	//pLoadTexture(LycanPet,"Skill\\",GL_REPEAT,GL_NEAREST,GL_TRUE);
}

ObjCreateBug gObjCreateBug = (ObjCreateBug)0x004AC2C4;
ObjCreatePet gObjCreatePet = (ObjCreatePet)0x0081BA70;
//ObjPetGetThis gObjPetGetThis	= (ObjPetGetThis)0x0081AB71;
// ----
Objsub_4997AD gObjsub_4997AD = (Objsub_4997AD)0x004997AD;
Objsub_4DD069 gObjsub_4DD069 = (Objsub_4DD069)0x004DD069;
Objsub_4FD6C5 gObjsub_4FD6C5 = (Objsub_4FD6C5)0x004FD6C5;
// ----

/*void cPets::CreatePetObjectEx2(lpItemObj lpObj)
{
	Preview * gObjPreview = &*(Preview*)pPreviewStructThis;
	// ----
	if(!ChaosCastleMapRange(pMapNumber))
	{
		switch(lpObj->Index)
		{
			case ItemId(13,0):
			{
				gObjCreateBug(Angel,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
				break;
			}
			case ItemId(13,2):
			{
				gObjCreateBug(Uniria,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
				break;
			}
			case ItemId(13,3):
			{
				gObjCreateBug(Dinorant,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
				break;
			}
			case ItemId(13,4):
			{
				gObjCreateBug(DarkHorse,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
				break;
			}
			case ItemId(13,37):
			{
				gObjPreview->FenrirCharSet = lpObj->ExcellentOption;
				// ----
				switch(lpObj->ExcellentOption)
				{
					case 1:	// -> BLACK_FENRIR
					{
						gObjCreateBug(BlackFenrir,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
						break;
					}
					case 2:	// -> BLUE_FENRIR
					{
						gObjCreateBug(BlueFenrir,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
						break;
					}
					case 4:	// -> GOLDEN_FENRIR
					{
						gObjCreateBug(GoldenFenrir,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
						break;
					}
					case 63: // -> ORANGE_FENRIR (NEW)
					{
						gObjCreateBug(OrangeFenrir,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
						break;
					}
					default: // -> RED_FENRIR (DEFAULT)
					{
						gObjCreateBug(RedFenrir,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
						break;
					}
				}
				break;
			}
			case ItemId(13,97):
			{
				gObjCreateBug(DarkWolf,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
				break;
			}
			case ItemId(13,98):
			{
				gObjCreateBug(FangSable,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
				break;
			}
			case ItemId(13,106):
			{
				gObjCreateBug(Unicorn,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
				break;
			}
			case ItemId(13,123):
			{
				gObjCreateBug(Skeleton,gObjPreview->SwitchCharPosX,gObjPreview->Unknown700,0,0);
				break;
			}
			case ItemId(13,64):
			{
				gObjCreatePet(gObjPetGetThis(),lpObj->Index,ObjectId(13,64),gObjPreview->SwitchCharPosX,pPreviewStructThis,0,0);
				break;
			}
			case ItemId(13,65):
			{
				gObjCreatePet(gObjPetGetThis(),lpObj->Index,ObjectId(13,65),gObjPreview->SwitchCharPosX,pPreviewStructThis,0,0);
				break;
			}
			case ItemId(13,67):
			{
				gObjCreatePet(gObjPetGetThis(),lpObj->Index,ObjectId(13,67),gObjPreview->SwitchCharPosX,pPreviewStructThis,0,0);
				break;
			}
			case ItemId(13,80):
			{
				gObjCreatePet(gObjPetGetThis(),lpObj->Index,ObjectId(13,80),gObjPreview->SwitchCharPosX,pPreviewStructThis,0,0);
				break;
			}
			default:
				break;
		}
	}
	// ----
	if(gObjPreview->PetStatus <= 0 || gObjPreview->PetStatus > 3 && lpObj->Index == ItemId(13,20) && lpObj->Level >> 3 == 3)
	{
		gCheckPetStatus(pPreviewStructThis);
		gObjPreview->PetStatus = 4;
	}
	if(lpObj->Index == ItemId(12,39) || lpObj->Index == ItemId(13,30) || lpObj->Index == ItemId(12,40))
	{
		gObjsub_4DD069(pPreviewStructThis,gObjPreview->Unknown700,0);
	}
}*/

void cPets::CreatePetObjectEx(int Index)
{
	int ObjectPreview = *(DWORD*)pPreviewStructOffset + 700;
	gObjsub_4FD6C5(pPreviewStructThis);
	// ----
	if (!ChaosCastleMapRange(pMapNumber))
	{
		switch (*(WORD*)Index)
		{
		case 6656:
			gObjCreateBug(Angel, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
		case 6658:
			gObjCreateBug(Uniria, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
		case 6659:
			gObjCreateBug(Dinorant, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
		case 6660:
			gObjCreateBug(DarkHorse, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
		case 6693:
			*(BYTE*)(pPreviewStructThis + 491) = *(BYTE*)(Index + 23);
			switch (*(BYTE*)(Index + 23))
			{
			case 1:
				gObjCreateBug(BlackFenrir, ObjectPreview + 252, ObjectPreview, 0, 0);
				break;
			case 2:
				gObjCreateBug(BlueFenrir, ObjectPreview + 252, ObjectPreview, 0, 0);
				break;
			case 4:
				gObjCreateBug(GoldenFenrir, ObjectPreview + 252, ObjectPreview, 0, 0);
				break;
			case 0x3F:
				gObjCreateBug(OrangeFenrir, ObjectPreview + 252, ObjectPreview, 0, 0);
				break;
			default:
				gObjCreateBug(RedFenrir, ObjectPreview + 252, ObjectPreview, 0, 0);
				break;
			}
			break;
		case 6753: // Dark Wolf Pet
			gObjCreateBug(DarkWolf, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
		case 6754: // Sable Fang Pet
			gObjCreateBug(FangSable, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
			/*
			case 6755: // Mistic Tiger Pet
				gObjCreateBug(MisticTiger,ObjectPreview+252,ObjectPreview,0,0);
				break;
			case 6756: // Giant Lyon Pet
				gObjCreateBug(GiantLyon,ObjectPreview+252,ObjectPreview,0,0);
				break;
			case 6757: // Lycan Wolf Pet
				gObjCreateBug(LycanPet,ObjectPreview+252,ObjectPreview,0,0);
				break;
			*/
			/*case 6765: // Pet Pegasus
				gObjCreateBug(Pegasus,ObjectPreview+252,ObjectPreview,0,0);
				break;*/
		case 6733: // Pet Skeleton
			gObjCreateBug(Skeleton, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
		case 6734: // Pet Unicorn
			gObjCreateBug(Unicorn, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
		case 6735: // Pet Sparky
			gObjCreateBug(Sparky, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
		case 6737: // Pet Chinlon
			gObjCreateBug(Chinlon, ObjectPreview + 252, ObjectPreview, 0, 0);
			break;
		case 6720: // Pet Demon
			gObjCreatePet(gObjPetGetThis(), *(WORD*)Index, ObjectId(13, 64), ObjectPreview + 252, pPreviewStructThis, 0, 0);
			break;
		case 6721: // Pet Fairy
			gObjCreatePet(gObjPetGetThis(), *(WORD*)Index, ObjectId(13, 65), ObjectPreview + 252, pPreviewStructThis, 0, 0);
			break;
		case 6723: // Pet Rudolf
			gObjCreatePet(gObjPetGetThis(), *(WORD*)Index, ObjectId(13, 67), ObjectPreview + 252, pPreviewStructThis, 0, 0);
			break;
		case 6736: // Pet Panda
			gObjCreatePet(gObjPetGetThis(), *(WORD*)Index, ObjectId(13, 80), ObjectPreview + 252, pPreviewStructThis, 0, 0);
			break;
		default:
			break;
		}
	}
	if (((signed int)*(BYTE*)(pPreviewStructThis + 23) <= 0 || (signed int)*(BYTE*)(pPreviewStructThis + 23) > 3)
		&& *(WORD*)Index == 6676
		&& *(DWORD*)(Index + 2) >> 3 == 3)
	{
		gObjsub_4997AD(pPreviewStructThis);
		*(BYTE*)(pPreviewStructThis + 23) = 4;
	}
	if (*(WORD*)Index == 6183 || *(WORD*)Index == 6686 || *(WORD*)Index == 6184)
		gObjsub_4DD069(pPreviewStructThis, pPreviewStructThis + 700, 0);
}

Objsub_5AB975 gObjsub_5AB975 = (Objsub_5AB975)0x005AB975;
Objsub_604FCD gObjsub_604FCD = (Objsub_604FCD)0x00604FCD;
Objsub_5B81A9 gObjsub_5B81A9 = (Objsub_5B81A9)0x005B81A9;
// ----
Objsub_85151D gObjsub_85151D = (Objsub_85151D)0x0085151D;
// ----
CreateSpriteEx pCreateSpriteEx = (CreateSpriteEx)0x006BABF2;
CreateParticleEx pCreateParticleEx = (CreateParticleEx)0x0069BCD9;

char cPets::CreatePetEffectEx(int Arg1, char Arg2)
{
	float v2; // ST14_4@3
	float v3; // ST10_4@3
	char v5; // [sp+17h] [bp-15h]@3
	int v6; // [sp+18h] [bp-14h]@18
	float v7; // [sp+1Ch] [bp-10h]@21
	float v8; // [sp+20h] [bp-Ch]@21
	float v9; // [sp+24h] [bp-8h]@21
	float v10; // [sp+28h] [bp-4h]@20

	vec3_t Color;
	Vector(0.f, 0.f, 0.f, Color);

	vec3_t Color2;
	Vector(0.f, 0.f, 0.f, Color2);

	vec3_t Color3;
	Vector(0.f, 0.f, 0.f, Color3);

	vec3_t Color4;
	Vector(0.f, 0.f, 0.f, Color4);

	vec3_t Color5;
	Vector(0.f, 0.f, 0.f, Color5);

	if (*(BYTE*)(Arg1 + 4))
	{
		if (Arg2)
		{
			v5 = 1;
		}
		else
		{
			v2 = *(float*)(Arg1 + 256) * 0.0099999998;
			v3 = *(float*)(Arg1 + 252) * 0.0099999998;
			v5 = gObjsub_5AB975(v3, v2, -20.0);
		}
		*(BYTE*)(Arg1 + 12) = v5;
		if (*(BYTE*)(Arg1 + 12))
		{
			if (*(DWORD*)(*(DWORD*)(Arg1 + 472) + 48) != 826 && *(DWORD*)(Arg1 + 48) != 7490 && *(DWORD*)(Arg1 + 48) != ObjectId(13, 77) && *(DWORD*)(Arg1 + 48) != ObjectId(13, 78) && *(DWORD*)(Arg1 + 48) != ObjectId(13, 79) && *(DWORD*)(Arg1 + 48) != ObjectId(13, 81))
				return 1;
			if (Arg2)
			{
				*(DWORD*)(Arg1 + 96) = *(DWORD*)(Arg1 + 96);
			}
			else if (pPlayerState == GameProcess && *(DWORD*)(Arg1 + 48) == MisticTiger
				|| pPlayerState == GameProcess && *(DWORD*)(Arg1 + 48) == OrangeFenrir)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;				// Size in Game
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == MisticTiger
				|| pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == OrangeFenrir)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;				// Size in Switch Character
			}
			else if (pPlayerState == GameProcess && *(DWORD*)(Arg1 + 48) == GiantLyon)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == GiantLyon)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == GameProcess && *(DWORD*)(Arg1 + 48) == LycanPet)
			{
				*(DWORD*)(Arg1 + 96) = 1060320051;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == LycanPet)
			{
				*(DWORD*)(Arg1 + 96) = 1060320051;
			}
			else if (pPlayerState == GameProcess && *(DWORD*)(Arg1 + 48) == DarkWolf)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == DarkWolf)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == GameProcess && *(DWORD*)(Arg1 + 48) == FangSable)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == GameProcess && *(DWORD*)(Arg1 + 48) == FangSable)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == FangSable)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == RedFenrir)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == BlueFenrir)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == BlackFenrir)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == GoldenFenrir)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == Unicorn)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == Skeleton)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == Sparky)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter && *(DWORD*)(Arg1 + 48) == Chinlon)
			{
				*(DWORD*)(Arg1 + 96) = 1063675494;
			}
			else if (pPlayerState == SwitchCharacter)
			{
				*(DWORD*)(Arg1 + 96) = 1065353216;
			}
			else if (*(DWORD*)(Arg1 + 48) != BlackFenrir
				&& *(DWORD*)(Arg1 + 48) != BlueFenrir
				&& *(DWORD*)(Arg1 + 48) != RedFenrir
				&& *(DWORD*)(Arg1 + 48) != GoldenFenrir
				&& *(DWORD*)(Arg1 + 48) != Skeleton
				&& *(DWORD*)(Arg1 + 48) != Unicorn
				&& *(DWORD*)(Arg1 + 48) != Sparky
				&& *(DWORD*)(Arg1 + 48) != Chinlon)
			{
				*(DWORD*)(Arg1 + 96) = 1065353216;
			}
			v6 = 0;
			if (gObjsub_604FCD((void*)(*(DWORD*)(Arg1 + 472) + 484), 18))
				v6 = 10;
			gObjsub_5B81A9(Arg1, 0, 0, v6);
			v10 = (double)(gObjsub_85151D() % 30 + 70) * 0.0099999998;
			// ----
			if (*(DWORD*)(Arg1 + 48) == ObjectId(13, 0))			// -> Angel Pet
			{
				v7 = v10 * 0.5;
				v8 = v10 * 0.80000001;
				v9 = v10 * 0.60000002;
				Vector(0.94, 0.812f, 0.5358f, Color);
				pCreateSpriteEx(32002, Arg1 + 252, 1065353216, (int)&Color, Arg1, 0, 0);
			}
			// ----
			else if (*(DWORD*)(Arg1 + 48) == ObjectId(13, 78))	// -> Unicorn Pet
			{
				Vector(0.5358f, 0.812f, 0.94f, Color);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color, 11, 0.5f, Arg1);
				Vector(0.94f, 0.834f, 0.553f, Color2);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color2, 11, 0.4f, Arg1);
				Vector(0.553f, 0.94f, 0.84f, Color3);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color3, 11, 0.3f, Arg1);
				Vector(0.235f, 0.125f, 0.85f, Color4);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color4, 11, 0.2f, Arg1);
				Vector(0.85689f, 0.23541f, 0.9635f, Color5);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color5, 11, 0.1f, Arg1);
			}
			// ----
			else if (*(DWORD*)(Arg1 + 48) == ObjectId(13, 77))	// -> Skeleton Pet
			{
				Vector(0.f, 1.f, 0.0167f, Color);
				pCreateParticleEx(32269, Arg1 + 252, Arg1 + 264, (int)Color, 3, 0.5f, Arg1);
				Vector(0.f, 1.f, 0.0178f, Color2);
				pCreateParticleEx(32269, Arg1 + 252, Arg1 + 264, (int)Color2, 3, 0.6f, Arg1);
				Vector(0.f, 1.f, 0.0187f, Color3);
				pCreateParticleEx(32269, Arg1 + 252, Arg1 + 264, (int)Color3, 3, 0.7f, Arg1);
			}
			else if (*(DWORD*)(Arg1 + 48) == ObjectId(13, 79))
			{
				Vector(0.4095f, 0.7598f, 0.91f, Color);
				pCreateParticleEx(32269, Arg1 + 252, Arg1 + 264, (int)&Color, 3, 0.5f, Arg1);
				Vector(0.4025f, 0.8598f, 0.98f, Color2);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)&Color2, 11, 0.5f, Arg1);
			}
			// ----
			else if (*(DWORD*)(Arg1 + 48) == ObjectId(13, 81))	// -> Chinlon Pet
			{
				Vector(0.5f, 0.9f, 0.7f, Color);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color, 11, 0.5f, Arg1); //jay_pet
				Vector(0.4f, 0.7f, 0.9f, Color2);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color2, 11, 0.4f, Arg1);
				Vector(0.5f, 0.9f, 0.7f, Color3);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color3, 11, 0.3f, Arg1);
				Vector(0.4f, 0.7f, 0.9f, Color4);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color4, 11, 0.2f, Arg1);
				Vector(0.5f, 0.9f, 0.7f, Color5);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)Color5, 11, 0.1f, Arg1);
			}
			/*
			// ----
			else if (*(DWORD*)(Arg1 + 48) == ObjectId(13,109))
			{
				Vector(0.4095f, 0.7598f, 0.91f, Color);
				pCreateParticleEx(32269, Arg1 + 252, Arg1 + 264, (int)&Color, 3, 0.5f, Arg1);
				Vector(1.f, 1.f, 0.98f, Color2);
				pCreateParticleEx(32033, Arg1 + 252, Arg1 + 264, (int)&Color2, 11, 0.5f, Arg1);
			}
			*/
		}
	}
	return 1;
}

bool cPets::ResetPetPreviewEx(int ItemId)
{
	bool Result;
	// ----
	if (ItemId)
		Result = *(WORD*)ItemId == ItemId(13, 0)	//Angel
		|| *(WORD*)ItemId == ItemId(13, 1)		//Satan
		|| *(WORD*)ItemId == ItemId(13, 2)		//Unicorn
		|| *(WORD*)ItemId == ItemId(13, 3)		//Dinorant
		|| *(WORD*)ItemId == ItemId(13, 4)		//Dark Horse
		|| *(WORD*)ItemId == ItemId(13, 5)		//Dark Raven
		|| *(WORD*)ItemId == ItemId(13, 37)		//Fenrir
		|| *(WORD*)ItemId == ItemId(13, 77)		//Skeleton Pet
		|| *(WORD*)ItemId == ItemId(13, 78)		//Unicorn Pet
		|| *(WORD*)ItemId == ItemId(13, 79)		//Sparky Pet
		|| *(WORD*)ItemId == ItemId(13, 81)		//Chinlon Pet
		|| *(WORD*)ItemId == ItemId(13, 97)		//Dark Wolf
		|| *(WORD*)ItemId == ItemId(13, 98);		//Fang Sable

		//|| *(WORD*)ItemId == ItemId(13,99)	//Mistic Tiger
		//|| *(WORD*)ItemId == ItemId(13,100)	//Giant Lyon
		//|| *(WORD*)ItemId == ItemId(13,101)	//Lycan Pet
		//|| *(WORD*)ItemId == ItemId(13,109)	//Pegasus Pet
	else
		Result = 0;
	return Result;
}

void Naked cPets::CreatePetInventorySizeEx()
{
	static DWORD dwPetSize_Buffer;
	static DWORD dwPetSize_Jump = 0x005A0998;
	// ----
	_asm
	{
		CMP ESI, ObjectId(13, 80)
		JNZ Size_Chinlon_Label
		MOV DWORD PTR SS : [ESP + 0x10] , 0x3B03126F
		JMP dwPetSize_Jump
		// ----
		Size_Chinlon_Label :
		// ----
		CMP ESI, ObjectId(13, 81)
			JNZ Size_Unicorn_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3AC49BA6
			JMP dwPetSize_Jump
			// ----
			Size_Unicorn_Label :
		// ----
		CMP ESI, ObjectId(13, 78)
			JNZ Size_Sparky_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3AC49BA6
			JMP dwPetSize_Jump
			// ----
			Size_Sparky_Label :
		// ----
		CMP ESI, ObjectId(13, 79)
			JNZ Size_Skeleton_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3B03126F
			JMP dwPetSize_Jump
			// ----
			Size_Skeleton_Label :
		// ----
		CMP ESI, ObjectId(13, 77)
			JNZ Size_AddedBox1_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3AC49BA6//Original: 0x3A6BEDFA
			JMP dwPetSize_Jump
			// ----
			Size_AddedBox1_Label :
		// ----
		CMP ESI, ObjectId(14, 101)
			JNZ Size_AddedBox2_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3AB78034
			JMP dwPetSize_Jump
			// ----
			Size_AddedBox2_Label :
		// ----
		CMP ESI, ObjectId(14, 102)
			JNZ Size_AddedBox3_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3A6BEDFA
			JMP dwPetSize_Jump
			// ----
			Size_AddedBox3_Label :
		// ----
		CMP ESI, ObjectId(14, 103)
			JNZ Size_AddedBox4_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3A6BEDFA
			JMP dwPetSize_Jump
			// ----
			Size_AddedBox4_Label :
		// ----
		CMP ESI, ObjectId(14, 104)
			JNZ Size_BundledLevel_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3A6BEDFA
			JMP dwPetSize_Jump
			// ----
			Size_BundledLevel_Label :
		// ----
		CMP ESI, ObjectId(12, 150)
			JNZ Size_BundledLuck_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3B83126F
			JMP dwPetSize_Jump
			// ----
			Size_BundledLuck_Label :
		// ----
		CMP ESI, ObjectId(12, 151)
			JNZ Size_BundledSkill_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3B83126F
			JMP dwPetSize_Jump
			// ----
			Size_BundledSkill_Label :
		// ----
		CMP ESI, ObjectId(12, 152)
			JNZ Size_BundledOption_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3B83126F
			JMP dwPetSize_Jump
			// ----
			Size_BundledOption_Label :
		// ----
		CMP ESI, ObjectId(12, 153)
			JNZ Size_BundledExcellent_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3B83126F
			JMP dwPetSize_Jump
			// ----
			Size_BundledExcellent_Label :
		// ----
		CMP ESI, ObjectId(12, 154)
			JNZ Size_BundledAncient_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3B83126F
			JMP dwPetSize_Jump
			// ----
			Size_BundledAncient_Label :
		// ----
		CMP ESI, ObjectId(12, 155)
			JNZ Size_BundledSocket_Label
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3B83126F
			JMP dwPetSize_Jump
			// ----
			Size_BundledSocket_Label :
		// ----
		CMP ESI, ObjectId(12, 156)
			JNZ ReturnLoad
			MOV DWORD PTR SS : [ESP + 0x10] , 0x3B83126F
			JMP dwPetSize_Jump
			// ----
			ReturnLoad :
		// ----
		MOV dwPetSize_Buffer, 0x0005A02AF
			JMP dwPetSize_Buffer
	}
}

void Naked cPets::CreatePetInvenModelPosEx()
{
	static DWORD dwPandaRot_Jump = 0x0059FA04;
	static DWORD dwPandaRot_Return = 0x0059F4AB;
	// ----
	_asm
	{
		CMP ESI, ObjectId(13, 80)
		JE AddPandaRotation
		// -----------------------------------
		CMP ESI, ObjectId(13, 78)
		JE AddUnicornRotation
		// -----------------------------------
		//CMP ESI,ObjectId(13,109)
		//JE AddPegasusRotation
		// -----------------------------------
		CMP ESI, ObjectId(13, 77)
		JE AddSkeletonRotation
		// -----------------------------------
		CMP ESI, ObjectId(13, 79)
		JE AddSparkyRotation
		// -----------------------------------
		CMP ESI, ObjectId(13, 81)
		JE AddChinlonRotation
		// -----------------------------------
		JMP ReturnRotLoad
		// -----------------------------------
		AddChinlonRotation :
		// -----------------------------------
		FLD DWORD PTR SS : [ESP + 0x14]
			FADD DWORD PTR DS : [0x889F94]		// FLOAT 0.01000000
			MOV DWORD PTR DS : [0x7C12D68] , 0x437F0000
			MOV DWORD PTR DS : [0x7C12D6C] , 0x42340000
			FSTP DWORD PTR SS : [ESP + 0x14]
			FLD DWORD PTR SS : [ESP + 0x18]
			FSUB DWORD PTR DS : [0x88B4F0]		// FLOAT 0.05000000
			FSTP DWORD PTR SS : [ESP + 0x18]
			JMP dwPandaRot_Jump
			// -----------------------------------
			AddPandaRotation :
		// -----------------------------------
		FLD DWORD PTR SS : [ESP + 0x18]
			FSUB DWORD PTR DS : [0x88B4F0]		// FLOAT 0.05000000
			MOV DWORD PTR DS : [0x7C12D68] , 0x43870000
			MOV DWORD PTR DS : [0x7C12D6C] , 0x42200000
			FSTP DWORD PTR SS : [ESP + 0x18]
			JMP dwPandaRot_Jump
			// -----------------------------------
			/*
			AddPegasusRotation:
			// -----------------------------------
			FLD DWORD PTR SS:[ESP+0x18]
			FSUB DWORD PTR DS:[0x88B4F0]		// FLOAT 0.05000000
			MOV DWORD PTR DS:[0x7C12D68],0x43870000
			MOV DWORD PTR DS:[0x7C12D6C],0x42200000
			FSTP DWORD PTR SS:[ESP+0x18]
			JMP dwPandaRot_Jump
			*/
			// -----------------------------------
		AddUnicornRotation:
		// -----------------------------------
		FLD DWORD PTR SS : [ESP + 0x14]
			FADD DWORD PTR DS : [0x889F94]		// FLOAT 0.01000000
			MOV DWORD PTR DS : [0x7C12D68] , 0x437F0000
			MOV DWORD PTR DS : [0x7C12D6C] , 0x42340000
			FSTP DWORD PTR SS : [ESP + 0x14]
			FLD DWORD PTR SS : [ESP + 0x18]
			FSUB DWORD PTR DS : [0x88B4F0]		// FLOAT 0.05000000
			FSTP DWORD PTR SS : [ESP + 0x18]
			JMP dwPandaRot_Jump
			// -----------------------------------
			AddSkeletonRotation :
		// -----------------------------------
		FLD DWORD PTR SS : [ESP + 0x18]
			FSUB DWORD PTR DS : [0x88B4F0]		// FLOAT 0.05000000
			MOV DWORD PTR DS : [0x7C12D68] , 0x43870000
			MOV DWORD PTR DS : [0x7C12D6C] , 0x42200000
			FSTP DWORD PTR SS : [ESP + 0x18]
			JMP dwPandaRot_Jump
			// -----------------------------------
			AddSparkyRotation :
		// -----------------------------------
		FLD DWORD PTR SS : [ESP + 0x14]
			FADD DWORD PTR DS : [0x889F94]		// FLOAT 0.01000000
			MOV DWORD PTR DS : [0x7C12D68] , 0x437F0000
			MOV DWORD PTR DS : [0x7C12D6C] , 0x42340000
			FSTP DWORD PTR SS : [ESP + 0x14]
			FLD DWORD PTR SS : [ESP + 0x18]
			FSUB DWORD PTR DS : [0x88B4F0]		// FLOAT 0.05000000
			FSTP DWORD PTR SS : [ESP + 0x18]
			JMP dwPandaRot_Jump
			// -----------------------------------
			ReturnRotLoad :
		// -----------------------------------
		JMP dwPandaRot_Return
	}
}

void Naked cPets::CreatePetInvenNewNameExc()
{
	static DWORD dwCreatePetInven_Buffer;
	// ----
	static DWORD dwCreatePetInven_Line = 0x07AAD828;
	static DWORD dwCreatePetInven_Call = 0x00402F50;
	static DWORD dwCreatePetInven_Jump = 0x00591ABC;
	// ----
	_asm
	{
		CMP AL, 0x4							//Horn of Fenrir + Illusion
		JNZ FenrirAddDestiny_Label
		PUSH 0x74A							//Text.bmd Number Line: 1866 -> (0x74A)
		MOV ECX, dwCreatePetInven_Line
		CALL dwCreatePetInven_Call
		MOV EDX, DWORD PTR SS : [ESP + 0x14]
		PUSH EAX
		PUSH EDX
		PUSH 0x008C57A4
		JMP dwCreatePetInven_Jump
		// ---------------------------------------
		FenrirAddDestiny_Label :
		// ---------------------------------------
		CMP AL, 0x3F							//Horn of Fenrir + Destiny
			JNZ FenrirNewAddName_Label1
			PUSH 0xACE							//Text.bmd Number Line: 2766 -> (0xACE)
			MOV ECX, dwCreatePetInven_Line
			CALL dwCreatePetInven_Call
			MOV EDX, DWORD PTR SS : [ESP + 0x14]
			PUSH EAX
			PUSH EDX
			PUSH 0x008C57A4
			JMP dwCreatePetInven_Jump
			// ---------------------------------------
			FenrirNewAddName_Label1 :
		// ---------------------------------------
		MOV dwCreatePetInven_Buffer, 0x005917FF
			JMP dwCreatePetInven_Buffer
	}
}

static BOOL bCreatePetFunctionUnknown_Switcher;

void Naked cPets::CreatePetFunctionUnknown()
{
	static DWORD dwCreatePetFunctionUnknown_Pointer;
	static DWORD dwCreatePetFunctionUnknown_Buffer;
	// ----
	bCreatePetFunctionUnknown_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP - 0x18]
		MOV EAX, DWORD PTR DS : [EDX + 0x580]
		MOV dwCreatePetFunctionUnknown_Pointer, EAX
	}
	// ----
	if (dwCreatePetFunctionUnknown_Pointer >= BlackFenrir && dwCreatePetFunctionUnknown_Pointer <= GoldenFenrir) // All Original Fenrirs
	{
		bCreatePetFunctionUnknown_Switcher = TRUE;
	}
	else if (dwCreatePetFunctionUnknown_Pointer == OrangeFenrir) // Orange Fenrir (Excellent: 63)
	{
		bCreatePetFunctionUnknown_Switcher = TRUE;
	}
	else if (dwCreatePetFunctionUnknown_Pointer == DarkWolf || dwCreatePetFunctionUnknown_Pointer == FangSable || dwCreatePetFunctionUnknown_Pointer == MisticTiger || dwCreatePetFunctionUnknown_Pointer == GiantLyon || dwCreatePetFunctionUnknown_Pointer == LycanPet) // All New Mount Type Pets
	{
		bCreatePetFunctionUnknown_Switcher = TRUE;
	}
	// ----
	if (bCreatePetFunctionUnknown_Switcher == TRUE)
	{
		_asm
		{
			MOV dwCreatePetFunctionUnknown_Buffer, oCreatePetFunctionUnk_Allowed
			JMP dwCreatePetFunctionUnknown_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwCreatePetFunctionUnknown_Buffer, oCreatePetFunctionUnk_Return
			JMP dwCreatePetFunctionUnknown_Buffer
		}
	}
}

static BOOL bCreatePetAllowedWalkOnMap_Switcher;
static BOOL bCreatePetAllowedWalkOnMap_Allowed;

void Naked cPets::CreatePetAllowedWalkOnMap()
{
	static DWORD dwCreatePetAllowedWalkOnMap_Pointer;
	static DWORD dwCreatePetAllowedWalkOnMap_Buffer;
	static DWORD dwCreatePetAllowedWalkOnMap_Jump = oCreatePetAllowWalkOnMap_Jump;
	// ----
	bCreatePetAllowedWalkOnMap_Switcher = FALSE;
	bCreatePetAllowedWalkOnMap_Allowed = FALSE;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP - 0x124]
		MOV dwCreatePetAllowedWalkOnMap_Pointer, EAX
	}
	// ----
	if (dwCreatePetAllowedWalkOnMap_Pointer >= BlackFenrir && dwCreatePetAllowedWalkOnMap_Pointer <= GoldenFenrir) // All Original Fenrirs
	{
		bCreatePetAllowedWalkOnMap_Switcher = TRUE;
		bCreatePetAllowedWalkOnMap_Allowed = TRUE;
	}
	else if (dwCreatePetAllowedWalkOnMap_Pointer == OrangeFenrir) // Orange Fenrir (Excellent: 63)
	{
		bCreatePetAllowedWalkOnMap_Switcher = TRUE;
		bCreatePetAllowedWalkOnMap_Allowed = TRUE;
	}
	else if (dwCreatePetAllowedWalkOnMap_Pointer == DarkWolf || dwCreatePetAllowedWalkOnMap_Pointer == FangSable || dwCreatePetAllowedWalkOnMap_Pointer == MisticTiger || dwCreatePetAllowedWalkOnMap_Pointer == GiantLyon || dwCreatePetAllowedWalkOnMap_Pointer == LycanPet) // All Custom New Mount Type Pets
	{
		bCreatePetAllowedWalkOnMap_Switcher = TRUE;
		bCreatePetAllowedWalkOnMap_Allowed = TRUE;
	}
	// ----
	if (bCreatePetAllowedWalkOnMap_Allowed == TRUE)
	{
		_asm
		{
			JNZ CreatePetAllowedWalkOnMap_Label
			// ----
			CreatePetAllowedWalkOnMap_Label :
			// ----
			JMP dwCreatePetAllowedWalkOnMap_Jump
		}
	}
	// ----
	if (bCreatePetAllowedWalkOnMap_Switcher == TRUE)
	{
		_asm
		{
			MOV dwCreatePetAllowedWalkOnMap_Buffer, oCreatePetAllowWalkOnMap_Allow
			JMP dwCreatePetAllowedWalkOnMap_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwCreatePetAllowedWalkOnMap_Buffer, oCreatePetAllowWalkOnMap_Return
			JMP dwCreatePetAllowedWalkOnMap_Buffer
		}
	}
}

/*
0046D87B MOV EAX,DWORD PTR SS:[EBP-0x1C]  -> REGRESO AQUI
*/

// -> Player Manager Actions Hook
void Naked cPets::CreatePetSetPlayerActions()
{
	static DWORD dwCreatePetSetPlayerActions_Return = (DWORD)&gPets.CreatePetStatics;//oCPSetPlayerActions_Return;
	static DWORD dwCreatePetSetPlayerActions_Call1 = (DWORD)&gSetObjMaunt2;//oCPSetPlayerActions_Call1;
	static DWORD dwCreatePetSetPlayerActions_Jump1 = 0x0046D8A9;
	// ----
	_asm
	{
		CMP DWORD PTR SS : [EBP - 0x4] , 1				// Positive Case
		JE PetSetActions_Label
		CMP DWORD PTR SS : [EBP - 0x18] , 1				// Negative Case
		JNZ PetSetActions_ThisJump
		// ----
		PetSetActions_Label :
		// ----
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			MOV BYTE PTR DS : [ECX + 0x554] , 0
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			MOVSX EAX, WORD PTR DS : [EDX + 0x264]
			SUB EAX, ObjectId(13, 0)					// ObjectId -> 0x1D42 (Angel Pet)
			MOV DWORD PTR SS : [EBP - 0x20] , EAX
			CMP DWORD PTR SS : [EBP - 0x20] , 0x7F		// Original Here: 0x25 = 37 ObjectId(13,37) Fenrir (Extended: 127 (7F))
			JA lbCreatePetSetPlayerActions_Return
			MOV EDX, DWORD PTR SS : [EBP - 0x20]
			XOR ECX, ECX
			MOV CL, BYTE PTR DS : [EDX + 0x46D8C5]
			JMP DWORD PTR DS : [ECX * 0x4 + 0x46D8AD]
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x1D42
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x0E9								// -> 233 (Uniria)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x143								// -> 323 (Dinorant)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x0E2								// -> 226 (Dark Horse)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x1FB								// -> 507 (Lycan Wolf) (Added Custom Pet)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x1F2								// -> 498 (Giant Lyon) (Added Custom Pet)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x204								// -> 516 (Dark Wolf) (Added Custom Pet)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x1EE								// -> 494 (Fang Sable) (Added Custom Pet)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x1F0								// -> 496 (Mistic Tiger) (Added Custom Pet)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			XOR ECX, ECX
			MOV CL, BYTE PTR DS : [EAX + 0x267]			// -> Sub-Switch for Excellent States (Fenrir)
			CMP ECX, 0x1								// -> Fenrir Black (Excellent State: 1)
			// ----
			JNZ BlueFenrir_Label
			// ----
			PUSH 0
			PUSH 0
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x550
			PUSH EDX
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x338
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x434
			PUSH ECX
			PUSH 0x180								// -> Black Fenrir (This is the First)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			BlueFenrir_Label :
		// ----
		MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			XOR EAX, EAX
			MOV AL, BYTE PTR DS : [EDX + 0x267]			// -> Sub-Switch for Excellent States (Fenrir)
			CMP EAX, 0x2								// -> Fenrir Blue (Excellent State: 2)
			// ----
			JNZ GoldenFenrir_Label
			// ----
			PUSH 0
			PUSH 0
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x550
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x338
			PUSH EDX
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x434
			PUSH EAX
			PUSH 0x182								// -> Blue Fenrir (This is the Second)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			GoldenFenrir_Label :
		// ----
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			XOR EDX, EDX
			MOV DL, BYTE PTR DS : [ECX + 0x267]			// -> Sub-Switch for Excellent States (Fenrir Gold)
			CMP EDX, 0x4								// -> Golden Fenrir (Excellent State: 4)
			JNZ OrangeFenrir_Label
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x183								// -> Golden Fenrir (This is the Last, but not default)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			OrangeFenrir_Label :
		// ----
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			XOR EDX, EDX
			MOV DL, BYTE PTR DS : [ECX + 0x267]			// -> Sub-Switch for Excellent States (Fenrir Gold)
			CMP EDX, 0x3F							// -> Orange Fenrir (Excellent State: 63)
			JNZ RedFenrir_Label
			// ----
			PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x206								// -> Orange Fenrir (This is the Added by Me xD)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			RedFenrir_Label :
		// ----
		PUSH 0
			PUSH 0
			MOV EAX, DWORD PTR SS : [EBP - 0x1C]
			ADD EAX, 0x550
			PUSH EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x1C]
			ADD ECX, 0x338
			PUSH ECX
			MOV EDX, DWORD PTR SS : [EBP - 0x1C]
			ADD EDX, 0x434
			PUSH EDX
			PUSH 0x181								// -> Red Fenrir (This is the default case)
			CALL dwCreatePetSetPlayerActions_Call1
			ADD ESP, 0x18
			JMP lbCreatePetSetPlayerActions_Return
			// ----
			lbCreatePetSetPlayerActions_Return :
		// ----
		JMP dwCreatePetSetPlayerActions_Return
			// ----
			PetSetActions_ThisJump :
		// ----
		JMP dwCreatePetSetPlayerActions_Jump1
	}
}

Objsub_4C91E7 gObjsub_4C91E7 = (Objsub_4C91E7)0x004C91E7;

int cPets::CreatePetMountEx(int Arg1, int Arg2)
{
	int Result;
	int PetInventory = *(WORD*)(Arg1 + 488);

	switch (PetInventory)
	{
	case ObjectId(13, 2): // Uniria
		Result = gObjsub_4C91E7(Arg2, 173, 1);
		break;
	case ObjectId(13, 3): // Dinorant
		Result = gObjsub_4C91E7(Arg2, 174, 1);
		break;
	case ObjectId(13, 37):// Fenrir
		Result = gObjsub_4C91E7(Arg2, 175, 1);
		break;
	case ObjectId(13, 100): // Giant Lyon
		Result = gObjsub_4C91E7(Arg2, 176, 1);
		break;
	case ObjectId(13, 101): // Lycan Wolf
		Result = gObjsub_4C91E7(Arg2, 180, 1);
		break;
	case ObjectId(13, 97):// Dark Wolf
		Result = gObjsub_4C91E7(Arg2, 177, 1);
		break;
	case ObjectId(13, 98):// Fang Sable
		Result = gObjsub_4C91E7(Arg2, 178, 1);
		break;
	case ObjectId(13, 99):// Mistic Tiger
		Result = gObjsub_4C91E7(Arg2, 179, 1);
		break;
	default:
		Result = gObjsub_4C91E7(Arg2, 172, 1);
		break;
	}
	return Result;
}

void Naked cPets::CreateCodeMountEx()
{
	static DWORD dwCreateCodeMount_Jump = 0x004C58EF;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP - 0x18]
		XOR EAX, EAX
		MOV AL, BYTE PTR DS : [EDX + 0x12]
		CMP EAX, 0xAE					//174 => Dinorant
		// ----
		MOV EDX, DWORD PTR SS : [EBP - 0x18]
		XOR EAX, EAX
		MOV AL, BYTE PTR DS : [EDX + 0x12]
		CMP EAX, 0xB0					//176 => GiantLyon
		// ----
		MOV EDX, DWORD PTR SS : [EBP - 0x18]
		XOR EAX, EAX
		MOV AL, BYTE PTR DS : [EDX + 0x12]
		CMP EAX, 0xB1					//177 => DarkWolf
		// ----
		MOV EDX, DWORD PTR SS : [EBP - 0x18]
		XOR EAX, EAX
		MOV AL, BYTE PTR DS : [EDX + 0x12]
		CMP EAX, 0xB2					//178 => SableFang
		// ----
		MOV EDX, DWORD PTR SS : [EBP - 0x18]
		XOR EAX, EAX
		MOV AL, BYTE PTR DS : [EDX + 0x12]
		CMP EAX, 0xB3					//179 => MisticTiger
		// ----
		MOV EDX, DWORD PTR SS : [EBP - 0x18]
		XOR EAX, EAX
		MOV AL, BYTE PTR DS : [EDX + 0x12]
		CMP EAX, 0xB4					//180 => LycanWolf
		// ----
		JMP dwCreateCodeMount_Jump
	}
}

void cPets::InitCreateCodeMountEx()
{
	gToolKit.SetRange((LPVOID)0x004C58E2, 13, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004C58E2, this->CreateCodeMountEx);
}

Objsub_490280 gObjsub_490280 = (Objsub_490280)0x00490280;
Objsub_5A84C3 gObjsub_5A84C3 = (Objsub_5A84C3)0x005A84C3;

char cPets::CreatePetStatics(int Arg1, int Arg2, int Arg3, int Arg4, int Arg5)
{
	char result;
	float SatanPosition;
	int InventoryPetSlot;

	if (gObjsub_490280(pMapNumber) == 1)
	{
		result = 0;
	}
	else if (*(BYTE*)(Arg4 + 4))
	{
		result = 1;
	}
	else
	{
		*(DWORD*)(Arg4 + 48) = Arg1;
		*(BYTE*)(Arg4 + 4) = 1;
		*(BYTE*)(Arg4 + 12) = 0;
		*(BYTE*)(Arg4 + 9) = 1;
		*(BYTE*)(Arg4 + 15) = 0;
		*(BYTE*)(Arg4 + 13) = 0;
		*(BYTE*)(Arg4 + 14) = 0;
		*(DWORD*)(Arg4 + 472) = Arg3;
		*(DWORD*)(Arg4 + 52) = Arg5;
		*(DWORD*)(Arg4 + 60) = -1;
		*(DWORD*)(Arg4 + 68) = -1;
		*(DWORD*)(Arg4 + 100) = 1065353216;
		*(DWORD*)(Arg4 + 96) = 1060320051;
		*(DWORD*)(Arg4 + 64) = 30;
		*(DWORD*)(Arg4 + 152) = 0;
		*(DWORD*)(Arg4 + 148) = 1065353216;
		*(DWORD*)(Arg4 + 252) = *(DWORD*)Arg2;
		*(DWORD*)(Arg4 + 256) = *(DWORD*)(Arg2 + 4);
		*(DWORD*)(Arg4 + 260) = *(DWORD*)(Arg2 + 8);
		*(DWORD*)(Arg4 + 264) = *(DWORD*)(Arg3 + 264);
		*(DWORD*)(Arg4 + 268) = *(DWORD*)(Arg3 + 268);
		*(DWORD*)(Arg4 + 272) = *(DWORD*)(Arg3 + 272);
		*(DWORD*)(Arg4 + 156) = 1077936128;
		*(DWORD*)(Arg4 + 160) = 1077936128;
		*(DWORD*)(Arg4 + 164) = 1077936128;
		*(DWORD*)(Arg4 + 144) = 0;
		*(DWORD*)(Arg4 + 140) = 0;
		*(DWORD*)(Arg4 + 120) = 1056964608;
		// ----
		InventoryPetSlot = *(DWORD*)(Arg4 + 48);
		// ----
		if (InventoryPetSlot > GoldenFenrir)
		{
			if (InventoryPetSlot == ObjectId(13, 0))			// Angel
			{
				*(DWORD*)(Arg4 + 68) = 1;
				*(float*)(Arg4 + 252) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 252);
				*(float*)(Arg4 + 256) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 256);
				*(float*)(Arg4 + 260) = (double)(gObjsub_85151D() % 128 + 128) + *(float*)(Arg3 + 260);
			}
			else if (InventoryPetSlot == ObjectId(13, 1))	// Satan
			{
				*(float*)(Arg4 + 252) = (double)(gObjsub_85151D() % 128 - 64) + *(float*)(Arg3 + 252);
				*(float*)(Arg4 + 256) = (double)(gObjsub_85151D() % 128 - 64) + *(float*)(Arg3 + 256);
				*(DWORD*)(Arg4 + 260) = *(DWORD*)(Arg3 + 260);
				// ----
				SatanPosition = gObjsub_5A84C3(*(float*)(Arg4 + 252), *(float*)(Arg4 + 256));
				*(float*)(Arg4 + 260) = (double)(gObjsub_85151D() % 100) + SatanPosition;
			}
			else if (InventoryPetSlot == ObjectId(13, 78))	// Unicorn
			{
				*(DWORD*)(Arg4 + 68) = 1;
				*(float*)(Arg4 + 252) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 252);
				*(float*)(Arg4 + 256) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 256);
				*(float*)(Arg4 + 260) = (double)(gObjsub_85151D() % 128 + 128) + *(float*)(Arg3 + 260);
			}
			else if (InventoryPetSlot == ObjectId(13, 77))	// Skeleton
			{
				*(DWORD*)(Arg4 + 68) = 1;
				*(float*)(Arg4 + 252) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 252);
				*(float*)(Arg4 + 256) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 256);
				*(float*)(Arg4 + 260) = (double)(gObjsub_85151D() % 128 + 128) + *(float*)(Arg3 + 260);
			}
			else if (InventoryPetSlot == ObjectId(13, 79))	// Sparky
			{
				*(DWORD*)(Arg4 + 68) = 1;
				*(float*)(Arg4 + 252) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 252);
				*(float*)(Arg4 + 256) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 256);
				*(float*)(Arg4 + 260) = (double)(gObjsub_85151D() % 128 + 128) + *(float*)(Arg3 + 260);
			}
			else if (InventoryPetSlot == ObjectId(13, 81))	// Chinlon
			{
				*(DWORD*)(Arg4 + 68) = 1;
				*(float*)(Arg4 + 252) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 252);
				*(float*)(Arg4 + 256) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 256);
				*(float*)(Arg4 + 260) = (double)(gObjsub_85151D() % 128 + 128) + *(float*)(Arg3 + 260);
			}
			/*else if (InventoryPetSlot == ObjectId(13,109))	// Pegasus
			{
				*(DWORD*)(Arg4 + 68) = 1;
				*(float*)(Arg4 + 252) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 252);
				*(float*)(Arg4 + 256) = (double)(gObjsub_85151D() % 512 - 256) + *(float*)(Arg3 + 256);
				*(float*)(Arg4 + 260) = (double)(gObjsub_85151D() % 128 + 128) + *(float*)(Arg3 + 260);
			}
			*/
		}
		else if (InventoryPetSlot >= BlackFenrir)
		{
			*(DWORD*)(Arg4 + 96) = 1063675494;
		}
		else if (InventoryPetSlot == OrangeFenrir)
		{
			*(DWORD*)(Arg4 + 96) = 1063675494;
		}
		else if (InventoryPetSlot == GiantLyon)
		{
			*(DWORD*)(Arg4 + 96) = 1063675494;
		}
		else if (InventoryPetSlot == LycanPet)
		{
			*(DWORD*)(Arg4 + 96) = 1063675494;
		}
		else if (InventoryPetSlot == DarkWolf)
		{
			*(DWORD*)(Arg4 + 96) = 1063675494;
		}
		else if (InventoryPetSlot == MisticTiger)
		{
			*(DWORD*)(Arg4 + 96) = 1063675494;
		}
		else if (InventoryPetSlot == DarkHorse)
		{
			*(DWORD*)(Arg4 + 96) = 1063675494;
		}
		else if (InventoryPetSlot == Uniria)
		{
			*(DWORD*)(Arg4 + 96) = 1063675494;
		}
		else if (InventoryPetSlot == Dinorant)
		{
			*(DWORD*)(Arg4 + 96) = 1063675494;
		}
		result = 0;
	}
	return result;
}

static BOOL bCreatePetMovementOnWalk_Switcher;

void Naked cPets::CreatePetMovementOnWalk()
{
	static DWORD dwCreatePetMovementOnWalk_Pointer;
	static DWORD dwCreatePetMovementOnWalk_Buffer;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP - 0x124]
		MOV dwCreatePetMovementOnWalk_Pointer, EAX
	}
	// ----
	if (dwCreatePetMovementOnWalk_Pointer >= BlackFenrir && dwCreatePetMovementOnWalk_Pointer <= GoldenFenrir) // All Original Fenrirs
	{
		bCreatePetMovementOnWalk_Switcher = TRUE;
	}
	else if (dwCreatePetMovementOnWalk_Pointer == OrangeFenrir) // Custom Fenrir
	{
		bCreatePetMovementOnWalk_Switcher = TRUE;
	}
	else if (dwCreatePetMovementOnWalk_Pointer == DarkWolf || dwCreatePetMovementOnWalk_Pointer == FangSable || dwCreatePetMovementOnWalk_Pointer == MisticTiger || dwCreatePetMovementOnWalk_Pointer == GiantLyon || dwCreatePetMovementOnWalk_Pointer == LycanPet)
	{
		bCreatePetMovementOnWalk_Switcher = TRUE;
	}
	// ----
	if (bCreatePetMovementOnWalk_Switcher == TRUE)
	{
		_asm
		{
			MOV dwCreatePetMovementOnWalk_Buffer, 0x004AC4B1
			JMP dwCreatePetMovementOnWalk_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwCreatePetMovementOnWalk_Buffer, 0x004ADD40
			JMP dwCreatePetMovementOnWalk_Buffer
		}
	}
}

void Naked cPets::FunctionUnknown1()
{
	static DWORD dwFunctionUnknown1_Return = 0x0059D485;
	static DWORD dwFunctionUnknown1_Jump = 0x0059D4BA;
	// ----
	_asm
	{
		MOV BL, BYTE PTR DS : [EBX + 0x17]
		MOV EDX, DWORD PTR DS : [0x7A723B8]
		CMP BL, 1
		MOV BYTE PTR DS : [EDX + 0x1EB] , BL
		JNZ NextAddedFenrir
		PUSH 0
		LEA EDI, [ESI + 0xFC]
		PUSH 0
		PUSH ESI
		PUSH EDI
		PUSH 0x180
		JMP dwFunctionUnknown1_Jump
		// ----
		NextAddedFenrir :
		// ----
		MOV BL, BYTE PTR DS : [EBX + 0x17]
			MOV EDX, DWORD PTR DS : [0x7A723B8]
			CMP BL, 0x3F
			MOV BYTE PTR DS : [EDX + 0x1EB] , BL
			JNZ ReturnBlueFenrir
			PUSH 0
			LEA EDI, [ESI + 0xFC]
			PUSH 0
			PUSH ESI
			PUSH EDI
			PUSH 0x206
			JMP dwFunctionUnknown1_Jump
			// ----
			ReturnBlueFenrir :
		// ----
		JMP dwFunctionUnknown1_Return
	}
}

void Naked cPets::FunctionUnknown2()
{
	static DWORD dwCreateMaxPetObjects = (DWORD)&gObjCreateBug;//0x004AC2C4;
	static DWORD dwFunctionUnknown2_Jump = 0x00617D54;
	// ----
	_asm
	{
		PUSH 0
		PUSH 0
		PUSH EBP
		ADD EBP, 0xFC
		PUSH EBP
		PUSH 0xE2
		CALL dwCreateMaxPetObjects
		ADD ESP, 0x14
		JMP dwFunctionUnknown2_Jump
		// ----
		PUSH 0
		PUSH 0
		PUSH EBP
		ADD EBP, 0xFC
		PUSH EBP
		PUSH 0x206
		CALL dwCreateMaxPetObjects
		ADD ESP, 0x14
		JMP dwFunctionUnknown2_Jump
		// ----
		PUSH 0
		PUSH 0
		PUSH EBP
		ADD EBP, 0xFC
		PUSH EBP
		PUSH 0x204
		CALL dwCreateMaxPetObjects
		ADD ESP, 0x14
		JMP dwFunctionUnknown2_Jump
		// ----
		PUSH 0
		PUSH 0
		PUSH EBP
		ADD EBP, 0xFC
		PUSH EBP
		PUSH 0x1EE
		CALL dwCreateMaxPetObjects
		ADD ESP, 0x14
		JMP dwFunctionUnknown2_Jump
		// ----
		PUSH 0
		PUSH 0
		PUSH EBP
		ADD EBP, 0xFC
		PUSH EBP
		PUSH 0x1F0
		CALL dwCreateMaxPetObjects
		ADD ESP, 0x14
		JMP dwFunctionUnknown2_Jump
		// ----
		PUSH 0
		PUSH 0
		PUSH EBP
		ADD EBP, 0xFC
		PUSH EBP
		PUSH 0x1F2
		CALL dwCreateMaxPetObjects
		ADD ESP, 0x14
		JMP dwFunctionUnknown2_Jump
		// ----
		PUSH 0
		PUSH 0
		PUSH EBP
		ADD EBP, 0xFC
		PUSH EBP
		PUSH 0x1FB
		CALL dwCreateMaxPetObjects
		ADD ESP, 0x14
		JMP dwFunctionUnknown2_Jump
	}
}

static BOOL bCreatePetFollowChar_Switcher;

void Naked cPets::CreatePetFollowChar()
{
	static DWORD dwCreatePetFollowChar_Pointer;
	static DWORD dwCreatePetFollowChar_Buffer;
	// ----
	bCreatePetFollowChar_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR DS : [0x7A723B8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		MOV dwCreatePetFollowChar_Pointer, ECX
	}
	// ----
	if (dwCreatePetFollowChar_Pointer == ObjectId(13, 64))		// Demon Pet
	{
		bCreatePetFollowChar_Switcher = TRUE;
	}
	else if (dwCreatePetFollowChar_Pointer == ObjectId(13, 78))	// Unicorn Pet
	{
		bCreatePetFollowChar_Switcher = TRUE;
	}
	else if (dwCreatePetFollowChar_Pointer == ObjectId(13, 77))	// Skeleton Pet
	{
		bCreatePetFollowChar_Switcher = TRUE;
	}
	else if (dwCreatePetFollowChar_Pointer == ObjectId(13, 79))	// Sparky Pet
	{
		bCreatePetFollowChar_Switcher = TRUE;
	}
	else if (dwCreatePetFollowChar_Pointer == ObjectId(13, 81))	// Chinlon Pet
	{
		bCreatePetFollowChar_Switcher = TRUE;
	}
	// ----
	if (bCreatePetFollowChar_Switcher == TRUE)
	{
		_asm
		{
			MOV dwCreatePetFollowChar_Buffer, oCreatePetFollowChar_Allowed
			JMP dwCreatePetFollowChar_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwCreatePetFollowChar_Buffer, oCreatePetFollowChar_Return
			JMP dwCreatePetFollowChar_Buffer
		}
	}
}

void Naked cPets::FollowCharacter()
{
	static DWORD dwJumpMauntPet = 0x0046D87B;
	static DWORD dwCreateMauntPet = (DWORD)&gSetObjMaunt2;
	// ----
	_asm
	{
		PUSH 0
		PUSH 0
		MOV EAX, DWORD PTR SS : [EBP - 0x1C]
		ADD EAX, 0x550
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
		ADD ECX, 0x338
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x1C]
		ADD EDX, 0x434
		PUSH EDX
		PUSH 0x1D42
		CALL dwCreateMauntPet
		ADD ESP, 0x18
		JMP dwJumpMauntPet
		// ----
		PUSH 0
		PUSH 0
		MOV EAX, DWORD PTR SS : [EBP - 0x1C]
		ADD EAX, 0x550
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
		ADD ECX, 0x338
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x1C]
		ADD EDX, 0x434
		PUSH EDX
		PUSH 0x1DB0
		CALL dwCreateMauntPet
		ADD ESP, 0x18
		JMP dwJumpMauntPet
		// ----
		PUSH 0
		PUSH 0
		MOV EAX, DWORD PTR SS : [EBP - 0x1C]
		ADD EAX, 0x550
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
		ADD ECX, 0x338
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x1C]
		ADD EDX, 0x434
		PUSH EDX
		PUSH ObjectId(13, 78)
		CALL dwCreateMauntPet
		ADD ESP, 0x18
		JMP dwJumpMauntPet
		// ----
		PUSH 0
		PUSH 0
		MOV EAX, DWORD PTR SS : [EBP - 0x1C]
		ADD EAX, 0x550
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
		ADD ECX, 0x338
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x1C]
		ADD EDX, 0x434
		PUSH EDX
		PUSH ObjectId(13, 77)
		CALL dwCreateMauntPet
		ADD ESP, 0x18
		JMP dwJumpMauntPet
		// ----
		PUSH 0
		PUSH 0
		MOV EAX, DWORD PTR SS : [EBP - 0x1C]
		ADD EAX, 0x550
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
		ADD ECX, 0x338
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x1C]
		ADD EDX, 0x434
		PUSH EDX
		PUSH ObjectId(13, 79)
		CALL dwCreateMauntPet
		ADD ESP, 0x18
		JMP dwJumpMauntPet
		// ----
		PUSH 0
		PUSH 0
		MOV EAX, DWORD PTR SS : [EBP - 0x1C]
		ADD EAX, 0x550
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
		ADD ECX, 0x338
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x1C]
		ADD EDX, 0x434
		PUSH EDX
		PUSH ObjectId(13, 81)
		CALL dwCreateMauntPet
		ADD ESP, 0x18
		JMP dwJumpMauntPet
		// ----
		PUSH 0
		PUSH 0
		MOV EAX, DWORD PTR SS : [EBP - 0x1C]
		ADD EAX, 0x550
		PUSH EAX
		MOV ECX, DWORD PTR SS : [EBP - 0x1C]
		ADD ECX, 0x338
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x1C]
		ADD EDX, 0x434
		PUSH EDX
		PUSH ObjectId(13, 97)
		CALL dwCreateMauntPet
		ADD ESP, 0x18
		JMP dwJumpMauntPet
	}
}

void Naked cPets::CreatePetTypeFenrir() // Hace al PJ sentarse en el Fenrir (Cuando esta parado)..
{
	static DWORD dwReturnLoad = 0x004D431E;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1D67
		JE ReturnLoad
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA3
		JE ReturnLoad
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA4
		JE ReturnLoad
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA5
		JE ReturnLoad
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA6 // -> ObjectId(13,100)
		JE ReturnLoad
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA7 // -> ObjectId(13,101)
		JE ReturnLoad
		// ----
		ReturnLoad :
		// ----
		JMP dwReturnLoad
	}
}

void Naked cPets::CreateFenrirThis1()
{
	static DWORD dwAddThisProp_Jump = 0x0049C1D6;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR DS : [0x7A723B8]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1D67
		JE AddThisProp1
		// ----
		MOV EDX, DWORD PTR DS : [0x7A723B8]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA3
		JE AddThisProp1
		// ----
		MOV EDX, DWORD PTR DS : [0x7A723B8]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA4
		JE AddThisProp1
		// ----
		MOV EDX, DWORD PTR DS : [0x7A723B8]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA5
		JE AddThisProp1
		// ----
		MOV EDX, DWORD PTR DS : [0x7A723B8]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA6
		JE AddThisProp1
		// ----
		MOV EDX, DWORD PTR DS : [0x7A723B8]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA7
		JE AddThisProp1
		// ----
		AddThisProp1 :
		// ----
		JMP dwAddThisProp_Jump
	}
}

void cPets::InitCreateFenrirThis1()
{
	gToolKit.SetRange((LPVOID)0x0049C1C4, 18, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0049C1C4, this->CreateFenrirThis1);
}

void Naked cPets::CreateFenrirThis2()
{
	static DWORD dwCreateThisF2_Return = 0x004D4D4D;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1D67
		JE AddThisProp2
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA3
		JE AddThisProp2
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA4
		JE AddThisProp2
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA5
		JE AddThisProp2
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA6
		JE AddThisProp2
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA7
		JE AddThisProp2
		// ----
		AddThisProp2 :
		// ----
		JMP dwCreateThisF2_Return
	}
}

void cPets::InitCreateFenrirThis2()
{
	gToolKit.SetRange((LPVOID)0x004D4D3E, 15, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D4D3E, this->CreateFenrirThis2);
}

void Naked cPets::CreateFenrirThis3()
{
	static DWORD dwAddThisProp3_Jump = 0x004D4F11;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1D67
		JE AddThisProp3
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA3
		JE AddThisProp3
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA4
		JE AddThisProp3
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA5
		JE AddThisProp3
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA6
		JE AddThisProp3
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA7
		JE AddThisProp3
		// ----
		AddThisProp3 :
		// ----
		JMP dwAddThisProp3_Jump
	}
}

void cPets::InitCreateFenrirThis3()
{
	gToolKit.SetRange((LPVOID)0x004D4F02, 15, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D4F02, this->CreateFenrirThis3);
}

void Naked cPets::CreateFenrirThis4() // Fenrir Mueve los PIEESSSS ! :D
{
	static DWORD dwAddThisProp4_Jump = 0x004D525A;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1D67
		JE AddThisProp4
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA3
		JE AddThisProp4
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA4
		JE AddThisProp4
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA5
		JE AddThisProp4
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA6
		JE AddThisProp4
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA7
		JE AddThisProp4
		// ----
		AddThisProp4 :
		// ----
		JMP dwAddThisProp4_Jump
	}
}

void cPets::InitCreateFenrirThis4()
{
	gToolKit.SetRange((LPVOID)0x004D524A, 16, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D524A, this->CreateFenrirThis4);
}

DWORD Pet_ExtrangeJump = 0x00736808;
DWORD Pet_FinalJump = 0x00736848;

DWORD PetStruct = 0x07AAD828;
DWORD PetCall1 = 0x00402F50;
DWORD PetCall2 = 0x004B69F0;

void Naked cPets::DrawHPBarOnScreen()
{
	_asm
	{
		MOV EAX, DWORD PTR DS : [0x7A723B8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, ObjectId(13, 67)					// Rudolf
		JNZ Unicorn_Pet_Label
		// ---------------------------------------
		Unicorn_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 78)					// Unicorn
			JE AddPetUnicorn_Text
			JNZ Chinlon_Pet_Label
			// ---------------------------------------
			Chinlon_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 81)					// Chinlon
			JE AddPetChinlon_Text
			JNZ Skeleton_Pet_Label
			// ---------------------------------------
			Skeleton_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 77)					// Skeleton
			JE AddPetSkeleton_Text
			JNZ Sparky_Pet_Label
			// ---------------------------------------
			Sparky_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 79)					// Sparky
			JE AddPetSparky_Text
			JNZ DarkWolf_Pet_Label
			// ---------------------------------------
			DarkWolf_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 97)					// Dark Wolf
			JE AddPetDarkWolf_Text
			JNZ FangSable_Pet_Label
			// ---------------------------------------
			FangSable_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 98)					// Fang Sable
			JE AddPetFangSable_Text
			JNZ HairTiger_Pet_Label
			// ---------------------------------------
			HairTiger_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 99)						// Hair Tiger
			JE AddPetHairTiger_Text
			JNZ GiantLyon_Pet_Label
			// ---------------------------------------
			GiantLyon_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 100)					// Giant Lyon
			JE AddPetGiantLyon_Text
			JNZ LycanWolf_Pet_Label
			// ---------------------------------------
			LycanWolf_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 101)					// Lycan Wolf
			JE AddPetLycanWolf_Text
			JNZ Fenrir_Pet_Label
			// ---------------------------------------
			Fenrir_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 37)						// Fenrir
			JE AddPetFenrir_Text
			JNZ Angel_Pet_Label
			// ---------------------------------------
			Angel_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 0)						// Angel
			JE AddPetAngel_Text
			JNZ Satan_Pet_Label
			// ---------------------------------------
			Satan_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 1)						// Satan
			JE AddPetSatan_Text
			JNZ Uniria_Pet_Label
			// ---------------------------------------
			Uniria_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 2)						// Uniria
			JE AddPetUniria_Text
			JNZ Dinorant_Pet_Label
			// ---------------------------------------
			Dinorant_Pet_Label :
		// ---------------------------------------
		MOV EAX, DWORD PTR DS : [0x7A723B8]
			MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
			CMP ECX, ObjectId(13, 3)						// Dinorant
			JE AddPetDinorant_Text
			JNZ Continue_Load
			// ---------------------------------------
			Continue_Load :
		// ---------------------------------------
		JNZ PetLifeBarFinalCheck
			// ---------------------------------------
			MOV BYTE PTR SS : [EBP - 0x100] , 0
			MOV ECX, 0x3F
			XOR EAX, EAX
			LEA EDI, [EBP - 0xFF]							// 0xFF = 255 (Max Pet Life)
			REP STOS DWORD PTR ES : [EDI]					// fucking REP STOS instruction set: EDI register
			STOS WORD PTR ES : [EDI]						// I don't know that is this
			STOS BYTE PTR ES : [EDI]						// I don't know that is this too, yet ! ;)
			MOV EDX, DWORD PTR DS : [0x7A723B8]			// Some STRUCT -> maybe is related to: PreviewStruct
			MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]			// 0x1E8 = Pet Slot from Inventory Character on: 1.03K JPN main.exe
			MOV DWORD PTR SS : [EBP - 0x110] , EAX
			MOV ECX, DWORD PTR SS : [EBP - 0x110]
			SUB ECX, ObjectId(13, 0)						// 0x1D42 => Guardian Angel ObjectId(13, 0) = 0x1D42
			MOV DWORD PTR SS : [EBP - 0x110] , ECX
			CMP DWORD PTR SS : [EBP - 0x110] , 0x7F			// 0x50 => Panda Pet ObjectId(13, 80) = 0x1A50.. I have added pets, then I must modify this (7F)
			JNZ PetLifeBarSomeCheck						// Here original instruction is: JA, but C++ Variant not admit this yet, then I change by: JNZ
			MOV EAX, DWORD PTR SS : [EBP - 0x110]
			XOR EDX, EDX
			MOV DL, BYTE PTR DS : [EAX + 0x73687D]
			JMP DWORD PTR DS : [EDX * 0x4 + 0x736851]
			// -----------------------------------------
			AddPetUnicorn_Text :
			// -----------------------------------------
			PUSH 0xB54									// Set Name Text: "Unicorn Pet" -> 2900
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// -----------------------------------------
			AddPetChinlon_Text :
		// -----------------------------------------
		PUSH 0xB5E									// Set Name Text: "Chinlon Pet" -> 2910
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetSkeleton_Text :
		// ----------------------------------------
		PUSH 0xB55									// Set Name Text: "Skeleton Pet" -> 2901
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetSparky_Text :
		// ----------------------------------------
		PUSH 0xB56									// Set Name Text: "Sparky Pet" -> 2902
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetDarkWolf_Text :
		// ----------------------------------------
		PUSH 0xB57									// Set Name Text: "Wolf Pet" -> 2903
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetFangSable_Text :
		// ----------------------------------------
		PUSH 0xB58									// Set Name Text: "Fang Pet" -> 2904
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetHairTiger_Text :
		// ----------------------------------------
		PUSH 0xB59									// Set Name Text: "Tiger Pet" -> 2905
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetGiantLyon_Text :
		// ----------------------------------------
		PUSH 0xB5C									// Set Name Text: "Lyon Pet" -> 2908
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetLycanWolf_Text :
		// ----------------------------------------
		PUSH 0xB5D									// Set Name Text: "Lycan Wolf" -> 2909
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetFenrir_Text :
		// ----------------------------------------
		PUSH 0x77C									// Set Name Text: "Fenrir Pet" -> 1916 (Original Number Line)
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetAngel_Text :
		// ----------------------------------------
		PUSH 0x161									// Set Name Text: "Angel Pet" -> 353 (Original Number Line)
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetSatan_Text :
		// ----------------------------------------
		PUSH 0x162									// Set Name Text: "Satan Pet" -> 354 (Original Number Line)
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetUniria_Text :
		// ----------------------------------------
		PUSH 0x163									// Set Name Text: "Uniria Pet" -> 355 (Original Number Line)
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			AddPetDinorant_Text :
		// ----------------------------------------
		PUSH 0xB5A									// Set Name Text: "Dinorant Pet" -> 2906 (Original Number Line)
			MOV ECX, 0x07AAD828							// Maybe this is a cool Pets Struct or Class :D method
			CALL PetCall1								// This is a class sure (exists a MOV ECX up).
			PUSH EAX
			LEA ECX, [EBP - 0x100]
			PUSH ECX
			CALL PetCall2
			ADD ESP, 0x8
			JMP Pet_ExtrangeJump						// Here I must jump again to extrange instruction
			// ----------------------------------------
			PetLifeBarSomeCheck :						// My cool defined LABEL, to make a extrange JUMP.
			// ----------------------------------------
		JMP Pet_ExtrangeJump
			// ----------------------------------------
			PetLifeBarFinalCheck :
		// ----------------------------------------
		JMP Pet_FinalJump
	}
}

void cPets::InitDrawHPBarOnScreen()
{
	gToolKit.SetRange((LPVOID)0x0073662D, 156, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0073662D, this->DrawHPBarOnScreen);
}

void Naked cPets::CreateFenrirThis5()
{
	static DWORD dwAddThisProp5_Jump = 0x004D5C25;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1D67
		JE AddThisProp5
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA3
		JE AddThisProp5
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA4
		JE AddThisProp5
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA5
		JE AddThisProp5
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA6
		JE AddThisProp5
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA7
		JE AddThisProp5
		// ----
		AddThisProp5 :
		// ----
		JMP dwAddThisProp5_Jump
	}
}

void cPets::InitCreateFenrirThis5()
{
	gToolKit.SetRange((LPVOID)0x004D5C16, 15, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D5C16, this->CreateFenrirThis5);
}

void Naked cPets::CreateFenrirThis6()
{
	static DWORD dwAddThisProp6_Jump = 0x004D5C89;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1D67
		JE AddThisProp6
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA3
		JE AddThisProp6
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA4
		JE AddThisProp6
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA5
		JE AddThisProp6
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA6
		JE AddThisProp6
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA7
		JE AddThisProp6
		// ----
		AddThisProp6 :
		// ----
		JMP dwAddThisProp6_Jump
	}
}

void cPets::InitCreateFenrirThis6()
{
	gToolKit.SetRange((LPVOID)0x004D5C7A, 15, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D5C7A, this->CreateFenrirThis6);
}

void Naked cPets::CreateFenrirThis7()
{
	static DWORD dwAddThisProp7_Jump = 0x004D685D;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1D67
		JE AddThisProp7
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA3
		JE AddThisProp7
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA4
		JE AddThisProp7
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA5
		JE AddThisProp7
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA6
		JE AddThisProp7
		// ----
		MOV EDX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		CMP EAX, 0x1DA7
		JE AddThisProp7
		// ----
		AddThisProp7 :
		// ----
		JMP dwAddThisProp7_Jump
	}
}

void cPets::InitCreateFenrirThis7()
{
	gToolKit.SetRange((LPVOID)0x004D684E, 15, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D684E, this->CreateFenrirThis7);
}

void Naked cPets::CreateFenrirThis8()
{
	static DWORD dwAddThisProp8_Jump = 0x004D75F4;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1D67
		JE AddThisProp8
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA3
		JE AddThisProp8
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA4
		JE AddThisProp8
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA5
		JE AddThisProp8
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA6
		JE AddThisProp8
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA7
		JE AddThisProp8
		// ----
		AddThisProp8 :
		// ----
		JMP dwAddThisProp8_Jump
	}
}

void cPets::InitCreateFenrirThis8()
{
	gToolKit.SetRange((LPVOID)0x004D75E4, 16, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D75E4, this->CreateFenrirThis8);
}

void Naked cPets::CreateFenrirThis9()
{
	static DWORD dwAddThisProp9_Jump = 0x004D77C0;
	// ----
	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EDX, WORD PTR DS : [ECX + 0x1E8]
		CMP EDX, 0x1D67
		JE AddThisProp9
		// ----
		MOV ECX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EDX, WORD PTR DS : [ECX + 0x1E8]
		CMP EDX, 0x1DA3
		JE AddThisProp9
		// ----
		MOV ECX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EDX, WORD PTR DS : [ECX + 0x1E8]
		CMP EDX, 0x1DA4
		JE AddThisProp9
		// ----
		MOV ECX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EDX, WORD PTR DS : [ECX + 0x1E8]
		CMP EDX, 0x1DA5
		JE AddThisProp9
		// ----
		MOV ECX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EDX, WORD PTR DS : [ECX + 0x1E8]
		CMP EDX, 0x1DA6
		JE AddThisProp9
		// ----
		MOV ECX, DWORD PTR SS : [EBP + 0x08]
		MOVSX EDX, WORD PTR DS : [ECX + 0x1E8]
		CMP EDX, 0x1DA7
		JE AddThisProp9
		// ----
		AddThisProp9 :
		// ----
		JMP dwAddThisProp9_Jump
	}
}

void cPets::InitCreateFenrirThis9()
{
	gToolKit.SetRange((LPVOID)0x004D77B0, 16, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D77B0, this->CreateFenrirThis9);
}

void Naked cPets::CreateFenrirThis10()
{
	static DWORD dwAddThisProp10_Jump = 0x004D7FAB;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1D67
		JE AddThisProp10
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA3
		JE AddThisProp10
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA4
		JE AddThisProp10
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA5
		JE AddThisProp10
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA6
		JE AddThisProp10
		// ----
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		CMP ECX, 0x1DA7
		JE AddThisProp10
		// ----
		AddThisProp10 :
		// ----
		JMP dwAddThisProp10_Jump
	}
}

void cPets::InitCreateFenrirThis10()
{
	gToolKit.SetRange((LPVOID)0x004D7F9B, 16, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D7F9B, this->CreateFenrirThis10);
}

static BOOL bCreateFenrirThis11_Switcher;

void Naked cPets::CreateFenrirThis11()
{
	static DWORD dwCreateFenrirThis11_Pointer;
	static DWORD dwCreateFenrirThis11_Buffer;
	// ----
	bCreateFenrirThis11_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x08]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		MOV dwCreateFenrirThis11_Pointer, ECX
	}
	// ----
	if (dwCreateFenrirThis11_Pointer == ObjectId(13, 37))
	{
		bCreateFenrirThis11_Switcher = TRUE;
	}
	else if (dwCreateFenrirThis11_Pointer == ObjectId(13, 97))
	{
		bCreateFenrirThis11_Switcher = TRUE;
	}
	// ----
	if (bCreateFenrirThis11_Switcher == TRUE)
	{
		_asm
		{
			MOV dwCreateFenrirThis11_Buffer, 0x004E1871
			JMP dwCreateFenrirThis11_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwCreateFenrirThis11_Buffer, 0x004E188F
			JMP dwCreateFenrirThis11_Buffer
		}
	}
}

void cPets::InitCreateFenrirThis11()
{
	gToolKit.SetRange((LPVOID)0x004E185F, 18, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004E185F, this->CreateFenrirThis11);
}

static BOOL bCreateFenrirThis12_Switcher;

void Naked cPets::CreateFenrirThis12()
{
	static DWORD dwCreateFenrirThis12_Pointer;
	static DWORD dwCreateFenrirThis12_Buffer;
	// ----
	bCreateFenrirThis12_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		MOV dwCreateFenrirThis12_Pointer, ECX
	}
	// ----
	if (dwCreateFenrirThis12_Pointer == ObjectId(13, 37))
	{
		bCreateFenrirThis12_Switcher = TRUE;
	}
	else if (dwCreateFenrirThis12_Pointer == ObjectId(13, 97) || dwCreateFenrirThis12_Pointer == ObjectId(13, 98))
	{
		bCreateFenrirThis12_Switcher = TRUE;
	}
	// ----
	if (bCreateFenrirThis12_Switcher == TRUE)
	{
		_asm
		{
			MOV dwCreateFenrirThis12_Buffer, 0x004E88E6
			JMP dwCreateFenrirThis12_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwCreateFenrirThis12_Buffer, 0x004E894F
			JMP dwCreateFenrirThis12_Buffer
		}
	}
}

void cPets::InitCreateFenrirThis12()
{
	gToolKit.SetRange((LPVOID)0x004E88D4, 18, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004E88D4, this->CreateFenrirThis12);
}

static BOOL bCreateFenrirThis13_Switcher;

void Naked cPets::CreateFenrirThis13()
{
	static DWORD dwCreateFenrirThis13_Pointer;
	static DWORD dwCreateFenrirThis13_Buffer;
	// ----
	bCreateFenrirThis13_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR DS : [0x7A723B8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x1E8]
		MOV dwCreateFenrirThis13_Pointer, ECX
	}
	// ----
	if (dwCreateFenrirThis13_Pointer == ObjectId(13, 37))
	{
		bCreateFenrirThis13_Switcher = TRUE;
	}
	else if (dwCreateFenrirThis13_Pointer == ObjectId(13, 97) || dwCreateFenrirThis13_Pointer == ObjectId(13, 98))
	{
		bCreateFenrirThis13_Switcher = TRUE;
	}
	// ----
	if (bCreateFenrirThis13_Switcher == TRUE)
	{
		_asm
		{
			MOV dwCreateFenrirThis13_Buffer, 0x007E5022
			JMP dwCreateFenrirThis13_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwCreateFenrirThis13_Buffer, 0x007E50DC
			JMP dwCreateFenrirThis13_Buffer
		}
	}
}

void cPets::InitCreateFenrirThis13()
{
	gToolKit.SetRange((LPVOID)0x007E500A, 24, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x007E500A, this->CreateFenrirThis13);
}

static BOOL bCreateFenrirThis14_Switcher;

void Naked cPets::CreateFenrirThis14()
{
	static DWORD dwCreateFenrirThis14_Pointer;
	static DWORD dwCreateFenrirThis14_Buffer;
	// ----
	bCreateFenrirThis14_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR DS : [0x7A723B8]
		MOVSX EAX, WORD PTR DS : [EDX + 0x1E8]
		MOV dwCreateFenrirThis14_Pointer, EAX
	}
	// ----
	if (dwCreateFenrirThis14_Pointer == ObjectId(13, 37))
	{
		bCreateFenrirThis14_Switcher = TRUE;
	}
	else if (dwCreateFenrirThis14_Pointer == ObjectId(13, 97) || dwCreateFenrirThis14_Pointer == ObjectId(13, 98))
	{
		bCreateFenrirThis14_Switcher = TRUE;
	}
	// ----
	if (bCreateFenrirThis14_Switcher == TRUE)
	{
		_asm
		{
			MOV dwCreateFenrirThis14_Buffer, 0x007F30AE
			JMP dwCreateFenrirThis14_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwCreateFenrirThis14_Buffer, 0x007F30C3
			JMP dwCreateFenrirThis14_Buffer
		}
	}
}

void cPets::InitCreateFenrirThis14()
{
	gToolKit.SetRange((LPVOID)0x007F309A, 20, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x007F309A, this->CreateFenrirThis14);
}

void Naked cPets::DemonShowLife()
{
	static DWORD dwShowLifeText = 0x00595F77;
	static DWORD dwReturnNormal = 0x00595F94;
	// ----
	_asm
	{
		CMP AX, ItemId(13, 64)	// -> Demon Pet
		JE AddLifeText
		// ----
		CMP AX, ItemId(13, 65)	// -> Fairy Pet
		JE AddLifeText
		// ----
		CMP AX, ItemId(13, 67)	// -> Rudolf Pet
		JE AddLifeText
		// ----
		CMP AX, ItemId(13, 80)	// -> Panda Pet
		JE AddLifeText
		// ----
		//CMP AX,ItemId(13,99)	// -> Tiger Pet
		//JE AddLifeText
		// ----
		CMP AX, ItemId(13, 97)	// -> Dark Wolf Pet
		JE AddLifeText
		// ----
		CMP AX, ItemId(13, 98)	// -> Sable Fang Pet
		JE AddLifeText
		// ----
		//CMP AX,ItemId(13,100)	// -> Giant Lyon Pet
		//JE AddLifeText
		// ----
		//CMP AX,ItemId(13,101)	// -> Lycan Wolf Pet
		//JE AddLifeText
		// ----
		CMP AX, ItemId(13, 78)	// -> Unicorn Pet
		JE AddLifeText
		// ----
		CMP AX, ItemId(13, 77)	// -> Skeleton Pet
		JE AddLifeText
		// ----
		CMP AX, ItemId(13, 79)	// -> Sparky Pet
		JE AddLifeText
		// ----
		CMP AX, ItemId(13, 81)	// -> Chinlon Pet
		JE AddLifeText
		// ----
		JMP dwReturnNormal
		// ----
		AddLifeText :
		// ----
		JMP dwShowLifeText
	}
}

void cPets::InitDemonShowLife()
{
	gToolKit.SetRange((LPVOID)0x00595F8E, 6, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x00595F8E, this->DemonShowLife);
}

int cPets::DrawObjectOnViewport(lpObjViewport lpObjView) // -> 0x005C0467
{
	for (int i = 0; i < gPets.gItemFloor; i++)
	{
		while (lpObjView->ObjIndex == ObjectId(gPets.eTYPE[i].Type, gPets.eTYPE[i].Index))
		{
			lpObjView->AngleX = gPets.eVALUE[i].RotX;
			lpObjView->AngleY = gPets.eVALUE[i].RotY;
			lpObjView->AngleZ = gPets.eVALUE[i].RotZ;
			lpObjView->Size = gPets.eVALUE[i].Size;
			// ----
			while (lpObjView->AngleX == gPets.eVALUE[i].RotX)
			{
				return gPets.eVALUE[i].RotX;
			}
			while (lpObjView->AngleY == gPets.eVALUE[i].RotY)
			{
				return gPets.eVALUE[i].RotY;
			}
			while (lpObjView->AngleZ == gPets.eVALUE[i].RotZ)
			{
				return gPets.eVALUE[i].RotZ;
			}
			while (lpObjView->Size == gPets.eVALUE[i].Size)
			{
				return gPets.eVALUE[i].Size;
			}
		}
	}
	// ----
	return pObjOnViewport(lpObjView);
}

void cPets::InitDrawObjectOnViewport()
{
	if (IsCustomFloor == 1)
	{
		if (gScriptEncode.ReadScript(FLOOR_FILE))
		{
			int Token;
			Token = gScriptEncode.GetToken();
			// ----
			gItemFloor = 0;
			// ----
			memset(eTYPE, -1, sizeof(eTYPE));
			memset(eVALUE, -1, sizeof(eVALUE));
			// ----
			while (TRUE)
			{
				Token = gScriptEncode.GetToken();
				// ----
				if ((Token == END)) break;
				// ----
				eTYPE[gItemFloor].Type = gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eTYPE[gItemFloor].Index = gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eVALUE[gItemFloor].RotX = gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eVALUE[gItemFloor].RotY = gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eVALUE[gItemFloor].RotZ = gScriptEncode.TokenNumber; Token = gScriptEncode.GetToken();
				eVALUE[gItemFloor].Size = gScriptEncode.TokenNumber;
				// ----
				gItemFloor++;
			}
			// ----
			if (gItemFloor > 0)
			{
				gToolKit.SetOp((LPVOID)oDrawObjectCall01, this->DrawObjectOnViewport, ASM::CALL);
				gToolKit.SetOp((LPVOID)oDrawObjectCall02, this->DrawObjectOnViewport, ASM::CALL);
			}
		}
		else
		{
			MessageBox(NULL, "ItemFloor.bmd file not found", "Error", MB_OK);
			::ExitProcess(0);
		}
	}
}

static BOOL bDrawAngelMovement_Switcher;

void Naked cPets::DrawAngelMovement()
{
	static DWORD dwDrawAngelMovement_Pointer;
	static DWORD dwDrawAngelMovement_Buffer;
	// ----
	static DWORD dwCallFollowCharCoords = 0x004CC549;
	static DWORD dwDrawAngelMovement_Final = 0x004AE096;
	// ----
	bDrawAngelMovement_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOV ECX, DWORD PTR DS : [EAX + 0x30]
		MOV dwDrawAngelMovement_Pointer, ECX
	}
	// ----
	if (dwDrawAngelMovement_Pointer == ObjectId(13, 0))			// -> Angel Pet
	{
		bDrawAngelMovement_Switcher = TRUE;
	}
	else if (dwDrawAngelMovement_Pointer == ObjectId(13, 78))		// -> Unicorn Pet
	{
		bDrawAngelMovement_Switcher = TRUE;
	}
	else if (dwDrawAngelMovement_Pointer == ObjectId(13, 77))		// -> Skeleton Pet
	{
		bDrawAngelMovement_Switcher = TRUE;
	}
	else if (dwDrawAngelMovement_Pointer == ObjectId(13, 79))		// -> Sparky Pet
	{
		bDrawAngelMovement_Switcher = TRUE;
	}
	else if (dwDrawAngelMovement_Pointer == ObjectId(13, 81))		// -> Chinlon Pet
	{
		bDrawAngelMovement_Switcher = TRUE;
	}
	// ----
	if (bDrawAngelMovement_Switcher == TRUE)
	{
		_asm
		{
			MOV dwDrawAngelMovement_Buffer, oDrawAngelMovement_Allowed
			JMP dwDrawAngelMovement_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwDrawAngelMovement_Buffer, oDrawAngelMovement_Return
			JMP dwDrawAngelMovement_Buffer
		}
	}
}

void cPets::InitDrawAngelMovement()
{
	gToolKit.SetRange((LPVOID)oDrawAngelMovement_Hook, 12, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oDrawAngelMovement_Hook, this->DrawAngelMovement);
}

static BOOL bRedrawObjViewport_Switcher;

void Naked cPets::RedrawObjViewport()
{
	static DWORD dwRedrawObjViewport_Pointer;
	static DWORD dwRedrawObjViewport_Buffer;
	// ----
	bRedrawObjViewport_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP - 0x2C]
		MOVSX EAX, WORD PTR DS : [EDX]
		MOV dwRedrawObjViewport_Pointer, EAX
	}
	// ----
	if (dwRedrawObjViewport_Pointer == ItemId(13, 37))	// -> Horn of Fenrir
	{
		bRedrawObjViewport_Switcher = TRUE;
	}
	else if (dwRedrawObjViewport_Pointer >= ItemId(13, 77) && dwRedrawObjViewport_Pointer <= ItemId(13, 79) || dwRedrawObjViewport_Pointer == ObjectId(13, 81))
	{
		bRedrawObjViewport_Switcher = TRUE;
	}
	else if (dwRedrawObjViewport_Pointer >= ItemId(13, 97) && dwRedrawObjViewport_Pointer <= ItemId(13, 120))
	{
		bRedrawObjViewport_Switcher = TRUE;
	}
	// ----
	if (bRedrawObjViewport_Switcher == TRUE)
	{
		_asm
		{
			MOV dwRedrawObjViewport_Buffer, 0x00751FAE
			JMP dwRedrawObjViewport_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwRedrawObjViewport_Buffer, 0x00751F4E
			JMP dwRedrawObjViewport_Buffer
		}
	}
}

void cPets::InitRedrawObjViewport()
{
	gToolKit.SetRange((LPVOID)0x00751F41, 13, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x00751F41, this->RedrawObjViewport);
}

static BOOL bRudolfSearchZen_Switcher;

void Naked cPets::RudolfSearchZen()
{
	static DWORD dwRudolfSearchZen_Pointer;
	static DWORD dwRudolfSearchZen_Buffer;
	// ----
	bRudolfSearchZen_Switcher = FALSE;
	// ----
	_asm
	{
		MOV EDX, DWORD PTR SS : [EBP - 0x8]
		IMUL EDX, EDX, 0x278
		MOVSX EAX, WORD PTR DS : [EDX + 0x7B46D7A]
		MOV dwRudolfSearchZen_Pointer, EAX
	}
	// ----
	if (dwRudolfSearchZen_Pointer == ItemId(14, 15) || dwRudolfSearchZen_Pointer == ItemId(14, 13) || dwRudolfSearchZen_Pointer == ItemId(14, 14)
		|| dwRudolfSearchZen_Pointer == ItemId(14, 16) || dwRudolfSearchZen_Pointer == ItemId(12, 15) || dwRudolfSearchZen_Pointer >= ItemId(14, 240)
		&& dwRudolfSearchZen_Pointer <= ItemId(14, 246))
	{
		bRudolfSearchZen_Switcher = TRUE;
	}
	// ----
	if (bRudolfSearchZen_Switcher == TRUE)
	{
		_asm
		{
			MOV dwRudolfSearchZen_Buffer, oRudolfSearchZen_Allowed
			JMP dwRudolfSearchZen_Buffer
		}
	}
	else
	{
		_asm
		{
			MOV dwRudolfSearchZen_Buffer, oRudolfSearchZen_Return
			JMP dwRudolfSearchZen_Buffer
		}
	}
}

void cPets::InitRudolfSearchZen()
{
	gToolKit.SetRange((LPVOID)oRudolfSearchZen_Hook, 23, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oRudolfSearchZen_Hook, this->RudolfSearchZen);
}

struct EffectStruct
{
	BYTE Shift1[8];
	int Texture;
	int EffectID;
	BYTE Shift2[56];
	float R;
	float G;
	float B;
};
EffectStruct* pEffect;

void Naked cPets::DrawPetSkillEffect()
{
	static DWORD dwDrawPetSkillEffect_Pointer;
	static DWORD dwDrawPetSkillEffect_Buffer;
	// ----
	_asm
	{
		MOV dwDrawPetSkillEffect_Pointer, EAX
	}
	// ----
	pEffect = (EffectStruct*)dwDrawPetSkillEffect_Pointer;
	// ----
	if (&pEffect->EffectID)
	{
		switch (pEffect->EffectID)
		{
		case 1:
			pEffect->Texture = 0x7D76;
			pEffect->R = 1.0;
			pEffect->G = 0.6;
			pEffect->B = 0.6;
			break;
			// ----
		case 2:
			pEffect->Texture = 0x7D76;
			pEffect->R = 0.7;
			pEffect->G = 0.7;
			pEffect->B = 1.0;
			break;
			// ----
		case 3:
			pEffect->Texture = 0x7D76;
			pEffect->R = 0.9;
			pEffect->G = 0.9;
			pEffect->B = 0.3;
			break;
			// ----
		case 4:
			pEffect->Texture = 0x7D67;//0x7DDA
			pEffect->R = 0.1;
			pEffect->G = 0.8;
			pEffect->B = 0.1;
			break;
			// ----
		case 5:
			pEffect->Texture = 0x7D67;
			pEffect->R = 1.0;
			pEffect->G = 0.3;
			pEffect->B = 0.2;
			break;
			// ----
		case 6:
			pEffect->Texture = 0x7D67;
			pEffect->R = 0.2;
			pEffect->G = 0.3;
			pEffect->B = 1.0;
			break;
			// ----
		case 7:
			pEffect->Texture = 0x7D67;
			pEffect->R = 0.8;
			pEffect->G = 0.8;
			pEffect->B = 0.1;
			break;
			// ----
		case 8:
			pEffect->Texture = 0x7D02;
			pEffect->R = 1.0;
			pEffect->G = 0.5667;
			pEffect->B = 0.0;
			break;

		case FENRIR_ORANGE:
			pEffect->Texture = 0x7D02;
			pEffect->R = 1.0;
			pEffect->G = 0.5667;
			pEffect->B = 0.0;
			break;
			// ----
		default:
			pEffect->Texture = 0x7DD5;//0x7D76
			pEffect->R = 0.7;
			pEffect->G = 1.0;
			pEffect->B = 0.7;
			break;
		}
	}
	// ----
	_asm
	{
		MOV dwDrawPetSkillEffect_Buffer, 0x00681D39
		JMP dwDrawPetSkillEffect_Buffer
	}
}

void cPets::InitDrawPetSkillEffect()
{
	gToolKit.SetRange((LPVOID)0x00681B97, 51, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x00681B97, this->DrawPetSkillEffect);
}

int cPets::GetFenrirSkillColor(int Arg1)	// -> 0x004D410F
{
	signed int Result;
	// ----
	switch (*(BYTE*)(Arg1 + 491))
	{
	case 1:
		Result = 0;
		break;
	case 2:
		Result = 2;
		break;
	case 4:
		Result = 3;
		break;
	case 8:
		Result = 63;
		break;
	default:
		Result = 1;
		break;
	}
	// ----
	return Result;
}

void cPets::InitGetFenrirSkillColor()
{
	gToolKit.SetOp((LPVOID)0x004E1FBA, this->GetFenrirSkillColor, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004E2007, this->GetFenrirSkillColor, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004E2110, this->GetFenrirSkillColor, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004E2165, this->GetFenrirSkillColor, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004E226E, this->GetFenrirSkillColor, ASM::CALL);
}

void cPets::Init()
{
	gToolKit.SetByte((PVOID)(0x00617C09 + 3), 0x7F);//Related to FunctionUnknown2
	// ----
	gToolKit.SetRange((LPVOID)0x00617C89, 30, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x00617C89, this->FunctionUnknown2);
	// ----
	gToolKit.SetRange((LPVOID)0x005A029A, 21, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x005A029A, this->CreatePetInventorySizeEx);
	// ----
	gToolKit.SetRange((LPVOID)0x0059F4A3, 8, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0059F4A3, this->CreatePetInvenModelPosEx);
	// ----
	gToolKit.SetRange((LPVOID)0x005917DC, 35, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x005917DC, this->CreatePetInvenNewNameExc);
	// ----
	gToolKit.SetRange((LPVOID)oCreatePetFunctionUnk_Hook, 30, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oCreatePetFunctionUnk_Hook, this->CreatePetFunctionUnknown);
	// ----
	gToolKit.SetRange((LPVOID)oCreatePetAllowWalkOnMap_Hook, 33, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oCreatePetAllowWalkOnMap_Hook, this->CreatePetAllowedWalkOnMap);
	// ----
	gToolKit.SetRange((LPVOID)oCPSetPlayerActions_Hook, 517, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oCPSetPlayerActions_Hook, this->CreatePetSetPlayerActions);
	// ----
	gToolKit.SetRange((LPVOID)oCreatePetFollowChar_Hook, 20, ASM::NOP);
	gToolKit.SetJmp((LPVOID)oCreatePetFollowChar_Hook, this->CreatePetFollowChar);
	// ----
	gToolKit.SetRange((LPVOID)0x004AC47B, 33, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004AC47B, this->CreatePetMovementOnWalk);
	// ----
	gToolKit.SetRange((LPVOID)0x0059D45E, 39, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0059D45E, this->FunctionUnknown1);
	// ----
	gToolKit.SetRange((LPVOID)0x0046D6BE, 51, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x0046D6BE, this->FollowCharacter);
	// ----
	gToolKit.SetRange((LPVOID)0x004D430E, 16, ASM::NOP);
	gToolKit.SetJmp((LPVOID)0x004D430E, this->CreatePetTypeFenrir);
	// ----
	this->InitDemonShowLife();
	this->InitCreateCodeMountEx();
	this->InitCreateFenrirThis1();
	this->InitCreateFenrirThis2();
	this->InitCreateFenrirThis3();
	this->InitCreateFenrirThis4();
	this->InitCreateFenrirThis5();
	this->InitCreateFenrirThis6();
	this->InitCreateFenrirThis7();
	this->InitCreateFenrirThis8();
	this->InitCreateFenrirThis9();
	this->InitCreateFenrirThis10();
	this->InitCreateFenrirThis11();
	this->InitCreateFenrirThis12();
	this->InitCreateFenrirThis13();
	this->InitCreateFenrirThis14();
	// ----
	this->InitDrawHPBarOnScreen();
	this->InitRedrawObjViewport();
	this->InitRudolfSearchZen();
	this->InitDrawPetSkillEffect();
	this->InitGetFenrirSkillColor();
}

void cPets::Load()
{
	this->InitDrawAngelMovement();
	this->InitDrawObjectOnViewport();
	this->Init();
	// ----
	gToolKit.SetOp((LPVOID)0x0046D6E4, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0046D717, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0046D74A, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0046D77D, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0046D7C0, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0046D803, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0046D843, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0046D873, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004AC33C, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004FE371, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004FE55E, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004FE5CD, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004FE682, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004FE6DF, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004FE73C, this->CreatePetStatics, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004FE786, this->CreatePetStatics, ASM::CALL);
	// ----
	gToolKit.SetOp((LPVOID)0x005EE12C, this->LoadObjSkillModel, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00734BA6, this->CreatePetObjectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00753C6E, this->CreatePetObjectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00755C90, this->ResetPetPreviewEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x0046C305, this->CreatePetEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004AE2EC, this->CreatePetEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004C499C, this->CreatePetMountEx, ASM::CALL);
}