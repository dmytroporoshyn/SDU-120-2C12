/*
 * MRANKWIN
 * Windows C main program illustrating the use of the MATLAB Math Library.
 * Calls mlfMrank, obtained by using MCC to compile mrank.m.
 *
 * $Revision: 1.3 $ 
 */

#include <stdio.h>
#include <math.h>
#include "matlab.h"
#include <windows.h>

/* Prototype for mlfMrank */
extern mxArray * mlfMrank( mxArray * );

static int totalcnt  = 0;
static int upperlim  = 0;
static int firsttime = 1;
char *OutputBuffer;

void WinPrint( char *text )
{
    int cnt;
    
    if (firsttime) {
        OutputBuffer = (char *)mxCalloc(1028, 1);
        upperlim += 1028;
        firsttime = 0;
    }
    
    cnt = strlen(text);
    if (totalcnt + cnt >= upperlim) {
        char *TmpOut;
        TmpOut = (char *)mxCalloc(upperlim + 1028, 1);
        memcpy(TmpOut, OutputBuffer, upperlim);
        upperlim += 1028;
        mxFree(OutputBuffer);
        OutputBuffer = TmpOut;
    }
    strncat(OutputBuffer, text, cnt);
}


void WinFlush(void)
{
    MessageBox(NULL, OutputBuffer, "MRANK", MB_OK);
    mxFree(OutputBuffer);
}


WINAPI
WinMain( HANDLE hInstance, HANDLE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow )
{
#define MAXCMDTOKENS 128

    LPSTR argv[MAXCMDTOKENS];
    int   argc = 0;
    
    mxArray *N;    /* matrix containing n. */
    mxArray *R;    /* Result matrix.       */
    int      n;    /* Integer parameter from command line. */
    
    PkgInitialize();  /* Initialize the library of M-Functions */
    /* Estlablish print handler */
    mlfSetPrintHandler(WinPrint);
    
    
    /* Get any command line parameter. */
    argv[argc] = "mrank.exe";
    argv[++argc] = strtok(lpszCmdLine, " ");
    while (argv[argc] != NULL) argv[++argc] = strtok(NULL, " ");
    if (argc >= 2) {
        n = atoi(argv[1]);
    } else {
        n = 12;
    }
    
    /* Create a 1-by-1 matrix containing n. */
    N = mxCreateDoubleMatrix(1, 1, mxREAL);
    *mxGetPr(N) = n;
    
    /* Call mlfMrank, the compiled version of mrank.m. */
    R = mlfMrank(N);
    
    /* Print the results. */
    mlfPrintMatrix(R);
    WinFlush();
    
    /* Free the matrices allocated during this computation. */
    mxDestroyArray(N);
    mxDestroyArray(R);
    
    PkgTerminate();    /* Terminate the library of M-functions */

    return(0);
}
