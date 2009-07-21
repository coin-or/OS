/* $Id$ */
/** @file BonminSolver.cpp
 * 
 * \brief This file defines the BonminSolver class.
 * \detail Read an OSInstance object and convert in Ipopt data structures
 *
 * @author  Jun Ma, Horand Gassmann, Kipp Martin, 
 * @version 1.1, 11/04/2008
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2008, Jun Ma, Horand Gassmann, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

//#define DEBUG

#include <iostream>


#include "OSBonminSolver.h"
#include "OSDataStructures.h"
#include "OSParameters.h" 
#include "OSMathUtil.h"
#include "CoinFinite.hpp"
#include "BonOsiTMINLPInterface.hpp"
#include "BonTMINLP.hpp"


#include "CoinTime.hpp"

using std::cout; 
using std::endl; 
using std::ostringstream;

BonminSolver::BonminSolver() {
	osrlwriter = new OSrLWriter();
	osresult = new OSResult();	
	m_osilreader = NULL;
	m_osolreader = NULL;
	bonminErrorMsg = "";

} 

BonminSolver::~BonminSolver() {
	#ifdef DEBUG
	cout << "inside BonminSolver destructor" << endl;
	#endif
	if(m_osilreader != NULL) delete m_osilreader;
	m_osilreader = NULL;
	if(m_osolreader != NULL) delete m_osolreader;
	m_osolreader = NULL;

	if(osrlwriter != NULL )delete osrlwriter;
	osrlwriter = NULL;
		if(osresult != NULL ){
			delete osresult;
			osresult = NULL;
			//cout << "DELETING OS RESULT" << endl;
		}
	#ifdef DEBUG
	cout << "leaving BonminSolver destructor" << endl;
	#endif
}






bool BonminProblem::get_variables_types(Index n, VariableType* var_types){
	int i = 0;
	char *varType;
	varType = osinstance->getVariableTypes();
	n = osinstance->getVariableNumber();
	for(i = 0; i < n;   i++){
		if( varType[i] == 'B') {
			var_types[i] = BINARY;
		}
		else{
			if( varType[i] == 'I') {
				var_types[i] = INTEGER;
			}
			else{
				var_types[i] = CONTINUOUS;
			}	
		}
	}
	return true;
}

bool BonminProblem::get_variables_linearity(Index n, Ipopt::TNLP::LinearityType* var_types){
	
	
	
	std::cout << "Initialize Nonlinear Structures" << std::endl;
	try{
		osinstance->initForAlgDiff( );
	}
	catch(const ErrorClass& eclass){
		bonminErrorMsg = eclass.errormsg;
		throw;  
	}	
	/**
	 * get an index map of the nonlinear variables
	 * and see which variable are in <nonlinearExpressions>
	 * element
	 */	
	std::map<int, int> varIndexMap;
	std::map<int, int>::iterator posVarIndexMap;
	varIndexMap = osinstance->getAllNonlinearVariablesIndexMap( );
	/* first make all continuous */
	
	int i;
	
	for(i = 0; i < n; i++){
		var_types[ i] = Ipopt::TNLP::LINEAR;	
	}
	/**
	 * iterate through and get an index of all variables that
	 * are in <nonlinearExpressions> element
	 */		
	for(posVarIndexMap = varIndexMap.begin(); posVarIndexMap != varIndexMap.end(); ++posVarIndexMap){
			std::cout <<  "Variable Index = "   << posVarIndexMap->first  << std::endl ;
			var_types[ posVarIndexMap->first] = Ipopt::TNLP::NON_LINEAR;
	}
	std::cout << "Number of nonlinear variables =  " << varIndexMap.size() << std::endl;	

	return true;
}

bool BonminProblem::get_constraints_linearity(Index m, Ipopt::TNLP::LinearityType* const_types){
	
	int i;
	
	for(i  = 0; i < m; i++){
		const_types[ i] = Ipopt::TNLP::LINEAR;
	}
	
	
	int mm = osinstance->getNumberOfNonlinearExpressionTreeModIndexes();
	

	
	for(i = 0; i < mm; i++){
		if(osinstance->getNonlinearExpressionTreeModIndexes()[ i] >= 0){
			std::cout << osinstance->getNonlinearExpressionTreeModIndexes()[ i] << std::endl;
			const_types[ osinstance->getNonlinearExpressionTreeModIndexes()[ i] ] = Ipopt::TNLP::NON_LINEAR;
			
		}
		
	}
		
	return true;
}

