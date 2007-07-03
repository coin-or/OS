% the number of constraints
numCon = 4;
% the number of variables
numVar = 2;
% variable types 
VarType='CC';
% constraint types
A = [.7  1; .5  5/6; 1   2/3  ; .1   .25];
BU = [630 600  708  135];
BL = [];
OBJ = [10  9];
VL = [-inf -inf];
VU = [];
ObjType = 1;
% leave Q empty if there are no quadratic terms
Q = [];
prob_name = 'ParInc Example'
password = 'chicagoesmuyFRIO';
%
%
%the solver
solverName = 'lindo';
%the remote service service address
%if left empty we solve locally
serviceAddress='http://128.135.130.17:8080/os/OSSolverService.jws';
% now solve
callMatlabSolver( numVar, numCon, A, BL, BU, OBJ, VL, VU, ObjType, ... 
    VarType, Q, prob_name, password, solverName, serviceAddress)
