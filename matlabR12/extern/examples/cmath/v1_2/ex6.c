/*
 * ex6.c
 *
 * Copyright (c) 1995-1999 by The Mathworks, Inc. All Rights Reserved.
 */
 
/* $Revision: 1.1 $ */
 
#include <stdlib.h>     /* used for EXIT_SUCCESS */

#define MLF_V1_2        /* used for C Math Library 1.2 declarations */
#include "matlab.h"

double SIGMA, RHO, BETA;

mxArray * lorenz(mxArray *tm, mxArray *ym)
{
    mxArray *ypm;
    double *y, *yp;

    ypm = mxCreateDoubleMatrix(3, 1, mxREAL);
    y = mxGetPr(ym);
    yp = mxGetPr(ypm);

    yp[0] = -BETA*y[0] + y[2]*y[1];
    yp[1] = -SIGMA*y[1] + SIGMA*y[2];
    yp[2] = -y[0]*y[1] + RHO*y[1] - y[2];

    return(ypm);
}

static
int _lorenz_thunk_fcn_( mlfFuncp pFunc, int nlhs, mxArray **lhs, int nrhs, mxArray **rhs )
{
  	typedef mxArray * (*PFCN_1_2)( mxArray * , mxArray * );
    mxArray *Out;

    if ( nlhs > 1 || nrhs > 2 ) {
        return(0);
    }
    
    Out = (*((PFCN_1_2)pFunc))(
                               nrhs > 0 ? rhs[0] : 0,
                               nrhs > 1 ? rhs[1] : 0
                               );
    
    if (nlhs > 0) {
        lhs[0] = Out;
    }
    
    return(1);
}

static mlfFuncTabEnt MFuncTab[] = 
{
	{ "lorenz", (mlfFuncp) lorenz, _lorenz_thunk_fcn_ },
	{ 0, 0, 0 }
};

int main()
{
    mxArray *ysm, *tm, *ym, *tsm;
    mxArray *lorenz_function = mxCreateString("lorenz");
    double tspan[] = { 0.0, 10.0 };
    double y0[] = { 10.0, 10.0, 10.0 };
    double *t, *y1, *y2, *y3;
    int     k, n;

    mlfFevalTableSetup ( MFuncTab );
    
    SIGMA = 10.0;
    RHO = 28.0;
    BETA = 8.0/3.0;

    tsm = mxCreateDoubleMatrix(2, 1, mxREAL);
    ysm = mxCreateDoubleMatrix(1, 3, mxREAL);

    memcpy(mxGetPr(tsm), tspan, sizeof(tspan));
    memcpy(mxGetPr(ysm), y0, sizeof(y0));

    tm = mlfOde23(&ym, 0, 0, 0, 0, lorenz_function, tsm, ysm, 0, 0);

    n = mxGetM(tm);
    t = mxGetPr(tm);
    y1 = mxGetPr(ym);
    y2 = y1 + n;
    y3 = y2 + n;

    mlfPrintf("      t         y1        y2          y3\n");
    for(k=0;k<n;k++) {
        mlfPrintf("%9.3f %9.3f %9.3f %9.3f\n",
                  t[k], y1[k], y2[k], y3[k]);
    }

    /* free the matrices */
    mxDestroyArray(tsm);
    mxDestroyArray(ysm);
    mxDestroyArray(tm);
    mxDestroyArray(ym);
    mxDestroyArray(lorenz_function);

    return(EXIT_SUCCESS);
}
