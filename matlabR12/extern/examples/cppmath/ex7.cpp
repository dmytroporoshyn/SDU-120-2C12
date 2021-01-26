// $Revision: 1.9 $ 
// Copyright (c) 1995-1999 The MathWorks, Inc. All Rights Reserved.
//
// ex7.cpp
//
// Using load() and save()
//

#include "matlab.hpp"
#include <stdlib.h>     /* used for EXIT_SUCCESS */

#ifdef GCC
 #ifndef EXIT_SUCCESS
  #define EXIT_SUCCESS 0
 #endif
#endif

int main(void)
{
#ifdef EXCEPTIONS_WORK
  try
#endif
  {
      mwArray a, b, c, x, y, z;

      x = rand(4,4);
      y = magic(7);
      z = eig(x);

      // Save (and name) the variables
      save("ex5.mat", "x", x, "y", y, "z", z);

      // Load the named variables
      load("ex5.mat", "x", &a, "y", &b, "z", &c);

      // Check to be sure the variables are equal
      if (tobool(a == x) && tobool(b == y) && tobool(c == z))
      {
          cout << "Success: all variables equal" << endl;
      }
      else 
      {
          cout << "Failure: loaded values not equal to saved values" << endl;
      }
  }
#ifdef EXCEPTIONS_WORK
  catch (mwException &ex)
  {
      cout << ex;
  }
#endif

  return(EXIT_SUCCESS);
}
