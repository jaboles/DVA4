sub HelpContents
    HelpDummy=HHelp(MainForm.Handle, AppDir+"help\DVA Help.chm", HH_DISPLAY_TOC,)
end sub

sub HelpIndex
    HelpDummy=HHelp(MainForm.Handle, AppDir+"help\DVA Help.chm", HH_DISPLAY_INDEX,)
end sub

sub HelpAbout
    AboutDlg.ShowModal
end sub