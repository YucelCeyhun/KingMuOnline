#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <Windows.h>
#include "zzzMathLib.h"

#pragma pack(push,1) 
struct MUItemInfo
{
	short		m_wItemType;
	int			m_level;
	char		gap_6[2];
	char		field_8;
	short		m_DamageMin;
	short		m_DamageMax;
	char		field_D;
	short		field_E;
	short		field_10;
	char		gap_12[1];
	char		field_13;
	short		field_14;
	char		m_nDur;
	char		m_exl;
	char		m_hion;
	short		m_reqStr;
	short		m_reqAgi;
	short		m_reqEne;
	short		m_reqVit;
	short		m_reqLead;
	short		m_reqLevel;
	char		m_SpeciaCount;
	WORD		m_SpecialType[8];
	BYTE		m_SpecialValue[8];
	int			m_nUniqueID;
	char		m_nCurrentActiveSlotInfex;
	char		m_nPosX;
	char		m_nPosY;
	WORD		m_JOHType;
	short		m_JOHValue;
	char		m_isItem380Opt;
	char		m_SocketOption[5];
	char		field_4F;
	char		m_SocketSeedIndex[5];
	char		m_SocketSphereLevel[5];
	char		m_SocketBound;
	DWORD		field_5B;
	char		gap_5F[1];
	char		m_DurabilityState;
	char		m_PeriodItem;
	char		m_ExpiredItem;
	int			m_ExpireDateConvert;
	int			m_nMaybeRefCount;
};
#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
	/*+0*/		BYTE Unknown0;
	/*+1*/		BYTE Unknown1;
	/*+2*/		BYTE Unknown2;
	/*+3*/		BYTE Unknown3;
	/*+4*/		BYTE Unknown4;
	/*+5*/		BYTE Unknown5;
	/*+6*/		BYTE Unknown6;
	/*+7*/		BYTE Unknown7;
	/*+8*/		BYTE Unknown8;
	/*+9*/		BYTE Unknown9;
	/*+10*/		BYTE Unknown10;
	/*+11*/		BYTE Unknown11;
	/*+12*/		BYTE Unknown12;
	/*+13*/		BYTE Unknown13;
	/*+14*/		BYTE Unknown14;
	/*+15*/		BYTE Unknown15;
	/*+16*/		BYTE Unknown16;
	/*+17*/		BYTE Unknown17;
	/*+18*/		BYTE Unknown18;
	/*+19*/		BYTE Unknown19;
	/*+20*/		BYTE Unknown20;
	/*+21*/		BYTE Unknown21;
	/*+22*/		BYTE Unknown22;
	/*+23*/		BYTE Unknown23;
	/*+24*/		BYTE Unknown24;
	/*+25*/		BYTE Unknown25;
	/*+26*/		BYTE Unknown26;
	/*+27*/		BYTE Unknown27;
	/*+28*/		BYTE Unknown28;
	/*+29*/		BYTE Unknown29;
	/*+30*/		BYTE Unknown30;
	/*+31*/		BYTE Unknown31;
	/*+32*/		BYTE Unknown32;
	/*+33*/		BYTE Unknown33;
	/*+34*/		BYTE Unknown34;
	/*+35*/		BYTE Unknown35;
	/*+36*/		BYTE Unknown36;
	/*+37*/		BYTE Unknown37;
	/*+38*/		BYTE Unknown38;
	/*+39*/		BYTE Unknown39;
	/*+40*/		BYTE Unknown40;
	/*+41*/		BYTE Unknown41;
	/*+42*/		BYTE Unknown42;
	/*+43*/		BYTE Unknown43;
	/*+44*/		BYTE Unknown44;
	/*+45*/		BYTE Unknown45;
	/*+46*/		BYTE Unknown46;
	/*+47*/		BYTE Unknown47;
	/*+48*/		DWORD ObjIndex;
	/*+49*/		BYTE Unknown49;
	/*+50*/		BYTE Unknown50;
	/*+51*/		BYTE Unknown51;
	/*+52*/		BYTE Unknown52;
	BYTE	Shift1[40];
	/*+96*/		float Size;
	BYTE	Shift2[152];
	/*252*/		float PositionX;
	/*256*/		float PositionY;
	/*260*/		float PositionZ;
	/*264*/		float AngleX;
	/*268*/		float AngleY;
	/*272*/		float AngleZ;
	BYTE	Shift3[198];
	/*+472*/	DWORD WorldPreview;
}gObjViewport, * lpObjViewport;
#pragma pack(pop)

struct CustomItem
{
	DWORD Type;
	DWORD Id;
	DWORD TitleColor;
};

