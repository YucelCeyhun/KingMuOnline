#ifndef __GLOW_H__
#define __GLOW_H__

class cGlow
{
public:
	void Load();
	// ----
	struct sITEM
	{
		int Type;
		int Index;
	};
	// ----
	struct sGLOW
	{
		float R;
		float G;
		float B;
	};
	// ----
	int gItemCount;
	// ----
	sGLOW eGLOW[512];
	sITEM eITEM[512];
	// ----
	static void ItemGlowEx(int ObjectId, float Arg2, float Arg3, vec3_t Color, bool Mode);
};

extern cGlow gGlow;

#endif