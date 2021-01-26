/*
 * ex6.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */
 
/* $Revision: 1.8 $ */

#include <stdio.h>
#include <stdlib.h>     
#include <string.h>
#include "matlab.h"  

static double data[] = { 1, 2, 3, 4, 5, 6 };

main()
{
    mxArray *mat0 = NULL;
    mxArray *mat1 = NULL;
    mxArray *volatile mat2 = NULL;

    mlfEnterNewContext(0,0);

    mlfAssign(&mat0, mlfDoubleMatrix(2, 3, data, NULL));
    mlfAssign(&mat1, mlfDoubleMatrix(3, 2, data, NULL));

    mlfTry 
    {
        mlfAssign(&mat2, mlfRdivide(mat1, mlfScalar(0)));

        mlfPrintf("Return to try block after warning.\n");

        mlfPrintMatrix(mlfPlus(mat0, mat1));
    }
    mlfCatch 
    {
        mlfPrintf("In catch block. Caught an error: ");
        mlfPrintMatrix(mlfLasterr(NULL));
    }
    mlfEndCatch

    mlfPrintf("Now in application after catch block.\n");

    mxDestroyArray(mat0);
    mxDestroyArray(mat1);
    mxDestroyArray(mat2);

    mlfRestorePreviousContext(0, 0);
	
    return(EXIT_SUCCESS);
}
