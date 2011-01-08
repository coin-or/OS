/* $Id: OSColGenApp.cpp 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSColGenApp.cpp
 * 
 * \remarks
 * Copyright (C) 2005-2010, Horand Gassmann, Jun Ma, Kipp Martin,
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




#include<vector>
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
	  //get parameters-options
	  m_osoption = osoption;
	  //get the options for the OSDecompSolver
	  getOptions( m_osoption);
	  
	  
	  m_osinstanceMaster = NULL;
	  m_osrouteSolver = NULL;
	  m_osrouteSolver = new OSRouteSolver( osoption);
	  //share the common parameters
	  m_osrouteSolver->m_osDecompParam = m_osDecompParam;
	  m_osrouteSolver->initializeDataStructures();
	  
	  //initialize the bounds
	  m_zUB = OSDBL_MAX;
	  m_zLB = -OSDBL_MAX;
	    


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
	
	//exit( 1);
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

		std::vector<SolverOption*> solverOptions;
		std::vector<SolverOption*>::iterator vit;
		
		solverOptions = osoption->getSolverOptions("OSDecompSolver");
		if (solverOptions.size() == 0) throw ErrorClass( "options for OSDecompSolver not available");
		
		
		for (vit = solverOptions.begin(); vit != solverOptions.end(); vit++) {
			
			if((*vit)->name.find("columnLimit") !=  std::string::npos){
				
				
				std::istringstream columnLimitBuffer( (*vit)->value);
				columnLimitBuffer >> m_osDecompParam.columnLimit;
				std::cout << "columnLimit = " <<  m_osDecompParam.columnLimit <<  std::endl;
				
			}else{
				
				if( (*vit)->name.find("artVarCoeff") !=  std::string::npos ){
					
					std::istringstream artVarCoeffBuffer( (*vit)->value);
					artVarCoeffBuffer >> m_osDecompParam.artVarCoeff;
					std::cout << "artVarCoeff = " <<  m_osDecompParam.artVarCoeff <<  std::endl;
					
				}else{
					
					if( (*vit)->name.find("zeroTol") !=  std::string::npos){
						
						std::istringstream zeroTolBuffer( (*vit)->value);
						zeroTolBuffer >> m_osDecompParam.zeroTol;
						std::cout << "zeroTol = " <<  m_osDecompParam.zeroTol <<  std::endl;
						
					}
				}
			}
			
			
		}
	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
}//end getOptions


void OSColGenApp::solve(){

	std::set<std::pair<int, double> >::iterator sit;	
	
	
	int numCols;
	int i;

	//initialize upper bound
	m_zUB = m_osrouteSolver->m_bestIPValue;
	
	std::cout << " m_zUB  " << m_zUB  << std::endl;
	
	try{
		  
		// the solver
		  
		m_solver = new CoinSolver();
		
		// the solver interface
		
		//kipp -- later have clp be an option
		//I guess for now it must be an Osi solver
		m_solver->sSolverName ="cbc";
		//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
		m_solver->osinstance = m_osinstanceMaster;
		
		//pass options
		m_solver->osoption = m_osoption;	
		m_solver->buildSolverInstance();

		
		//get the solver interface
		m_si = m_solver->osiSolver;
		
		m_yA = new double[m_osinstanceMaster->getConstraintNumber() ];
		//kipp -- hard coding, come back and fix with option
		//kipp -- do all of the newing in a separate routine
		m_yB = new double[  m_osrouteSolver->m_maxBmatrixCon];
		
		//kipp again hard coding -- remove later
		m_maxCols = m_osrouteSolver->m_maxMasterColumns;
		m_theta = new double[ m_maxCols];
		
		
		//get initial LP relaxation of master
		solveRestrictedMasterRelaxation();
		m_zLB =  m_si->getObjValue();
		
		

		//now get the upper bound
		//solve as an integer program to get initial upper bound
		
		for ( sit = m_osrouteSolver->intVarSet.begin() ; 
				sit != m_osrouteSolver->intVarSet.end(); sit++ ){
			
			m_si->setInteger( sit->first);
			
			
		}
		
		
		CbcModel model(  *m_si);
		OsiSolverInterface *ipSolver = model.solver();
		
		ipSolver->branchAndBound();
		//CbcMain0(  model);	
		//CbcMain1( 0, 0, model);
		//kipp -- put in check to make sure we get an integer solution
		if( ipSolver->getObjValue() < m_zUB) m_zUB = ipSolver->getObjValue() ;
		
		//get the solution
		numCols = m_si->getNumCols();
		
		for(i = 0; i < numCols; i++){	
			//get the LP relaxation
			
			*(m_theta + i) = model.getColSolution()[i];	
			
			if( *(m_theta + i) > m_osDecompParam.zeroTol){
				
				m_zOptIndexes.push_back( i) ;
				
				std::cout << "GAIL PUSHING BACK VALUE " << *(m_theta + i) << std::endl;
				std::cout << "GAIL PUSHING BACK INDEX " << i << std::endl;

			}
			
		}

		for ( sit = m_osrouteSolver->intVarSet.begin() ; 
				sit != m_osrouteSolver->intVarSet.end(); sit++ ){
			
			m_si->setContinuous( sit->first);
			m_si->setColUpper( sit->first, sit->second);
			
		}
		

		
		std::cout << "OPTIMAL LP VALUE = " << m_zLB << std::endl;
		std::cout << "CURRENT BEST IP VALUE = " << m_zUB << std::endl;
		//go into branch and bound
		branchAndBound();
		
		m_osrouteSolver->m_bestLPValue = m_zLB;
		m_osrouteSolver->m_bestIPValue = m_zUB;
		
		m_osrouteSolver->pauHana( m_zOptIndexes);
		
		
		
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
	//double bigM = 1.0e24;
	double bigM  = m_osDecompParam.artVarCoeff;
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
		
		
		isCutAdded = true;
		
		while(isCutAdded == true ){
			
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
			
			//////////////////////
			while(lowerBound < -m_osDecompParam.zeroTol && loopKount < m_osDecompParam.columnLimit){
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
			
				std::cout << " OBJ VALUE = " << m_si->getObjValue() << std::endl;
				
				std::cout << "m_zUB  = " <<  m_zUB << std::endl;
				
				if(lowerBound + m_si->getObjValue() > m_zUB) break;
			
				std::cout << std::endl  << std::endl << std::endl;
				std::cout << "CALL Solve  " << std::endl;
				m_solver->solve();
				std::cout << "Solution Status =  " << m_solver->osresult->getSolutionStatusType( 0 ) << std::endl;
				std::cout << "Number of solver interface columns =  " <<  m_si->getNumCols()  << std::endl;
				//m_numNodes is number of artificial variables
				
				numCols = m_si->getNumCols();
				
				if( numCols != m_osrouteSolver->m_numThetaVar ) throw ErrorClass("number variables in solver not consistent with master");
				if( numCols + m_osrouteSolver->m_numHubs >= m_maxCols) throw ErrorClass("we ran out of columns");
				
				for(i = 0; i <  numARows; i++){
					
					*(m_yA + i) = m_si->getRowPrice()[ i];
					
				}
							
				for(i = numARows; i <  numARows + numBRows; i++){
					
					*(m_yB + i - numARows) = m_si->getRowPrice()[ i];
					
				}
				
			}//end while on column generation
			//////////////////////////////////
			
			if( loopKount >=  m_osDecompParam.columnLimit)throw ErrorClass("we exceeded loop kount in column generation");
			
			//get a primal solution
			numCols = m_si->getNumCols();
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
					//m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, bigM, bigM);
					m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1, bigM);
					//add the artificial variable for the LB					
					rowArtVal = 1.0;
					
					//m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, bigM, bigM);
					m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1, bigM);
							
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
	isInt = true;
	int i;
	
	try{	
		
		for(i = 0; i < numThetaVar; i++){
			
			if( (thetaVar[ i] > tol) && (thetaVar[ i] < 1 -  tol) ){
				
				isInt = false;
				break;
			}
			
		}
		
		return isInt;
		
	} catch (const ErrorClass& eclass) {
	
		throw ErrorClass(eclass.errormsg);
	
	}		

	
	
}//end isInteger


void OSColGenApp::printDebugInfo( ){
	
	int numCols;
	int numRows;
	std::set<std::pair<int, double> >::iterator sit;
	int i;
	
	numCols = m_si->getNumCols();	
	
	
	for(i = 0;  i < numCols; i++){
		
		std::cout << "PROCESSING THETA COLUMN " << i <<  "  value =  " <<  m_si->getColSolution()[i] << std::endl;
		
		for(int j = m_osrouteSolver->m_thetaPnt[ i]; j <  m_osrouteSolver->m_thetaPnt[ i + 1]; j++ ){
			
			//std::cout << m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[ j] ] << std::endl;
			
		}
	}

	numRows = m_si->getNumRows();
	
	for(i = m_osrouteSolver->m_numNodes;  i < numRows; i++){
		
		std::cout << "PROCESSING ROW " << i  << std::endl;
		
		for(int j = m_osrouteSolver->m_pntBmatrix[ i  -   m_osrouteSolver->m_numNodes]; j <  m_osrouteSolver->m_pntBmatrix[ i + 1 -  m_osrouteSolver->m_numNodes]; j++ ){
			
			//std::cout << m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_Bmatrix[ j] ] << std::endl;
			
		}
	}
	//check integer variables and upper bounds -- loop over integer variable set

	//
	for ( sit = m_osrouteSolver->intVarSet.begin() ; 
			sit != m_osrouteSolver->intVarSet.end(); sit++ ){
		
		//std::cout << "Integer variable  " << sit->first << " Upper Bound = "  << sit->second  << std::endl;	
		
	}	
}//end printDebugInfo


bool OSColGenApp::branchAndBound(){
	
	/** varConMap is a map that maps the index
	 * of an x_{ij} variable to the corresponding
	 * branching constraint number in the master
	 */
	std::map<int, int> varConMap;
	
	std::vector<OSNode*> nodeVec;
	std::vector<OSNode*>::iterator vit;
	
	std::map<int, OSNode*> nodeMap;
	std::map<int, OSNode*>::iterator mit;
	int bestNodeID;
	double bestNodeBound;

	
	OSNode *osnode = NULL;
	OSNode *osnodeLeftChild = NULL;
	OSNode *osnodeRightChild = NULL;
	
	int nodeLimit;
	bool bandbWorked;
	bandbWorked = true;
	int numCols;
	int i;
	int rowIdx;
	rowIdx = 0;
	
	bool leftNodeCreated = false;
	bool rightNodeCreated = false;
	
	int numNodesGenerated;
	numNodesGenerated = 0;
	
	try{
		
		//get the solution
		numCols = m_si->getNumCols();	
		
		for(i = 0; i < numCols; i++){	
			//get the LP relaxation
			*(m_theta + i) = m_si->getColSolution()[i];	
		}
		
		
		//create a branching cut 
		createBranchingCut(m_theta, numCols, varConMap, rowIdx);

		//// start left node ////
			
		osnodeLeftChild = createChild(osnode, varConMap, rowIdx, 1, 1);
		if(osnodeLeftChild != NULL){
			//finally set the nodeID
			//and record parent ID
			numNodesGenerated++;
			osnodeLeftChild->nodeID = numNodesGenerated;
			osnodeLeftChild->parentID = 0;
			//nodeVec.push_back( osnodeLeftChild);
			nodeMap.insert ( std::pair<int, OSNode*>(osnodeLeftChild->nodeID, osnodeLeftChild) );

		}
		
		//// end of left node ////
		
		//// start right node ////
		
		osnodeRightChild = createChild(osnode, varConMap, rowIdx, 0, 0);
		if(osnodeRightChild != NULL){
			//finally set the nodeID
			//and record parent ID
			numNodesGenerated++;
			osnodeRightChild->nodeID = numNodesGenerated;
			osnodeRightChild->parentID = 0;
			//nodeVec.push_back( osnodeRightChild);
			nodeMap.insert ( std::pair<int, OSNode*>(osnodeRightChild->nodeID, osnodeRightChild) );
		}
			
		//// end of right node ////
		
		// now loop
		//kipp -- make this an option
		nodeLimit = 250;
		std::cout << "ENTERING THE WHILE IN BRANCH AND BOUND" << std::endl;
		std::cout << "numNodesGenerated = " <<  numNodesGenerated  << std::endl;
		//while( (nodeVec.size() > 0) && (numNodesGenerated <= nodeLimit) ){
		while( (nodeMap.size() > 0) && (numNodesGenerated <= nodeLimit) ){
			
			leftNodeCreated = false;
			rightNodeCreated = false;
			//grab a node -- for now the last node, we do FIFO
			//osnode =  nodeVec.back();
			
			//let's loop and find node with the largest nodeID -- this will
			//corespond to fifo
			
			bestNodeID = 0;
			bestNodeBound = OSDBL_MAX;
			//mit->first is the the OSNode nodeID
			//mit->second is an OSNode
			for (mit = nodeMap.begin(); mit != nodeMap.end(); mit++ ){
				
				//FIFO criterions
				//if( mit->second->nodeID > bestNodeID) bestNodeID =  mit->second->nodeID;
				
				//Best Bound criterion
				if( mit->second->lpValue < bestNodeBound) {
					
					bestNodeBound = mit->second->lpValue;
					bestNodeID =  mit->first;
					//note same as:
					//bestNodeID =  mit->second->nodeID;
					
					
				}
				
			}

			//get the node
			mit = nodeMap.find( bestNodeID );
			if(mit == nodeMap.end() ) throw ErrorClass("a node selection problem in branch and bound");
			osnode = mit->second;
			
			if( osnode->lpValue < m_zUB - m_osDecompParam.zeroTol){
			
				
				//create a branching cut 
				createBranchingCut(osnode->thetaIdx, osnode->theta, osnode->thetaNumNonz, 
						varConMap, rowIdx);
				
				// create children
				//create the left node
				osnodeLeftChild = createChild(osnode, varConMap, rowIdx, 1, 1);
				if(osnodeLeftChild != NULL){
					//finally set the nodeID
					//and record parent ID
					numNodesGenerated++;
					osnodeLeftChild->nodeID = numNodesGenerated;
					osnodeLeftChild->parentID = osnode->nodeID;
					leftNodeCreated = true;
				}
				
				//create the right node
				osnodeRightChild = createChild(osnode, varConMap, rowIdx, 0, 0);
				if(osnodeRightChild != NULL){
					//finally set the nodeID
					//and record parent ID
					numNodesGenerated++;
					osnodeRightChild->nodeID = numNodesGenerated;
					osnodeRightChild->parentID = osnode->nodeID;
					rightNodeCreated = true;
				}
				
				
				//nodeVec.erase( nodeVec.end() - 1) ;
				nodeMap.erase( mit);
				delete osnode;
				
				//if( leftNodeCreated == true) nodeVec.push_back( osnodeLeftChild) ;
				//if( rightNodeCreated == true) nodeVec.push_back( osnodeRightChild) ;
				
				if( leftNodeCreated == true) 
					nodeMap.insert ( std::pair<int, OSNode*>(osnodeLeftChild->nodeID, osnodeLeftChild) ) ;
				
				if( rightNodeCreated == true) 
					nodeMap.insert ( std::pair<int, OSNode*>(osnodeRightChild->nodeID, osnodeRightChild) ) ;

				 
			}else{
				
				//fathom node by virtue of the upper bound
				std::cout << "FATHAM BY UPPER BOUND " << std::endl;
				//nodeVec.erase( nodeVec.end() - 1) ;
				nodeMap.erase( mit);
				delete osnode;

			}//end if on lp bound check
			
			//kipp -- critical reset upper and lower bounds 
			//kipp don't forget to erase the parent node
			
		}//end the while
		

		
		m_zLB = m_zUB;
		std::cout <<  std::endl << std::endl;
		//std::cout << "NUMBER OF REMAINING DANGLING NODES  = " << nodeVec.size() << std::endl;
		std::cout << "NUMBER OF REMAINING DANGLING NODES  = " << nodeMap.size() << std::endl;
		
		/*
		for ( vit = nodeVec.begin() ; 
				vit != nodeVec.end(); vit++ ){
			
			std::cout << "NODE ID VALUE = " << (*vit)->nodeID << " " ;
			std::cout << "  NODE LP VALUE = " << (*vit)->lpValue << std::endl;
			
			for(i = 0; i < (*vit)->rowIdxNumNonz; i++){
				
				std::cout << "CONSTRAINT =  " <<(*vit)->rowIdx[ i]  ;
				std::cout << "  CONSTRAINT LB = " << (*vit)->rowLB[ i]  ;
				std::cout << "  CONSTRAINT UB = " << (*vit)->rowUB[ i]  << std::endl;
			}
				
			if( (*vit)->lpValue < m_zLB) m_zLB = (*vit)->lpValue;
			delete *vit;
			
		}
		nodeVec.clear();
		*/
		
		
		
		
		for ( mit = nodeMap.begin() ; 
				mit != nodeMap.end(); mit++ ){
			
			std::cout << "NODE ID VALUE = " << mit->second->nodeID << " " ;
			std::cout << "  NODE LP VALUE = " << mit->second->lpValue << std::endl;
			
			for(i = 0; i < mit->second->rowIdxNumNonz; i++){
				
				std::cout << "CONSTRAINT =  " << mit->second->rowIdx[ i]  ;
				std::cout << "  CONSTRAINT LB = " <<  mit->second->rowLB[ i]  ;
				std::cout << "  CONSTRAINT UB = " <<  mit->second->rowUB[ i]  << std::endl;
			}
				
			if(  mit->second->lpValue < m_zLB) m_zLB =  mit->second->lpValue;
	
			
		}
		nodeMap.clear();
		
		//exit( 1);
	
		return bandbWorked;

	} catch (const ErrorClass& eclass) {
		
		throw ErrorClass(eclass.errormsg);

	}		

}// end branchAndBound

