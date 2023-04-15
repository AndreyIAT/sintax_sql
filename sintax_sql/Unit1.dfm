object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 551
  ClientWidth = 591
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 591
    Height = 97
    Align = alTop
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object ComboBox1: TComboBox
      Left = 16
      Top = 23
      Width = 161
      Height = 24
      TabOrder = 0
      TextHint = #1042#1099#1073#1077#1088#1080#1090#1077' '#1057#1059#1041#1044
      Items.Strings = (
        'SQL Server'
        'PostgreSQL')
    end
    object Edit1: TEdit
      Left = 192
      Top = 23
      Width = 209
      Height = 24
      TabOrder = 1
      TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1080#1084#1103' '#1089#1077#1088#1074#1077#1088#1072
    end
    object Edit2: TEdit
      Left = 16
      Top = 59
      Width = 161
      Height = 24
      TabOrder = 2
      TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1080#1084#1103' '#1041#1044
    end
    object Edit3: TEdit
      Left = 192
      Top = 59
      Width = 129
      Height = 24
      TabOrder = 3
      TextHint = #1048#1084#1103' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    end
    object Edit4: TEdit
      Left = 336
      Top = 59
      Width = 129
      Height = 24
      PasswordChar = '*'
      TabOrder = 4
      TextHint = #1055#1072#1088#1086#1083#1100
    end
    object Button1: TButton
      Left = 471
      Top = 59
      Width = 106
      Height = 25
      Caption = #1055#1086#1076#1082#1083#1102#1095#1080#1090#1100#1089#1103
      TabOrder = 5
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 97
    Width = 591
    Height = 454
    Align = alClient
    Caption = #1057#1086#1089#1090#1072#1074#1083#1077#1085#1080#1077' '#1079#1072#1087#1088#1086#1089#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    ExplicitTop = 168
    ExplicitWidth = 699
    ExplicitHeight = 472
    object Label1: TLabel
      Left = 16
      Top = 66
      Width = 88
      Height = 16
      Caption = #1055#1086#1083#1103' '#1074#1099#1073#1086#1088#1082#1080':'
    end
    object Label2: TLabel
      Left = 320
      Top = 66
      Width = 125
      Height = 16
      Caption = #1055#1086#1083#1103' '#1086#1090#1073#1086#1088#1072' WHERE:'
    end
    object ComboBox2: TComboBox
      Left = 16
      Top = 32
      Width = 145
      Height = 24
      TabOrder = 0
      TextHint = #1042#1099#1073#1077#1088#1080#1090#1077' '#1090#1072#1073#1083#1080#1094#1091
    end
    object ComboBox3: TComboBox
      Left = 176
      Top = 32
      Width = 161
      Height = 24
      TabOrder = 1
      TextHint = #1042#1099#1073#1077#1088#1080#1090#1077' '#1082#1086#1084#1072#1085#1076#1091
    end
    object CheckListBox1: TCheckListBox
      Left = 16
      Top = 88
      Width = 281
      Height = 201
      TabOrder = 2
    end
    object CheckListBox2: TCheckListBox
      Left = 320
      Top = 88
      Width = 257
      Height = 201
      TabOrder = 3
    end
    object Memo1: TMemo
      Left = 16
      Top = 304
      Width = 561
      Height = 137
      TabOrder = 4
    end
    object Button2: TButton
      Left = 352
      Top = 32
      Width = 225
      Height = 25
      Caption = #1057#1086#1089#1090#1072#1074#1080#1090#1100' '#1079#1072#1087#1088#1086#1089
      TabOrder = 5
    end
  end
end
