/* $Id$ */
/** @file CoinSolver.cpp
 *
 * \brief This file defines the CoinSolver class.
 * \detail Read an OSInstance object and convert to COIN data structures
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2013, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#include "OSCoinSolver.h"
#include "OSInstance.h"
#include "OSFileUtil.h"
#include "OSOutput.h"
#include "CoinTime.hpp"
#include "CglPreProcess.hpp"
#include "CglGomory.hpp"
#include "CglSimpleRounding.hpp"
#include "CglMixedIntegerRounding2.hpp"
#include "CglKnapsackCover.hpp"
#include "CglFlowCover.hpp"
#include "CbcBranchActual.hpp" //for CbcSOS
#include "CoinMessageHandler.hpp"
#include "CoinMessage.hpp"

#include "OsiClpSolverInterface.hpp"
#include "CoinWarmStartBasis.hpp"

#ifdef COIN_HAS_SYMPHONY
#include "OsiSymSolverInterface.hpp"
#endif

#ifdef COIN_HAS_VOL
#include "OsiVolSolverInterface.hpp"
#endif

#ifdef COIN_HAS_DYLP
#include "OsiDylpSolverInterface.hpp"
#endif

#ifdef COIN_HAS_GLPK
#include "OsiGlpkSolverInterface.hpp"
#endif

#ifdef COIN_HAS_CPX
#include "OsiCpxSolverInterface.hpp"
#endif

#ifdef COIN_HAS_GRB
#include "OsiGrbSolverInterface.hpp"
#endif

#ifdef COIN_HAS_MSK
#include "OsiMskSolverInterface.hpp"
#endif

#ifdef COIN_HAS_SOPLEX
#include "OsiSpxSolverInterface.hpp"
#endif

#ifdef COIN_HAS_XPR
#include "OsiXprSolverInterface.hpp"
#endif

#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSMathUtil.h"

#include <map>

#include <iostream>
#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif

using std::cout;
using std::endl;
using std::ostringstream;



CoinSolver::CoinSolver() :
    osiSolver(NULL),
    m_osilreader(NULL),
    m_osolreader(NULL),
    m_CoinPackedMatrix(NULL),
    cbc_argv( NULL),
    num_cbc_argv( 0),
    cpuTime( 0)
{
    osrlwriter = new OSrLWriter();
}

CoinSolver::~CoinSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "inside CoinSolver destructor\n");
#endif
    if(m_osilreader != NULL) delete m_osilreader;
    m_osilreader = NULL;
    if(m_osolreader != NULL) delete m_osolreader;
    m_osolreader = NULL;
    delete m_CoinPackedMatrix;
    m_CoinPackedMatrix = NULL;
    delete osiSolver;
    if(osiSolver != NULL) osiSolver = NULL;
    delete osrlwriter;
    osrlwriter = NULL;
    delete osresult;
    osresult = NULL;
    if(num_cbc_argv > 0)
    {
/* ----- 
        int i;
        for(i = 0; i < num_cbc_argv; i++)
        {
            delete cbc_argv[ i];
        }
        delete[] cbc_argv;
  ----- */
        cbc_argv = NULL;
    }
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, "Leaving CoinSolver destructor\n");
#endif
}


