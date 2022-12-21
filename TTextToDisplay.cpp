//---------------------------------------------------------------------------

#pragma hdrstop

#include "TTextToDisplay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TTextToDisplay::TTextToDisplay() {
	lineToAdd = NULL;
	stringsToAdd = NULL;
}
TTextToDisplay::TTextToDisplay(String str) {
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

void __fastcall TTextToDisplay::DoSynchronize(){
			// Use the input parameters here...
		if (stringsToAdd)
			Form1->Display->Lines->AddStrings(stringsToAdd);
		else if (lineToAdd != NULL) {
			Form1->Display->Lines->Add(lineToAdd);
		}
}
