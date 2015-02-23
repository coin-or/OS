/* $Id: OSRunSolver.cpp 4263 2011-09-09 20:19:26Z Martin $ */
/** @file OSRunSolver.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2013, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSRunSolver.h"
#include "OSCoinSolver.h"
#include "OSResult.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSOption.h"
#include "OSConfig.h"
#include "OSDefaultSolver.h"
#include "OSErrorClass.h"

#ifdef COIN_HAS_KNITRO
#include "OSKnitroSolver.h"
#endif

#ifdef COIN_HAS_LINDO
#include "OSLindoSolver.h"
#endif

#ifdef COIN_HAS_IPOPT
# ifndef COIN_HAS_ASL
#  include "OSIpoptSolver.h"
#  undef COIN_HAS_ASL
# else
#  include "OSIpoptSolver.h"
# endif
#endif

#ifdef COIN_HAS_BONMIN
#include "OSBonminSolver.h"
#endif

#ifdef COIN_HAS_COUENNE
#include "OSCouenneSolver.h"
#endif

#ifdef COIN_HAS_CSDP
#include "OSCsdpSolver.h"
#endif

#include <stdio.h>
#include <map>


using std::endl;
using std::ostringstream;
using std::string;
using std::map;

/* Four implementations of this method, with different combinations of inputs */

std::string runSolver(std::string solverName, std::string osol,
                        OSInstance *osinstance)
{
    DefaultSolver *solverType = NULL;
    try
    {
        solverType = selectSolver(solverName, osinstance);
        if (solverType == NULL)  
            throw ErrorClass("No appropriate solver found");
    
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
        if (solverType != NULL)
            delete solverType;
        solverType = NULL;
        throw eclass;
        return "";
    }
} //runSolver (osinstance, osol)      


std::string runSolver(std::string solverName, OSOption* osoption,
                            OSInstance *osinstance)
{
    DefaultSolver *solverType = NULL;
    try
    {
        solverType = selectSolver(solverName, osinstance);
        if (solverType == NULL)  
            throw ErrorClass("No appropriate solver found");
    
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
        return "";
    }
} //runSolver (osinstance, osoption)


std::string runSolver(std::string solverName, std::string osol,
                        std::string osil)
{
    OSiLReader* osilreader = new OSiLReader();
    OSInstance* osinstance = new OSInstance();
    DefaultSolver *solverType = NULL;

    try
    {
        osinstance = osilreader->readOSiL(osil);

        solverType = selectSolver(solverName, osinstance);
        if (solverType == NULL)  
            throw ErrorClass("No appropriate solver found");

        solverType->osinstance = osinstance;
        solverType->osol = osol;
        solverType->buildSolverInstance();
        solverType->setSolverOptions();
        solverType->solve();
        std::string resultString = solverType->osrl;
        if (solverType != NULL)
            delete solverType;
        solverType = NULL;
        delete osilreader;
        osilreader = NULL;
        return resultString;
    }
    catch (const ErrorClass& eclass)
    {
        if (solverType != NULL)
            delete solverType;
        solverType = NULL;
        delete osilreader;
        osilreader = NULL;
        throw eclass;
        return "";
    }
} //runSolver (osil, osol)      


std::string runSolver(std::string solverName, OSOption* osoption,
                        std::string osil)
{
    OSiLReader* osilreader = new OSiLReader();
    OSInstance* osinstance = new OSInstance();
    DefaultSolver *solverType = NULL;

    try
    {
        osinstance = osilreader->readOSiL(osil);

        solverType = selectSolver(solverName, osinstance);
        if (solverType == NULL)  
            throw ErrorClass("No appropriate solver found");

        solverType->osinstance = osinstance;
        solverType->osoption = osoption;
        solverType->buildSolverInstance();
        solverType->setSolverOptions();
        solverType->solve();
        std::string resultString = solverType->osrl;
        if (solverType != NULL)
            delete solverType;
        solverType = NULL;
        delete osilreader;
        osilreader = NULL;
        return resultString;
    }
    catch (const ErrorClass& eclass)
    {
        if (solverType != NULL)
            delete solverType;
        solverType = NULL;
        delete osilreader;
        osilreader = NULL;
        throw eclass;
        return "";
    }
} //runSolver (osil, osoption)


