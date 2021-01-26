function h = yovector(stop) 
%Doc example.  Chapter 4.
% $Revision: 1.1 $

angle = 1:stop; 
radians = (angle ./ 180) .* pi; 
h = sin(radians);
