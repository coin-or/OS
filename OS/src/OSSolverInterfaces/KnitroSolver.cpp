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


//--------------------------------------------------------------------
//  Static variables and data
//--------------------------------------------------------------------

static NlpProblemDef *  g_pTheNlpProblemDefInstance = NULL;


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
return false;
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
	/*
    *dObj =   9.0 - (8.0 * daX[0]) - (6.0 * daX[1]) - (4.0 * daX[2])
            + (2.0 * daX[0] * daX[0]) + (2.0 * daX[1] * daX[1])
                                      + (daX[2] * daX[2])
            + (2.0 * daX[0] * daX[1]) + (2.0 * daX[0] * daX[2]);
	*/
    //daC[0] = daX[0] + daX[1] + (2.0 * daX[2]);

    return( 0 );
}//evalFC


//--------------------------------------------------------------------
//  Method:  evalGA
//--------------------------------------------------------------------
int  KnitroSolver::evalGA (const double * const  daX,
                         double * const  daG,
                         double * const  daJ,
                         void   *        userParams){
    //daG[0] = -8.0 + (4.0 * daX[0]) + (2.0 * daX[1]) + (2.0 * daX[2]);
    //daG[1] = -6.0 + (2.0 * daX[0]) + (4.0 * daX[1]);
    //daG[2] = -4.0 + (2.0 * daX[0])                  + (2.0 * daX[2]);

    //daJ[ 0] = 1.0;
    //daJ[ 1] = 1.0;
    //daJ[ 2] = 2.0;

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
		
		
	
	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
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





