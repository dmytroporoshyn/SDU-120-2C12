function g = fibomult(n) 
% Doc example.  Chapter 4.

% $Revision: 1.1 $

g = ones(1,n); 
for i = 3:n 
  g(i) = myfunc(g(i - 1)) + g(i - 2); 
end

