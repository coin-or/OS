/** @file IpoptSolver.cpp
 * 
 * \brief This file defines the IpoptSolver class.
 * \detail Read an OSInstance object and convert to Ipopt data structures
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

#define DEBUG

#include "OSIpoptSolver.h"
#include "OSDataStructures.h"
#include "OSParameters.h" 
#include "OSCommonUtil.h"
#include "OSMathUtil.h"


using std::cout; 
using std::endl; 
using std::ostringstream;
using namespace Ipopt;


IpoptSolver::IpoptSolver() {
	osrlwriter = new OSrLWriter();
	osresult = new OSResult();
	m_osilreader = NULL;
	m_osolreader = NULL;
	ipoptErrorMsg = "";
} 

IpoptSolver::~IpoptSolver() {
	#ifdef DEBUG
	cout << "inside IpoptSolver destructor" << endl;
	#endif
	if(m_osilreader != NULL) delete m_osilreader;
	m_osilreader = NULL;
	if(m_osolreader != NULL) delete m_osolreader;
	m_osolreader = NULL;
	delete osresult;
	osresult = NULL;
	delete osrlwriter;
	osrlwriter = NULL;
	//delete osinstance;
	//osinstance = NULL;
	#ifdef DEBUG
	cout << "leaving IpoptSolver destructor" << endl;
	#endif
}

// returns the size of the problem
bool IpoptProblem::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                             Index& nnz_h_lag, IndexStyleEnum& index_style)
{
	if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Ipopt NEEDS AN OBJECTIVE FUNCTION");                 	
	// number of variables
	n = osinstance->getVariableNumber();
	// number of constraints
	m = osinstance->getConstraintNumber();
#ifdef DEBUG
	cout << "number variables  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << n << endl;
	cout << "number constraints  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << m << endl;
#endif
	try{
		osinstance->initForAlgDiff( );
	}
	catch(const ErrorClass& eclass){
		ipoptErrorMsg = eclass.errormsg;
		throw;  
	}	
	// use the OS Expression tree for function evaluations instead of CppAD
	osinstance->bUseExpTreeForFunEval = true;
	//std::cout << "Call sparse jacobian" << std::endl;
	SparseJacobianMatrix *sparseJacobian = NULL;
	try{
		sparseJacobian = osinstance->getJacobianSparsityPattern();
	}
	catch(const ErrorClass& eclass){
		ipoptErrorMsg = eclass.errormsg;
		throw;  
	}
	//std::cout << "Done calling sparse jacobian" << std::endl;
	nnz_jac_g = sparseJacobian->valueSize;
#ifdef DEBUG
	cout << "nnz_jac_g  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << nnz_jac_g << endl;	
#endif
	// nonzeros in upper hessian
	
	if( (osinstance->getNumberOfNonlinearExpressions() == 0) && (osinstance->getNumberOfQuadraticTerms() == 0) ) {
#ifdef DEBUG
		cout << "This is a linear program"  << endl;
#endif
		nnz_h_lag = 0;
	}
	else{
		//std::cout << "Get Lagrangain Hessian Sparsity Pattern " << std::endl;
		SparseHessianMatrix *sparseHessian = osinstance->getLagrangianHessianSparsityPattern();
		//std::cout << "Done Getting Lagrangain Hessian Sparsity Pattern " << std::endl;
		nnz_h_lag = sparseHessian->hessDimension;
	}
#ifdef DEBUG
	cout << "nnz_h_lag  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << nnz_h_lag << endl;	
#endif
	// use the C style indexing (0-based)
	index_style = TNLP::C_STYLE;
  
  /////

  return true;
}//get_nlp_info


bool  IpoptProblem::get_bounds_info(Index n, Number* x_l, Number* x_u,
                                Index m, Number* g_l, Number* g_u){
 	int i; 
	double * mdVarLB = osinstance->getVariableLowerBounds();
	//std::cout << "GET BOUNDS INFORMATION FOR IPOPT !!!!!!!!!!!!!!!!!" << std::endl;
	// variables upper bounds
	double * mdVarUB = osinstance->getVariableUpperBounds();

	for(i = 0; i < n; i++){
		x_l[ i] = mdVarLB[ i];
		x_u[ i] = mdVarUB[ i];
		//cout << "x_l !!!!!!!!!!!!!!!!!!!!!!!!!!!" << x_l[i] << endl;
		//cout << "x_u !!!!!!!!!!!!!!!!!!!!!!!!!!!" << x_u[i] << endl;
	}
	// Ipopt interprets any number greater than nlp_upper_bound_inf as
	// infinity. The default value of nlp_upper_bound_inf and nlp_lower_bound_inf
	// is 1e19 and can be changed through ipopt options.
	// e.g. g_u[0] = 2e19;

	//constraint lower bounds
	double * mdConLB = osinstance->getConstraintLowerBounds();
	//constraint upper bounds
	double * mdConUB = osinstance->getConstraintUpperBounds();
	
	for(int i = 0; i < m; i++){
		g_l[ i] = mdConLB[ i];
		g_u[ i] = mdConUB[ i];
		//cout << "lower !!!!!!!!!!!!!!!!!!!!!!!!!!!" << g_l[i] << endl;
		//cout << "upper !!!!!!!!!!!!!!!!!!!!!!!!!!!" << g_u[i] << endl;
	}  
  	return true;
}//get_bounds_info


// returns the initial point for the problem
bool IpoptProblem::get_starting_point(Index n, bool init_x, Number* x,
     bool init_z, Number* z_L, Number* z_U, Index m, bool init_lambda,
     Number* lambda) {
  	// Here, we assume we only have starting values for x, if you code
  	// your own NLP, you can provide starting values for the dual variables
  	// if you wish
  	assert(init_x == true);
  	assert(init_z == false);
  	assert(init_lambda == false);
  	int i, m1, n1;

#ifdef DEBUG
  	cout << "get initial values !!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
#endif
  	
	//now set initial values
#ifdef DEBUG
  	cout << "get number of initial values !!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
	cout << "Is osoption = NULL? " << (osoption == NULL) << endl;
#endif
	int k;
	m1 = osoption->getNumberOfInitVarValues();
#ifdef DEBUG
	cout << "number of variables initialed: " << m1 << endl;
#endif

	n1 = osinstance->getVariableNumber();
	bool* initialed;
	initialed = new bool[n1];
#ifdef DEBUG
	cout << "number of variables in total: " << n1 << endl;
#endif

	for(k = 0; k < n1; k++)
		initialed[k] = false;

	if (m1 > 0)
	{
#ifdef DEBUG
			cout << "get initial values " << endl;
#endif

		InitVarValue**  initVarVector = osoption->getInitVarValuesSparse();
#ifdef DEBUG
		cout << "done " << endl;
#endif

		double initval;
		for(k = 0; k < m1; k++)
		{	cout << "process component " << k << " -- index " << initVarVector[k]->idx << endl;
			i = initVarVector[k]->idx;
			if (initVarVector[k]->idx > n1)
				throw ErrorClass ("Illegal index value in variable initialization");

				initval = initVarVector[k]->value;
				if (osinstance->instanceData->variables->var[k]->ub == OSDBL_MAX)
				{	if (osinstance->instanceData->variables->var[k]->lb > initval)
						throw ErrorClass ("Initial value outside of bounds");
				}
				else
					if (osinstance->instanceData->variables->var[k]->lb == -OSDBL_MAX)
					{	if (osinstance->instanceData->variables->var[k]->ub < initval)
							throw ErrorClass ("Initial value outside of bounds");
					}
					else
					{	if ((osinstance->instanceData->variables->var[k]->lb > initval) ||
							(osinstance->instanceData->variables->var[k]->ub < initval))
							throw ErrorClass ("Initial value outside of bounds");
					}

			x[initVarVector[k]->idx] = initval;
			initialed[initVarVector[k]->idx] = true;
		}
	}  //  end if (m1 > 0)		

	double default_initval;
	default_initval = 1.7171;

	for(k = 0; k < n1; k++)
	{	cout << "verify component " << k << endl;
		if (!initialed[k])
			if (osinstance->instanceData->variables->var[k]->ub == OSDBL_MAX)
				if (osinstance->instanceData->variables->var[k]->lb <= default_initval)
					x[k] = default_initval;
				else
					x[k] = osinstance->instanceData->variables->var[k]->lb;
			else
				if (osinstance->instanceData->variables->var[k]->lb == -OSDBL_MAX)
					if (osinstance->instanceData->variables->var[k]->ub >= default_initval)
						x[k] = default_initval;
					else
						x[k] = osinstance->instanceData->variables->var[k]->ub;
				else
					if ((osinstance->instanceData->variables->var[k]->lb <= default_initval) && 
						(osinstance->instanceData->variables->var[k]->ub >= default_initval))
						x[k] = default_initval;
					else
						if (osinstance->instanceData->variables->var[k]->lb > default_initval)
							x[k] = osinstance->instanceData->variables->var[k]->lb;
						else
							x[k] = osinstance->instanceData->variables->var[k]->ub;
	}

/*
 	if( osoption != NULL) {
 		cout << " OSOPTION IS NOT NULL " << endl;
 		double* denseInitVarVector;
 		// not working -- fix
 		denseInitVarVector = osoption->getInitVarValuesDense();
 		
		n = osoption->getNumberOfVariables();
 	
		cout << " OSOPTION IS NOT NULL "  << n << endl;
 		for(i = 0; i < n; i++){
 			if( CommonUtil::ISOSNAN( denseInitVarVector[ i]) == true){ 
 				x[ i] = 1.7171; 
 				//std::cout << "INITIAL VALUE !!!!!!!!!!!!!!!!!!!!  " << x[ i] << std::endl;
 			}
 			else x[ i] = denseInitVarVector[ i];
 			std::cout << "INITIAL VALUE !!!!!!!!!!!!!!!!!!!!  " << x[ i] << std::endl;	
 		}	
// 		delete[] denseInitVarVector;    //HIG: We don't new, so we don't dDelete
 	}
 	else{
 		for(i = 0; i < n; i++){
 			x[ i] = 1.7171;
 		}
 	}
  	//cout << "got initial values !!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
  	
*/
 	for(i = 0; i < n1; i++){
 		std::cout << "INITIAL VALUE !!!!!!!!!!!!!!!!!!!!  " << x[ i] << std::endl;
 	}
 

	delete[] initialed;

  	return true;
}//get_starting_point

