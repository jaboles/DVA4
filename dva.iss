[Setup]
Compression=none
SourceDir=C:\Users\Jonathan Boles\Desktop\Soft Dev\dva\DVADev\dva
OutputDir=C:\Users\Jonathan Boles\Desktop\Soft Dev\dva\DVADev\dvasetup
OutputBaseFilename=Setup

AllowNoIcons=false
;AlwaysCreateUninstallIcon=true
AppName=DVA
AppId=DVA4
AppVerName=DVA 4
ChangesAssociations=true
DefaultDirName={pf}\DVA
DefaultGroupName=DVA 4

AppCopyright=Copyright © Jonathan Boles 1999-2013. All Rights Reserved.
BackColor=clNavy
BackColor2=clGreen
WindowShowCaption=false
WizardImageFile=compiler:wizmodernimage.bmp
LicenseFile=help\License Agreement.txt
AppPublisher=Jonathan Boles
AppPublisherURL={app}\help\DVA Online.url
AppSupportURL={app}\help\DVA Online.url
AppUpdatesURL={app}\help\DVA Online.url
AppVersion=4
UninstallDisplayIcon={app}\images\dvaprog.ico
WindowVisible=true
UninstallDisplayName=DVA
UseSetupLdr=true

WizardSmallImageFile=compiler:wizmodernsmallimage.bmp
;DiskSpanning=true
;DiskSize=1048576



[Dirs]
Name: {app}\Sounds; Components: Core_Program_Files
Name: {app}\Sources; Components: Example_DVA_Files

Name: {app}\Sources\Railwavs; Components: Example_DVA_Files
Name: {app}\Sources\Railwavs\Sydney-Male; Components: Example_DVA_Files
Name: {app}\Sources\Railwavs\Sydney-Countrylink; Components: Example_DVA_Files
Name: {app}\Sources\Railwavs\Sydney-Female; Components: Example_DVA_Files
Name: {app}\Sources\Railwavs\Brisbane; Components: Example_DVA_Files

Name: {app}\help; Components: Help_Files
Name: {app}\images; Components: Core_Program_Files
Name: {app}\dvasrc; Components: DVA_Source
;Name: {app}\Sources\Railwavs\Sydney-Longline; Components: Sydney_Longline
;Name: {app}\Sounds\Sydney-Longline; Components: Sydney_Longline

Name: {app}\Sounds\Adelaide; Components: Adelaide_DVA_Sounds
Name: {app}\Sounds\Brisbane; Components: Brisbane_DVA_Sounds
Name: {app}\Sounds\Brisbane SMU-IMU; Components: Brisbane_SMU_IMU_DVA_Sounds
Name: {app}\Sounds\dTrog remix; Components: dTrog_DVA_Sounds
Name: {app}\Sounds\Perth; Components: Perth_DVA_Sounds
Name: {app}\Sounds\Perth onboard; Components: Perth_onboard_DVA_Sounds
Name: {app}\Sounds\Perth PIM (new); Components: Perth_PIM_new_DVA_Sounds
Name: {app}\Sounds\Perth PIM (original); Components: Perth_PIM_original_DVA_Sounds
Name: {app}\Sounds\Sydney-Male; Components: Sydney_Male_DVA_Sounds
Name: {app}\Sounds\Sydney-Female; Components: Sydney_Female_DVA_Sounds
Name: {app}\Sounds\Sydney Millennium Train; Components: Sydney_Millennium_Train_DVA_Sounds
Name: {app}\Sounds\Sydney-Male (replaced low quality sounds); Components: Sydney_Male_replaced_low_quality_sounds_DVA_Sounds


[Files]
Source: dva.exe; DestDir: {app}; Components: Core_Program_Files
Source: wplay.exe; DestDir: {app}; Components: Core_Program_Files
Source: desktop.ini; DestDir: {app}; Attribs: hidden; Components: Core_Program_Files

Source: images\*.*; DestDir: {app}\images; Components: Core_Program_Files



Source: Sources\Railwavs\Sydney-Male\*.*; DestDir: {app}\Sources\Railwavs\Sydney-Male; Components: Example_DVA_Files
Source: Sources\Railwavs\Sydney-Countrylink\*.*; DestDir: {app}\Sources\Railwavs\Sydney-Countrylink; Components: Example_DVA_Files

Source: Sources\Railwavs\Sydney-Female\*.*; DestDir: {app}\Sources\Railwavs\Sydney-Female; Components: Example_DVA_Files

