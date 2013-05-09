@echo off
del "j:\hlp\winhelp4\source\DVA Help.cnt"
del "j:\hlp\winhelp4\source\DVA Help.hpj"
copy "j:\hlp\winhelp4\source\dva.hpj" "j:\hlp\winhelp4\source\DVA Help.hpj"
start /wait /m "d:\Program Files\Help Workshop\hcw.exe" /c /e /m "j:\hlp\winhelp4\source\DVA Help.hpj"
del "j:\hlp\winhelp4\source\DVA Help.cnt"
del "j:\hlp\winhelp4\source\DVA Help.hpj"
ren "j:\hlp\winhelp4\source\DVA HELP.HLP" j:\hlp\winhelp4\source\hlp.hlp
ren "j:\hlp\winhelp4\source\hlp.hlp" "j:\hlp\winhelp4\source\DVA Help.hlp"
copy /y "j:\hlp\winhelp4\source\DVA Help.hlp" "j:\dva\help"
copy /y "j:\hlp\winhelp4\source\dva.cnt" "j:\dva\help"

del "j:\hlp\winhelp4\source\Readme.hpj"
copy "j:\hlp\winhelp4\source\read.hpj" "j:\hlp\winhelp4\source\Readme.hpj"
start /wait /m "d:\Program Files\Help Workshop\hcw.exe" /c /e /m "j:\hlp\winhelp4\source\Readme.hpj"
del "j:\hlp\winhelp4\source\Readme.hpj"
rem ren j:\hlp\winhelp4\source\read.hlp "j:\hlp\winhelp4\source\Readme.hlp"
copy /y "j:\hlp\winhelp4\source\Readme.hlp" "j:\dva\help"
copy /y "j:\hlp\winhelp4\source\Readme.cnt" "j:\dva\help"

del "j:\hlp\winhelp4\source\License.hpj"
copy "j:\hlp\winhelp4\source\lic.hpj" "j:\hlp\winhelp4\source\License.hpj"
start /wait /m "d:\Program Files\Help Workshop\hcw.exe" /c /e /m "j:\hlp\winhelp4\source\License.hpj"
del j:\hlp\winhelp4\source\License.hpj
copy /y "j:\hlp\winhelp4\source\License.hlp" "j:\dva\help"
copy /y "j:\hlp\winhelp4\source\License.cnt" "j:\dva\help"

copy /y "j:\hlp\winhelp4\source\*.gid" "j:\dva\help"
cls