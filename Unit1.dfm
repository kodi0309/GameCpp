object KodiGame: TKodiGame
  Left = 520
  Top = 248
  BorderStyle = bsDialog
  Caption = 'KodiGame'
  ClientHeight = 641
  ClientWidth = 1278
  Color = clGrayText
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Board: TShape
    Left = 100
    Top = 20
    Width = 600
    Height = 600
    Cursor = crCross
    Brush.Color = clMoneyGreen
    OnMouseMove = BoardMouseMove
  end
  object Rocket: TShape
    Left = 248
    Top = 588
    Width = 100
    Height = 20
    Cursor = crCross
    Brush.Color = clSkyBlue
    OnMouseMove = RocketMouseMove
  end
  object Info: TLabel
    Left = 704
    Top = 72
    Width = 3
    Height = 13
  end
  object GameName: TLabel
    Left = 780
    Top = 46
    Width = 424
    Height = 112
    Caption = 'KodiGame'
    Color = clGrayText
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -96
    Font.Name = 'Consolas'
    Font.Style = [fsItalic, fsUnderline]
    ParentColor = False
    ParentFont = False
  end
  object BallCounter: TLabel
    Left = 780
    Top = 176
    Width = 196
    Height = 30
    Caption = 'Active Balls: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 30
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
  end
  object Hell: TShape
    Left = 100
    Top = 620
    Width = 600
    Height = 30
    Brush.Color = clRed
  end
  object Rules: TLabel
    Left = 780
    Top = 270
    Width = 279
    Height = 20
    Caption = 'Try to hit the green rectangle.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = 20
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 780
    Top = 232
    Width = 84
    Height = 30
    Caption = 'Rules:'
    Color = clGrayText
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = 30
    Font.Name = 'Consolas'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 780
    Top = 300
    Width = 369
    Height = 20
    Caption = 'After hitting it, a new ball will appear.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = 20
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 780
    Top = 330
    Width = 450
    Height = 20
    Caption = 'Try to keep as many balls in the game as possible!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clYellow
    Font.Height = 20
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
  end
  object TopScoreInf: TLabel
    Left = 780
    Top = 440
    Width = 209
    Height = 40
    Caption = 'Top Score: '
    Color = clCaptionText
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clTeal
    Font.Height = 40
    Font.Name = 'Consolas'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object PlayAgain: TButton
    Left = 780
    Top = 512
    Width = 424
    Height = 89
    Caption = 'In the game!'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 30
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = PlayAgainClick
  end
  object Timer1: TTimer
    Interval = 10
    OnTimer = Timer1Timer
    Left = 720
    Top = 8
  end
end
