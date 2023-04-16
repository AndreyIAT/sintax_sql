//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

const int _i = 50;
const int _j = 50;
AnsiString table_column[_i][_j];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

// запрос получени€ списка таблиц
AnsiString query_get_table() {
	if (Form1->ComboBox1->ItemIndex == 0) {
		return "SELECT [name] FROM sys.objects WHERE type in (N'U')";
	} else {
		return "SELECT table_name AS name FROM information_schema.tables WHERE table_schema = 'public'";
    }
}

// запрос получени€ списка колонок
AnsiString query_get_columns(AnsiString name_t) {
	if (Form1->ComboBox1->ItemIndex == 0) {
		return "SELECT COLUMN_NAME AS [name_c] FROM INFORMATION_SCHEMA.COLUMNS WHERE table_name='" + name_t + "'";
	} else {
		return "SELECT column_name AS name_c FROM information_schema.columns WHERE table_schema = 'public' AND table_name = '" + name_t + "'";
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int i,j;
	// обнуление массива наименований таблиц и колонок
	for (i = 0; i < _i; i++)
		for (j = 0; j < _j; j++)
			table_column[i][j] = "";
	i = 0;
	j = 0;

    if (ComboBox1->ItemIndex == -1) {
		Label4->Caption = "¬ыберите —”Ѕƒ!";
		return;
	}

	if (OpenDialog1->Execute()) {
		try {
			// подключение к Ѕƒ
            TADOConnection* Connect = new TADOConnection(this);
			Connect->Connected = false;
			Connect->ConnectionString = "FILE NAME=" + OpenDialog1->FileName;
			Connect->Provider = OpenDialog1->FileName;
			Connect->Connected = true;

			// получаем список таблиц
			TADOQuery* T_Query = new TADOQuery(this);
			T_Query->Connection = Connect;
			T_Query->SQL->Add(query_get_table());
			T_Query->Active = true;

			TADOQuery* C_Query = new TADOQuery(this);
			C_Query->Connection = Connect;

			while(!T_Query->Eof) {

				AnsiString name_t = T_Query->Fields->Fields[0]->AsString;
				ComboBox2->Items->Add(name_t);
				table_column[i][0] = name_t;
				T_Query->Next();

				// получаем список колонок текущей таблицы
				C_Query->Active = false;
				C_Query->SQL->Clear();
				C_Query->SQL->Add(query_get_columns(name_t));
				C_Query->Active = true;

				j = 1;

				// заполн€ем массив наименовани€ми колонок
				while(!C_Query->Eof) {
					AnsiString name_c = C_Query->Fields->Fields[0]->AsString;
					table_column[i][j] = name_c;
					C_Query->Next();
					j++;
					if (j >= _j) {
                        break;
					}
				}
				i++;
				if (i >= _i) {
					break;
				}
			}
			Label4->Caption = "ѕодключение прошло успешно!";
		} catch (...) {
            Label4->Caption = "ѕроизошла ошибка!";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
    // заполн€ем списки полей именами колонок из массива
	CheckListBox1->Items->Clear();
    CheckListBox2->Items->Clear();
	int i,j;
	bool _exit = false;
	for (i = 0; i < _i; i++) {
		if(table_column[i][0] == ComboBox2->Text) {
			for (j = 1; j < _j; j++)
				if (table_column[i][j] == "") {
					_exit = true;
					break;
				} else {
					CheckListBox1->Items->Add(table_column[i][j]);
					CheckListBox2->Items->Add(table_column[i][j]);
                }
		}
		if (_exit == true) {
            break;
		}
	}
}
//---------------------------------------------------------------------------

void building_select()
{
	AnsiString _query = "";
	// перечисление выводимых полей
	for (int i = 0; i < Form1->CheckListBox1->Items->Count; i++) {
		if (Form1->CheckListBox1->Checked[i] == true) {
			_query = _query + Form1->CheckListBox1->Items->Strings[i] + ", ";
		}
	}

	if (_query.Length() > 0) {
		_query = "SELECT " + _query.SubString(0, _query.Length() - 2);
		Form1->Memo1->Lines->Add(_query);
		_query = "";

		// указание таблицы
        _query = "FROM " + Form1->ComboBox2->Text;
		Form1->Memo1->Lines->Add(_query);
		_query = "";

		// перечисление полей отбора
		int j = 0;
		for (int i = 0; i < Form1->CheckListBox2->Items->Count; i++) {
			if (Form1->CheckListBox2->Checked[i] == true) {
				j++;
				_query = _query + Form1->CheckListBox1->Items->Strings[i] + " = 'parametr" + IntToStr(j) + "' AND ";
			}
		}

		if (_query.Length() > 0) {
			_query = "WHERE " + _query.SubString(0, _query.Length() - 5);
			Form1->Memo1->Lines->Add(_query);
		}

	}
}

void building_insert()
{
	AnsiString _query = "";

	// перечисление полей вставки
	int j = 0;
	for (int i = 0; i < Form1->CheckListBox1->Items->Count; i++) {
		if (Form1->CheckListBox1->Checked[i] == true) {
			j++;
			_query = _query + Form1->CheckListBox1->Items->Strings[i] + ", ";
		}
	}

	if (_query.Length() > 0) {
		_query = "INSERT INTO " + Form1->ComboBox2->Text + " (" + _query.SubString(0, _query.Length() - 2) + ")";
		Form1->Memo1->Lines->Add(_query);
		_query = "";

		// перечисление значений
		for (int i = 0; i < j; i++) {
			_query = _query + "'values" + IntToStr(i) + "', ";
		}
		if (_query.Length() > 0) {
			_query = "VALUES (" + _query.SubString(0, _query.Length() - 2) + ")";
			Form1->Memo1->Lines->Add(_query);
        }
	}
}

void building_update()
{
	AnsiString _query = "";
	// перечисление обновл€емых полей
	int j = 0;
	for (int i = 0; i < Form1->CheckListBox1->Items->Count; i++) {
		if (Form1->CheckListBox1->Checked[i] == true) {
			j++;
			_query = _query + Form1->CheckListBox1->Items->Strings[i] + " = 'values" + IntToStr(j) + "', ";
		}
	}

	if (_query.Length() > 0) {
		// указание таблицы
		Form1->Memo1->Lines->Add("UPDATE " + Form1->ComboBox2->Text);

		_query = "SET " + _query.SubString(0, _query.Length() - 2);
		Form1->Memo1->Lines->Add(_query);
		_query = "";

		// перечисление полей отбора
		j = 0;
		for (int i = 0; i < Form1->CheckListBox2->Items->Count; i++) {
			if (Form1->CheckListBox2->Checked[i] == true) {
				j++;
				_query = _query + Form1->CheckListBox1->Items->Strings[i] + " = 'parametr" + IntToStr(j) + "' AND ";
			}
		}

		if (_query.Length() > 0) {
			_query = "WHERE " + _query.SubString(0, _query.Length() - 5);
			Form1->Memo1->Lines->Add(_query);
		}
	}
}

void building_delete()
{
	// перечисление полей отбора
	AnsiString _query = "";
	int j = 0;
	for (int i = 0; i < Form1->CheckListBox2->Items->Count; i++) {
		if (Form1->CheckListBox2->Checked[i] == true) {
			j++;
			_query = _query + Form1->CheckListBox1->Items->Strings[i] + " = 'parametr" + IntToStr(j) + "' AND ";
		}
	}

	if (_query.Length() > 0) {
		Form1->Memo1->Lines->Add("DELETE FROM " + Form1->ComboBox2->Text);
		_query = "WHERE " + _query.SubString(0, _query.Length() - 5);
		Form1->Memo1->Lines->Add(_query);
	}
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	// формируем запрос

	Memo1->Lines->Clear();

	if (ComboBox2->ItemIndex == -1 || ComboBox3->ItemIndex == -1) {
		return;
	}

	if (ComboBox3->ItemIndex == 0) {
		building_select();
	}

	if (ComboBox3->ItemIndex == 1) {
		building_insert();
	}

	if (ComboBox3->ItemIndex == 2) {
		building_update();
	}

	if (ComboBox3->ItemIndex == 3) {
		building_delete();
	}
}
//---------------------------------------------------------------------------

