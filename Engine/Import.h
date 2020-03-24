#ifndef __IMPORT_H__
#define __IMPORT_H__

// -> Set PC Point Inventory Message Colors
#define oPCPointMessageByteB			0x00756D23
#define oPCPointMessageByteG			0x00756D28
#define oPCPointMessageByteR			0x00756D2D

// -> Set Main Attribute (NPC)
#define oSetMainAttr_Hook				0x004FF0E2
#define oSetMainAttr_Allowed			0x004FF0F4
#define oSetMainAttr_Return				0x004FF0EB

// -> Rudolf Search Zen
#define oRudolfSearchZen_Hook			0x008125E5
#define oRudolfSearchZen_Allowed		0x00812601
#define oRudolfSearchZen_Return			0x008125FC

// -> Main Connection
#define oIPConnection					0x008C2FC4
#define oSEConnection					0x008D7D34
#define oVEConnection					0x008D7D2C

// -> Draw Object Movement
#define oDrawObjectMovement01_Call		0x0046BFBC
#define oDrawObjectMovement02_Call		0x004AE0D2

#define pDrawObjectMovement				((char(__cdecl*)(lpObjViewport lpObj,int Arg2))0x004AC355)
#define pObjUpdateRectMovement			((double(__cdecl*)(float PosX,float PosY,float MapTilePosX,float MapTilePosY))0x4C8000)
#define pObjUpdateRectMovement2			((double(__cdecl*)(float Arg1,float Arg2,float Arg3))0x4C824B)

// -> Draw Angel Movement
#define oDrawAngelMovement_Hook			0x004ADD8C
#define oDrawAngelMovement_Allowed		0x004ADDA8
#define oDrawAngelMovement_Return		0x004ADD98

// -> Draw Object
#define oDrawObjectCall01				0x005C1D91
#define oDrawObjectCall02				0x005C1FE2
#define pObjOnViewport					((int(__cdecl*)(lpObjViewport lpObjView))0x5C0467)

// -> Launcher
#define oLauncherName					0x008D668C

// -> Fix CharacterEx (Select Character)
#define oFixCharacterEx_Width			0x004028BC
#define oFixCharacterEx_Height			0x004028BA
#define oFixCharacterEx_PosX			0x004028A4
#define oFixCharacterEx_PosY			0x0040289F			// Not used

// -> Speed Frame Player
#define oFrameSpeed						0x0088B700			// Float
#define oFrameSpeed2					0x0088B494			// Float
#define oFrameSpeed3					(0x0061EB5E + 3)	// Byte (Method 1) [Check Macro name]
#define oFrameSpeed4					(0x004DB812 + 6)	// Byte (Method 2) [Check Macro name]
#define oGameState						0x008D6F7C 
#define oObjUser						0x7AB351C
#define oClass							0x0B
#define	oDexterity						0x1A
#define oAttackSpeed					0x60
#define pGetAttackSpeed					((void(__thiscall*)()) 0x00511C7E) // 1.04D

// -> Game Window
#define pGameWindow						*(HWND*)0x809F654
#define oGameWindowText					0x008D6A6C

// -> User
#define pPlayerState					*(int*)0x008D6F7C

// -> Maps
#define pMapNumber						*(int*)0x008C5CF8

// -> Font
#define oLoadMainFont1					0x005FAB27	// -> Normal (400)
#define oLoadMainFont2					0x005FAB8E	// -> Bold (700)
#define oLoadMainFont3					0x005FABF7	// -> Bold (700)
#define oLoadMainFont4					0x005FAC60	// -> Normal (400)

#define pLoadMainFont1					*(HFONT*)0x809F664
#define pLoadMainFont2					*(HFONT*)0x809F668
#define pLoadMainFont3					*(HFONT*)0x809F66C
#define pLoadMainFont4					*(HFONT*)0x809F670

// -> Item
#define pInitModelData					((void(__cdecl*)())0x005D81C5)
#define pInitTextureData				((void(__cdecl*)())0x005DA0F4)
#define pLoadModel						((void(__cdecl*)(int ResourceID,char *Path,char *File,int Index))0x005D5DC3)
#define pLoadTexture					((void(__cdecl*)(int ResourceID,char *SubFolder,int Wrap,int Type,bool Check))0x005D5710)
#define pSetItemSpecialStat				((int(__cdecl*)(short ItemID,int Arg2,BYTE SpecialOption,BYTE SpecialValue,int Arg5))0x0058F9E0)
#define oSetItemSpecialStat_Hook		0x00596FCB