#pragma pack(push,1)
typedef struct	//-> Complete (size: 96)
{
	/*+0*/		WORD	Index;
	/*+2*/		int		Level;
	/*+6*/		char	Unknown6;
	/*+7*/		char	Unknown7;
	/*+8*/		char	Unknown8;
	/*+9*/		short	DamageMin;
	/*+11*/		short	DamageMax;
	/*+13*/		char	Unknown13;
	/*+14*/		short	Unknown14;
	/*+16*/		short	Unknown16;
	/*+18*/		char	Unknown18;
	/*+19*/		char	Unknown19;
	/*+20*/		short	Unknown20;
	/*+22*/		char	Durability;
	/*+23*/		char	ExcellentOption;
	/*+24*/		char	AncientOption;
	/*+25*/		short	ReqStrenght;
	/*+27*/		short	ReqDextirity;
	/*+29*/		short	ReqEnergy;
	/*+31*/		short	ReqVitality;
	/*+33*/		short	ReqCommand;
	/*+35*/		short	ReqLevel;
	/*+37*/		char    SpecialCount;
	/*+38*/		WORD	SpecialType[8];
	/*+54*/		BYTE	SpecialValue[8];
	/*+62*/		int		UniqueID;
	/*+66*/		char	Unknown66;
	/*+67*/		char 	PosX;
	/*+68*/		char 	PosY;
	/*+69*/		WORD 	HarmonyType;
	/*+71*/		short	HarmonyValue;
	/*+73*/		char 	Is380Item;
	/*+74*/		char	SocketOption[5];
	/*+79*/		char	Unknown79;
	/*+80*/		char	SocketSeedIndex[5];
	/*+85*/		char	SocketSphereLevel[5];
	/*+90*/		char	SocketSet;
	BYTE gap01[5];
	/*+96*/		char	DurabilityState;
} ObjectItem, * lpItemObj;
#pragma pack(pop)

#pragma pack(push, 1)
struct VAngle
{
	float X;
	float Y;
	float Z;
};
#pragma pack(pop)

#pragma pack(push,1)
struct UnknownStruct0
{
	/*+0*/	WORD	Unknown0;//?
	/*+2*/	WORD	Unknown2;//?
	/*+4*/	WORD	Unknown4;//?
	/*+6*/	WORD	Unknown6;
	/*+8*/	WORD	Unknown8;
	/*+10*/	WORD	Unknown10;
	/*+12*/	WORD	Unknown12;//?
	/*+14*/	WORD	Unknown14;
	/*+16*/	WORD	Unknown16;
};
#pragma pack(pop)

#pragma pack(push,1)
typedef struct	//-> InDev (size: 6012)
{
	/*+0*/		char	Name[11];
	/*+11*/		char	Class;
	/*+12*/		BYTE	Unknown12;
	/*+13*/		BYTE	Unknown13;
	/*+14*/		short	Level;
	/*+16*/		DWORD	Experience;
	/*+20*/		DWORD	NextExperience;
	/*+24*/		WORD	Strength;
	/*+26*/		WORD	Dexterity;
	/*+28*/		WORD	Vitality;
	/*+30*/		WORD	Energy;
	/*+32*/		WORD	Leadership;
	/*+34*/		WORD	Life;
	/*+36*/		WORD	Mana;
	/*+38*/		WORD	MaxLife;
	/*+40*/		WORD	MaxMana;
	/*+42*/		WORD	Shield;
	/*+44*/		WORD	MaxShield;
	/*+46*/		WORD	AttackRate;
	/*+48*/		WORD	DefenseRate;
	/*+50*/		short	AddStrength;
	/*+52*/		short	AddDexterity;
	/*+54*/		short	AddVitality;
	/*+56*/		short	AddEnergy;
	BYTE gap01[4];
	/*+62*/		WORD	AddLeadership;	//GS use unsigned value...
	/*+64*/		WORD	Stamina;
	/*+66*/		WORD	MaxStamina;
	/*+68*/		BYTE	ItemSpecialUseFlag;		//Bit decomposit (1, 2, 8)
	BYTE UnknownGap;
	/*+70*/		WORD	ItemSpecialUseTime[3];	//[ ]
	/*+76*/		WORD	AddPoint;	//FruitStat start
	/*+78*/		WORD	MaxAddPoint;
	/*+80*/		WORD	MinusPoint;
	/*+82*/		WORD	MaxMinusPoint;	//FruitStat end
	/*+84*/		WORD	AttackSpeed;
	/*+86*/		WORD	DamageRate;
	/*+88*/		WORD	DamageMin;
	/*+90*/		WORD	DamageMax;
	/*+92*/		WORD	Unknown92;
	/*+94*/		WORD	Unknown94;
	/*+96*/		WORD	MagicSpeed;
	BYTE gap02[10];
	/*+108*/	WORD	Unknown108;
	/*+110*/	WORD	Unknown110;
	BYTE gap03[4];
	/*+116*/	WORD	LevelPoint;
	/*+118*/	BYTE	MagicCount;
	/*+119*/	BYTE	Unknown119;
	/*+120*/	WORD	pMagicList[650];	//maybe 150?
											/*1420*/
	BYTE gap04[3252];	//maybe preview struct some here
	/*+4672*/	ObjectItem pEquipment[12];
	/*+5956*/	DWORD	MoneyInventory;	//(C4)
	/*+5960*/	DWORD	MoneyWarehouse;	//(C4)
	BYTE gap05[8];
	/*+5972*/	UnknownStruct0 Unknown5972;
	BYTE gap06[2];
	/*+5992*/	WORD	Unknown5992;
	/*+5994*/	WORD	Unknown5994;
	BYTE gap07[2];
	/*+5998*/	WORD	Unknown5998;
	/*+6000*/	WORD	Unknown6000;
	/*+6002*/	WORD	Unknown6002;
	/*+6004*/	WORD	Unknown6004;
	/*+6006*/	WORD	Unknown6006;
	/*+6008*/	BYTE	Unknown6008;
	/*+6009*/	BYTE	Unknown6009;
	/*+6010*/	BYTE	Unknown6010;
	/*+6011*/	BYTE	Unknown6011;
} ObjectCharacter, * lpCharObj;
#pragma pack(pop)

