@echo off
echo Compiling HLP Help File...
start /wait /m j:\HLP\Winhelp4\Source\BuildHelp.bat"
echo Done!
echo.
echo Compiling CHM Help File...
start /wait /m "d:\program files\html help workshop\hhc.exe" "j:\dvahelp\dva.hhp" > nul
echo Done!
echo.
echo Compiling Executable...
start /wait /m "d:\rq\rc.exe" "j:\dva\dva.rqb" > nul
echo Done!
echo.
echo Updating Version Information...
start /wait /m "j:\dva\build.exe"
echo Done!
echo.
echo Compiling Setup...
start /wait /m "d:\Program Files\Inno Setup 2\iscc.exe" "j:\dva.iss" > nul
echo Done!
echo.
start "j:\dvabackup.set"
cls
