/*=================================================================
 * mxislogical.c 
 * This example demonstrates how to use mexIsGlobal, mexGetArrayPtr,
 * mxIsLogical, mxSetLogical, mxClearLogical.  You pass in the name of
 * a variable in the caller workspace.  It then gets the pointer to
 * that variable. If the variable is in the global workspace, the
 * function errors out because in this example you do not want to
 * modify data that is in the global workspace.  If the variable is
 * not a global variable, it toggles the variables' logical flag in
 * the MATLAB workspace.
 *
 * This is a MEX-file for MATLAB.  
 * Copyright 1984-2000 The MathWorks, Inc. 
 *=================================================================*/
/* $Revision: 1.5 $ */
#include "mex.h"

void
mexFunction(int nlhs,mxArray *plhs[],int nrhs,const mxArray *prhs[])
{
    mxArray  *array_ptr;
    char     *variable;

    /* Check for proper number of input and output arguments */    
    if (nrhs != 1) {
	mexErrMsgTxt("One input argument required.");
    } 
    if(nlhs > 1){
	mexErrMsgTxt("Too many output arguments.");
    }
    /* Check to be sure input argument is a string. */
    if (!(mxIsChar(prhs[0]))){
	mexErrMsgTxt("Input must be of type string.\n.");
    }
    
    /* Get input variable */
    variable= mxArrayToString(prhs[0]);
    array_ptr = (mxArray *)mexGetArrayPtr(variable, "caller");
    if (array_ptr == NULL){
	mexErrMsgTxt("Could not get variable.\n");
    }

    /* NOTE: You should be careful not modify data that is in the global
       workspace if this is not your intension. */
    if (mexIsGlobal(array_ptr)) {
	mexErrMsgTxt("The variable you requested is global.\n");
    }  
    mexPrintf("%s is not a global\n",variable);

    if(mxIsLogical(array_ptr)) {
	mxClearLogical(array_ptr);
    } else {
	mxSetLogical(array_ptr);
    }

    mxFree(variable);
    
}


