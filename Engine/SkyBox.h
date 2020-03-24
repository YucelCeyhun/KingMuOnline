#ifndef __SKYBOX_H__
#define __SKYBOX_H__

#define MAX_SKY_FACES		6
#define MAX_MAP_SKY			100

#define SKY_NULL_TEXTURE	".\\Data\\Custom\\Sky\\Null.bmp"
#define SKY_BACK_TEXTURE	".\\Data\\Custom\\Sky\\World%d\\Back.bmp"
#define SKY_BOTTOM_TEXTURE	".\\Data\\Custom\\Sky\\World%d\\Bottom.bmp"
#define SKY_FRONT_TEXTURE	".\\Data\\Custom\\Sky\\World%d\\Front.bmp"
#define SKY_LEFT_TEXTURE	".\\Data\\Custom\\Sky\\World%d\\Left.bmp"
#define SKY_RIGHT_TEXTURE	".\\Data\\Custom\\Sky\\World%d\\Right.bmp"
#define SKY_TOP_TEXTURE		".\\Data\\Custom\\Sky\\World%d\\Top.bmp"

class cSkyBox
{
public:
	cSkyBox();
	virtual ~cSkyBox();
	// ----
	bool SkyDisplayInitialized;
	// ----
	struct SkyStruct
	{
		float R;
		float G;
		float B;
	} Sky;
	// ----
	SkyStruct SkyColor;
	// ----
	unsigned int uTextures[MAX_MAP_SKY][MAX_SKY_FACES];
	// ----
	void Load();
	void ChangeSky();
	void GetCamCoords(double* x_cam, double* y_cam, double* z_cam);
	void InitDisplay();
	bool CanDrawSky();
	bool SpecialMaps();
	bool EventMaps();
	static void Display();
	// ----
private:
	char TexturePath[256];
};

extern cSkyBox gSkyBox;

#endif