void CoinSolver::buildSolverInstance() throw (ErrorClass)
{
    std::ostringstream outStr;
    try
    {
        if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
        clock_t start, finish;
        double duration;
        start = clock();
        if(osinstance == NULL)
        {
            m_osilreader = new OSiLReader();
            osinstance = m_osilreader->readOSiL( osil);
        }
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;

    // Can't handle multiobjective problems properly --- especially nonlinear ones
    if (osinstance->getObjectiveNumber() > 1)
            throw ErrorClass("Solver cannot handle multiple objectives --- please delete all but one");

        // get the type of solver requested from OSoL string
        if (sSolverName == "clp")
            osiSolver = new OsiClpSolverInterface();

        else if (sSolverName == "cbc")
            osiSolver = new OsiClpSolverInterface();

        else if (sSolverName == "vol")
            #ifdef COIN_HAS_VOL
                osiSolver = new OsiVolSolverInterface();
            #else
                throw ErrorClass("This OSSolverService was built without solver vol");
            #endif

        else if (sSolverName == "cplex")
            #ifdef COIN_HAS_CPX
                osiSolver = new OsiCpxSolverInterface();
            #else
                throw ErrorClass("This OSSolverService was built without solver cplex");
            #endif

        else if (sSolverName == "gurobi")
            #ifdef COIN_HAS_GRB
                osiSolver = new OsiGrbSolverInterface();
            #else
                throw ErrorClass("This OSSolverService was built without solver gurobi");
            #endif

        else if (sSolverName == "mosek")
            #ifdef COIN_HAS_MSK
                osiSolver = new OsiMskSolverInterface();
            #else
                throw ErrorClass("This OSSolverService was built without solver mosek");
            #endif

        else if (sSolverName == "soplex")
            #ifdef COIN_HAS_SOPLEX
                osiSolver = new OsiSpxSolverInterface();
            #else
                throw ErrorClass("This OSSolverService was built without solver soplex");
            #endif

        else if (sSolverName == "xpress")
            #ifdef COIN_HAS_XPR
                osiSolver = new OsiXprSolverInterface();
            #else
                throw ErrorClass("This OSSolverService was built without solver xpress");
            #endif

        else if (sSolverName == "glpk")
            #ifdef COIN_HAS_GLPK
                osiSolver = new OsiGlpkSolverInterface();
            #else
                throw ErrorClass("This OSSolverService was built without solver glpk");
            #endif

        else if (sSolverName == "dylp")
            #ifdef COIN_HAS_DYLP
                osiSolver = new OsiDylpSolverInterface();
            #else
                throw ErrorClass("This OSSolverService was built without solver dylp");
            #endif

        else if (sSolverName == "symphony")
            #ifdef COIN_HAS_SYMPHONY
                osiSolver = new OsiSymSolverInterface();
            #else
                throw ErrorClass("This OSSolverService was built without solver symphony");
            #endif

        else if (sSolverName == "")
        {   // default solver is Clp in continuous case,
            // Cbc for an integer program
            if( osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0 ||
                                  sSolverName.find( "cbc") != std::string::npos    ) sSolverName = "cbc";
            else sSolverName = "clp";
            osiSolver = new OsiClpSolverInterface();
        }
        else
            throw ErrorClass("Solver selected is not supported by this version of OSSolverService");

        // first check the various solvers and see if they are of the proper problem type
        if ( (osinstance->getNumberOfNonlinearExpressions() > 0) )
        {
            throw ErrorClass( "This COIN-OR Solver is not configured for nonlinear programming");
        }
        if ((osinstance->getNumberOfQuadraticTerms() > 0) && 
            (sSolverName.find( "cbc") == std::string::npos) && (sSolverName.find( "clp") == std::string::npos))
        {
            throw ErrorClass( "This COIN-OR Solver is not configured for quadratic programming");
        }
        // throw an exception if we have a solver that cannot do integer programming
        if( osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0)
        {
            if( sSolverName.find("clp") != std::string::npos) throw ErrorClass( "Clp cannot do integer programming");
            if( sSolverName.find("vol") != std::string::npos) throw ErrorClass( "Vol cannot do integer programming");
            if( sSolverName.find("dylp") != std::string::npos) throw ErrorClass( "DyLP cannot do integer programming");
            if( sSolverName.find("soplex") != std::string::npos) throw ErrorClass( "SoPlex cannot do integer programming");
        }
        // throw an exception if we have a solver that cannot handle semi-continuous or semi-integer variables
        if( osinstance->getNumberOfSemiIntegerVariables() + osinstance->getNumberOfSemiContinuousVariables() > 0)
        {
            throw ErrorClass( "Semi-integer and semi-continuous variables not supported");
            //if( sSolverName.find("clp") != std::string::npos) throw ErrorClass( "Clp cannot do semi-integer variables");
            //if( sSolverName.find("vol") != std::string::npos) throw ErrorClass( "Vol cannot do semi-integer variables");
            //if( sSolverName.find("dylp") != std::string::npos) throw ErrorClass( "DyLP cannot do semi-integer variables");
            //if( sSolverName.find("soplex") != std::string::npos) throw ErrorClass( "SoPlex cannot do semi-integer variables");
        }
        // check other trivial solver limitations
        //if(osinstance->getConstraintNumber() <= 0)throw ErrorClass("Coin solver:" + sSolverName +" cannot handle unconstrained problems");
        //if(osinstance->getVariableNumber() <= 0)throw ErrorClass("Coin solver requires decision variables");
        if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Coin solver: " + sSolverName + " needs an objective function");
        if(osinstance->getNumberOfStringVariables() > 0) throw ErrorClass("Coin solver: " + sSolverName + " can only handle numeric variables");
        if(osinstance->getLinearConstraintCoefficientNumber() <= 0 && sSolverName == "symphony") throw ErrorClass("Coin solver: " + sSolverName +   " needs a positive number of constraints");

        if(!setCoinPackedMatrix() ) throw ErrorClass("Problem generating coin packed matrix");
        osiSolver->loadProblem(*m_CoinPackedMatrix, osinstance->getVariableLowerBounds(),
                               osinstance->getVariableUpperBounds(),
                               osinstance->getDenseObjectiveCoefficients()[0],
                               osinstance->getConstraintLowerBounds(), osinstance->getConstraintUpperBounds()
                              );
#ifndef NDEBUG
        //dataEchoCheck();
#endif
        if( osinstance->getObjectiveMaxOrMins()[0] == "min") osiSolver->setObjSense(1.0);
        else osiSolver->setObjSense(-1.0);
        // set the integer variables
        int numOfIntVars = osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables();
        if (numOfIntVars > 0)
        {
            int *intIndex = NULL;
            int i = 0;
            int k = 0;
            char *varType;
            intIndex = new int[ numOfIntVars];
            varType = osinstance->getVariableTypes();
            for(i = 0; i < osinstance->getVariableNumber(); i++)
            {
                if( (varType[i] == 'B') || (varType[i]) == 'I' )
                {
                    intIndex[k++] = i;
                }
            }
            osiSolver->setInteger( intIndex,  numOfIntVars);

            delete[] intIndex;
            intIndex = NULL;
        }

        // the clpSolver supports quadratic objectives if present in the input    
        int nq = osinstance->getNumberOfQuadraticTerms();
        if (nq > 0)
        {
            if ( (sSolverName.find("clp") != std::string::npos) || (sSolverName.find("clp") != std::string::npos) )
            {
                // must get the quadratic data, verify objective terms only, and convert to sparse matrix format
                QuadraticTerms* qterms = osinstance->getQuadraticTerms();


#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "original arrays:" << std::endl;
                outStr << "  var One indexes:";
                for (int i=0; i<nq; i++)
                    outStr << "  " << qterms->varOneIndexes[i];
                outStr << std::endl;
                outStr << "  var Two indexes:";
                for (int i=0; i<nq; i++)
                    outStr << "  " << qterms->varTwoIndexes[i];
                outStr << std::endl;
                outStr << "  coefficients:   ";
                for (int i=0; i<nq; i++)
                    outStr << "  " << qterms->coefficients[i];
                outStr << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif


                int  ncols = osinstance->getVariableNumber(); 
                int* colStarts = new int[ncols+1];
                for (int i=0; i<=ncols; i++)
                    colStarts[i] = 0;

                //get column lengths
                for (int i=0; i<nq; i++)
                {
                    if (qterms->rowIndexes[i] != -1)
                        throw ErrorClass("Clp solver cannot handle quadratic terms in the constraints");
                    else
                        colStarts[qterms->varOneIndexes[i]+1] += 1;
                }

                // convert column lengths to column starts
                for (int i=0; i<ncols; i++)
                    colStarts[i+1] += colStarts[i];

                // sort the varOneIndexes array in ascending order
                // assumptions: 1. Most likely the quadratic terms are sorted already
                // 2. The order of varTwoIndexes within varOneIndexes does not matter
                int swapLoc;
                int iswap;
                double dswap;
                for (int i=0; i< ncols-1; i++)
                {
                    swapLoc = colStarts[i+1];
                    for (int j=colStarts[i]; j<colStarts[i+1]; j++)
                    {
                        if (qterms->varOneIndexes[j] != i)
                        {
                            while ( (qterms->varOneIndexes[swapLoc] != i) && (swapLoc < nq))
                                swapLoc++;
                            if (swapLoc < nq)
                            {
                                iswap = qterms->varOneIndexes[j];
                                qterms->varOneIndexes[j] = qterms->varOneIndexes[swapLoc];
                                qterms->varOneIndexes[swapLoc] = iswap;
                                iswap = qterms->varTwoIndexes[j];
                                qterms->varTwoIndexes[j] = qterms->varTwoIndexes[swapLoc];
                                qterms->varTwoIndexes[swapLoc] = iswap;
                                dswap = qterms->coefficients[j];
                                qterms->coefficients[j] = qterms->coefficients[swapLoc];
                                qterms->coefficients[swapLoc] = dswap;
#ifndef NDEBUG
                                outStr.str("");
                                outStr.clear();
                                outStr << "swapping locations " << j << " and " << swapLoc << std::endl;
                
                                outStr << "after swap:" << std::endl;
                                outStr << "  var One indexes:";
                                for (int i=0; i<nq; i++)
                                    outStr << "  " << qterms->varOneIndexes[i];
                                outStr << std::endl;
                                outStr << "  var Two indexes:";
                                for (int i=0; i<nq; i++)
                                    outStr << "  " << qterms->varTwoIndexes[i];
                                outStr << std::endl;
                                outStr << "  coefficients:   ";
                                for (int i=0; i<nq; i++)
                                    outStr << "  " << qterms->coefficients[i];
                                outStr << std::endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str()); 
#endif
                            }
                            else
                                throw ErrorClass("Sorting of quadratic terms failed in OSCoinSolver");
                        }
                    }
                }
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "terminal arrays:" << std::endl;
                outStr << "  var One indexes:";
                for (int i=0; i<nq; i++)
                    outStr << "  " << qterms->varOneIndexes[i];
                outStr << std::endl;
                outStr << "  var Two indexes:";
                for (int i=0; i<nq; i++)
                    outStr << "  " << qterms->varTwoIndexes[i];
                outStr << std::endl;
                outStr << "  coefficients:   ";
                for (int i=0; i<nq; i++)
                    outStr << "  " << qterms->coefficients[i];
                outStr << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str()); 
#endif

                //osiSolver->loadQuadraticObjective(ncols, colStarts, qterms->varTwoIndexes, qterms->coefficients);
                throw ErrorClass("Quadratic terms not implemented yet");
            }               
        }

        bCallbuildSolverInstance = true;
    }
    catch(const ErrorClass& eclass)
    {
        osresult = new OSResult();
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//end buildSolverInstance()



void CoinSolver::setSolverOptions() throw (ErrorClass)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "build solver options\n");
#endif
    this->bSetSolverOptions = true;
    // the osi maps
    // the OsiHintParameter Map
    std::map<std::string, OsiHintParam> hintParamMap;
    hintParamMap["OsiDoPresolveInInitial"] = OsiDoPresolveInInitial;
    hintParamMap["OsiDoDualInInitial"] = OsiDoDualInInitial;
    hintParamMap["OsiDoPresolveInResolve"] = OsiDoPresolveInResolve;
    hintParamMap["OsiDoDualInResolve"] = OsiDoDualInResolve;
    hintParamMap["OsiDoScale"] = OsiDoScale;
    hintParamMap["OsiDoCrash"] = OsiDoCrash;
    hintParamMap["OsiDoReducePrint"] = OsiDoReducePrint;
    hintParamMap["OsiDoInBranchAndCut"] =  OsiDoInBranchAndCut;
    hintParamMap["OsiLastHintParam"] = OsiLastHintParam;
    //
    // the OsiHintStrength Map
    std::map<std::string, OsiHintStrength> hintStrengthMap;
    hintStrengthMap["OsiHintIgnore"] = OsiHintIgnore;
    hintStrengthMap["OsiHintTry"] = OsiHintTry;
    hintStrengthMap["OsiHintDo"] = OsiHintDo;
    hintStrengthMap["OsiForceDo"] = OsiForceDo;
    //
    // the OsiStrParam Map
    std::map<std::string, OsiStrParam> strParamMap;
    strParamMap["OsiProbName"] = OsiProbName;
    strParamMap["OsiSolverName"] = OsiSolverName;
    strParamMap["OsiLastStrParam"] = OsiLastStrParam;
    //
    // the OsiDblParam Map
    std::map<std::string, OsiDblParam>  dblParamMap;
    dblParamMap["OsiDualObjectiveLimit"] = OsiDualObjectiveLimit;
    dblParamMap["OsiPrimalObjectiveLimit"] = OsiPrimalObjectiveLimit;
    dblParamMap["OsiDualTolerance"] = OsiDualTolerance;
    dblParamMap["OsiPrimalTolerance"] = OsiPrimalTolerance;
    dblParamMap["OsiObjOffset"] = OsiObjOffset;
    dblParamMap["OsiLastDblParam"] = OsiLastDblParam;
    //
    //
    // the OsiIntParam Map
    std::map<std::string, OsiIntParam>  intParamMap;
    intParamMap["OsiMaxNumIteration"] = OsiMaxNumIteration;
    intParamMap["OsiMaxNumIterationHotStart"] = OsiMaxNumIterationHotStart;
    intParamMap["OsiNameDiscipline"] = OsiNameDiscipline;
    intParamMap["OsiLastIntParam"] = OsiLastIntParam;
    //
    //
    // initialize low level of printing


    /*
     * start default settings -- these get set
     * even when the OSOption object is NULL
     *
     * */
    OsiHintStrength hintStrength = OsiHintTry; //don't want too much output
    osiSolver->setHintParam(OsiDoReducePrint, true, hintStrength);
    // it looks like the COIN-OR default is to subtract off the constant rather than add it.
    // this seems true regardless of max or min
    osiSolver->setDblParam(OsiObjOffset, -osinstance->getObjectiveConstants()[0]);



    // treat symphony differently
