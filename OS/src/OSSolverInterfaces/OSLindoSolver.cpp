/* $Id$ */
/** @file LindoSolver.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#include "OSLindoSolver.h"
#include "OSiLReader.h"
#include "OSInstance.h"
#include "OSFileUtil.h"
#include "OSOutput.h"
#include "OSErrorClass.h"

#include "OSDataStructures.h"
#include "OSParameters.h"
#include "OSMathUtil.h"

#include "CoinTime.hpp"


#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif
#include <iostream>
#include <sstream>
#include<vector>
#include <map>

using std::cout;
using std::endl;
using std::ostringstream;

#define DEBUG
#ifndef __LINDOI_H__
#define __LINDOI_H__

#ifdef __cplusplus
extern "C" {
#endif

    int CALLTYPE LSwriteMPIFile(pLSmodel pModel, char *pszFname);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __ILINDO_H__   */

#define LINDO_OP_CODE_CONVERSION \
	std::map<int, int> nlNodeIdxLindo;\
	nlNodeIdxLindo[OS_PLUS] = EP_PLUS; \
	nlNodeIdxLindo[OS_SUM] = EP_SUM; \
	nlNodeIdxLindo[OS_MINUS] = EP_MINUS; \
	nlNodeIdxLindo[OS_NEGATE] = EP_NEGATE; \
	nlNodeIdxLindo[OS_TIMES] = EP_MULTIPLY; \
	nlNodeIdxLindo[OS_DIVIDE] = EP_DIVIDE; \
	nlNodeIdxLindo[OS_POWER] = EP_POWER; \
	nlNodeIdxLindo[OS_SQRT] = EP_SQRT; \
	nlNodeIdxLindo[OS_LN] = EP_LN; \
	nlNodeIdxLindo[OS_EXP] = EP_EXP; \
	nlNodeIdxLindo[OS_NUMBER] = EP_PUSH_NUM; \
	nlNodeIdxLindo[OS_VARIABLE] = EP_PUSH_VAR;\
	nlNodeIdxLindo[OS_IF] = EP_IF; \
	nlNodeIdxLindo[OS_ABS] = EP_ABS; \
	nlNodeIdxLindo[OS_MAX] = EP_MAX; \
	nlNodeIdxLindo[OS_MIN] = EP_MIN; \
	nlNodeIdxLindo[OS_SQUARE] = EP_SQR; \
	nlNodeIdxLindo[OS_SIN] = EP_SIN; \
	nlNodeIdxLindo[OS_COS] = EP_COS;

LindoSolver::LindoSolver():
    m_osilreader( NULL),
    pEnv_( NULL),
    pModel_( NULL),
    m_miSlackIdx( NULL),
    m_iNumberNewSlacks( 0),
    m_mdRhsValue( NULL),
    m_mcRowType( NULL),
    m_mdVarLB( NULL),
    m_mdVarUB( NULL),
    m_mdConLB( NULL),
    m_mdConUB( NULL),
    m_mmcVarName( NULL),
    m_msVarName( NULL),
    m_msConName( NULL),
    m_mcVarType( NULL),
    m_mdObjConstant( 0),
    osrlwriter( NULL),
    cpuTime( 0)

{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "Lindo constructor called\n");
#endif
    osrlwriter = new OSrLWriter();
}

LindoSolver::~LindoSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "Lindo destructor called\n");
#endif
    //delete[] m_mdRhsValue ;
    //delete[] m_mdVarLB ;
    //delete[] m_mdVarUB ;
    delete[] m_mmcVarName ;

    m_mdConLB = NULL;
    m_mdConUB = NULL;
    m_msVarName = NULL;
    m_mcVarType = NULL;
    m_mcRowType = NULL;
    m_msConName = NULL;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "Delete LSdelete\n");
#endif
    LSdeleteEnv(&pEnv_);
    delete[] m_miSlackIdx;
    m_miSlackIdx = NULL;
    delete[] m_mdRhsValue;
    m_mdRhsValue = NULL;
    delete osrlwriter;
    osrlwriter = NULL;
    delete osresult;
    osresult = NULL;
    if(m_osilreader != NULL) delete m_osilreader;
    m_osilreader = NULL;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, "Lindo Solver garbage collection done\n");

}


void LindoSolver::buildSolverInstance() throw (ErrorClass)
{
    try
    {
        osresult = new OSResult();
        if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
        OSiLReader* osilreader = NULL;
        bool newOSiLReader = false;
        if(osinstance == NULL)
        {
            osilreader = new OSiLReader();
            osinstance = osilreader->readOSiL( osil);
            newOSiLReader = true;

        }

        OSiLWriter osilwriter;

        if (osinstance->instanceData->constraints->numberOfConstraints <= 0)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, 
                "HERE I AM 1 !!!!!!!!!!!!!!!!!!!\n");
#endif
            osinstance->setConstraintNumber(1);
            osinstance->addConstraint(0, "dummyConstraint", 0, 0, 0);
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, 
                "HERE I AM 2 !!!!!!!!!!!!!!!!!!!\n");
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, 
                osilwriter.writeOSiL( osinstance));
#endif
        }
        if(osinstance->getVariableNumber() <  0)throw ErrorClass("Cannot have a negative number of decision variables");
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, 
                "Start process variables !!!!!!!!!\n");
#endif
        if( !processVariables() ) throw ErrorClass("failed processing variables");
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, 
                "Finish process variables !!!!!!!!!\n");
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, 
                "Start process constraints !!!!!!!!!\n");
#endif
        if( !processConstraints() ) throw ErrorClass("failed processing constraints");
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, 
                "Finish process constraints !!!!!!!!!\n");
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, 
                "Start generateLindoModel() !!!!!!!!!\n");
#endif
        if( !generateLindoModel()) throw ErrorClass("failed generating Lindo model");
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, 
                "Finish generateLindoModel() !!!!!!!!!\n");
