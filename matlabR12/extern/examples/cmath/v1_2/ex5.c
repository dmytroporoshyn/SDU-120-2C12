/*
 * ex5.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */

/* $Revision: 1.1 $ */

#include <stdlib.h>    /* used for EXIT_SUCCESS */

#define MLF_V1_2        /* used for C Math Library 1.2 declarations */
#include "matlab.h"

main()
{
    mxArray *x, *y, *z, *a, *b, *c;
    mxArray *r1, *r2, *r3;
    mxArray *four = mlfScalar(4);
    mxArray *seven = mlfScalar(7);
    
    x = mlfRand(four,four);
    y = mlfMagic(seven);
    z = mlfEig(NULL, x, NULL);
    
    /* Save (and name) the variables */
    mlfSave("ex5.mat", "w", "x", x, "y", y, "z", z, NULL);
    
    /* Load the named variables */
    mlfLoad("ex5.mat", "x", &a, "y", &b, "z", &c, NULL);
    
    /* Check to be sure that the variables are equal */
    
    r1 = mlfIsequal(a, x, NULL);
    r2 = mlfIsequal(b, y, NULL);
    r3 = mlfIsequal(c, z, NULL);
    
    if (*mxGetPr(r1) == 1.0 && 
        *mxGetPr(r2) == 1.0 && 
        *mxGetPr(r3) == 1.0)
      {
          mlfPrintf("Success: all variables equal.\n");
      }
    else
      {
          mlfPrintf("Failure: loaded values not equal to saved values.\n");
      }
    
    mxDestroyArray(four);
    mxDestroyArray(seven);
    mxDestroyArray(x);
    mxDestroyArray(y);
    mxDestroyArray(z);
    mxDestroyArray(a);
    mxDestroyArray(b);
    mxDestroyArray(c);
    mxDestroyArray(r1);
    mxDestroyArray(r2);
    mxDestroyArray(r3);
    
    return(EXIT_SUCCESS);
}
