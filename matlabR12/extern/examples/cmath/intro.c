/*
 * intro.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */
 
/* $Revision: 1.2 $ */
 
#include <stdio.h>
#include <stdlib.h>     
#include <string.h>
#include "matlab.h"   

int main()
{   
    double num1, num2;
    mxArray *volatile factors1 = NULL;
    mxArray *volatile factors2 = NULL;
    mxArray *volatile common_factors = NULL;

    mlfEnterNewContext(0,0);
	
    /* Get user input and convert from string to integer */
    mlfPrintf("Enter a number: ");
    scanf("%lf", &num1);
    mlfPrintf("Enter a second number: ");
    scanf("%lf", &num2);

    mlfTry
    {   /* Call MATLAB C Math Library Functions  */
        /* Get factors of input numbers */
        mlfAssign(&factors1,mlfFactor(mlfScalar(num1)));
        mlfAssign(&factors2,mlfFactor(mlfScalar(num2)));

        /* Determine if there are factors in common */
        mlfAssign(&common_factors,
                  mlfIntersect(NULL,NULL,factors1,factors2,NULL));
        
        /* If common_factors is an empty array,
        /* the numbers are relatively prime */

        if(mlfTobool(mlfIsempty(common_factors)))
            mlfPrintf("%0.0lf and %0.0lf are relatively prime\n",num1,num2);
        else
        {	
            mlfPrintf("%0.0lf and %0.0lf share common factor(s):",num1,num2);
            mlfPrintMatrix(common_factors);
        }
    }  /* end try block */
    mlfCatch
    {
        mlfPrintf("In catch block:\n");
        mlfPrintMatrix(mlfLasterr(NULL)); 
    }
    mlfEndCatch  /* end catch block */

    mlfRestorePreviousContext(0,0);

    mxDestroyArray(factors1);
    mxDestroyArray(factors2);
    mxDestroyArray(common_factors);

    return(EXIT_SUCCESS);
}