#endif
        if(m_iNumberNewSlacks > 0 && !addSlackVars()) throw ErrorClass("failed adding slack variables");
        if( (osinstance->getNumberOfNonlinearExpressions() > 0 || osinstance->getNumberOfQuadraticTerms() > 0)
                && !processNonlinearExpressions()) throw ErrorClass("failed adding nonlinear terms");
        this->bCallbuildSolverInstance = true ;
        //dataEchoCheck();
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, "THERE IS AN ERROR\n");
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//end buildSolverInstance()



void LindoSolver::setSolverOptions() throw (ErrorClass)
{
    try
    {

    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, "THERE IS AN ERROR\n");
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//end setSolverOptions()


void LindoSolver::solve()
{
    if( this->bCallbuildSolverInstance == false) buildSolverInstance();
    try
    {
        double start = CoinCpuTime();
        if( optimize() != true) throw ErrorClass("problem optimizing model");
        cpuTime = CoinCpuTime() - start;
        osresult->setGeneralStatusType("normal");
        osresult->setTime(cpuTime);
        osrl = osrlwriter->writeOSrL( osresult);
    }
    catch(const ErrorClass& eclass)
    {
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}// end solve

bool LindoSolver::processConstraints()
{
    int i;
    m_iNumberNewSlacks = 0;
    try
    {


        m_mdConLB = osinstance->getConstraintLowerBounds();
        m_mdConUB = osinstance->getConstraintUpperBounds();
        m_msConName = osinstance->getConstraintNames();
        m_mdRhsValue = new double[ osinstance->getConstraintNumber()];
        m_miSlackIdx = new int[ osinstance->getConstraintNumber()];
        m_mcRowType = osinstance->getConstraintTypes();

        for(i = 0; i < osinstance->getConstraintNumber(); i++)
        {
            switch( m_mcRowType[ i] )
            {
            case 'E':
                m_mdRhsValue[ i] = m_mdConUB[ i];
                //m_mdRhsValue[ i] = m_mdConUB[ i]; Kipp: get constant
                // Add method in OSInstance get constraint constant
                break;
            case 'L':
                m_mdRhsValue[ i] = m_mdConUB[ i];
                break;
            case 'G':
                m_mdRhsValue[ i] = m_mdConLB[ i];
                break;
            case 'U':
                throw ErrorClass("LINDO cannot handle unbounded constraints");
                break;
            case 'R':
                // we have a range constraint -- LINDO does not allow this -- a variable must be added later
                m_mdRhsValue[ i] = m_mdConUB[ i] ;
                m_mcRowType[ i] = 'E';
                m_miSlackIdx[ m_iNumberNewSlacks] = i;
                m_iNumberNewSlacks++;
                break;
            }
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ;
    }
} // end processConstraints
//
bool LindoSolver::addSlackVars()
{
    std::ostringstream outStr;

    /* the following is LINDO specific -- make up
    for the fact that lindo does not like upper and lower bounds on consraints
    this is not needed in the COIN Interface
    */
    if(m_iNumberNewSlacks <= 0) return false;
    int i;
    ostringstream varName;
    char* p;
    std::string tmpstring;
    char* pachVartypes = new char[m_iNumberNewSlacks];
    char** paszVarnames = new char*[m_iNumberNewSlacks];
    int* paiAcols = new int[m_iNumberNewSlacks + 1];
    int* pacAcols =  NULL;
    double* padAcoef = new double[m_iNumberNewSlacks];
    int* paiArows = new int[m_iNumberNewSlacks];
    double* padC = new double[m_iNumberNewSlacks];
    double* padL =  NULL;
    double* padU = new double[m_iNumberNewSlacks];
    for(i = 0; i < m_iNumberNewSlacks; i++)
    {
        pachVartypes[ i] = 'C';
        varName << "xyzabc_" ;
        varName << i ;
        varName << '\0';
        tmpstring = varName.str();
        p = new char[tmpstring.size() + 1];
        strcpy(p, tmpstring.c_str());
        char ch;
        ch = ' ';
        // a LINDO kludge
        if( m_iNumberNewSlacks == 1) paszVarnames[i] = &ch;
        else paszVarnames[i] = p;
        varName << "";
        paiAcols[ i] = i;
        padAcoef[ i] = 1.0;
        paiArows[ i] = m_miSlackIdx[ i];
        padC[ i] = 0.0;
        padU[ i] = m_mdConUB[ m_miSlackIdx[ i]] - m_mdConLB[ m_miSlackIdx[ i]];
        if(padU[ i]  - padC[i]< 0) return false;
    }
    paiAcols[ m_iNumberNewSlacks] = m_iNumberNewSlacks;
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "The number of new slack variables is: " << m_iNumberNewSlacks << endl;
    for(i = 0; i < m_iNumberNewSlacks; i++)
    {
        outStr << paszVarnames[ i] << endl;
    }
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    if(!LSaddVariables(pModel_, m_iNumberNewSlacks, pachVartypes, paszVarnames, paiAcols,
                       pacAcols, padAcoef, paiArows, padC, padL, padU))
    {
        if(m_iNumberNewSlacks > 0)
        {
            //
            delete[] paiAcols;
            delete[] padAcoef;
            delete[] paiArows;
            delete[] padC;
            delete[] padU;

            // another LINDO kludge
            if( m_iNumberNewSlacks == 1)
            {
                delete paszVarnames;
                delete pachVartypes;
            }
            else
            {
                for(i = 0; i < m_iNumberNewSlacks; i++) delete[] paszVarnames[i];
                delete[] paszVarnames;
                delete[] pachVartypes;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
} // end addSlackVars()


bool LindoSolver::processVariables()
{
    int i;
    try
    {
        m_mcVarType = osinstance->getVariableTypes();
        m_mdVarLB = osinstance->getVariableLowerBounds();
        m_mdVarUB  = osinstance->getVariableUpperBounds();
        m_mmcVarName = new char*[ osinstance->getVariableNumber()];
        for(i = 0; i < osinstance->getVariableNumber(); i++)
        {
            m_mmcVarName[i] = &osinstance->getVariableNames()[  i][0];
        }
        //fix for Stefan
        for(i = 0; i <  osinstance->getVariableNumber() ; i++)
        {
            if(	osinstance->getVariableTypes()[ i] == 'B')
            {
                m_mdVarUB[ i] = 1.0;
            }
        }

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ;
    }
}  // end processVariables



bool LindoSolver::generateLindoModel()
{
    std::ostringstream outStr;

    // Generate the LINDO model
    /* declare an instance of the LINDO environment object */
    /* >>> Step 1 <<< Create a LINDO environment. Note:
    MY_LICENSE_KEY must be defined in license.h to
    be the license key shipped with your software. */
    char *MY_LICENSE_KEY = NULL;
    MY_LICENSE_KEY = getenv( "LINDOAPI_LICENSE_FILE");
    try
    {
        pEnv_ = LScreateEnv ( &m_iLindoErrorCode, MY_LICENSE_KEY);
        lindoAPIErrorCheck("There was an Error Creating the LINDO environment");
        /* >>> Step 2 <<< Create a model in the environment. */
        pModel_ = LScreateModel ( pEnv_, &m_iLindoErrorCode);
        lindoAPIErrorCheck("There was an Error Creating the LINDO Model");
        /* >>> Step 3 <<< Specify the model.
        	To specify our model, we make a call to LSloadLPData,
        	passing it:
        	- A pointer to the model which we are specifying(pModel_)
        	- The number of constraints in the model
        	- The number of variables in the model
        	- The direction of the optimization (i.e. minimize or maximize)
        	- The value of the constant term in the objective (may be zero)
        	- The coefficients of the objective function
        	- The right-hand sides of the constraints
        	- The types of the constraints
        	- The number of nonzeros in the constraint matrix
        	- The indices of the first nonzero in each column
        	- The length of each column
        	- The nonzero coefficients
        	- The row indices of the nonzero coefficients
        	- Simple upper and lower bounds on the variables
        	*/
        int *colLength = NULL;
        // Kipp: this is a kludge -- fix later
        if(osinstance->getLinearConstraintCoefficientNumber()  <=  0)
        {
            outStr.str("");
            outStr.clear();
            outStr << "LinearConstraintCoefficientNumber =  " << osinstance->getLinearConstraintCoefficientNumber() << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
            //

            int iNumFakeNonz = 1;
            // fake index array
            int *paiArrayIdx;
            paiArrayIdx = new int[ 1];
            paiArrayIdx[ 0] = 0;
            // fake nonzero array
            double *padValArray;
            padValArray = new double[ 1];
            padValArray[0] = 0;
            //
            int *paiArrayBeg;
            paiArrayBeg = new int[osinstance->getVariableNumber() + 1];
            paiArrayBeg[0] = 0;
            for(int kl = 1; kl <= osinstance->getVariableNumber(); kl++)
            {
                paiArrayBeg[kl] = 1;
            }
            //
            //
            m_iLindoErrorCode = LSloadLPData( pModel_, osinstance->getConstraintNumber(),  osinstance->getVariableNumber(),
                                              ( osinstance->getObjectiveMaxOrMins()[0] == "min")?LS_MIN:LS_MAX ,
                                              osinstance->getObjectiveConstants()[0],
                                              osinstance->getDenseObjectiveCoefficients()[0],
                                              m_mdRhsValue, m_mcRowType,
                                              iNumFakeNonz,
                                              paiArrayBeg,
                                              colLength,  padValArray,
                                              paiArrayIdx,
                                              m_mdVarLB, m_mdVarUB);
            lindoAPIErrorCheck("Error with LSloadLPData when the number of nonzeros is 0");
        }
        else
        {
            m_iLindoErrorCode = LSloadLPData( pModel_, osinstance->getConstraintNumber(),  osinstance->getVariableNumber(),
                                              ( osinstance->getObjectiveMaxOrMins()[0] == "min")?LS_MIN:LS_MAX ,
                                              osinstance->getObjectiveConstants()[0], osinstance->getDenseObjectiveCoefficients()[0], m_mdRhsValue, m_mcRowType,
                                              osinstance->getLinearConstraintCoefficientNumber(),
                                              osinstance->getLinearConstraintCoefficientsInColumnMajor()->starts,
                                              colLength,  osinstance->getLinearConstraintCoefficientsInColumnMajor()->values,
                                              osinstance->getLinearConstraintCoefficientsInColumnMajor()->indexes,
                                              m_mdVarLB, m_mdVarUB);
            lindoAPIErrorCheck("Error with LSloadLPData when the number of nonzeros is greater than 0");
        }
        m_iLindoErrorCode = LSloadVarType(pModel_, m_mcVarType);
        lindoAPIErrorCheck("There was an error loading the Lindo Variable Types");
        return true;
    }
    catch( const ErrorClass& eclass)
    {
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ;
    }
} // end generateLindoModel


bool LindoSolver::optimize()
{
    double *x,  *y, *z;
    int solIdx = 0;
    ostringstream outStr;
    std::string *srcost;
    bool isNonlinear = false;
    double *drcost;
    int nSolStatus;
    std::string description = "";
    // resultHeader information
    if(osresult->setSolverInvoked( "LINDO Systems, Inc. Lindo API") != true)
        throw ErrorClass("OSResult error: setSolverInvoked");
    if(osresult->setServiceName( OSgetVersionInfo()) != true)
        throw ErrorClass("OSResult error: setServiceName");

    if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
        throw ErrorClass("OSResult error: setInstanceName");
    //if(osresult->setJobID( osresultdata->jobID) != true)
    //	throw ErrorClass("OSResult error: setJobID");
    //if(osresult->setGeneralMessage( osresultdata->message) != true)
    //	throw ErrorClass("OSResult error: setGeneralMessage");
    if(osinstance->getNumberOfNonlinearObjectives() > 0 ||  osinstance->getNumberOfNonlinearConstraints() > 0) isNonlinear = true;
    try
    {
        if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("LINDO NEEDS AN OBJECTIVE FUNCTION");

        if( isNonlinear == true )
        {
            //m_iLindoErrorCode = LSoptimize( pModel_, LS_METHOD_FREE, &nSolStatus);
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, 
                "We are using the LINDO Global Optimizer\n");
            m_iLindoErrorCode = LSsolveGOP(pModel_,  &nSolStatus) ;
            lindoAPIErrorCheck("There was an ERROR in the call to the Optimizer solver");
            LSgetInfo (pModel_, LS_IINFO_GOP_STATUS, &nSolStatus);
        }
        else
        {
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, 
                "We are using the LINDO LSsolveMIP Optimizer\n");
            m_iLindoErrorCode = LSsolveMIP( pModel_,  &nSolStatus);
            lindoAPIErrorCheck("There was an ERROR in the call to the MIP solver");
        }
        // set basic problem parameters
        if(osresult->setVariableNumber( osinstance->getVariableNumber()) != true)
            throw ErrorClass("OSResult error: setVariableNumer");
        if(osresult->setObjectiveNumber( 1) != true)
            throw ErrorClass("OSResult error: setObjectiveNumber");
        if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
            throw ErrorClass("OSResult error: setConstraintNumber");
        if(osresult->setSolutionNumber(  1) != true)
            throw ErrorClass("OSResult error: setSolutionNumer");
        outStr.str("");
        outStr.clear();
        outStr << "Solution Status  = " <<  nSolStatus << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());

        osresult->setGeneralStatusType("normal");
        osresult->setSolutionStatus(solIdx, "optimal", description);
        x = new double[ osinstance->getVariableNumber() + m_iNumberNewSlacks];
        srcost = new std::string[ osinstance->getVariableNumber() + m_iNumberNewSlacks];
        drcost = new double[ osinstance->getVariableNumber() + m_iNumberNewSlacks];
        for(int i = 0; i <  osinstance->getVariableNumber() + m_iNumberNewSlacks; i++)
        {
            drcost[i] = 0.0;
            srcost[i] = "";
        }
        y = new double[ osinstance->getConstraintNumber() ];
        z = new double[1];
        switch( nSolStatus)
        {
        case 1:
            // an optimal solution is found
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, "case 1\n");
        case 8:
            // a local optimal solution is found
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, "case 8\n");
        case 2:
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, "case 2\n");
            // an optimal basic  solution is also found
            // get the primal result
            if( (osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0 )
                    || (isNonlinear == false) )
            {
                m_iLindoErrorCode = LSgetMIPPrimalSolution( pModel_, x);
                lindoAPIErrorCheck("Error trying to obtain primal solution with integer variables present");
            }

            else
            {
                m_iLindoErrorCode = LSgetPrimalSolution( pModel_, x);
                lindoAPIErrorCheck("Error trying to obtain primal solution with NO integer variables present");
            }
            osresult->setPrimalVariableValuesDense(solIdx, x);
            // Get the dual values result
            if( (osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0)
                    || (isNonlinear == false) )
            {
                m_iLindoErrorCode = LSgetMIPDualSolution( pModel_, y);
                lindoAPIErrorCheck("Error trying to obtain dual solution with integer variables present");
            }
            else
            {
                m_iLindoErrorCode = LSgetDualSolution( pModel_, y);
                lindoAPIErrorCheck("Error trying to obtain dual solution with NO integer variables present");
            }
            osresult->setDualVariableValuesDense(solIdx, y);
            // get the reduced cost result
            if( ( osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0)
                    || (isNonlinear == false ) )
            {
                //m_iLindoErrorCode = LSgetMIPReducedCosts( pModel_, drcost);
                //lindoAPIErrorCheck("Error trying to obtain the reduced costs with integer variables present");
            }
            else
            {
                m_iLindoErrorCode = LSgetReducedCosts( pModel_, drcost);
                lindoAPIErrorCheck("Error trying to obtain the reduced costs with NO integer variables present");;
            }
            // now put the reduced costs into the osrl
            {
                int numberOfOtherVariableResult = 1;
                int otherIdx = 0;
                // first set the number of Other Variable Results
                osresult->setNumberOfOtherVariableResults(solIdx, numberOfOtherVariableResult);
                for(int i = 0; i <  osinstance->getVariableNumber() + m_iNumberNewSlacks; i++)
                {
                    outStr << drcost[i];
                    srcost[ i] = outStr.str();
                    outStr.str("");
                }
                osresult->setAnOtherVariableResultDense(solIdx, otherIdx, "reduced costs", "", "the variable reduced costs", srcost);
                /* Get the value of the objective */
                if( ( osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0)
                        || (isNonlinear == false ) )
                {
                    m_iLindoErrorCode = LSgetInfo( pModel_, LS_DINFO_MIP_OBJ, &z[0]);
                    lindoAPIErrorCheck("Error trying to obtain optimal objective value with integer variables present");
                }
                else
                {
                    LSgetInfo( pModel_, LS_DINFO_GOP_OBJ, &z[0]);
                    lindoAPIErrorCheck("Error trying to obtain optimal objective value with NO integer variables present");
                }
                osresult->setObjectiveValuesDense(solIdx, z);
            }
            break;
        case 3:
            osresult->setSolutionStatus(solIdx,  "infeasible", description);
            break;
        case 4:
            osresult->setSolutionStatus(solIdx,  "unbounded", description);
            break;
        default:
            osresult->setSolutionStatus(solIdx,  "other", description);
        }

        delete[] x;
        delete[] y;
        delete[] z;
        delete[] srcost;
        delete[] drcost;
        return true;
    }
    catch(const ErrorClass& eclass)
    {

        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ;
    }
} //end optimize


