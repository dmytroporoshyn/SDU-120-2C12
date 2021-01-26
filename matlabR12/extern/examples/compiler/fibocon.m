function g = fibocon(n,x) 
%Doc example.  Chapter 6.
% $Revision: 1.1 $

g(1)=1; 
g(2)=1; 
for i=3:n 
  g(i) = g(i - 1) + g(i - 2) + x; 
end