Source: Sources\Railwavs\Brisbane\*.*; DestDir: {app}\Sources\Railwavs\Brisbane; Components: Example_DVA_Files
Source: Sources\*.*; DestDir: {app}\Sources; Components: Example_DVA_Files
Source: Sounds\start.wav; DestDir: {app}\Sounds; Components: Core_Program_Files
Source: help\License.hlp; DestDir: {app}\help
Source: help\License.cnt; DestDir: {app}\help
Source: help\Tech Support.url; DestDir: {app}\help; Components: Help_Files
Source: help\DVA Help.hlp; DestDir: {app}\help; Components: Help_Files
Source: help\DVA Online.url; DestDir: {app}\help; Components: Help_Files
Source: help\dva.cnt; DestDir: {app}\help; Components: Help_Files
Source: help\Feedback.url; DestDir: {app}\help; Components: Help_Files
Source: help\Readme.cnt; DestDir: {app}\help; Components: Help_Files
Source: help\Readme.hlp; DestDir: {app}\help; Components: Help_Files
Source: help\DVA Help.chm; DestDir: {app}\help; Components: Help_Files
Source: Sounds\Adelaide\*.*; DestDir: {app}\Sounds\Adelaide; Components: Adelaide_DVA_Sounds
Source: Sounds\Brisbane\*.*; DestDir: {app}\Sounds\Brisbane; Components: Brisbane_DVA_Sounds
Source: Sounds\dTrog remix\*.*; DestDir: {app}\Sounds\dTrog remix; Components: dTrog_DVA_Sounds
Source: Sounds\Perth\*.*; DestDir: {app}\Sounds\Perth; Components: Perth_DVA_Sounds
Source: Sounds\Perth onboard\*.*; DestDir: {app}\Sounds\Perth onboard; Components: Perth_onboard_DVA_Sounds
Source: Sounds\Perth PIM (original)\*.*; DestDir: {app}\Sounds\Perth PIM (original); Components: Perth_PIM_original_DVA_Sounds
Source: Sounds\Perth PIM (new)\*.*; DestDir: {app}\Sounds\Perth PIM (new); Components: Perth_PIM_new_DVA_Sounds
Source: Sounds\Sydney-Male\*.*; DestDir: {app}\Sounds\Sydney-Male; Components: Sydney_Male_DVA_Sounds
Source: Sounds\Sydney-Male (replaced low-quality sounds)\*.*; DestDir: {app}\Sounds\Sydney-Male (replaced low-quality sounds); Components: Sydney_Male_replaced_low_quality_sounds_DVA_Sounds
Source: Sounds\Sydney Millennium Train\*.*; DestDir: {app}\Sounds\Sydney Millennium Train; Components: Sydney_Millennium_Train_DVA_Sounds
Source: Sounds\Sydney-Female\*.*; DestDir: {app}\Sounds\Sydney-Female; Components: Sydney_Female_DVA_Sounds
Source: FileProp.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: AboutDlg.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: findsystem.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: htmlhelp.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: initialise.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: optionsdlg.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: PromptSaveDlg.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: Qtoolbar.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: Rapidq.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: ShortFileName.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: tflipbook.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: toolbar.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: dva.rqb; DestDir: {app}\dvasrc; Components: DVA_Source
Source: rc.exe; DestDir: {app}; Components: Core_Program_Files
Source: rapidq4.lib; DestDir: {app}; Components: Core_Program_Files
;Source: Sources\Railwavs\Sydney-Longline\*.*; DestDir: {app}\Sources\Railwavs\Sydney_Longline; Components: Sydney_Longline
;Source: Sounds\Sydney-Longline\*.*; DestDir: {app}\Sounds\Sydney_Longline; Components: Sydney_Longline
Source: LoadFiles.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: TFlipbookResources.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: FileCmds.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: EditCmds.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: ViewCmds.inc; DestDir: {app}\dvasrc; Components: DVA_Source
Source: HelpCmds.inc; DestDir: {app}\dvasrc; Components: DVA_Source


;Source: "Sources\*.*"; DestDir: "{app}\Sources"
;Source: "Sources\Railwavs\*.*"; DestDir: "{app}\Sources\Railwavs"



[Icons]
Name: "{group}\DVA  "; Filename: {app}\dva.exe; IconFilename: {app}\images\DVAProg.ico; IconIndex: 0
Name: {group}\Source Files; Filename: {app}\Sources; IconFilename: {app}\images\DVA.ico; IconIndex: 0
Name: {group}\DVA Help; Filename: {app}\help\DVA Help.hlp; IconIndex: 0; Components: Help_Files
Name: {group}\Feedback; Filename: {app}\help\Feedback.url; IconIndex: 0; Components: Help_Files; IconFilename: {app}\images\mail.ico
Name: {group}\Tech Support; Filename: {app}\help\Tech Support.url; IconIndex: 0; Components: Help_Files; IconFilename: {app}\images\mail.ico
Name: {group}\DVA Online; Filename: {app}\help\DVA Online.url; IconIndex: 0; Components: Help_Files

