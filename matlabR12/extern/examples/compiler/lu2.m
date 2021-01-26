function [A,p] = lu2(A) 
%Doc example.  When %#ivdep creates faster code.
% $Revision: 1.1 $

[m,n] = size(A); 
p = (1:m)'; 

for k = 1:min(m,n) - 1 
  q = min(find(abs(A(k:m,k)) == max(abs(A(k:m,k))))) + k - 1; 
  if q ~= k 
    p([k q]) = p([q k]); 
    A([k q],:) = A([q k],:); 
  end 
  if A(k,k) ~= 0 
    A(k+1:m,k) = A(k+1:m,k)/A(k,k); 
    for j = k+1:n; 
      %# ivdep 
      A(k+1:m,j) = A(k+1:m,j) - A(k+1:m,k)*A(k,j); 
    end 
  end 
end

