/*
 * ex1.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */
 
/* $Revision: 1.6 $ */
 
#include <stdio.h>
#include <stdlib.h>     /* used for EXIT_SUCCESS */
#include <string.h>

#include "matlab.h"

static double real_data[] = { 1, 2, 3, 4, 5, 6 };
static double cplx_data[] = { 7, 8, 9, 10, 11, 12 };

int main()
{
    /* Declare two matrices and initialize to NULL */
    mxArray *mat0 = NULL;
    mxArray *mat1 = NULL;

    /* Enable automated memory management */
    mlfEnterNewContext(0, 0);

    /* Create the matrices and assign data to them */
    mlfAssign(&mat0, mlfDoubleMatrix(2, 3, real_data, NULL));
    mlfAssign(&mat1, mlfDoubleMatrix(3, 2, real_data, cplx_data));

    /* Print the matrices */
    mlfPrintMatrix(mat0);
    mlfPrintMatrix(mat1);

    /* Free the matrices */
    mxDestroyArray(mat0);
    mxDestroyArray(mat1);

    /* Disable automated memory management */
    mlfRestorePreviousContext(0, 0);

    return(EXIT_SUCCESS);
}