/*struct TargetObj
{
	int Class;
	BOOL Live;
	int TickCount;
	float Life;
	float MaxLife;
	float LifePercent;
};*/

typedef struct
{
	int		Class;
	BOOL	Live;
	float	Life;
	float	MaxLife;
	float	LifePercent;
	int		Level;
} pTargetObj, * lpTargetObj;

typedef struct _OBJECT
{
	BYTE New_0[0xFC];

	vec3_t	 	  Position;
	vec3_t	 	  Angle;

} OBJECT;

#pragma pack(push,1)
struct OBJECTSTRUCT
{
	BYTE gap0[4];
	BYTE unk0x04;
	char gap_5[3];
	DWORD unk0x08;
	char gap_C[2];
	char IsSafeZone;
	char unk0xF;
	BYTE byte10;
	char unk0x11;
	char gap_12[1];
	BYTE Class;
	char unk0x14;
	char unk0x15;
	char unk0x16;
	char gap_17[1];
	char unk0x18;
	char unk0x19;
	char unk0x1A;
	char unk0x1B;
	char unk0x1C;
	char unk0x1D;
	char unk0x1E;
	BYTE objPkState;
	char unk0x20;
	char unk0x21;
	char gap_22[1];
	char unk0x23;
	char unk0x24;
	char gap_25[1];
	WORD unk0x26;
	char gap_28[1];
	char unk0x29;
	char unk0x2A;
	char gap_2B[1];
	char unk0x2C;
	char gobjX;
	char gobjY;
	char gap_2F[9];
	char Name[24];
	char unk0x50;
	char gap_51[1];
	char unk0x52;
	char gap_53[1];
	WORD unk0x54;
	WORD m_index;
	WORD unk0x58;
	WORD unk0x5A;
	WORD objID;
	char gap_5E[4];
	WORD objSpeed;
	char gap_64[4];
	DWORD unk0x68;
	DWORD unk0x6C;
	char gap_70[4];
	DWORD unk0x74;
	char gap_78[12];
	DWORD unk0x84;
	DWORD unk0x88;
	DWORD unk0x8C;
	char gap_90[4];
	DWORD unk0x94;
	char gap_98[12];
	DWORD unk0xA4;
	char gap_A8[12];
	DWORD R;
	DWORD G;
	DWORD B;
	char gap_C0[32];
	WORD objHelm;
	BYTE objHelmLvl;
	BYTE gapE3[29];
	WORD objArmor;
	BYTE objArmorLvl;
	BYTE gap103[29];
	WORD objPants;
	BYTE objPantsLvl;
	BYTE gap123[29];
	WORD objGloves;
	BYTE objGlovesLvl;
	BYTE gap143[29];
	WORD objBoots;
	BYTE objBootsLvl;
	BYTE gap163[29];
	WORD WeaponRight;
	BYTE WeaponRightLvl;
	BYTE WeaponRightOpt;
	char gap_184[1];
	char unk0x185;
	char gap_186[26];
	WORD WeaponLeft;
	BYTE WeaponLeftLvl;
	char gap_1A3[2];
	char unk0x1A5;
	char gap_1A6[26];
	WORD objWings;
	char gap_1C2[30];
	WORD objPet;
	char gap_1E2[30];
	WORD unk0x200;
	char gap_202[30];
	BYTE unk0x220;
	char gap_221[1];
	char unk0x222;
	char gap_223[41];
	DWORD unk0x24C;
	DWORD unk0x250;
	char gap_254[12];
	WORD unk0x260;
	char unk0x262;
	char gap_263[1];
	DWORD unk0x264;
	BYTE Visible;
	BYTE gap269[2];
	BYTE unk0x26B;
	BYTE ShadowEnable;
	BYTE unk0x26D;
	char unk0x26E;
	char gap_26F[1];
	BYTE unk0x270;
	char unk0x271;
	char unk0x272;
	char unk0x273;
	char gap_274[1];
	char unk0x275;
	char CurrentAnimation;
	char unk0x277;
	BYTE unk0x278;
	char unk0x279;
	BYTE TypePlayer;
	char gap_27B[4];
	char unk0x27F;
	char gap_280[2];
	char unk0x282;
	char unk0x283;
	char gap_284[16];
	DWORD TypeObj;
	DWORD unk0x298;
	DWORD dword29C;
	DWORD unk0x2A0;
	DWORD dword2A4;
	DWORD unk0x2A8;
	char gap_2AC[12];
	DWORD unk2B8;
	char gap_2BC[8];
	float SizeObj;
	float unk0x2C8;
	float unk0x2CC;
	float unk0x2D0;
	float unk0x2D4;
	float unk0x2D8;
	DWORD unk0x2DC;
	float unk0x2E0;
	DWORD unk0x2E4;
	char gap_2E8[8];
	float unk0x2F0;
	float unk0x2F4;
	float Opacity2;
	float Opacity;
	DWORD unk0x300;
	DWORD unk0x304;
	DWORD unk0x308;
	char gap_30C[36];
	float unk0x330;
	float unk0x334;
	float unk0x338;
	float dword33C;
	float dword340;
	float dword344;
	char gap_348[24];
	float PositionX;
	float PositionY;
	float PositionZ;
	float RotateX;
	float RotateY;
	float RotateZ;
	char gap_378[144];
	DWORD unk0x408;
	char gap_40C[60];
	char unk0x448;
	char gap_449[23];
	DWORD dword460;
};
#pragma pack(pop)

