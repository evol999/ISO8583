//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (!MITMProxy->Active) {
		// Prepares the client side that goes to the server
		MITMProxy->MappedHost = Form1->EditRemoteHostAddress->Text;
		MITMProxy->MappedPort = Form1->EditRemoteHostPort->Text.ToInt();

		// Prepares the host side that receive messages from the client
		MITMProxy->DefaultPort = Form1->EditLocalHostPort->Text.ToInt();
		MITMProxy->Active = True;
		Button1->Caption = "Stop";
	}
	else {
		MITMProxy->Active = False;
		Button1->Caption = "Start";

	}
}
//---------------------------------------------------------------------------

