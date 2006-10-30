/** @file IpoptSolver.cpp
 * 
 * \brief This file defines the IpoptSolver class.
 * \detail Read an OSInstance object and convert in Ipopt data structures
 *
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */


#include "IpoptSolver.h"
  
using std::cout; 
using std::endl; 
using std::ostringstream;
using namespace Ipopt;


IpoptSolver::IpoptSolver() {
	osrlwriter = new OSrLWriter();
}

IpoptSolver::~IpoptSolver() {
	#ifdef DEBUG
	cout << "inside IpoptSolver destructor" << endl;
	#endif
	delete osrlwriter;
	osrlwriter = NULL;
	#ifdef DEBUG
	cout << "leaving IpoptSolver destructor" << endl;
	#endif
}

// returns the size of the problem
bool IpoptSolver::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                             Index& nnz_h_lag, IndexStyleEnum& index_style){
	// number of variables
	n = osinstance->getVariableNumber();

	// number of constraints
	m = osinstance->getConstraintNumber();

	// nonzeros in jacobian
	SparseJacobianMatrix *sparseJacobian = osinstance->getJacobianSparsityPattern();
	nnz_jac_g = sparseJacobian->valueSize;

	// nonzeros in upper hessian
	SparseHessianMatrix *sparseHessian = osinstance->getLagrangianHessianSparsityPattern();
	nnz_h_lag = sparseHessian->hessDimension;

	// use the C style indexing (0-based)
	index_style = TNLP::C_STYLE;

	return true;
}//get_nlp_info

// returns the variable bounds
bool IpoptSolver::get_bounds_info(Index n, Number* x_l, Number* x_u,
                                Index m, Number* g_l, Number* g_u){
	//variables lower bounds
	double * mdVarLB = osinstance->getVariableLowerBounds();
	x_l = mdVarLB;
	/*
	for (Index i=0; i<n; i++) {
		x_l[i] = mdVarLB[i];
	}
	*/

	// variables upper bounds
	double * mdVarUB = osinstance->getVariableUpperBounds();
	x_u = mdVarUB;
	/*
	for (Index i=0; i<n; i++) {
		x_u[i] = mdVarUB[i];
	}
	*/

	// the first constraint g1 has NO upper bound, here we set it to 2e19.
	// Ipopt interprets any number greater than nlp_upper_bound_inf as
	// infinity. The default value of nlp_upper_bound_inf and nlp_lower_bound_inf
	// is 1e19 and can be changed through ipopt options.
	// e.g. g_u[0] = 2e19;

	//constraint lower bounds
	double * mdConLB = osinstance->getConstraintLowerBounds();
	g_l = mdConLB;
	/*
	for (Index j=0; j<m; j++) {
		g_l[j] = mdConLB[j];
	}
	*/

	//constraint lower bounds
	double * mdConUB = osinstance->getConstraintUpperBounds();
	g_u = mdConUB;
	/*
	for (Index j=0; j<m; j++) {
		g_u[j] = mdConUB[j];
	}
	*/

	return true;
}//get_bounds_info


// returns the initial point for the problem
bool IpoptSolver::get_starting_point(Index n, bool init_x, Number* x,
                                   bool init_z, Number* z_L, Number* z_U,
                                   Index m, bool init_lambda,
                                   Number* lambda){
	// Here, we assume we only have starting values for x, if you code
	// your own NLP, you can provide starting values for the dual variables
	// if you wish
	//assert(init_x == true);
	//assert(init_z == false);
	//assert(init_lambda == false);

    double * mdXInit = osinstance->getVariableInitialValues();
	x = mdXInit;

	return true;
}//get_starting_point

// returns the value of the objective function
bool IpoptSolver::eval_f(Index n, const Number* x, bool new_x, Number& obj_value){
	
	obj_value = osinstance->calculateFunctionValue(-1, (double*)x, !new_x);
	return true;
}//eval_f

// return the gradient of the objective function grad_{x} f(x)
bool IpoptSolver::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f){
  
	grad_f = osinstance->calculateObjectiveFunctionGradient(-1, (double*)x, !new_x, false);
	return true;
}//eval_grad_f

// return the value of the constraints: g(x)
bool IpoptSolver::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g){

	g = osinstance->calculateAllConstraintFunctionValues((double*)x, !new_x);
	return true;
}//eval_g

