//---------------------------------------------------------------------------

#ifndef TTextToDisplayH
#define TTextToDisplayH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <IdSync.hpp>
#include "Unit1.h"
class TTextToDisplay : public TIdSync {
private:
	String lineToAdd;
	TStringList* stringsToAdd;

protected:
	virtual void __fastcall DoSynchronize();

public:
	__fastcall TTextToDisplay();
	void __fastcall AddSingleLine(String str);
	void __fastcall AddStringList(TStringList* strings);
};
#endif
