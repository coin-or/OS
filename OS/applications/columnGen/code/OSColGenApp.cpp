/* $Id: OSColGenApp.cpp 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSColGenApp.cpp
 * 
 *
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 21/July/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Gus Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
#include "OSColGenApp.h"
#include "OSErrorClass.h" 
#include "OSDataStructures.h"

#include "OSConfig.h"
#include "OSResult.h" 
#include "OSOption.h"
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSoLReader.h"        
#include "OSoLWriter.h" 
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"  

#ifdef COIN_HAS_COUENNE    
#include "OSCouenneSolver.h"
#endif

#ifdef COIN_HAS_IPOPT    
#include "OSIpoptSolver.h"
#endif

#include<map>

#include <sstream>
using std::ostringstream;




OSColGenApp::OSColGenApp():
	m_osinstanceMaster(NULL) {
	std::cout << "INSIDE OSColGenApp CONSTRUCTOR" << std::endl;
	
}//end OSColGenApp Constructor


OSColGenApp::OSColGenApp(   OSOption *osoption) {
	  std::cout << "INSIDE OSColGenApp CONSTRUCTOR" << std::endl;
	  //std::cout << "the contructor things whichBlock = " << m_whichBlock<< std::endl;
	  m_osinstanceMaster = NULL;
	  m_osrouteSolver = NULL;
	
	  m_osrouteSolver = new OSRouteSolver( osoption);
	  m_osoption = osoption;
	  getOptions( m_osoption);
	  
	  //initialize the bounds
	  m_zUB = OSDBL_MAX;
	  m_zLB = -OSDBL_MAX;
	    
	  	  
	  //now the arrays

} //end OSColGenApp Constructor


OSColGenApp::~OSColGenApp(){
	
	std::cout << "INSIDE ~OSColGenApp DESTRUCTOR" << std::endl;

	//kipp -- why doesn't m_osrouteSolver delete the 
	//m_osinstanceMaster object
	
	if( m_osinstanceMaster != NULL) delete  m_osinstanceMaster;

	if( m_osrouteSolver != NULL) delete  m_osrouteSolver;

}//end ~OSColGenApp() destructor


void OSColGenApp::getInitialRestrictedMaster( ){

	m_osinstanceMaster = m_osrouteSolver->getInitialRestrictedMaster( );
	//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
	
}//end generateInitialRestrictedMaster


void OSColGenApp::getInitialRestrictedMaster2( ){

	m_osinstanceMaster = m_osrouteSolver->getInitialRestrictedMaster2( );
	//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
	
}//end generateInitialRestrictedMaster2


void OSColGenApp::getCuts(const  double* thetaVar, const int numThetaVar,
		int &numNewRows, int*  &numNonz, int** &colIdx,
		double** &values, double* &rowLB, double* &rowUB) {
	
	m_osrouteSolver->getCutsTheta( thetaVar, numThetaVar,
			numNewRows, numNonz, colIdx, values, rowLB, rowUB);
	
}//end getCuts


void OSColGenApp::getColumns(const  double* yA, const int numARows,
			const  double* yB, const int numBRows,
			int &numNewColumns, int* &numNonz, double* &cost, 
			int** &rowIdx, double** &values, double &lowerBound) {

	m_osrouteSolver->getColumns(yA, numARows,
			yB, numBRows, numNewColumns, numNonz, 
			cost, rowIdx, values,  lowerBound);
	

	
	
}//end generateColumns

void OSColGenApp::getOptions(OSOption *osoption) {
	
	
	//get any options relevant to OSColGenApp
	
	try{

	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
}//end getOptions


void OSColGenApp::solve(){
	
	/** varConMap is a map that maps the index
	 * of an x_{ij} variable to the corresponding
	 * branching constraint number in the master
	 */
	std::map<int, int> varConMap;
	
	int numCols;
	int numRows;
	int varIdx;
	int numNonz;
	int* indexes;
	double* values;	
	int i;
	

	//kipp -- I would like to use OSDBL_MAX but Clp likes this better
	//double bigNum  = 1.0e24;
	double bigNum  = 1000000;
	double rowArtVal ;
	int rowArtIdx ;
	
	try{
		  
		// the solver
		  
		m_solver = new CoinSolver();
		
		// the solver interface
		
		//kipp -- later have clp be an option
		//I guess for now it must be an Osi solver
		m_solver->sSolverName ="cbc";
		//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
		m_solver->osinstance = m_osinstanceMaster;
		m_solver->osoption = m_osoption;	
		m_solver->buildSolverInstance();

		
		//get the solver interface
		m_si = m_solver->osiSolver;
		
		m_yA = new double[m_osinstanceMaster->getConstraintNumber() ];
		//kipp -- hard coding, come back and fix with option
		//kipp -- do all of the newing in a separate routine
		m_yB = new double[ 10000];
		
		//kipp again hard coding -- remove later
		m_maxCols = 100000;
		m_theta = new double[ m_maxCols];
		
		
		//get initial LP relaxation of master
		solveRestrictedMasterRelaxation();
		//get the solution
		numCols = m_si->getNumCols();	
		
		for(i = 0; i < numCols; i++){	
			//get the LP relaxation
			*(m_theta + i) = m_si->getColSolution()[i];	
		}
		
		m_zLB =  m_si->getObjValue();
		
		std::cout << "OPTIMAL LP VALUE = " << m_zLB << std::endl;
		
		//now get the upper bound
		
		//solve as an integer program to get initial upper bound
		/*
		for(i=0; i < numCols; i++){
			
			m_solver->osiSolver->setInteger( i);
		}
		
		m_solver->osiSolver->branchAndBound();
		
		
		
		if(m_si->getObjValue() < m_zUB) m_zUB = m_si->getObjValue() ;
		
		
		
		std::cout << "OPTIMAL IP VALUE = " << m_zUB << std::endl;
		*/
		
		//kipp
		//kipp -- make variables continuous again		
		
		for(i=0; i < numCols; i++){
			
			m_solver->osiSolver->setContinuous( i);
		}
				
		
		
		m_osrouteSolver->getBranchingCut(m_theta, numCols, 
				varConMap, varIdx, numNonz, indexes,  values);
			
		std::cout << "varIDX = " << varIdx << std::endl;
		std::cout << "numNonz = " << numNonz << std::endl;			
		for(i = 0; i < numNonz; i++){
			
			std::cout <<  indexes[ i]  << "   "  << values[ i  ]  << std::endl;
		}
		//end temp test
		
		//if numNonz is greater than zero:
		// 1) add add new variable to map
		// 2) add constraint then add to the formulation
		// 3) add artificial variables
		
		if( numNonz >0){
			
			//insert into map
			varConMap.insert ( std::pair<int,int>(varIdx , m_si->getNumRows() + 1) );
			
			//add the row
			//make upper and lower bound 0 and 1 first 
			m_si->addRow(numNonz, indexes, values, 1, 1 ) ;
			
			//add the artificial variables
			
			//add the artificial variable for the UB					
			rowArtVal = -1.0;
			rowArtIdx = m_si->getNumRows() - 1;
			
			m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1.0, bigNum);
			//add the artificial variable for the LB					
			rowArtVal = 1.0;
			
			m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1.0, bigNum);			
			
		}
		
		m_si->writeLp("gailTest");
		
		
		//m_si->writeMps("gailMpsTest");
		//solve  LP relaxation of master again
		solveRestrictedMasterRelaxation();
		
		exit( 1);
		

		
		std::cout << "OPTIMAL LP VALUE = " << m_si->getObjValue() << std::endl;
		

		m_osrouteSolver->m_bestIPValue = m_zUB;
		m_osrouteSolver->pauHana( m_theta);
		
		
		
		delete m_solver;
		
		delete[] m_yA;
		m_yA = NULL;
		
		delete[] m_yB;
		m_yB = NULL;
		
		delete[] m_theta;
		m_theta = NULL;
	

	} catch (const ErrorClass& eclass) {
		
		delete m_solver;
		
		delete[] m_yA;
		m_yA = NULL;
		
		delete[] m_yB;
		m_yB = NULL;
		
		delete[] m_theta;
		m_theta = NULL;		

		throw ErrorClass(eclass.errormsg);

}
	
}//end solve


