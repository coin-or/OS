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


#include "KnitroSolver.h"
#include "CommonUtil.h"

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
//  Internal Function:  printUsage
//--------------------------------------------------------------------
static void  printUsage (void){
    cout << "Use KNITRO to solve an optimization problem coded in C++.\n";
    cout << "  Usage:  driverExample problem_name <checkders>\n";
    cout << "          'checkders' means check derivatives instead of solving\n";
    cout << "Note that problem names are case sensitive.\n";
    return;
}//printUsage


//--------------------------------------------------------------------
//  Internal Function:  loadProblemCode
//--------------------------------------------------------------------
/** Convert the first command line argument to shared link object
 *  that contains a test problem.  The command line may also specify
 *  a boolean flag.
 */
static bool  loadProblemCode (const int                     argc,
                              const char          *  const  argv[],
                                    NlpProblemDef **        pOptProb,
                                    bool          *  const  pbWantToSolve){
    *pOptProb = NULL;
    *pbWantToSolve = true;

    //---- CHECK IF THE USER REQUESTED A HELP MESSAGE.
    if (argc < 2)
        return( false );
    for (int  i = 1; i < argc; i++)
        if ((strcmp (argv[i], "-?") == 0) || (strcmp (argv[i], "?") == 0))
            return( false );

    //---- LOAD THE LINK OBJECT.
    cout << "Attempting to load problem '" << argv[1] << "' ...\n";
    #if defined(_WIN32)
        HINSTANCE  hLib = LoadLibrary (argv[1]);
        if (hLib == NULL)
            {
            cout << "*** Could not load DLL '" << argv[1] << "'.\n\n";
            return( false );
            }
        FnType_getNlpProblemDef  fnPtr;
        fnPtr = (FnType_getNlpProblemDef) GetProcAddress (hLib,
                                                          "getNlpProblemDef");
        if (fnPtr == NULL)
            {
            cout << "*** Could not find getNlpProblemDef in DLL '"
                 << argv[1] << "'.\n\n";
            FreeLibrary (hLib);
            return( false );
            }
        *pOptProb = fnPtr();
    #else
        char *  szTmp = new char[100 + 1];
        strcpy (szTmp, argv[1]);
        if (strchr (szTmp, '.') == NULL)
            {
            #if defined(__APPLE__)
                strcat (szTmp, ".dylib");
            #else
                strcat (szTmp, ".so");
            #endif
            }
        void *  hLib = dlopen (szTmp, RTLD_NOW);
        if (hLib == NULL)
            {
            cout << "*** Could not load problem '" << szTmp << "'.\n";
            cout << "    " << dlerror() << "\n\n";
            return( false );
            }
        delete[] szTmp;
        dlerror();    //-- CLEAR THE ERROR ROUTINE.
        FnType_getNlpProblemDef  fnPtr;
        *(void **) (&fnPtr) = dlsym (hLib, "getNlpProblemDef");
        char *  pszError = dlerror();
        if (pszError != NULL)
            {
            cout << "*** Could not find getNlpProblemDef in DLL '"
                 << argv[1] << "'.\n";
            cout << "    " << pszError << "\n\n";
            dlclose (hLib);
            return( false );
            }
        *pOptProb = fnPtr();
    #endif

    //---- CHECK FOR OPTIONAL COMMAND LINE ARGUMENTS.
    if (argc == 3)
        {
        if (strcmp (argv[2], "checkders") == 0)
            *pbWantToSolve = false;
        else
            {
            cout << "*** Unknown argument '" << argv[2] << "'.\n\n";
            return( false );
            }
        }
    if (argc > 3)
        {
        cout << "*** Too many arguments.\n\n";
        return( false );
        }

    return( true );
}//loadProblemCode


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
		osinstance->initForCallBack( );
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
		_daXLo[i] = mdVarLB[ i];  //-KTR_INFBOUND;	
		_daXUp[i] = mdVarUB[ i];  //KTR_INFBOUND;
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
    _daCLo[0] = -KTR_INFBOUND;
    _daCUp[0] = 3.0;
    _naCType[0] = KTR_CONTYPE_LINEAR;
	for(i = 0; i < _nM; i++){
		_daCLo[i] = mdConLB[ i];
		_daCUp[0] = mdConUB[ i];
		//cout << "lower !!!!!!!!!!!!!!!!!!!!!!!!!!!" << _daCLo[i] << endl;
		//cout << "upper !!!!!!!!!!!!!!!!!!!!!!!!!!!" << _daCUp[i] << endl;
		_naCType[0] = KTR_CONTYPE_GENERAL; //need change
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
			_naHessRows[i] = *(sparseHessian->hessColIdx + i);
			_naHessCols[i] = *(sparseHessian->hessRowIdx + i);
				//cout << "ROW HESS IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << iRow[i] << endl;
				//cout << "COL HESS IDX  !!!!!!!!!!!!!!!!!!!!!!!!!!!"  << jCol[i] << endl;
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
 			_daXInit[ i] = mdXInit[ i];
 			//std::cout << "INITIAL VALUE !!!!!!!!!!!!!!!!!!!!  " << _daXInit[ i] << std::endl;	
 		}	
 	}
 	else{
 		for(i = 0; i < _nN; i++){
 			_daXInit[ i] = 1.7171;
 		}
 	}
  	//cout << "got initial values !!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;

	double *  daLambdaInit = new double[_nM + _nN];
    for (i = 0; i < _nN; i++)
        _daXInit[i] = 0.5;
    for (i = 0; i < _nM + _nN; i++)
        daLambdaInit[i] = 0.0;
    
	i = KTR_init_problem (kc, _nN,
                          KTR_OBJGOAL_MINIMIZE, KTR_OBJTYPE_QUADRATIC,
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
bool  KnitroSolver::areDerivativesImplemented
          (const DerivativesImplementedType  nWhichDers){
    if (nWhichDers == nCAN_COMPUTE_GA)
        return( true );
    if (nWhichDers == nCAN_COMPUTE_H)
        return( true );
    if (nWhichDers == nCAN_COMPUTE_HV)
        return( true );
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
 			if( CommonUtil::ISOSNAN( (double)conVals[ i] ) ) return false;
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
 		double *conVals = osinstance->calculateAllConstraintFunctionValues((double*)daX, NULL, NULL, true, 0 );
 		int i;
 		for(i = 0; i < _nM; i++){
 			if( CommonUtil::ISOSNAN( (double)conVals[ i] ) ) return (-1);
 			daG[i] = conVals[ i]  ;	
 		} 
	}
	catch(const ErrorClass& eclass){
		knitroErrorMsg = eclass.errormsg;
		return (-1);
	}

 	SparseJacobianMatrix *sparseJacobian;
	//std::cout << "EVALUATING JACOBIAN" << std::endl; 
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
		//cout << "daJ[i]:!!!!!!!!!!!!  " <<  daJ[ i] << endl;
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
    //daH[0] = 4.0;
    //daH[1] = 2.0;
    //daH[2] = 2.0;
    //daH[3] = 4.0;
    //daH[4] = 2.0;
	SparseHessianMatrix *sparseHessian;
	int i;
	//std::cout << "EVALUATING HESSIAN" << std::endl; 
	// return the values. This is a symmetric matrix, fill the lower left triangle only 
	double* objMultipliers = new double[1];
	objMultipliers[0] = 1;//need to change
	try{
		sparseHessian = osinstance->calculateLagrangianHessian((double*)daX, objMultipliers, (double*)daLambda ,  true, 2);
	}
	catch(const ErrorClass& eclass){
		knitroErrorMsg = eclass.errormsg;
		return (-1);  
	}
	for(i = 0; i < _nNnzH; i++){
		daH[ i]  = *(sparseHessian->hessValues + i); //need to change
	}

    return( 0 );
}//evalH