// -> Item Stack
#define oItemStackAttachCall01			0x00733CCD
#define oItemStackAttachCall02			0x00757A09
#define oItemStackAttachCall03			0x0075AA30

// -> Fruit Messages (Normal & Cash Shop Fruits)
#define oFruitRemoveMsgBox01			0x00636C21
#define oFruitRemoveMsgBox02			0x00636C7D
#define oFruitRemoveMsgBox03			0x00636EC2
#define oFruitRemoveMsgBox04			0x00636F22
// ----
#define oCashShopFruitRemove			0x00637295

// -> PC Point Item Price (in PCShop)
#define pItemPriceOnPCShop				((int(__cdecl*)(lpItemObj Item,int Arg2))0x0050CE05)

// -> Item Description (Option) Style
#define oItemAddDescriptionOpt_Hook		0x0059787D
#define oItemAddDescriptionOpt_Allowed	0x00597884
#define oItemAddDescriptionOpt_Return	0x005978D5

// -> Item Book (Summoner) Inventory Position
#define oItemSummonBookInvenPos_Hook	0x005A07F3
#define oItemSummonBookInvenPos_Jump	0x005A08E3
#define oItemSummonBookInvenPos_Return	0x005A0807

// -> Item Book (Summoner) Inventory Rotation
#define oItemSummonBookInvenRot_Hook	0x0059E462
#define oItemSummonBookInvenRot_Jump	0x0059F3DB
#define oItemSummonBookInvenRot_Return	0x0059E495

// -> Item Ring Inventory Position
#define oItemRingInventoryPos_Hook		0x0059F09E
#define oItemRingInventoryPos_Allowed	0x0059F0A4
#define oItemRingInventoryPos_Return	0x0059F0AA

// -> Item Name Color
#define oItemNameColorR					0x0059C8E8
#define oItemNameColorG					0x0059C8E3
#define oItemNameColorB					0x0059C8DE

// -> Divine
#define oItemDivineNameOnFloor_Hook		0x0059C77B
#define oItemDivineNameOnFloor_Allowed	0x0059C8D8
#define oItemDivineNameOnFloor_Return	0x0059C786

// -> Sound
#define pLoadWavSound					((int(__cdecl*)(int SoundID,char*Folder,int Arg3,bool State))0x0064D77D)
#define pPlayWavSound					((int(__cdecl*)(int SoundID,int Arg2,int Arg3))0x0064DB05)

// -> MiniMap
#define oMiniMapKeyPush					0x00730A9E
#define pLoadSomeMapObject				((void(*)())0x005E4B99)

// -> SkyBox
#define oDisplay						0x0060175A
#define pSkyHook						((void(__cdecl*)())0x0057FC00)

// -> Display
#define pGameLoad						((int(__cdecl*)())0x005F921D)
#define pMoveListInit					((void(__thiscall*)(LPVOID This,int Arg1,int Arg2))0x751320)
#define pInitGraphics					((void(__cdecl*)())0x006E8721)
#define pSelectDraw						((int(__cdecl*)(DWORD))0x0041EB98)
#define pGameResolutionMode				*(int*)0x809F460
#define oInitGraphics_Call				0x006E80DC
#define oSelectDraw_Call				0x004063FF

// -> ChatHandler
#define oChatHandler01_Call				0x0057EC8A
#define oChatHandler02_Call				0x0057EDDB
#define oChatHandler03_Call				0x0057EEB4
#define oChatHanlder04_Call				0x006F41AD

// -> Interface
#define pLoadImage						((int(__cdecl*)(char * Folder,int Code,int Arg3,int Arg4,int Arg5))0x006C167E)
#define pWindowThis						((LPVOID(*)())0x7747FF)
#define pCheckWindow					((bool(__thiscall*)(LPVOID This,int Code))0x00772B6D)

