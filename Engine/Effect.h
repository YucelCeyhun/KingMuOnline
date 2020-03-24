#ifndef __EFFECT_H__
#define __EFFECT_H__

typedef int(*pCreateSprite)(int Type, vec3_t Position, float Scale, vec3_t Light, OBJECT *Owner, float Rotation, int SubType);
int CreateSprite(int Type, vec3_t Position, float Scale, vec3_t Light, OBJECT *Owner, float Rotation = 0.f, int SubType = 0);

typedef void(*pCreateEffect)(int Type, vec3_t Position, vec3_t Angle, vec3_t Light, int SubType, OBJECT *Owner, short PKKey, BYTE Skill, float Scale, BYTE SkillSerial, vec3_t SkillAngle, BYTE SkillHotKey);
void CreateEffect(int Type, vec3_t Position, vec3_t Angle, vec3_t Light, int SubType = 0, OBJECT *Target = NULL, short PKKey = -1, BYTE Skill = 0, float Scale = 0.0f, BYTE SkillSerial = 0, vec3_t SkillAngle = NULL, BYTE SkillHotKey = -1);

typedef void(*pCreateSpark)(int Type, vec3_t Position, vec3_t RelativePosition, vec3_t Angle, int SubType, OBJECT *Owner, float Scale, short PKKey, USHORT Arg9, BYTE SkillSerial, int Arg11, int Arg12, USHORT Arg13);
void CreateSpark(int Type,vec3_t Position,vec3_t RelativePosition,vec3_t Angle,int SubType,OBJECT *Target = NULL, float Scale = 0.0f, short PKKey = -1, USHORT Arg9 = 0, BYTE SkillSerial = 0, int Arg11 = NULL, int Arg12 = NULL, USHORT Arg13 = -1);

typedef int(*pCreateParticle)(int Type, vec3_t Position, vec3_t Angle, vec3_t Light, int SubType, float Scale, OBJECT *Owner);
int CreateParticle(int Type, vec3_t Position, vec3_t Angle, vec3_t Light, int SubType = 0, float Scale = 1.f, OBJECT *Owner = NULL);

class cEffect
{
public:
	void Load();
	// ----
	void InitRenderPartObjectEffectEx();
	void InitRenderPartItemEffectEx();
};

extern cEffect gEffect;

#endif