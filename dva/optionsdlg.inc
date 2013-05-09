Create OptionsPrefTreeViewImages as qimagelist
AddICOFile AppDir+"images\options.ico"
AddICOFile AppDir+"images\locations.ico"
AddICOFile AppDir+"images\appearance.ico"
AddICOFile AppDir+"images\shell.ico"
end create
CREATE OptionsPreferencesDlg AS QFORM
    Caption = "Preferences"
    Width = 658
    Height = 375
    BorderStyle=bsDialog
    'Parent=MainForm
    CREATE OptionsPreferencesDlgInfoLabel AS QLABEL
        Caption = "Please select one of the following pages:"
        Left = 15
        Top = 7
        Width = 200
    END CREATE
    create PrefTreeView as qtreeview
        Readonly=True
        left=8
        top=28
        width=200
        height=305
        ShowHint=False
        onchange=TreeViewChange
        AddItems "Options"
        AddChildItems 0,"Locations","Appearance","Shell"
        FullExpand
        stateimages=OptionsPrefTreeViewImages
        Item(0).StateIndex=0
        Item(1).StateIndex=1
        Item(2).StateIndex=2
        Item(3).StateIndex=3
    end create
    CREATE SplitPanel AS QPANEL
        Left = 218
        Top = 28
        Width = 3
        Height = 305
        BevelInner = 1
        BevelOuter = 0
        BorderStyle = 1
    END CREATE
    create OptionsPreferencesDlgOKButton as qbutton
        kind=bkOK
        left=478
        top=320
        onclick=OptionsPreferencesDlgOKButtonClicked
        'default=True
        cursor=crHandPoint
        default=true
    end create
    create OptionsPreferencesDlgCancelButton as qbutton
        Kind=bkCancel
        left=560
        top=320
        cursor=crHandPoint
    end create
    create BlankPanel as qpanel
        left=228
        top=28
        width=410
        height=280
        bevelouter=bvNone
        caption="Please select one of the items on the left."
    end create
END CREATE

dim PreviousToolbarSettingLarge as integer, PreviousToolbarSettingFlat as integer

create OptionsPageHeaderFont as qfont:size=16:AddStyles fsBold:end create
'--------------------- Blank Options Panel
create OptionsPage as qpanel:BevelOuter=bvNone:Visible=False:Left=228:Top=28:Width=410:Height=280:Parent=OptionsPreferencesDlg:Caption="Please select one of the items on the left.":end create
'--------------------- Directories Panel
create OptionsLocationsPage as qpanel
        BevelOuter=bvNone:Visible=False:Left=228:Top=28:Width=410:Height=280:Parent=OptionsPreferencesDlg
        create OptionsLocationsPicture as qimage:ICOn=AppDir+"images\locations.ico":end create
        create OptionsLocationsPageHeader as qlabel:font=OptionsPageHeaderFont:caption="Locations":top=5:left=41:end create
        create OptionsLocationsSoundsDirTreeHeader as qlabel:top=58:left=1:caption="Please select the sounds directory...":end create 
        CREATE OptionsLocationsSoundsDirTree AS Qdirtree:Left = 1:Top = 73:Width = 190:Height = 137:ReadOnly=True:END CREATE
        create OptionsLocationsSourcesDirTreeHeader as qlabel:top=58:left=200:caption="...and the sources directory...":end create
        CREATE OptionsLocationsSourcesDirTree AS Qdirtree:Left = 200:Top = 73:Width = 190:Height = 137:ReadOnly=True:END CREATE
        create OptionsLocationsPrintOutputEditHeader as qlabel:top=230:left=1:caption="...and finally the print output location (printer, file or device)":end create
        create OptionsLocationsPrintOutputEdit as qedit:top=245:left=1:Width=390:end create
end create
'--------------------- Appearance Panel
showmessage
create OptionsAppearancePage as qpanel
        BevelOuter=bvNone:Visible=False:Left=228:Top=28:Width=410:Height=280:Parent=OptionsPreferencesDlg
        create OptionsAppearancePicture as qimage:ICOn=AppDir+"images\appearance.ico":end create
        create OptionsAppearancePageHeader as qlabel:font=OptionsPageHeaderFont:caption="Appearance":top=5:left=41:end create
        create OptionsAppearanceSplashScreenOnStartup as qcheckbox:top=55:left=1:width=200:caption="Show splash screen on startup":end create
        create OptionsAppearanceToolbar as qcheckbox:top=80:left=1:width=200:caption="Show toolbar":onclick=OptionsAppearanceToolbarChanged:end create
        create OptionsAppearanceLargeToolbarButtons as qcheckbox:top=100:left=15:width=200:caption="Large Toolbar Buttons":end create
        create OptionsAppearanceFlatToolbarButtons as qcheckbox:top=120:left=15:width=200:caption="Flat Toolbar Buttons":end create
        create OptionsAppearanceFontPanel as qpanel:bevelinner=bvNone:bevelouter=bvLowered:color=&HFFFFFF:caption="Sample Text":top=235:left=1:height=40:width=300:end create
        create OptionsAppearanceFontChangeButton as qbutton:cursor=crHandPoint:caption="Change...":top=235:left=310:onclick=OptionsAppearanceFontChangeButtonClicked:end create
        create OptionsAppearanceSoundOnStartup as qcheckbox:top=145:left=1:width=200:caption="Play sound on startup":end create
        create OptionsAppearanceFullScreen as qcheckbox:top=170:left=1:width=200:caption="Full screen":end create
        create OptionsAppearanceRememberWindowPosition as qcheckbox:top=195:left=1:width=200:caption="Remember window positions":end create