// returns the size of the problem
bool BonminProblem::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                             Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style)
{
	if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Bonmin NEEDS AN OBJECTIVE FUNCTION");                 	
	// number of variables
	n = osinstance->getVariableNumber();
	// number of constraints
	m = osinstance->getConstraintNumber();
	#ifdef DEBUG
	cout << "Bonmin number variables  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << n << endl;
	cout << "Bonmin number constraints  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << m << endl;
	#endif
	try{
		osinstance->initForAlgDiff( ); 
	}
	catch(const ErrorClass& eclass){
		bonminErrorMsg = eclass.errormsg;
		throw;  
	}	
	// use the OS Expression tree for function evaluations instead of CppAD
	osinstance->bUseExpTreeForFunEval = true;
	//std::cout << "Call sparse jacobian" << std::endl;
	SparseJacobianMatrix *sparseJacobian = NULL;
	try{
		sparseJacobian = osinstance->getJacobianSparsityPattern();
		//cout << "Get sparse Jacobian pattern" << std::endl;
	}
	catch(const ErrorClass& eclass){
		bonminErrorMsg = eclass.errormsg;
		throw;  
	}
	//std::cout << "Done calling sparse jacobian" << std::endl;
	nnz_jac_g = sparseJacobian->valueSize;
	#ifdef DEBUG
	cout << "nnz_jac_g  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << nnz_jac_g << endl;	
	#endif
	// nonzeros in upper hessian
	
	if( (osinstance->getNumberOfNonlinearExpressions() == 0) && (osinstance->getNumberOfQuadraticTerms() == 0) ) {
		cout << "This is a linear program"  << endl;
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
  
  return true;
}//get_nlp_info


bool  BonminProblem::get_bounds_info(Index n, Number* x_l, Number* x_u,
                                Index m, Number* g_l, Number* g_u){
 	int i; 

	double * mdVarLB = osinstance->getVariableLowerBounds();
	//std::cout << "GET BOUNDS INFORMATION FOR BONMIN !!!!!!!!!!!!!!!!!" << std::endl;
	// variables upper bounds
	double * mdVarUB = osinstance->getVariableUpperBounds();

	for(i = 0; i < n; i++){
		x_l[ i] = mdVarLB[ i];
		x_u[ i] = mdVarUB[ i];
		#ifdef DEBUG
		cout << "x_l !!!!!!!!!!!!!!!!!!!!!!!!!!!" << x_l[i] << endl;
		cout << "x_u !!!!!!!!!!!!!!!!!!!!!!!!!!!" << x_u[i] << endl;
		#endif
	}
	// Bonmin interprets any number greater than nlp_upper_bound_inf as
	// infinity. The default value of nlp_upper_bound_inf and nlp_lower_bound_inf
	// is 1e19 and can be changed through bonmin options.
	// e.g. g_u[0] = 2e19;

	//constraint lower bounds
	double * mdConLB = osinstance->getConstraintLowerBounds();
	//constraint upper bounds
	double * mdConUB = osinstance->getConstraintUpperBounds();
	
	for(int i = 0; i < m; i++){
		g_l[ i] = mdConLB[ i];
		g_u[ i] = mdConUB[ i];
		#ifdef DEBUG
		cout << "lower !!!!!!!!!!!!!!!!!!!!!!!!!!!" << g_l[i] << endl;
		cout << "upper !!!!!!!!!!!!!!!!!!!!!!!!!!!" << g_u[i] << endl;
		#endif
	}  
  	return true;
}//get_bounds_info


// returns the initial point for the problem
bool BonminProblem::get_starting_point(Index n, bool init_x, Number* x,
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
#endif
	int k;
	if (osoption != NULL)
		m1 = osoption->getNumberOfInitVarValues();
	else
		m1 = 0;
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
		try 
		{
			for(k = 0; k < m1; k++)
			{	
				i = initVarVector[k]->idx;
				if (initVarVector[k]->idx > n1)
					throw ErrorClass ("Illegal index value in variable initialization");

				initval = initVarVector[k]->value;
				if (osinstance->instanceData->variables->var[i]->ub == OSDBL_MAX)
				{	if (osinstance->instanceData->variables->var[i]->lb > initval)
						throw ErrorClass ("Initial value outside of bounds");
				}
				else
					if (osinstance->instanceData->variables->var[i]->lb == -OSDBL_MAX)
					{	if (osinstance->instanceData->variables->var[i]->ub < initval)
							throw ErrorClass ("Initial value outside of bounds");
					}
					else
					{	if ((osinstance->instanceData->variables->var[i]->lb > initval) ||
							(osinstance->instanceData->variables->var[i]->ub < initval))
							throw ErrorClass ("Initial value outside of bounds");
					}

				x[initVarVector[k]->idx] = initval;
				initialed[initVarVector[k]->idx] = true;
			}
		}
		catch(const ErrorClass& eclass){
			cout << "Error in BonminProblem::get_starting_point (OSBonminSolver.cpp)";
			cout << endl << endl << endl;
		}	
	}  //  end if (m1 > 0)		

	double default_initval;
	default_initval = 1.7171;
	

	for(k = 0; k < n1; k++)
	{
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
 	for(i = 0; i < n1; i++){
		#ifdef DEBUG
 		std::cout << "INITIAL VALUE !!!!!!!!!!!!!!!!!!!!  " << x[ i] << std::endl;
		#endif
 	}
 
	osinstance->calculateAllObjectiveFunctionValues( x, true);
	delete[] initialed;
  	return true;
}//get_starting_point


// returns the value of the objective function
bool BonminProblem::eval_f(Index n, const Number* x, bool new_x, Number& obj_value){
	
	try{
		if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") == 0){
			obj_value  = osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(x), NULL, NULL, new_x, 0 )[ 0];	
  		}else{// we have a max
			obj_value  = -osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(x), NULL, NULL, new_x, 0 )[ 0];
		}
		
	}
	catch(const ErrorClass& eclass){
		bonminErrorMsg = eclass.errormsg;
		throw;  
	}
	if( CoinIsnan( (double)obj_value) ) return false;
  	return true;
}

