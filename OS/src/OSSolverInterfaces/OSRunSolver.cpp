/* $Id: OSRunSolver.cpp 4263 2011-09-09 20:19:26Z Martin $ */
/** @file OSRunSolver.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */




#include "OSCoinSolver.h"
#include "OSResult.h"
#include "OSiLReader.h"
#include "OSiLWriter.h"
#include "OSoLReader.h"
#include "OSrLReader.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSOption.h"
#include "OSoLWriter.h"
#include "OSFileUtil.h"
#include "OSConfig.h"
#include "OSDefaultSolver.h"
#include "OSWSUtil.h"
#include "OSSolverAgent.h"
#include "OShL.h"
#include "OSErrorClass.h"
//#include "OSmps2osil.h"
#include "OSBase64.h"

#ifdef COIN_HAS_KNITRO
#include "OSKnitroSolver.h"
#endif

#ifdef COIN_HAS_LINDO
#include "OSLindoSolver.h"
#endif

#ifdef COIN_HAS_ASL
//#include "OSnl2osil.h"
#endif

#ifdef COIN_HAS_GAMSUTILS
#include "OSgams2osil.hpp"
#endif

//#ifdef COIN_HAS_IPOPT
//#include "OSIpoptSolver.h"
//#endif

#ifdef COIN_HAS_IPOPT
#ifndef COIN_HAS_ASL
#include "OSIpoptSolver.h"
#undef COIN_HAS_ASL
#else
#include "OSIpoptSolver.h"
#endif
#endif

#ifdef COIN_HAS_BONMIN
#include "OSBonminSolver.h"
#endif

#ifdef COIN_HAS_COUENNE
#include "OSCouenneSolver.h"
#endif

#include "OSOptionsStruc.h"

#include<stdio.h>
#include <map>


using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using std::map;


