#include "StdAfx.h"

cProtocol gProtocol;

void cProtocol::DataRecv(DWORD Case, LPBYTE lpMsg, int Len, int aIndex)
{
	BYTE ProtocolType = lpMsg[0];
	// ----
	if (ProtocolType == 0xC1)
	{
		switch (BYTE(Case))
		{
		case PROTOCOL_KILLED:
		{
			gVisualFix.RecvKilledObject((PMSG_DIEPLAYER*)lpMsg);
			//gUser.RecvKilledObject((PMSG_DIEPLAYER*)lpMsg);
		}
		break;
		// ----
		case PROTOCOL_ATTACK:
		{
			gVisualFix.RecvDamage((PMSG_ATTACKRESULT*)lpMsg);
			//gUser.RecvAttackResult((PMSG_ATTACKRESULT*)lpMsg);
		}
		break;
		// ----
		case PROTOCOL_RECVHPTOSD:
		{
			gVisualFix.RecvHPSD((PMSG_REFILL*)lpMsg);
		}
		break;
		// ----
		case PROTOCOL_RECVMPTOAG:
		{
			gVisualFix.RecvMPAG((PMSG_MANASEND*)lpMsg);
		}
		break;
		// ----
		/*
		case 0x30: // Wharehouse Opened ?
		{

		}
		break;
		// ----
		case PROTOCOL_TELEPORT:
		{
			if (lpMsg[4] == 1)
			{
				gHPMobBar.isDraw = false;
			}
			break;
		}
		*/
		// ----

		case 0x70: //version_checked
		{
			PMSG_VERSION* Data = (PMSG_VERSION*)lpMsg;
			BOOL versionStatus = gVControl.getVersion(Data->ClientVersion);

			PMSG_VERSION_CHECKED pMsg;
			pMsg.h.headcode = 0xF2;
			pMsg.h.c = 0xC1;
			pMsg.VersionChecked = versionStatus;
			pMsg.h.size = sizeof(pMsg);

			gProtocol.DataSend((LPBYTE)&pMsg, pMsg.h.size);

			if (!versionStatus)
				MessageBox(NULL, "You need the client update.Please run Launcher.exe to update the client.After that try again.", "CLIENT VERSION FAIL", MB_ICONERROR);

		}
		case 0xF1:
		{
			PMSG_DEFAULT2* lpDef = (PMSG_DEFAULT2*)lpMsg;
			// ----
			switch (lpDef->subcode)
			{
			case PROTOCOL_CHARJOINRESULT:
			{
				gVisualFix.RecvIndex((PMSG_JOINRESULT*)lpMsg);
			}
			break;
			}
			break;
		}
		// ----
		case 0xF3:
		{
			switch (lpMsg[3])
			{
			case PROTOCOL_CHARJOINMAP:
			{
				gVisualFix.RecvUpPoint((PMSG_CHARMAPJOINRESULT*)lpMsg);
				gVisualFix.RecvRespawn();
			}
			break;

			case PROTOCOL_CHARRESPAWN:
			{
				gVisualFix.RecvRespawn();
			}
			break;

			case PROTOCOL_CHARLEVELUP:
			{
				gVisualFix.RecvUpLevel((PMSG_LEVELUP*)lpMsg);
				PMSG_LEVELUP* pResult = (PMSG_LEVELUP*)lpMsg;
			}
			break;

			case PROTOCOL_CHARPOINTDOWN:
			{
				gVisualFix.RecvDownPoint((PMSG_LVPOINTADDRESULT*)lpMsg);
			}
			break;
			}
			break;
		}
		// ----
		case 0xFB:
		{
			PMSG_DEFAULT2* lpDef = (PMSG_DEFAULT2*)lpMsg;
			// ----
			switch (lpDef->subcode)
			{
			case PROTO_CUSTOM_RESETDATA:
			{
				gReset.SetData((RESET_ANS_USERDATA*)lpMsg);
			}
			break;
			}
			break;
		}
		// ----
		case 0xBB:
		{
			PMSG_DEFAULT2* lpDef = (PMSG_DEFAULT2*)lpMsg;
			// ----
			switch (lpDef->subcode)
			{
			case PROTO_CUSTOM_LIFEBAR:
			{
				gExHP.InfoRecv((LPMSG_ANS_LIFEBAR_SEND)lpMsg);
			}
			break;
			}
			break;
		}
		}
	}
	// ----
	pDataRecv(Case, lpMsg, Len, aIndex);
}

void cProtocol::DataSend(LPBYTE Data, int Size)
{
	if (pActiveSocket == INVALID_SOCKET)
	{
		return;
	}

	int StartPos = 0;

	if ((Data[0] == 0xC1) || (Data[0] == 0xC3))
	{
		StartPos = 3;
	}
	else if ((Data[0] == 0xC2) || (Data[0] == 0xC4))
	{
		StartPos = 4;
	}

	XorData(Data, StartPos, Size);

	send(pActiveSocket, (PCHAR)Data, Size, 0);
}

void cProtocol::XorData(LPBYTE& Data, int iStart, int iSize)
{
	if (iStart > iSize)
	{
		return;
	}

	BYTE XOR[MAX_XOR_KEYS];

	XOR[0] = 0xE7;
	XOR[1] = 0x6D;
	XOR[2] = 0x3A;
	XOR[3] = 0x89;
	XOR[4] = 0xBC;
	XOR[5] = 0xB2;
	XOR[6] = 0x9F;
	XOR[7] = 0x73;
	XOR[8] = 0x23;
	XOR[9] = 0xA8;
	XOR[10] = 0xFE;
	XOR[11] = 0xB6;
	XOR[12] = 0x49;
	XOR[13] = 0x5D;
	XOR[14] = 0x39;
	XOR[15] = 0x5D;
	XOR[16] = 0x8A;
	XOR[17] = 0xCB;
	XOR[18] = 0x63;
	XOR[19] = 0x8D;
	XOR[20] = 0xEA;
	XOR[21] = 0x7D;
	XOR[22] = 0x2B;
	XOR[23] = 0x5F;
	XOR[24] = 0xC3;
	XOR[25] = 0xB1;
	XOR[26] = 0xE9;
	XOR[27] = 0x83;
	XOR[28] = 0x29;
	XOR[29] = 0x51;
	XOR[30] = 0xE8;
	XOR[31] = 0x56;

	for (int i = iStart; i < iSize; i++)
	{
		Data[i] ^= Data[i - 1] ^ XOR[i % 32];
	}
}

void cProtocol::Load()
{
	gToolKit.SetOp((LPVOID)oDataRecv_Call, this->DataRecv, ASM::CALL);
}