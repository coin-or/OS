% Markowitz example from www.lindo.com
% x0 = .530093,  x1 = .356411, x2 = .113497
% obj = .0224138
% the number of constraints
numCon = 2;
% the number of variables
numVar = 3;
% variable types 
VarType='CCC';
% constraint types
A = [ 1 1 1  ;
     .0890833  .213667  .234583];
BU = [1  inf];
BL = [1   .15];
OBJ = [0 0 0];
VL = [0  0  0];
VU = [.75 .75 .75];
ObjType = 0;
% leave Q empty if there are no quadratic terms
Q = [ -1 -1 -1 -1 -1 -1 -1 -1 -1 ;
     0 0 0  1 1 1  2 2 2;
     0 1 2  0 1 2  0 1 2 ;
.01080754 .01240721 .01307513    .01240721 .05839170 .05542639    .01307513 .05542639 .09422681];
%Q = [];
prob_name = 'Makowitz Example'
password = 'chicagoesmuyFRIO';
callMatlabSolver( numVar, numCon, A, BL, BU, OBJ, VL, VU, ObjType, VarType, Q, prob_name, password);
