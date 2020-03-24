#ifndef __FIXES_H__
#define __FIXES_H__

class cFixes
{
public:
	void Load();
	// ----
	void ImageSplashMode();
	void ScreenShotFolder();
	void FixUseMultiClient();
	void FixMoveWithoutSeal();
	void FixMaxZenCountOnWare();
	void FixDeleteCharWithoutId();
	void FixRemoveFruitMessages();
	void FixMixBmdMaxLineCount();
	void FixBeepSoundWhispMsg();
	void FixAncientMainToolTip();
	void FixAgilityCharacterBug();
	// ----
	static void FixDeleteCharASM();
	static void AncientMainToolTip();
private:
	char CurrentDir[MAX_PATH];
};

extern cFixes gFixes;

#endif