end create
'--------------------- Shell Panel
create OptionsShellPage as qpanel
        BevelOuter=bvNone:Visible=False:Left=228:Top=28:Width=410:Height=280:Parent=OptionsPreferencesDlg
        create OptionsShellPicture as qimage:ICOn=AppDir+"images\shell.ico":end create
        create OptionsShellPageHeader as qlabel:font=OptionsPageHeaderFont:caption="Shell":top=5:left=41:end create
        CREATE OptionsShellActionHeader AS QLABEL:Caption = "Default Shell Action:":Left = 0:Top = 46:Width = 176:END CREATE
        CREATE OptionsShellActionOpen AS QRADIOBUTTON:Caption = "Open file for editing.":Left = 32:Top = 70:END CREATE
        CREATE OptionsShellActionPlay AS QRADIOBUTTON:Caption = "Play File.":Left = 32:Top = 94:TabOrder = 1:END CREATE
        CREATE OptionsShellActionCompile AS QRADIOBUTTON:Caption = "Compile File.":Left = 32:Top = 118:TabOrder = 2:END CREATE
    

end create



'---------------------- QTreeview.OnChange EventProc
sub TreeViewChange '(Node as integer, Sender as qtreeview)
OptionsPage.Visible=False
OptionsLocationsPage.visible=False
OptionsAppearancePage.Visible=False
OptionsShellPage.Visible=False
select case Node+1
    case 1:OptionsPage.Visible=True
    case 2:OptionsLocationsPage.Visible=True
    case 3:OptionsAppearancePage.visible=True
    case 4:OptionsShellPage.Visible=True
end select
end sub
'---------------------- QCheckBox.OnChange EventProc
sub OptionsAppearanceToolbarChanged
if OptionsAppearanceToolbar.Checked=False then
    OptionsAppearanceLargeToolbarButtons.Enabled=False
    OptionsAppearanceFlatToolbarButtons.Enabled=False
else
    OptionsAppearanceLargeToolbarButtons.Enabled=True
    OptionsAppearanceFlatToolbarButtons.Enabled=True
end if:end sub
'----------------------- SaveOptions Code 
sub SaveOptions
SetStatus("Busy","Storing Options")
PreviousToolbarSettingLarge=DVAReg.ReadInteger("ToolbarSize"):PreviousToolbarSettingFlat=DVAReg.ReadInteger("ToolbarFlat")
DVAReg.WriteString("SoundsDir",OptionsLocationsSoundsDirTree.Directory)
DVAReg.WriteString("SourceDir",OptionsLocationsSourcesDirTree.Directory)
DVAReg.WriteString("PrintOutput",OptionsLocationsPrintOutputEdit.Text)
DVAReg.WriteInteger("SplashScreen",OptionsAppearanceSplashScreenOnStartup.Checked)
DVAReg.WriteInteger("ToolbarVisible",OptionsAppearanceToolbar.Checked)
DVAReg.WriteInteger("ToolbarSize",OptionsAppearanceLargeToolbarButtons.Checked)
DVAReg.WriteInteger("ToolbarFlat",OptionsAppearanceFlatToolbarButtons.Checked)
DVAReg.WriteInteger("StartupSound",OptionsAppearanceSoundOnStartup.Checked)
DVAReg.WriteInteger("FullScreen",OptionsAppearanceFullScreen.Checked)
DVAReg.WriteInteger("RememberWindowPosition",OptionsAppearanceRememberWindowPosition.Checked)
DVAReg.WriteString("FontName",EditFont.Name)
DVAReg.WriteInteger("FontSize",EditFont.Size)
If OptionsAppearanceFullScreen.Checked=1 then
    if not IsFullScreen then SwitchToFullScreen
    ViewFullScreenMenu.Checked=1
else
    if IsFullScreen then SwitchFromFullScreen
    ViewFullScreenMenu.Checked=0
