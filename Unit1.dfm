object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Crack ISO 8583'
  ClientHeight = 524
  ClientWidth = 867
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
    Left = 24
    Top = 16
    Width = 249
    Height = 97
    Caption = 'Incoming'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 35
      Width = 56
      Height = 13
      Caption = 'IP Address:'
    end
    object Label2: TLabel
      Left = 16
      Top = 64
      Width = 24
      Height = 13
      Caption = 'Port:'
    end
    object EditLocalHostAddress: TEdit
      Left = 78
      Top = 34
      Width = 121
      Height = 21
      Alignment = taRightJustify
      TabOrder = 0
      Text = '0.0.0.0'
    end
    object EditLocalHostPort: TEdit
      Left = 78
      Top = 61
      Width = 121
      Height = 21
      Alignment = taRightJustify
      TabOrder = 1
      Text = '8000'
    end
  end
  object GroupBox2: TGroupBox
    Left = 296
    Top = 16
    Width = 257
    Height = 97
    Caption = 'Outgoing'
    TabOrder = 1
    object Label3: TLabel
      Left = 32
      Top = 35
      Width = 56
      Height = 13
      Caption = 'IP Address:'
    end
    object Label4: TLabel
      Left = 32
      Top = 64
      Width = 24
      Height = 13
      Caption = 'Port:'
    end
    object EditRemoteHostAddress: TEdit
      Left = 94
      Top = 34
      Width = 121
      Height = 21
      Alignment = taRightJustify
      TabOrder = 0
      Text = '127.0.0.1'
    end
    object EditRemoteHostPort: TEdit
      Left = 94
      Top = 61
      Width = 121
      Height = 21
      Alignment = taRightJustify
      TabOrder = 1
      Text = '8001'
    end
  end
  object Button1: TButton
    Left = 632
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 2
    OnClick = Button1Click
  end
  object RawDataDisplay: TRichEdit
    Left = 24
    Top = 128
    Width = 529
    Height = 161
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    HideScrollBars = False
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 3
    Zoom = 100
    OnChange = RawDataDisplayChange
  end
  object DecodedDataDisplay: TRichEdit
    Left = 24
    Top = 304
    Width = 529
    Height = 145
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    HideScrollBars = False
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 4
    Zoom = 100
    OnChange = DecodedDataDisplayChange
  end
  object MITMProxy: TIdMappedPortTCP
    Bindings = <
      item
        IP = '127.0.0.1'
        Port = 8000
      end>
    DefaultPort = 0
    OnConnect = MITMProxyConnect
    OnDisconnect = MITMProxyDisconnect
    OnBeforeConnect = MITMProxyBeforeConnect
    MappedPort = 0
    OnExecute = MITMProxyExecute
    OnOutboundData = MITMProxyOutboundData
    Left = 656
    Top = 168
  end
end
