/* $Id$ */
/** @file OSInstance.cpp
 * \brief This file defines the OSInstance class along with its supporting classes.
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2014, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in the root directory for terms.
 *
 */


#include "OSGeneral.h"
#include "OSInstance.h"
#include "OSMathUtil.h"
#include "OSMatrix.h"
#include "OSErrorClass.h"
#include "OSParameters.h"
#include "OSOutput.h"
#include "OSgLWriter.h"

#include <cstdlib>
#include <stack>
#include <iostream>
#include <sstream>


using namespace std;
using std::ostringstream;


OSInstance::OSInstance():
    bVariablesModified(false),
    bObjectivesModified(false),
    bConstraintsModified(false),
    bAMatrixModified(false),
    m_sInstanceName(""),
    m_sInstanceSource(""),
    m_sInstanceDescription(""),
    m_sInstanceCreator(""),
    m_sInstanceLicence(""),
    m_bProcessVariables(false),
    m_iVariableNumber(-1),
    m_iNumberOfIntegerVariables( 0),
    m_iNumberOfBinaryVariables( 0),
    m_iNumberOfSemiContinuousVariables( 0),
    m_iNumberOfSemiIntegerVariables( 0),
    m_iNumberOfStringVariables( 0),
    m_msVariableNames(NULL),
    m_mcVariableTypes(NULL),
    m_mdVariableLowerBounds(NULL),
    m_mdVariableUpperBounds(NULL),
    //m_mdVariableInitialValues(NULL), -- deprecated
    //m_msVariableInitialStringValues(NULL), -- deprecated
    m_bProcessObjectives(false),
    m_iObjectiveNumber(-1),
    m_iObjectiveNumberNonlinear( 0),
    m_msObjectiveNames(NULL),
    m_msMaxOrMins(NULL),
    m_miNumberOfObjCoef(NULL),
    m_mdObjectiveConstants(NULL),
    m_mdObjectiveWeights(NULL),
    m_mObjectiveCoefficients(NULL),
    m_bGetDenseObjectives(false),
    m_mmdDenseObjectiveCoefficients(NULL),
    m_bProcessConstraints(false),
    m_iConstraintNumber(-1),
    m_iConstraintNumberNonlinear( 0),
    m_msConstraintNames(NULL),
    m_mdConstraintLowerBounds(NULL),
    m_mdConstraintUpperBounds(NULL),
    m_mdConstraintConstants( NULL),
    m_mcConstraintTypes(NULL),
    m_bProcessLinearConstraintCoefficients(false),
    m_iLinearConstraintCoefficientNumber(-1),
    m_bColumnMajor(true),
    m_linearConstraintCoefficientsInColumnMajor(NULL),
    m_linearConstraintCoefficientsInRowMajor(NULL),
    m_iNumberOfQuadraticRowIndexes( 0),
    m_bQuadraticRowIndexesProcessed(false),
    m_miQuadRowIndexes( NULL),
    m_bProcessQuadraticTerms(false),
    m_iQuadraticTermNumber(-1),
    m_quadraticTerms( NULL),
    m_bQTermsAdded( false),
    m_iNumberOfNonlinearExpressionTreeIndexes( 0),
    m_bNonlinearExpressionTreeIndexesProcessed( false),
    m_miNonlinearExpressionTreeIndexes( NULL),
    m_iNumberOfNonlinearExpressionTreeModIndexes( 0),
    m_bNonlinearExpressionTreeModIndexesProcessed( false),
    m_miNonlinearExpressionTreeModIndexes( NULL),
    m_binitForAlgDiff( false),
    m_iNumberOfNonlinearVariables( 0),
    m_bProcessNonlinearExpressions( false),
    m_iNonlinearExpressionNumber( -1),
    m_miNonlinearExpressionIndexes( NULL),
    m_bProcessExpressionTrees( false),
    m_bProcessExpressionTreesMod( false),
    m_mdConstraintFunctionValues( NULL),
    m_mdObjectiveFunctionValues( NULL),
    m_iJacValueSize( 0),
    m_miJacStart( NULL),
    m_miJacIndex( NULL),
    m_mdJacValue( NULL),
    m_miJacNumConTerms( NULL),
    m_sparseJacMatrix( NULL),
    m_iHighestTaylorCoeffOrder(-1),
    m_LagrangianExpTree(NULL),
    m_bLagrangianExpTreeCreated( false),
    m_LagrangianSparseHessian( NULL),
    m_bLagrangianSparseHessianCreated( false),
    m_miNonLinearVarsReverseMap( NULL),
    m_bAllNonlinearVariablesIndex( false),
    m_bOSADFunIsCreated( false),
    m_bCppADTapesBuilt( false),
    m_bCppADMustReTape( false),
    m_bDuplicateExpressionTreesMap( false),
    m_bNonLinearStructuresInitialized( false),
    m_bSparseJacobianCalculated( false),
    m_iHighestOrderEvaluated( -1),
    m_mmdObjGradient( NULL),
    m_bProcessMatrices( false),
    m_iMatrixNumber (-1),
    m_miMatrixSymmetry(NULL),
    m_miMatrixType(NULL),
    m_miMatrixNumberOfColumns(NULL),
    m_miMatrixNumberOfRows(NULL),
    m_msMatrixNames(NULL),
    m_mMatrix(NULL),

//    m_mExpandedMatricesInColumnMajor(NULL),
//    m_mExpandedMatricesInRowMajor(NULL),
//    m_mMatrixBlocksInColumnMajor(NULL),
//    m_mMatrixTransformation(NULL),

    m_iMatrixVarNumber(-1),
    m_iMatrixObjNumber(-1),
    m_iMatrixConNumber(-1),
    m_iMatrixExpressionNumber(-1),

    m_bProcessTimeDomain( false),
    m_bProcessTimeStages( false),
    m_bProcessTimeInterval( false),
    m_bFiniteTimeStages( false),
    m_iNumberOfTimeStages(-1),
    m_sTimeDomainFormat(""),
    m_msTimeDomainStageNames(NULL),
    m_miTimeDomainStageVariableNumber(NULL),
    m_mmiTimeDomainStageVarList(NULL),
    m_miTimeDomainStageConstraintNumber(NULL),
    m_mmiTimeDomainStageConList(NULL),
    m_miTimeDomainStageObjectiveNumber(NULL),
    m_mmiTimeDomainStageObjList(NULL),
    bUseExpTreeForFunEval( false)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside OSInstance Constructor");
#endif
    this->instanceHeader = new GeneralFileHeader();
    this->instanceData = new InstanceData();
}

OSInstance::~OSInstance()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "OSInstance Destructor Called");
#endif
    std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
    // delete the temporary arrays

    if (this->instanceData->variables != NULL && 
        this->instanceData->variables->numberOfVariables > 0 && 
        m_bProcessVariables == true)
    {
        if (m_msVariableNames != NULL) delete[] m_msVariableNames;
        m_msVariableNames = NULL;
        if (m_mcVariableTypes != NULL) delete[] m_mcVariableTypes;
        m_mcVariableTypes = NULL;
        if (m_mdVariableLowerBounds != NULL) delete[] m_mdVariableLowerBounds;
        m_mdVariableLowerBounds = NULL;
        if (m_mdVariableUpperBounds != NULL) delete[] m_mdVariableUpperBounds;
        m_mdVariableUpperBounds = NULL;
    }


    if(m_bProcessConstraints == true)
    {
        if (m_msConstraintNames != NULL) delete[] m_msConstraintNames;
        m_msConstraintNames = NULL;
        if (m_mcConstraintTypes != NULL) delete[] m_mcConstraintTypes;
        m_mcConstraintTypes = NULL;
        if (m_mdConstraintConstants != NULL) delete[]  m_mdConstraintConstants;
        m_mdConstraintConstants = NULL;
        if (m_mdConstraintLowerBounds != NULL) delete[] m_mdConstraintLowerBounds;
        m_mdConstraintLowerBounds = NULL;
        if (m_mdConstraintUpperBounds != NULL) delete[] m_mdConstraintUpperBounds;
        m_mdConstraintUpperBounds = NULL;
    }


    int i;
    //if(instanceData->objectives->numberOfObjectives > 0 && m_mObjectiveCoefficients != NULL){
    if(instanceData->objectives != NULL && m_bProcessObjectives == true )
    {
        for(i = 0; i < instanceData->objectives->numberOfObjectives; i++)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, "Delete m_mObjectiveCoefficients[i]");
#endif
            if (m_mObjectiveCoefficients[i] != NULL) delete m_mObjectiveCoefficients[i];
            m_mObjectiveCoefficients[i] = NULL;
        }
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr <<  "Delete m_msObjectiveNames" << std::endl;
        outStr <<  "Delete m_msMaxOrMins" << std::endl;
        outStr <<  "Delete m_miNumberOfObjCoef" << std::endl;
        outStr <<  "Delete m_mdObjectiveConstants" << std::endl;
        outStr <<  "Delete m_mdObjectiveWeights" << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        if (m_msObjectiveNames != NULL) delete[] m_msObjectiveNames;
        m_msObjectiveNames = NULL;
        if (m_msMaxOrMins != NULL) delete[] m_msMaxOrMins;
        m_msMaxOrMins = NULL;
        if (m_miNumberOfObjCoef != NULL) delete[] m_miNumberOfObjCoef;
        m_miNumberOfObjCoef = NULL;
        if (m_mdObjectiveConstants != NULL) delete[] m_mdObjectiveConstants;
        m_mdObjectiveConstants = NULL;
        if (m_mdObjectiveWeights != NULL) delete[] m_mdObjectiveWeights;
        m_mdObjectiveWeights = NULL;
        if (m_mObjectiveCoefficients != NULL) delete[] m_mObjectiveCoefficients;
        m_mObjectiveCoefficients = NULL;
    }

    if(instanceData->objectives != NULL && m_bGetDenseObjectives == true)
    {
        for(i = 0; i < instanceData->objectives->numberOfObjectives; i++)
        {
            //delete m_mmdDenseObjectiveCoefficients[i];
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, "delete m_mmdDenseObjectiveCoefficients[i]");
#endif
            if (m_mmdDenseObjectiveCoefficients[i] != NULL) 
                delete[] m_mmdDenseObjectiveCoefficients[i];
            m_mmdDenseObjectiveCoefficients[i] = NULL;           
        }
        if (m_mmdDenseObjectiveCoefficients != NULL) 
            delete[] m_mmdDenseObjectiveCoefficients;
        m_mmdDenseObjectiveCoefficients = NULL;
    }

    if( m_linearConstraintCoefficientsInColumnMajor != NULL) 
        delete m_linearConstraintCoefficientsInColumnMajor;
    if (m_linearConstraintCoefficientsInRowMajor != NULL ) 
        delete m_linearConstraintCoefficientsInRowMajor;

    if( (m_binitForAlgDiff == true)  )    
    {
        if (m_miNonLinearVarsReverseMap != NULL) delete[] m_miNonLinearVarsReverseMap;
        m_miNonLinearVarsReverseMap = NULL;

        if (instanceData->objectives != NULL &&
            instanceData->objectives->numberOfObjectives > 0 && 
            m_mmdObjGradient != NULL)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "The number of objectives =  " << instanceData->objectives->numberOfObjectives << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            for(i = 0; i < instanceData->objectives->numberOfObjectives; i++)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "deleting Objective function gradient " << i << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                if (m_mmdObjGradient[i] != NULL) delete[] m_mmdObjGradient[i];
                m_mmdObjGradient[i] = NULL;
            }
            if (m_mmdObjGradient != NULL) delete[] m_mmdObjGradient;
            m_mmdObjGradient = NULL;
        }
    }

    // garbage collection for the gradient
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
        "Do garbage collection for the nonlinear API");
#endif
    if(m_bNonLinearStructuresInitialized == true )
    {
        if (m_mdObjectiveFunctionValues != NULL) delete[] m_mdObjectiveFunctionValues;
        m_mdObjectiveFunctionValues = NULL;
        if (m_mdConstraintFunctionValues != NULL) delete[] m_mdConstraintFunctionValues;
        m_mdConstraintFunctionValues = NULL;
    }
    if(m_bSparseJacobianCalculated == true)
    {
        if (m_miJacStart != NULL) delete[] m_miJacStart;
        m_miJacStart = NULL;
        if (m_miJacIndex != NULL) delete[] m_miJacIndex;
        m_miJacIndex = NULL;
        if (m_mdJacValue != NULL) delete[] m_mdJacValue;
        m_mdJacValue = NULL;
        if (m_miJacNumConTerms != NULL) delete[] m_miJacNumConTerms;
        m_miJacNumConTerms = NULL;
    }
    if( m_bLagrangianExpTreeCreated == true)
    {
        if (m_LagrangianExpTree != NULL) delete m_LagrangianExpTree;
        m_LagrangianExpTree = NULL;
    }
    if( m_bLagrangianSparseHessianCreated == true)
    {
        if (m_LagrangianSparseHessian != NULL) delete m_LagrangianSparseHessian;
        m_LagrangianSparseHessian = NULL;
    }
    if( m_bSparseJacobianCalculated == true)
    {
        if (m_sparseJacMatrix != NULL) delete m_sparseJacMatrix;
        m_sparseJacMatrix = NULL;
    }
    if( (instanceData->quadraticCoefficients != NULL) && (instanceData->quadraticCoefficients->qTerm != NULL) )
    {
        if( (m_bProcessQuadraticTerms == true) )
        {
            if (m_quadraticTerms != NULL) delete m_quadraticTerms;
            m_quadraticTerms = NULL;
        }
        if( (m_bQuadraticRowIndexesProcessed == true) )
        {
            if (m_miQuadRowIndexes != NULL) delete[] m_miQuadRowIndexes;
            m_miQuadRowIndexes = NULL;
        }
    }
    //
    // delete the new expression trees that got created
    //if( m_bLagrangianExpTreeCreated == false  ||  m_bLagrangianExpTreeCreated == true){
    if( (m_bProcessExpressionTrees == true) && (m_bDuplicateExpressionTreesMap == false)  )
    {
        for(posMapExpTree = m_mapExpressionTrees.begin(); posMapExpTree != m_mapExpressionTrees.end(); ++posMapExpTree)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Deleting an expression tree from the map for row  " << posMapExpTree->first  << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            delete m_mapExpressionTrees[ posMapExpTree->first ];
        }
    }
    if( m_bDuplicateExpressionTreesMap == true)
    {
        for(posMapExpTree  = m_mapExpressionTreesMod.begin();
            posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                            "Deleting an expression tree from m_mapExpressionTreesMod");
#endif
            delete m_mapExpressionTreesMod[ posMapExpTree->first ];
        }
    }
    //}
    ///
    if( (m_bNonlinearExpressionTreeIndexesProcessed == true) && (m_mapExpressionTrees.size() > 0) )
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, "Deleting  m_miNonlinearExpressionTreeIndexes");
#endif
        delete[] m_miNonlinearExpressionTreeIndexes;
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, "Done Deleting  m_miNonlinearExpressionTreeIndexes");
#endif
        m_miNonlinearExpressionTreeIndexes = NULL;
    }
    if( (m_bNonlinearExpressionTreeModIndexesProcessed == true) && (m_mapExpressionTreesMod.size() > 0) )
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, "Deleting  m_miNonlinearExpressionTreeModIndexes");
#endif
        delete[] m_miNonlinearExpressionTreeModIndexes;
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, "Done Deleting  m_miNonlinearExpressionTreeModIndexes");
#endif
        m_miNonlinearExpressionTreeModIndexes = NULL;
    }
    if(m_bOSADFunIsCreated == true)
    {
        try
        {
#ifdef COIN_HAS_CPPAD
            delete Fad;
            Fad = NULL;
#else
            throw ErrorClass( "Error: An Algorithmic Differentiation Package Not Available");
#endif
        }
        catch(const ErrorClass& eclass)
        {
            throw ErrorClass( eclass.errormsg);
        }
    }

    if (this->instanceData->matrices != NULL && 
        this->instanceData->matrices->numberOfMatrices > 0 && 
        m_bProcessMatrices == true)
    {
        if (m_miMatrixSymmetry != NULL) delete[] m_miMatrixSymmetry;
        m_miMatrixSymmetry = NULL;
        if (m_miMatrixType != NULL) delete[] m_miMatrixType;
        m_miMatrixType = NULL;
        if (m_miMatrixNumberOfColumns != NULL) delete[] m_miMatrixNumberOfColumns;
        m_miMatrixNumberOfColumns = NULL;
        if (m_miMatrixNumberOfRows != NULL) delete[] m_miMatrixNumberOfRows;
        m_miMatrixNumberOfRows = NULL;
        if (m_msMatrixNames != NULL) delete[] m_msMatrixNames;
        m_msMatrixNames = NULL;

        if (m_mMatrix != NULL) 
        {
            for (int i=0; i < instanceData->matrices->numberOfMatrices; i++)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "DESTROYING MATRIX " << i << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, 
                                  ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                if (m_mMatrix[i] != NULL)
                {
                    delete m_mMatrix[i];
                    m_mMatrix[i] = NULL;
                    instanceData->matrices->matrix[i] = NULL;
                }
            }
            delete[] m_mMatrix;
            m_mMatrix = NULL;
            delete[] instanceData->matrices->matrix;
            instanceData->matrices->matrix = NULL;
        }



//    if( (instanceData->timeDomain->stages->stage != NULL) && (m_bProcessTimeStages == true) ){
//        delete m_Stages;
//        m_Stages = NULL;
    }

    if (m_msTimeDomainStageNames != NULL)
    {
        delete[] m_msTimeDomainStageNames;
        m_msTimeDomainStageNames = NULL;
    }

    if (m_miTimeDomainStageVariableNumber != NULL)
    {
        delete[] m_miTimeDomainStageVariableNumber;
        m_miTimeDomainStageVariableNumber = NULL;
    }

    if (m_mmiTimeDomainStageVarList != NULL)
    {
        for (int i = 0; i < m_iNumberOfTimeStages; i ++)
            delete[] m_mmiTimeDomainStageVarList[i];
        delete[] m_mmiTimeDomainStageVarList;
        m_mmiTimeDomainStageVarList = NULL;
    }

    if (m_miTimeDomainStageConstraintNumber != NULL)
    {
        delete[] m_miTimeDomainStageConstraintNumber;
        m_miTimeDomainStageConstraintNumber = NULL;
    }

    if (m_mmiTimeDomainStageConList != NULL)
    {
        for (int i = 0; i < m_iNumberOfTimeStages; i ++)
            delete[] m_mmiTimeDomainStageConList[i];
        delete[] m_mmiTimeDomainStageConList;
        m_mmiTimeDomainStageConList = NULL;
    }

    if (m_miTimeDomainStageObjectiveNumber != NULL)
    {
        delete[] m_miTimeDomainStageObjectiveNumber;
        m_miTimeDomainStageObjectiveNumber = NULL;
    }

    if (m_mmiTimeDomainStageObjList != NULL)
    {
        for (int i = 0; i < m_iNumberOfTimeStages; i ++)
            delete[] m_mmiTimeDomainStageObjList[i];
        delete[] m_mmiTimeDomainStageObjList;
        m_mmiTimeDomainStageObjList = NULL;
    }

    // delete the two children of OSInstance
    //delete instanceHeader object
    delete instanceHeader;
    instanceHeader = NULL;
    //delete instanceData object
    delete instanceData;
    instanceData = NULL;
}//OSInstance Destructor


Variable::Variable():
    lb(0.0),
    ub(OSDBL_MAX),
    //init(OSNaN()),  deprecated
    type('C'),
    name("")
    //initString("") deprecated
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Variable Constructor");
#endif
}

Variable::~Variable()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Variable Destructor");
#endif
}

Variables::Variables()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Variables Constructor");
#endif
    numberOfVariables = 0;
    var = NULL;
}

Variables::~Variables()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Variables Destructor");
#endif
    int i;
    if(numberOfVariables > 0 && var != NULL)
    {
        for(i = 0; i < numberOfVariables; i++)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, "Deleting var[ i]");
#endif
            delete var[i];
            var[i] = NULL;
        }
    }
    if (var != NULL)
        delete[] var;
    var = NULL;
}

ObjCoef::ObjCoef():
    idx(-1),
    value(0.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjCoef Constructor");
#endif
}

ObjCoef::~ObjCoef()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjCoef Destructor");
#endif
}

Objective::Objective():
    name("") ,
    maxOrMin("min"),
    constant(0.0),
    weight(OSNaN()),
    numberOfObjCoef(0),
    coef(NULL)
{

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Objective Constructor");
#endif
}

Objective::~Objective()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Objective Destructor");
#endif
    int i;
    if(numberOfObjCoef > 0 && coef != NULL)
    {
        for(i = 0; i < numberOfObjCoef; i++)
        {
            delete coef[i];
            coef[i] = NULL;
        }
    }
    if (coef != NULL)
        delete[] coef;
    coef = NULL;
}

Objectives::Objectives()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Objectives Constructor");
#endif
    numberOfObjectives = 0;
    obj = NULL;
}

Objectives::~Objectives()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Objectives Destructor");
#endif
    int i;
    if(numberOfObjectives > 0 && obj != NULL)
    {
        for(i = 0; i < numberOfObjectives; i++)
        {
            delete obj[i];
            obj[i] = NULL;
        }
    }
    if (obj != NULL)
        delete[] obj;
    obj = NULL;
}

Constraint::Constraint():
    name(""),
    constant(0.0),
    lb(-OSDBL_MAX),
    ub(OSDBL_MAX)

{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Constraint Constructor");
#endif
}

Constraint::~Constraint()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Constraint Destructor");
#endif
}

Constraints::Constraints():
    numberOfConstraints(0),
    con(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Constraints Constructor");
#endif
}

Constraints::~Constraints()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Constraints Destructor");
#endif
    int i;
    if(numberOfConstraints > 0 && con != NULL)
    {
        for( i = 0; i < numberOfConstraints; i++)
        {
            delete con[i];
            con[i] = NULL;
        }
    }
    if (con != NULL)
        delete[] con;
    con = NULL;
}



LinearConstraintCoefficients::LinearConstraintCoefficients():
    numberOfValues(0) ,
    iNumberOfStartElements( 0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearConstraintCoefficients Constructor");
#endif
    start  = new IntVector();
    rowIdx = new IntVector();
    colIdx = new IntVector();
    value  = new DoubleVector();
}


LinearConstraintCoefficients::~LinearConstraintCoefficients()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearConstraintCoefficients Destructor");
#endif
    delete start;
    start = NULL;
    delete rowIdx;
    rowIdx = NULL;
    delete colIdx;
    colIdx = NULL;
    delete value;
    value = NULL;
}

QuadraticTerm::QuadraticTerm():

    idx(0),
    idxOne(-1),
    idxTwo(-1),
    coef(0.0)

{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the QuadraticTerm Constructor");
#endif
}


QuadraticTerm::~QuadraticTerm()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the QuadraticTerm Destructor");
#endif
}



QuadraticCoefficients::QuadraticCoefficients():
    numberOfQuadraticTerms(0),
    qTerm(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the QuadraticCoefficients Constructor");
#endif
}//end QuadraticCoefficients()


QuadraticCoefficients::~QuadraticCoefficients()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the QuadraticCoefficients Destructor");
#endif
    int i;
    if(numberOfQuadraticTerms > 0 && qTerm != NULL)
    {
        for( i = 0; i < numberOfQuadraticTerms; i++)
        {
            delete qTerm[i];
            qTerm[i] = NULL;
        }
    }
    if (qTerm != NULL)
        delete[] qTerm;
    qTerm = NULL;
}//end ~QuadraticCoefficients()


Nl::Nl()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Nl Constructor");
#endif
    idx = 0;
    declaredShape = ENUM_NL_EXPR_SHAPE_unknown;
    inferredShape = ENUM_NL_EXPR_SHAPE_unknown;
    osExpressionTree = NULL;
    m_bDeleteExpressionTree = true;
}//end Nl


Nl::~Nl()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Nl Destructor");
#endif
    // don't delete the expression tree if we created a map of the expression
    // trees, otherwise we would destroy twice
    if( m_bDeleteExpressionTree == true)
    {
        if (osExpressionTree != NULL) delete osExpressionTree;
        osExpressionTree = NULL;
    }
}//end ~Nl



NonlinearExpressions::NonlinearExpressions():
    numberOfNonlinearExpressions(0) ,
    nl(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
        "Inside the NonlinearExpressions Constructor");
#endif
}//end NonlinearExpressions()

NonlinearExpressions::~NonlinearExpressions()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the NonlinearExpressions Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF NONLINEAR EXPRESSIONS = " << numberOfNonlinearExpressions << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    int i;
    if(numberOfNonlinearExpressions > 0 && nl != NULL)
    {
        for( i = 0; i < numberOfNonlinearExpressions; i++)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "DESTROYING EXPRESSION " << i << " (row " << nl[ i]->idx << ")" << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            if(nl[i] != NULL)
            {
                delete nl[i];
                nl[i] = NULL;
            }
        }
    }
    if(nl != NULL)
    {
        delete[] nl;
    }
    nl = NULL;
}//end ~NonlinearExpressions()


Matrices::Matrices():
    numberOfMatrices(0) ,
    matrix(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
        "Inside the Matrices Constructor");
#endif
}//end Matrices()

Matrices::~Matrices()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
        "Inside the Matrices Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF MATRICES = " << numberOfMatrices << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    int i;
    if(numberOfMatrices > 0 && matrix != NULL)
    {
        for (i = 0; i < numberOfMatrices; i++)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "DESTROYING MATRIX " << i << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            if(matrix[i] != NULL)
            {
                delete matrix[i];
                matrix[i] = NULL;
            }
        }
    }
    if(matrix != NULL)
    {
        delete[] matrix;
        matrix = NULL;
    }
}//end ~Matrices()


Cones::Cones():
    numberOfCones(0) ,
    cone(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Cones Constructor");
#endif
}//end Cones()

Cones::~Cones()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Cones Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF CONES = " << numberOfCones << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    int i;
    if(numberOfCones > 0 && cone != NULL)
    {
        for( i = 0; i < numberOfCones; i++)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "DESTROYING CONE " << i << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            if(cone != NULL)
            {
                if(cone[i] != NULL)
                {
                    delete cone[i];
                    cone[i] = NULL;
                }
            }
        }
    }
    if(cone != NULL)
    {
        delete [] cone;
        cone = NULL;
    }
}//end ~Cones()

Cone::Cone():
    numberOfRows(0),
    numberOfColumns(0),
    numberOfOtherIndexes(0),
    otherIndexes(NULL),
    coneType(ENUM_CONE_TYPE_unknown),
    idx(-1)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Cone Constructor");
#endif
}//end Cone()

Cone::~Cone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the Cone Destructor");
#endif
    if(otherIndexes != NULL)
    {
        delete[] otherIndexes;
        otherIndexes = NULL;
    }
}//end ~Cone()

std::string Cone::getConeName()
{
    return "genericCone";
}// end Cone::getConeName()

NonnegativeCone::NonnegativeCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the NonnegativeCone Constructor");
#endif
}//end NonnegativeCone()

NonnegativeCone::~NonnegativeCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the NonnegativeCone Destructor");
#endif
}//end ~NonnegativeCone()

std::string NonnegativeCone::getConeName()
{
    return "nonnegativeCone";
}// end NonnegativeCone::getConeName()

NonpositiveCone::NonpositiveCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the NonpositiveCone Constructor");
#endif
}//end NonnegativeCone()

NonpositiveCone::~NonpositiveCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the NonpositiveCone Destructor");
#endif
}//end ~NonpositiveCone()

std::string NonpositiveCone::getConeName()
{
    return "nonpositiveCone";
}// end NonpositiveCone::getConeName()

OrthantCone::OrthantCone():
    ub(NULL),
    lb(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the OrthantCone Constructor");
#endif
}//end OrthantCone()

OrthantCone::~OrthantCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the OrthantCone Destructor");
#endif
    if(ub != NULL)
    {
        delete[] ub;
        ub = NULL;
    }
    if(lb != NULL)
    {
        delete[] lb;
        lb = NULL;
    }
}//end ~OrthantCone()

std::string OrthantCone::getConeName()
{
    return "orthantCone";
}// end OrthantCone::getConeName()

PolyhedralCone::PolyhedralCone():
    referenceMatrixIdx(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the PolyhedralCone Constructor");
#endif
}//end PolyhedralCone()

PolyhedralCone::~PolyhedralCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the PolyhedralCone Destructor");
#endif
}//end ~PolyhedralCone()

std::string PolyhedralCone::getConeName()
{
    return "polyhedralCone";
}// end PolyhedralCone::getConeName()


QuadraticCone::QuadraticCone():
    normScaleFactor(1.0),
    distortionMatrixIdx(-1),
    axisDirection(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the QuadraticCone Constructor");
#endif
}//end QuadraticCone()

QuadraticCone::~QuadraticCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the QuadraticCone Destructor");
#endif
}//end ~QuadraticCone()

std::string QuadraticCone::getConeName()
{
    return "quadraticCone";
}// end QuadraticCone::getConeName()


RotatedQuadraticCone::RotatedQuadraticCone():
    normScaleFactor(1.0),
    distortionMatrixIdx(-1),
    firstAxisDirection(0),
    secondAxisDirection(1)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the RotatedQuadraticCone Constructor");
#endif
}//end RotatedQuadraticCone()

RotatedQuadraticCone::~RotatedQuadraticCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the RotatedQuadraticCone Destructor");
#endif
}//end ~RotatedQuadraticCone()

std::string RotatedQuadraticCone::getConeName()
{
    return "rotatedQuadraticCone";
}// end RotatedQuadraticCone::getConeName()




SemidefiniteCone::SemidefiniteCone():
    semidefiniteness("positive"),
    isPositiveSemiDefinite(true)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the SemidefiniteCone Constructor");
#endif
}//end SemidefiniteCone()

SemidefiniteCone::~SemidefiniteCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the SemidefiniteCone Destructor");
#endif
}//end ~SemidefiniteCone()

std::string SemidefiniteCone::getConeName()
{
    return "semidefiniteCone";
}// end SemidefiniteCone::getConeName()

CopositiveMatricesCone::CopositiveMatricesCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the CopositiveMatricesCone Constructor");
#endif
}//end CopositiveMatricesCone()

CopositiveMatricesCone::~CopositiveMatricesCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the CopositiveMatricesCone Destructor");
#endif
}//end ~CopositiveMatricesCone()

std::string CopositiveMatricesCone::getConeName()
{
    return "copositiveMatricesCone";
}// end CopositiveMatricesCone::getConeName()


CompletelyPositiveMatricesCone::CompletelyPositiveMatricesCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the CompletelyPositiveMatricesCone Constructor");
#endif
}//end CompletelyPositiveMatricesCone()

CompletelyPositiveMatricesCone::~CompletelyPositiveMatricesCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the CompletelyPositiveMatricesCone Destructor");
#endif
}//end ~CompletelyPositiveMatricesCone()

std::string CompletelyPositiveMatricesCone::getConeName()
{
    return "completelyPositiveMatricesCone";
}// end CompletelyPositiveMatricesCone::getConeName()

ProductCone::ProductCone():
    factors(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ProductCone Constructor");
#endif
}//end ProductCone()