// returns the value of the objective function
bool IpoptProblem::eval_f(Index n, const Number* x, bool new_x, Number& obj_value){
	try{
		obj_value  = osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(x), NULL, NULL, new_x, 0 )[ 0];
	}
	catch(const ErrorClass& eclass){
		ipoptErrorMsg = eclass.errormsg;
		throw;  
	}
	if( CommonUtil::ISOSNAN( (double)obj_value) ) return false;
  	return true;
}

bool IpoptProblem::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f){
 	int i;
 	double *objGrad;
	try{
  		//objGrad = osinstance->calculateAllObjectiveFunctionGradients( const_cast<double*>(x), NULL, NULL,  new_x, 1)[ 0];
  		objGrad = osinstance->calculateObjectiveFunctionGradient( const_cast<double*>(x), NULL, NULL, -1,  new_x, 1);
	}
   	catch(const ErrorClass& eclass){
		ipoptErrorMsg = eclass.errormsg;
		throw;  
	}
  	for(i = 0; i < n; i++){
  		grad_f[ i]  = objGrad[ i];
  	}
  	return true;
}//eval_grad_f

// return the value of the constraints: g(x)
bool IpoptProblem::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g) {
	try{
 		double *conVals = osinstance->calculateAllConstraintFunctionValues( const_cast<double*>(x), NULL, NULL, new_x, 0 );
 		int i;
 		for(i = 0; i < m; i++){
 			if( CommonUtil::ISOSNAN( (double)conVals[ i] ) ) return false;
 			g[i] = conVals[ i]  ;	
 		} 
		return true;
	}
	catch(const ErrorClass& eclass){
		ipoptErrorMsg = eclass.errormsg;
		throw;  
	}
}//eval_g


