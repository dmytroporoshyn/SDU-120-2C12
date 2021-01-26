/* $Revision: 1.8 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc. All Rights Reserved.
//
// ex4.cpp
//
// Writing Simple Functions

#include "matlab.hpp"
#include <stdlib.h>     /* used for EXIT_SUCCESS */

#ifdef GCC
 #ifndef EXIT_SUCCESS
  #define EXIT_SUCCESS 0
 #endif
#endif

static double data0[] = { 2, 6, 4, 8 };
static double data1[] = { 1, 5, 3, 7 };

mwArray average(const mwArray &m1, const mwArray &m2)
{
  // (m1 + m2) / 2
  return rdivide(plus(m1, m2), 2);
}

int main(void)
{
  // create two matrices
  mwArray mat0(2, 2, data0);
  mwArray mat1(2, 2, data1);
  mwArray mat2;

  mat2 = average(mat0, mat1);

  cout << mat0 << "\t + \n" << mat1 << "\t /2 = \n" << mat2;

  return(EXIT_SUCCESS);
}
