' Copy and paste into your program

CREATE FilePropertiesDlg AS QFORM
    Caption = "Properties"
    Width = 366
    Height = 316
    Center
    Parent=MainForm
    borderstyle=bsDialog
    CREATE FilePropertiesDlgTitleLabel AS QLABEL
        Caption = "Title"
        Left = 32
        Top = 16
    END CREATE
    CREATE FilePropertiesDlgAuthorLabel AS QLABEL
        Caption = "Author"
        Left = 32
        Top = 48
    END CREATE
    CREATE FilePropertiesDlgCommentsLabel AS QLABEL
        Caption = "Comments"
        Left = 32
        Top = 80
        Width = 52
        Transparent = 1
    END CREATE
    CREATE FilePropertiesDlgDefaultDirLabel AS QLABEL
        Caption = "Default Directory (relative to \Sounds)"
        Left = 32
        Top = 200
        Width = 180
    END CREATE
    CREATE FilePropertiesDlgTitle AS QEDIT
        Left = 88
        Top = 16
        Width = 249
        MaxLength = 64
    END CREATE
    CREATE FilePropertiesDlgAuthor AS QEDIT
        Text = ""
        Left = 88
        Top = 48
        Width = 249
        MaxLength = 64
        TabOrder = 1
    END CREATE
    CREATE FilePropertiesDlgComments AS QRICHEDIT
        Left = 88
        Top = 80
        Width = 249
        Height = 113
        PlainText = 1
        ScrollBars = 3
        TabOrder = 2
    END CREATE
    CREATE FilePropertiesDlgDefaultDir AS QEDIT
        Text = "Edit3"
        Left = 88
        Top = 216
        Width = 249
        TabOrder = 3
    END CREATE
    CREATE FilePropertiesDlgOKButton AS Qbutton
    cursor=crHandPoint
        Kind=bkOK
        Height=25
        Width=75
        Left = 184
        Top = 256
        Default=True
        onclick=FilePropertiesDlgOKButtonClicked
    END CREATE
    CREATE FilePropertiesDlgCancelButton AS Qbutton
        cursor=crHandPoint
        Kind=bkCancel
        Height=25
        Width=75
        Left = 264
        Top = 256
        
    END CREATE
END CREATE

sub LoadPropertiesFromFile
    SetStatus("Busy","Loading File Properties")
    FilePropertiesDlgTitle.Text=dfTitle
    FilePropertiesDlgAuthor.Text=dfAuthor
    FilePropertiesDlgComments.Text=dfComments
    FilePropertiesDlgDefaultDir.Text=dfDefaultDir
    SetStatus("Ready",)
end sub

sub SavePropertiesToFile
    SetStatus("Busy","Storing File Properties")
    dfTitle=FilePropertiesDlgTitle.Text
    dfAuthor=FilePropertiesDlgAuthor.Text
    dfComments=FilePropertiesDlgComments.Text
    dfDefaultDir=FilePropertiesDlgDefaultDir.Text
    SetStatus("Ready",)
end sub

sub FileProperties
    LoadPropertiesFromFile
    FilePropertiesDlg.ShowModal
end sub

sub FilePropertiesDlgOKButtonClicked
    SavePropertiesToFile
    FilePropertiesDlg.Close'
    if FileIsModified then StatusBar.Panel(1).Caption="Modified" else StatusBar.Panel(1).Caption=""
end sub
