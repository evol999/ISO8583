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
	Display->SetFocus();
	Display->SelStart = Display->GetTextLen();
	Display->Perform(EM_SCROLLCARET, 0, 0);
}
//---------------------------------------------------------------------------

bool ReadMessageData(TIdBuffer *Buffer, int &Offset, TIdBytes &Data) {
	// has enough bytes?
	if ((Offset + 2) > Buffer->Size)
		return false;

	// read the length of the message from the first two bytes
	UInt16 binLength = Buffer->ExtractToUInt16(Offset);

	// converting from hex binary to hex string
	String bcdLength = String().sprintf(_D("%04hx"), binLength);

	// converting from hex string to int
	int calculated_length = bcdLength.ToInt() - 2;

	// has enough bytes?
	if ((Offset + 2 + calculated_length) > Buffer->Size)
		return false;

	// reads data
	Data.Length = calculated_length;
	Buffer->ExtractToBytes(Data, calculated_length, false, Offset + 2);

	Offset += (2 + calculated_length);
	return true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MITMProxyExecute(TIdContext *AContext)
{
	String sTemp;

	TIdBuffer *Buffer = static_cast<TIdBuffer*>(AContext->Data);
	Buffer->Write(static_cast<TIdMappedPortContext*>(AContext)->NetData);
	Buffer->CompactHead();

	TTextToDisplay *TextToDisplay = new TTextToDisplay;
	CDecoder *Decoder = new CDecoder();
	TStringList *slDecodedLines = NULL;
	TIdBytes ucBuffer;
	int offset = 0;
	while (ReadMessageData(Buffer, offset, ucBuffer)) {
		sTemp = String().sprintf(_D("%s"), ToHex(ucBuffer).c_str());
		slDecodedLines = Decoder->formatInput(sTemp);
		if(slDecodedLines)
		{
			TextToDisplay->AddStringList(slDecodedLines);
			TextToDisplay->Notify();
		}
	}

	// delete TextToDisplay;
	delete Decoder;
	delete slDecodedLines;

	if (offset > 0)
		Buffer->Remove(offset);


}
//---------------------------------------------------------------------------


