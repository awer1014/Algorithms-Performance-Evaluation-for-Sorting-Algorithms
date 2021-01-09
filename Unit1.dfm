object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Performance Evaluation for Sorting Algorithms Made By W.R_Chen'
  ClientHeight = 582
  ClientWidth = 651
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 209
    Top = 0
    Height = 582
    ExplicitLeft = 88
    ExplicitTop = 240
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 209
    Height = 582
    Align = alLeft
    TabOrder = 0
    object GroupBox1: TGroupBox
      Left = 9
      Top = 8
      Width = 194
      Height = 153
      Caption = 'Input Control'
      TabOrder = 0
      object Label1: TLabel
        Left = 21
        Top = 32
        Width = 29
        Height = 13
        Caption = 'Time :'
      end
      object Label2: TLabel
        Left = 36
        Top = 78
        Width = 14
        Height = 13
        Caption = 'N :'
      end
      object Label3: TLabel
        Left = 12
        Top = 118
        Width = 38
        Height = 13
        BiDiMode = bdLeftToRight
        Caption = 'Range :'
        ParentBiDiMode = False
      end
      object Edit1: TEdit
        Left = 56
        Top = 29
        Width = 121
        Height = 21
        TabOrder = 0
        Text = '1'
      end
      object Edit2: TEdit
        Left = 56
        Top = 75
        Width = 121
        Height = 21
        TabOrder = 1
        Text = '10'
      end
      object Edit3: TEdit
        Left = 56
        Top = 115
        Width = 121
        Height = 21
        TabOrder = 2
        Text = '1000'
      end
    end
    object GroupBox2: TGroupBox
      Left = 9
      Top = 167
      Width = 194
      Height = 225
      Caption = 'Sort Type'
      TabOrder = 1
      object CheckBox1: TCheckBox
        Left = 21
        Top = 16
        Width = 97
        Height = 17
        Caption = 'Selection sort'
        TabOrder = 0
      end
      object CheckBox2: TCheckBox
        Left = 21
        Top = 39
        Width = 97
        Height = 17
        Caption = 'Insertion sort   '
        TabOrder = 1
      end
      object CheckBox3: TCheckBox
        Left = 21
        Top = 62
        Width = 97
        Height = 17
        Caption = 'Bubble sort'
        TabOrder = 2
      end
      object CheckBox4: TCheckBox
        Left = 21
        Top = 85
        Width = 170
        Height = 17
        Caption = 'Quick sort (recursive)'
        TabOrder = 3
      end
      object CheckBox5: TCheckBox
        Left = 21
        Top = 108
        Width = 156
        Height = 17
        Caption = 'Quick sort (non-recursive)'
        TabOrder = 4
      end
      object CheckBox6: TCheckBox
        Left = 21
        Top = 131
        Width = 170
        Height = 17
        Caption = 'Merge sort (recursive)'
        TabOrder = 5
      end
      object CheckBox7: TCheckBox
        Left = 21
        Top = 154
        Width = 170
        Height = 17
        Caption = 'Merge sort (non-recursive)'
        TabOrder = 6
      end
      object CheckBox8: TCheckBox
        Left = 21
        Top = 177
        Width = 156
        Height = 17
        Caption = 'Heap sort'
        TabOrder = 7
      end
      object CheckBox9: TCheckBox
        Left = 21
        Top = 200
        Width = 156
        Height = 17
        Caption = 'Radix sort'
        TabOrder = 8
      end
    end
    object CheckBox10: TCheckBox
      Left = 30
      Top = 402
      Width = 97
      Height = 17
      Caption = 'Print Data'
      Checked = True
      State = cbChecked
      TabOrder = 2
    end
    object Button1: TButton
      Left = 104
      Top = 398
      Width = 82
      Height = 25
      Caption = 'Start Sort'
      TabOrder = 3
      OnClick = Button1Click
    end
    object GroupBox3: TGroupBox
      Left = 9
      Top = 429
      Width = 194
      Height = 140
      Caption = 'Check'
      TabOrder = 4
      object Memo1: TMemo
        Left = 2
        Top = 15
        Width = 190
        Height = 123
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
  end
  object PageControl1: TPageControl
    Left = 212
    Top = 0
    Width = 439
    Height = 582
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Data'
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 431
        Height = 554
        Align = alClient
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
      end
    end
  end
end
