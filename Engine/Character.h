#ifndef __CHARACTER_H__
#define __CHARACTER_H__

class cCharacter
{
public:
	void Load();
	//void Init();
	// ----
	static BOOL CheckSafeZone();
	static BOOL CheckCharacterLevel(int Level);
	static void FixTextStats();
	static void FixTextOnSelect();
	static void FixCharacterExSize();
	//static char DrawCharSelection(lpObjViewport pObject);
	// ----
	/*private:
	int Slot;
	float PosX;
	float PosY;
	float PosZ;
	*/
};

extern cCharacter gCharacter;

#endif