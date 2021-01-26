/*
 * ex3.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */
 
/* $Revision: 1.7 $ */
 
/* ex3.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matlab.h"

static double data[] = { 1, 3, 5, 7, 2, 4, 6, 8 };

main()
{
    /* Initialize pointers to array arguments */
    mxArray *X = NULL;
    mxArray *U = NULL, *S = NULL, *V = NULL;

    mlfEnterNewContext(0, 0);

    mlfAssign(&X, mlfDoubleMatrix(4, 2, data, NULL));

    /* Compute the singular value decomposition and print it */
    mlfAssign(&S, mlfSvd(NULL, NULL, X, NULL));
    mlfPrintf("One input, one output:\n");
    mlfPrintf("S = \n"); mlfPrintMatrix(S);

    /* Multiple output arguments */
    mlfAssign(&U, mlfSvd(&S, &V, X, NULL));
    mlfPrintf("One input, three outputs:\n");
    mlfPrintf("U = \n"); mlfPrintMatrix(U); 
    mlfPrintf("S = \n"); mlfPrintMatrix(S);
    mlfPrintf("V = \n"); mlfPrintMatrix(V);

    /* Multiple input and output arguments */
    mlfAssign(&U, mlfSvd(&S, &V, X, mlfScalar(0.0)));
    mlfPrintf("Two inputs, three outputs:\n");
    mlfPrintf("U = \n"); mlfPrintMatrix(U);
    mlfPrintf("S = \n"); mlfPrintMatrix(S);
    mlfPrintf("V = \n"); mlfPrintMatrix(V);

    mxDestroyArray(X);
    mxDestroyArray(U);
    mxDestroyArray(S);
    mxDestroyArray(V);

    mlfRestorePreviousContext(0, 0);
    return(EXIT_SUCCESS);
}
