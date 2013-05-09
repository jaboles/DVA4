sub FileNew
    PromptSave
    SetStatus("Busy","Creating New File")
    RichEdit.Clear
    Filename="Untitled.dva"
    Application.Title=AppName+" - ["+Filename+"]"
    MainForm.Caption=AppName+" - ["+Filename+"]"
    'CurrentFile.Header=Header
    dfHeader=""
    'CurrentFile.Title=""
    dfTitle=""
    'CurrentFile.Author=""
    dfAuthor=""
    'CurrentFile.Comments=""
    dfComments=""
    'CurrentFile.DefaultDir=""
    dfDefaultDir=""
    'CurrentFile.Contents=RichEdit.Text
    dfContents=""
    ResetModifiedStatus
    StatusBar.Panel(1).Caption=""
    FileEnhanced=True
    CheckToDisableProperties
    SetStatus("Ready",)
end sub


sub FileOpen
    create OpenDialog as qopendialog
        caption="Open..."
        filter="DVA File (*.DVA)|*.DVA|MVA File (*.MVA)|*.MVA|All Files (*.*)|*.*"
        filterindex=1
        initialdir=AppDir+"Sources\"
    end create
    if OpenDialog.Execute then
        PromptSave
        SetStatus("Busy","Opening File")
        Filename=OpenDialog.Filename
        TestStream.Open(Filename,fmOpenRead)
        Test=TestStream.Readstr(8)
        TestStream.Close
        if lcase$(right$(Filename,3))="dva" and left$(Test,4)="DVA4" then
            LoadDVA4
            RichEdit.Text=dfContents
        elseif lcase$(right$(Filename,3))="dva" and left$(Test,8)="DVA00.41" then
            LoadDVA00_41
            RichEdit.Text=rtrim$(dfContents)
        elseif lcase$(right$(Filename,3))="dva" then
            RichEdit.LoadFromFile(Filename)
            FileEnhanced=True
            CurrentFile.Title=""
            CurrentFile.Author=""
            CurrentFile.Comments=""
            CurrentFile.DefaultDir=""
        else
            RichEdit.LoadFromFile(Filename)
            FileEnhanced=False
        end if
        Application.Title=AppName+" - ["+Filename+"]"
        MainForm.Caption=AppName+" - ["+Filename+"]"
        ResetModifiedStatus
        CheckToDisableProperties
        SetStatus("Ready",)
    end if
    StatusBar.Panel(1).Caption=""
end sub



sub FileSaveAs
    create SaveDialog as qsavedialog
        caption="Save As..."
        filter="DVA File (*.DVA)|*.DVA|MVA File (*.MVA)|*.MVA|All Files (*.*)|*.*"
        filterindex=1
        initialdir=AppDir+"Sources\"
    end create
    if SaveDialog.Execute then
        SetStatus("Busy","Saving File")
        Filename=SaveDialog.Filename
        If SaveDialog.filterindex=1 then
            if ucase$(right$(Filename,4)) <> ".DVA" then Filename = Filename+".dva"
             FileEnhanced=True
        end if
        If SaveDialog.filterindex=2 then
            if ucase$(right$(Filename,4)) <> ".MVA" then Filename = Filename+".mva"
            FileEnhanced=False
        end if
        FileSave
        CheckToDisableProperties
        Application.Title=AppName+" - ["+Filename+"]"
        MainForm.Caption=AppName+" - ["+Filename+"]"
        SetStatus("Ready",)
    end if
end sub

sub FileSave:if Filename="Untitled.dva" then
    FileSaveAs
else
    SetStatus("Busy","Saving File")
    if FileEnhanced=True then
        SaveFileStream.Open(Filename,fmCreate)
        dfContents=RichEdit.Text
        SaveFileStream.WriteStr(header,8)
        SaveFileStream.WriteNum(len(dfTitle),2)
        SaveFileStream.WriteStr(dfTitle,len(dfTitle))
        SaveFileStream.WriteNum(len(dfAuthor),2)
        SaveFileStream.WriteStr(dfAuthor,len(dfAuthor))
        SaveFileStream.WriteNum(len(dfComments),4)
        SaveFileStream.WriteStr(dfComments,len(dfComments))
        SaveFileStream.WriteNum(len(dfDefaultDir),2)
        SaveFileStream.WriteStr(dfDefaultDir,len(dfDefaultDir))
        SaveFileStream.WriteNum(len(dfContents),4)
        SaveFileStream.WriteStr(dfContents,len(dfContents))
        SaveFileStream.Close
    else
        RichEdit.SaveToFile(Filename)
    end if
    ResetModifiedStatus
    StatusBar.Panel(1).Caption=""
    SetStatus("Ready",)
end if:end sub

