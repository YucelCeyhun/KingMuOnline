#ifndef __ENUMS_H__
#define __ENUMS_H__

enum eItemByNames
{
	Demon_Pet = 7554,	// -> ObjectId(13,64)
	Fairy_Pet = 7555,	// -> ObjectId(13,65)
	// ----
	Phoenix_Book = 8212,	// -> ObjectId(14,210)
	Dragon_Book = 8213,	// -> ObjectId(14,211)
	Kundun_Book = 8214,	// -> ObjectId(14,212)
};

namespace ItemColor
{
	enum T
	{
		White = 0x00,
		Blue = 0x01,
		Red = 0x02,
		Gold = 0x03,
		Green = 0x04,
		WhiteRed = 0x05,
		Violet = 0x06,
		WhiteBlue = 0x07,
		WhiteBeige = 0x08,
		GreenBlue = 0x09,
		Gray = 0x0A,
		DarkViolet = 0x0B,
	};
};

enum eItemDropCl
{
	DropWhite = 0,
	DropBlue = 1,
	DropRed = 2,
	DropGold = 3,
	DropGreen = 4,
	DropPurple = 5,
	DropPink = 6,
	DropOrange = 7,
	DropLightBlue = 8,
	DropIceBlue = 9,
	DropDarkViolet = 10,
	DropLightGreen = 11,
	DropThunderBlue = 12,
};

enum ItemWeight
{
	Normal = 0x00,
	Bold = 0x01,
};

enum eMagicalSwords
{
	DarkReignBlade = 21,
	RuneSacredBlade = 29,
	BlastBreak = 33,
	DivineBlade = 36,
	DarknessBlade = 38,
};

enum eSkillsId
{
	Starfall = 46,
	IceArrow = 51,
	Penetration = 52,
};

enum eObjPlayer
{
	DrawSlotPos1 = 0,
	DrawSlotPos2 = 1,
	DrawSlotPos3 = 2,
	DrawSlotPos4 = 3,
	DrawSlotPos5 = 4,
	DrawSlotPos6 = 5,
};

enum eItemOption
{
	Damage = 80, //-> Additional Damage +<N>
	WizardryDamage = 81,
	CurseSpell = 82,
	Defense = 84, //-> Additional Defense +<N>
	Luck = 85, //-> Default: 0
	HPRecovery = 86,
	IncreaseDamage = 95, //-> Increase Damage +<N>%
	IncreaseSpeed = 98, //-> Increase Attacking(Wizardry)speed +<N>
	IgnorOpDefense = 103,
	ReturnAttack = 106, //-> Return's the enemy's attack power in <N>%
	CompleteLife = 107, //-> Complete recovery of life in <N>% rate
	CompleteMana = 108, //-> Complete recovery of Mana in <N>% rate
};

enum eObjState
{
	SelectServer = 2,
	SwitchCharacter = 4,
	GameProcess = 5,
};

enum eObjClass
{
	DarkWizard = 0,
	SoulMaster = 8,
	GrandMaster = 24,
	DarkKnight = 1,
	BladeKnight = 9,
	BladeMaster = 25,
	Elf = 2,
	MuseElf = 10,
	HightElf = 26,
	MagicGladiator = 3,
	DuelMaster = 19,
	DarkLord = 4,
	LordEmperor = 20,
	Summoner = 5,
	BloodySummoner = 13,
	DimensionMaster = 29,
};

enum eMapNumber
{
	Lorencia = 0,
	Dungeon = 1,
	Devias = 2,
	Noria = 3,
	LostTower = 4,
	Exile = 5,
	Stadium = 6,
	Atlans = 7,
	Tarkan = 8,
	DevilSquare = 9,
	DevilSquare6 = 32,
	Icarus = 10,
	BloodCastle1 = 11,
	BloodCastle2 = 12,
	BloodCastle3 = 13,
	BloodCastle4 = 14,
	BloodCastle5 = 15,
	BloodCastle6 = 16,
	BloodCastle7 = 17,
	ChaosCastle1 = 18,
	ChaosCastle2 = 19,
	ChaosCastle3 = 20,
	ChaosCastle4 = 21,
	ChaosCastle5 = 22,
	ChaosCastle6 = 23,
	Kalima1 = 24,
	Kalima2 = 25,
	Kalima3 = 26,
	Kalima4 = 27,
	Kalima5 = 28,
	Kalima6 = 29,
	Kalima7 = 36,
	Loren = 30,
	Trials = 31,
	Aida = 33,
	Crywolf = 34,
	Kanturu1 = 37,
	Kanturu3 = 38,
	Kanturu_Event = 39,
	Silent = 40,
	Barracks = 41,
	Refuge = 42,
	Illusion1 = 45,
	Illusion2 = 46,
	Illusion3 = 47,
	Illusion4 = 48,
	Illusion5 = 49,
	Illusion6 = 50,
	Elbeland = 51,
	BloodCastle8 = 52,
	ChaosCastle7 = 53,
	Calmness = 56,
	Raklion = 57,
	RaklionBoss = 58,
	SantaTown = 62,
	Vulcanus = 63,
	Collosseum = 64,
	Kalimdor = 65,
	Arkania = 66,
	Market = 67,
	Karutan = 68,
	Acheron = 69,
	ElbelandSelect = 77,
	ElbelandSwitch = 78,
};

