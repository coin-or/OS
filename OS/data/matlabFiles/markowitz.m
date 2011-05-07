%matlabSolver problem template
%
% the number of constraints
numCon = 2 ;
% the number of variables
numVar = 3;
%
% variable types 
% enter a single character for each variable
% enter a C for continuous variables
% enter a B for binary variables
% enter an I for general integer variables
VarType='CCC';
%
% constraint bounds
% if all constraints  <= leave BL empty
% for a default value of -inf
% if all constraints >= leave UB empty
% for a default value of  inf
% both BL and BU must be a 1 by numCon matrix
BU = [1  inf];
BL = [1   .15];
% variable bounds
% leave VL empty if all variables nonnegative
% leave VU empty if all variables have upper 
% bound of inf
% both VL and VU must be a 1 by numVar matrix
VL = [0 0 0 ];
VU = [.75 .75 .75];
% the objective function coefficients
% OBJ is a 1 by numVar matrix
% one number (even if zero) for every variable
OBJ = [0 0 0];
% the constraint matrix
% the number of rows should equal number of constraints
% the number of variables should equal number of variables
A = [ 1 1 1  ;
   0.3221  	0.0963	0.1187 ];
%ObjType =  1 for a max, 0  for a min
ObjType = 0;
% leave Q empty if there are no quadratic terms
% if there quadratic terms, the number of columns of Q
% should equal the number of quadratic terms and Q must have 4 rows
% the first row indexes which row the quadratic term appears in
% use -1 if the term is in the objective function
% use zero based counting for the row number
% the second row is the index of the first variable
% the thrid row is the index of the second variable
% use zero based counting for the variable indicies
% the last (fourth) row is the coefficient of the quadratic term
Q = [ -1 -1 -1 -1 -1 -1;
0 1 2 0 0 1 ;
0 1 2  1 2 2;
 .425349654  .445784443   0.231430983   .370437388  .27862509 .27763384];
% replace Template with the name of your  problem
prob_name = 'Markowitz Example from Anderson, Sweeney, Williams, and Martin';
password = ' ';
%
%the solver
solverName = 'ipopt';
%the remote service service address
%if left empty we solve locally
serviceAddress='';
% now solve
OSCallMatlabSolver( numVar, numCon, A, BL, BU, OBJ, VL, VU, ObjType, VarType, ...
     Q, prob_name, password, solverName, serviceAddress)

