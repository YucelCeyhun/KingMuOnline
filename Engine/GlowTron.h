#ifndef __GLOWTRON_H__
#define __GLOWTRON_H__

// Vertex
#define CG_DARKEN_VP			".\\Data\\Custom\\Shader\\glow_darken_vp.cg"
#define CG_GLOWBLUR_VP			".\\Data\\Custom\\Shader\\glow_blur_vp.cg"
#define CG_GLOWCOMBINE_VP		".\\Data\\Custom\\Shader\\glow_combine_vp.cg"

// Fragments
#define CG_DARKEN_FP			".\\Data\\Custom\\Shader\\glow_darken_fp.cg"
#define CG_GLOWBLUR_FP			".\\Data\\Custom\\Shader\\glow_blur_fp.cg"
#define CG_GLOWCOMBINE_FP		".\\Data\\Custom\\Shader\\glow_combine_fp.cg"

extern int IsGlt;
extern void InitScreenGlow(void);
extern void RenderScreenGlow(void);
extern bool g_bEnabled;

class cGlowTron
{
public:
	cGlowTron();
	virtual ~cGlowTron();
	// ----
	bool Enabled;
	void SwitchState();
};

extern cGlowTron gGlowTron;

#endif