/*
 * ex5.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */

/* $Revision: 1.13 $ */

#include <stdlib.h>
#include "matlab.h"

main()
{
    mxArray *x = NULL, *y = NULL, *z = NULL;
    mxArray *a = NULL, *b = NULL, *c = NULL;

    mlfEnterNewContext(0, 0);

    mlfAssign(&x, mlfRand(mlfScalar(4),mlfScalar(4),NULL));
    mlfAssign(&y, mlfMagic(mlfScalar(7)));
    mlfAssign(&z, mlfEig(NULL, x, NULL, NULL));

    /* Save (and name) the variables */
    mlfSave(mxCreateString("ex5.mat"), "w",
               "x", x, "y", y, "z", z, NULL);

    /* Load the named variables */
    mlfLoad(mxCreateString("ex5.mat"),
               "x", &a, "y", &b, "z", &c, NULL);

    /* Check to be sure that the variables are equal */
    if (mlfTobool(mlfIsequal(a, x, NULL)) && 
        mlfTobool(mlfIsequal(b, y, NULL)) && 
        mlfTobool(mlfIsequal(c, z, NULL)))
    {

        mlfPrintf("Success: all variables equal.\n");
    }
    else
    {
        mlfPrintf("Failure: loaded values not equal to                    saved values.\n");
    }

    mxDestroyArray(x);
    mxDestroyArray(y);
    mxDestroyArray(z);
    mxDestroyArray(a);
    mxDestroyArray(b);
    mxDestroyArray(c);

    mlfRestorePreviousContext(0, 0);

    return(EXIT_SUCCESS);
}