std::string runSolver(std::string solverName, OSOption *osoption,
                        OSInstance *osinstance)
{
    DefaultSolver *solverType = NULL;
    //std::cout << "SOLVER NAME = " << solverName << std::endl;
    try
    {
		// if no solver was given, must determine the default solver
        if (solverName == "")  
        {
            if (osinstance == NULL)
                throw ErrorClass(
                    "there was a NULL instance sent to buildSolver");
            //see if we have an integer program
            if (osinstance->getNumberOfIntegerVariables()
                    + osinstance->getNumberOfBinaryVariables() > 0)  //we have an integer program
            {
                if ((osinstance->getNumberOfNonlinearExpressions() > 0)
                        || (osinstance->getNumberOfQuadraticTerms() > 0))   // we are nonlinear and integer
                {
                    solverName = "bonmin";
                }
                else    //we are linear integer
                {
                    solverName = "cbc";
                }
            }
            else    // we have a continuous problem
            {
                if ((osinstance->getNumberOfNonlinearExpressions() > 0)
                        || (osinstance->getNumberOfQuadraticTerms() > 0))   // we are nonlinear and continuous
                {
                    solverName = "ipopt";
                }
                else    //we have linear program
                {
                    solverName = "clp";
                }
            }
        }//end of if on solverName

        //now build the solver through its constructor

        //std::cout << "SOLVER NAME =  " << solverName << std::endl;

        if (solverName.find("ipopt") != std::string::npos)
        {
            // we are requesting the Ipopt solver

#ifdef COIN_HAS_IPOPT
            solverType = new IpoptSolver();
            solverType->sSolverName = "ipopt";
#else
            throw ErrorClass("the Ipopt solver requested is not present");
#endif                
        }
        else
        {
            if (solverName.find("lindo") != std::string::npos)
            {
                // we are requesting the Lindo solver
#ifdef COIN_HAS_LINDO
                solverType = new LindoSolver();
                solverType->sSolverName = "lindo";
#else
                throw ErrorClass( "the Lindo solver requested is not present");
#endif
            }
            else
            {
                if (solverName.find("clp") != std::string::npos)
                {
                    //std::cout << "NEWING SOLVER TYPE " << std::endl;
                    solverType = new CoinSolver();
                    //std::cout << "END NEWING SOLVER TYPE " << std::endl;
                    solverType->sSolverName = "clp";
                }
                else
                {
                    if (solverName.find("cplex") != std::string::npos)
                    {
#ifdef COIN_HAS_CPX
                        solverType = new CoinSolver();
                        solverType->sSolverName = "cplex";
#else
                        throw ErrorClass( "the Cplex solver requested is not present");
#endif
                    }
                    else
                    {
                        if (solverName.find("glpk") != std::string::npos)
                        {
#ifdef COIN_HAS_GLPK
                            solverType = new CoinSolver();
                            solverType->sSolverName = "glpk";
#else
                            throw ErrorClass( "the GLPK solver requested is not present");
#endif
                        }
                        else
                        {
                            if (solverName.find("dylp") != std::string::npos)
                            {
#ifdef COIN_HAS_DYLP
                                solverType = new CoinSolver();
                                solverType->sSolverName = "dylp";
#else
                                throw ErrorClass( "the DyLP solver requested is not present");
#endif
                            }
                            else
                            {
                                if (solverName.find("symphony")
                                        != std::string::npos)
                                {
#ifdef COIN_HAS_SYMPHONY
                                    solverType = new CoinSolver();
                                    solverType->sSolverName = "symphony";
#else
                                        throw ErrorClass( "the SYMPHONY solver requested is not present");
#endif
                                }
                                else
                                {
                                    if (solverName.find("knitro")
                                            != std::string::npos)
                                    {
#ifdef COIN_HAS_KNITRO
                    
                                        solverType = new KnitroSolver();
                                        solverType->sSolverName = "knitro";
                                     
#else
                                        throw ErrorClass( "the Knitro solver requested is not present");
#endif
                                    }
                                    else
                                    {
                                        if (solverName.find("vol")
                                                != std::string::npos)
                                        {
#ifdef COIN_HAS_VOL
                                            solverType = new CoinSolver();
                                            solverType->sSolverName = "vol";
#else
                                            throw ErrorClass( "the Vol solver requested is not present");
#endif
                                        }
                                        else
                                        {
                                            if (solverName.find("bonmin")
                                                    != std::string::npos)
                                            {
                                                // we are requesting the Bonmin solver
#ifdef COIN_HAS_BONMIN
                                                solverType = new BonminSolver();
                                                solverType->sSolverName = "bonmin";
#else
                                                    throw ErrorClass( "the Bonmin solver requested is not present");
#endif
                                            }
                                            else
                                            {
                                                if (solverName.find("couenne")
                                                        != std::string::npos)
                                                {
                                                    // we are requesting the Couenne solver
#ifdef COIN_HAS_COUENNE
                                                    solverType = new CouenneSolver();
                                                    solverType->sSolverName = "couenne";
#else
                                                        throw ErrorClass( "the Couenne solver requested is not present");
#endif
                                                }
                                                else     
                                                {
                                                	if(solverName.find("cbc") != std::string::npos)
                                                	{
                                                        solverType = new CoinSolver();
                                                        solverType->sSolverName = "cbc";
                                                	}
                                                	else
                                                	{
                                                		std::string errorMessage;
                                                		errorMessage = "solver type " + solverName + " is not supported";
                                                		throw ErrorClass( errorMessage );

                                                		
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

        //std::cout << "SET SOLVER INSTANCE " << std::endl;
        
        
        solverType->osinstance = osinstance;
        solverType->osoption = osoption;
        solverType->buildSolverInstance();
        solverType->setSolverOptions();
        solverType->solve();
        std::string resultString = solverType->osrl;
        if (solverType != NULL)
            delete solverType;
        solverType = NULL;
        return resultString;
        

    }
    catch (const ErrorClass& eclass)
    {
        if (solverType != NULL)
            delete solverType;
        solverType = NULL;
        throw eclass;
    }

}//runSolver


