% the number of constraints
numCon = 4;
% the number of variables
numVar = 2;
% variable types 
VarType='CC';
% constraint types
A = [.7  1; .5  5/6; 1   2/3  ; .1   .25];
BU = [630 600  708  135];
BL = [-inf -inf -inf -inf ];
OBJ = [10  9];
VL = [0 0];
VU = [inf inf];
ObjType = 1;
% leave Q empty if there are no quadratic terms
Q = [];
prob_name = 'ParInc Example';
password = '';
%
%
%the solver
solverName = 'clp';
%the remote service service address
%if left empty we solve locally
serviceAddress='';
% now solve
OSCallMatlabSolver( numVar, numCon, A, BL, BU, OBJ, VL, VU, ObjType, ... 
    VarType, Q, prob_name, password, solverName, serviceAddress)

