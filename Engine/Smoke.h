#ifndef __SMOKE_H__
#define __SMOKE_H__

class cSmoke
{
public:
	// ----
	void Load();
	INT GetLineId(DWORD ItemType);
	static void SetItemEffect();
	static void SetColorEffect();
	// ----
	struct sEffect
	{
		int Id;

		float R;
		float G;
		float B;
	};
};

extern cSmoke gSmoke;

extern cSmoke::sEffect eColor[256];

#endif