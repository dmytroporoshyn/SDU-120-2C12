function [a,b,c]=vmfirst

%
%   Copyright 1984-2000 The MathWorks, Inc.
%   $Revision: 1.2 $  $Date: 2000/09/20 15:04:48 $
%
%   First example for MATLAB add-in for Visual Studio
%   standalone program.
%

a=magic(3)
b=inv(a)
c=a*b
maxerr=max(max(abs(c-eye(size(a)))))

