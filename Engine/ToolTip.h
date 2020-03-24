#ifndef __TOOLTIP_H__
#define __TOOLTIP_H__

#include "Import.h"

#define MAX_TEXT_LINES		10
#define MAX_TEXT_LENGTH		128

class cToolTip
{
public:
	void Load();
	void InitItemDescriptionText();
	void InitItemDescriptionFixRena();
	void InitItemDescriptionFixLostMap();
	void InitItemDescriptionFixSymbolKundun();
	void InitItemDescriptionFixSymbolKundunAdd();
	void InitItemDescriptionAddOptionTypePosText();
	// ---
	static void AddText(PCHAR Text,INT Color,INT Weight);
	// ---
	static void ItemDescriptionText();
	static void ItemDescriptionFixRena();
	static void ItemDescriptionFixLostMap();
	static void ItemDescriptionFixSymbolKundun();
	static void ItemDescriptionFixSymbolKundunAdd();
	static void ItemDescriptionAddOptionTypePosText();
	// ----
	void ItemNameColorDrop(INT ColorId);
};

extern cToolTip gToolTip;

#endif