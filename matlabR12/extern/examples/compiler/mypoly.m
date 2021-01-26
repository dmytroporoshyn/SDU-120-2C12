function g = mypoly(n) 
% Doc example.  Chapter 4.
 
% $Revision: 1.1 $

m = magic(n); 
m = m / 5; 
g = poly(m);
