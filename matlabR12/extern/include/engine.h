/*
 * @(#)engine.h    generated by: makeheader    Sun Oct 31 23:20:48 1999
 *
 *		built from:	copyright.h
 *				../../src/extern/engintrf.c
 *				../../src/extern/engapiv4.c
 */

#ifndef engine_h
#define engine_h


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


typedef struct engine Engine;	/* Incomplete definition for Engine */


/*
 * Execute matlab statement
 */
extern int engEvalString(
	Engine	*ep,		/* engine pointer */
	const char *string	/* string for matlab t execute */
	);


/*
 * Start matlab process for single use.
 * Not currently supported on UNIX.
 */
extern Engine *engOpenSingleUse(
			 const char *startcmd, /* exec command string used to start matlab */
			 void *reserved, /* reserved for future use, must be NULL */
			 int *retstatus /* return status */
);


/*
 * Start matlab process
 */
extern Engine *engOpen(
	const char *startcmd /* exec command string used to start matlab */
	);


/*
 * Close down matlab server
 */
extern int engClose(
	Engine	*ep         /* engine pointer */
	);


/*
 * get a array from matlabs workspace
 */
extern mxArray *engGetArray(
	Engine	*ep,		/* engine pointer */
	const char *name	/* name of array to get */
	);


/*
 * put a array in matlabs workspace
 */
extern int engPutArray(
	Engine	*ep,        /* engine pointer */
	const mxArray *ap   /* array pointer */
	);


/*
 * register a buffer to hold matlab text output
 */
extern int engOutputBuffer(
	Engine	*ep,		/* engine pointer */
	char	*buffer,	/* character array to hold output */
	int     buflen		/* buffer array length */
	);


#if defined(V4_COMPAT)


extern Engine *engOpenV4(
	const char *startcmd /* exec command string used to start matlab */
	);


/*
 * get a full array from matlabs workspace
 */
extern int engGetFull(
	Engine	*ep,		/* engine pointer */
	char	*name,		/* full array name */
	int     *m,         /* returned number of rows */
	int     *n,         /* returned number of columns */
	double	**pr,		/* returned pointer to real part */
	double	**pi		/* returned pointer to imaginary part */
	);


/*
 * put a full array in matlabs workspace
 */
extern int engPutFull(
	Engine	*ep,		/* engine pointer */
	char	*name,		/* full array name */
	int     m,          /* number of rows */
	int     n,          /* number of columns */
	double	*pr,		/* pointer to real part */
	double	*pi 		/* pointer to imaginary part */
	);


#if defined(_WINDOWS_)


/*
 * Register an engEvalString() callback routine
 * Not currently implemented
 */
extern void engSetEvalCallback(Engine *ep, void(*callback)());


/*
 * Set the engEvalString() timeout
 * Obsolete: no longer needed
 */ 	
extern void engSetEvalTimeout(Engine *ep, long timeout);


/*
 * Initialize the MATLAB engine session
 * Obsolete: no longer needed
 */
extern void engWinInit(HANDLE hInst);


#endif /* _WINDOWS_ */


#define engGetMatrix engGetArray
#define engPutMatrix engPutArray
#define engOpen engOpenV4
#else
#define engOpenV4()      cannot_call_engOpenV4
#define engGetFull()     engGetFull_is_obsolete
#define engPutFull()     engPutFull_is_obsolete
#define engGetMatrix()   engGetMatrix_is_obsolete
#define engPutMatrix()   engPutMatrix_is_obsolete
#endif /* defined(V4_COMPAT) */

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* engine_h */