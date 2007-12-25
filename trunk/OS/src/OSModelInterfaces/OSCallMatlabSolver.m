function callMatlabSolver(numVar, numCon, A, BL, BU, OBJ, VL, VU, ObjType, VarType, Q, prob_name, password, solverName, serviceAddress)
% callMatLabSolver invokes the Matlab mex routine to solve a MATLAB
% formulated problem using optimization services.
os_result = matlabSolver( numVar, numCon, A, BL, BU, OBJ, VL, VU, ObjType, VarType, Q, prob_name, password, solverName, serviceAddress);
if size(os_result) > 0
     fid = fopen('osrl.xml', 'w');
     fprintf(fid, '%s' ,os_result);
     fclose( fid);
     xslt('osrl.xml', 'OSrL.xslt', 'test.html');
     curdir = pwd;
     file_path = strcat('test.html');
     web(file_path);
end