pushd %~dp0%
rem @echo off
rem echo Compiling HLP Help File...
rem j:\HLP\Winhelp4\Source\BuildHelp.bat"
rem echo Done!
rem echo.
echo Compiling CHM Help File...
start /wait "Build CHM Help" "%programfiles(x86)%\html help workshop\hhc.exe" ".\dvahelp > htmlhelp.out.txt
echo Done!
echo.
echo Compiling Executable...
pushd dva
start /wait "Compile" "c:\rapidq\rc.exe" -Lc:\rapidq\lib ".\build.rqb" > ..\compile2.out.txt
start /wait "Compile" "c:\rapidq\rc.exe" -Lc:\rapidq\lib ".\dva.rqb" > ..\compile.out.txt
popd
echo Done!
echo.
echo Updating Version Information...
start /wait "Update version" ".\dva\build.exe" > updateversion.out.txt
echo Done!
echo.
echo Compiling Setup...
start /wait "Build setup" "%programfiles(x86)%\Inno Setup 5\iscc.exe" ".\dva.iss" > setupbuild.out.txt
echo Done!
echo.
popd
rem start "j:\dvabackup.set"
rem cls
