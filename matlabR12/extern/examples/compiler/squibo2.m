function g = squibo2(n) 
%Doc example.  Use of %realonly.
% $Revision: 1.2 $

%#realonly 
g = ones(1,n); 
for i=4:n 
  g(i) = sqrt(g(i - 1)) + g(i - 2) + g(i - 3); 
end
