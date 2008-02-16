/** @file KnitroSolver.cpp
 * 
 * \brief This file defines the KnitroSolver class.
 * \detail Read an OSInstance object and convert in Knitro data structures
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


#include "OSKnitroSolver.h"
#include "OSCommonUtil.h"

using std::cout; 
using std::endl; 
using std::ostringstream;
using namespace std;

#if defined(_WIN32)
  #include  <windows.h>     //-- FOR LoadLibrary
#else
  #include  <dlfcn.h>       //-- FOR dlopen
#endif


//--------------------------------------------------------------------
//  Static variables and data
//--------------------------------------------------------------------

static NlpProblemDef *  g_pTheNlpProblemDefInstance = NULL;

//for calling the solver and feeding the nlp problem
static NlpProblemDef *  g_pOptProblem = NULL;

static int  wrapperEvalFC (const int             evalRequestCode,
                           const int             n,
                           const int             m,
                           const int             nnzJ,
                           const int             nnzH,
                           const double * const  daX,
                           const double * const  daLambda,
                                 double * const  dObj,
                                 double * const  daC,
                                 double * const  daG,
                                 double * const  daJ,
                                 double * const  daH,
                                 double * const  daHV,
                                 void   *        userParams){
    if (g_pOptProblem == NULL)
        {
        cout << "*** Problem not defined  <wrapperEvalFC>\n";
        return( -1 );
        }
    if (evalRequestCode != KTR_RC_EVALFC)
        {
        cout << "*** Bad request code " << evalRequestCode
             << "  <wrapperEvalFC>\n";
        return( -1 );
        }
    return( g_pOptProblem->evalFC (daX, dObj, daC, userParams) );
}//wrapperEvalFC


//--------------------------------------------------------------------
//  Internal Function:  wrapperEvalGA
//--------------------------------------------------------------------
/** By necessity this wrapper signature matches the function KTR_callback.
 *  It calls the current optimization problem's eval method.
 */
static int  wrapperEvalGA (const int             evalRequestCode,
                           const int             n,
                           const int             m,
                           const int             nnzJ,
                           const int             nnzH,
                           const double * const  daX,
                           const double * const  daLambda,
                                 double * const  dObj,
                                 double * const  daC,
                                 double * const  daG,
                                 double * const  daJ,
                                 double * const  daH,
                                 double * const  daHV,
                                 void   *        userParams){
    if (g_pOptProblem == NULL)
        {
        cout << "*** Problem not defined  <wrapperEvalGA>\n";
        return( -1 );
        }
    if (evalRequestCode != KTR_RC_EVALGA)
        {
        cout << "*** Bad request code " << evalRequestCode
             << "  <wrapperEvalGA>\n";
        return( -1 );
        }
    return( g_pOptProblem->evalGA (daX, daG, daJ, userParams) );
}//wrapperEvalGA


//--------------------------------------------------------------------
//  Internal Function:  wrapperEvalHorHV
//--------------------------------------------------------------------
/** By necessity this wrapper signature matches the function KTR_callback.
 *  It calls the current optimization problem's eval method.
 */
static int  wrapperEvalHorHV (const int             evalRequestCode,
                              const int             n,
                              const int             m,
                              const int             nnzJ,
                              const int             nnzH,
                              const double * const  daX,
                              const double * const  daLambda,
                                    double * const  dObj,
                                    double * const  daC,
                                    double * const  daG,
                                    double * const  daJ,
                                    double * const  daH,
                                    double * const  daHV,
                                    void   *        userParams){
    if (g_pOptProblem == NULL)
        {
        cout << "*** Problem not defined  <wrapperEvalHorHV>\n";
        return( -1 );
        }
    if (evalRequestCode == KTR_RC_EVALH)
        {
        if (g_pOptProblem->areDerivativesImplemented (nCAN_COMPUTE_H) == false)
            {
            cout << "*** This problem not evaluate H  <wrapperEvalHorHV>\n";
            return( -1 );
            }
        return( g_pOptProblem->evalH (daX, daLambda, daH, userParams) );
        }
    else if (evalRequestCode == KTR_RC_EVALHV)
        {
        if (g_pOptProblem->areDerivativesImplemented (nCAN_COMPUTE_HV) == false)
            {
            cout << "*** This problem not evaluate H*v  <wrapperEvalHorHV>\n";
            return( -1 );
            }
        return( g_pOptProblem->evalHV (daX, daLambda, daHV, userParams) );
        }
    else
        {
        cout << "*** Bad request code " << evalRequestCode
             << "  <wrapperEvalHorHV>\n";
        return( -1 );
        }
}//wrapperEvalHorHV



