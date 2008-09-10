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


#define DEBUG

#include "OSCoinSolver.h"
#include "OSInstance.h"
#include "OSFileUtil.h"
#include "CglPreProcess.hpp"
#include "CglGomory.hpp"
#include "CglSimpleRounding.hpp"
#include "CglMixedIntegerRounding2.hpp"
#include "CglKnapsackCover.hpp"
#include "CglFlowCover.hpp"


#include "OSDataStructures.h"
#include "OSParameters.h" 
#include "OSCommonUtil.h"
#include "OSMathUtil.h"
  
#include <iostream>
#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif 
using std::cout; 
using std::endl; 
using std::ostringstream;


CoinSolver::CoinSolver() : 
osiSolver(NULL),
m_osilreader(NULL),
m_CoinPackedMatrix(NULL)
{
osrlwriter = new OSrLWriter();
}

CoinSolver::~CoinSolver() {
	#ifdef DEBUG
	cout << "inside CoinSolver destructor" << endl;
	#endif
	cout << "inside CoinSolver destructor" << endl;
	if(m_osilreader != NULL) delete m_osilreader;
	m_osilreader = NULL;
	delete m_CoinPackedMatrix;
	m_CoinPackedMatrix = NULL;
	delete osiSolver;
	if(osiSolver != NULL) osiSolver = NULL;
	delete osrlwriter;
	osrlwriter = NULL;
	delete osresult;
	osresult = NULL;
	cout << "leaving CoinSolver destructor" << endl;
}


void CoinSolver::buildSolverInstance() throw (ErrorClass) {
	try{
		osresult = new OSResult();
			if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
			clock_t start, finish;
			double duration;
			start = clock();
			if(osinstance == NULL){
				m_osilreader = new OSiLReader();
				osinstance = m_osilreader->readOSiL( osil);
			}
					finish = clock();
			duration = (double) (finish - start) / CLOCKS_PER_SEC;
			cout << "Parsing took (seconds): "<< duration << endl;
				cout << "Start Solve with a Coin Solver" << endl;
			// get the type of solver requested from OSoL string
			bool solverIsDefined = false;
			std::cout << "SOLVER NAME =  " << sSolverName << std::endl;
			if( sSolverName.find("clp") != std::string::npos){
				solverIsDefined = true;
				osiSolver = new OsiClpSolverInterface();
			}
			else{
				if( sSolverName.find("vol") != std::string::npos){
	             #ifdef COIN_HAS_VOL
					solverIsDefined = true;
					osiSolver = new OsiVolSolverInterface();
	             #endif
				}
				else{
					if( sSolverName.find( "cplex") != std::string::npos){
						#ifdef COIN_HAS_CPX
						solverIsDefined = true;
						osiSolver = new OsiCpxSolverInterface();
						#endif
					}
					else{
						if(sSolverName.find( "glpk") != std::string::npos){
							#ifdef COIN_HAS_GLPK
							solverIsDefined = true;
							osiSolver = new OsiGlpkSolverInterface();
							#endif
						}
						else{
							if(sSolverName.find( "dylp") != std::string::npos){
								#ifdef COIN_HAS_DYLP
								solverIsDefined = true;
								osiSolver = new OsiDylpSolverInterface();
								#endif
							}
							else{
								if( sSolverName.find( "symphony") != std::string::npos) {
									#ifdef COIN_HAS_SYMPHONY
									solverIsDefined = true;
									osiSolver = new OsiSymSolverInterface();
									#endif
								}
								else{
									// default solver is CBC
									solverIsDefined = true;
									osiSolver = new OsiCbcSolverInterface();
								}
							}
						}
					}
				}
			}
			//
			//
			if(solverIsDefined == false) throw ErrorClass("a supported solver was not defined");
			if(osinstance->getConstraintNumber() <= 0)throw ErrorClass("Coin solver Needs Constraints");
			if(osinstance->getVariableNumber() <= 0)throw ErrorClass("Coin solver requires decision variables");
			if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Coin solver needs an objective function");
			if(osinstance->getLinearConstraintCoefficientNumber() <= 0) throw ErrorClass("Coin solver needs linear constraints");
			if(!setCoinPackedMatrix() ) throw ErrorClass("Problem generating coin packed matrix");
			osiSolver->loadProblem(*m_CoinPackedMatrix, osinstance->getVariableLowerBounds(), 
				osinstance->getVariableUpperBounds(),  
				osinstance->getDenseObjectiveCoefficients()[0], 
				osinstance->getConstraintLowerBounds(), osinstance->getConstraintUpperBounds()
			);
			//dataEchoCheck();	
			if(osinstance->getObjectiveNumber() == 0) throw ErrorClass("there is no objective function");
			if( osinstance->getObjectiveMaxOrMins()[0] == "min") osiSolver->setObjSense(1.0);
			else osiSolver->setObjSense(-1.0);
			// set the integer variables
			int *intIndex = NULL;
			int i = 0;
			int k = 0;
			char *varType;
			int numOfIntVars = osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables();
			if(numOfIntVars > 0) {
				intIndex = new int[ numOfIntVars];
				varType = osinstance->getVariableTypes();
				for(i = 0; i < osinstance->getVariableNumber(); i++){
					if( (varType[i] == 'B') || (varType[i]) == 'I' ) {
						intIndex[k++] = i;
					}
				}
				osiSolver->setInteger( intIndex,  numOfIntVars);
			}
			if(numOfIntVars > 0){ 
				delete[] intIndex;
				intIndex = NULL;
			}
			bCallbuildSolverInstance = true;
	}
	catch(const ErrorClass& eclass){
		std::cout << "THERE IS AN ERROR" << std::endl;
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
	}				
}//end buildSolverInstance()


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

