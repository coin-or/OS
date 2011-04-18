/* $Id: OSBearcatSolverXij.cpp 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSBearcatSolverXij.cpp
 *
 * \remarks
 * Copyright (C) 2005-2010, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */


#include "OSBearcatSolverXij.h"

#include "OSErrorClass.h" 
#include "OSDataStructures.h"

#include "OSInstance.h"
#include "OSCoinSolver.h"
#include "OSConfig.h"
#include "OSResult.h" 

#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSoLReader.h"        
#include "OSoLWriter.h" 
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"  

#include "CoinTime.hpp"

#include "ClpFactorization.hpp"
#include "ClpNetworkMatrix.hpp"
#include "OsiClpSolverInterface.hpp"

#include <iostream>

#include <algorithm> 


#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
# else
#  error "don't have header file for math"
# endif
#endif

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif 

using std::ostringstream;

std::string makeStringFromInt(std::string theString, int theInt);


OSBearcatSolverXij::OSBearcatSolverXij() {
	std::cout << "INSIDE OSBearcatSolverXij CONSTRUCTOR with OSOption argument" << std::endl;
}//end default OSBearcatSolverXij constructor

OSBearcatSolverXij::OSBearcatSolverXij(OSOption *osoption) {
	std::cout << "INSIDE OSBearcatSolverXij CONSTRUCTOR with OSOption argument" << std::endl;
	
	
	m_bestIPValue = OSDBL_MAX;
	m_bestLPValue = -OSDBL_MAX;
	
	m_upperBoundL = NULL;
	m_upperBoundLMax = -OSINT_MAX;
	m_minDemand = OSINT_MAX;
	
	m_u = NULL;
	m_v = NULL;
	m_g = NULL;
	m_px = NULL;
	m_tx =NULL;
	m_varIdx = NULL;
	
	m_optL = NULL;
	m_optD = NULL;
	m_vv = NULL;
	m_vvpnt = NULL;
	
	m_demand = NULL;
	m_cost = NULL;
	
	m_rc = NULL;
	
	m_routeCapacity = NULL;
	m_routeMinPickup = NULL;
	
	m_osoption = osoption;
	
	m_multiCommodCutLimit = 50;
	m_numMultCuts = 0;
	

}//end OSBearcatSolverXijDestructor

