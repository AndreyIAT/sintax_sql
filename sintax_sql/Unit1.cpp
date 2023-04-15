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
	if (OpenDialog1->Execute()) {
		try {
            TADOConnection* Connect = new TADOConnection(this);
			Connect->Connected = false;
			Connect->ConnectionString = "FILE NAME=" + OpenDialog1->FileName;
			Connect->Provider = OpenDialog1->FileName;
			Connect->Connected = true;

			TADOQuery* T_Query = new TADOQuery(this);
			T_Query->Connection = Connect;
			T_Query->SQL->Add("SELECT [name] FROM sys.objects WHERE type in (N'U')");
			T_Query->Active = true;
			while(!T_Query->Eof) {
				ComboBox2->Items->Add(T_Query->Fields->Fields[0]->AsString);
				T_Query->Next();
			}
			Label4->Caption = "Подключение прошло успешно!";
		} catch (...) {
            Label4->Caption = "Произошла ошибка!";
		}
	}
}
//---------------------------------------------------------------------------