//--------------------------------------------------------------------
//  Exported Function:  getNlpProblemDef
//--------------------------------------------------------------------
//++ Export a function that returns the static pointer to this class.
#ifdef __cplusplus
extern "C"
{
    #if defined(_WIN32)
    __declspec(dllexport) NlpProblemDef *  getNlpProblemDef (void)
    #else
     NlpProblemDef *  getNlpProblemDef (void)
    #endif
    {
        if (g_pTheNlpProblemDefInstance == NULL)
            g_pTheNlpProblemDefInstance = new KnitroSolver;

        return( g_pTheNlpProblemDefInstance );
    }
}
#endif


KnitroSolver::KnitroSolver() {
	osrlwriter = new OSrLWriter();
	knitroErrorMsg = "";
	_daXInit = NULL;
}

KnitroSolver::~KnitroSolver() {
	#ifdef DEBUG
	cout << "inside KnitroSolver destructor" << endl;
	#endif
	delete osrlwriter;
	osrlwriter = NULL;
	delete osresult;
	osresult = NULL;
	#ifdef DEBUG
	cout << "leaving KnitroSolver destructor" << endl;
	#endif
    delete [] _daXInit;
	_daXInit = NULL;
} 

//--------------------------------------------------------------------
//  Simple access methods
//--------------------------------------------------------------------

int  KnitroSolver::getN (void){
    return( _nN );
}//getN


int  KnitroSolver::getM (void){
    return( _nM );
}//getM


void  KnitroSolver::getInitialX (double * const  daX){
    if (_daXInit == NULL){
        cout << "*** Must call 'loadProblemIntoKnitro' before 'KnitroSolver::getInitialX'\n";
        exit( EXIT_FAILURE );
        }

	for (int  i = 0; i < _nN; i++){
        daX[i] = _daXInit[i];
	}
    return;
}//getM

//--------------------------------------------------------------------
//  Method:  loadProblemIntoKnitro
//--------------------------------------------------------------------
/** Define the fixed problem definition information and pass it to
 *  KNITRO by calling KTR_init_problem.
 */
