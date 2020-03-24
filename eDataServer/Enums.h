#ifndef __ENUMS_H__
#define __ENUMS_H__

enum eJOIN_PROTOCOL_MSG
{
	JMSG_SERVER_LOGIN				= 0x00,
	JMSG_IDPASS						= 0x01,
	JMSG_JOIN_FAIL					= 0x02,
	JMSG_COMMAND_BLOCK				= 0x04,
	JMSG_USER_CLOSE_BY_ID			= 0x05,
	JMSG_MAP_SVR_MOVE				= 0x7A,
	JMSG_MAP_SVR_AUTH				= 0x7B,
	JMSG_NOTIFY_MAX_USER			= 0x7C,
};

enum eJOIN_ACCOUNTINFO_MSG
{
	eIDPASSRESULT_BADPASS			= 0x00, // your password is wrong. 
	eIDPASSRESULT_SUCCESS			= 0x01, // Success. 
	eIDPASSRESULT_BADID				= 0x02, // id does not exist. 
	eIDPASSRESULT_INUSE				= 0x03, // account is use 
	eIDPASSRESULT_MAXSERVER			= 0x04, // maxium active user reached
	eIDPASSRESULT_ACCBANED			= 0x05, // account banned
	eIDPASSRESULT_FIX_EXP			= 0x0C, // fixed expiration 
	eIDPASSRESULT_INUSE_DET_EXP		= 0x0D, // Determination of Expiration 
	eIDPASSRESULT_TEMPBLOCK			= 0x0E, // a temporary block status (MuManager used) 
	eIDPASSRESULT_BADCOUNTRY		= 0xD2, // IP is not a local IP (not country for player)
};

enum STATE
{
	SS_CLOSED,
	SS_CONNECTED,
};

#endif