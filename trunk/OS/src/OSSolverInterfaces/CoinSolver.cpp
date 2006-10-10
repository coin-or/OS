/** @file CoinSolver.cpp
 * 
 * \brief This file defines the CoinSolver class.
 * \detail Read an OSInstance object and convert in COIN data structures
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


      

#include "CoinSolver.h"
#include "OSiLReader.h"
#include "OSInstance.h"
#include "FileUtil.h"
  
#include <iostream>
#include <time.h>  
using std::cout; 
using std::endl; 
using std::ostringstream;


CoinSolver::CoinSolver() : 
m_OsiSolver(NULL),
m_CoinPackedMatrix(NULL) 
{
osrlwriter = new OSrLWriter();
}

CoinSolver::~CoinSolver() {
	#ifdef DEBUG
	cout << "inside CoinSolver destructor" << endl;
	#endif
	cout << "inside CoinSolver destructor" << endl;
	delete m_CoinPackedMatrix;
	m_CoinPackedMatrix = NULL;
	delete m_OsiSolver;
	m_OsiSolver = NULL;
	delete osrlwriter;
	osrlwriter = NULL;
	cout << "leaving CoinSolver destructor" << endl;
}


void CoinSolver::solve() throw (ErrorClass) {
	try{
	OSiLReader *osilreader = NULL;
	osresult = new OSResult();

		if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
		clock_t start, finish;
		double duration;
		start = clock();
		if(osinstance == NULL){
			osilreader = new OSiLReader();
			osinstance = osilreader->readOSiL( &osil);
		}
				finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Parsing took (seconds): "<< duration << endl;
			cout << "Start Solve with a Coin Solver" << endl;
		// get the type of solver requested from OSoL string
		bool solverIsDefined = false;
		if( m_sSolverName.find("clp") != std::string::npos){
			if( (osinstance->getNumberOfNonlinearExpressions() > 0)
				|| (osinstance->getNumberOfQuadraticTerms() > 0) 
				|| (osinstance->getNumberOfIntegerVariables() > 0)
				|| (osinstance->getNumberOfBinaryVariables() > 0) ) throw ErrorClass( "Clp cannot do nonlinear or quadratic or integer");
			solverIsDefined = true;
			m_OsiSolver = new OsiClpSolverInterface();
		}
		else{
			if( m_sSolverName.find("cbc") != std::string::npos){
				if( (osinstance->getNumberOfNonlinearExpressions() > 0)
					|| (osinstance->getNumberOfQuadraticTerms() > 0) ) throw ErrorClass( "Cbc cannot do nonlinear or quadratic");
				solverIsDefined = true;
				m_OsiSolver = new OsiCbcSolverInterface();
			}
			else{
				if( m_sSolverName.find( "cplex") != std::string::npos){
					#ifdef COIN_HAS_CPX
					if( (osinstance->getNumberOfNonlinearExpressions() > 0)
						|| (osinstance->getNumberOfQuadraticTerms() > 0) ) throw ErrorClass( "Cplex cannot do nonlinear or quadratic");
					solverIsDefined = true;
					m_OsiSolver = new OsiCpxSolverInterface();
					#endif
				}
				else{
					if(m_sSolverName.find( "glpk") != std::string::npos){
						#ifdef COIN_HAS_GLPK
						if( (osinstance->getNumberOfNonlinearExpressions() > 0)
							|| (osinstance->getNumberOfQuadraticTerms() > 0) ) throw ErrorClass( "Glpk cannot do nonlinear or quadratic");
						solverIsDefined = true;
						m_OsiSolver = new OsiGlpkSolverInterface();
						#endif
					}
					else{
						solverIsDefined = false;
					}
				}
			}
		}
		if(solverIsDefined == false) throw ErrorClass("a supported solver was not defined");
		if(osinstance->getConstraintNumber() <= 0)throw ErrorClass("Coin solver Needs Constraints");
		if(osinstance->getVariableNumber() <= 0)throw ErrorClass("Coin solver requires decision variables");
		if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Coin solver needs an objective function");
		if(osinstance->getLinearConstraintCoefficientNumber() <= 0) throw ErrorClass("Coin solver needs linear constraints");
		if(!setCoinPackedMatrix() ) throw ErrorClass("Problem generating coin packed matrix");
		//dataEchoCheck();
		if(optimize() != true) throw ErrorClass("there was an error trying to optimize the problem");
		delete osilreader;
		osilreader = NULL;
	}// end solve
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ;
	}				
}//end solve()



bool CoinSolver::setCoinPackedMatrix(){
	bool columnMajor = osinstance->getLinearConstraintCoefficientMajor();
	try{
		int maxGap = 0;
		m_CoinPackedMatrix = new CoinPackedMatrix(
			columnMajor, //Column or Row Major
			columnMajor? osinstance->getConstraintNumber() : osinstance->getVariableNumber(), //Minor Dimension
			columnMajor? osinstance->getVariableNumber() : osinstance->getConstraintNumber(), //Major Dimension
			osinstance->getLinearConstraintCoefficientNumber(), //Number of nonzeroes
			columnMajor? osinstance->getLinearConstraintCoefficientsInColumnMajor()->values : osinstance->getLinearConstraintCoefficientsInRowMajor()->values, //Pointer to matrix nonzeroes
			columnMajor? osinstance->getLinearConstraintCoefficientsInColumnMajor()->indexes : osinstance->getLinearConstraintCoefficientsInRowMajor()->indexes, //Pointer to start of minor dimension indexes -- change to allow for row storage
			columnMajor? osinstance->getLinearConstraintCoefficientsInColumnMajor()->starts : osinstance->getLinearConstraintCoefficientsInRowMajor()->starts, //Pointers to start of columns.
			0,   0, maxGap ); 

		return true;
	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ;
	}
} // end setCoinPackedMatrix

bool CoinSolver::optimize()
{
	double *x, *y, *z;
	std::string *rcost;
	int solIdx = 0;
	// resultHeader infomration
	if(osresult->setServiceName("Solved with Coin Solver: " + m_sSolverName) != true)
		throw ErrorClass("OSResult error: setServiceName");
	if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
		throw ErrorClass("OSResult error: setInstanceName");
	//if(osresult->setJobID( osresultdata->jobID) != true)
	//	throw ErrorClass("OSResult error: setJobID");
	//if(osresult->setGeneralMessage( osresultdata->message) != true)
	//	throw ErrorClass("OSResult error: setGeneralMessage");
	// set basic problem parameters
	if(osresult->setVariableNumber( osinstance->getVariableNumber()) != true)
		throw ErrorClass("OSResult error: setVariableNumer");
	if(osresult->setObjectiveNumber( 1) != true)
		throw ErrorClass("OSResult error: setObjectiveNumber");
	if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
		throw ErrorClass("OSResult error: setConstraintNumber");
	if(osresult->setSolutionNumber(  1) != true)
		throw ErrorClass("OSResult error: setSolutionNumer");	
	//
	int i = 0;
	try{
		m_OsiSolver->loadProblem(*m_CoinPackedMatrix, osinstance->getVariableLowerBounds(), 
					osinstance->getVariableUpperBounds(),  
					osinstance->getDenseObjectiveCoefficients()[0], 
					osinstance->getConstraintLowerBounds(), osinstance->getConstraintUpperBounds());
		
		// the code below causes a memory problem because it does not create a new copy in memory
		//m_OsiSolver->assignProblem(m_CoinPackedMatrix, osinstance->getVariableLowerBounds(), 
		//			osinstance->getVariableUpperBounds(),  
		//			osinstance->getDenseObjectiveCoefficients()[0], 
		//			osinstance->getConstraintLowerBounds(), osinstance->getConstraintUpperBounds());

		if(osinstance->getObjectiveNumber() == 0) throw ErrorClass("there is no objective function");

		//		
		if( osinstance->getObjectiveMaxOrMins()[0] == "min") m_OsiSolver->setObjSense(1.0);
		else m_OsiSolver->setObjSense(-1.0);
		m_OsiSolver->setDblParam(OsiObjOffset, osinstance->getObjectiveConstants()[0]);
		//
		// set the integer variables
		int *intIndex;
		int k = 0;
		char *varType;
		int numOfIntVars = osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables();
		intIndex = new int[ numOfIntVars];
		varType = osinstance->getVariableTypes();
		for(i = 0; i < osinstance->getVariableNumber(); i++){
			if( (varType[i] == 'B') || (varType[i]) == 'I' ) {
				intIndex[k++] = i;
			}
		}
		m_OsiSolver->setInteger( intIndex,  numOfIntVars);
		if(numOfIntVars > 0){
			m_OsiSolver->branchAndBound();
		}
		else{
			m_OsiSolver->initialSolve();
			cout << "DONE WITH INITIAL SOLVE" << endl;
		}
		int solIdx = 0;
		std::string description = "";
		osresult->setGeneralStatusType("success");
		if (m_OsiSolver->isProvenOptimal() == true){
			osresult->setSolutionStatus(solIdx, "optimal", description);
			/* Retrieve the solution */
			x = new double[osinstance->getVariableNumber() ];
			y = new double[osinstance->getConstraintNumber() ];
			z = new double[1];
			//
			*(z + 0)  =  m_OsiSolver->getObjValue();
			osresult->setObjectiveValues(solIdx, z);
			for(i=0; i < osinstance->getVariableNumber(); i++){
				*(x + i) = m_OsiSolver->getColSolution()[i];

			}
			osresult->setPrimalVariableValues(solIdx, x);
			for(i=0; i <  osinstance->getConstraintNumber(); i++){
				*(y + i) = m_OsiSolver->getRowPrice()[ i];
			}
			osresult->setDualVariableValues(solIdx, y);
			//
			//
			// now put the reduced costs into the osrl
			int numberOfOtherVariableResult = 1;
			int otherIdx = 0;
			// first set the number of Other Variable Results
			osresult->setNumberOfOtherVariableResult(solIdx, numberOfOtherVariableResult);
			ostringstream outStr;
			int numberOfVar =  osinstance->getVariableNumber();
			rcost = new std::string[ numberOfVar];
			for(i=0; i < numberOfVar; i++){
				outStr << m_OsiSolver->getReducedCost()[ i]; 
				rcost[ i] = outStr.str();
				outStr.str("");
			}
			osresult->setAnOtherVariableResult(solIdx, otherIdx, "reduced costs", "the variable reduced costs", rcost);			
			// end of settiing reduced costs
		}
		else{ 
			if(m_OsiSolver->isProvenPrimalInfeasible() == true) 
				osresult->setSolutionStatus(solIdx, "infeasible", description);
			else
				if(m_OsiSolver->isProvenDualInfeasible() == true) 
					osresult->setSolutionStatus(solIdx, "dualinfeasible", description);
				else
					osresult->setSolutionStatus(solIdx, "other", description);
		}
		osrl = osrlwriter->writeOSrL( osresult);
		if(osinstance->getVariableNumber() > 0) delete[] x;
		x = NULL;
		if(osinstance->getConstraintNumber()) delete[] y;
		y = NULL;
		delete[] z;	
		z = NULL;
		if(osinstance->getVariableNumber() > 0) delete[] rcost;
		return true;
	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ;
	}
} // end optimize

std::string CoinSolver::getCoinSolverType(std::string osol){
// this is deprecated, but keep it around
	try{
		if( osol.find( "clp") != std::string::npos){
			return "coin_solver_glpk";
		}
		else{
			if( osol.find( "cbc") != std::string::npos){
				return "coin_solver_cpx";
			}
			else{
				if( osol.find( "cpx") != std::string::npos){
					return "coin_solver_clp";
				}
				else{
					if(osol.find( "glpk") != std::string::npos){
						return "";
					}
					else throw ErrorClass("a supported solver was not defined");
				}
			}
		}
	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ;
	}
} // end getCoinSolverType

void CoinSolver::dataEchoCheck(){
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
	if(m_CoinPackedMatrix != NULL) m_CoinPackedMatrix->dumpMatrix();
} // end dataEchoCheck