bool  KnitroSolver::loadProblemIntoKnitro (KTR_context_ptr  kc){
	int i;
	if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Knitro NEEDS AN OBJECTIVE FUNCTION");                 	
	// number of variables
	_nN = osinstance->getVariableNumber();
	// number of constraints
	_nM = osinstance->getConstraintNumber();
	cout << "number variables  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << _nN << endl;
	cout << "number constraints  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << _nM << endl;
	try{
		osinstance->initForAlgDiff( );
	}
	catch(const ErrorClass& eclass){
		knitroErrorMsg = eclass.errormsg;
		throw;  
	}	

	// variables lower bounds
	double * mdVarLB = osinstance->getVariableLowerBounds();
	std::cout << "GET BOUNDS INFORMATION FOR KNITRO!!!!!!!!!!!!!!!" << std::endl;
	// variables upper bounds
	double * mdVarUB = osinstance->getVariableUpperBounds();

	_daXLo  = new double[_nN];
    _daXUp  = new double[_nN];
	for(i = 0; i < _nN; i++){
		if( mdVarLB[ i] == -OSDBL_MAX) _daXLo[i] = -KTR_INFBOUND;
			else _daXLo[i] = mdVarLB[ i]; 
		if( mdVarUB[ i] == OSDBL_MAX) _daXUp[i] = KTR_INFBOUND;
			else _daXUp[i] = mdVarUB[ i];  	
			
		//cout << "x_l !!!!!!!!!!!!!!!!!!!!!!!!!!!" << x_l[i] << endl;
		//cout << "x_u !!!!!!!!!!!!!!!!!!!!!!!!!!!" << x_u[i] << endl;
	}

	//constraint lower bounds
	double * mdConLB = osinstance->getConstraintLowerBounds();
	//constraint upper bounds
	double * mdConUB = osinstance->getConstraintUpperBounds();
	
	_naCType  = new int[_nM];
    _daCLo    = new double[_nM];
    _daCUp    = new double[_nM];
    _naCType[0] = KTR_CONTYPE_LINEAR;
	for(i = 0; i < _nM; i++){
		if( mdConLB[ i] == -OSDBL_MAX) _daCLo[i] = -KTR_INFBOUND;
			else _daCLo[i] = mdConLB[ i]; 
		if( mdConUB[ i] == OSDBL_MAX) _daCUp[i] = KTR_INFBOUND;
			else _daCUp[i] = mdConUB[ i];  	
		//cout << "lower !!!!!!!!!!!!!!!!!!!!!!!!!!!" << _daCLo[i] << endl;
		//cout << "upper !!!!!!!!!!!!!!!!!!!!!!!!!!!" << _daCUp[i] << endl;
		_naCType[i] = KTR_CONTYPE_GENERAL; //need change
	}  

	// use the OS Expression tree for function evaluations instead of CppAD
	osinstance->bUseExpTreeForFunEval = true;
	std::cout << "Call sparse jacobian" << std::endl;
	SparseJacobianMatrix *sparseJacobian = NULL;
	try{
		sparseJacobian = osinstance->getJacobianSparsityPattern();
	}
	catch(const ErrorClass& eclass){
		knitroErrorMsg = eclass.errormsg;
		throw;  
	}
	std::cout << "Done calling sparse jacobian" << std::endl;
	_nNnzJ = sparseJacobian->valueSize;
	//cout << "_nNnzJ  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << _nNnzJ << endl;	
    _naJacIndexVars = new int[_nNnzJ];
    _naJacIndexCons = new int[_nNnzJ];
	int k, idx;
	i = 0;
	for(idx = 0; idx < _nM; idx++){
		for(k = *(sparseJacobian->starts + idx); k < *(sparseJacobian->starts + idx + 1); k++){
			_naJacIndexCons[i] = idx;
			_naJacIndexVars[i] = *(sparseJacobian->indexes + k);
			//cout << "ROW IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << _naJacIndexCons[i] << endl;
			//cout << "COL IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << _naJacIndexVars[i] << endl;
			i++;
		}
	}


	// nonzeros in upper hessian	
	if( (osinstance->getNumberOfNonlinearExpressions() == 0) && (osinstance->getNumberOfQuadraticTerms() == 0) ) {
		cout << "This is a linear program"  << endl;
		_nNnzH = 0;
	}
	else{
		std::cout << "Get Lagrangain Hessian Sparsity Pattern " << std::endl;
		SparseHessianMatrix *sparseHessian = osinstance->getLagrangianHessianSparsityPattern();
		std::cout << "Done Getting Lagrangain Hessian Sparsity Pattern " << std::endl;
		_nNnzH = sparseHessian->hessDimension;
		_naHessRows = new int[_nNnzH];
		_naHessCols = new int[_nNnzH];
		for(i = 0; i < _nNnzH; i++){
			_naHessCols[i] = *(sparseHessian->hessColIdx + i);
			_naHessRows[i] = *(sparseHessian->hessRowIdx + i);
				cout << "ROW HESS IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << _naHessRows[i] << endl;
				cout << "COL HESS IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << _naHessCols[i] << endl;
		}
	}  
 

    //---- INITIAL GUESS FOR x AND lambda.
  	// Here, we assume we only have starting values for x, if you code
  	// your own NLP, you can provide starting values for the dual variables
  	// if you wish
  	//cout << "get initial values !!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;
 	double *mdXInit = osinstance->getVariableInitialValues(); 
	_daXInit = new double[_nN];
 	if( mdXInit != NULL) {
 		for(i = 0; i < _nN; i++){
 	 		if(  CommonUtil::ISOSNAN( mdXInit[ i])  == true){
 	 			_daXInit[ i] = 1.7171;		
 	 		}			
 	 		else _daXInit[ i] = mdXInit[ i];
 		}
 	}	
 	else{
 		for(i = 0; i < _nN; i++){
 			_daXInit[ i] = 1.7171;
 		}
 	}
  	//cout << "got initial values !!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;

	double *  daLambdaInit = new double[_nM + _nN];
    for (i = 0; i < _nM + _nN; i++)
        daLambdaInit[i] = 0.0;
        
    // set obj type
    int iObjSense = KTR_OBJGOAL_MINIMIZE;
	if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("max") == 0){
  		iObjSense = KTR_OBJGOAL_MAXIMIZE;
  	}
    int iObjType = KTR_OBJTYPE_GENERAL; //KTR_OBJTYPE_LINEAR, KTR_OBJTYPE_QUADRATIC
	i = KTR_init_problem (kc, _nN,
                          iObjSense, iObjType,
                          _daXLo, _daXUp,
                          _nM, _naCType, _daCLo, _daCUp,
                          _nNnzJ, _naJacIndexVars, _naJacIndexCons,
                          _nNnzH, _naHessRows, _naHessCols,
                          _daXInit, daLambdaInit);

    delete [] _daXLo;
    delete [] _daXUp;
    delete [] _naCType;
    delete [] _daCLo;
    delete [] _daCUp;
    delete [] _naJacIndexVars;
    delete [] _naJacIndexCons;
    delete [] _naHessRows;
    delete [] _naHessCols;
    delete [] daLambdaInit;

    if (i != 0)
        {
        cout << "*** KTR_init_problem() returned " << i << "\n";
        return( false );
        }

    return( true );
}//loadProblemIntoKnitro

