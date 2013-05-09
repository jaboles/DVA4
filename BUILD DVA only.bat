pushd %~dp0%
echo Compiling Executable...
pushd dva
"c:\rapidq\rc.exe" -Lc:\rapidq\lib ".\build.rqb"
"c:\rapidq\rc.exe" -Lc:\rapidq\lib ".\dva.rqb"
popd
echo Done!
dva\dva.exe