// return the structure or values of the jacobian
bool IpoptProblem::eval_jac_g(Index n, const Number* x, bool new_x,
                           Index m, Index nele_jac, Index* iRow, Index *jCol,
                           Number* values){
  	SparseJacobianMatrix *sparseJacobian;
	if (values == NULL) {
		// return the values of the jacobian of the constraints
		//cout << "n: " << n << endl;
		//cout << "m: " << m << endl;
		//cout << "nele_jac: " <<  nele_jac << endl;
		// return the structure of the jacobian
		try{
			sparseJacobian = osinstance->getJacobianSparsityPattern();
		}
		catch(const ErrorClass& eclass){
			ipoptErrorMsg =  eclass.errormsg; 
			throw; 
		}
		int i = 0;
		int k, idx;
		for(idx = 0; idx < m; idx++){
			for(k = *(sparseJacobian->starts + idx); k < *(sparseJacobian->starts + idx + 1); k++){
				iRow[i] = idx;
				jCol[i] = *(sparseJacobian->indexes + k);
				//cout << "ROW IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << iRow[i] << endl;
				//cout << "COL IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << jCol[i] << endl;
				i++;
			}
		}
	}
	else {
		//std::cout << "EVALUATING JACOBIAN" << std::endl; 
		try{
			sparseJacobian = osinstance->calculateAllConstraintFunctionGradients( const_cast<double*>(x), NULL, NULL,  new_x, 1);
		}
		catch(const ErrorClass& eclass){
			ipoptErrorMsg = eclass.errormsg;
			throw;  
		}
		//osinstance->getIterateResults( (double*)x, 0.0, NULL, -1, new_x,  1);
		for(int i = 0; i < nele_jac; i++){
			values[ i] = sparseJacobian->values[i];
			//values[ i] = osinstance->m_mdJacValue[ i];
			//cout << "values[i]:!!!!!!!!!!!!  " <<  values[ i] << endl;
			//cout << "m_mdJacValue[ i]:!!!!!!!!!!!!  " <<  osinstance->m_mdJacValue[ i] << endl;
		}
	}
  return true;
}//eval_jac_g

