#ifndef __CAMERA_H__
#define __CAMERA_H__

// 1.03.11 (100%)
static float *Camera_Zoom = (float*)0x006001E9;
static float *Camera_RotY = (float*)0x0088BC78;
static float *Camera_RotZ = (float*)0x0809F150;
static float *Camera_PosZ = (float*)0x0088ACFC;
static float *Camera_ClipX = (float*)0x0088BB18;
static float *Camera_ClipY = (float*)0x005AB4CD;
static float *Camera_ClipZ = (float*)0x00600479;
static float *Camera_ClipW = (float*)0x0088B148;//540.0000
static float *Camera_ClipV = (float*)0x0088BB10;//660.0000
static float *Camera_ClipU = (float*)0x0088BB34;//580.0000
static float *Camera_ClipT = (float*)0x0088BB30;//1250.000
static float *Camera_ClipS = (float*)0x0088BBC4;//330.0000
static float *Camera_ClipR = (float*)0x0088BB3C;//2250.000

class cCamera
{
public:
	cCamera();
	virtual ~cCamera();
	// ----
	void SwitchState();
	void ResetZoom();
	void SetClips();
	void Run(MOUSEHOOKSTRUCTEX * Mouse, WPARAM wParam);
	bool CheckWindow(int WindowID);
	bool DevMod();
	// ----
	bool RestStop;
	BOOL Enabled;
	// ----
	bool InitCamera;
	bool MoveCamera;
	// ----
	float Zoom;
	float RotY;
	float RotZ;
	float PosZ;
	float ClipX;
	float ClipY;
	float ClipZ;
	float ClipV;
	float ClipU;
	float ClipW;
	float ClipS;
	float ClipT;
	float ClipR;
	// ----
	int MouseX, MouseY;
};

extern cCamera gCamera;

#endif