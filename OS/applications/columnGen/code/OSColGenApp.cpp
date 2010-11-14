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
	  m_osoption = osoption;
	  m_osrouteSolver = new OSRouteSolver( m_osoption);
	  getOptions( m_osoption);
	  

} //end OSColGenApp Constructor


OSColGenApp::~OSColGenApp(){
	
	std::cout << "INSIDE ~OSColGenApp DESTRUCTOR" << std::endl;

	if( m_osinstanceMaster != NULL) delete  m_osinstanceMaster;

	if( m_osrouteSolver != NULL) delete  m_osrouteSolver;

}//end ~OSColGenApp() destructor


void OSColGenApp::getInitialRestrictedMaster( ){

	m_osinstanceMaster = m_osrouteSolver->getInitialRestrictedMaster( );
	//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
	
}//end generateInitialRestrictedMaster


void OSColGenApp::getCuts(const  double* x) {
	
	
}//end generateCuts

void OSColGenApp::getColumns(const  double* yA, const int numARows,
		const  double* yB, const int numBRows,
		int &numNewColumns, int* numNonz, double* cost, 
		int** rowIdx, double** values, double &lowerBound) 
 {


	m_osrouteSolver->getColumns(yA, numARows,
			yB, numBRows,
			numNewColumns, numNonz, cost, 
			rowIdx, values,  lowerBound);
	
	
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
	int j;
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
	
	
	
	int numNewColumns;
	int* numNonz = NULL;
	double* cost = NULL; 
	int** rowIdx = NULL; 
	double** values = NULL ; 
	double lowerBound;
	double collb;
	double colub;
	collb = 0.0;
	colub = 1.0;
	
	
	double rowlb;
	rowlb = 0.0;
	double rowub;
	int numRowEls;
	int tmpKount;

	int* cutColIndexes;
	double* cutColValues;
	int* tmpScatterArray;
	int scatterArraySize;
	scatterArraySize = m_osrouteSolver->m_numNodes*(m_osrouteSolver->m_numNodes - 1);
	//kippster -- make this dimension a parameter
	cutColIndexes = new int[ 100000];
	cutColValues = new double [ 100000];
	tmpScatterArray = new int[ scatterArraySize ];
	//zero out the scatter array
	
	for(i = 0; i < scatterArraySize; i++){
		
		tmpScatterArray[ i] = 0;
		
	}
	
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
			
			
			while(lowerBound < -.01 && loopKount < 10000){
				loopKount++;
				
				//kipp here is where the while loop goes
				//start while loop
				getColumns(yA, numARows, yB, numBRows,
						numNewColumns, numNonz, 
						cost,  rowIdx, values,  lowerBound);
				
				std::cout << "LOWER BOUND = " <<  lowerBound   << std::endl;
				
				//kipp -- get rid of the variables below
				numNonz = m_osrouteSolver->m_nonzVec; 
				cost =  m_osrouteSolver->m_costVec; 
				rowIdx = m_osrouteSolver->m_newColumnRowIdx; 
				values = m_osrouteSolver->m_newColumnRowValue;
				//add columns
				
				for(k = 0; k < numNewColumns; k++){
					
					si->addCol(numNonz[ k], rowIdx[k], values[k],
							collb, colub,   cost[ k]) ;			
					
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
	
			
			numRowEls = 0;
			
			if(m_osrouteSolver->getCuts( theta,  numCols ) == true){
				
				isCutAdded = true;
				
				rowub = m_osrouteSolver->m_BmatrixRhs[ m_osrouteSolver->m_numTourBreakCon  - 1];
				
		
				//scatter the constraint in the x - variables
				
				for(i = m_osrouteSolver->m_pntBmatrix[  m_osrouteSolver->m_numTourBreakCon  - 2] ; 
						i <  m_osrouteSolver->m_pntBmatrix[  m_osrouteSolver->m_numTourBreakCon  - 1] ; i++){
					
					tmpScatterArray[ m_osrouteSolver->m_Bmatrix[ i] ] = 1;
					
					
					
				}
	
				for(i = 0; i < m_osrouteSolver->m_numThetaVar - 1; i++){
					
					//get the xij indexes in this colum 
					tmpKount = 0;
					for(j = m_osrouteSolver->m_thetaPnt[i]; j < m_osrouteSolver->m_thetaPnt[i + 1] ;  j++){
						
						if(tmpScatterArray[ m_osrouteSolver->m_thetaIndex[ j] ] > 0 ){ //count number of xij for theta_i
							
							tmpKount++;
							
						}
						
					}//end loop on j
					
					if(tmpKount > 0){
						//theta_i has a nonzero coefficient in this row
						cutColIndexes[ numRowEls] = i;
						cutColValues[ numRowEls++] = tmpKount;
						
						//std::cout << " INDEX = " << i <<  " VALUE = " << tmpKount << std::endl;
						
					}
					
				}//end loop on i
				
	
				si->addRow(numRowEls, cutColIndexes, cutColValues, rowlb, rowub ) ;	
								
				//zero out the scatter array again
				
				for(i = m_osrouteSolver->m_pntBmatrix[  m_osrouteSolver->m_numTourBreakCon  - 2] ; 
						i <  m_osrouteSolver->m_pntBmatrix[  m_osrouteSolver->m_numTourBreakCon  - 1] ; i++){
					
					tmpScatterArray[ m_osrouteSolver->m_Bmatrix[ i] ] = 0;
					
				}	
				
				
				std::cout << std::endl;
				std::cout << "CUTS WERE ADDED CALL SOLVE" << std::endl;
				solver->solve();
				
			} // end if on whether or not we added cuts
			


		
		}//end while on isCutAdded

		for(i=0; i < numCols; i++){
			*(theta + i) = si->getColSolution()[i];
		}

		m_osrouteSolver->pauHana( theta);
		std::cout << "NUMBER OF ROWS =  " << si->getNumRows() << std::endl;
		
		
		//solve as an integer program
		
		for(i=0; i < numCols; i++){
			solver->osiSolver->setInteger( i);
		}
		
		
		solver->osiSolver->branchAndBound();
		
		for(i=0; i < numCols; i++){
			if( si->getColSolution()[i] > 0)
			std::cout <<  si->getColSolution()[i] << std::endl;
		}
	
		delete[] yA;
		yA = NULL;
		
		delete[] yB;
		yB = NULL;
		
		if(numCols > 0) delete[] theta;
		theta = NULL;
		
		
		delete[]  cutColIndexes;
		cutColIndexes = NULL;
		
		delete[]  cutColValues;
		cutColValues = NULL;
		
		delete[]  tmpScatterArray;
		tmpScatterArray = NULL;
		
		
		delete solver;
	

		
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
	
}// end solveRelaxation



