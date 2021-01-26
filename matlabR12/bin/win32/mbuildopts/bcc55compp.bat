@echo off
rem BCC55COMPP.BAT
rem
rem    Compile and link options used for building MATLAB compiler
rem    applications with C++ Math Library with the Borland C compiler
rem
rem    $Revision: 1.2 $  $Date: 2000/05/22 19:31:44 $
rem
rem ********************************************************************
rem General parameters
rem ********************************************************************
set MATLAB=%MATLAB%
set BORLAND=%BORLAND%\CBuilder5
set PATH=%BORLAND%\BIN;%MATLAB_BIN%;%PATH%
set INCLUDE=%BORLAND%\INCLUDE
set LIB=%BORLAND%\LIB
set PERL="%MATLAB%\sys\perl\win32\bin\perl.exe"

rem ********************************************************************
rem Compiler parameters
rem ********************************************************************
set COMPILER=bcc32
set COMPFLAGS=-c -3 -a8  -b -w- -WM- -I"%INCLUDE%"
set CPPCOMPFLAGS=-c -3 -a8  -b -w- -WM- -DBORLAND -DIBMPC -DMSWIND -I"%MATLAB%\extern\include\cpp" -I"%INCLUDE%"
set DLLCOMPFLAGS=-c -3 -P- -w- -pc -a8 -I"%INCLUDE%"
set OPTIMFLAGS=-O1 -DNDEBUG
set DEBUGFLAGS=-v
set CPPOPTIMFLAGS=-O1 -DNDEBUG
set CPPDEBUGFLAGS=-v
set NAME_OBJECT=-o

rem ********************************************************************
rem Library creation command
rem ********************************************************************
set DLL_MAKEDEF=type %BASE_EXPORTS_FILE% | %PERL% -e "print \"LIBRARY %MEX_NAME%.dll\nEXPORTS\n\"; while (<>) {print "_" . $_;}" > "%OUTDIR%%MEX_NAME%.def"
set DLL_MAKEDEF1=implib "%OUTDIR%%MEX_NAME%.lib" "%OUTDIR%%MEX_NAME%.def"

rem ********************************************************************
rem Linker parameters
rem MATLAB_EXTLIB is set automatically by mex.bat
rem ********************************************************************
set LIBLOC=%MATLAB%\extern\lib\win32\borland\bc54
set LINKER=bcc32
set LINK_LIBS=libmmfile.lib libmatlb.lib libmx.lib libmat.lib
set LINKFLAGS=-Twe -L"%BORLAND%"\lib\32bit -L"%BORLAND%"\lib -L"%LIBLOC%" %LINK_LIBS%
set CPPLINKFLAGS=%LINKFLAGS% %MATLAB_EXTLIB%\libmatpb55.lib %LINK_LIBS%
set DLLLINKFLAGS=-tWCD -L"%BORLAND%"\lib\32bit -L"%BORLAND%\lib" -L"%LIBLOC%" %LINK_LIBS%
set HGLINKFLAGS=%LINKFLAGS% sgl.lib libmwsglm.lib
set HGCPPLINKFLAGS=%CPPLINKFLAGS% sgl.lib libmwsglm.lib
set HGDLLLINKFLAGS=%DLLLINKFLAGS% sgl.lib libmwsglm.lib
set LINKOPTIMFLAGS=
set LINKDEBUGFLAGS=-v
set LINK_FILE=
set LINK_LIB= 
set NAME_OUTPUT=-e"%OUTDIR%%MEX_NAME%.exe"
set DLL_NAME_OUTPUT=-e"%OUTDIR%%MEX_NAME%.dll"
set RSP_FILE_INDICATOR=@

rem ********************************************************************
rem Resource compiler parameters
rem ********************************************************************
set RC_COMPILER=
set RC_LINKER=

set POSTLINK_CMDS1=if exist "%OUTDIR%%MEX_NAME%.def" del "%OUTDIR%%MEX_NAME%.def"
set POSTLINK_CMDS2=if exist "%MEX_NAME%.map" del "%MEX_NAME%.map"

set USE_HG=-1