#include "StdAfx.h"

cEffect gEffect;

int CreateSprite(int Type, vec3_t Position, float Scale, vec3_t Light, OBJECT* Owner, float Rotation, int SubType)
{
	pCreateSprite CreateSpriteMain = (pCreateSprite)(0x006BABF2);//1.03.11
	return CreateSpriteMain(Type, Position, Scale, Light, Owner, Rotation, SubType);
}

void CreateEffect(int Type, vec3_t Position, vec3_t Angle, vec3_t Light, int SubType, OBJECT* Owner, short PKKey, BYTE Skill, float Scale, BYTE SkillSerial, vec3_t SkillAngle, BYTE SkillHotKey)
{
	pCreateEffect CreateEffectMain = (pCreateEffect)(0x00650FF0);//1.03.11
	CreateEffectMain(Type, Position, Angle, Light, SubType, Owner, PKKey, Skill, Scale, SkillSerial, SkillAngle, SkillHotKey);
}

//void __cdecl sub_67F110(signed int a1, int a2, int a3, int a4, int a5, int a6, float a7, __int16 a8, unsigned __int16 a9, char a10, int a11, int a12, __int16 a13)

void CreateSpark(int Type, vec3_t Position, vec3_t RelativePosition, vec3_t Angle, int SubType, OBJECT* Owner, float Scale, short PKKey, USHORT Arg9, BYTE SkillSerial, int Arg11, int Arg12, USHORT Arg13)
{
	pCreateSpark CreateSparkMain = (pCreateSpark)(0x0067F110);//1.03.11
	CreateSparkMain(Type, Position, RelativePosition, Angle, SubType, Owner, Scale, PKKey, Arg9, SkillSerial, Arg11, Arg12, Arg13);
}

int CreateParticle(int Type, vec3_t Position, vec3_t Angle, vec3_t Light, int SubType, float Scale, OBJECT* Owner)
{
	pCreateParticle CreateParticleMain = (pCreateParticle)(0x0069BCD9);//1.03.11
	return CreateParticleMain(Type, Position, Angle, Light, SubType, Scale, Owner);
}

typedef void(*pRenderPartObjectEffect)(OBJECT* o, int Type, vec3_t Light, float Alpha, int ItemLevel, int NewOption, int SetOption, int Select, int RenderType);//005CD8D7
void RenderPartObjectEffect(OBJECT* o, int Type, vec3_t Light, float Alpha, int ItemLevel, int NewOption, int SetOption, int Select, int RenderType)
{
	pRenderPartObjectEffect RenderPartObjectEffectMain = (pRenderPartObjectEffect)(0x005CDA66);//1.03.11
	RenderPartObjectEffectMain(o, Type, Light, Alpha, ItemLevel, NewOption, SetOption, Select, RenderType);
}

float absf(float a)
{
	if (a < 0.f) return -a;
	return a;
}

float& WorldTime = *(float*)0x00596ABD8;//1.03.11

typedef void(*pRenderPartItemEffect)(float Arg1, float Arg2, float Arg3, OBJECT* Object, int Arg5, int Type, int Arg7, int Arg8, char Arg9, char Arg10, int Arg11, char Arg12);
void RenderPartItemEffect(float Arg1, float Arg2, float Arg3, OBJECT* Object, int Arg5, int Type, int Arg7, int Arg8, char Arg9, char Arg10, int Arg11, char Arg12)
{
	pRenderPartItemEffect RenderPartItemEffectMain = (pRenderPartItemEffect)(0x004E9336);
	RenderPartItemEffectMain(Arg1, Arg2, Arg3, Object, Arg5, Type, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12);
}

