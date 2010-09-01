/* $Id: OSDipInterface.cpp 3038 2009-11-07 11:43:44Z Gassmann $ */
/** @file OSDipInterface.cpp
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

//===========================================================================//




#include "OSDipInterface.h"
#include "UtilMacrosDecomp.h"
 


//===========================================================================//
void OS_DipInterface::readOSiL(string & fileName){
	
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();


	
	try{


		std::string osil;
		osil = fileUtil->getFileAsString( fileName.c_str() );
		m_osilreader = new OSiLReader();
		m_osinstance = m_osilreader->readOSiL( osil);
	
		delete fileUtil;
		fileUtil  = NULL;
		//kipp  -- worry about garbage collection here -- do I delete m_osinstance
		//delete  osilreader;
		//osilreader = NULL;
		
		
	}
	catch(const ErrorClass& eclass){
		std::cout << "PROBLEM READING OSiL File" <<std::endl;
		delete fileUtil;
		std::cout << eclass.errormsg <<  std::endl;
		fileUtil  = NULL;
		throw ErrorClass( eclass.errormsg);
		
	} 
	
	
}//end readOSiL


//===========================================================================//
void OS_DipInterface::readOSoL(string & fileName){
	
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();	
	try{


		std::string osol;
		osol = fileUtil->getFileAsString( fileName.c_str() );
		m_osolreader = new OSoLReader();
		m_osoption = m_osolreader->readOSoL( osol);
	
		delete fileUtil;
		fileUtil  = NULL;
		//kipp  -- worry about garbage collection here -- do I delete m_osinstance
		//delete  osilreader;
		//osilreader = NULL;
		
		
	}
	catch(const ErrorClass& eclass){
		std::cout << "Problem reading OSoL File" <<std::endl;
		delete fileUtil;
		std::cout << eclass.errormsg <<  std::endl;
		fileUtil  = NULL;
		throw ErrorClass( eclass.errormsg);
		
	} 
	
	
}// end readOSoL

CoinPackedMatrix * OS_DipInterface::getCoinPackedMatrix( ){
	
	bool columnMajor = false;
	double maxGap = 0;
	CoinPackedMatrix *coinpm = NULL;
	
	coinpm = new CoinPackedMatrix(
			columnMajor, //Column or Row Major
			columnMajor? m_osinstance->getConstraintNumber() : m_osinstance->getVariableNumber(), //Minor Dimension
			columnMajor? m_osinstance->getVariableNumber() : m_osinstance->getConstraintNumber(), //Major Dimension
			m_osinstance->getLinearConstraintCoefficientNumber(), //Number of nonzeroes
			columnMajor? m_osinstance->getLinearConstraintCoefficientsInColumnMajor()->values : 
				m_osinstance->getLinearConstraintCoefficientsInRowMajor()->values, //Pointer to matrix nonzeroes
			columnMajor? m_osinstance->getLinearConstraintCoefficientsInColumnMajor()->indexes : 
				m_osinstance->getLinearConstraintCoefficientsInRowMajor()->indexes, //Pointer to start of minor dimension indexes -- change to allow for row storage
			columnMajor? m_osinstance->getLinearConstraintCoefficientsInColumnMajor()->starts : 
			m_osinstance->getLinearConstraintCoefficientsInRowMajor()->starts, //Pointers to start of columns.
			0,   0, maxGap );
	
	return coinpm;
}//end getCoinPackedMatrix

CoinPackedVector * OS_DipInterface::getRow( int i){
	
	 CoinPackedVector *row = NULL;
	 
	 row =  new CoinPackedVector();
	 

	 int k;
	 
	 SparseMatrix* sm;
	 
	 sm = m_osinstance->getLinearConstraintCoefficientsInRowMajor();
	 
	 for(k = sm->starts[i];  k < sm->starts[i + 1];  k++){
		 
		 row->insert(sm->indexes[k], sm->values[k]);
		 
	 }
	 

	 
	 return row;
}//end getRow

const char* OS_DipInterface::getIntegerColumns(){
	
	char* integerVars =  NULL;
	int numVars = getVariableNumber();
	integerVars = new char[ numVars];
	int i;
	
	for(i  = 0; i < numVars;  i++){
		
		if( m_osinstance->getVariableTypes()[ i] == 'B' || m_osinstance->getVariableTypes()[i] == 'I') integerVars[i] = '1';
		else integerVars[i] = '0';
		
		
	}
	return integerVars;
	
}// end getIntegerColumns


double OS_DipInterface::getObjectiveOffset(){
	
	double offset = 0;
	//assume only one objective function for now
	
	if(getObjectiveConstants() != NULL){
		offset = getObjectiveConstants()[0];
	}
	
	return offset;
}// end getObjectiveOffset


std::set<int> OS_DipInterface::getVariableMap(std::vector<int> rowIndexes){
	std::set<int> variableSet;
	// get a sparse matrix by row
	SparseMatrix *sm;
	sm = m_osinstance->getLinearConstraintCoefficientsInRowMajor();	
    std::vector<int>::iterator vit;
    int i;
  
    for(vit = rowIndexes.begin(); vit != rowIndexes.end(); vit++){
    	for( i =  sm->starts[*vit]  ; i < sm->starts[*vit + 1]; i++){
    		// insert int the set any new columns
			if( variableSet.find( sm->indexes[ i] ) == variableSet.end() ) {
				variableSet.insert( sm->indexes[ i]);
			}
    	}
	 }	
    
	return variableSet;
} 

double* OS_DipInterface::getObjectiveFunctionCoeff(){
	
	//Dip has only one objective function 
	
	return  m_osinstance->getDenseObjectiveCoefficients()[ 0];
}// end getObjectiveFunctionCoeff()