ProductCone::~ProductCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ProductCone Destructor");
#endif
    if (factors != NULL)
        delete factors;
    factors = NULL;
}//end ~ProductCone()

std::string ProductCone::getConeName()
{
    return "productCone";
}// end ProductCone::getConeName()


IntersectionCone::IntersectionCone():
    components(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the IntersectionCone Constructor");
#endif
}//end IntersectionCone()

IntersectionCone::~IntersectionCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the IntersectionCone Destructor");
#endif
    if (components != NULL)
        delete components;
    components = NULL;
}//end ~IntersectionCone()

std::string IntersectionCone::getConeName()
{
    return "intersectionCone";
}// end IntersectionCone::getConeName()


DualCone::DualCone():
    referenceConeIdx(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the DualCone Constructor");
#endif
}//end DualCone()

DualCone::~DualCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the DualCone Destructor");
#endif
}//end ~DualCone()

std::string DualCone::getConeName()
{
    return "dualCone";
}// end DualCone::getConeName()


PolarCone::PolarCone():
    referenceConeIdx(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the PolarCone Constructor");
#endif
}//end PolarCone()

PolarCone::~PolarCone()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the PolarCone Destructor");
#endif
}//end ~PolarCone()

std::string PolarCone::getConeName()
{
    return "polarCone";
}// end PolarCone::getConeName()

MatrixProgramming::MatrixProgramming():
    matrixVariables(NULL),
    matrixObjectives(NULL),
    matrixConstraints(NULL),
    matrixExpressions(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixProgramming Constructor");
#endif
}//end MatrixProgramming()

MatrixProgramming::~MatrixProgramming()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixProgramming Destructor");
#endif
    if (matrixVariables != NULL)
        delete matrixVariables;
    matrixVariables = NULL;
    if (matrixObjectives != NULL)
        delete matrixObjectives;
    matrixObjectives = NULL;
    if (matrixConstraints != NULL)
        delete matrixConstraints;
    matrixConstraints = NULL;
    if (matrixExpressions != NULL)
        delete matrixExpressions;
   matrixExpressions = NULL;
}//end ~MatrixProgramming()


MatrixVariables::MatrixVariables():
    numberOfMatrixVar(0),
    matrixVar(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixVariables Constructor");
#endif
}//end MatrixVariables()

MatrixVariables::~MatrixVariables()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixVariables Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF MATRIXVAR = " << numberOfMatrixVar << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif

    if (numberOfMatrixVar > 0 && matrixVar != NULL)
    {
        for(int i = 0; i < numberOfMatrixVar; i++)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "DESTROYING MATRIXVAR " << i << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            if(matrixVar != NULL)
            {
                if(matrixVar[i] != NULL)
                {
                    delete matrixVar[i];
                    matrixVar[i] = NULL;
                }
            }
        }
    }
    if(matrixVar != NULL)
    {
        delete [] matrixVar;
        matrixVar = NULL;
    }
}//end ~MatrixVariables()

MatrixObjectives::MatrixObjectives():
    numberOfMatrixObj(0),
    matrixObj(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixObjectives Constructor");
#endif
}//end MatrixObjectives()

MatrixObjectives::~MatrixObjectives()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixObjectives Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF MATRIXOBJ = " << numberOfMatrixObj << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif

    if (numberOfMatrixObj > 0 && matrixObj != NULL)
    {
        for(int i = 0; i < numberOfMatrixObj; i++)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "DESTROYING MATRIXOBJ " << i << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            if(matrixObj != NULL)
            {
                if(matrixObj[i] != NULL)
                {
                    delete matrixObj[i];
                    matrixObj[i] = NULL;
                }
            }
        }
    }
    if(matrixObj != NULL)
    {
        delete [] matrixObj;
        matrixObj = NULL;
    }
}//end ~MatrixObjectives()

MatrixConstraints::MatrixConstraints():
    numberOfMatrixCon(0),
    matrixCon(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixConstraints Constructor");
#endif
}//end MatrixConstraints()

MatrixConstraints::~MatrixConstraints()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixConstraints Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF MATRIXCON = " << numberOfMatrixCon << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif

    if (numberOfMatrixCon > 0 && matrixCon != NULL)
    {
        for(int i = 0; i < numberOfMatrixCon; i++)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "DESTROYING MATRIXCON " << i << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            if(matrixCon != NULL)
            {
                if(matrixCon[i] != NULL)
                {
                    delete matrixCon[i];
                    matrixCon[i] = NULL;
                }
            }
        }
    }
    if(matrixCon != NULL)
    {
        delete [] matrixCon;
        matrixCon = NULL;
    }
}//end ~MatrixConstraints()

MatrixExpressions::MatrixExpressions():
    numberOfExpr(0),
    expr(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixExpressions Constructor");
#endif
}//end MatrixExpressions()

MatrixExpressions::~MatrixExpressions()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixExpressions Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF EXPR = " << numberOfExpr << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif

    if (numberOfExpr > 0 && expr != NULL)
    {
        for(int i = 0; i < numberOfExpr; i++)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "DESTROYING EXPR " << i << "(\"row\" " << expr[i]->idx << ")"  << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            if(expr != NULL)
            {
                if(expr[i] != NULL)
                {
                    delete expr[i];
                    expr[i] = NULL;
                }
            }
        }
    }
    if(expr != NULL)
    {
        delete [] expr;
        expr = NULL;
    }
}//end ~MatrixExpressions()


MatrixVar::MatrixVar():
    numberOfRows(0),
    numberOfColumns(0),
    templateMatrixIdx(-1),
    varReferenceMatrixIdx(-1),
    lbMatrixIdx(-1),
    lbConeIdx(-1),
    ubMatrixIdx(-1),
    ubConeIdx(-1),
    name(""),
    varType('C')
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixVar Constructor");
#endif
}//end MatrixVar()

MatrixVar::~MatrixVar()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixVar Destructor");
#endif
}//end ~MatrixVar()


MatrixObj::MatrixObj():
    numberOfRows(0),
    numberOfColumns(0),
    templateMatrixIdx(-1),
    objReferenceMatrixIdx(-1),
    orderConeIdx(-1),
    constantMatrixIdx(-1),
    name("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixObj Constructor");
#endif
}//end MatrixObj()

MatrixObj::~MatrixObj()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixObj Destructor");
#endif
}//end ~MatrixObj()


MatrixCon::MatrixCon():
    numberOfRows(0),
    numberOfColumns(0),
    templateMatrixIdx(-1),
    conReferenceMatrixIdx(-1),
    lbMatrixIdx(-1),
    lbConeIdx(-1),
    ubMatrixIdx(-1),
    ubConeIdx(-1),
    name("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixCon Constructor");
#endif
}//end MatrixCon()

MatrixCon::~MatrixCon()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixCon Destructor");
#endif
}//end ~MatrixCon()

MatrixExpression::MatrixExpression()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixExpression Constructor");
#endif
    idx = 0;
    declaredShape = ENUM_NL_EXPR_SHAPE_unknown;
    inferredShape = ENUM_NL_EXPR_SHAPE_unknown;
    matrixExpressionTree = NULL;
    m_bDeleteExpressionTree = true;
}

MatrixExpression::~MatrixExpression()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixExpression Destructor");
#endif
    if( m_bDeleteExpressionTree == true)
    {
        delete matrixExpressionTree;
        matrixExpressionTree = NULL;
    }
}


TimeDomainStageVar::TimeDomainStageVar():
    idx(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageVar Constructor");
#endif
} // end TimeDomainStageVar


TimeDomainStageVar::~TimeDomainStageVar()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageVar Destructor");
#endif
} // end ~TimeDomainStageVar


TimeDomainStageVariables::TimeDomainStageVariables():
    numberOfVariables(0),
    startIdx(-1)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageVariables Constructor");
#endif
    var = NULL;
} // end TimeDomainStageVariables

TimeDomainStageVariables::~TimeDomainStageVariables()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageVariables Destructor");
#endif
    if (numberOfVariables > 0 && var != NULL)
    {
        for (int i = 0; i < numberOfVariables; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
    }
    if (var != NULL)
        delete [] var;
    var = NULL;
} // end ~TimeDomainStageVariables

TimeDomainStageCon::TimeDomainStageCon():
    idx(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageCon Constructor");
#endif
} // end TimeDomainStageCon


TimeDomainStageCon::~TimeDomainStageCon()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageCon Destructor");
#endif
} // end ~TimeDomainStageCon


TimeDomainStageConstraints::TimeDomainStageConstraints():
    numberOfConstraints(0),
    startIdx(-1)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageConstraints Constructor");
#endif
    con = NULL;
} // end TimeDomainStageConstraints

TimeDomainStageConstraints::~TimeDomainStageConstraints()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageConstraints Destructor");
#endif
    if (numberOfConstraints > 0 && con != NULL)
    {
        for (int i = 0; i < numberOfConstraints; i++)
        {
            delete con[i];
            con[i] = NULL;
        }
    }
    if (con != NULL)
        delete [] con;
    con = NULL;
} // end ~TimeDomainStageConstraints

TimeDomainStageObj::TimeDomainStageObj():
    idx(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageObj Constructor");
#endif
} // end TimeDomainStageObj


TimeDomainStageObj::~TimeDomainStageObj()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageObj Destructor");
#endif
} // end ~TimeDomainStageObj


TimeDomainStageObjectives::TimeDomainStageObjectives():
    numberOfObjectives(0),
    startIdx(-1)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageObjectives Constructor");
#endif
    obj = NULL;
} // end TimeDomainStageObjectives

TimeDomainStageObjectives::~TimeDomainStageObjectives()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStageObjectives Destructor");
#endif
    if (numberOfObjectives > 0 && obj != NULL)
    {
        for (int i = 0; i < numberOfObjectives; i++)
        {
            delete obj[i];
            obj[i] = NULL;
        }
    }
    if (obj != NULL)
        delete [] obj;
    obj = NULL;
} // end ~TimeDomainStageObjectives

TimeDomainStage::TimeDomainStage():
    name("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStage Constructor");
#endif
    variables   = NULL;
    constraints = NULL;
    objectives  = NULL;
}//end TimeDomainStage()


TimeDomainStage::~TimeDomainStage()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStage Destructor");
#endif
    if (variables != NULL)
    {
        delete variables;
        variables = NULL;
    }
    if (constraints != NULL)
    {
        delete constraints;
        constraints = NULL;
    }
    if (objectives != NULL)
    {
        delete objectives;
        objectives = NULL;
    }
}//end ~TimeDomainStage()


TimeDomainStages::TimeDomainStages():
    numberOfStages(0),
    stage(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStages Constructor");
#endif
}


TimeDomainStages::~TimeDomainStages()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainStages Destructor");
#endif
    int i;
    if(numberOfStages > 0 && stage != NULL)
    {
        for( i = 0; i < numberOfStages; i++)
        {
            delete stage[i];
            stage[i] = NULL;
        }
    }
    if (stage != NULL)
        delete[] stage;
    stage = NULL;
}

TimeDomainInterval::TimeDomainInterval():
    start(0.0),
    horizon(0.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainInterval Constructor");
#endif
}


TimeDomainInterval::~TimeDomainInterval()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomainInterval Constructor");
#endif
}

TimeDomain::TimeDomain()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomain Constructor");
#endif
    stages = NULL;
    interval = NULL;
}

TimeDomain::~TimeDomain()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeDomain Constructor");
#endif
    if (stages != NULL)
    {
        delete stages;
        stages = NULL;
    }
    if (interval != NULL)
    {
        delete interval;
        interval = NULL;
    }
}


InstanceData::InstanceData():
    variables(NULL),
    objectives(NULL),
    constraints(NULL),
    linearConstraintCoefficients(NULL),
    quadraticCoefficients(NULL),
    nonlinearExpressions(NULL),
    matrices(NULL),
    cones(NULL),
    matrixProgramming(NULL),
    timeDomain(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the InstanceData Constructor");
#endif
//    variables = new Variables();
//    objectives = new Objectives();
//    constraints = new Constraints();
//    linearConstraintCoefficients = new LinearConstraintCoefficients();
//    quadraticCoefficients = new QuadraticCoefficients();
//    nonlinearExpressions = new NonlinearExpressions();
//    matrices = new Matrices();
//    cones = new Cones();
//    matrixProgramming = new MatrixProgramming();
//    timeDomain = NULL;
}//end of InstanceData constructor

InstanceData::~InstanceData()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the InstanceData Destructor");
#endif
    if (variables != NULL)
    {
        delete variables;
        variables = NULL;
    }

    if (objectives != NULL)
    {
        delete objectives;
        objectives = NULL;
    }

    if (constraints != NULL)
    {
        delete constraints;
        constraints = NULL;
    }

    if (linearConstraintCoefficients != NULL)
    {
        delete linearConstraintCoefficients;
        linearConstraintCoefficients = NULL;
    }

    if (quadraticCoefficients != NULL)
    {
        delete quadraticCoefficients;
        quadraticCoefficients = NULL;
    }

    if (nonlinearExpressions != NULL)
    {
        delete nonlinearExpressions;
        nonlinearExpressions = NULL;
    }

    if (matrices != NULL)
    {
        delete matrices;
        matrices = NULL;
    }

    if (cones != NULL)
    {
        delete cones;
        cones = NULL;
    }

    if (matrixProgramming != NULL)
    {
        delete matrixProgramming;
        matrixProgramming = NULL;
    }

    if (timeDomain != NULL)
    {
        delete timeDomain;
        timeDomain = NULL;
    }
}//end of InstanceData destructor


/** the get() methods
 *  =================
 */
string OSInstance::getInstanceName()
{
    if (m_sInstanceName.length() <= 0)
    {
        if (instanceHeader == NULL)
            throw ErrorClass("instanceHeader object undefined in method getInstanceName()");
        m_sInstanceName = instanceHeader->name;
    }
    return m_sInstanceName;
}//getInstanceName

string OSInstance::getInstanceSource()
{
    if (m_sInstanceSource.length() <= 0)
    {
        if (instanceHeader == NULL)
            throw ErrorClass("instanceHeader object undefined in method getInstanceSource()");
        m_sInstanceSource = instanceHeader->source;
    }
    return m_sInstanceSource;
}//getInstanceSource

string OSInstance::getInstanceDescription()
{
    if (m_sInstanceDescription.length() <= 0)
    {
        if (instanceHeader == NULL)
            throw ErrorClass("instanceHeader object undefined in method getInstanceDescription()");
        m_sInstanceDescription = instanceHeader->description;
    }
    return m_sInstanceDescription;
}//getInstanceDescription

string OSInstance::getInstanceCreator()
{
    if (m_sInstanceCreator.length() <= 0)
    {
        if (instanceHeader == NULL)
            throw ErrorClass("instanceHeader object undefined in method getInstanceCreator()");
        m_sInstanceCreator = instanceHeader->fileCreator;
    }
    return m_sInstanceCreator;
}//getInstanceCreator

string OSInstance::getInstanceLicence()
{
    if (m_sInstanceLicence.length() <= 0)
    {
        if (instanceHeader == NULL)
            throw ErrorClass("instanceHeader object undefined in method getInstanceLicence()");
        m_sInstanceLicence = instanceHeader->licence;
    }
    return m_sInstanceLicence;
}//getInstanceLicence

int OSInstance::getVariableNumber()
{
    if (m_iVariableNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getVariableNumber()");
        if (instanceData->variables == NULL)
            m_iVariableNumber = 0;    
        else
            m_iVariableNumber = instanceData->variables->numberOfVariables;
    }
    return m_iVariableNumber;
}//getVariableNumber

