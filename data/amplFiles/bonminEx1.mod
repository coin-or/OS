var x0 binary;
var x1 >= 0;
var x2 >= 0;
var x3 >= 0, integer;

min obj: 10*x0 - 10*x1 - 10*x2;

s.t. con0: (x1 - 0.5)**2 + (x2 - 0.5)**2 <= 0.25;
s.t. con1: x0 - x1       <= 0;
s.t. con2: x1 + x2 + x3  <= 2;