//--------------------------------------------------------------------
//  Method:  evalHV
//--------------------------------------------------------------------
int  KnitroSolver::evalHV (const double * const  daX,
                   const double * const  daLambda,
                         double * const  daHV,
                         void   *        userParams){
    //daHV[0] = (4.0 * daHV[0]) + (2.0 * daHV[1]) + (2.0 * daHV[2]);
    //daHV[1] = (2.0 * daHV[0]) + (4.0 * daHV[1]);
    //daHV[2] = (2.0 * daHV[0])                   + (2.0 * daHV[2]);

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
		if(osinstance == NULL){
			osilreader = new OSiLReader();
			osinstance = osilreader->readOSiL( &osil);
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

	/* //to do
		if ((loadProblemCode (argc, argv, &pOptProb, &bWantToSolve) == false)){ //need to change
			printUsage();
			exit( EXIT_FAILURE );
        }
	*/
		//---- OPEN A NEW INSTANCE OF KNITRO.
		KTR_context_ptr  kc;
		kc = KTR_new();
		if (kc == NULL){
			cout << "*** KTR_new failed, maybe a license issue?\n";
			exit( EXIT_FAILURE );
        }

		//---- APPLY ANY USER OPTIONS (PROCEED EVEN IF THERE IS AN ERROR).
		KTR_load_param_file (kc, "knitro.opt");

		//---- LOAD THE PROBLEM INTO KNITRO.
		if (pOptProb->loadProblemIntoKnitro (kc) == false){
			cout << "*** loadProblemIntoKnitro failed\n";
			exit( EXIT_FAILURE );
        }

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

		if (bWantToSolve == true){
			//---- CALL KNITRO AND SOLVE.
			double  dFinalObj;
			int  nStatus = KTR_solve (kc, daX, daLambda, 0, &dFinalObj,
									NULL, NULL, NULL, NULL, NULL, NULL);
			cout << "*** Final KNITRO status = " << nStatus << "\n";
		}
		else{
			//---- USE KNITRO TO CHECK THE DERIVATIVES CODED IN THE TEST PROBLEM.
			pOptProb->getInitialX (daX);
			KTR_check_first_ders (kc, daX, 2, 1.0e-14, 1.0e-14,
								0, 0.0, NULL, NULL, NULL, NULL);
		}

		delete [] daX;
		delete [] daLambda;

		KTR_free (&kc);

		delete pOptProb;
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



                               