sub FilePlay
SetStatus("Busy","Playing File")
dim AString as string
dim BString as string
if FileEnhanced=True and len(dfDefaultDir) then
    SoundsDir=AppDir+"Sounds\"+dfDefaultDir
    if right$(SoundsDir,1) <> "\" then SoundsDir=SoundsDir+"\"
end if
dim Count as integer
for Count=0 to RichEdit.LineCount
AString=ltrim$(rtrim$(RichEdit.Line(Count)))
BString=SoundsDir+AString+".wad"
If AString <> "" and left$(AString,1)<>"/" and fileexists(BString) then
    PLAYWAV(BString, SND_SYNC)
else
    BString=SoundsDir+AString+".wav"
    If AString <> "" and left$(AString,1)<>"/" and fileexists(BString) then PLAYWAV(BString, SND_SYNC)
end if
doevents
next
SetStatus("Ready",)
end sub

sub FileCompile
    create CompileSave as qsavedialog
        Caption="Compile As..."
        Filter="Windows Executable (*.EXE)|*.exe|MS-DOS Batch File (*.BAT)|*.bat"
        FilterIndex=1
        InitialDir=AppDir
        'filename=left$(Filename,len(Filename)-4)+".exe"
    end create
    If CompileSave.Execute then
        SetStatus("Busy","Compiling")
        dim CompileFileName as string
        CompileFileName=CompileSave.Filename
        dim CountB as integer
        dim CompileStream as qfilestream, CountC as integer
     if Compilesave.FilterIndex=2 then
        if  lcase$(right$(CompileFileName,4)) <> ".bat" then CompileFileName = CompileFileName + ".bat"
        if FileEnhanced=True and len(dfDefaultDir) then
            SoundsDir=AppDir+"Sounds\"+dfDefaultDir
            if right$(SoundsDir,1) <> "\" then SoundsDir=SoundsDir+"\"
        end if
        CompileStream.Open(CompileFileName,fmCreate)
        CompileStream.WriteLine("@echo off")
        CompileStream.WriteLine("echo Compiled DVA File")
        CompileStream.WriteLine("echo.")
        CompileStream.WriteLine("echo Compiled in "+AppName)
        CompileStream.WriteLine("echo Copyright (c) Jonathan Boles 1999-"+right$(date$,4))
        for CountB=0 to RichEdit.LineCount
            If RichEdit.Line(CountB) <> "" and left$(RichEdit.Line(CountB),1) <> "/" then CompileStream.WriteLine(chr$(34)+AppDir+"wplay.exe"+chr$(34)+" "+chr$(34)+GetShortFileName(SoundsDir+rtrim$(ltrim$(RichEdit.Line(CountB)))+".wad")+chr$(34)+" > nul")
        next
        CompileStream.Close
     else
        if lcase$(right$(CompileFileName,4)) <> ".exe" then CompileFileName = CompileFileName + ".exe"
        if FileEnhanced=True and len(dfDefaultDir) then
            SoundsDir=AppDir+"Sounds\"+dfDefaultDir
            if right$(SoundsDir,1) <> "\" then SoundsDir=SoundsDir+"\"
        end if
        
        dim CompileBinary as string, CompileIconPath as string, CompileLibPath as string, CompileInput as string, CompileOutput as string, CompileBinLib as string
        CompileBinary=AppDir+"rc.exe"
        CompileIconPath=AppDir
        CompileLibPath=AppDir
        CompileInput=left$(CompileFileName,len(CompileFileName)-4)+".rqb"
        CompileOutput=CompileFilename
        CompileBinLib=AppDir+"rapidq4.lib"
        
        CompilerText.Text=""
        CompilerForm.show

        Compilertext.AddStrings "CompileBinary = "+CompileBinary,"CompileIconPath = "+CompileIconPath,"CompileLibPath = "+CompileLibPath
        Compilertext.AddStrings "CompileInput = "+CompileInput,"CompileOutput = "+CompileOutput,"CompileBinLib = "+CompileBinLib
        Compilertext.AddStrings "","Please wait. Compiling bytecode...",""
        CompileStream.Open(CompileInput,fmCreate)
        'CompileStream.writeline("$option bytecode")
        Countc=0
        for CountB=0 to RichEdit.LineCount
            If RichEdit.Line(CountB) <> "" and left$(RichEdit.Line(CountB),1) <> "/" then
                if fileexists(SoundsDir+rtrim$(ltrim$(RichEdit.Line(CountB)))+".wad") then
                    CompileStream.WriteLine("$resource wav"+str$(CountC)+" as "+chr$(34)+SoundsDir+rtrim$(ltrim$(RichEdit.Line(CountB)))+".wad"+chr$(34))
                    CompilerText.AddStrings "$resource wav"+str$(CountC)+" as "+chr$(34)+SoundsDir+rtrim$(ltrim$(RichEdit.Line(CountB)))+".wad"+chr$(34)
                elseif fileexists(SoundsDir+rtrim$(ltrim$(RichEdit.Line(CountB)))+".wav") then
                    CompileStream.WriteLine("$resource wav"+str$(CountC)+" as "+chr$(34)+SoundsDir+rtrim$(ltrim$(RichEdit.Line(CountB)))+".wav"+chr$(34))
                    CompilerText.AddStrings "$resource wav"+str$(CountC)+" as "+chr$(34)+SoundsDir+rtrim$(ltrim$(RichEdit.Line(CountB)))+".wav"+chr$(34)
                else
                    Compilertext.Addstrings "Warning, "+RichEdit.Line(CountB)+" not found!"
                end if
                CountC=CountC+1
            end if
        next
        for CountB=0 to CountC-1
            CompileStream.writeline("playwav wav"+str$(CountB)+",0")
            CompilerText.AddStrings "playwav wav"+str$(CountB)+",0" 
        next
        CompileStream.Close
        if fileexists("out.txt") then kill "out.txt"
        dim CCommandstring as string
        CCommandstring="-I"+GetShortFileName(CompileIconPath)+" "
        CCommandstring=CCommandstring+"-L"+GetShortFileName(CompileLibPath)+" "
        CCommandstring=CCommandstring+"-GUI -opt -vON " 
        CCommandstring=CCommandstring+qt+CompileInput+qt+" "
        'CCommandstring=CCommandstring+qt+CompileFileName+qt+" "
        'CCommandstring=replacesubstr$(CCommandstring,"\","/")
        CompilerText.AddStrings "", "Command Line:", CCommandString
        deflng cpid=shell(qt+AppDir+"rc.exe"+qt+" "+CCommandstring,0)
        CompilerText.AddStrings "Process id: " + str$(cpid)
        'WaitForSingleObject(cpid,&HFFFF)
        CompilerText.AddStrings "", "Compiled to: " + CompileFileName
        'ShellExecute(0,"open",qt+AppDir+"rc.exe"+qt,CCommandstring,"",0)
        'shell qt+AppDir+"rc.exe"+qt+" "+CCommandstring
        'dim Creadoutput as qfilestream, CdoTxt as string, CroTxt as string
        'Creadoutput.open(AppDir+ "dump.$$$",fmOpenRead)
        'CroTxt = Creadoutput.ReadStr(Creadoutput.size)
        'Creadoutput.close
        'kill "dump.$$$"
        'CompilerText.text=CompilerText.text+CroTxt+cr
        'CompilerForm.Repaint
        
        'dim CByteCode as string, CLibCode as string, CExeCode as string
        'Compilestream.Open(CompileBinLib,fmOpenRead)
        'CLibCode=Compilestream.readstr(Compilestream.size)
        'Compilestream.close
        'sleep 0.2
        'CompilerText.AddStrings "Loaded.","Loading bytecode output..."
        'CompilerForm.Repaint
        'CompileStream.Open(CompileFileName,fmOpenRead)
        'CByteCode=CompileStream.readstr(Compilestream.size)
        'CompileStream.close
        'sleep 0.3
        'CompilerText.AddStrings "Loaded.","Writing EXE output..."
        'CompilerForm.Repaint
        'Compilestream.open(Compilefilename,fmcreate)
        'Compilestream.writestr(CLibCode,len(CLibCode)-1)
        'CompileStream.writestr(CByteCode,len(CByteCode)-1)
        'CompileStream.Close
        'sleep 0.2
        'CompilerText.AddStrings "Written.","","Compilation completed!!!"
        CompilerForm.Repaint
        'sleep 3
        'CompilerForm.Close
        'kill CompileInput
        'kill "run.bat"
        'kill "out.txt"
        EndOfCompile:
     end if
     SetStatus("Ready",)
    end if
end sub            

sub FilePrint
    RichEdit.SaveToFile(DVAReg.ReadString("PrintOutput"))
end sub

sub FileCheckForUpdate
    PromptSave
    SetStatus("Busy","Preparing to check for update")
    run AppDir+"update.exe"
    Application.Terminate
end sub

sub FileExit
    PromptSave
    SetStatus("Busy","Exiting")
    if DVAReg.ReadInteger("RememberWindowPosition")=1 and DVAReg.ReadInteger("FullScreen")=0 then
        if MainForm.WindowState=wsMaximized then
            DVAReg.WriteString("MainFormWindowState","wsMaximized")
        else
            DVAReg.WriteString("MainFormWindowState","wsNormal")
            DVAReg.WriteInteger("MainFormTop",MainForm.Top)
            DVAReg.WriteInteger("MainFormLeft",MainForm.Left)
            DVAReg.WriteInteger("MainFormWidth",MainForm.Width)
            DVAReg.WriteInteger("MainFormHeight",MainForm.Height)
        end if
    end if
    MainForm.OnResize=dummyproc
    Application.Terminate
end sub    



