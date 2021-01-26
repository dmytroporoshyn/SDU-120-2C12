/*
 * $Revision: 1.3 $
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "matlab.h"

/*
 * Function prototype; the MATLAB Compiler creates mlfMultarg 
 *  from multarg.m
 */
mxArray * mlfMultarg( mxArray **, mxArray *, mxArray * );

void PrintHandler( const char *text )
{
    printf(text);
}

int main( )   /* Programmer written coded to call mlfMultarg */
{
#define ROWS  3 
#define COLS  3

    mxArray *a, *b, *x, *y; 
    double  x_pr[ROWS * COLS] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    double  x_pi[ROWS * COLS] = {9, 2, 3, 4, 5, 6, 7, 8, 1}; 
    double  y_pr[ROWS * COLS] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    double  y_pi[ROWS * COLS] = {2, 9, 3, 4, 5, 6, 7, 1, 8}; 
    double *a_pr, *a_pi, value_of_scalar_b;

    /* Install a print handler to tell mlfPrintMatrix how to
     * display its output.
     */
    mlfSetPrintHandler(PrintHandler);
    
    /* Create input matrix "x" */ 
    x = mxCreateDoubleMatrix(ROWS, COLS, mxCOMPLEX); 
    memcpy(mxGetPr(x), x_pr, ROWS * COLS * sizeof(double));
    memcpy(mxGetPi(x), x_pi, ROWS * COLS * sizeof(double));
    
    /* Create input matrix "y" */ 
    y = mxCreateDoubleMatrix(ROWS, COLS, mxCOMPLEX); 
    memcpy(mxGetPr(y), y_pr, ROWS * COLS * sizeof(double));
    memcpy(mxGetPi(y), y_pi, ROWS * COLS * sizeof(double));
    
    /* Call the mlfMultarg function. */
    a = mlfMultarg(&b, x, y); 
    
    /* Display the entire contents of output matrix "a". */
    mlfPrintMatrix(a);
    
    /* Display the entire contents of output scalar "b" */
    mlfPrintMatrix(b);
    
    /* Deallocate temporary matrices. */
    mxDestroyArray(a);
    mxDestroyArray(b);
    return(0);
}