#define pGetMapName						((char*(__cdecl*)(int MapNumber))0x005A48E0)
#define pChatHandler					((void(*)(char*Command))0x00541B20)
#define pDrawInterface					((void(__cdecl*)()) 0x00739CB5)
#define oDrawInterface_Call				0x00739C02
#define pDrawGUI						((void(__cdecl*)(DWORD, float, float, float, float)) 0x006FBD23)
#define pDrawColorButton				((void(__cdecl*)(DWORD, float, float, float, float, float, float, DWORD)) 0x006FBED6)
#define pLoadSomeForm					((void(__cdecl*)()) 0x006E8721) // -> pInitGraphics :)
#define oLoadSomeForm_Call				0x006E80DC // -> oInitGraphics_Call
#define pDrawImage						((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, int Arg6, int Arg7, float ScaleX, float ScaleY, int Arg10, int Arg11, GLfloat Alpha)) 0x005F5459)
#define pCursorX        				*(int*)0x809F0FC
#define pCursorY        				*(int*)0x809F0F8
#define pDrawTextExtern					((int(__cdecl*)(int Arg1,unsigned __int8 *Arg2,char Arg3))0x4B69F0)//0x004B69F0
#define pDrawToolTip					((int(__cdecl*)(int X, int Y, LPCSTR Text)) 0x00514E80)
#define pDrawColorText					((int(__cdecl*)(LPCTSTR Text, int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align)) 0x72DDF7)
#define pDrawTextMini					((int(__thiscall*)(LPVOID This, int Arg2)) 0x41EE2C)
#define pDrawText						((int(__thiscall*)(LPVOID This, int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin)) 0x0041EE57)
#define pDrawBarForm					((void(__cdecl*)(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)) 0x5F518C)
#define pSetTextColor					((void(__thiscall*)(LPVOID This,BYTE Red,BYTE Green,BYTE Blue,BYTE Alpha)) 0x0041ED68)
#define pSetBackGround					((void(__thiscall*)(LPVOID This,BYTE Red,BYTE Green,BYTE Blue,BYTE Alpha)) 0x0041EDCA)
#define pDrawItemModel					((int(__cdecl*)(float PosX, float PosY, float Width, float Height, int ItemID, int a6, int a7, float a8, char a9)) 0x005A0AF0)
#define pMapThis						((char()()) 0x7E4E36)
#define pTextThis						((LPVOID(*)())0x41EB98)
#define pMakeColor						((int(__cdecl*)(BYTE,BYTE,BYTE,BYTE))0x4109C0)
#define pSetBlend						((void(__cdecl*)(BYTE Mode)) 0x5F3BD0)
#define pGLSwitchBlend					((void(__cdecl*)()) 0x5F3C6B)
#define pGLSwitch						((void(__cdecl*)()) 0x5F3B51)
#define pAllowGUI						((bool(__cdecl*)()) 0x00730BB0)
#define oAllowGUI_Call1					0x00730668
#define oAllowGUI_Call2					0x0073BC35
#define pWinWidth						*(GLsizei*)0x08D65C8
#define pWinHeight						*(GLsizei*)0x08D65CC
#define pWinWidthReal					*(float*)0x8F5C8C
#define pWinHeightReal					*(float*)0x8F5C90
#define pWinFontHeight					*(int*)0x7AB3538
#define pSetCursorFocus					*(DWORD*)0x80A39D8

// -> Skill		
#define pInitSkillData					((void(__cdecl*)())0x005E24C4)

// -> Glow
#define pItemGlowColor					((void(__cdecl*)(int ObjectId,float Arg2,float Arg3,vec3_t Color,bool Mode))0x005C2744)

// -> Smoke
#define oSetSmokeEffect					0x004F9F76
#define oSetSmokeColor					0x004F9FDA
#define oSetSmokeAllowed				0x004F9F9F
#define oSetSmokeNotAllowed				0x004FA63E
#define oSetSmokeReturn					0x004FA013

