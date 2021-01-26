/*
 * ex4.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */
 
/* $Revision: 1.1 $ */

#include <stdio.h>
#include <stdlib.h>     /* used for EXIT_SUCCESS */
#include <string.h>
#include <setjmp.h>     /* needed for setjmp, longjmp */

#define MLF_V1_2        /* used for C Math Library 1.2 declarations */
#include "matlab.h"

/* Matrix data. Column-major element order */
static double data[] = { 1, 2, 3, 4, 5, 6 };

/* Setjmp/longjmp buffer */
static jmp_buf env;

/* User-defined error handling routine. */
void ErrorHandler(const char* msg, bool isError)
{
    if (isError)
    {
        mlfPrintf("ERROR: %s\n", msg);
        longjmp(env, -1);
    }
    else /* just a warning */
    {
        mlfPrintf("WARNING: %s\n", msg);
    }
}

int main()
{
    /* Create two matrices */
    mxArray *mat0 = mxCreateDoubleMatrix(2, 3, mxREAL);
    mxArray *mat1 = mxCreateDoubleMatrix(3, 2, mxREAL);

    /* 
     * These pointers must be declared as volatile, since their values may be
     * changed inside a setjmp block, and we need to access these values if
     * a longjmp occurs.
     */
    mxArray * volatile mat2 = NULL;
    mxArray * volatile mat3 = NULL;
    mxArray * volatile zero = NULL;
    
    memcpy(mxGetPr(mat0), data, 6 * sizeof(double));
    memcpy(mxGetPr(mat1), data, 6 * sizeof(double));
  
    if (setjmp(env) == 0) {
        /* Set the error handler */
        mlfSetErrorHandler(ErrorHandler);
        
        /* Create a scalar matrix*/
        zero = mlfScalar(0);

        /* Division by zero will produce a warning */
        mat2 = mlfRdivide(mat1, zero);

        /* Illegal operation: dimensions not equal */
        mat3 = mlfPlus(mat0, mat1);
        mlfPrintMatrix(mat3);

        /* free the matrices */
        mxDestroyArray(mat2);
        mxDestroyArray(mat3);
        mxDestroyArray(zero);

    } else {
        mlfPrintf("Caught an error! Recovering!\n");
        
        /* clean up any matrices allocated before the error occurred */
        if (mat2) mxDestroyArray(mat2);
        if (mat3) mxDestroyArray(mat3);
        if (zero) mxDestroyArray(zero);
    }
    
    /* free the matrices */
    mxDestroyArray(mat0);
    mxDestroyArray(mat1);

    return(EXIT_SUCCESS);
}
