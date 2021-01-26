/* $Revision: 1.7 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc. All Rights Reserved.
// 
// ex3.cpp
//
// Passing Functions As Arguments


#include "matlab.hpp"
#include <stdlib.h>     /* used for EXIT_SUCCESS */

#ifdef GCC
 #ifndef EXIT_SUCCESS
  #define EXIT_SUCCESS 0
 #endif
#endif

mwArray func1(mwArray x)
{
  // one argument test function
  return(times(realsqrt(x), reallog(x)));
}

typedef mwArray (*PFCN_1_1)(mwArray);

extern "C" {
static

// This is a "thunk function".
// The thunk function serves as an interpreter, if you will, between the
// library's internal feval() mechanism and the user functions. There must
// be one thunk function for every possible combination of input and output
// arguments.

int one_input_one_output( mlfFuncp pFunc, int nlhs, mxArray **lhs, int nrhs,
                          mxArray **rhs )
{
    int ret = 0;
    MW_BEGIN_MLX();
    mwArray Out;
    if ( nlhs <= 1 && nrhs <= 1 )
    {

	mwArray tmp = mwArray( rhs[0], 0 );

	Out = (*((PFCN_1_1)pFunc))(
		nrhs > 0 ? tmp : mwArray::DIN
	);

        ret = 1;

	if (nlhs > 0) 
	{
		lhs[0] = Out.FreezeData();
	}
    }
    MW_END_MLX();

    return(ret);

}
}

// This table maps string function names to function pointers. The
// entries in the table are triplets:
//
//    <string name> <user function> <thunk function>
// 
// Every function that can be called by feval() (directly or indirectly)
// must have an entry in a table like this.

static mlfFuncTabEnt MFuncTab[] = 
{
	{ "func1", (mlfFuncp) func1, one_input_one_output },
	{ 0, 0, 0 }
};

//
// The following code is a static initializer used
// to initalize the feval function table.  It is intentionally
// outside the body of any function
//
class feval_init {
	feval_init() { mlfFevalTableSetup( MFuncTab ); }
	static feval_init feval_setup;
};

feval_init feval_init::feval_setup;

int main(void)
{
#ifdef EXCEPTIONS_WORK
    try {
#endif

        cout << fminsearch("func1", 0.25) << endl;

#ifdef EXCEPTIONS_WORK
    }
    catch (mwException &ex)
    {
        cout << ex;
    }
#endif

  return(EXIT_SUCCESS);
}