//--------------------------------------------------------------------
//  Method:  areDerivativesImplemented
//--------------------------------------------------------------------
bool  KnitroSolver::areDerivativesImplemented(const DerivativesImplementedType  nWhichDers){
     if (nWhichDers == nCAN_COMPUTE_GA)
        return( true );
    if (nWhichDers == nCAN_COMPUTE_H)
        return( true );
    if (nWhichDers == nCAN_COMPUTE_HV)
        return( false);
    return( false );         	
}//areDerivativesImplemented


//--------------------------------------------------------------------
//  Method:  evalFC
//--------------------------------------------------------------------
int  KnitroSolver::evalFC (const double * const  daX,
                         double * const  dObj,
                         double * const  daC,
                         void   *        userParams){
	try{
		*dObj  = osinstance->calculateAllObjectiveFunctionValues((double*)daX, NULL, NULL, true, 0 )[0];
	}
	catch(const ErrorClass& eclass){
		knitroErrorMsg = eclass.errormsg;
		return (-1);    
	}
	if( CommonUtil::ISOSNAN( *dObj )) return (-1);



	try{
 		double *conVals = osinstance->calculateAllConstraintFunctionValues((double*)daX, NULL, NULL, true, 0 );
 		int i;
 		for(i = 0; i < _nM; i++){
 			if( CommonUtil::ISOSNAN( (double)conVals[ i] ) ) return (-1);
 			daC[i] = conVals[ i]  ;	
 		} 
	}
	catch(const ErrorClass& eclass){
		knitroErrorMsg = eclass.errormsg;
		return (-1);  
	}


    return( 0 );
}//evalFC


//--------------------------------------------------------------------
//  Method:  evalGA
//--------------------------------------------------------------------
int  KnitroSolver::evalGA (const double * const  daX,
                         double * const  daG,
                         double * const  daJ,
                         void   *        userParams){
	try{
 		double *objGrad = osinstance->calculateAllObjectiveFunctionGradients((double*)daX, NULL, NULL, true, 1 )[0];
 		int i;
 		std::cout << "EVALUATING OBJ GRADIENT" << std::endl;
 		for(i = 0; i < _nN; i++){
 			if( CommonUtil::ISOSNAN( (double)objGrad[ i] ) ) return (-1);
 			daG[i] = objGrad[ i]  ;	
 		} 
	}
	catch(const ErrorClass& eclass){
		knitroErrorMsg = eclass.errormsg;
		return (-1);
	}

 	SparseJacobianMatrix *sparseJacobian;
	std::cout << "EVALUATING JACOBIAN" << std::endl; 
	try{
		sparseJacobian = osinstance->calculateAllConstraintFunctionGradients((double*)daX, NULL, NULL,  true, 1);
	}
	catch(const ErrorClass& eclass){
		knitroErrorMsg = eclass.errormsg;
		return (-1);
	}
	//osinstance->getIterateResults( (double*)x, 0.0, NULL, -1, true,  1);
	for(int i = 0; i < _nNnzJ; i++){
		daJ[ i] = sparseJacobian->values[i];
		//daJ[ i] = osinstance->m_mdJacValue[ i];
		cout << "daJ[i]:!!!!!!!!!!!!  " <<  daJ[ i] << endl;
		//cout << "m_mdJacValue[ i]:!!!!!!!!!!!!  " <<  osinstance->m_mdJacValue[ i] << endl;
	}

    return( 0 );
}//evalGA


