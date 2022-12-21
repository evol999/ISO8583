//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "TTextToDisplay.h"
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

void __fastcall TForm1::MITMProxyBeforeConnect(TIdContext *AContext)
{
	String tempStr;

	// displaying remote address.
	tempStr = "Received connection from " +
		AContext->Connection->Socket->Binding->PeerIP;
	TTextToDisplay *TextToDisplay = new TTextToDisplay(tempStr);
	TextToDisplay->Notify();
	// delete TextToDisplay;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::MITMProxyDisconnect(TIdContext *AContext)
{
	String tempStr;

	// displaying remote address.
	tempStr = "Client disconnected"; TTextToDisplay *TextToDisplay =
		new TTextToDisplay(tempStr); TextToDisplay->Notify();
	// delete TextToDisplay;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MITMProxyConnect(TIdContext *AContext)
{
	String tempStr;

	// displaying remote address.
	tempStr = "Attempting to connect to the remote server " +
		MITMProxy->MappedHost + ":" + MITMProxy->MappedPort;
	TTextToDisplay *TextToDisplay = new TTextToDisplay(tempStr);
	TextToDisplay->Notify();
	// delete TextToDisplay;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DisplayChange(TObject *Sender)
{
	Display->SelStart = Display->GetTextLen(); Display->Perform(EM_SCROLLCARET,
		0, 0);
}
//---------------------------------------------------------------------------