OSNode* OSColGenApp::createChild(const OSNode *osnodeParent, std::map<int, int> &varConMap,
		const int rowIdx, const double rowLB, const double rowUB){
	
	OSNode *osnodeChild;
	osnodeChild = NULL;


	
	std::map<int, int>::iterator mit;
	
	int i;
	int childRowIdxNumNonz;
	childRowIdxNumNonz = 0;
	
	int numCols;

	//we want to store the solution vector (theta space)
	//in sparse format
	int thetaNumNonz;

	
	try{

		if(osnodeParent != NULL) childRowIdxNumNonz = osnodeParent->rowIdxNumNonz + 1;
		else childRowIdxNumNonz = 1;
			
		//set upper and lower bounds correctly
		//set the parent values 
		if(osnodeParent != NULL){
			for(i = 0; i < osnodeParent->rowIdxNumNonz; i++){
				
				
				m_si->setRowLower( osnodeParent->rowIdx[ i], osnodeParent->rowLB[ i]);
				m_si->setRowUpper( osnodeParent->rowIdx[ i], osnodeParent->rowUB[ i]);
				
				
			}
		}
		//set the new value
		m_si->setRowLower( rowIdx, rowLB);
		m_si->setRowUpper( rowIdx, rowUB);
		//now solve
		
		//print out the restricted master

		//if(rowUB == 0) m_si->writeLp( "gailTest2" );
	
		//exit( 1);
		solveRestrictedMasterRelaxation();
		std::cout << std::endl << std::endl;
		std::cout << "FINISH SOLVING THE MASTER "  << std::endl;
		//now reset the upper and lower bound
		//set the parent values 
		if( osnodeParent != NULL){
			for(i = 0; i < osnodeParent->rowIdxNumNonz; i++){
				
				
				m_si->setRowLower( osnodeParent->rowIdx[ i], 0);
				m_si->setRowUpper( osnodeParent->rowIdx[ i], 1);
				
				
			}
		}
		//reset the new value
		m_si->setRowLower( rowIdx, 0);
		m_si->setRowUpper( rowIdx, 1);
		
		// let's try and fathom the node
		// if we are not as good a upper bound
		// we fathom, if we are integer we fathom
		std::cout << std::endl << std::endl;
		std::cout << "MESSAGE: START CREATION OF A CHILD NODE" << std::endl;
		std::cout << "LB " << rowLB  <<  " UB = " << rowUB << std::endl;
		std::cout << "MESSAGE: LP RELAXATION VALUE OF POTENTIAL CHILD NODE  " << m_si->getObjValue() << std::endl;
		if( m_si->getObjValue() < m_zUB - m_osDecompParam.zeroTol) {
			// okay cannot fathom based on bound try integrality
			std::cout << "MESSAGE: WE CANNOT FATHOM THE CHILD BASED ON UPPER BOUND " << std::endl;
			numCols = m_si->getNumCols();
			thetaNumNonz = 0;
			
			for(i = 0; i < numCols; i++){	
				//get the LP relaxation
				*(m_theta + i) = m_si->getColSolution()[i];	
				if( *(m_theta + i) > m_osDecompParam.zeroTol) thetaNumNonz++;
				
			}
			if( isInteger( m_theta, numCols, m_osDecompParam.zeroTol) == true){
				//fathom by integrality
				std::cout << "MESSAGE:  WE HAVE AN INTEGRALITY FATHOM " << m_zUB << std::endl;
				if( m_zUB > m_si->getObjValue() ){
					
					m_zUB = m_si->getObjValue() ;
					//clear out out solution vector
					if( m_zOptIndexes.size() > 0) m_zOptIndexes.clear();
					
					for(i = 0; i < numCols; i++){
						
						if( *(m_theta + i) > m_osDecompParam.zeroTol) m_zOptIndexes.push_back( i) ;
						
					}
				}
				
			}else{
				//create the child node
				std::cout << "MESSAGE:  WE ARE CREATING A CHILD NODE " << std::endl;
				osnodeChild = new OSNode(childRowIdxNumNonz,  thetaNumNonz );
				
				
				//now set bound arrays 
				if(osnodeParent == NULL){
					osnodeChild->rowIdx[ 0] = rowIdx;
					osnodeChild->rowLB[ 0] = rowLB;
					osnodeChild->rowUB[ 0] = rowUB;
				}else{
					//set old values
					for(i = 0; i < osnodeParent->rowIdxNumNonz; i++){
						
						osnodeChild->rowIdx[ i] = osnodeParent->rowIdx[ i];
						osnodeChild->rowLB[ i] = osnodeParent->rowLB[ i];
						osnodeChild->rowUB[ i] = osnodeParent->rowUB[ i];				
						
					}
					//set new value
					
					osnodeChild->rowIdx[ childRowIdxNumNonz - 1] = rowIdx;
					osnodeChild->rowLB[ childRowIdxNumNonz - 1 ] = rowLB;
					osnodeChild->rowUB[ childRowIdxNumNonz - 1 ] = rowUB;	
					
					
				}
				//set child lp value
				osnodeChild->lpValue = m_si->getObjValue();
				//set theta
				thetaNumNonz = 0;
				for(i = 0; i < numCols; i++){
					
					if( *(m_theta + i) > m_osDecompParam.zeroTol){
						
						osnodeChild->thetaIdx[ thetaNumNonz] = i;
						osnodeChild->theta[ thetaNumNonz] = *(m_theta + i);
						
						thetaNumNonz++;
						//std::cout <<  "x variables for column "  << i  << std::endl;
						//for(int j = m_osrouteSolver->m_thetaPnt[ i ];  j < m_osrouteSolver->m_thetaPnt[ i + 1] ;  j++){
						//	std::cout <<  m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[  j] ]  << " = "  <<  *(m_theta + i) << std::endl;	
						//}
					}
					
					
					
				}
			}//end else on isInteger
		}// end if on upper bound test

		std::cout << std::endl << std::endl;
		return osnodeChild;
	
	} catch (const ErrorClass& eclass) {
	

		throw ErrorClass(eclass.errormsg);

	}		
	
}//end createChild


