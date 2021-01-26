/*
 * ex3.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */
 
/* $Revision: 1.1 $ */
 
#include <stdio.h>
#include <stdlib.h>     /* used for EXIT_SUCCESS */
#include <string.h>

#define MLF_V1_2        /* used for C Math Library 1.2 declarations */
#include "matlab.h"

static double data[] = { 1, 3, 5, 7, 2, 4, 6, 8 };

int main()
{
    /* create two matrices */
    mxArray *X = mxCreateDoubleMatrix(4, 2, mxREAL);
    mxArray *U, *S, *V, *W = mlfScalar(0.0);

    memcpy(mxGetPr(X), data, 8*sizeof(double));

    /* compute the singular value decompostiion and print it */
    mlfPrintf("One input, one output:\nU = \n");
    mlfPrintMatrix(U=mlfSvd(0, 0, X, 0));
    mxDestroyArray(U);

    /* multiple output arguments */
    U = mlfSvd(&S, &V, X, 0);
    mlfPrintf("One input, three outputs:\n");
    mlfPrintf("U = \n"); mlfPrintMatrix(U); mxDestroyArray(U);
    mlfPrintf("S = \n"); mlfPrintMatrix(S); mxDestroyArray(S);
    mlfPrintf("V = \n"); mlfPrintMatrix(V); mxDestroyArray(V);

    /* multiple input and output arguments */
    U = mlfSvd(&S, &V, X, W);
    mlfPrintf("Two inputs, three outputs:\n");
    mlfPrintf("U = \n"); mlfPrintMatrix(U); mxDestroyArray(U);
    mlfPrintf("S = \n"); mlfPrintMatrix(S); mxDestroyArray(S);
    mlfPrintf("V = \n"); mlfPrintMatrix(V); mxDestroyArray(V);

    /* free the matrices */
    mxDestroyArray(X);
    mxDestroyArray(W);

    return(EXIT_SUCCESS);
}
