/*
 * MRANKP.C
 * "Posix" C main program illustrating the use of the MATLAB Math Library.
 * Calls mlfMrank, obtained by using MCC to compile mrank.m.
 *
 * $Revision: 1.3 $
 *
 */

#include <stdio.h>
#include <math.h>
#include "matlab.h"

/* Prototype for mlfMrank */
extern mxArray *mlfMrank( mxArray * );

main( int argc, char **argv )
{
    mxArray *N;    /* Matrix containing n. */
    mxArray *R;    /* Result matrix. */
    int      n;    /* Integer parameter from command line. */

    /* Get any command line parameter. */
    if (argc >= 2) {
        n = atoi(argv[1]);
    } else {
        n = 12;
    }
    PkgInitialize();  /* Initialize the library of M-Functions */
    
    /* Create a 1-by-1 matrix containing n. */
    N = mlfScalar(n);
    
    /* Call mlfMrank, the compiled version of mrank.m. */
    R = mlfMrank(N);
    
    /* Print the results. */
    mlfPrintMatrix(R);
    
    /* Free the matrices allocated during this computation. */
    mxDestroyArray(N);
    mxDestroyArray(R);

    PkgTerminate();    /* Terminate the library of M-functions */
}