bool OSInstance::processVariables()
{
    if(m_bProcessVariables == true && bVariablesModified == false) return true;
    //m_bProcessVariables = true;
    int i = 0;
    int varType;
    int n = getVariableNumber();
    try
    {
        m_iNumberOfBinaryVariables  = 0;
        m_iNumberOfIntegerVariables = 0;
        m_iNumberOfStringVariables  = 0;
        if(n > 0)
        {
            if(m_bProcessVariables != true )
            {
                m_mcVariableTypes = new char[n];
                m_mdVariableLowerBounds = new double[n];
                m_mdVariableUpperBounds = new double[n];
                m_msVariableNames = new string[n];
                m_bProcessVariables = true;
            }

            for(i = 0; i < n; i++)
            {
                if(instanceData->variables->var[i] == NULL) throw ErrorClass("processVariables(): var element was never defined");
                varType = returnVarType(instanceData->variables->var[i]->type);
                switch (varType)
                {
                case 0:
                {
                    throw ErrorClass("unknown variable type");
                    break;
                }
                case ENUM_VARTYPE_continuous:
                {
                    break;
                }
                case ENUM_VARTYPE_binary:
                {
                    m_iNumberOfBinaryVariables++;
                    break;
                }
                case ENUM_VARTYPE_integer:
                {
                    m_iNumberOfIntegerVariables++;
                    break;
                }
                case ENUM_VARTYPE_string:
                {

                    m_iNumberOfStringVariables++;
                    break;
                }
                case ENUM_VARTYPE_semicontinuous:
                {
                    m_iNumberOfSemiContinuousVariables++;
                    break;
                }
                case ENUM_VARTYPE_semiinteger:
                {
                    m_iNumberOfSemiIntegerVariables++;
                    break;
                }
                default:
                {
                    throw ErrorClass("variable type not yet implemented");
                    break;
                }
                }
                m_mcVariableTypes[i] = instanceData->variables->var[i]->type;
                m_mdVariableLowerBounds[i] = instanceData->variables->var[i]->lb;
                m_mdVariableUpperBounds[i] = instanceData->variables->var[i]->ub;
                if(instanceData->variables->var[i]->name.length() > 0)
                    m_msVariableNames[i] = instanceData->variables->var[i]->name;
                else
                    m_msVariableNames[i] = "";
            }
        }
        return true;
    } //end try
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//processVariables

string* OSInstance::getVariableNames()
{
    processVariables();
    return m_msVariableNames;
}//getVariableNames

char* OSInstance::getVariableTypes()
{
    processVariables();
    return m_mcVariableTypes;
}//getVariableTypes

int OSInstance::getNumberOfBinaryVariables()
{
    processVariables();
    return m_iNumberOfBinaryVariables;
}//getNumberOfBinaryVariables

int OSInstance::getNumberOfIntegerVariables()
{
    processVariables();
    return m_iNumberOfIntegerVariables;
}//getNumberOfIntegerVariables

int OSInstance::getNumberOfSemiContinuousVariables()
{
    processVariables();
    return m_iNumberOfSemiContinuousVariables;
}//getNumberOfSemiContinuousVariables

int OSInstance::getNumberOfSemiIntegerVariables()
{
    processVariables();
    return m_iNumberOfSemiIntegerVariables;
}//getNumberOfSemiIntegerVariables

int OSInstance::getNumberOfStringVariables()
{
    processVariables();
    return m_iNumberOfStringVariables;
}//getNumberOfStringVariables

double* OSInstance::getVariableLowerBounds()
{
    processVariables();
    return m_mdVariableLowerBounds;
}//getVariableLowerBounds

double* OSInstance::getVariableUpperBounds()
{
    processVariables();
    return m_mdVariableUpperBounds;
}//getVariableUpperBounds


int OSInstance::getObjectiveNumber()
{
    if (m_iObjectiveNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getVariableNumber()");
        if (instanceData->objectives == NULL)
            m_iObjectiveNumber = 0;    
        else
            m_iObjectiveNumber = instanceData->objectives->numberOfObjectives;
    }
    return m_iObjectiveNumber;

}//getObjectiveNumber

bool OSInstance::processObjectives()
{
    if(m_bProcessObjectives == true && bObjectivesModified == false) return true;
    //m_bProcessObjectives = true;
    int i = 0;
    int j = 0;
    int n = getObjectiveNumber();
    if (n == 0 || instanceData->objectives->obj == NULL) return true;
    try
    {
        if (n > 0)
        {
            if(m_bProcessObjectives != true)
            {
                m_msMaxOrMins            = new string[n];
                m_miNumberOfObjCoef      = new int[n];
                m_mdObjectiveConstants   = new double[n];
                m_mdObjectiveWeights     = new double[n];
                m_mObjectiveCoefficients = new SparseVector*[n];
                m_msObjectiveNames       = new string[n];
                for(i = 0; i < n; i++)
                {
                    if(instanceData->objectives->obj[i] == NULL)
                        throw ErrorClass("processObjectives(): obj element was never defined");
                    m_mObjectiveCoefficients[i]
                        = new SparseVector(instanceData->objectives->obj[i]->numberOfObjCoef);
                    //m_mObjectiveCoefficients[i]->bDeleteArrays=false;
                }
                m_bProcessObjectives = true;
            }

            for(i = 0; i < n; i++)
            {
                if(instanceData->objectives->obj[i] == NULL) throw ErrorClass("processObjectives(): obj element was never defined");
                if((instanceData->objectives->obj[i]->maxOrMin.compare("max") != 0) && 
                   (instanceData->objectives->obj[i]->maxOrMin.compare("min") != 0 )) 
                   throw ErrorClass("wrong objective maxOrMin");
                m_msMaxOrMins[i] = instanceData->objectives->obj[i]->maxOrMin;
                m_miNumberOfObjCoef[i] = instanceData->objectives->obj[i]->numberOfObjCoef;
                m_mdObjectiveConstants[i] = instanceData->objectives->obj[i]->constant;
                m_mdObjectiveWeights[i] = instanceData->objectives->obj[i]->weight;
                if(instanceData->objectives->obj[i]->coef == NULL && m_miNumberOfObjCoef[i] != 0)
                {
                    throw ErrorClass("objective coefficient number inconsistent with objective coefficient array");
                }
                if(instanceData->objectives->obj[i]->coef != NULL)
                {
                    for(j = 0; j < m_mObjectiveCoefficients[i]->number; j++)
                    {
                        m_mObjectiveCoefficients[i]->indexes[j] = instanceData->objectives->obj[i]->coef[j]->idx;
                        m_mObjectiveCoefficients[i]->values[j] = instanceData->objectives->obj[i]->coef[j]->value;
                    }
                }
                if(instanceData->objectives->obj[i]->name.length() > 0)
                    m_msObjectiveNames[i] = instanceData->objectives->obj[i]->name;
                else
                    m_msObjectiveNames[i] = "";
            }
        }
        return true;
    } //end try
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//processObjectives

string* OSInstance::getObjectiveNames()
{
    processObjectives();
    return m_msObjectiveNames;
}//getObjectiveNames

string* OSInstance::getObjectiveMaxOrMins()
{
    processObjectives();
    return m_msMaxOrMins;
}//getObjectiveMaxOrMins

int* OSInstance::getObjectiveCoefficientNumbers()
{
    processObjectives();
    return m_miNumberOfObjCoef;
}//getObjectiveCoefficientNumbers

double* OSInstance::getObjectiveConstants()
{
    processObjectives();
    return m_mdObjectiveConstants;
}//getObjectiveConstants

double* OSInstance::getObjectiveWeights()
{
    processObjectives();
    return m_mdObjectiveWeights;

}//getObjectiveWeights

SparseVector** OSInstance::getObjectiveCoefficients()
{
    processObjectives();
    return m_mObjectiveCoefficients;
}//getObjectiveCoefficients


double** OSInstance::getDenseObjectiveCoefficients()
{
    if(m_bGetDenseObjectives == true && bObjectivesModified == false)
        return m_mmdDenseObjectiveCoefficients;
    int i, j, numobjcoef;
    SparseVector *sparsevec;
    int m = getObjectiveNumber();
    int n = getVariableNumber();
    if (m == 0 || instanceData->objectives->obj == NULL) return NULL;
    if (m_bGetDenseObjectives != true)
    {
        m_mmdDenseObjectiveCoefficients = new double*[m];
        for(i = 0; i < m; i++)
        {
            m_mmdDenseObjectiveCoefficients[ i] = new double[n];
        }
        m_bGetDenseObjectives = true;
    }

    for(i = 0; i < m; i++)
    {
        sparsevec = this->getObjectiveCoefficients()[i];
        for(j = 0; j < n; j++)
        {
            m_mmdDenseObjectiveCoefficients[ i][j] = 0.0;
        }
        sparsevec =  this->getObjectiveCoefficients()[i];
        numobjcoef = sparsevec->number;
        for(j = 0; j < numobjcoef; j++)
        {
            m_mmdDenseObjectiveCoefficients[i][ sparsevec->indexes[ j]]
                += sparsevec->values[ j];
        }
    }
    return m_mmdDenseObjectiveCoefficients;
}//getDenseObjectiveCoefficients


int OSInstance::getConstraintNumber()
{
    if (m_iConstraintNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getConstraintNumber()");
        if (instanceData->constraints == NULL)
            m_iConstraintNumber = 0;    
        else
            m_iConstraintNumber = instanceData->constraints->numberOfConstraints;
    }
    return m_iConstraintNumber;
}//getConstraintNumber

bool OSInstance::processConstraints()
{
    if(m_bProcessConstraints == true && bConstraintsModified == false) return true;
    //m_bProcessConstraints = true;
    int i = 0;
    ostringstream outStr;
    int n = getConstraintNumber();
    if (n == 0 || instanceData->constraints->con == NULL) return true;
    try
    {
        if(n > 0)
        {
            if(m_bProcessConstraints != true)
            {
                m_mdConstraintLowerBounds = new double[n];
                m_mdConstraintUpperBounds = new double[n];
                m_mdConstraintConstants   = new double[n];
                m_mcConstraintTypes       = new char[n];
                m_msConstraintNames       = new string[n];
                m_bProcessConstraints = true;
            }
            for(i = 0; i < n; i++)
            {
                if(instanceData->constraints->con[i] == NULL) throw ErrorClass("processConstraints(): con element was never defined");
                m_mdConstraintLowerBounds[i] = instanceData->constraints->con[i]->lb;
                m_mdConstraintUpperBounds[i] = instanceData->constraints->con[i]->ub;
                m_mdConstraintConstants[i] = instanceData->constraints->con[i]->constant;
                if(m_mdConstraintLowerBounds[i] == OSDBL_MAX || m_mdConstraintUpperBounds[i] == -OSDBL_MAX)
                {
                    outStr << "Constraint  " ;
                    outStr << i;
                    outStr << " is infeasible";
                    throw ErrorClass( outStr.str() );
                }
                else if(m_mdConstraintLowerBounds[i] > m_mdConstraintUpperBounds[i])
                {
                    outStr << "Constraint  " ;
                    outStr << i;
                    outStr << " is infeasible";
                    throw ErrorClass( outStr.str());
                }
                else if(m_mdConstraintLowerBounds[i] == -OSDBL_MAX && m_mdConstraintUpperBounds[i] == OSDBL_MAX)
                    m_mcConstraintTypes[i] = 'U';
                else if(m_mdConstraintLowerBounds[i] == m_mdConstraintUpperBounds[i])
                    m_mcConstraintTypes[i] = 'E';
                else if(m_mdConstraintLowerBounds[i] == -OSDBL_MAX)
                    m_mcConstraintTypes[i] = 'L';
                else if(m_mdConstraintUpperBounds[i] == OSDBL_MAX)
                    m_mcConstraintTypes[i] = 'G';
                else m_mcConstraintTypes[i] = 'R';
                if(instanceData->constraints->con[i]->name.length() > 0)
                    m_msConstraintNames[i] = instanceData->constraints->con[i]->name;
                else
                    m_msConstraintNames[i] = "";
            }
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//processConstraints


string* OSInstance::getConstraintNames()
{
    processConstraints();
    return m_msConstraintNames;
}//getConstraintNames


char* OSInstance::getConstraintTypes()
{
    processConstraints();
    return m_mcConstraintTypes;
}//getConstraintTypes

double* OSInstance::getConstraintLowerBounds()
{
    processConstraints();
    return m_mdConstraintLowerBounds;
}//getConstraintLowerBounds

double* OSInstance::getConstraintUpperBounds()
{
    processConstraints();
    return m_mdConstraintUpperBounds;
}//getConstraintUpperBounds

double* OSInstance::getConstraintConstants()
{
    processConstraints();
    return m_mdConstraintConstants;
}//getConstraintConstants


int OSInstance::getLinearConstraintCoefficientNumber()
{
    if(this->getVariableNumber() <= 0 || this->getConstraintNumber() <= 0) return 0;
    if(m_iLinearConstraintCoefficientNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getLinearConstraintCoefficientNumber()");
        if (instanceData->linearConstraintCoefficients == NULL)
            m_iLinearConstraintCoefficientNumber = 0;    
        else
            m_iLinearConstraintCoefficientNumber
                = instanceData->linearConstraintCoefficients->numberOfValues;
    }
    return m_iLinearConstraintCoefficientNumber;
}//getLinearConstraintCoefficientNumber

bool OSInstance::processLinearConstraintCoefficients()
{
    if(m_bProcessLinearConstraintCoefficients == true && bAMatrixModified == false) return true;
    //m_bProcessLinearConstraintCoefficients = true;
    try
    {
        int n = getLinearConstraintCoefficientNumber();
        if((instanceData->linearConstraintCoefficients == NULL ) || (n == 0) ) return true;
        //value array
        if((instanceData->linearConstraintCoefficients->value == NULL ) || (n == 0) ) return true;
        //index array
        if((instanceData->linearConstraintCoefficients->colIdx     != NULL  && 
            instanceData->linearConstraintCoefficients->colIdx->el != NULL) && 
           (instanceData->linearConstraintCoefficients->rowIdx     != NULL  && 
            instanceData->linearConstraintCoefficients->rowIdx->el != NULL))
            throw ErrorClass("ambiguous linear constraint coefficient major");
        else if(instanceData->linearConstraintCoefficients->value->el == NULL) return true;
        else
        {
            if(instanceData->linearConstraintCoefficients->rowIdx->el != NULL)
            {
                m_bColumnMajor = true;
                if(m_bProcessLinearConstraintCoefficients != true)
                {
                    m_linearConstraintCoefficientsInColumnMajor = new SparseMatrix();
                    m_linearConstraintCoefficientsInColumnMajor->bDeleteArrays = false;
                    m_bProcessLinearConstraintCoefficients = true;
                }
                m_linearConstraintCoefficientsInColumnMajor->isColumnMajor = true;
                m_linearConstraintCoefficientsInColumnMajor->valueSize = n;
                m_linearConstraintCoefficientsInColumnMajor->startSize
                    = instanceData->variables->numberOfVariables + 1;
            }
            else
            {
                m_bColumnMajor = false;
                if(m_bProcessLinearConstraintCoefficients != true)
                {
                    m_linearConstraintCoefficientsInRowMajor = new SparseMatrix();
                    m_linearConstraintCoefficientsInRowMajor->bDeleteArrays = false;
                    m_bProcessLinearConstraintCoefficients = true;
                }
                m_linearConstraintCoefficientsInRowMajor->isColumnMajor = false;
                m_linearConstraintCoefficientsInRowMajor->valueSize = n;
                m_linearConstraintCoefficientsInRowMajor->startSize
                    = instanceData->constraints->numberOfConstraints + 1;
            }
        }
        if(m_bColumnMajor == true)
        {
            m_linearConstraintCoefficientsInColumnMajor->values
                = instanceData->linearConstraintCoefficients->value->el;
            m_linearConstraintCoefficientsInColumnMajor->indexes
                = instanceData->linearConstraintCoefficients->rowIdx->el;
            m_linearConstraintCoefficientsInColumnMajor->starts
                = instanceData->linearConstraintCoefficients->start->el;
        }
        else
        {
            m_linearConstraintCoefficientsInRowMajor->values 
                = instanceData->linearConstraintCoefficients->value->el;
            m_linearConstraintCoefficientsInRowMajor->indexes 
                = instanceData->linearConstraintCoefficients->colIdx->el;
            m_linearConstraintCoefficientsInRowMajor->starts
                = instanceData->linearConstraintCoefficients->start->el;
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//processLinearConstraintCoefficients

bool OSInstance::getLinearConstraintCoefficientMajor()
{
    processLinearConstraintCoefficients();
    return m_bColumnMajor;
}//getLinearConstraintCoefficientMajor

SparseMatrix* OSInstance::getLinearConstraintCoefficientsInColumnMajor()
{
    processLinearConstraintCoefficients();
    if(getVariableNumber() ==  0) return NULL;
    if(m_linearConstraintCoefficientsInColumnMajor != NULL) return m_linearConstraintCoefficientsInColumnMajor;
    if(!m_bColumnMajor)
    {
        if(m_linearConstraintCoefficientsInRowMajor == NULL) return NULL;
        m_linearConstraintCoefficientsInColumnMajor =
            MathUtil::convertLinearConstraintCoefficientMatrixToTheOtherMajor(false,
                    m_linearConstraintCoefficientsInRowMajor->startSize,
                    m_linearConstraintCoefficientsInRowMajor->valueSize,
                    m_linearConstraintCoefficientsInRowMajor->starts,
                    m_linearConstraintCoefficientsInRowMajor->indexes,
                    m_linearConstraintCoefficientsInRowMajor->values,
                    getVariableNumber());
    }
    return m_linearConstraintCoefficientsInColumnMajor;
}//getLinearConstraintCoefficientsInColumnMajor

SparseMatrix* OSInstance::getLinearConstraintCoefficientsInRowMajor()
{
    processLinearConstraintCoefficients();
    if(m_linearConstraintCoefficientsInRowMajor != NULL) return m_linearConstraintCoefficientsInRowMajor;
    if(m_bColumnMajor)
    {
        if(m_linearConstraintCoefficientsInColumnMajor == NULL) return NULL;
        m_linearConstraintCoefficientsInRowMajor =

            MathUtil::convertLinearConstraintCoefficientMatrixToTheOtherMajor(true,
                    m_linearConstraintCoefficientsInColumnMajor->startSize,
                    m_linearConstraintCoefficientsInColumnMajor->valueSize,
                    m_linearConstraintCoefficientsInColumnMajor->starts,
                    m_linearConstraintCoefficientsInColumnMajor->indexes,
                    m_linearConstraintCoefficientsInColumnMajor->values,
                    getConstraintNumber());
    }
    return m_linearConstraintCoefficientsInRowMajor;
}//getLinearConstraintCoefficientsInRowMajor


int OSInstance::getNumberOfQuadraticTerms()
{
    if(m_iQuadraticTermNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getNumberOfQuadraticTerms()");
        if (instanceData->quadraticCoefficients == NULL)
            m_iQuadraticTermNumber = 0;
        else
            m_iQuadraticTermNumber = instanceData->quadraticCoefficients->numberOfQuadraticTerms;
    }
    return m_iQuadraticTermNumber;
}//getNumberOfQuadraticTerms

QuadraticTerms* OSInstance::getQuadraticTerms()
{
    if(m_bProcessQuadraticTerms) return m_quadraticTerms;
    m_bProcessQuadraticTerms = true;
    int n = getNumberOfQuadraticTerms();
    if(instanceData->quadraticCoefficients->qTerm == NULL) return NULL;
    try
    {
        int i = 0;
        QuadraticCoefficients* quadraticCoefs = instanceData->quadraticCoefficients;
        if(!quadraticCoefs->qTerm  && n != 0)
            throw ErrorClass("quadratic term number inconsistent with quadratic term array");
        m_quadraticTerms = new QuadraticTerms();
        if(n > 0)
        {
            m_quadraticTerms->rowIndexes    = new int[n];
            m_quadraticTerms->varOneIndexes = new int[n];
            m_quadraticTerms->varTwoIndexes = new int[n];
            m_quadraticTerms->coefficients  = new double[n];
        }
        for(i = 0; i < n; i++)
        {
            m_quadraticTerms->rowIndexes[i]    = quadraticCoefs->qTerm[i]->idx;
            m_quadraticTerms->varOneIndexes[i] = quadraticCoefs->qTerm[i]->idxOne;
            m_quadraticTerms->varTwoIndexes[i] = quadraticCoefs->qTerm[i]->idxTwo;
            m_quadraticTerms->coefficients[i]  = quadraticCoefs->qTerm[i]->coef;
        }
        return m_quadraticTerms;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getQuadraticTerms

int OSInstance::getNumberOfQuadraticRowIndexes()
{
    if(m_bQuadraticRowIndexesProcessed == false) getQuadraticRowIndexes();
    return m_iNumberOfQuadraticRowIndexes;
}//getNumberOfQuadraticRowIndexes

int* OSInstance::getQuadraticRowIndexes()
{
    if(m_bQuadraticRowIndexesProcessed == true) return m_miQuadRowIndexes;
    m_bQuadraticRowIndexesProcessed = true;
    int n = getNumberOfQuadraticTerms();
    if(n <= 0) return NULL;
    QuadraticTerms *qTerms = NULL;
    qTerms = getQuadraticTerms();
    std::map<int, int> foundIdx;
    std::map<int, int>::iterator pos;
    int i;
    try
    {
        for(i = 0; i < n; i++)
        {
            // add the terms
            foundIdx[ qTerms->rowIndexes[ i] ];
        }
        // now put the term into an array
        m_iNumberOfQuadraticRowIndexes = foundIdx.size();
        m_miQuadRowIndexes = new int[ m_iNumberOfQuadraticRowIndexes ];
        i = 0;
        for(pos = foundIdx.begin(); pos != foundIdx.end(); ++pos)
        {
            m_miQuadRowIndexes[ i++] = pos->first;
        }
        foundIdx.clear();
        return m_miQuadRowIndexes;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getQuadraticRowIndexes


int OSInstance::getNumberOfNonlinearExpressions()
{
    if(m_iNonlinearExpressionNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getNumberOfNonlinearExpressions()");
        if (instanceData->nonlinearExpressions == NULL)
            m_iNonlinearExpressionNumber = 0;
        else
            m_iNonlinearExpressionNumber = instanceData->nonlinearExpressions->numberOfNonlinearExpressions;
    }
    return m_iNonlinearExpressionNumber;
}//getNumberOfNonlinearExpressions

Nl** OSInstance::getNonlinearExpressions()
{
//    Nl** root = new Nl*[getNumberOfNonlinearExpressions()];
//    for (int i=0; i < getNumberOfNonlinearExpressions(); i++)
//    {
//        root[i] = instanceData->nonlinearExpressions->nl[i];
//    }
//    return root;
    return instanceData->nonlinearExpressions->nl;
}//getNonlinearExpressions


int OSInstance::getNumberOfNonlinearExpressionTreeIndexes()
{
    if(m_bNonlinearExpressionTreeIndexesProcessed == false) getNonlinearExpressionTreeIndexes();
    return m_iNumberOfNonlinearExpressionTreeIndexes;
}//getNumberOfNonlinearExpressionTreeIndexes

int* OSInstance::getNonlinearExpressionTreeIndexes()
{
    if(m_bNonlinearExpressionTreeIndexesProcessed == true) return m_miNonlinearExpressionTreeIndexes;
    m_bNonlinearExpressionTreeIndexesProcessed = true;
    std::map<int, RealValuedExpressionTree*> expTrees;
    expTrees = getAllNonlinearExpressionTrees();

    std::map<int, RealValuedExpressionTree*>::iterator pos;
    try
    {
        // now put the term into an array
        m_iNumberOfNonlinearExpressionTreeIndexes = expTrees.size();
        m_miNonlinearExpressionTreeIndexes = new int[ m_iNumberOfNonlinearExpressionTreeIndexes ]    ;
        int i = 0;
        for(pos = expTrees.begin(); pos != expTrees.end(); ++pos)
        {
            m_miNonlinearExpressionTreeIndexes[ i++] = pos->first;
        }
        expTrees.clear();
        return m_miNonlinearExpressionTreeIndexes;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getNonlinearExpressionTreeIndexes

int OSInstance::getNumberOfNonlinearExpressionTreeModIndexes()
{
    if(m_bNonlinearExpressionTreeModIndexesProcessed == false) getNonlinearExpressionTreeModIndexes();
    return m_iNumberOfNonlinearExpressionTreeModIndexes;
}//getNumberOfNonlinearExpressionTreeModIndexes

int* OSInstance::getNonlinearExpressionTreeModIndexes()
{
    if(m_bNonlinearExpressionTreeModIndexesProcessed == true) return m_miNonlinearExpressionTreeModIndexes;
    m_bNonlinearExpressionTreeModIndexesProcessed = true;
    std::map<int, RealValuedExpressionTree*> expTrees;
    expTrees = getAllNonlinearExpressionTreesMod();
    std::map<int, RealValuedExpressionTree*>::iterator pos;
    try
    {
        // now put the term into an array
        m_iNumberOfNonlinearExpressionTreeModIndexes = expTrees.size();
        m_miNonlinearExpressionTreeModIndexes = new int[ m_iNumberOfNonlinearExpressionTreeModIndexes ]    ;
        int i = 0;
        for(pos = expTrees.begin(); pos != expTrees.end(); ++pos)
        {
            m_miNonlinearExpressionTreeModIndexes[ i++] = pos->first;
        }
        expTrees.clear();
        return m_miNonlinearExpressionTreeModIndexes;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getNonlinearExpressionTreeModIndexes

int OSInstance::getNumberOfNonlinearConstraints()
{
    if( m_bProcessExpressionTrees == false )
        getAllNonlinearExpressionTrees();
    return m_iConstraintNumberNonlinear;
}//getNumberOfNonlinearConstraints

int OSInstance::getNumberOfNonlinearObjectives()
{
    if( m_bProcessExpressionTrees == false )
        getAllNonlinearExpressionTrees();

    return m_iObjectiveNumberNonlinear;
}//getNumberOfNonlinearObjectivess

RealValuedExpressionTree* OSInstance::getNonlinearExpressionTree(int rowIdx)
{
    // check to make sure rowIdx has a nonlinear term and is in the map
    if( m_bProcessExpressionTrees == false )
    {
        getAllNonlinearExpressionTrees();
    }
    if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end())
        return m_mapExpressionTrees[ rowIdx];
    else return NULL ;
}// getNonlinearExpressionTree for a specific index

RealValuedExpressionTree* OSInstance::getNonlinearExpressionTreeMod(int rowIdx)
{
    // check to make sure rowIdx has a nonlinear term and is in the map
    if( m_bProcessExpressionTreesMod == false )
    {
        getAllNonlinearExpressionTreesMod();
    }
    if( m_mapExpressionTreesMod.find( rowIdx) != m_mapExpressionTreesMod.end()) 
        return m_mapExpressionTreesMod[ rowIdx];
    else return NULL ;
}// getNonlinearExpressionTreeMod for a specific index

std::vector<ExprNode*> OSInstance::getNonlinearExpressionTreeInPostfix( int rowIdx)
{
    //if( m_binitForAlgDiff == false) this->initForAlgDiff();
    if( m_bProcessExpressionTrees == false ) getAllNonlinearExpressionTrees();
    std::vector<ExprNode*> postfixVec;
    try
    {
        if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end())
        {
            RealValuedExpressionTree* expTree = getNonlinearExpressionTree( rowIdx);
            postfixVec = ((OSnLNode*)expTree->m_treeRoot)->getPostfixFromExpressionTree();
        }
        else
        {
            throw ErrorClass("Error in getNonlinearExpressionTreeInPostfix, rowIdx not valid");
        }
        return postfixVec;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getNonlinearExpressionTreeInPostfix

std::string OSInstance::getNonlinearExpressionTreeInInfix( int rowIdx_)
{
    if( m_binitForAlgDiff == false) this->initForAlgDiff();
    if( m_bProcessExpressionTrees == false ) getAllNonlinearExpressionTrees();

    std::vector<ExprNode*> postfixVec;

    int rowIdx = rowIdx_;

    try
    {
        if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end())
        {
            RealValuedExpressionTree* exptree = this->getNonlinearExpressionTree( rowIdx);
            if(exptree != NULL)
            {
                postfixVec = this->getNonlinearExpressionTreeInPostfix( rowIdx);
                return getExpressionTreeAsInfixString(postfixVec);
            }
            else
            {
                return "";
            }
        }
        else
        {
            throw ErrorClass("Error in getNonlinearExpressionTreeInInfix, rowIdx not valid");
        }
        return "";
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getNonlinearExpressionTreeInInfix


std::vector<ExprNode*> OSInstance::getNonlinearExpressionTreeModInPostfix( int rowIdx)
{
    //if( m_binitForAlgDiff == false) this->initForAlgDiff();
    if( m_bProcessExpressionTreesMod == false ) getAllNonlinearExpressionTreesMod();
    std::vector<ExprNode*> postfixVec;
    try
    {
        if( m_mapExpressionTreesMod.find( rowIdx) != m_mapExpressionTreesMod.end())
        {
            RealValuedExpressionTree* expTree = getNonlinearExpressionTreeMod( rowIdx);
            postfixVec = ((OSnLNode*)expTree->m_treeRoot)->getPostfixFromExpressionTree();

        }
        else
        {
            throw ErrorClass("Error in getNonlinearExpressionTreeModInPostfix, rowIdx not valid");
        }
        return postfixVec;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getNonlinearExpressionTreeModInPostfix


std::vector<ExprNode*> OSInstance::getNonlinearExpressionTreeInPrefix( int rowIdx)
{
    //if( m_binitForAlgDiff == false) this->initForAlgDiff();
    if( m_bProcessExpressionTrees == false ) getAllNonlinearExpressionTrees();
    std::vector<ExprNode*> prefixVec;
    try
    {
        if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end())
        {
            RealValuedExpressionTree* expTree = getNonlinearExpressionTree( rowIdx);
            prefixVec = ((OSnLNode*)expTree->m_treeRoot)->getPrefixFromExpressionTree();
        }
        else
        {
            throw ErrorClass("Error in getNonlinearExpressionTreeInPrefix, rowIdx not valid");
        }
        return prefixVec;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getNonlinearExpressionTreeInPrefix

std::vector<ExprNode*> OSInstance::getNonlinearExpressionTreeModInPrefix( int rowIdx)
{

    //if( m_binitForAlgDiff == false) this->initForAlgDiff();
    if( m_bProcessExpressionTreesMod == false ) getAllNonlinearExpressionTreesMod();
    std::vector<ExprNode*> prefixVec;
    try
    {
        if( m_mapExpressionTreesMod.find( rowIdx) != m_mapExpressionTreesMod.end())
        {
            RealValuedExpressionTree* expTree = getNonlinearExpressionTreeMod( rowIdx);
            prefixVec = ((OSnLNode*)expTree->m_treeRoot)->getPrefixFromExpressionTree();
        }
        else
        {
            throw ErrorClass("Error in getNonlinearExpressionTreeInPrefix, rowIdx not valid");
        }
        return prefixVec;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getNonlinearExpressionTreeInPrefix

std::map<int, RealValuedExpressionTree*> OSInstance::getAllNonlinearExpressionTrees()
{
    //if( m_binitForAlgDiff == false) this->initForAlgDiff();
    if(m_bProcessExpressionTrees == true) return m_mapExpressionTrees;
    std::map<int, int> foundIdx;
    std::map<int, int>::iterator pos;
    OSnLNodePlus *nlNodePlus;
    RealValuedExpressionTree *expTree;
    m_iObjectiveNumberNonlinear = 0;
    m_iConstraintNumberNonlinear = 0;
    int i;
    // important -- tell the nl nodes not to destroy the OSExpression Objects
    if (instanceData->nonlinearExpressions != NULL)
    {
        if (instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 && 
            instanceData->nonlinearExpressions->nl != NULL)
        {
            for( i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++)
            {
                instanceData->nonlinearExpressions->nl[i]->m_bDeleteExpressionTree = false;
            }
        }
        int index;
        // kipp -- what should we return if instanceData->nonlinearExpressions->numberOfNonlinearExpressions is zero
        for(i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++)
        {
            index = instanceData->nonlinearExpressions->nl[ i]->idx;
            if(foundIdx.find( index) != foundIdx.end() )
            {
                nlNodePlus = new OSnLNodePlus();
                //expTree = new OSExpressionTree();
                expTree =  instanceData->nonlinearExpressions->nl[ i]->osExpressionTree;
                // set left child to old index and right child to new one
                nlNodePlus->m_mChildren[ 0] = ((OSnLNode*)m_mapExpressionTrees[ index]->m_treeRoot);
                nlNodePlus->m_mChildren[ 1] = ((OSnLNode*)instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot);
                // we must delete the Expression tree corresponding to the old index value but not the nl nodes
                instanceData->nonlinearExpressions->nl[ foundIdx[ index]  ]->m_bDeleteExpressionTree = true;
                instanceData->nonlinearExpressions->nl[ foundIdx[ index]  ]->osExpressionTree->bDestroyNlNodes = false;
                //point to the new expression tree
                m_mapExpressionTrees[ index] = expTree;
                m_mapExpressionTrees[ index]->m_treeRoot = nlNodePlus;
                foundIdx[ index] = i;
            }
            else
            {
                // we have a new index
                m_mapExpressionTrees[ index] = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree;
                m_mapExpressionTrees[ index]->m_treeRoot = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot;
                foundIdx[ index] = i;
            }
            //foundIdx[ index]++;
        }
    }
    // count the number of constraints and objective functions with nonlinear terms.
    for(pos = foundIdx.begin(); pos != foundIdx.end(); ++pos)
    {
        if(pos->first < 0)
        {
            m_iObjectiveNumberNonlinear++;
        }
        else
        {
            m_iConstraintNumberNonlinear++;
        }
    }
    m_bProcessExpressionTrees = true;
    return m_mapExpressionTrees;
}// getAllNonlinearExpressionTrees

std::map<int, RealValuedExpressionTree*> OSInstance::getAllNonlinearExpressionTreesMod()
{
    if( m_bProcessExpressionTreesMod == true ) return m_mapExpressionTreesMod;
    m_bProcessExpressionTreesMod = true;
    // make sure we have the modified map available
    if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
    return m_mapExpressionTreesMod;
}// getAllNonlinearExpressionTreesMod



int OSInstance::getMatrixNumber()
{
    if(m_iMatrixNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getMatrixNumber()");
        if (instanceData->matrices == NULL)
            m_iMatrixNumber = 0;    
        else
            m_iMatrixNumber = instanceData->matrices->numberOfMatrices;
    }
    return m_iMatrixNumber;
}//getMatrixNumber

bool OSInstance::processMatrices()
{
    if (m_bProcessMatrices == true) return true;

    int n = getMatrixNumber();
    if((instanceData->matrices == NULL ) || (n == 0) ) return true;

    try
    {
        if (n > 0)
        {
            if(m_bProcessMatrices != true)
            {
                //allocate space
                m_miMatrixType            = new ENUM_MATRIX_TYPE[n];
                m_miMatrixSymmetry        = new ENUM_MATRIX_SYMMETRY[n];
                m_miMatrixNumberOfColumns = new int[n];
                m_miMatrixNumberOfRows    = new int[n];
                m_msMatrixNames           = new std::string[n];
                m_mMatrix                 = new OSMatrix*[n];
                m_bProcessMatrices = true;
            }

            //process each matrix
            for (int i=0; i < n; i++)
            {
                m_miMatrixSymmetry[i] = instanceData->matrices->matrix[i]->symmetry;
                m_miMatrixType[i] = mergeMatrixType(ENUM_MATRIX_TYPE_unknown, 
                                    instanceData->matrices->matrix[i]->getMatrixType());
                m_miMatrixNumberOfColumns[i] = instanceData->matrices->matrix[i]->numberOfColumns;
                m_miMatrixNumberOfRows[i] = instanceData->matrices->matrix[i]->numberOfRows;
                m_msMatrixNames[i] = instanceData->matrices->matrix[i]->name;
                m_mMatrix[i] = (OSMatrix*)instanceData->matrices->matrix[i];

            }// end for on i (number of the matrix)
        }// end if (n > 0)
        return true;
    }// end try
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//processMatrices


bool OSInstance::matrixHasBase(int n)
{
    int nMatrices = getMatrixNumber();
    if ( (instanceData->matrices == NULL) || (nMatrices == 0) ) return false;
    if ( (n < 0) || (n >= nMatrices) ) return false;
    return instanceData->matrices->matrix[n]->matrixHasBase();
}//matrixHasBase

bool OSInstance::matrixHasElements(int n)
{
    int nMatrices = getMatrixNumber();
    if ( (instanceData->matrices == NULL) || (nMatrices == 0) ) return false;
    if ( (n < 0) || (n >= nMatrices) ) return false;
    return instanceData->matrices->matrix[n]->matrixHasElements();
}//matrixHasElements

bool OSInstance::matrixHasTransformations(int n)
{
    int nMatrices = getMatrixNumber();
    if ( (instanceData->matrices == NULL) || (nMatrices == 0) ) return false;
    if ( (n < 0) || (n >= nMatrices) ) return false;
    return instanceData->matrices->matrix[n]->matrixHasTransformations();
}//matrixHasTransformations

bool OSInstance::matrixHasBlocks(int n)
{
    int nMatrices = getMatrixNumber();
    if ( (instanceData->matrices == NULL) || (nMatrices == 0) ) return false;
    if ( (n < 0) || (n >= nMatrices) ) return false;
    return instanceData->matrices->matrix[n]->matrixHasBlocks();
}//matrixHasBlocks

int  OSInstance::getNumberOfElementConstructors(int n)
{
    int nMatrices = getMatrixNumber();
    if ( (instanceData->matrices == NULL) || (nMatrices == 0) ) return 0;
    if ( (n < 0) || (n >= nMatrices) ) return false;
    return instanceData->matrices->matrix[n]->getNumberOfElementConstructors();
}//getNumberOfElementConstructors

int  OSInstance::getNumberOfTransformationConstructors(int n)
{
    int nMatrices = getMatrixNumber();
    if ( (instanceData->matrices == NULL) || (nMatrices == 0) ) return 0;
    if ( (n < 0) || (n >= nMatrices) ) return false;
    return instanceData->matrices->matrix[n]->getNumberOfTransformationConstructors();
}//getNumberOfTransformationConstructors

int  OSInstance::getNumberOfBlocksConstructors(int n)
{
    int nMatrices = getMatrixNumber();
    if ( (instanceData->matrices == NULL) || (nMatrices == 0) ) return 0;
    if ( (n < 0) || (n >= nMatrices) ) return false;
    return instanceData->matrices->matrix[n]->getNumberOfBlocksConstructors();
}//getNumberOfBlocksConstructors


GeneralSparseMatrix* OSInstance::getExpandedMatrix(int n, bool rowMajor_,
                                                   ENUM_MATRIX_TYPE convertTo_,
                                                   ENUM_MATRIX_SYMMETRY symmetry_)
{
    try
    {
        if (!m_bProcessMatrices) processMatrices();
        int nMatrices = getMatrixNumber();
        if ( (instanceData->matrices == NULL) || (nMatrices == 0) )
            throw ErrorClass("no matrices defined in method getExpandedMatrix()");
        if ( (n < 0) || (n >= nMatrices) )
            throw ErrorClass("invalid matrix index in method getExpandedMatrix()");
        int i = instanceData->matrices->matrix[n]->getExpandedMatrix(m_mMatrix, rowMajor_,
                                                                     convertTo_, symmetry_);
        if (i < 0) throw ErrorClass("Expanded matrix could not be retrieved");
        return instanceData->matrices->matrix[n]->expandedMatrixByElements[i];
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getExpandedMatrix

#if 0
GeneralSparseMatrix* OSInstance::getMatrixCoefficientsInRowMajor(int n)
{
    try
    {
        int nMatrices = getMatrixNumber();
        if ( (instanceData->matrices == NULL) || (nMatrices == 0) )
            throw ErrorClass("no matrices defined in method getMatrixCoefficientsInRowMajor()");
        if ( (n < 0) || (n >= nMatrices) )
            throw ErrorClass("invalid matrix index in method getMatrixCoefficientsInRowMajor()");
        return instanceData->matrices->matrix[n]->getMatrixCoefficientsInRowMajor();
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getMatrixCoefficientsInRowMajor
#endif

//===========================================================================

int OSInstance::getNumberOfMatrixVariables()
{
    if(m_iMatrixVarNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getNumberOfMatrixVariables()");
        if (instanceData->matrixProgramming == NULL || 
            instanceData->matrixProgramming->matrixVariables == NULL)
            m_iMatrixVarNumber = 0;
        else
            m_iMatrixVarNumber = instanceData->matrixProgramming->matrixVariables->numberOfMatrixVar;
    }
    return m_iMatrixVarNumber;
}//getNumberOfMatrixVariables

int OSInstance::getNumberOfMatrixObjectives()
{
    if(m_iMatrixObjNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getNumberOfMatrixObjectives()");
        if (instanceData->matrixProgramming == NULL || 
            instanceData->matrixProgramming->matrixObjectives == NULL)
            m_iMatrixObjNumber = 0;
        else
            m_iMatrixObjNumber = instanceData->matrixProgramming->matrixObjectives->numberOfMatrixObj;
    }
    return m_iMatrixObjNumber;
}//getNumberOfMatrixObjectives

int OSInstance::getNumberOfMatrixConstraints()
{
    if(m_iMatrixObjNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getNumberOfMatrixConstraints()");
        if (instanceData->matrixProgramming == NULL || 
            instanceData->matrixProgramming->matrixConstraints == NULL)
            m_iMatrixConNumber = 0;
        else
            m_iMatrixConNumber = instanceData->matrixProgramming->matrixConstraints->numberOfMatrixCon;
    }
    return m_iMatrixConNumber;
}//getNumberOfMatrixConstraints

int OSInstance::getNumberOfMatrixExpressions()
{
    if(m_iMatrixExpressionNumber == -1)
    {
        if (instanceData == NULL)
            throw ErrorClass("data object undefined in method getNumberOfMatrixExpressions()");
        if (instanceData->matrixProgramming == NULL|| 
            instanceData->matrixProgramming->matrixExpressions == NULL)
            m_iMatrixExpressionNumber = 0;
        else
            m_iMatrixExpressionNumber = instanceData->matrixProgramming->matrixExpressions->numberOfExpr;
    }
    return m_iMatrixExpressionNumber;
}//getNumberOfMatrixExpressions


std::string OSInstance::getTimeDomainFormat()
{
    if (instanceData->timeDomain == NULL)
        return "";
    if (instanceData->timeDomain->interval != NULL)
        return "interval";
    if (instanceData->timeDomain->stages != NULL)
        return "stages";
    return "";
}// getTimeDomainFormat

int OSInstance::getTimeDomainStageNumber()
{
    try
    {
        if (instanceData->timeDomain == NULL)
            return 1;
        if (instanceData->timeDomain->interval != NULL)
            throw ErrorClass("getTimeDomainStageNumber: Continuous time not implemented yet");
        if (instanceData->timeDomain->stages == NULL)
            return 1;
        return instanceData->timeDomain->stages->numberOfStages;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(  eclass.errormsg);
    }
}// getTimeDomainStageNumber

std::string* OSInstance::getTimeDomainStageNames()
{
    if (instanceData->timeDomain == NULL)
        return NULL;
    if (instanceData->timeDomain->interval != NULL)
        return NULL; //throw an error
    if (instanceData->timeDomain->stages == NULL)
        return NULL;
    if (m_msTimeDomainStageNames != NULL)
        delete [] m_msTimeDomainStageNames;
    if (instanceData->timeDomain->stages->numberOfStages == 0)
        return NULL;
    m_msTimeDomainStageNames = new std::string[instanceData->timeDomain->stages->numberOfStages];
    for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
        m_msTimeDomainStageNames[i] = instanceData->timeDomain->stages->stage[i]->name;
    return m_msTimeDomainStageNames;
}// getTimeDomainStageNames


int* OSInstance::getTimeDomainStageNumberOfVariables()
{
    if (instanceData->timeDomain == NULL)
        return NULL;
    if (instanceData->timeDomain->interval != NULL)
        return NULL; //throw an error
    if (instanceData->timeDomain->stages == NULL)
        return NULL;
    if (m_miTimeDomainStageVariableNumber != NULL)
        delete [] m_miTimeDomainStageVariableNumber;
    if (instanceData->timeDomain->stages->numberOfStages == 0)
        return NULL;
    m_miTimeDomainStageVariableNumber = new int[instanceData->timeDomain->stages->numberOfStages];
    for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
        m_miTimeDomainStageVariableNumber[i] = instanceData->timeDomain->stages->stage[i]->variables->numberOfVariables;
    return m_miTimeDomainStageVariableNumber;
}// getTimeDomainStageNumberOfVariables

int* OSInstance::getTimeDomainStageNumberOfConstraints()
{
    if (instanceData->timeDomain == NULL)
        return NULL;
    if (instanceData->timeDomain->interval != NULL)
        return NULL; //throw an error
    if (instanceData->timeDomain->stages == NULL)
        return NULL;
    if (m_miTimeDomainStageConstraintNumber != NULL)
        delete [] m_miTimeDomainStageConstraintNumber;
    if (instanceData->timeDomain->stages->numberOfStages == 0)
        return NULL;
    m_miTimeDomainStageConstraintNumber = new int[instanceData->timeDomain->stages->numberOfStages];
    for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
        m_miTimeDomainStageConstraintNumber[i] = instanceData->timeDomain->stages->stage[i]->constraints->numberOfConstraints;
    return m_miTimeDomainStageConstraintNumber;
}// getTimeDomainStageNumberOfConstraints

int* OSInstance::getTimeDomainStageNumberOfObjectives()
{
    if (instanceData->timeDomain == NULL)
        return NULL;
    if (instanceData->timeDomain->interval != NULL)
        return NULL; //throw an error
    if (instanceData->timeDomain->stages == NULL)
        return NULL;
    if (m_miTimeDomainStageObjectiveNumber != NULL)
        delete [] m_miTimeDomainStageObjectiveNumber;
    if (instanceData->timeDomain->stages->numberOfStages == 0)
        return NULL;
    m_miTimeDomainStageObjectiveNumber = new int[instanceData->timeDomain->stages->numberOfStages];
    for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
        m_miTimeDomainStageObjectiveNumber[i] = instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives;
    return m_miTimeDomainStageObjectiveNumber;
}// getTimeDomainStageNumberOfObjectives

int** OSInstance::getTimeDomainStageVarList()
{
    if (instanceData->timeDomain == NULL)
        return NULL;
    if (instanceData->timeDomain->interval != NULL)
        return NULL; //throw an error
    if (instanceData->timeDomain->stages == NULL)
        return NULL;
    if (m_miTimeDomainStageVariableNumber == NULL)
        return NULL;
    if (m_mmiTimeDomainStageVarList != NULL)
    {
        for (int i = 0; i < m_iNumberOfTimeStages; i ++)
            delete[] m_mmiTimeDomainStageVarList[i];
        delete[] m_mmiTimeDomainStageVarList;
        m_mmiTimeDomainStageVarList = NULL;
    }

    //delete [] m_mmiTimeDomainStageVarList;
    if (instanceData->timeDomain->stages->numberOfStages == 0)
        return NULL;
    m_iNumberOfTimeStages = instanceData->timeDomain->stages->numberOfStages;
    m_mmiTimeDomainStageVarList = new int*[instanceData->timeDomain->stages->numberOfStages];
    int timeDomainStageNumberVar;
    for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
    {
        timeDomainStageNumberVar = m_miTimeDomainStageVariableNumber[i];
        m_mmiTimeDomainStageVarList[i] = new int[ timeDomainStageNumberVar ];
        if (instanceData->timeDomain->stages->stage[i]->variables->startIdx == -1)
            for (int j = 0; j < m_miTimeDomainStageVariableNumber[i]; j++)
                m_mmiTimeDomainStageVarList[i][j] = instanceData->timeDomain->stages->stage[i]->variables->var[j]->idx;
        else
            for (int j = 0; j < m_miTimeDomainStageVariableNumber[i]; j++)
                m_mmiTimeDomainStageVarList[i][j] = instanceData->timeDomain->stages->stage[i]->variables->startIdx + j;
    }
    return m_mmiTimeDomainStageVarList;
}// getTimeDomainStageVarList

int** OSInstance::getTimeDomainStageConList()
{
    if (instanceData->timeDomain == NULL)
        return NULL;
    if (instanceData->timeDomain->interval != NULL)
        return NULL; //throw an error
    if (instanceData->timeDomain->stages == NULL)
        return NULL;
    if (m_miTimeDomainStageConstraintNumber == NULL)
        return NULL;
    if (m_mmiTimeDomainStageConList != NULL)
    {

        for (int i = 0; i < m_iNumberOfTimeStages; i ++)
            delete[] m_mmiTimeDomainStageConList[i];
        delete[] m_mmiTimeDomainStageConList;
        m_mmiTimeDomainStageConList = NULL;
    }

    if (instanceData->timeDomain->stages->numberOfStages == 0)
        return NULL;
    m_iNumberOfTimeStages = instanceData->timeDomain->stages->numberOfStages;
    m_mmiTimeDomainStageConList = new int*[instanceData->timeDomain->stages->numberOfStages];
    int numTimeDomainStageCon;
    for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
    {
        numTimeDomainStageCon = m_miTimeDomainStageConstraintNumber[i];
        m_mmiTimeDomainStageConList[i] = new int[ numTimeDomainStageCon];
        if (instanceData->timeDomain->stages->stage[i]->constraints->startIdx == -1)
            for (int j = 0; j < m_miTimeDomainStageConstraintNumber[i]; j++)
                m_mmiTimeDomainStageConList[i][j] = instanceData->timeDomain->stages->stage[i]->constraints->con[j]->idx;
        else
            for (int j = 0; j < m_miTimeDomainStageConstraintNumber[i]; j++)
                m_mmiTimeDomainStageConList[i][j] = instanceData->timeDomain->stages->stage[i]->constraints->startIdx + j;
    }
    return m_mmiTimeDomainStageConList;
}// getTimeDomainStageConList

int** OSInstance::getTimeDomainStageObjList()
{
    if (instanceData->timeDomain == NULL)
        return NULL;
    if (instanceData->timeDomain->interval != NULL)
        return NULL; //throw an error
    if (instanceData->timeDomain->stages == NULL)
        return NULL;
    if (m_miTimeDomainStageObjectiveNumber == NULL)
        return NULL;
    if (m_mmiTimeDomainStageObjList != NULL)
    {
        for (int i = 0; i < m_iNumberOfTimeStages; i ++)
            delete[] m_mmiTimeDomainStageObjList[i];
        delete[] m_mmiTimeDomainStageObjList;
        m_mmiTimeDomainStageObjList = NULL;
    }
    if (instanceData->timeDomain->stages->numberOfStages == 0)
        return NULL;
    m_iNumberOfTimeStages = instanceData->timeDomain->stages->numberOfStages;
    m_mmiTimeDomainStageObjList = new int*[instanceData->timeDomain->stages->numberOfStages];
    int numTimeDomainStageObjNum;
    for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
    {
        numTimeDomainStageObjNum = m_miTimeDomainStageObjectiveNumber[i];
        m_mmiTimeDomainStageObjList[i] = new int[ numTimeDomainStageObjNum];
        if (instanceData->timeDomain->stages->stage[i]->objectives->startIdx == 0)
            for (int j = 0; j < m_miTimeDomainStageObjectiveNumber[i]; j++)
                m_mmiTimeDomainStageObjList[i][j] = instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx;
        else
            for (int j = 0; j < m_miTimeDomainStageObjectiveNumber[i]; j++)
                m_mmiTimeDomainStageObjList[i][j] = instanceData->timeDomain->stages->stage[i]->objectives->startIdx - j;
    }
    return m_mmiTimeDomainStageObjList;
}// getTimeDomainStageObjList

double OSInstance::getTimeDomainIntervalStart()
{
    if (instanceData->timeDomain == NULL)
        return 0.0;
    if (instanceData->timeDomain->stages != NULL)
        return 0.0; //throw an error
    if (instanceData->timeDomain->interval == NULL)
        return 0.0;
    return instanceData->timeDomain->interval->start;
}// getTimeDomainIntervalStart

double OSInstance::getTimeDomainIntervalHorizon()
{
    if (instanceData->timeDomain == NULL)
        return 0.0;
    if (instanceData->timeDomain->stages != NULL)
        return 0.0; //throw an error
    if (instanceData->timeDomain->interval == NULL)
        return 0.0;
    return instanceData->timeDomain->interval->horizon;
}// getTimeDomainIntervalHorizon



/* the set() methods
   ================= */

bool OSInstance::setInstanceName(string name)
{
    instanceHeader->name = name;
    return true;
}//setInstanceName

bool OSInstance::setInstanceSource(string source)
{
    instanceHeader->source = source;
    return true;
}//setInstanceSource

bool OSInstance::setInstanceDescription(string description)
{
    instanceHeader->description = description;
    return true;
}//setInstanceDescription

bool OSInstance::setInstanceCreator(string fileCreator)
{
    instanceHeader->fileCreator = fileCreator;
    return true;
}//setInstanceSource

bool OSInstance::setInstanceLicence(string licence)
{
    instanceHeader->licence = licence;
    return true;
}//setInstanceLicence


bool OSInstance::setVariableNumber(int number)
{
    // this method assume osinstance->instanceData->variables is not null
    if(number < 0) return false;
    //if(instanceData->variables->numberOfVariables != -1  && instanceData->variables->numberOfVariables != number){
    //    delete[] instanceData->variables->var;
    //    instanceData->variables->var = NULL;
    //}
    if(instanceData->variables == NULL) instanceData->variables = new Variables();
    instanceData->variables->numberOfVariables = number;
    if(instanceData->variables->var == NULL && number > 0)
    {
        instanceData->variables->var = new Variable*[number];
    }
    return true;
}//setVariableNumber


bool OSInstance::addVariable(int index, string name, double lowerBound, double upperBound, char type)
{
    if (verifyVarType(type) == false) type = 'C';
    instanceData->variables->var[index] = new Variable();
    if(index < 0 || instanceData->variables->numberOfVariables <= 0 || index >= instanceData->variables->numberOfVariables) return false;
    instanceData->variables->var[index]->name = name;
    instanceData->variables->var[index]->lb = lowerBound;
    instanceData->variables->var[index]->ub = upperBound;
    instanceData->variables->var[index]->type = type;
    //if(init != OSNaN()) instanceData->variables->var[index]->init = init;
    //instanceData->variables->var[index]->initString = initString;
    return true;
}//addVariable


bool OSInstance::setVariables(int number, string *names, double *lowerBounds,
                              double *upperBounds, char *types)
{
    if(number <= 0) return false;
    try
    {
        if(instanceData->variables == NULL)
        {
            throw ErrorClass("There is no variables object");
        }
        if(instanceData->variables->numberOfVariables != number)
        {
            throw ErrorClass("input number of variables not equal to number in class");
        }
        //instanceData->variables->var = new Variable*[number];
        int i;
        for(i = 0; i < number; i++)
        {
            instanceData->variables->var[ i] = new Variable();
        }
        if(names  != NULL)
        {
            for(i = 0; i < number; i++) instanceData->variables->var[i]->name = names[i];
        }
        if(lowerBounds != NULL)
        {
            for(i = 0; i < number; i++)
            {
                instanceData->variables->var[i]->lb = lowerBounds[i];
            }
        }
        if(upperBounds != NULL)
        {
            for(i = 0; i < number; i++)
            {
                instanceData->variables->var[i]->ub = upperBounds[i];
            }
        }
        if(types != NULL)
        {
            for(i = 0; i < number; i++)
            {
                if(verifyVarType(types[i]) == false) types[i] = 'C';
                instanceData->variables->var[i]->type = types[i];
            }
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(  eclass.errormsg);
    }
}//setVariables

// begin checking again with Jun Ma

bool OSInstance::setObjectiveNumber(int number)
{
    if(number < 0) return false;
    if(instanceData->objectives == NULL) instanceData->objectives = new Objectives();
    if(number == 0)
    {
        instanceData->objectives->numberOfObjectives = 0;
        instanceData->objectives->obj = 0;
        return true;
    }
    instanceData->objectives->numberOfObjectives = number;
    instanceData->objectives->obj = new Objective*[number];
    return true;
}//setObjectiveNumber

bool OSInstance::addObjective(int index, string name, string maxOrMin, double constant, double weight, SparseVector *objectiveCoefficients)
{
    if(index >= 0 || instanceData->objectives->numberOfObjectives <= 0 || abs(index) > instanceData->objectives->numberOfObjectives) return false;
    int arrayIndex = abs(index) -1;
    if(instanceData->objectives->obj == NULL) return false;
    instanceData->objectives->obj[arrayIndex] = new Objective();
    instanceData->objectives->obj[arrayIndex]->name = name;
    if( (maxOrMin != "max") && (maxOrMin != "min") ) return false;
    else instanceData->objectives->obj[arrayIndex]->maxOrMin = maxOrMin;
    instanceData->objectives->obj[arrayIndex]->constant = constant;
    instanceData->objectives->obj[arrayIndex]->weight = weight;
    int n = objectiveCoefficients->number;
    instanceData->objectives->obj[arrayIndex]->numberOfObjCoef = n;
    if(n == 0)
    {
        instanceData->objectives->obj[arrayIndex]->coef = 0;
    }
    else
    {
        int i = 0;
        instanceData->objectives->obj[arrayIndex]->coef = new ObjCoef*[n];
        for(i = 0; i < n; i++) instanceData->objectives->obj[arrayIndex]->coef[i] = new ObjCoef();
        for(i = 0; i < n; i++)
        {
            instanceData->objectives->obj[arrayIndex]->coef[i]->idx = objectiveCoefficients->indexes[i];
            instanceData->objectives->obj[arrayIndex]->coef[i]->value = objectiveCoefficients->values[i];
        }
    }
    return true;
}//addObjective

bool OSInstance::setObjectives(int number, string *names, string *maxOrMins, double *constants, double *weights, SparseVector **objectiveCoefficients)
{
    if(number < 0) return false;
    try
    {
        if(instanceData->objectives == NULL)
        {
            throw ErrorClass("there is no objectives object");
        }
        if(instanceData->objectives->numberOfObjectives != number)
        {
            throw ErrorClass("input number of objective not equal to number in class");
        }
        if(number == 0) return true;
        int i = 0;
        for(i = 0; i < number; i++)instanceData->objectives->obj[i] = new Objective();
        int j = 0;
        if(names != NULL)
        {
            for(i = 0; i < number; i++) instanceData->objectives->obj[i]->name = names[i];
        }
        if(maxOrMins != NULL)
        {
            for(i = 0; i < number; i++)
            {
                if(maxOrMins[i] == "" || (maxOrMins[i].compare("max") != 0 && maxOrMins[i].compare("min") !=0)) return false;
                instanceData->objectives->obj[i]->maxOrMin = maxOrMins[i];
            }
        }
        if(constants != NULL)
        {
            for(i = 0; i < number; i++) instanceData->objectives->obj[i]->constant = constants[i];
        }
        if(weights != NULL)
        {
            for(i = 0; i < number; i++) instanceData->objectives->obj[i]->weight = weights[i];
        }
        if(objectiveCoefficients != NULL)
        {
            for(i = 0; i < number; i++)
            {
                int n = (&objectiveCoefficients[i] == NULL || objectiveCoefficients[i]->indexes == NULL)?0:objectiveCoefficients[i]->number;
                instanceData->objectives->obj[i]->numberOfObjCoef = n;
                if(n == 0)
                {
                    instanceData->objectives->obj[i]->coef = NULL;
                }
                else
                {
                    instanceData->objectives->obj[i]->coef = new ObjCoef*[n];
                    for(j = 0; j < n; j++)
                    {
                        instanceData->objectives->obj[i]->coef[j] = new ObjCoef();
                        instanceData->objectives->obj[i]->coef[j]->idx  = objectiveCoefficients[i]->indexes[j];
                        instanceData->objectives->obj[i]->coef[j]->value = objectiveCoefficients[i]->values[j];
                    }
                }
            }
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(  eclass.errormsg);
    }
}//setObjectives


bool OSInstance::setConstraintNumber(int number)
{
    if(number < 0) return false;
    if(instanceData->constraints == NULL) instanceData->constraints = new Constraints();
    if(number == 0)
    {
        instanceData->constraints->numberOfConstraints = 0;
        instanceData->constraints->con = 0;
        return true;
    }
    instanceData->constraints->numberOfConstraints = number;
    if(instanceData->constraints->con == 0 )
    {
        instanceData->constraints->con = new Constraint*[number];
    }
    return true;
}//setConstraintNumber

bool OSInstance::addConstraint(int index, string name, double lowerBound, double upperBound, double constant)
{
    instanceData->constraints->con[ index] = new Constraint();
    if(index < 0 || instanceData->constraints->numberOfConstraints <= 0 || index >= instanceData->constraints->numberOfConstraints) return false;
    instanceData->constraints->con[ index]->name = name;
    if(lowerBound != -OSDBL_MAX && lowerBound != -OSDBL_MAX) instanceData->constraints->con[ index]->lb = lowerBound;
    if(upperBound != OSDBL_MAX && upperBound != OSDBL_MAX)instanceData->constraints->con[ index]->ub = upperBound;
    instanceData->constraints->con[ index]->constant = constant;
    return true;
}//addConstraint


bool OSInstance::setConstraints(int number, string* names, double* lowerBounds, double* upperBounds, double* constants)
{
    if(number < 0) return false;
    if(number == 0)
    {
        return true;
    }
    try
    {
        if(instanceData->constraints  == NULL)
        {
            throw ErrorClass("there is no constraints object");
        }
        if(instanceData->constraints->numberOfConstraints != number)
        {
            throw ErrorClass("input number of constraints not equal to number in class");
        }
        int i = 0;
        for(i = 0; i < number; i++)
        {
            instanceData->constraints->con[i] = new Constraint();
        }
        if(names != NULL)
        {
            for(i = 0; i < number; i++) instanceData->constraints->con[i]->name = names[i];
        }
        if(lowerBounds != NULL)
        {
            for(i = 0; i < number; i++)
            {
                if(lowerBounds[i] != -OSDBL_MAX && lowerBounds[i] != -OSDBL_MAX)instanceData->constraints->con[i]->lb = lowerBounds[i];
            }
        }
        if(upperBounds != NULL)
        {
            for(i = 0; i < number; i++)
            {
                if(upperBounds[i] != OSDBL_MAX && upperBounds[i] != OSDBL_MAX)instanceData->constraints->con[i]->ub = upperBounds[i];
            }
        }
        if(constants != NULL)
        {
            for(i = 0; i < number; i++) instanceData->constraints->con[i]->constant = constants[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(  eclass.errormsg);
    }
}//setConstraints

bool OSInstance::setLinearConstraintCoefficients(int numberOfValues, bool isColumnMajor,
        double* values, int valuesBegin, int valuesEnd,
        int* indexes, int indexesBegin, int indexesEnd,
        int* starts, int startsBegin, int startsEnd)
{
    if(numberOfValues < 0) return false;
    if(instanceData->linearConstraintCoefficients == NULL)
        instanceData->linearConstraintCoefficients = new LinearConstraintCoefficients() ;
    if(numberOfValues == 0) return true;
    if((values == 0 ) ||
            (valuesBegin < 0 || (valuesEnd - valuesBegin + 1) != numberOfValues) ||
            (indexes == 0) ||
            (indexesBegin < 0 || (indexesEnd - indexesBegin + 1) != numberOfValues) ||
            (starts == 0 ) ||
            (startsBegin < 0  || startsBegin >= startsEnd)) return false;
    instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
 
    //starts
    if (instanceData->linearConstraintCoefficients->start == NULL) 
        instanceData->linearConstraintCoefficients->start = new IntVector();
    else
        if (instanceData->linearConstraintCoefficients->start->el != NULL)
            delete [] instanceData->linearConstraintCoefficients->start->el;

    instanceData->linearConstraintCoefficients->start->el = (starts+startsBegin);
    instanceData->linearConstraintCoefficients->start->numberOfEl = startsEnd - startsBegin + 1;
    instanceData->linearConstraintCoefficients->iNumberOfStartElements = startsEnd - startsBegin + 1;

    //values
    if (instanceData->linearConstraintCoefficients->value == NULL) 
        instanceData->linearConstraintCoefficients->value = new DoubleVector();
    else
        if (instanceData->linearConstraintCoefficients->value->el != NULL)
            delete[] instanceData->linearConstraintCoefficients->value->el;

    instanceData->linearConstraintCoefficients->value->el = (values+valuesBegin);
    instanceData->linearConstraintCoefficients->value->numberOfEl = numberOfValues;

    //indexes
    if(isColumnMajor)
    {
        if (instanceData->linearConstraintCoefficients->rowIdx == NULL) 
            instanceData->linearConstraintCoefficients->rowIdx = new IntVector();
        else
            if (instanceData->linearConstraintCoefficients->rowIdx->el != NULL)
                delete[] instanceData->linearConstraintCoefficients->rowIdx->el;

        instanceData->linearConstraintCoefficients->rowIdx->el = (indexes+indexesBegin);
        instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = numberOfValues;
    }
    else
    {
        if (instanceData->linearConstraintCoefficients->colIdx == NULL) 
            instanceData->linearConstraintCoefficients->colIdx = new IntVector();
        else
            if (instanceData->linearConstraintCoefficients->colIdx->el != NULL)
                delete[] instanceData->linearConstraintCoefficients->colIdx->el;

        instanceData->linearConstraintCoefficients->colIdx->el = (indexes+indexesBegin);
        instanceData->linearConstraintCoefficients->colIdx->numberOfEl = numberOfValues;
    }
    return true;
}//setLinearConstraintCoefficients


bool OSInstance::copyLinearConstraintCoefficients(int numberOfValues, bool isColumnMajor,
        double* values, int valuesBegin, int valuesEnd,
        int* indexes, int indexesBegin, int indexesEnd,
        int* starts, int startsBegin, int startsEnd)
{
    if (numberOfValues < 0) return false;
    if (instanceData->linearConstraintCoefficients == NULL)
        instanceData->linearConstraintCoefficients = new LinearConstraintCoefficients() ;
    if (numberOfValues == 0) return true;
    if ((values == 0 ) ||
            (valuesBegin < 0 || (valuesEnd - valuesBegin + 1) != numberOfValues) ||
            (indexes == 0) ||
            (indexesBegin < 0 || (indexesEnd - indexesBegin + 1) != numberOfValues) ||
            (starts == 0 ) ||
            (startsBegin < 0  || startsBegin >= startsEnd)) return false;
    instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
    int i = 0;
    int k;

    //starts
    if (instanceData->linearConstraintCoefficients->start == NULL) 
        instanceData->linearConstraintCoefficients->start = new IntVector();
    else 
        delete [] instanceData->linearConstraintCoefficients->start->el;

    instanceData->linearConstraintCoefficients->start->el = new int[startsEnd - startsBegin + 1];
    k = 0;
    for(i = startsBegin; i <= startsEnd; i++)
    {
        instanceData->linearConstraintCoefficients->start->el[k] = starts[i];
        k++;
    }

    instanceData->linearConstraintCoefficients->start->numberOfEl = startsEnd - startsBegin + 1;

    //values
    if (instanceData->linearConstraintCoefficients->value == NULL) 
        instanceData->linearConstraintCoefficients->value = new DoubleVector();
    else 
        delete [] instanceData->linearConstraintCoefficients->value->el;

    instanceData->linearConstraintCoefficients->value->el = new double[numberOfValues];
    k = 0;
    for(i = valuesBegin; i <= valuesEnd; i++)
    {
        instanceData->linearConstraintCoefficients->value->el[k] = values[i];
        k++;
    }
    instanceData->linearConstraintCoefficients->value->numberOfEl = numberOfValues;

    //indexes
    if(isColumnMajor)
    {
        if (instanceData->linearConstraintCoefficients->rowIdx == NULL) 
            instanceData->linearConstraintCoefficients->rowIdx = new IntVector();
        else 
            delete [] instanceData->linearConstraintCoefficients->rowIdx->el;

        instanceData->linearConstraintCoefficients->rowIdx->el = new int[numberOfValues];
        k = 0;
        for(i = indexesBegin; i <= indexesEnd; i++)
        {
            instanceData->linearConstraintCoefficients->rowIdx->el[k] = indexes[i];
            k++;
        }
        instanceData->linearConstraintCoefficients->rowIdx->numberOfEl = k;
    }
    else
    {
        if (instanceData->linearConstraintCoefficients->colIdx == NULL) 
            instanceData->linearConstraintCoefficients->colIdx = new IntVector();
        else 
            delete [] instanceData->linearConstraintCoefficients->colIdx->el;

        instanceData->linearConstraintCoefficients->colIdx->el = new int[numberOfValues];
        k = 0;
        for(i = indexesBegin; i <= indexesEnd; i++)
        {
            instanceData->linearConstraintCoefficients->colIdx->el[k] = indexes[i];
            k++;
        }
        instanceData->linearConstraintCoefficients->colIdx->numberOfEl = k;
    }
    return true;
}//copyLinearConstraintCoefficients


bool OSInstance::setNumberOfQuadraticTerms(int nq)
{
    if (nq < 0)
        throw ErrorClass("number of quadratic terms cannot be negative");
    if (instanceData == NULL) instanceData = new InstanceData();
    if (instanceData->quadraticCoefficients == NULL)
        instanceData->quadraticCoefficients = new QuadraticCoefficients();
    m_iQuadraticTermNumber = nq;
    instanceData->quadraticCoefficients->numberOfQuadraticTerms = nq;
    return true;
}//setNumberOfQuadraticTerms


bool OSInstance::setQuadraticCoefficients(int number,
                                          int* rowIndexes, int* varOneIndexes, int* varTwoIndexes,
                                          double* coefficients, int begin, int end)
{
    if(number < 0) return false;
    if(number != (end - begin) + 1) return false;
    if(number == 0)
    {
        instanceData->quadraticCoefficients = NULL;
        return true;
    }
    if( (rowIndexes    == 0) ||
        (varOneIndexes == 0) ||
        (varTwoIndexes == 0) ||
        (coefficients  == 0)  ) return false;
    if (instanceData->quadraticCoefficients == NULL)
        instanceData->quadraticCoefficients = new QuadraticCoefficients();

    instanceData->quadraticCoefficients->numberOfQuadraticTerms = number;
    int i = 0;

    if (instanceData->quadraticCoefficients->qTerm != NULL)
        delete [] instanceData->quadraticCoefficients->qTerm;

    instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[number];
    for(i = 0; i < number; i++) instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();
    int k = 0;
    for(i = begin; i <= end; i++)
    {
        instanceData->quadraticCoefficients->qTerm[k]->idx = rowIndexes[i];
        instanceData->quadraticCoefficients->qTerm[k]->idxOne = varOneIndexes[i];
        instanceData->quadraticCoefficients->qTerm[k]->idxTwo = varTwoIndexes[i];
        instanceData->quadraticCoefficients->qTerm[k]->coef = coefficients[i];
        k++;
    }
    return true;
}//setQuadraticCoefficients

bool OSInstance::setQuadraticTermsInNonlinearExpressions(int numQPTerms, int* rowIndexes, int* varOneIndexes, int* varTwoIndexes, double* coefficients)
{
    instanceData->nonlinearExpressions->numberOfNonlinearExpressions = numQPTerms;
    instanceData->nonlinearExpressions->nl = new Nl*[ numQPTerms ];
    // define the vectors
    OSnLNode *nlNodePoint;
    OSnLNodeVariable *nlNodeVariablePoint;
    std::vector<ExprNode*> nlNodeVec;
    //
    //
    int i;
    for(i = 0; i < numQPTerms; i++)
    {
        instanceData->nonlinearExpressions->nl[ i] = new Nl();
        instanceData->nonlinearExpressions->nl[ i]->idx = rowIndexes[ i];
        instanceData->nonlinearExpressions->nl[ i]->osExpressionTree = new RealValuedExpressionTree();
        // create a variable nl node for x0
        nlNodeVariablePoint = new OSnLNodeVariable();
        nlNodeVariablePoint->idx = varOneIndexes[ i];
        // give this variable the coefficient
        nlNodeVariablePoint->coef = coefficients[ i];
        nlNodeVec.push_back( nlNodeVariablePoint);
        // create the nl node for x1
        nlNodeVariablePoint = new OSnLNodeVariable();
        nlNodeVariablePoint->idx = varTwoIndexes[ i];
        nlNodeVec.push_back( nlNodeVariablePoint);
        // create the nl node for *
        nlNodePoint = new OSnLNodeTimes();
        nlNodeVec.push_back( (OSnLNode*)nlNodePoint);
        // the vectors are in postfix format
        // now the expression tree
        instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot =
            ((OSnLNode*)nlNodeVec[ 0])->createExpressionTreeFromPostfix( nlNodeVec);
        nlNodeVec.clear();
    }
    return true;
}//setQuadraticTermsInNonlinearExpressions

bool OSInstance::setNonlinearExpressions(int nexpr, Nl** root)
{
    if(nexpr < 0) return false;

    if(nexpr == 0)
    {
        instanceData->nonlinearExpressions = 0;
        return true;
    }

    if (instanceData->nonlinearExpressions == NULL)
        instanceData->nonlinearExpressions = new NonlinearExpressions(); 
    instanceData->nonlinearExpressions->numberOfNonlinearExpressions = nexpr;
    instanceData->nonlinearExpressions->nl = new Nl*[nexpr];

    for (int i=0; i < nexpr; i++)
    {
        instanceData->nonlinearExpressions->nl[i] = new Nl();
        instanceData->nonlinearExpressions->nl[i]->idx = root[i]->idx;
        instanceData->nonlinearExpressions->nl[i]->osExpressionTree = new RealValuedExpressionTree();
        instanceData->nonlinearExpressions->nl[i]->osExpressionTree->m_treeRoot
            = /*((OSnLNode*)*/root[i]->osExpressionTree->m_treeRoot->cloneExprNode()/*)*/;
//            = root[i]->osExpressionTree->m_treeRoot->copyNodeAndDescendants();
    }
    return true;
}//setNonlinearExpressions

bool OSInstance::initializeNonLinearStructures( )
{
    std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
    if( m_bNonLinearStructuresInitialized == true) return true;
    if( m_bProcessVariables == false) processVariables();
    if( m_bProcessObjectives == false) processObjectives();
    if( m_bProcessConstraints == false) processConstraints();
    m_iVariableNumber = getVariableNumber();
    m_iObjectiveNumber = getObjectiveNumber();
    m_iConstraintNumber = getConstraintNumber();
    // get all of the expression trees
    if( m_bProcessExpressionTrees == false) getAllNonlinearExpressionTrees();
    // before proceeding get a copy of the map of the Expression Trees
    if( m_bDuplicateExpressionTreesMap == false) duplicateExpressionTreesMap();
    // now create all of the variable maps for each expression tree
    for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
    {
        (posMapExpTree->second)->getVariableIndicesMap();
    }
    // add the quadratic terms if necessary
    if(getNumberOfQuadraticTerms() > 0) addQTermsToExpressionTree();
    // now get the map of all nonlinear variables
    getAllNonlinearVariablesIndexMap( );
    getDenseObjectiveCoefficients();
    m_mdConstraintFunctionValues = new double[ this->getConstraintNumber()];
    m_mdObjectiveFunctionValues = new double[ this->getObjectiveNumber()];
    //m_mdObjGradient = new double[ this->instanceData->variables->numberOfVariables];
    m_bNonLinearStructuresInitialized = true;
    m_bProcessVariables = true;
    m_bProcessObjectives = true;
    m_bProcessConstraints = true;
    m_bProcessExpressionTrees = true;
    m_bDuplicateExpressionTreesMap = true;
    return true;
}

SparseJacobianMatrix *OSInstance::getJacobianSparsityPattern( )
{
    // it is important that this method NOT get called twice -- if
    // there are linear terms in <linearConstraintCoefficients> that
    // also appear in <nonlinearExpressions> then they will keep getting added
    // to the modified expession tree with each call to this method
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
        "in getJacobianSparsityPattern");
#endif
    if( m_bSparseJacobianCalculated == true) return m_sparseJacMatrix;
    // determine if we are in column or row major
    getLinearConstraintCoefficientMajor();

    // make sure the data structures have been inialized
    if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
    try
    {
        if( m_bColumnMajor == true)
        {
            if( getSparseJacobianFromColumnMajor( ) == false) throw ErrorClass("An error occurred in getSpareJacobianFromColumnMajor");
        }
        else
        {
            if( getSparseJacobianFromRowMajor( ) == false) throw ErrorClass("An error occurred in getSpareJacobianFromRowMajor");
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(  eclass.errormsg);
    }
    // now fill in the arrays of the sparseJacMatrix
    m_sparseJacMatrix = new SparseJacobianMatrix();
    // we point to memory already created so don't
    // destroy during garbage collection
    m_sparseJacMatrix->bDeleteArrays = false;
    m_sparseJacMatrix->valueSize =     m_iJacValueSize;
    m_sparseJacMatrix->starts = m_miJacStart;
    m_sparseJacMatrix->conVals = m_miJacNumConTerms;
    m_sparseJacMatrix->indexes = m_miJacIndex;
    m_sparseJacMatrix->values = m_mdJacValue;
    m_bSparseJacobianCalculated = true;
    return m_sparseJacMatrix;
}//getJacobianSparsityPattern

bool OSInstance::addQTermsToExressionTree() // obsolescent --- replaced by addQTermsToExpressionTree
{
    return addQTermsToExpressionTree();
}

bool OSInstance::addQTermsToExpressionTree()
{
    std::ostringstream outStr;
    int i, k, idx;
    // get the number of qTerms
    int numQTerms = instanceData->quadraticCoefficients->numberOfQuadraticTerms;
    if(numQTerms <= 0 || m_bQTermsAdded == true) return true;
    OSnLNodeVariable* nlNodeVariableOne;
    OSnLNodeVariable* nlNodeVariableTwo;
    OSnLNodeTimes* nlNodeTimes;
    OSnLNodePlus* nlNodePlus;
    RealValuedExpressionTree* expTree;
    getQuadraticTerms();
#ifndef NDEBUG
    //std::cout << "PROCESSING QUADRATIC TERMS" << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "PROCESSING QUADRATIC TERMS");
#endif
    for(i = 0; i < numQTerms; i++)
    {
        idx = m_quadraticTerms->rowIndexes[ i];
        //std::cout << "PROCESSING QTERM  = "  << i <<std::endl;
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "PROCESSING QTERM " <<  i << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        // see if row idx is in the expression tree
        if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() )
        {
            // row idx is in the expression tree
            // add the qTerm in row idx  to the expression tree
            // define two new OSnLVariable nodes, an OSnLnodeTimes, and OSnLnodePlus
            nlNodeVariableOne = new OSnLNodeVariable();
            nlNodeVariableOne->idx = m_quadraticTerms->varOneIndexes[ i];
            // see if the variable indexed by nlNodeVariableOne->idx is in the expression tree for row idx
            // if not, add to mapVarIdx
            expTree = m_mapExpressionTreesMod[ idx];
            if(  expTree->m_bIndexMapGenerated == false) expTree->getVariableIndicesMap();
            if( (*expTree->mapVarIdx).find( nlNodeVariableOne->idx) == (*expTree->mapVarIdx).end()  )
            {
                // add placeholder to map
                (*expTree->mapVarIdx)[ nlNodeVariableOne->idx] = 1;
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "ADDED THE FOLLOWING VARIABLE TO THE MAP: " <<  nlNodeVariableOne->idx << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            }
            nlNodeVariableOne->coef = m_quadraticTerms->coefficients[ i];
            nlNodeVariableTwo = new OSnLNodeVariable();
            nlNodeVariableTwo->idx = m_quadraticTerms->varTwoIndexes[ i];
            // see if the variable indexed by nlNodeVariableTwo->idx is in the expression tree for row idx
            // if not, add to mapVarIdx
            if( (*expTree->mapVarIdx).find( nlNodeVariableTwo->idx) == (*expTree->mapVarIdx).end()  )
            {
                // add to map
                k = (*expTree->mapVarIdx).size();
                (*expTree->mapVarIdx)[ nlNodeVariableTwo->idx] =  k + 1;
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "ADDED THE FOLLOWING VARIABLE TO THE MAP" <<  nlNodeVariableTwo->idx << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            }
            nlNodeVariableTwo->coef = 1.;
            // now multiply the two new variable nodes together
            nlNodeTimes = new OSnLNodeTimes();
            nlNodeTimes->m_mChildren[ 0] = nlNodeVariableOne;
            nlNodeTimes->m_mChildren[ 1] = nlNodeVariableTwo;
            // now add the result to the expression tree
            nlNodePlus = new OSnLNodePlus();
            nlNodePlus->m_mChildren[ 0] = (OSnLNode*)expTree->m_treeRoot;
            nlNodePlus->m_mChildren[ 1] = nlNodeTimes;
            //expTree = new RealValuedExpressionTree();
            expTree->m_treeRoot = nlNodePlus ;
            // get rid of old variable map
            if(expTree->m_bIndexMapGenerated == true)
            {
                delete expTree->mapVarIdx;
                expTree->mapVarIdx = NULL;
                expTree->m_bIndexMapGenerated = false;
            }
            //expTree->m_bIndexMapGenerated = false;
            //m_mapExpressionTreesMod[ idx ]  = expTree;
            //expTree->mapVarIdx = m_mapExpressionTreesMod[ idx]->mapVarIdx;
        }
        else
        {
            // create the quadratic expression to add to the expression tree
            nlNodeVariableOne = new OSnLNodeVariable();
            nlNodeVariableOne->idx = m_quadraticTerms->varOneIndexes[ i];
            nlNodeVariableOne->coef = m_quadraticTerms->coefficients[ i];
            nlNodeVariableTwo = new OSnLNodeVariable();
            nlNodeVariableTwo->idx = m_quadraticTerms->varTwoIndexes[ i];
            nlNodeVariableTwo->coef = 1.;
            // now multiply the two new variable nodes together
            nlNodeTimes = new OSnLNodeTimes();
            nlNodeTimes->m_mChildren[ 0] = nlNodeVariableOne;
            nlNodeTimes->m_mChildren[ 1] = nlNodeVariableTwo;
            // create a new expression tree corresponding to row idx.
            expTree = new RealValuedExpressionTree();
            expTree->m_treeRoot = nlNodeTimes ;
            expTree->mapVarIdx = expTree->getVariableIndicesMap();
            m_mapExpressionTreesMod[ idx ] = expTree;
            if(idx < 0)
            {
                m_iObjectiveNumberNonlinear++;
                m_bProcessExpressionTrees = true;
            }
            else
            {
                m_iConstraintNumberNonlinear++;
                m_bProcessExpressionTrees = true;
            }
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "NUMBER OF EXPRESSION TREES = "  << m_mapExpressionTreesMod.size() <<std::endl;
            outStr << "NUMBER OF NONLINEAR OBJECTIVES = "  << getNumberOfNonlinearObjectives() <<std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        }
        // if there were no nonlinear terms make this the expression tree
        if(m_iNonlinearExpressionNumber <= 0) m_mapExpressionTrees = m_mapExpressionTreesMod;
        m_bQTermsAdded =true;
    }
    return true;
} //addQTermsToExpressionTree


bool OSInstance::setMatrixNumber(int number)
{
    if(number < 0) return false;
    if(instanceData->matrices == NULL) instanceData->matrices = new Matrices();
    if(number == 0)
    {
        instanceData->matrices->numberOfMatrices = 0;
        instanceData->matrices->matrix = NULL;
        return true;
    }
    instanceData->matrices->numberOfMatrices = number;
    instanceData->matrices->matrix = new OSMatrix*[number];
    return true;
}//setMatrixNumber

bool OSInstance::addMatrix(int arrayIndex, std::string name, int numberOfRows, int numberOfColumns, 
                           ENUM_MATRIX_SYMMETRY symmetry, ENUM_MATRIX_TYPE matrixType, 
                           unsigned int inumberOfChildren, MatrixNode **m_mChildren)
{
    if (instanceData->matrices->numberOfMatrices <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->matrices->numberOfMatrices) return false;
    if (instanceData->matrices->matrix == NULL) return false;
    instanceData->matrices->matrix[arrayIndex] = new OSMatrix();
    return instanceData->matrices->matrix[arrayIndex]->setMatrix(
                name, numberOfRows, numberOfColumns, symmetry, matrixType,
                ENUM_MATRIX_TYPE_unknown, inumberOfChildren, m_mChildren);
}//addMatrix

bool OSInstance::setConeNumber(int number)
{
    if (number < 0) return false;
    if (instanceData->cones == NULL) instanceData->cones = new Cones();
    instanceData->cones->numberOfCones = number;

    if (number == 0)
        instanceData->cones->cone = NULL;
    else
        instanceData->cones->cone = new Cone*[number];
    return true;
}//setConeNumber

bool OSInstance::addCone(int arrayIndex, int numberOfRows, int numberOfColumns, ENUM_CONE_TYPE coneType,
                 std::string name, int numberOfOtherIndexes, int* otherIndexes)
{
    if (instanceData->cones->numberOfCones <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->cones->numberOfCones) return false;
    if (instanceData->cones->cone == NULL) return false;

    switch (coneType)
    {

        case ENUM_CONE_TYPE_nonnegative: 
            instanceData->cones->cone[arrayIndex] = new NonnegativeCone();
            ((NonnegativeCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((NonnegativeCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((NonnegativeCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((NonnegativeCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((NonnegativeCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((NonnegativeCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            break;
        case ENUM_CONE_TYPE_nonpositive:
            instanceData->cones->cone[arrayIndex] = new NonpositiveCone();
            ((NonpositiveCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((NonpositiveCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((NonpositiveCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((NonpositiveCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((NonpositiveCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((NonpositiveCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            break;
        case ENUM_CONE_TYPE_copositiveMatrices:
            instanceData->cones->cone[arrayIndex] = new CopositiveMatricesCone();
            ((CopositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((CopositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((CopositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((CopositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((CopositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((CopositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            break;
        case ENUM_CONE_TYPE_completelyPositiveMatrices:
            instanceData->cones->cone[arrayIndex] = new CompletelyPositiveMatricesCone();
            ((CompletelyPositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->numberOfRows    = numberOfRows;
            ((CompletelyPositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns = numberOfColumns;
            ((CompletelyPositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->coneType        = coneType;
            ((CompletelyPositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->name            = name;
            ((CompletelyPositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes
                = numberOfOtherIndexes;
            ((CompletelyPositiveMatricesCone*)instanceData->cones->cone[arrayIndex])->otherIndexes = otherIndexes;
            break;
        default:
            return false;
    }
    return true;
}//addCone --- nonnegative or nonpositive orthant, copositive matrices or completely positive matrices cone

bool OSInstance::addCone(int arrayIndex, int numberOfRows, int numberOfColumns, ENUM_CONE_TYPE coneType,
                 std::string name, int numberOfComponents, int* components, 
                 int numberOfOtherIndexes, int* otherIndexes)
{
    if (instanceData->cones->numberOfCones <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->cones->numberOfCones) return false;
    if (instanceData->cones->cone == NULL) return false;

    switch (coneType)
    {
        case ENUM_CONE_TYPE_product: 
            instanceData->cones->cone[arrayIndex] = new ProductCone();
            ((ProductCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((ProductCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((ProductCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((ProductCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((ProductCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((ProductCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;

            ((ProductCone*)instanceData->cones->cone[arrayIndex])->factors = new IntVector();
            ((ProductCone*)instanceData->cones->cone[arrayIndex])->factors->numberOfEl  = numberOfComponents;
            ((ProductCone*)instanceData->cones->cone[arrayIndex])->factors->el          = components;
            break;
        case ENUM_CONE_TYPE_intersection:
            instanceData->cones->cone[arrayIndex] = new IntersectionCone();
            ((IntersectionCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((IntersectionCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((IntersectionCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((IntersectionCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((IntersectionCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((IntersectionCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;

            ((IntersectionCone*)instanceData->cones->cone[arrayIndex])->components = new IntVector();
            ((IntersectionCone*)instanceData->cones->cone[arrayIndex])->components->numberOfEl = numberOfComponents;
            ((IntersectionCone*)instanceData->cones->cone[arrayIndex])->components->el         = components;
            break;
        default:
            return false;
    }
    return true;
}//addCone -- product or intersection cone

bool OSInstance::addCone(int arrayIndex, int numberOfRows, int numberOfColumns, ENUM_CONE_TYPE coneType,
                 std::string name, int referenceIdx, int numberOfOtherIndexes, int* otherIndexes)
{
    if (instanceData->cones->numberOfCones <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->cones->numberOfCones) return false;
    if (instanceData->cones->cone == NULL) return false;

    switch (coneType)

    {
/*
        case ENUM_CONE_TYPE_dual: 
            instanceData->cones->cone[arrayIndex] = new DualCone();
            ((DualCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((DualCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((DualCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((DualCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((DualCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((DualCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            ((DualCone*)instanceData->cones->cone[arrayIndex])->referenceConeIdx     = referenceIdx;
            break;
        case ENUM_CONE_TYPE_polar:
            instanceData->cones->cone[arrayIndex] = new PolarCone();
            ((PolarCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((PolarCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((PolarCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((PolarCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((PolarCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((PolarCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            ((PolarCone*)instanceData->cones->cone[arrayIndex])->referenceConeIdx     = referenceIdx;
            break;
*/
        case ENUM_CONE_TYPE_polyhedral:
            instanceData->cones->cone[arrayIndex] = new PolyhedralCone();
            ((PolyhedralCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((PolyhedralCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((PolyhedralCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((PolyhedralCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((PolyhedralCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((PolyhedralCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            ((PolyhedralCone*)instanceData->cones->cone[arrayIndex])->referenceMatrixIdx   = referenceIdx;
            break;
        default:
            return false;
    }

    return true;
}//addCone -- dual, polar or polyhedral cone

bool OSInstance::addCone(int arrayIndex, int numberOfRows, int numberOfColumns, ENUM_CONE_TYPE coneType,
                 std::string name, std::string semidefiniteness, int numberOfOtherIndexes, int* otherIndexes)
{
    if (instanceData->cones->numberOfCones <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->cones->numberOfCones) return false;
    if (instanceData->cones->cone == NULL) return false;

    if (coneType == ENUM_CONE_TYPE_semidefinite)
    {
            instanceData->cones->cone[arrayIndex] = new SemidefiniteCone();
            ((SemidefiniteCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((SemidefiniteCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((SemidefiniteCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((SemidefiniteCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((SemidefiniteCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((SemidefiniteCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            ((SemidefiniteCone*)instanceData->cones->cone[arrayIndex])->semidefiniteness     = semidefiniteness;
        return true;
    }
    else
        return false;
}//addCone --- semidefinite cone

bool OSInstance::addCone(int arrayIndex, int numberOfRows, int numberOfColumns, ENUM_CONE_TYPE coneType,
                 std::string name, int distortionMatrixIdx, double normFactor, int axisDirection, 
                 int numberOfOtherIndexes, int* otherIndexes)
{
    if (instanceData->cones->numberOfCones <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->cones->numberOfCones) return false;
    if (instanceData->cones->cone == NULL) return false;

    if (coneType == ENUM_CONE_TYPE_quadratic)
    {
            instanceData->cones->cone[arrayIndex] = new QuadraticCone();
            ((QuadraticCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((QuadraticCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((QuadraticCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((QuadraticCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((QuadraticCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((QuadraticCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            ((QuadraticCone*)instanceData->cones->cone[arrayIndex])->distortionMatrixIdx  = distortionMatrixIdx;
            ((QuadraticCone*)instanceData->cones->cone[arrayIndex])->normScaleFactor      = normFactor;
            ((QuadraticCone*)instanceData->cones->cone[arrayIndex])->axisDirection        = axisDirection;
        return true;
    }
    else
        return false;
}//addCone -- quadratic cone

bool OSInstance::addCone(int arrayIndex, int numberOfRows, int numberOfColumns, ENUM_CONE_TYPE coneType,
                 std::string name, int distortionMatrixIdx, double normFactor, int firstAxisDirection, 
                 int secondAxisDirection, int numberOfOtherIndexes, int* otherIndexes)
{
    if (instanceData->cones->numberOfCones <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->cones->numberOfCones) return false;
    if (instanceData->cones->cone == NULL) return false;

    if (instanceData->cones->numberOfCones <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->cones->numberOfCones) return false;
    if (instanceData->cones->cone == NULL) return false;

    if (coneType == ENUM_CONE_TYPE_rotatedQuadratic)
    {
            instanceData->cones->cone[arrayIndex] = new RotatedQuadraticCone();
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->distortionMatrixIdx  = distortionMatrixIdx;
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->normScaleFactor      = normFactor;
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->firstAxisDirection   = firstAxisDirection;
            ((RotatedQuadraticCone*)instanceData->cones->cone[arrayIndex])->secondAxisDirection  = secondAxisDirection;
        return true;
    }
    else
        return false;
}//addCone -- rotated quadratic cone

bool OSInstance::addCone(int arrayIndex, int numberOfRows, int numberOfColumns, ENUM_CONE_TYPE coneType,
                 std::string name, int distortionMatrixIdx, double normFactor, int axisDirection, double pNorm, 
                 int numberOfOtherIndexes, int* otherIndexes)
{
    if (instanceData->cones->numberOfCones <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->cones->numberOfCones) return false;
    if (instanceData->cones->cone == NULL) return false;

/*
    if (coneType == ENUM_CONE_TYPE_normed)
    {
            instanceData->cones->cone[arrayIndex] = new NormedCone();
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->distortionMatrixIdx  = distortionMatrixIdx;
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->normFactor           = normFactor;
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->axisDirectionIndex   = axisDirection;
            ((NormedCone*)instanceData->cones->cone[arrayIndex])->pNorm                = pNorm;
        return true;
    }
    else
*/
        return false;
}//addCone -- normed cone

bool OSInstance::addCone(int arrayIndex, int numberOfRows, int numberOfColumns, ENUM_CONE_TYPE coneType,
                 std::string name, int maxDegree, int numberOfUB, double* ub, int numberOfLB, double* lb,
                 int numberOfOtherIndexes, int* otherIndexes)
{
    if (instanceData->cones->numberOfCones <= 0) return false;
    if (arrayIndex < 0 || arrayIndex > instanceData->cones->numberOfCones) return false;
    if (instanceData->cones->cone == NULL) return false;

    switch (coneType)
    {
/*
        case ENUM_CONE_TYPE_nonnegativePolynomials: 
            instanceData->cones->cone[arrayIndex] = new NonnegativePolynomialsCone();
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes
                = numberOfOtherIndexes;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->otherIndexes = otherIndexes;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->maxDegree = maxDegree;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->maxDegree = maxDegree;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->maxDegree = maxDegree;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->maxDegree = maxDegree;
            ((NonnegativePolynomialsCone*)instanceData->cones->cone[arrayIndex])->maxDegree = maxDegree;
            break;
        case ENUM_CONE_TYPE_sumOfSquaresPolynomials:
            instanceData->cones->cone[arrayIndex] = new SumOfSquaresPolynomialsCone();
            ((SumOfSquaresPolynomialsCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((SumOfSquaresPolynomialsCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((SumOfSquaresPolynomialsCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((SumOfSquaresPolynomialsCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((SumOfSquaresPolynomialsCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes
                = numberOfOtherIndexes;
            ((SumOfSquaresPolynomialsCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            break;
        case ENUM_CONE_TYPE_moment:
            instanceData->cones->cone[arrayIndex] = new MomentCone();
            ((MomentCone*)instanceData->cones->cone[arrayIndex])->numberOfRows         = numberOfRows;
            ((MomentCone*)instanceData->cones->cone[arrayIndex])->numberOfColumns      = numberOfColumns;
            ((MomentCone*)instanceData->cones->cone[arrayIndex])->coneType             = coneType;
            ((MomentCone*)instanceData->cones->cone[arrayIndex])->name                 = name;
            ((MomentCone*)instanceData->cones->cone[arrayIndex])->numberOfOtherIndexes = numberOfOtherIndexes;
            ((MomentCone*)instanceData->cones->cone[arrayIndex])->otherIndexes         = otherIndexes;
            break;
*/
        default:
            return false;
    }
    return true;
}//addCone -- sum of squares polynomials, nonnegative polynomials or moment cone

std::string OSInstance::printModel( )
{
    std::string resultString = "";
    ostringstream outStr;
    outStr << "";
    int numCon;
    int numObj;
    int numVar;
    int i;
    numCon = this->getConstraintNumber();
    numObj = this->getObjectiveNumber();
    numVar = this->getVariableNumber();
    this->initForAlgDiff( );
    outStr << std::endl;
    std::string *objMaxOrMin = getObjectiveMaxOrMins();    
    outStr << "Objectives:" << std::endl;
    for(i = 0; i < numObj; i++)
    {
        outStr << objMaxOrMin[i] << ' ';
        outStr << this->printModel(-i-1);
    }
    outStr << std::endl;
    outStr << "Constraints:" << std::endl;
    for(i = 0; i < numCon; i++)
    {
        outStr << this->printModel( i);
    }

    outStr << std::endl;
    outStr << "Variables:" << std::endl;
    if(m_bProcessVariables != true  || bVariablesModified == true ) this->processVariables();
    for(i = 0; i < numVar; i++)
    {
        if(this->instanceData->variables->numberOfVariables > 0 && this->instanceData->variables->var[  i ]->name.size() > 0)
        {
            outStr << this->instanceData->variables->var[  i ]->name << ": ";
        }
//        else
        {
            outStr << "x_";
            outStr << i;
        }


        //outStr << "x_";
        //outStr << i;
        outStr << "  Type = " ;
        outStr <<  m_mcVariableTypes[i];
        outStr << "  Lower Bound =  ";
        outStr << os_dtoa_format( m_mdVariableLowerBounds[i])  ;
        outStr << "  Upper Bound =  ";
        outStr << os_dtoa_format( m_mdVariableUpperBounds[i])  ;
        outStr << std::endl;
    }

    // if model was originally in column matrix form we need to delete the new
    // matrix stored by row

    //if( this->instanceData->linearConstraintCoefficients != NULL && this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
    //    if(m_bColumnMajor == true){// we now have a duplication
    //        delete m_linearConstraintCoefficientsInRowMajor;
    //    }
    //}
    return outStr.str() ;
}//printModel( )


std::string OSInstance::printModel(int rowIdx )
{
    std::string resultString = "";


    ostringstream outStr;
    outStr << "";
    //loop over the constraints first;
    int j;
    int row_nonz = 0;
    int obj_nonz = 0;
    int varIdx = 0;
    bool addedLinearTerm = false;

    // initialize all of the necessary nonlinear stuff
    this->initForAlgDiff( );

    if( rowIdx >= 0)
    {
        if (rowIdx < this->getConstraintNumber())
        {
            outStr << this->getConstraintNames()[ rowIdx] ;
            outStr << "  ";
            if( m_bProcessConstraints != true || bConstraintsModified == true) this->processConstraints() ;
            if( m_mdConstraintLowerBounds[ rowIdx] >  -OSDBL_MAX)
            {
                if(m_mdConstraintLowerBounds[ rowIdx] < m_mdConstraintUpperBounds[ rowIdx])
                {
                    outStr << os_dtoa_format( m_mdConstraintLowerBounds[ rowIdx] );
                    outStr << " <= ";
                }
            }
        //
            if(this->instanceData->linearConstraintCoefficients != NULL && this->instanceData->linearConstraintCoefficients->numberOfValues > 0)
            {
                if(m_linearConstraintCoefficientsInRowMajor == NULL)
                    m_linearConstraintCoefficientsInRowMajor = this->getLinearConstraintCoefficientsInRowMajor();
                row_nonz = m_linearConstraintCoefficientsInRowMajor->starts[ rowIdx + 1] - m_linearConstraintCoefficientsInRowMajor->starts[ rowIdx];

                for(j = 0; j < row_nonz; j++)
                {
                    varIdx =  m_linearConstraintCoefficientsInRowMajor->indexes[ m_linearConstraintCoefficientsInRowMajor->starts[ rowIdx]  + j];

                    if(m_bSparseJacobianCalculated == false  ||  (m_mapExpressionTreesMod.find( rowIdx) == m_mapExpressionTreesMod.end() ) ||
                        ( (*m_mapExpressionTreesMod[ rowIdx]->mapVarIdx).find( varIdx) == (*m_mapExpressionTreesMod[ rowIdx]->mapVarIdx).end()) )
                    {
                        outStr << os_dtoa_format( m_linearConstraintCoefficientsInRowMajor->values[ m_linearConstraintCoefficientsInRowMajor->starts[ rowIdx]  + j] );
                        outStr << "*";

//                        if(this->instanceData->variables->numberOfVariables > 0 && this->instanceData->variables->var[  varIdx ]->name.size() > 0)
//                        {
//                            outStr << this->instanceData->variables->var[  varIdx ]->name;
//                        }
//                        else
                        {
                            outStr << "x_";
                            outStr << varIdx;
                        }


                        if( j < row_nonz - 1) outStr << " + ";
                        addedLinearTerm = true;
                    }
                }
            }
        }
        else
            return "row index not found; print command ignored\n";
    }
    else  // process an objective function
    {
        if(m_bProcessObjectives != true || bObjectivesModified == true)  this->processObjectives() ;
        int obj_idx =  -rowIdx - 1;
        if (obj_idx < this->getObjectiveNumber())
        {
            obj_nonz = m_miNumberOfObjCoef[ obj_idx];
            for(j = 0; j < obj_nonz; j++)
            {
                outStr << os_dtoa_format( m_mObjectiveCoefficients[obj_idx]->values[j] );
                outStr << "*";
                outStr << "x_";
                outStr << m_mObjectiveCoefficients[obj_idx]->indexes[j] ;
                if( j < obj_nonz - 1) outStr << " + ";
            }
        }
        else
            return "row index not found; print command ignored\n";
    }
    if( this->getNonlinearExpressionTree( rowIdx) != NULL)
    {
        if( (addedLinearTerm == true)  || (obj_nonz > 0) ) outStr << " + " ;
        outStr << getNonlinearExpressionTreeInInfix( rowIdx);
        //outStr << ")";
    }

    if( rowIdx >= 0)
    {
        if( m_bProcessConstraints != true ) this->processConstraints() ;
        if( m_mdConstraintUpperBounds[ rowIdx] <  OSDBL_MAX)
        {
            if(m_mdConstraintLowerBounds[ rowIdx] < m_mdConstraintUpperBounds[ rowIdx])
            {
                outStr << " <= ";
            }
            else
            {
                outStr << " = ";
            }
            outStr << os_dtoa_format( m_mdConstraintUpperBounds[ rowIdx] );
        }
    }
    outStr << std::endl;
    resultString = outStr.str();
    return resultString;
}//printModel( rowIdx )


double OSInstance::calculateFunctionValue(int idx, double *x, bool new_x)
{
    try
    {
        int i, j;
        double dvalue = 0;
        if( m_binitForAlgDiff == false) initForAlgDiff();
        if( m_bSparseJacobianCalculated == false) getJacobianSparsityPattern();
        if(idx >= 0)  // we have a constraint
        {
            // make sure the index idx is valid
            if( getConstraintNumber() <= idx  ) throw
                ErrorClass("constraint index not valid in OSInstance::calculateFunctionValue");
            if( new_x == false) return *(m_mdConstraintFunctionValues + idx);
            // get the nonlinear part
            if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() )
            {
                dvalue = m_mapExpressionTreesMod[ idx]->calculateFunction( x,  new_x);
            }
            // now the linear part
            // be careful, loop over only the constant terms in sparseJacMatrix
            i = m_sparseJacMatrix->starts[ idx];
            j = m_sparseJacMatrix->starts[ idx + 1 ];
            while ( (i - m_sparseJacMatrix->starts[ idx]) < m_sparseJacMatrix->conVals[ idx] )
            {
                dvalue += m_sparseJacMatrix->values[ i]*x[ m_sparseJacMatrix->indexes[ i] ];
                i++;
            }
            // add in the constraint function constant
            dvalue += m_mdConstraintConstants[ idx ];
            return dvalue;
        }
        else  // we have an objective function
        {
            // make sure the index idx is valid
            if( getObjectiveNumber() <= ( abs( idx) - 1) ) throw
                ErrorClass("objective function index not valid in OSInstance::calculateFunctionValue");
            if( new_x == false) return *(m_mdObjectiveFunctionValues + ( abs( idx) - 1));
            // get the nonlinear part
            if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() )
            {
                dvalue = m_mapExpressionTreesMod[ idx]->calculateFunction( x,  new_x);
            }
            // get linear part
            SparseVector **objCoef = getObjectiveCoefficients();
            SparseVector *obj = objCoef[ abs( idx) - 1];
            for(i = 0; i < obj->number; i++)
            {
                dvalue += x[ obj->indexes[i]]*(obj->values[ i]);
            }
            // add in the objective function constant
            dvalue += m_mdObjectiveConstants[ abs( idx) - 1 ];
            // get the coefficients for objective function idx
            *(m_mdObjectiveFunctionValues + ( abs( idx) - 1)) = dvalue;
            return *(m_mdObjectiveFunctionValues + ( abs( idx) - 1));
        }
    }

    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//calculateFunctionValue


double *OSInstance::calculateAllConstraintFunctionValues( double* x, double *objLambda, double *conLambda,
        bool new_x, int highestOrder)
{
    try
    {
        if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  )
            getIterateResults(x, objLambda, conLambda, new_x,  highestOrder);
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_mdConstraintFunctionValues;
}//calculateAllConstraintFunctionValues


double *OSInstance::calculateAllConstraintFunctionValues(double* x, bool new_x)
{
    try
    {
        m_iHighestOrderEvaluated = -1;
        if( new_x == false) return m_mdConstraintFunctionValues;
        int idx, numConstraints;
        numConstraints = getConstraintNumber();
        // loop over all constraints
        for(idx = 0; idx < numConstraints; idx++)
        {
            m_mdConstraintFunctionValues[ idx]  = calculateFunctionValue(idx, x, new_x);
        }

    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_mdConstraintFunctionValues;
}//end calculateAllConstraintFunctionValues


double *OSInstance::calculateAllObjectiveFunctionValues( double* x, double *objLambda, double *conLambda,
        bool new_x, int highestOrder)
{
    try
    {
        if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  )
            getIterateResults(x, objLambda, conLambda, new_x,  highestOrder);
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_mdObjectiveFunctionValues;
}//calculateAllObjectiveFunctionValues


double *OSInstance::calculateAllObjectiveFunctionValues( double* x, bool new_x)
{
    try
    {
        m_iHighestOrderEvaluated = -1;

        if( new_x == false) return m_mdObjectiveFunctionValues;
        int idx, numObjectives;
        numObjectives = getObjectiveNumber();
        // loop over all objectives
        for(idx = 0; idx < numObjectives; idx++)
        {
            m_mdObjectiveFunctionValues[ idx]  = calculateFunctionValue(-idx -1, x, new_x);
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_mdObjectiveFunctionValues;
}//calculateAllObjectiveFunctionValues


SparseJacobianMatrix *OSInstance::calculateAllConstraintFunctionGradients(double* x, double *objLambda, double *conLambda,
        bool new_x, int highestOrder)
{
    try

    {
        if(highestOrder < 1 ) throw ErrorClass("When calling calculateAllConstraintFunctionGradients highestOrder should be 1 or 2");

        if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  )
            getIterateResults(x, objLambda, conLambda,  new_x,  highestOrder);
    }//end try
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_sparseJacMatrix;
}//calculateAllConstraintFunctionGradients


SparseVector *OSInstance::calculateConstraintFunctionGradient(double* x, double *objLambda, double *conLambda,
        int idx, bool new_x, int highestOrder)
{
    try
    {
        if(highestOrder < 1 ) throw ErrorClass("When calling calculateConstraintFunctionGradient highestOrder should be 1 or 2");
        if(idx < 0 || idx >= instanceData->constraints->numberOfConstraints )
            throw ErrorClass("invalid index passed to calculateConstraintFunctionGrad");
        SparseVector *sp;
        sp = new SparseVector();
        sp->bDeleteArrays = true;
        int i;
        if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  )
            getIterateResults(x, objLambda, conLambda,  new_x,  highestOrder);
        sp->number = m_miJacStart[ idx + 1] - m_miJacStart[ idx];
        sp->values = new double[ sp->number];
        sp->indexes = new int[ sp->number];
        for(i = 0; i < sp->number; i++)
        {
            sp->values[ i] = m_mdJacValue[ m_miJacStart[ idx] +  i];
            sp->indexes[ i] = m_miJacIndex[ m_miJacStart[ idx] +  i];
        }
        return sp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//calculateConstraintFunctionGradient


SparseVector *OSInstance::calculateConstraintFunctionGradient(double* x, int idx, bool new_x)
{
    try
    {
        if(idx < 0 || idx >= instanceData->constraints->numberOfConstraints )
            throw ErrorClass("invalid index passed to calculateConstraintFunctionGrad");
        SparseVector *sp;
        sp = new SparseVector();
        sp->bDeleteArrays = true;
        int i;
        if( new_x == true || (1 > m_iHighestOrderEvaluated)  )
            getIterateResults(x, NULL, NULL,  new_x,  1);
        sp->number = m_miJacStart[ idx + 1] - m_miJacStart[ idx];
        sp->values = new double[ sp->number];
        sp->indexes = new int[ sp->number];
        for(i = 0; i < sp->number; i++)
        {
            sp->values[ i] = m_mdJacValue[ m_miJacStart[ idx] + i];
            sp->indexes[i] = m_miJacIndex[ m_miJacStart[ idx] + i];
        }
        return sp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//calculateConstraintFunctionGradient


double **OSInstance::calculateAllObjectiveFunctionGradients(double* x, double *objLambda, double *conLambda,
        bool new_x, int highestOrder)
{
    try
    {
        if(highestOrder < 1 ) throw ErrorClass("When calling calculateAllObjectiveFunctionGradients highestOrder should be 1 or 2");
        if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  )
        {
            std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
            for(posMapExpTree =  m_mapExpressionTreesMod.begin(); 
                posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
            {
                if(posMapExpTree->first < 0)  // this nonlinear expression indexes an objective function
                {
                    m_mmdObjGradient[ abs( posMapExpTree->first) - 1 ] = calculateObjectiveFunctionGradient(x, objLambda, conLambda,
                            posMapExpTree->first, new_x, highestOrder);
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_mmdObjGradient;
}// calculateAllObjectiveFunctionGradients

double *OSInstance::calculateObjectiveFunctionGradient(double* x, double *objLambda, double *conLambda,
        int objIdx, bool new_x, int highestOrder)
{
    /* if we are just doing an objective function gradient we should do a zero order forward sweep
     * and a reverse first order reverse sweep
     */
    try
    {
        if(highestOrder < 1 ) throw ErrorClass("When calling calculateObjectiveFunctionGradient highestOrder should be 1 or 2");
        if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  )
        {
            int domainIdx = 0;
            std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
            std::map<int, int>::iterator posVarIndexMap;
            int iHighestOrderEvaluatedStore;
            unsigned int i;
            iHighestOrderEvaluatedStore = m_iHighestOrderEvaluated;
            for(posMapExpTree  = m_mapExpressionTreesMod.begin(); 
                posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
            {
                //kipp: modify for more than one obj
                if(posMapExpTree->first == objIdx)
                {
                    if( new_x == true )
                    {
                        if( m_vdX.size() > 0) m_vdX.clear();
                        for(posVarIndexMap  = m_mapAllNonlinearVariablesIndex.begin(); 
                            posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap)
                        {
                            m_vdX.push_back( x[ posVarIndexMap->first]) ;
                        }
                        if( (m_bOSADFunIsCreated == false || m_bCppADMustReTape == true )  &&
                            (m_mapExpressionTreesMod.size() > 0) )
                        {
                            createOSADFun( m_vdX);
                        }
                    }

                    if(( new_x == true ) || (m_iHighestOrderEvaluated < 0) )this->forwardAD(0, m_vdX);

                    if(( new_x == true ) || (m_iHighestOrderEvaluated < 1) )
                    {
                        m_vdRangeUnitVec[ domainIdx] = 1.;
                        m_vdYjacval = this->reverseAD(1, m_vdRangeUnitVec);
                        for(i = 0; i < m_iNumberOfNonlinearVariables; i++)
                        {
                            m_mmdObjGradient[ abs( objIdx) - 1 ][ m_miNonLinearVarsReverseMap[ i]] = m_vdYjacval[ i] +
                                    m_mmdDenseObjectiveCoefficients[  abs( objIdx) - 1][ m_miNonLinearVarsReverseMap[ i]];
                        }
                    }
                    m_iHighestOrderEvaluated = iHighestOrderEvaluatedStore;
                    m_vdRangeUnitVec[ domainIdx] = 0.;
                    // exit the loop
                    break;
                }
                domainIdx++;
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_mmdObjGradient[abs( objIdx) - 1];
}//calculateObjectiveFunctionGradient


double *OSInstance::calculateObjectiveFunctionGradient(double* x, int objIdx, bool new_x)
{
    try
    {
        int domainIdx = 0;
        std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
        std::map<int, int>::iterator posVarIndexMap;
        unsigned int i;
        int  iHighestOrderEvaluatedStore;
        iHighestOrderEvaluatedStore = m_iHighestOrderEvaluated;
        for(posMapExpTree  = m_mapExpressionTreesMod.begin(); 
            posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
        {
            if(posMapExpTree->first == objIdx)
            {
                if( new_x == true )
                {
                    if( m_vdX.size() > 0) m_vdX.clear();
                    for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap)
                    {
                        m_vdX.push_back( x[ posVarIndexMap->first]) ;
                    }
                    if( (m_bOSADFunIsCreated == false || m_bCppADMustReTape == true )  &&
                        (m_mapExpressionTreesMod.size() > 0) )
                    {
                        createOSADFun( m_vdX);
                    }
                }

                if(( new_x == true ) || (m_iHighestOrderEvaluated < 0) ) this->forwardAD(0, m_vdX);

                if(( new_x == true ) || (m_iHighestOrderEvaluated < 1) )
                {
                    m_vdRangeUnitVec[ domainIdx] = 1.;
                    m_vdYjacval = this->reverseAD(1, m_vdRangeUnitVec);
                    for(i = 0; i < m_iNumberOfNonlinearVariables; i++)
                    {
                        m_mmdObjGradient[ abs( objIdx) - 1 ][ m_miNonLinearVarsReverseMap[ i]] = m_vdYjacval[ i] +
                                m_mmdDenseObjectiveCoefficients[  abs( objIdx) - 1][ m_miNonLinearVarsReverseMap[ i]];
                    }
                }
                m_iHighestOrderEvaluated = iHighestOrderEvaluatedStore;
                m_vdRangeUnitVec[ domainIdx] = 0.;
                // exit the loop
                break;
            }
            domainIdx++;
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_mmdObjGradient[abs( objIdx) - 1];
}//calculateObjectiveFunctionGradient

SparseHessianMatrix *OSInstance::calculateLagrangianHessian( double* x, double *objLambda, double *conLambda,
        bool new_x, int highestOrder)
{
    try
    {
        if(highestOrder != 2 ) throw ErrorClass("When calling calculateLagrangianHessian highestOrder should be 2");
        if( new_x == true || (highestOrder > m_iHighestOrderEvaluated)  )
        {
            getIterateResults(x, objLambda, conLambda,  new_x,  highestOrder);
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_LagrangianSparseHessian;
}//calculateLagrangianHessian

SparseHessianMatrix *OSInstance::calculateHessian(double* x, int idx, bool new_x)
{
    try
    {
        if(idx < -instanceData->objectives->numberOfObjectives || idx >= instanceData->constraints->numberOfConstraints )
            throw ErrorClass("invalid index passed to calculateHessian");
        double *objLambda = new double[ getObjectiveNumber() ];
        double *conLambda = new double[ getConstraintNumber() ];
        int i;
        // initialize all to zero
        for(i = 0; i < getObjectiveNumber(); i++)
        {
            objLambda[ i] = 0.0;
        }
        for(i = 0; i < getConstraintNumber(); i++)
        {
            conLambda[ i] = 0.0;
        }
        // see if we have the index of an objective function or a constraint
        // and make corresponding component 1.0
        if(idx < 0)
        {
            objLambda[ abs(idx) - 1] = 1.0;
        }
        else
        {
            conLambda[ idx] = 1.0;
        }

        if( new_x == true || (2 > m_iHighestOrderEvaluated)  )
        {
            getIterateResults(x, objLambda, conLambda, new_x,  2);
        }
        delete[] objLambda;
        delete[] conLambda;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_LagrangianSparseHessian;
}//calculateHessian


bool OSInstance::getSparseJacobianFromColumnMajor( )
{
    std::ostringstream outStr;

    // we assume column major matrix
    if( m_bColumnMajor == false) return false;
    int iNumRowStarts = getConstraintNumber() + 1;
    int i,j, iTemp;
    int iNumVariableStarts = getVariableNumber();
    int *start = NULL;
    int *index = NULL;
    double *value = NULL;

    if(this->instanceData->linearConstraintCoefficients != NULL)
    {
        start = this->instanceData->linearConstraintCoefficients->start->el;
        index = this->instanceData->linearConstraintCoefficients->rowIdx->el;
        value = this->instanceData->linearConstraintCoefficients->value->el;
    }
    m_miJacStart = new int[ iNumRowStarts];
    m_miJacNumConTerms = new int[ getConstraintNumber()];
    OSnLNodePlus *nlNodePlus;
    OSnLNodeVariable *nlNodeVariable;
    RealValuedExpressionTree *expTree = NULL;
    // now initialize starts and variable index maps
    for ( i = 0; i < iNumRowStarts; i++)
    {
        m_miJacStart [ i ] = 0;
        // map the variables  in the nonlinear rows
        if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() )
        {
            // the following is equivalent to  m_treeRoot->getVariableIndexMap( i);
            m_mapExpressionTreesMod[ i]->getVariableIndicesMap();
        }
    }
    //this is the only place where we can make sure that variable indices reference true variables
    std::map<int, RealValuedExpressionTree*>::iterator ixpr;
    std::map<int, int>::iterator ivar;
    for (ixpr = m_mapExpressionTreesMod.begin(); ixpr != m_mapExpressionTreesMod.end(); ++ixpr)
    {
        RealValuedExpressionTree* tmpTree = ixpr->second;
        for (ivar = (*tmpTree->mapVarIdx).begin(); ivar != (*tmpTree->mapVarIdx).end(); ++ivar)
        {
            if (ivar->first < 0 || ivar->first >= instanceData->variables->numberOfVariables)
                throw ErrorClass("Variable index references nonexisting variable");
        }
    }
    // only execute the following code if there are linear constraint coefficients
    if (this->instanceData->linearConstraintCoefficients != NULL &&
        this->instanceData->linearConstraintCoefficients->numberOfValues > 0)
    {
        // i is indexing columns (variables) and j is indexing row numbers
        for (i = 0; i < iNumVariableStarts; i++)
        {
            for (j = start[i]; j < start[ i + 1 ]; j++)
            {
                // index[ j] is a row index, we have just found an occurance of row index[j]
                // therefore we increase by 1 (or push back) the start of the row indexed by index[j] + 1,
                // i.e. the start of the next row
                // check to see if variable i is linear/constant in the row index[ j]
                // if so, increment m_miJacStart[ index[j] + 1]
                //
                if( (m_mapExpressionTreesMod.find( index[ j]) != m_mapExpressionTreesMod.end() ) &&
                        ( (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).find( i) !=
                          (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).end()) )
                {
                    // variable i appears in the expression tree for row index[ j]
                    // add the coefficient corresponding to variable i in row index[ j] to the expression tree
                    // define a new OSnLVariable and OSnLnodePlus
                    // don't add a zero
                    if( value[j] > 0 || value[j] < 0)
                    {
                        expTree = m_mapExpressionTreesMod[ index[j]  ];
                        nlNodeVariable = new OSnLNodeVariable();
                        nlNodeVariable->coef = value[ j];
                        nlNodeVariable->idx = i;
                        nlNodePlus = new OSnLNodePlus();
                        nlNodePlus->m_mChildren[ 0] = m_mapExpressionTreesMod[ index[ j] ]->m_treeRoot;
                        nlNodePlus->m_mChildren[ 1] = nlNodeVariable;
                        expTree->m_treeRoot = nlNodePlus;
                    }
                }
                else
                {
                    m_miJacStart[ index[j] + 1] ++;
                }
            }
        }
    }
    // at this point, m_miJacStart[ i] holds the number of columns with a linear/constant nonzero in row i - 1
    // we are not done with the start indices, if we are here, and we
    // knew the correct starting point of row i -1, the correct starting point
    // for row i is m_miJacStart[i] + m_miJacStart [i - 1]
    m_miJacStart[0] = 0;
    for (i = 1; i < iNumRowStarts; i++ )
    {
        m_miJacNumConTerms[ i - 1] = m_miJacStart[i];
        if( m_mapExpressionTreesMod.find( i - 1) != m_mapExpressionTreesMod.end() )
        {
            m_miJacStart[i] += (m_miJacStart[i - 1] + (*m_mapExpressionTreesMod[ i - 1]->mapVarIdx).size() );
        }
        else
        {
            m_miJacStart[i] += m_miJacStart[i - 1];
        }
    }
    // dimension miIndex and mdValue here
    m_iJacValueSize =     m_miJacStart[ iNumRowStarts - 1];
    m_miJacIndex = new int[  m_iJacValueSize];
    m_mdJacValue = new double[ m_iJacValueSize ];
    // now get the values of the constant terms if there are any
    if (this->instanceData->linearConstraintCoefficients != NULL &&
        this->instanceData->linearConstraintCoefficients->numberOfValues > 0)

    {
        // loop over variables
        for (i = 0; i < iNumVariableStarts; i++)
        {
            // get row indices and values of the A matrix
            // kipp -- should we have a check to see if start[i+1] > start[i]
            for (j = start[i]; j < start[ i + 1 ]; j++)
            {
                // store this variable index in every row where the variable appears
                // however, don't store this as constant term if it appears in mapVarIdx
                if( (m_mapExpressionTreesMod.find( index[ j]) == m_mapExpressionTreesMod.end() ) ||
                        ( (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).find( i) ==
                          (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).end()) )
                {
                    iTemp = m_miJacStart[ index[j]];
                    m_miJacIndex[ iTemp] = i;
                    m_mdJacValue[ iTemp] = value[j];
                    m_miJacStart[ index[j]]++;
                }
            }
        }
    }
    //
    std::map<int, int>::iterator posVarIdx;
    // m_miJacStart[ i] is now equal to the correct m_miJacStart[ i] + m_miJacNumConTerms[ i], so readjust
    for (i = 0; i < iNumRowStarts - 1; i++ )
    {
        m_miJacStart[ i] = m_miJacStart [ i] - m_miJacNumConTerms[ i] ;
        iTemp = m_miJacStart[ i] + m_miJacNumConTerms[ i];
        // if the row is in the list of expression trees read in indices and values
        if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() )
        {
            for(posVarIdx  = (*m_mapExpressionTreesMod[ i]->mapVarIdx).begin(); 
                posVarIdx != (*m_mapExpressionTreesMod[ i]->mapVarIdx).end(); ++posVarIdx)
            {
                m_miJacIndex[ iTemp] = posVarIdx->first;
                m_mdJacValue[ iTemp] = 0;
                iTemp++;
            }
        }
    }
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "HERE ARE ROW STARTS:" << std::endl;
    for (i = 0; i < iNumRowStarts; i++ )
    {
        outStr <<  m_miJacStart[ i] << "  ";
    }
    outStr << std::endl << std::endl;
    outStr << "HERE ARE VARIABLE INDICES:" << std::endl;
    for (i = 0; i < m_miJacStart[ iNumRowStarts - 1]; i++ )
    {
        outStr <<  m_miJacIndex[ i] << "  ";
    }
    outStr << std::endl << std::endl;
    outStr << "HERE ARE VALUES:" << std::endl;
    for (i = 0; i < m_miJacStart[ iNumRowStarts - 1]; i++ )
    {
        outStr <<  m_mdJacValue[ i] << "  ";
    }
    outStr << std::endl << std::endl;

    outStr << "HERE ARE NUMBER OF CONSTANT TERMS:" << std::endl;
    for (i = 0; i < iNumRowStarts - 1; i++ )

    {
        outStr <<  m_miJacNumConTerms[ i ] << "  ";
    }
    outStr << std::endl << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    return true;
}//getSparseJacobianFromColumnMajor


bool OSInstance::getSparseJacobianFromRowMajor( )
{
    std::ostringstream outStr;

    // we assume row major matrix
    if( m_bColumnMajor == true) return false;
    int iNumJacRowStarts = getConstraintNumber() + 1;
    std::map<int, int>::iterator posVarIdx;
    int i,j, k;
    int *start = NULL;
    int *index = NULL;
    double *value = NULL;

    if (this->instanceData->linearConstraintCoefficients != NULL &&
        this->instanceData->linearConstraintCoefficients->numberOfValues > 0)
    {
        start = this->instanceData->linearConstraintCoefficients->start->el;
        index = this->instanceData->linearConstraintCoefficients->colIdx->el;
        value = this->instanceData->linearConstraintCoefficients->value->el;
    }

    m_miJacStart = new int[ iNumJacRowStarts];
    m_miJacNumConTerms = new int[ getConstraintNumber()];
    OSnLNodePlus *nlNodePlus;
    OSnLNodeVariable *nlNodeVariable;
    // now initialize starts and variable index maps
    for ( i = 0; i < iNumJacRowStarts; i++)
    {
        m_miJacStart [ i ] = 0;
        // map the variables  in the nonlinear rows
        if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() )
        {
            // the following is equivalent to  m_treeRoot->getVariableIndexMap( i);
            m_mapExpressionTreesMod[ i]->getVariableIndicesMap();

        }
    }
    //make sure that variable indices reference true variables
    std::map<int, RealValuedExpressionTree*>::iterator ixpr;
    std::map<int, int>::iterator ivar;
    for (ixpr = m_mapExpressionTreesMod.begin(); ixpr != m_mapExpressionTreesMod.end(); ++ixpr)
    {
        RealValuedExpressionTree* tmpTree = ixpr->second;
        for (ivar = (*tmpTree->mapVarIdx).begin(); ivar != (*tmpTree->mapVarIdx).end(); ++ivar)
        {
            if (ivar->first < 0 || ivar->first >= instanceData->variables->numberOfVariables)
                throw ErrorClass("Variable index references nonexisting variable");
        }
    }
    int loopLimit =  getConstraintNumber();
    // only execute the following code if there are linear constraint coefficients
    // determine the number of terms in constraint with constant partial derivative
    if (this->instanceData->linearConstraintCoefficients != NULL &&
        this->instanceData->linearConstraintCoefficients->numberOfValues > 0)
    {
        // i is indexing rows (constrains) and j is indexing column numbers
        for (i = 0; i < loopLimit; i++)
        {
            m_miJacNumConTerms[ i] = 0;
            for (j = start[i]; j < start[ i + 1 ]; j++)
            {
                // determine if variable index[j] appears in the Expression Tree for row i
                // if we pass if test below then variable i is in the expresssion tree and we add
                // the linear term to the expession tree
                if( (m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() ) &&
                        ( (*m_mapExpressionTreesMod[ i]->mapVarIdx).find( index[ j]) !=
                          (*m_mapExpressionTreesMod[ i]->mapVarIdx).end()) )
                {
                    // variable index[ j] appears in the expression tree for row i
                    // add the coefficient corresponding to variable index[j] in row i to the expression tree
                    // define a new OSnLVariable and OSnLnodePlus
                    if(value[ j] > 0 || value[j] < 0)
                    {
                        nlNodeVariable = new OSnLNodeVariable();
                        nlNodeVariable->coef = value[ j];
                        nlNodeVariable->idx = index[ j];
                        nlNodePlus = new OSnLNodePlus();
                        nlNodePlus->m_mChildren[ 0] = ((OSnLNode*)m_mapExpressionTreesMod[ i ]->m_treeRoot);
                        nlNodePlus->m_mChildren[ 1] = nlNodeVariable;
                        m_mapExpressionTreesMod[ i ]->m_treeRoot = nlNodePlus;
                    }
                }
                else
                {
                    //the partial derivative of variable j in row i is constant
                    m_miJacNumConTerms[ i]++;
                }
            }
        }
    }
    //
    m_miJacStart[0] = 0;
    for (i = 1; i < iNumJacRowStarts; i++ )
    {
        if( m_mapExpressionTreesMod.find( i - 1) != m_mapExpressionTreesMod.end() )
        {
            m_miJacStart[i] = m_miJacStart[i - 1] + (m_miJacNumConTerms[ i - 1]
                                                  + (*m_mapExpressionTreesMod[ i - 1]->mapVarIdx).size() );
        }
        else
        {
            m_miJacStart[i] = m_miJacStart[i - 1] + m_miJacNumConTerms[ i - 1];
        }
    }
    // we know how many constant terms and size of arrays
    // dimension miIndex and mdValue here
    m_iJacValueSize =     m_miJacStart[ iNumJacRowStarts - 1];
    m_miJacIndex = new int[  m_iJacValueSize];
    m_mdJacValue = new double[ m_iJacValueSize ];
    // now loop again and put in values and indices
    // first put in the constant terms
    if (this->instanceData->linearConstraintCoefficients != NULL &&
        this->instanceData->linearConstraintCoefficients->numberOfValues > 0)
    {
        for (i = 0; i < loopLimit; i++)
        {
            k = 0;
            for (j = start[i]; j < start[ i + 1 ]; j++)
            {
                if( (m_mapExpressionTreesMod.find( i) == m_mapExpressionTreesMod.end() ) ||
                        ( (*m_mapExpressionTreesMod[ i]->mapVarIdx).find( index[ j]) ==
                          (*m_mapExpressionTreesMod[ i]->mapVarIdx).end()) )
                {
                    m_miJacIndex[ m_miJacStart[i] + k ] = index[ j];
                    m_mdJacValue[ m_miJacStart[i] + k ] = value[ j];
                    k++;
                }
            }
        }
    }
    // put in terms from the modified nonlinear expression tree
    for (i = 0; i < loopLimit; i++ )
    {
        k = m_miJacStart[i] + m_miJacNumConTerms[ i ];
        // if the row is in the list of expression trees read in indices and values
        if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() )
        {
            for(posVarIdx  = (*m_mapExpressionTreesMod[ i]->mapVarIdx).begin();
                posVarIdx != (*m_mapExpressionTreesMod[ i]->mapVarIdx).end(); ++posVarIdx)
            {
                m_miJacIndex[ k] = posVarIdx->first;
                m_mdJacValue[ k] = 0;
                k++;
            }
        }
    }
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "HERE ARE ROW STARTS:" << std::endl;
    for (i = 0; i < iNumJacRowStarts; i++ )
    {
        outStr <<  m_miJacStart[ i] << "  ";
    }
    outStr << std::endl << std::endl;
    outStr << "HERE ARE VARIABLE INDICES:" << std::endl;
    for (i = 0; i < m_miJacStart[ iNumJacRowStarts - 1]; i++ )
    {
        outStr <<  m_miJacIndex[ i] << "  ";
    }
    outStr << std::endl << std::endl;
    outStr << "HERE ARE VALUES:" << std::endl;
    for (i = 0; i < m_miJacStart[ iNumJacRowStarts - 1]; i++ )
    {
        outStr <<  m_mdJacValue[ i] << "  ";
    }
    outStr << std::endl << std::endl;

    outStr << "HERE ARE NUMBER OF CONSTANT TERMS:" << std::endl;
    for (i = 0; i < iNumJacRowStarts - 1; i++ )
    {
        outStr <<  m_miJacNumConTerms[ i ] << "  ";
    }
    outStr << std::endl << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    return true;
}//getSparseJacobianFromRowMajor

RealValuedExpressionTree* OSInstance::getLagrangianExpTree( )
{
    if( m_bLagrangianExpTreeCreated == true) return m_LagrangianExpTree;
    // we calculate the Lagrangian for all the objectives and constraints
    // with nonlinear terms
    // first initialize everything for nonlinear work
    if(m_bSparseJacobianCalculated == false) getJacobianSparsityPattern( );
    std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
    OSnLNodeTimes* nlNodeTimes = NULL;
    OSnLNodeVariable* nlNodeVariable = NULL;
    OSnLNodeSum* nlNodeSum = NULL;
    int numChildren = 0;
    int rowIdx;
    // create the sum node
    nlNodeSum = new OSnLNodeSum();
    nlNodeSum->inumberOfChildren = m_mapExpressionTreesMod.size();
    nlNodeSum->m_mChildren = new ExprNode*[ nlNodeSum->inumberOfChildren];
    // create an expression tree for the sum node
    m_LagrangianExpTree = new RealValuedExpressionTree();
    m_LagrangianExpTree->m_treeRoot = nlNodeSum;
    // now create the children of the sum node
    for(posMapExpTree  = m_mapExpressionTreesMod.begin(); 
        posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
    {
        // this variable is the Lagrange multiplier
        nlNodeVariable = new OSnLNodeVariable();
        nlNodeVariable->coef = 1.;
        // get the correct index --
        // for rowIdx = 0, ..., m - 1 set idx = numVar + rowIdx
        rowIdx = posMapExpTree->first;
        if(rowIdx >= 0)
        {
            nlNodeVariable->idx = instanceData->variables->numberOfVariables + rowIdx;
        }
        else
        {
            nlNodeVariable->idx = instanceData->variables->numberOfVariables +
                                  instanceData->constraints->numberOfConstraints + (abs(rowIdx) - 1);
        }

        // now create a times multiply the new variable times the root of the expression tree
        nlNodeTimes = new OSnLNodeTimes();
        nlNodeTimes->m_mChildren[ 0] = nlNodeVariable;
        nlNodeTimes->m_mChildren[ 1]
                = ((OSnLNode*)m_mapExpressionTreesMod[ posMapExpTree->first ]->m_treeRoot);
        // the times node is the new child
        nlNodeSum->m_mChildren[ numChildren] = nlNodeTimes;
        numChildren++;
    }
    // get a variable index map for the expression tree
    m_LagrangianExpTree->getVariableIndicesMap();
    m_bLagrangianExpTreeCreated = true;
    return m_LagrangianExpTree;
}//getLagrangianExpTree

std::map<int, int> OSInstance::getAllNonlinearVariablesIndexMap( )
{
    std::ostringstream outStr;

    if(m_bAllNonlinearVariablesIndex == true) return m_mapAllNonlinearVariablesIndex;
    // loop over the map of expression tree and get a unique listing of all variables
    // put these in the map m_mapAllNonlinearVariablesIndex
    std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
    std::map<int, int>::iterator posVarIdx;
    RealValuedExpressionTree *expTree;
    for(posMapExpTree  = m_mapExpressionTreesMod.begin(); 
        posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
    {
        // get the index map for the expression tree

        expTree = posMapExpTree->second;
        if(expTree->m_bIndexMapGenerated == false)expTree->getVariableIndicesMap();
        for(posVarIdx = (*expTree->mapVarIdx).begin(); posVarIdx != (*expTree->mapVarIdx).end(); ++posVarIdx)
        {
            if( m_mapAllNonlinearVariablesIndex.find( posVarIdx->first) == m_mapAllNonlinearVariablesIndex.end() )
            {
                // add the variable to the Lagragian map
                m_mapAllNonlinearVariablesIndex[ posVarIdx->first] = 1;
            }
        }
    }
    m_miNonLinearVarsReverseMap = new int[m_mapAllNonlinearVariablesIndex.size()];
    // now order appropriately
    int kount = 0;
    for(posVarIdx = m_mapAllNonlinearVariablesIndex.begin(); posVarIdx !=m_mapAllNonlinearVariablesIndex.end(); ++posVarIdx)
    {
        posVarIdx->second = kount;
        m_miNonLinearVarsReverseMap[ kount] = posVarIdx->first;
        kount++;
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr <<  "POSITION FIRST =  "  << posVarIdx->first ;
        outStr <<  "   POSITION SECOND = "  << posVarIdx->second << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    }
    m_iNumberOfNonlinearVariables = kount;
    m_bAllNonlinearVariablesIndex = true;
    return m_mapAllNonlinearVariablesIndex;
}//getAllNonlinearVariablesIndexMap

SparseHessianMatrix* OSInstance::getLagrangianHessianSparsityPattern( )
{
    std::ostringstream outStr;

    // fill in the nonzeros in the sparse Hessian
    if( m_bLagrangianSparseHessianCreated == true) return m_LagrangianSparseHessian;
    if( m_iNumberOfNonlinearVariables == 0) return NULL;
    if( m_binitForAlgDiff == false ) initForAlgDiff();
    unsigned int i = 0;
    unsigned int j;
    int numNonz = 0;
    // Create the CppAD function if necessary
    //
    std::vector<double> vx;
    std::map<int, int>::iterator posMap1, posMap2;
    if( (m_bOSADFunIsCreated == false || m_bCppADMustReTape == true )  && 
        (m_mapExpressionTreesMod.size() > 0) )
    {
        for(posMap1 = m_mapAllNonlinearVariablesIndex.begin(); posMap1 != m_mapAllNonlinearVariablesIndex.end(); ++posMap1)
        {
            vx.push_back( 1.0) ;
        }
        createOSADFun( vx);
    }

    // note this function call also fills in m_vbLagHessNonz
    numNonz = getADSparsityHessian();

    i = 0;
    // now that we have the dimension create SparseHessianMatrix (upper triangular)
    m_LagrangianSparseHessian = new SparseHessianMatrix();
    m_LagrangianSparseHessian->bDeleteArrays = true;
    m_LagrangianSparseHessian->hessDimension = numNonz;
    m_LagrangianSparseHessian->hessRowIdx = new int[m_LagrangianSparseHessian->hessDimension];
    m_LagrangianSparseHessian->hessColIdx = new int[m_LagrangianSparseHessian->hessDimension];
    m_LagrangianSparseHessian->hessValues = new double[m_LagrangianSparseHessian->hessDimension];
    numNonz = 0;
    for(posMap1 = m_mapAllNonlinearVariablesIndex.begin(); posMap1 != m_mapAllNonlinearVariablesIndex.end(); ++posMap1)
    {
        j = i;
        for(posMap2 = posMap1; posMap2 != m_mapAllNonlinearVariablesIndex.end(); ++posMap2)
        {
            if(m_vbLagHessNonz[ i*m_iNumberOfNonlinearVariables + j] == true)
            {
                *(m_LagrangianSparseHessian->hessRowIdx + numNonz) = posMap1->first;
                *(m_LagrangianSparseHessian->hessColIdx + numNonz) = posMap2->first;
                numNonz++;
            }
            j++;
        }
        i++;
    }
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "HESSIAN SPARSITY PATTERN" << std::endl;
    int kj;
    for(kj = 0; kj < m_LagrangianSparseHessian->hessDimension; kj++)
    {
        outStr <<  "Row Index = " << *(m_LagrangianSparseHessian->hessRowIdx + kj) << std::endl;
        outStr <<  "Column Index = " << *(m_LagrangianSparseHessian->hessColIdx + kj) << std::endl;
    }
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    //
    m_bLagrangianSparseHessianCreated = true;
    return m_LagrangianSparseHessian;
}//getLagrangianHessianSparsityPattern


void OSInstance::duplicateExpressionTreesMap()
{
    // we do this so that we can keep the integrity of the original formulation
    if(m_bDuplicateExpressionTreesMap == false)
    {
        // first make sure the map was created
        if( m_bProcessExpressionTrees == false) getAllNonlinearExpressionTrees();
        m_mapExpressionTreesMod = m_mapExpressionTrees;
        m_bDuplicateExpressionTreesMap = true;
        return;
    }
    else
    {
        return;
    }
}//duplicateExpressionTreesMap


bool OSInstance::getIterateResults( double *x, double *objLambda, double* conMultipliers,
                                    bool new_x, int highestOrder)
{
    try
    {
        if( m_binitForAlgDiff == false) initForAlgDiff();
        std::map<int, int>::iterator posVarIndexMap;

        if(new_x == true)
        {
            if( m_vdX.size() > 0) m_vdX.clear();
            for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap)
            {
                m_vdX.push_back( x[ posVarIndexMap->first]) ;
            }
            if( (m_bOSADFunIsCreated == false || m_bCppADMustReTape == true )  &&
                (m_mapExpressionTreesMod.size() > 0) )
            {
                createOSADFun( m_vdX);
            }
        }
        else  // make sure vector not empty -- this could happen if we have linear obj and nonlinear constraints

        {
            if( m_vdX.size() == 0)
            {
                for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap)
                {
                    m_vdX.push_back( x[ posVarIndexMap->first]) ;
                }
                if( (m_bOSADFunIsCreated == false || m_bCppADMustReTape == true )  &&
                    (m_mapExpressionTreesMod.size() > 0) )
                {
                    createOSADFun( m_vdX);
                }
            }
        }
        switch( highestOrder)
        {
        case 0:
            if(new_x == true || m_iHighestOrderEvaluated < 0)
            {
                if(bUseExpTreeForFunEval == true)
                {
                    calculateAllConstraintFunctionValues( x, new_x);
                    calculateAllObjectiveFunctionValues( x, new_x);
                }
                else
                {
                    getZeroOrderResults(x, objLambda, conMultipliers);
                }

            }
            break;
        case 1:
            if(new_x == true || m_iHighestOrderEvaluated < 0)
                getZeroOrderResults(x, objLambda, conMultipliers);
            if(new_x == true || m_iHighestOrderEvaluated < 1)
                getFirstOrderResults(x, objLambda, conMultipliers);
            break;
        case 2:
            if(new_x == true || m_iHighestOrderEvaluated < 0)
                getZeroOrderResults(x, objLambda, conMultipliers);
            if(new_x == true || m_iHighestOrderEvaluated < 2)
                getSecondOrderResults(x, objLambda, conMultipliers);
            break;
        default:
            throw ErrorClass("Derivative should be order 0, 1, or 2");
        }//end switch
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end getIterateResults


bool OSInstance::getZeroOrderResults(double *x, double *objLambda, double *conMultipliers)
{
    std::ostringstream outStr;

    try
    {
        // initialize everything
        int i, j, rowNum, objNum;
        if( m_mapExpressionTreesMod.size() > 0)
        {
            m_vdYval = this->forwardAD(0, m_vdX);
        }
        // now get all function and constraint values using forward result
        for(rowNum = 0; rowNum < m_iConstraintNumber; rowNum++)
        {
            m_mdConstraintFunctionValues[ rowNum] = 0.0;
            if( m_mapExpressionTreesMod.find( rowNum) != m_mapExpressionTreesMod.end() )
            {
                m_mdConstraintFunctionValues[ rowNum] = m_vdYval[  m_mapOSADFunRangeIndex[ rowNum]];
            }
            // now the linear part
            // be careful, loop over only the constant terms in sparseJacMatrix
            i = m_sparseJacMatrix->starts[ rowNum];
            j = m_sparseJacMatrix->starts[ rowNum + 1 ];
            while ( (i - m_sparseJacMatrix->starts[ rowNum])  < m_sparseJacMatrix->conVals[ rowNum] )
            {
                m_mdConstraintFunctionValues[ rowNum] += m_sparseJacMatrix->values[ i]*x[ m_sparseJacMatrix->indexes[ i] ];
                i++;
            }
            // add in the constraint function constant
            m_mdConstraintFunctionValues[ rowNum] += m_mdConstraintConstants[ rowNum ];
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Constraint " <<  rowNum << " function value =  " << m_mdConstraintFunctionValues[ rowNum ] << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        }
        // now get the objective function values from the forward result
        for(objNum = 0; objNum < m_iObjectiveNumber; objNum++)
        {
            m_mdObjectiveFunctionValues[ objNum] = 0.0;
            if( m_mapExpressionTreesMod.find( -objNum -1) != m_mapExpressionTreesMod.end() )
            {
                m_mdObjectiveFunctionValues[ objNum] = m_vdYval[ objNum];
            }
            for(i = 0; i < m_iVariableNumber; i++)
            {
                m_mdObjectiveFunctionValues[ objNum] += m_mmdDenseObjectiveCoefficients[ objNum][i]*x[ i];
            }
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Objective " << objNum << " function value =  " << m_mdObjectiveFunctionValues[ objNum] << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        }
        return true;
    }//end try
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end getZeroOrderResults


bool OSInstance::getFirstOrderResults(double *x, double *objLambda, double *conMultipliers)
{
    std::ostringstream outStr;

    try
    {
        // initialize everything
        unsigned int i, j;
        int rowNum,  jacIndex;
        unsigned int jstart, jend;
        int idx;
        RealValuedExpressionTree *expTree = NULL;
        int domainIdx = 0;
        std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
        std::map<int, int>::iterator posVarIdx;

        /** if the number of columns exceeds the number of rows we will get the
         * Jacobian by row, however, if the number of rows exceeds the number of
         * columns we get the Jacobian by column
         */

        if(m_iNumberOfNonlinearVariables >= m_mapExpressionTreesMod.size() )
        {
            // calculate the gradient by doing a reverse sweep over each row
            // loop over the constraints that have a nonlinear term and get their gradients
            for(posMapExpTree  = m_mapExpressionTreesMod.begin();
                posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
            {
                idx = posMapExpTree->first;
                // we are considering only constraints, not objective function
                if(idx >= 0)
                {
                    m_vdRangeUnitVec[ domainIdx] = 1.;
                    m_mapExpressionTreesMod[ idx]->getVariableIndicesMap();
                    m_vdYjacval = this->reverseAD(1, m_vdRangeUnitVec);
                    // check size
                    jstart = m_miJacStart[ idx] + m_miJacNumConTerms[ idx];
                    jend = m_miJacStart[ idx + 1 ];
                    if( (*m_mapExpressionTreesMod[ idx]->mapVarIdx).size() != (jend - jstart)) throw
                        ErrorClass("number of partials not consistent");
                    j = 0;
                    jacIndex = 0;
                    for(posVarIdx = m_mapAllNonlinearVariablesIndex.begin(); posVarIdx
                            != m_mapAllNonlinearVariablesIndex.end(); ++posVarIdx)
                    {
                        // we are working with variable posVarIdx->first in the original variable space
                        // we need to see which variable this is in the individual constraint map
                        if( (*m_mapExpressionTreesMod[ idx]->mapVarIdx).find( posVarIdx->first) !=
                            (*m_mapExpressionTreesMod[ idx]->mapVarIdx).end())
                        {
                            m_mdJacValue[ jstart] = m_vdYjacval[ jacIndex];
                            jstart++;
                            j++;
                        }
                        jacIndex++;
                    }

                    m_vdRangeUnitVec[ domainIdx] = 0.;
                    domainIdx++;
                }
                else     // we have an objective function
                {
                    domainIdx++;
                }
            }
        }
        else
        {
            // calculate the gradients using a forward sweep over all the variables.
            for(i = 0; i < m_iNumberOfNonlinearVariables; i++)
            {
                m_vdDomainUnitVec[i] = 1.;
                rowNum = 0;
                if( m_mapExpressionTreesMod.size() > 0)
                {
                    m_vdYjacval = this->forwardAD(1, m_vdDomainUnitVec);
                }
                // fill in Jacobian here, we have column i
                // start Jacobian calculation
                for(posMapExpTree  = m_mapExpressionTreesMod.begin();
                    posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
                {
                    idx = posMapExpTree->first;
                    // we are considering only constraints, not objective function
                    if(idx >= 0)
                    {
                        //figure out original variable this corresponds to
                        //then use (*m_mapExpressionTreesMod[ idx]->mapVarIdx) to figure out which variable it is within row idx
                        //m_mapAllNonlinearVariablesIndex
                        expTree = m_mapExpressionTreesMod[ idx];
                        if( (*expTree->mapVarIdx).find( m_miNonLinearVarsReverseMap[ i]) != (*expTree->mapVarIdx).end()  )
                        {
                            jacIndex = (*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ m_miNonLinearVarsReverseMap[ i]];
                            jstart = m_miJacStart[ idx] + m_miJacNumConTerms[ idx];
                            // kipp change 1 to number of objective functions
                            m_mdJacValue[ jstart + jacIndex] = m_vdYjacval[m_iObjectiveNumberNonlinear + rowNum];
                        }
                        rowNum++;
                    }//end Jacobian calculation
                }
                //
                m_vdDomainUnitVec[i] = 0.;
            }
        }
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        int k;
        outStr  << "JACOBIAN DATA " << std::endl;
        for(idx = 0; idx < m_iConstraintNumber; idx++)
        {
            for(k = *(m_sparseJacMatrix->starts + idx); k < *(m_sparseJacMatrix->starts + idx + 1); k++)
            {
                outStr << "row idx = " << idx <<  "  col idx = "<< *(m_sparseJacMatrix->indexes + k)
                          << " value = " << *(m_sparseJacMatrix->values + k) << std::endl;
            }
        }
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        return true;
    }//end try
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end getFirstOrderResults


bool OSInstance::getSecondOrderResults(double *x, double *objLambda, double *conMultipliers)
{
    std::ostringstream outStr;

    try
    {
        // initialize everything
        unsigned int i, j;
        int rowNum,  jacIndex;
        int jstart,  idx;
        RealValuedExpressionTree *expTree = NULL;
        int hessValuesIdx = 0;
        if( m_bLagrangianSparseHessianCreated == false) getLagrangianHessianSparsityPattern( );
        std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
        std::map<int, int>::iterator posVarIndexMap;
        if( objLambda == NULL) throw ErrorClass("must have a multiplier for the objective function even if zero when calling getSecondOrderResults");

        if( conMultipliers == NULL) throw ErrorClass("cannot have a null vector of lagrange multipliers when calling getSecondOrderResults -- okay if  zero");
        if( m_vdLambda.size() > 0) m_vdLambda.clear();
        for(posMapExpTree  = m_mapExpressionTreesMod.begin();
            posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
        {
            if( posMapExpTree->first >= 0)
            {
                m_vdLambda.push_back( conMultipliers[ posMapExpTree->first]);
            }
            else
            {
                // kipp correct when there is more than one obj
                m_vdLambda.push_back( objLambda[ abs(posMapExpTree->first) - 1] );
            }
        }
        for(i = 0; i < m_iNumberOfNonlinearVariables; i++)
        {
            m_vdDomainUnitVec[i] = 1.;
            rowNum = 0;
            if( m_mapExpressionTreesMod.size() > 0)
            {
                m_vdYjacval = this->forwardAD(1, m_vdDomainUnitVec);
            }
            // fill in Jacobian here, we have column i
            // start Jacobian calculation
            for(posMapExpTree  = m_mapExpressionTreesMod.begin();
                posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
            {
                idx = posMapExpTree->first;
                // we are considering only constraints, not objective function
                if(idx >= 0)
                {
                    //figure out original variable this corresponds to
                    //then use (*m_mapExpressionTreesMod[ idx]->mapVarIdx) 
                    //to figure out which variable it is within row idx
                    //m_mapAllNonlinearVariablesIndex
                    expTree = m_mapExpressionTreesMod[ idx];
                    if( (*expTree->mapVarIdx).find( m_miNonLinearVarsReverseMap[ i]) != 
                        (*expTree->mapVarIdx).end()  )
                    {
                        jacIndex = (*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ m_miNonLinearVarsReverseMap[ i]];
                        jstart = m_miJacStart[ idx] + m_miJacNumConTerms[ idx];
                        m_mdJacValue[ jstart + jacIndex] = m_vdYjacval[m_iObjectiveNumberNonlinear + rowNum];
                    }
                    rowNum++;
                }//end Jacobian calculation
                else
                {
                    // see if we have the objective function of interest
                    //kipp fix if more than one obj
                    m_mmdObjGradient[  (abs( idx) - 1)][ m_miNonLinearVarsReverseMap[ i]] = m_vdYjacval[ (abs( idx) - 1)] +
                            m_mmdDenseObjectiveCoefficients[  (abs( idx) - 1)][ m_miNonLinearVarsReverseMap[ i]];
                }//end Obj gradient calculation
            }
            // now calculate the Hessian
            if( m_mapExpressionTreesMod.size() > 0)
            {
                m_vdw = reverseAD(2, m_vdLambda);   // derivative of partial
            }
            for(j = i; j < m_iNumberOfNonlinearVariables; j++)
            {
                if( m_vbLagHessNonz[i*m_iNumberOfNonlinearVariables + j] == true)
                {
                    m_LagrangianSparseHessian->hessValues[ hessValuesIdx] =  m_vdw[  j*2 + 1];
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "reverse 2 " << m_LagrangianSparseHessian->hessValues[ hessValuesIdx] << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                    hessValuesIdx++;
                }
            }
            //
            //
            m_vdDomainUnitVec[i] = 0.;
        }
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        int k;
        outStr  << "JACOBIAN DATA " << std::endl;
        for(idx = 0; idx < m_iConstraintNumber; idx++)
        {
            for(k = *(m_sparseJacMatrix->starts + idx); k < *(m_sparseJacMatrix->starts + idx + 1); k++)
            {
                outStr << "row idx = " << idx <<  "  col idx = "<< *(m_sparseJacMatrix->indexes + k)
                          << " value = " << *(m_sparseJacMatrix->values + k) << std::endl;
            }
        }
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        return true;
    }//end try
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end getSecondOrderResults

bool OSInstance::initForAlgDiff()
{
    std::ostringstream outStr;

    if( m_binitForAlgDiff == true ) return true;
    initializeNonLinearStructures( );
    initObjGradients();
    getAllNonlinearVariablesIndexMap( );
    //if(m_bSparseJacobianCalculated  == false) getJacobianSparsityPattern();
    //see if we need to retape
    //loop over expression tree and see if one requires it
    std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
    for(posMapExpTree  = m_mapExpressionTreesMod.begin();
        posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
    {
        if(posMapExpTree->second->bADMustReTape == true) m_bCppADMustReTape = true;
    }

#ifndef NDEBUG
    outStr << "RETAPE ==  " << m_bCppADMustReTape << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    unsigned int i;
    for(i = 0; i < m_iNumberOfNonlinearVariables; i++)
    {
        m_vdDomainUnitVec.push_back( 0.0 );
    }
    for(i = 0; i < m_mapExpressionTreesMod.size(); i++)
    {
        m_vdRangeUnitVec.push_back( 0.0 );
    }
    m_binitForAlgDiff = true;
    //m_bSparseJacobianCalculated = true;
    //m_bProcessExpressionTrees = true;
    return true;
}//end initForAlgDiff

bool OSInstance::initObjGradients()
{
    std::ostringstream outStr;

    int i, j;
    int m, n;
    m = getObjectiveNumber();
    n = getVariableNumber();
    getDenseObjectiveCoefficients();
    if(m <= 0)
    {
        m_mmdObjGradient = NULL;
        return true;
    }
    m_mmdObjGradient = new double*[m];
    for(i = 0; i < m; i++)
    {
        m_mmdObjGradient[i] = new double[n];
        for(j = 0; j < n; j++)
        {
            m_mmdObjGradient[i][j] =  m_mmdDenseObjectiveCoefficients[ i][j];
#ifndef NDEBUG
            outStr << "m_mmdObjGradient[i][j] = " << m_mmdObjGradient[i][j]  << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        }
    }
    return true;
}//end initObjGradients
/**
 * end revised AD test code
 */

/**
 * set methods for matrices object
 */

/**
 * set methods for cones object
 */

/**
 * set methods for timeDomain object
 */
bool OSInstance::setTimeDomain(std::string format)
{
    if ((format != "stages") && (format != "interval") && (format != "none"))
        return false;
    if (instanceData->timeDomain == NULL)
    {
        instanceData->timeDomain = new TimeDomain();
    }
    if (format == "stages")
    {
        if (instanceData->timeDomain->interval != NULL)
        {
            delete instanceData->timeDomain->interval;
            instanceData->timeDomain->interval = NULL;
        }
        if (instanceData->timeDomain->stages == NULL)
            instanceData->timeDomain->stages = new TimeDomainStages();
        m_sTimeDomainFormat = format;
    }
    if (format == "interval")
    {
        if (instanceData->timeDomain->stages != NULL)
        {
            delete instanceData->timeDomain->stages;
            instanceData->timeDomain->stages = NULL;
        }
        if (instanceData->timeDomain->interval == NULL)
            instanceData->timeDomain->interval = new TimeDomainInterval();
        m_sTimeDomainFormat = format;
    }
    if (format == "none")
    {
        if (instanceData->timeDomain->stages != NULL)
        {
            delete instanceData->timeDomain->stages;
            instanceData->timeDomain->stages = NULL;
        }
        if (instanceData->timeDomain->interval != NULL)
        {
            delete instanceData->timeDomain->interval;
            instanceData->timeDomain->interval = NULL;
        }
        m_sTimeDomainFormat = "";
    }
    return true;
} //end setTimeDomain

/**
 * set time domain stages
 */
bool OSInstance::setTimeDomainStages(int number, std::string *names)
{
    if (instanceData->timeDomain == NULL)
        instanceData->timeDomain = new TimeDomain();
    if (instanceData->timeDomain->interval != NULL)
        return false;
    if (instanceData->timeDomain->stages == NULL)
    {
        instanceData->timeDomain->stages = new TimeDomainStages;
    }
    else
    {
        if (instanceData->timeDomain->stages->numberOfStages != number)
        {
            for (int i = 0; i < instanceData->timeDomain->stages->numberOfStages; i++)
            {
                if (instanceData->timeDomain->stages->stage[i]->variables != NULL)
                {
                    delete instanceData->timeDomain->stages->stage[i]->variables;
                    instanceData->timeDomain->stages->stage[i]->variables = NULL;
                }
                if (instanceData->timeDomain->stages->stage[i]->constraints != NULL)
                {
                    delete instanceData->timeDomain->stages->stage[i]->constraints;
                    instanceData->timeDomain->stages->stage[i]->constraints = NULL;

                }
                if (instanceData->timeDomain->stages->stage[i]->objectives != NULL)
                {
                    delete instanceData->timeDomain->stages->stage[i]->objectives;
                    instanceData->timeDomain->stages->stage[i]->objectives = NULL;
                }
                delete instanceData->timeDomain->stages->stage[i];
                instanceData->timeDomain->stages->stage[i] = NULL;
            }
            delete []instanceData->timeDomain->stages->stage;
            instanceData->timeDomain->stages->stage = NULL;
        }
    }
    if (number != 0 )
    {
        if (instanceData->timeDomain->stages->stage == NULL)
            instanceData->timeDomain->stages->stage = new TimeDomainStage*[number];
        for (int i = 0; i < number; i++)
        {
            instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
        }
        instanceData->timeDomain->stages->numberOfStages = number;
    }
    for (int i = 0; i < number; i++)
        //initial or empty vars, cons, objectives and set default to all objectives
    {
        if (instanceData->timeDomain->stages->stage[i]->variables != NULL)
        {
            delete instanceData->timeDomain->stages->stage[i]->variables;
            instanceData->timeDomain->stages->stage[i]->variables = NULL;
        }
        instanceData->timeDomain->stages->stage[i]->variables = new TimeDomainStageVariables();
        if (instanceData->timeDomain->stages->stage[i]->constraints != NULL)
        {
            delete instanceData->timeDomain->stages->stage[i]->constraints;
            instanceData->timeDomain->stages->stage[i]->constraints = NULL;
        }
        instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
        if (instanceData->timeDomain->stages->stage[i]->objectives != NULL)
        {
            delete instanceData->timeDomain->stages->stage[i]->objectives;
            instanceData->timeDomain->stages->stage[i]->objectives = NULL;
        }
        instanceData->timeDomain->stages->stage[i]->objectives = new TimeDomainStageObjectives();
        instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives = instanceData->objectives->numberOfObjectives;
        instanceData->timeDomain->stages->stage[i]->objectives->obj = new TimeDomainStageObj*[instanceData->objectives->numberOfObjectives];
        for (int j = 0; j < instanceData->objectives->numberOfObjectives; j++)
        {
            instanceData->timeDomain->stages->stage[i]->objectives->obj[j] = new TimeDomainStageObj();
            instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx = -(j+1);
        }
        if (names != NULL)
            instanceData->timeDomain->stages->stage[i]->name = names[i];
    }
    return true;
} //end setTimeDomainStages

/**
 * set time domain stage variables in temporal order
 */
bool OSInstance::setTimeDomainStageVariablesOrdered(int numberOfStages, int *numberOfVariables, int *startIdx)
{
    if (instanceData->timeDomain == NULL)
        instanceData->timeDomain = new TimeDomain();
    if (instanceData->timeDomain->interval != NULL)
        return false;
    if (instanceData->timeDomain->stages == NULL)
        instanceData->timeDomain->stages = new TimeDomainStages();
    if (instanceData->timeDomain->stages != NULL)
    {
        if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
                (instanceData->timeDomain->stages->numberOfStages != 0))
            return false;
    }
    if (instanceData->timeDomain->stages->numberOfStages == 0)
    {
        instanceData->timeDomain->stages->numberOfStages = numberOfStages;
        if (instanceData->timeDomain->stages->stage == NULL)
            instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
        for (int i = 0; i < numberOfStages; i++)
            instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
    }
    int checksum = 0;
    for (int i = 0; i < numberOfStages; i++)
        //initial or empty vars, cons, objectives and set default to all objectives
    {
        if (instanceData->timeDomain->stages->stage[i]->variables != NULL)
        {
            delete instanceData->timeDomain->stages->stage[i]->variables;
            instanceData->timeDomain->stages->stage[i]->variables = NULL;
        }
        instanceData->timeDomain->stages->stage[i]->variables = new TimeDomainStageVariables();
        instanceData->timeDomain->stages->stage[i]->variables->startIdx = startIdx[i];
        instanceData->timeDomain->stages->stage[i]->variables->numberOfVariables = numberOfVariables[i];
        checksum += numberOfVariables[i];
    }
    return (checksum == instanceData->variables->numberOfVariables);
} //end setTimeDomainVariablesOrdered

/**
 * set time domain stage variables in arbitrary order
 */
bool OSInstance::setTimeDomainStageVariablesUnordered(int numberOfStages, int *numberOfVariables, int **varIndex)
{
    if (instanceData->timeDomain == NULL)
        instanceData->timeDomain = new TimeDomain();
    if (instanceData->timeDomain->interval != NULL)
        return false;
    if (instanceData->timeDomain->stages == NULL)
        instanceData->timeDomain->stages = new TimeDomainStages();
    if (instanceData->timeDomain->stages != NULL)
    {
        if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
                (instanceData->timeDomain->stages->numberOfStages != 0))
            return false;
    }
    if (instanceData->timeDomain->stages->numberOfStages == 0 )
    {
        instanceData->timeDomain->stages->numberOfStages = numberOfStages;
        if (instanceData->timeDomain->stages->stage == NULL)
            instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
        for (int i = 0; i < numberOfStages; i++)
            instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
    }
    int checksum = 0;
    for (int i = 0; i < numberOfStages; i++)
        //initial or empty vars, cons, objectives and set default to all objectives
    {
        if (instanceData->timeDomain->stages->stage[i]->variables != NULL)
        {
            delete instanceData->timeDomain->stages->stage[i]->variables;
            instanceData->timeDomain->stages->stage[i]->variables = NULL;
        }
        instanceData->timeDomain->stages->stage[i]->variables = new TimeDomainStageVariables();
        instanceData->timeDomain->stages->stage[i]->variables->numberOfVariables = numberOfVariables[i];
        instanceData->timeDomain->stages->stage[i]->variables->var = new TimeDomainStageVar*[numberOfVariables[i]];
        for (int j = 0; j < numberOfVariables[i]; j++)
        {
            instanceData->timeDomain->stages->stage[i]->variables->var[j] = new TimeDomainStageVar();
            instanceData->timeDomain->stages->stage[i]->variables->var[j]->idx = varIndex[i][j];
        }
        checksum += numberOfVariables[i];
    }
    if (checksum != instanceData->variables->numberOfVariables) return false;
    int *checkvar = new int[instanceData->variables->numberOfVariables];
    for (int j = 0; j < instanceData->variables->numberOfVariables; j++)
        checkvar[j] = -1;
    int k;
    for (int i = 0; i < numberOfStages; i++)
        for (int j = 0; j < instanceData->timeDomain->stages->stage[i]->variables->numberOfVariables; j++)
        {
            k = instanceData->timeDomain->stages->stage[i]->variables->var[j]->idx;
            if (checkvar[k] != -1)
            {
                delete [] checkvar;
                checkvar = NULL;
                return false;
            }
            checkvar[k] = instanceData->timeDomain->stages->stage[i]->variables->var[j]->idx;
        }
    delete [] checkvar;
    checkvar = NULL;
    return true;
} //end setTimeDomainVariablesUnordered

/**
 * set time domain stage constraints in temporal order
 */
bool OSInstance::setTimeDomainStageConstraintsOrdered(int numberOfStages, int *numberOfConstraints, int *startIdx)
{
    if (instanceData->timeDomain == NULL)
        instanceData->timeDomain = new TimeDomain();
    if (instanceData->timeDomain->interval != NULL)
        return false;
    if (instanceData->timeDomain->stages == NULL)
        instanceData->timeDomain->stages = new TimeDomainStages();
    if (instanceData->timeDomain->stages != NULL)
    {
        if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
                (instanceData->timeDomain->stages->numberOfStages != 0))
            return false;
    }
    if (instanceData->timeDomain->stages->numberOfStages == 0 )
    {
        instanceData->timeDomain->stages->numberOfStages = numberOfStages;
        if (instanceData->timeDomain->stages->stage == NULL)
            instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
        for (int i = 0; i < numberOfStages; i++)
            instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
    }
    int checksum = 0;
    for (int i = 0; i < numberOfStages; i++)
        //initial or empty vars, cons, objectives and set default to all objectives
    {
        if (instanceData->timeDomain->stages->stage[i]->constraints != NULL)
        {
            delete instanceData->timeDomain->stages->stage[i]->constraints;
            instanceData->timeDomain->stages->stage[i]->constraints = NULL;
        }
        instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
        instanceData->timeDomain->stages->stage[i]->constraints->startIdx = startIdx[i];
        instanceData->timeDomain->stages->stage[i]->constraints->numberOfConstraints = numberOfConstraints[i];
        checksum += numberOfConstraints[i];
    }
    return (checksum == instanceData->constraints->numberOfConstraints);
} // end of setTimeStageConstraintsOrdered

/**
 * set time domain stage constraints in arbitrary order
 */
bool OSInstance::setTimeDomainStageConstraintsUnordered(int numberOfStages, int *numberOfConstraints, int **conIndex)
{
    if (instanceData->timeDomain == NULL)
        instanceData->timeDomain = new TimeDomain();
    if (instanceData->timeDomain->interval != NULL)
        return false;
    if (instanceData->timeDomain->stages == NULL)
        instanceData->timeDomain->stages = new TimeDomainStages();
    if (instanceData->timeDomain->stages != NULL)
    {
        if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
                (instanceData->timeDomain->stages->numberOfStages != 0))
            return false;
    }
    if ( instanceData->timeDomain->stages->numberOfStages == 0 )
    {
        instanceData->timeDomain->stages->numberOfStages = numberOfStages;
        if (instanceData->timeDomain->stages->stage == NULL)
            instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
        for (int i = 0; i < numberOfStages; i++)
            instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
    }
    int checksum = 0;
    for (int i = 0; i < numberOfStages; i++)
        //initial or empty vars, cons, objectives and set default to all objectives
    {
        if (instanceData->timeDomain->stages->stage[i]->constraints != NULL)
        {
            delete instanceData->timeDomain->stages->stage[i]->constraints;
            instanceData->timeDomain->stages->stage[i]->constraints = NULL;
        }
        instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
        instanceData->timeDomain->stages->stage[i]->constraints->numberOfConstraints = numberOfConstraints[i];
        instanceData->timeDomain->stages->stage[i]->constraints->con = new TimeDomainStageCon*[numberOfConstraints[i]];
        for (int j = 0; j < numberOfConstraints[i]; j++)
        {
            instanceData->timeDomain->stages->stage[i]->constraints->con[j] = new TimeDomainStageCon();
            instanceData->timeDomain->stages->stage[i]->constraints->con[j]->idx = conIndex[i][j];
        }
        checksum += numberOfConstraints[i];
    }
    if (checksum != instanceData->constraints->numberOfConstraints) return false;
    int *checkvar = new int[instanceData->constraints->numberOfConstraints];
    for (int j = 0; j < instanceData->constraints->numberOfConstraints; j++)
        checkvar[j] = -1;
    int k;
    for (int i = 0; i < numberOfStages; i++)
        for (int j = 0; j < instanceData->timeDomain->stages->stage[i]->constraints->numberOfConstraints; j++)
        {
            k = instanceData->timeDomain->stages->stage[i]->constraints->con[j]->idx;
            if (checkvar[k] != -1)
            {
                delete [] checkvar;
                checkvar = NULL;
                return false;
            }
            checkvar[k] = instanceData->timeDomain->stages->stage[i]->constraints->con[j]->idx;
        }
    delete [] checkvar;
    checkvar = NULL;
    return true;
}// end setTimeDomainStageConstraintsUnordered()

/**
 * set time domain stage objectives in temporal order
 */
bool OSInstance::setTimeDomainStageObjectivesOrdered(int numberOfStages, int *numberOfObjectives, int *startIdx)
{
    if (instanceData->timeDomain == NULL)
        instanceData->timeDomain = new TimeDomain();
    if (instanceData->timeDomain->interval != NULL)
        return false;
    if (instanceData->timeDomain->stages == NULL)

        instanceData->timeDomain->stages = new TimeDomainStages();
    if (instanceData->timeDomain->stages != NULL)
    {
        if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
                (instanceData->timeDomain->stages->numberOfStages != 0))
            return false;
    }
    if (instanceData->timeDomain->stages->numberOfStages == 0)

    {
        instanceData->timeDomain->stages->numberOfStages = numberOfStages;
        if (instanceData->timeDomain->stages->stage == NULL)
            instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
        for (int i = 0; i < numberOfStages; i++)
            instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
    }
    for (int i = 0; i < numberOfStages; i++)
        //initial or empty vars, cons, objectives and set default to all objectives
    {

        if (instanceData->timeDomain->stages->stage[i]->objectives != NULL)
        {
            delete instanceData->timeDomain->stages->stage[i]->objectives;
            instanceData->timeDomain->stages->stage[i]->objectives = NULL;
        }
        instanceData->timeDomain->stages->stage[i]->objectives = new TimeDomainStageObjectives();
        instanceData->timeDomain->stages->stage[i]->objectives->startIdx = startIdx[i];
        instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives = numberOfObjectives[i];
    }
    return true;
}

/**
 * set time domain stage objectives in arbitrary order
 */
bool OSInstance::setTimeDomainStageObjectivesUnordered(int numberOfStages, int *numberOfObjectives, int **objIndex)
{
    if (instanceData->timeDomain == NULL)
        instanceData->timeDomain = new TimeDomain();
    if (instanceData->timeDomain->interval != NULL)
        return false;
    if (instanceData->timeDomain->stages == NULL)
        instanceData->timeDomain->stages = new TimeDomainStages();
    if (instanceData->timeDomain->stages != NULL)
    {
        if ((instanceData->timeDomain->stages->numberOfStages != numberOfStages) &&
                (instanceData->timeDomain->stages->numberOfStages != 0))
            return false;
    }
    if (instanceData->timeDomain->stages->numberOfStages == 0)
    {
        instanceData->timeDomain->stages->numberOfStages = numberOfStages;
        if (instanceData->timeDomain->stages->stage == NULL)
            instanceData->timeDomain->stages->stage = new TimeDomainStage*[numberOfStages];
        for (int i = 0; i < numberOfStages; i++)
            instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
    }
    for (int i = 0; i < numberOfStages; i++)
        //initial or empty vars, cons, objectives and set default to all objectives
    {
        if (instanceData->timeDomain->stages->stage[i]->objectives != NULL)
        {
            delete instanceData->timeDomain->stages->stage[i]->objectives;
            instanceData->timeDomain->stages->stage[i]->objectives = NULL;
        }
        instanceData->timeDomain->stages->stage[i]->objectives = new TimeDomainStageObjectives();
        instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives = numberOfObjectives[i];
        instanceData->timeDomain->stages->stage[i]->objectives->obj = new TimeDomainStageObj*[numberOfObjectives[i]];
        for (int j = 0; j < numberOfObjectives[i]; j++)
        {
            instanceData->timeDomain->stages->stage[i]->objectives->obj[j] = new TimeDomainStageObj();
            instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx = objIndex[i][j];
        }
    }
    int *checkvar = new int[instanceData->objectives->numberOfObjectives];
    for (int j = 0; j < instanceData->objectives->numberOfObjectives; j++)
        checkvar[j] = 0;
    int k;
    for (int i = 0; i < numberOfStages; i++)
        for (int j = 0; j < instanceData->timeDomain->stages->stage[i]->objectives->numberOfObjectives; j++)
        {
            k = -instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx-1;
            checkvar[k] = instanceData->timeDomain->stages->stage[i]->objectives->obj[j]->idx;
        }
    for (int i = 0; i < instanceData->objectives->numberOfObjectives; i++)
        if (checkvar[i] == 0)
        {
            delete [] checkvar;
            checkvar = NULL;
            return false;
        }
    delete [] checkvar;
    checkvar = NULL;
    return true;
}

/**
 * set time domain interval
 */
bool OSInstance::setTimeDomainInterval(double start, double horizon)
{
    if (instanceData->timeDomain == NULL)
        instanceData->timeDomain = new TimeDomain();
    if (instanceData->timeDomain->stages != NULL)
        return false;
    if (instanceData->timeDomain->interval == NULL)
        instanceData->timeDomain->interval = new TimeDomainInterval();
    instanceData->timeDomain->interval->start = start;
    instanceData->timeDomain->interval->horizon = horizon;
    return true;
} //end setTimeDomainInterval


bool OSInstance::createOSADFun(std::vector<double> vdX)
{
    try
    {
        if(m_bOSADFunIsCreated == true) return true;
        //if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
        if(m_binitForAlgDiff == false) initForAlgDiff();

        //if( m_bAllNonlinearVariablesIndex == false) getAllNonlinearVariablesIndexMap( );
        std::map<int, RealValuedExpressionTree*>::iterator posMapExpTree;
        unsigned int i;
        size_t n = vdX.size();
#ifdef COIN_HAS_CPPAD
        // declare a CppAD vector and fill it in
        CppAD::vector< CppAD::AD<double> > vdaX( n );
        for(i = 0; i < n; i++)
        {
            vdaX[ i] = vdX[ i];
        }
        // declare the independent variables and start recording
        CppAD::Independent( vdaX);
        /**
         * For expression tree, record the operations for CppAD and put into
         * the range vector m_vFG and it is a vector of CppAD
         * objective and constraint functions.
         */
        CppAD::vector< CppAD::AD<double> > m_vFG;
        int kount = 0;
        for(posMapExpTree  = m_mapExpressionTreesMod.begin();
            posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree)
        {
            m_vFG.push_back( ((OSnLNode*)posMapExpTree->second->m_treeRoot)->constructADTape(&m_mapAllNonlinearVariablesIndex, &vdaX) );
            if( m_mapOSADFunRangeIndex.find( posMapExpTree->first) == m_mapOSADFunRangeIndex.end() )
            {
                // count which nonlinear obj/constraint this is
                m_mapOSADFunRangeIndex[ posMapExpTree->first] = kount;
                kount++;
            }
        }
        //create the function and stop recording

        Fad = new CppAD::ADFun<double>(vdaX, m_vFG);
        // no forward sweeps done yet
        m_iHighestTaylorCoeffOrder = -1;
        m_bOSADFunIsCreated = true;
#else
        throw ErrorClass( "Error: An Algorithmic Differentiation Package Not Available");
#endif

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end createOSADFun


std::vector<double> OSInstance::forwardAD(int p, std::vector<double> vdX)
{
    try
    {
        // make sure a OSADFun has been created
        if(m_bOSADFunIsCreated == false) createOSADFun( vdX);
        if(p > (m_iHighestTaylorCoeffOrder + 1) ) throw
            ErrorClass( "trying to calculate a p order forward when p-1 Taylor coefficient not available");
        // adjust the order of the Taylor coefficient
        m_iHighestTaylorCoeffOrder = p;
        m_iHighestOrderEvaluated = p;
#ifdef COIN_HAS_CPPAD
        return (*Fad).Forward(p, vdX);
#else
        throw ErrorClass( "Error: An Algorithmic Differentiation Package Not Available");
#endif

    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end forwardAD


std::vector<double> OSInstance::reverseAD(int p, std::vector<double> vdlambda)
{
    try
    {
#ifndef COIN_HAS_CPPAD
        throw ErrorClass( "Error: An Algorithmic Differentiation Package Not Available");
#endif
        if(p == 0) throw
            ErrorClass( "reverseAD must have p >= 1");
        if(p > (m_iHighestTaylorCoeffOrder + 1) ) throw
            ErrorClass( "trying to calculate a p order reverse when p-1 Taylor coefficient not available");
        m_iHighestOrderEvaluated = p;
#ifdef COIN_HAS_CPPAD
        return (*Fad).Reverse(p, vdlambda);
#endif

    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end forwardAD


int  OSInstance::getADSparsityHessian()
{
    unsigned int i;
    int numNonz;
    numNonz = 0;
    try
    {
        std::vector<bool> r(m_iNumberOfNonlinearVariables * m_iNumberOfNonlinearVariables);
        unsigned int j;
        for(i = 0; i < m_iNumberOfNonlinearVariables; i++)
        {
            for(j = 0; j < m_iNumberOfNonlinearVariables; j++)
                r[ i * m_iNumberOfNonlinearVariables + j ] = false;
            r[ i * m_iNumberOfNonlinearVariables + i] = true;
        }
        // compute sparsity pattern for J(x) = F^{(1)} (x)
        //should only be here if we have CppAD
#ifdef COIN_HAS_CPPAD
        (*Fad).ForSparseJac(m_iNumberOfNonlinearVariables, r);
#else
        throw ErrorClass( "Error: An Algorithmic Differentiation Package Not Available");
#endif
        //
        //now the second derivative
        unsigned int m = m_mapExpressionTreesMod.size();
        std::vector<bool> e( m);
        //Vector s(m);
        for(i = 0; i < m; i++) e[i] = true;
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Computing Sparse Hessian"); 
#endif
        //m_vbLagHessNonz holds the sparsity pattern Lagrangian of the Hessian
#ifdef COIN_HAS_CPPAD
        m_vbLagHessNonz = (*Fad).RevSparseHes(m_iNumberOfNonlinearVariables, e);
#endif

        for(i = 0; i < m_iNumberOfNonlinearVariables; i++)
        {
            for(j = i; j < m_iNumberOfNonlinearVariables; j++)
            {
                if(m_vbLagHessNonz[ i*m_iNumberOfNonlinearVariables + j]  == true) numNonz++;
            }
        }
        return numNonz;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end getADSparsityHessian()


/***************************************************
 * methods to print out cone objects as XML strings
 ***************************************************/
std::string Cone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<cone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    outStr << "/>" << std::endl;   
    return outStr.str();
}// end of Cone::getConeInXML()

std::string NonnegativeCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<nonnegativeCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    outStr << "/>" << std::endl;   
    return outStr.str();
}// end of NonnegativeCone::getConeInXML()

std::string NonpositiveCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<nonpositiveCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    outStr << "/>" << std::endl;   
    return outStr.str();
}// end of NonpositiveCone::getConeInXML()

std::string OrthantCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<generalOrthantCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    outStr << ">" << std::endl;
    int i = 0;
    int mult = 1;
    double ubt;
    double lbt;
    while (i < numberOfRows*numberOfColumns)
    {
        ubt = ub[i];
        lbt = lb[i];
        if (i+mult < numberOfRows*numberOfColumns && ubt == ub[i+mult] && lbt == lb[i+mult])
        {
            mult++;
        }
        else
        {
            outStr << "<direction";
            if (ubt == 0.0)
                if (lbt == 0.0)
                    outStr << " type=\"zero\"";
                else
                    outStr << " type=\"nonpositive\"";
            else if(lbt == 0.0) 
                    outStr << " type=\"nonnegative\"";
                else
                    outStr << " type=\"free\"";
            if (mult > 1)
                outStr <<" mult=\"" << mult << "\"";
            outStr << "/>";
            i += mult;
            mult = 1;
        }
    }
    outStr << "</generalOrthantCone>" << std::endl;   
    return outStr.str();
}// end of OrthantCone::getConeInXML()

std::string PolyhedralCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<polyhedralCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    outStr << " referenceMatrixIdx=\"" << referenceMatrixIdx << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    outStr << "/>" << std::endl;   
    return outStr.str();
}// end of PolyhedralCone::getConeInXML()

std::string QuadraticCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<quadraticCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    if (normScaleFactor != 1.0)
        outStr << " normScaleFactor=\"" << normScaleFactor << "\"";
    if (distortionMatrixIdx != -1)
        outStr << " distortionMatrixIdx=\"" << distortionMatrixIdx << "\"";
    if (axisDirection != 0)
        outStr << " axisDirection=\"" << axisDirection << "\"";
    outStr << "/>" << std::endl;   
    return outStr.str();
}// end of QuadraticCone::getConeInXML()

std::string RotatedQuadraticCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<rotatedQuadraticCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    if (normScaleFactor != 1.0)
        outStr << " normScaleFactor=\"" << normScaleFactor << "\"";
    if (distortionMatrixIdx != -1)
        outStr << " distortionMatrixIdx=\"" << distortionMatrixIdx << "\"";
    if (firstAxisDirection != 0)
        outStr << " firstAxisDirection=\"" << firstAxisDirection << "\"";
    if (secondAxisDirection != 1)
        outStr << " secondAxisDirection=\"" << secondAxisDirection << "\"";
    outStr << "/>" << std::endl;   
    return outStr.str();
}// end of RotatedQuadraticCone::getConeInXML()

std::string SemidefiniteCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<semidefiniteCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (semidefiniteness != "positive")
        outStr << " semidefiniteness=\"" << semidefiniteness << "\"";
    outStr << "/>" << std::endl;

    return outStr.str();
}// end of SemidefiniteCone::getConeInXML()

std::string CopositiveMatricesCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<nonnegativeCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    outStr << "/>" << std::endl;   
    return outStr.str();
}// end of CopositiveMatricesCone::getConeInXML()

std::string CompletelyPositiveMatricesCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<nonnegativeCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    outStr << "/>" << std::endl;   
    return outStr.str();
}// end of CompletelyPositiveMatricesCone::getConeInXML()

std::string ProductCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<productCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    outStr << ">" << std::endl;

    outStr << "<factors numberOfEl=\"" << factors->numberOfEl << "\">" << std::endl;
    outStr << writeIntVectorData(factors, true, false);
    outStr << "</factors>" << std::endl;

    outStr << "</productCone>" << std::endl;
    return outStr.str();
}// end of ProductCone::getConeInXML()

std::string IntersectionCone::getConeInXML()
{
    ostringstream outStr;
    outStr << "<intersectionCone";
    outStr << " numberOfRows=\"" << numberOfRows << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (name != "")
        outStr << " name=\"" << name << "\"";
    outStr << ">" << std::endl;

    outStr << "<components numberOfEl=\"" << components->numberOfEl << "\">";
    outStr << writeIntVectorData(components, true, false);
    outStr << "</components>" << std::endl;

    outStr << "</intersectionCone>" << std::endl;
    return outStr.str();
}// end of IntersectionCone::getConeInXML()


/***************************************************
 * methods to test whether two OSInstance objects
 * or their components are equal to each other
 ***************************************************/
bool OSInstance::IsEqual(OSInstance *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OSInstance");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->instanceHeader == NULL)
        {
            if (that->instanceHeader != NULL)
                return false;
        }
        else
            if (!this->instanceHeader->IsEqual(that->instanceHeader))
                return false;

        if (this->instanceData == NULL)
        {
            if (that->instanceData != NULL)
                return false;
        }
        else
            if (!this->instanceData->IsEqual(that->instanceData))
                return false;
    }

    return true;
}//OSInstance::IsEqual


bool InstanceData::IsEqual(InstanceData *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InstanceData");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->variables == NULL)
        {
            if (that->variables != NULL)
                return false;
        }
        else
            if (!this->variables->IsEqual(that->variables))
                return false;

        if (this->objectives == NULL)
        {
            if (that->objectives != NULL)
                return false;
        }
        else
            if (!this->objectives->IsEqual(that->objectives))
                return false;

         if (this->constraints == NULL)
        {
            if (that->constraints != NULL)
                return false;
        }
        else
            if (!this->constraints->IsEqual(that->constraints))
                return false;

        if (this->linearConstraintCoefficients == NULL)
        {
            if (that->linearConstraintCoefficients != NULL)
                return false;
        }
        else
            if (!this->linearConstraintCoefficients->IsEqual(that->linearConstraintCoefficients))
                return false;

        if (this->quadraticCoefficients == NULL)
        {
            if (that->quadraticCoefficients != NULL)
                return false;
        }
        else
            if (!this->quadraticCoefficients->IsEqual(that->quadraticCoefficients))
                return false;

        if (this->nonlinearExpressions == NULL)
        {
            if (that->nonlinearExpressions != NULL)
                return false;
        }
        else
            if (!this->nonlinearExpressions->IsEqual(that->nonlinearExpressions))
                return false;

        if (this->matrices == NULL)
        {
            if (that->matrices != NULL)
                return false;
        }
        else
            if (!this->matrices->IsEqual(that->matrices))
                return false;

        if (this->cones == NULL)
        {
            if (that->cones != NULL)
                return false;
        }
        else
            if (!this->cones->IsEqual(that->cones))
                return false;

        if (this->matrixProgramming == NULL)
        {
            if (that->matrixProgramming != NULL)
                return false;
        }
        else
            if (!this->matrixProgramming->IsEqual(that->matrixProgramming))
                return false;
    }

    return true;
}//InstanceData::IsEqual

bool Variables::IsEqual(Variables *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Variables");

#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfVariables != that->numberOfVariables)
            return false;
        for (int i=0; i<this->numberOfVariables; i++)
        {
            if (this->var[i] == NULL)
            {
                if (that->var[i] != NULL)
                    return false;
            }
            else
                if (!this->var[i]->IsEqual(that->var[i]))
                    return false;
        }
    }

    return true;
}//Variables::IsEqual

bool Variable::IsEqual(Variable *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Variable");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->lb != that->lb)
            return false;
        if (this->ub != that->ub)
            return false;
        if (this->type != that->type)
            return false;
        if (this->name != that->name)
            return false;
    }

    return true;
}//Variable::IsEqual

bool Objectives::IsEqual(Objectives *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Objectives");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfObjectives != that->numberOfObjectives)
            return false;
        for (int i=0; i<this->numberOfObjectives; i++)
        {
            if (this->obj[i] == NULL)
            {
                if (that->obj[i] != NULL)
                    return false;
            }
            else
                if (!this->obj[i]->IsEqual(that->obj[i]))
                    return false;
        }
    }

    return true;
}//Objectives::IsEqual

bool Objective::IsEqual(Objective *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Objective");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->name != that->name)
            return false;
        if (this->maxOrMin != that->maxOrMin)
            return false;
        if (this->constant != that->constant)
            return false;
        if (!OSIsEqual(this->weight, that->weight))
            return false;
        if (this->numberOfObjCoef != that->numberOfObjCoef)
            return false;

        for (int i=0; i<this->numberOfObjCoef; i++)
        {
            if (this->coef[i] == NULL)
            {
                if (that->coef[i] != NULL)
                    return false;
            }
            else
                if (!this->coef[i]->IsEqual(that->coef[i]))
                    return false;
        }
    }

    return true;
}//Objective::IsEqual

bool ObjCoef::IsEqual(ObjCoef *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in ObjCoef");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx != that->idx)
            return false;
        if (this->value != that->value)
            return false;
    }

    return true;
}//ObjCoef::IsEqual

bool Constraints::IsEqual(Constraints *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Constraints");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfConstraints != that->numberOfConstraints)
            return false;

        for (int i=0; i<this->numberOfConstraints; i++)
        {
            if (this->con[i] == NULL)
            {
                if (that->con[i] != NULL)
                    return false;
            }
            else
                if (!this->con[i]->IsEqual(that->con[i]))
                    return false;
        }
    }

    return true;
}//Constraints::IsEqual

bool Constraint::IsEqual(Constraint *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Constraint");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->name != that->name)
            return false;
        if (this->constant != that->constant)
            return false;
        if (this->lb != that->lb)
            return false;
        if (this->ub != that->ub)
            return false;
    }

    return true;
}//Constraint::IsEqual

bool LinearConstraintCoefficients::IsEqual(LinearConstraintCoefficients *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in LinearConstraintCoefficients");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfValues != that->numberOfValues)
            return false;

        if (this->start == NULL)
        {
            if (that->start != NULL)
                return false;
        }
        else
            if (!this->start->IsEqual(that->start))
                return false;

        if (this->rowIdx == NULL)
        {
            if (that->rowIdx != NULL)
                return false;
        }
        else
            if (!this->rowIdx->IsEqual(that->rowIdx))
                return false;

        if (this->colIdx == NULL)
        {
            if (that->colIdx != NULL)
                return false;
        }
        else
            if (!this->colIdx->IsEqual(that->colIdx))
                return false;

        if (this->value == NULL)
        {
            if (that->value != NULL)
                return false;
        }
        else
            if (!this->value->IsEqual(that->value))
                return false;
    }

    return true;
}//LinearConstraintCoefficients::IsEqual

bool QuadraticCoefficients::IsEqual(QuadraticCoefficients *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in QuadraticCoefficients");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfQuadraticTerms != that->numberOfQuadraticTerms)
            return false;

        for (int i=0; i<this->numberOfQuadraticTerms; i++)
        {
            if (this->qTerm[i] == NULL)
            {
                if (that->qTerm[i] != NULL)
                    return false;
            }
            else
                if (!this->qTerm[i]->IsEqual(that->qTerm[i]))
                    return false;
        }
    }

    return true;
}//QuadraticCoefficients::IsEqual


bool QuadraticTerm::IsEqual(QuadraticTerm *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in QuadraticTerm");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx != that->idx)
            return false;
        if (this->idxOne != that->idxOne)
            return false;
        if (this->idxTwo != that->idxTwo)
            return false;
        if (this->coef != that->coef)
            return false;
    }

    return true;
}//QuadraticTerm::IsEqual

bool NonlinearExpressions::IsEqual(NonlinearExpressions *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in NonlinearExpressions");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfNonlinearExpressions != that->numberOfNonlinearExpressions)
            return false;

        for (int i=0; i<this->numberOfNonlinearExpressions; i++)
        {
            if (this->nl[i] == NULL)
            {
                if (that->nl[i] != NULL)
                    return false;
            }
            else
                if (!this->nl[i]->IsEqual(that->nl[i]))
                    return false;
        }
    }

    return true;
}//NonlinearExpressions::IsEqual


bool Nl::IsEqual(Nl *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Nl");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx != that->idx)
            return false;

        if (this->osExpressionTree == NULL)
        {
            if (that->osExpressionTree != NULL)
                return false;
        }
        else
            if (!this->osExpressionTree->IsEqual(that->osExpressionTree))
                return false;
    }

    return true;
}//Nl::IsEqual

bool Matrices::IsEqual(Matrices *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Matrices");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfMatrices != that->numberOfMatrices)
            return false;

        for (int i=0; i<this->numberOfMatrices; i++)
        {
            if (this->matrix[i] == NULL)
            {
                if (that->matrix[i] != NULL)
                    return false;
            }
            else
                if (!this->matrix[i]->IsEqual(that->matrix[i]))
                    return false;
        }
    }

    return true;
}//Matrices::IsEqual

bool Cones::IsEqual(Cones *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Cones");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfCones != that->numberOfCones)
            return false;

        for (int i=0; i<this->numberOfCones; i++)
        {
            if (this->cone[i] == NULL)
            {
               if (that->cone[i] != NULL)
                   return false;
            }
            else
                if (!this->cone[i]->IsEqual(that->cone[i]))
                    return false;
        }
    }

    return true;
}//Cones::IsEqual

bool Cone::IsEqual(Cone *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Cone");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->coneType != that->coneType)
            return false;
        if (this->numberOfColumns != that->numberOfColumns)
            return false;
        if (this->numberOfRows != that->numberOfRows)
            return false;
        if (this->numberOfOtherIndexes != that->numberOfOtherIndexes)
            return false;

        for (int i=0; i<this->numberOfOtherIndexes; i++)
        {
            if (this->otherIndexes[i] == NULL)
            {
                if (that->otherIndexes[i] != NULL)
                    return false;
            }
            else
                if (this->otherIndexes[i] != that->otherIndexes[i])
                    return false;
        }
    }

    return true;
}//Cone::IsEqual

bool PolyhedralCone::IsEqual(PolyhedralCone *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in PolyhedralCone");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->referenceMatrixIdx == NULL)
        {
            if (that->referenceMatrixIdx != NULL)
                return false;
        }
        else
            if (this->referenceMatrixIdx != that->referenceMatrixIdx)
                return false;

        return this->Cone::IsEqual(that);
    }

    return true;
}//PolyhedralCone::IsEqual


bool QuadraticCone::IsEqual(QuadraticCone *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in QuadraticCone");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->normScaleFactor != that->normScaleFactor)
            return false;    
        if (this->distortionMatrixIdx != that->distortionMatrixIdx)
            return false;    
        if (this->axisDirection != that->axisDirection)
            return false;

        return this->Cone::IsEqual(that);
    }

    return true;
}//QuadraticCone::IsEqual



bool RotatedQuadraticCone::IsEqual(RotatedQuadraticCone *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in RotatedQuadraticCone");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->normScaleFactor != that->normScaleFactor)
            return false;    
        if (this->distortionMatrixIdx != that->distortionMatrixIdx)
            return false;    
        if (this->firstAxisDirection != that->firstAxisDirection)
            return false;
        if (this->secondAxisDirection != that->secondAxisDirection)
            return false;

        return this->Cone::IsEqual(that);
    }

    return true;
}//RotatedQuadraticCone::IsEqual

bool SemidefiniteCone::IsEqual(SemidefiniteCone *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in SemidefiniteCone");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->semidefiniteness != that->semidefiniteness)
            return false;
        return this->Cone::IsEqual(that);
    }

    return true;
}//SemidefiniteCone::IsEqual

bool ProductCone::IsEqual(ProductCone *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in ProductCone");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->factors == NULL)
        {
            if (that->factors != NULL)
                return false;
        }
        else
            if (!this->factors->IsEqual(that->factors))
                return false;

        return this->Cone::IsEqual(that);
    }

    return true;
}//ProductCone::IsEqual

bool IntersectionCone::IsEqual(IntersectionCone *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in IntersectionCone");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->components == NULL)
        {
            if (that->components != NULL)
                return false;
        }
        else
            if (!this->components->IsEqual(that->components))
                return false;

        return this->Cone::IsEqual(that);
    }

    return true;
}//IntersectionCone::IsEqual

bool DualCone::IsEqual(DualCone *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in DualCone");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->referenceConeIdx != that->referenceConeIdx)
            return false;

        return this->Cone::IsEqual(that);
    }

    return true;
}//DualCone::IsEqual


bool PolarCone::IsEqual(PolarCone *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in PolarCone");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->referenceConeIdx != that->referenceConeIdx)
            return false;

        return this->Cone::IsEqual(that);
    }

    return true;
}//PolarCone::IsEqual


bool MatrixProgramming::IsEqual(MatrixProgramming *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixProgramming");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->matrixVariables != NULL)
        {
            if (!(this->matrixVariables->IsEqual(that->matrixVariables)))
                return false;
        }
        else
        {
            if (that->matrixVariables != NULL) return false;
        }

        if (this->matrixObjectives != NULL)
        {
            if (!(this->matrixObjectives->IsEqual(that->matrixObjectives)))
                return false;
        }
        else
        {
            if (that->matrixObjectives != NULL) return false;
        }

        if (this->matrixConstraints != NULL)
        {
            if (!(this->matrixConstraints->IsEqual(that->matrixConstraints)))
                return false;
        }
        else
        {
            if (that->matrixConstraints != NULL) return false;
        }

        if (this->matrixExpressions != NULL)
        {
            if (!(this->matrixExpressions->IsEqual(that->matrixExpressions)))
                return false;
        }
        else
        {
            if (that->matrixExpressions != NULL) return false;
        }
    }

    return true;
}//MatrixProgramming::IsEqual


bool MatrixVariables::IsEqual(MatrixVariables *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixVariables");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfMatrixVar != that->numberOfMatrixVar) return false;

        for (int i=0; i<numberOfMatrixVar; i++)
        {
            if (this->matrixVar[i] != NULL)
            {
                if (!(this->matrixVar[i]->IsEqual(that->matrixVar[i]))) return false;
            }
            else 
                if (that->matrixVar[i] != NULL) return false; 
        }
    }

    return true;
}//MatrixVariables::IsEqual

bool MatrixVar::IsEqual(MatrixVar *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixVar");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfRows != that->numberOfRows)
            return false;
        if (this->numberOfColumns != that->numberOfColumns)
            return false;
        if (this->templateMatrixIdx != that->templateMatrixIdx)
            return false;
        if (this->varReferenceMatrixIdx != that->varReferenceMatrixIdx)
            return false;
        if (this->lbMatrixIdx != that->lbMatrixIdx)
            return false;
        if (this->lbConeIdx != that->lbConeIdx)
            return false;
        if (this->ubMatrixIdx != that->ubMatrixIdx)
            return false;
        if (this->ubConeIdx != that->ubConeIdx)
            return false;
        if (this->name != that->name)
            return false;
        if (this->varType != that->varType)
            return false;
    }

    return true;
}//MatrixVar::IsEqual

bool MatrixObjectives::IsEqual(MatrixObjectives *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixProgramming");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfMatrixObj != that->numberOfMatrixObj) return false;

        for (int i=0; i<numberOfMatrixObj; i++)
        {
            if (this->matrixObj[i] != NULL)
            {
                if (!(this->matrixObj[i]->IsEqual(that->matrixObj[i]))) return false;
            }
            else 
                if (that->matrixObj[i] != NULL) return false; 
        }
    }

    return true;
}//MatrixObjectives::IsEqual

bool MatrixObj::IsEqual(MatrixObj *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixObj");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfRows != that->numberOfRows)
            return false;
        if (this->numberOfColumns != that->numberOfColumns)
            return false;
        if (this->templateMatrixIdx != that->templateMatrixIdx)
            return false;
        if (this->objReferenceMatrixIdx != that->objReferenceMatrixIdx)
            return false;
        if (this->orderConeIdx != that->orderConeIdx)
            return false;
        if (this->constantMatrixIdx != that->constantMatrixIdx)
            return false;
        if (this->name != that->name)
            return false;
    }

    return true;
}//MatrixObj::IsEqual

bool MatrixConstraints::IsEqual(MatrixConstraints *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixConstraints");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfMatrixCon != that->numberOfMatrixCon) return false;

        for (int i=0; i<numberOfMatrixCon; i++)
        {
            if (this->matrixCon[i] != NULL)
            {
                if (!(this->matrixCon[i]->IsEqual(that->matrixCon[i]))) return false;
            }
            else 
                if (that->matrixCon[i] != NULL) return false; 
        }
    }

    return true;
}//MatrixConstraints::IsEqual

bool MatrixCon::IsEqual(MatrixCon *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixCon");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfRows != that->numberOfRows)
            return false;
        if (this->numberOfColumns != that->numberOfColumns)
            return false;
        if (this->templateMatrixIdx != that->templateMatrixIdx)
            return false;
        if (this->conReferenceMatrixIdx != that->conReferenceMatrixIdx)
            return false;
        if (this->lbMatrixIdx != that->lbMatrixIdx)
            return false;
        if (this->lbConeIdx != that->lbConeIdx)
            return false;
        if (this->ubMatrixIdx != that->ubMatrixIdx)
            return false;
        if (this->ubConeIdx != that->ubConeIdx)
            return false;
        if (this->name != that->name)
            return false;
    }

    return true;
}//MatrixCon::IsEqual

bool MatrixExpressions::IsEqual(MatrixExpressions *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixExpressions");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfExpr != that->numberOfExpr) return false;

        for (int i=0; i<numberOfExpr; i++)
        {
            if (this->expr[i] != NULL)
            {
                if (!(this->expr[i]->IsEqual(that->expr[i]))) return false;
            }
            else 
                if (that->expr[i] != NULL) return false; 
        }
    }

    return true;
}//MatrixExpressions::IsEqual

bool MatrixExpression::IsEqual(MatrixExpression *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixExpression");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx           != that->idx          ) return false;
        if (this->declaredShape != that->declaredShape) return false;
        if (this->inferredShape != that->inferredShape) return false;

        if (this->matrixExpressionTree != NULL)
        {
            if (!(this->matrixExpressionTree->IsEqual(that->matrixExpressionTree))) 
                return false;
        }
        else 
            if (that->matrixExpressionTree != NULL) return false; 
    }

    return true;
}//MatrixExpression::IsEqual