#pragma pack(push,1)
typedef struct  //-> Complete (size: 27)
{
	WORD	ObjectID;
	char	Name[25];
} NpcNameList, * lpNpcNameList;
#pragma pack(pop)

struct Preview
{
	BYTE	Shift1[14];

	/*4*/	//BYTE	Unknown4;	// -> 100%
	/*8*/	//DWORD	Unknown8;	// -> 100%
	/*14*/	BYTE	IsSafeZone;
	/*15*/	BYTE	Visible;
	/*16*/	BYTE	Unknown16;
	/*17*/	BYTE	IsLiveObject;
	/*18*/	BYTE	Unknown18;
	/*19*/	BYTE	Class;
	/*20*/	BYTE	Unknown20;
	/*21*/	BYTE	CtrlCode;
	/*22*/	BYTE	AncientEffect;
	/*23*/	BYTE	PetStatus;
	/*24*/	BYTE	Unknown24;
	/*25*/	BYTE	Unknown25;
	/*26*/	BYTE	Unknown26;
	/*27*/	BYTE	Unknown27;
	/*28*/	BYTE	Unknown28;
	/*29*/	BYTE	Unknown29;
	/*30*/	BYTE	Unknown30;
	/*31*/	BYTE	Unknown31;
	/*32*/	BYTE	PKLevel;
	/*33*/	BYTE	Unknown33;
	/*34*/	BYTE	Unknown34;
	/*35*/	BYTE	Unknown35;
	/*36*/	BYTE	Unknown36;
	/*37*/	BYTE	Unknown37;
	/*38*/	WORD	Unknown38;
	/*40*/	BYTE	Unknown40;
	/*41*/	BYTE	Unknown41;
	/*42*/	BYTE	Unknown42;
	/*43*/	BYTE	Unknown43;
	/*44*/	BYTE	Unknown44;
	/*45*/	BYTE	RespawnPosX;
	/*46*/	BYTE	RespawnPosY;
	BYTE	Shift47[9];
	/*56*/	char	Name[32];	//-> 32 new 25: Need check size
	//BYTE	Shift2a[15];
	/*50*/	//BYTE	Unknown50;	// -> 100%
	/*88*/	//BYTE	Unknown88;	// -> 100%
	/*90*/	//BYTE	Unknown90;	// -> 100%
	/*91*/	//BYTE	Unknown91;	// -> 100%
	/*92*/	//WORD	InGuild;	// -> 100%
	/*94*/	//WORD	ObjIndex;	// -> 100%
	/*96*/	//WORD	Unknown96;	// -> 100%
	/*98*/	//WORD	Unknown98;	// -> 100%
	/*100*/	//WORD	ID;			// -> 100%
	/*106*/	//WORD	Unknown106;	// -> 100%
	/*112*/	//DWORD	Unknown112;	// -> 100%
	/*116*/	//DWORD	Unknown116;	// -> 100%
	/*124*/	//DWORD	Unknown124;	// -> 100%
	/*140*/	//DWORD MapPosX;	// -> 100%
	/*144*/	//DWORD MapPosY;	// -> 100%
	/*156*/	//DWORD	Unknown156;	// -> 100%
	/*172*/	//DWORD	Unknown172;	// -> 100%
	/*188*/	//DWORD	Unknown188;	// -> 100%
	/*192*/	//DWORD	Unknown192;	// -> 100%
	/*196*/	//DWORD	Unknown196;	// -> 100%

	BYTE	Shift2[143]; // New: 143 Ori: 150

	/*232*/	WORD	HelmSlot;
	/*234*/	BYTE	HelmLevel;
	/*235*/	BYTE	HelmExcellent;
	/*236*/	BYTE	HelmAncient;
	BYTE	Shift5[27];
	/*264*/	WORD	ArmorSlot;
	/*266*/	BYTE	ArmorLevel;
	/*267*/	BYTE	ArmorExcellent;
	/*268*/	BYTE	ArmorAncient;
	BYTE	Shift6[27];
	/*296*/	WORD	PantsSlot;
	/*298*/	BYTE	PantsLevel;
	/*299*/	BYTE	PantsExcellent;
	/*300*/	BYTE	PantsAncient;
	BYTE	Shift7[27];
	/*328*/	WORD	GlovesSlot;
	/*330*/	BYTE	GlovesLevel;
	/*331*/	BYTE	GlovesExcellent;
	/*332*/	BYTE	GlovesAncient;
	BYTE	Shift8[27];
	/*360*/	WORD	BootsSlot;
	/*362*/	BYTE	BootsLevel;
	/*363*/	BYTE	BootsExcellent;
	/*364*/	BYTE	BootsAncient;
	BYTE	Shift9[27];
	/*392*/	WORD	WeaponFirstSlot;
	/*394*/	BYTE	WeaponFirstLevel;
	/*395*/	BYTE	WeaponFirstExcellent;
	/*396*/	BYTE	WeaponFirstAncient;
	/*397*/	BYTE	Unknown397;
	BYTE	Shift10[26];
	/*424*/	WORD	WeaponSecondSlot;
	/*426*/	BYTE	WeaponSecondLevel;
	/*427*/	BYTE	WeaponSecondExcellent;
	/*428*/	BYTE	WeaponSecondAncient;
	/*429*/	BYTE	Unknown429;
	BYTE	Shift11[26];
	/*456*/	WORD	WingsSlot;
	/*458*/ BYTE	Unknown458;
	/*459*/ BYTE	Unknown459;
	/*460*/ BYTE	Unknown460;
	BYTE	Shift12[27];
	/*488*/	WORD	PetSlot;
	/*490*/ BYTE	Unknown490;
	/*491*/ BYTE	FenrirCharSet;
	/*492*/ BYTE	ExpectPet;

