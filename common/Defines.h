#ifndef __DEFINES_H__
#define __DEFINES_H__

#define ENABLE_CUSTOM_OPTMIZE			TRUE
#define ENABLE_WEBZEN_SPEED_CHECK		FALSE

#define IS_NEWWINGS(x)					((x < ITEMGET(12,236)) ? FALSE : (x > ITEMGET(12,253)) ? FALSE : TRUE)

#define ANGELPET						0x00
#define SATANPET						0x01
#define UNIRIAPET						0x02
#define DINORANTPET						0x03
#define DARKHORSE						0x04
#define RUDOLFPET						0x43
#define FENRIRPET						0x25
#define DARKWOLF						0x61
#define SABLEFANG						0x62
#define MISTICTIGER						0x63
#define UNICORN							0x6A
#define SKELETON						0x7B
#define LAST_PET						0xFE
#define INVALID_INDEX					0x1FF

#define MAX_CHARNAME_LEN				10

#define MAX_GUILDNAME_LEN				9
#define MAX_GUILDUNION_COUNT			3
#define MAX_GUILDMARK_LEN				32
#define MAX_GUILDMEMBER_COUNT			80
#define MAX_GUILDNOTICE_LEN				60

#define CLASS_DW						0x00
#define CLASS_SM						0x01
#define CLASS_GM						0x02
#define CLASS_DK						0x10
#define CLASS_BK						0x11
#define CLASS_BM						0x12
#define CLASS_FE						0x20
#define CLASS_ME						0x21
#define CLASS_HE						0x22
#define CLASS_MG						0x30
#define CLASS_DM						0x32
#define CLASS_DL						0x40
#define CLASS_LE						0x42
#define CLASS_SUM						0x50
#define CLASS_BS						0x51
#define CLASS_DIM						0x52

#define MAX_WAREHOUSE_LEN				1920
#define MAX_INVENTORY_LEN				1728

#define MAX_MAIL_SUBJECT_LEN			32
#define MAX_MAIL_IMAGE_LEN				18
#define MAX_MAIL_BODY_LEN				1000
#define MAX_MAIL_DATE_LEN				30

#define MAX_HOTKEY_BUFFER_LEN			10

#define MAX_DUEL_CHANNEL				4
#define MAX_DUEL_OBSERVER				10

#define MAX_JOL_OPT						7

// Player Inventory Defines
#define EQUIPMENT_WEAPON_RIGHT			0
#define EQUIPMENT_WEAPON_LEFT			1
#define EQUIPMENT_HELM					2
#define EQUIPMENT_ARMOR					3
#define EQUIPMENT_PANTS					4
#define EQUIPMENT_GLOVES				5
#define EQUIPMENT_BOOTS					6
#define EQUIPMENT_WING					7
#define EQUIPMENT_HELPER				8
#define EQUIPMENT_AMULET				9
#define EQUIPMENT_RING_RIGHT			10
#define EQUIPMENT_RING_LEFT				11
#define EQUIPMENT_GOLD					12

#endif