void RenderPartItemEffectEx(float Arg1, float Arg2, float Arg3, OBJECT* Object, int Arg5, int Type, int Arg7, int Arg8, char Arg9, char Arg10, int Arg11, char Arg12)
{
	int WorldPreview = *(DWORD*)(Object + 700);

	BMD* b = &Models[Type];

	vec3_t p, Position;

	vec3_t Color;
	Vector(0.f, 0.f, 0.f, Color);

	switch (Type)
	{
		// Rune Sacred Blade
	case ObjectId(0, 29):
	{
		Vector(0.95f, 0.8588f, 0.038f, Color);
		b->TransformPosition(BoneTransform[17], p, Position, true);
		CreateSprite(32002, Position, 0.5f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[18], p, Position, true);
		CreateSprite(32002, Position, 0.5f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[20], p, Position, true);
		CreateSprite(32002, Position, 0.5f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[21], p, Position, true);
		CreateSprite(32002, Position, 0.5f, Color, Object, 0.5f);
		// ----
		Vector(1.0f, 1.0f, 1.0f, Color);
		b->TransformPosition(BoneTransform[0], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[1], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[2], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[3], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[4], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[5], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[6], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[7], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[8], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[9], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[10], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[11], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[12], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[13], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[14], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
		b->TransformPosition(BoneTransform[15], p, Position, true);
		CreateSprite(32213, Position, 0.6f, Color, Object, 0.5f);
	}
	break;
	}
	RenderPartItemEffect(Arg1, Arg2, Arg3, Object, Arg5, Type, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12);
}

void RenderPartObjectEffectEx(OBJECT* o, int Type, vec3_t Light, float Alpha, int ItemLevel, int NewOption, int SetOption, int Select, int RenderType)
{
	BMD* b = &Models[Type];

	vec3_t Position;

	vec3_t Light2;
	Vector(0.f, 0.f, 0.f, Light2);

	vec3_t p;
	Vector(0.f, 0.f, 0.f, p);	// -> WorldPosition or Preview

	switch (Type)
	{
		// Evolve Dragon Set
	case ObjectId(7, 100):
	{
		Vector(0.0f, 0.0f, 0.0f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 20);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// ---
	case ObjectId(8, 100):
	{
		Vector(1.0f, 0.0f, 0.0f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 19);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
		// ----
		if (rand() % 12 <= 2)
		{
			float Formula1 = (float)(rand() % 100) / 100.0f;

			vec3_t fVal;

			Vector(Formula1 * 0.5f + 4.0f,
				Formula1 * 0.5f + 4.0f,
				Formula1 * 0.5f + 2.0f, fVal);
			// ---
			Vector(1.0f, 0.0f, 0.0f, Light2);
			Vector(1.f, 1.f, 1.f, Position);
			// ---
			b->TransformByObjectBone(Position, o, 19);
			CreateSprite(32002, Position, fVal[1], Light2, o, fVal[0], 0);
		}
	}
	break;
	// ---
	case ObjectId(9, 100):
	{
		Vector(1.0f, 0.0f, 0.0f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 45);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
		// ---
		b->TransformByObjectBone(Position, o, 49);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// ---
	case ObjectId(10, 100):
	{
		Vector(1.0f, 0.0f, 0.0f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 36);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// ---
	case ObjectId(11, 100):
	{
		Vector(1.0f, 0.0f, 0.0f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 4);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
		// ---
		b->TransformByObjectBone(Position, o, 11);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// Evolve Guardian Set
	case ObjectId(7, 101):
	{
		Vector(0.74f, 0.5328f, 0.7365f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 20);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// ---
	case ObjectId(8, 101):
	{
		Vector(0.74f, 0.5328f, 0.7365f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 19);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
		// ----
		if (rand() % 12 <= 2)
		{
			float Formula1 = (float)(rand() % 100) / 100.0f;

			vec3_t fVal;

			Vector(Formula1 * 0.5f + 4.0f,
				Formula1 * 0.5f + 4.0f,
				Formula1 * 0.5f + 2.0f, fVal);
			// ---
			Vector(0.74f, 0.5328f, 0.7365f, Light2);
			Vector(1.f, 1.f, 1.f, Position);
			// ---
			b->TransformByObjectBone(Position, o, 19);
			CreateSprite(32002, Position, fVal[1], Light2, o, fVal[0], 0);
		}
	}
	break;
	// ---
	case ObjectId(9, 101):
	{
		Vector(0.74f, 0.5328f, 0.7365f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 45);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
		// ---
		b->TransformByObjectBone(Position, o, 49);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// ---
	case ObjectId(10, 101):
	{
		Vector(0.74f, 0.5328f, 0.7365f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 36);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// ---
	case ObjectId(11, 101):
	{
		Vector(0.74f, 0.5328f, 0.7365f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 4);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
		// ---
		b->TransformByObjectBone(Position, o, 11);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// Evolve Legendary Set
	case ObjectId(7, 102):
	{
		Vector(0.182400f, 0.493400f, 0.960000f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 20);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// ---
	case ObjectId(8, 102):
	{
		Vector(0.182400f, 0.493400f, 0.960000f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 19);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
		// ----
		if (rand() % 12 <= 2)
		{
			float Formula1 = (float)(rand() % 100) / 100.0f;

			vec3_t fVal;

			Vector(Formula1 * 0.5f + 4.0f,
				Formula1 * 0.5f + 4.0f,
				Formula1 * 0.5f + 2.0f, fVal);
			// ---
			Vector(0.182400f, 0.493400f, 0.960000f, Light2);
			Vector(1.f, 1.f, 1.f, Position);
			// ---
			b->TransformByObjectBone(Position, o, 19);
			CreateSprite(32002, Position, fVal[1], Light2, o, fVal[0], 0);
		}
	}
	break;
	// ---
	case ObjectId(9, 102):
	{
		Vector(0.182400f, 0.493400f, 0.960000f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 45);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
		// ---
		b->TransformByObjectBone(Position, o, 49);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// ---
	case ObjectId(10, 102):
	{
		Vector(0.182400f, 0.493400f, 0.960000f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 36);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// ---
	case ObjectId(11, 102):
	{
		Vector(0.182400f, 0.493400f, 0.960000f, Light2);
		Vector(1.f, 1.f, 1.f, Position);
		// ---
		b->TransformByObjectBone(Position, o, 4);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
		// ---
		b->TransformByObjectBone(Position, o, 11);
		CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
	}
	break;
	// Legend Amulet
	case ObjectId(14, 171):
	{
		if (rand() % 25 <= 2)
		{
			Vector(1.f, 0.154f, 0.06f, Light2);
			b->TransformPosition(BoneTransform[9], p, Position, true);
			CreateParticle(32033, Position, o->Angle, Light2, 11, 2.0, 0);
		}
	}
	break;
	// Divine Stone (Added: 19-09-16)
	case ObjectId(14, 172):
	{
		int BoneID[4] = { 1,2,3,4 };
		// ----
		for (int i = 0; i < 4; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.920000f, 0.156400f, 0.461800f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0, 0);
			}
		}
	}
	break;
	// Horrocrux of Fire
	case ObjectId(13, 140):
	{
		if (!SafeZone)
		{
			Vector(1.f, 0.154f, 0.06f, Light2);
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateParticle(32002, Position, o->Angle, Light2, 1);
		}
	}
	break;
	// Horrocrux of Water
	case ObjectId(13, 141):
	{
		if (!SafeZone)
		{
			Vector(0.f, 0.4667f, 1.f, Light2);
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateParticle(32002, Position, o->Angle, Light2, 1);
		}
	}
	break;
	// Horrocrux of Earth
	case ObjectId(13, 142):
	{
		if (!SafeZone)
		{
			Vector(0.9667f, 1.f, 0.f, Light2);
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateParticle(32002, Position, o->Angle, Light2, 1);
		}
	}
	break;
	// Horrocrux of Wind
	case ObjectId(13, 143):
	{
		if (!SafeZone)
		{
			Vector(0.f, 1.f, 0.0167f, Light2);
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateParticle(32002, Position, o->Angle, Light2, 1);
		}
	}
	break;
	// Horrocrux of Thunder
	case ObjectId(13, 144):
	{
		if (!SafeZone)
		{
			Vector(1.f, 0.f, 0.75f, Light2);
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateParticle(32002, Position, o->Angle, Light2, 1);
		}
	}
	break;
	// Horrocrux of Ice
	case ObjectId(13, 145):
	{
		if (!SafeZone)
		{
			Vector(0.86f, 0.986f, 1.f, Light2);
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateParticle(32002, Position, o->Angle, Light2, 1);
		}
	}
	break;
	// Fragment of Fire (Added: 13-10-16)
	case ObjectId(13, 150):
	{
		int BoneID[3] = { 0,1,2 };
		// ----
		for (int i = 0; i < 3; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(1.f, 0.f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0, 0);
			}
		}
	}
	break;
	// Fragment of Earth (Added: 13-10-16)
	case ObjectId(13, 151):
	{
		int BoneID[3] = { 0,1,2 };
		// ----
		for (int i = 0; i < 3; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(1.f, 0.8f, 0.1f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0, 0);
			}
		}
	}
	break;
	// Fragment of Water (Added: 13-10-16)
	case ObjectId(13, 152):
	{
		int BoneID[3] = { 0,1,2 };
		// ----
		for (int i = 0; i < 3; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.f, 0.f, 1.f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0, 0);
			}
		}
	}
	break;
	// Ring of Chaos (Added: 26-11-16)
	case ObjectId(13, 153):
	{
		int BoneID[3] = { 1,2,3 };
		// ----
		for (int i = 0; i < 3; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.9f, 0.53f, 0.13f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0, 0);
			}
		}
	}
	break;
	// Ring of Bless (Added: 28-11-16)
	case ObjectId(13, 154):
	{
		int BoneID[4] = { 1,2,3,4 };
		// ----
		for (int i = 0; i < 4; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.8144f, 0.4042f, 0.86f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID1[2] = { 2,3 };
		// ----
		for (int x = 0; x < 2; x++)
		{
			if (rand() % 10 <= 4)
			{
				Vector(0.98f, 0.98f, 0.98f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
	}
	break;
	// Ring of Soul (Added: 20-12-16)
	case ObjectId(13, 155):
	{
		int BoneID[4] = { 1,2,3,4 };
		// ----
		for (int i = 0; i < 4; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.94f, 0.4888f, 0.8422f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID1[4] = { 2,3,5,6 };
		// ----
		for (int x = 0; x < 4; x++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.98f, 0.98f, 0.98f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
	}
	break;
	// Jewel of Dark Chaos (Added: 19-10-16)
	case ObjectId(14, 173):
	{
		int BoneID[5] = { 0,1,2,3,4 };
		// ----
		for (int i = 0; i < 5; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.f, 0.f, 1.f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0, 0);
			}
			if (rand() % 15 <= 3)
			{
				Vector(0.5167f, 0.f, 1.f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0, 0);
			}
		}
	}
	break;
	// Deathless Amulet (Added: 22-12-16)
	case ObjectId(14, 174):
	{
		Vector(0.f, 0.7187f, 0.98f, Light2);
		// ----
		b->TransformPosition(BoneTransform[28], p, Position, true);
		CreateSprite(32002, Position, 0.7f, Light2, o, 0.40000001f, 0);
		// ----
		b->TransformPosition(BoneTransform[29], p, Position, true);
		CreateSprite(32002, Position, 0.7f, Light2, o, 0.40000001f, 0);
		// ----
		int BoneID[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
		// ----
		for (int i = 0; i < 15; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.98f, 0.8003f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID[i]], p, Position, true);
				CreateSprite(32002, Position, 0.6f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID2[13] = { 15,16,17,18,19,20,21,22,23,24,25,26,27 };
		// ----
		for (int x = 0; x < 13; x++)
		{
			if (rand() % 15 <= 3)
			{
				Vector(0.94f, 0.4f, 0.4f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.6f, Light2, o, 0, 0);
			}
		}
	}
	break;
	// Summon Book of Dark Phoenix (Added: 09-12-16)
	case ObjectId(14, 210):
	{
		int BoneID1[5] = { 0,1,2,3,4 };
		// ----
		for (int i = 0; i < 5; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(1.f, 0.5333f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID2[4] = { 5,6,7,8 };
		// ----
		for (int x = 0; x < 4; x++)
		{
			Vector(1.f, 0.9333f, 0.f, Light2);
			b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
		}
	}
	break;
	// Summon Book of Red Giant Dragon (Added: 09-12-16)
	case ObjectId(14, 211):
	{
		int BoneID1[5] = { 0,1,2,3,4 };
		// ----
		for (int i = 0; i < 5; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(1.f, 0.2167f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID2[4] = { 5,6,7,8 };
		// ----
		for (int x = 0; x < 4; x++)
		{
			Vector(1.f, 0.6333f, 0.f, Light2);
			b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
		}
	}
	break;
	// Summon Book of Kundun Boss (Added: 09-12-16)
	case ObjectId(14, 212):
	{
		int BoneID1[5] = { 0,1,2,3,4 };
		// ----
		for (int i = 0; i < 5; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.f, 0.45f, 1.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID2[4] = { 5,6,7,8 };
		// ----
		for (int x = 0; x < 4; x++)
		{
			Vector(0.f, 0.8f, 1.f, Light2);
			b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
		}
	}
	break;
	// Summon Book of Giant Drakan (Added: 15-02-17)
	case ObjectId(14, 213):
	{
		int BoneID1[5] = { 0,1,2,3,4 };
		// ----
		for (int i = 0; i < 5; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.9f, 0.f, 1.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID2[4] = { 5,6,7,8 };
		// ----
		for (int x = 0; x < 4; x++)
		{
			Vector(1.f, 0.f, 0.f, Light2);
			b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
		}
	}
	break;
	// Summon Book of Iron Knight (Added: 15-02-17)
	case ObjectId(14, 214):
	{
		int BoneID1[5] = { 0,1,2,3,4 };
		// ----
		for (int i = 0; i < 5; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.f, 1.f, 0.9333f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID2[4] = { 5,6,7,8 };
		// ----
		for (int x = 0; x < 4; x++)
		{
			Vector(0.98f, 0.98f, 0.98f, Light2);
			b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
		}
	}
	break;
	// Summon Book of Selupan Boss (Added: 15-02-17)
	case ObjectId(14, 215):
	{
		int BoneID1[5] = { 0,1,2,3,4 };
		// ----
		for (int i = 0; i < 5; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.f, 1.f, 0.6167f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID2[4] = { 5,6,7,8 };
		// ----
		for (int x = 0; x < 4; x++)
		{
			Vector(0.f, 0.5f, 0.9f, Light2);
			b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
		}
	}
	break;
	// Summon Book of Thunder Nappin (Added: 15-02-17)
	case ObjectId(14, 216):
	{
		int BoneID1[5] = { 0,1,2,3,4 };
		// ----
		for (int i = 0; i < 5; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.f, 0.45f, 1.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID2[4] = { 5,6,7,8 };
		// ----
		for (int x = 0; x < 4; x++)
		{
			Vector(0.f, 0.3f, 0.7f, Light2);
			b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
		}
	}
	break;
	// Summon Book of Hell Maine (Added: 28-03-17)
	case ObjectId(14, 217):
	{
		int BoneID1[5] = { 0,1,2,3,4 };
		// ----
		for (int i = 0; i < 5; i++)
		{
			if (rand() % 15 <= 2)
			{
				Vector(1.f, 0.4f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
			}
		}
		// ----
		int BoneID2[4] = { 5,6,7,8 };
		// ----
		for (int x = 0; x < 4; x++)
		{
			Vector(1.f, 0.4f, 0.7f, Light2);
			b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			CreateSprite(32002, Position, 0.3f, Light2, o, 0, 0);
		}
	}
	break;
	}

	if (Select)

		switch (Type)
		{
			// Rune Sacred Blade (Modified:14-07-16)
		case ObjectId(0, 29):
		{
			int BoneID1[4] = { 17,18,20,21 };
			// --
			for (int i = 0; i < 4; i++)
			{
				Vector(0.95f, 0.8588f, 0.038f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			int BoneID2[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
			// --
			for (int x = 0; x < 15; x++)
			{
				Vector(1.0f, 1.0f, 1.0f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32213, Position, 0.6f, Light2, o, 0.5f);
			}
			// --
			if (int y = 15)
			{
				Vector(1.0f, 1.0f, 1.0f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateSprite(32213, Position, 0.2f, Light2, o, 0.5f);
			}
		}
		break;
		// Demonic Sword
		case ObjectId(0, 30):
		{
			float Tick = (float)(rand() % 100) / 100.0f;
			float Vec1 = Tick * 0.5f + 1.0f;
			// ---
			Vector(1.0f, 0.f, 0.f, Light2);
			b->TransformPosition(BoneTransform[0], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, 0.40000001f, 0);
			// ---
			int BoneID1[2] = { 1,2 };
			// --
			for (int i = 0; i < 2; i++)
			{
				Vector(0.95f, 0.8588f, 0.038f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, Vec1);
			}
			int BoneID2[38] = { 3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38 };
			// --
			for (int x = 0; x < 38; x++)
			{
				Vector(0.5291f, 0.72f, 0.4536f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, Vec1);
			}
		}
		break;
		// Cyclone Sword
		case ObjectId(0, 32):
		{
			float Tick = (float)(rand() % 100) / 100.0f;
			float Vec1 = Tick * 0.5f + 1.0f;
			// ---
			Vector(1.f, 0.f, 0.f, Light2);
			b->TransformPosition(BoneTransform[0], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.40000001f, 0);
			// ---
			int BoneID1[7] = { 2,3,4,5,6,7,8 };
			// --
			for (int i = 0; i < 7; i++)
			{
				Vector(0.92f, 0.7406f, 0.092f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.8f, Light2, o, Vec1);
			}
			int BoneID2[7] = { 1,9,10,11,12,13,14 };
			// --
			for (int x = 0; x < 7; x++)
			{
				Vector(0.92f, 0.7406f, 0.092f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.8f, Light2, o, Vec1);
			}
		}
		break;
		// Blast Break (Added:15-07-16)
		case ObjectId(0, 33):
		{
			float TickCount = (float)(rand() % 100) / 88.0f;
			float VectorRot = TickCount * 0.5f + 1.0f;
			// ----
			if (int y = 4)
			{
				if (rand() % 45 <= 15)
				{
					Vector(1.0f, 1.0f, 1.0f, Light2);
					b->TransformPosition(BoneTransform[y], p, Position, true);
					CreateSprite(32211, Position, 0.6f, Light2, o, VectorRot);
				}
			}
			// ----
			int BoneID1[29] = { 0,1,2,3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29 };
			// ----
			for (int i = 0; i < 29; i++)
			{
				Vector(1.0f, 1.0f, 1.0f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32211, Position, 0.5f, Light2, o, VectorRot);
			}
		}
		break;
		// Asura (Added:15-07-16)
		case ObjectId(0, 34):
		{
			float TickCount = (float)(rand() % 100) / 88.0f;
			float VectorRot = TickCount * 0.5f + 1.0f;
			// ----
			int BoneID1[8] = { 7,8,9,10,11,12,13,14 };
			// ----
			for (int x = 0; x < 8; x++)
			{
				if (rand() % 45 <= 15)
				{
					Vector(1.0f, 1.0f, 1.0f, Light2);
					b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
					CreateSprite(32213, Position, 0.4f, Light2, o, VectorRot);
				}
			}
			// ----
			if (rand() % 45 <= 15)
			{
				Vector(0.98f, 0.98f, 0.98f, Light2);
				b->TransformPosition(BoneTransform[0], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, VectorRot);
			}
		}
		break;
		// Absolute Sword of Archangel (Modified: 17-10-16)
		case ObjectId(0, 35):
		{
			int BoneID1[4] = { 0,1,14,15 };
			// ----
			for (int i = 0; i < 4; i++)
			{
				Vector(0.6561f, 0.2829f, 0.69f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
				CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f);
			}
			// ----
			int BoneID2[2] = { 3,4 };
			// ----
			for (int x = 0; x < 2; x++)
			{
				Vector(0.2829f, 0.3372f, 0.69f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0.5f, 0);
				CreateParticle(32269, Position, o->Angle, Light2, 3, 0.3f);
				CreateParticle(32002, Position, o->Angle, Light2, 1, 0.9f, 0);
			}
			// ----
			int BoneID3[3] = { 6,7,8 };
			// ----
			for (int y = 0; y < 3; y++)
			{
				Vector(0.6561f, 0.2829f, 0.69f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[y]], p, Position, true);
				CreateSprite(32002, Position, 0.4f, Light2, o, 0.5f, 0);
				CreateParticle(32269, Position, o->Angle, Light2, 3, 0.4f);
			}
			// ----
			int BoneID4[5] = { 9,10,11,12,13 };
			// ----
			for (int l = 0; l < 5; l++)
			{
				Vector(0.6561f, 0.2829f, 0.69f, Light2);
				b->TransformPosition(BoneTransform[BoneID4[l]], p, Position, true);
				CreateSprite(32002, Position, 0.4f, Light2, o, 0.0041f, 0);
				CreateParticle(32269, Position, o->Angle, Light2, 3, 0.4f);
			}
			// ----
			int BoneID5[55] = { 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,
								32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,
								48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,
								64,65,66,67,68,69,70 };
			// ----
			for (int z = 0; z < 55; z++)
			{
				Vector(0.98f, 0.9702f, 0.833f, Light2);
				b->TransformPosition(BoneTransform[BoneID5[z]], p, Position, true);
				CreateSprite(32002, Position, 0.4f, Light2, o, 0.0041f, 0);
			}
		}
		break;
		// Divine Archangel Blade (Added: 21-09-16)
		case ObjectId(0, 36):
		{
			int BoneID1[5] = { 1,2,3,4,5 };
			// ---
			for (int i = 0; i < 5; i++)
			{
				Vector(0.384f, 0.8064f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID2[14] = { 6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
			// ----
			for (int x = 0; x < 14; x++)
			{
				Vector(0.8118f, 0.9425f, 0.99f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID3[16] = { 20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35 };
			// ----
			for (int z = 0; z < 16; z++)
			{
				Vector(0.8118f, 0.9425f, 0.99f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[z]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0.5f, 0);
			}
		}
		break;
		// Darkness Sword (Added: 21-09-16)
		case ObjectId(0, 37):
		{
			if (int y = 2)
			{
				Vector(1.0f, 0.6167f, 0.0f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
			}
			// ----
			if (int x = 24)
			{
				Vector(0.0f, 0.9167f, 1.0f, Light2);
				b->TransformPosition(BoneTransform[x], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID1[8] = { 1,3,4,5,6,7,8,9 };
			// ----
			for (int i = 0; i < 8; i++)
			{
				Vector(1.0f, 0.9167f, 0.0f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID2[11] = { 12,13,14,15,16,17,18,19,20,21,23 };
			// ----
			for (int j = 0; j < 11; j++)
			{
				Vector(1.0f, 0.9167f, 0.0f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[j]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID3[10] = { 26,27,28,29,30,31,32,33,34,35 };
			// ----
			for (int w = 0; w < 10; w++)
			{
				Vector(0.7189f, 0.7841f, 0.79f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[w]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID4[10] = { 37,38,39,40,41,42,43,44,45,46 };
			// ----
			for (int z = 0; z < 10; z++)
			{
				Vector(0.7189f, 0.7841f, 0.79f, Light2);
				b->TransformPosition(BoneTransform[BoneID4[z]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID5[5] = { 47,48,49,51,52 };
			// ----
			for (int n = 0; n < 5; n++)
			{
				Vector(0.7189f, 0.7841f, 0.79f, Light2);
				b->TransformPosition(BoneTransform[BoneID5[n]], p, Position, true);
				CreateSprite(32002, Position, 0.2f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID6[15] = { 54,55,56,57,58,59,60,61,62,63,64,65,66,67,68 };
			// ----
			for (int k = 0; k < 15; k++)
			{
				Vector(0.7189f, 0.7841f, 0.79f, Light2);
				b->TransformPosition(BoneTransform[BoneID6[k]], p, Position, true);
				CreateSprite(32002, Position, 0.2f, Light2, o, 0.5f, 0);
			}
		}
		break;
		// Darkness Blade (Added: 23-09-16)
		case ObjectId(0, 38):
		{
			if (rand() % 25 <= 2)
			{
				if (int y = 17)
				{
					Vector(0.5358f, 0.812f, 0.94f, Light2);
					b->TransformPosition(BoneTransform[y], p, Position, true);
					CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
				}
				// ----
				int BoneID[47] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48 };
				// ----
				for (int x = 0; x < 47; x++)
				{
					Vector(1.0f, 0.3258f, 0.54f, Light2);
					b->TransformPosition(BoneTransform[BoneID[x]], p, Position, true);
					CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
				}
			}
		}
		break;
		// Blood Angel Sword (Added: 21-04-17)
		case ObjectId(0, 39):
		{
			Vector(1.f, 0.f, 0.f, Light2);
			// ----
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
			// ----
			b->TransformPosition(BoneTransform[2], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
			// ----
			b->TransformPosition(BoneTransform[3], p, Position, true);
			CreateParticle(32273, Position, o->Angle, Light2, 11, 1.f, o);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.f, 0, 0, -1);
			// ----
			if (int i = 3)
			{
				Vector(0.8f, 0.8f, 0.8f, Light2);
				b->TransformPosition(BoneTransform[i], p, Position, true);
				CreateSprite(32273, Position, 0.3f, Light2, o, 0.00004f, 11);
				CreateParticle(32273, Position, o->Angle, Light2, 11, 0.4f, o);
			}
			// ----
			if (int y = 3)
			{
				Vector(0.9325f, 0.94f, 0.4888f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateSprite(32273, Position, 0.4f, Light2, o, 0.00004f, 11);
				CreateParticle(32273, Position, o->Angle, Light2, 11, 0.5f, o);
			}
		}
		break;
		// Blood Angel Blade (Added: 21-04-17)
		case ObjectId(0, 40):
		{
			Vector(1.f, 0.f, 0.f, Light2);
			// ----
			b->TransformPosition(BoneTransform[7], p, Position, true);
			CreateParticle(32273, Position, o->Angle, Light2, 11, 0.5f, o);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.f, 0, 0, -1);
			// ----
			int BoneID1[6] = { 1,2,3,4,5,6 };
			// ----
			for (int i = 0; i < 6; i++)
			{
				Vector(1.f, 0.f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0.5f, 0);
			}
			// ----
			if (int x = 7)
			{
				Vector(0.8f, 0.8f, 0.8f, Light2);
				b->TransformPosition(BoneTransform[x], p, Position, true);
				CreateSprite(32273, Position, 0.3f, Light2, o, 0.00004f, 11);
				CreateParticle(32273, Position, o->Angle, Light2, 11, 0.4f, o);
			}
			// ----
			if (int y = 7)
			{
				Vector(0.9325f, 0.94f, 0.4888f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateSprite(32273, Position, 0.4f, Light2, o, 0.00004f, 11);
				CreateParticle(32273, Position, o->Angle, Light2, 11, 0.5f, o);
			}
		}
		case ObjectId(0, 42): //Blade of jay
		{
			int BoneID1[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

			//Vector(1.f, 0.f, 0.f, Light2);
			// ----
			//b->TransformPosition(BoneTransform[11], p, Position, true);
			//CreateParticle(32273, Position, o->Angle, Light2, 11, 0.5f, o);
			//CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.f, 0, 0, -1);
			Vector(0.9833f, 1.f, 0.f, Light2);
			b->TransformPosition(BoneTransform[2], p, Position, true);
			CreateSprite(32115, Position, 0.7f, Light2, o, 0.2f, 0);

			b->TransformPosition(BoneTransform[4], p, Position, true);
			CreateSprite(32115, Position, 0.7f, Light2, o, 0.2f, 0);

			b->TransformPosition(BoneTransform[8], p, Position, true);
			CreateSprite(32115, Position, 0.7f, Light2, o, 0.2f, 0);

			b->TransformPosition(BoneTransform[10], p, Position, true);
			CreateSprite(32115, Position, 0.7f, Light2, o, 0.2f, 0);

			for (int i = 0; i < 11; i++)
			{
				Vector(1.f, 0.f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32038, Position, 0.6f, Light2, o, 0.5f, 0);
			}
		}
		break;
		// Ice Storm Hammer
		case ObjectId(2, 20):
		{
			if (rand() % 25 <= 2)
			{
				Vector(0.5358f, 0.812f, 0.94f, Light2);
				b->TransformPosition(BoneTransform[9], p, Position, true);
				CreateParticle(32273, Position, o->Angle, Light2, 0, 1.0f, o);
			}
			// --
			int BoneID1[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
			// --
			for (int i = 0; i < 11; i++)
			{
				Vector(0.8736f, 0.8649f, 0.93f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0.5f);
			}
			// --
			int BoneID2[25] = { 11,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
			// --
			for (int x = 0; x < 25; x++)
			{
				Vector(0.5358f, 0.812f, 0.94f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0.5f);
			}
			// --
			int BoneID3[26] = { 12,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61 };
			// --
			for (int y = 0; y < 26; y++)
			{
				Vector(0.5358f, 0.812f, 0.94f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[y]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0.5f);
			}
		}
		break;
		// Bone Crusher
		case ObjectId(2, 21):
		{
			int BoneID1[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
			// --
			for (int x = 0; x < 12; x++)
			{
				Vector(1.f, 0.f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32002, Position, 0.8f, Light2, o, 0.5f);
			}
			// --
			int BoneID2[12] = { 13,14,15,16,17,18,19,20,21,22,23,24 };
			// --
			for (int y = 0; y < 12; y++)
			{
				Vector(0.5358f, 0.812f, 0.94f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[y]], p, Position, true);
				CreateSprite(32002, Position, 0.8f, Light2, o, 0.5f);
			}
		}
		break;
		// Thunder Bolt Scepter
		case ObjectId(2, 22):
		{
			Vector(0.576f, 0.9088f, 0.96f, Light2);
			b->TransformPosition(BoneTransform[9], p, Position, true);
			CreateSprite(32211, Position, 0.8f, Light2, o, 0.40000001f, 0);
			// --
			int BoneID1[6] = { 0,3,4,7,8,10 };
			// --
			for (int x = 0; x < 6; x++)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			int BoneID2[9] = { 13,14,19,22,24,26,27,29,31 };
			// --
			for (int y = 0; y < 9; y++)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[y]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Horn of Steel
		case ObjectId(2, 23):
		{
			int BoneID1[16] = { 0,1,2,5,6,7,13,14,19,20,21,22,23,24,25,26 };
			// --
			for (int x = 0; x < 16; x++)
			{
				Vector(0.52f, 0.51f, 0.50f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			int BoneID2[14] = { 8,9,10,11,15,16,17,18,27,28,29,30,31,32 };
			// --
			for (int y = 0; y < 14; y++)
			{
				Vector(0.9088f, 0.50f, 0.9662f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[y]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Absolute Scepter of Archangel (Added: 19-09-16)
		case ObjectId(2, 24):
		{
			Vector(0.576f, 0.9088f, 0.96f, Light2);
			b->TransformPosition(BoneTransform[84], p, Position, true);
			CreateParticle(32002, Position, o->Angle, Light2, 0, 0.5f);
			// ----
			if (int y = 83)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateParticle(32273, Position, o->Angle, Light2, 0, 0.5f, o);
			}
			// ----
			if (int x = 82)
			{
				Vector(0.921f, 0.1564f, 0.46f, Light2);
				b->TransformPosition(BoneTransform[x], p, Position, true);
				CreateParticle(32273, Position, o->Angle, Light2, 0, 0.5f, o);
			}
			// ----
			if (int g = 81)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[g], p, Position, true);
				CreateParticle(32273, Position, o->Angle, Light2, 0, 0.5f, o);
			}
			// ----
			if (int z = 76)
			{
				Vector(0.921f, 0.1564f, 0.46f, Light2);
				b->TransformPosition(BoneTransform[z], p, Position, true);
				CreateParticle(32273, Position, o->Angle, Light2, 0, 0.5f, o);
			}
			// ----
			if (int d = 75)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[d], p, Position, true);
				CreateParticle(32002, Position, o->Angle, Light2, 0, 0.5f, o);
			}
			// ----
			int BoneID1[4] = { 77,78,79,80 };
			// ----
			for (int h = 0; h < 4; h++)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[h]], p, Position, true);
				CreateParticle(32002, Position, o->Angle, Light2, 0, 0.5f, o);
			}
		}
		break;
		// Darkness Scepter (Added: 23-09-16)
		case ObjectId(2, 25):
		{
			if (int y = 11)
			{
				Vector(0.4095f, 0.7598f, 0.91f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateParticle(32273, Position, o->Angle, Light2, 0, 1.0f, o);
			}
			// ----
			if (rand() % 15 <= 2)
			{
				int BoneID1[10] = { 1,2,3,4,5,6,7,8,9,10 };
				// ----
				for (int i = 0; i < 10; i++)
				{
					Vector(0.7189f, 0.7841f, 0.79f, Light2);
					b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
					CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
				}
			}
			// ----
			if (rand() % 23 <= 4)
			{
				int BoneID2[8] = { 12,13,14,15,16,17,18,19 };
				// ----
				for (int x = 0; x < 8; x++)
				{
					Vector(1.f, 0.28f, 0.28f, Light2);
					b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
					CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 1);
				}
			}
			// ----
			if (rand() % 9 <= 2)
			{
				int BoneID3[15] = { 20,21,22,23,24,25,26,27,28,29,30,31,32,33,34 };
				int BoneID4[15] = { 35,36,37,38,39,40,41,42,43,44,45,46,47,48,49 };
				int BoneID5[15] = { 50,51,52,53,54,55,56,57,58,60,61,62,63,64,65 };
				int BoneID6[16] = { 66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81 };
				// ----
				for (int z = 0; z < 15; z++)
				{
					Vector(0.95f, 0.75f, 0.45f, Light2);
					b->TransformPosition(BoneTransform[BoneID3[z]], p, Position, true);
					CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 1);
				}
				// ----
				for (int w = 0; w < 15; w++)
				{
					Vector(0.95f, 0.75f, 0.45f, Light2);
					b->TransformPosition(BoneTransform[BoneID4[w]], p, Position, true);
					CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 1);
				}
				// ----
				for (int u = 0; u < 15; u++)
				{
					Vector(0.95f, 0.75f, 0.45f, Light2);
					b->TransformPosition(BoneTransform[BoneID5[u]], p, Position, true);
					CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 1);
				}
				// ---
				for (int s = 0; s < 16; s++)
				{
					Vector(0.95f, 0.75f, 0.45f, Light2);
					b->TransformPosition(BoneTransform[BoneID6[s]], p, Position, true);
					CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 1);
				}
			}
		}
		break;
		// Galia Spear
		case ObjectId(3, 12):
		{
			int BoneID1[7] = { 1,2,3,4,5,6,7 };
			// ---
			for (int x = 0; x < 7; x++)
			{
				Vector(0.97f, 0.9118f, 0.9118f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// ---
			int BoneID2[7] = { 8,9,10,11,12,13,14 };
			// ---
			for (int y = 0; y < 7; y++)
			{
				Vector(1.f, 0.28f, 0.28f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[y]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// ---
			int BoneID3[8] = { 15,16,17,18,19,20,21,22 };
			// ---
			for (int j = 0; j < 8; j++)
			{
				Vector(0.97f, 0.9118f, 0.9118f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[j]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// ---
			int BoneID4[6] = { 23,24,25,26,27,28 };
			// ---
			for (int k = 0; k < 6; k++)
			{
				Vector(1.f, 0.28f, 0.28f, Light2);
				b->TransformPosition(BoneTransform[BoneID4[k]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
				// ---
				if (!SafeZone)
				{
					CreateParticle(32002, Position, o->Angle, Light2, 1, 0.5f);
				}
			}
		}
		break;
		// Lightning Bow (Modified:14-07-16)
		case ObjectId(4, 25):
		{
			int BoneID1[7] = { 0,1,2,3,5,6,7 };
			// ---
			for (int x = 0; x < 7; x++)
			{
				Vector(0.4095f, 0.7598f, 0.91f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32211, Position, 1.2f, Light2, o, 0.5f);
			}
			// ---
			Vector(0.4095f, 0.7598f, 0.91f, Light2);
			b->TransformPosition(BoneTransform[12], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[13], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[14], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[15], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[16], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[17], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[18], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[19], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[20], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[21], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[22], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[23], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[24], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[25], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[26], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[27], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[28], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[29], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			b->TransformPosition(BoneTransform[30], p, Position, true);
			CreateSprite(32002, Position, 0.9f, Light2, o, 0.5f, 0);
			// ---
			if (!SafeZone)
			{
				b->TransformPosition(BoneTransform[31], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
				CreateParticle(32248, Position, o->Angle, Light2, 0, 0.5f, o);
			}
			// ---
			if (!SafeZone)
			{
				b->TransformPosition(BoneTransform[33], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
				CreateParticle(32002, Position, o->Angle, Light2, 1, 0.5f, o);
			}
		}
		break;
		// Divinity Bow
		case ObjectId(4, 26):
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.95f, 0.8588f, 0.038f, Light2);
				b->TransformPosition(BoneTransform[30], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			}
			int BoneID1[29] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29 };
			// --
			for (int i = 0; i < 29; i++)
			{
				Vector(0.95f, 0.836f, 0.8968f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Angelic Bow
		case ObjectId(4, 27):
		{
			if (rand() % 15 <= 2)
			{
				Vector(0.2322f, 0.86f, 0.2322f, Light2);
				b->TransformPosition(BoneTransform[9], p, Position, true);
				CreateParticle(32002, Position, o->Angle, Light2, 0, 0.5f, o);
				CreateEffect(388, Position, o->Angle, Light2, 2, o, -1, 0, -2.1f, 0, 0);
			}
			int BoneID1[18] = { 12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29 };
			// --
			for (int i = 0; i < 18; i++)
			{
				Vector(0.2322f, 0.86f, 0.2322f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Thunder Bow
		case ObjectId(4, 28):
		{
			int BoneID1[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
			int BoneID2[15] = { 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
			int BoneID3[15] = { 31,32,33,34,35,36,37,38,39,40,41,42,43,44,45 };
			// --
			for (int x = 0; x < 15; x++)
			{
				Vector(0.9765f, 0.99f, 0.5841f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			for (int y = 0; y < 15; y++)
			{
				Vector(0.9765f, 0.99f, 0.5841f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[y]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			for (int z = 0; z < 15; z++)
			{
				Vector(0.9765f, 0.99f, 0.5841f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[z]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Darkness Bow (Added:29-10-16)
		case ObjectId(4, 29):
		{
			float TickCount = (float)(rand() % 100) / 87.0f;
			float VectorRot = TickCount * 0.5f + 1.0f;
			// ----
			int BoneID1[67] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
			31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,
			58,59,60,61,62,63,64,65,66 };
			// ----
			if (rand() % 25 <= 4)
			{
				for (int i = 0; i < 67; i++)
				{
					Vector(1.f, 0.f, 0.f, Light2);
					b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
					CreateSprite(32002, Position, 0.4f, Light2, o, VectorRot);
				}
			}
		}
		break;
		// Devil Crossbow
		case ObjectId(4, 129):
		{
			Vector(1.f, 0.f, 0.f, Light2);
			// ---
			b->TransformPosition(BoneTransform[12], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[13], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[15], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[16], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[17], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[18], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[19], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[20], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[21], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[22], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[23], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[24], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[25], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[26], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[27], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[28], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[29], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[30], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[31], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[32], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[33], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[34], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[35], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[36], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[37], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[38], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[39], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[40], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[41], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[42], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[43], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[44], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[45], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[46], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
			// ---
			b->TransformPosition(BoneTransform[47], p, Position, true);
			CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
		}
		break;
		// Absolute Crossbow of Archangel (Added: 19-09-16)
		case ObjectId(4, 130):
		{
			int BoneID1[3] = { 44,45,46 };
			// ----
			for (int h = 0; h < 3; h++)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[h]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
				CreateParticle(32002, Position, o->Angle, Light2, 0, 0.9f, o);
			}
			// ----
			int BoneID2[3] = { 14,15,16 };
			// ----
			for (int x = 0; x < 3; x++)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, -2.1f, 0);
				CreateParticle(32002, Position, o->Angle, Light2, 0, 0.9f, o);
			}
			// ----
			Vector(0.4095f, 0.7598f, 0.91f, Light2);
			b->TransformPosition(BoneTransform[60], p, Position, true);
			CreateParticle(32273, Position, o->Angle, Light2, 11, 2.0, 0);
		}
		break;
		// Angelical Staff
		case ObjectId(5, 35):
		{
			Vector(0.2139f, 0.69f, 0.3012f, Light2);
			b->TransformPosition(BoneTransform[5], p, Position, true);
			CreateParticle(32273, Position, o->Angle, Light2, 11, 2.0, 0);
			CreateParticle(32002, Position, o->Angle, Light2, 1, 2.3f, 0);
			// --
			int BoneID1[4] = { 1,2,3,4 };
			// --
			for (int i = 0; i < 4; i++)
			{
				Vector(0.2139f, 0.69f, 0.3012f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Cerberus Staff
		case ObjectId(5, 36):
		{
			Vector(1.f, 1.f, 1.f, Light2);
			// --
			b->TransformPosition(BoneTransform[7], p, Position, true);
			CreateParticle(32002, Position, o->Angle, Light2, 0, -2.1f, o);
			// --
			b->TransformPosition(BoneTransform[8], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0);
			// --
			int BoneID1[14] = { 0,1,2,3,4,5,6,18,19,20,21,22,23,24 };
			// --
			for (int i = 0; i < 14; i++)
			{
				Vector(0.67f, 0.4346f, 0.1922f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			int BoneID2[13] = { 9,10,11,12,13,14,15,16,17,25,26,27,28 };
			// --
			for (int x = 0; x < 13; x++)
			{
				Vector(0.67f, 0.4346f, 0.1922f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Miracle Staff
		case ObjectId(5, 37):
		{
			if (int y = 6)
			{
				Vector(0.3361f, 0.2944f, 0.92f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateParticle(32003, Position, o->Angle, Light2, 2, 1.0, 0);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 2.0, 0);
			}
			// --
			if (int k = 6)
			{
				Vector(0.92f, 0.2944f, 0.3361f, Light2);
				b->TransformPosition(BoneTransform[k], p, Position, true);
				CreateParticle(32003, Position, o->Angle, Light2, 2, 1.0, 0);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 2.0, 0);
			}
			// --
			int BoneID3[9] = { 0,1,2,3,4,7,8,9,10 };
			// --
			for (int i = 0; i < 9; i++)
			{
				Vector(0.9765f, 0.99f, 0.5841f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			int BoneID4[9] = { 0,1,2,3,4,7,8,9,10 };
			// --
			for (int x = 0; x < 9; x++)
			{
				Vector(0.9765f, 0.99f, 0.5841f, Light2);
				b->TransformPosition(BoneTransform[BoneID4[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Summon Spirit Stick (Added:14-07-16)
		case ObjectId(5, 38):
		{
			int BoneID1[6] = { 0,1,2,3,4,9 };
			// --
			for (int i = 0; i < 6; i++)
			{
				Vector(0.9765f, 0.3f, 0.1f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32115, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			int BoneID2[3] = { 6,7,8 };
			// --
			for (int x = 0; x < 3; x++)
			{
				Vector(0.9765f, 0.3f, 0.1f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32115, Position, 0.8f, Light2, o, 0.8f);
			}
			// --
			if (int y = 9)
			{
				Vector(0.9765f, 0.3f, 0.1f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f);
			}
		}
		break;
		// Divine Archangel Stick (Added: 21-09-16) -> Identical
		case ObjectId(5, 39):
		{
			int BoneID1[30] = { 16,17,18,19,20,21,22,23,24,25,26,27,28,29,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46 };
			// ----
			for (int i = 0; i < 30; i++)
			{
				Vector(0.98f, 0.2548f, 0.5932f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.6f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID2[6] = { 47,48,49,50,52,53 };
			// ----
			for (int x = 0; x < 6; x++)
			{
				Vector(0.99f, 0.858f, 0.0f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
			}
			// ----
			int BoneID3[6] = { 8,9,10,12,13,14 };
			// ----
			for (int g = 0; g < 6; g++)
			{
				Vector(0.98f, 0.9767f, 0.931f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[g]], p, Position, true);
				CreateSprite(32002, Position, 1.2f, Light2, o, 0.5f, 0);
			}
			// ----
			if (int y = 30)
			{
				Vector(0.99f, 0.495f, 0.0f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateSprite(32002, Position, 0.7f, Light2, o, 0.5f, 0);
			}
		}
		break;
		// Absolute Archangel Staff (Added: 24-09-16)
		case ObjectId(5, 40):
		{
			if (rand() % 25 <= 2)
			{
				if (int h = 100)
				{
					Vector(0.4095f, 0.7598f, 0.91f, Light2);
					b->TransformPosition(BoneTransform[h], p, Position, true);
					CreateParticle(32273, Position, o->Angle, Light2, 11, 2.0, 0);
					CreateParticle(32002, Position, o->Angle, Light2, 1, 2.3f, 0);
				}
				// ----
				int BoneID1[8] = { 92,93,94,95,96,97,98,99 };
				// ----
				for (int i = 0; i < 8; i++)
				{
					Vector(0.98f, 0.2548f, 0.5932f, Light2);
					b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
					CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f, 0);
				}
			}
		}
		break;
		// Darkness Staff (Added: 14-10-16)
		case ObjectId(5, 41):
		{
			Vector(0.99f, 0.9306f, 0.396f, Light2);
			b->TransformPosition(BoneTransform[38], p, Position, true);
			CreateParticle(32273, Position, o->Angle, Light2, 11, 1.2f, 0);
			CreateParticle(32002, Position, o->Angle, Light2, 1, 2.3f, 0);
			// ----
			int BoneID1[6] = { 37,39,40,41,42,43 };
			// ----
			for (int i = 0; i < 6; i++)
			{
				Vector(0.99f, 0.9306f, 0.396f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// ----
			int BoneID2[16] = { 7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22 };
			// ----
			for (int x = 0; x < 16; x++)
			{
				Vector(0.94f, 0.1128f, 0.9124f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.4f, Light2, o, 0.5f);
			}
			// ----
			int BoneID3[28] = { 0,1,2,3,4,5,6,23,24,25,26,27,28,29,30,31,32,33,34,35,36,44,45,46,47,48,49,50 };
			// ----
			for (int z = 0; z < 28; z++)
			{
				Vector(0.94f, 0.1128f, 0.9124f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[z]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Blood Angel Staff (Added: 21-04-17)
		case ObjectId(5, 42):
		{
			Vector(1.f, 0.f, 0.f, Light2);
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateParticle(32273, Position, o->Angle, Light2, 11, 1.2f, 0);
			CreateParticle(32002, Position, o->Angle, Light2, 1, 2.3f, 0);
			// ----
			if (int i = 1)
			{
				Vector(0.8f, 0.8f, 0.8f, Light2);
				b->TransformPosition(BoneTransform[i], p, Position, true);
				CreateSprite(32273, Position, 0.7f, Light2, o, 0.00004f, 11);
				CreateParticle(32273, Position, o->Angle, Light2, 11, 0.8f, o);
			}
			// ----
			if (int y = 1)
			{
				Vector(0.9325f, 0.94f, 0.4888f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateSprite(32273, Position, 0.8f, Light2, o, 0.00004f, 11);
				CreateParticle(32273, Position, o->Angle, Light2, 11, 0.9f, o);
			}
			// ----
			if (int g = 1)
			{
				if (rand() % 25 <= 2)
				{
					Vector(1.f, 0.f, 0.f, Light2);
					b->TransformPosition(BoneTransform[g], p, Position, true);
					CreateParticle(32205, Position, o->Angle, Light2, 0, 1.f, o);
				}
			}
			// ----
			int BoneID[3] = { 2,3,4 };
			// ----
			for (int j = 0; j < 3; j++)
			{
				Vector(1.f, 0.f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID[j]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.00004f, 0);
			}
			// ----
			for (int k = 0; k < 3; k++)
			{
				Vector(0.9325f, 0.94f, 0.4888f, Light2);
				b->TransformPosition(BoneTransform[BoneID[k]], p, Position, true);
				CreateSprite(32002, Position, 0.4f, Light2, o, 0.00004f, 0);
			}
			// ----
			for (int l = 0; l < 3; l++)
			{
				Vector(0.8f, 0.8f, 0.8f, Light2);
				b->TransformPosition(BoneTransform[BoneID[l]], p, Position, true);
				CreateSprite(32002, Position, 0.3f, Light2, o, 0.00004f, 0);
			}
		}
		break;
		// Blood Angel Bow (Added: 21-04-17)
		case ObjectId(4, 30):
		{
			Vector(1.f, 0.f, 0.f, Light2);
			// ----
			b->TransformPosition(BoneTransform[37], p, Position, true);
			CreateParticle(32273, Position, o->Angle, Light2, 11, 1.f, o);
			CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.f, 0, 0, -1);
			// ----
			if (int y = 37)
			{
				Vector(0.9325f, 0.94f, 0.4888f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateSprite(32273, Position, 0.8f, Light2, o, 0.00004f, 11);
				CreateParticle(32273, Position, o->Angle, Light2, 11, 0.9f, o);
			}
			// ----
			if (int i = 37)
			{
				Vector(0.8f, 0.8f, 0.8f, Light2);
				b->TransformPosition(BoneTransform[i], p, Position, true);
				CreateSprite(32273, Position, 0.7f, Light2, o, 0.00004f, 11);
				CreateParticle(32273, Position, o->Angle, Light2, 11, 0.8f, o);
			}
		}
		break;
		// Angelical Shield
		case ObjectId(6, 22):
		{
			int BoneID1[10] = { 3,4,5,6,71,72,73,74,75,76 };
			// --
			for (int i = 0; i < 10; i++)
			{
				Vector(0.2139f, 0.69f, 0.3012f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			int BoneID2[46] = { 13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58 };
			// --
			for (int x = 0; x < 46; x++)
			{
				Vector(0.98f, 0.9725f, 0.5292f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			int BoneID3[12] = { 59,60,61,62,63,64,65,66,67,68,69,70 };
			// --
			for (int j = 0; j < 12; j++)
			{
				Vector(0.9f, 0.8991f, 0.846f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[j]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Storm Wing Shield
		case ObjectId(6, 23):
		{
			int BoneID1[17] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
			// --
			for (int i = 0; i < 17; i++)
			{
				Vector(0.92f, 0.7406f, 0.092f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
		}
		break;
		// Cerberus Shield
		case ObjectId(6, 24):
		{
			float Formula = (double)(rand() % 100) / 100.0f;
			// --
			vec3_t fVal;
			Vector(Formula * 0.5f + 0.005f, Formula * 0.5f + 0.005f, Formula * 0.5f + 0.002f, fVal);
			// --
			Vector(1.f, 1.f, 1.f, Light2);
			b->TransformPosition(BoneTransform[5], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, 0.5f);
			// --
			b->TransformPosition(BoneTransform[6], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, 0.5f);
			// --
			if (rand() % 15 < 12)
			{
				Vector(1.f, 0.f, 0.f, Light2);
				b->TransformPosition(BoneTransform[5], p, Position, true);
				CreateSprite(32002, Position, fVal[1], Light2, o, 0.5f);
				// --
				b->TransformPosition(BoneTransform[6], p, Position, true);
				CreateSprite(32002, Position, fVal[1], Light2, o, 0.5f);
			}
			// --
			int BoneID1[36] = { 0,1,2,3,4,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37 };
			// --
			for (int i = 0; i < 36; i++)
			{
				Vector(0.67f, 0.4346f, 0.1922f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.0400001f);
			}
		}
		break;
		// Hell Knight Shield
		case ObjectId(6, 25):
		{
			double Formula = (double)(rand() % 15) / 57.8231f;
			vec3_t fVal;
			Vector(Formula * 0.5f + 0.1f, Formula * 0.5f + 0.00041f, Formula * 0.5f + 2.0f, fVal);
			// --
			if (int i = 2)
			{
				Vector(1.f, 0.f, 0.f, Light2);
				b->TransformPosition(BoneTransform[i], p, Position, true);
				CreateSprite(32002, Position, fVal[1], Light2, o, fVal[2]);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 1.0, 0);
			}
			// --
			int BoneID1[14] = { 0,1,3,4,5,6,7,8,9,10,11,12,13,14 };
			// --
			for (int x = 0; x < 14; x++)
			{
				Vector(0.84f, 0.2184f, 0.8193f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
			}
			// --
			int BoneID2[15] = { 15,16,17,18,19,20,21,22,23,24,25,26,27,28,29 };
			// --
			for (int y = 0; y < 15; y++)
			{
				Vector(0.84f, 0.2184f, 0.8193f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[y]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
			}
		}
		break;
		// Embisyeon Shield
		case ObjectId(6, 26):
		{
			double Formula = (double)(rand() % 2) / 56.8453f;
			// ----
			vec3_t fVal;
			Vector(Formula * 0.5f + 0.1f, Formula * 0.5f + 0.00041f, Formula * 0.5f + 2.0f, fVal);
			// ----
			if (int i = 3)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[i], p, Position, true);
				CreateSprite(32002, Position, fVal[1], Light2, o, fVal[2]);
			}
			// ----
			if (int u = 4)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[u], p, Position, true);
				CreateSprite(32002, Position, fVal[1], Light2, o, fVal[2]);
			}
			// ----
			int BoneID1[6] = { 6,7,8,9,10,11 };
			// ----
			for (int x = 0; x < 6; x++)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[x]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
				CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f, o);
			}
			// ----
			int BoneID2[4] = { 12,13,14,15 };
			// ----
			for (int y = 0; y < 4; y++)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[y]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
				CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f, o);
			}
		}
		break;
		// Sphere Shield (Added: 12-11-16)
		case ObjectId(6, 27):
		{
			double Formula = (double)(rand() % 27) / 100.0f;
			// ----
			vec3_t fVal;
			Vector(Formula * 0.5f + 0.1f, Formula * 0.5f + 0.2f, Formula * 0.5f + 0.3f, fVal);
			// ----
			int BoneID1[14] = { 0,1,2,3,4,5,9,13,14,19,20,21,22,23 };
			// ----
			for (int i = 0; i < 14; i++) // -> Blue Lights
			{
				if (rand() % 21 < 7)
				{
					Vector(0.f, 0.7f, 1.0f, Light2);
					b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
					CreateSprite(32002, Position, fVal[1], Light2, o, fVal[0], 0);
				}
				// ----
				if (rand() % 21 < 5)
				{
					Vector(0.f, 0.7f, 1.0f, Light2);
					b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
					CreateSprite(32002, Position, fVal[1], Light2, o, fVal[1], 0);
				}
				// ----
				if (rand() % 21 < 3)
				{
					Vector(0.f, 0.7f, 1.0f, Light2);
					b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
					CreateSprite(32002, Position, fVal[1], Light2, o, fVal[2], 0);
				}
			}
			// ----
			int BoneID2[6] = { 6,7,8,10,11,12 };
			// ----
			for (int x = 0; x < 6; x++) // -> Purple Lights
			{
				if (rand() % 42 < 14)
				{
					Vector(0.86f, 0.4558f, 0.8331f, Light2);
					b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
					CreateSprite(32002, Position, fVal[0], Light2, o, fVal[0], 0);
				}
			}
			// ----
			int BoneID3[4] = { 15,16,17,18 };
			// ----
			for (int z = 0; z < 4; z++) // -> Red Lights
			{
				if (rand() % 55 <= 33)
				{
					Vector(0.96f, 0.0288f, 0.184f, Light2);
					b->TransformPosition(BoneTransform[BoneID3[z]], p, Position, true);
					CreateSprite(32002, Position, fVal[0], Light2, o, fVal[0], 0);
				}
			}
		}
		break;
		// Magic Wings
		case ObjectId(12, 236):
		{
			double Formula = (double)(rand() % 100) / 100.0f;
			// ----
			vec3_t fVal;
			Vector(Formula * 0.5f + 1.5f, Formula * 0.5f + 1.2f, Formula * 0.5f + 1.0f, fVal);
			// ----
			Vector(0.8f, 0.35f, 0.1f, Light2);
			// ----
			b->TransformPosition(BoneTransform[8], p, Position, true);
			CreateSprite(32002, Position, fVal[1], Light2, o, fVal[0], 0);
			// ----
			b->TransformPosition(BoneTransform[16], p, Position, true);
			CreateSprite(32002, Position, fVal[1], Light2, o, fVal[0], 0);
		}
		break;
		// Chaos Wings
		case ObjectId(12, 237):
		{
			Vector(1.f, 1.f, 1.f, Light2);
			// ----
			b->TransformPosition(BoneTransform[43], p, Position, true);
			CreateSprite(32213, Position, 1.2f, Light2, o, 0.7f, 0);
		}
		break;
		// Life Wings
		case ObjectId(12, 238):
		{
			int BoneID1[8] = { 5,6,7,16,17,18,26,34 };
			// --
			for (int i = 0; i < 8; i++)
			{
				Vector(1.f, 0.f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 0.5f, Light2, o, 0.5f);
			}
			// --
			int BoneID2[2] = { 11,22 };
			// --
			for (int x = 0; x < 2; x++)
			{
				Vector(1.f, 0.4667f, 0.f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateSprite(32002, Position, 0.8f, Light2, o);
			}
			// ---
			Vector(0.9686f, 0.98f, 0.294f, Light2);
			// ---
			b->TransformPosition(BoneTransform[2], p, Position, true);
			CreateSprite(32002, Position, 3.5f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[3], p, Position, true);
			CreateSprite(32002, Position, 1.5f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[9], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[13], p, Position, true);
			CreateSprite(32002, Position, 3.5f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[14], p, Position, true);
			CreateSprite(32002, Position, 1.5f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[21], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[24], p, Position, true);
			CreateSprite(32002, Position, 2.5f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[25], p, Position, true);
			CreateSprite(32002, Position, 1.2f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[29], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[32], p, Position, true);
			CreateSprite(32002, Position, 2.5f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[33], p, Position, true);
			CreateSprite(32002, Position, 1.2f, Light2, o, 0.2f);
			// ---
			b->TransformPosition(BoneTransform[37], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
		}
		break;
		// Heaven Wings
		case ObjectId(12, 240):
		{
			double Formula = (double)(rand() % 100) / 100.0f;
			// ---
			vec3_t fVal;
			Vector(Formula * 0.5f + 4.0f, Formula * 0.5f + 4.0f, Formula * 0.5f + 2.0f, fVal);
			// ---
			Vector(0.f, 0.3511f, 1.f, Light2);
			// ---
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateSprite(32002, Position, fVal[1], Light2, o, fVal[0], 0);
			// ---
			if (int x = 2)
			{
				Vector(0.87f, 0.f, 1.f, Light2);
				b->TransformPosition(BoneTransform[x], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			}
			// ---
			if (int y = 6)
			{
				Vector(0.87f, 0.f, 1.f, Light2);
				b->TransformPosition(BoneTransform[y], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			}
		}
		break;
		// Demonic Wings
		case ObjectId(12, 241):
		{
			double Formula = (double)(rand() % 100) / 100.0f;
			// ----
			double Value1 = Formula * 0.5f + 6.0f;
			double Value2 = Formula * 0.5f + 2.0f;
			// ----
			Vector(1.f, 0.f, 0.f, Light2);
			// ----
			b->TransformPosition(BoneTransform[1], p, Position, true);
			CreateSprite(32002, Position, Value1, Light2, o, 1.0f);
			// ----
			b->TransformPosition(BoneTransform[2], p, Position, true);
			CreateSprite(32002, Position, Value2, Light2, o, 1.0f);
			// ----
			b->TransformPosition(BoneTransform[3], p, Position, true);
			CreateSprite(32002, Position, Value2, Light2, o, 1.0f);
			// ----
			b->TransformPosition(BoneTransform[4], p, Position, true);
			CreateSprite(32002, Position, Value2, Light2, o, 1.0f);
			// ----
			b->TransformPosition(BoneTransform[5], p, Position, true);
			CreateSprite(32002, Position, Value2, Light2, o, 1.0f);
			// ----
			for (int i = 9; i <= 11; i++)
			{
				Vector(0.67f, 0.4346f, 0.1922f, Light2);
				b->TransformPosition(BoneTransform[i], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			}
			// ----
			for (int j = 13; j <= 15; j++)
			{
				Vector(0.77f, 0.4346f, 0.1922f, Light2);
				b->TransformPosition(BoneTransform[j], p, Position, true);
				CreateEffect(388, Position, o->Angle, Light2, 1, o, -1, 0, 0.0f, 0, 0, -1);
			}
		}
		break;
		// Red Spirit Wings
		case ObjectId(12, 242):
		{
			float Formula = (double)(rand() % 100) / 100.0f;

			float Value1 = absf(sinf(WorldTime * 0.5f)) * 0.2f;
			float Value2 = Formula * 0.5f + 1.0f;

			if (rand() % 15 < 12)
			{
				Vector(1.f, 0.f, 0.f, Light2);
				b->TransformPosition(BoneTransform[20], p, Position, true);
				CreateSprite(32213, Position, Value1 + 1.0f, Light2, o);
			}

			Vector(0.99f, 0.1881f, 0.3351f, Light2);
			b->TransformPosition(BoneTransform[4], p, Position, true);
			CreateSprite(32115, Position, 3.5f, Light2, o, 0.40000001f);

			b->TransformPosition(BoneTransform[7], p, Position, true);
			CreateSprite(32115, Position, 3.5f, Light2, o, 0.40000001f);

			b->TransformPosition(BoneTransform[9], p, Position, true);
			CreateSprite(32115, Position, 2.5f, Light2, o, 0.40000001f);

			b->TransformPosition(BoneTransform[12], p, Position, true);
			CreateSprite(32115, Position, 2.5f, Light2, o, 0.40000001f);

			b->TransformPosition(BoneTransform[17], p, Position, true);
			CreateSprite(32115, Position, Value2, Light2, o, 1.0f);

			b->TransformPosition(BoneTransform[18], p, Position, true);
			CreateSprite(32115, Position, Value2, Light2, o, Value2);

			b->TransformPosition(BoneTransform[19], p, Position, true);
			CreateSprite(32115, Position, 2.5f, Light2, o, 0.5f);

			b->TransformPosition(BoneTransform[20], p, Position, true);
			CreateSprite(32115, Position, 2.5f, Light2, o, 0.5f);
		}
		break;
		// Thunder Wings
		case ObjectId(12, 243):
		{
			// ----
			Vector(0.7f, 0.4f, 1.f, Light2);
			// ----
			b->TransformPosition(BoneTransform[19], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3);
			b->TransformPosition(BoneTransform[20], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3);
			b->TransformPosition(BoneTransform[10], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3);
			// ----
			b->TransformPosition(BoneTransform[11], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3);
			b->TransformPosition(BoneTransform[4], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3);
			b->TransformPosition(BoneTransform[7], p, Position, true);
			CreateSprite(32002, Position, 0.8f, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3);
		}
		break;
		// Raven Wings
		case ObjectId(12, 244):
		{
			if (rand() % 15 <= 12)
			{
				Vector(0.576f, 0.9088f, 0.96f, Light2);
				b->TransformPosition(BoneTransform[19], p, Position, true);
				CreateSprite(32002, Position, 1.5f, Light2, o, 0.0f);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 0.8, 0);
				// ---
				b->TransformPosition(BoneTransform[20], p, Position, true);
				CreateSprite(32002, Position, 1.5f, Light2, o, 0.0f);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 0.8, 0);
			}
			// ---
			Vector(0.576f, 0.9088f, 0.96f, Light2);
			// ---
			b->TransformPosition(BoneTransform[3], p, Position, true);
			CreateSprite(32002, Position, 3.5f, Light2, o, 0.0f);
			CreateParticle(32269, Position, o->Angle, Light2, 3, 0.1f);
			// ---
			b->TransformPosition(BoneTransform[4], p, Position, true);
			CreateSprite(32002, Position, 1.0f, Light2, o, 0.0f);
			CreateParticle(32269, Position, o->Angle, Light2, 3, 0.1f);
			// ---
			b->TransformPosition(BoneTransform[6], p, Position, true);
			CreateSprite(32002, Position, 3.5f, Light2, o, 0.0f);
			CreateParticle(32269, Position, o->Angle, Light2, 3, 0.1f);
			// ---
			b->TransformPosition(BoneTransform[7], p, Position, true);
			CreateSprite(32002, Position, 1.0f, Light2, o, 0.0f);
			CreateParticle(32269, Position, o->Angle, Light2, 3, 0.1f);
			// ---
			b->TransformPosition(BoneTransform[9], p, Position, true);
			CreateSprite(32002, Position, 1.5f, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f);
			// ---
			b->TransformPosition(BoneTransform[12], p, Position, true);
			CreateSprite(32002, Position, 1.5f, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f);
		}
		break;
		// Eternal Wings
		case ObjectId(12, 245):
		{
			double Formula = (double)(rand() % 100) / 100.0f;
			double Value1 = Formula * 0.5f + 2.0f;
			// ----
			Vector(0.5763f, 0.455f, 0.91f, Light2);
			// ----
			b->TransformPosition(BoneTransform[3], p, Position, true);
			CreateSprite(32002, Position, Value1, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f);
			// ----
			b->TransformPosition(BoneTransform[6], p, Position, true);
			CreateSprite(32002, Position, Value1, Light2, o, 0.2f);
			CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f);
			// ----
			b->TransformPosition(BoneTransform[19], p, Position, true);
			CreateSprite(32003, Position, Value1, Light2, o, 0.2f);
			// ----
			b->TransformPosition(BoneTransform[20], p, Position, true);
			CreateSprite(32003, Position, Value1, Light2, o, 0.2f);
		}
		break;
		// Wings of Legend
		case ObjectId(12, 246):
		{
			int BoneID1[12] = { 6,7,9,12,13,14,22,23,25,28,29,30 };
			// --
			for (int i = 0; i < 12; i++)
			{
				Vector(0.92f, 0.2944f, 0.3361f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 2.5f, Light2, o, 0.5f);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
			}
		}
		break;
		// Flaming Wings
		case ObjectId(12, 247):
		{
			float Formula = (double)(rand() % 87) / 100.0f;

			float Value1 = absf(sinf(WorldTime * 0.5f)) * 0.2f;
			float Value2 = Formula * 0.5f + 1.0f;

			Vector(0.1f, 0.1f, 0.1f, Light2);
			b->TransformPosition(BoneTransform[3], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, Value2);

			b->TransformPosition(BoneTransform[4], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, Value2);

			b->TransformPosition(BoneTransform[6], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, Value2);

			b->TransformPosition(BoneTransform[7], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, Value2);

			b->TransformPosition(BoneTransform[9], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, Value1);

			b->TransformPosition(BoneTransform[10], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, Value1);

			b->TransformPosition(BoneTransform[11], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, Value1);

			b->TransformPosition(BoneTransform[12], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, Value1);

			b->TransformPosition(BoneTransform[19], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, 0.5f);

			b->TransformPosition(BoneTransform[20], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, 0.5f);
		}
		break;
		// Nightwish Wings
		case ObjectId(12, 248):
		{
			Vector(0.9654f, 0.85, 0.9996f, Light2);
			// ---
			b->TransformPosition(BoneTransform[9], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, 0.5f);
			// ---
			b->TransformPosition(BoneTransform[16], p, Position, true);
			CreateParticle(32348, Position, o->Angle, Light2, 0, 0.5f);
		}
		break;
		// Imperial Dragon Wings Updated:(25-07-16)
		case ObjectId(12, 249):
		{
			float Formula = (double)(rand() % 55) / 95.0f;
			// ----
			float Value1 = absf(sinf(WorldTime * 0.5f)) * 0.2f;
			float Value2 = Formula * 0.5f + 0.1f;
			// ----
			int BoneID1[8] = { 1,2,3,4,5,6,7,8 };
			// ----
			for (int i = 0; i < 8; i++)
			{
				Vector(0.73f, 0.4346f, 0.2022f, Light2);
				b->TransformPosition(BoneTransform[BoneID1[i]], p, Position, true);
				CreateSprite(32002, Position, 3.5f, Light2, o, Value1);
				CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
			}
			// ----
			int BoneID2[8] = { 1,2,3,4,5,6,7,8 };
			// ----
			for (int x = 0; x < 8; x++)
			{
				Vector(0.67f, 0.4346f, 0.1922f, Light2);
				b->TransformPosition(BoneTransform[BoneID2[x]], p, Position, true);
				CreateParticle(32348, Position, o->Angle, Light2, 2, Value2);
				CreateParticle(32269, Position, o->Angle, Light2, 3, 0.5f);
				CreateParticle(32033, Position, o->Angle, Light2, 11, 0.5f, 0);
			}
			// ----
			int BoneID3[2] = { 1,2 };
			// ----
			for (int y = 0; y < 2; y++)
			{
				Vector(0.1f, 0.1f, 0.1f, Light2);
				b->TransformPosition(BoneTransform[BoneID3[y]], p, Position, true);
				CreateParticle(32348, Position, o->Angle, Light2, 0, 0.8f);
			}
		}
		break;
		// Wings of Conqueror (Updated: 31-07-16)
		case ObjectId(12, 250):
		{
			Vector(0.9833f, 1.f, 0.f, Light2);
			b->TransformPosition(BoneTransform[8], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[12], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[16], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[17], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[21], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[22], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[23], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[24], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[31], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[35], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[39], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[40], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[44], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[45], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[46], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[47], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[52], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[53], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[54], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[55], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[59], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[60], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[61], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			b->TransformPosition(BoneTransform[62], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			float Value = (0.3f * ((float)rand() / RAND_MAX)) + 0.2f;

			for (int i = 1; i < b->NumBones; i++) //asdsad
			{
				b->TransformPosition(BoneTransform[i], Position, p, true);

				Vector(0.15f, 0.10f, 0.00f, Light2);
				CreateSprite(31108, p, Value, Light2, o, 0, 0);

				Vector(0.20f, 0.10f, 0.00f, Light2);

				CreateParticle(32269, p, o->Angle, Light2, 3, 0, 0);
			}

		}
		case ObjectId(8, 16):
		{


			// ----
			Vector(1.0f, 1.0f, 1.0f, Light2);

			b->TransformPosition(BoneTransform[3], Position, p, true); //bak
			CreateSprite(32002, p, 1.0f, Light2, o, 0, 0);

			Vector(0.9833f, 1.f, 0.f, Light2);
			b->TransformPosition(BoneTransform[4], Position, p, true);
			CreateSprite(32115, p, 0.5f, Light2, o, 0.01f, 0);

			float Value = (0.3f * ((float)rand() / RAND_MAX)) + 0.2f;

			for (int i = 1; i < b->NumBones; i++) //asdsad
			{
				b->TransformPosition(BoneTransform[i], Position, p, true);

				Vector(0.15f, 0.10f, 0.00f, Light2);
				CreateSprite(31108, p, Value, Light2, o, 0, 0);

				Vector(0.20f, 0.10f, 0.00f, Light2);

				CreateParticle(32269, p, o->Angle, Light2, 3, 0, 0);
			}

		}
		break;
		// Wings of Angel and Devil (Updated: 08-08-16)
		case ObjectId(12, 251):
		{
			float WorldTime = (float)(rand() % 100 + 1) / 100.0f;
			// ----
			float ft1 = WorldTime * 0.5f + 1.8f;
			float ft2 = WorldTime * 0.5f + 2.5f;
			// ----
			Vector(0.2f, 0.1f, 0.3f, Light2);
			b->TransformPosition(BoneTransform[44], Position, p, true);
			CreateEffect(300, p, o->Angle, Light2, 4, o, -1, 0, 0, 0, 0, -1);
			// ----
			b->TransformPosition(BoneTransform[62], Position, p, true);
			CreateEffect(300, p, o->Angle, Light2, 4, o, -1, 0, 0, 0, 0, -1);
			// ----
			int Bones1[10] = { 39,40,41,42,43,58,59,60,61,62 };
			// ----
			Vector(0.42f, 0.43f, 0.4f, Light2);
			// ----
			for (int x = 0; x < 10; x++)
			{
				b->TransformPosition(BoneTransform[Bones1[x]], Position, p, true);
				CreateSprite(32002, p, ft2, Light2, o, 0, 0);
			}
			// ----
			int Bones2[8] = { 32,44,45,46,51,63,64,65 };
			// ----
			Vector(0.41f, 0.25f, 0.45f, Light2);
			// ----
			for (int y = 0; y < 8; y++)
			{
				b->TransformPosition(BoneTransform[Bones2[y]], Position, p, true);
				CreateSprite(32002, p, ft2, Light2, o, 0, 0);
			}
		}
		break;
		// Wings of Deathless (Added: 22-12-16)
		case ObjectId(12, 252):
		{
			float WorldTime = (float)(rand() % 100 + 1) / 100.0f;
			// ----
			float VectorTick = WorldTime * 0.2f + 1.5f;
			// ----
			Vector(0.94f, 0.04f, 0.04f, Light2);
			// ----
			int BoneID1[15] = { 3,4,5,6,8,9,10,11,12,13,15,19,22,23,24 };
			// ----
			for (int i = 0; i < 15; i++)
			{
				b->TransformPosition(BoneTransform[BoneID1[i]], Position, p, true); //bak
				CreateSprite(32002, p, VectorTick, Light2, o, 0, 0);
			}
			// ----
			int BoneID2[16] = { 25,26,27,28,30,33,36,37,38,39,42,43,44,46,47,48 };
			// ----
			for (int x = 0; x < 16; x++)
			{
				b->TransformPosition(BoneTransform[BoneID2[x]], Position, p, true);
				CreateSprite(32002, p, VectorTick, Light2, o, 0, 0);
			}
		}
		break;
		}
	RenderPartObjectEffect(o, Type, Light, Alpha, ItemLevel, NewOption, SetOption, Select, RenderType);
}

void cEffect::InitRenderPartObjectEffectEx()
{
	gToolKit.SetOp((LPVOID)oRenderPartObjectEffect01, RenderPartObjectEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)oRenderPartObjectEffect02, RenderPartObjectEffectEx, ASM::CALL);
}

void cEffect::InitRenderPartItemEffectEx()
{
	gToolKit.SetOp((LPVOID)0x004F29DA, RenderPartItemEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004F2A90, RenderPartItemEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004F2BD5, RenderPartItemEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x004F6839, RenderPartItemEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x005056F6, RenderPartItemEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00505740, RenderPartItemEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00505847, RenderPartItemEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00505943, RenderPartItemEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00505981, RenderPartItemEffectEx, ASM::CALL);
	gToolKit.SetOp((LPVOID)0x00505A15, RenderPartItemEffectEx, ASM::CALL);
}

void cEffect::Load()
{
	this->InitRenderPartObjectEffectEx();
	//this->InitRenderPartItemEffectEx();
}