function a = mydep 
%Doc example.  When %#ivdep generates incorrect results.
% $Revision: 1.1 $

a = 1:8; 
%#ivdep
a(3:6) = a(1:4);