#ifdef COIN_HAS_SYMPHONY
    if( sSolverName.find( "symphony") != std::string::npos)
    {
        OsiSymSolverInterface * si =
            dynamic_cast<OsiSymSolverInterface *>(osiSolver) ;
        //set default verbosity to -2
        si->setSymParam("verbosity",   -2);
    }
#endif       //symphony end    
    /*
     * end default settings
     *
     */

    //
    try
    {
        if(osoption == NULL && osol.length() > 0)
        {
            m_osolreader = new OSoLReader();
            osoption = m_osolreader->readOSoL( osol);
        }

        if(osoption != NULL)
        {
            int i;

#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "number of solver options " << osoption->getNumberOfSolverOptions() << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            if( osoption->getNumberOfSolverOptions() > 0)
            {
                //this->bSetSolverOptions = true;
                std::vector<SolverOption*> optionsVector;

                //get the osi options, which apply to all solvers
                optionsVector = osoption->getSolverOptions( "osi",true);
                int num_osi_options = optionsVector.size();
                char *pEnd;
                bool yesNo;

/**
 *  In this first pass through the options just see if the hintStrength was set
 *
 */
                for(i = 0; i < num_osi_options; i++)
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "osi solver option  "  << optionsVector[ i]->name  << std::endl;
                    outStr << "osi solver value   "  << optionsVector[ i]->value << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                    if (optionsVector[ i]->type == "OsiHintStrength" )
                    {
                        if( hintStrengthMap.find( optionsVector[ i]->name ) != hintStrengthMap.end() )
                        {
                            hintStrength = hintStrengthMap[ optionsVector[ i]->name] ;
                        }
                    }
                }

/**
 *  If the hintStrength was set, use it when processing the other options
 */
                for(i = 0; i < num_osi_options; i++)
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "osi solver option  "  << optionsVector[ i]->name  << std::endl;
                    outStr << "osi solver value   "  << optionsVector[ i]->value << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                    if (optionsVector[ i]->type == "OsiHintParam" )
                    {
                        if( optionsVector[ i]->value == "true" )
                        {
                            yesNo = true;
                        }
                        else
                        {
                            yesNo = false;
                        }
                        if( hintParamMap.find( optionsVector[ i]->name ) != hintParamMap.end() )
                        {
                            osiSolver->setHintParam( hintParamMap[ optionsVector[ i]->name] , yesNo, hintStrength);
                        }
                    }
                    else if(optionsVector[ i]->type == "OsiStrParam" )
                    {
                        if( strParamMap.find( optionsVector[ i]->name ) != strParamMap.end() )
                        {
                            osiSolver->setStrParam( strParamMap[ optionsVector[ i]->name] , optionsVector[ i]->value);
                        }
                    }
                    else if(optionsVector[ i]->type == "OsiDblParam" )
                    {
                        if( dblParamMap.find( optionsVector[ i]->name ) != dblParamMap.end() )
                        {
                            osiSolver->setDblParam( dblParamMap[ optionsVector[ i]->name] , os_strtod( optionsVector[ i]->value.c_str(), &pEnd ));
                        }
    
                    }
                    else if(optionsVector[ i]->type == "OsiIntParam" )
                    {
                        if( intParamMap.find( optionsVector[ i]->name ) != intParamMap.end() )
                        {
                            osiSolver->setIntParam( intParamMap[ optionsVector[ i]->name] , atoi( optionsVector[ i]->value.c_str() ) );
                        }
                    }
                    else if (optionsVector[ i]->type == "bool" )
                    {
                        if( optionsVector[ i]->name == "primalSimplex" )
                        {
                            if (optionsVector[ i]->value != "false")
                            osiSolver->enableSimplexInterface((optionsVector[ i]->value != "false"));
                        }
                    }
                }

                // treat Cbc separately to take advantage of CbcMain1()

                if( sSolverName.find( "cbc") != std::string::npos)
                {
                    // get Cbc options
                    if(optionsVector.size() > 0) optionsVector.clear();
                    optionsVector = osoption->getSolverOptions( "cbc",true);

                    int num_cbc_options = optionsVector.size();
                    char *cstr;
                    std::string cbc_option;
                    num_cbc_argv = optionsVector.size() + 3;
                    cbc_argv = new const char*[ num_cbc_argv];

                    // the first option
                    cbc_option = "OS";
                    cstr = new char [cbc_option.size() + 1];
                    strcpy (cstr, cbc_option.c_str());
                    cbc_argv[ 0] = cstr;
    
                    for(i = 0; i < num_cbc_options; i++)
                    {
#ifndef NDEBUG
                        outStr.str("");
                        outStr.clear();
                        outStr << "cbc solver option  "  << optionsVector[ i]->name << std::endl;
                        outStr << "cbc solver value   "  << optionsVector[ i]->name << std::endl;
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

                        if(optionsVector[ i]->value.length() > 0 )
                        {
                            cbc_option = "-" + optionsVector[ i]->name +"="+optionsVector[ i]->value;
                        }
                        else
                        {
                            cbc_option = "-" + optionsVector[ i]->name ;
                        }
                        cstr = new char [cbc_option.size() + 1];
                        strcpy (cstr, cbc_option.c_str());
                        cbc_argv[i +  1] = cstr;
                    }

                    // the solve option
                    cbc_option = "-solve";
                    cstr = new char [cbc_option.size() + 1];
                    strcpy (cstr, cbc_option.c_str());
                    cbc_argv[ num_cbc_argv - 2] = cstr;
    
                    // the quit option
                    cbc_option = "-quit";
                    cstr = new char [cbc_option.size() + 1];
                    strcpy (cstr, cbc_option.c_str());
                    cbc_argv[ num_cbc_argv - 1] = cstr;

                }//end of cbc if


                // also need to treat SYMPHONY differently

#ifdef COIN_HAS_SYMPHONY
                if(optionsVector.size() > 0) optionsVector.clear();
                //if( !optionsVector.empty() ) optionsVector.clear();
                //first the number of processors -- applies only to SYMPHONY
                if( sSolverName.find( "symphony") != std::string::npos)
                {
                    OsiSymSolverInterface * si =
                        dynamic_cast<OsiSymSolverInterface *>(osiSolver) ;
                    optionsVector = osoption->getSolverOptions( "symphony",true);
                    int num_sym_options = optionsVector.size();
                    for(i = 0; i < num_sym_options; i++)
                    {
#ifndef NDEBUG
                        outStr.str("");
                        outStr.clear();
                        outStr << "symphony solver option  "  << optionsVector[ i]->name << std::endl;
                        outStr << "symphony solver value   "  << optionsVector[ i]->name << std::endl;
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                        si->setSymParam(optionsVector[ i]->name,   optionsVector[ i]->value);
                    }
                }
#endif      //symphony end            

            }
            //now set initial values
            int n,m,k;
            if (osoption != NULL)
                m = osoption->getNumberOfInitVarValues();
            else
                m = 0;
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "number of variables initialed: " << m << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

            if (m > 0)
            {
#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "get initial values\n");
#endif
                n = osinstance->getVariableNumber();
                double* denseInitVarVector;
                denseInitVarVector = new double[n];
                bool* initialed;
                initialed = new bool[n];

                for(k = 0; k < n; k++)
                    initialed[k] = false;

                InitVarValue**  initVarVector = osoption->getInitVarValuesSparse();
#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "done\n");
#endif

                double initval;
                for(k = 0; k < m; k++)
                {
                    i = initVarVector[k]->idx;
                    if (initVarVector[k]->idx >= n)
                        throw ErrorClass ("Illegal index value in variable initialization");

                    initval = initVarVector[k]->value;
                    if (osinstance->instanceData->variables->var[k]->ub == OSDBL_MAX)
                    {
                        if (osinstance->instanceData->variables->var[k]->lb > initval)
                            throw ErrorClass ("Initial value outside of bounds");
                    }
                    else if (osinstance->instanceData->variables->var[k]->lb == -OSDBL_MAX)
                    {
                        if (osinstance->instanceData->variables->var[k]->ub < initval)
                            throw ErrorClass ("Initial value outside of bounds");
                    }
                    else
                    {
                        if ((osinstance->instanceData->variables->var[k]->lb > initval) ||
                                (osinstance->instanceData->variables->var[k]->ub < initval))
                            throw ErrorClass ("Initial value outside of bounds");
                    }

                    denseInitVarVector[initVarVector[k]->idx] = initval;
                    initialed[initVarVector[k]->idx] = true;
                }

                double default_initval;
                default_initval = 0.0;

                for(k = 0; k < n; k++)
                {
                    if (!initialed[k])
                    {
                        if (osinstance->instanceData->variables->var[k]->ub == OSDBL_MAX)
                            if (osinstance->instanceData->variables->var[k]->lb <= default_initval)
                                denseInitVarVector[k] = default_initval;
                            else
                                denseInitVarVector[k] = osinstance->instanceData->variables->var[k]->lb;
                        else if (osinstance->instanceData->variables->var[k]->lb == -OSDBL_MAX)
                            if (osinstance->instanceData->variables->var[k]->ub >= default_initval)
                                denseInitVarVector[k] = default_initval;
                            else
                               denseInitVarVector[k] = osinstance->instanceData->variables->var[k]->ub;
                        else if ((osinstance->instanceData->variables->var[k]->lb <= default_initval) &&
                                 (osinstance->instanceData->variables->var[k]->ub >= default_initval))
                            denseInitVarVector[k] = default_initval;
                        else if (osinstance->instanceData->variables->var[k]->lb > default_initval)
                            denseInitVarVector[k] = osinstance->instanceData->variables->var[k]->lb;
                        else
                            denseInitVarVector[k] = osinstance->instanceData->variables->var[k]->ub;
                    }
//                    denseInitVarVector[k] = default_initval;
//                    denseInitVarVector[k] = osinstance->instanceData->variables->var[k]->lb;
                }
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "set initial values: " << std::endl;
                for (k=0; k < n; k++)
                    outStr << "  " << k << ": " << denseInitVarVector[k] << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                osiSolver->setColSolution( denseInitVarVector);
                delete[] denseInitVarVector;
                delete[] initialed;
#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "done\n");
#endif

            }  //  end set initial variable values


            // add starting basis --- only supported by Clp