Name: {userdesktop}\DVA; Filename: {group}; IconFilename: {app}\images\DVAFolder.ico; IconIndex: 0
Name: {group}\License Agreement; Filename: {app}\help\License.hlp; IconIndex: 0
Name: {group}\Readme for DVA; Filename: {app}\help\readme.hlp; IconIndex: 0; Components: Help_Files
Name: {group}\Uninstall DVA; Filename: {uninstallexe}; IconIndex: 0

[Registry]
Root: HKCU; Subkey: Software\DVA; ValueType: string; ValueName: AppVer; ValueData: v0.40b
Root: HKCU; Subkey: Software\DVA; ValueType: string; ValueName: PrintOutput; ValueData: LPT1:
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: ToolbarSize; ValueData: 1
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: ToolbarFlat; ValueData: 1
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: ToolbarVisible; ValueData: 1
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: WordWrap; ValueData: 1
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: SplashScreen; ValueData: 1
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: AppBuild; ValueData: 69
Root: HKCU; Subkey: Software\DVA; ValueType: string; ValueName: FontName; ValueData: System
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: FontSize; ValueData: 14
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: StartupSound; ValueData: 1
Root: HKCU; Subkey: Software\DVA; ValueType: string; ValueName: MainFormWindowState; ValueData: wsMaximized
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: RememberWindowPosition; ValueData: 0
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: MainFormTop; ValueData: 0
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: MainFormLeft; ValueData: 0
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: MainFormWidth; ValueData: 800
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: MainFormHeight; ValueData: 600
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: OptionsPreferencesDlgLeft; ValueData: 0
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: OptionsPreferencesDlgTop; ValueData: 0
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: FullScreen; ValueData: 0

[Run]
Filename: {app}\dva.exe; Parameters: reg; StatusMsg: Updating registry settings.
Filename: {app}\dva.exe; WorkingDir: {app}; Flags: postinstall skipifsilent unchecked nowait shellexec; Description: Run DVA now.; Components: Core_Program_Files
Filename: {app}\help\DVA Help.hlp; Flags: postinstall skipifsilent unchecked nowait shellexec; Description: View DVA Help file.; Components: Help_Files
Filename: {app}\help\Readme.hlp; Flags: postinstall skipifsilent nowait shellexec; Components: Help_Files; Description: View DVA Readme.



[UninstallRun]
;Filename: {win}\DVARegisterButton.exe; Parameters: uninstall

[UninstallDelete]
;Type: files; Name: {win}\DVARegisterButton.exe

[_ISTool]
EnableISX=false
UseAbsolutePaths=true

[Components]
Name: Core_Program_Files; Description: DVA Program Files; Flags: fixed; Types: Custom Compact Full
Name: Help_Files; Description: Help Files; Types: Full Custom
Name: Example_DVA_Files; Description: Example DVA Files; Types: Custom Full
;Name: Sydney_Longline; Description: Sydney Longline DVA Sounds; Types: Custom Full
Name: DVA_Source; Description: DVA Source (compile in RapidQ); Types: Custom Full
Name: Adelaide_DVA_Sounds; Description: Adelaide DVA; Types: Custom Full
Name: Brisbane_DVA_Sounds; Description: Brisbane DVA; Types: Custom Full
Name: Brisbane_SMU_IMU_DVA_Sounds; Description: Brisbane (SMU-IMU) DVA; Types: Custom Full
Name: dTrog_DVA_Sounds; Description: dTrog DVA; Types: Custom Full
Name: Perth_DVA_Sounds; Description: Perth DVA; Types: Custom Full
Name: Perth_onboard_DVA_Sounds; Description: Perth (onboard) DVA; Types: Custom Full
Name: Perth_PIM_original_DVA_Sounds; Description: Perth (PIM original) DVA; Types: Custom Full
Name: Perth_PIM_new_DVA_Sounds; Description: Perth (PIM new) DVA; Types: Custom Full
Name: Sydney_Male_DVA_Sounds; Description: Sydney (Male) DVA; Types: Custom Full
Name: Sydney_Male_replaced_low_quality_sounds_DVA_Sounds; Description: Sydney (Male, replaced low-quality sounds) DVA; Types: Custom Full
Name: Sydney_Female_DVA_Sounds; Description: Sydney (Female) DVA; Types: Custom Full
Name: Sydney_Millennium_Train_DVA_Sounds; Description: Sydney (Millennium Train) DVA; Types: Custom Full


[Types]
Name: Full; Description: Full installation
Name: Compact; Description: Compact Installation
Name: Custom; Description: Custom Installation; Flags: iscustom