// return the structure or values of the jacobian
bool IpoptSolver::eval_jac_g(Index n, const Number* x, bool new_x,
                           Index m, Index nele_jac, Index* iRow, Index *jCol,
                           Number* values){
	SparseJacobianMatrix *sparseJacobian;
	if (values == NULL) {
		// return the structure of the jacobian
		sparseJacobian = osinstance->getJacobianSparsityPattern();

		int i = 0;
		int k, idx;
		for(idx = 0; idx < m; idx++){
			for(k = *(sparseJacobian->starts + idx); k < *(sparseJacobian->starts + idx + 1); k++){
				iRow[i] = idx;
				jCol[i] = *(sparseJacobian->indexes + k);
				i++;
			}
		}	
	}
	else {
		// return the values of the jacobian of the constraints
		sparseJacobian = osinstance->calculateAllConstraintFunctionGradients((double*)x, !new_x, false);
		values = sparseJacobian->values;
	}

	return true;
}//eval_jac_g


//return the structure or values of the hessian
bool IpoptSolver::eval_h(Index n, const Number* x, bool new_x,
                       Number obj_factor, Index m, const Number* lambda,
                       bool new_lambda, Index nele_hess, Index* iRow,
                       Index* jCol, Number* values){
	SparseHessianMatrix *sparseHessian;
	if (values == NULL) {
		// return the structure. This is a symmetric matrix, fill the lower left triangle only.

		sparseHessian = osinstance->getLagrangianHessianSparsityPattern( );

		int i, j;
		for(i = 0; i < nele_hess; i++){
			iRow[i] = *(sparseHessian->hessColIdx + i);
			jCol[i] = *(sparseHessian->hessRowIdx + i);
		}
	}
	else {
		// return the values. This is a symmetric matrix, fill the lower left triangle only
		double* objMultipliers = new double[0];
		objMultipliers[0] = obj_factor;
		sparseHessian = osinstance->calculateLagrangianHessian((double*)x, (double*)lambda, objMultipliers, !new_x, false);
		values = sparseHessian->hessValues;
	}
	return true;
}//eval_h

void IpoptSolver::finalize_solution(SolverReturn status,
            Index n, const Number* x, const Number* z_L, const Number* z_U,
            Index m, const Number* g, const Number* lambda,
            Number obj_value){
  // here is where we would store the solution to variables, or write to a file, etc
  // so we could use the solution.

  // For this example, we write the solution to the console
  printf("\n\nSolution of the primal variables, x\n");
  for (Index i=0; i<n; i++) {
    printf("x[%d] = %e\n", i, x[i]);
  }

  printf("\n\nSolution of the bound multipliers, z_L and z_U\n");
  for (Index i=0; i<n; i++) {
    printf("z_L[%d] = %e\n", i, z_L[i]);
  }
  for (Index i=0; i<n; i++) {
    printf("z_U[%d] = %e\n", i, z_U[i]);
  }

  printf("\n\nObjective value\n");
  printf("f(x*) = %e\n", obj_value);

  ///////////////////////////////////////
  	int solIdx = 0;
	ostringstream outStr;
	int i = 0;
	int nSolStatus;
	std::string description = "";	
	std::string message = "";

	// resultHeader infomration
	if(osresult->setServiceName( "Solved using a Ipopt solver service") != true)
		throw ErrorClass("OSResult error: setServiceName");
	if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
		throw ErrorClass("OSResult error: setInstanceName");


	//if(osresult->setJobID( osoption->jobID) != true)
	//	throw ErrorClass("OSResult error: setJobID");
	if(osresult->setGeneralMessage( message) != true)
		throw ErrorClass("OSResult error: setGeneralMessage");


	// set basic problem parameters
	if(osresult->setVariableNumber( osinstance->getVariableNumber()) != true)
		throw ErrorClass("OSResult error: setVariableNumer");
	if(osresult->setObjectiveNumber( 1) != true)
		throw ErrorClass("OSResult error: setObjectiveNumber");
	if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
		throw ErrorClass("OSResult error: setConstraintNumber");
	if(osresult->setSolutionNumber(  1) != true)
		throw ErrorClass("OSResult error: setSolutionNumer");	

	try{
		if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Ipopt NEEDS AN OBJECTIVE FUNCTION");










		osrl = osrlwriter->writeOSrL( osresult);

	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ;
	}

}//finalize_solution