//return the structure or values of the hessian
bool IpoptProblem::eval_h(Index n, const Number* x, bool new_x,
                       Number obj_factor, Index m, const Number* lambda,
                       bool new_lambda, Index nele_hess, Index* iRow,
                       Index* jCol, Number* values){

//////
	SparseHessianMatrix *sparseHessian;
	
	int i;
	if (values == NULL) {
		// return the structure. This is a symmetric matrix, fill the lower left triangle only.
		//cout << "get structure of HESSIAN !!!!!!!!!!!!!!!!!!!!!!!!!! "  << endl;
		try{
			sparseHessian = osinstance->getLagrangianHessianSparsityPattern( );
		}
		catch(const ErrorClass& eclass){
			ipoptErrorMsg = eclass.errormsg;
			throw;  
		}
		//cout << "got structure of HESSIAN !!!!!!!!!!!!!!!!!!!!!!!!!! "  << endl;
		for(i = 0; i < nele_hess; i++){
			iRow[i] = *(sparseHessian->hessColIdx + i);
			jCol[i] = *(sparseHessian->hessRowIdx + i);
				//cout << "ROW HESS IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << iRow[i] << endl;
				//cout << "COL HESS IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << jCol[i] << endl;
		}
	}
	else {
		//std::cout << "EVALUATING HESSIAN" << std::endl; 
		// return the values. This is a symmetric matrix, fill the lower left triangle only
		double* objMultipliers = new double[1];
		objMultipliers[0] = obj_factor;
		try{
			sparseHessian = osinstance->calculateLagrangianHessian( const_cast<double*>(x), objMultipliers, (double*)lambda ,  new_x, 2);
		delete[]  objMultipliers;
		}
		catch(const ErrorClass& eclass){
			ipoptErrorMsg = eclass.errormsg;
			delete[]  objMultipliers;
			throw;  
		}
		for(i = 0; i < nele_hess; i++){
			values[ i]  = *(sparseHessian->hessValues + i);
		}
	}
///////
  	return true;
}//eval_h

bool IpoptProblem::get_scaling_parameters(Number& obj_scaling,
                 	bool& use_x_scaling, Index n,
                   	Number* x_scaling,
                    bool& use_g_scaling, Index m,
                    Number* g_scaling){
	if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") != 0){
  		obj_scaling = -1;
  	}
    else obj_scaling = 1;
    use_x_scaling = false;
    use_g_scaling = false;
	return true;
}//get_scaling_parameters

