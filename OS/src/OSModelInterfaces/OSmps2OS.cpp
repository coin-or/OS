/* $Id: OSmps2OS.cpp 4692 2013-10-16 13:56:17Z Gassmann $ */
/** @file OSmps2OS.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2013, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#include "OSmps2OS.h"
#include "OSOutput.h"
#include "OSErrorClass.h"
#include <iostream>



using std::cout;
using std::endl;

OSmps2OS::OSmps2OS( std::string mpsfilename)
{
    m_MpsData = new CoinMpsIO();
    m_nOfSOS = 0;
    m_SOS = NULL;
    m_quadColumnStart = NULL;
    m_quadColumnIdx = NULL;
    m_quadElements = NULL;
    m_coneStart = NULL;
    m_coneIdx = NULL;
    m_coneType = NULL;

    int status = m_MpsData->readMps( &mpsfilename[ 0], "", m_nOfSOS, m_SOS );
    if (status != 0) 
        throw ErrorClass("Error trying to read MPS file");

    m_CoinPackedMatrix  =  new CoinPackedMatrix( *(m_MpsData->getMatrixByCol()));

    if (m_nOfSOS > 0)
    {
#ifndef NDEBUG
        std::ostringstream outStr;
        {
             outStr << "Detected " << m_nOfSOS << " special ordered sets" << std::endl;
            for (int i=0; i < m_nOfSOS; i++)
            {
                int numberEntries = m_SOS[i]->numberEntries();
                const int * which = m_SOS[i]->which();
                const double * weights = m_SOS[i]->weights();
                outStr << "SOS " << i << " has type " << m_SOS[i]->setType();
                outStr << " and " << numberEntries << " entries:" << std::endl;
                for (int j=0;j<numberEntries;j++)
                    outStr << "    Idx: " << which[j] << "    Weight: " << weights[j] << std::endl;
            }
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
        }
#endif
//        throw ErrorClass("SOS has not been implemented yet");
    }

    while (m_MpsData->reader()->whichSection (  ) != COIN_ENDATA_SECTION ) 
    {
        switch (m_MpsData->reader()->whichSection (  ))
        {
            case COIN_QUAD_SECTION:
//#if 0 // Not yet supported
                status = m_MpsData->readQuadraticMps(NULL, m_quadColumnStart, m_quadColumnIdx, m_quadElements, 0);

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
                    outStr << "Quadratic objective has " << m_quadColumnStart[numberColumns] << " entries" << std::endl;
                    outStr << "Column starts:" << std::endl;
                    for (int i=0; i<=numberColumns; i++)
                        outStr << "    " << m_quadColumnStart[i] << std::endl; 
                    for (int i=0; i<numberColumns; i++)
                    {
                        if (m_quadColumnStart[i] < m_quadColumnStart[i+1])
                        {
                            outStr << "Column " << i << ":    index      value" << std::endl;
                            for (int j=m_quadColumnStart[i];j<m_quadColumnStart[i+1];j++)
                                outStr << "                 " << m_quadColumnIdx[j] << "       " << m_quadElements[j] << std::endl;
                        }
                    }
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
//                    throw ErrorClass("QUADOBJ has not been implemented yet");
                }
                break;


            case COIN_CONIC_SECTION:
                m_nOfCones;
                status = m_MpsData->readConicMps(NULL, m_coneStart, m_coneIdx, m_coneType, m_nOfCones);
                if (status != 0) 
                {
                    if (status != -2 && status != -3)
                        throw ErrorClass("Error trying to read cone section");
                }
                else
                {
#ifndef NDEBUG
                    std::ostringstream outStr;
                    outStr << "Conic section has " << m_nOfCones << " cones" << std::endl;
                    for (int i=0;i<m_nOfCones;i++) 
                    {
                        outStr << "Cone " << i << " has " << m_coneStart[i+1]-m_coneStart[i] << " entries ";
                        outStr << "(type " << m_coneType[i] << "):" << std::endl;
                        for (int j=m_coneStart[i];j<m_coneStart[i+1];j++)
                            outStr << "    " << m_coneIdx[j] << std::endl;
                    }
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
//                    throw ErrorClass("CSECTION has not been implemented yet");
                }
//#endif
                break;

            
            case COIN_BASIS_SECTION:
#ifndef NDEBUG
                {
                    std::ostringstream outStr;
                    outStr << "Basis section has not been implemented yet" << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
                }
#endif
                break;

            default:
                throw ErrorClass("encountered unknown section in MPS file");
         }
     }
}// end constructor

OSmps2OS::~OSmps2OS()
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

    if (m_SOS != NULL)
        delete m_SOS;
    m_SOS = NULL;

    if (m_quadColumnStart != NULL)
        delete m_quadColumnStart;
    m_quadColumnStart = NULL;

    if (m_quadColumnIdx != NULL)
        delete m_quadColumnIdx;
    m_quadColumnIdx = NULL;

    if (m_quadElements != NULL)
        delete m_quadElements;
    m_quadElements = NULL;

    if (m_coneStart != NULL)
        delete m_coneStart;
    m_coneStart = NULL;

    if (m_coneIdx != NULL)
        delete m_coneIdx;
    m_coneIdx = NULL;

    if (m_coneType != NULL)
        delete m_coneType;
    m_coneType = NULL;

} // end destructor

// Kipp-- put in integer programming
bool OSmps2OS::createOSObjects( )
{
    int i;
    int numvar  = m_MpsData->getNumCols();
    int numrows = m_MpsData->getNumRows();
    int numnonz = m_MpsData->getNumElements();
    int numberObj = 1;
    int objIndex = -1;
    std::ostringstream outStr;

    osinstance = new OSInstance();
    
    osinstance->setInstanceName( const_cast<char*>(m_MpsData->getProblemName()));
    //
    // get the variable information
    //
    osinstance->setVariableNumber( numvar);

    for(i = 0; i < numvar; i++)
    {
        char vartype = 'C';
        if (m_MpsData->isInteger( i) )
        {
            if (m_MpsData->getColLower()[ i] == 0 && m_MpsData->getColUpper()[ i] == 1)
                vartype = 'B';
            else
                vartype = 'I';
        }
        osinstance->addVariable(i, m_MpsData->columnName( i),
                                m_MpsData->getColLower()[ i], m_MpsData->getColUpper()[ i],
                                vartype);
    }
    //
    // now create the objective function
    //
    double objWeight = 1.0;
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

    // if there is a quadratic section, store it
    if (m_quadColumnStart != NULL)
    {
        int numberColumns=m_MpsData->getNumCols();
        int numberElements=m_quadColumnStart[numberColumns];
        if (numberElements > 0)
        {
            int *rowindexes = new int[numberElements];
            for (int i=0; i<numberElements;i++)
                rowindexes[i] = -1;
            int *colindexes = new int[numberElements];
            for (int i=0; i<numberColumns; i++)
                for (int j=m_quadColumnStart[i];j<m_quadColumnStart[i+1];j++)
                    colindexes[j] = i;
            osinstance->setQuadraticTerms(numberElements, rowindexes, colindexes, 
                m_quadColumnIdx, m_quadElements, 0, numberElements-1);
        }
    }
    // store any cone information (TODO)
    // store SOS -- if there are nonstandard weights, put into an OSOption object (TODO)
    // if there is basis information, it needs to be stored in an OSOption object (TODO)
    return true;
}

