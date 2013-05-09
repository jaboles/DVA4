

[Setup]
CompressLevel=7
SourceDir=j:\dva
OutputDir=j:\Setup
OutputBaseFilename=DVA4Brisbane

AppName=DVA - Brisbane DVA Update
AppId=DVA4
AppVerName=DVA - Brisbane DVA Update
DefaultDirName={pf}\DVA
DisableDirPage=yes
DisableReadyPage=yes
UsePreviousAppDir=yes
DisableFinishedPage=true
DisableStartupPrompt=true
UpdateUninstallLogAppName=no

WindowVisible=false
DisableProgramGroupPage=true
WindowStartMaximized=false

[Dirs]
Name: {app}\Sounds\Brisbane

[Files]
Source: Sounds\Brisbane\*.*; DestDir: {app}\Sounds\Brisbane

[_ISTool]
EnableISX=false
UseAbsolutePaths=true