void OSBearcatSolverXij::initializeDataStructures(){
	
	int k;
	int i;
	int l;
	int tmpVal;
	
	try{
		

		//get all the parameter values
		getOptions( m_osoption);
		// we need to get cost data from option file
		if(m_cost == NULL) throw ErrorClass("Option file did not contain cost data");
		
		
		
	
		m_maxMasterRows =  m_maxBmatrixCon + m_numNodes;
		
		m_upperBoundL = new int[ m_numHubs];
		m_lowerBoundL = new int[ m_numHubs];
		
		
	
		for(k = 0; k < m_numHubs; k++){
			
			//adjust routeMinPickup
			tmpVal = 0;
			for(i = 0; i < m_numHubs; i++) 
				if( i != k) tmpVal += m_routeCapacity[ i];
			
			m_lowerBoundL[ k] = std::max( m_routeMinPickup[ k], (m_totalDemand - tmpVal) )  ;
			
			m_upperBoundL[ k] = m_routeCapacity[ k];
			
			//set m_upperBoundL cannot exceed total demand
			if(m_upperBoundL[ k] > m_totalDemand) m_upperBoundL[ k] = m_totalDemand;
			if( m_upperBoundL[ k] > m_upperBoundLMax) m_upperBoundLMax = m_upperBoundL[ k];
			
		}

		//m_varIdx = new int[ m_numNodes];
		// I think we can make this the max of  m_upperBoundL
		// over the k
		m_varIdx = new int[ m_upperBoundLMax + 1];
		
		
		m_u = new double*[ m_numNodes];
		m_v = new double*[ m_numNodes];
		m_g = new double*[ m_numNodes];
		
		m_px = new int*[ m_numNodes];
		m_tx = new int*[ m_numNodes];
		

		
		/**
		 * m_u[i, l] -- this will be the minimum cost of reaching
		 * node i on a q-route with demand l, note that m_u[ i] has
		 * dimension m_upperBoundL + 1 so the possible values for l
		 * are l = 0, 1, \ldots, m_upperBoundL -- l is the actual value
		 * of demand
		 * 
		 */
		 
		for (i = 0; i < m_numNodes; i++) {
			
			//kipp we can use the biggest possible m_upperBoundL
			m_u[ i] = new double[ m_upperBoundLMax + 1];
			m_v[ i] = new double[ m_upperBoundLMax + 1];
			
			
			
			for(l = 0; l <= m_upperBoundLMax; l++){

				m_u[ i][l] = OSDBL_MAX;
				m_v[ i][l] = OSDBL_MAX;
			}
			
			m_g[ i] = new double[ m_numNodes];
			m_px[ i] = new int[ m_upperBoundLMax + 1];
			m_tx[ i] = new int[m_upperBoundLMax + 1];
			
			
		}
		
		
		//outer dynamic programming arrays
		m_optL = new int[ m_numHubs];
		m_optD = new int[ m_numHubs];
		
		m_vv = new double*[ m_numHubs];
		m_vvpnt = new int*[ m_numHubs];
		m_rc = new double*[ m_numHubs];
		
		for (k = 0; k < m_numHubs; k++) {
			
			
			m_vv[ k] = new double[ m_totalDemand + 1];
			m_vvpnt[ k] = new int[ m_totalDemand + 1];
			
			//allocate memory for the reduced cost vector. 
			//assume order is k, l, i, j
			//assume order is l, i, j
			m_rc[ k] = new double[ m_upperBoundL[ k]*(m_numNodes*m_numNodes - m_numNodes)];
			
			
		}
		
		m_optValHub = new double[ m_numHubs];
		
		m_variableNames = new string[ m_numNodes*(m_numNodes - 1)];
		
		createVariableNames();
		
		//these are constraints that say we must be incident to each
		//non-hub node -- there are  m_numNodes - m_numHubs of these
		m_pntAmatrix = new int[ m_numNodes - m_numHubs + 1];
		//the variables -- the variable space we are in is x_{ij} NOT
		// x_{ijk} -- a bit tricky
		//m_Amatrix[ j] is a variable index -- this logic works
		//since the Amatrix coefficient is 1 -- we don't need a value
		//it indexes variable that points into the node
		m_Amatrix = new  int[ (m_numNodes - m_numHubs)*(m_numNodes - 1) ];
		createAmatrix();
		
		//this has size of the number of x variables
		int numVar = m_numNodes*m_numNodes - m_numHubs ;
		m_tmpScatterArray = new int[ numVar ];
		for(i = 0; i < numVar; i++){
			
			m_tmpScatterArray[ i] = 0;
			
		}

		//New column arrays
		m_newColumnNonz = new int[ m_numHubs] ; //at most one column per Hub
		m_costVec = new double[ m_numHubs];
		m_newColumnRowIdx = new int*[ m_numHubs];
		m_newColumnRowValue = new double*[ m_numHubs];
	
		for (k = 0; k < m_numHubs; k++) {
			//size of arrray is maximum number of constraints
			// 1) coupling + 2) tour breaking + 3) branching
			m_newColumnRowValue[ k] = new double[ m_maxBmatrixCon + m_numNodes];
			m_newColumnRowIdx[ k] = new int[ m_maxBmatrixCon + m_numNodes];
			
		}
		

		
		//New row arrays
		//m_newRowNonz = new int[ m_numHubs] ; //at most one cut per Hub
		//m_newRowColumnIdx = new int*[ m_numHubs] ; //at most one cut per Hub
		//m_newRowColumnValue = new double*[ m_numHubs] ; //at most one cut per Hub
		//m_newRowUB = new double[ m_numHubs]; //at most one cut per Hub
		//m_newRowLB = new double[ m_numHubs]; //at most one cut per Hub
		
		
		m_newRowNonz = new int[ 100] ; //at most one cut per Hub
		m_newRowColumnIdx = new int*[ 100] ; //at most one cut per Hub
		m_newRowColumnValue = new double*[ 100] ; //at most one cut per Hub
		m_newRowUB = new double[ 100]; //at most one cut per Hub
		m_newRowLB = new double[ 100]; //at most one cut per Hub
		

		//for now, the number of columns will be m_maxMasterColumns 	
		//for (k = 0; k < m_numHubs; k++) {
		for (k = 0; k < 100; k++) {
			
			
			m_newRowColumnValue[ k] = new double[ m_maxMasterColumns];
			m_newRowColumnIdx[ k] = new int[ m_maxMasterColumns];
			
		}
		
		//new array for keeping track of convexity rows
		m_convexityRowIndex = new int[ m_maxMasterColumns];
		//new arrays for branches
		
		branchCutIndexes = new int[ m_maxMasterColumns];
		branchCutValues = new double[ m_maxMasterColumns];

		m_thetaPnt = new int[ m_maxMasterColumns + 1];
		for(i = 0; i <= m_maxMasterColumns; i++){
			m_thetaPnt[ i] = 0;
		}
		m_thetaCost = new double[ m_maxMasterColumns];
		m_thetaIndex = new int[ m_maxThetaNonz];
		m_numThetaVar = 0;
		m_numThetaNonz = 0;
		m_thetaPnt[ m_numThetaVar] = 0;
		

		//the number of cuts will be at most nubmer of tour 
		// breaking constraints + braching variable cuts
		// branching variable constraints = m_numNodes*(m_numNodes - 1)
		m_pntBmatrix = new int[ m_maxBmatrixCon];
		// number of nonzeros in the Bmatrix
		m_BmatrixIdx = new int[ m_maxBmatrixNonz];
		m_BmatrixRowIndex = new int[ m_maxBmatrixNonz];
		for(i = 0; i <  m_maxBmatrixNonz; i++) m_BmatrixRowIndex[ i] = -1;
		
		// number of nonzeros in the Bmatrix
		m_BmatrixVal = new double[ m_maxBmatrixNonz];
		
		
		m_numBmatrixCon = 0;
		m_numBmatrixNonz = 0;
		m_pntBmatrix[ m_numBmatrixCon] = 0;
		
;
		
		
		m_separationIndexMap = new int[m_numNodes*(m_numNodes - 1)];
		
		for(i = 0; i < m_numNodes*(m_numNodes - 1); i++){
			
			m_separationIndexMap[ i] =  OSINT_MAX;
			
		}
			
			
		

		//kipp -- move this later
		getSeparationInstance();
		for(k = 0; k < m_numHubs; k++){
			
			m_multCommodCutSolvers.push_back( getMultiCommodInstance( k) );
			
		}
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	
	
	
}//end initializeDataStructures


OSBearcatSolverXij::~OSBearcatSolverXij(){
	
	std::cout << "INSIDE ~OSBearcatSolverXij DESTRUCTOR" << std::endl;


	
	//delete data structures for arrays used in calculating minimum reduced cost
	int i;
	
	delete[] m_routeCapacity;
	m_routeCapacity = NULL;
	
	
	delete[] m_routeMinPickup;
	m_routeMinPickup = NULL;
	
	for(i = 0; i < m_numNodes; i++){
		 
		
		
	    delete[] m_v[i];
	    delete[] m_g[i];
	    delete[] m_px[i];
	    delete[] m_tx[i];
		delete[] m_u[i];

	
	}
	
	delete[] m_u;
	m_u= NULL;

	delete[] m_v;
	m_v= NULL;
	
	delete[] m_g;
	m_g= NULL;
	
	delete[] m_px;
	m_px= NULL;
	
	delete[] m_tx;
	m_tx= NULL;
	
	
	
	if(m_demand != NULL){
		//std::cout << "I AM DELETING m_demand" << std::endl;
		delete[] m_demand;
	}

	
	if(m_varIdx != NULL){ 
		delete[] m_varIdx;
		m_varIdx = NULL;
	
	}
	
	if(m_cost != NULL ){
		delete[] m_cost;
		m_cost = NULL;
	}
	
	for(i = 0; i < m_numHubs; i++){
		
		delete[] m_vv[i];
		delete[] m_vvpnt[i];
		delete[] m_rc[ i];
		
		
	}
	delete[] m_optL;
	m_optL = NULL;
	delete[] m_optD;
	m_optD = NULL;
	delete[] m_vv;
	m_vv = NULL;
	delete[] m_vvpnt;
	m_vvpnt = NULL;
	
	delete[] m_rc;
	m_rc = NULL;
	
	delete[] m_upperBoundL;	
	m_upperBoundL = NULL;
	
	delete[] m_lowerBoundL;	
	m_lowerBoundL = NULL;
	
	
	delete[] m_optValHub;
	m_optValHub = NULL;
	
	delete[] m_variableNames;
	m_variableNames = NULL;
	
	delete[] m_pntAmatrix;
	m_pntAmatrix = NULL;
	
	delete[] m_Amatrix;
	m_Amatrix = NULL;
	
	delete[] m_tmpScatterArray;
	m_tmpScatterArray = NULL;
	
	delete[] m_newColumnNonz  ;
	m_newColumnNonz = NULL;
	delete[] m_costVec ;
	m_costVec = NULL;
	
	for(i = 0; i < m_numHubs; i++){
		
		delete[] m_newColumnRowIdx[i];
		delete[] m_newColumnRowValue[i];
	}
	
	delete[] m_newColumnRowIdx;
	m_newColumnRowIdx = NULL;
	
	delete[] m_newColumnRowValue;
	m_newColumnRowValue = NULL;
	
	
	delete[] m_convexityRowIndex;
	m_convexityRowIndex = NULL;
	
	
	//getCut arrays
	delete[] m_newRowNonz;
	m_newRowNonz = NULL;
	
	delete[] m_newRowUB ; 
	m_newRowUB = NULL;
	
	delete[] m_newRowLB ; 
	m_newRowLB = NULL;
	
	//garbage collection on row arrays
	for (i = 0; i < m_numHubs; i++) {
		
		delete[] m_newRowColumnValue[ i];
		delete[] m_newRowColumnIdx[ i];
		
	}	
	
	delete[] m_newRowColumnIdx;
	m_newRowColumnIdx = NULL;
	
	delete[] m_newRowColumnValue;
	m_newRowColumnValue = NULL;
	
	
	delete[] branchCutIndexes ;
	branchCutIndexes = NULL;
	
	delete[] branchCutValues ;
	branchCutValues = NULL;
	
	
	delete[] m_thetaPnt;
	m_thetaPnt = NULL;
	
	delete[] m_thetaIndex;
	m_thetaIndex = NULL;

	
	delete[] m_thetaCost;
	m_thetaCost = NULL;
	
	
	delete[] m_pntBmatrix ;
	m_pntBmatrix = NULL;
	
	delete[]  m_BmatrixIdx ;
	m_BmatrixIdx = NULL;
	
	delete[]  m_BmatrixVal ;
	m_BmatrixVal = NULL;
	
	delete[]  m_BmatrixRowIndex ;
	m_BmatrixRowIndex = NULL;
	
		

	
	delete[] m_separationIndexMap;
	m_separationIndexMap = NULL;
	
	delete m_separationClpModel;
	m_separationClpModel = NULL;
	
	delete m_osinstanceSeparation;
	m_osinstanceSeparation = NULL;
	
	std::vector<CoinSolver*>::iterator vit;
	for(vit = m_multCommodCutSolvers.begin(); vit < m_multCommodCutSolvers.end(); vit++){
		
		delete *vit;
	}

}//end ~OSBearcatSolverXij







void OSBearcatSolverXij::getOptL( double** c) {
	
	//initialize the first HUB
	
	int k;
	int d;
	int d1;
	int kountVar;
	double testVal;
	int l;
	//int startPntInc;
	double trueMin;
	
	bool isFeasible;
	isFeasible = false;
	
	kountVar = 0;
	//startPntInc = m_upperBoundL*(m_numNodes*m_numNodes - m_numNodes);
	
	m_vv[ 0][ 0] = 0;
	for(d = 1; d <=  m_totalDemand; d++){
		
		m_vv[ 0][ d] = OSDBL_MAX;
		
	}
	//initialize up to last hub
	for(k = 1; k < m_numHubs - 1; k++){
		for(d = 0; d <=  m_totalDemand; d++){
			
			m_vv[ k][ d] = OSDBL_MAX;
			
		}
	}

	
	//now loop over the other HUBS
	
	int  dlower;
	dlower = 0;
	
	for(k = 1; k < m_numHubs; k++){
		
		dlower += m_lowerBoundL[ k - 1];
		
		//kipp make d the min demand for the previous routes
		for(d = dlower; d <= m_totalDemand; d++){
			
			m_vv[ k][ d] = OSDBL_MAX;
			
			//d1 is the state variable at stage k -1
			//for(d1 = 0; d1 <= m_totalDemand; d1++){
			for(d1 = 0; d1 <= d; d1++){
				
				l = d - d1;
				
				//std::cout << "L = " << l <<  "  m_upperBoundL[ k  - 1]  "  << m_upperBoundL[ k  - 1] << std::endl;
				//kipp make m_upperBoundL the route capapcity
				if( (m_vv[ k - 1][ d1] < OSDBL_MAX) &&  (l <= m_upperBoundL[ k  - 1]) && (l >= m_lowerBoundL[ k - 1]) ){
				
					//std::cout << "k - 1 = "   <<  k - 1 << "  L = " << l <<  "  m_upperBoundL[ k  - 1]  "  << m_upperBoundL[ k  - 1] << std::endl;
					// l was the decision at state d1 in stage k-1
					// l + d1 brings us to state d at stage k
					// d is the total carried on routes 0 -- k-1
				
					testVal = qrouteCost(k - 1,  l,  c[ k - 1],  &kountVar);
					
					//std::cout << "L = " << l << std::endl;
					//std::cout << "testVal " << testVal << std::endl;
					
					if( m_vv[ k-1][ d1]  +  testVal < m_vv[  k][ d] ){
						
						m_vv[ k][ d] =  m_vv[ k-1][ d1]  +  testVal;
						//now point to the best way to get to d
						m_vvpnt[ k][ d]  = d1;
						
					}
					
					
				}
				
			}
			
		}
		
		//c+=  startPntInc ;	
		
	}//  end for on k
	
	trueMin = OSDBL_MAX;
	//we now enter the last stage through the other hubs
	// have satisfied total demand d


	//if (m_numHubs > 1) dlower = 1;
	
	//std::cout << " dlower = " << dlower << "  m_totalDemand = " << m_totalDemand << std::endl;
	
	for(d = dlower; d < m_totalDemand; d++){
		
		//std::cout << "m_vv[ m_numHubs - 1 ][ d]  " << m_vv[ m_numHubs - 1 ][ d]  << std::endl;
		l = m_totalDemand - d;
		
		if(m_vv[ m_numHubs - 1 ][ d]  < OSDBL_MAX  && l <= m_upperBoundL[ m_numHubs - 1] && l >= m_lowerBoundL[ m_numHubs - 1]){
		
			//must execute this loop at least once
			
			//std::cout << "LL = " <<  l  << std::endl;
			
			isFeasible = true;
			
			
			testVal = qrouteCost(m_numHubs -1 ,  l,  c[ m_numHubs -1],  &kountVar);
			
			//std::cout << "l = " << l << std::endl;
			//std::cout << "testVal = " << testVal << std::endl;
			
			if(m_vv[ m_numHubs - 1][ d] + testVal < trueMin){
				
				trueMin = m_vv[ m_numHubs -1][ d] + testVal;
				m_optD[  m_numHubs -1 ] = d;
				m_optL[  m_numHubs -1 ] = l;
				
			}
			
			
		}
	}
	
	//std::cout << "TRUE MIN = " <<  trueMin << std::endl;
	
	if( isFeasible == false){
		
		std::cout << "NOT ENOUGH CAPACITY " << std::endl;
		throw ErrorClass( "NOT ENOUGH CAPACITY ");
	}

	k = m_numHubs -1;
	
	while( k - 1 >= 0) {
		
		m_optD[  k - 1 ] = m_vvpnt[ k][ m_optD[  k  ] ];
		
		m_optL[ k - 1 ] =  m_optD[  k  ] - m_optD[  k - 1 ] ;
		
		//std::cout << "k = " <<  k << std::endl;
		//std::cout << "m_optD[  k  ]  = " <<  m_optD[  k  ] << std::endl;
		//std::cout << "m_optD[  k -1 ] " << m_optD[  k - 1 ]  << std::endl;
		
		k--;
		
		
	}
	
}//end getOptL






double OSBearcatSolverXij::qrouteCost(const int& k, const int& l, const double* c, int* kountVar){
	
	//critical -- nodes 0, ..., m_numNodes - 1 are the hub nodes
	// we are doing the calculation for hub k, k <= m_numNodes - 1
	//l  should be the total demand on the network -- we are NOT using 0 based counting
	double rcost;
	rcost = OSDBL_MAX;
	

	
	if(l <= 0){
		
		std::cout  << "LVALUE  NEGATIVE OR ZERO  " << l  << std::endl;
		exit( 1);
	}


	
	if(l > m_upperBoundL[ k]){
		
		std::cout  << "LVALUE  BIGGER THAN UPPER BOUND " << l  << std::endl;
		exit( 1);
	}	
	
	//start of the cost vector for hub k plus move to start of l demands
	// now move the pointer up
	//int startPnt = m_upperBoundL[ k]*(m_numNodes*m_numNodes - m_numNodes) + (l - 1)*(m_numNodes*m_numNodes - m_numNodes);
	
	int startPnt = (l - 1)*(m_numNodes*m_numNodes - m_numNodes);
	c+=  startPnt ;
	


	*kountVar = 0;
	int bestLastNode;
	//initialize
	bestLastNode = OSINT_MAX;
	int i;
	int j;
	int l1;
	int l2;
	//for(i = 0; i < 20; i++){
	//	std::cout << "i =  " << i  <<  " c[i] = " << *(c + i) << std::endl ;
	//}



	// l  is the total demand on this network
	//address of node (j, i) is j*(m_numNodes-1) + i when i < j
	//address of node (j, i) is j*(m_numNodes-1) + i - 1 when i > j
	
	//
	// initialize
	
	
	for(i = m_numHubs; i < m_numNodes; i++){
		
		
		for(l1 = m_minDemand; l1 <= l; l1++){  //l-1  is total demand on network
			//std::cout << "HUB : " << k << " i = " << i << "  l1 " << l1 << std::endl;
			//std::cout << "m_upperBoundLMax: " <<   m_upperBoundLMax << std::endl;
			m_u[i][l1] = OSDBL_MAX;
			//std::cout << "DONE: " << " i = " << i << "  l1 " << l1 << std::endl;
			m_v[i][l1] = OSDBL_MAX;
			m_px[i][l1] = -1; //a node we don't have
			
			
			if(l1 == *(m_demand + i) ){//this should be valid even if demand is zero
				
				m_px[i][l1] = k;
				// want the cost for arc (k, i)
				// note: k < i so use that formula
				m_u[i][l1] = *(c + k*(m_numNodes - 1) + i - 1);  // put in correct cost
				

		
			}
			
		}	
	}
	//end initialize
	


	//
	
	//if l = minDemand we visit only one node, let's get the reduced cost in this case
	if(l == m_minDemand){
		
		for(i = m_numHubs; i < m_numNodes; i++){
			
			
			if(  m_u[i][l] + *(c + i*(m_numNodes-1) + k )  < rcost){
							
				rcost = m_u[i][l] + *(c + i*(m_numNodes-1) + k );
				
				//std::cout << " m_u[i][l2] = "  << m_u[i][l2] << std::endl;
				
				//std::cout << " *(c + i*(m_numNodes-1) + k ) = "  << *(c + i*(m_numNodes-1) + k ) << std::endl;
				//push node back
				bestLastNode = i;
			}
			
		}
		
		//go from node bestLastNode to node k		
		//node bestLastNode is a higher number than k
		*(m_varIdx + (*kountVar)++) = startPnt + bestLastNode*(m_numNodes - 1)  +  k ;
		*(m_varIdx + (*kountVar)++) = startPnt + k*(m_numNodes - 1)  + bestLastNode - 1;
		

		return rcost;	
	}//end if on l == minDemand
	
	
// now calculate values for demand 2 or greater 	
	//address of node (j, i) is j*(m_numNodes-1) + i when i < j
	//address of node (j, i) is j*(m_numNodes-1) + i - 1 when i > j
	// we start l2 at 2 since demand must be at least 1
	// change to min demand + 1
	//int lowerVal = m_minDemand + 1;
	//lowerVal = m_minDemand;
	//for(l2 = lowerVal; l2 <= l; l2++){// loop over possible demand values assuming we have already gone to at least one node
	for(l2 = m_minDemand + 1; l2 <= l; l2++){// loop over possible demand values assuming we have already gone to at least one node
			
		for(i = m_numHubs; i < m_numNodes; i++) { //we are finding least cost to node i
			
			
			if( *(m_demand + i) < l2 ){ // kipp < OR <= ????
					
				for(j = m_numHubs; j < i; j++){ //we are coming from node j
					

						
					//calculate g  -- l2 - d[ i]  is the demand trough and including node j
					l1 = l2 - *(m_demand + i);
					
					if( m_px[j][ l1 ] != i ){//check to make sure we did not come into j from i
						
						
						m_g[j][i] = m_u[ j][ l1 ] + *(c + j*(m_numNodes-1) + i - 1) ;
						
						
						
						
					}else{
												
						m_g[j][i] = m_v[ j][ l1] + *(c + j*(m_numNodes-1) + i - 1) ;
						
						
						
					}
					
					// update u and the pointer for p
					
					if(m_g[j][i] < m_u[i][l2] ){
						
						m_u[i][l2] = m_g[j][i];
						m_px[i][l2] =  j;
						
					}


					
				}//end of first for loop on j, j < i
				
				
				for(j = i + 1; j < m_numNodes; j++){ //we are coming from node j
					
		
					//calculate g  -- l2 - d[ i]  is the demand trough and including node j
					l1 = l2 - *(m_demand + i);
					
					if( m_px[j][ l1 ] != i ){//check to make sure we did not come into j from i
						
						
						m_g[j][i] = m_u[ j][ l1 ] + *(c + j*(m_numNodes-1) + i ) ;
						
						
					}else{
												
						m_g[j][i] = m_v[ j][ l1] + *(c + j*(m_numNodes-1) + i ) ;
						
					}
					
					// update u and the pointer for p
					
					if(m_g[j][i] < m_u[i][l2] ){
						
						m_u[i][l2] = m_g[j][i];
						m_px[i][l2] =  j;
						
					}

					
				}//end of second for loop on j, j > i				
				
				
				//now calculate the second best solution and point
				//right now m_px[i][l2] points to the best j node
				
				for(j =m_numHubs; j < m_numNodes; j++){ //we are coming from node j
					
					if(j != i){
						
						if( (m_g[j][i] < m_v[i][l2] ) && (m_px[i][l2] != j)  ){ // kipp the && gives the second best
							
						//if( m_g[j][i] < m_v[i][l2] )  {	
							
							m_v[i][l2] = m_g[j][i];
							m_tx[i][l2] = j;	
							
							
						}
						
					}
					
					
				}//end second best calculation, another for loop on j
				
				//now if l2 = l  we are done
				if(l2 == l ){
					
					if(  m_u[i][l2] + *(c + i*(m_numNodes-1) + k )  < rcost){
						
						rcost = m_u[i][l2] + *(c + i*(m_numNodes-1) + k );

						bestLastNode = i;
					}
					
				}
				
				
			}//end if on demand less than l2
			
			
		}//i loop
		
		
	}//l2 loop

	//
	
	//std::cout << "best Last Node = "  << bestLastNode << std::endl;
	
	// now get the path that gives the reduced cost

	
	int currentNode;
	int successorNode;
	int lvalue;
	
	//initialize
	// we work backwords from bestLastNode
	//in our recursion we recurse on the currentNode and assume
	//it is in the optimal path
	
	//node bestLastNode is a higher number than k
	*(m_varIdx + (*kountVar)++) = startPnt + bestLastNode*(m_numNodes - 1)  +  k ;
	
	
	//if we are here we should have a value for bestLastNode
	//if not return infinity
	if( bestLastNode == OSINT_MAX) return OSDBL_MAX;

	//by successor, I mean node after current node in the path
	successorNode = k;
	currentNode = bestLastNode;
	//the lvalue is the demand through the currentNode
	lvalue = l ;

	
	
	
	while(currentNode != k){
		//std::cout << "currentNode = " << currentNode << "   " <<  "lvalue " <<  lvalue << std::endl;
		if(*kountVar == m_upperBoundLMax + 1) return OSDBL_MAX;
		if( m_px[ currentNode][ lvalue ] != successorNode){
			

			
			//update nodes
			successorNode = currentNode;
			currentNode = m_px[ currentNode][ lvalue ];
			
			
			if(currentNode - successorNode > 0){
				 //below diagonal
				
				//std::cout << "startPnt "  << startPnt << "  currentNode  " << currentNode << "  successorNode  " << successorNode << " Kount "  << *kountVar << std::endl;

				*(m_varIdx  + (*kountVar)++) = startPnt + currentNode*(m_numNodes - 1)  +  successorNode;

				
			}else{
				 //above diagonal
				
				//std::cout << "startPnt "  << startPnt << "  currentNode  " << currentNode << "  successorNode  " << successorNode   << " Kount "  << *kountVar << std::endl;

				*(m_varIdx + (*kountVar)++) = startPnt + currentNode*(m_numNodes - 1)  +  successorNode  - 1 ;

			}

			
		}else{ //take second best
			
			
			//update nodes
			successorNode = currentNode;
			currentNode = m_tx[ currentNode][ lvalue ];
			
			if(currentNode - successorNode > 0){
				 //below diagonal
				
				//std::cout << "startPnt "  << startPnt << "  currentNode  " << currentNode << "  successorNode  " << successorNode << " Kount "  << *kountVar  << std::endl;
				*(m_varIdx  + (*kountVar)++) = startPnt + currentNode*(m_numNodes - 1)  +  successorNode;
				
			}else{
				 //above diagonal
				//std::cout << "startPnt "  << startPnt << "  currentNode  " << currentNode << "  successorNode  " << successorNode << " Kount "  << *kountVar << std::endl;
				*(m_varIdx + (*kountVar)++) = startPnt + currentNode*(m_numNodes - 1)  +  successorNode  - 1 ;
				
			}
			
		}
		
		//update lvalue
		//if ( *(m_demand + successorNode) == 0) lvalue = lvalue - 1;
		//else lvalue = lvalue - *(m_demand + successorNode);
		lvalue = lvalue - *(m_demand + successorNode);
		
		

	}//end while

	
	//go from node k to bestLastNode -- already done in loop above
	//*(m_varIdx + (*kountVar)++) = startPnt + k*(m_numNodes - 1)  +  currentNode - 1;
	

	return rcost;
	
}//end qroute




void OSBearcatSolverXij::getColumns(const  double* yA, const int numARows,
		const  double* yB, const int numBRows,
		int &numNewColumns, int* &numNonzVec, double* &costVec, 
		int** &rowIdxVec, double** &valuesVec, double &lowerBound) 
{
	
//first strip of the phi dual values and then the convexity row costs
	
	int i;
	int j;
	int numCoulpingConstraints;
	numCoulpingConstraints = m_numNodes - m_numHubs;
	
	int numVar;
	numVar = m_numNodes*m_numNodes - m_numHubs;
	int numNonz;
	
	try{
		

		
		if(numARows != m_numNodes) throw ErrorClass("inconsistent row count in getColumns");
		

		
		//get the reduced costs 
		calcReducedCost( yA, yB );
	
		int kountVar;
		double testVal;
		testVal = 0;
		int k;
		int startPntInc;
		int rowCount;
		double rowValue;

		//// get optimal q for each route
		
		double cpuTime;
		double start = CoinCpuTime();
		getOptL( m_rc);
		cpuTime = CoinCpuTime() - start;
		std::cout << "DYNAMIC PROGRAMMING CPU TIME  " << cpuTime << std::endl;
		m_lowerBnd = 0.0;
		for(k = 0; k < m_numHubs; k++){
			
			
			//startPntInc  = k*m_upperBoundL*(m_numNodes*m_numNodes - m_numNodes) + (m_optL[ k] - 1)*(m_numNodes*m_numNodes - m_numNodes);
			startPntInc  =   (m_optL[ k] - 1)*(m_numNodes*m_numNodes - m_numNodes);
			
			std::cout << " whichBlock =  " << k << "  L = " << m_optL[ k] << std::endl;
			
			testVal += m_optL[ k];
			
			kountVar = 0;  
			
			///// calling qrouteCost
			m_optValHub[ k] = qrouteCost(k,  m_optL[ k], m_rc[ k],  &kountVar);
			
			m_optValHub[ k] -= yA[ k + numCoulpingConstraints];
			
			std::cout << "Best Reduced Cost Hub " << k << " =  "  << m_optValHub[ k] << std::endl;
			m_lowerBnd += m_optValHub[ k];
			
			//loop over the rows, scatter each row and figure
			//out the column coefficients in this row
			//first scatter the sparse array m_varIdx[ j]
			
			m_costVec[ k] = 0.0;
			
			for(j = 0; j < kountVar; j++){
				
				
				//we are counting the NUMBER of times the variable used
				//the same variable can appear more than once in m_varIdx
				m_tmpScatterArray[ m_varIdx[ j] - startPntInc  ] += 1;
				
				// is variable m_varIdx[ j] - startPntInc in this row	
				
				m_costVec[ k] += m_cost[  m_varIdx[ j] - startPntInc  ];
				
			}
			
			
			
			numNonz = 0;
			//multiply the sparse array by each A matrix constraint
			for(i = 0; i < numCoulpingConstraints; i++){
				
				rowCount = 0;
				
				for(j = m_pntAmatrix[ i]; j < m_pntAmatrix[ i + 1]; j++){
					
					//m_Amatrix[ j] is a variable index -- this logic works
					//since the Amatrix coefficient is 1 -- we don't need a value
					//it indexes variable that points into the node
					rowCount += m_tmpScatterArray[  m_Amatrix[ j] ];
					

				}
				
				if(rowCount > 0){
					
					//std::cout << "GAIL NODE " << i + m_numHubs <<  " COUNT = " << rowCount << std::endl;
					m_newColumnRowIdx[ k][ numNonz] = i;
					m_newColumnRowValue[ k][ numNonz] = rowCount;
					numNonz++;
				}
					
					
			}//end loop on coupling constraints
			
			//add a 1 in the convexity row
			m_newColumnRowIdx[ k][ numNonz] = m_numNodes - m_numHubs + k;
			m_newColumnRowValue[ k][ numNonz++] = 1.0;
			
			
			
			//now multiply the sparse array by each B-matrix constraint
			
			for(i = 0; i < m_numBmatrixCon; i++){
				
				if(m_BmatrixRowIndex[ i] == -1 || m_BmatrixRowIndex[ i] == k ){
				
					//rowCount = 0;
					rowValue = 0;
					
					for(j = m_pntBmatrix[ i]; j < m_pntBmatrix[ i + 1]; j++){
						
						//m_BmatrixIdx[ j] is a variable index -- this logic works
						//since the Bmatrix coefficient is 1 -- we don't need a value
						//it indexes variable that points into the node
						//rowCount += m_tmpScatterArray[  m_BmatrixIdx[ j] ];
						//now assume coefficients not necessarily 1
	
						rowValue += m_tmpScatterArray[  m_BmatrixIdx[ j] ]*m_BmatrixVal[ j];
	
					}
					//use epsilon instead of 0
					if( rowValue > m_osDecompParam.zeroTol || rowValue < -m_osDecompParam.zeroTol){
						
						
						m_newColumnRowIdx[ k][ numNonz] = i + m_numNodes;
						m_newColumnRowValue[ k][ numNonz++] = rowValue;
						
					}
					
				}
				
				
			}
			
			m_newColumnNonz[ k] = numNonz;
			
			
			
			//zero out the scatter vector and store the generated column
			for(j = 0; j < kountVar; j++){
				
				
				m_thetaIndex[ m_numThetaNonz++ ] =  m_varIdx[ j] - startPntInc ;
				m_tmpScatterArray[ m_varIdx[ j] - startPntInc  ]  = 0;
				
				// is variable m_varIdx[ j] - startPntInc in this row	
				
			}
			

			intVarSet.insert ( std::pair<int,double>( m_numThetaVar, 1.0) );
			m_convexityRowIndex[ m_numThetaVar] = k;
			m_costVec[ k] =  m_optL[ k]*m_costVec[ k];
			m_thetaCost[ m_numThetaVar++ ] = m_costVec[ k];
			m_thetaPnt[ m_numThetaVar ]  = m_numThetaNonz;
			

	

			
			//stuff for debugging
			//*****************************//
			/**
			int ivalue;
			int jvalue;
			for(j = 0; j < kountVar; j++){
				
				startPntInc  =  k*m_upperBoundL*(m_numNodes*m_numNodes - m_numNodes) + (m_optL[ k] - 1)*(m_numNodes*m_numNodes - m_numNodes);
				
				
				std::cout << "Variable Index = " <<  m_varIdx[ j] - startPntInc ;
				std::cout << "  Variable = " << m_variableNames[  m_varIdx[ j] - startPntInc ]	<< std::endl ;	
				
				//tmp -- get the node
				
				//tmp = fmod(m_varIdx[ j] - startPntInc, m_numNodes) ;  
				
				ivalue = floor( (m_varIdx[ j] - startPntInc)/(m_numNodes - 1) );
				jvalue = (m_varIdx[ j] - startPntInc) - ivalue*(m_numNodes - 1);
				std::cout << " i NODE NUMBER = " << ivalue  ;
				
				if(  jvalue  > ivalue ){
					
					std::cout << " j NODE NUMBER = " <<  jvalue + 1   << std::endl;
				}else{
					
					std::cout << " j NODE NUMBER = " <<  jvalue   << std::endl;
				}
				
				
			}
			
			std::cout << "Route True Cost = " << m_costVec[ k] << std::endl;
			*/
			//**************************//
			//end debugging stuff
	
			
		}//end of loop on hubs
		
		
		
		numNonzVec = m_newColumnNonz;
		costVec = m_costVec;
		rowIdxVec = m_newColumnRowIdx;
		valuesVec = m_newColumnRowValue;	
		std::cout << "Lower Bound = " << m_lowerBnd << std::endl;
		
		
		if(testVal != m_totalDemand) {
			
			std::cout  << "TOTAL DEMAND = " << m_totalDemand << std::endl;
			std::cout  << "Test Value = " << testVal << std::endl;
			throw  ErrorClass( "inconsistent demand calculation" );
		}
		
		
		

		
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}
	
	
	//set method parameters
	numNewColumns = m_numHubs;
	lowerBound =  m_lowerBnd;
	
	std::cout << "LEAVING GET COLUMNS" << std::endl;
	return;
	
}//end getColumns



/**
OSInstance* OSBearcatSolverXij::getInitialRestrictedMaster( ){

	
	std::cout << "Executing OSBearcatSolverXij::getInitialRestrictedMaster( )" << std::endl;
	
	// define the classes
	FileUtil *fileUtil = NULL;
	OSiLReader *osilreader = NULL;
	DefaultSolver *solver  = NULL;
	OSInstance *osinstance = NULL;


	// end classes    

	std::string testFileName;
	std::string osil;
	
	//std::vector< int> indexes;
	fileUtil = new FileUtil();
	
	
	std::map<int, std::map<int, std::vector<int> > >::iterator  mit;
	std::map<int, std::vector<int> >::iterator  mit2;
	std::vector<int>::iterator  vit;
	
	m_osinstanceMaster = NULL;
	
	//add linear constraint coefficients
	//number of values will nodes.size() the coefficients in the node constraints
	//plus coefficients in convexity constraints which is the number of varaibles
	int kountNonz;
	int kount;
	int numThetaVar = m_numberOfSolutions*m_numHubs;
	double *values = new double[ m_numberOfSolutions*(m_numNodes-m_numHubs) + numThetaVar];
	int *indexes = new int[ m_numberOfSolutions*(m_numNodes-m_numHubs) + numThetaVar];
	int *starts = new int[ numThetaVar + 1]; 
	kount = 0;
	
	starts[ 0] = 0;	
	
	int startsIdx;
	startsIdx = 0;

	std::vector<IndexValuePair*> primalValPair;

	try {
		
		if(m_initOSiLFile.size() == 0) throw ErrorClass("OSiL file to generate restricted master missing");
		osil = fileUtil->getFileAsString( m_initOSiLFile.c_str());

		osilreader = new OSiLReader();
		osinstance = osilreader->readOSiL(osil);
		

		
		int i;
		int j;
		int k;
		//fill in the cost vector first
		//the x vector starts at 2*m_numHubs
		
		int idx1;
		int idx2;
		
		
		idx2 = 0;  //zRouteDemand have 0 coefficients in obj
		//fill in m_cost from the cost coefficient in osil
		for(k = 0; k < m_numHubs; k++){
			
			idx1 = 0;
			
			for(i = 0; i < m_numNodes; i++){
				
				for(j = 0; j < i; j++){
				
					m_cost[k][idx1++ ] = osinstance->instanceData->objectives->obj[0]->coef[ idx2++ ]->value;
				}
				
				for(j = i + 1; j < m_numNodes; j++){
					
					m_cost[k][idx1++ ] = osinstance->instanceData->objectives->obj[0]->coef[ idx2++ ]->value;
					
				}
			}
		}
	

	
		//get variable names for checking purposes
		std::string* varNames;
		varNames =  osinstance->getVariableNames();

		
		//start building the restricted master here
		
		
		m_osinstanceMaster = new OSInstance();
		m_osinstanceMaster->setInstanceDescription("The Initial Restricted Master");
		
		// first the variables
		m_osinstanceMaster->setVariableNumber( m_numberOfSolutions*m_numHubs);   
		
		// now add the objective function
		m_osinstanceMaster->setObjectiveNumber( 1);
		SparseVector *objcoeff = new SparseVector( m_numberOfSolutions*m_numHubs);   

		
		// now the constraints
		m_osinstanceMaster->setConstraintNumber( m_numNodes); 		
		
		
		//addVariable(int index, string name, double lowerBound, double upperBound, char type, double init, string initString);
		// we could use setVariables() and add all the variable with one method call -- below is easier

		//

		int varNumber;
		varNumber = 0;
		std::string masterVarName;
		kountNonz = 0;
		// now get the primal solution
		//solve the model for solution in the osoption object
		for ( mit = m_initSolMap.begin() ; mit != m_initSolMap.end(); mit++ ){
			
			//kipp change upper and lower bounds here on z variables
			//loop over nodes and routes and set bound
			//set kount to the start of the z variables
			//go past the x variables
			kount  =  2*m_numHubs + m_numHubs*(m_numNodes*m_numNodes - m_numNodes);
			osinstance->bVariablesModified = true;
			for ( mit2 = mit->second.begin() ; mit2 != mit->second.end(); mit2++ ){ //we are looping over routes in solution mit
				
				
				
				startsIdx++;
				starts[ startsIdx ] = kountNonz + mit2->second.size() + 1; //the +1 comes from the convexity row
				
				
				//make sure all lower bounds on z variables on this route back to 0.0
				for(i = 0; i < m_numNodes; i++){
					osinstance->instanceData->variables->var[ kount + mit2->first*m_numNodes + i]->lb = 0.0;
				}
				
	
				for ( vit = mit2->second.begin() ; vit != mit2->second.end(); vit++ ){	
					
							
					osinstance->instanceData->variables->var[ kount + mit2->first*m_numNodes + *vit]->lb = 1.0;
					//std::cout << "FIXING LOWER BOUND ON VARIABLE " << osinstance->getVariableNames()[ kount + mit2->first*m_numNodes + *vit ] << std::endl;
					
					values[ kountNonz] = 1.0;
					indexes[ kountNonz ] = *vit - m_numHubs ;  //0 based counting
					kountNonz++;
					
				}
				
				
				 //now for the convexity row coefficient	
				values[ kountNonz] = 1;
				indexes[ kountNonz ] = m_numNodes - m_numHubs +  mit2->first  ;
				kountNonz++;
				
				
			}
			
			solver = new CoinSolver();
			solver->sSolverName ="cbc"; 
			solver->osinstance = osinstance;	
			
			solver->buildSolverInstance();
			solver->solve();
			
			//get the solver solution status
			
			std::cout << "Solution Status =  " << solver->osresult->getSolutionStatusType( 0 ) << std::endl;
			
			//get the optimal objective function value
			
			
			primalValPair = solver->osresult->getOptimalPrimalVariableValues( 0);

			//loop over routes again to create master objective coefficients

			for(k = 0; k < m_numHubs; k++){
				
				
				//lets get the x variables
				//the variables for this route should be from 2*numHubs + k*(numNodes - 1*)*(numNodes - 1)
				idx1 = 2*m_numHubs + k*m_numNodes*(m_numNodes - 1);
				idx2 = idx1 + m_numNodes*(m_numNodes - 1);
				//end of x variables
			
				//std::cout << "HUB " <<  k  << " VARIABLES" << std::endl;
				
			

				for(i = idx1; i < idx2; i++){
					if(  primalValPair[ i]->value > .1 ){
						//std::cout <<  osinstance->getVariableNames()[  primalValPair[ i]->idx  ] << std::endl;
						//std::cout <<  m_variableNames[  primalValPair[ i]->idx  -  k*(m_numNodes - 1)*m_numNodes - 2*m_numHubs  ] << std::endl;
						m_thetaIndex[ m_numThetaNonz++ ] = primalValPair[ i]->idx  -  k*(m_numNodes - 1)*m_numNodes - 2*m_numHubs;
					}
					
				}
				m_convexityRowIndex[ m_numThetaVar] = k;
				m_thetaCost[ m_numThetaVar++ ] = primalValPair[ k]->value*primalValPair[ k + m_numHubs]->value;
				m_thetaPnt[ m_numThetaVar ] = m_numThetaNonz;
				
				masterVarName = makeStringFromInt("theta(", k);
				masterVarName += makeStringFromInt(",", mit->first);
				masterVarName += ")";
				intVarSet.insert ( std::pair<int,double>(varNumber, 1.0) );
				m_osinstanceMaster->addVariable(varNumber++, masterVarName, 0, 1, 'C');
				
				std::cout << "Optimal Objective Value = " << primalValPair[ k]->value*primalValPair[ k + m_numHubs]->value << std::endl;
				
				objcoeff->indexes[ k + (mit->first)*m_numHubs] = k +  (mit->first)*m_numHubs;
				objcoeff->values[ k + (mit->first)*m_numHubs] = primalValPair[ k]->value*primalValPair[ k + m_numHubs]->value;

				
				std::cout <<  osinstance->getVariableNames()[ k ] << std::endl;
				std::cout <<  osinstance->getVariableNames()[ k + m_numHubs ] << std::endl;
				

			}//end for on k -- hubs
			
			
			primalValPair.clear();
			delete solver;
			solver = NULL;
		}//end for on number of solutions
		
		//add the constraints
		//add the row saying we must visit each node
		for( i =  0; i < m_numNodes - m_numHubs ; i++){
			
			m_osinstanceMaster->addConstraint(i,  makeStringFromInt("visitNode_", i + m_numHubs) , 1.0, 1.0, 0); 
		}
		
		kount = 0;
		
		//add the convexity row
		for( i =  m_numNodes - m_numHubs; i < m_numNodes ; i++){
			
			m_osinstanceMaster->addConstraint(i,  makeStringFromInt("convexityRowRoute_", kount++ ) , 1.0, 1.0, 0); 
		}
		
		m_osinstanceMaster->addObjective(-1, "objfunction", "min", 0.0, 1.0, objcoeff);
		
		std::cout << "kountNonz = " << kountNonz << std::endl;
		
		//add the linear constraints coefficients
		m_osinstanceMaster->setLinearConstraintCoefficients(kountNonz , true, 
				values, 0, kountNonz - 1,  indexes, 0, kountNonz - 1, starts, 0, startsIdx);
	
		
		std::cout << m_osinstanceMaster->printModel() << std::endl;
		delete objcoeff;
		
		//delete[] values;
		//delete[] starts;
		//delete[] indexes;
		delete osilreader;
		osilreader = NULL;

		

	} catch (const ErrorClass& eclass) {
		std::cout << std::endl << std::endl << std::endl;
		if (osilreader != NULL)
			delete osilreader;
		if (solver != NULL)
			delete solver;


		//  Problem with the parser
		throw ErrorClass(eclass.errormsg);
	}

	delete fileUtil;
	fileUtil = NULL;

	return m_osinstanceMaster;
}//end generateInitialRestrictedMaster
*/







OSInstance* OSBearcatSolverXij::getInitialRestrictedMaster( ){

	
	//implement 1OPT
	
	
	getInitialSolution();
	
	std::cout << "Executing OSBearcatSolverXij::getInitialRestrictedMaster( )" << std::endl;
	
	//this master will have m_numNodes artificial variables
	int numVarArt;
	//numVarArt = 2*m_numNodes;
	numVarArt = m_numNodes;
	
	int numXVar;
	numXVar = m_numNodes*m_numNodes - m_numNodes;
	
	double* xVar = NULL;
	xVar = new double[ numXVar];

	int i;
	int k;
	std::string testFileName;
	std::string osil;
	
	std::map<int, std::map<int, std::vector<int> > >::iterator  mit;
	std::map<int, std::vector<int> >::iterator  mit2;
	std::vector<int>::iterator  vit;
	
	m_osinstanceMaster = NULL;
	//add linear constraint coefficients
	//number of values will nodes.size() the coefficients in the node constraints
	//plus coefficients in convexity constraints which is the number of varaibles
	int kountNonz;
	int kount;
	m_numberOfSolutions = 1;
	int numThetaVar = m_numberOfSolutions*m_numHubs;
	//the extra  is for the artificial variables
	double *values = new double[ m_numberOfSolutions*(m_numNodes-m_numHubs) + numThetaVar + numVarArt];
	int *indexes = new int[ m_numberOfSolutions*(m_numNodes-m_numHubs) + numThetaVar +  numVarArt]  ;
	int *starts = new int[ numThetaVar + 1 + numVarArt]; 
	kount = 0;
	starts[ 0] = 0;	
	int startsIdx;
	startsIdx = 0;
	startsIdx++;
	
	double tspObjValue;
	double demandSum;
	
	SparseVector *objcoeff = NULL;
	
	for(i = 0; i < numVarArt; i++){
		m_convexityRowIndex[ m_numThetaVar] = -1;
		m_thetaPnt[ m_numThetaVar++] = 0;
		
	}
	try {
		
		//start building the restricted master here
		m_osinstanceMaster = new OSInstance();
		m_osinstanceMaster->setInstanceDescription("The Initial Restricted Master");
		
		// first the variables
		// we have numVarArt] artificial variables 
		m_osinstanceMaster->setVariableNumber( m_numberOfSolutions*m_numHubs + numVarArt);   
		
		// now add the objective function
		m_osinstanceMaster->setObjectiveNumber( 1);
		//add m_numNodes artificial variables
		objcoeff = new SparseVector( m_numberOfSolutions*m_numHubs + numVarArt);   

		// now the constraints
		m_osinstanceMaster->setConstraintNumber( m_numNodes); 	
		
		//add the artificial variables -- they must be first in the model
		
		int varNumber;
		varNumber = 0;
		std::string masterVarName;
		kountNonz = 0;
		
		for(i = 0; i < m_numNodes; i++){
			
			objcoeff->indexes[ varNumber ] = varNumber ;
			//if obj too large we get the following error
			//Assertion failed: (fabs(obj[i]) < 1.0e25), function createRim, 
			//file ../../../Clp/src/ClpSimplex.cpp, l
			//objcoeff->values[ varNumber ] = OSDBL_MAX;
			//objcoeff->values[ varNumber ] = 1.0e24;
			objcoeff->values[ varNumber ] = m_osDecompParam.artVarCoeff;
			
			m_osinstanceMaster->addVariable(varNumber++, makeStringFromInt("AP", i ) , 
					0, 1.0, 'C');
											
			values[ kountNonz] = 1;
			indexes[ kountNonz++] = i ;
			starts[ startsIdx++] = kountNonz;
			
		}
		
		m_bestIPValue = 0;
		mit = m_initSolMap.find( 0);
		if(mit == m_initSolMap.end() ) throw ErrorClass("Problem finding first solution in m_initSolMap");

		CoinSolver *solver = NULL;
		solver = getTSP(m_numNodes, m_cost);
		
		
		for(k = 0; k < m_numHubs; k++){
			//locate hub k
			mit2 = mit->second.find( k);
			if(mit2 == mit->second.end()  ) throw ErrorClass("Problem finding hub k in the solution map");
			
			tspObjValue = getRouteDistance(m_numNodes, mit2->first, solver,
					 mit2->second, xVar);
			demandSum = 0;
			//get demands
			for ( vit = mit2->second.begin() ; vit != mit2->second.end(); vit++ ) {
				
				demandSum += m_demand[ *vit];
				values[ kountNonz] = 1;
				indexes[ kountNonz++] = *vit - m_numHubs ;
				
			}
			
			//update theta indexes
			
			for(i = 0; i < numXVar; i++){
				
				//std::cout << "xVar = " << xVar[ i] << std::endl;
				if(xVar[ i] > .1) {
					m_thetaIndex[ m_numThetaNonz++ ] = i;
					//std::cout << m_variableNames[ i]  << std::endl;
				}
			}  
			//exit( 1);
			//now for convexity row  k
			
			values[ kountNonz] = 1;
			indexes[ kountNonz++] = m_numNodes - m_numHubs + k ;
			
			
			
			
			m_convexityRowIndex[ m_numThetaVar] = k;
			m_thetaCost[ m_numThetaVar++ ] = demandSum*tspObjValue; 
			m_thetaPnt[ m_numThetaVar ] = m_numThetaNonz;
			
			masterVarName = makeStringFromInt("theta(", k);
			masterVarName += makeStringFromInt(",", 0);
			masterVarName += ")";
			intVarSet.insert ( std::pair<int,double>(varNumber, 1.0) );
			m_osinstanceMaster->addVariable(varNumber++, masterVarName, 0, 1, 'C');
			
			std::cout << "Optimal Objective Value = " << demandSum*tspObjValue << std::endl;

		
			objcoeff->indexes[ k + numVarArt ] = k + numVarArt ;
			objcoeff->values[ k + numVarArt ] = demandSum*tspObjValue;
			
			m_bestIPValue += demandSum*tspObjValue;
			
			std::cout << "m_bestIPValue = " << m_bestIPValue << std::endl;
			starts[ startsIdx++] = kountNonz;	
			
		}//end of index on k
		std::cout << " m_numThetaVar  " << m_numThetaVar  << std::endl;
		//add the constraints
		//add the row saying we must visit each node
		
		for( i =  0; i < m_numNodes - m_numHubs ; i++){
			
			m_osinstanceMaster->addConstraint(i,  makeStringFromInt("visitNode_", i + m_numHubs) , 1.0, 1.0, 0); 
		}
		
		kount = 0;
		
		//add the convexity row
		for( i =  m_numNodes - m_numHubs; i < m_numNodes ; i++){
			
			m_osinstanceMaster->addConstraint(i,  makeStringFromInt("convexityRowRoute_", kount++ ) , 1.0, 1.0, 0); 
		}
				
		m_osinstanceMaster->addObjective(-1, "objfunction", "min", 0.0, 1.0, objcoeff);
		
		
		//add the linear constraints coefficients
		m_osinstanceMaster->setLinearConstraintCoefficients(kountNonz , true, 
				values, 0, kountNonz - 1,  indexes, 0, kountNonz - 1, starts, 0, startsIdx);
		

		std::cout << m_osinstanceMaster->printModel( ) << std::endl;		
		std::cout << "NONZ = " << kountNonz << std::endl;
	
	
		delete objcoeff;
		objcoeff = NULL;
		delete[] xVar;
		xVar = NULL;
		delete solver->osinstance;
		delete solver;
		

  

	} catch (const ErrorClass& eclass) {
		std::cout << std::endl << std::endl << std::endl;

		if(objcoeff != NULL) delete objcoeff;
		if(xVar != NULL) delete xVar;
		//  Problem with the parser
		throw ErrorClass(eclass.errormsg);
	}

	return m_osinstanceMaster;
}//end generateInitialRestrictedMaster2



void OSBearcatSolverXij::getOptions(OSOption *osoption) {
	
	
	std::cout << "Executing getOptions(OSOption *osoption)" << std::endl;
	//get any options relevant to OSColGenApp
	try{
		
		int i;

		
		std::vector<SolverOption*> solverOptions;
		std::vector<SolverOption*>::iterator vit;
		std::vector<int>::iterator vit2;
		std::vector<int >demand;
		std::vector<std::string >nodeName;
		std::vector<int >routeCapacity;
		std::vector<int >routeMinPickup;
		std::vector<double >arcCost;
		std::vector<double >::iterator vit3;
		std::vector<std::string>::iterator vit4;
	
		m_numberOfSolutions = 0;
		solverOptions = osoption->getSolverOptions("routeSolver");
		if (solverOptions.size() == 0) throw ErrorClass( "options for routeSolver not available");
		//iterate over the vector
		
		int tmpVal;
		double tmpCost;

		
		std::string routeString; //variable for parsing a category option
		std::string solutionString; //variable for parsing a category option
		string::size_type pos1; //variable for parsing a category option
		string::size_type pos2; //variable for parsing a category option
		string::size_type pos3; //variable for parsing a category option
		
		
		std::map<int, std::map<int, std::vector<int> > >::iterator  mit;
		std::map<int, std::vector<int> >::iterator  mit2;
		int solutionNumber;
		int routeNumber;
		
	
		for (vit = solverOptions.begin(); vit != solverOptions.end(); vit++) {
			
			
			//std::cout << (*vit)->name << std::endl;
			
			//(*vit)->name.compare("initialCol") == 0
			//if(rowNames[ i3].find("routeCapacity(1)") == string::npos )
			
			if( (*vit)->name.find("numHubs") !=  std::string::npos){
				
				
				std::istringstream hubBuffer( (*vit)->value);
				hubBuffer >> m_numHubs;
				std::cout << "numHubs = " << m_numHubs <<  std::endl;
				
			}else{
				
				if((*vit)->name.find("numNodes") !=  std::string::npos){
					
					
					std::istringstream numNodesBuffer( (*vit)->value);
					numNodesBuffer >> m_numNodes;
					std::cout << "numNodes = " <<  m_numNodes <<  std::endl;
					
				}else{
					if((*vit)->name.find("totalDemand") !=  std::string::npos){
						
						
						std::istringstream totalDemandBuffer( (*vit)->value);
						totalDemandBuffer >> m_totalDemand;
						std::cout << "m_totalDemand = " << m_totalDemand <<  std::endl;
						
					}else{
						if((*vit)->name.find("routeMinPickup") !=  std::string::npos){
							
							
							std::istringstream routeMinPickupBuffer( (*vit)->value);
							routeMinPickupBuffer >> tmpVal;
							routeMinPickup.push_back( tmpVal);
							//std::cout << "m_minDemand = " << tmpVal <<  std::endl;
						
						}else{
							if( (*vit)->name.find("demand") !=  std::string::npos ){
								
								
								std::istringstream demandBuffer( (*vit)->value);
								demandBuffer >> tmpVal;
								if(tmpVal <= 0 && demand.size() > (unsigned int) m_numHubs) throw ErrorClass("must have strictly positive demand");
								if(tmpVal < m_minDemand  && demand.size() > (unsigned int) m_numHubs ) m_minDemand = tmpVal;
								demand.push_back( tmpVal);
								nodeName.push_back( (*vit)->description);
								//std::cout << "demand = " << tmpVal <<  std::endl;
								
							}else{
								if((*vit)->name.find("routeCapacity") !=  std::string::npos ){
									std::istringstream routeCapacityBuffer( (*vit)->value);
									routeCapacityBuffer >> tmpVal;
									routeCapacity.push_back( tmpVal);
									std::cout << "m_routeCapacity = " << tmpVal <<  std::endl;
									
								}else{
									
									if((*vit)->name.find("osilFile") !=  std::string::npos ){
										m_initOSiLFile = (*vit)->value;
										std::cout << "m_initOSiLFile = " << m_initOSiLFile <<  std::endl;
										
									}else{
										
										if( (*vit)->name.find("restrictedMasterSolution") !=  std::string::npos  ){
											//std::istringstream buffer( (*vit)->value);
											//buffer >> m_numberOfSolutions;
	
											//get the block number and solution number
											//first get routeString and soluionString
											//parse the category string base on :
											pos1 = (*vit)->category.find( ":");
											if(pos1 == std::string::npos ) throw ErrorClass("OSoL category attribute not properly defined");
											
											//solutionString = (*vit)->category.substr( pos1 + 1, pos2 - pos1 - 1);
											solutionString = (*vit)->category.substr( 0,  pos1);
											routeString = (*vit)->category.substr( pos1 + 1);
	
											pos2 = solutionString.find( "n");
											if(pos2  == std::string::npos ) throw ErrorClass("OSoL category attribute not properly defined");
											
											std::istringstream solutionBuffer( solutionString.substr( pos2 + 1)  );
											solutionBuffer >> solutionNumber;
											//std::cout << "solution number = " << solutionNumber  << std::endl;
											
											
											pos3 = routeString.find( "e");
											if(pos3  == std::string::npos ) throw ErrorClass("OSoL category attribute not properly defined");
											std::istringstream routeBuffer( routeString.substr( pos3 + 1)  );
											routeBuffer >> routeNumber;
											//std::cout << "route number = " <<  routeNumber << std::endl;
											std::istringstream nodeBuffer( (*vit)->value);
											nodeBuffer >> tmpVal;
											
											mit = m_initSolMap.find(  solutionNumber  );
											
											if( mit  != m_initSolMap.end() ){
												// we have solution from before
												// do we have a new route?
												
												mit2 = mit->second.find( routeNumber);
												
												if(mit2 != mit->second.end() ){
												// we have a route from before and solution from before
	
													
													mit2->second.push_back( tmpVal);
													
													
												}else{
													
													//we have a new route, but old solution
													std::vector<int> tmpVec;
													tmpVec.push_back( tmpVal) ;
													mit->second.insert( std::pair<int,std::vector<int> >(routeNumber, tmpVec) );	
													
												
												}
												
											}else{
												// we have a new solution
												std::vector<int> tmpVec;
												tmpVec.push_back( tmpVal) ;
												
												std::map<int, std::vector<int> > tmpMap;
												tmpMap.insert( std::pair<int,std::vector<int> >(routeNumber, tmpVec) );
												m_initSolMap.insert( std::pair<int, std::map<int, std::vector<int> > >(solutionNumber, tmpMap) )  ;
												
											}
										}//if on restricted master solution
										else{
											if( (*vit)->name.find("maxMasterColumns") !=  std::string::npos){
												

												std::istringstream maxMasterColumns( (*vit)->value);
												maxMasterColumns >> m_maxMasterColumns;
												std::cout << "m_maxMasterColumn = " << m_maxMasterColumns <<  std::endl;
												
											}else{
												if( (*vit)->name.find("maxThetaNonz") !=  std::string::npos){
													
													std::istringstream maxThetaNonz( (*vit)->value);
													maxThetaNonz >> m_maxThetaNonz;
													std::cout << "m_maxThetaNonz = " << m_maxThetaNonz <<  std::endl;
													
												}else{
													if( (*vit)->name.find("use1OPTstart") !=  std::string::npos){
														m_use1OPTstart  = false;
														if ( (*vit)->value.find("true") !=  std::string::npos ) m_use1OPTstart  = true;
														std::cout << "m_use1OPTstart = " << m_use1OPTstart <<  std::endl;
														
													}else{
														if( (*vit)->name.find("maxBmatrixCon") !=  std::string::npos ){
															
															std::istringstream maxBmatrixCon( (*vit)->value);
															maxBmatrixCon >> m_maxBmatrixCon;
															std::cout << "m_maxBmatrixCon = " << m_maxBmatrixCon <<  std::endl;
															
														}else{
															if( (*vit)->name.find("maxBmatrixNonz") !=  std::string::npos ){
																
																std::istringstream maxBmatrixNonz( (*vit)->value);
																maxBmatrixNonz >> m_maxBmatrixNonz;
																std::cout << "m_maxBmatrixNonz = " << m_maxBmatrixNonz <<  std::endl;
																
																
															}else{
																
																if( (*vit)->name.find("cost") !=  std::string::npos ){
																	
																	
																	std::istringstream costBuffer( (*vit)->value);
																	costBuffer >> tmpCost;
																	arcCost.push_back( tmpCost);
																	
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}//end if on solver options
			
		}//end for loop on options
		
		
		//now fill in route capacities
		i = 0;
		m_routeCapacity = new int[ m_numHubs];
		if( (unsigned int)m_numHubs != routeCapacity.size( ) ) throw ErrorClass("inconsistent number of HUBS");
		for (vit2 = routeCapacity.begin(); vit2 != routeCapacity.end(); vit2++) {
			
			*(m_routeCapacity + i++) = *vit2;
			
			std::cout << "ROUTE CAP = " << *vit2 << std::endl;
			
		}
		routeCapacity.clear();
		
		
		//now fill in route min pickups
		i = 0;
		m_routeMinPickup = new int[ m_numHubs];
		if( (unsigned int)m_numHubs != routeMinPickup.size( ) ) throw ErrorClass("inconsistent number of HUBS");
		//initialize
		for(int k = 0; k < m_numHubs; k++){
			m_routeMinPickup[ k] = 1;
		}
		for (vit2 = routeMinPickup.begin(); vit2 != routeMinPickup.end(); vit2++) {
			
			*(m_routeMinPickup + i++) = *vit2;
			
		}
		routeMinPickup.clear();
		
		
		//now fill in demand		
		i = 0;
		m_demand = new int[ m_numNodes];
		if( (unsigned int)m_numNodes != demand.size( ) ) 
			throw ErrorClass("inconsistent number of demand nodes");
		for (vit2 = demand.begin(); vit2 != demand.end(); vit2++) {
			
			*(m_demand + i++) = *vit2;
			
		}
		demand.clear();
		
		//now fill in node names		
		i = 0;
		m_nodeName = new std::string[ m_numNodes];

		for (vit4 = nodeName.begin(); vit4 != nodeName.end(); vit4++) {
			
			*(m_nodeName + i++) = *vit4;
			
		}
		nodeName.clear();	
		
		
		
		//now fill in costs	
		m_cost = NULL;
		m_costSetInOption = false;
		if(arcCost.size() != (unsigned int)(m_numNodes*m_numNodes - m_numNodes) ) 
			throw ErrorClass("input cost vector not consistent with number of nodes");
		if(arcCost.size() >= 1){
			m_costSetInOption = true;
			i = 0;
			m_cost = new double[ m_numNodes*m_numNodes - m_numNodes ];
			for (vit3 = arcCost.begin(); vit3 != arcCost.end(); vit3++) {
				
				*(m_cost + i++) = *vit3;
				
			}
			arcCost.clear();
		}
		
		//kipp -- fill in numberOfRestricedMasterSolutions from map size
		 m_numberOfSolutions = m_initSolMap.size();
		
	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
}//end getOptions



void OSBearcatSolverXij::getCutsTheta(const  double* theta, const int numTheta,
		int &numNewRows, int*  &numNonz, int** &colIdx,
		double** &values, double* &rowLB, double* &rowUB) {
	//critical -- the variables that come in the theta variables
	//not the x variables, we must convert to x, find a cut in x-space
	//and then convert back to theta
	
	int i;
	int j;
	int k;
	int index;
	int rowKount;
	int tmpKount;
	int indexAdjust = m_numNodes - m_numHubs;
	double* tmpRhs;
	int numSepRows = m_osinstanceSeparation->getConstraintNumber() ;
	
	tmpRhs = new double[ numSepRows ]; 
	
	for(i = 0; i < numSepRows; i++){
		
		tmpRhs[ i] = 0;
	}
	
	try{
		m_osinstanceSeparation->bConstraintsModified = true;
		//m_numNodes is the number of artificial variables
		if(numTheta != m_numThetaVar ) throw 
				ErrorClass("number of master varibles in OSBearcatSolverXij::getCuts inconsistent");
		
		//for(i = 0; i < numTheta; i++){
		
		//std::cout << "numTheta = " << numTheta << std::endl;
		//std::cout << "m_numThetaVar = " << m_numThetaVar - 1 << std::endl;
		
		//exit( 1);
		
		for(i = 0; i < numTheta; i++){
			
			//get a postive theta
			if(theta[ i] > m_osDecompParam.zeroTol){
				
				//get the xij indexes associated with this variable
				for(j = m_thetaPnt[ i ]; j <  m_thetaPnt[ i + 1 ]; j++ ){
					
					//get the xij index 
					
					

					rowKount = m_separationIndexMap[  m_thetaIndex[ j] ];
					
					//std::cout << "rowKount = " << rowKount  <<std::endl;
					
					if(rowKount < OSINT_MAX ){
						
						tmpRhs[ rowKount] -= theta[ i];
						
					}
					
				}
			}
		}
		
		
		// don't adjust the kludge row
		
		for(i = indexAdjust; i < numSepRows - 1; i++){
			
			if(-tmpRhs[ i] > 1 + m_osDecompParam.zeroTol ){
				// quick and dirty does x_{ij} + x_{ji} <= 1 cut off anything
				//std::cout << " tmpRhs[ i] =  " << tmpRhs[ i]  << std::endl;
				//which variable is this 
				//kipp this an inefficient way of finding i and j -- improve this
				int tmpKount = indexAdjust;
				for(int i1 = m_numHubs; i1 < m_numNodes; i1++){
				
				
				
					for(int j1 = i1+1; j1 < m_numNodes; j1++){
						
						if(tmpKount ==  i){
							
							//std::cout << "i = " << i1 << std::endl;
							//std::cout << "j = " << j1 << std::endl;
							//okay generate a cut that says
							// x(i1,j1) + x(j1, i1) << 1
							m_BmatrixVal[   m_numBmatrixNonz ] = 1 ;
							//get index for i1,j1
							m_BmatrixIdx[   m_numBmatrixNonz++ ] = i1*(m_numNodes - 1) + j1 - 1 ;
							
							m_BmatrixVal[   m_numBmatrixNonz ] = 1 ;
							//get index for j1,i1
							m_BmatrixIdx[   m_numBmatrixNonz++ ] = j1*(m_numNodes - 1) + i1 ;
							m_numBmatrixCon++;
							m_pntBmatrix[ m_numBmatrixCon ] =  m_numBmatrixNonz;

							numNewRows = 1;
							
							m_newRowNonz[ 0] = 0;
							m_newRowUB[ 0] = 1;
							m_newRowLB[ 0] = 0;
						
							//now we have to get the theta column indexes
							//scatter the constraint in the x - variables
							
							for(j = m_pntBmatrix[  m_numBmatrixCon  - 1] ; 
									j <  m_pntBmatrix[ m_numBmatrixCon  ] ; j++){
								
								
								std::cout << " m_BmatrixIdx[ j] "  << m_BmatrixIdx[ j] <<  std::endl ;
								
								m_tmpScatterArray[ m_BmatrixIdx[ j] ] = 1;
								
							}	
							
							
							
							
							for(k = 0; k < m_numThetaVar ; k++){
								
								//get the xij indexes in this column 
								tmpKount = 0;
							
								
								for(j = m_thetaPnt[k]; j < m_thetaPnt[k + 1] ;  j++){
									
									if(m_tmpScatterArray[ m_thetaIndex[ j] ] > 0 ){ //count number of xij for theta_i
										
										std::cout << " Variable  " << m_variableNames[ m_thetaIndex[ j]  ]  << std::endl;
										
										tmpKount++;
										
									}
									
								}//end loop on j
								
								if(tmpKount > 0){
									//theta_i has a nonzero coefficient in this row
									
									m_newRowColumnIdx[0][ m_newRowNonz[ 0] ] = k ;
									//m_newRowColumnValue[0][ m_newRowNonz[ 0]++ ] = tmpKount;
									m_newRowColumnValue[0][ m_newRowNonz[ 0]++ ] = tmpKount;
									 
									
								}
								
							}//end loop on k
							
							
							//zero out the scatter array again
							
							//::cout << " m_numBmatrixCon  - 1  " << m_numBmatrixCon  - 1  << std::endl;
							//std::cout << " m_pntBmatrix[  m_numBmatrixCon  - 1] "  << m_pntBmatrix[  m_numBmatrixCon  - 1] <<  std::endl ;
							//std::cout << " m_pntBmatrix[  m_numBmatrixCon  ] "  << m_pntBmatrix[  m_numBmatrixCon  ] <<  std::endl ;
							for(j = m_pntBmatrix[  m_numBmatrixCon  - 1] ; 
									j < m_pntBmatrix[  m_numBmatrixCon  ] ; j++){
								
								m_tmpScatterArray[ m_BmatrixIdx[ j] ] = 0;
								
							}	
						
							numNonz = m_newRowNonz;
							colIdx =  m_newRowColumnIdx;
							values =  m_newRowColumnValue;
							rowUB =  m_newRowUB;
							rowLB =  m_newRowLB;
							
							delete[] tmpRhs;
							tmpRhs = NULL;
							
							//we found a row, add the corresponding artificial variables
							//to the transformation matrix
							m_numThetaVar++;
							m_convexityRowIndex[ m_numThetaVar] = -1;
							m_thetaPnt[ m_numThetaVar] = m_numThetaNonz;
							//m_thetaPnt[ m_numThetaVar++] = m_numThetaNonz;
							//m_thetaPnt[ m_numThetaVar] = m_numThetaNonz;
							
							return;						
							
						} //end loop on if tmpKount
						
						tmpKount++;
					
					}//loop on j1
					
				}//loop  on i1
			
			
			}//end if on tmpRHS
			
			m_separationClpModel->setRowUpper(i, tmpRhs[ i] );
			m_separationClpModel->setRowLower(i, tmpRhs[ i] );		

		}//end loop on i
		
		
		//std::cout << m_osinstanceSeparation->printModel() << std::endl;
	

		std::vector<int> dualIdx;
		std::vector<int>::iterator vit1;
		std::vector<int>::iterator vit2;
		
		//if the objective function value is greater than zero we have a cut
		//the cut is based on the nodes with dual value - 1
		
		for(k = 0; k < indexAdjust; k++){
			//std::cout <<   std::endl << std::endl;
			
			
			m_separationClpModel->setRowUpper(k, 0.0);
			//we don't need output
			
			m_separationClpModel->setLogLevel( 0);
			
			m_separationClpModel->primal();		
			
			if(m_separationClpModel->getObjValue() > m_osDecompParam.zeroTol){
				std::cout << "DOING SEPARATION FOR NODE "  << k + m_numHubs << std::endl;
				std::cout << "SEPERATION OBJ VALUE =  "  <<  m_separationClpModel->getObjValue() << std::endl;
				numNewRows = 1;
			
				for(i = 0; i < m_numNodes - m_numHubs ; i++){
					//std::cout <<   m_osinstanceSeparation->getConstraintNames()[ i]   << " = " << m_separationClpModel->getRowPrice()[ i] << std::endl;
					if( m_separationClpModel->getRowPrice()[ i] - m_osDecompParam.zeroTol <= -1) dualIdx.push_back( i) ;
				}
				
				for (vit1 = dualIdx.begin(); vit1 != dualIdx.end(); vit1++) {
					
					i = *vit1 + m_numHubs;
					
					for (vit2 = dualIdx.begin(); vit2 != dualIdx.end(); vit2++) {
						
						j = *vit2 + m_numHubs;
						
						if( i > j ){
						
							index = i*(m_numNodes -1) + j;
							std::cout << "CUT VARIABLE = " << m_variableNames[ index  ] <<std::endl;	
							m_BmatrixVal[   m_numBmatrixNonz ] = 1 ;
							m_BmatrixIdx[   m_numBmatrixNonz++ ] = index ;
							
						}else{
							
							if( i < j ){
								
								index = i*(m_numNodes -1) + j - 1;
								std::cout << "CUT VARIABLE = " << m_variableNames[ index  ] <<std::endl;
								m_BmatrixVal[   m_numBmatrixNonz ] = 1 ;
								m_BmatrixIdx[   m_numBmatrixNonz++ ] = index  ;
								
							}
						}
						
					}//end for on vit2
				}//end for on vit1
				
				//add the tour-breaking cut
				m_numBmatrixCon++;
				m_pntBmatrix[ m_numBmatrixCon ] =  m_numBmatrixNonz;
	
				// multiply the transformation matrix times this cut to get the cut in theta space
				// do the usual trick and scatter m_BmatrixIdx into a dense vector

				//reset
				// don't adjust the kludge row
				for(i = indexAdjust; i < numSepRows - 1; i++){
					
					m_separationClpModel->setRowUpper(i, 0.0 );
					m_separationClpModel->setRowLower(i, 0.0 );
					
					
				}
				m_separationClpModel->setRowUpper(k, 1.0);
				delete[] tmpRhs;
				tmpRhs = NULL;
				
			
				m_newRowNonz[ 0] = 0;
				m_newRowUB[ 0] =  dualIdx.size()  - 1;
				m_newRowLB[ 0] = 0;
				
				dualIdx.clear();
			
				//now we have to get the theata column indexes
				//scatter the constraint in the x - variables
				
				for(j = m_pntBmatrix[  m_numBmatrixCon  - 1] ; 
						j <  m_pntBmatrix[ m_numBmatrixCon  ] ; j++){
					
					m_tmpScatterArray[ m_BmatrixIdx[ j] ] = 1;
					
				}	
				
				
				
				
				for(i = 0; i < m_numThetaVar ; i++){
					
					//get the xij indexes in this column 
					tmpKount = 0;
					for(j = m_thetaPnt[i]; j < m_thetaPnt[i + 1] ;  j++){
						
						if(m_tmpScatterArray[ m_thetaIndex[ j] ] > 0 ){ //count number of xij for theta_i
							
							tmpKount++;
							
						}
						
					}//end loop on j
					
					if(tmpKount > 0){
						//theta_i has a nonzero coefficient in this row
						
						m_newRowColumnIdx[0][ m_newRowNonz[ 0] ] = i ;
						
						m_newRowColumnValue[0][ m_newRowNonz[ 0]++ ] = tmpKount;
						 
						
					}
					
				}//end loop on i
				
			
				//zero out the scatter array again
	
				for(j = m_pntBmatrix[  m_numBmatrixCon  - 1] ; 
						j < m_pntBmatrix[  m_numBmatrixCon  ] ; j++){
					
					m_tmpScatterArray[ m_BmatrixIdx[ j] ] = 0;
					
				}		
						

				
				numNonz = m_newRowNonz;
				colIdx =  m_newRowColumnIdx;
				values =  m_newRowColumnValue;
				rowUB =  m_newRowUB;
				rowLB =  m_newRowLB;
				m_numThetaVar++;
				m_convexityRowIndex[ m_numThetaVar] = -1;
				m_thetaPnt[ m_numThetaVar] = m_numThetaNonz;
				//m_thetaPnt[ m_numThetaVar++] = m_numThetaNonz; //first artificial variable
				//m_thetaPnt[ m_numThetaVar] = m_numThetaNonz; //second artificial varaible
			
				return;
				
			
				
			}//end if on obj value		
			m_separationClpModel->setRowUpper(k, 1.0);
			dualIdx.clear();
			
		}//end loop on k
		
		//if we are here there was no cut
		//reset
		// don't adjust the kludge row
		for(i = indexAdjust; i < numSepRows - 1; i++){
			
			m_separationClpModel->setRowUpper(i, 0.0 );
			m_separationClpModel->setRowLower(i, 0.0 );
			
			
		}
		
		delete[] tmpRhs;
		tmpRhs = NULL;
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
	
	
}//end getCutsTheta


void OSBearcatSolverXij::getCutsMultiCommod(const  double* theta, const int numTheta,
		int &numNewRows, int*  &numNonz, int** &colIdx,
		double** &values, double* &rowLB, double* &rowUB) {
	//critical -- the variables that come in the theta variables
	//not the x variables, we must convert to x, find a cut in x-space
	//and then convert back to theta
	
	numNewRows = 0;
	
	
	//m_convexityRowIndex
	int i;
	int j;
	int k;
	int ivalue;
	int jvalue;
	int thetaIdx;
	int inodenum;
	int jnodenum;
	int j1;
	int j2;
	int kount;
	double wVal;
	double uVal;
	bool foundCut;
	double  objVal;

	int ckijIndex;
	int numNonHubs;
	numNonHubs = m_numNodes - m_numHubs;
	
	int numVar;
	double rowValue;
	
	double* scatterValues;
	int numXijVar = m_numNodes*m_numNodes - m_numNodes;
	scatterValues = new double[ numXijVar ];
	for(i = 0; i < numXijVar; i++ )scatterValues[ i] = 0;
	
	double tmpCoeff;
	
	double *wcoeff = NULL;
	wcoeff = new double[ numNonHubs];
	CoinSolver *solver;
	
	std::cout <<  std::endl << std::endl;
	std::cout << "INSIDE getCutsMultiCommod "  << std::endl;
	std::cout <<  std::endl << std::endl;
	
	std::map<int, std::vector<std::pair<int,double> > > xVarMap;
	std::map<int, std::vector<std::pair<int,double> > >::iterator mit;
	std::vector<std::pair<int,double> >::iterator vit;
	
	std::map<std::pair<int, int>,int>xVarIndexMap;
	std::pair<int,int> indexPair;
	ostringstream cutString;
	
	
	
	
	

	//construct index map
	kount = 0;
	for(i = 0; i < m_numNodes; i++){
		
		for(j = 0; j < i; j++){  //j < i
		
		
			
			indexPair.first = i;
			indexPair.second = j;
			xVarIndexMap[ indexPair] = kount;
			kount++;
		}
		
		for(j = i+1; j < m_numNodes; j++){ // i < j
			
			indexPair.first = i;
			indexPair.second = j;
			xVarIndexMap[ indexPair] = kount;
			kount++;
		}
	}
	//end construct map

	

	
	//intVarSet.insert ( std::pair<int,double>(mit->second, 1.0) );
	
	try{
		
		for(i = 0; i < numTheta; i++){
			xVarMap[ m_convexityRowIndex[ i] ] ; 
			//get a postive theta
			if(theta[ i] > m_osDecompParam.zeroTol){
				
				//get the xij indexes associated with this variable
				for(j = m_thetaPnt[ i ]; j <  m_thetaPnt[ i + 1 ]; j++ ){
					
					mit = xVarMap.find( m_convexityRowIndex[ i]) ;  
					
					if(mit != xVarMap.end() ){
						
						mit->second.push_back( std::pair<int, double>( m_thetaIndex[  j],  theta[ i])  );
						 
					}
				}
			}
		}
		

		
		//get a cut for each hub
		for(k = 0; k < m_numHubs; k++){
			
			
			mit = xVarMap.find( k) ;
			
			solver = m_multCommodCutSolvers[ k];
			
			numVar  = solver->osiSolver->getNumCols();
			for(i = 0; i < numVar; i++ ) solver->osiSolver->setObjCoeff( i, 0);
			
			for(i = 0; i < numNonHubs; i++)  wcoeff[ i ] = 0;
		
			if(mit != xVarMap.end() ){
				
				std::cout <<  "CONVEXITY ROW "  << " = "  <<  mit->first  << std::endl;
				
				for(vit = mit->second.begin();  vit < mit->second.end(); vit++){
					
					//std::cout <<  m_variableNames[ vit->first ]  << " = "  <<  vit->second  << std::endl;
						
					ivalue = (int)floor( vit->first /(m_numNodes - 1) );
					
					jvalue = vit->first - ivalue*(m_numNodes - 1);
					
					if(  jvalue  >= ivalue ){
						//std::cout << " i NODE NUMBER = " <<  ivalue   << std::endl;
						//std::cout << " j NODE NUMBER = " <<  jvalue + 1   << std::endl;
						inodenum = ivalue;
						jnodenum = jvalue + 1;
						
						
					}else{
						//std::cout << " i NODE NUMBER = " <<  ivalue   << std::endl;
						//std::cout << " j NODE NUMBER = " <<  jvalue    << std::endl;

						inodenum = ivalue;
						jnodenum = jvalue;
					}
					
					if(jnodenum != k){
						
						//std::cout << "GAIL " << m_nodeName[ inodenum] << "  " <<  m_nodeName[ jnodenum]  << std::endl;
						wcoeff[ jnodenum - m_numHubs ] += vit->second;
						
						if( inodenum == k ){
							ckijIndex = jnodenum - m_numHubs;
						} else{
							//inodenum and jnodenum NOT hub nodes
							inodenum -=  m_numHubs;
							jnodenum -=  m_numHubs;
							
							
							if( jnodenum > inodenum) ckijIndex = inodenum*(numNonHubs - 1) + jnodenum - 1 ;
								else ckijIndex = inodenum*(numNonHubs - 1) + jnodenum  ;
							
							//increment by the number (k, i) variables --- there are numNonHUbs
							ckijIndex += numNonHubs ;
							
						}
						
						
						ckijIndex += numNonHubs;	
						
						tmpCoeff = solver->osiSolver->getObjCoefficients()[ ckijIndex] ;
						//std::cout <<  " HONDA "  << "cijkIndex = " <<  ckijIndex << std::endl;
						
						tmpCoeff  = tmpCoeff - vit->second;
						if( ckijIndex > numVar - 1) throw ErrorClass( "problem with ckijIndex calculation");
						//std::cout << "cijkIndex = " <<  ckijIndex  << " tmp Coeff After = " << tmpCoeff << " vit->second = "<< vit->second << std::endl;
						solver->osiSolver->setObjCoeff( ckijIndex,  tmpCoeff );
					}
					
				}//end looping over xkij
				 
			}//end if on mit
			foundCut = false;
			//loop over s to get a cut
			for(i = 0; i < numNonHubs; i++){

				//set s^{\hat} coefficient
				solver->osiSolver->setObjCoeff( i,  wcoeff[ i ]  );
				
				//solve the LP
				solver->solve();
				//solver->osiSolver->initialSolve();
				//kipp -- change the hard coding
				//we have a cut
				if(solver->osiSolver->getObjValue() > .1){
					objVal = 0;
					std::cout << "Separation Obj Value = " <<  
						solver->osiSolver->getObjValue() << "  Node " << m_nodeName[i + m_numHubs] << std::endl;
					//if(k == 1)solver->osiSolver->writeLp( "tmpLP--April17");
					foundCut = true;
					m_newRowNonz[ numNewRows ] = 0;
				//get the solution, let's see what the cut is in x(i, j) variables
					//empty the buffer
					cutString.str("");
					cutString << "";
					//first get the coefficients on x(i, shat)
					// this is the sum of w(shat) and the u(i, shat)
					kount = numNonHubs;
					
					wVal = solver->osiSolver->getColSolution()[ i];
					objVal += wVal*solver->osiSolver->getObjCoefficients()[ i];

					if(wVal < m_osDecompParam.zeroTol  )throw ErrorClass("problem with wVal in generating a multicommodity cut");
					//get the u(k,j2) variables
					//j1 = k
					for(j2 = m_numHubs; j2 < m_numNodes; j2++){ //j1 = k
						
						indexPair.first = k;
						indexPair.second = j2;
						
						uVal = solver->osiSolver->getColSolution()[ kount];
						objVal += uVal*solver->osiSolver->getObjCoefficients()[ kount];
						
						//if(solver->osiSolver->getObjCoefficients()[ kount] < -0.001 ) std::cout << m_variableNames[ xVarIndexMap[ indexPair] ]<< " valueeeee  = " << uVal << " coeff " << solver->osiSolver->getObjCoefficients()[ kount] << " kount " << kount << std::endl;
													
						
						if (j2 == (i + m_numHubs) ){
							
							if( (wVal - uVal) > m_osDecompParam.zeroTol || (uVal - wVal)  > m_osDecompParam.zeroTol ){
								//variable (wVal - uVal)*x(k, shat)
								cutString << " =";
								cutString << (wVal - uVal);
								cutString << "*" ;
								//cutString << m_nodeName[ k] ;
								//cutString << "," ;
								//cutString << m_nodeName[ i + m_numHubs] ; //i is indexing a non-hub
								//cutString << ")  " ;
								
								m_BmatrixVal[   m_numBmatrixNonz ] = (wVal - uVal)/wVal ;
								//get index for k, j2
								//m_BmatrixIdx[   m_numBmatrixNonz++ ] = k*(m_numNodes - 1) + j2 - 1   ;
								if(xVarIndexMap.find( indexPair) == xVarIndexMap.end()  ){
									std::cout << " Getting ready to call ErrorClass: kount = " << kount << std::endl;
									throw ErrorClass( "index mapping problem in generating multicommodity cut");
								}else{
									m_BmatrixIdx[   m_numBmatrixNonz++ ] = xVarIndexMap[ indexPair];
									cutString << m_variableNames[ xVarIndexMap[ indexPair] ]; 
								}
								
							}
							
						}else{
							
							if(  (-uVal > m_osDecompParam.zeroTol) || (uVal  > m_osDecompParam.zeroTol)  ){
								//variable -uVal*x(j1, j2)
								cutString << " ";
								cutString << - uVal;
								cutString << "*" ;
								//cutString << m_nodeName[ k ];
								//cutString << "," ;
								//cutString << m_nodeName[ j2 ];
								//cutString << ")  " ;
								
								
								m_BmatrixVal[   m_numBmatrixNonz ] = -uVal/wVal ;
								//get index for k, j2
								//m_BmatrixIdx[   m_numBmatrixNonz++ ] = k*(m_numNodes - 1) + j2 - 1   ;
								
								if(xVarIndexMap.find( indexPair) == xVarIndexMap.end()  ){
									std::cout << " Getting ready to call ErrorClass: kount = " << kount << std::endl;
									throw ErrorClass( "index mapping problem in generating multicommodity cut");
								}else{
									m_BmatrixIdx[   m_numBmatrixNonz++ ] = xVarIndexMap[ indexPair];
									cutString << m_variableNames[ xVarIndexMap[ indexPair] ]; 
								}
							}
							
						}
						
						kount++;
					}
					
					//get the u(j1, j2) variables for j1 not a hub		
					for(j1 = m_numHubs; j1 < m_numNodes; j1++){ //<= since we include hub
						
						//j1 = 0 corresponds to the hub
						
						//for(j2 = j1 + 1; j2 < m_numNodes; j2++){
						for(j2 = m_numHubs; j2 < j1; j2++){
							
							indexPair.first = j1;
							indexPair.second = j2;
							
							uVal = solver->osiSolver->getColSolution()[ kount];
							objVal += uVal*solver->osiSolver->getObjCoefficients()[ kount];
							
							//if(solver->osiSolver->getObjCoefficients()[ kount] < -0.001 ) std::cout << m_variableNames[ xVarIndexMap[ indexPair] ] << " valueeeee  = " << uVal << " coeff " << solver->osiSolver->getObjCoefficients()[ kount] << " kount " << kount << std::endl;
							
							if (j2 == (i + m_numHubs)  ){
							
								
								if( (wVal - uVal) > m_osDecompParam.zeroTol || (uVal - wVal)  > m_osDecompParam.zeroTol ){
									//variable (wVal - uVal)*x(j1, shat)
									cutString << " +";
									cutString << (wVal - uVal) ;
									cutString << "*" ;
									//cutString << m_nodeName[ j1] ;
									//cutString << "," ;
									//cutString << m_nodeName[ i + m_numHubs];
									//cutString << ")  " ;
									m_BmatrixVal[   m_numBmatrixNonz ] = (wVal - uVal)/wVal ;
									//get index for j1, j2 with  j1  < j2
									//m_BmatrixIdx[   m_numBmatrixNonz++ ] = j1*(m_numNodes - 1) + j2 - 1   ;
									
									if(xVarIndexMap.find( indexPair) == xVarIndexMap.end()  ){
										std::cout << " Getting ready to call ErrorClass: kount = " << kount << std::endl;
										throw ErrorClass( "index mapping problem in generating multicommodity cut");
									}else{
										m_BmatrixIdx[   m_numBmatrixNonz++ ] = xVarIndexMap[ indexPair];
										cutString << m_variableNames[ xVarIndexMap[ indexPair] ]; 
									}
									
								}
								
							}else{
								
								if(  (-uVal > m_osDecompParam.zeroTol) || (uVal  > m_osDecompParam.zeroTol)  ){
									//variable -uVal*x(j1, j2)
									cutString << " ";
									cutString << - uVal;
									cutString << "*" ;
									//cutString << m_nodeName[ j1 ];
									//cutString << "," ;
									//cutString << m_nodeName[ j2 ];
									//cutString << ")  " ;
									
									m_BmatrixVal[   m_numBmatrixNonz ] = -uVal/wVal ;
									//get index for j1, j2 with  j1  < j2
									//m_BmatrixIdx[   m_numBmatrixNonz++ ] = j1*(m_numNodes - 1) + j2 - 1   ;
									
									if(xVarIndexMap.find( indexPair) == xVarIndexMap.end()  ){
										std::cout << " Getting ready to call ErrorClass: kount = " << kount << std::endl;
										throw ErrorClass( "index mapping problem in generating multicommodity cut");
									}else{
										m_BmatrixIdx[   m_numBmatrixNonz++ ] = xVarIndexMap[ indexPair];
										cutString << m_variableNames[ xVarIndexMap[ indexPair] ]; 
									}
								}
							}
							kount++;
						}
						
						//for(j2 = m_numHubs; j2 < j1; j2++){
						for(j2 = j1 + 1; j2 < m_numNodes; j2++){
							
							indexPair.first = j1;
							indexPair.second = j2;
							
							uVal = solver->osiSolver->getColSolution()[ kount];
							objVal += uVal*solver->osiSolver->getObjCoefficients()[ kount];
							
							//if(solver->osiSolver->getObjCoefficients()[ kount] < -0.001) std::cout << m_variableNames[ xVarIndexMap[ indexPair] ] << " valueeeee  = " << uVal << " coeff " << solver->osiSolver->getObjCoefficients()[ kount] << " kount " << kount << std::endl;
							
							if (j2 == (i + m_numHubs) ){
								
								if( (wVal - uVal) > m_osDecompParam.zeroTol || (uVal - wVal)  > m_osDecompParam.zeroTol ){
									//variable (wVal - uVal)*x(j1, shat)
									cutString << " +";
									cutString << (wVal - uVal);
									cutString << "*" ;
									//cutString << m_nodeName[ j1 ];
									//cutString << "," ;
									//cutString << m_nodeName[ i+ m_numHubs] ;
									//cutString << ")  " ;
									m_BmatrixVal[   m_numBmatrixNonz ] = (wVal - uVal)/wVal ;
									//get index for j1, j2 with  j1  > j2
									//m_BmatrixIdx[   m_numBmatrixNonz++ ] = j1*(m_numNodes - 1) + j2    ;
									
									if(xVarIndexMap.find( indexPair) == xVarIndexMap.end()  ){
										std::cout << " Getting ready to call ErrorClass: kount = " << kount << std::endl;
										throw ErrorClass( "index mapping problem in generating multicommodity cut");
									}else{
										m_BmatrixIdx[   m_numBmatrixNonz++ ] = xVarIndexMap[ indexPair];
										cutString << m_variableNames[ xVarIndexMap[ indexPair] ]; 
									}
								}
								
							}else{
								
								if(  (-uVal > m_osDecompParam.zeroTol) || (uVal  > m_osDecompParam.zeroTol)  ){
									//variable -uVal*x(j1, j2)
									cutString << " ";
									cutString << - uVal;
									cutString << "*" ;
									//cutString << m_nodeName[ j1 ];
									//cutString << "," ;
									//cutString << m_nodeName[ j2] ;
									//cutString << ")  " ;
									m_BmatrixVal[   m_numBmatrixNonz ] = -uVal/wVal ;
									//get index for j1, j2 with  j1  > j2
									//m_BmatrixIdx[   m_numBmatrixNonz++ ] = j1*(m_numNodes - 1) + j2   ;
									if(xVarIndexMap.find( indexPair) == xVarIndexMap.end()  ){
										std::cout << " Getting ready to call ErrorClass: kount = " << kount << std::endl;
										throw ErrorClass( "index mapping problem in generating multicommodity cut");
									}else{
										m_BmatrixIdx[   m_numBmatrixNonz++ ] = xVarIndexMap[ indexPair];
										cutString << m_variableNames[ xVarIndexMap[ indexPair] ]; 
									}
								}
							}	
							kount++;
						}
					}//end loop on j1
					cutString << std::endl;
					std::cout << cutString.str() <<  " kount =  " << kount << std::endl; 
					std::cout << "OPTIMAL OBJECTIVE FUNCTION VALUE = " <<  objVal << std::endl;
					std::cout << "OPTIMAL W VALUE = " <<  wVal << std::endl;
					
					//now add the cut
					//
					m_numBmatrixCon++;
					m_pntBmatrix[ m_numBmatrixCon ] =  m_numBmatrixNonz;
					//we have taken care of the B-matrix -- the Xij space
					//now take care the theta indexes and values
					
					//scatter the constraint in the x - variables, we
					//are scattering the B matrix constraint just found

					for(j = m_pntBmatrix[  m_numBmatrixCon  - 1] ; 
					        j <  m_pntBmatrix[ m_numBmatrixCon  ] ; j++){
						
						m_tmpScatterArray[ m_BmatrixIdx[ j] ] = 1;
						scatterValues[ m_BmatrixIdx[ j] ]  = m_BmatrixVal[ j];
						std::cout  << m_variableNames[ m_BmatrixIdx[ j] ] << " xkij cut coeff =  " << m_BmatrixVal[ j] << std::endl;
						
					}

					//done with scatter operation
					
			
					
					if(numTheta != m_numThetaVar)throw 
							ErrorClass( "Inconsistent Number of theta variables in multicommondity cut separation problem" );
					
		
					for(thetaIdx = 0; thetaIdx < m_numThetaVar ; thetaIdx++){
						//make sure we only consider thetaIdx in convexity row k
						
						if(m_convexityRowIndex[ thetaIdx] == k){
							
							
							rowValue = 0;
							for(j = m_thetaPnt[ thetaIdx]; j < m_thetaPnt[ thetaIdx + 1] ;  j++){
								
								//std::cout << "row value  = " << rowValue << " m_tmpScatterArray[  j ]  " << m_tmpScatterArray[  j ] << std::endl;
								
								rowValue +=  m_tmpScatterArray[  m_thetaIndex[ j] ]*scatterValues[ m_thetaIndex[ j] ];
								//std::cout << "theta index " << thetaIdx << "  " << m_variableNames[ m_thetaIndex[ j]  ] << " = " << m_BmatrixVal[ j] << "   row value = " <<  rowValue << std::endl;
							}
							
							if(rowValue > m_osDecompParam.zeroTol || -rowValue > m_osDecompParam.zeroTol){
								//std::cout << "numNewRows  = " <<    numNewRows << "  m_newRowNonz[ numNewRows ]  " <<  m_newRowNonz[ numNewRows ] <<  std::endl;
								m_newRowColumnIdx[ numNewRows][ m_newRowNonz[ numNewRows ] ] = thetaIdx ;
								m_newRowColumnValue[ numNewRows][ m_newRowNonz[ numNewRows]++ ] = rowValue;
							}
							
						
						}//end of if on convexity row
						

					}//end loop on thetaIdx
					
					m_newRowLB[ numNewRows] = -OSDBL_MAX;
					m_newRowUB[ numNewRows] = 0;
					numNewRows++;
					
					
					//zero out the scatter array again
					for(j = m_pntBmatrix[  m_numBmatrixCon  - 1] ; 
					        j < m_pntBmatrix[  m_numBmatrixCon  ] ; j++){

					    m_tmpScatterArray[ m_BmatrixIdx[ j] ] = 0;
					    scatterValues[ m_BmatrixIdx[ j] ]  = 0;

					}
					//
					//done adding cut
					
					//kipp -- don't forget to increment the artificial variable since a cut is added
					//
					

					
					m_BmatrixRowIndex[ m_numBmatrixCon] = k;
					///
					
				}//end iff on positive obj value
				//set objcoefficient back to 0
				solver->osiSolver->setObjCoeff( i,  0 );
				
				//we have a cut so break from the loop
				//if(foundCut == true) break;
			}//end loop over i
			std::cout <<  std::endl << std::endl;
			
			//reset the coefficients
			
			for(i = 0; i < numVar; i++ ) solver->osiSolver->setObjCoeff( i,  0 );
			
			
		}//end loop over k
		
		delete[] wcoeff;
		wcoeff = NULL;
		
		delete[] scatterValues;
		scatterValues = NULL;
		
		numNonz = m_newRowNonz;
		colIdx =  m_newRowColumnIdx;
		values =  m_newRowColumnValue;
		rowUB =  m_newRowUB;
		rowLB =  m_newRowLB;
		
		for(i = 0; i < numNewRows; i++){
			
			//we found a row, add the corresponding artificial variables
			//to the transformation matrix
			m_numThetaVar++;
			m_convexityRowIndex[ m_numThetaVar] = -1;
			m_thetaPnt[ m_numThetaVar] = m_numThetaNonz;
		}

		return;
		
	
	} catch (const ErrorClass& eclass) {
		if(wcoeff != NULL){
			delete[] wcoeff;
			wcoeff = NULL;
		}
		
		
		
		if(scatterValues != NULL) {
			delete[] scatterValues;
			scatterValues = NULL;
		}
		

		throw ErrorClass(eclass.errormsg);

	}		

	
}//end getCutsMultiCommod

void OSBearcatSolverXij::getCutsX(const  double* x, const int numX,
		int &numNewRows, int*  &numNonz, int** &colIdx,
		double** &values, double* &rowLB, double* &rowUB) {
	//critical -- we are assuming that the size of x is going to be 
	// m_numNodes*(m_numNodes - 1)
	
	int i;
	int j;
	int k;
	int index;
	int rowKount;

	
	int indexAdjust = m_numNodes - m_numHubs;
	double* tmpRhs;
	int numSepRows = m_osinstanceSeparation->getConstraintNumber() ;
	
	tmpRhs = new double[ numSepRows ]; 
	
	for(i = 0; i < numSepRows; i++){
		
		tmpRhs[ i] = 0;
	}
	
	try{
		m_osinstanceSeparation->bConstraintsModified = true;
			
		for(i = 0; i < numX; i++){
			
			//get a postive theta
			if(x[ i] > m_osDecompParam.zeroTol){
				
				//the row index for x_{ij}
				rowKount = m_separationIndexMap[ i ];
				
				if(rowKount < OSINT_MAX ){
					
					tmpRhs[ rowKount] -= x[ i];
					
				}
				
			}
		}// end i loop
		
		for(i = indexAdjust; i < numSepRows - 1; i++){
			
			if(-tmpRhs[ i] > 1 + m_osDecompParam.zeroTol ){
			
				// quick and dirty does x_{ij} + x_{ji} <= 1 cut off anything
				//std::cout << " tmpRhs[ i] =  " << tmpRhs[ i]  << std::endl;
				//which variable is this 
				//kipp this an inefficient way of finding i and j -- improve this
				int tmpKount = indexAdjust;
				for(int i1 = m_numHubs; i1 < m_numNodes; i1++){
				
					for(int j1 = i1+1; j1 < m_numNodes; j1++){
						
						if(tmpKount ==  i){
							
							numNewRows = 1;
							
							m_newRowNonz[ 0] = 2;
							m_newRowUB[ 0] = 1;
							m_newRowLB[ 0] = 0;
						
							m_newRowColumnIdx[ 0][ 0 ] = i1*(m_numNodes - 1) + j1 - 1;
							m_newRowColumnIdx[ 0][ 1 ] = j1*(m_numNodes - 1) + i1;
							m_newRowColumnValue[ 0][ 0] = 1;
							m_newRowColumnValue[ 0][ 1] = 1;
						
							numNonz = m_newRowNonz;
							colIdx =  m_newRowColumnIdx;
							values =  m_newRowColumnValue;
							rowUB =  m_newRowUB;
							rowLB =  m_newRowLB;
							
							delete[] tmpRhs;
							tmpRhs = NULL;
							return;

							
							
						}
						
						tmpKount++;
					
					}// end loop on j1
					
				}//end loop on i1
			
			
			}//end if on tmpRHS
			
			m_separationClpModel->setRowUpper(i, tmpRhs[ i] );
			m_separationClpModel->setRowLower(i, tmpRhs[ i] );		

		}//end loop on i
		
		
		//std::cout << m_osinstanceSeparation->printModel() << std::endl;
	

		std::vector<int> dualIdx;
		std::vector<int>::iterator vit1;
		std::vector<int>::iterator vit2;
		
		//if the objective function value is greater than zero we have a cut
		//the cut is based on the nodes with dual value - 1
		
		for(k = 0; k < indexAdjust; k++){
			std::cout <<   std::endl << std::endl;
			
			
			m_separationClpModel->setRowUpper(k, 0.0);
			
			
			m_separationClpModel->primal();		
			
			if(m_separationClpModel->getObjValue() > m_osDecompParam.zeroTol){
				std::cout << "DOING SEPARATION FOR NODE "  << k + m_numHubs << std::endl;
				std::cout << "SEPERATION OBJ =  "  <<  m_separationClpModel->getObjValue() << std::endl;
				numNewRows = 1;
				m_newRowNonz[ 0] = 0;
				m_newRowLB[ 0] = 0;
			
				for(i = 0; i < m_numNodes - m_numHubs ; i++){
					//std::cout <<   m_osinstanceSeparation->getConstraintNames()[ i]   << " = " << m_separationClpModel->getRowPrice()[ i] << std::endl;
					if( m_separationClpModel->getRowPrice()[ i] - m_osDecompParam.zeroTol <= -1) dualIdx.push_back( i) ;
				}
				
				for (vit1 = dualIdx.begin(); vit1 != dualIdx.end(); vit1++) {
					
					i = *vit1 + m_numHubs;
					
					for (vit2 = dualIdx.begin(); vit2 != dualIdx.end(); vit2++) {
						
						j = *vit2 + m_numHubs;
						
						if( i > j ){
						
							index = i*(m_numNodes -1) + j;
							std::cout << "CUT VARIABLE = " << m_variableNames[ index] <<std::endl;
							m_newRowColumnValue[ 0][   m_newRowNonz[ 0] ] = 1.0;
							m_newRowColumnIdx[ 0][   m_newRowNonz[ 0]++ ] = index;
							
						}else{
							
							if( i < j ){
								
								index = i*(m_numNodes -1) + j - 1;
								std::cout << "CUT VARIABLE = " << m_variableNames[ index] <<std::endl;	
								m_newRowColumnValue[ 0][   m_newRowNonz[ 0] ] = 1.0;
								m_newRowColumnIdx[ 0][   m_newRowNonz[ 0]++ ] = index;
								
							}
						}
						
					}//end for on vit2
				}//end for on vit1
				

				m_newRowUB[ 0] =  dualIdx.size()  - 1;
				
				dualIdx.clear();
				//reset
				// don't adjust the kludge row
				for(i = indexAdjust; i < numSepRows - 1; i++){
					
					m_separationClpModel->setRowUpper(i, 0.0 );
					m_separationClpModel->setRowLower(i, 0.0 );
					
					
				}
				m_separationClpModel->setRowUpper(k, 1.0);
				delete[] tmpRhs;
				tmpRhs = NULL;

				
				numNonz = m_newRowNonz;
				colIdx =  m_newRowColumnIdx;
				values =  m_newRowColumnValue;
				rowUB =  m_newRowUB;
				rowLB =  m_newRowLB;
			
				return;
				
			
				
			}//end if on obj value		
			m_separationClpModel->setRowUpper(k, 1.0);
			dualIdx.clear();
			
		}//end loop on k
		
		//if we are here there was no cut
		//reset
		// don't adjust the kludge row
		for(i = indexAdjust; i < numSepRows - 1; i++){
			
			m_separationClpModel->setRowUpper(i, 0.0 );
			m_separationClpModel->setRowLower(i, 0.0 );
			
			
		}
		
		delete[] tmpRhs;
		tmpRhs = NULL;
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
	
}//end getCutsX


void OSBearcatSolverXij::calcReducedCost( const double* yA, const double* yB){
	
	int k;
	int i;
	int j;
	int l;
	int kount;
	
	int tmpVal;
	tmpVal = m_numNodes - 1;
	
	for(k = 0; k < m_numHubs; k++){
		kount = 0;
		
		for(l = 1; l <= m_upperBoundL[ k]; l++){
			
			
			for(i = 0; i< m_numNodes; i++){
				

				
				for(j = 0; j < i; j++){
				
					if(j < m_numHubs){
						
						m_rc[k][ kount++] = l*m_cost[ i*tmpVal + j ] ;
						
					}else{
						
						m_rc[k][ kount++] = l*m_cost[ i*tmpVal + j ] - yA[ j - m_numHubs] ;
					}
					
					
				}
				

				
				for(j = i + 1; j < m_numNodes; j++){
					
					
					if(j < m_numHubs){
					
						m_rc[k][ kount++] = l*m_cost[ i*tmpVal + j - 1 ];
					
					} else {
						
						
						m_rc[k][ kount++] = l*m_cost[ i*tmpVal + j - 1 ] - yA[ j - m_numHubs ];
						
					}
					
				}
				
				
			}
			
			
		}//end l loop
		
		
	}//end hub loop
	
	//now adjust for tour breaking constraints

	
	int startPnt ;
	
	for(i = 0; i < m_numBmatrixCon; i++){
		
		//get the xij
		
		for(j = m_pntBmatrix[ i]; j < m_pntBmatrix[ i + 1]; j++){
			
			
			
			for(k = 0; k < m_numHubs; k++){
				
				
				for(l = 1; l <= m_upperBoundL[ k]; l++){
					
					//startPnt = k*m_upperBoundL*(m_numNodes*m_numNodes - m_numNodes) + (l - 1)*(m_numNodes*m_numNodes - m_numNodes);
					startPnt = (l - 1)*(m_numNodes*m_numNodes - m_numNodes);
					
					if(m_BmatrixRowIndex[ i] == -1 || m_BmatrixRowIndex[ i] == k ) m_rc[ k][ startPnt + m_BmatrixIdx[ j] ]  -=  yB[ i]*m_BmatrixVal[ j];
					
				}
				
			}
			

		}
		
	}
	
}//end calcReducedCost


void OSBearcatSolverXij::createVariableNames( ){
	
	int i;
	int j;
	int kount;
	
	kount = 0;
	
	for(i = 0; i< m_numNodes; i++){
		
		//if we have (i, j) where j is hub then do not subtract off phi[ j]
		for(j = 0; j < i; j++){
			
			if(m_nodeName[ i] == "") m_variableNames[ kount] = makeStringFromInt("x(" , i);
				else m_variableNames[ kount] = "x("  +  m_nodeName[ i];
			if(m_nodeName[ i] == "") m_variableNames[ kount] += makeStringFromInt( "," , j);
				else m_variableNames[ kount] += "," +   m_nodeName[ j];
			m_variableNames[ kount] +=  ")"; 
			//std::cout << "GAIL VARIABLE NAME " << m_variableNames[ kount] << std::endl;
			
			kount++;
			
		}
		
		for(j = i + 1; j < m_numNodes; j++){
			
			if(m_nodeName[ i] == "") m_variableNames[ kount] = makeStringFromInt("x(" , i);
				else m_variableNames[ kount] = "x("  +  m_nodeName[ i];
			if(m_nodeName[ i] == "") m_variableNames[ kount] += makeStringFromInt( "," , j);
				else m_variableNames[ kount] += "," +   m_nodeName[ j];
			m_variableNames[ kount] +=  ")";
			
			//std::cout << "GAIL VARIABLE NAME " << m_variableNames[ kount] << std::endl;
			kount++;
			
		}
		
		
	}	
}//end createVariableNames

void OSBearcatSolverXij::createAmatrix(){
	
	//arrays for the coupling constraint matrix
	//this is in the x variable space, not theta
	//int* m_pntAmatrix;
	//int* m_Amatrix;
	
	
	int i;
	int j;
	int numNonz;
	
	//loop over nodes 
	m_pntAmatrix[ 0] = 0; 
	numNonz = 0;
	
	for(j = m_numHubs; j < m_numNodes; j++){
		
		
		for(i = 0; i < j; i++){
			
			m_Amatrix[ numNonz++] = i*(m_numNodes - 1) + j - 1 ;

		}
		
		for(i = j + 1; i < m_numNodes; i++){
			
			m_Amatrix[ numNonz++] = i*(m_numNodes - 1) + j ;		
			
		}
		
		m_pntAmatrix[ j - m_numHubs + 1]  = numNonz;
	
	}
	
	/*
	for(i = 0; i < m_numNodes - m_numHubs; i++){
		
		for(j = m_pntAmatrix[ i]; j <  m_pntAmatrix[ i + 1]; j++){
			
			std::cout << m_variableNames[  m_Amatrix[ j ] ] << std::endl;
			
		}

	}
	*/
	
}//end createAmatrix

void OSBearcatSolverXij::pauHana( std::vector<int> &m_zOptIndexes, int numNodes, int numColsGen){
	
	std::cout <<  std::endl;
	std::cout << "     PAU HANA TIME! " << std::endl;
	double cost;
	cost = 0;
	std::vector<int>::iterator vit;
	try{
		int i;
		int j;

		
		//we better NOT have any artifical variables positive
		//for(i = 0; i < numVarArt  ; i++){
		//	
		//	if(theta[ i] > m_osDecompParam.zeroTol) throw ErrorClass("we have a positive artificial variable");
		//}
		
		//for(i = 0; i < m_numThetaVar    ; i++){
		
			//cost += theta[ i]*m_thetaCost[ i ];
			//std::cout << "COLUMN VALUE = " << theta[ i] << std::endl;
			
		//}
		
		double routeDemand;
		
	
		int ivalue;
		int jvalue;
		
		for(vit = m_zOptIndexes.begin() ; vit != m_zOptIndexes.end(); vit++){
			
				i = *vit;
				std::cout <<  "x variables for column "  << i  << " CONVEXITY ROW = "<< m_convexityRowIndex[ i]  <<   std::endl;
				
				
				//cost += m_thetaCost[ i ];
				routeDemand = 0; 
				
				for(j = m_thetaPnt[ i];  j < m_thetaPnt[ i + 1] ;  j++){
				
					
					//std::cout <<  "INDEX = "    <<  m_thetaIndex[  j]  << std::endl;
					std::cout <<  m_variableNames[ m_thetaIndex[  j] ]  << " = "  <<  1  << " DISTANCE = " <<  m_cost[ m_thetaIndex[  j] ]  << std::endl;
					
					ivalue = (int)floor( m_thetaIndex[  j] /(m_numNodes - 1) );
					
					jvalue = m_thetaIndex[  j] - ivalue*(m_numNodes - 1);
					
					if(  jvalue  >= ivalue ){
						//std::cout << " i NODE NUMBER = " <<  ivalue   << std::endl;
						//std::cout << " j NODE NUMBER = " <<  jvalue + 1   << std::endl;
						//std::cout << " DEMAND =  = " <<  m_demand[ jvalue + 1]   << std::endl;
						routeDemand += m_demand[ jvalue + 1];

						
					}else{
						//std::cout << " i NODE NUMBER = " <<  ivalue   << std::endl;
						//std::cout << " j NODE NUMBER = " <<  jvalue    << std::endl;
						//std::cout << " DEMAND =  = " <<  m_demand[ jvalue ]   << std::endl;
						routeDemand += m_demand[ jvalue ];
					}
				}
				
				std::cout <<  "route demand = " << routeDemand << std::endl << std::endl;
				std::cout <<  "distance for this route "  << m_thetaCost[ i ] / routeDemand  << std::endl;
				
		}
		
		
		//std::cout <<  "cost = " << cost << std::endl << std::endl;
		
		std::cout << std::endl <<  std::endl;
		std::cout << "LOWER BOUND VALUE = " << m_bestLPValue << std::endl;
		std::cout << "FINAL BEST IP SOLUTION VALUE = " << m_bestIPValue << std::endl;
		std::cout << "NUMBER OF COLUMNS IN FINAL MASTER = " << m_numThetaVar << std::endl;
		//std::cout << "NUMBER OF GENERATED COLUMNS = " << m_numThetaVar - 2*m_numNodes - 2*m_numBmatrixCon << std::endl;
		//the original master has m_numHubs + m_numNodes columns
		std::cout << "NUMBER OF GENERATED COLUMNS = " << numColsGen << std::endl;
		std::cout << "NUMBER OF GENERATED CUTS  = " << m_numBmatrixCon  << std::endl;
		std::cout << "NUMBER OF NODES  = " <<  numNodes  << std::endl;
		std::cout << "        PAU!!!" << std::endl;
		
		std::cout << std::endl <<  std::endl;
	
		std::cout << std::endl <<  std::endl;
	}catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	
		
}//end pauHana -- no pun intended


OSInstance* OSBearcatSolverXij::getSeparationInstance(){
	

	
	
	m_osinstanceSeparation = NULL;
	
	//add linear constraint coefficients
	//number of values will nodes.size() the coefficients in the node constraints
	//plus coefficients in convexity constraints which is the number of varaibles
	int kountNonz;
	int kount;
	int startsIdx;
	//we build these on nodes that do not include the hubs
	int numYvar = (m_numNodes - m_numHubs)*(m_numNodes - m_numHubs - 1);
	int numVvar = m_numNodes - m_numHubs;
	//the plus 1 is for the kludge row
	int numCon = (m_numNodes - m_numHubs) + (m_numNodes - m_numHubs)*(m_numNodes - m_numHubs - 1)/2 + 1;
	double *values = new double[ 2*numYvar + 2*numVvar];
	int *indexes = new int[ 2*numYvar + 2*numVvar];
	int *starts = new int[ numYvar + numVvar + 1]; 
	starts[ 0] = 0;	
	startsIdx = 0;
	startsIdx++;
	kountNonz = 0;
	int i;
	int j;
	
			
	std::string separationVarName;
	std::string separationConName;

	try {
		
		m_osinstanceSeparation = new OSInstance();
		
		//start building the separation instance

		m_osinstanceSeparation->setInstanceDescription("The Tour Breaking Separation Problem");

		
		// now the constraints
		m_osinstanceSeparation->setConstraintNumber( numCon); 
		
		
		//add the node rows
		for( i =  0; i < m_numNodes - m_numHubs ; i++){
			
			m_osinstanceSeparation->addConstraint(i,  makeStringFromInt("nodeRow_", i+  m_numHubs ) , 0.0, 1.0, 0); 
			
		}
		
		//add the variable rows rows
	
		int rowKounter;
		rowKounter = m_numNodes - m_numHubs;
		
		for(i = m_numHubs; i < m_numNodes; i++){
			
			
			
			for(j = i+1; j < m_numNodes; j++){
				separationConName = makeStringFromInt("Row_(", i);
				separationConName += makeStringFromInt(",", j);
				separationConName += ")";
				
				m_osinstanceSeparation->addConstraint(rowKounter++,  separationConName , 0, 0, 0); 
			}
			
		}	
		
		// the klude row so we have +/-1 in every column
		m_osinstanceSeparation->addConstraint(rowKounter++,  "kludgeRow" , 0, m_numNodes, 0);
		
		//  the variables
		m_osinstanceSeparation->setVariableNumber(  numYvar + numVvar);   
		
		
		
		std::cout << "NUMBER OF VARIABLES SET = " << numYvar + numVvar << std::endl;
		//add the v variables
		for(i = 0; i < numVvar; i++){
			
			separationVarName = makeStringFromInt("v", i + m_numHubs);
			
			m_osinstanceSeparation->addVariable(i, separationVarName, 0, 1, 'C');
			
			values[ kountNonz ] = -1.0;
			indexes[ kountNonz ] = i;
			kountNonz++;
			
			values[ kountNonz ] = 1.0;
			indexes[ kountNonz ] = rowKounter - 1;
			kountNonz++;
			
			
			
			starts[ startsIdx++ ] = kountNonz;
			
			
		}
		//add the y variables
		kount = numVvar;
		
		int i1;
		int j1;
		int kountCon;
		kountCon = m_numNodes - m_numHubs;
		
		for(i1 = 0; i1 < m_numNodes - m_numHubs; i1++){
			

			i = i1 + m_numHubs;
			
			for(j1 = i1 + 1; j1 < m_numNodes - m_numHubs; j1++){
				
	
				j = j1 + m_numHubs;
				
				separationVarName = makeStringFromInt("y(", i);
				separationVarName += makeStringFromInt(",", j);
				separationVarName += ")";
				m_osinstanceSeparation->addVariable(kount++, separationVarName, 0, 1, 'C');
				
				//map the variable to row kountCon
				
				// i < j case
				m_separationIndexMap[ i*(m_numNodes - 1)  + (j - 1) ] = kountCon;
				
				values[ kountNonz ] = 1.0;
				indexes[ kountNonz ] = i1;
				kountNonz++;
						
				values[ kountNonz ] = -1.0;
				indexes[ kountNonz ] = kountCon ;
				kountNonz++;
			
				starts[ startsIdx++ ] = kountNonz;
				
				
				
				
				separationVarName = makeStringFromInt("y(", j );
				separationVarName += makeStringFromInt(",", i);
				separationVarName += ")";
				m_osinstanceSeparation->addVariable(kount++, separationVarName, 0, 1, 'C');
				
				values[ kountNonz ] = 1.0;
				indexes[ kountNonz ] = j1;
				kountNonz++;
				
				// i < j case
				m_separationIndexMap[ j*(m_numNodes - 1)  + i ] = kountCon;
				
				values[ kountNonz ] = -1.0;
				indexes[ kountNonz ] = kountCon ;
				kountNonz++;
			
				starts[ startsIdx++ ] = kountNonz;
				
				
				kountCon++;
				
				
			}
			
		}
		
		std::cout << "NUMBER OF VARIABLES ADDED = " << kount << std::endl;
		
		// now add the objective function
		m_osinstanceSeparation->setObjectiveNumber( 1);
		SparseVector *objcoeff = new SparseVector( numVvar);  

		
		for(i = 0; i < numVvar; i++){
			
			objcoeff->indexes[ i] = i;
			objcoeff->values[ i] = 1.0;
		
		}
		

	
	
		
		m_osinstanceSeparation->addObjective(-1, "objfunction", "min", 0.0, 1.0, objcoeff);
		//now for the nonzeros
		//add the linear constraints coefficients
		m_osinstanceSeparation->setLinearConstraintCoefficients(kountNonz , true, 
				values, 0, kountNonz - 1,  indexes, 0, kountNonz - 1, starts, 0, startsIdx);
	
		
		
		//std::cout << m_osinstanceSeparation->printModel(  ) << std::endl;	
		//
		delete objcoeff;
		
		
		// now create the Clp model
		
		
		//below is temporty see if we can setup as a Clp network problem
	    CoinPackedMatrix* matrix;
	    bool columnMajor = true;
	    double maxGap = 0;
		matrix = new CoinPackedMatrix(
		columnMajor, //Column or Row Major
		columnMajor? m_osinstanceSeparation->getConstraintNumber() : m_osinstanceSeparation->getVariableNumber(), //Minor Dimension
		columnMajor? m_osinstanceSeparation->getVariableNumber() : m_osinstanceSeparation->getConstraintNumber(), //Major Dimension
		m_osinstanceSeparation->getLinearConstraintCoefficientNumber(), //Number of nonzeroes
		columnMajor? m_osinstanceSeparation->getLinearConstraintCoefficientsInColumnMajor()->values : m_osinstanceSeparation->getLinearConstraintCoefficientsInRowMajor()->values, //Pointer to matrix nonzeroes
		columnMajor? m_osinstanceSeparation->getLinearConstraintCoefficientsInColumnMajor()->indexes : m_osinstanceSeparation->getLinearConstraintCoefficientsInRowMajor()->indexes, //Pointer to start of minor dimension indexes -- change to allow for row storage
		columnMajor? m_osinstanceSeparation->getLinearConstraintCoefficientsInColumnMajor()->starts : m_osinstanceSeparation->getLinearConstraintCoefficientsInRowMajor()->starts, //Pointers to start of columns.
		0,   0, maxGap ); 
		
		ClpNetworkMatrix network( *matrix);
		
		m_separationClpModel = new ClpSimplex();
		
		//if( m_osinstanceSeparation->getObjectiveMaxOrMins()[0] == "min") osiSolver->setObjSense(1.0);
	    m_separationClpModel->setOptimizationDirection( 1);
		m_separationClpModel->loadProblem( network, m_osinstanceSeparation->getVariableLowerBounds(), 
				m_osinstanceSeparation->getVariableUpperBounds(),  
				m_osinstanceSeparation->getDenseObjectiveCoefficients()[0], 
				m_osinstanceSeparation->getConstraintLowerBounds(), m_osinstanceSeparation->getConstraintUpperBounds()
		);
		
		m_separationClpModel->factorization()->maximumPivots(200 + m_separationClpModel->numberRows() / 100);
		
		
		delete matrix;
		
	}catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	
	
	return NULL;
}//end getSeparationInstance



int OSBearcatSolverXij::getBranchingVar(const double* theta, const int numThetaVar ) {

	int varIdx;
	varIdx = -1;
	int i;
	int j;
	int numVar = m_numNodes*m_numNodes - m_numHubs ;
	
	double from1Distance;
	double from0Distance;
	double fraction;
	double minFraction;
	
	double *xvalues;
	
	
	xvalues = new double[ numVar];
	for(i = 0; i < numVar; i++){
		xvalues[ i] = 0;
	}
	
	try{
		if(numThetaVar != m_numThetaVar) throw ErrorClass("inconsistent number of variables in getBranchingVar");
		//loop over the fractional thetas
		for(i = 0; i < m_numThetaVar; i++){
			
			if( ( theta[ i  ] > m_osDecompParam.zeroTol ) && ( theta[ i  ] < 1 - m_osDecompParam.zeroTol ) ){
				
				for(j = m_thetaPnt[ i];  j < m_thetaPnt[ i + 1] ;  j++){
					
					xvalues[  m_thetaIndex[  j] ] += theta[ i  ] ;
					
				}	
			
			}
	
			
		}
	
		//let's branch on a variable in and out of hub first
		minFraction = 1.0;
		//ideally we find minFraction very close to .5
		
		for(i = 0; i < m_numHubs; i++){
			
			for( j = 0;  j < i;  j++){
				
				//j < i so the index is i*(m_numNodes - 1) + j
				from1Distance = 1 - xvalues[ i*(m_numNodes - 1) + j  ];
				from0Distance = xvalues[ i*(m_numNodes - 1) + j  ];
				fraction = std::max(from1Distance, from0Distance);
				//try to find fractional variable that is the closest to .5
				if(fraction < minFraction){
					
					minFraction = fraction;
					varIdx = i*(m_numNodes - 1) + j;
				}
				
			}
			
			for(j = i + 1;  j < m_numNodes;  j++){
				
				//j < i so the index is i*(m_numNodes - 1) + j - 1
				//j < i so the index is i*(m_numNodes - 1) + j
				from1Distance = 1 - xvalues[ i*(m_numNodes - 1) + j - 1 ];
				from0Distance = xvalues[ i*(m_numNodes - 1) + j - 1 ];
				fraction = std::max(from1Distance, from0Distance);
				//try to find fractional variable that is the closest to .5
				if(fraction < minFraction) {
					
					minFraction = fraction;
					varIdx = i*(m_numNodes - 1) + j - 1;
				}
				
				
			}
			
		}
		
		//if we have a candidate among arcs in/out of hubs, take it
		
		if(minFraction > 1 - m_osDecompParam.zeroTol){
			
			for(i = m_numHubs; i < m_numNodes; i++){
				
				for( j = 0;  j < i;  j++){
					
					//j < i so the index is i*(m_numNodes - 1) + j
					from1Distance = 1 - xvalues[ i*(m_numNodes - 1) + j  ];
					from0Distance = xvalues[ i*(m_numNodes - 1) + j  ];
					fraction = std::max(from1Distance, from0Distance);
					//try to find fractional variable that is the closest to .5
					if(fraction < minFraction) {
						
						minFraction = fraction;
						varIdx = i*(m_numNodes - 1) + j ;
					}
					
				}
				
				for(j = i + 1;  j < m_numNodes;  j++){
					
					//j < i so the index is i*(m_numNodes - 1) + j - 1
					//j < i so the index is i*(m_numNodes - 1) + j
					from1Distance = 1 - xvalues[ i*(m_numNodes - 1) + j - 1 ];
					from0Distance = xvalues[ i*(m_numNodes - 1) + j - 1 ];
					fraction = std::max(from1Distance, from0Distance);
					//try to find fractional variable that is the closest to .5
					if(fraction < minFraction) {
						
						minFraction = fraction;
						varIdx = i*(m_numNodes - 1) + j - 1;
					}
					
				}
				
			}
		
		}//end of if on minFraction

	
		delete[] xvalues;

		xvalues = NULL;
		
		return varIdx;
	
	}catch (const ErrorClass& eclass) {
		
		delete[] xvalues;
		xvalues = NULL;

		throw ErrorClass(eclass.errormsg);

	}	

	
}//end getBranchingVar Dense



int OSBearcatSolverXij::getBranchingVar(const int* thetaIdx, const double* theta, 
		const int numThetaVar) {

	int varIdx;
	varIdx = -1;
	int i;
	int j;
	int numVar = m_numNodes*m_numNodes - m_numHubs ;
	double from1Distance;
	double from0Distance;
	double fraction;
	double minFraction;
	
	double *xvalues;
	
	
	xvalues = new double[ numVar];
	for(i = 0; i < numVar; i++){
		xvalues[ i] = 0;
	}
	
	try{
		//loop over the fractional thetas
		//working with a sparse matrix
		for(i = 0; i < numThetaVar; i++){
			
			if( ( theta[ i  ] > m_osDecompParam.zeroTol ) && ( theta[ i  ] < 1 - m_osDecompParam.zeroTol ) ){
				
				for(j = m_thetaPnt[ thetaIdx[ i] ];  j < m_thetaPnt[ thetaIdx[ i]  + 1] ;  j++){
					
					xvalues[  m_thetaIndex[  j] ] += theta[ i  ] ;
					
				}	
			
			}
	
			
		}
	
	
		//let's branch on a variable in and out of hub first
		minFraction = 1.0;
		//ideally we find minFraction very close to .5
		
		for(i = 0; i < m_numHubs; i++){
			
			for( j = 0;  j < i;  j++){
				
				//j < i so the index is i*(m_numNodes - 1) + j
				from1Distance = 1 - xvalues[ i*(m_numNodes - 1) + j  ];
				from0Distance = xvalues[ i*(m_numNodes - 1) + j  ];
				fraction = std::max(from1Distance, from0Distance);
				//try to find fractional variable that is the closest to .5
				if(fraction < minFraction){
					
					minFraction = fraction;
					varIdx = i*(m_numNodes - 1) + j;
				}
				
			}
			
			for(j = i + 1;  j < m_numNodes;  j++){
				
				//j < i so the index is i*(m_numNodes - 1) + j - 1
				//j < i so the index is i*(m_numNodes - 1) + j
				from1Distance = 1 - xvalues[ i*(m_numNodes - 1) + j - 1 ];
				from0Distance = xvalues[ i*(m_numNodes - 1) + j - 1 ];
				fraction = std::max(from1Distance, from0Distance);
				//try to find fractional variable that is the closest to .5
				if(fraction < minFraction) {
					
					minFraction = fraction;
					varIdx = i*(m_numNodes - 1) + j - 1;
				}
				
				
			}
			
		}
		
		//if we have a candidate among arcs in/out of hubs, take it
		
		std::cout << "MIN FRACTION = " <<  minFraction << std::endl;
		
		if(minFraction > 1 - m_osDecompParam.zeroTol){
		
			for(i = m_numHubs; i < m_numNodes; i++){
				
				
				
				for( j = 0;  j < i;  j++){
					
					//j < i so the index is i*(m_numNodes - 1) + j
					from1Distance = 1 - xvalues[ i*(m_numNodes - 1) + j  ];
					from0Distance = xvalues[ i*(m_numNodes - 1) + j  ];
					fraction = std::max(from1Distance, from0Distance);
					//try to find fractional variable that is the closest to .5
					if(fraction < minFraction) {
						
						minFraction = fraction;
						varIdx = i*(m_numNodes - 1) + j ;
					}
					
				}
				
				for(j = i + 1;  j < m_numNodes;  j++){
					
					//j < i so the index is i*(m_numNodes - 1) + j - 1
					//j < i so the index is i*(m_numNodes - 1) + j
					from1Distance = 1 - xvalues[ i*(m_numNodes - 1) + j - 1 ];
					from0Distance = xvalues[ i*(m_numNodes - 1) + j - 1 ];
					fraction = std::max(from1Distance, from0Distance);
					//try to find fractional variable that is the closest to .5
					if(fraction < minFraction) {
						
						minFraction = fraction;
						varIdx = i*(m_numNodes - 1) + j - 1;
					}
					
				}
				
			}
		
		}//end of if on minFraction
		
		//zero out the scatter array
		
		delete[] xvalues;
		xvalues = NULL;
		
		return varIdx;
	
	}catch (const ErrorClass& eclass) {
		
		delete[] xvalues;
		xvalues = NULL;

		throw ErrorClass(eclass.errormsg);

	}	

	
}//end getBranchingVar Sparse


void OSBearcatSolverXij::getBranchingCut(const double* thetaVar, const int numThetaVar,
		const std::map<int, int> &varConMap, int &varIdx,  int &numNonz, 
		int* &indexes,  double* &values) {
	
	//get a branching variable
	int i;
	int j;
	int kount;
	numNonz = 0;
	//keep numNonz at zero if there is no cut
	//there will be no cut if the xij is in conVarMap
	
	try{
		
		if(numThetaVar != m_numThetaVar) throw ErrorClass("inconsistent number of variables in getBranchingCut");
	
		
		varIdx = getBranchingVar(thetaVar, numThetaVar );
		std::cout << "VARIABLE INDEX = " << varIdx << std::endl;
		std::cout << "Branching on Variable:  " << m_variableNames[ varIdx] << std::endl;
		
		//if this variable is in the map, then we just return with the index, 
		//if this variable is NOT in the map then we add a cut
		
		if( varConMap.find( varIdx) == varConMap.end() ){
			
			for(i = 0; i < m_numThetaVar; i++){
				
				kount = 0;
				
				for(j = m_thetaPnt[ i];  j < m_thetaPnt[ i + 1] ;  j++){
					
					if ( m_thetaIndex[  j]  == varIdx) kount++ ;
					
				}
				
				//count is the number times variable i appears in the constraint
				
				if(kount > 0){
					
					branchCutIndexes[ numNonz] = i;
					branchCutValues[ numNonz++] = kount ;
					
				}
				
			}
			
			
			//add varIdx cut to B matrix
			m_BmatrixVal[ m_numBmatrixNonz] = 1;
			m_BmatrixIdx[ m_numBmatrixNonz++] = varIdx;
			m_numBmatrixCon++;
			m_pntBmatrix[ m_numBmatrixCon] = m_numBmatrixNonz;
			
			//make sure to add artificial variables
			//of course they have no nonzero elements in 
			//the transformation matrix
			m_numThetaVar++;
			m_convexityRowIndex[ m_numThetaVar] = -1;
			m_thetaPnt[ m_numThetaVar] = m_numThetaNonz;
			//m_thetaPnt[ m_numThetaVar++] = m_numThetaNonz; //first artificial variable
			//m_thetaPnt[ m_numThetaVar] = m_numThetaNonz; //second artificial variable
		
		
		}//end of if on checking for map membership
		
		//set return arguments
		
		indexes = branchCutIndexes;
		values = branchCutValues;
		
		return;
	
	}catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	
	
}//end getBranchingCut dense


void OSBearcatSolverXij::getBranchingCut(const int* thetaIdx, const double* thetaVar, 
		const int numThetaVar, const std::map<int, int> &varConMap, 
		int &varIdx,  int &numNonz, int* &indexes, double* &values) {
	
	//get a branching variable
	int i;
	int j;
	int kount;
	numNonz = 0;
	//keep numNonz at zero if there is no cut
	//there will be no cut if the xij is in conVarMap
	
	try{
		
		
	
		varIdx = getBranchingVar(thetaIdx, thetaVar, numThetaVar );
		
		std::cout << "Branching on Variable:  " << m_variableNames[ varIdx] << std::endl;
		
		//if this variable is in the map, then we just return with the index, 
		//if this variable is NOT in the map then we add a cut
		
		if( varConMap.find( varIdx) == varConMap.end() ){
			
			
			
			
			
			
			for(i = 0; i < m_numThetaVar; i++){
				
				kount = 0;
				
				for(j = m_thetaPnt[ i];  j < m_thetaPnt[ i + 1] ;  j++){
					
					if ( m_thetaIndex[  j]  == varIdx) kount++ ;
					
				}
				
				//count is the number times variable i appears in the constraint
				
				if(kount > 0){
					
					branchCutIndexes[ numNonz] = i;
					branchCutValues[ numNonz++] = kount ;
					
				}
				
			}
			
			
			//add varIdx cut to B matrix
			m_BmatrixVal[ m_numBmatrixNonz] = 1.0;
			m_BmatrixIdx[ m_numBmatrixNonz++] = varIdx;
			m_numBmatrixCon++;
			m_pntBmatrix[ m_numBmatrixCon] = m_numBmatrixNonz;
			
			//make sure to add artificial variables
			//of course they have no nonzero elements in 
			//the transformation matrix
			m_numThetaVar++;
			m_convexityRowIndex[ m_numThetaVar] = -1;
			m_thetaPnt[ m_numThetaVar] = m_numThetaNonz;
			//m_thetaPnt[ m_numThetaVar++] = m_numThetaNonz; //first artificial variable
			//m_thetaPnt[ m_numThetaVar] = m_numThetaNonz; // second artificial variable
		
		
		}//end of if on checking for map membership
		
		//set return arguments
		
		indexes = branchCutIndexes;
		values = branchCutValues;
		
		return;
	
	}catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	
	
}//end getBranchingCut sparse


void OSBearcatSolverXij::getInitialSolution(){
	
	try{	

		
		if( OneOPT() == false) 
			throw ErrorClass("no initilal feasible solution");
		
	}catch (const ErrorClass& eclass) {
	
		throw ErrorClass(eclass.errormsg);
	
	}	
	
	
}//end getInitialSolution


void OSBearcatSolverXij::resetMaster( std::map<int, int> &inVars, OsiSolverInterface *si){
	
	int i;
	int j;

	int kount;
	int numNonz;

	std::map<int, int>::iterator mit;
	//temporarily create memory for the columns we keep
	int numVars = inVars.size();
	int numVarArt;
	//there 2*m_numNodes in the A matrix
	//there are  m_numBmatrixCon B matrix constraints
	//numVarArt = 2*m_numNodes +  2*m_numBmatrixCon;
	numVarArt = m_numNodes +  m_numBmatrixCon;
	
	//arrays for the new osinstance
	std::vector<double> valuesVec;
	double *values = NULL;
	
	std::vector<int> indexesVec;
	int *indexes = NULL  ;
	
	int *starts = new int[ numVars + 1 + numVarArt]; 
	
	int startsIdx;



	//temporay holders
	int* thetaPntTmp;
	int* thetaIndexTmp;
	int*  tmpConvexity = new int[  m_numThetaVar];
	
	//get the number of nonzeros that we need
	numNonz = 0;
	
	for(mit = inVars.begin();  mit != inVars.end(); mit++){
		
		numNonz += m_thetaPnt[mit->first + 1 ] - m_thetaPnt[ mit->first ];
	}
	
	//allocate the memory
	thetaPntTmp = new int[ numVars + 1];
	thetaIndexTmp = new int[ numNonz];
	
	
	//error check
	for(mit = inVars.begin();  mit != inVars.end(); mit++){
		
		
		//std::cout << "VARIABLE INDEX =  " <<  mit->first  << " OBJ COEF = " <<  si->getObjCoefficients()[ mit->first ] << std::endl;
		if( m_convexityRowIndex[ mit->first] == -1) throw ErrorClass( "we have an artificial variable in reset master");
		
		
	}
	
	//fill in the temporary arrays
	kount = 0;
	numNonz = 0;
	thetaPntTmp[ kount] = 0;
	
	for(mit = inVars.begin();  mit != inVars.end(); mit++){
		
		//std::cout << "mit->first " <<   mit->first << "  mit->second   " << mit->second   << std::endl;
		
		kount++;
		
		for(i = m_thetaPnt[ mit->first ]; i < m_thetaPnt[mit->first + 1 ]; i++){
			
			thetaIndexTmp[ numNonz++] = m_thetaIndex[ i];
			
			//std::cout << "Column = " <<   mit->first << "  Variable   " <<   m_variableNames[ m_thetaIndex[ i] ]   << std::endl;
			
		}
		
		thetaPntTmp[ kount] = numNonz;
		
		//std::cout << "kount =  " << kount << "  thetaPntTmp[ kount] = " << thetaPntTmp[ kount] << std::endl;
		//readjust numbering to take into account artificial variables
		//mit->second += numVarArt;
		//kipp -- double check calculation below
		inVars[ mit->first] = numVarArt + kount - 1 ;
		
	}
	
	//std::cout << "kount = " <<  kount  << std::endl;
	//std::cout << "numVars = " << numVars  << std::endl;
	

	
	//copy old values of m_convexityRowIndex
	for(i = 0; i < m_numThetaVar; i++) tmpConvexity[ i] = m_convexityRowIndex[ i];
	
	//reset the theta pointers
	//first the artificial variables
	m_numThetaVar = 0;
	m_numThetaNonz = 0;
	for(i = 0; i < numVarArt; i++){
		
		m_convexityRowIndex[ m_numThetaVar] = -1;
		m_thetaPnt[ m_numThetaVar++] = 0;
		
		
	}
	//now fill in the other pointers from the temp arrarys
	//std::cout << "Number of artificial variables =  " << numVarArt   << std::endl;
	intVarSet.clear();
	for(mit = inVars.begin();  mit != inVars.end(); mit++){
		
		
		intVarSet.insert ( std::pair<int,double>(mit->second, 1.0) );
		
		//std::cout << " m_numThetaVar =  "  << m_numThetaVar << "  m_numThetaNonz =  " <<  m_numThetaNonz  << std::endl;
		//std::cout << "Variable number " << mit->first << "  OBJ coefficient = " <<   si->getObjCoefficients()[  mit->first] << std::endl;
		
		m_convexityRowIndex[ m_numThetaVar] = tmpConvexity[ mit->first];
		
		m_thetaPnt[ m_numThetaVar++ ] = m_numThetaNonz;
		
		for(j = thetaPntTmp[ mit->second - numVarArt]; j < thetaPntTmp[ mit->second - numVarArt  + 1 ]; j++){
		
			
			m_thetaIndex[ m_numThetaNonz ] = thetaIndexTmp[ m_numThetaNonz] ;
			m_numThetaNonz++;
			
		}
		
	}
	
	m_thetaPnt[ m_numThetaVar ] = m_numThetaNonz;
	//std::cout << " number of art vars = " <<  numVarArt  << std::endl;
	//std::cout << " m_numThetaVar = " <<  m_numThetaVar  << std::endl;
	//std::cout << " m_numThetaNonz = " <<  m_numThetaNonz  << std::endl;
	//done with the transformation matrix
	

	
	//
	//write old master --- just for testing
	si->writeLp( "gailTest" );
	
	//now create the formulation
	
	//first get each column of the new master
	//first take care of the artificial variables
	numNonz = 0;
	startsIdx = 0;
	starts[ startsIdx++] = numNonz;	

	for(i = 0; i < numVarArt; i++){
		numNonz++;
		starts[ startsIdx++] = numNonz;
		valuesVec.push_back( 1.0);
		indexesVec.push_back( i);
		
	}
	
	
	int rowCount;
	
	int numAmatrixRows;
	numAmatrixRows = m_numNodes - m_numHubs;
	
	for(mit = inVars.begin();  mit != inVars.end(); mit++){
		
		//std::cout << "CONVEXITY ROW = " << m_convexityRowIndex[ mit->second]  << std::endl;
		valuesVec.push_back( 1.0);
		indexesVec.push_back( numAmatrixRows + m_convexityRowIndex[ mit->second] );
		//increment numNonz by 1 for the convexity row
		numNonz++;
		
		for(j = m_thetaPnt[ mit->second ]; j < m_thetaPnt[ mit->second + 1 ]; j++){
			
			m_tmpScatterArray[ m_thetaIndex[ j] ]++;
			
			//std::cout << "Column = " <<  mit->second << "  Variable   " <<   m_variableNames[ m_thetaIndex[ j] ]   << std::endl;
			
		}
		

	
		//multiply the sparse array by each A matrix constraint
		for(i = 0; i < numAmatrixRows; i++){
			
			rowCount = 0;
			
			for(j = m_pntAmatrix[ i]; j < m_pntAmatrix[ i + 1]; j++){
				
				//m_Amatrix[ j] is a variable index -- this logic works
				//since the Amatrix coefficient is 1 -- we don't need a value
				//it indexes variable that points into the node
				rowCount += m_tmpScatterArray[  m_Amatrix[ j] ];
				

			}
			
			if(rowCount > 0){
				
				numNonz++;
				
				//std::cout << "Column = " <<  mit->second << "  Nonzero in A marix row  " << i  <<  " Value = " << rowCount << std::endl;
				valuesVec.push_back( rowCount);
				indexesVec.push_back( i);

				
			}
				
				
		}//end loop on coupling constraints
		
		
		//multiply the sparse array by each B matrix constraint
		for(i = 0; i < m_numBmatrixCon; i++){
			
			rowCount = 0;
			
			for(j = m_pntBmatrix[ i]; j < m_pntBmatrix[ i + 1]; j++){
				
				//m_Amatrix[ j] is a variable index -- this logic works
				//since the Amatrix coefficient is 1 -- we don't need a value
				//it indexes variable that points into the node
				rowCount += m_tmpScatterArray[  m_BmatrixIdx[ j] ];
				

			}
			
			if(rowCount > 0){
				numNonz++;
				
				//std::cout << "Column = " <<  mit->first << "  Nonzero in B matrix row  " << i  + m_numNodes<<  " Value = " << rowCount << std::endl;

				valuesVec.push_back( rowCount);
				indexesVec.push_back( i + m_numNodes);
			}
				
				
		}//end loop on B matrix constraints
		
		
		//zero out the scatter array
		
		for(j = m_thetaPnt[ mit->second ]; j < m_thetaPnt[ mit->second + 1 ]; j++){
			
			m_tmpScatterArray[ m_thetaIndex[ j] ] = 0;
			
		}
		
		starts[ startsIdx++] = numNonz;	
		
	}
	

	//for(i = 0; i < startsIdx; i++) std::cout << "starts[ i] = " << starts[ i] << std::endl;
	values = new double[ numNonz];
	indexes = new int[ numNonz];
	
	if( (unsigned int)numNonz != valuesVec.size() ) throw ErrorClass("dimension problem in reset");
	if( (unsigned int)numNonz != indexesVec.size() ) throw ErrorClass("dimension problem in reset");
	
	for(i = 0; i < numNonz; i++){
		
		values[ i] = valuesVec[i];
		indexes[ i] = indexesVec[i];
		
	}
	

	
	//construct the new master
	//create an OSInstance from the tmp arrays
	// delete the old  m_osinstanceMaster
	
	delete m_osinstanceMaster;
	m_osinstanceMaster = NULL;
	
	//start building the restricted master here
	m_osinstanceMaster = new OSInstance();
	m_osinstanceMaster->setInstanceDescription("The Restricted Master");
	
	// first the variables
	// we have numVarArt] artificial variables 
	m_osinstanceMaster->setVariableNumber( numVars + numVarArt );   
	
	// now add the objective function
	//m_osinstanceMaster->setObjectiveNumber( 1);
	//add m_numNodes artificial variables
	SparseVector *objcoeff = new SparseVector( numVars + numVarArt);   
	


	// now the constraints
	m_osinstanceMaster->setConstraintNumber( m_numNodes  + m_numBmatrixCon); 
	
	
	//add the artificial variables first
	
	int varNumber;
	varNumber = 0;
	

	//define the artificial variables
	for(i = 0; i < numVarArt; i++){
		
		objcoeff->indexes[ varNumber ] = varNumber ;

		objcoeff->values[ varNumber ] = m_osDecompParam.artVarCoeff;
		
		m_thetaCost[ varNumber] = m_osDecompParam.artVarCoeff;
		
		m_osinstanceMaster->addVariable(varNumber++, makeStringFromInt("x", i ) , 
				0, 1.0, 'C');	
		

	}
	
	// now the theta variables
	kount = 0;
	for(mit = inVars.begin();  mit != inVars.end(); mit++){
		
		objcoeff->indexes[ varNumber ] = varNumber ;

		objcoeff->values[ varNumber ] = si->getObjCoefficients()[ mit->first] ;
		
		m_thetaCost[ varNumber] = si->getObjCoefficients()[ mit->first];
		
		m_osinstanceMaster->addVariable(varNumber++, makeStringFromInt("x", kount + numVarArt ) , 
				0, 1.0, 'C');	
		
		kount++;
		
	
		
	}


	
	for(i = 0; i < m_numNodes; i++){
		
		m_osinstanceMaster->addConstraint(i,  makeStringFromInt("con", i), 
				1.0, 1.0, 0);
	
	}
	
	
	for(i = m_numNodes; i <  m_numBmatrixCon + m_numNodes; i++){
		
		m_osinstanceMaster->addConstraint(i,  makeStringFromInt("con", i), 
				si->getRowLower()[ i], si->getRowUpper()[ i], 0);
		
		
	}
	

	// now add the objective function
	m_osinstanceMaster->setObjectiveNumber( 1);
	m_osinstanceMaster->addObjective(-1, "objfunction", "min", 0.0, 1.0, objcoeff);
	
	//add the linear constraints coefficients
	m_osinstanceMaster->setLinearConstraintCoefficients(numNonz , true, 
			values, 0, numNonz - 1,  indexes, 0, numNonz - 1, starts, 0, startsIdx);
	
	
	//std::cout << m_osinstanceMaster->printModel( ) << std::endl;	
	
	//garbage collection
	delete[] tmpConvexity;
	tmpConvexity = NULL;
	delete[] thetaPntTmp;
	thetaPntTmp = NULL;
	delete[] thetaIndexTmp;
	thetaIndexTmp = NULL;
	delete objcoeff;
	objcoeff = NULL;
}//end resetMaster



double OSBearcatSolverXij::getRouteDistance(int numNodes, int hubIndex, 
		CoinSolver* solver,  std::vector<int> zk, double* xVar){
	
	int i;
	int j;
	int numVar;
	numVar = numNodes*numNodes - numNodes;

	int kount;
	double objValue;
	std::vector<int>::iterator vit;
	std::map<std::pair<int, int>, int > cutMap;
	std::map<std::pair<int, int>, int >::iterator mit;
	std::vector<IndexValuePair*> primalValPair;
	//
	//stuff for cut generation
	//

	//zero this array out
	for(i = 0; i < numVar; i++) xVar[ i] = 0;
	//getRows function call return parameters
	int numNewRows;
	int* numRowNonz = NULL;
	int** colIdx = NULL; 
	double** rowValues = NULL ; 
	double* rowLB;
	double* rowUB;
	//end of getRows function call return parameters	
	//
	//end of cut generation stuff
	OsiSolverInterface *si = solver->osiSolver;
	try{

		//adjust the RHS of the hubIndex constraints
		si->setRowUpper(hubIndex, 1.0);	
		si->setRowUpper(hubIndex + numNodes, 1.0);
		si->setRowLower(hubIndex, 1.0);	
		si->setRowLower(hubIndex + numNodes, 1.0);
		//
		//adjust the lower bounds on the variables
		
		kount = zk.size();
	
		int idx1;
		int idx2;

		for(i = 0; i < kount ; i++){
			
			//adjust the RHS of the hubIndex constraints
			si->setRowUpper(zk[ i], 1.0);	
			si->setRowUpper(zk[ i] + numNodes, 1.0);
			si->setRowLower(zk[ i], 1.0);	
			si->setRowLower(zk[ i] + numNodes, 1.0);
		
			idx1 = hubIndex;
			idx2 = zk[i ];
			
			//get variable number for (idx1, idx2)
			if( idx1 > idx2 ){
				si->setColUpper(idx1*(numNodes -1) + idx2, 1.0);	
			}else{
				
				if( idx1 < idx2 ){
					
					si->setColUpper(idx1*(numNodes -1) + idx2 - 1, 1.0);			
					
				}
			}
			
			idx1 = zk[ i];
			idx2 = hubIndex;
			
			//get variable number for (idx1, idx2)
			if( idx1 > idx2 ){
			
				si->setColUpper(idx1*(numNodes -1) + idx2, 1.0);	
				
			}else{
				
				if( idx1 < idx2 ){
					
					si->setColUpper(idx1*(numNodes -1) + idx2 - 1, 1.0);								
					
				}
			}
			
			for(j = i + 1; j < kount; j++){
				
				idx1 = zk[i];
				idx2 = zk[j];
				
				//get variable number for (idx1, idx2)
				if( idx1 > idx2 ){
				
					si->setColUpper(idx1*(numNodes -1) + idx2, 1.0);					
					
				}else{
					
					if( idx1 < idx2 ){
						
						si->setColUpper(idx1*(numNodes -1) + idx2 - 1, 1.0);						
					}
				}
				
				
				idx1 = zk[j];
				idx2 = zk[i];
				
				//get variable number for (idx1, idx2)
				if( idx1 > idx2 ){		
					si->setColUpper(idx1*(numNodes -1) + idx2, 1.0);					
				}else{
					
					if( idx1 < idx2 ){

						si->setColUpper(idx1*(numNodes -1) + idx2 - 1, 1.0);
					}
				}
			}
		}
		
		solver->solve();
		
		//throw an exception if we don't get an optimal solution
		
		if(solver->osresult->getSolutionStatusType( 0 ) != "optimal" ) throw ErrorClass("Trouble with integer program used to construct initial master");
		objValue = solver->osresult->getObjValue(0, 0) ;
		// now get the X values -- use these to get a cut
		primalValPair = solver->osresult->getOptimalPrimalVariableValues( 0);
		
		//loop over routes again to create master objective coefficients
		bool isCutAdded;
		isCutAdded = true;
		while(isCutAdded == true){
			
			isCutAdded = false;
			
			for(i = 0; i < numVar; i++) xVar[ primalValPair[ i]->idx  ] = primalValPair[ i]->value;

			numNewRows = 0;
			getCutsX(xVar, numVar, numNewRows, numRowNonz, 
					colIdx,rowValues, rowLB, rowUB);
			
			if(numNewRows >= 1){
				isCutAdded  = true;
				std::cout << "WE HAVE A CUT " << std::endl;
				std::cout << "EXPRESS CUT IN X(I, J) SPACE" << std::endl;
				//for(i = 0; i < numRowNonz[ 0]; i++)  std::cout <<  m_variableNames[ colIdx[0][ i] ] << std::endl;
					
				for(i = 0; i < numNewRows; i++){
					
					std::cout << "CUT UPPER BOUND = " <<  rowUB[ i] << std::endl;
					si->addRow(numRowNonz[ i], colIdx[ i], rowValues[ i], rowLB[ i], rowUB[ i] ) ;
				}
				
				std::cout << "A CUT WAS ADDED, CALL SOLVE AGAIN" << std::endl;
				solver->solve();
				if(solver->osresult->getSolutionStatusType( 0 ) != "optimal" ) throw ErrorClass("Trouble with integer program used to construct initial master");
				primalValPair = solver->osresult->getOptimalPrimalVariableValues( 0);
				std::cout << "New Solution Status =  " << solver->osresult->getSolutionStatusType( 0 ) << std::endl;
				std::cout << "Optimal Objective Value = " << solver->osresult->getObjValue(0, 0) << std::endl;
		
				// zero out xVar
				//for(i = 0; i < numVar; i++) xVar[ i  ] = 0;

			}//end if on numNewRows >= 1
			
		}//end while on isCutAdded
		
		objValue = solver->osresult->getObjValue(0, 0) ;
		// now get the X values -- use these to get a cut
		primalValPair = solver->osresult->getOptimalPrimalVariableValues( 0);
		
		//for(i = 0; i < numVar; i++)
		//	if( primalValPair[ i]->value > .5) std::cout << m_variableNames[ primalValPair[ i]->idx ] << std::endl;
		std::cout << "Objective Function Value = " << objValue  << std::endl;
		
		//reset the upper bounds
		for(i = 0; i < numVar; i++) si->setColUpper(i, 0);
		for(i = 0; i < 2*numNodes; i++) si->setRowUpper(i, 0);
		for(i = 0; i < 2*numNodes; i++) si->setRowLower(i, 0);

		return objValue;
	
	
	} catch (const ErrorClass& eclass) {
		
		std::cout << std::endl << std::endl << std::endl;

		if( xVar != NULL)
			delete  xVar;
		//  Problem with the parser
		throw ErrorClass(eclass.errormsg);
	}
	
}//end getRouteDistance



CoinSolver* OSBearcatSolverXij::getTSP(int numNodes, double* cost){
	

	int i;
	int j;
	int numVar;
	numVar = numNodes*numNodes - numNodes;
	int numNonz;
	int kount;

	std::vector<int>::iterator vit;
	double* rhsVec;
	CoinSolver *solver  = NULL;
	std::map<std::pair<int, int>, int > cutMap;
	std::map<std::pair<int, int>, int >::iterator mit;
	
	//numCuts is the number of cuts of the form Xij + Xji <= 1
	int numCuts;
	
	rhsVec = new double[ 2*numNodes];
	
	for(i = 0; i < 2*numNodes; i++){
		
		//this will then get changed to 1 
		//when we know assignments
		rhsVec[ i] = 0;
	}
	

	
	//now count and get variables in Xij + Xji <=1 cut
	numCuts = 0;
	std::pair <int,int> pairIJ;
	std::pair <int,int> pairJI;
	
	for(i = 0; i < numNodes - 1; i++){
		
		
		for(j = i + 1; j < numNodes; j++){
			
			
			pairIJ = std::make_pair(i, j);
			pairJI = std::make_pair(j, i);
			
			cutMap[pairIJ ] = 2*numNodes + numCuts;
			cutMap[pairJI ] = 2*numNodes + numCuts;
			numCuts++;
			
		}
	}

	

	OSInstance *osinstance = new OSInstance();
	try{
		
		osinstance->setInstanceSource("generated from OSBearcatSoleverXij");
		osinstance->setInstanceDescription("Find the minimum tour for a route");
		osinstance->setVariableNumber( numVar); 
		
		for(i = 0; i < numVar; i++){
			
			osinstance->addVariable(i, m_variableNames[ i], 0, 0, 'B');
			
		}
		// now add the objective function
		osinstance->setObjectiveNumber( 1);
		
		// now the coefficient
		SparseVector *objcoeff = new SparseVector( numVar); 
		
		for(i = 0; i < numVar; i++){
			
			objcoeff->indexes[ i] = i;
			objcoeff->values[ i] = cost[ i];
			
		}
	
		osinstance->addObjective(-1, "minimizeDistance", "min", 0.0, 1.0, objcoeff);
		objcoeff->bDeleteArrays = true;
		delete objcoeff;
		
		osinstance->setConstraintNumber( 2*numNodes + numCuts); 
		//bool addConstraint(int index, string name, double lowerBound, double upperBound, double constant);
		
		for(i = 0; i < numNodes; i++){
			
			osinstance->addConstraint(i, makeStringFromInt("enter_node_", i) , rhsVec[i], rhsVec[i],  0);
			
		}
		
		for(i = numNodes; i < 2*numNodes; i++){
			
			osinstance->addConstraint(i, makeStringFromInt("leave_node_", i - numNodes) , rhsVec[i], rhsVec[i], 0);
			
		}
		
		//now the Xij cuts
		
		for(i = 0; i < numCuts; i++){
			
			osinstance->addConstraint(2*numNodes + i, makeStringFromInt("XijCut_", i) , 0, 	1, 0);
			
		}
		 
		//now the A matrix
		//note: each Xij + Xji <= 1 has two nonzero elements 
		numNonz = numVar*numVar - numVar + 2*numCuts;
	
	
		double *values = new double[ numNonz];
		int *rowIndexes = new int[ numNonz];
		int *starts = new int[ numVar + 1];  
		
	
		kount = 0;
		numNonz = 0;
		starts[ kount++] = 0;
		for(i = 0; i < numNodes; i++){
			
			for(j = 0; j < i; j++){
				//we have xij, j < i
				
				rowIndexes[ numNonz] = j; //enter node j
				values[ numNonz++] = 1.0;
				
				rowIndexes[ numNonz] = numNodes + i; //leave node i
				values[ numNonz++] = 1.0;
				
				
				pairIJ = std::make_pair(i, j);
				mit =  cutMap.find( pairIJ);
				if(mit != cutMap.end() ){
					
					rowIndexes[ numNonz] = mit->second; 
					values[ numNonz++] = 1.0;
				}
				
		
				starts[ kount++] = numNonz;
				
				
			}
			
			for(j = i+1; j < numNodes; j++){
				//we have xij, j > i
	
				rowIndexes[ numNonz] = j; //enter node j
				values[ numNonz++] = 1.0;
				
				rowIndexes[ numNonz] = numNodes + i; //leave node i
				values[ numNonz++] = 1.0;
				
				
				pairIJ = std::make_pair(i, j);
				mit =  cutMap.find( pairIJ);
				if(mit != cutMap.end() ){
					
					rowIndexes[ numNonz] = mit->second; 
					values[ numNonz++] = 1.0;
				}
				
				
				starts[ kount++] = numNonz;
				
			}
			
			
		}
		
		osinstance->setLinearConstraintCoefficients(numNonz, true, values, 0, numNonz - 1, 
			rowIndexes, 0, numNonz - 1, starts, 0, numVar);
		
		//std::cout << osinstance->printModel() << std::endl;
		
		
		solver = new CoinSolver();
		solver->sSolverName ="cbc"; 
		solver->osinstance = osinstance;	
		solver->buildSolverInstance();
		solver->osoption = m_osoption;	
		
		delete[] rhsVec;
		rhsVec = NULL;
		
		return solver;
	
	
		
	} catch (const ErrorClass& eclass) {
		
		std::cout << std::endl << std::endl << std::endl;
		
		if(rhsVec != NULL){
			delete[] rhsVec;
			rhsVec = NULL;
		}
	
		//  Problem with the parser
		throw ErrorClass(eclass.errormsg);
	}
		
	
}//end getTSP


bool OSBearcatSolverXij::OneOPT(){
	
	int k;
	int kprime;
	double *routeCost = NULL;
	int *routeDemand = NULL;
	double *xVar = NULL;
	int numXVar = m_numNodes*m_numNodes - m_numNodes;
	double routeCostInf;
	
	routeCostInf = OSINT_MAX;
	double feasMult = 10000; //factor by which we multiply feasibility improvement
	
	routeCost = new double[m_numHubs];
	routeDemand = new int[m_numHubs];
	xVar = new double[ numXVar];
	
	//get current capacities
	
	std::map<int, std::vector<int> > routeMap;
	std::vector<int> tmpVec;
	std::vector<int>::iterator vit;
	std::vector<int>::iterator vit2;

	routeMap = m_initSolMap[ 0];
	CoinSolver *solver = NULL;
	
	double totalCost;
	bool foundMoBetta; //set to true if improved
	bool foundLocalImprovement;
	
	try{
		
		solver = getTSP(m_numNodes, m_cost);
		totalCost = 0;
		for(k = 0; k < m_numHubs; k++){
		
			routeDemand[ k] = 0;
			for(vit = routeMap[k].begin(); vit!=routeMap[k].end(); ++vit){
			
				std::cout << "node i = " << *vit << " demand " << m_demand[ *vit] << std::endl;
				routeDemand[ k] +=  m_demand[ *vit];
			}
			
			if(routeDemand[k] <= m_routeCapacity[ k] ){
				
				routeCost[ k] = getRouteDistance(m_numNodes, k, solver,
						routeMap[k], xVar)*routeDemand[ k];
				
				
				std::cout << "rout = " << k << " cost " << routeCost[ k] << std::endl;
				totalCost += routeCost[ k];
			}else{
				std::cout << "rout demand " << routeDemand[k] << " route capacity =  " << m_routeCapacity[ k] << std::endl;
				routeCost[ k] = routeCostInf;
				totalCost += routeCost[ k];

			}
			
		
		}
		
		
		//now loop as long as there is improvement
		foundMoBetta = true;
		double improvement;
		
		double tmpCostk;
		double tmpCostkPrime;
		double optCostk;
		double optCostkPrime;
		double tmpVal;
		int tmpIdx;
		std::vector<int>::iterator vitIdx;
	
		while(foundMoBetta == true){
			foundMoBetta = false;
			
			for(k = 0; k < m_numHubs; k++){
				
				foundLocalImprovement = false;
				
				for(kprime = 0; kprime < m_numHubs; kprime++){
					
					if(k != kprime && routeCost[ kprime] < routeCostInf){
						
						//try to move a node from route k to route kprime
						improvement = 0;
						optCostk = routeCostInf;
						optCostkPrime = routeCostInf;
						
						for(vit = routeMap[k].begin(); vit!=routeMap[k].end(); ++vit){
							
							//consider making a switch if feasible
							if( m_demand[ *vit] + routeDemand[ kprime] <= m_routeCapacity[ kprime] ){
								
								tmpCostk = routeCostInf;
								tmpCostkPrime = routeCostInf;
								
								
								//make a switch
								//add *vit to route kprime and take away from  k
								routeMap[ kprime].push_back( *vit);
								//calculate cost for route kprime
								tmpCostkPrime = getRouteDistance(m_numNodes, kprime, solver,
										routeMap[kprime], xVar)*(routeDemand[ kprime] + m_demand[ *vit] );
								
								//now switch back
								routeMap[ kprime].pop_back( );
								

								//kipp -- handle both infinite and finite
								if(routeCost[k] == routeCostInf ){
									
									//std::cout << "WE HAVE INFINITY CASE" << std::endl;
									
									
									//don't bother to solve TSP for route k if we are still infinite
									if(  routeDemand[ k] - m_demand[ *vit] <= m_routeCapacity[ k]) {

										for(vit2 = routeMap[k].begin(); vit2 != routeMap[k].end();  vit2++){
											
											if(vit != vit2) tmpVec.push_back( *vit2);
											
										}
										
										tmpCostk = getRouteDistance(m_numNodes, k, solver,
												tmpVec, xVar)*(routeDemand[ k] - m_demand[ *vit] );
										
										tmpVec.clear();
										
									}
									
									tmpVal = std::max(*vit, routeDemand[ k] - m_demand[ *vit])*feasMult 
											+ ( routeCost[kprime]  - tmpCostkPrime);
								
									if(  tmpVal > improvement)  {
										foundLocalImprovement = true;
										improvement = tmpVal;
										tmpIdx = *vit;
										vitIdx = vit;
										optCostk = tmpCostk;
										optCostkPrime = tmpCostkPrime;	
										
									}
									
									
								}else{// not infinite cost
									
									//std::cout << "WE HAVE FINITE CASE" << std::endl;
									
									//evaluate cost on route k
									for(vit2 = routeMap[k].begin(); vit2 != routeMap[k].end();  vit2++){
										
										if(vit != vit2) tmpVec.push_back( *vit2);
										
									}
									
									tmpCostk = getRouteDistance(m_numNodes, k, solver,
											tmpVec, xVar)*(routeDemand[ k] - m_demand[ *vit] );
									
									tmpVec.clear();
	
									if( ( (routeCost[k] + routeCost[kprime]) -
											( tmpCostkPrime + tmpCostk ) ) > improvement  ) {
										
										improvement = (routeCost[k] + routeCost[kprime]) -
												( tmpCostkPrime + tmpCostk );
										
										foundLocalImprovement = true;
										tmpIdx = *vit;
										vitIdx = vit;
										optCostk = tmpCostk;
										optCostkPrime = tmpCostkPrime;
									}
								}
							}//end if on capacity test
							
							
						}// looping over nodes
						
						//do updates here if we found an improvement
						
						//make switch on best found
						if( foundLocalImprovement == true) {
							
							
							std::cout << "index =  "  <<  tmpIdx << std::endl;
							//add tmpIdx to route kPrime
							routeMap[ kprime].push_back( tmpIdx);
							//adjust route demand
							routeDemand[ kprime] += m_demand[ tmpIdx];
							//adjust  route cost
							routeCost[ kprime] = optCostkPrime;
							
							//std::cout << "kprime route cost = " << routeCost[ kprime] << std::endl;
							//std::cout << "kprime route demand = " << routeDemand[ kprime] << std::endl;
							
							
							//delete tmpIdx to route kPrime
							routeMap[ k].erase( vitIdx);
							//adjust rouet demand
							routeDemand[ k] -= m_demand[ tmpIdx];
							//adjust  route cost
							routeCost[ k] = optCostk;
							
							//std::cout << "k route cost = " << routeCost[ k] << std::endl;
							//std::cout << "k route demand = " << routeDemand[ k] << std::endl;
							
							foundMoBetta = true;
							
						}//if on OSDBL_MAX	
					}//close if on k != kprime
				}//loop on kprime
			}//loop on k
			
			
		}//loop on while
		
		
		//summarize
		totalCost = 0;
		for(k = 0; k < m_numHubs; k++){
			
			std::cout << std::endl << std::endl;
			
			std::cout << "ROUTE "  << k << " Total Demand =  " << routeDemand[ k]  << std::endl;
			std::cout << "ROUTE " << k << " Total Cost =  " << routeCost[ k]  << std::endl;
			std::cout << "ROUTE "  << k << "  Nodes "  << std::endl;
			
			//for(vit = routeMap[ k].begin(); vit != routeMap[k].end(); vit++){
			//	std::cout << *vit  << std::endl;
			//}
			totalCost += routeCost[ k];
		}
		
		std::cout << "Total Cost  = " << totalCost << std::endl;
		//get the solution
		m_initSolMap[ 0] = routeMap;
		
		
		//garbage collection
		delete[] routeCost;
		routeCost = NULL;
		delete[] routeDemand;
		routeDemand = NULL;
		delete[] xVar;
		xVar = NULL;
		delete solver->osinstance;
		delete solver;
		//exit( 1);
		if( totalCost >= routeCostInf )return false;
		else return true;
	
	
	} catch (const ErrorClass& eclass) {
	
	std::cout << std::endl << std::endl << std::endl;
	
	if(routeCost != NULL){
		delete[] routeCost;
		routeCost = NULL;
	}
	
	if(routeDemand != NULL){
		delete[] routeDemand;
		routeDemand = NULL;
	}
	
	if(xVar != NULL){
		delete[] xVar;
		xVar = NULL;
	}



	//  Problem with the parser
	throw ErrorClass(eclass.errormsg);
}

}//1OPT





CoinSolver* OSBearcatSolverXij::getMultiCommodInstance(int hubIndex){
	

	int i;
	int j;
	int numVar;
	int numNonHubs;
	numNonHubs = m_numNodes - m_numHubs;
	//first the w varibles 
	numVar = numNonHubs; 
	//u(i, j) varibles with i = hubIndex
	numVar +=  numNonHubs; 
	//u(i, j) variable where i, j are not hubs
	numVar +=  numNonHubs*numNonHubs - numNonHubs;
	int numNonz;
	int kount;
	int numCon;
	CoinSolver *solver  = NULL;
	SparseVector *objcoeff = NULL;
	
	numCon = numNonHubs + (numNonHubs*numNonHubs - numNonHubs) + 1;



	OSInstance *osinstance = new OSInstance();
	try{
		
		osinstance->setInstanceSource("generated from OSBearcatSoleverXij");
		osinstance->setInstanceDescription("Instance for finding a multicommodity cut");
		osinstance->setVariableNumber( numVar); 
		
		numVar = 0;
		
		for(i = m_numHubs; i < m_numNodes; i++){
			
			if(m_nodeName[ i] != "")
				osinstance->addVariable(numVar++, "w[" +  m_nodeName[ i]  +"]", 0, OSDBL_MAX, 'C');
			else
				osinstance->addVariable(numVar++, makeStringFromInt("w[", i)  +"]", 0, OSDBL_MAX, 'C');
			
			m_tmpVarMap.insert( std::pair<int,std::string>(numVar, "w[" +  m_nodeName[ i]  +"]" ) );
			
		}
		

			
		for(j = m_numHubs; j < m_numNodes; j++){
			
			if(m_nodeName[ hubIndex ] != "" && m_nodeName[ j] != "")
				osinstance->addVariable(numVar++, "u[" +  m_nodeName[ hubIndex] + "," + m_nodeName[ j] +"]", 0, OSDBL_MAX, 'C');
			else
				osinstance->addVariable(numVar++, makeStringFromInt("u[", hubIndex)  + makeStringFromInt(",", j)  +"]", 0, OSDBL_MAX, 'C');
			
			m_tmpVarMap.insert( std::pair<int,std::string>(numVar,  m_nodeName[ hubIndex] + "," + m_nodeName[ j] +"]") );
			
			
		}
		
		for(i = m_numHubs; i < m_numNodes; i++){
			
			
			for(j = m_numHubs; j < i; j++){
			
			
				
				if(m_nodeName[ i] != "" && m_nodeName[ j] != "")
					osinstance->addVariable(numVar++, "u[" +  m_nodeName[ i] + "," + m_nodeName[ j] +"]", 0, OSDBL_MAX, 'C');
				else
					osinstance->addVariable(numVar++, makeStringFromInt("u[", i)  + makeStringFromInt(",", j)  +"]", 0, OSDBL_MAX, 'C');
				
				
				m_tmpVarMap.insert( std::pair<int,std::string>(numVar,  "u[" +  m_nodeName[ i] + "," + m_nodeName[ j] +"]") );
				
			}
			
			for(j = i + 1; j < m_numNodes; j++){
				
				if(m_nodeName[ i] != "" && m_nodeName[ j] != "")
					osinstance->addVariable(numVar++, "u[" +  m_nodeName[ i] + "," + m_nodeName[ j] +"]", 0, OSDBL_MAX, 'C');
				else
					osinstance->addVariable(numVar++, makeStringFromInt("u[", i)  + makeStringFromInt(",", j)  +"]", 0, OSDBL_MAX, 'C');
				
				m_tmpVarMap.insert( std::pair<int,std::string>(numVar,  "u[" +  m_nodeName[ i] + "," + m_nodeName[ j] +"]") );
				
				
			}
			
		}
		
		
		// now add the objective function
		osinstance->setObjectiveNumber( 1);
		
		// now the coefficient

		objcoeff = new SparseVector( numVar); 
		
		for(i = 0; i < numVar; i++){
			
			objcoeff->indexes[ i] = i;
			objcoeff->values[ i] = 0;
			
		}
	
		osinstance->addObjective(-1, "cutViolation", "max", 0.0, 1.0, objcoeff);
		objcoeff->bDeleteArrays = true;
		delete objcoeff;
		
		osinstance->setConstraintNumber( numCon ); 
		//bool addConstraint(int index, string name, double lowerBound, double upperBound, double constant);
		numCon = 0;
		for(i = m_numHubs; i < m_numNodes; i++){
			
			if(m_nodeName[ hubIndex] != "" && m_nodeName[ i] != "")
				osinstance->addConstraint(numCon++, "dualCon[" + m_nodeName[ hubIndex] + "," +   m_nodeName[ i] + "]", -OSDBL_MAX, 0,  0);
			else
				osinstance->addConstraint(numCon++, makeStringFromInt("dualCon[", hubIndex)  + makeStringFromInt(",", i)  +"]", -OSDBL_MAX, 0,  0);
		}
		
		
		for(i = m_numHubs; i < m_numNodes; i++){
			
			
			for(j = m_numHubs; j < i; j++){
				
				if(m_nodeName[ i] != "" && m_nodeName[ j] != "")
					osinstance->addConstraint(numCon++, "dualCon[" +  m_nodeName[ i] + "," + m_nodeName[ j] +"]", -OSDBL_MAX, 0, 0);
				else
					osinstance->addConstraint(numCon++, makeStringFromInt("dualCon[", i)  + makeStringFromInt(",", j)  +"]", -OSDBL_MAX, 0, 0);
				
				
			}
			
			for(j = i + 1; j < m_numNodes; j++){
				
				if(m_nodeName[ i] != "" && m_nodeName[ j] != "")
					osinstance->addConstraint(numCon++, "dualCon[" +  m_nodeName[ i] + "," + m_nodeName[ j] +"]", -OSDBL_MAX, 0, 0);
				else
					osinstance->addConstraint(numCon++, makeStringFromInt("dualCon[", i)  + makeStringFromInt(",", j)  +"]", -OSDBL_MAX, 0, 0);
				
				
			}
			
		}
		
		double upperBound;
		upperBound = numVar - numNonHubs ;
		upperBound = 100;
		osinstance->addConstraint(numCon++, "boundConstraint", -OSDBL_MAX, upperBound, 0);
		
		//now the A matrix
		numCon = numNonHubs + (numNonHubs*numNonHubs - numNonHubs) + 1;
		numNonz = 2*numNonHubs;
		numNonz += 3*(numNonHubs*numNonHubs - numNonHubs);
		numNonz += (numNonHubs*numNonHubs - numNonHubs) + numNonHubs;
	
	
		double *values = new double[ numNonz];
		int *columnIndexes = new int[ numNonz];
		//store by row major
		int *starts = new int[ numCon + 1];  
		
	
		kount = 0;
		numNonz = 0;
		starts[ kount++] = 0;
		
		
		//////////////////////////////////
		
		
		int uijKount;
		uijKount = numNonHubs;
		
		for(j = m_numHubs; j < m_numNodes; j++){
			
			//-u(k, j) + w(j)  =l=  0;
			//variable w(j)
			columnIndexes[ numNonz] = j - m_numHubs ; 
			values[ numNonz++] = 1.0;
			
			//variable -u(k, j)
			columnIndexes[ numNonz] = uijKount ; 
			values[ numNonz++] = -1.0;
			
			starts[ kount++] = numNonz;
			uijKount++;
		}
		
		
		for(i = m_numHubs; i < m_numNodes; i++){
			
			
			for(j = m_numHubs; j < i; j++){
				
				//-u(i, j) - w(i) + w(j) =l=  0;
				//variable w(i)
				columnIndexes[ numNonz] = i - m_numHubs ; 
				values[ numNonz++] = -1.0;
				
				//variable w(j)
				columnIndexes[ numNonz] = j - m_numHubs ; 
				values[ numNonz++] = 1.0;
				
				//variable -u(i, j)
				columnIndexes[ numNonz] = uijKount ; 
				values[ numNonz++] = -1.0;
				
				
				starts[ kount++] = numNonz;
				uijKount++;
				
				
			}
			
			for(j = i + 1; j < m_numNodes; j++){
				
				//-u(i, j) - w(i) + w(j) =l=  0;
				//variable w(i)
				columnIndexes[ numNonz] = i - m_numHubs ; 
				values[ numNonz++] = -1.0;
				
				//variable w(j)
				columnIndexes[ numNonz] = j - m_numHubs ; 
				values[ numNonz++] = 1.0;
				
				//variable -u(i, j)
				columnIndexes[ numNonz] = uijKount ; 
				values[ numNonz++] = -1.0;
				
				
				starts[ kount++] = numNonz;
				uijKount++;

				
			}
			
		}		
		
		//the last row
		for(i = numNonHubs; i < numVar; i++ ){
			
			//variable u(i, j)
			columnIndexes[ numNonz] = i ; 
			values[ numNonz++] = 1.0;
			
		}
	
		starts[ kount++] = numNonz;
		osinstance->setLinearConstraintCoefficients(numNonz, false, values, 0, numNonz - 1, 
			columnIndexes, 0, numNonz - 1, starts, 0, numVar);
		
		//std::cout << osinstance->printModel() << std::endl;
		//temp stuff
		//
		ClpSimplex *clpModel;  
		
	    CoinPackedMatrix* matrix;
	    bool columnMajor = true;
	    double maxGap = 0;
		matrix = new CoinPackedMatrix(
		columnMajor, //Column or Row Major
		columnMajor? osinstance->getConstraintNumber() : osinstance->getVariableNumber(), //Minor Dimension
		columnMajor? osinstance->getVariableNumber() : osinstance->getConstraintNumber(), //Major Dimension
		osinstance->getLinearConstraintCoefficientNumber(), //Number of nonzeroes
		columnMajor? osinstance->getLinearConstraintCoefficientsInColumnMajor()->values : osinstance->getLinearConstraintCoefficientsInRowMajor()->values, //Pointer to matrix nonzeroes
		columnMajor? osinstance->getLinearConstraintCoefficientsInColumnMajor()->indexes : osinstance->getLinearConstraintCoefficientsInRowMajor()->indexes, //Pointer to start of minor dimension indexes -- change to allow for row storage
		columnMajor? osinstance->getLinearConstraintCoefficientsInColumnMajor()->starts : osinstance->getLinearConstraintCoefficientsInRowMajor()->starts, //Pointers to start of columns.
		0,   0, maxGap ); 
		
		clpModel = new ClpSimplex( );
		
		//if( m_osinstanceSeparation->getObjectiveMaxOrMins()[0] == "min") osiSolver->setObjSense(1.0);
		clpModel->setOptimizationDirection( 1);
		clpModel->loadProblem( *matrix, osinstance->getVariableLowerBounds(), 
				osinstance->getVariableUpperBounds(),  
				osinstance->getDenseObjectiveCoefficients()[0], 
				osinstance->getConstraintLowerBounds(), m_osinstanceSeparation->getConstraintUpperBounds()
		);
		
		
		
		delete matrix;
		
		//
		//
		
		solver = new CoinSolver();
		solver->sSolverName ="clp"; 
		solver->osinstance = osinstance;	
		solver->buildSolverInstance();
		solver->osoption = m_osoption;	

		
		return solver;
	
	
		
	} catch (const ErrorClass& eclass) {
		
		if( objcoeff != NULL ){
			delete objcoeff;
			objcoeff = NULL;
		}
		//  Problem with the parser
		throw ErrorClass(eclass.errormsg);
	}
		
	
}//end getMultiCommodInstance



std::string makeStringFromInt(std::string theString, int theInt){
	ostringstream outStr;
	outStr << theString;
	outStr << theInt;
	return outStr.str();
}//end makeStringFromInt