bool LindoSolver::processQuadraticTerms()
{
    int nQCnnz = osinstance->getNumberOfQuadraticTerms();
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, 
        "WE ARE PROCESSING QUADRATIC TERMS\n");
    try
    {
        if(nQCnnz  <= 0)return false;
        std::map<std::string, double> mapQuadraticAdjustMap;
        std::map<std::string, double>::iterator mapPointer;

        int i;
        int iVarOneIndex, iVarTwoIndex;
        int iRowIndex;
        std::string sKey;
        double dValue;

        int iStringPostionOne, iStringPostionTwo;

        int* paiQCrows = osinstance->getQuadraticTerms()->rowIndexes;
        int* paiQCcols1 = osinstance->getQuadraticTerms()->varOneIndexes;
        int* paiQCcols2 = osinstance->getQuadraticTerms()->varTwoIndexes;
        double* padQCcoef = osinstance->getQuadraticTerms()->coefficients;
        std::ostringstream ostrRow, ostr1, ostr2;
        std::string sIndexRow, sIndex1, sIndex2;

        for ( i = 0; i < nQCnnz; i++)
        {
            iRowIndex = paiQCrows[i];

            if (iRowIndex >= -1)
            {
                iVarOneIndex = (paiQCcols1[i] >= paiQCcols2[i])?paiQCcols2[i]:paiQCcols1[i];
                iVarTwoIndex = (paiQCcols1[i] <= paiQCcols2[i])?paiQCcols2[i]:paiQCcols1[i];
                ostrRow << iRowIndex;
                ostr2<<iVarTwoIndex;
                ostr1<<iVarOneIndex;
                sIndexRow = ostrRow.str();
                sIndex2 = ostr2.str();
                sIndex1 = ostr1.str();

                ostrRow.str("");
                ostr2.str("");
                ostr1.str("");

                sKey = sIndexRow + "," + sIndex1 + "," + sIndex2;

                mapPointer = mapQuadraticAdjustMap.find(sKey);
                if (mapPointer != mapQuadraticAdjustMap.end())
                {
                    dValue = mapPointer->second;
                    dValue += padQCcoef[i];
                    mapQuadraticAdjustMap[sKey] = dValue;
                }
                else
                {
                    mapQuadraticAdjustMap[sKey] = padQCcoef[i];
                }
            }
        }

        int iNumberOfQuadraticTerms = 0;
        for (mapPointer = mapQuadraticAdjustMap.begin();  mapPointer != mapQuadraticAdjustMap.end(); 			++mapPointer)
        {
            sKey = mapPointer->first;
            dValue = mapPointer->second;
            iStringPostionOne = sKey.find_first_of(',');
            iStringPostionTwo = sKey.find_last_of(',');

            iRowIndex = atoi(sKey.substr(0, iStringPostionOne).c_str());
            iVarOneIndex = atoi(sKey.substr(iStringPostionOne + 1, iStringPostionTwo).c_str());
            iVarTwoIndex = atoi(sKey.substr(iStringPostionTwo + 1).c_str());

            if ( iVarOneIndex == iVarTwoIndex)
            {
                dValue *= 2;
            }

            paiQCrows[iNumberOfQuadraticTerms] = iRowIndex;
            paiQCcols1[iNumberOfQuadraticTerms] = iVarOneIndex;
            paiQCcols2[iNumberOfQuadraticTerms] = iVarTwoIndex;

            padQCcoef[iNumberOfQuadraticTerms] = dValue ;//lindo' AD assumes that there is a 0.5 in front of quadratic matrix.
            iNumberOfQuadraticTerms ++;
        }

        if(!LSloadQCData(pModel_, nQCnnz, paiQCrows, paiQCcols1,
                         paiQCcols2, padQCcoef)) return true;
        else return false;
    }
    catch(const ErrorClass& eclass)
    {
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ;
    }
}  // end processQuadraticTerms



