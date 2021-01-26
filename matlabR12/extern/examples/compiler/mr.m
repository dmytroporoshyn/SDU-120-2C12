function mr(m) 
%Doc example.  Chapter 5.
% $Revision: 1.4 $

initprnt; % Call a print handler initialization routine
m=str2num(m);
r = mrank(m)

function initprnt
%#external
