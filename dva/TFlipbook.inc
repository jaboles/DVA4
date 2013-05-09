TYPE TFlipBook EXTENDS QPanel
    Images(0 TO MaxImages-1) AS QBITMAP
    Canvas AS QCANVAS
    FlipTimer AS QTIMER
    ItemIndex AS INTEGER

    EVENT Canvas.OnPaint (Sender AS QCANVAS)
        WITH This
            .Canvas.Draw(0,0,.Images(.ItemIndex).BMP)
        END WITH
    END EVENT

    EVENT FlipTimer.OnTimer (Sender AS QTIMER)
        WITH This
            .Canvas.Draw(0,0,.Images(.ItemIndex).BMP)
            .ItemIndex = (.ItemIndex+1) MOD MaxImages
            $IFNDEF LoopBook
              IF .ItemIndex = 0 THEN .FlipTimer.Enabled = 0
            $ENDIF
            .FlipTimer.Interval = FlipDelay
        END WITH
    END EVENT

    FUNCTION Execute AS LONG
        WITH This
            .ItemIndex = 0
            .FlipTimer.Interval = 1
            .FlipTimer.Enabled = 1
            .Visible=True
	END WITH
    END FUNCTION

    CONSTRUCTOR
        'Center
        Width = MaxWidth
        Height = MaxHeight
        FlipTimer.Enabled = 0
        Visible=False
        Canvas.Parent = This
        'Canvas.Align = 5
        'borderstyle=0
    END CONSTRUCTOR
END TYPE
