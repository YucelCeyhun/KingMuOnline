#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

class Graphics
{
public:
	Graphics();
	// ----
	void Load();
	//static void InitGraphics();
	static int SelectDraw(int value);
};

extern Graphics gGraphics;

#endif