//--------------------------------------------------------------------
//  Method:  evalH
//--------------------------------------------------------------------
int  KnitroSolver::evalH (const double * const  daX,
                  const double * const  daLambda,
                        double * const  daH,
                        void   *        userParams){
	SparseHessianMatrix *sparseHessian;
	int i;
	double* objMultipliers = new double[1];
	objMultipliers[0] = 1;
	try{
		sparseHessian = osinstance->calculateLagrangianHessian((double*)daX, objMultipliers, (double*)daLambda ,  true, 2);
	}
	catch(const ErrorClass& eclass){
		knitroErrorMsg = eclass.errormsg;
		return (-1);  
	}
	for(i = 0; i < _nNnzH; i++){
		daH[ i]  = *(sparseHessian->hessValues + i);
		std::cout << "Hessian Value = " << daH[ i] << std::endl;
	}
	delete[] objMultipliers;
    return( 0 );
}//evalH


//--------------------------------------------------------------------
//  Method:  evalHV
//--------------------------------------------------------------------
int  KnitroSolver::evalHV (const double * const  daX,
                   const double * const  daLambda,
                         double * const  daHV,
                         void   *        userParams){

    return( 0 );
}//evalHV

//OS specific default solver methods

void KnitroSolver::solve() throw (ErrorClass) {
	try{
		OSiLReader* osilreader = NULL; 
		osresult = new OSResult();
		if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
		clock_t start, finish;
		double duration;
		start = clock();
		bool newOSiLReader = false;
		if(osinstance == NULL){
			osilreader = new OSiLReader();
			osinstance = osilreader->readOSiL( osil);
			newOSiLReader = true;
		}
		OSiLWriter osilwriter;
		//cout << osilwriter.writeOSiL( osinstance) << endl;
		if(osinstance->getVariableNumber() <= 0)throw ErrorClass("Knitro requires decision variables");
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Parsing took (seconds): "<< duration << endl;
		//dataEchoCheck();

		/***************now the Knitro invokation*********************/
		// Create a new instance of your nlp 
		NlpProblemDef *  pOptProb = this;
		bool             bWantToSolve;

		//---- OPEN A NEW INSTANCE OF KNITRO.
		KTR_context  *kc;
		kc = KTR_new();
		if (kc == NULL){
			cout << "*** KTR_new failed, maybe a license issue?\n";
			exit( EXIT_FAILURE );
        }

		//---- APPLY ANY USER OPTIONS (PROCEED EVEN IF THERE IS AN ERROR).
		KTR_load_param_file (kc, "knitro.opt");

		//---- LOAD THE PROBLEM INTO KNITRO.
		//if (pOptProb->loadProblemIntoKnitro (kc) == false){
		//	cout << "*** loadProblemIntoKnitro failed\n";
		//	exit( EXIT_FAILURE );
        //}

		//---- SET CALLBACK POINTERS FOR EVALUATION OF PROBLEM INFORMATION.
		//---- IF THE TEST CODE DOES NOT SUPPLY DERIVATIVES, THEN THE
		//---- USER OPTIONS IN "knitro.opt" SHOULD REQUEST AN ALTERNATIVE,
		//---- SUCH AS FINITE DIFFERENCES.
	    g_pOptProblem = pOptProb;
		if (KTR_set_func_callback (kc, wrapperEvalFC) != 0){
			cout << "*** KTR_set_func_callback failed\n";
			exit( EXIT_FAILURE );
		}
		if (pOptProb->areDerivativesImplemented (nCAN_COMPUTE_GA) == true){
			if (KTR_set_grad_callback (kc, wrapperEvalGA) != 0){
				cout << "*** KTR_set_grad_callback failed\n";
				exit( EXIT_FAILURE );
			}
        }
	    if ((pOptProb->areDerivativesImplemented (nCAN_COMPUTE_H) == true)
			|| (pOptProb->areDerivativesImplemented (nCAN_COMPUTE_HV) == true)){
			if (KTR_set_hess_callback (kc, wrapperEvalHorHV) != 0){
            cout << "*** KTR_set_hess_callback failed\n";
            exit( EXIT_FAILURE );
            }
        }

		//---- ALLOCATE ARRAYS
		double *  daX      = new double[pOptProb->getN()];
		double *  daLambda = new double[pOptProb->getM() + pOptProb->getN()];
		double* mdObjValues = new double[1];
		bWantToSolve = true;
		if (bWantToSolve == true){
			//---- CALL KNITRO AND SOLVE.
			double  dFinalObj;
			int  nStatus = KTR_solve (kc, daX, daLambda, 0, &dFinalObj,
									NULL, NULL, NULL, NULL, NULL, NULL);
			std::cout << "dFinalObj =  " << dFinalObj << std::endl;
			cout << "*** Final KNITRO status = " << nStatus << "\n";
			cout << "dax[0] = " << daX[0] << "\n";

			//construct osresult
			int solIdx = 0;
			
			std::string message = "Knitro solver finishes to the end.";
			std::string solutionDescription = "";	

			// resultHeader infomration
			if(osresult->setServiceName( "Knitro solver service") != true)
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
		std::cout << "START CASES  " << 0 << endl;
			switch( nStatus){
				case 0:
					std::cout << "WE ARE IN CASE " << 0 << endl;
					solutionDescription = "LOCALLY OPTIMAL SOLUTION FOUND[KNITRO STATUS 0]: Knitro found a locally optimal point which satisfies the stopping criterion.If the problem is convex (for example, a linear program), then this point corresponds to a globally optimal solution.";
					osresult->setSolutionStatus(solIdx,  "locallyOptimal", solutionDescription);
					std::cout << "SET SOLUTION STATUS " << endl;
					osresult->setPrimalVariableValues(solIdx, daX);
					std::cout << "SET PRIMAL VALUES " << endl;
					osresult->setDualVariableValues(solIdx, daLambda);
					mdObjValues[0] = dFinalObj;
					osresult->setObjectiveValues(solIdx, mdObjValues);
					std::cout << "SET OBJECTIVE VALUES " << endl;
				break;
				case -1:
					solutionDescription = "Iteration limit reached[KNITRO STATUS -1]: The iteration limit was reached before being able to satisfy the required stopping criteria.";
					osresult->setSolutionStatus(solIdx,  "stoppedByLimit", solutionDescription);
					osresult->setPrimalVariableValues(solIdx, daX);
					osresult->setDualVariableValues(solIdx, daLambda);
					mdObjValues[0] = dFinalObj;
					osresult->setObjectiveValues(solIdx, mdObjValues);
				break;
				case -2:
					solutionDescription = "Convergence to an infeasible point[KNITRO STATUS -2]: Problem may be locally infeasible.The algorithm has converged to an infeasible point from which it cannot further decrease the infeasibility measure. This happens when the problem is infeasible, but may also occur on occasion for feasible problems with nonlinear constraints or badly scaled problems. It is recommended to try various initial points. If this occurs for a variety of initial points, it is likely the problem is infeasible.";
					osresult->setSolutionStatus(solIdx,  "infeasible", solutionDescription);
				break;
				case -3:
					solutionDescription = "Problem appears to be unbounded[KNITRO STATUS -3]: Iterate is feasible and objective magnitude > objrange. The objective function appears to be decreasing without bound, while satisfying the constraints.If the problem really is bounded, increase the size of the parameter objrange to avoid terminating with this message.";
					osresult->setSolutionStatus(solIdx,  "unbounded", solutionDescription);
				break;
				case -4:
					solutionDescription = "Relative change in solution estimate < xtol[KNITRO STATUS -4]: The relative change in the solution estimate is less than that specified by the paramater xtol.To try to get more accuracy one may decrease xtol. If xtol is very small already, it is an indication that no more significant progress can be made. If the current point is feasible, it is possible it may be optimal, however the stopping tests cannot be satisfied (perhaps because of degeneracy, ill-conditioning or bad scaling).";
					osresult->setSolutionStatus(solIdx,  "stoppedByLimit", solutionDescription);
					osresult->setPrimalVariableValues(solIdx, daX);
					osresult->setDualVariableValues(solIdx, daLambda);
					mdObjValues[0] = dFinalObj;
					osresult->setObjectiveValues(solIdx, mdObjValues);
				break;
				case -5:
					solutionDescription = "Current solution estimate cannot be improved. Point appears to be optimal, but desired accuracy could not be achieved.[KNITRO  STATUS -5]: No more progress can be made, but the stopping tests are close to being satisfied (within a factor of 100) and so the current approximate solution is believed to be optimal.";
					osresult->setSolutionStatus(solIdx,  "locallyOptimal", solutionDescription);
					osresult->setPrimalVariableValues(solIdx, daX);
					osresult->setDualVariableValues(solIdx, daLambda);
					mdObjValues[0] = dFinalObj;
					osresult->setObjectiveValues(solIdx, mdObjValues);
				break;
				case -6:
					solutionDescription = "Time limit reached[KNITRO STATUS -6]: The time limit was reached before being able to satisfy the required stopping criteria.";
					osresult->setSolutionStatus(solIdx,  "stoppedByLimit", solutionDescription);
					osresult->setPrimalVariableValues(solIdx, daX);
					osresult->setDualVariableValues(solIdx, daLambda);
					mdObjValues[0] = dFinalObj;
					osresult->setObjectiveValues(solIdx, mdObjValues);
				break;
				case -50:
				case -51:
				case -52:
				case -53:
				case -54:
				case -55:
				case -56:
				case -57:
				case -58:
				case -59:
				case -60:
					solutionDescription = "Input Error[KNITRO STATUS -50 to -60]: Termination values in this range imply some input error. If outlev>0 details of this error will be printed to standard output or the file knitro.log depending on the value of outmode.";
					osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
				break;
				case -90:
					solutionDescription = "Callback function error[KNITRO STATUS -90]: This termination value indicates that an error (i.e., negative return value) occurred in a user provided callback routine.";
					osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
				break;
				case -97:
					solutionDescription = "LP solver error[KNITRO STATUS -97]: This termination value indicates that an unrecoverable error occurred in the LP solver used in the active-set algorithm preventing the optimization from continuing.";
					osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
				break;
				case -98:
					solutionDescription = "Evaluation error[KNITRO STATUS -98]: This termination value indicates that an evaluation error occurred (e.g., divide by 0, taking the square root of a negative number), preventing the optimization from continuing.";
					osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
				break;
				case -99:
					solutionDescription = "Not enough memory available to solve problem[KNITRO STATUS -99]: This termination value indicates that there was not enough memory available to solve the problem.";
					osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
				break;
				default:
					solutionDescription = "OTHER[KNITRO]: other unknown solution status from Knitro solver";
					osresult->setSolutionStatus(solIdx,  "other", solutionDescription);
			}

			osresult->setGeneralStatusType("success");
			osrl = osrlwriter->writeOSrL( osresult);
		}
		else{
			//---- USE KNITRO TO CHECK THE DERIVATIVES CODED IN THE TEST PROBLEM.
			pOptProb->getInitialX (daX);
			KTR_check_first_ders (kc, daX, 2, 1.0e-14, 1.0e-14,
								0, 0.0, NULL, NULL, NULL, NULL);
		}
		
		if(newOSiLReader == true){
			delete osilreader;
			osilreader = NULL;
		}
		delete [] daX;
		delete [] daLambda;
		delete [] mdObjValues;

		KTR_free (&kc);

		//delete pOptProb;
		//return( EXIT_SUCCESS );	//to do
	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		//throw ErrorClass( osrl) ; //to do
	}
}//solve


void KnitroSolver::dataEchoCheck(){
	
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


NlpProblemDef::~NlpProblemDef (void)
{
    //---- DO NOTHING.
   //return;
   }

                               