bool LindoSolver::processNonlinearExpressions()
{
    std::ostringstream outStr;

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, 
        "PROCESS NONLINEAR TERMS\n");
    osinstance->initializeNonLinearStructures( );
    //osinstance->addQTermsToExpressionTree();
    outStr.str("");
    outStr.clear();
    outStr  << "The number of objectives with nonlinear terms is:  " 
            << osinstance->getNumberOfNonlinearObjectives() << endl;
    outStr  << "The number of constraints with nonlinear terms is:  " 
            << osinstance->getNumberOfNonlinearConstraints() << endl << endl << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
    // first convert OS numbering of operators to Lindo numbering of operators.
    // this is done by the method setnlNodeIdxLindo()
    // execute the Macro that does the conversion between LINDO and OS op codes
    LINDO_OP_CODE_CONVERSION;
    /**
     * LINDO wants a unique list of the nonzero elements that appear in
     * the nonlinear terms. To do this we index on the nonzero element and point to a number
     * that counts where this unique element is in the list
     */
    std::map<double, int> mapNewNumber;

    /** pos is an iteratior for mapNewNumber */
    std::map<double, int>::iterator pos;

    /**
     * We don't know at compile time the number of instructions in a problem
     * use a vector to dynamically allocate the instructions (OP_Codes). This
     * eventually gets copied into a LINDO array paiInsList
     */
    std::vector<int> insList;


    /**
     * We get a map of all of the Expression trees where the index is row or objective number
     * that points to an expression tree for that row or objective function that contains
     * at least one nonlinear term.
     */
    std::map<int, OSExpressionTree*> allExpTrees;

    /**
     * The map allExpTrees indexes by row and objective function all of the expression
     * trees. For each nonlinear constraint or objective function we convert the associated
     * expresssion tree into a vector of OSnLNodes in postfix format
     */
    std::vector<OSnLNode*> postFixVec;

    /** define an iterator for the expression trees map allExpTrees */
    std::map<int, OSExpressionTree*>::iterator posTree;

    /**
     * KEY ASSUMPTION: We have already defined the model including all variables,
     * constraints, bounds, objective functions, etc.
     *
     * Define the local variables used by LINDO
     *
     */

    /** Direction of optimization */
    int *piObjSense = NULL;

    /** Lower bounds of variables. Since we aren't adding
     *	any new variables to our model, we can set this to NULL
     */
    double *padVarLowerBounds = NULL;

    /** Upper bounds of variables. Since we aren't adding
     *	any new variables to our model, we can set this to NULL
     */
    double *padVarUpperBounds = NULL;

    /**  The initial values of the variables */
    double  *padVarval = NULL;

    /** Variable type. Since we aren't adding
     *	any new variables to our model, we can set this to NULL
     */
    char *pachVarType = NULL;

    /** Constraint type Since we aren't changing or adding
    	the constraint types in our model, we can set this to NULL */
    char *pachConType = NULL;

    /** The number of nonzeros in the nonlinear terms is given by iNumNonlinearNonz */
    int iNumNonlinearNonz = 0;

    /** A pointer to the nonzeros in the nonlinear terms is given by padNonlinearNonz */
    double *padNonlinearNonz = NULL;

    /** The number of constraints with nonlinear terms is given by iNumberOfNonlinearConstraints*/
    int iNumberOfNonlinearConstraints = osinstance->getNumberOfNonlinearConstraints();

    /** A pointer to the start of each nonlinear constraint in the instructions list paiOp_Codes
     *  is given by paiConsBegin
     */
    int *paiConsBegin = NULL;
    if(iNumberOfNonlinearConstraints > 0) paiConsBegin = new int[ iNumberOfNonlinearConstraints];

    /** A pointer to the length of each nonlinear constraint in the instructions list paiOp_Codes
     *  is given by paiConsLength
     */
    int *paiConsLength = NULL;
    if(iNumberOfNonlinearConstraints > 0) paiConsLength = new int[ iNumberOfNonlinearConstraints];

    /** The number of objectives with nonlinear terms is given by iNumberOfNonlinearObjectives */
    int iNumberOfNonlinearObjectives = osinstance->getNumberOfNonlinearObjectives();

    /** A pointer to the start of each objective function in the instructions list paiOp_Codes
     *  is given by paiObjsBegin
     */
    int *paiObjsBegin = NULL;
    if(iNumberOfNonlinearObjectives > 0) paiObjsBegin = new int[ iNumberOfNonlinearObjectives];

    /** A pointer to the length of each objective function in the instructions list paiOp_Codes
     *  is given by paiObjsLength
     */
    int *paiObjsLength = NULL;
    if(iNumberOfNonlinearObjectives > 0) paiObjsLength = new int[ iNumberOfNonlinearObjectives];


    /**
     * The number of new variables in the nonlinear terms is given by iNumberOfNewVariables
     *  In our implementation we assume all the variables are added prior to adding the nonlinear
     *  terms so this should always be zero
     */
    int iNumberOfNewVariables = 0;

    /** The nonlinear terms are held in postfix format via op codes in the pointer array paiInsList */
    int *paiInsList;

    /** The length the instruction list, paiInstList is iInstListLength */
    int iInstListLength = 0;

    /** The length the instruction list, paiInstList is iInstListLength */
    int *paiNonlinearConIndex = NULL;
    if(iNumberOfNonlinearConstraints > 0) paiNonlinearConIndex = new int[ iNumberOfNonlinearConstraints];

    // end of local variable definition
    try
    {
        int i;
        // initialize constraint and objectives counters
        int iCountObjs = 0;
        int iCountCons = 0;
        // get all of the expression trees for each constraint and objective
        allExpTrees = osinstance->getAllNonlinearExpressionTreesMod();
        // now use an iterator to loop over all the expression trees
        for(posTree = allExpTrees.begin(); posTree != allExpTrees.end(); ++posTree)
        {
            outStr.str("");
            outStr.clear();
            outStr << "HERE IS EXPRESSION TREE " << posTree->first << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
            // get the expression tree and put it into a postfix vector of OSnLNodes
            postFixVec = posTree->second->m_treeRoot->getPostfixFromExpressionTree();
            int iVecSize = postFixVec.size();
            int iNodeID;
            if(iVecSize > 0)
            {
                for(i = 0; i < iVecSize; i++)
                {
                    iNodeID = postFixVec[i]->inodeInt;
                    switch (iNodeID)
                    {
                    case OS_SUM:  // the sum token
                        insList.push_back( nlNodeIdxLindo[ OS_SUM] );
                        insList.push_back( postFixVec[i]->inumberOfChildren);
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, "PUSH BACK A SUM\n");
                        break;
                    case OS_MAX:  // the sum token
                        insList.push_back( nlNodeIdxLindo[ OS_MAX] );
                        insList.push_back( postFixVec[i]->inumberOfChildren);
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, "PUSH BACK A MAX\n");
                        break;
                    case OS_PRODUCT:  // the product token
                        throw ErrorClass("Error: OS_PRODUCT operator not supported by Lindo");
                        break;
                    case OS_NUMBER:  // the number token
                        OSnLNodeNumber *numNode;
                        insList.push_back( EP_PUSH_NUM );
                        numNode = (OSnLNodeNumber*)postFixVec[i];
                        pos = mapNewNumber.find( numNode->value);
                        if(pos == mapNewNumber.end() )
                        {
                            outStr.str("");
                            outStr.clear();
                            outStr << "FOUND A NEW NUMBER  " << numNode->value << endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
                            insList.push_back( iNumNonlinearNonz);
                            mapNewNumber[ numNode->value] =  iNumNonlinearNonz++;
                        }
                        else insList.push_back( pos->second);
                        break;
                    case OS_VARIABLE:  // the variable token
                        OSnLNodeVariable *varNode;
                        insList.push_back( EP_PUSH_VAR );
                        varNode = (OSnLNodeVariable*)postFixVec[i];
                        insList.push_back( varNode->idx );
                        // If the variable has a coefficient other than 1 push back
                        // that coefficient plus a multiplier
                        if(varNode->coef != 1)
                        {
                            //push back the number
                            insList.push_back( EP_PUSH_NUM );
                            pos = mapNewNumber.find( varNode->coef);
                            if(pos == mapNewNumber.end() )
                            {
                                outStr.str("");
                                outStr.clear();
                                outStr << "FOUND A NEW NUMBER  " << varNode->coef << endl;
                                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
                                insList.push_back( iNumNonlinearNonz);
                                mapNewNumber[ varNode->coef] =  iNumNonlinearNonz++;
                            }
                            else insList.push_back( pos->second);
                            insList.push_back( EP_MULTIPLY);
                        }
                        break;
                    default:
                        insList.push_back( nlNodeIdxLindo[iNodeID] );
                        break;
                    }
                }//end for loop over the postfix vector of OSnLNodes
                //take appropriate action depending on whether we have a nonlinear obj or constraint
                if(posTree->first < 0)
                {
                    // process an objective function
                    // Kipp: what to do if more than one objective function -- issue an error
                    paiObjsBegin[ iCountObjs] = iInstListLength;
                    paiObjsLength[ iCountObjs] = insList.size() - iInstListLength;
                    iInstListLength = insList.size();
                    iCountObjs++;
                }
                else
                {
                    // process a constraint
                    paiConsBegin[ iCountCons] = iInstListLength;
                    paiConsLength[ iCountCons] = insList.size() - iInstListLength;
                    paiNonlinearConIndex[ iCountCons] = posTree->first;
                    outStr.str("");
                    outStr.clear();
                    outStr << "CONSTRAINT ILIST LENGTH =  " << iInstListLength << endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
                    iInstListLength = insList.size();
                    iCountCons++;
                }
            }
            postFixVec.clear();
        }//end for loop over the expression trees
        /* Number of real number constants */
        padNonlinearNonz = new double[ iNumNonlinearNonz];
        outStr.str("");
        outStr.clear();
        for(pos = mapNewNumber.begin(); pos != mapNewNumber.end(); ++pos)
        {
            padNonlinearNonz[ pos->second] = pos->first;
            outStr << "INDEX = " << pos->second  << " NUMBER = " << pos->first << endl;
        }
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
        // read instructions into a Lindo pointer
        paiInsList = new int[ iInstListLength];
        copy(insList.begin(), insList.end(), paiInsList);

        //
        // Lindo Solver variables
        int nLinearz, nAutoDeriv;
        /* Set linearization level, before a call to LSloadInstruct.
        	* If not specified, the solver will decide */
        nLinearz = 1;
        m_iLindoErrorCode = LSsetModelIntParameter (pModel_,
                            LS_IPARAM_NLP_LINEARZ, nLinearz);
        lindoAPIErrorCheck("Error trying to set the LS_IPARAM_NLP_LINEARZ parameter");

        /* Set up automatic differentiation, before a call to
        	* LSloadInstruct. If not specified, the numerical derivative
        	* will be applied */
        nAutoDeriv = 1;
        m_iLindoErrorCode = LSsetModelIntParameter (pModel_,
                            LS_IPARAM_NLP_AUTODERIV, nAutoDeriv);
        lindoAPIErrorCheck("Error trying to set the LS_IPARAM_NLP_AUTODERIV parameter");
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "iNumberOfNonlinearConstraints=  " << iNumberOfNonlinearConstraints << std::endl;
        outStr << "iNumberOfNonlinearObjectives=  " << iNumberOfNonlinearObjectives << std::endl;
        outStr << "iNumberOfNewVariables = " << iNumberOfNewVariables << std::endl;
        outStr << "iNumNonlinearNonz =  " << iNumNonlinearNonz << std::endl;
        outStr << "piObjSense =  " << "NULL" << std::endl ;
        outStr << "pachConType =  " << "NULL" << std::endl ;
        outStr << "pachVarType =  " << "NULL" << std::endl ;
        int kl;
        outStr << "Here is the instruction list" << std::endl;
        for(kl = 0; kl < iInstListLength; kl++)
        {
            outStr << "instruction list num  " << paiInsList[ kl] << endl;
        }
        outStr << "Number of terms in instruction list " << iInstListLength << std::endl;
        outStr << "Here are the constraint indices " << std::endl;
        for(kl = 0; kl < iNumberOfNonlinearConstraints; kl++)
        {
            outStr << "con idx  " << paiNonlinearConIndex[ kl] << endl;
        }
        outStr << "Here come the nonlinear nonzeros " <<  std::endl;
        for(kl = 0; kl < iNumNonlinearNonz; kl++)
        {
            outStr << "nonz value  =   " << padNonlinearNonz[ kl] << endl;
        }
        outStr << "padVarval =  " << "NULL" << std::endl ;
        for(kl = 0; kl < iNumberOfNonlinearObjectives; kl++)
        {
            outStr << "obj inst begin  =   " << paiObjsBegin[ kl] << endl;
        }
        for(kl = 0; kl < iNumberOfNonlinearObjectives; kl++)
        {
            outStr << "obj inst list length  =   " << paiObjsLength[ kl] << endl;
        }
        for(kl = 0; kl < iNumberOfNonlinearConstraints; kl++)
        {
            outStr << "constraint inst begin  =   " << paiConsBegin[ kl] << endl;
        }
        for(kl = 0; kl < iNumberOfNonlinearConstraints; kl++)
        {
            outStr << "constraints inst list length  =   " << paiConsLength[ kl] << endl;
        }
        outStr << "padVarLowerBounds =  " << "NULL" << std::endl ;
        outStr << "padUpperBounds =  " << "NULL" << std::endl ;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
        m_iLindoErrorCode = LSaddInstruct (pModel_, iNumberOfNonlinearConstraints,
                                           iNumberOfNonlinearObjectives, iNumberOfNewVariables, iNumNonlinearNonz,
                                           piObjSense, pachConType,  pachVarType, paiInsList, iInstListLength, paiNonlinearConIndex,
                                           padNonlinearNonz, padVarval, paiObjsBegin, paiObjsLength, paiConsBegin,
                                           paiConsLength, padVarLowerBounds, padVarUpperBounds);
        lindoAPIErrorCheck("Error trying to call LSaddInstruct");
        // Kipp: do some garbage collection
        // get rid of the local news
        //mapNewNumber.~map();
        if( iNumberOfNonlinearConstraints > 0) delete[] paiConsBegin;
        if( iNumberOfNonlinearConstraints > 0) delete[] paiConsLength;
        if( iNumberOfNonlinearObjectives  > 0) delete[] paiObjsBegin;
        if( iNumberOfNonlinearObjectives  > 0) delete[] paiObjsLength;
        if( iNumberOfNonlinearConstraints > 0) delete[] paiNonlinearConIndex;
        if( iNumNonlinearNonz > 0) delete[] padNonlinearNonz;
        if(  iInstListLength > 0) delete[] paiInsList;
        mapNewNumber.clear();
        //mapNewNumber.~map();
        allExpTrees.clear();
        //allExpTrees.~map();
        insList.clear();
        //insList.~vector<int>();
        postFixVec.clear();
        //postFixVec.~vector<OSnLNode*>();
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ;
    }
}//end processNonlinearExpressions



