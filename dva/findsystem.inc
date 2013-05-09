dim Position as integer

create SearchFindDlg as qform

BorderStyle = bsDialog
Caption = "Find"
Width = 300
Height = 110
Center
	create SearchFindEdit as qedit
  		Top = 15
  		Left = 20
  		Width = 170
	end create
  create SearchFindButton AS QButton
  	OnClick = FindText
	kind=bkRetry
  	Caption = "&Find"
  	Top = 13
  	Left = 210
      Default=True
	cursor=crHandPoint
  end create
  create SearchFindCancelButton as qbutton
      kind=bkCancel
      left=210
      top=50
      cursor=crHandPoint
  end create
end create

CREATE ReplaceDlg AS QFORM
    Caption = "Replace"
    Width = 388
    Height = 120
    Center
    BorderStyle=bsDialog
    CREATE ReplaceDlgLabel1 AS QLABEL
        Caption = "Replace:"
        Left = 16
        Top = 16
        Width = 48
    END CREATE
    CREATE ReplaceDlgLabel2 AS QLABEL
        Caption = "With:"
        Left = 16
        Top = 48
    END CREATE
    CREATE ReplaceDlgEdit1 AS QEDIT
        Left = 64
        Top = 16
        Width = 217
	Text=""
    END CREATE
    CREATE ReplaceDlgEdit2 AS QEDIT
        Left = 64
        Top = 48
        Width = 217
        TabOrder = 1
	Text=""
    END CREATE
    CREATE ReplaceDlgOKButton AS QBUTTON
        Left = 296
        Top = 16
        TabOrder = 2
        Default = 1
        Kind=bkOK
        OnClick=ReplaceDlgOKButtonClick
	cursor=crHandPoint
    END CREATE
    CREATE ReplaceDlgCancelButton AS QBUTTON
        Kind=bkCancel
        Left = 296
        Top = 48
        TabOrder = 3
	cursor=crHandPoint
    END CREATE
END CREATE




SUB SearchFind:SearchFindDlg.ShowModal:END SUB
sub SearchReplace:if RichEdit.SelLength then ReplaceDlgEdit1.Text=RichEdit.SelText
ReplaceDlg.ShowModal:end sub
sub ReplaceDlgOKButtonClick
    ReplaceText (ReplaceDlgEdit1.Text,ReplaceDlgEdit2.Text)
    ReplaceDlg.Close
end sub

SUB FindText   '' Primitive search...
    SetStatus("Busy","Finding Text")
  Position=0
  RichEdit.SelStart = INSTR(UCASE$(RichEdit.Text), UCASE$(SearchFindEdit.Text))-1
  IF INSTR(UCASE$(RichEdit.Text), UCASE$(SearchFindEdit.Text)) > 0 THEN
    
    RichEdit.SelLength = LEN(SearchFindEdit.Text)
    Position=RichEdit.SelStart+RichEdit.SelLength
    SearchFindDlg.Close
    SearchFindNextMenu.Enabled=True
    SetStatus("Ready",)
  ELSE
    SearchFindNextMenu.Enabled=False
    SetStatus("Ready",)
    SHOWMESSAGE "'"+SearchFindEdit.Text+"' not found."
  END IF
  
END SUB

sub SearchFindNext
    SetStatus("Busy","Finding Text")
    RichEdit.SelStart = INSTR(UCASE$(RIGHT$(RichEdit.Text,LEN(RichEdit.Text)-Position)), UCASE$(SearchFindEdit.Text))-1+Position
  IF INSTR(UCASE$(RIGHT$(RichEdit.Text,Len(RichEdit.Text)-Position)), UCASE$(SearchFindEdit.Text)) > 0 THEN
    
    RichEdit.SelLength = LEN(SearchFindEdit.Text)
    Position=RichEdit.SelStart+RichEdit.SelLength
    SearchFindDlg.Close
    SetStatus("Ready",)
  ELSE
    SearchFindNextMenu.Enabled=False
    SetStatus("Ready",)
    SHOWMESSAGE "'"+SearchFindEdit.Text+"' not found."
  END IF
end sub
  
sub ReplaceText(ReplaceFrom as string, ReplaceTo as string)
    SetStatus("Busy","Replacing Text")
  Position=0
  if instr(ucase$(RichEdit.Text), ucase$(ReplaceFrom)) =0 then
      SetStatus("Ready",)
	showmessage "'"+ReplaceFrom+"' not found."
  else
    do
	RichEdit.SelStart = INSTR(UCASE$(RIGHT$(RichEdit.Text,LEN(RichEdit.Text)-Position)), UCASE$(ReplaceFrom))-1+Position
	RichEdit.SelLength=len(ReplaceFrom)
	RichEdit.SelText=ReplaceTo
    loop until instr(ucase$(right$(RichEdit.Text,Len(RichEdit.Text)-Position)), ucase$(ReplaceFrom))=0
    SetStatus("Ready",)
    showmessage"'"+ReplaceFrom+"' replaced with '"+ReplaceTo+"'." 
  end if
end sub