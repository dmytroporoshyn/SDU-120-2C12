/*
 * mwdebug.c
 *
 * Copyright (c) 1984-1999 The MathWorks, Inc. All Rights Reserved.
 * All Rights Reserved.
 * $Revision: 1.27 $
 */

/* Turn off debugging in this file to avoid infinite recursion */
#undef ARGCHECK
#define BEGIN_EXPORT
#define END_EXPORT
#define EXPORT
#include <string.h>
BEGIN_EXPORT
#include "matrix.h"
END_EXPORT
#if defined(MATLAB_MEX_FILE)
# include "mex.h"
#else
# include <stdio.h>
# include <stdlib.h>
#endif
BEGIN_EXPORT
#include "mat.h"
END_EXPORT

#ifdef __cplusplus
    extern "C" {
#endif

#define NULL_INPUT "Invalid NULL input"

static char mwErrorBuffer[512];

static void mwHandleError(const char * fcn, 
			const char *errmsg, 
			const char *file, 
			int linenum)
{
	sprintf(mwErrorBuffer, "Illegal call to %s on line %d of \"%s\": %s",
		  	fcn, linenum, file, errmsg);	
#if defined(MATLAB_MEX_FILE)
	mexErrMsgTxt(mwErrorBuffer);
#else
	fprintf(stderr, mwErrorBuffer);
	exit(EXIT_FAILURE);
#endif
}

#if defined(PRINT_POINTERS)
# if defined(MATLAB_MEX_FILE)
#  define ptrprint(ptr, func) mexPrintf("\n" #func ":" #ptr " = %p\n", ptr)
# else
#  define ptrprint(ptr, func) fprintf(stdout, "\n" #func ":" #ptr " = %p\n", ptr)
# endif
#else
# define ptrprint(ptr, func)
#endif

/*****************************
 * MAT-FILE ACCESS FUNCTIONS *
 *****************************/

EXPORT
int matClose_d(MATFile *ph, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matClose", NULL_INPUT, file, linenum);
	
	ptrprint(ph, matClose);
	
	return matClose(ph);		
}

EXPORT
int matDeleteArray_d(MATFile *ph, const char *name, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matDeleteArray", NULL_INPUT " (input #1)", file, linenum);
	
	if (name == NULL)
		mwHandleError("matDeleteArray", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(ph, matDeleteArray);
	ptrprint(name, matDeleteArray);

	return matDeleteArray(ph, name);
}

EXPORT
mxArray *matGetArray_d(MATFile *ph, const char *name, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matGetArray", NULL_INPUT " (input #1)", file, linenum);
	
	if (name == NULL)
		mwHandleError("matGetArray", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(ph, matGetArray);
	ptrprint(name, matGetArray);

	return matGetArray(ph, name);
}

EXPORT
mxArray *matGetArrayHeader_d(MATFile *ph, const char *name, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matGetArrayHeader", NULL_INPUT " (input #1)", file, linenum);
	
	if (name == NULL)
		mwHandleError("matGetArrayHeader", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(ph, matGetArrayHeader);
	ptrprint(name, matGetArrayHeader);

	return matGetArrayHeader(ph, name);
}

EXPORT
char **matGetDir_d(MATFile *ph, int *num, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matGetDir", NULL_INPUT " (input #1)", file, linenum);
	
	if (num == NULL)
		mwHandleError("matGetDir", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(ph, matGetDir);
	ptrprint(num, matGetDir);

	return matGetDir(ph, num);
}

EXPORT
FILE *matGetFp_d(MATFile *ph, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matGetFp", NULL_INPUT, file, linenum);
	
	ptrprint(ph, matGetFp);
	
	return matGetFp(ph);		
}

EXPORT
mxArray *matGetNextArray_d(MATFile *ph, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matGetNextArray", NULL_INPUT, file, linenum);

	ptrprint(ph, matGetNextArray);
	
	return matGetNextArray(ph);
}

EXPORT
mxArray *matGetNextArrayHeader_d(MATFile *ph, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matGetNextArrayHeader", NULL_INPUT, file, linenum);

	ptrprint(ph, matGetNextArrayHeader);
	
	return matGetNextArrayHeader(ph);
}

EXPORT
MATFile *matOpen_d(const char *filename, const char *mode, const char * file, int linenum)
{
	if (filename == NULL)
		mwHandleError("matOpen", NULL_INPUT " (input #1)", file, linenum);
		
	if (mode == NULL)
		mwHandleError("matOpen", NULL_INPUT " (input #2)", file, linenum);
		
	ptrprint(filename, matOpen);
	ptrprint(mode, matOpen);

	return matOpen(filename, mode);		
}

EXPORT
int matPutArray_d(MATFile *ph, const mxArray *mp, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matPutArray", NULL_INPUT " (input #1)", file, linenum);
	
	if (mp == NULL)
		mwHandleError("matPutArray", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(ph, matPutArray);
	ptrprint(mp, matPutArray);

	return matPutArray(ph, mp);
}

EXPORT
int matPutArrayAsGlobal_d(MATFile *ph, const mxArray *mp, const char * file, int linenum)
{
	if (ph == NULL)
		mwHandleError("matPutArrayAsGlobal", NULL_INPUT " (input #1)", file, linenum);
	
	if (mp == NULL)
		mwHandleError("matPutArrayAsGlobal", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(ph, matPutArrayAsGlobal);
	ptrprint(mp, matPutArrayAsGlobal);

	return matPutArrayAsGlobal(ph, mp);
}

/********************************
 * MEX-FILE INTERFACE FUNCTIONS *
 ********************************/

BEGIN_EXPORT
#if defined(MATLAB_MEX_FILE)
END_EXPORT

EXPORT
int mexAtExit_d(void (*exit_fcn)(void), const char * file, int linenum)
{
	if (exit_fcn == NULL)
		mwHandleError("mexAtExit", NULL_INPUT, file, linenum);
	
	ptrprint(exit_fcn, mexAtExit);
	
	return mexAtExit(exit_fcn);	
}

EXPORT
int mexCallMATLAB_d(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[], 
					  const char *fcn_name, const char * file, int linenum)
{
	if (nlhs < 0)
		mwHandleError("mexCallMATLAB", "Invalid negative input (input #1)", file, linenum);

	if (plhs == NULL)
		mwHandleError("mexCallMATLAB", NULL_INPUT " (input #2)", file, linenum);
				
	if (nrhs < 0)
		mwHandleError("mexCallMATLAB", "Invalid negative input (input #3)", file, linenum);

	if (prhs == NULL && nrhs > 0)
		mwHandleError("mexCallMATLAB", NULL_INPUT " (input #4)", file, linenum);

	if (fcn_name == NULL)
		mwHandleError("mexCallMATLAB", NULL_INPUT " (input #5)", file, linenum);

	ptrprint(plhs, mexCallMATLAB);
	ptrprint(prhs, mexCallMATLAB);
	ptrprint(fcn_name, mexCallMATLAB);

	return mexCallMATLAB(nlhs, plhs, nrhs, prhs, fcn_name);						
}

EXPORT
void mexErrMsgTxt_d(const char * error_msg, const char * file, int linenum)
{
	if (error_msg == NULL)
		mwHandleError("mexErrMsgTxt", NULL_INPUT, file, linenum);
	
	ptrprint(error_msg, mexErrMsgTxt);
	
	mexErrMsgTxt(error_msg);	
}

EXPORT
int mexEvalString_d(const char *str, const char * file, int linenum)
{
	if (str == NULL)
		mwHandleError("mexEvalString", NULL_INPUT, file, linenum);
	
	ptrprint(str, mexEvalString);
	
	return  mexEvalString(str);	
}

EXPORT
const mxArray *mexGet_d(double handle, const char *property, const char * file, int linenum)
{
	if (property == NULL)
		mwHandleError("mexGet", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(property, mexGet);
	
	return mexGet(handle, property);
}

EXPORT
mxArray *mexGetArray_d(const char *name, const char *workspace, const char * file, int linenum)
{
	if (name == NULL)
		mwHandleError("mexGetArray", NULL_INPUT " (input #1)", file, linenum);
		
	if (workspace == NULL)
		mwHandleError("mexGetArray", NULL_INPUT " (input #2)", file, linenum);
			
	if (strcmp(workspace, "base") && 
	    strcmp(workspace, "global") && 
        strcmp(workspace, "caller")
       )
		mwHandleError("mexGetArray", "Invalid workspace specification (input #2)", file, linenum);

	ptrprint(name, mexGetArray);
	ptrprint(workspace, mexGetArray);

	return mexGetArray(name, workspace);
}

EXPORT
const mxArray *mexGetArrayPtr_d(const char *name, const char *workspace, const char * file, int linenum)
{
	if (name == NULL)
		mwHandleError("mexGetArrayPtr", NULL_INPUT " (input #1)", file, linenum);
		
	if (workspace == NULL)
		mwHandleError("mexGetArrayPtr", NULL_INPUT " (input #2)", file, linenum);
			
	if (strcmp(workspace, "base") && 
	    strcmp(workspace, "global") && 
        strcmp(workspace, "caller")
       )
		mwHandleError("mexGetArrayPtr", "Invalid workspace specification (input #2)", file, linenum);

	ptrprint(name, mexGetArrayPtr);
	ptrprint(workspace, mexGetArrayPtr);

	return mexGetArrayPtr(name, workspace);
}

EXPORT
bool mexIsGlobal_d(const mxArray *pa, const char * file, int linenum)
{

	if (pa == NULL)
		mwHandleError("mexIsGlobal", NULL_INPUT " (input #1)", file, linenum);
		
	return mexIsGlobal(pa);
}

EXPORT
void mexMakeArrayPersistent_d(mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mexMakeArrayPersistent", NULL_INPUT, file, linenum);
	
	ptrprint(pa, mexMakeArrayPersistent);
	
	mexMakeArrayPersistent(pa);	
}

EXPORT
void mexMakeMemoryPersistent_d(void *ptr, const char * file, int linenum)
{
	if (ptr == NULL)
		mwHandleError("mexMakeMemoryPersistent", NULL_INPUT, file, linenum);
	
	ptrprint(ptr, mexMakeMemoryPersistent);
	
	mexMakeMemoryPersistent(ptr);	
}

EXPORT
int mexPutArray_d(mxArray *parray, const char *workspace, const char * file, int linenum)
{
	if (parray == NULL)
		mwHandleError("mexPutArray", NULL_INPUT " (input #1)", file, linenum);
		
	if (workspace == NULL)
		mwHandleError("mexPutArray", NULL_INPUT " (input #2)", file, linenum);
			
	if (strcmp(workspace, "base") && 
	    strcmp(workspace, "global") && 
        strcmp(workspace, "caller")
       )
		mwHandleError("mexPutArray", "Invalid workspace specification (input #2)", file, linenum);

	ptrprint(parray, mexPutArray);
	ptrprint(workspace, mexPutArray);

	return mexPutArray(parray, workspace);	
}

EXPORT
int mexSet_d(double handle, const char *property, mxArray *value, const char * file, int linenum)
{
	if (property == NULL)
		mwHandleError("mexSet", NULL_INPUT " (input #2)", file, linenum);
		
	if (value == NULL)
		mwHandleError("mexSet", NULL_INPUT " (input #3)", file, linenum);
		
	ptrprint(property, mexSet);
	ptrprint(value, mexSet);

	return mexSet(handle, property, value);
}

EXPORT
void mexSetTrapFlag_d(int value, const char * file, int linenum)
{
	if ((value != 0) && (value != 1))
		mwHandleError("mexSet", "Invalid non-boolean input", file, linenum);

	mexSetTrapFlag(value);
}

EXPORT
void mexWarnMsgTxt_d(const char *error_msg, const char * file, int linenum)
{
	if (error_msg == NULL)
		mwHandleError("mexWarnMsgTxt", NULL_INPUT, file, linenum);
	
	ptrprint(error_msg, mexWarnMsgTxt);
	
	mexWarnMsgTxt(error_msg);	
}

BEGIN_EXPORT
#endif /* MATLAB_MEX_FILE */
END_EXPORT

/***************************
 * MATRIX ACCESS FUNCTIONS *
 ***************************/

EXPORT
int mxCalcSingleSubscript_d(const mxArray *pa, int nsubs, const int *subs,
							const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxCalcSingleSubscript", NULL_INPUT " (input #1)", file, linenum);
		
	if (nsubs <= 0)
		mwHandleError("mxCalcSingleSubscript", "Invalid nonpositive input (input #2)", file, linenum);

	if (subs == NULL)
		mwHandleError("mxCalcSingleSubscript", NULL_INPUT " (input #3)", file, linenum);

	ptrprint(pa, mxCalcSingleSubscript);
	ptrprint(subs, mxCalcSingleSubscript);
				
	return mxCalcSingleSubscript(pa, nsubs, subs);
}

EXPORT
void * mxCalloc_d(size_t nmemb, size_t size, const char * file, int linenum)
{

	if (nmemb <= 0)
		mwHandleError("mxCalloc",
			      "Invalid nonpositive input (input #1)",
			      file, linenum);

	if (size <= 0)
		mwHandleError("mxCalloc",
			      "Invalid nonpositive input (input #2)",
			      file, linenum);

	return mxCalloc(nmemb, size);
}

EXPORT
void mxClearLogical_d(mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxClearLogical", NULL_INPUT, file, linenum);

	ptrprint(pa, mxClearLogical);

	mxClearLogical(pa);
}

EXPORT
mxArray *mxCreateCellArray_d(int ndim, const int *dims, const char * file, int linenum)
{
	if (ndim < 0)
		mwHandleError("mxCreateCellArray", "Invalid negative input (input #1)", file, linenum);

	if (dims == NULL && ndim > 0)
		mwHandleError("mxCreateCellArray", NULL_INPUT " (input #2)", file, linenum);
	
	ptrprint(dims, mxCreateCellArray);

	return mxCreateCellArray(ndim, dims);			
}

EXPORT
mxArray *mxCreateCellMatrix_d(int m, int n, const char * file, int linenum)
{
	if (m < 0)
		mwHandleError("mxCreateCellMatrix", "Invalid negative input (input #1)", file, linenum);
		
	if (n < 0)
		mwHandleError("mxCreateCellMatrix", "Invalid negative input (input #2)", file, linenum);

	return mxCreateCellMatrix(m, n);		
}

EXPORT
mxArray *mxCreateCharArray_d(int ndim, const int *dims, const char * file, int linenum)
{
	if (ndim < 0)
		mwHandleError("mxCreateCharArray", "Invalid negative input (input #1)", file, linenum);

	if (dims == NULL && ndim > 0)
		mwHandleError("mxCreateCharArray", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(dims, mxCreateCharArray);

	return mxCreateCharArray(ndim, dims);				
}

EXPORT
mxArray *mxCreateCharMatrixFromStrings_d(int m, const char **str, const char * file, int linenum)
{
	if (m < 0)
		mwHandleError("mxCreateCharMatrixFromStrings", "Invalid negative input (input #1)", file, linenum);
		
	if (str == NULL && m > 0)
		mwHandleError("mxCreateCharMatrixFromStrings", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(str, mxCreateCharMatrixFromStrings);

	return mxCreateCharMatrixFromStrings(m, str);			
}

EXPORT
mxArray *mxCreateNumericArray_d(int ndim, const int *dims, mxClassID classid, 
								mxComplexity flag, const char * file, int linenum)
{
	if (ndim < 0)
		mwHandleError("mxCreateNumericArray", "Invalid negative input (input #1)", file, linenum);
		
	if (dims == NULL && ndim > 0)
		mwHandleError("mxCreateNumericArray", NULL_INPUT " (input #2)", file, linenum);
		
	if (classid != mxDOUBLE_CLASS &&
	  	classid != mxSINGLE_CLASS &&
	   	classid != mxINT8_CLASS &&
	   	classid != mxUINT8_CLASS &&
	   	classid != mxINT16_CLASS &&
	   	classid != mxUINT16_CLASS &&
	   	classid != mxINT32_CLASS &&
	   	classid != mxUINT32_CLASS &&
	   	classid != mxINT64_CLASS &&
	   	classid != mxUINT64_CLASS
	   )
		mwHandleError("mxCreateNumericArray", "Invalid class type (input #3)", file, linenum);
	
	if (flag != mxREAL && flag != mxCOMPLEX)
		mwHandleError("mxCreateNumericArray", "Invalid complexity (input #4)", file, linenum);
					
	ptrprint(dims, mxCreateNumericArray);

	return mxCreateNumericArray(ndim, dims, classid, flag);
}

EXPORT
mxArray *mxCreateDoubleMatrix_d(int m, int n, mxComplexity flag, const char * file, int linenum)
{
	if (m < 0)
		mwHandleError("mxCreateDoubleMatrix", "Invalid negative input (input #1)", file, linenum);
		
	if (n < 0)
		mwHandleError("mxCreateDoubleMatrix", "Invalid negative input (input #2)", file, linenum);

	if (flag != mxREAL && flag != mxCOMPLEX)
		mwHandleError("mxCreateDoubleMatrix", "Invalid complexity (input #3)", file, linenum);

	return mxCreateDoubleMatrix(m, n, flag);			
}

EXPORT
mxArray *mxCreateSparse_d(int m, int n, int nzmax, mxComplexity flag, const char * file, int linenum)
{
	if (m < 0)
		mwHandleError("mxCreateSparse", "Invalid negative input (input #1)", file, linenum);
		
	if (n < 0)
		mwHandleError("mxCreateSparse", "Invalid negative input (input #2)", file, linenum);
		
	if (nzmax < 0)
		mwHandleError("mxCreateSparse", "Invalid negative input (input #3)", file, linenum);
		
	if (flag != mxREAL && flag != mxCOMPLEX)
		mwHandleError("mxCreateSparse", "Invalid complexity (input #4)", file, linenum);
		
	return mxCreateSparse(m, n, nzmax, flag);
}

EXPORT
mxArray *mxCreateString_d(const char *str, const char * file, int linenum)
{
	if (str == NULL)
		mwHandleError("mxCreateString", NULL_INPUT, file, linenum);
	
	ptrprint(str, mxCreateString);
	
	return mxCreateString(str);
}

EXPORT
mxArray *mxCreateStructArray_d(int ndim, const int *dims, int nfields,
								const char **fieldnames, const char * file, int linenum)
{
        int i;

	if (ndim < 0)
		mwHandleError("mxCreateStructArray", "Invalid negative input (input #1)", file, linenum);

	if (dims == NULL && ndim > 0)
		mwHandleError("mxCreateStructArray", NULL_INPUT " (input #2)", file, linenum);

	if (nfields < 0)
		mwHandleError("mxCreateStructArray", "Invalid negative input (input #3)", file, linenum);

	if (fieldnames == NULL && nfields > 0)
		mwHandleError("mxCreateStructArray", NULL_INPUT " (input #4)", file, linenum);

	/*
	 * Check validity of the field names.
	 * Specifically, make sure field names don't have any of the
	 * following characters:
	 *
	 *  "!"#$%&'()*+,-./:;<=>?@[\]^`{|}~ "
	 *
	 * and that they don't start with any of the characters of the set 
	 * 
	 *  "!"#$%&'()*+,-./:;<=>?@[\]^`{|}~ 0123456789".  
	 */
	for (i=0; i < nfields; i++) {
	    char message[255];

	    /* Check to make sure array name isn't empty. */
	    if (strlen(fieldnames[i]) == 0) {
		sprintf(message, "Field %d's name is empty", i);
		mwHandleError("mxCreateStructArray", message, file, linenum);
	    }

	    if (strchr("!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ 0123456789",
		       fieldnames[i][0]) != NULL) {
		sprintf(message,
			"Field %d's name begins with an invalid character",
			i);
		mwHandleError("mxCreateStructArray", message, file, linenum);
	    }
		
	    if (strpbrk(fieldnames[i], "!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ ")
		!= NULL) {
		sprintf(message,
			"Field %d's name contains an invalid character",
			i);
		mwHandleError("mxCreateStructArray", message, file, linenum);
	    }
	}

	ptrprint(dims, mxCreateStructArray);
	ptrprint(fieldnames, mxCreateStructArray);

	return mxCreateStructArray(ndim, dims, nfields, fieldnames);
}

EXPORT
mxArray *mxCreateStructMatrix_d(int m, int n, int nfields, 
								  const char **fieldnames, const char * file, int linenum)
{
        int i;

	if (m < 0)
		mwHandleError("mxCreateStructMatrix", "Invalid negative input (input #1)", file, linenum);
		
	if (n < 0)
		mwHandleError("mxCreateStructMatrix", "Invalid negative input (input #2)", file, linenum);

	if (nfields < 0)
		mwHandleError("mxCreateStructMatrix", "Invalid negative input (input #3)", file, linenum);

	if (fieldnames == NULL && nfields > 0)
		mwHandleError("mxCreateStructMatrix", NULL_INPUT " (input #4)", file, linenum);

	/*
	 * Check validity of the field names.
	 * Specifically, make sure field names don't have any of the
	 * following characters:
	 *
	 *  "!"#$%&'()*+,-./:;<=>?@[\]^`{|}~ "
	 *
	 * and that they don't start with any of the characters of the set 
	 * 
	 *  "!"#$%&'()*+,-./:;<=>?@[\]^`{|}~ 0123456789".  
	 */
	for (i=0; i < nfields; i++) {
	    char message[255];

	    /* Check to make sure array name isn't empty. */
	    if (strlen(fieldnames[i]) == 0) {
		sprintf(message, "Field %d's name is empty", i);
		mwHandleError("mxCreateStructMatrix", message, file, linenum);
	    }

	    if (strchr("!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ 0123456789",
		       fieldnames[i][0]) != NULL) {
		sprintf(message,
			"Field %d's name begins with an invalid character",
			i);
		mwHandleError("mxCreateStructMatrix", message, file, linenum);
	    }
		
	    if (strpbrk(fieldnames[i], "!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ ")
		!= NULL) {
		sprintf(message,"Field %d's name contains an invalid character",i);
		mwHandleError("mxCreateStructMatrix", message, file, linenum);
	    }
	}

	ptrprint(fieldnames, mxCreateStructMatrix);
	
	return mxCreateStructMatrix(m, n, nfields, fieldnames);
}

EXPORT
void mxDestroyArray_d(mxArray *pa, const char * file, int linenum)
{

	if (pa == NULL)
		mwHandleError("mxDestroyArray", NULL_INPUT " (input #1)", file, linenum);

	ptrprint(pa, mxDestroyArray);

	mxDestroyArray(pa);
}

EXPORT
mxArray *mxDuplicateArray_d(const mxArray *pa,
			      const char *file,
			      const int linenum)
{

	if (pa == NULL)
		mwHandleError("mxDuplicateArray", NULL_INPUT " (input #1)", file, linenum);

	ptrprint(pa, mxDuplicateArray);

	return mxDuplicateArray(pa);
}

EXPORT
void mxFree_d(void *pm, const char * file, int linenum)
{

	if (pm == NULL)
		mwHandleError("mxFree", NULL_INPUT " (input #1)",
			      file, linenum);

	ptrprint(pm, mxFree);

	mxFree(pm);
}

EXPORT
mxArray *mxGetCell_d(const mxArray *pa, int i, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetCell", NULL_INPUT " (input #1)", file, linenum);

	if (!mxIsCell(pa) && !mxIsStruct(pa))
		mwHandleError("mxGetCell", "Invalid non-cell array input (input #1)", file, linenum);

	if (i < 0)
		mwHandleError("mxGetCell", "Invalid negative input (input #2)", file, linenum);

	if (i >= mxGetNumberOfElements(pa) || (mxIsStruct(pa) && i >= mxGetNumberOfElements(pa) * mxGetNumberOfFields(pa)))
		mwHandleError("mxGetCell", "Invalid out-of-range  input (input #2)", file, linenum);

	ptrprint(pa, mxGetCell);

	return mxGetCell(pa, i);
}

EXPORT
mxClassID mxGetClassID_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetClassID", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetClassID);
		
	return mxGetClassID(pa);
}

EXPORT
const char *mxGetClassName_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetClassName", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetClassName);

	return mxGetClassName(pa);
}

EXPORT
void *mxGetData_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetData", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetData);

	return mxGetData(pa);
}

EXPORT
const int *mxGetDimensions_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetDimensions", NULL_INPUT " (input #1)", file, linenum);

	ptrprint(pa, mxGetDimensions);

	return mxGetDimensions(pa);
}

EXPORT
int mxGetElementSize_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetElementSize", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetElementSize);

	return mxGetElementSize(pa);
}

EXPORT
mxArray *mxGetField_d(const mxArray *pa, int i, const char *fieldname, 
					const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetField", NULL_INPUT " (input #1)", file, linenum);

	if (!mxIsStruct(pa))
		mwHandleError("mxGetField", "Invalid non-structure array input (input #1)", file, linenum);
		
	if (i < 0)
		mwHandleError("mxGetField", "Invalid negative input (input #2)", file, linenum);
	
	if (i >= mxGetNumberOfElements(pa))
                mwHandleError("mxGetField", "Invalid out_of_range input (input #2)", file, linenum);
	if (fieldname == NULL)
		mwHandleError("mxGetField", NULL_INPUT " (input #3)", file, linenum);

	ptrprint(pa, mxGetField);
	ptrprint(fieldname, mxGetField);

	return mxGetField(pa, i, fieldname);
}

EXPORT
mxArray *mxGetFieldByNumber_d(const mxArray *pa, int i, int fieldnum, 
							const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetFieldByNumber", NULL_INPUT " (input #1)", file, linenum);

	if (!mxIsStruct(pa))
		mwHandleError("mxGetFieldByNumber", "Invalid non-structure array input (input #1)", file, linenum);

	if (i < 0)
		mwHandleError("mxGetFieldByNumber", "Invalid negative input (input #2)", file, linenum);

	if (i >= mxGetNumberOfElements(pa))
                mwHandleError("mxGetFieldByNumber", "Invalid out-of-range input (input #2)", file, linenum);

	if (fieldnum < 0)
		mwHandleError("mxGetFieldByNumber", "Invalid negative input (input #3)", file, linenum);

	if (fieldnum >= mxGetNumberOfFields(pa))
                mwHandleError("mxGetFieldByNumber", "Invalid out-of-range input (input #3)", file, linenum);

	ptrprint(pa, mxGetFieldByNumber);

	return mxGetFieldByNumber(pa, i, fieldnum);
}

EXPORT
const char *mxGetFieldNameByNumber_d(const mxArray *pa, int n, 
									const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetFieldNameByNumber", NULL_INPUT " (input #1)", file, linenum);

	if (!mxIsStruct(pa))
		mwHandleError("mxGetFieldNameByNumber", "Invalid non-structure array input (input #1)", file, linenum);

	if (n < 0)
		mwHandleError("mxGetFieldNameByNumber", "Invalid negative input (input #2)", file, linenum);

	ptrprint(pa, mxGetFieldNameByNumber);

	return mxGetFieldNameByNumber(pa, n);
}

EXPORT
int mxGetFieldNumber_d(const mxArray *pa, const char *name, 
						const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetFieldNumber", NULL_INPUT " (input #1)", file, linenum);

	if (!mxIsStruct(pa))
		mwHandleError("mxGetFieldNumber", "Invalid non-structure array input (input #1)", file, linenum);

	if (name == NULL)
		mwHandleError("mxGetFieldNumber", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(pa, mxGetFieldNumber);
	ptrprint(name, mxGetFieldNumber);

	return mxGetFieldNumber(pa, name);			
}

EXPORT
void *mxGetImagData_d(
    const mxArray *pa, const char * file, int linenum	
    )
{
	if (pa == NULL)
		mwHandleError("mxGetImagData", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetImagData);

	return mxGetImagData(pa);		
}

EXPORT
int *mxGetIr_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetIr", NULL_INPUT, file, linenum);
	
	if (!mxIsSparse(pa))
		mwHandleError("mxGetIr", "Invalid non-sparse input", file, linenum);
	
	ptrprint(pa, mxGetIr);

	return mxGetIr(pa);	
}

EXPORT
int *mxGetJc_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetJc", NULL_INPUT, file, linenum);
	
	if (!mxIsSparse(pa))
		mwHandleError("mxGetJc", "Invalid non-sparse input", file, linenum);
	
	ptrprint(pa, mxGetJc);

	return mxGetJc(pa);	
}

EXPORT 
const char *mxGetName_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetName", NULL_INPUT, file, linenum);
	
	ptrprint(pa, mxGetName);
	
	return mxGetName(pa);
}

EXPORT
int mxGetNumberOfDimensions_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetNumberOfDimensions", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetNumberOfDimensions);

	return mxGetNumberOfDimensions(pa);
}

 
EXPORT
int mxGetNumberOfElements_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetNumberOfElements", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetNumberOfElements);

	return mxGetNumberOfElements(pa);
}

EXPORT
int mxGetNumberOfFields_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetNumberOfFields", NULL_INPUT, file, linenum);

	if (!mxIsStruct(pa))
		mwHandleError("mxGetNumberOfFields", "Invalid non-structure input", file, linenum);
			
	ptrprint(pa, mxGetNumberOfFields);

	return mxGetNumberOfFields(pa);		
}

EXPORT
int mxGetNzmax_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetNzmax", NULL_INPUT, file, linenum);
	
	if (!mxIsSparse(pa))
		mwHandleError("mxGetNzmax", "Invalid non-sparse input", file, linenum);
	
	ptrprint(pa, mxGetNzmax);

	return mxGetNzmax(pa);	
}

EXPORT
int mxGetM_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetM", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetM);

	return mxGetM(pa);
}

EXPORT
int mxGetN_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetN", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetN);

	return mxGetN(pa);
}

EXPORT
double *mxGetPi_d(
    const mxArray *pa, const char * file, int linenum	
    )
{
	if (pa == NULL)
		mwHandleError("mxGetPi", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetPi);

	return mxGetPi(pa);		
}

EXPORT
double *mxGetPr_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxGetPr", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetPr);

	return mxGetPr(pa);
}

EXPORT
double mxGetScalar_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetScalar", NULL_INPUT, file, linenum);

	ptrprint(pa, mxGetScalar);

	return mxGetScalar(pa);
}

EXPORT
int mxGetString_d(const mxArray *pa, char *buf, int buflen, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxGetString", NULL_INPUT " (input #1)", file, linenum);
	
	if (!mxIsChar(pa))
		mwHandleError("mxGetString", "Invalid non-character array input (input #1)", file, linenum);
	
	if (buf == NULL)
		mwHandleError("mxGetString", NULL_INPUT " (input #2)", file, linenum);

	if (buflen <= 0)
		mwHandleError("mxGetString", "Invalid nonpositive input (input #3)", file, linenum);

	ptrprint(pa, mxGetString);
	ptrprint(buf, mxGetString);

	return mxGetString(pa, buf, buflen);						
}

EXPORT
bool mxIsCell_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsCell", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsCell);

	return mxIsCell(pa);
}

EXPORT
bool mxIsChar_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsChar", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsChar);

	return mxIsChar(pa);
}

EXPORT
bool mxIsClass_d(const mxArray *pa, const char *name, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsClass", NULL_INPUT " (input #1)", file, linenum);
		
	if (name == NULL)
		mwHandleError("mxIsClass", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(pa, mxIsClass);

	return mxIsClass(pa, name);
}

EXPORT
bool mxIsComplex_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsComplex", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsComplex);

	return mxIsComplex(pa);
}

EXPORT
bool mxIsDouble_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsDouble", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsDouble);

	return mxIsDouble(pa);
}

EXPORT
bool mxIsEmpty_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxIsEmpty", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsEmpty);

	return mxIsEmpty(pa);
}

EXPORT
bool mxIsFromGlobalWS_d(
    const mxArray *pa, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxIsFromGlobalWS", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsFromGlobalWS);

	return mxIsFromGlobalWS(pa);
}

EXPORT
bool mxIsInt8_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError(" mxIsInt8", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsInt8);

	return  mxIsInt8(pa);
}

EXPORT
bool mxIsInt16_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsInt16", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsInt16);

	return mxIsInt16(pa);
}

EXPORT
bool mxIsInt32_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsInt32", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsInt32);

	return mxIsInt32(pa);
}

EXPORT
bool mxIsLogical_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsLogical", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsLogical);

	return mxIsLogical(pa);
}

EXPORT
bool mxIsNumeric_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsNumeric", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsNumeric);

	return mxIsNumeric(pa);
}

