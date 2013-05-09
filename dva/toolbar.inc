const btnNew    = 0
const btnOpen   = 1
const btnSave   = 2
const btnPrint  = 3
const btnProp   = 4
const btnRef    = 5
const btnCut    = 6
const btnCopy   = 7
const btnPaste  = 8
const btnPrefs  = 9
const btnHelp   = 10

dim ImageDir as string
ImageDir=DVAReg.ReadString("AppDir")+"images\"
'-------------------small buttons-----------------------------------
Dim Sbmp as QBitmap                    'For get Height and Width
   Sbmp.bmp = ImageDir+"snew.bmp"
dim Simgs as qimagelist                'List of images for tool bar
   Simgs.Height = Sbmp.Height          'Button enabled
   Simgs.Width = Sbmp.Width
   Simgs.Masked = False
   Simgs.addbmpfile ImageDir+"snew.bmp",0
   Simgs.addbmpfile ImageDir+"sopen.bmp",0
   Simgs.addbmpfile ImageDir+"ssave.bmp",0
   Simgs.addbmpfile ImageDir+"sprint.bmp",0
   Simgs.addbmpfile ImageDir+"sprop.bmp",0
   Simgs.addbmpfile ImageDir+"sref.bmp",0
   Simgs.addbmpfile ImageDir+"scut.bmp",0
   Simgs.addbmpfile ImageDir+"scopy.bmp",0
   Simgs.addbmpfile ImageDir+"spaste.bmp",0
   Simgs.addbmpfile ImageDir+"sprefs.bmp",0
   Simgs.addbmpfile ImageDir+"shelp.bmp",0
dim SimgsD as qimagelist                'List of images for tool bar
   SimgsD.Height = Sbmp.Height          'Button disabled
   SimgsD.Width = Sbmp.Width
   SimgsD.Masked = False
   SimgsD.addbmpfile ImageDir+"snewD.bmp",0
   SimgsD.addbmpfile ImageDir+"sopenD.bmp",0
   SimgsD.addbmpfile ImageDir+"ssaveD.bmp",0
   SimgsD.addbmpfile ImageDir+"sprintD.bmp",0
   SimgsD.addbmpfile ImageDir+"spropD.bmp",0
   SimgsD.addbmpfile ImageDir+"srefD.bmp",0   
   SimgsD.addbmpfile ImageDir+"scutD.bmp",0
   SimgsD.addbmpfile ImageDir+"scopyD.bmp",0
   SimgsD.addbmpfile ImageDir+"spasteD.bmp",0
   SimgsD.addbmpfile ImageDir+"sprefsD.bmp",0
   SimgsD.addbmpfile ImageDir+"shelpD.bmp",0
'--------------------LARGE BUTTONS---------------------------------
dim Lbmp as qbitmap
   Lbmp.bmp = ImageDir+"lnew.bmp"
dim Limgs as qimagelist                'List of images for tool bar
   Limgs.Height = Lbmp.Height          'Button enabled
   Limgs.Width = Lbmp.Width
   Limgs.Masked = False
   Limgs.addbmpfile ImageDir+"lnew.bmp",0
   Limgs.addbmpfile ImageDir+"lopen.bmp",0
   Limgs.addbmpfile ImageDir+"lsave.bmp",0
   Limgs.addbmpfile ImageDir+"lprint.bmp",0
   Limgs.addbmpfile ImageDir+"lprop.bmp",0
   Limgs.addbmpfile ImageDir+"lref.bmp",0   
   Limgs.addbmpfile ImageDir+"lcut.bmp",0
   Limgs.addbmpfile ImageDir+"lcopy.bmp",0
   Limgs.addbmpfile ImageDir+"lpaste.bmp",0
   Limgs.addbmpfile ImageDir+"lprefs.bmp",0
   Limgs.addbmpfile ImageDir+"lhelp.bmp",0
dim LimgsD as qimagelist                'List of images for tool bar
   LimgsD.Height = Lbmp.Height          'Button disabled
   LimgsD.Width = Lbmp.Width
   LimgsD.Masked = False
   LimgsD.addbmpfile ImageDir+"lnewD.bmp",0
   LimgsD.addbmpfile ImageDir+"lopenD.bmp",0
   LimgsD.addbmpfile ImageDir+"lsaveD.bmp",0
   LimgsD.addbmpfile ImageDir+"lprintD.bmp",0
   LimgsD.addbmpfile ImageDir+"lpropD.bmp",0
   LimgsD.addbmpfile ImageDir+"lrefD.bmp",0   
   LimgsD.addbmpfile ImageDir+"lcutD.bmp",0
   LimgsD.addbmpfile ImageDir+"lcopyD.bmp",0
   LimgsD.addbmpfile ImageDir+"lpasteD.bmp",0
   LimgsD.addbmpfile ImageDir+"lprefsD.bmp",0
   LimgsD.addbmpfile ImageDir+"lhelpD.bmp",0
'-----------------------------------------------------------------