// -> Skills
#define oSiegeSkillsAllowed01			0x0057F0A7
#define oSiegeSkillsAllowed02			0x0057F0AC
#define oSiegeSkillsAllowed03			0x0057F0B1
#define oSiegeSkillsAllowed04			0x0057F0B6
#define oSiegeSkillsAllowed05			0x0057F0BB
#define oSiegeSkillsAllowed06			0x0059A9B5
#define oSiegeSkillsAllowed07			0x0059A9BB
#define oSiegeSkillsAllowed08			0x0059A9C1
#define oSiegeSkillsAllowed09			0x0059A9C7
#define oSiegeSkillsAllowed10			0x0059A9CD
#define oSiegeSkillsAllowed11			0x0059A9D3
#define oSiegeSkillsAllowed12			0x00579D0F
#define oSiegeSkillsAllowed13			0x00579D14
#define oSiegeSkillsAllowed14			0x00579D19
#define oSiegeSkillsAllowed15			0x00579D1E
#define oSiegeSkillsAllowed16			0x00579D23
#define oSiegeSkillsAllowed17			0x00579D71
#define oSiegeSkillsAllowed18			0x00579D76
#define oSiegeSkillsAllowed19			0x00579D7B
#define oSiegeSkillsAllowed20			0x00579D80
#define oSiegeSkillsAllowed21			0x00579D85
#define oSiegeSkillsAllowed22			0x00492A98
#define oSiegeSkillsAllowed23			0x00579D28
#define oSiegeSkillsAllowed24			0x0057F0C0
#define oSiegeSkillsAllowed25			0x00579D8A

// -> ToolTip (Descriptions)
#define oItemDescriptionText_Hook		0x00594CFD
#define oItemDescriptionText_Next		0x00594D48
#define oItemDescriptionText_Crypt		0x00851348
#define oItemDescriptionText_Color		0x07BE239C
#define oItemDesctiptionText_Weight		0x07C114A0
#define oItemDescriptionText_Line		0x07C13C7C
#define oItemDescriptionText_This		0x07C13C80
#define oItemDescriptionText_Point		0x07BE1238

#define pSetItemTextLine				((void(__cdecl*)(int Line,LPSTR Text,...))0x851348)

// -> Draw Frame
#define oDrawFrameFixAllowed01			0x006020C4
#define oDrawFrameFixAllowed02			0x00888FC3

// -> Fix Move Without Seal
#define oMoveWithoutSealAllowed			0x0075104B

// -> Effect
#define oRenderPartObjectEffect01		0x004E9E21
#define oRenderPartObjectEffect02		0x005D31BB

// -> Item Gold Smelt Effect
#define oItemAddGoldSmelt_Hook			0x005C7BC4
#define oItemAddGoldSmelt_Allowed		0x005C7BDA
#define oItemAddGoldSmelt_Return		0x005C7BCD

// -> Item Armor Position on Inventory
#define oItemArmorPosition_Hook			0x005A0D3A
#define oItemArmorPosition_Allowed		0x005A0D8B
#define oItemArmorPosition_Return		0x005A0D42

// -> Item Description Text by Number of Items (Durability)
#define oItemDescriptionByNumber_Hook	0x00595FE2
#define oItemDescriptionByNumber_Allow	0x00596135
#define oItemDescriptionByNumber_Return	0x00595FEC

// -> Event Item Bags
#define oItemAddInventoryPosition_Hook	0x0059F035
#define oItemAddInventoryPosition_Exit	0x0059F04C

#define oItemAddInventorySize_Hook		0x005A0681
#define oItemAddInventorySize_Return	0x005A0696

#define oItemAddBoxOfLuckThis_Hook		0x005A1024
#define oItemAddBoxOfLuckThis_Allowed	0x005A102C
#define oItemAddBoxOfLuckThis_Return	0x005A1051

#define oItemAddFloorSize_Hook			0x005C0E40
#define oItemAddFloorSize_Allowed		0x005C0E4C
#define oItemAddFloorSize_Return		0x005C0E68

// -> Item Level +14 & +15 (Glow)
#define oItemExtendLevelGlow01			0x004E5396
#define oItemExtendLevelGlow02			0x004E53CC
#define oItemExtendLevelGlow03			0x004E51A2
#define oItemExtendLevelGlow04			0x004E51DB

// -> Item Level Extended (+16)
#define oItemExtendLevelPlus16			0x005D2067