enum ObjChar
{
	DarkWizardChar = 0,
	SoulMasterChar = 8,
	GrandMasterChar = 24,
	// ----
	DarkKnightChar = 1,
	BladeKnightChar = 9,
	BladeMasterChar = 25,
	// ----
	ElfChar = 2,
	MuseElfChar = 10,
	HightElfChar = 26,
	// ----
	MagicGladiatorChar = 3,
	DuelMasterChar = 19,
	// ----
	DarkLordChar = 4,
	LordEmperorChar = 20,
	// ----
	SummonerChar = 5,
	BloodySummonerChar = 13,
	DimensionMasterChar = 29,
};

enum eEffectState
{
	AtDarkHorse = 1,
	AtFenrir = 4,
	AtGameMaster = 5,
};

enum eMauntType
{
	DarkHorse = 226,
	Uniria = 233,
	Dinorant = 323,
	BlackFenrir = 384,
	RedFenrir = 385,
	BlueFenrir = 386,
	GoldenFenrir = 387,
	OrangeFenrir = 518,
};

enum ePetSystemType
{
	Angel = 7490,
	Satan = 7491,
	Panda = 7570,
	Skeleton = 7567,//(13,77)
	Unicorn = 7568,//(13,78)
	Sparky = 7569,//(13,79)
	Chinlon = 7571,//(13,81)
	Pegasus = 7599,
};

enum eNewMounts
{
	FangSable = 494,
	MisticTiger = 496,
	Item497 = 497,
	GiantLyon = 498,
	LycanPet = 507,
	Item508 = 508,
	Item514 = 514,
	Item515 = 515,
	DarkWolf = 516,
};

enum eBowShootEffects
{
	ArrowImpact = 365, // -> Starfall
	LaceArrow = 335, // -> Viper Bow
	Carrow = 324, // -> Saint Crossbow
	ArrowDouble = 294, // -> Some Crossbow (Blue)
	KCross = 321,
	ArrowWing = 274,
	Sketbows_Arrows = 298, // -> Stinger Bow
	//Mana_Rune		= 363, // -> Extrange Item Siege in the Head
	Seaman_FX = 333,
	Air_Force = 326,
	Arrow_Bomb = 273,
	Gamble_Arrow = 509,
	CW_Bow_Skill = 297,
	Arrow_Nature = 272,
	Arrow_Thunder = 268,
	Wave_Force = 380,
	Dark_LordSkill = 330,
	Inferno = 293,
	Blast = 292,
	Fire_Shoot = 284,
	Fire_Circle = 285,
	Twisting_Slash = 290,
	Twisting_Slash2 = 291,
	Stars_Shoot = 295,
	HDK_Arrow = 296,
	Death_Stab = 301,
	Shiny_Dark = 310,
	Penetration_Sk = 313,
	Black_Aura = 314,
	Ice_Storm = 315,
	White_Shield = 316,
	Crystal_Stones = 317,
	Arrow_Divine = 321,
	Combo = 325,
	Combo2 = 327,
	Force = 328,
	Fire_Burst = 329,
	Earth_Quake = 331,
	Earth_Quake2 = 332,
	FastBlue_Arrow = 333,
	Wind_Up_Skill = 344,
	Wind_Shoot = 345,
	Meteor_Rain = 346,
	Wind_Shoot2 = 347,
	Black_Crystal_R = 361,
	Fire_Castle_DW = 364,
	Fire_Castle_DK = 366,
	Erohim_Skill = 368,
	Erohim_Skill2 = 369,//Fire
	Erohim_Skill3 = 370,//Lights
	Blue_Shine_Head = 371,
	Dark_Hole_Tele = 373,
	Dark_Hole_Tele2 = 374,
	Dark_Hole_Tele3 = 375,

};

