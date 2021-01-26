@echo off
rem MSVC60COMPP.BAT
rem
rem    Compile and link options used for building MATLAB compiler programs
rem    with Microsoft Visual C++ compiler version 6.0 
rem
rem    $Revision: 1.12 $  $Date: 2000/08/11 15:53:32 $
rem
rem ********************************************************************
rem General parameters
rem ********************************************************************
set MATLAB=%MATLAB%
set MSVCDir=%MSVCDir%
set MSDevDir=%MSVCDir%\..\Common\msdev98
set PATH=%MSVCDir%\BIN;%MSDevDir%\bin;%MATLAB_BIN%;%PATH%
set INCLUDE=%MSVCDir%\INCLUDE;%MSVCDir%\MFC\INCLUDE;%MSVCDir%\ATL\INCLUDE;%INCLUDE%
set LIB=%MSVCDir%\LIB;%MSVCDir%\MFC\LIB;%LIB%
set PERL="%MATLAB%\sys\perl\win32\bin\perl.exe"

rem ********************************************************************
rem Compiler parameters
rem ********************************************************************
set COMPILER=cl
set OPTIMFLAGS=-O2 -DNDEBUG
set DEBUGFLAGS=-Zi -Fd"%OUTDIR%%MEX_NAME%.pdb"
set CPPOPTIMFLAGS=-O2 -DNDEBUG
set CPPDEBUGFLAGS=-Zi -Fd"%OUTDIR%%MEX_NAME%.pdb"
set COMPFLAGS=-c -Zp8 -G5 -W3 -nologo
set CPPCOMPFLAGS=-c -Zp8 -G5 -W3 -nologo -Zm500 -GX -MD -I"%MATLAB%\extern\include\cpp" -DMSVC -DIBMPC -DMSWIND
set DLLCOMPFLAGS=-c -Zp8 -G5 -W3 -nologo -DMSVC -DIBMPC -DMSWIND
set NAME_OBJECT=/Fo

rem ********************************************************************
rem Library creation commands creating import and export libraries
rem ********************************************************************
set DLL_MAKEDEF=type %BASE_EXPORTS_FILE% | %PERL% -e "print \"LIBRARY %MEX_NAME%.dll\nEXPORTS\n\"; while (<>) {print;}" > %DEF_FILE%

rem ********************************************************************
rem Linker parameters
rem MATLAB_EXTLIB is set automatically by mex.bat
rem ********************************************************************
set LIBLOC=%MATLAB%\extern\lib\win32\microsoft\msvc60
set LINKER=link
set LINKFLAGS=kernel32.lib user32.lib gdi32.lib /LIBPATH:"%LIBLOC%" libmmfile.lib libmatlb.lib /nologo 
set LINKFLAGS=%LINKFLAGS% libmx.lib libmat.lib
set CPPLINKFLAGS=%LINKFLAGS% %MATLAB_EXTLIB%\libmatpm.lib
set DLLLINKFLAGS=%LINKFLAGS% /dll /implib:"%OUTDIR%%MEX_NAME%.lib" /def:%DEF_FILE%
set HGLINKFLAGS=%LINKFLAGS% sgl.lib libmwsglm.lib
set HGCPPLINKFLAGS=%CPPLINKFLAGS% sgl.lib libmwsglm.lib
set HGDLLLINKFLAGS=%DLLLINKFLAGS% sgl.lib libmwsglm.lib
set LINKOPTIMFLAGS=
set LINKDEBUGFLAGS=/debug
set LINK_FILE=
set LINK_LIB=
set NAME_OUTPUT="/out:%OUTDIR%%MEX_NAME%.exe"
set DLL_NAME_OUTPUT="/out:%OUTDIR%%MEX_NAME%.dll"
set RSP_FILE_INDICATOR=@

rem ********************************************************************
rem Resource compiler parameters, for versioning
rem ********************************************************************
set RC_COMPILER=
set RC_LINKER= 

set POSTLINK_CMDS1=if exist %LIB_NAME%.def del %LIB_NAME%.def
set USE_HG=-1
