/* $Revision: 1.11 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc. All Rights Reserved.
//
// ex5.cpp
//
// Handling Exceptions

#include "matlab.hpp"
#include <stdlib.h>     /* used for EXIT_SUCCESS, EXIT_FAILURE */

#ifdef GCC
 #ifndef EXIT_SUCCESS
  #define EXIT_SUCCESS 0
 #endif
 #ifndef EXIT_FAILURE
  #define EXIT_FAILURE 1
 #endif
#endif

static double data[] = { 1, 2, 3, 4, 5, 6 };

mwArray compute(const mwArray &in)
{
  // illegal operation: negative index
  return in(-5) * 17;
}

int main(void)
{
  // handle exceptions for all code in the try-block
#ifdef EXCEPTIONS_WORK
  try
#endif
    {
      mwArray mat0(2, 3, data);
      mwArray mat1;
					
      mat1 = compute(mat0);
      cout << mat1 << endl;
    }
		
#ifdef EXCEPTIONS_WORK
  // catch and print any exceptions that occur
  catch(mwException &ex)
    {
      cout << ex ;
      return(EXIT_FAILURE);
    }
#endif

  return(EXIT_SUCCESS);
}