void CoinSolver::solve() throw (ErrorClass) {
	// make sure the solver instance exists
	if( this->bCallbuildSolverInstance == false) buildSolverInstance();
	// first check the various solvers and see if they are of the proper problem type
	if( osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0){
		// throw an exception if we have a solver that cannot do integer programming
		if( sSolverName.find("clp") != std::string::npos) throw ErrorClass( "Clp cannot do integer programming");
		if( sSolverName.find("vol") != std::string::npos) throw ErrorClass( "Vol cannot do integer programming");
		if( sSolverName.find("dylp") != std::string::npos) throw ErrorClass( "DyLP cannot do integer programming");
		if( sSolverName.find("ipopt") != std::string::npos) throw ErrorClass( "Ipopt cannot do integer programming");
	}
	if( (osinstance->getNumberOfNonlinearExpressions() > 0)
		|| (osinstance->getNumberOfQuadraticTerms() > 0) ){
		throw ErrorClass( "This COIN-OR Solver is not configured for nonlinear programming");
	}
	// if we are throw an exception if the problem is nonlinear
	double *x = NULL;
	double *y = NULL;
	double *z = NULL;
	int i = 0;
	std::string *rcost = NULL;
	// resultHeader infomration
	if(osresult->setServiceName("Solved with Coin Solver: " + sSolverName) != true)
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
	try{
		osiSolver->setDblParam(OsiObjOffset, osinstance->getObjectiveConstants()[0]);
		// set some OSI options
#ifdef COIN_HAS_SYMPHONY
		//first the number of processors -- applies only to SYMPHONY
		if( sSolverName.find( "symphony") != std::string::npos) {
			OsiSymSolverInterface * si =
			dynamic_cast<OsiSymSolverInterface *>(osiSolver) ;
			std::string num_proc = "";
			string::size_type pos1 = this->osol.find("num_proc"); 
			string::size_type pos2;
			if(pos1 != std::string::npos){
				// get the end of the other start element
				pos1 = osol.find(">", pos1 + 1);
				if(pos1 != std::string::npos){
					// get the start of other end tag
					pos2 = osol.find( "</other", pos1 + 1);
					if( pos2 != std::string::npos){
						// get the substring
						num_proc = osol.substr( pos1 + 1, pos2 - pos1 - 1); 
					}
				}
			}
			//pass the option on
			if(num_proc.size() > 0) si->setSymParam("max_active_nodes", num_proc);	
		}
#endif
		//
		//
		//
		// now some other Osi options
		osiSolver->setHintParam(OsiDoScale, false, OsiHintTry);
		osiSolver->setHintParam(OsiDoReducePrint, true, OsiHintTry);
		//OsiSolverInterface *m_OsiSolverPre = NULL;	
		// try to catch Coin Solver errors
		try{
			if( osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0){
				//cout << "CALL BRANCH AND BOUND " << endl;
				// just use simple branch and bound for anything but cbc
				if( sSolverName.find( "cbc") == std::string::npos) {
					osiSolver->branchAndBound();	
				}
				else{
					// this is Solver Cbc
					OsiSolverInterface *m_OsiSolverPre = NULL;
					// copy from John Forrest examples in Cbc
					CglPreProcess process;
	                /* Do not try and produce equality cliques and
	                   do up to 10 pass;es -- I use 10 because John does in Cbc and he is brilliant*/
					m_OsiSolverPre = process.preProcess(*osiSolver, false, 10);
	                if (!osiSolver) {
	                  throw ErrorClass("Pre-processing says infeasible");
	                } else {
	                	printf("processed model has %d rows and %d columns\n",
	                		m_OsiSolverPre->getNumRows(), m_OsiSolverPre->getNumCols());
	                } 
	               osiSolver->setHintParam( OsiDoScale, true, OsiHintDo) ;
	               
	               CbcModel model( *m_OsiSolverPre);
	       		   CglKnapsackCover cover;
				   CglFlowCover flowcover;
	       	       CglSimpleRounding round;  
	       	       CglMixedIntegerRounding2 roundmixed; 
	       		   CglGomory gomory;
	       		
	       	
	       		   model.addCutGenerator(&gomory, 1, "Gomory");
	       		   model.addCutGenerator(&cover, 1, "KnapsackCover");
				   model.addCutGenerator(&flowcover, 1, "FlowCover");
	       		   model.addCutGenerator(&round, 1, "Round");
	       		   model.addCutGenerator(&roundmixed, 1, "MixedRound");
	               model.setLogLevel( 1);
				   model.branchAndBound();
	               //osiSolver->messageHandler()->setLogLevel( 0) ;
	               //m_OsiSolverPre->branchAndBound( ); 
	               cout << "CALL POSTPROCESS " << endl;
	               //process.postProcess( *m_OsiSolverPre);
	               process.postProcess( *model.solver() );
	               cout << "DONE WITH CALL POSTROCESS " << endl;
				}
			}
			else{
				osiSolver->initialSolve();
			}
		}
		catch(CoinError e){
			std::string errmsg;
			errmsg = "Coin Solver Error: " + e.message() + "\n" + " see method "  
				+ e.methodName() + " in class " + e.className();
			throw ErrorClass( errmsg );
		}
		int solIdx = 0;
		std::string description = "";
		osresult->setGeneralStatusType("success");
		if (osiSolver->isProvenOptimal() == true){
			osresult->setSolutionStatus(solIdx, "optimal", description);
			/* Retrieve the solution */
			x = new double[osinstance->getVariableNumber() ];
			y = new double[osinstance->getConstraintNumber() ];
			z = new double[1];
			rcost = new std::string[ osinstance->getVariableNumber()];
			//
			*(z + 0)  =  osiSolver->getObjValue();
			osresult->setObjectiveValues(solIdx, z);
			for(i=0; i < osinstance->getVariableNumber(); i++){
				*(x + i) = osiSolver->getColSolution()[i];
			}
			osresult->setPrimalVariableValues(solIdx, x);
			// Symphony does not get dual prices
			if( sSolverName.find( "symphony") == std::string::npos && osinstance->getNumberOfIntegerVariables() == 0 && osinstance->getNumberOfBinaryVariables() == 0) {
				for(i=0; i <  osinstance->getConstraintNumber(); i++){
					*(y + i) = osiSolver->getRowPrice()[ i];
				}
				osresult->setDualVariableValues(solIdx, y);
			}
			//
			//
			// now put the reduced costs into the osrl
			// Symphony does not get reduced costs
			if( sSolverName.find( "symphony") == std::string::npos && osinstance->getNumberOfIntegerVariables() == 0 && osinstance->getNumberOfBinaryVariables() == 0){
				int numberOfOtherVariableResult = 1;
				int otherIdx = 0;
				// first set the number of Other Variable Results
				osresult->setNumberOfOtherVariableResult(solIdx, numberOfOtherVariableResult);
				ostringstream outStr;
				int numberOfVar =  osinstance->getVariableNumber();
				for(i=0; i < numberOfVar; i++){
					rcost[ i] = os_dtoa_format( osiSolver->getReducedCost()[ i]);
				}
				osresult->setAnOtherVariableResult(solIdx, otherIdx, "reduced costs", "the variable reduced costs", rcost);			
				// end of settiing reduced costs
			}					
		}
		else{ 
			if(osiSolver->isProvenPrimalInfeasible() == true) 
				osresult->setSolutionStatus(solIdx, "infeasible", description);
			else
				if(osiSolver->isProvenDualInfeasible() == true) 
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
		if(osinstance->getVariableNumber() > 0){
			delete[] rcost;
			rcost = NULL;
		}
		cout << "DONE WITH COIN SOLVER SOLVE" << endl;
	}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ;
	}
} // end solve

std::string CoinSolver::getCoinSolverType(std::string lcl_osol){
// this is deprecated, but keep it around
	try{
		if( lcl_osol.find( "clp") != std::string::npos){
			return "coin_solver_glpk";
		}
		else{
			if( lcl_osol.find( "cbc") != std::string::npos){
				return "coin_solver_cpx";
			}
			else{
				if( lcl_osol.find( "cpx") != std::string::npos){
					return "coin_solver_clp";
				}
				else{
					if(lcl_osol.find( "glpk") != std::string::npos){
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