EXPORT
bool mxIsSingle_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsSingle", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsSingle);

	return mxIsSingle(pa);
}

EXPORT
bool mxIsSparse_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsSparse", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsSparse);

	return mxIsSparse(pa);
}

EXPORT
bool mxIsStruct_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsStruct", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsStruct);

	return mxIsStruct(pa);
}

EXPORT
bool mxIsUint8_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsUint8", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsUint8);

	return mxIsUint8(pa);
}

EXPORT
bool mxIsUint16_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsUint16", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsUint16);

	return mxIsUint16(pa);
}

EXPORT
bool mxIsUint32_d(const mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxIsUint32", NULL_INPUT, file, linenum);

	ptrprint(pa, mxIsUint32);

	return mxIsUint32(pa);
}

EXPORT
void * mxRealloc_d(void * pm, size_t size, const char * file, int linenum)
{

	if (pm == NULL)
		mwHandleError("mxRealloc", NULL_INPUT " (input #1)",
			      file, linenum);

	if (size <= 0)
		mwHandleError("mxRealloc",
			      "Invalid nonpositive input (input #2)",
			      file, linenum);

	ptrprint(pm, mxRealloc);

	return mxRealloc(pm, size);
}

BEGIN_EXPORT
#if !defined(MATLAB_MEX_FILE)
END_EXPORT
EXPORT
void mxSetAllocFcns_d(calloc_proc callocfcn, free_proc freefcn, realloc_proc reallocfcn, malloc_proc mallocfcn, const char * file, int linenum)
{
	if (callocfcn == NULL)
		mwHandleError("mxSetAllocFcns", NULL_INPUT " (input #1)", file, linenum);
		
	if (freefcn == NULL)
		mwHandleError("mxSetAllocFcns", NULL_INPUT " (input #1)", file, linenum);
	
	if (reallocfcn == NULL)
		mwHandleError("mxSetAllocFcns", NULL_INPUT " (input #1)", file, linenum);
	
	if (mallocfcn == NULL)
		mwHandleError("mxSetAllocFcns", NULL_INPUT " (input #1)", file, linenum);
	
	ptrprint(callocfcn, mxSetAllocFcns);
	ptrprint(freefcn, mxSetAllocFcns);
	ptrprint(reallocfcn, mxSetAllocFcns);
	ptrprint(mallocfcn, mxSetAllocFcns);

	mxSetAllocFcns(callocfcn, freefcn, reallocfcn, mallocfcn);	
}
BEGIN_EXPORT
#endif 
END_EXPORT