	/*520*/	//WORD	Unknown520;	// -> 100%
	/*596*/	//DWORD	Unknown596;	// -> 100%
	/*688*/	//DWORD	Unknown688;	//
	BYTE	Shift13[207];

	/*700*/	DWORD	Unknown700;	// -> # Need check
	/*704*/	BYTE	Unknown704;

	BYTE	Shift14[2];

	/*707*/	BYTE	Unknown707;
	/*708*/	BYTE	Unknown708;
	/*709*/	BYTE	Unknown709;
	/*710*/	BYTE	Unknown710;	// -> 100%
	/*711*/	BYTE	Unknown711;
	/*712*/	BYTE	Unknown712;
	BYTE	Shift16[5];
	/*718*/	BYTE	Action;
	/*719*/	BYTE	Unknown719;
	/*720*/	BYTE	Unknown720; //-> 100%
	/*721*/	BYTE	Unknown721;	//-> 100%
	/*722*/ BYTE	ObjectType; //-> Object Type (1 = Player, 2 = Monster, 4 = NPC) 100%
	BYTE	Shift17[25];
	/*748*/	DWORD	Unknown748;
	/*752*/	DWORD	Unknown752;
	/*756*/	DWORD	Unknown756;
	/*760*/	DWORD	Unknown760;

	/*768*/	//DWORD	Unknown768;	// -> 100%

	BYTE	Shift18[32];
	/*796*/	DWORD	ModelScale; // -> This is: float to MONSTERS Size
	BYTE	Shift19[16];

	/*800*/	//DWORD	Unknown800;	// -> 100%

	/*816*/	DWORD	Unknown816;

	/*824*/	//DWORD	Unknown824;	// -> 100%

	BYTE	Shift20[103];

	/*856*/	//DWORD	Unknown856;	// -> 100%
	/*860*/	//DWORD	Unknown860;	// -> 100%
	/*864*/	//DWORD	Unknown864;	// -> 100%
	/*972*/	//DWORD	Unknown972;	// -> 100%
	/*904*/	//DWORD	Unknown904;	// -> 100%
	/*908*/	//DWORD	Unknown908;	// -> 100%
	/*912*/	//DWORD	Unknown912;	// -> 100%
	/*916*/	//DWORD	Unknown916;	// -> 100% / Maybe float
	/*920*/	//DWORD	Unknown920;	// -> 100% / Maybe float

	/*924*/	float	SelectZone;	// -> Maybe DWORD
	BYTE	Shift21[24];

	/*952*/	float	SwitchCharPosX;	// -> 100%
	/*956*/	float	SwitchCharPosY;	// -> 100%
	/*960*/ float	SwitchCharPosZ;	// -> 100%

	/*964*/	//DWORD	Unknown964;	// -> 100%
	/*968*/	//DWORD	Unknown968;	// -> 100%
	/*972*/	//DWORD	Unknown972;	// -> 100%
	/*1120*/	//DWORD	Unknown1120;	// -> 100%
	/*1184*/	//void?
};