//            if (sSolverName == "clp" || sSolverName == "cbc")
            {
                if (  osoption != NULL && 
                      osoption->optimization != NULL &&
                    ((osoption->optimization->variables != NULL &&
                      osoption->optimization->variables->initialBasisStatus != NULL) ||
                     (osoption->optimization->constraints != NULL &&
                      osoption->optimization->constraints->initialBasisStatus != NULL)) ) 

                /* Only the following statuses are recognized:
                 *
                 *   enum Status {
                 *       isFree = 0x00,                ///< Nonbasic free variable
                 *       basic = 0x01,              ///< Basic variable
                 *       atUpperBound = 0x02,       ///< Nonbasic at upper bound
                 *       atLowerBound = 0x03        ///< Nonbasic at lower bound
                 *   }
                 *
                 * Any others, or any missing statuses, are set to isFree; let Clp deal with it.
                 */
                {
                    int nsBas,naBas,nsUpp,naUpp,nsLow,naLow,nvar,ncon;
                    int* tmpBas = NULL;
                    CoinWarmStartBasis* warmstart = new CoinWarmStartBasis();
                    nvar = osinstance->getVariableNumber();
                    ncon = osinstance->getConstraintNumber();
                    warmstart->setSize(nvar, ncon); // this initials everything to isFree

                    // pull the number of basis elements of each type
                    if ( osoption->optimization->variables != NULL &&
                         osoption->optimization->variables->initialBasisStatus != NULL )
                    {
                        nsBas = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic);
                        nsUpp = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper);
                        nsLow = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower);
                    }
                    else
                    {
                        nsBas = 0;
                        nsUpp = 0;
                        nsLow = 0;
                    }
                    if ( osoption->optimization->constraints != NULL &&
                         osoption->optimization->constraints->initialBasisStatus != NULL ) 
                    {
                        naBas = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic);
                        naUpp = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper);
                        naLow = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower);
                    }
                    else
                    {
                        naBas = 0;
                        naUpp = 0;
                        naLow = 0;
                    }

                    // get the elements and store them into the Clp warm start object
                    if (nsBas > 0)
                    {
                        tmpBas = new int[nsBas];
                        osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic,tmpBas);
                        for (int i=0; i<nsBas; i++)
                            warmstart->setStructStatus(tmpBas[i], (CoinWarmStartBasis::Status)0x01); 
                        delete [] tmpBas;
                    }
                    if (naBas > 0)
                    {
                        tmpBas = new int[naBas];
                        osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic,tmpBas);           
                        for (int i=0; i<naBas; i++)                        
                            warmstart->setArtifStatus(tmpBas[i], (CoinWarmStartBasis::Status)0x01); 
                        delete [] tmpBas;
                    }

                    if (nsUpp > 0)
                    {
                        tmpBas = new int[nsUpp];
                        osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper,tmpBas);           
                        for (int i=0; i<nsUpp; i++)
                            warmstart->setStructStatus(tmpBas[i], (CoinWarmStartBasis::Status)0x02); 
                        delete [] tmpBas;
                    }
                    if (naUpp > 0)
                    {
                        tmpBas = new int[naUpp];
                        osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper,tmpBas);           
                        for (int i=0; i<naUpp; i++)                        
                            warmstart->setArtifStatus(tmpBas[i], (CoinWarmStartBasis::Status)0x02); 
                        delete [] tmpBas;
                    }

                    if (nsLow > 0)
                    {
                        tmpBas = new int[nsLow];
                        osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower,tmpBas);           
                        for (int i=0; i<nsLow; i++)
                            warmstart->setStructStatus(tmpBas[i], (CoinWarmStartBasis::Status)0x03); 
                        delete [] tmpBas;
                    }
                    if (naLow > 0)
                    {
                        tmpBas = new int[naLow];
                        osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower,tmpBas);           
                        for (int i=0; i<naLow; i++)                        
                            warmstart->setArtifStatus(tmpBas[i], (CoinWarmStartBasis::Status)0x03); 
                        delete [] tmpBas;
                    }

                    osiSolver->setWarmStart(warmstart);

                } // end if (some basis info available)
            } // end if solver = clp

        }// end of osoption if

