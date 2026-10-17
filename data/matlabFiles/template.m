%matlabSolver problem template
%
% the number of constraints
numCon = ;
% the number of variables
numVar = ;
%
% variable types 
% enter a single character for each variable
% enter a C for continuous variables
% enter a B for binary variables
% enter an I for general integer variables
VarType='';
%
% constraint bounds
% if all constraints  <= leave BL empty
% for a default value of -inf
% if all constraints >= leave UB empty
% for a default value of  inf
% both BL and BU must be a 1 by numCon matrix
BU = [];
BL = [];
% variable bounds
% leave VL empty if all variables nonnegative
% leave VU empty if all variables have upper 
% bound of inf
% both VL and VU must be a 1 by numVar matrix
VL = [];
VU = [];
% the objective function coefficients
% OBJ is a 1 by numVar matrix
% one number (even if zero) for every variable
OBJ = [];
% the constraint matrix
% the number of rows should equal number of constraints
% the number of variables should equal number of variables
A = [];
%ObjType =  1 for a max, 0  for a min
ObjType = 1;
% leave Q empty if there are no quadratic terms
% if there quadratic terms, the number of columns of Q
% should equal the number of quadratic terms and Q must have 4 rows
% the first row indexes which row the quadratic term appears in
% use -1 if the term is in the objective function
% use zero based counting for the row number
% the second row is the index of the first variable
% the thrid row is the index of the second variable
% use zero based counting for the variable indices
% the last (fourth) row is the coefficient of the quadratic term
Q = [];
% replace Template with the name of your  problem
prob_name = 'Template Example'
%the solver
solverName = 'cbc';
%the remote service service address
%if left empty we solve locally
serviceAddress='';
% now solve
callMatLabSolver( numVar, numCon, A, BL, BU, OBJ, VL, VU, ObjType, VarType, Q, prob_name, password,solverName, serviceAddress)