//#pragma pack(push,1)
typedef struct	//-> InDev (size: 1184)
{
	BYTE	Shift1[14];

	/*4*/	//BYTE	Unknown4;	// -> 100%
	/*8*/	//DWORD	Unknown8;	// -> 100%
	/*14*/	BYTE	IsSafeZone;
	/*15*/	BYTE	Visible;
	/*16*/	BYTE	Unknown16;
	/*17*/	BYTE	IsLiveObject;
	/*18*/	BYTE	Unknown18;
	/*19*/	BYTE	Class;
	/*20*/	BYTE	Unknown20;
	/*21*/	BYTE	CtrlCode;
	/*22*/	BYTE	AncientEffect;
	/*23*/	BYTE	PetStatus;
	/*24*/	BYTE	Unknown24;
	/*25*/	BYTE	Unknown25;
	/*26*/	BYTE	Unknown26;
	/*27*/	BYTE	Unknown27;
	/*28*/	BYTE	Unknown28;
	/*29*/	BYTE	Unknown29;
	/*30*/	BYTE	Unknown30;
	/*31*/	BYTE	Unknown31;
	/*32*/	BYTE	PKLevel;
	/*33*/	BYTE	Unknown33;
	/*34*/	BYTE	Unknown34;
	/*35*/	BYTE	Unknown35;
	/*36*/	BYTE	Unknown36;
	/*37*/	BYTE	Unknown37;
	/*38*/	WORD	Unknown38;
	/*40*/	BYTE	Unknown40;
	/*41*/	BYTE	Unknown41;
	/*42*/	BYTE	Unknown42;
	/*43*/	BYTE	Unknown43;
	/*44*/	BYTE	Unknown44;
	/*45*/	BYTE	RespawnPosX;
	/*46*/	BYTE	RespawnPosY;
	BYTE	Shift47[9];
	/*56*/	char	Name[25];	//-> Need check size
	//BYTE	Shift2a[15];
	/*50*/	//BYTE	Unknown50;	// -> 100%
	/*88*/	//BYTE	Unknown88;	// -> 100%
	/*90*/	//BYTE	Unknown90;	// -> 100%
	/*91*/	//BYTE	Unknown91;	// -> 100%
	/*92*/	//WORD	InGuild;	// -> 100%
	/*94*/	//WORD	ObjIndex;	// -> 100%
	/*96*/	//WORD	Unknown96;	// -> 100%
	/*98*/	//WORD	Unknown98;	// -> 100%
	/*100*/	//WORD	ID;			// -> 100%
	/*106*/	//WORD	Unknown106;	// -> 100%
	/*112*/	//DWORD	Unknown112;	// -> 100%
	/*116*/	//DWORD	Unknown116;	// -> 100%
	/*124*/	//DWORD	Unknown124;	// -> 100%
	/*140*/	//DWORD MapPosX;	// -> 100%
	/*144*/	//DWORD MapPosY;	// -> 100%
	/*156*/	//DWORD	Unknown156;	// -> 100%
	/*172*/	//DWORD	Unknown172;	// -> 100%
	/*188*/	//DWORD	Unknown188;	// -> 100%
	/*192*/	//DWORD	Unknown192;	// -> 100%
	/*196*/	//DWORD	Unknown196;	// -> 100%

	BYTE	Shift2[150]; // 150

	/*232*/	WORD	HelmSlot;
	/*234*/	BYTE	HelmLevel;
	/*235*/	BYTE	HelmExcellent;
	/*236*/	BYTE	HelmAncient;
	BYTE	Shift5[27];
	/*264*/	WORD	ArmorSlot;
	/*266*/	BYTE	ArmorLevel;
	/*267*/	BYTE	ArmorExcellent;
	/*268*/	BYTE	ArmorAncient;
	BYTE	Shift6[27];
	/*296*/	WORD	PantsSlot;
	/*298*/	BYTE	PantsLevel;
	/*299*/	BYTE	PantsExcellent;
	/*300*/	BYTE	PantsAncient;
	BYTE	Shift7[27];
	/*328*/	WORD	GlovesSlot;
	/*330*/	BYTE	GlovesLevel;
	/*331*/	BYTE	GlovesExcellent;
	/*332*/	BYTE	GlovesAncient;
	BYTE	Shift8[27];
	/*360*/	WORD	BootsSlot;
	/*362*/	BYTE	BootsLevel;
	/*363*/	BYTE	BootsExcellent;
	/*364*/	BYTE	BootsAncient;
	BYTE	Shift9[27];
	/*392*/	WORD	WeaponFirstSlot;
	/*394*/	BYTE	WeaponFirstLevel;
	/*395*/	BYTE	WeaponFirstExcellent;
	/*396*/	BYTE	WeaponFirstAncient;
	/*397*/	BYTE	Unknown397;
	BYTE	Shift10[26];
	/*424*/	WORD	WeaponSecondSlot;
	/*426*/	BYTE	WeaponSecondLevel;
	/*427*/	BYTE	WeaponSecondExcellent;
	/*428*/	BYTE	WeaponSecondAncient;
	/*429*/	BYTE	Unknown429;
	BYTE	Shift11[26];
	/*456*/	WORD	WingsSlot;
	/*458*/ BYTE	Unknown458;
	/*459*/ BYTE	Unknown459;
	/*460*/ BYTE	Unknown460;
	BYTE	Shift12[27];
	/*488*/	WORD	PetSlot;
	/*490*/ BYTE	Unknown490;
	/*491*/ BYTE	FenrirCharSet;
	/*492*/ BYTE	ExpectPet;

	/*520*/	//WORD	Unknown520;	// -> 100%
	/*596*/	//DWORD	Unknown596;	// -> 100%
	/*688*/	//DWORD	Unknown688;	//
	BYTE	Shift13[207];

	/*700*/	DWORD	Unknown700;	// -> # Need check
	/*704*/	BYTE	Unknown704;

	BYTE	Shift14[2];

	/*707*/	BYTE	Unknown707;
	/*708*/	BYTE	Unknown708;
	/*709*/	BYTE	Unknown709;
	/*710*/	BYTE	Unknown710;	// -> 100%
	/*711*/	BYTE	Unknown711;
	/*712*/	BYTE	Unknown712;
	BYTE	Shift16[5];
	/*718*/	BYTE	Action;
	/*719*/	BYTE	Unknown719;
	/*720*/	BYTE	Unknown720; //-> 100%
	/*721*/	BYTE	Unknown721;	//-> 100%
	/*722*/ BYTE	ObjectType; //-> Object Type (1 = Player, 2 = Monster, 4 = NPC) 100%
	BYTE	Shift17[25];
	/*748*/	DWORD	Unknown748;
	/*752*/	DWORD	Unknown752;
	/*756*/	DWORD	Unknown756;
	/*760*/	DWORD	Unknown760;

	/*768*/	//DWORD	Unknown768;	// -> 100%

	BYTE	Shift18[32];
	/*796*/	DWORD	ModelScale; // -> This is: float to MONSTERS Size
	BYTE	Shift19[16];

	/*800*/	//DWORD	Unknown800;	// -> 100%

	/*816*/	DWORD	Unknown816;

	/*824*/	//DWORD	Unknown824;	// -> 100%

	BYTE	Shift20[103];

	/*856*/	//DWORD	Unknown856;	// -> 100%
	/*860*/	//DWORD	Unknown860;	// -> 100%
	/*864*/	//DWORD	Unknown864;	// -> 100%
	/*972*/	//DWORD	Unknown972;	// -> 100%
	/*904*/	//DWORD	Unknown904;	// -> 100%
	/*908*/	//DWORD	Unknown908;	// -> 100%
	/*912*/	//DWORD	Unknown912;	// -> 100%
	/*916*/	//DWORD	Unknown916;	// -> 100% / Maybe float
	/*920*/	//DWORD	Unknown920;	// -> 100% / Maybe float

	/*924*/	float	SelectZone;	// -> Maybe DWORD
	BYTE	Shift21[32];

	/*952*/	//float	Unknown952;	// -> 100%
	/*956*/	//float	Unknown956;	// -> 100%

	/*960*/ float	Unknown960;

	/*964*/	//DWORD	Unknown964;	// -> 100%
	/*968*/	//DWORD	Unknown968;	// -> 100%
	/*972*/	//DWORD	Unknown972;	// -> 100%
	/*1120*/	//DWORD	Unknown1120;	// -> 100%
	/*1184*/	//void?
} ObjectPreview, * lpViewObj;
//#pragma pack(pop)

