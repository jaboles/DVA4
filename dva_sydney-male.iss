

[Setup]
CompressLevel=7
SourceDir=j:\dva
OutputDir=j:\Setup
OutputBaseFilename=DVA4Sydney-Male

AppName=DVA - Sydney Male DVA Update
AppId=DVA4
AppVerName=DVA - Sydney Male DVA Update
DefaultDirName={pf}\DVA
DisableDirPage=yes
UsePreviousAppDir=yes
DisableReadyPage=yes
DisableFinishedPage=true
DisableStartupPrompt=true
UpdateUninstallLogAppName=false

WindowVisible=false
DisableProgramGroupPage=true
WindowStartMaximized=false

[Dirs]
Name: {app}\Sounds\Sydney-Male

[Files]
Source: Sounds\Sydney-Male\*.*; DestDir: {app}\Sounds\Sydney-Male

[_ISTool]
EnableISX=false
UseAbsolutePaths=true
