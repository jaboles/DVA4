sub ViewRefresh
    SetStatus("Busy","Refreshing File List")
    WadView.Directory=AppDir+"Sounds\"
    WadView.Update:SetStatus("Ready",)
end sub

sub ViewWordWrap:if RichEdit.WordWrap=False then
        RichEdit.WordWrap=True:ViewWordWrapMenu.Checked=True
        DVAReg.WriteInteger("WordWrap",1)
    else
        RichEdit.WordWrap=False:ViewWordWrapMenu.Checked=False
        DVAReg.WriteInteger("WordWrap",0)
    end if
end sub

sub ViewFullScreen
    if ViewFullScreenMenu.Checked=1 then
        if IsFullScreen=1 then SwitchFromFullScreen
        DVAReg.WriteInteger("FullScreen",0)
        ViewFullScreenMenu.Checked=0
        OptionsAppearanceFullScreen.Checked=0
    else
        if IsFullScreen=0 then SwitchToFullScreen
        DVAReg.WriteInteger("FullScreen",1)
        ViewFullScreenMenu.Checked=1
        OptionsAppearanceFullScreen.Checked=1
    end if
end sub
