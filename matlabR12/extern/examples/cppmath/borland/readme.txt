% $Revision: 1.2 $
Readme For Borland 5.x IDE Template Files For Use With C/C++ Math 
Library 2.1/MATLAB 6.0


This readme describes the steps you need to take to configure project
template files for Borland 5.0, 5.2(5.02), Borland C++Builder 3.0
which contains Borland C 5.3, and Borland C++Builder 4.0 which
contains Borland C 5.4 for use with the C++ Math Library 2.1. The
template project files are configured by default to compile example 1
in %MATLAB%\extern\examples\cppmath, where %MATLAB% is the root
directory where your MATLAB is installed.

Borland 5.0:

1.)  Open the project, borland50.ide, in Borland 5.0.

2.)  From the Options pull-down menu select Project. In the window
that appears select Directories. An area labeled Source Directories
should now be displayed in the editable window on the right side of
the window. In this area, modify the Include and Library paths to 
point to your installation of MATLAB and Borland.

3.)  You should now be able to build the project.   


Borland 5.2:

1.)   Open the project, borland52.ide, in Borland 5.2.

2.)  From the Options pull-down menu select Project. In the window 
that appears select Directories. An area labeled Source Directories
should now be displayed in the editable window on the right side of
the window. In this area, modify the Include and Library paths to 
point to your installation of MATLAB and Borland.

3.)  You should now be able to build the project.   


Borland C++Builder 3.0 which contain Borland C 5.3: 

1.)  Open in an editor the file mk_borland53_libs.bat that lives
in your %MATLAB%\extern\lib\win32 directory. Edit the first line of the 
file so that the MATLAB variable points to the location of MATLAB
on on your machine.  Once you have modified the file, execute the
file from the DOS prompt in your %MATLAB%\extern\lib\win32 directory.
This will create the necessary libraries needed to compile the 
standalone executable. This step is necessary because Borland C++Builder 3.0
does not automatically create .lib files from .def files.

2.)  Open the project, borland53.bpr, in Borland C++Builder 3.0.

3.)  From the Project pull-down menu select Options. In the window 
that appears select the Directories/Conditionals tab. Modify the 
Include and Library paths to point to your installation of MATLAB.

4.)  You should now be able to build the project.   


Borland C++Builder 4.0 which contain Borland C 5.4:

1.)  Open in an editor the file mk_borland54_libs.bat that lives in
your %MATLAB%\extern\lib\win32 directory. Edit the first line of the file so
that the MATLAB variable points to the location of MATLAB on on your
machine.  Once you have modified the file, execute the file from the
DOS prompt in your %MATLAB%\extern\lib\win32 directory.  This will create the
necessary libraries needed to compile the standalone executable. This
step is necessary because Borland C++Builder 4.0 does not
automatically create .lib files from .def files.

2.)  Open the project, borland54.bpr, in Borland C++Builder 4.0.

3.)  From the Project pull-down menu select Options. In the window 
that appears select the Directories/Conditionals tab. Modify the 
Include and Library paths to point to your installation of MATLAB.

4.)  You should now be able to build the project.