end if
RichEdit.Font=EditFont
'DVAReg.WriteInteger("FontColour",EditFont.Color)
if PreviousToolbarSettingLarge<>OptionsAppearanceLargeToolbarButtons.Checked or PreviousToolbarSettingFlat<>OptionsAppearanceFlatToolbarButtons.Checked then showmessage("You will need to restart DVA to update toolbar settings.")
    if OptionsShellActionOpen.Checked then
        AssnReg.OpenKey("\MVA.Source\shell",1)
        AssnReg.WriteString(,"Open")
        AssnReg.OpenKey("\DVA.Source\shell",1)
        AssnReg.WriteString(,"Open")
    elseif OptionsShellActionPlay.Checked then
        AssnReg.OpenKey("\MVA.Source\shell",1)
        AssnReg.WriteString(,"Play")
        AssnReg.OpenKey("\DVA.Source\shell",1)
        AssnReg.WriteString(,"Play")
    elseif OptionsShellActionCompile.Checked then
        AssnReg.OpenKey("\MVA.Source\shell",1)
        AssnReg.WriteString(,"Compile")
        AssnReg.OpenKey("\DVA.Source\shell",1)
        AssnReg.WriteString(,"Compile")
    end if
if OptionsAppearanceToolbar.Checked then
        flip.visible=True:Toolbar.Visible=True:SplitterMoved
    else
        flip.visible=False:Toolbar.Visible=False:SplitterMoved
    end if
SetStatus("Ready",)
end sub
'----------------------- LoadOptions Code
sub LoadOptions
SetStatus("Busy","Retrieving Options")
OptionsLocationsSoundsDirTree.Directory=AppDir+"Sounds\"
OptionsLocationsSourcesDirTree.Directory=AppDir+"Sources\"
OptionsLocationsPrintOutputEdit.Text=DVAReg.ReadString("PrintOutput")
OptionsAppearanceSplashScreenOnStartup.Checked=DVAReg.ReadInteger("SplashScreen")
OptionsAppearanceToolbar.Checked=DVAReg.ReadInteger("ToolbarVisible")
OptionsAppearanceLargeToolbarButtons.Checked=DVAReg.ReadInteger("ToolbarSize")
OptionsAppearanceFlatToolbarButtons.Checked=DVAReg.ReadInteger("ToolbarFlat")
OptionsAppearanceSoundOnStartup.Checked=DVAReg.ReadInteger("StartupSound")
OptionsAppearanceFullScreen.Checked=DVAReg.ReadInteger("FullScreen")
OptionsAppearanceRememberWindowPosition.Checked=DVAReg.ReadInteger("RememberWindowPosition")
EditFont.Name=DVAReg.ReadString("FontName")
EditFont.Size=DVAReg.ReadInteger("FontSize")
OptionsAppearanceFontPanel.Font=EditFont
AssnReg.OpenKey("\DVA.Source\shell",0)
If AssnReg.ReadString()="Compile" then
    OptionsShellActionCompile.Checked=True
elseif AssnReg.ReadString()="Play" then
    OptionsShellActionPlay.Checked=True
else
    OptionsShellActionOpen.Checked=True
end if    
OptionsAppearanceToolbarChanged
SetStatus("Ready",)
end sub
'----------------------- Options Constructors
sub OptionsPreferences
if DVAReg.ReadInteger("RememberWindowPosition")=1 then
    OptionsPreferencesDlg.Top=DVAReg.ReadInteger("OptionsPreferencesDlgTop")
    OptionsPreferencesDlg.Left=DVAReg.ReadInteger("OptionsPreferencesDlgLeft")
else
    OptionsPreferencesDlg.Center
end if
LoadOptions 
OptionsPreferencesDlg.ShowModal
end sub
sub OptionsPreferencesDlgOKButtonClicked
SaveOptions:ViewRefresh
if DVAReg.ReadInteger("RememberWindowPosition")=1 then
    DVAReg.WriteInteger("OptionsPreferencesDlgTop",OptionsPreferencesDlg.Top)
    DVAReg.WriteInteger("OptionsPreferencesDlgLeft",OptionsPreferencesDlg.Left)
end if
end sub
sub OptionsAppearanceFontChangeButtonClicked:dim OptionsAppearanceFontDlg as qfontdialog
OptionsAppearanceFontDlg.DelOptions fdShowHelp, fdEffects
'OptionsAppearanceFontDlg.AddOptions fdNoStyleSel
OptionsAppearanceFontDlg.GetFont(EditFont)
if OptionsAppearanceFontDlg.Execute=1 then
    OptionsAppearanceFontDlg.SetFont(EditFont)
    OptionsAppearanceFontPanel.Font=EditFont
    end if
end sub