function theImage = gasket(numPoints)
%GASKET An image of a Sierpinski Gasket.
%   IM = GASKET(NUMPOINTS)
%
%   Example:
%   x = gasket(50000);
%   imagesc(x);colormap([0 0 0;1 1 1]);
%   axis equal tight

%   Copyright (c) 1984-98 by The MathWorks, Inc
%   $Revision: 1.1 $  $Date: 1998/09/11 20:05:06 $

theImage = zeros(1000,1000);

corners = [866 1;1 500;866 1000];
startPoint = [866 1];
theRand = rand(numPoints,1);
theRand = ceil(theRand*3);

for i=1:numPoints
   startPoint = floor((corners(theRand(i),:)+startPoint)/2);
   theImage(startPoint(1),startPoint(2)) = 1;
end
