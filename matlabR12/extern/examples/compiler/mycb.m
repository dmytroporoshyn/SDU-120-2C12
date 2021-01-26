function g = mycb(n) 
% Doc example.  Chapter 4.

% $Revision: 1.1 $

g = ones(1,n); 
for i = 4:n 
  temp1 = log(g(i - 1) + g(i - 2)); 
  temp2 = tan(g(i - 3)); 
  g(i) = temp1 + temp2; 
end 
log10(g);