void OSColGenApp::createBranchingCut(const int* thetaIdx, const double* theta, 
		const int numThetaVar, std::map<int, int> &varConMap, int &rowIdx){
	
	int varIdx;
	int numNonz;
	int* indexes;
	double* values;	
	

	
	
	//kipp -- I would like to use OSDBL_MAX but Clp likes this better
	//double bigM  = 1.0e24;
	double bigM  = m_osDecompParam.artVarCoeff;
	double rowArtVal ;
	
	std::map<int, int>::iterator mit;
	
	//get the branching cut information
	m_osrouteSolver->getBranchingCut(thetaIdx, theta, numThetaVar, 
			varConMap, varIdx, numNonz, indexes,  values);
		
	std::cout << "varIDX = " << varIdx << std::endl;
	std::cout << "numNonzz = " << numNonz << std::endl;	
	
	
	//for(int i = 0; i < numNonz; i++){
	//	std::cout <<  "x variables for column "  << indexes[i]  << std::endl;
	//	for(int j = m_osrouteSolver->m_thetaPnt[ indexes[ i] ];  j < m_osrouteSolver->m_thetaPnt[ indexes[ i] + 1] ;  j++){
	//		std::cout <<  m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[  j] ]  << " = "  << theta[ thetaNumNonz]  << std::endl;
	//	}	
	//}

	//if numNonz is greater than zero:
	// 1) add add new variable to map -- at this point varConMap is empty
	// 2) add constraint then add to the formulation
	// 3) add artificial variables
	
	if( numNonz >0){

		
		//add the row
		//make upper and lower bound 0 and 1 first 
		m_si->addRow(numNonz, indexes, values, 0, 1) ;
		
		//add the artificial variables
		//add the artificial variable for the UB					
		rowArtVal = -1.0;
		rowIdx = m_si->getNumRows() - 1;
		
		m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigM);
		//add the artificial variable for the LB					
		rowArtVal = 1.0;
		
		m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigM);
		
		
		//insert into map -- this is the first variable
		varConMap.insert ( std::pair<int,int>(varIdx , rowIdx) );
		
		
		
		
	} else{
		//the variable varIdx is in the map
		//get the constraint associated with this variable
		//throw and exception if varIdx not a key
	
		mit = varConMap.find( varIdx);
		if( mit == varConMap.end() ) throw ErrorClass("in branchAndBound getBranchingCut() returned inconsistent value for varIdx");
				else rowIdx = mit->second;


	}//end if on numNonz
	
	
	
}//end createBranchingCut Sparse



