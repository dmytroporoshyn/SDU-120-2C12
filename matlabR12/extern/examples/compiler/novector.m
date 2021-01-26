function h = novector(stop) 
%Doc example.  Chapter 4.
% $Revision: 1.1 $

for angle = 1:stop 
  radians = (angle ./ 180) .* pi; 
  h(angle) = sin(radians); 
end