DefaultSolver* selectSolver(std::string solverName, OSInstance *osinstance)
{
    DefaultSolver *solverType = NULL;
    try
    {
        if (solverName == "")  // must determine the default solver
        {
            if (osinstance == NULL)
                throw ErrorClass(
                    "there was a NULL instance sent to buildSolver");

            // make sure there are no special items here, matrixProgramming, stochastic, etc.
            // for which there is no default solver
            // HIG: To do...

            // see if we have an integer program
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
        }//end of if solverName == ""

        //now build the solver through its constructor

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

        else if (solverName.find("lindo") != std::string::npos)
        {
            // we are requesting the Lindo solver
#ifdef COIN_HAS_LINDO
            solverType = new LindoSolver();
            solverType->sSolverName = "lindo";
#else
            throw ErrorClass( "the Lindo solver requested is not present");
#endif
        }

        else if (solverName.find("clp") != std::string::npos)
        {
            solverType = new CoinSolver();
            solverType->sSolverName = "clp";
        }

        else if (solverName.find("cplex") != std::string::npos)
        {
#ifdef COIN_HAS_CPX
            solverType = new CoinSolver();
            solverType->sSolverName = "cplex";
#else
            throw ErrorClass( "the Cplex solver requested is not present");
#endif
        }

        else if (solverName.find("glpk") != std::string::npos)
        {
#ifdef COIN_HAS_GLPK
            solverType = new CoinSolver();
            solverType->sSolverName = "glpk";
#else
            throw ErrorClass( "the GLPK solver requested is not present");
#endif
        }

        else if (solverName.find("dylp") != std::string::npos)
        {
#ifdef COIN_HAS_DYLP
            solverType = new CoinSolver();
            solverType->sSolverName = "dylp";
#else
            throw ErrorClass( "the DyLP solver requested is not present");
#endif
        }

        else if (solverName.find("symphony") != std::string::npos)
        {
#ifdef COIN_HAS_SYMPHONY
            solverType = new CoinSolver();
            solverType->sSolverName = "symphony";
#else
            throw ErrorClass( "the SYMPHONY solver requested is not present");
#endif
        }

        else if (solverName.find("knitro") != std::string::npos)
        {
#ifdef COIN_HAS_KNITRO
            solverType = new KnitroSolver();
            solverType->sSolverName = "knitro";
#else
            throw ErrorClass( "the Knitro solver requested is not present");
#endif
        }

        else if (solverName.find("vol") != std::string::npos)
        {
#ifdef COIN_HAS_VOL
            solverType = new CoinSolver();
            solverType->sSolverName = "vol";
#else
            throw ErrorClass( "the Vol solver requested is not present");
#endif
        }

        else if (solverName.find("bonmin") != std::string::npos)
        {
            // we are requesting the Bonmin solver
#ifdef COIN_HAS_BONMIN
            solverType = new BonminSolver();
            solverType->sSolverName = "bonmin";
#else
            throw ErrorClass( "the Bonmin solver requested is not present");
#endif
        }

        else if (solverName.find("couenne") != std::string::npos)
        {
             // we are requesting the Couenne solver
#ifdef COIN_HAS_COUENNE
            solverType = new CouenneSolver();
            solverType->sSolverName = "couenne";
#else
            throw ErrorClass( "the Couenne solver requested is not present");
#endif
        }

        else if (solverName.find("cbc") != std::string::npos)
        {
            solverType = new CoinSolver();
            solverType->sSolverName = "cbc";
        }

        else if (solverName.find("gurobi") != std::string::npos)
        {
#ifdef COIN_HAS_GRB
            solverType = new CoinSolver();
            solverType->sSolverName = "gurobi";
#else
            throw ErrorClass( "the Gurobi solver requested is not present");
#endif
        }

        else if (solverName.find("mosek") != std::string::npos)
        {
#ifdef COIN_HAS_MSK
            solverType = new CoinSolver();
            solverType->sSolverName = "mosek";
#else
            throw ErrorClass( "the Mosek solver requested is not present");
#endif
        }

        else if (solverName.find("soplex") != std::string::npos)
        {
#ifdef COIN_HAS_SOPLEX
            solverType = new CoinSolver();
            solverType->sSolverName = "soplex";
#else
            throw ErrorClass( "the Soplex solver requested is not present");
#endif
        }

        else if (solverName.find("xpress") != std::string::npos)
        {
#ifdef COIN_HAS_XPR
            solverType = new CoinSolver();
            solverType->sSolverName = "xpress";
#else
            throw ErrorClass( "the Xpress solver requested is not present");
#endif
        }

        else if (solverName.find("csdp") != std::string::npos)
        {
#ifdef COIN_HAS_CSDP
//            solverType = new CsdpSolver();
//            solverType->sSolverName = "csdp";
            throw ErrorClass( "the CSDP solver requested is not yet supported");
#else
            throw ErrorClass( "the CSDP solver requested is not present");
#endif
        }

        else
        {
            std::string errorMessage;
            errorMessage = "solver " + solverName + " is not supported";
            throw ErrorClass( errorMessage );
        }

        return solverType;
    }

    catch (const ErrorClass& eclass)
    {
        if (solverType != NULL)
            delete solverType;
        solverType = NULL;
        throw eclass;
        return NULL;
    }

}//selectSolver