typedef struct
{
	BYTE	Shift1[14];

	/*4*/	//BYTE	Unknown4;	// -> 100%
	/*8*/	//DWORD	Unknown8;	// -> 100%

	/*14*/	BYTE	IsSafeZone;
	/*15*/	BYTE	Visible;
	/*16*/	BYTE	Unknown16;
	/*17*/	BYTE	IsLiveObject;
	/*18*/	BYTE	Unknown18;
	/*19*/	BYTE	Class;
	/*20*/	BYTE	Unknown20;
	/*21*/	BYTE	CtrlCode;
	/*22*/	BYTE	AncientEffect;
	/*23*/	BYTE	PetStatus;
	/*24*/	BYTE	Unknown24;
	/*25*/	BYTE	Unknown25;
	/*26*/	BYTE	Unknown26;
	/*27*/	BYTE	Unknown27;
	/*28*/	BYTE	Unknown28;
	/*29*/	BYTE	Unknown29;
	/*30*/	BYTE	Unknown30;
	/*31*/	BYTE	Unknown31;
	/*32*/	BYTE	PKLevel;
	/*33*/	BYTE	Unknown33;
	/*34*/	BYTE	Unknown34;
	/*35*/	BYTE	Unknown35;
	/*36*/	BYTE	Unknown36;
	/*37*/	BYTE	Unknown37;
	/*38*/	WORD	Unknown38;
	/*40*/	BYTE	Unknown40;
	/*41*/	BYTE	Unknown41;
	/*42*/	BYTE	Unknown42;
	/*43*/	BYTE	Unknown43;
	/*44*/	BYTE	Unknown44;
	/*45*/	BYTE	MapPosX;
	/*46*/	BYTE	MapPosY;

	BYTE	Shift47[9];

	/*56*/	char	Name[25];

	BYTE	Shift47a[10];

	/*92*/	WORD	InGuild;
	/*93*/	BYTE	Unknown93;
	/*94*/	WORD	ObjIndex;
	/*95*/	BYTE	Unknown95;
	/*96*/	WORD	Unknown96;
	/*97*/	BYTE	Unknown97;
	/*98*/	WORD	Unknown98;
	/*100*/	WORD	Unknown100;

	BYTE	Shift47b[38];

	/*140*/	DWORD	MapCoordX;
	/*144*/	DWORD	MapCoordY;

	BYTE	Shift2[75];

	/*232*/	WORD	HelmSlot;
	/*234*/	BYTE	HelmLevel;
	/*235*/	BYTE	HelmExcellent;
	/*236*/	BYTE	HelmAncient;
	BYTE	Shift5[27];
	/*264*/	WORD	ArmorSlot;
	/*266*/	BYTE	ArmorLevel;
	/*267*/	BYTE	ArmorExcellent;
	/*268*/	BYTE	ArmorAncient;
	BYTE	Shift6[27];
	/*296*/	WORD	PantsSlot;
	/*298*/	BYTE	PantsLevel;
	/*299*/	BYTE	PantsExcellent;
	/*300*/	BYTE	PantsAncient;
	BYTE	Shift7[27];
	/*328*/	WORD	GlovesSlot;
	/*330*/	BYTE	GlovesLevel;
	/*331*/	BYTE	GlovesExcellent;
	/*332*/	BYTE	GlovesAncient;
	BYTE	Shift8[27];
	/*360*/	WORD	BootsSlot;
	/*362*/	BYTE	BootsLevel;
	/*363*/	BYTE	BootsExcellent;
	/*364*/	BYTE	BootsAncient;
	BYTE	Shift9[27];
	/*392*/	WORD	WeaponFirstSlot;
	/*394*/	BYTE	WeaponFirstLevel;
	/*395*/	BYTE	WeaponFirstExcellent;
	/*396*/	BYTE	WeaponFirstAncient;
	/*397*/	BYTE	Unknown397;
	BYTE	Shift10[26];
	/*424*/	WORD	WeaponSecondSlot;
	/*426*/	BYTE	WeaponSecondLevel;
	/*427*/	BYTE	WeaponSecondExcellent;
	/*428*/	BYTE	WeaponSecondAncient;
	/*429*/	BYTE	Unknown429;
	BYTE	Shift11[26];
	/*456*/	WORD	WingsSlot;
	/*458*/ BYTE	Unknown458;
	/*459*/ BYTE	Unknown459;
	/*460*/ BYTE	Unknown460;
	BYTE	Shift12[27];
	/*488*/	WORD	PetSlot;
	/*490*/ BYTE	Unknown490;
	/*491*/ BYTE	FenrirCharSet;
	/*492*/ BYTE	ExpectPet;

	/*520*/	//WORD	Unknown520;	// -> 100%
	/*596*/	//DWORD	Unknown596;	// -> 100%
	/*688*/	//DWORD	Unknown688;	//
	BYTE	Shift13[207];

	/*700*/	DWORD	Unknown700;	// -> # Need check
	/*704*/	BYTE	Unknown704;

	BYTE	Shift14[2];

	/*707*/	BYTE	Unknown707;
	/*708*/	BYTE	Unknown708;
	/*709*/	BYTE	Unknown709;
	/*710*/	BYTE	Unknown710;	// -> 100%
	/*711*/	BYTE	Unknown711;
	/*712*/	BYTE	Unknown712;
	BYTE	Shift16[5];
	/*718*/	BYTE	Action;
	/*719*/	BYTE	Unknown719;
	/*720*/	BYTE	Unknown720; //-> 100%
	/*721*/	BYTE	Unknown721;	//-> 100%
	/*722*/ BYTE	ObjectType; //-> Object Type (1 = Player, 2 = Monster, 4 = NPC) 100%
	BYTE	Shift17[25];
	/*748*/	DWORD	Unknown748;
	/*752*/	DWORD	Unknown752;
	/*756*/	DWORD	Unknown756;
	/*760*/	DWORD	Unknown760;

	/*768*/	//DWORD	Unknown768;	// -> 100%

	BYTE	Shift18[32];
	/*796*/	DWORD	ModelScale;
	BYTE	Shift19[16];

	/*800*/	//DWORD	Unknown800;	// -> 100%

	/*816*/	DWORD	Unknown816;

	/*824*/	//DWORD	Unknown824;	// -> 100%

	BYTE	Shift20[103];

	/*856*/	//DWORD	Unknown856;	// -> 100%
	/*860*/	//DWORD	Unknown860;	// -> 100%
	/*864*/	//DWORD	Unknown864;	// -> 100%
	/*972*/	//DWORD	Unknown972;	// -> 100%
	/*904*/	//DWORD	Unknown904;	// -> 100%
	/*908*/	//DWORD	Unknown908;	// -> 100%
	/*912*/	//DWORD	Unknown912;	// -> 100%
	/*916*/	//DWORD	Unknown916;	// -> 100% / Maybe float
	/*920*/	//DWORD	Unknown920;	// -> 100% / Maybe float

	/*924*/	float	SelectZone;	// -> Maybe DWORD
	BYTE	Shift21[32];

	/*952*/	//float	Unknown952;	// -> 100%
	/*956*/	//float	Unknown956;	// -> 100%

	/*960*/ float	Unknown960;

	/*964*/	//DWORD	Unknown964;	// -> 100%
	/*968*/	//DWORD	Unknown968;	// -> 100%
	/*972*/	//DWORD	Unknown972;	// -> 100%
	/*1120*/	//DWORD	Unknown1120;	// -> 100%
	/*1184*/	//void?
} MonsterPreview2, * lpViewMob2;

#pragma pack(push,1)
typedef struct
{
	BYTE Shift1[56];
	/*+56*/		char Name[25];
	BYTE Shift2[15];
	/*+96*/		WORD Unknown96;
	/*+97*/		BYTE Unknown97;
	/*+98*/		BYTE Unknown98;
	/*+100*/	WORD Unknown100;
	BYTE Shift3[598];
	/*+700*/	DWORD MapViewport;
	BYTE Shift4[16];
	/*+720*/	BYTE Unknown720;
	/*+721*/	BYTE Unknown721;
	/*+722*/	BYTE ObjectType; //-> Object Type (1 = Player, 2 = Monster, 4 = NPC) 100%
	BYTE Shift5[73];
	/*+796*/	float ModelScale;
} MonsterPreview, * lpViewMob;
#pragma pack(pop)

#endif