#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "solver options set\n");
#endif
    }//end of try

    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, "THERE IS AN ERROR\n");
        osresult = new OSResult();
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//end setSolverOptions()


bool CoinSolver::setCoinPackedMatrix()
{
    bool columnMajor = osinstance->getLinearConstraintCoefficientMajor();
    try
    {
        double maxGap = 0;
        if(osinstance->getLinearConstraintCoefficientNumber() > 0)
        {
            m_CoinPackedMatrix = new CoinPackedMatrix(
                columnMajor, //Column or Row Major
                columnMajor? osinstance->getConstraintNumber() : osinstance->getVariableNumber(), //Minor Dimension
                columnMajor? osinstance->getVariableNumber() : osinstance->getConstraintNumber(), //Major Dimension
                osinstance->getLinearConstraintCoefficientNumber(), //Number of nonzeroes
                columnMajor? osinstance->getLinearConstraintCoefficientsInColumnMajor()->values : osinstance->getLinearConstraintCoefficientsInRowMajor()->values, //Pointer to matrix nonzeroes
                columnMajor? osinstance->getLinearConstraintCoefficientsInColumnMajor()->indexes : osinstance->getLinearConstraintCoefficientsInRowMajor()->indexes, //Pointer to start of minor dimension indexes -- change to allow for row storage
                columnMajor? osinstance->getLinearConstraintCoefficientsInColumnMajor()->starts : osinstance->getLinearConstraintCoefficientsInRowMajor()->starts, //Pointers to start of columns.
                0,   0, maxGap );
        }
        else
        {
            int* start = new int[osinstance->getVariableNumber()+1];
            for (int i=0; i <= osinstance->getVariableNumber(); i++)
                start[i] = 0;
            m_CoinPackedMatrix = new CoinPackedMatrix(
                columnMajor, //Column or Row Major
                columnMajor? osinstance->getConstraintNumber() : osinstance->getVariableNumber(), //Minor Dimension
                columnMajor? osinstance->getVariableNumber() : osinstance->getConstraintNumber(), //Major Dimension
                osinstance->getLinearConstraintCoefficientNumber(), //Number of nonzeroes
                NULL, //Pointer to matrix nonzeroes
                NULL, //Pointer to start of minor dimension indexes -- change to allow for row storage
                start, //Pointers to start of columns.
                NULL,   0.0, maxGap );
        }


        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osresult = new OSResult();
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
} // end setCoinPackedMatrix

void CoinSolver::solve() throw (ErrorClass)
{
    std::ostringstream outStr;
    if(osresult != NULL) delete osresult;
    osresult = new OSResult();
    try
    {
        // make sure the solver instance exists
        if( this->bCallbuildSolverInstance == false) buildSolverInstance();
        //set the options
        if( this->bSetSolverOptions == false) setSolverOptions();
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( osrl) ;
    }

    // resultHeader information
    if(osresult->setSolverInvoked("COIN-OR " + sSolverName) != true)
        throw ErrorClass("OSResult error: SetSolverInvoked");
    if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
        throw ErrorClass("OSResult error: setInstanceName");
    //if(osresult->setJobID( osresultdata->jobID) != true)
    //    throw ErrorClass("OSResult error: setJobID");
    //if(osresult->setGeneralMessage( osresultdata->message) != true)
    //    throw ErrorClass("OSResult error: setGeneralMessage");
    // set basic problem parameters

    if(osresult->setVariableNumber( osinstance->getVariableNumber()) != true)
        throw ErrorClass("OSResult error: setVariableNumer");
    if(osresult->setObjectiveNumber( 1) != true)
        throw ErrorClass("OSResult error: setObjectiveNumber");
    if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
        throw ErrorClass("OSResult error: setConstraintNumber");
    if(osresult->setSolutionNumber(  1) != true)
        throw ErrorClass("OSResult error: setSolutionNumer");

    //
    try
    {
        double start = CoinCpuTime();
        try
        {
            if( sSolverName.find( "cbc") != std::string::npos)
            {
                //if( osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0){
                // just use simple branch and bound for anything but cbc
                CbcModel model(  *osiSolver);
                //CoinMessages coinMessages;
                //int numberOfMessages;
                //CoinOneMessage currentMessage;
                //CoinMessageHandler * generalMessageHandler;
                //CoinOneMessage **coinOneMessage;
                //CoinOneMessage *oneMessage;

                CbcMain0(  model);

                /*
                coinMessages = model.messages();
                numberOfMessages = coinMessages.numberMessages_;
                for(int i = 0; i < numberOfMessages - 1; i++){
                    oneMessage = coinMessages.message_[ i] ;
                //    std::cout << "ONE MESSAGE = " << oneMessage->message() << std::endl;
                }

                generalMessageHandler = model.messageHandler();
                currentMessage = generalMessageHandler->currentMessage();
                std::cout << "HIGHEST NUMBER =  "  << generalMessageHandler->highestNumber() << std::endl;
                std::cout << "CURRENT SOURCE =  "  << generalMessageHandler->currentSource() << std::endl;
                std::cout << "MESSAGE BUFFER =  "  << generalMessageHandler->messageBuffer() << std::endl;
                */

                //CoinMessages generalMessages = model.getModelPtr()->messages();
                // make sure we define cbc_argv if not done already when reading options
                if(num_cbc_argv <= 0)
                {
                    char *cstr;
                    std::string cbc_option;
                    num_cbc_argv = 4;
                    cbc_argv = new const char*[ num_cbc_argv];

                    // the first option
                    cbc_option = "OS";
                    cstr = new char [cbc_option.size() + 1];
                    strcpy (cstr, cbc_option.c_str());
                    cbc_argv[ 0] = cstr;


                    // the log option -- by default minimal printing
                    cbc_option = "-log=0";
                    cstr = new char [cbc_option.size() + 1];
                    strcpy (cstr, cbc_option.c_str());
                    cbc_argv[ 1] = cstr;


                    // the solve option
                    cbc_option = "-solve";
                    cstr = new char [cbc_option.size() + 1];
                    strcpy (cstr, cbc_option.c_str());
                    cbc_argv[ 2] = cstr;

                    // the quit option
                    cbc_option = "-quit";
                    cstr = new char [cbc_option.size() + 1];
                    strcpy (cstr, cbc_option.c_str());
                    cbc_argv[ 3] = cstr;

                }
                int i;

                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, "CALLING THE CBC SOLVER  CBCMAIN1()\n"); 
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                for(i = 0; i < num_cbc_argv; i++)
                {
                    outStr << "Cbc Option: "  << cbc_argv[ i]   <<  std::endl;
                }
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                CbcMain1( num_cbc_argv, cbc_argv, model);
                /*
                coinMessages = model.messages();
                numberOfMessages = coinMessages.numberMessages_;
                for(int i = 0; i < 5; i++){
                    oneMessage = coinMessages.message_[ i] ;
                    std::cout << "ONE MESSAGE = " << oneMessage->message() << std::endl;
                }
                numberOfMessages = coinMessages.numberMessages_;
                generalMessageHandler = model.messageHandler();
                currentMessage = generalMessageHandler->currentMessage();

                std::cout << "HIGHEST NUMBER =  "  << generalMessageHandler->highestNumber() << std::endl;
                std::cout << "CURRENT SOURCE =  "  << generalMessageHandler->currentSource() << std::endl;
                std::cout << "MESSAGE BUFFER =  "  << generalMessageHandler->messageBuffer() << std::endl;
                std::cout << "NUMBER OF STRING FIELDS  =  "  << generalMessageHandler->numberStringFields() << std::endl;

                */
                //do the garbage collection on cbc_argv
                for(i = 0; i < num_cbc_argv; i++)
                {
                    delete[]  cbc_argv[ i];
                    cbc_argv[i] = NULL;
                }
                if( num_cbc_argv > 0)
                {
                    delete[] cbc_argv;
                    cbc_argv = NULL;
                    num_cbc_argv = 0;
                }

                cpuTime = CoinCpuTime() - start;

                // create a solver
                OsiSolverInterface *solver = model.solver();
                if(osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0)
                {
                    writeResult( &model);
                }
                else
                {
                    writeResult( solver);
                }
            }
            else  // use other solvers
            {
                //if an LP just do initial solve
                if( osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() > 0)
                {
                    osiSolver->branchAndBound();
                }
                else
                {
                    osiSolver->initialSolve();
                }
                cpuTime = CoinCpuTime() - start;

                writeResult( osiSolver);
            }
        }

        catch(CoinError e)
        {
            std::string errmsg;
            errmsg = "Coin Solver Error: " + e.message() + "\n" + " see method "
                     + e.methodName() + " in class " + e.className();
            throw ErrorClass( errmsg );
        }
    }

    catch(const ErrorClass& eclass)
    {
        std::string::size_type  pos1 = eclass.errormsg.find( "<osrl");
        if(pos1 == std::string::npos)
        {
            osresult->setGeneralMessage(eclass.errormsg);
            osresult->setGeneralStatusType("error");
            osrl = osrlwriter->writeOSrL(osresult);
        }
        else
        {
            osrl = eclass.errormsg;
        }
        throw ErrorClass( osrl);
    }
} // end solve

