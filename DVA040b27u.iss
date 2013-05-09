
[Setup]
CompressLevel=9
SourceDir=d:\rq\dva
OutputDir=e:\
OutputBaseFilename=DVA040b27u

AppName=DVA Update
AppId=DVA4
AppVerName=DVA Update
DefaultDirName={reg:HKCU\Software\DVA,AppDir|C:\Program Files\DVA}
DisableFinishedPage=true
DisableStartupPrompt=true
UpdateUninstallLogAppName=false

WindowVisible=false
DisableProgramGroupPage=true
WindowStartMaximized=false
DisableDirPage=true

[Dirs]
Name: {app}\help

[Files]
Source: D:\rq\dva\dva.exe; DestDir: {app}
Source: D:\rq\dva\help\*.*; DestDir: {app}\help

[_ISTool]
EnableISX=false
UseAbsolutePaths=true

[Registry]
Root: HKCU; Subkey: Software\DVA; ValueType: dword; ValueName: AppBuild; ValueData: 27
