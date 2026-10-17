/* $Id$ */
/** @file OSmps2osil.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2013, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#include "OSmps2osil.h"
#include "OSOutput.h"
#include "OSErrorClass.h"
#include <iostream>
#include <sstream>


using std::cout;
using std::endl;

OSmps2osil::OSmps2osil( std::string mpsfilename)
{
    m_MpsData = new CoinMpsIO();
    int nOfSOS;
    CoinSet ** SOS;
    int status = m_MpsData->readMps( &mpsfilename[ 0], "", nOfSOS, SOS );
    if (status != 0) 
        throw ErrorClass("Error trying to read MPS file");

    m_CoinPackedMatrix  =  new CoinPackedMatrix( *(m_MpsData->getMatrixByCol()));

    if (nOfSOS > 0)
    {
#ifndef NDEBUG
        std::ostringstream outStr;
        {
             outStr << "Detected " << nOfSOS << " special ordered sets" << std::endl;
            for (int i=0; i < nOfSOS; i++)
            {
                int numberEntries = SOS[i]->numberEntries();
                const int * which = SOS[i]->which();
                const double * weights = SOS[i]->weights();
                outStr << "SOS " << i << " has type " << SOS[i]->setType();
                outStr << " and " << numberEntries << " entries:" << std::endl;
                for (int j=0;j<numberEntries;j++)
                    outStr << "    Idx: " << which[j] << "    Weight: " << weights[j] << std::endl;
            }
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
        }
#endif
//        throw ErrorClass("SOS has not been implemented yet");
    }

#if 0 // Not yet supported
    int * columnStart = NULL;
    int * columnIdx = NULL;
    double * elements = NULL;
    status = m_MpsData->readQuadraticMps(NULL, columnStart, columnIdx, elements, 0);

    if (status != 0)
    {
        if (status != -2 && status != -3)
            throw ErrorClass("Error trying to read QUADOBJ section");
    }
    else
    {
#ifndef NDEBUG
        std::ostringstream outStr;
        int numberColumns=m_MpsData->getNumCols();
        outStr << "Quadratic objective has " << columnStart[numberColumns] << " entries" << std::endl;
        outStr << "Column starts:" << std::endl;
        for (int i=0; i<=numberColumns; i++)
            outStr << "    " << columnStart[i] << std::endl; 
        for (int i=0; i<numberColumns; i++)
        {
            if (columnStart[i] < columnStart[i+1])
            {
                outStr << "Column " << i << ":    index      value" << std::endl;
                for (int j=columnStart[i];j<columnStart[i+1];j++)
                    outStr << "                 " << columnIdx[j] << "       " << elements[j] << std::endl;
            }
        }
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
//        throw ErrorClass("QUADOBJ has not been implemented yet");
    }

    int nOfCones;
    int * coneStart = NULL;
    int * coneIdx = NULL;
    int * coneType = NULL;
    status = m_MpsData->readConicMps(NULL, coneStart, coneIdx, coneType, nOfCones);
    if (status != 0) 
    {
        if (status != -2 && status != -3)
            throw ErrorClass("Error trying to read cone section");
    }
    else
    {
#ifndef NDEBUG
        std::ostringstream outStr;
        outStr << "Conic section has " << nOfCones << " cones" << std::endl;
        for (int i=0;i<nOfCones;i++) 
        {
            outStr << "Cone " << i << " has " << coneStart[i+1]-coneStart[i] << " entries ";
            outStr << "(type " << coneType[i] << "):" << std::endl;
            for (int j=coneStart[i];j<coneStart[i+1];j++)
                outStr << "    " << coneIdx[j] << std::endl;
        }
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
//        throw ErrorClass("CSECTION has not been implemented yet");
    }
#endif

}// end constructor

OSmps2osil::~OSmps2osil()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, "now delete m_MpsData\n");
#endif
    delete m_MpsData;
    m_MpsData = NULL;
    delete m_CoinPackedMatrix;
    m_CoinPackedMatrix = NULL;
    osinstance->instanceData->linearConstraintCoefficients->value->el = NULL;
    osinstance->instanceData->linearConstraintCoefficients->start->el = NULL;
    osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
    osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
    delete osinstance;
    osinstance = NULL;
    //delete m_MpsData;

} // end destructor

// Kipp-- put in integer programming
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
    osinstance->setInstanceName( const_cast<char*>(m_MpsData->getProblemName()));
    //
    // get the variable information
    //
    osinstance->setVariableNumber( numvar);
    for(i = 0; i < numvar; i++)
    {
        osinstance->addVariable(i, m_MpsData->columnName( i),
                                m_MpsData->getColLower()[ i], m_MpsData->getColUpper()[ i],
                                m_MpsData->isInteger( i)? 'I':'C');
    }
    //
    // now create the objective function
    //
    SparseVector* objectiveCoefficients = NULL;
    objectiveCoefficients = new SparseVector( numvar);
    double *p = const_cast<double*>(m_MpsData->getObjCoefficients());
    for(i = 0; i < numvar; i++)
    {
        objectiveCoefficients->indexes[i] = i;
        objectiveCoefficients->values[i] = *(p++);
    }
    // We will go with the
    // majority on this one and assume minimization by default
    osinstance->setObjectiveNumber( numberObj) ;
    osinstance->addObjective(objIndex, m_MpsData->getObjectiveName(),
                             "min", m_MpsData->objectiveOffset(),  objWeight, objectiveCoefficients) ;
    delete objectiveCoefficients;
    objectiveCoefficients = NULL;
    //
    // now fill in row information
    //
    osinstance->setConstraintNumber( numrows);
    double constant = 0.0;
    for(i = 0; i < numrows; i++)
    {
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
            const_cast<double*>(m_CoinPackedMatrix->getElements()), valuesBegin,  valuesEnd,
            const_cast<int*>(m_CoinPackedMatrix->getIndices()),  indexesBegin,  indexesEnd,
            const_cast<int*>(m_CoinPackedMatrix->getVectorStarts()),  startsBegin,  startsEnd);
    return true;
}





