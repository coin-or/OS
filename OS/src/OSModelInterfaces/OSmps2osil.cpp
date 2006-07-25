/** @file OSmps2osil.cpp
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


#include "OSmps2osil.h"
//#include "OSDataStructures.h"
#include <CoinMpsIO.hpp>
#include <CoinPackedMatrix.hpp>
#include <iostream> 



using namespace std;

OSmps2osil::OSmps2osil( string mpsfilename)
{
	m_MpsData = new CoinMpsIO();
	m_MpsData->readMps( &mpsfilename[ 0] );	
	m_CoinPackedMatrix  =  new CoinPackedMatrix( *(m_MpsData->getMatrixByCol()));
}// end constructor

OSmps2osil::~OSmps2osil(){
	m_MpsData = NULL;
	delete m_CoinPackedMatrix;
	m_CoinPackedMatrix = NULL;
	osinstance->instanceData->linearConstraintCoefficients->value->el = NULL;
	osinstance->instanceData->linearConstraintCoefficients->start->el = NULL;
	osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
	osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
	delete osinstance;                       
	osinstance = NULL;
	#ifdef DEBUG
	cout << "now delete m_MpsData" << endl;
	#endif
	delete m_MpsData;

} // end destructor

bool OSmps2osil::createOSInstance( )
{
	osinstance = new OSInstance();
	int i;
	int numvar =  m_MpsData->getNumCols();
	int numrows =  m_MpsData->getNumRows();
	int numnonz = m_MpsData->getNumElements();
	int numberObj = 1;
	int objIndex = -1;
	double objWeight = 1.0;
	osinstance->setInstanceName((char*)m_MpsData->getProblemName());
	//
	// get the variable information
	//
	string initString;
	double init = OSNAN;
	osinstance->setVariableNumber( numvar);
	for(i = 0; i < numvar; i++)
	{
		osinstance->addVariable(i, m_MpsData->columnName( i), 
			m_MpsData->getColLower()[ i], m_MpsData->getColUpper()[ i], 
			m_MpsData->isInteger( i)? 'I':'C', init, initString);
	}
	//
	// now create the objective function
	//	
	SparseVector* objectiveCoefficients = NULL;
	objectiveCoefficients = new SparseVector( numvar);
	double *p = (double*)m_MpsData->getObjCoefficients();
	for(i = 0; i < numvar; i++){
		objectiveCoefficients->indexes[i] = i;
		objectiveCoefficients->values[i] = *(p++);
	}
	// kipp -- check on this -- does MPS assume a min???
	osinstance->setObjectiveNumber( numberObj) ;
	osinstance->addObjective(objIndex, m_MpsData->getObjectiveName(), 
	"min", m_MpsData->objectiveOffset(),  objWeight, objectiveCoefficients) ;
	delete objectiveCoefficients;
	objectiveCoefficients = NULL;
	//
	// now fill in row information
	//
	osinstance->setConstraintNumber( numrows);
	double constant = OSNAN;
	for(i = 0; i < numrows; i++){
		osinstance->addConstraint(i, m_MpsData->rowName( i), m_MpsData->getRowLower()[i], 
		m_MpsData->getRowUpper()[i], constant);
	}
	//
	// now fill in the lp arrays
	//
	int valuesBegin = 0;
	int valuesEnd = numnonz - 1;
	int startsBegin = 0;
	int indexesBegin = 0;
	int indexesEnd = numnonz - 1;
	int startsEnd = m_CoinPackedMatrix->isColOrdered()?numvar:numrows;
	osinstance->setLinearConstraintCoefficients(numnonz,  m_CoinPackedMatrix->isColOrdered(), 
		(double*)m_CoinPackedMatrix->getElements(), valuesBegin,  valuesEnd, 
		(int*)m_CoinPackedMatrix->getIndices(),  indexesBegin,  indexesEnd,   			
		(int*)m_CoinPackedMatrix->getVectorStarts(),  startsBegin,  startsEnd);
	return true;
}




