//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdMappedPortTCP.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdContext.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TEdit *EditLocalHostAddress;
	TEdit *EditLocalHostPort;
	TGroupBox *GroupBox2;
	TEdit *EditRemoteHostAddress;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *EditRemoteHostPort;
	TButton *Button1;
	TRichEdit *RawDataDisplay;
	TIdMappedPortTCP *MITMProxy;
	TRichEdit *DecodedDataDisplay;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall MITMProxyBeforeConnect(TIdContext *AContext);
	void __fastcall MITMProxyDisconnect(TIdContext *AContext);
	void __fastcall MITMProxyConnect(TIdContext *AContext);
	void __fastcall MITMProxyExecute(TIdContext *AContext);
	void __fastcall RawDataDisplayChange(TObject *Sender);
	void __fastcall DecodedDataDisplayChange(TObject *Sender);
	void __fastcall MITMProxyOutboundData(TIdContext *AContext);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
