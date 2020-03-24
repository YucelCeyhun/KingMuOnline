#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <Windows.h>

// Virtual Key Codes
#define VK_M							0x4D // -> Move List
#define VK_N							0x4E
#define VK_H							0x48
#define VK_J							0x4A
#define VK_K							0x4B
#define VK_O							0x4F
#define VK_S							0x53
#define VK_X							0x58 // -> Cash Shop
#define VK_Y							0x59

#define pVisible(x)						*(BYTE*)(x + 15)
#define pPlayerClass(x)					*(BYTE*)(x + 19)
#define pAncientEffect(x)				*(BYTE*)(x + 22)
#define pAtEffect(x)					*(BYTE*)(x + 23)
#define pHelmSlot(x)					*(WORD*)(x + 232)
#define pHelmSetLevel(x)				*(BYTE*)(x + 234)
#define pHelmSetExcellent(x)			*(BYTE*)(x + 235)
#define pHelmSetAncient(x)				*(BYTE*)(x + 236)
#define pArmorSlot(x)					*(WORD*)(x + 264)
#define pArmorSetLevel(x)				*(BYTE*)(x + 266)
#define pArmorSetExcellent(x)			*(BYTE*)(x + 267)
#define pArmorSetAncient(x)				*(BYTE*)(x + 268)
#define pPantsSlot(x)					*(WORD*)(x + 296)
#define pPantsSetLevel(x)				*(BYTE*)(x + 298)
#define pPantsSetExcellent(x)			*(BYTE*)(x + 299)
#define pPantsSetAncient(x)				*(BYTE*)(x + 300)
#define pGlovesSlot(x)					*(WORD*)(x + 328)
#define pGlovesSetLevel(x)				*(BYTE*)(x + 330)
#define pGlovesSetExcellent(x)			*(BYTE*)(x + 331)
#define pGlovesSetAncient(x)			*(BYTE*)(x + 332)
#define pBootsSlot(x)					*(WORD*)(x + 360)
#define pBootsSetLevel(x)				*(BYTE*)(x + 362)
#define pBootsSetExcellent(x)			*(BYTE*)(x + 363)
#define pBootsSetAncient(x)				*(BYTE*)(x + 364)
#define pWeaponFirstSlot(x)				*(WORD*)(x + 392)
#define pWeaponFirstSetLevel(x)			*(BYTE*)(x + 394)
#define pWeaponFirstSetExcellent(x)		*(BYTE*)(x + 395)
#define pWeaponFirstSetAncient(x)		*(BYTE*)(x + 396)
#define pWeaponSecondSlot(x)			*(WORD*)(x + 424)
#define pWeaponSecondSetLevel(x)		*(BYTE*)(x + 426)
#define pWeaponSecondSetExcellent(x)	*(BYTE*)(x + 427)
#define pWeaponSecondSetAncient(x)		*(BYTE*)(x + 428)
#define pWingsSlot(x)					*(WORD*)(x + 456)
#define pSetUnknown1(x)					*(BYTE*)(x + 458)
#define pSetUnknown2(x)					*(BYTE*)(x + 459)
#define pSetUnknown3(x)					*(BYTE*)(x + 460)
#define pPetSlot(x)						*(WORD*)(x + 488)
#define pSetUnknown4(x)					*(BYTE*)(x + 490)
#define pFenrirCharSet(x)				*(BYTE*)(x + 491)
#define pExpectPet(x)					*(BYTE*)(x + 492)
#define pObjAction(x)					*(BYTE*)(x + 718)
#define pObjScale(x)					*(DWORD*)(x + 796)
#define pObjSelectZone(x)				*(float*)(x + 924)
#define pGetPosition(x)					*(WORD*)(x + 952)
// ----
#define MAX_ITEM_INDEX					255
#define MAX_CUSTOM_ITEMS				256
// ----
#define CS_START						1236
// ----
#define CS_EMPTY_SLOT					-1
#define CS_EMPTY_ITEM					511
#define CS_EMPTY_WEAPON					4095 // ITEM(7, 511)
// ----
#define	CS_SET_1(x)						(x >> 2)
// ----
#define CS_HELM							9036 // Season 4.6 JPN
#define CS_ARMOR						CS_HELM + 20
#define CS_PANTS						CS_ARMOR + 20
#define CS_GLOVES						CS_PANTS + 20
#define CS_BOOTS						CS_GLOVES + 20
// ----
#define Color4f(r, b, g, o)				((o << 24) + (g << 16) + (b << 8) + r)
// ----
#define CS_GET_STRUCT(x, y)				(CS_START * x + *(int*)y)
#define CS_GET_WEAPON(x, y)				( y | (16 * (x & 0xF0)) )
#define CS_GET_HELM(x, y, z)			( (32 * (z & 0xF)) + 16 * ((x >> 7) & 1) + (y >> 4) )
#define CS_GET_ARMOR(x, y, z)			( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 6) & 1) + (y & 0xF) )
#define CS_GET_PANTS(x, y, z)			( (32 * (z & 0xF)) + 16 * ((x >> 5) & 1) + (y >> 4) )
#define CS_GET_GLOVES(x, y, z)			( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 4) & 1) + (y & 0xF) )
#define CS_GET_BOOTS(x, y, z)			( (32 * (z & 0xF)) + 16 * ((x >> 3) & 1) + (y >> 4) )

#endif