bool BonminProblem::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f){
 	int i;
 	double *objGrad;
	try{
  		//objGrad = osinstance->calculateAllObjectiveFunctionGradients( const_cast<double*>(x), NULL, NULL,  new_x, 1)[ 0];
		//std::cout << "Calculate Objective function gradient " << std::endl;
		// we assume we are doing the objective function indexed by -1
  		objGrad = osinstance->calculateObjectiveFunctionGradient( const_cast<double*>(x), NULL, NULL, -1,  new_x, 1);
	}
   	catch(const ErrorClass& eclass){
		bonminErrorMsg = eclass.errormsg;
		throw;  
	}
  	for(i = 0; i < n; i++){
		if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") == 0){
			grad_f[ i]  = objGrad[ i];
		}else{
			grad_f[ i]  = -objGrad[ i];
		}
  		//std::cout << grad_f[ i]  << std::endl;
  	}
//std::cout << "DONE WITH Calculate Objective function gradient " << std::endl;
  	return true;
}//eval_grad_f

// return the value of the constraints: g(x)
bool BonminProblem::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g) {
	try{
 		double *conVals = osinstance->calculateAllConstraintFunctionValues( const_cast<double*>(x), NULL, NULL, new_x, 0 );
 		int i;
 		for(i = 0; i < m; i++){
 			if( CoinIsnan( (double)conVals[ i] ) ) return false;
 			g[i] = conVals[ i]  ;	
 		} 
		return true;
	}
	catch(const ErrorClass& eclass){
		bonminErrorMsg = eclass.errormsg;
		throw;  
	}
}//eval_g


