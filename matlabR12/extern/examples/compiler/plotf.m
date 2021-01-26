function plotf(fun1,fun2,x) 
%Doc example.  Chapter 4.
% $Revision: 1.1 $

hold on 
y = feval(fun1,x); 
plot(x,y,'g+'); 
z = feval(fun2,x); 
plot(x,z,'b');