// -> Item Level Attack/Defense (+15)
#define oItemExtendLevelAttr01			0x0050A56B
#define oItemExtendLevelAttr02			0x0050A571
#define oItemExtendLevelAttr03			0x0050A59A
#define oItemExtendLevelAttr04			0x0050A696
#define oItemExtendLevelAttr05			0x0050A69C
#define oItemExtendLevelAttr06			0x0050A6C5
#define oItemExtendLevelAttr07			0x0050A7B8
#define oItemExtendLevelAttr08			0x0050A7BE
#define oItemExtendLevelAttr09			0x0050A7E4
#define oItemExtendLevelAttr10			0x0050A8C6
#define oItemExtendLevelAttr11			0x0050A8CC
#define oItemExtendLevelAttr12			0x0050A8F2
#define oItemExtendLevelAttr13			0x0050AA7C
#define oItemExtendLevelAttr14			0x0050AA82
#define oItemExtendLevelAttr15			0x0050AABA
#define oItemExtendLevelAttr16			0x0050AAC0
#define oItemExtendLevelAttr17			0x0050AB13
#define oItemExtendLevelAttr18			0x0050AB19
#define oItemExtendLevelAttr19			0x0050AB41
#define oItemExtendLevelAttr20			0x0050AB47
#define oItemExtendLevelAttr21			0x0050AB99
#define oItemExtendLevelAttr22			0x0050AC05
#define oItemExtendLevelAttr23			0x0050AC7C
#define oItemExtendLevelAttr24			0x0050AC82
#define oItemExtendLevelAttr25			0x0050ACAB

// -> Bows
#define pCreateBowSkill					((void(__cdecl*)(int Object,int Position,int Target,BYTE Skill,DWORD ModelSize,USHORT SkillId))0x00698FA3)

//#define pCreateElfSkill					((int(__cdecl*)(int SkillLevel,OBJECT *Target,int Arg3))0x64DB05)
#define pCreateElfSkill					((int(__cdecl*)(int SkillLevel,int Target,int Arg3))0x64DB05)

#define oCreateBowSkill_Hook			0x00699410
#define oCreateBowSkill_Return			0x00699416

#define oCreateInvenPos_Hook			0x0059F774
#define oCreateInvenPos_Allowed			0x0059F77C
#define oCreateInvenPos_Return			0x0059F7BB

#define oCreateBowDimension_Hook		0x004E9A0B
#define oCreateBowDimension_Next		0x004E9A12

#define oCreateBowArrowReload_Hook		0x0050B20C
#define oCreateBowArrowReload_Allowed	0x0050B279
#define oCreateBowArrowReload_Return	0x0050B219

// -> Item Socket System
#define pItemSocketSet					((int(__stdcall*)(int ItemId))0x004C2CEA)

// -> Item Title Color
#define oItemTitleColor					0x005904F8
#define oItemTitleColor_Next			0x00590502
#define oItemTitleColor_Stack			0x00590620

// -> Item Drop Title Color (Using Zen)
#define oItemDropTitleColor_Hook		0x0059ACCC
#define oItemDropTitleColor_Return		0x0059AD1E

// -> Cash Shop Buttons
#define oCashShopGiftButtonRemoveHook	0x007A92B5
#define oCashShopPurchaseButtonCoordY	0x007A90BE

// -> Character Statics
#define oCharEnergyTextNumberLine		0x006F13FC
#define oCharVitalityTextNumberLine		0x006F108E
#define oCharStrengthTextNumberLine		0x006EF316
#define oCharAgilityTextNumberLine		0x006F0509

// -> Character Statics (On Switch)
#define oCharStrengthOnSwitchNumberLine	0x004046B1

// -> Blades Wizardry Damage Text View
#define oBladesWizardryDmg_Hook			0x005969F6
#define oBladesWizardryDmg_Allowed		0x00596A06
#define oBladesWizardryDmg_Return		0x005969FC

// -> Blades Wizardry Aditional Text View
#define oBladesWizardryAdd_Hook			0x00597092
#define oBladesWizardryAdd_Allowed		0x005970AE
#define oBladesWizardryAdd_Return		0x00597098

// -> Scepters Pet Attack Text View
#define oSceptersPetAttack_Hook			0x0050A2BB
#define oSceptersPetAttack_Allowed		0x0050A2CD
#define oSceptersPetAttack_Return		0x0050A2C4

// -> Bundles Props
#define oBundledBlessInvenPos_Hook		0x005A11B3
#define oBundledBlessInvenPos_Allowed	0x005A133A
#define oBundledBlessInvenPos_Return	0x005A11BF

#define oBundledBlessInvenSize_Hook		0x0059FD4B
#define oBundledBlessInvenSize_Allowed	0x005A08E3
#define oBundledBlessInvenSize_Return	0x0059FD57

#define oBundledBlessInvenPrice_Hook	0x0048B84B
#define oBundledBlessInvenPrice_Jump	0x0048B87F
#define oBundledBlessInvenPrice_Return	0x0048B866

