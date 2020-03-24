#ifndef __MINIMAP_H__
#define __MINIMAP_H__

#define MINI_MAP_FILE_LOAD	"Custom\\Minimap\\Map%d.jpg"
#define MINI_MAP_FILE_CHECK ".\\Data\\Custom\\Minimap\\Map%d.ozj"
#define MAX_MINI_MAP		100

class cMiniMap
{
public:
	void Load();
	void Init();
	void Toggle();
	// ----
	DWORD CreateNewDir();
	bool FileCheck(int Map);
	bool CheckThis();
	bool minimapToggle = false;
	// ----
	static void Core();
	static void Path();
	static bool CoreCheck(int Map);
	// ----
private:
	bool Table[MAX_MINI_MAP];
};

extern cMiniMap gMiniMap;

#endif