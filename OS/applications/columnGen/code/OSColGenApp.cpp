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



#include <sstream>
using std::ostringstream;


std::string makeStringFromInt(std::string theString, int theInt);

OSColGenApp::OSColGenApp():
	m_osinstanceMaster(NULL) {
	std::cout << "INSIDE OSColGenApp CONSTRUCTOR" << std::endl;
}//end OSDipBlockBearcatSolver


OSColGenApp::OSColGenApp(   OSOption *osoption) {
	  std::cout << "INSIDE OSColGenApp CONSTRUCTOR" << std::endl;
	  //std::cout << "the contructor things whichBlock = " << m_whichBlock<< std::endl;
	try{
		
		m_osinstanceMaster = NULL;
		//m_osinstanceMaster = osinstance;
		//m_numberOfVar = m_osinstanceMaster->getVariableNumber();
		
		m_osoption = osoption;
		//now get  the solver options
		getOptions( m_osoption);
		
		m_demand = NULL;
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
		
		//kipp -- fill in numberOfRestricedMasterSolutions from map size
		 m_numberOfSolutions = m_initSolMap.size();
		
		if(m_routeCapacity > m_totalDemand){
			m_upperBoundL = m_totalDemand;
		}else{
			m_upperBoundL = m_routeCapacity;
		}
		

		
		//m_varIdx = new int[ m_numNodes];
		m_varIdx = new int[ m_upperBoundL + 1];
		
		
		m_u = new double*[ m_numNodes];
		m_v = new double*[ m_numNodes];
		m_g = new double*[ m_numNodes];
		
		m_px = new int*[ m_numNodes];
		m_tx = new int*[ m_numNodes];
		
		
		int i;
		int l;
		for (i = 0; i < m_numNodes; i++) {
			
			
			m_u[ i] = new double[ m_upperBoundL + 1];
			m_v[ i] = new double[ m_upperBoundL + 1];
			
			for(l = 0; l <= m_upperBoundL; l++){
				m_u[ i][l] = OSDBL_MAX;
				m_v[ i][l] = OSDBL_MAX;
			}
			
			m_g[ i] = new double[ m_numNodes];
			
			m_px[ i] = new int[ m_upperBoundL + 1];
			m_tx[ i] = new int[m_upperBoundL + 1];
			
			
		}
		
		
		//outer dynamic programming arrays
		m_optL = new int[ m_numHubs];
		m_optD = new int[ m_numHubs];
		
		m_vv = new double*[ m_numHubs];
		m_vvpnt = new int*[ m_numHubs];
		
		for (i = 0; i < m_numHubs; i++) {
			
			
			m_vv[ i] = new double[ m_totalDemand + 1];
			m_vvpnt[ i] = new int[ m_totalDemand + 1];

			
			
		}
		
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	

}//end OSColGenApp

OSColGenApp::~OSColGenApp(){
	
	std::cout << "INSIDE ~OSColGenApp DESTRUCTOR" << std::endl;

	if( m_osinstanceMaster != NULL) delete  m_osinstanceMaster;
	std::vector<IndexValuePair*>::iterator  vit;
	
	for (vit = m_primalVals.begin(); vit != m_primalVals.end(); vit++) {
		
		delete *vit;
	}
	
	//delete data structures for arrays used in calculating minimum reduced cost
	int i;
	
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
	
	
	
	if(m_demand != NULL) delete[] m_demand;
	
	if(m_varIdx != NULL) delete[] m_varIdx;
	
	for(i = 0; i < m_numHubs; i++){
		
		delete[] m_vv[i];
		delete[] m_vvpnt[i];
		
		
	}
	delete[] m_optL;
	m_optL = NULL;
	delete[] m_optD;
	m_optD = NULL;
	delete[] m_vv;
	m_vv = NULL;
	delete[] m_vvpnt;
	m_vvpnt = NULL;
	//if(m_osrlreader != NULL) delete m_osrlreader;
}//end ~OSDipBlockBearcatSolver

void OSColGenApp::solveMaster(const double *cost, std::vector<IndexValuePair*> *solIndexValPair, 
		double *optVal, const double& convexDual){

	try{
		
		int i;  
		
		//kipp fix the line below
		cost+=  m_whichBlock*m_upperBoundL*(m_numNodes*m_numNodes - m_numNodes) ;
		
		struct IndexValuePair *primalValPair;

		std::vector<IndexValuePair*>::iterator  vit;
		
		for (vit = m_primalVals.begin(); vit != m_primalVals.end(); vit++) {
			
			delete *vit;
		}
		m_primalVals.clear();
		
			
		//now, lets find the minimum reduced cost
		
		*optVal = OSDBL_MAX;
		
		//std::cout << "Number of Var " << m_numberOfVar  << std::endl;
	

		int bestl;
		int kountVar;
		double testVal;
		
		testVal = 0;
		if(m_whichBlock == 0){
			
			getOptL( cost);
			
			for(i = 0; i < m_numHubs; i++){
				
				std::cout << " whichBlock =  " << i << "  L = " << m_optL[ i] << std::endl;
				testVal += m_optL[ i];
				
			}
			
			
			
			if(testVal != m_totalDemand) {
				
				std::cout  << "TOTAL DEMAND = " << m_totalDemand << std::endl;
				std::cout  << "Test Value = " << testVal << std::endl;
				throw  ErrorClass( "inconsistent demand calculation" );
			}
			
		}
		
		

		
		/*
		for(l = m_minDemand; l <= m_routeCapacity; l++){
			
			testVal = qrouteCost(m_whichBlock,  l,  cost,  &kountVar);
			if( testVal < *optVal){
				*optVal = testVal;
				bestl = l;
			}
			
		}
		*/
		
		//kipp -- set back
		//bestl = 4;
		
		bestl = m_optL[ m_whichBlock];
		//m_trueMin = m_trueMin - convexDual;
		
		std::cout  << "WHICH BLOCK =  " << m_whichBlock << "  BEST L = " << bestl <<  "  m_trueMin " <<  m_trueMin << std::endl;
		// when m_whichBlock == m_numHubs  - 1 we have a lower bound
		std::cout << "LOWER BOUND = " << m_trueMin << std::endl;
		if(  (m_whichBlock == m_numHubs  - 1) && m_trueMin > 0){
			std::cout << "WE ARE OPTIMAL " << std::endl;
			//exit( 1);
		}
		

		
		                  
		*optVal = qrouteCost(m_whichBlock,  bestl,  cost,  &kountVar);
		
		

		//std::cout <<   "best reduced cost = " << *optVal << std::endl;
		
		std::map<int, int> indexCount;
		
		std::map<int, int>::iterator mit;
		
		
		for(i = 0; i < kountVar; i++){
			
			if( indexCount.find(  m_varIdx[ i]) == indexCount.end()  ){
				
				indexCount[ m_varIdx[ i]] = 1;
				
			}else{
				
				indexCount[ m_varIdx[ i]] += 1;
				
			}
				
				
		}
		
		for (mit = indexCount.begin(); mit != indexCount.end(); mit++){
			
			//std::cout << "Variable Index " << mit->first << " Count =  " << mit->second << std::endl;
			
			//std::cout << "Variable Name = " << m_osinstanceMasterMaster->getVariableNames()[   mit->first]  << std::endl;
			
			// get unique indexes
			primalValPair = new IndexValuePair();
			
			primalValPair->value =  mit->second;
			primalValPair->idx =  mit->first;
	
			
			m_primalVals.push_back( primalValPair);
		}
		
		/*** old way could lead to duplicate indexes
		for (i = 0; i < kountVar; i++){
			
			//std::cout << "Variable Number = " << m_varIdx[ i] << std::endl;
			std::cout << "Variable Name = " << m_osinstanceMasterMaster->getVariableNames()[  m_varIdx[ i]]  << std::endl;
			
			// get unique indexes
			primalValPair = new IndexValuePair();
			
			primalValPair->value = 1.0;
			primalValPair->idx = m_varIdx[ i];
	
			
			m_primalVals.push_back( primalValPair);
			
			
		}
	*/
		
		 *solIndexValPair = m_primalVals;

			
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	
	
}//end solve


double OSColGenApp::qrouteCost(const int& k, const int& l, const double* c, int* kountVar){
	
	//critical -- nodes 0, ..., m_numNodes - 1 are the hub nodes
	// we are doing the calculation for hub k, k <= m_numNodes - 1
	//l  should be the total demand on the network -- we are NOT using 0 based counting
	double rcost;
	rcost = OSDBL_MAX;
	

	
	if(l < 0){
		
		std::cout  << "LVALUE  NEGATIVE " << l  << std::endl;
		exit( 1);
	}


	
	if(l > m_upperBoundL){
		
		std::cout  << "LVALUE  BIGGER THAN UPPER BOUND " << l  << std::endl;
		exit( 1);
	}	
	
	//start of the cost vector for hub k plus move to start of l demands
	// now move the pointer up
	//int startPnt = k*totalDemand*(m_numNodes*m_numNodes - m_numNodes) + (l - 1)*(m_numNodes*m_numNodes - m_numNodes);
	
	int startPnt = (l - 1)*(m_numNodes*m_numNodes - m_numNodes);
	c+=  startPnt ;
	


	*kountVar = 0;
	int bestLastNode;
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
			
			m_u[i][l1] = OSDBL_MAX;
			m_v[i][l1] = OSDBL_MAX;
			
			if(l1 == *(m_demand + i) ){
				
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
	int lowerVal = m_minDemand + 1;
	for(l2 = lowerVal; l2 <= l; l2++){// loop over possible demand values assuming we have already gone to at least one node
			
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
							
							//if(g(j, i) < v(i, l2),
							
							m_v[i][l2] = m_g[j][i];
							m_tx[i][l2] = j;	
							
							
						}
						
					}
					
					
				}//end second best calculation, anothe for loop on j
				
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
	
	
	

	//by successor, I mean node after current node in the path
	successorNode = k;
	currentNode = bestLastNode;
	//the lvalue is the demand through the currentNode
	lvalue = l ;


	while(currentNode != k){

		if( m_px[ currentNode][ lvalue ] != successorNode){
			

			
			//update nodes
			successorNode = currentNode;
			currentNode = m_px[ currentNode][ lvalue ];
			
			
			if(currentNode - successorNode > 0){
				 //below diagonal

				*(m_varIdx  + (*kountVar)++) = startPnt + currentNode*(m_numNodes - 1)  +  successorNode;

				
			}else{
				 //above diagonal

				*(m_varIdx + (*kountVar)++) = startPnt + currentNode*(m_numNodes - 1)  +  successorNode  - 1 ;

			}

			
		}else{ //take second best
			
			
			//update nodes
			successorNode = currentNode;
			currentNode = m_tx[ currentNode][ lvalue ];
			
			if(currentNode - successorNode > 0){
				 //below diagonal
				*(m_varIdx  + (*kountVar)++) = startPnt + currentNode*(m_numNodes - 1)  +  successorNode;
				
			}else{
				 //above diagonal
				*(m_varIdx + (*kountVar)++) = startPnt + currentNode*(m_numNodes - 1)  +  successorNode  - 1 ;
				
			}
			
		}
		
		//update lvalue
		lvalue = lvalue - *(m_demand + successorNode);
	
		

	}//end while

	
	//go from node k to bestLastNode -- already done in loop above
	//*(m_varIdx + (*kountVar)++) = startPnt + k*(m_numNodes - 1)  +  currentNode - 1;
	

	return rcost;
	
}//end qroute


void OSColGenApp::getOptL(const  double* c) {
	
	//initialize the first HUB
	
	int k;
	int d;
	int d1;
	int kountVar;
	double testVal;
	int l;
	int startPntInc;
	
	kountVar = 0;
	startPntInc = m_upperBoundL*(m_numNodes*m_numNodes - m_numNodes);
	
	m_vv[ 0][ 0] = 0;
	for(d = 1; d <=  m_totalDemand; d++){
		
		m_vv[ 0][ d] = OSDBL_MAX;
		
	}
	
	//now loop over the other HUBS
	

	
	for(k = 1; k < m_numHubs; k++){
		
		for(d = 1; d <= m_totalDemand; d++){
			
			m_vv[ k][ d] = OSDBL_MAX;
			
			//d1 is the state variable at stage k -1
			for(d1 = 0; d1 <= m_totalDemand; d1++){
			
				l = d - d1;
				
				if( (m_vv[ k - 1][ d1] < OSDBL_MAX) &&  (l <= m_upperBoundL) && (l >= 1) ){
				
					
					// l was the decision at state d1 in stage k-1
					// l + d1 brings us to state d at stage k
					// d is the total carried on routes 0 -- k-1
				
					testVal = qrouteCost(k - 1,  l,  c,  &kountVar);
					
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
		
		c+=  startPntInc ;	
		
	}//  end for on k
	
	m_trueMin = OSDBL_MAX;
	//we now enter the last stage through the other hubs
	// have satisfied total demand d

	int  dlower = 0;
	if (m_numHubs > 1) dlower = 1;
	
	for(d = dlower; d < m_totalDemand; d++){
		
		//std::cout << "m_vv[ m_numHubs - 1 ][ d]  " << m_vv[ m_numHubs - 1 ][ d]  << std::endl;
		l = m_totalDemand - d;
		
		if(m_vv[ m_numHubs - 1 ][ d]  < OSDBL_MAX  && l <= m_upperBoundL && l >= 1){
		
			
			
			//std::cout << "LL = " <<  l  << std::endl;
			
			
			testVal = qrouteCost(m_numHubs -1 ,  l,  c,  &kountVar);
			
			//std::cout << "l = " << l << std::endl;
			//std::cout << "testVal = " << testVal << std::endl;
			
			if(m_vv[ m_numHubs - 1][ d] + testVal < m_trueMin){
				
				m_trueMin = m_vv[ m_numHubs -1][ d] + testVal;
				m_optD[  m_numHubs -1 ] = d;
				m_optL[  m_numHubs -1 ] = l;
				
			}
			
			
		}
	}
	
	std::cout << "TRUE MIN = " <<  m_trueMin << std::endl;

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


void OSColGenApp::generateInitialRestrictedMaster( ){

	
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
		int k;

	
		
	
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
					std::cout << "FIXING LOWER BOUND ON VARIABLE " << osinstance->getVariableNames()[ kount + mit2->first*m_numNodes + *vit ] << std::endl;
					
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
				
				masterVarName = makeStringFromInt("theta(", mit->first);
				masterVarName += makeStringFromInt(",", k);
				masterVarName += ")";
				std::cout << masterVarName << std::endl;
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
	
		
		std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
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
	
	
}//end generateInitialRestrictedMaster


void OSColGenApp::generateCuts(const  double* x) {
	
	
}//end generateCuts

void OSColGenApp::generateColumns(const  double* u) {
	
	
}//end generateColumns

void OSColGenApp::getOptions(OSOption *osoption) {
	
	try{
		std::vector<SolverOption*> solverOptions;
		std::vector<SolverOption*>::iterator vit;
		std::vector<int >demand;
	
		m_numberOfSolutions = 0;
		solverOptions = m_osoption->getSolverOptions("decomp");
		//iterate over the vector
		
		int tmpVal;
		
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
						if((*vit)->name.find("minDemand") !=  std::string::npos){
							
							
							std::istringstream minDemandBuffer( (*vit)->value);
							minDemandBuffer >> m_minDemand;
							std::cout << "m_minDemand = " << m_minDemand <<  std::endl;
						
						}else{
							if( (*vit)->name.find("demand") !=  std::string::npos ){
								
								
								std::istringstream demandBuffer( (*vit)->value);
								demandBuffer >> tmpVal;
								demand.push_back( tmpVal);
								//std::cout << "demand = " << tmpVal <<  std::endl;
								
							}else{
								if((*vit)->name.find("routeCapacity") !=  std::string::npos ){
									std::istringstream routeCapacityBuffer( (*vit)->value);
									routeCapacityBuffer >> m_routeCapacity;
									std::cout << "m_routeCapacity = " << m_routeCapacity <<  std::endl;
									
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
											std::cout << "solution number = " << solutionNumber  << std::endl;
											
											
											pos3 = routeString.find( "e");
											if(pos3  == std::string::npos ) throw ErrorClass("OSoL category attribute not properly defined");
											std::istringstream routeBuffer( routeString.substr( pos3 + 1)  );
											routeBuffer >> routeNumber;
											std::cout << "route number = " <<  routeNumber << std::endl;
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
										}
									}
								}
							}
						}
					}
				}
			}//end if on solver options
			
		}//end for loop on options
	
		//now fill in demand
		m_demand = new int[ m_numNodes];
		std::vector<int>::iterator vit2;
		if(m_numNodes != demand.size( ) ) throw ErrorClass("inconsistent number of demand nodes");
		int i;
		i = 0;
		for (vit2 = demand.begin(); vit2 != demand.end(); vit2++) {
			
			*(m_demand + i++) = *vit2;
			
		}
		demand.clear();
		
	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
}//end getOptions



std::string makeStringFromInt(std::string theString, int theInt){
	ostringstream outStr;
	outStr << theString;
	outStr << theInt;
	return outStr.str();
}//end makeStringFromInt



