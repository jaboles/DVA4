create PromptSaveDlg as qform
    borderstyle=bsDialog
    caption="Save Changes?"
    width=500
    height=100
    parent=MainForm
    center
    create PromptSaveCaptionPanel as qpanel
        width=PromptSaveDlg.ClientWidth
        height=PromptSaveDlg.ClientHeight-30
        caption="Save changes to "+Filename+"?"
        bevelouter=bvNone
    end create
    create PromptSaveDlgYesButton as QButton
        kind=bkYes
        cursor=crHandPoint
        left=170
        top=45
        onclick=PromptSaveDlgYesButtonClicked
        default=1
    end create
    create PromptSaveDlgNoButton as qbutton
        kind=bkNo
        cursor=crHandPoint
        left=250
        top=45
        onclick=PromptSaveDlgNoButtonClicked
    end create
end create