void IpoptProblem::finalize_solution(SolverReturn status,
                               Index n, const Number* x, const Number* z_L, const Number* z_U,
                                  Index m, const Number* g, const Number* lambda,
                                  Number obj_value,
                                   const IpoptData* ip_data,
                                   IpoptCalculatedQuantities* ip_cq)
{
	  // here is where we would store the solution to variables, or write to a file, etc
	  // so we could use the solution.
	  // For this example, we write the solution to the console
	OSrLWriter *osrlwriter ;
	osrlwriter = new OSrLWriter();
#ifdef DEBUG
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
#endif
	  printf("\nObjective value f(x*) = %e\n", obj_value);
	  
  	int solIdx = 0;
  	int numberOfOtherVariableResults;
  	int otherIdx;
	ostringstream outStr;
	
	std::string *rcost = NULL;
	double* mdObjValues = new double[1];
	std::string message = "Ipopt solver finishes to the end.";
	std::string solutionDescription = "";	

	try{
		// resultHeader infomration
		if(osresult->setServiceName( "Ipopt solver service") != true)
			throw ErrorClass("OSResult error: setServiceName");
		if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
			throw ErrorClass("OSResult error: setInstanceName");

		//if(osresult->setJobID( osoption->jobID) != true)
		//	throw ErrorClass("OSResult error: setJobID");

		// set basic problem parameters
		if(osresult->setVariableNumber( osinstance->getVariableNumber()) != true)
			throw ErrorClass("OSResult error: setVariableNumer");
		if(osresult->setObjectiveNumber( 1) != true)
			throw ErrorClass("OSResult error: setObjectiveNumber");
		if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
			throw ErrorClass("OSResult error: setConstraintNumber");
		if(osresult->setSolutionNumber(  1) != true)
			throw ErrorClass("OSResult error: setSolutionNumer");	


		if(osresult->setGeneralMessage( message) != true)
			throw ErrorClass("OSResult error: setGeneralMessage");

		switch( status){
			case SUCCESS:
				solutionDescription = "SUCCESS[IPOPT]: Algorithm terminated successfully at a locally optimal point, satisfying the convergence tolerances.";
				osresult->setSolutionStatus(solIdx,  "locallyOptimal", solutionDescription);
				osresult->setPrimalVariableValues(solIdx, const_cast<double*>(x));
				osresult->setDualVariableValues(solIdx, const_cast<double*>( lambda));
				mdObjValues[0] = obj_value;
				osresult->setObjectiveValues(solIdx, mdObjValues);
				
				
				// set other
				
				numberOfOtherVariableResults = 2;
				osresult->setNumberOfOtherVariableResults(solIdx, numberOfOtherVariableResults);
				
			
				rcost = new std::string[ osinstance->getVariableNumber()];
				

				for (Index i = 0; i < n; i++) {
				    rcost[ i] =  os_dtoa_format( z_L[i]); 
				 }
				otherIdx = 0;
				osresult->setAnOtherVariableResult(solIdx, otherIdx, "varL", "Lagrange Multiplier on the Variable Lower Bound", rcost);
				
				
				for (Index i = 0; i < n; i++) {
				    rcost[ i] =  os_dtoa_format( z_U[i]); 
				 }
				otherIdx = 1;
				osresult->setAnOtherVariableResult(solIdx, otherIdx, "varU", "Lagrange Multiplier on the Variable Upper Bound", rcost);
				
				delete[] rcost;
				
				// done with other
				
				
			break;
			case MAXITER_EXCEEDED:
				solutionDescription = "MAXITER_EXCEEDED[IPOPT]: Maximum number of iterations exceeded.";
				osresult->setSolutionStatus(solIdx,  "stoppedByLimit", solutionDescription);
				osresult->setPrimalVariableValues(solIdx, const_cast<double*>(x));
				osresult->setDualVariableValues(solIdx, const_cast<double*>( lambda));
				mdObjValues[0] = obj_value;
				osresult->setObjectiveValues(solIdx, mdObjValues);
			break;
			case STOP_AT_TINY_STEP:
				solutionDescription = "STOP_AT_TINY_STEP[IPOPT]: Algorithm proceeds with very little progress.";
				osresult->setSolutionStatus(solIdx,  "stoppedByLimit", solutionDescription);
				osresult->setPrimalVariableValues(solIdx, const_cast<double*>( x));
				osresult->setDualVariableValues(solIdx, const_cast<double*>( lambda));
				mdObjValues[0] = obj_value;
				osresult->setObjectiveValues(solIdx, mdObjValues);
			break;
			case STOP_AT_ACCEPTABLE_POINT:
				solutionDescription = "STOP_AT_ACCEPTABLE_POINT[IPOPT]: Algorithm stopped at a point that was converged, not to _desired_ tolerances, but to _acceptable_ tolerances";
				osresult->setSolutionStatus(solIdx,  "IpoptAccetable", solutionDescription);
				osresult->setPrimalVariableValues(solIdx, const_cast<double*>(x));
				osresult->setDualVariableValues(solIdx, const_cast<double*>( lambda));
				mdObjValues[0] = obj_value;
				osresult->setObjectiveValues(solIdx, mdObjValues);
			break;
			case LOCAL_INFEASIBILITY:
				solutionDescription = "LOCAL_INFEASIBILITY[IPOPT]: Algorithm converged to a point of local infeasibility. Problem may be infeasible.";
				osresult->setSolutionStatus(solIdx,  "infeasible", solutionDescription);
			break;
			case USER_REQUESTED_STOP:
				solutionDescription = "USER_REQUESTED_STOP[IPOPT]: The user call-back function  intermediate_callback returned false, i.e., the user code requested a premature termination of the optimization.";
				osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
			break;
			case DIVERGING_ITERATES:
				solutionDescription = "DIVERGING_ITERATES[IPOPT]: It seems that the iterates diverge.";
				osresult->setSolutionStatus(solIdx,  "unbounded", solutionDescription);
			break;
			case RESTORATION_FAILURE:
				solutionDescription = "RESTORATION_FAILURE[IPOPT]: Restoration phase failed, algorithm doesn't know how to proceed.";
				osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
			break;
			case ERROR_IN_STEP_COMPUTATION:
				solutionDescription = "ERROR_IN_STEP_COMPUTATION[IPOPT]: An unrecoverable error occurred while IPOPT tried to compute the search direction.";
				osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
			break;
			case INVALID_NUMBER_DETECTED:
				solutionDescription = "INVALID_NUMcatBER_DETECTED[IPOPT]: Algorithm received an invalid number (such as NaN or Inf) from the NLP; see also option check_derivatives_for_naninf.";
				osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
			break;
			case INTERNAL_ERROR:
				solutionDescription = "INTERNAL_ERROR[IPOPT]: An unknown internal error occurred. Please contact the IPOPT authors through the mailing list.";
				osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
			break;
			default:
				solutionDescription = "OTHER[IPOPT]: other unknown solution status from Ipopt solver";
				osresult->setSolutionStatus(solIdx,  "other", solutionDescription);
		}
		osresult->setGeneralStatusType("success");
		delete osrlwriter;
		delete[] mdObjValues;
		osrlwriter = NULL;

	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		std::string osrl = osrlwriter->writeOSrL( osresult);
		delete osrlwriter;
		osrlwriter = NULL;
		throw ErrorClass(  osrl) ;
		delete[] mdObjValues;
		mdObjValues = NULL;
	}
//////////
}


