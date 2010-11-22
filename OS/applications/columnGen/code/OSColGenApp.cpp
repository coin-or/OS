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

#include "OSInstance.h"
#include "OSCoinSolver.h"
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


void OSColGenApp::solveRestrictedMasterRelaxation(){
	
	int i;
	int k;
	//we include convexity constraints in this number
	int numARows;
	// y holds the dual values for the coupling constraints
	double *yA = NULL;
	//kipp -- really dangerous what happens when we add rows to si, these don't get added to 
	//m_osinstanceMaster
	// dimension y to number of nodes
	yA = new double[m_osinstanceMaster->getConstraintNumber() ];
	
	//kipp -- hard coding, come back and fix with option
	double *yB = NULL;
	yB = new double[ 10000];
	int numBRows;
	
	int numCols;
	double* theta = NULL;
	//kipp again hard coding -- remove later
	int maxCols;
	maxCols = 100000;
	theta = new double[ maxCols];
	
	
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
	//all of our theta columns have a lower bound of 0 and upper bound of 1
	collb = 0.0;
	colub = 1.0;
	
	
	//getRows function call return parameters
	int numNewRows;
	int* numRowNonz = NULL;
	int** colIdx = NULL; 
	double** rowValues = NULL ; 
	double* rowLB;
	double* rowUB;
	//end of getRows function call return parameters	
	

	bool isCutAdded;

	try{
		numARows = m_osrouteSolver->m_numNodes;
		
		CoinSolver *solver = NULL;
		solver = new CoinSolver();
		//kipp -- later have clp be an option
		//I guess for now it must be an Osi solver
		solver->sSolverName ="cbc";
		//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
		solver->osinstance = m_osinstanceMaster;
		solver->osoption = m_osoption;	
		solver->buildSolverInstance();

		
		//get the solver interface
		OsiSolverInterface *si = solver->osiSolver;
		//get the dual solution 
		
		isCutAdded = true;
		
		while(isCutAdded == true && m_osrouteSolver->m_numTourBreakCon <= 100){
			
			isCutAdded = false;
			//start out loop on if cuts found
			std::cout << "CALL Solve  " << std::endl;
			solver->solve();
			std::cout << "Solution Status =  " << solver->osresult->getSolutionStatusType( 0 ) << std::endl;
			//std::cout <<  solver->osrl << std::endl;
	
			if(si->getNumRows() != numARows + m_osrouteSolver->m_numTourBreakCon - 1) {
				std::cout << "si->getNumRows() = " << si->getNumRows() << std::endl;
				std::cout << "numARows = " << numARows << std::endl;
				std::cout << "m_numTourBreakCon = " << m_osrouteSolver->m_numTourBreakCon << std::endl;
				throw ErrorClass("detect a row number inconsistency in solveRestrictedMasterRelaxation");
			}
			
			
			
			if(si->getRowPrice() == NULL  ) 
				throw ErrorClass("problem getting dual values in solveRestrictedMasterRelaxation");
			
			
			numBRows = m_osrouteSolver->m_numTourBreakCon;
			
			for(i = 0; i <  numARows; i++){
				
				*(yA + i) = si->getRowPrice()[ i];
				
			}
			
			for(i = numARows; i <  numARows + numBRows; i++){
				
				*(yB + i - numARows) = si->getRowPrice()[ i];
				
			}
			
			lowerBound = -1;
			int loopKount = 0;
			
			//kipp -- hard coding in the .0001
			while(lowerBound < -.0001 && loopKount < 10000){
				loopKount++;
				
				//kipp here is where the while loop goes
				//start while loop
				getColumns(yA, numARows, yB, numBRows,
						numNewColumns, numNonz, 
						cost,  rowIdx, values,  lowerBound);
				
				std::cout << "Lower Bound = " <<  lowerBound   << std::endl;
			
				for(k = 0; k < numNewColumns; k++){
					
					si->addCol( numNonz[ k], rowIdx[k], values[k],
							collb, colub,  cost[ k]) ;	
					
				}
			
				std::cout << std::endl  << std::endl << std::endl;
				std::cout << "CALL Solve  " << std::endl;
				solver->solve();
				std::cout << "Solution Status =  " << solver->osresult->getSolutionStatusType( 0 ) << std::endl;
				std::cout << "Number of solver interface columns =  " <<  si->getNumCols()  << std::endl;
				
				if(si->getNumCols() != m_osrouteSolver->m_numThetaVar - 1) throw ErrorClass("number variables in solver not consistent with master");
				
				for(i = 0; i <  numARows; i++){
					
					*(yA + i) = si->getRowPrice()[ i];
					
				}
				
				
				for(i = numARows; i <  numARows + numBRows; i++){
					
					*(yB + i - numARows) = si->getRowPrice()[ i];
					
				}
				
			}//end while on column generation
			
			//get a primal solution
			numCols = si->getNumCols();
			if(numCols + m_osrouteSolver->m_numHubs >= maxCols) throw ErrorClass("we ran out of columns");
			
			for(i=0; i < numCols; i++){
				*(theta + i) = si->getColSolution()[i];
			}
	
			
			numNewRows = 0;
			getCuts(theta, numCols, numNewRows, numRowNonz, 
					colIdx,rowValues, rowLB, rowUB);
			
			if( numNewRows >= 1 ){
				
				isCutAdded = true;
				
				for(i = 0; i < numNewRows; i++){
					
					si->addRow(numRowNonz[ i], colIdx[ i], rowValues[ i], rowLB[ i], rowUB[ i] ) ;
					
					
				}
				
				std::cout << std::endl;
				std::cout << "CUTS WERE ADDED CALL SOLVE" << std::endl;
				solver->solve();
				
			} // end if on whether or not we added cuts
			


		
		}//end while on isCutAdded

		for(i=0; i < numCols; i++){
			*(theta + i) = si->getColSolution()[i];
		}


		

		//solve as an integer program
		
		for(i=0; i < numCols; i++){
			solver->osiSolver->setInteger( i);
		}
		solver->osiSolver->branchAndBound();
		
		m_osrouteSolver->m_bestIPValue = si->getObjValue();
		
		m_osrouteSolver->pauHana( theta);
		
		//for(i=0; i < numCols; i++){
		//	if( si->getColSolution()[i] > 0)
		//	std::cout <<  si->getColSolution()[i] << std::endl;
		//}
	
		delete[] yA;
		yA = NULL;
		
		delete[] yB;
		yB = NULL;
		
		if(numCols > 0) delete[] theta;
		theta = NULL;
		
		
		delete solver;
		
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
	
}// end solveRelaxation



