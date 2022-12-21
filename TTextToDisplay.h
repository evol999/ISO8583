//---------------------------------------------------------------------------

#ifndef TTextToDisplayH
#define TTextToDisplayH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <IdSync.hpp>
#include "Unit1.h"
class TTextToDisplay : public TIdNotify {
private:
	String lineToAdd;
	TStringList* stringsToAdd;

protected:
	virtual void __fastcall DoNotify();

public:
	__fastcall TTextToDisplay();
	__fastcall TTextToDisplay(String str);
	void __fastcall AddSingleLine(String str);
	void __fastcall AddStringList(TStringList* strings);
};
#endif