void OSColGenApp::solveRestrictedMasterRelaxation(){
	
	int i;
	int k;
	//we include convexity constraints in this number
	int numARows;
	// dimension y to number of nodes
	int numBRows;
	int numCols;
	
	//getColumns function call return parameters
	int numNewColumns;
	int* numNonz = NULL;
	double* cost = NULL; 
	int** rowIdx = NULL; 
	double** values = NULL ; 
	double lowerBound;
	//end of getColumns function call return parameters
	
	double collb; // kipp -- put in getColumns
	double colub; // kipp -- put in getColumns
	//all of our m_theta columns have a lower bound of 0 and upper bound of 1
	collb = 0.0;
	colub = 1.0;
	//kipp -- I would like to use OSDBL_MAX but Clp likes this better
	double bigNum = 1.0e24;
	
	//getRows function call return parameters
	int numNewRows;
	int* numRowNonz = NULL;
	int** colIdx = NULL; 
	double** rowValues = NULL ; 
	double* rowLB;
	double* rowUB;
	//end of getRows function call return parameters	
	//art variables

	int rowArtIdx;
	double rowArtVal;
	
	bool isCutAdded;

	try{
		numARows = m_osrouteSolver->m_numNodes;
		


		//get the dual solution 
		
		isCutAdded = true;
		
		while(isCutAdded == true && m_osrouteSolver->m_numBmatrixCon <= 100){
			
			isCutAdded = false;
			//start out loop on if cuts found
			std::cout << "CALL Solve  " << std::endl;
			m_solver->solve();
			std::cout << "Solution Status =  " << m_solver->osresult->getSolutionStatusType( 0 ) << std::endl;
			//std::cout <<  m_solver->osrl << std::endl;
	
			if(m_si->getNumRows() != numARows + m_osrouteSolver->m_numBmatrixCon ) {
				std::cout << "m_si->getNumRows() = " << m_si->getNumRows() << std::endl;
				std::cout << "numARows = " << numARows << std::endl;
				std::cout << "m_numBmatrixCon = " << m_osrouteSolver->m_numBmatrixCon << std::endl;
				throw ErrorClass("detect a row number inconsistency in solveRestrictedMasterRelaxation");
			}
			
			
			
			if(m_si->getRowPrice() == NULL  ) 
				throw ErrorClass("problem getting dual values in solveRestrictedMasterRelaxation");
			
			
			numBRows = m_osrouteSolver->m_numBmatrixCon;
			
			for(i = 0; i <  numARows; i++){
				
				*(m_yA + i) = m_si->getRowPrice()[ i];
				
			}
			
			for(i = numARows; i <  numARows + numBRows; i++){
				
				*(m_yB + i - numARows) = m_si->getRowPrice()[ i];
				
			}
			
			lowerBound = -1;
			int loopKount = 0;
			
			//kipp -- hard coding in the .0001  and loopKount
			while(lowerBound < -.0001 && loopKount < 10000){
				loopKount++;
				
				//kipp here is where the while loop goes
				//start while loop
				getColumns(m_yA, numARows, m_yB, numBRows, numNewColumns, 
						numNonz, cost,  rowIdx, values,  lowerBound);
				
				std::cout << "Lower Bound = " <<  lowerBound   << std::endl;
			
				for(k = 0; k < numNewColumns; k++){
					
					m_si->addCol( numNonz[ k], rowIdx[k], values[k],
							collb, colub,  cost[ k]) ;	
					
				}
			
				std::cout << std::endl  << std::endl << std::endl;
				std::cout << "CALL Solve  " << std::endl;
				m_solver->solve();
				std::cout << "Solution Status =  " << m_solver->osresult->getSolutionStatusType( 0 ) << std::endl;
				std::cout << "Number of solver interface columns =  " <<  m_si->getNumCols()  << std::endl;
				//m_numNodes is number of artificial variables
				if(m_si->getNumCols() != m_osrouteSolver->m_numThetaVar ) throw ErrorClass("number variables in solver not consistent with master");
				
				for(i = 0; i <  numARows; i++){
					
					*(m_yA + i) = m_si->getRowPrice()[ i];
					
				}
							
				for(i = numARows; i <  numARows + numBRows; i++){
					
					*(m_yB + i - numARows) = m_si->getRowPrice()[ i];
					
				}
				
			}//end while on column generation
			
			//get a primal solution
			numCols = m_si->getNumCols();
			if(numCols + m_osrouteSolver->m_numHubs >= m_maxCols) throw ErrorClass("we ran out of columns");
			
			for(i=0; i < numCols; i++){
				*(m_theta + i) = m_si->getColSolution()[i];
			}
	
			
			numNewRows = 0;
			
			//do not get cuts if LP relaxation worse than upper bound
			if(m_si->getObjValue() < m_zUB) getCuts(m_theta, numCols, numNewRows, numRowNonz, 
					colIdx,rowValues, rowLB, rowUB);
		
			
			if( numNewRows >= 1 ){
				
				isCutAdded = true;
				
				for(i = 0; i < numNewRows; i++){
					
					m_si->addRow(numRowNonz[ i], colIdx[ i], rowValues[ i], rowLB[ i], rowUB[ i] ) ;
					
					//add two artificial variables for this row so we can never be infeasible
					//m_si->addCol( numNonz, rowIdx[k], values[k],
					//		collb, colub,  cost[ k]) ;
					
					//add the artificial variable for the UB					
					rowArtVal = -1.0;
					rowArtIdx = m_si->getNumRows() - 1;
					m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, bigNum, bigNum);
					//add the artificial variable for the LB					
					rowArtVal = 1.0;
					
					m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, bigNum, bigNum);
							
				}
				
				std::cout << std::endl;
				std::cout << "CUTS WERE ADDED CALL SOLVE" << std::endl;
				m_solver->solve();
				
			} // end if on whether or not we added cuts
			


		
		}//end while on isCutAdded

		
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
	
}//end solveRestrictedMasterRelaxation


bool OSColGenApp::isInteger( const double *thetaVar, const int numThetaVar, 
		const double tol){
	
	
	bool isInt;
	isInt = false;
	
	try{	
		
		return isInt;
		
	} catch (const ErrorClass& eclass) {
	
		throw ErrorClass(eclass.errormsg);
	
	}		

	
	
}//end isInteger