void IpoptSolver::setSolverOptions() throw (ErrorClass) {
	try{
		/* set the default options */		
		this->bSetSolverOptions = true;
		app->Options()->SetNumericValue("tol", 1e-9);
		app->Options()->SetIntegerValue("print_level", 0);
		app->Options()->SetIntegerValue("max_iter", 20000);
		app->Options()->SetStringValue("mu_strategy", "adaptive");
		app->Options()->SetStringValue("output_file", "ipopt.out");
		app->Options()->SetStringValue("check_derivatives_for_naninf", "yes");
		/* end of the default options */
		
		if(osoption == NULL && osol.length() > 0)
		{
			m_osolreader = new OSoLReader();
			osoption = m_osolreader->readOSoL( osol);
		}

		if( osoption != NULL  &&  osoption->getNumberOfSolverOptions() > 0 ){
			std::cout << "number of solver options "  <<  osoption->getNumberOfSolverOptions() << std::endl;
			std::vector<SolverOption*> optionsVector;
			optionsVector = osoption->getSolverOptions( "ipopt");
			char *pEnd;
			int i;
			int num_ipopt_options = optionsVector.size();
			for(i = 0; i < num_ipopt_options; i++){
				std::cout << "ipopt solver option  "  << optionsVector[ i]->name << std::endl;
				if(optionsVector[ i]->type == "numeric" ){
					std::cout << "FOUND A NUMERIC OPTION  "  <<  os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) << std::endl;
					app->Options()->SetNumericValue(optionsVector[ i]->name, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );	
				}
				else if(optionsVector[ i]->type == "integer" ){
					std::cout << "FOUND AN INTEGER OPTION  "  << atoi( optionsVector[ i]->value.c_str() ) << std::endl;
					app->Options()->SetIntegerValue(optionsVector[ i]->name, atoi( optionsVector[ i]->value.c_str() ) );
				}
				else if(optionsVector[ i]->type == "string" ){
					std::cout << "FOUND A STRING OPTION  "  <<  optionsVector[ i]->value.c_str() << std::endl;
					app->Options()->SetStringValue(optionsVector[ i]->name, optionsVector[ i]->value);
				}
			}	
		}
	}
	catch(const ErrorClass& eclass){
		std::cout << "THERE IS AN ERROR" << std::endl;
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
	}				
}//end setSolverOptions() 



