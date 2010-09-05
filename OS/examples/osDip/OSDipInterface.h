/* $Id: OSDipInterface.h 3038 2009-11-07 11:43:44Z Gassmann $ */
/** @file OSDipInterface.h
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

#ifndef OSDIPINTERFACE_H
#define OSDIPINTERFACE_H

//===========================================================================//
#include "UtilMacros.h"
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
#include "CoinError.hpp"
#include "OSDefaultSolver.h"  
#include "OSWSUtil.h"     
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "CoinHelperFunctions.hpp"


#include <map>
#include <set>

//===========================================================================//
/*!
 * \class OS_DipInterface
 * A generic class to interface with Optimization Services (OS) for use  
 *    in Dip (Decomposition in Integer Programming).
 *
 *
 */

//===========================================================================//
class OS_DipInterface {


public:

	/** Best known LB/UB */
	bool      m_isProvenOptimal;
	double    m_bestKnownLB;
	double    m_bestKnownUB;



	OSInstance *m_osinstance;
	OSOption *m_osoption;	
	OSiLReader *m_osilreader;
	OSoLReader *m_osolreader;
	char* m_integerVars;
	CoinPackedMatrix *m_coinpm;
	CoinPackedVector *m_row ;


	/** @name Helper Methods. */
	void readOSiL(string & filename);
	
	void readOSoL(string & filename);

	CoinPackedVector *getRow( int i);
	
	//return a CoinPackedMatrix
	CoinPackedMatrix *getCoinPackedMatrix( );
	
    /** Returns array[getNumCols()] specifying if a variable is integer.

	At present, simply coded as zero (continuous) and non-zero (integer)
	May be extended at a later date.
    */	
	const char* getIntegerColumns();
	
	//get the objective function constant
	double getObjectiveOffset()	;
	
	
	//get the set of variable indexes for each block in the model
	//std::vector<std::set<int> > getBlockVarIndexes();
	
	
	//get the objective function coefficients
	double *getObjectiveFunctionCoeff();
	


	void initMembers();

	inline const double getBestKnownLB() const {return m_bestKnownLB;}
	inline const double getBestKnownUB() const {return m_bestKnownUB;}


	//some OS wrapper methods

	/**
	 * Get objective maxOrMins. One maxOrMin for each objective.
	 * 
	 * @return a std::string array of objective maxOrMins ("max" or "min"), null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	inline const std::string* getObjectiveMaxOrMins() const {return m_osinstance->getObjectiveMaxOrMins();} 



	/**
	 * Get objective constants. One constant for each objective.
	 * 
	 * @return a double array of objective constants, null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	inline const double* getObjectiveConstants() const {return m_osinstance->getObjectiveConstants();} 

	/**
	 * Get objective weights. One weight for each objective.
	 * 
	 * @return a double array of objective weights, null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	inline const double* getObjectiveWeights() const {return m_osinstance->getObjectiveWeights();} 

	/**
	 * getNumberOfIntegerVariables
	 * @return an integer which is the number of general integer variables. 
	 */
	inline const int getNumberOfIntegerVariables() const {return m_osinstance->getNumberOfIntegerVariables();} 

	/**
	 * getNumberOfBinaryVariables
	 * @return an integer which is the number of binary variables. 
	 */
	inline const int getNumberOfBinaryVariables() const {return m_osinstance->getNumberOfBinaryVariables();}
	

	/**
	 * Get variable number. 
	 * 
	 * @return variable number. 
	 */
	inline const int getVariableNumber() const {return m_osinstance->getVariableNumber();} 

	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number. 
	 */
	inline const int getConstraintNumber() const {return m_osinstance->getConstraintNumber();} 
	
	/**
	 * Get variable lower bounds. 
	 * 
	 * @return pointer to variable lower bounds. 
	 */
	inline const double* getColLower() const {return m_osinstance->getVariableLowerBounds();} 
	
		
	/**
	 * Get variable upper bounds. 
	 * 
	 * @return pointer to variable upper bounds. 
	 */
	inline const double* getColUpper() const {return m_osinstance->getVariableUpperBounds();} 
	
	
	/**
	 * Get variable names. 
	 * 
	 * @return array of variable names. 
	 */
	inline const std::string* getVariableNames() const {return m_osinstance->getVariableNames();} 
	
	
	/**
	 * Get constraint lower bounds. 
	 * 
	 * @return pointer to constraint lower bounds. 
	 */
	inline const double* getRowLower() const {return m_osinstance->getConstraintLowerBounds();} 
	

	/**
	 * Get constraint upper bounds. 
	 * 
	 * @return pointer to constraint upper bounds. 
	 */
	inline const double* getRowUpper() const {return m_osinstance->getConstraintUpperBounds();} 
	
	
	/**
	 * Get constraint names. 
	 * 
	 * @return array of constraint names. 
	 */
	inline const std::string* getConstraintNames() const {return m_osinstance->getConstraintNames();} 
	
	//end wrapper methods

	OS_DipInterface(string & fileName);
	OS_DipInterface();
	~OS_DipInterface();
};

#endif
