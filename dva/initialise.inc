dim DVAReg as qregistry
dim AssnReg as qregistry
dim SoundsDir as string
dim SourceDir as string

const HKLM=&H80000002
const HKCU=&H80000001
const HKCR=&H80000000


DVAReg.RootKey=HKCU
DVAReg.OpenKey("Software\DVA",0)
if (DVAReg.ValueExists("SoundsDir") And DirExists(DVAReg.ReadString("SoundsDir"))) Then
    SoundsDir=DVAReg.ReadString("SoundsDir")
Else
    SoundsDir=AppDir+"Sounds\"
End If
if (DVAReg.ValueExists("SourceDir") And DirExists(DVAReg.ReadString("SourceDir"))) Then
    SourceDir=DVAReg.ReadString("SourceDir")
Else
    SourceDir=AppDir+"Source\"
End If

AssnReg.RootKey=HKCR
AssnReg.OpenKey("\.mva",1)
AssnReg.WriteString(,"MVA.Source")
AssnReg.OpenKey("\MVA.Source",1)
AssnReg.WriteString(,"MVA Source File")
AssnReg.OpenKey("\MVA.Source\DefaultIcon",1)
AssnReg.WriteString(,AppDir+"images\MVA.ico,0")
AssnReg.OpenKey("\MVA.Source\shell",1)
AssnReg.OpenKey("\MVA.Source\shell\Open",1)
AssnReg.OpenKey("\MVA.Source\shell\Open\command",1)
AssnReg.WriteString(,AppDir+"dva.exe %1")
AssnReg.OpenKey("\MVA.Source\shell\Play",1)
AssnReg.OpenKey("\MVA.Source\shell\Play\command",1)
AssnReg.WriteString(,AppDir+"dva.exe play "+chr$(34)+"%1"+chr$(34))
AssnReg.OpenKey("\MVA.Source\shell\Compile",1)
AssnReg.OpenKey("\MVA.Source\shell\Compile\command",1)
AssnReg.WriteString(,AppDir+"dva.exe compile "+chr$(34)+"%1"+chr$(34))
AssnReg.OpenKey("\.dva",1)
AssnReg.WriteString(,"DVA.Source")
AssnReg.OpenKey("\.dva\ShellNew",1)
AssnReg.WriteString("NullFile","")
AssnReg.OpenKey("\DVA.Source",1)
AssnReg.WriteString(,"DVA Source File")
AssnReg.OpenKey("\DVA.Source\DefaultIcon",1)
AssnReg.WriteString(,AppDir+"images\DVA.ico,0")
AssnReg.OpenKey("\DVA.Source\shell",1)
AssnReg.OpenKey("\DVA.Source\shell\Open",1)
AssnReg.OpenKey("\DVA.Source\shell\Open\command",1)
AssnReg.WriteString(,AppDir+"dva.exe "+chr$(34)+"%1"+chr$(34))
AssnReg.OpenKey("\DVA.Source\shell\Play",1)
AssnReg.OpenKey("\DVA.Source\shell\Play\command",1)
AssnReg.WriteString(,AppDir+"dva.exe play "+chr$(34)+"%1"+chr$(34))
AssnReg.OpenKey("\DVA.Source\shell\Compile",1)
AssnReg.OpenKey("\DVA.Source\shell\Compile\command",1)
AssnReg.WriteString(,AppDir+"dva.exe compile "+chr$(34)+"%1"+chr$(34))
AssnReg.OpenKey("\.wad",1)
AssnReg.WriteString(,"DVA.WavData")
AssnReg.OpenKey("\DVA.WavData",1)
AssnReg.WriteString(,"DVA Wave Data")
AssnReg.OpenKey("\DVA.WavData\DefaultIcon",1)
AssnReg.WriteString(,AppDir+"images\WAD.ico,0")
AssnReg.OpenKey("\DVA.WavData\shell",1)
AssnReg.OpenKey("\DVA.WavData\shell\open",1)
AssnReg.OpenKey("\DVA.WavData\shell\open\command",1)
AssnReg.WriteString(,"sndrec32.exe /play /close "+chr$(34)+"%1"+chr$(34))


if lcase$(command$(1))="reg" then Application.Terminate
