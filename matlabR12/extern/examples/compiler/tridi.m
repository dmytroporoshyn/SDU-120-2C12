function x = tridi(a,b,c,d)
%TRIDI  Solve tridiagonal system of equations
%       x = TRIDI(a,b,c,d) solves the system of linear
%       equations x = T\d where T is the the tridiagonal
%       matrix with a on the subdiagonal, b on the diagonal,
%       and c on the superdiagonal, i. e.
%       M = diag(a,-1) + diag(b,0) + diag(c,1)
%
% $Revision: 1.1 $
%
n = length(b);
x = zeros(size(b));

for j = 2:n 
        p = a(j-1)/b(j-1);
        b(j) = b(j) - p*c(j-1);
        d(j) = d(j) - p*d(j-1);
end

x(n) = d(n)/b(n); 
for j = (n-1):-1:1
        x(j) = (d(j)-c(j)*x(j+1))/b(j); 
end