// -> Jewels Props
#define oJewelsDropSound_Hook			0x005C17C2
#define oJewelsDropSound_Allowed		0x005C17EF
#define oJewelsDropSound_Return			0x005C17CB

#define oJewelsPickSound_Hook			0x00621184
#define oJewelsPickSound_Allowed		0x006211E0
#define oJewelsPickSound_Return			0x0062118B

#define oJewelsMoveOnItem_Hook			0x00733B71
#define oJewelsMoveOnItem_Allowed		0x00733B78
#define oJewelsMoveOnItem_Return		0x00733B99

#define oJewelsAllowOnItem_Hook			0x007351D6
#define oJewelsAllowOnItem_Allowed		0x007351DD
#define oJewelsAllowOnItem_Return		0x007351ED

#define oJewelsInvenSwitch_Hook			0x0075758A
#define oJewelsInvenSwitch_Allowed		0x007575E0
#define oJewelsInvenSwitch_Return		0x00757597

#define oJewelsPricesOnShop_Hook		0x0050D0B2
#define oJewelsPricesOnShop_Allowed		0x0050E3DF
#define oJewelsPricesOnShop_Return		0x0050D0D3

#define oJewelsBlockDrop_Hook			0x0059DBCB
#define oJewelsBlockDrop_Allowed		0x0059DCDE
#define oJewelsBlockDrop_Return			0x0059DBD5

#define oJewelsShineEffect_Hook			0x005C5C8A
#define oJewelsShineEffect_Allowed		0x005C5C93
#define oJewelsShineEffect_Return		0x005C5D0D

#define oJewelsUpdateFlags_Hook			0x007577FA
#define oJewelsUpdateFlags_Call			0x0075780B
#define oJewelsUpdateFlags_Return		0x007579CC

// ----------------------------------------------------------------

// -> Pets
#define oCreatePetFunctionUnk_Hook		0x0046C3FD
#define oCreatePetFunctionUnk_Allowed	0x0046C47E
#define oCreatePetFunctionUnk_Return	0x0046C41B

#define oCreatePetAllowWalkOnMap_Hook	0x004AC47B
#define oCreatePetAllowWalkOnMap_Jump	0x004AC4B1
#define oCreatePetAllowWalkOnMap_Allow	0x004ADD40
#define oCreatePetAllowWalkOnMap_Return	0x004AC49C

#define oCPSetPlayerActions_Hook		0x0046D676
#define oCPSetPlayerActions_Return		0x0046D87B
#define oCPSetPlayerActions_Call1		0x004ABF7C

#define oCreatePetFollowChar_Hook		0x00735C53
#define oCreatePetFollowChar_Allowed	0x00735CB8
#define oCreatePetFollowChar_Return		0x00735C67

// -> Wings
#define oFixMoveKanturu_Hook			0x006CEE3E
#define oFixMoveKanturu_Return			0x006CEE54
#define oFixMoveKanturu_Allowed			0x006CEE46

#define oShowDurability_Hook			0x00595DBE
#define oShowDurability_Allowed			0x00595DF4
#define oShowDurability_Return			0x00595DD0

#define oShowAdditionals_Hook			0x00595265
#define oShowAdditionals_Allowed		0x00595282
#define oShowAdditionals_Return			0x005952FF

#define oAddLuckOption_Hook				0x0050B8CD
#define oAddLuckOption_Allowed			0x0050B8D5
#define oAddLuckOption_Return			0x0050B8F3

#define oAddExcellentStatus_Hook		0x0050B688
#define oAddExcellentStatus_Allowed		0x0050B694
#define oAddExcellentStatus_Return		0x0050B77F

#define oHideExcellentText_Hook			0x00591594
#define oHideExcellentText_Allowed		0x0059159A
#define oHideExcellentText_Return		0x005915D4

#define oHideExcellentGlow_Hook			0x005D2297
#define oHideExcellentGlow_Allowed		0x005D23EE
#define oHideExcellentGlow_Return		0x005D22B3

#define oDisableLevelShine_Hook			0x005CDCC8
#define oDisableLevelShine_Allowed		0x005CE14E
#define oDisableLevelShine_Return		0x005CDCE1

#define oAddAdditionalLife_Hook			0x0050C453
#define oAddAdditionalLife_Default		0x0050C51A

