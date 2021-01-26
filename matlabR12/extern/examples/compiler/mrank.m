function r = mrank(n)
%Doc example.  Chapter 5.

% $Revision: 1.2 $

r = zeros(n,1);
for k = 1:n
   r(k) = rank(magic(k));
end