void LindoSolver::dataEchoCheck()
{
    int i;
    std::ostringstream outStr;

    // print out problem parameters
    outStr << "This is problem:  " << osinstance->getInstanceName() << endl;
    outStr << "The problem source is:  " << osinstance->getInstanceSource() << endl;
    outStr << "The problem description is:  " << osinstance->getInstanceDescription() << endl;
    outStr << "number of variables = " << osinstance->getVariableNumber() << endl;
    outStr << "number of Rows = " << osinstance->getConstraintNumber() << endl;

    // print out the variable information
    if(osinstance->getVariableNumber() > 0)
    {
        for(i = 0; i < osinstance->getVariableNumber(); i++)
        {
            if(osinstance->getVariableNames() != NULL) outStr << "variable Names  " << osinstance->getVariableNames()[ i]  << endl;
            if(osinstance->getVariableTypes() != NULL) outStr << "variable Types  " << osinstance->getVariableTypes()[ i]  << endl;
            if(osinstance->getVariableLowerBounds() != NULL) outStr << "variable Lower Bounds  " << osinstance->getVariableLowerBounds()[ i]  << endl;
            if(osinstance->getVariableUpperBounds() != NULL) outStr << "variable Upper Bounds  " <<  osinstance->getVariableUpperBounds()[i] << endl;
        }
    }

    // print out objective function information
    if(osinstance->getVariableNumber() > 0 || osinstance->instanceData->objectives->obj != NULL || osinstance->instanceData->objectives->numberOfObjectives > 0)
    {
        if( osinstance->getObjectiveMaxOrMins()[0] == "min")  outStr <<  "problem is a minimization" << endl;
        else outStr <<  "problem is a maximization" << endl;
        for(i = 0; i < osinstance->getVariableNumber(); i++)
        {
            outStr << "OBJ COEFFICIENT =  " <<  osinstance->getDenseObjectiveCoefficients()[0][i] << endl;
        }
    }
    // print out constraint information
    if(osinstance->getConstraintNumber() > 0)
    {
        for(i = 0; i < osinstance->getConstraintNumber(); i++)
        {
            if(osinstance->getConstraintNames() != NULL) outStr << "row name = " << osinstance->getConstraintNames()[i] <<  endl;
            if(osinstance->getConstraintLowerBounds() != NULL) outStr << "row lower bound = " << osinstance->getConstraintLowerBounds()[i] <<  endl;
            if(osinstance->getConstraintUpperBounds() != NULL) outStr << "row upper bound = " << osinstance->getConstraintUpperBounds()[i] <<  endl;
        }
    }

    // print out linear constraint data
    outStr << endl;
    outStr << "number of nonzeros =  " << osinstance->getLinearConstraintCoefficientNumber() << endl;
    if(osinstance->getLinearConstraintCoefficientNumber() > 0)
    {
        for(i = 0; i <= osinstance->getVariableNumber(); i++)
        {
            outStr << "Start Value =  " << osinstance->getLinearConstraintCoefficientsInColumnMajor()->starts[ i] << endl;
        }
        outStr << endl;
        for(i = 0; i < osinstance->getLinearConstraintCoefficientNumber(); i++)
        {
            outStr << "Index Value =  " << osinstance->getLinearConstraintCoefficientsInColumnMajor()->indexes[i] << endl;
            outStr << "Nonzero Value =  " << osinstance->getLinearConstraintCoefficientsInColumnMajor()->values[i] << endl;
        }
    }
    // print out quadratic data
    outStr << "number of qterms =  " <<  osinstance->getNumberOfQuadraticTerms() << endl;
    for(int i = 0; i <  osinstance->getNumberOfQuadraticTerms(); i++)
    {
        outStr << "Row Index = " <<  osinstance->getQuadraticTerms()->rowIndexes[i] << endl;
        outStr << "Var Index 1 = " << osinstance->getQuadraticTerms()->varOneIndexes[ i] << endl;
        outStr << "Var Index 2 = " << osinstance->getQuadraticTerms()->varTwoIndexes[ i] << endl;
        outStr << "Coefficient = " << osinstance->getQuadraticTerms()->coefficients[ i] << endl;
    }
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());

} // end dataEchoCheck

void  LindoSolver::lindoAPIErrorCheck(std::string errormsg)
{
    try
    {
        ostringstream outStr;
        std::string error = errormsg;
        char lindoerrormsg[LS_MAX_ERROR_MESSAGE_LENGTH];
        if(m_iLindoErrorCode != 0)
        {
            outStr << endl;
            error = "LINDO ERROR: "+ error;
            outStr << error << endl;
            outStr << "LINDO ERROR NUMBER: " << m_iLindoErrorCode << endl;
            if( pEnv_ != NULL) LSgetErrorMessage(pEnv_, m_iLindoErrorCode, lindoerrormsg);
            error = lindoerrormsg;
            outStr << "LINDO ERROR MESSAGE: "  <<  error;
            outStr << endl;
            error = outStr.str();
            throw ErrorClass( error);
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end lindoAPIErrorCheck






