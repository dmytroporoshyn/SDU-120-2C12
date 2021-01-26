@echo off
rem BCCENGMATOPTS.BAT
rem
rem    Compile and link options used for building MEX-files
rem    with the Borland C compiler
rem
rem    $Revision: 1.18 $  $Date: 2000/04/04 17:07:27 $
rem
rem ********************************************************************
rem General parameters
rem ********************************************************************
set MATLAB=%MATLAB%
set BORLAND=%BORLAND%
set PATH=%BORLAND%\BIN;%PATH%
set INCLUDE=%BORLAND%\INCLUDE
set LIB=%BORLAND%\LIB;%BORLAND%\LIB\32BIT
set NAME_OBJECT=-o

rem ********************************************************************
rem Compiler parameters
rem ********************************************************************
set COMPILER=bcc32
set COMPFLAGS=-c -3 -a8 -w- -b -g30 -I"%INCLUDE%"
set OPTIMFLAGS=-O1 -DNDEBUG
set DEBUGFLAGS=-v

rem ********************************************************************
rem Linker parameters
rem ********************************************************************
set LIBLOC=%MATLAB%\extern\lib\win32\borland\bc50
set LINKER=bcc32
set LINKFLAGS=-tWE -L"%BORLAND%"\lib\32bit -L"%BORLAND%"\lib
set LINKFLAGS=%LINKFLAGS% -L"%LIBLOC%" libmx.lib libmat.lib libeng.lib
set LINKOPTIMFLAGS=
set LINKDEBUGFLAGS=-v
set LINK_FILE=
set LINK_LIB= 
set NAME_OUTPUT=-e"%OUTDIR%%MEX_NAME%".exe
set RSP_FILE_INDICATOR=@

rem ********************************************************************
rem Resource compiler parameters
rem ********************************************************************
set RC_COMPILER=
set RC_LINKER=
