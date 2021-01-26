/* $Revision: 1.5 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc. All Rights Reserved.
//
// ex2.cpp
//
// Calling Library Routines

#include "matlab.hpp"
#include <stdlib.h>     /* used for EXIT_SUCCESS */

#ifdef GCC
 #ifndef EXIT_SUCCESS
  #define EXIT_SUCCESS 0
 #endif
#endif

static double data[] = { 1, 3, 5, 7, 2, 4, 6, 8 };

int main(void)
{
  // create the input matrix
  mwArray X(4, 2, data);
  mwArray U, S, V;

  // compute the singular value decompostion of the matrix
  cout << "One input, one output: " << endl;
  cout << "S = " << svd(X) << endl;

  // pass in optional output arguments
  U = svd(&S, &V, X);

  cout << "One input, three outputs: " << endl;
  cout << "U = " << U << "S = " << S << "V = " << V << endl;

  // pass in optional argument
  U = svd(&S, &V, X, 0.0);

  cout << "Two inputs, three outputs: " << endl;
  cout << "U = " << U << "S = " << S << "V = " << V;

  return(EXIT_SUCCESS);
}
