/*
 * @(#)mat.h    generated by: makeheader    Sat May 13 02:26:48 2000
 *
 *		built from:	copyright.h
 *				../../src/file/matintf.c
 *				../../src/file/matdbg.h
 */

#ifndef mat_h
#define mat_h


/* $Revision: 1.6 $ */
/*
 * Copyright (c) 1984-1999 The MathWorks, Inc.
 * All Rights Reserved.
 */


#ifdef __cplusplus
    extern "C" {
#endif


#include <stdio.h>
#include "matrix.h"

typedef struct MATFile_tag MATFile;


/*
 * Allocate and initialize a MATFile structure for a file "filename".
 * file "filename" must already have been fopened with a mode corresponding
 * to "mode" ("r" == "rb", "w" == "w+b", "u" == "r+b"), and the result
 * of that fopen must be passed in as "fp".
 *
 * WARNING:
 * THIS FILE IS FOR INTERNAL MATHWORKS USE ONLY.  IT IS AN UNDOCUMENTED
 * FUNCTION, AND MAY AT ANY TIME BE REMOVED FROM THE MAT API.
 */
extern MATFile * matCreateMATFile(const char * filename, FILE *fp, const char * mode);


/* 
 * Open a MAT-file "filename" using mode "mode".  Return
 * a pointer to a MATFile for use with other MAT API functions.
 *
 * Current valid entries for "mode" are
 * "r"  == read only.
 * "w"  == write only (deletes any existing file with name <filename>).
 * "w4" == as "w", but create a MATLAB 4.0 MAT-file.
 * "u"  == update.  Read and write allowed, existing file is not deleted.
 * 
 * Return NULL if an error occurs.
 */
extern MATFile * matOpen(const char *filename, const char * mode);


/*
 * Close a MAT-file opened with matOpen.
 *
 * Return zero for success, EOF on error.
 */
extern int matClose(MATFile *pMF);


/*
 * Return the ANSI C FILE pointer obtained when the MAT-file was opened.
 */
extern FILE * matGetFp(MATFile *pMF);


/* 
 * Write array pA to MATFile pMF at the current file offset, without
 * deleting any previously existing arrays of the same name.
 *
 * Return zero for success, nonzero for error.
 *
 * WARNING:
 * THIS FILE IS FOR INTERNAL MATHWORKS USE ONLY.  IT IS AN UNDOCUMENTED
 * FUNCTION, AND MAY AT ANY TIME BE REMOVED FROM THE MAT API.  IMPROPER
 * USE OF THIS FUNCTION WILL LEAD TO CORRUPTION OF THE MAT-FILE.
 */
extern int matPutNextArray(MATFile * pMF, const mxArray * pA);


/*
 * Write array pA to the MAT-file pMF, deleting any previously
 * existing array in pMF with the same name as pA.
 *
 * Return zero for success, nonzero for error.
 */
extern int matPutArray(MATFile * pMF, const mxArray * pA);


/*
 * Write array pA to the MAT-file pMF, deleting any previously
 * existing array in pMF with the same name as pA.
 *
 * pA will be written such that when the MATLAB LOAD command 
 * loads the array, it will automatically place it in the 
 * global workspace and establish a link to it in the local
 * workspace (as if the command "global <varname>" had been
 * issued after the array was loaded.)
 *
 * Return zero for success, nonzero for error.
 */
extern int matPutArrayAsGlobal(MATFile * pMF, const mxArray * pA);


/* 
 * Read the next array from the current file location of the MAT-file
 * pMF.  This function should only be used in conjunction with 
 * matOpen and matClose.  Passing pMF to any other API functions
 * will cause matGetNextArray to work incorrectly.
 *
 * Return NULL if an error occurs.
 */
extern mxArray * matGetNextArray(MATFile *pMF);


/*
 * Read array named "name" from MAT-file pMF.
 *
 * Return NULL if an error occurs.
 */
extern mxArray * matGetArray(MATFile * pMF, const char * name);


/*
 * Read the array header of the next array in a MAT-file.  
 * This function should only be used in conjunction with 
 * matOpen and matClose.  Passing pMF to any other API functions
 * will cause matGetNextArrayHeader to work incorrectly.
 * 
 * See the description of matGetArrayHeader below for the definition
 * and valid uses of an array header.
 *
 * Return NULL if an error occurs.
 */ 
extern mxArray * matGetNextArrayHeader(MATFile *pMF);


/*
 * Read the array header for the array named "name" from 
 * the MAT-file pMF.
 * 
 * An array header contains all the same information as an
 * array, except that the pr, pi, ir, and jc data structures are 
 * not allocated for non-recursive data types.  That is,
 * Cells, structures, and objects contain pointers to other
 * array headers, but numeric, string, and sparse arrays do not 
 * contain valid data in their pr, pi, ir, or jc fields.
 *
 * The purpose of an array header is to gain fast access to 
 * information about an array without reading all the array's
 * actual data.  Thus, functions such as mxGetM, mxGetN, and mxGetClassID
 * can be used with array headers, but mxGetPr, mxGetPi, mxGetIr, mxGetJc,
 * mxSetPr, mxSetPi, mxSetIr, and mxSetJc cannot.
 *
 * An array header should NEVER be returned to MATLAB (for example via the
 * MEX API), or any other non-matrix access API function that expects a
 * full mxArray (examples include engPutArray, matPutArray, and 
 * mexPutArray).
 *
 * Return NULL if an error occurs.
 */
extern mxArray * matGetArrayHeader(MATFile *pMF, const char * name);


/* 
 * Get a list of the names of the arrays in a MAT-file.
 * The array of strings returned by this function contains "num"
 * entries.  It is allocated with one call to mxCalloc, and so 
 * can (must) be freed with one call to mxFree.
 *
 * If there are no arrays in the MAT-file, return value 
 * is NULL and num is set to zero.  If an error occurs,
 * return value is NULL and num is set to a negative number.
 */
extern char ** matGetDir(MATFile * pMF, int *num);


/*
 * Remove an array with name "name" from the MAT-file pMF.
 *
 * Return zero on success, non-zero on error.
 */
extern int matDeleteArray(MATFile *pMF, const char *name);


#if defined(V4_COMPAT)
/*
 * THE FOLLOWING FUNCTIONS ARE PROVIDED FOR BACKWARD COMPATIBILITY
 * ONLY.  THEY MAY BE REMOVED FROM THE MAT API AT ANY TIME, SO IT 
 * IS SUGGESTED THAT YOU UPDATE YOUR CODE TO THE CURRENT API SPEC
 * AS SOON AS POSSIBLE.  THEY ARE ONLY AVAILABLE IF THE SYMBOL
 * "V4_COMPAT" IS DEFINED.
 */


#define matDeleteMatrix matDeleteArray


/*
 * Get full matrix from MAT-file
 * Obsolete: use matGetArray() and mxGet routines instead
 */
extern int matGetFull(MATFile *fp, char *name, int *m, int *n, double **pr, double **pi);


/*
 * Put full matrix into MAT-file
 * Obsolete: use mxCreateDoubleMatrix() and mxSet routines instead
 */
extern int matPutFull(	MATFile	*ph, char *name, int m, int n, double *pr, double *pi);


extern int matGetString(MATFile *pMF, const char *name, char *buffer, int buflen);


extern int matPutString(MATFile *pMF, const char *name, const char *str);


#define matGetMatrix     matGetArray
#define matPutMatrix     matPutArray
#define matGetNextMatrix matGetNextArray
#else
#define matDeleteMatrix()  matDeleteMatrix_is_obsolete
#define matGetFull()       matGetFull_is_obsolete
#define matPutFull()       matPutFull_is_obsolete
#define matGetString()     matGetString_is_obsolete
#define matPutString()     matPutString_is_obsolete
#define matGetMatrix()     matGetMatrix_is_obsolete
#define matPutMatrix()     matPutMatrix_is_obsolete
#define matGetNextMatrix() matGetNextMatrix_is_obsolete
#endif /* V4_COMPAT */


/* $Revision: 1.6 $ */
#ifdef ARGCHECK

#include "mwdebug.h" /* Prototype _d versions of API functions */

#define matClose(pMAT) 					matClose_d(pMAT, __FILE__, __LINE__)
#define matDeleteArray(pMAT, name)		matDeleteArray_d(pMAT, name, __FILE__, __LINE__) 
#define matGetArray(pMAT, name) 		matGetArray_d(pMAT, name, __FILE__, __LINE__) 
#define matGetArrayHeader(pMAT, name) 		matGetArrayHeader_d(pMAT, name, __FILE__, __LINE__) 
#define matGetDir(pMAT, num) 			matGetDir_d(pMAT, num, __FILE__, __LINE__)
#define matGetFp(pMAT) 					matGetFp_d(pMAT, __FILE__, __LINE__) 
#define matGetNextArray(pMAT) 			matGetNextArray_d(pMAT, __FILE__, __LINE__)
#define matGetNextArrayHeader(pMAT) 	matGetNextArrayHeader_d(pMAT, __FILE__, __LINE__)
#define matOpen(fname, permissions) 	matOpen_d(fname, permissions, __FILE__, __LINE__) 
#define matPutArray(pMAT, pa) 			matPutArray_d(pMAT, pa, __FILE__, __LINE__)
#define matPutArrayAsGlobal(pMAT, pa) 			matPutArrayAsGlobal_d(pMAT, pa, __FILE__, __LINE__)
#endif

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* mat_h */
