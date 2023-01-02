//---------------------------------------------------------------------------

#pragma hdrstop

#include "TTextToDisplay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TTextToDisplay::TTextToDisplay(TRichEdit* inputRichEdit) {
	workingRichEdit = inputRichEdit;
	lineToAdd = NULL;
	stringsToAdd = NULL;
}
TTextToDisplay::TTextToDisplay(TRichEdit* inputRichEdit, String str) {
	workingRichEdit = inputRichEdit;
	lineToAdd = str;
	stringsToAdd = NULL;
}
void __fastcall TTextToDisplay::AddSingleLine(String str)
{
	lineToAdd = str;
}
void __fastcall TTextToDisplay::AddStringList(TStringList* strings)
{
	stringsToAdd = strings;
}

void __fastcall TTextToDisplay::DoNotify(){
	
	if(NULL != workingRichEdit)
	{
			// Use the input parameters here...
		if (stringsToAdd)
			workingRichEdit->Lines->AddStrings(stringsToAdd);
		else if (lineToAdd != NULL) {
			workingRichEdit->Lines->Add(lineToAdd);
		}
	}
}
