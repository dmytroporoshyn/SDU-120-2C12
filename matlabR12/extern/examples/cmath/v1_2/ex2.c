/*
 * ex2.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */
 
/* $Revision: 1.1 $ */
 
#include <stdio.h>
#include <stdlib.h>     /* used for EXIT_SUCCESS */
#include <string.h>

#define MLF_V1_2        /* used for C Math Library 1.2 declarations */
#include "matlab.h"

static double data0[] = { 2, 6, 4, 8 };
static double data1[] = { 1, 5, 3, 7 };

/* (m1+m2)/2 */
mxArray * average(mxArray *m1, mxArray *m2)
{
    mxArray *sum, *ave, *two = mlfScalar(2);

    sum = mlfPlus(m1, m2);
    ave = mlfRdivide(sum, two);

    mxDestroyArray(sum);
    mxDestroyArray(two);

    return(ave);
}

int main()
{
    /* create two matrices */
    mxArray *mat0 = mxCreateDoubleMatrix(2, 2, mxREAL);
    mxArray *mat1 = mxCreateDoubleMatrix(2, 2, mxCOMPLEX);
    mxArray *mat2;

    memcpy(mxGetPr(mat0), data0, 4*sizeof(double));
    memcpy(mxGetPr(mat1), data1, 4*sizeof(double));

    mat2 = average(mat0, mat1);
    mlfPrintMatrix(mat0); mlfPrintf(" + \n");
    mlfPrintMatrix(mat1); mlfPrintf(" / 2 = \n");
    mlfPrintMatrix(mat2);

    /* free the matrices */
    mxDestroyArray(mat0);
    mxDestroyArray(mat1);
    mxDestroyArray(mat2);

    return(EXIT_SUCCESS);
}
