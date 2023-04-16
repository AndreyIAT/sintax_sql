//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.CheckLst.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TComboBox *ComboBox2;
	TComboBox *ComboBox3;
	TCheckListBox *CheckListBox1;
	TLabel *Label1;
	TCheckListBox *CheckListBox2;
	TLabel *Label2;
	TMemo *Memo1;
	TButton *Button2;
	TOpenDialog *OpenDialog1;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};

void building_select();
void building_insert();
void building_update();
void building_delete();
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
