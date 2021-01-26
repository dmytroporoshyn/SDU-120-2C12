/* $Revision: 1.8 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc. All Rights Reserved.
//
// ex6.cpp
//
// Using File I/O Functions


#include "matlab.hpp"
#include <stdlib.h>     /* used for EXIT_SUCCESS */

#ifdef GCC
 #ifndef EXIT_SUCCESS
  #define EXIT_SUCCESS 0
 #endif
#endif

int main(void)
{
  mwArray a("Alas, poor Yorick.  I knew him, Horatio.");
  mwArray b("Blow, wind, and crack you cheeks!");
  mwArray c("Cry havoc, and let slip the dogs of war!");
  mwArray d("Out, out, damned spot!");
  mwArray fid, r, a1, b1, c1, d1, mode("w"), sz, x, y;
  mwArray file("ex6.txt");

  // write string data to a file, then read it
  fid = fopen(file, mode);
  fprintf(fid, "%s\n", a, b, c, d);
  fclose(fid);

  fid = fopen(file);
  a1 = fgetl(fid);
  b1 = fgetl(fid);
  c1 = fgetl(fid);
  d1 = fgetl(fid);

  cout << a1 << endl << b1 << endl << c1 << endl << d1 << endl;
  fclose(fid);

  // now try numeric data
  fid = fopen(file, mode);
  fprintf(fid, "%f ", magic(4), rand(4));
  fclose(fid);

  fid = fopen(file);
  sz = horzcat(4, 4);
  x = fscanf(fid, "%f ", sz);
  cout << x << endl;
  y = fscanf(fid, "%f ", sz);
  cout << y << endl;
  fclose(fid);

  return(EXIT_SUCCESS);
}
