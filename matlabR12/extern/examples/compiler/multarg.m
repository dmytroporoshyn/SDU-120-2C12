function [a, b] = multarg(x, y)
% multargp.c calls this M-file.
% $Revision: 1.1 $
%
a = (x + y) * pi; 
b = svd(svd(a)); 
