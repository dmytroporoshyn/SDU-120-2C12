/* $Revision: 1.11 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc. All Rights Reserved.
//
// ex8.cpp
//
// Rewriting roots.m in C++

#include "matlab.hpp"
#include <stdlib.h>     /* used for EXIT_SUCCESS */

#ifdef GCC
 #ifndef EXIT_SUCCESS
  #define EXIT_SUCCESS 0
 #endif
#endif

// ROOTS(C) computes the root sof the polynomial whos
// coefficients are the elements of the vector C.  if C has N+1
// components, the polynomial is C(1)*X^N + ... + C(N)*X + C(N+1)

mwArray example_roots(mwArray c)
{
  mwArray n, inz, nnz, r, a;
  mwIndex x;
  
  // all dimensions greater than 1?
  n = size(c);
  if(tobool(all(n>1.0)))
    error("Must be a vector");
  
  n = max(n);
  c = transpose(c(x));   // make sure it's a row vector
  inz = find(abs(c));    // find all nonzero elements
  nnz = max(size(inz));  // count nonzero elements
  
  // test all the arguments against zero
  if(!tobool(nnz == 0.0))
    {
      c = c(ramp(inz(1), inz(nnz)));
      r = zeros(n-inz(nnz), 1);
    }
  
  // polynomial roots via a companion matrix
  n = max(size(c));                // size of the largest dimension of c
  a = diag(ones(1, n-2.0), -1.0);  // create a row vector of 1's
  
  if(tobool(n>1.0))
    a(1,x) = -c(ramp(2, n))/c(1);
  
  r = vertcat(r, eig(a));
  
  return(r);
}

// call roots() using the example in the MATLAB Users Guide
int main(void)
{
  // static arrays of doubles used to initialize the matrices
  static double input[] = { 1, -6, -72, -27 };
  
  // declare three matrices, one with initial values
  mwArray x(1, 4, input), result, verify;
  
  // call our version of roots()
  result = example_roots(x);
  
  // call the MALTAB C Math Library roots
  verify = roots(x);         
  
  // print the input and out matrices from example_roots()
  cout << "x = " << endl << x << endl;
  cout << "example_roots(x) = " << endl << result << endl;
  
  // check to see if the answer is equal to the real roots()
  if (tobool(result == verify))
    cout << "Success!" << endl;
  
  return(EXIT_SUCCESS);
}
