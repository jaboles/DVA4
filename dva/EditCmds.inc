sub EditUndo:  SendMessage RichEdit.Handle,WM_UNDO,0,0:EveryTime: END SUB
SUB EditCopy:  RichEdit.CopyToClipBoard:    END SUB   '' Oh yeah, that was easy
SUB EditCut:   RichEdit.CutToClipBoard:     END SUB
SUB EditPaste: RichEdit.PasteFromClipBoard: END SUB
SUB EditSelectAll: RichEdit.SelectAll:      END SUB
sub EditClear: RichEdit.SelText="":end sub