void OSColGenApp::createBranchingCut(const double* theta, 
		const int numThetaVar, std::map<int, int> &varConMap, int &rowIdx){
	
	int varIdx;
	int numNonz;
	int* indexes;
	double* values;	
	
	//kipp -- I would like to use OSDBL_MAX but Clp likes this better
	//double bigM  = 1.0e24;
	double bigM  = m_osDecompParam.artVarCoeff;
	double rowArtVal ;
	
	std::map<int, int>::iterator mit;
	
	//get the branching cut information
	m_osrouteSolver->getBranchingCut( theta, numThetaVar, 
			varConMap, varIdx, numNonz, indexes,  values);
		
	std::cout << "varIDX = " << varIdx << std::endl;
	std::cout << "numNonzz = " << numNonz << std::endl;	
	
	
	//for(int i = 0; i < numNonz; i++){
	//	std::cout <<  "x variables for column "  << indexes[i]  << std::endl;
	//	for(int j = m_osrouteSolver->m_thetaPnt[ indexes[ i] ];  j < m_osrouteSolver->m_thetaPnt[ indexes[ i] + 1] ;  j++){
	//		std::cout <<  m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[  j] ]  << " = "  << theta[ thetaNumNonz]  << std::endl;
	//	}	
	//}

	//if numNonz is greater than zero:
	// 1) add add new variable to map -- at this point varConMap is empty
	// 2) add constraint then add to the formulation
	// 3) add artificial variables
	
	if( numNonz >0){

		
		//add the row
		//make upper and lower bound 0 and 1 first 
		m_si->addRow(numNonz, indexes, values, 0, 1) ;
		
		//add the artificial variables
		//add the artificial variable for the UB					
		rowArtVal = -1.0;
		rowIdx = m_si->getNumRows() - 1;
		
		m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigM);
		//add the artificial variable for the LB					
		rowArtVal = 1.0;
		
		m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigM);
		
		
		//insert into map -- this is the first variable
		varConMap.insert ( std::pair<int,int>(varIdx , rowIdx) );
		
		
		
		
	} else{
		//the variable varIdx is in the map
		//get the constraint associated with this variable
		//throw and exception if varIdx not a key
	
		mit = varConMap.find( varIdx);
		if( mit == varConMap.end() ) throw ErrorClass("in branchAndBound getBranchingCut() returned inconsistent value for varIdx");
				else rowIdx = mit->second;


	}//end if on numNonz
	
	
	
}//end createBranchingCut Dense