// return the structure or values of the jacobian
bool BonminProblem::eval_jac_g(Index n, const Number* x, bool new_x,
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
			bonminErrorMsg =  eclass.errormsg; 
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
			bonminErrorMsg = eclass.errormsg;
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
bool BonminProblem::eval_h(Index n, const Number* x, bool new_x,
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
			bonminErrorMsg = eclass.errormsg;
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
			sparseHessian = osinstance->calculateLagrangianHessian( const_cast<double*>(x), objMultipliers, const_cast<double*>(lambda) ,  new_x, 2);
		delete[]  objMultipliers;
		}
		catch(const ErrorClass& eclass){
			bonminErrorMsg = eclass.errormsg;
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

bool BonminProblem::get_scaling_parameters(Number& obj_scaling,
                 	bool& use_x_scaling, Index n,
                   	Number* x_scaling,
                    bool& use_g_scaling, Index m,
                    Number* g_scaling){
	/*
	 * Bonmin assumes problems cast as a min
	 * if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") != 0){
  		obj_scaling = -1;
  	}
    else obj_scaling = 1;
    use_x_scaling = false;
    use_g_scaling = false;
    */
	return true;
}//get_scaling_parameters




void BonminProblem::finalize_solution(TMINLP::SolverReturn status_,
                            Index n, const Number* x, Number obj_value)
{
	
	status = status_;
	#ifdef DEBUG
	std::cout << "FINALIZE OBJ SOLUTION VALUE = " << obj_value << std::endl;
	#endif

}


   

void BonminSolver::buildSolverInstance() throw (ErrorClass) {
	try{	
		
		if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
		if(osinstance == NULL){
			m_osilreader = new OSiLReader();
			osinstance = m_osilreader->readOSiL( osil);
		}
		// Create a new instance of your nlp 
		tminlp = new BonminProblem( osinstance, osoption);
		this->bCallbuildSolverInstance = true;
		//Now initialize from tminlp
		//bonminSetup.initialize( GetRawPtr(tminlp) );
	}
	catch(const ErrorClass& eclass){
		std::cout << "THERE IS AN ERROR" << std::endl;
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
	}				
}//end buildSolverInstance() 



void BonminSolver::setSolverOptions() throw (ErrorClass) {
	try{
		this->bSetSolverOptions = true;
		bonminSetup.initializeOptionsAndJournalist();
		//Register an additional option -- just an example
		bonminSetup.roptions()->AddStringOption2("print_solution","Do we print the solution or not?",
		                                 "yes",
		                                 "no", "No, we don't.",
		                                 "yes", "Yes, we do.",
		                                 "A longer comment can be put here");
		  
		 // Here we can change the default value of some Bonmin or Ipopt option
		bonminSetup.options()->SetNumericValue("bonmin.time_limit", 5000); //changes bonmin's time limit
		//bonminSetup.options()->SetIntegerValue("bonmin.num_resolve_at_node", 3); 
		//bonminSetup.options()->SetIntegerValue("bonmin.num_resolve_at_root", 3); 
		//bonminSetup.options()->SetIntegerValue("bonmin.num_retry_unsolved_random_point", 30); 
		//bonminSetup.options()->SetIntegerValue("print_level", 12); 
		//bonminSetup.options()->SetIntegerValue("bonmin.bb_log_level", 4); 
		//bonminSetup.options()->SetStringValue("bonmin.nlp_failure_behavior", "fathom");
		//bonminSetup.options()->SetNumericValue("bonmin.allowable_gap", -1);
		//bonminSetup.options()->SetNumericValue("bonmin.allowable_fraction_gap", -.1);
		//bonminSetup.options()->SetNumericValue("bonmin.cutoff_decr", -1);
		//bonminSetup.options()->SetStringValue("mu_oracle","loqo");
	
	
		//Here we read several option files
		//bonminSetup.readOptionsFile("Mybonmin.opt");
		//bonminSetup.readOptionsFile();// This reads the default file "bonmin.opt"
		  
		// Options can also be set by using a string with a format similar to the bonmin.opt file
		bonminSetup.readOptionsString("bonmin.algorithm B-BB\n");
		
				//turn off a lot of output -- this can be overridden by using OSOptions
		bonminSetup.options()->SetIntegerValue("bonmin.bb_log_level", 0 );
		bonminSetup.options()->SetIntegerValue("bonmin.nlp_log_level", 0 );
		  
		// Now we can obtain the value of the new option
		int printSolution;
		bonminSetup.options()->GetEnumValue("print_solution", printSolution,"");
		if(printSolution == 1){
			tminlp->printSolutionAtEndOfAlgorithm();
		}	
		//
		if(osoption == NULL && osol.length() > 0)
		{
			m_osolreader = new OSoLReader();
			osoption = m_osolreader->readOSoL( osol);
		}

		if(osoption != NULL && osoption->getNumberOfSolverOptions() > 0 ){
			char *pEnd;
			int i;
			std::vector<SolverOption*> optionsVector;
			optionsVector = osoption->getSolverOptions( "bonmin");
			int num_bonmin_options = optionsVector.size();
			for(i = 0; i < num_bonmin_options; i++){
				if(optionsVector[ i]->type == "numeric" ){
					std::cout << "FOUND A  NUMERIC OPTION  "  <<  os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) << std::endl;
					if(optionsVector[ i]->category == "ipopt"){
						bonminSetup.options()->SetNumericValue(optionsVector[ i]->name, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );	
					}else{
						if(optionsVector[ i]->category == "cbc" ){
							bonminSetup.options()->SetNumericValue("milp_solver."+optionsVector[ i]->name, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );
						}
						else{
							bonminSetup.options()->SetNumericValue("bonmin."+optionsVector[ i]->name, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );	
						}
					}
				}  
				else if(optionsVector[ i]->type == "integer" ){
					std::cout << "FOUND AN INTEGER OPTION  "  <<optionsVector[ i]->name << std::endl;
					if(optionsVector[ i]->category == "ipopt"){
						bonminSetup.options()->SetIntegerValue(optionsVector[ i]->name, atoi( optionsVector[ i]->value.c_str() ) );	
					}else{
						if(optionsVector[ i]->category == "cbc" ){
							std::cout << "SETTING INTEGER CBC OPTION" << std::endl;
							bonminSetup.options()->SetIntegerValue("milp_solver."+optionsVector[ i]->name, atoi( optionsVector[ i]->value.c_str() ));
						}
						else{
							bonminSetup.options()->SetIntegerValue("bonmin."+optionsVector[ i]->name, atoi( optionsVector[ i]->value.c_str() )  );	
						}
					}					
				}
				else if(optionsVector[ i]->type == "string" ){
					std::cout << "FOUND A STRING OPTION  "  <<optionsVector[ i]->name << std::endl;
					if(optionsVector[ i]->category == "ipopt"){
						bonminSetup.options()->SetStringValue(optionsVector[ i]->name, optionsVector[ i]->value );	
					}else{
						if(optionsVector[ i]->category == "cbc" ){
							bonminSetup.options()->SetStringValue("milp_solver."+optionsVector[ i]->name, optionsVector[ i]->value);
						}
						else{
							bonminSetup.options()->SetStringValue("bonmin."+optionsVector[ i]->name, optionsVector[ i]->value);	
						}
					}	

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


//void BonminSolver::solve() throw (ErrorClass) {
void BonminSolver::solve() throw (ErrorClass) {
		if( this->bCallbuildSolverInstance == false) buildSolverInstance();
		if( this->bSetSolverOptions == false) setSolverOptions();
	try{

		if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Bonmin NEEDS AN OBJECTIVE FUNCTION");
		//double start = CoinCpuTime();
		//OSiLWriter osilwriter;
		//cout << osilwriter.writeOSiL( osinstance) << endl;
		if(osinstance->getVariableNumber() <= 0)throw ErrorClass("Bonmin requires decision variables");
		//double duration = CoinCpuTime() - start;

		  try {
			  bonminSetup.initialize( GetRawPtr(tminlp) );
		    // bb is a Bonmin BonCbc object;;
		    bb(  bonminSetup);  //process parameter file using Ipopt and do branch and bound using Cbc

		  }
		  catch(TNLPSolver::UnsolvedError *E) {
		    //There has been a failure to solve a problem with Ipopt.
		    std::cerr<<"Ipopt has failed to solve a problem"<<std::endl;
		  }
		  catch(OsiTMINLPInterface::SimpleError &E) {
		    std::cerr<<E.className()<<"::"<<E.methodName()
			     <<std::endl
			     <<E.message()<<std::endl;
		  }
		  catch(CoinError &E) {
		    std::cerr<<E.className()<<"::"<<E.methodName()
			     <<std::endl
			     <<E.message()<<std::endl;
		  }
		  
	if(( bb.model().isContinuousUnbounded() == true) && (osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() <= 0) ){
		std::string solutionDescription = "";
		std::string message = "Success";
		int solIdx = 0;
		if(osresult->setServiceName( "Bonin solver service") != true)
			throw ErrorClass("OSResult error: setServiceName");
		if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
			throw ErrorClass("OSResult error: setInstanceName");
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
		solutionDescription = "The problem is unbounded";
			osresult->setSolutionStatus(solIdx,  "error", solutionDescription);	
		osresult->setGeneralStatusType("normal");
		osrl = osrlwriter->writeOSrL( osresult);		
		return;
	}
	
	
	if(( bb.model().isProvenInfeasible() == true)  ){
		std::string solutionDescription = "";
		std::string message = "Success";
		int solIdx = 0;
		if(osresult->setServiceName( "Bonin solver service") != true)
			throw ErrorClass("OSResult error: setServiceName");
		if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
			throw ErrorClass("OSResult error: setInstanceName");
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
		solutionDescription = "The problem is infeasible";
			osresult->setSolutionStatus(solIdx,  "error", solutionDescription);	
		osresult->setGeneralStatusType("normal");
		osrl = osrlwriter->writeOSrL( osresult);		
		return;
	}
	    status = tminlp->status;
	    writeResult();

	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
	}
}//solve




void BonminSolver::writeResult(){
	double *x = NULL;
	double *z = NULL;
	int i = 0;
	int solIdx = 0;
	std::string solutionDescription = "";
	std::string message = "Bonmin solver finishes to the end.";
	
	
	try{
		x = new double[osinstance->getVariableNumber() ];
		z = new double[1];		
		// resultHeader information
		if(osresult->setServiceName( "Bonmin solver service") != true)
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
			case  TMINLP::SUCCESS:
				solutionDescription = "SUCCESS[BONMIN]: Algorithm terminated normally at a locally optimal point, satisfying the convergence tolerances.";
				//std::cout << solutionDescription << std::endl;
				osresult->setSolutionStatus(solIdx,  "locallyOptimal", solutionDescription);		
				/* Retrieve the solution */
				*(z + 0)  =  osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(bb.bestSolution()), true)[ 0];
				osresult->setObjectiveValuesDense(solIdx, z); 
				for(i=0; i < osinstance->getVariableNumber(); i++){
					*(x + i) = bb.bestSolution()[i];
					//std::cout <<  *(x + i)  << std::endl;
				}
				osresult->setPrimalVariableValuesDense(solIdx, x);
			break;
			
			case TMINLP::LIMIT_EXCEEDED:
				solutionDescription = "LIMIT_EXCEEDED[BONMIN]: A resource limit was exceeded, we provide the current solution.";
				//std::cout << solutionDescription << std::endl;
				osresult->setSolutionStatus(solIdx,  "stoppedByLimit", solutionDescription);
				//osresult->setPrimalVariableValuesDense(solIdx, const_cast<double*>(x));
				//osresult->setDualVariableValuesDense(solIdx, const_cast<double*>( lambda));	
				/* Retrieve the solution */
				*(z + 0)  =  osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(bb.model().getColSolution()), true)[ 0];
				osresult->setObjectiveValuesDense(solIdx, z); 
				for(i=0; i < osinstance->getVariableNumber(); i++){
					*(x + i) = bb.model().getColSolution()[i];
					//std::cout <<  *(x + i)  << std::endl;
				}
				osresult->setPrimalVariableValuesDense(solIdx, x); 
			break;
			
			case TMINLP::MINLP_ERROR:
				solutionDescription = "MINLP_ERROR [BONMIN]: Algorithm stopped with unspecified error.";
				//std::cout << solutionDescription << std::endl;
				osresult->setSolutionStatus(solIdx,  "error", solutionDescription);	

			break;
			
			case TMINLP::CONTINUOUS_UNBOUNDED:
				solutionDescription = "CONTINUOUS_UNBOUNDED [BONMIN]: The continuous relaxation is unbounded, the MINLP may or may not be unbounded.";
				//std::cout << solutionDescription << std::endl;
				osresult->setSolutionStatus(solIdx,  "error", solutionDescription);	

			break;
			
		
			case TMINLP::INFEASIBLE:
				solutionDescription = "INFEASIBLE [BONMIN]: Problem may be infeasible.";
				//std::cout << solutionDescription << std::endl;
				osresult->setSolutionStatus(solIdx,  "infeasible", solutionDescription);
			break;
			
			
			default:
				solutionDescription = "OTHER[BONMIN]: other unknown solution status from Bonmin solver";
				//std::cout << solutionDescription << std::endl;
				osresult->setSolutionStatus(solIdx,  "other", solutionDescription);
		}//switch end	
		osresult->setGeneralStatusType("normal");
		osrl = osrlwriter->writeOSrL( osresult);
		delete[] x;
		x = NULL;
		delete[] z;	
		z = NULL;
	}//end try
	
	
	catch(const ErrorClass& eclass){
		delete[] x;
		x = NULL;
		delete[] z;	
		z = NULL;
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
	}	
	
	
}// end writeResult()


void BonminSolver::dataEchoCheck(){
	
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


BonminProblem::BonminProblem(OSInstance *osinstance_,  OSOption *osoption_) {
	osinstance = osinstance_;
	osoption = osoption_;
	printSol_ = false;
}

BonminProblem::~BonminProblem() {

}



