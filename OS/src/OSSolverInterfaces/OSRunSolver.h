/* $Id: OSGetSolver.h 4263 2011-09-09 20:19:26Z Martin $ */
/** @file CoinSolver.h
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

#ifndef OSRUNSOLVER_H
#define OSRUNSOLVER_H


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
#include "OSmps2osil.h"
#include "OSBase64.h"

#ifdef COIN_HAS_KNITRO
#include "OSKnitroSolver.h"
#endif

#ifdef COIN_HAS_LINDO
#include "OSLindoSolver.h"
#endif

#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
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


std::string runSolver(std::string solverName, std::string osol,
                        OSInstance *osinstance)
{
    DefaultSolver *solverType = NULL;
    //std::cout << "SOLVER NAME = " << solverName << std::endl;
    try
    {
        if (solverName == "")  // must determine the default solver
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
            bool bIpoptIsPresent = false;
#ifdef COIN_HAS_IPOPT
            bIpoptIsPresent = true;
            solverType = new IpoptSolver();
#endif
            if (bIpoptIsPresent == false)
                throw ErrorClass("the Ipopt solver requested is not present");
        }
        else
        {
            if (solverName.find("lindo") != std::string::npos)
            {
                // we are requesting the Lindo solver
                bool bLindoIsPresent = false;
#ifdef COIN_HAS_LINDO
                bLindoIsPresent = true;
                std::cout << "calling the LINDO Solver " << std::endl;
                solverType = new LindoSolver();
                std::cout << "DONE calling the LINDO Solver " << std::endl;
#endif
                if (bLindoIsPresent == false)
                    throw ErrorClass(
                        "the Lindo solver requested is not present");
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
                        bool bCplexIsPresent = false;
#ifdef COIN_HAS_CPX
                        bCplexIsPresent = true;
                        solverType = new CoinSolver();
                        solverType->sSolverName = "cplex";
#endif
                        if (bCplexIsPresent == false)
                            throw ErrorClass(
                                "the Cplex solver requested is not present");
                    }
                    else
                    {
                        if (solverName.find("glpk") != std::string::npos)
                        {
                            bool bGlpkIsPresent = false;
#ifdef COIN_HAS_GLPK
                            bGlpkIsPresent = true;
                            solverType = new CoinSolver();
                            solverType->sSolverName = "glpk";
#endif
                            if (bGlpkIsPresent == false)
                                throw ErrorClass(
                                    "the GLPK solver requested is not present");
                        }
                        else
                        {
                            if (solverName.find("dylp") != std::string::npos)
                            {
                                bool bDyLPIsPresent = false;
#ifdef COIN_HAS_DYLP
                                bDyLPIsPresent = true;
                                solverType = new CoinSolver();
                                solverType->sSolverName = "dylp";
                                bDyLPIsPresent = true;
#endif
                                if (bDyLPIsPresent == false)
                                    throw ErrorClass(
                                        "the DyLP solver requested is not present");
                            }
                            else
                            {
                                if (solverName.find("symphony")
                                        != std::string::npos)
                                {
                                    bool bSymphonyIsPresent = false;
#ifdef COIN_HAS_SYMPHONY
                                    bSymphonyIsPresent = true;
                                    solverType = new CoinSolver();
                                    solverType->sSolverName = "symphony";
#endif
                                    if (bSymphonyIsPresent == false)
                                        throw ErrorClass(
                                            "the SYMPHONY solver requested is not present");
                                }
                                else
                                {
                                    if (solverName.find("knitro")
                                            != std::string::npos)
                                    {
                                        bool bKnitroIsPresent = false;
#ifdef COIN_HAS_KNITRO
                                        bKnitroIsPresent = true;
                                        std::cout << "calling the KNITRO Solver " << std::endl;
                                        solverType = new KnitroSolver();
                                        std::cout << "DONE calling the KNITRO Solver " << std::endl;
#endif
                                        if (bKnitroIsPresent == false)
                                            throw ErrorClass(
                                                "the Knitro solver requested is not present");
                                    }
                                    else
                                    {
                                        if (solverName.find("vol")
                                                != std::string::npos)
                                        {
                                            bool bVolIsPresent = false;
#ifdef COIN_HAS_VOL
                                            bVolIsPresent = true;
                                            solverType = new CoinSolver();
                                            solverType->sSolverName = "vol";
#endif
                                            if (bVolIsPresent == false)
                                                throw ErrorClass(
                                                    "the Vol solver requested is not present");
                                        }
                                        else
                                        {
                                            if (solverName.find("bonmin")
                                                    != std::string::npos)
                                            {
                                                // we are requesting the Bonmin solver
                                                bool bBonminIsPresent = false;
#ifdef COIN_HAS_BONMIN
                                                bBonminIsPresent = true;
                                                solverType = new BonminSolver();
#endif
                                                if (bBonminIsPresent == false)
                                                    throw ErrorClass(
                                                        "the Bonmin solver requested is not present");
                                            }
                                            else
                                            {
                                                if (solverName.find("couenne")
                                                        != std::string::npos)
                                                {
                                                    // we are requesting the Couenne solver
                                                    bool bCouenneIsPresent =
                                                        false;
#ifdef COIN_HAS_COUENNE
                                                    bCouenneIsPresent = true;
                                                    solverType = new CouenneSolver();
#endif
                                                    if (bCouenneIsPresent
                                                            == false)
                                                        throw ErrorClass(
                                                            "the Couenne solver requested is not present");
                                                }
                                                else     //cbc is the default
                                                {
                                                    solverType
                                                        = new CoinSolver();
                                                    solverType->sSolverName
                                                        = "cbc";
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
        solverType->osol = osol;
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
        throw eclass;
    }

}//runSolver

#endif