std::string CoinSolver::getCoinSolverType(std::string lcl_osol)
{
// this is deprecated, but keep it around
    try
    {
        if( lcl_osol.find( "clp") != std::string::npos)
        {
            return "coin_solver_glpk";
        }
        else
        {
            if( lcl_osol.find( "cbc") != std::string::npos)
            {
                return "coin_solver_cpx";
            }
            else
            {
                if( lcl_osol.find( "cpx") != std::string::npos)
                {
                    return "coin_solver_clp";
                }
                else
                {
                    if(lcl_osol.find( "glpk") != std::string::npos)
                    {
                        return "";
                    }
                    else throw ErrorClass("a supported solver was not defined");
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
} // end getCoinSolverType

#ifndef NDEBUG
void CoinSolver::dataEchoCheck()
{
    int i;
    // print out problem parameters
    cout << "This is problem:  " << osinstance->getInstanceName() << endl;
    cout << "The problem source is:  " << osinstance->getInstanceSource() << endl;
    cout << "The problem description is:  " << osinstance->getInstanceDescription() << endl;
    cout << "number of variables = " << osinstance->getVariableNumber() << endl;
    cout << "number of Rows = " << osinstance->getConstraintNumber() << endl;

    // print out the variable information
    if(osinstance->getVariableNumber() > 0)
    {
        for(i = 0; i < osinstance->getVariableNumber(); i++)
        {
            if(osinstance->getVariableNames() != NULL) cout << "variable Names  " << osinstance->getVariableNames()[ i]  << endl;
            if(osinstance->getVariableTypes() != NULL) cout << "variable Types  " << osinstance->getVariableTypes()[ i]  << endl;
            if(osinstance->getVariableLowerBounds() != NULL) cout << "variable Lower Bounds  " << osinstance->getVariableLowerBounds()[ i]  << endl;
            if(osinstance->getVariableUpperBounds() != NULL) cout << "variable Upper Bounds  " <<  osinstance->getVariableUpperBounds()[i] << endl;
        }
    }

    // print out objective function information
    if(osinstance->getVariableNumber() > 0 || osinstance->instanceData->objectives->obj != NULL || osinstance->instanceData->objectives->numberOfObjectives > 0)
    {
        if( osinstance->getObjectiveMaxOrMins()[0] == "min")  cout <<  "problem is a minimization" << endl;
        else cout <<  "problem is a maximization" << endl;
        for(i = 0; i < osinstance->getVariableNumber(); i++)
        {
            cout << "OBJ COEFFICIENT =  " <<  osinstance->getDenseObjectiveCoefficients()[0][i] << endl;
        }
    }
    // print out constraint information
    if(osinstance->getConstraintNumber() > 0)
    {
        for(i = 0; i < osinstance->getConstraintNumber(); i++)
        {
            if(osinstance->getConstraintNames() != NULL) cout << "row name = " << osinstance->getConstraintNames()[i] <<  endl;
            if(osinstance->getConstraintLowerBounds() != NULL) cout << "row lower bound = " << osinstance->getConstraintLowerBounds()[i] <<  endl;
            if(osinstance->getConstraintUpperBounds() != NULL) cout << "row upper bound = " << osinstance->getConstraintUpperBounds()[i] <<  endl;
        }
    }

    // print out linear constraint data
    if(m_CoinPackedMatrix != NULL) m_CoinPackedMatrix->dumpMatrix();
} // end dataEchoCheck
#endif


void CoinSolver::writeResult(OsiSolverInterface *solver)
{
    double *x = NULL;
    double *y = NULL;
    double *z = NULL;
    int *cbasis = NULL;  //column basis information
    int *rbasis = NULL;  //row basis information
    int *idx = NULL;
    int kount;

    //vectors to hold the basis information
    std::vector<int> freeVars;
    std::vector<int> basicVars;
    std::vector<int> nonBasicLower;
    std::vector<int> nonBasicUpper;
    std::vector<int>::iterator vit;
    int **basisIdx;
    basisIdx = new int*[ 4];
    //end of vectors

    int numberOfVar = solver->getNumCols();
    int numberOfCon = solver->getNumRows();
    int numOfIntVars = osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables();
    std::string *rcost = NULL;
    if ( numberOfVar > 0 ) x = new double[numberOfVar];
    if ( numberOfCon > 0 ) y = new double[numberOfCon ];
    if ( numberOfVar > 0 ) idx = new int[ numberOfVar];
    if ( numberOfVar > 0 ) rcost = new std::string[numberOfVar];
    z = new double[1];

    //allocate basis if solver supports it (Clp, Cbc, Cplex, Gurobi
    bool supportsBasis = false;
    if ( (sSolverName.find( "clp") != std::string::npos) 
           || (sSolverName.find( "cbc") != std::string::npos) 
           || (sSolverName.find( "cplex") != std::string::npos) 
           || (sSolverName.find( "gurobi") != std::string::npos) ) 
    {
        if (numOfIntVars == 0) // basis information is meaningless for (M)IP
        {
            if (numberOfVar > 0) cbasis = new int[numberOfVar];
            if (numberOfCon > 0) rbasis = new int[numberOfCon];
            supportsBasis = true;
        }
    }

    int solIdx = 0;
    int i = 0;
    int numberOfOtherVariableResults = 1;
    int otherIdx = 0;
    std::string description = "";

    try
    {
        osresult->setGeneralStatusType("normal");
        osresult->setTime(cpuTime);
        osresult->setServiceName( OSgetVersionInfo() );
        osresult->setSolverInvoked( "COIN-OR " + sSolverName );
        if (solver->isProvenOptimal() == true)
        {
            osresult->setSolutionStatus(solIdx, "optimal", description);
            if ( supportsBasis ) 
            {
                solver->getBasisStatus( cbasis, rbasis);
            }

        }//end if proven optimal
        else // some other terminating condition
        {
            if(solver->isProvenPrimalInfeasible() == true)
                osresult->setSolutionStatus(solIdx, "infeasible", "the problem is primal infeasible");
            else
            {
                if(solver->isProvenDualInfeasible() == true)
                    osresult->setSolutionStatus(solIdx, "unbounded", "the problem is unbounded");
                else
                {
                    if(solver->isPrimalObjectiveLimitReached() == true)
                    {
                        osresult->setSolutionStatus(solIdx, "other", "primal objective limit reached");
                        if ( supportsBasis ) 
                        {
                            solver->getBasisStatus( cbasis, rbasis);
                        }
                    }
                    else
                    {
                        if(solver->isDualObjectiveLimitReached() == true)
                        {
                            osresult->setSolutionStatus(solIdx, "other", "dual objective limit reached");
                            if ( supportsBasis ) 
                            {
                                solver->getBasisStatus( cbasis, rbasis);
                            }
                        }
                        else
                        {
                            if(solver->isIterationLimitReached() == true)
                            {
                                osresult->setSolutionStatus(solIdx, "other", "iteration limit reached");
                                if ( supportsBasis ) 
                                {
                                    solver->getBasisStatus( cbasis, rbasis);
                                }
                            }
                            else
                            {
                                if(solver->isAbandoned() == true)
                                    osresult->setSolutionStatus(solIdx, "other", "there are numerical difficulties");
                                else
                                    if( solver->getNumCols() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
                                    else
                                        osresult->setSolutionStatus(solIdx, "other", description);
                            }
                        }
                    }
                }
            }
        }

        /* Retrieve the solution */
        //
        *(z + 0)  =  solver->getObjValue();

        osresult->setObjectiveValuesDense(solIdx, z);

        for(i=0; i < numberOfVar; i++)
        {
            *(x + i) = solver->getColSolution()[i];
            *(idx + i) = i;

            // sort basis information for variables into four categories
            if( (cbasis != NULL) && (solver->isProvenOptimal() == true) )
            {
                switch (cbasis[ i] )
                {
                case 0:
                {
                    //a free variable
                    freeVars.push_back( i);
                    break;
                }

                case 1:
                {
                    //a basic variable
                    basicVars.push_back( i);
                    break;
                }

                case 2:
                {
                    //nonbasic at upper bound
                    nonBasicUpper.push_back( i );
                    break;
                }

                case 3:
                {
                    //nonbasic at lower bound
                    nonBasicLower.push_back( i) ;
                    break;
                }
                default:
                    throw ErrorClass("unknown result from Osi getBasisStatus when getting variable basis status");

                }//end switch

            } //end if on cbasis == NULL

        }// end for on number of variables

        //now store basis information for variables
        if(freeVars.size()  > 0)
        {
            kount = 0;

            basisIdx[ 0] = new int[ freeVars.size()];

            for(vit = freeVars.begin(); vit < freeVars.end(); vit++)
            {
                basisIdx[0][ kount++] = *vit;
            }

            osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, basisIdx[ 0], kount);
            delete[] basisIdx[ 0];
            freeVars.clear();
        }

        if(basicVars.size()  > 0)
        {
            kount = 0;

            basisIdx[ 1] = new int[ basicVars.size()];

            for(vit = basicVars.begin(); vit < basicVars.end(); vit++)
            {
                basisIdx[1][ kount++] = *vit;
            }

            osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, basisIdx[ 1], kount);
            delete[] basisIdx[ 1];
            basicVars.clear();
        }

        if(nonBasicUpper.size()  > 0)
        {
            kount = 0;

            basisIdx[ 2] = new int[ nonBasicUpper.size()];

            for(vit = nonBasicUpper.begin(); vit < nonBasicUpper.end(); vit++)
            {
                basisIdx[2][ kount++] = *vit;
            }

            osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, basisIdx[ 2], kount);
            delete[] basisIdx[ 2];
            nonBasicUpper.clear();
        }


        if(nonBasicLower.size()  > 0)
        {
            kount = 0;

            basisIdx[ 3] = new int[ nonBasicLower.size()];

            for(vit = nonBasicLower.begin(); vit < nonBasicLower.end(); vit++)
            {
                basisIdx[3][ kount++] = *vit;
            }

            osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, basisIdx[ 3], kount);
            delete[] basisIdx[ 3];
            nonBasicLower.clear();
        }
        //end get basis information for variables

        osresult->setPrimalVariableValuesDense(solIdx, x);
        // Symphony does not get dual prices
        if( sSolverName.find( "symphony") == std::string::npos && osinstance->getNumberOfIntegerVariables() == 0 && osinstance->getNumberOfBinaryVariables() == 0)
        {
            for(i = 0; i <  numberOfCon; i++)
            {
                *(y + i) = solver->getRowPrice()[ i];

                // get basis information
                if((rbasis != NULL) && (solver->isProvenOptimal() == true) )
                {
                    switch (rbasis[ i] )
                    {
                    case 0:
                    {
                        //a free variable
                        freeVars.push_back( i);
                        break;
                    }

                    case 1:
                    {
                        //a basic variable
                        basicVars.push_back( i);
                        break;
                    }

                    case 2:
                    {
                        //nonbasic at upper bound
                        nonBasicUpper.push_back( i );
                        break;
                    }

                    case 3:
                    {
                        //nonbasic at lower bound
                        nonBasicLower.push_back( i) ;
                        break;
                    }
                    default:
                        throw ErrorClass("unknown result from Osi getBasisStatus when getting row basis status");

                    }//end switch

                } //end if on rbasis == NULL


            }// end for of loop on constraints

            osresult->setDualVariableValuesDense(solIdx, y);


            //now set basis information for variables
            if(freeVars.size()  > 0)
            {
                kount = 0;

                basisIdx[ 0] = new int[ freeVars.size()];

                for(vit = freeVars.begin(); vit < freeVars.end(); vit++)
                {
                    basisIdx[0][ kount++] = *vit;
                }

                osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, basisIdx[ 0], kount);
                delete[] basisIdx[ 0];
                freeVars.clear();
            }

            if(basicVars.size()  > 0)
            {
                kount = 0;

                basisIdx[ 1] = new int[ basicVars.size()];

                for(vit = basicVars.begin(); vit < basicVars.end(); vit++)
                {
                    basisIdx[1][ kount++] = *vit;
                }

                osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, basisIdx[ 1], kount);
                delete[] basisIdx[ 1];
                basicVars.clear();
            }

            if(nonBasicUpper.size()  > 0)
            {

                kount = 0;

                basisIdx[ 2] = new int[ nonBasicUpper.size()];

                for(vit = nonBasicUpper.begin(); vit < nonBasicUpper.end(); vit++)
                {
                    basisIdx[2][ kount++] = *vit;
                }

                osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, basisIdx[ 2], kount);
                delete[] basisIdx[ 2];
                nonBasicUpper.clear();
            }

            if(nonBasicLower.size()  > 0)
            {
                kount = 0;

                basisIdx[ 3] = new int[ nonBasicLower.size()];

                for(vit = nonBasicLower.begin(); vit < nonBasicLower.end(); vit++)
                {
                    basisIdx[3][ kount++] = *vit;
                }

                osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, basisIdx[ 3], kount);
                delete[] basisIdx[ 3];
                nonBasicLower.clear();

            }
            //end get basis information for variables


        }// end of if on integer variables


        // now put the reduced costs into the osrl
        // Symphony does not get reduced costs
        if( sSolverName.find( "symphony") == std::string::npos && osinstance->getNumberOfIntegerVariables() == 0 && osinstance->getNumberOfBinaryVariables() == 0)
        {
            // first set the number of Other Variable Results
            if(numOfIntVars <= 0)
            {
                osresult->setNumberOfOtherVariableResults(solIdx, numberOfOtherVariableResults);
                for(i=0; i < numberOfVar; i++)
                {
                    rcost[ i] = os_dtoa_format( solver->getReducedCost()[ i]);
                }
                osresult->setAnOtherVariableResultSparse(solIdx, otherIdx, "reduced_costs", "", "the variable reduced costs", idx,  rcost, solver->getNumCols(), "", "double", "");
                // end of setting reduced costs
            }
        }

        ostringstream temp;
        temp << solver->getIterationCount();
        if (!osresult->setAnOtherSolutionResult(0,"iterations",temp.str(),"","",0,NULL))
           throw ErrorClass("error setting iteration count");

        osrl = osrlwriter->writeOSrL( osresult);

        if (y != NULL)
        {
            delete[] y;
            y = NULL;
        }

        if (rbasis != NULL)
        {
            delete[] rbasis;
            rbasis = NULL;
        }

        delete[] z;
        z = NULL;

        delete[] basisIdx;
        basisIdx = NULL;

        if (x != NULL)
        {
            delete[] x;
            x = NULL;
        }

        if (cbasis != NULL)
        {
            delete[] cbasis;
            cbasis = NULL;
        }

        if (rcost != NULL)
        {
            delete[] rcost;
            rcost = NULL;
        }

        if (idx != NULL)
        {
            delete[] idx;
            idx = NULL;
        }
    }

    catch(const ErrorClass& eclass)
    {
        if (y != NULL)
        {
            delete[] y;
            y = NULL;
        }

        if (rbasis != NULL)
        {
            delete[] rbasis;
            rbasis = NULL;
        }

        delete[] z;
        z = NULL;

        delete[] basisIdx;
        basisIdx = NULL;

        if (x != NULL)
        {
            delete[] x;
            x = NULL;
        }

        if (cbasis != NULL)
        {
            delete[] cbasis;
            cbasis = NULL;
        }

        if (rcost != NULL)
        {
            delete[] rcost;
            rcost = NULL;
        }

        if (idx != NULL)
        {
            delete[] idx;
            idx = NULL;
        }

        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//writeResult(OsiSolverInterface)


void CoinSolver::writeResult(CbcModel *model)
{
    double *x = NULL;
    double *y = NULL;

    double *z = NULL;
    int *idx = NULL;
    std::string *rcost = NULL;
    //if( osinstance->getVariableNumber() > 0 ) x = new double[osinstance->getVariableNumber() ];
    if( model->getNumCols() > 0 ) x = new double[model->getNumCols() ];
    if( model->getNumRows() > 0 ) y = new double[model->getNumRows() ];
    if( model->getNumCols() > 0 ) idx = new int[ model->getNumCols() ];
    z = new double[1];
    if( model->getNumCols() > 0 ) rcost = new std::string[ model->getNumCols()];

    int numberOfOtherVariableResults = 1;
    int otherIdx = 0;
    int numberOfVar =  model->getNumCols();
    int numOfIntVars = osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables();
    int i = 0;
    int solIdx = 0;
    std::string description = "";
    osresult->setGeneralStatusType("normal");
    osresult->setTime(cpuTime);

    osresult->setServiceName( OSgetVersionInfo() );

    //first determine if we are feasible
    int numberIntegerInfeasibilities = 0;
    int numberObjectInfeasibilities = 0;
    bool isFeasible = false;
    isFeasible = model->feasibleSolution( numberIntegerInfeasibilities,
                                          numberObjectInfeasibilities);
    std::string statusMsg;
    if(isFeasible == true)
    {
        statusMsg = "feasible";
    }
    else
    {
        statusMsg = "infeasible";
    }


    if (model->isProvenOptimal() == true  )
    {
        osresult->setSolutionStatus(solIdx, "optimal", description);
    }
    else
    {
        if(model->isProvenInfeasible() == true)
            osresult->setSolutionStatus(solIdx, "infeasible", "the integer program is infeasible");
        else
        {
            if(model->isProvenDualInfeasible() == true)
                osresult->setSolutionStatus(solIdx, "infeasible", "the continuous relaxation is dual infeasible");
            else
            {
                if(model->isContinuousUnbounded() == true)
                    osresult->setSolutionStatus(solIdx, statusMsg, "the continuous relaxation is unbounded");
                else
                {
                    if(model->isNodeLimitReached() == true)
                        osresult->setSolutionStatus(solIdx, statusMsg, "node limit reached");
                    else
                    {
                        if(model->isSecondsLimitReached() == true)
                            osresult->setSolutionStatus(solIdx, statusMsg, "time limit reached");
                        else
                        {
                            if(model->isSolutionLimitReached() == true)
                                osresult->setSolutionStatus(solIdx, statusMsg, "solution limit reached");
                            else
                            {
                                if(model->isAbandoned() == true)
                                    osresult->setSolutionStatus(solIdx, statusMsg, "there are numerical difficulties");
                                else
                                    osresult->setSolutionStatus(solIdx, statusMsg,"unknown");
                            }
                        }
                    }
                }
            }
        }
    }

    /* Retrieve the solution -- of course it may not be optimal */
    if(numOfIntVars > 0) *(z + 0)  =  model->getObjValue();
    osresult->setObjectiveValuesDense(solIdx, z);
    for(i=0; i < model->getNumCols(); i++)
    {
        *(x + i) = model->getColSolution()[i];
        *(idx + i) = i;
    }
    osresult->setPrimalVariableValuesDense(solIdx, x);
    for(i=0; i <  model->getNumRows(); i++)
    {
        *(y + i) = model->getRowPrice()[ i];
    }
    if(numOfIntVars <= 0) osresult->setDualVariableValuesDense(solIdx, y);
    // now put the reduced costs into the osrl
    // first set the number of Other Variable Results
    if(numOfIntVars <= 0)
    {
        osresult->setNumberOfOtherVariableResults(solIdx, numberOfOtherVariableResults);
        for(i=0; i < numberOfVar; i++)
        {
            rcost[ i] = os_dtoa_format( model->getReducedCost()[ i]);
        }
        osresult->setAnOtherVariableResultSparse(solIdx, otherIdx, "reduced_costs", "", "the variable reduced costs", idx,  rcost, model->getNumCols());
    }
    // end of setting reduced costs
    osrl = osrlwriter->writeOSrL( osresult);
    //garbage collection
    if(model->getNumCols() > 0) delete[] x;
    x = NULL;
    if(model->getNumRows() > 0) delete[] y;
    y = NULL;
    delete[] z;
    z = NULL;
    if(model->getNumCols() > 0)
    {
        delete[] rcost;
        rcost = NULL;
        delete[] idx;
        idx = NULL;
    }
}//writeResult( CbcModel)