EXPORT
void mxSetCell_d(mxArray *pa, int i, mxArray *value, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxSetCell", NULL_INPUT " (input #1)", file, linenum);

	if (!mxIsCell(pa) && !mxIsStruct(pa))
		mwHandleError("mxSetCell", "Invalid non-cell array input (input #1)", file, linenum);

	if (i < 0)
		mwHandleError("mxSetCell", "Invalid negative input (input #2)", file, linenum);
	
	if (i >= mxGetNumberOfElements(pa)*(mxIsStruct(pa) ? mxGetNumberOfFields(pa) : 1))
		mwHandleError("mxGetCell", "Invalid out-of-range  input (input #2)", file, linenum);

	ptrprint(pa, mxSetCell);
	ptrprint(value, mxSetCell);

	mxSetCell(pa, i, value);
}

EXPORT
int mxSetClassName_d(mxArray *pa, const char *classname, const char * file, int linenum)
{
        
	if (pa == NULL)
		mwHandleError("mxSetClassName", NULL_INPUT " (input #1)",
			      file, linenum);

	if (classname == NULL)
		mwHandleError("mxSetClassName", NULL_INPUT " (input #2)",
			      file, linenum);

	if (!mxIsStruct(pa) && (mxGetClassID(pa) != mxOBJECT_CLASS))
	        mwHandleError("mxSetClassName",
			      "Array must be structure or object (input #1)",
			      file, linenum);

	if (strlen(classname) == 0)
	  mwHandleError("mxSetClassName", "Invalid empty string (input #2)",
			file, linenum);
	
	/*
	 * Check validity of the class names.
	 * Specifically, make sure class names don't have any of the
	 * following characters:
	 *
	 *  "!"#$%&'()*+,-./:;<=>?@[\]^`{|}~ "
	 *
	 * and that they don't start with any of the characters of the set 
	 * 
	 *  "!"#$%&'()*+,-./:;<=>?@[\]^`{|}~ 0123456789".  
	 */
	if (strchr("!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ 0123456789",
		   classname[0]) != NULL)
	  mwHandleError("mxSetClassName", "Invalid class name (input #2)",
			file, linenum);

	if (strpbrk(classname, "!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ ")
	    != NULL)
	  mwHandleError("mxSetClassName", "Invalid class name (input #2)",
			file, linenum);

	ptrprint(pa, mxSetClassName);
	ptrprint(classname, mxSetClassName);

	return mxSetClassName(pa, classname);
}

EXPORT
void mxSetData_d(
    mxArray *pa, void *Data, const char * file, int linenum			
    )
{
	if (pa == NULL)
		mwHandleError("mxSetData", NULL_INPUT " (input #1)", file, linenum);
		
	ptrprint(pa, mxSetData);
	ptrprint(Data, mxSetData);

	mxSetData(pa, Data);
}

EXPORT
int mxSetDimensions_d(mxArray *pa, const int *size, int ndims, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxSetDimensions", NULL_INPUT " (input #1)", file, linenum);

	if (ndims < 0)
		mwHandleError("mxSetDimensions", "Invalid negative input (input #3)", file, linenum);

	if (size == NULL && ndims > 0)
		mwHandleError("mxSetDimensions", NULL_INPUT " (input #2)", file, linenum);

	ptrprint(pa, mxSetDimensions);
	ptrprint(size, mxSetDimensions);

	return mxSetDimensions(pa, size, ndims);
}

EXPORT
void mxSetField_d(mxArray *pa, int i, const char *fieldname, mxArray *value,
				const char * file, int linenum)
{
	int found = 0;
	char str[256];

	if (pa == NULL)
		mwHandleError("mxSetField", NULL_INPUT " (input #1)",
			      file, linenum);

	if (!mxIsStruct(pa))
		mwHandleError("mxSetField",
			      "Invalid non-structure array input (input #1)",
			      file, linenum);

	if (i < 0)
		mwHandleError("mxSetField",
			      "Invalid negative input (input #2)",
			      file, linenum);

	if (i >= mxGetNumberOfElements(pa))
		mwHandleError("mxSetField",
			      "Invalid out-of-range input (input #2)",
			      file, linenum);
	
	if (fieldname == NULL)
		mwHandleError("mxSetField", NULL_INPUT " (input #3)",
			      file, linenum);

	if (mxGetFieldNumber(pa, fieldname) < 0) {
	        sprintf(str, "Invalid non-existent field %s (input #3)", fieldname);
	        mwHandleError("mxSetField", str, file, linenum);
	}

	ptrprint(pa, mxSetField);
	ptrprint(fieldname, mxSetField);
	ptrprint(value, mxSetField);

	mxSetField(pa, i, fieldname, value);
}

EXPORT
void mxSetFieldByNumber_d(mxArray *pa, int i, int fieldnum, mxArray *value, 
						const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxSetFieldByNumber", NULL_INPUT " (input #1)", file, linenum);

	if (!mxIsStruct(pa))
		mwHandleError("mxSetFieldByNumber", "Invalid non-structure array input (input #1)", file, linenum);

	if (i < 0)
		mwHandleError("mxSetFieldByNumber", "Invalid negative input (input #2)", file, linenum);

	if (i >= mxGetNumberOfElements(pa))
                mwHandleError("mxSetFieldByNumber", "Invalid out-of-range input (input #2)", file, linenum);

	if (fieldnum < 0)
		mwHandleError("mxSetFieldByNumber", "Invalid negative input (input #3)", file, linenum);
	if (fieldnum >= mxGetNumberOfFields(pa))
                mwHandleError("mxSetFieldByNumber", "Invalid out-of-range input (input #3)", file, linenum);

	ptrprint(pa, mxSetFieldByNumber);
	ptrprint(value, mxSetFieldByNumber);

	mxSetFieldByNumber(pa, i, fieldnum, value);
}

EXPORT
void mxSetImagData_d(
    mxArray *pa, void *ImagData, const char * file, int linenum			
    )
{
	if (pa == NULL)
		mwHandleError("mxSetImagData", NULL_INPUT "(input #1)", file, linenum);

	ptrprint(pa, mxSetImagData);
	ptrprint(ImagData, mxSetImagData);

	mxSetImagData(pa, ImagData);		
}

EXPORT
void mxSetIr_d(
    mxArray *pa, int *ir, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxSetIr", NULL_INPUT " (input #1)", file, linenum);
	
	if (!mxIsSparse(pa))
		mwHandleError("mxSetIr", "Invalid non-sparse input (input #1)", file, linenum);

	ptrprint(pa, mxSetIr);
	ptrprint(ir, mxSetIr);

	mxSetIr(pa, ir);
}

EXPORT
void mxSetJc_d(
    mxArray *pa,int *jc, const char * file, int linenum			
    )
{
	if (pa == NULL)
		mwHandleError("mxSetJc", NULL_INPUT " (input #1)", file, linenum);
	
	if (!mxIsSparse(pa))
		mwHandleError("mxSetJc", "Invalid non-sparse input (input #1)", file, linenum);

	ptrprint(pa, mxSetJc);
	ptrprint(jc, mxSetJc);
	
	mxSetJc(pa, jc);
}

EXPORT
void mxSetLogical_d(mxArray *pa, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxSetLogical", NULL_INPUT, file, linenum);

	if (mxIsComplex(pa))
		mwHandleError("mxSetLogical", "Invalid complex input (input #1)", file, linenum);

	ptrprint(pa, mxSetLogical);

	mxSetLogical(pa);
}

EXPORT
void mxSetM_d(
    mxArray *pa,int m, const char * file, int linenum			
    )
{
	if (pa == NULL)
		mwHandleError("mxSetM", NULL_INPUT " (input #1)", file, linenum);

	if (m < 0)
		mwHandleError("mxSetM", "Invalid negative input (input #2)", file, linenum);
		
	ptrprint(pa, mxSetM);

	mxSetM(pa, m);				
}

EXPORT 
void mxSetN_d(mxArray *pa, int n, const char * file, int linenum)
{
	if (pa == NULL)
		mwHandleError("mxSetN", NULL_INPUT " (input #1)", file, linenum);
		
	if (n < 0)
		mwHandleError("mxSetN", "Invalid negative input (input #2)", file, linenum);

	ptrprint(pa, mxSetN);

	mxSetN(pa, n);		
}

EXPORT
void mxSetName_d(
    mxArray *pa, const char *s, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxSetName", NULL_INPUT " (input #1)", file, linenum);

	if (s == NULL)
		mwHandleError("mxSetName", NULL_INPUT " (input #2)", file, linenum);

	/* Check to make sure array name isn't empty. */
	if (strlen(s) == 0)
	    mwHandleError("mxSetName", "Second input argument is an empty string", file, linenum);

	/* Check validity of the name as a name for a MATLAB array.  Specifically,
       make sure variable name doesn't have any of the following characters:
	    
	    "!"#$%&'()*+,-./:;<=>?@[\]^`{|}~ "

	   and that it doesn't start with any of the characters of the set 
	   
	    "!"#$%&'()*+,-./:;<=>?@[\]^`{|}~ 0123456789".  
    */
	    
	if (strchr("!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ 0123456789", s[0]) != NULL)
		mwHandleError("mxSetName", "Second input argument's first character is invalid", file, linenum);
		
	if (strpbrk(s, "!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ ") != NULL)
		mwHandleError("mxSetName", "Second input argument contains an invalid character", file, linenum);

	ptrprint(pa, mxSetName);
	ptrprint(s, mxSetName);

	mxSetName(pa, s);
}

EXPORT
void mxSetNzmax_d(
    mxArray *pa,		
    int     nzmax, const char * file, int linenum		
    )
{
	if (pa == NULL)
		mwHandleError("mxSetNzmax", NULL_INPUT " (input #1)", file, linenum);
	
	if (!mxIsSparse(pa))
		mwHandleError("mxSetNzmax", "Invalid non-sparse input (input #1)", file, linenum);

	if (nzmax < 0)
		mwHandleError("mxSetNzmax", "Invalid negative input (input #2)", file, linenum);
	
	ptrprint(pa, mxSetNzmax);

	mxSetNzmax(pa, nzmax);	
}

EXPORT
void mxSetPi_d(
    mxArray *pa, double *pi, const char * file, int linenum			
    )
{
	if (pa == NULL)
		mwHandleError("mxSetPi", NULL_INPUT "(input #1)", file, linenum);

	ptrprint(pa, mxSetPi);
	ptrprint(pi, mxSetPi);

	mxSetPi(pa, pi);		
}

EXPORT
void mxSetPr_d(
    mxArray *pa, double *pr, const char * file, int linenum			
    )
{
	if (pa == NULL)
		mwHandleError("mxSetPr", NULL_INPUT " (input #1)", file, linenum);
		
	ptrprint(pa, mxSetPr);
	ptrprint(pr, mxSetPr);

	mxSetPr(pa, pr);
}
#ifdef __cplusplus
    }   /* extern "C" */
#endif