#define pAllowRepairWings				((char(__cdecl*)(int * pObjItem))0x0059E180)

// -> Create Arrow Skill
#define oCreateArrowSkill_Hook			0x0065ACC7
#define oCreateArrowSkill_Allowed		0x0065ACD3
#define oCreateArrowSkill_Return		0x0065B251

// -> Monster
#define oNpcName						0x7A724F8//*(DWORD*)0x7A724F8
//#define pSetObjAttr(x)					*(BYTE*)(x + 722)
//#define pLoadMonster					((int(__cdecl*)(int MonsterID))0x5DD7BC)
//#define pGetSkillLvl					((int(__cdecl*)(int LevelReq,int Arg2,int Arg3))0x64DB05)
//#define pSetMainAttr					((int(__cdecl*)(int ObjectPointer,int MonsterID))0x4FEDE7)
//#define pShowMonster					((int(__cdecl*)(int MonsterID,int Arg2,int Arg3,int Arg4))0x4FF128)
//#define pViewportObj					((int(__cdecl*)(int ViewportID,int ResourceID,char Arg3,char Arg4,float Size))0x4FD3A4)

// -> Ex700 HP Mob Bar
#define pViewMonsterStruct				*(int*)0x7A7239C
#define pGetViewPortId					((int(__cdecl*)(int aIndex)) 0x4FBF3E)
#define pGetPosFromAngle				((void(__cdecl*)(VAngle*Angle,int*PosX,int*PosY))0x5F3770)

// -> Protocol
#define pDataRecv						((void(*)(DWORD Type,LPBYTE Data,int Len,int aIndex))0x0063FDD0)
#define oDataRecv_Call					0x0063F6B3
#define pActiveSocket					*(SOCKET*)(*(DWORD*)0x8D7D48 + 0x0C)
#define	MAX_XOR_KEYS					32

// -> User
#define oUserObjectStruct				*(int*)0x7AB351C
#define oUserPreviewStruct				*(int*)0x7A723B8
// ----
#define pPlayerLevel					*(short*)(oUserObjectStruct + 14)
#define pPlayerGuild					*(WORD*)(oUserPreviewStruct + 92)
#define pPlayerPoint					*(short*)(oUserObjectStruct + 116)
#define pPlayerPosX						*(BYTE*)(oUserPreviewStruct + 140)
#define pPlayerPosY						*(BYTE*)(oUserPreviewStruct + 144)

// -> Preview
#define pMakePreviewCharSet				((void(__cdecl*)(int ObjectIndex,BYTE *CharSet,int Object,int Mode))0x004FDFE0)
#define LODWORD(h)						((DWORD)(__int64(h) & __int64(0xffffffff)))
#define pPreviewStructOffset			0x07A723B8
#define pPreviewStructThis				*(DWORD*)0x07A723B8
#define pCreatePetObject				((void(__stdcall*)(int ItemId))0x0075574A)
#define pPreviewPetSwitch				((void(__thiscall*)(LPVOID This,int Arg1,int Arg2,int Arg3,int Arg4,int Arg5,int Arg6))0x81BA70)
#define pObjPetGetThis					((LPVOID(__cdecl*)(void))0x81AB71)

#define MAX_PET_LIFE					0xFF
#define pObjectStruct					*(DWORD*)0x7A723B8
#define pPreviewStruct					*(DWORD*)0x7A7239C
#define pPreviewStruct2					*(int*)0x7A7239C
#define pItemStruct						*(DWORD*)0x7AB3514
#define pThisStructUnk					*(DWORD*)0x7AB3518
#define pThisStructUnk2					*(DWORD*)0x80A818C

#define SearchLineTextThis				((LPVOID(*)()) 0x7AAD828)
#define pThisPointer					((int(__cdecl*)(int Arg1,char Arg2,char Arg3))0x4B69F0)
#define SearchLineText					((char(__thiscall*)(LPVOID This,char Arg2))0x402F50)
#define pGetTextNumberLine				((char(__thiscall*)(LPVOID This,int Arg2))0x402F50)
#define pSub_736299						((void(__stdcall*)(LPVOID This,int Arg1,int Arg2,int Arg3,int Arg4,int Arg5,int Arg6))0x736299)

#define SafeZone						*(BYTE*)(LODWORD(pObjectStruct) + 14)

#endif