enum eObjectType	//-> Complete
{
	emPlayer = 1,
	emMonster = 2,
	emNPC = 4,
	emNone = 8,
};

enum eNPCNames
{
	Bolo = 505,
	Dina = 506,
};

enum eCustomWings
{
	MagicWings = 1,
	ChaosWings = 2,
	LifeWings = 3,
	DeathCape = 4,
	HeavenWings = 5,
	DemonicWings = 6,
	BlossomWings = 7,
	ThunderWings = 8,
	RavenWings = 9,
	EternalWings = 10,
	LegendWings = 11,
	FlamingWings = 12,
	NightwishWings = 13,
	ImperialWings = 14,
	ConquerorWings = 15,
	AngelAndDevil = 16,
	DeathlessWings = 17,
};

enum eCustomPets
{
	TigerPet = 1,
	SablePet = 2,
	WolfPet = 3,
};

enum ColorMacro
{
	eShinyGreen = Color4f(172, 255, 56, 255),
	eGold = Color4f(255, 189, 25, 255),
	eWhite = Color4f(255, 255, 255, 255),
	eWhite180 = Color4f(255, 255, 255, 180),
	eOrange = Color4f(255, 105, 25, 255),
	eGray100 = Color4f(50, 50, 50, 100),
	eGray150 = Color4f(50, 50, 50, 150),
	eBlowPink = Color4f(220, 20, 60, 255),
	eRed = Color4f(225, 0, 0, 255),
	eExcellent = Color4f(0, 225, 139, 255),
	eAncient = Color4f(1, 223, 119, 255),
	eSocket = Color4f(153, 102, 204, 255),
	eBlue = Color4f(36, 242, 252, 255),
	eLightBlue = Color4f(29, 232, 252, 255),
	eYellow = Color4f(255, 255, 0, 255),
	eBrown = Color4f(69, 39, 18, 255),
};

enum Obj

{
	GATE_KEEPER_TITUS = 0x1DF,
	BOLO_THE_MERCHANT = 0x258,
	KUNDUN = 0X113
};

enum ObjWindow		// -> Complete
{
	FriendList = 1,
	MoveList = 2,
	Party = 3,
	Quest = 4,
	Guild = 6,
	Trade = 7,
	Warehouse = 8,
	ChaosBox = 9,
	CommandWindow = 10,
	PetInfo = 11,
	Shop = 12,
	Inventory = 13,
	Store = 14,
	OtherStore = 15,
	Character = 16,
	ChatWindow = 33,
	FastMenu = 34,
	Options = 35,
	Help = 36,
	FastDial = 39,
	Mini_Map = 52,
	CashShop = 57,
	SkillTree = 58,
	NPC_Titus = 63,
};

enum ObjectID
{
	eSAMPLE_BUTTON = 1,
	eTIME,
	eGLOWTRON_CHECKED,
	eGLOWTRON_UNCHECKED,
	eHPMOB_CHECKED,
	eHPMOB_UNCHECKED,
	eCAMERA_MAIN,
	eCAMERA_BUTTON1,
	eCAMERA_BUTTON2,
	/*
	eANTIALISING_BOX,
	eANTIALISING_PLUS,
	eANTIALISING_MINUS,
	eANTIALISING_X2,
	eANTIALISING_X4,
	eANTIALISING_X6,
	eANTIALISING_X8,
	eCHANGEFPS_CHECKED,
	eCHANGEFPS_UNCHECKED,
	*/
	// ----
	eLAST_OBJECT_ID // DO NOT USE!
};

enum eSkyState
{
	SkyOff = 0,
	SkyOn = 1,
};

enum eFogState
{
	FogOff = 0,
	FogOn = 1,
};

enum eTimeState
{
	TimeOff = 0,
	TimeOn = 1,
};

enum eHealthBarState
{
	HealthBarOff = 0,
	HealthBarOn = 1,
};

enum eGlowTronState
{
	GlowTronOff = 0,
	GlowTronOn = 1,
};

enum eItemNumberStackCl
{
	eNormalNumber = 0,
	eBlueNumber = 1,
	eRedNumber = 2,
	eGoldenNumber = 3,
	eGreenNumber = 4,
	eLBlueNumber = 5,
	eLGreenNumber = 6,
	eOrangeNumber = 7,
	eBlueJewelNumb = 8,
	eLRedNumber = 9,
	ePinkNumber = 10,
	ePurpleNumber = 11,
};

#endif