//---------------------------------------------------------------------------

#ifndef TTextToDisplayH
#define TTextToDisplayH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <IdSync.hpp>
#include "Unit1.h"
class TTextToDisplay : public TIdNotify {
private:
	TRichEdit* workingRichEdit;
	String lineToAdd;
	TStringList* stringsToAdd;

protected:
	virtual void __fastcall DoNotify();

public:
	// it's mandatory now to explicitly define the destination TRichEdit
	__fastcall TTextToDisplay(TRichEdit* inputRichEdit);
	__fastcall TTextToDisplay(TRichEdit* inputRichEdit, String str);
	void __fastcall AddSingleLine(String str);
	void __fastcall AddStringList(TStringList* strings);
};
#endif
