'$resource Background as "about.bmp"

CREATE AboutDlg AS QFORM
    Caption = "DVA"
    BorderStyle=bsNone
    Parent=MainForm
    Center
    create AboutDlgBackgroundBitmap as qimage
        'BMPHandle=Background
        BMP=DVAReg.ReadString("AppDir")+"images\about.bmp"
        Width=580
        Height=255
    end create
    create AussieLogo as qimage
        BMP=DVAReg.ReadString("AppDir")+"images\aus.bmp"
        width=60
        height=60
        left=488
        top=140
        transparent=1
        stretch=1
        
    end create
    Width=AboutDlgBackgroundBitmap.Width
    Height=AboutDlgBackgroundBitmap.Height
    Center
    CREATE AboutLabel1 AS QLABEL
        Caption = "Version "+AppVer+"    Build "+AppBuild
        Left = 355
        Top = 108
        Width = 160
        Color=&HFFFFFF
        Font=Font
    END CREATE
    create AboutLabel2 as qlabel
        caption="DVA Online: "+DVAReg.ReadString("Website")+cr+"E-Mail: "+DVAReg.ReadString("ContactEmail")
        left=410
        top=8
        Font=Font
        Width=160
        color=&HFFFFFF
    end create
    create AboutText as qlabel
		left=12
		top=183
            font=YellowFont
            color=&H993333
		caption="Copyright © Jonathan Boles 1999-"+right$(date$,4)+". All rights reserved."+cr+ _
                    "Sounds included with DVA are copyright ©: "+DVAReg.ReadString("SoundCopyright")+cr+ _
                   "Used with permission. Visit the site at www.railpage.org.au/railwavs"+cr+ _
                   "Splash Screen Design: Winston Yang."+cr+ _
                   "Beta Testers: "+DVAReg.ReadString("BetaTesters")+"."
	end create
    CREATE AboutOKButton AS Qbutton
        'Flat=True
        Left = 480
        Kind=bkCancel
        Caption="Close"
        Top = 218
        Cursor=crHandPoint
        onclick=AboutDlgOKButtonClicked
    END CREATE
	create StartProgress as qgauge
		left=490
		top=186
		kind=gkPie
		width=40
		height=40
		borderstyle=bsNone
		color=&H993333
            
		'showtext=false
	end create
END CREATE

sub AboutDlgOKButtonClicked:AboutDlg.close:end sub

