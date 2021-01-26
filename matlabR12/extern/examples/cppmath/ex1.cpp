/* $Revision: 1.5 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc. All Rights Reserved.
//
// ex1.cpp
//
// Creating Arrays and Array I/O


#include "matlab.hpp"
#include <stdlib.h>     /* used for EXIT_SUCCESS */

#ifdef GCC
 #ifndef EXIT_SUCCESS
  #define EXIT_SUCCESS 0
 #endif
#endif

static double data[] = { 1, 2, 3, 4, 5, 6 };

int main(void)
{
  // create two matrices
  mwArray mat0(2, 3, data);
  mwArray mat1(3, 2, data);
		
  // print the matrices
  cout << mat0 << endl;
  cout << mat1 << endl;

  // read the matrix from standard in, the print it to standard out
  cout << "Please enter a matrix: " << endl;
  cin >> mat1;
  cout << mat1 << endl;

  return(EXIT_SUCCESS);
}
