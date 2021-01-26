function myarray = squares2(n) 
%Doc example.  Chapter 4.
% $Revision: 1.1 $

myarray = zeros(1,n); 
for i = 1:n 
  myarray(i) = i * i; 
end
