C
C
C     matdemo1.f
C
C     This is a simple program that illustrates how to call the MATLAB
C     MAT-file functions from a FORTRAN program.  This demonstration
C     focuses on writing MAT-files.
C
C Copyright (c) 1996-1998 by The MathWorks, Inc.
C All Rights Reserved.
C=====================================================================
C $Revision: 1.3 $
C     matdemo1 - create a new MAT-file from scratch.
C
      program matdemo1
C--------------------------------------------------------------------
C     (pointer) Replace integer by integer*8 on the DEC alpha and the
C     SGI64 platforms
C
      integer matOpen, mxCreateFull, mxCreateString 
      integer matGetMatrix, mxGetPr
      integer mp, pa1, pa2, pa3
C--------------------------------------------------------------------
C
C     Other variable declarations here
C     
      integer status, matClose
      double precision dat(9)
      data dat / 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 /
C
C     Open MAT-file for writing
C
      write(6,*) 'Creating MAT-file matdemo.mat ...'
      mp = matOpen('matdemo.mat', 'w')
      if (mp .eq. 0) then
         write(6,*) 'Can''t open ''matdemo.mat'' for writing.'
         write(6,*) '(Do you have write permission in this directory?)'
         stop
      end if
C
C     Create variables
C
      pa1 = mxCreateFull(3,3,0)
      call mxSetName(pa1, 'Numeric')
C
      pa2 = mxCreateString('MATLAB: The language of computing')
      call mxSetName(pa2, 'String')
C
      pa3 = mxCreateString('MATLAB: The language of computing')
      call mxSetName(pa3, 'String2')
C
      call matPutMatrix(mp, pa1)
      call matPutMatrix(mp, pa2)
      call matPutMatrix(mp, pa3)
C
C     Whoops! Forgot to copy the data into the first matrix -- 
C     it is now blank.  Well, ok, this was deliberate.  This 
C     demonstrates that matPutMatrix will overwrite existing 
C     matrices.
C
      call mxCopyReal8ToPtr(dat, mxGetPr(pa1), 9)
      call matPutMatrix(mp, pa1)
C
C     We will delete String2 from the MAT-file.
C
      call matDeleteMatrix(mp, 'String2')
C     
C     Finally, read back in MAT-file to make sure we know what we put
C     in it.
C
      status = matClose(mp)
      if (status .ne. 0) then
         write(6,*) 'Error closing MAT-file'
         stop
      end if
C
      mp = matOpen('matdemo.mat', 'r')
      if (status .ne. 0) then
         write(6,*) 'Can''t open ''matdemo.mat'' for reading.'
         stop
      end if
C
      pa1 = matGetMatrix(mp, 'Numeric')
      if (mxIsNumeric(pa1) .eq. 0) then
         write(6,*) 'Invalid non-numeric matrix written to MAT-file'
         stop
      end if
C
      pa2 = matGetMatrix(mp, 'String')
      if (mxIsString(pa2) .eq. 0) then
         write(6,*) 'Invalid non-numeric matrix written to MAT-file'
         stop
      end if
C
      pa3 = matGetMatrix(mp, 'String2')
      if (pa3 .ne. 0) then
         write(6,*) 'String2 not deleted from MAT-file'
         stop
      end if
C
C     clean up memory
      call mxFreeMatrix(pa1)
      call mxFreeMatrix(pa2)
      call mxfreeMatrix(pa3)
      status = matClose(mp)
      if (status .ne. 0) then
         write(6,*) 'Error closing MAT-file'
         stop
      end if
C
      write(6,*) 'Done creating MAT-file'
      stop
      end
