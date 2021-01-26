@rem $Revision: 1.2 $
set MATLAB=%MATLAB%

implib _libmmfile.lib "%MATLAB%\extern\include\_libmmfile.def"

implib _libmatlb.lib "%MATLAB%\extern\include\_libmatlb.def"

implib _libmx.lib "%MATLAB%\extern\include\_libmx.def"

implib _libmat.lib "%MATLAB%\extern\include\_libmat.def"
