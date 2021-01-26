/*
 * ex2.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */
 
/* $Revision: 1.6 $ */
 
#include <stdio.h>
#include <stdlib.h>     /* used for EXIT_SUCCESS */
#include <string.h>

#include "matlab.h"

static double real_data1[] = { 1, 2, 3, 4, 5, 6 };
static double real_data2[] = { 6, 5, 4, 3, 2, 1 };

mxArray *Automated_Mem_Example(mxArray **z_out, mxArray *x_in,
                    mxArray *y_in)
{
    mxArray *result_local = NULL;
    mxArray *q_local = NULL;

    mlfEnterNewContext(1, 2, z_out, x_in, y_in);

    /* In MATLAB: result = sqrt(sin(x) + cos(x)) */
    mlfAssign(&result_local,
              mlfSqrt(mlfPlus(mlfSin(x_in), mlfCos(x_in))));

    /* In MATLAB: q = sqrt(cos(y) - sin(y)) */
    mlfAssign(&q_local,
              mlfSqrt(mlfMinus(mlfCos(y_in), mlfSin(y_in))));

    /* In MATLAB: z = q * result - q^3 */
    mlfAssign(z_out,
              mlfMinus(mlfTimes(q_local, result_local),
                  mlfPower(q_local, mlfScalar(3))));

    mxDestroyArray(q_local);
    mlfRestorePreviousContext(1, 2, z_out, x_in, y_in);
    return mlfReturnValue(result_local);
}

int main()
{
    mxArray *mat0 = NULL;
    mxArray *output_array = NULL;
    mxArray *result_array = NULL;

    mlfEnterNewContext(0, 0);

    mlfAssign(&mat0, mlfDoubleMatrix(2, 3, real_data1, NULL));


    mlfAssign(&result_array,
              Automated_Mem_Example(&output_array,
                         mat0,
                         mlfDoubleMatrix(2, 3, real_data2, NULL)));

    /* Print the matrices. */
    mlfPrintf("mat0:\n");
    mlfPrintMatrix(mat0);
    mlfPrintf("output_array:\n");
    mlfPrintMatrix(output_array);
    mlfPrintf("result_array:\n");
    mlfPrintMatrix(result_array);

    mxDestroyArray(mat0);
    mxDestroyArray(result_array);
    mxDestroyArray(output_array);

    mlfRestorePreviousContext(0, 0);
    return(EXIT_SUCCESS);
}