void IpoptSolver::buildSolverInstance() throw (ErrorClass) {
	try{
		
		if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
		if(osinstance == NULL){
			m_osilreader = new OSiLReader();
			osinstance = m_osilreader->readOSiL( osil);
		}
		// Create a new instance of your nlp 
		nlp = new IpoptProblem( osinstance, osoption, osresult);
		app = new IpoptApplication();
		this->bCallbuildSolverInstance = true;
	}
	catch(const ErrorClass& eclass){
		std::cout << "THERE IS AN ERROR" << std::endl;
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
	}				
}//end buildSolverInstance() 



void IpoptSolver::solve() throw (ErrorClass) {
	if( this->bCallbuildSolverInstance == false) buildSolverInstance();
	if( this->bSetSolverOptions == false) setSolverOptions();
	try{
		clock_t start, finish;
		double duration;
		start = clock();
		//OSiLWriter osilwriter;
		//cout << osilwriter.writeOSiL( osinstance) << endl;
		if(osinstance->getVariableNumber() <= 0)throw ErrorClass("Ipopt requires decision variables");
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Parsing took (seconds): " << duration << endl; 
		//dataEchoCheck();
		/***************now the ipopt invokation*********************/
		// see if we have a linear program
		if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Ipopt NEEDS AN OBJECTIVE FUNCTION");
		if( (osinstance->getNumberOfNonlinearExpressions() == 0) && (osinstance->getNumberOfQuadraticTerms() == 0) ) 
			app->Options()->SetStringValue("hessian_approximation", "limited-memory");
		// if it is a max problem call scaling and set to -1
		if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") != 0){
  			app->Options()->SetStringValue("nlp_scaling_method", "user-scaling");
  		}
		// Intialize the IpoptApplication and process the options
		std::cout << "Call Ipopt Initialize" << std::endl;
		app->Initialize();
		std::cout << "Finished Ipopt Initialize" << std::endl;
		//nlp->osinstance = this->osinstance;
		// Ask Ipopt to solve the problem
		std::cout << "Call Ipopt Optimize" << std::endl;
		ApplicationReturnStatus status = app->OptimizeTNLP( nlp);
		std::cout << "Finish Ipopt Optimize" << std::endl;
		osrl = osrlwriter->writeOSrL( osresult);
		std::cout << "Finish writing the osrl" << std::endl;
		//if (status != Solve_Succeeded) {
		if (status < -2) {
			throw ErrorClass("Ipopt FAILED TO SOLVE THE PROBLEM: " + ipoptErrorMsg);
		}	
	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
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


IpoptProblem::IpoptProblem(OSInstance *osinstance_,  OSOption *osoption_, OSResult *osresult_) {
	osinstance = osinstance_;
	osoption = osoption_;
	osresult = osresult_;
}

IpoptProblem::~IpoptProblem() {

}