void IpoptSolver::solve() throw (ErrorClass) {
	OSiLReader* osilreader = NULL; 
	osresult = new OSResult();
	try{
		if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
		clock_t start, finish;
		double duration;
		start = clock();
		if(osinstance == NULL){
			osilreader = new OSiLReader();
			osinstance = osilreader->readOSiL( &osil);
		}
		OSiLWriter osilwriter;
		//cout << osilwriter.writeOSiL( osinstance) << endl;
		if(osinstance->getVariableNumber() <= 0)throw ErrorClass("Ipopt requires decision variables");
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Parsing took (seconds): "<< duration << endl;
		//dataEchoCheck();

		/***************now the ipopt invokation*********************/


		delete osilreader;
		osilreader = NULL;
	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ;
	}
}//solve


void IpoptSolver::dataEchoCheck(){
	
	int i;
	
	// print out problem parameters
	cout << "This is problem:  " << osinstance->getInstanceName() << endl;
	cout << "The problem source is:  " << osinstance->getInstanceSource() << endl;
	cout << "The problem description is:  " << osinstance->getInstanceDescription() << endl;
	cout << "number of variables = " << osinstance->getVariableNumber() << endl;
	cout << "number of Rows = " << osinstance->getConstraintNumber() << endl;

	// print out the variable information
	if(osinstance->getVariableNumber() > 0){
		for(i = 0; i < osinstance->getVariableNumber(); i++){
			if(osinstance->getVariableNames() != NULL) cout << "variable Names  " << osinstance->getVariableNames()[ i]  << endl;
			if(osinstance->getVariableTypes() != NULL) cout << "variable Types  " << osinstance->getVariableTypes()[ i]  << endl;
			if(osinstance->getVariableLowerBounds() != NULL) cout << "variable Lower Bounds  " << osinstance->getVariableLowerBounds()[ i]  << endl;
			if(osinstance->getVariableUpperBounds() != NULL) cout << "variable Upper Bounds  " <<  osinstance->getVariableUpperBounds()[i] << endl;
		}
	}
	
	// print out objective function information
	if(osinstance->getVariableNumber() > 0 || osinstance->instanceData->objectives->obj != NULL || osinstance->instanceData->objectives->numberOfObjectives > 0){
		if( osinstance->getObjectiveMaxOrMins()[0] == "min")  cout <<  "problem is a minimization" << endl;
		else cout <<  "problem is a maximization" << endl;
		for(i = 0; i < osinstance->getVariableNumber(); i++){
			cout << "OBJ COEFFICIENT =  " <<  osinstance->getDenseObjectiveCoefficients()[0][i] << endl;
		}
	}
	// print out constraint information
	if(osinstance->getConstraintNumber() > 0){
		for(i = 0; i < osinstance->getConstraintNumber(); i++){
			if(osinstance->getConstraintNames() != NULL) cout << "row name = " << osinstance->getConstraintNames()[i] <<  endl;
			if(osinstance->getConstraintLowerBounds() != NULL) cout << "row lower bound = " << osinstance->getConstraintLowerBounds()[i] <<  endl;
			if(osinstance->getConstraintUpperBounds() != NULL) cout << "row upper bound = " << osinstance->getConstraintUpperBounds()[i] <<  endl; 
		}
	}
	
	// print out linear constraint data
	cout << endl;
	cout << "number of nonzeros =  " << osinstance->getLinearConstraintCoefficientNumber() << endl;
	for(i = 0; i <= osinstance->getVariableNumber(); i++){
		cout << "Start Value =  " << osinstance->getLinearConstraintCoefficientsInColumnMajor()->starts[ i] << endl;
	}
	cout << endl;
	for(i = 0; i < osinstance->getLinearConstraintCoefficientNumber(); i++){
		cout << "Index Value =  " << osinstance->getLinearConstraintCoefficientsInColumnMajor()->indexes[i] << endl;
		cout << "Nonzero Value =  " << osinstance->getLinearConstraintCoefficientsInColumnMajor()->values[i] << endl;
	}

	// print out quadratic data
	cout << "number of qterms =  " <<  osinstance->getNumberOfQuadraticTerms() << endl;
	for(int i = 0; i <  osinstance->getNumberOfQuadraticTerms(); i++){
		cout << "Row Index = " <<  osinstance->getQuadraticTerms()->rowIndexes[i] << endl;
		cout << "Var Index 1 = " << osinstance->getQuadraticTerms()->varOneIndexes[ i] << endl;
		cout << "Var Index 2 = " << osinstance->getQuadraticTerms()->varTwoIndexes[ i] << endl;
		cout << "Coefficient = " << osinstance->getQuadraticTerms()->coefficients[ i] << endl;
	}
} // end dataEchoCheck





