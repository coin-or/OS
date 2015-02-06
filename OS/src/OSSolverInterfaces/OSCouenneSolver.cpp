/* $Id$ */
/** @file CouenneSolver.cpp
 *
 * \brief This file defines the Couenne Solver class.
 * \detail Read an OSInstance object and convert in Ipopt data structures
 *
 * @author  Jun Ma, Horand Gassmann, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2008-2011, Jun Ma, Horand Gassmann, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */
#include <iostream>


//OS stuff
#include "OSDataStructures.h"
#include "OSParameters.h"
#include "OSMathUtil.h"
#include "OSOutput.h"
#include "OSCouenneSolver.h"
#include "BonBonminSetup.hpp"
#include <cppad/cppad.hpp>
#include <cppad/configure.hpp>
//end OS stuff


// Couenne stuff

#include "CouenneConfig.h"
#include "CouenneTypes.hpp"
#include "CouenneJournalist.hpp"
#include "CouenneExprClone.hpp"
#include "CouenneExprGroup.hpp"
#include "CouenneExprAbs.hpp"
#include "CouenneExprConst.hpp"
#include "CouenneExprCos.hpp"
#include "CouenneExprDiv.hpp"
#include "CouenneExprExp.hpp"
#include "CouenneExprInv.hpp"
#include "CouenneExprLog.hpp"
#include "CouenneExprMax.hpp"
#include "CouenneExprMin.hpp"
#include "CouenneExprMul.hpp"
#include "CouenneExprOpp.hpp"
#include "CouenneExprPow.hpp"
#include "CouenneExprSin.hpp"
#include "CouenneExprSub.hpp"
#include "CouenneExprSum.hpp"
#include "CouenneExprVar.hpp"
using namespace Couenne;
// end Couenne stuff


//Bonmin stuff

#include "BonOsiTMINLPInterface.hpp"
#include "BonIpoptSolver.hpp"


#include "CoinTime.hpp"
#include "BonminConfig.h"
#include "BonCouenneInterface.hpp"


#include "BonCouenneSetup.hpp"


#ifdef COIN_HAS_FILTERSQP
#include "BonFilterSolver.hpp"
#endif

#include "CbcCutGenerator.hpp"
#include "CouenneProblem.hpp"
#include "CouenneCutGenerator.hpp"
#include "CouenneBab.hpp"

#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <stack>
#include <string>
#include <iostream>



using namespace Bonmin;
using namespace Couenne;
using std::endl;
using std::ostringstream;


CouenneSolver::CouenneSolver()
{
    using namespace  Ipopt;
    osrlwriter = new OSrLWriter();
    osresult = new OSResult();
    m_osilreader = NULL;
    m_osolreader = NULL;
    couenneErrorMsg = "";
    couenne = NULL;
    con_body = NULL;
    obj_body = NULL;
}

CouenneSolver::~CouenneSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "inside CouenneSolver destructor\n");
#endif

    if(con_body != NULL)
    {
        //delete con_body;
    }
    if(obj_body != NULL)
    {
        //delete obj_body;
    }
    if(m_osilreader != NULL)
    {
        delete m_osilreader;
    }
    m_osilreader = NULL;
    if(m_osolreader != NULL) delete m_osolreader;
    m_osolreader = NULL;
    delete osresult;
    osresult = NULL;
    delete osrlwriter;
    osrlwriter = NULL;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "leaving CouenneSolver destructor\n");
#endif

}


void CouenneSolver::buildSolverInstance() throw (ErrorClass)
{
    // Much of the following is taken from Stefan Vigerske
    try
    {
        this->bCallbuildSolverInstance = true;
        // do some initialization

        int i, j;
        std::ostringstream outStr;

        if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
        if(osinstance == NULL)
        {
            m_osilreader = new OSiLReader();
            osinstance = m_osilreader->readOSiL( osil);
        }

        osinstance->initForAlgDiff( );
        //Ipopt::Journalist* jnlst = new Ipopt::Journalist();
        //jnlst->AddFileJournal("console", "stdout", J_STRONGWARNING);
        //couenne = new CouenneProblem(NULL, NULL, jnlst);
        couenne = new CouenneProblem(NULL, NULL, NULL);
        int n_allvars = osinstance->getVariableNumber();
        if( n_allvars < 0 )throw ErrorClass("Couenne solver Cannot have a negatiave number of Variables");
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "NUMBER OF VARIABLES = " <<  n_allvars <<  std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
        if(n_allvars > 0)
        {
            // create room for problem's variables and bounds
            CouNumber *x_ = (CouNumber *) malloc ((n_allvars) * sizeof (CouNumber));
            CouNumber	*lb = NULL, *ub = NULL;

            // now get variable upper and lower bounds
            ub = osinstance->getVariableUpperBounds();
            lb = osinstance->getVariableLowerBounds();

            //declare the variable types
            char *varType;
            varType = osinstance->getVariableTypes();
            for (i = 0; i < n_allvars; ++i)
            {
                if( (varType[i] == 'B') || (varType[i]) == 'I' )
                {
                    couenne->addVariable(true, couenne->domain() );
                }
                else
                {
                    couenne->addVariable(false, couenne->domain() );
                }

                x_[i] = 0.;
            }

            couenne->domain()->push(n_allvars, x_, lb, ub);
            free(x_);
        }

        // now for the objective function -- assume just one for now
        //just worry about linear coefficients

        if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Couenne NEEDS AN OBJECTIVE FUNCTION");

	// Can't handle multiobjective problems properly --- especially nonlinear ones
	if (osinstance->getObjectiveNumber() > 1)
    		throw ErrorClass("Solver cannot handle multiple objectives --- please delete all but one");

        //if(n_allvars > 0){
        SparseVector* sv = osinstance->getObjectiveCoefficients()[ 0];
        int nterms = sv->number;
        exprGroup::lincoeff lin( nterms);
        for ( i = 0; i < nterms; ++i)
        {
            lin[i].first = couenne->Var( sv->indexes[ i] );
            if( osinstance->getObjectiveMaxOrMins()[0] == "min")
            {
                lin[i].second = sv->values[ i];
            }
            else
            {
                lin[i].second = -sv->values[ i];
            }
        }


        ScalarExpressionTree* exptree = osinstance->getNonlinearExpressionTree( -1);
        if (exptree != NULL)
        {
            expression** nl = new expression*[1];
            if( osinstance->getObjectiveMaxOrMins()[0] == "min")
            {
                nl[0] = createCouenneExpression( exptree->m_treeRoot );
            }
            else
            {
                nl[ 0] = new exprOpp(createCouenneExpression( exptree->m_treeRoot) );

            }
            obj_body = new exprGroup(osinstance->getObjectiveConstants()[0], lin, nl, 1);
        }
        else
        {
            obj_body = new exprGroup(osinstance->getObjectiveConstants()[0], lin, NULL, 0);
        }

        couenne->addObjective(obj_body, "min");

        // get the constraints in row format

        SparseMatrix* sm =  osinstance->getLinearConstraintCoefficientsInRowMajor();

        int nconss = osinstance->getConstraintNumber();

        int row_nonz = 0;
        int kount = 0;
        double *rowlb = osinstance->getConstraintLowerBounds();
        double *rowub = osinstance->getConstraintUpperBounds();

        for (i = 0; i < nconss; ++i)
        {
            row_nonz = 0;
            if( sm) row_nonz = sm->starts[ i +1] - sm->starts[ i];
            exprGroup::lincoeff con_lin( row_nonz);
            for (j = 0; j  <  row_nonz;  ++j)
            {
                con_lin[j].first = couenne->Var( sm->indexes[ kount] );
                con_lin[j].second = sm->values[ kount];
                kount++;
            }
            ScalarExpressionTree* exptree = osinstance->getNonlinearExpressionTree( i);
            if (exptree != NULL)
            {
                expression** nl = new expression*[1];
                nl[0] = createCouenneExpression(exptree->m_treeRoot);
                con_body = new exprGroup(0., con_lin, nl, 1);
            }
            else
            {
                con_body = new exprGroup(0., con_lin, NULL, 0);
            }

            if (rowlb[ i] == rowub[ i])
            {
                couenne->addEQConstraint(con_body, new exprConst( rowub[ i] ));
            }
            else if (rowlb[ i]  ==  -OSDBL_MAX)
            {
                assert(rowub[ i]  !=  -OSDBL_MAX);
                couenne->addLEConstraint(con_body, new exprConst( rowub[ i] ));
            }
            else if (rowub[ i] ==  OSDBL_MAX)
            {
                assert(rowlb[ i]  != OSDBL_MAX);
                couenne->addGEConstraint(con_body, new exprConst( rowlb[ i] ));
            }
            else
                couenne->addRNGConstraint(con_body, new exprConst( rowlb[ i]), new
                                          exprConst( rowub[ i] ));
        }
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


expression* CouenneSolver::createCouenneExpression(OSnLNode* node)
{
    unsigned int i;
    std::ostringstream outStr;

    switch (node->inodeInt)
    {
    case OS_PLUS :
        return new exprSum(createCouenneExpression(node->m_mChildren[0]), createCouenneExpression(node->m_mChildren[1]));
    case OS_SUM :
        switch ( node->inumberOfChildren )
        {
        case 0:
            return new exprConst(0.);
        case 1:
            return createCouenneExpression(node->m_mChildren[0]);
        default:
            expression** sumargs = new expression*[node->inumberOfChildren];
            for(i = 0;  i<  node->inumberOfChildren;  i++)
                sumargs[i] = createCouenneExpression(node->m_mChildren[i]);
            return new exprSum(sumargs, node->inumberOfChildren);
        }
    case OS_MINUS :
        return new exprSub(createCouenneExpression(node->m_mChildren[0]), createCouenneExpression(node->m_mChildren[1]));
    case OS_NEGATE :
        return new exprOpp(createCouenneExpression(node->m_mChildren[0]));
    case OS_TIMES :
        return new exprMul(createCouenneExpression(node->m_mChildren[0]), createCouenneExpression(node->m_mChildren[1]));
    case OS_DIVIDE :
        // couenne does not like expressions of the form exp1/exp2 with exp1 a constant, so we write them as exp1 * 1/exp2
        if (node->m_mChildren[0]->inodeInt == OS_NUMBER)
            return new exprMul(createCouenneExpression(node->m_mChildren[0]), new exprInv(createCouenneExpression(node->m_mChildren[1])));
        else
            return new exprDiv(createCouenneExpression(node->m_mChildren[0]), createCouenneExpression(node->m_mChildren[1]));
    case OS_POWER :
        // couenne does not like expressions of the form exp1 ^ exp2 with exp2 not a constant, so we write them as exp(log(exp1)*exp2)
        if (node->m_mChildren[1]->inodeInt != OS_NUMBER)
            return new exprExp(new exprMul(new exprLog(createCouenneExpression(node->m_mChildren[0])), createCouenneExpression(node->m_mChildren[1])));
        else
            return new exprPow(createCouenneExpression(node->m_mChildren[0]), createCouenneExpression(node->m_mChildren[1]));
    case OS_PRODUCT:
        switch ( node->inumberOfChildren )
        {
        case 0:
            return new exprConst(1.);
        case 1:
            return createCouenneExpression(node->m_mChildren[0]);
        default:
            expression** args = new expression*[node->inumberOfChildren];
            for( i = 0; i < node->inumberOfChildren; i++)
                args[i] = createCouenneExpression(node->m_mChildren[i]);
            expression* base = new exprMul(args, node->inumberOfChildren);
            return base;
        }
    case OS_ABS :
        return new exprAbs(createCouenneExpression(node->m_mChildren[0]));
    case OS_SQUARE :
        return new exprPow(createCouenneExpression(node->m_mChildren[0]), new exprConst(2.));
    case OS_SQRT :
        return new exprPow(createCouenneExpression(node->m_mChildren[0]), new exprConst(0.5));
    case OS_LN :
        return new exprLog(createCouenneExpression(node->m_mChildren[0]));
    case OS_EXP :
        return new exprExp(createCouenneExpression(node->m_mChildren[0]));
    case OS_SIN :
        return new exprSin(createCouenneExpression(node->m_mChildren[0]));
    case OS_COS :
        return new exprCos(createCouenneExpression(node->m_mChildren[0]));
    case OS_MIN :
        switch (node->inumberOfChildren)
        {
        case 0:
            return new exprConst(0.);
        case 1:
            return createCouenneExpression(node->m_mChildren[0]);
        default:
            expression** args = new expression*[node->inumberOfChildren];
            for( i = 0; i <node->inumberOfChildren; i++)
                args[i] = createCouenneExpression(node->m_mChildren[i]);
            expression* base = new exprMin(args, node->inumberOfChildren);
            return base;
        }
    case OS_MAX :
        switch (node->inumberOfChildren)
        {
        case 0:
            return new exprConst(0.);
        case 1:
            return createCouenneExpression(node->m_mChildren[0]);
        default:
            expression** args = new expression*[node->inumberOfChildren];
            for(i = 0; i < node->inumberOfChildren; i++)
                args[i] = createCouenneExpression(node->m_mChildren[i]);
            expression* base = new exprMax(args, node->inumberOfChildren);
            return base;
        }
    case OS_NUMBER :
        return new exprConst(((OSnLNodeNumber*)node)->value);
    case OS_PI :
        assert(false);
        //TODO
//    	 return new exprConst(PI);
    case OS_VARIABLE :
    {
        OSnLNodeVariable* varnode = (OSnLNodeVariable*)node;
        if (varnode->coef == 0.)
            return new exprConst(0.);
        if (varnode->coef == 1.)
            return new exprClone(couenne->Variables()[varnode->idx]);
        if (varnode->coef == -1.)
            return new exprOpp(new exprClone(couenne->Variables()[varnode->idx]));
        return new exprMul(new exprConst(varnode->coef), new exprClone(couenne->Variables()[varnode->idx]));
    }
    default:
        outStr.str("");
        outStr.clear();
        outStr << node->getTokenName() << " NOT IMPLEMENTED!!" << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
        break;
    }

    return NULL;
}


void CouenneSolver::setSolverOptions() throw (ErrorClass)
{
    std::ostringstream outStr;

    try
    {
        char *pEnd;
        bSetSolverOptions = true;
        couenneSetup.initializeOptionsAndJournalist();
        //turn off a lot of output -- this can be overridden by using OSOptions
        couenneSetup.options()->SetIntegerValue("bonmin.bb_log_level", 0);
        couenneSetup.options()->SetIntegerValue("bonmin.nlp_log_level", 0 );
        if(osoption == NULL && osol.length() > 0)
        {
            m_osolreader = new OSoLReader();
            osoption = m_osolreader->readOSoL( osol);
        }

        if(osoption != NULL && osoption->getNumberOfSolverOptions() > 0 )
        {
            int i;
            std::vector<SolverOption*> optionsVector;
            optionsVector = osoption->getSolverOptions( "couenne",true);
            int num_bonmin_options = optionsVector.size();
            std::string optionName;

            for(i = 0; i < num_bonmin_options; i++)
            {
                if(optionsVector[ i]->category == "ipopt")
                {
                    optionName = optionsVector[ i]->name;
                }
                else
                {
                    if(optionsVector[ i]->category == "bonmin" )
                    {
                        optionName = "bonmin."+optionsVector[ i]->name;
                    }
                    else
                    {
                        optionName = "couenne."+optionsVector[ i]->name;
                    }
                }

                outStr.str("");
                outStr.clear();
                outStr << "found option " << optionName << " of type " << optionsVector[ i]->type << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());

                if(optionsVector[ i]->type == "numeric" )
                {
                    couenneSetup.options()->SetNumericValue(optionName, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );
                }
                else if(optionsVector[ i]->type == "integer" )
                {
                    couenneSetup.options()->SetIntegerValue(optionName, atoi( optionsVector[ i]->value.c_str() ) );
                }
                else if(optionsVector[ i]->type == "string" )
                {
                    couenneSetup.options()->SetStringValue(optionName, optionsVector[ i]->value );
                }
            }
        }
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


using namespace Ipopt;


void CouenneSolver::solve() throw (ErrorClass)
{
#define PRINTED_PRECISION 1e-5
    const int infeasible = 1;
    //double time_start = CoinCpuTime();
    if( this->bCallbuildSolverInstance == false) buildSolverInstance();
    if(this->bSetSolverOptions == false) setSolverOptions() ;
    try
    {

        //couenne->print();

        char **argv = NULL;

	bb.setProblem(couenne);

        //using namespace Ipopt;

        if(osoption == NULL  && osol.length() > 0)
        {
            m_osolreader = new OSoLReader();
            osoption = m_osolreader->readOSoL( osol);
        }


        tminlp = new BonminProblem( osinstance, osoption);

        CouenneInterface *ci = NULL;

        ci = new CouenneInterface();

        ci->initialize (couenneSetup.roptions(),//GetRawPtr(roptions),
                        couenneSetup.options(),//GetRawPtr( options),
                        couenneSetup.journalist(),//GetRawPtr(jnlst),
                        GetRawPtr( tminlp) );

        app_ = new Bonmin::IpoptSolver(couenneSetup.roptions(),//GetRawPtr(roptions),
                                       couenneSetup.options(),//GetRawPtr( options),
                                       couenneSetup.journalist()//GetRawPtr(jnlst),
                                      );

        ci->setModel( GetRawPtr( tminlp) );
        ci->setSolver( GetRawPtr( app_) );

        // initialize causes lots of memory leaks
        bool setupInit = false;
        setupInit = couenneSetup.InitializeCouenne(argv, couenne, NULL, ci);


        if(setupInit == false)
        {
            std::string solutionDescription = "";
            std::string message = "Couenne solver finishes to the end.";
            int solIdx = 0;
            if(osresult->setServiceName( "Couenne solver service") != true)
                throw ErrorClass("OSResult error: setServiceName");
            if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
                throw ErrorClass("OSResult error: setInstanceName");
            if(osresult->setVariableNumber( osinstance->getVariableNumber()) != true)
                throw ErrorClass("OSResult error: setVariableNumer");
            if(osresult->setObjectiveNumber( 1) != true)
                throw ErrorClass("OSResult error: setObjectiveNumber");
            if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
                throw ErrorClass("OSResult error: setConstraintNumber");
            if(osresult->setSolutionNumber(  1) != true)
                throw ErrorClass("OSResult error: setSolutionNumer");
            if(osresult->setGeneralMessage( message) != true)
                throw ErrorClass("OSResult error: setGeneralMessage");
            solutionDescription = "COUENNE INITIALIZE PROBLEM: \n There was a problem with Couenne Initialize: \n the problem could be infeasible \n there may be zero decision variables";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            osresult->setGeneralStatusType("normal");
            osrl = osrlwriter->writeOSrL( osresult);
            return;

        }

        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, " \n\n");
        // see if we have an unbounded solution
        // if we are not infeasible and not optimal and have no integer variables we are probably unbounded
        if(( ci->isProvenPrimalInfeasible() == false) && (ci -> isProvenOptimal () == false)
                && (osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() <= 0) )
        {
            std::string solutionDescription = "";
            std::string message = "Success";
            int solIdx = 0;
            if(osresult->setServiceName( "Couenne solver service") != true)
                throw ErrorClass("OSResult error: setServiceName");
            if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
                throw ErrorClass("OSResult error: setInstanceName");
            if(osresult->setVariableNumber( osinstance->getVariableNumber()) != true)
                throw ErrorClass("OSResult error: setVariableNumer");
            if(osresult->setObjectiveNumber( 1) != true)
                throw ErrorClass("OSResult error: setObjectiveNumber");
            if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
                throw ErrorClass("OSResult error: setConstraintNumber");
            if(osresult->setSolutionNumber(  1) != true)
                throw ErrorClass("OSResult error: setSolutionNumer");
            if(osresult->setGeneralMessage( message) != true)
                throw ErrorClass("OSResult error: setGeneralMessage");
            solutionDescription = "CONTINUOUS_UNBOUNDED [COUENNE]: The continuous relaxation is unbounded, the MINLP may or may not be unbounded.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            osresult->setGeneralStatusType("normal");
            osrl = osrlwriter->writeOSrL( osresult);
            return;
        }

        bb ( couenneSetup); // do branch and bound

        CouenneCutGenerator *cg = NULL;

        if (bb.model (). cutGenerators ())
            cg = dynamic_cast <CouenneCutGenerator *>
                 (bb.model (). cutGenerators () [0] -> generator ());


        double global_opt;
        couenneSetup.options () -> GetNumericValue ("couenne_check", global_opt, "couenne.");
        double timeLimit = 0;
        couenneSetup.options () -> GetNumericValue ("time_limit", timeLimit, "couenne.");

        // now put information in OSResult object
        status = tminlp->status;
        writeResult();
    } //end try

    catch(const ErrorClass& eclass)
    {
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }

    // Pietro's catch

    catch(TNLPSolver::UnsolvedError *E)
    {
        E->writeDiffFiles();
        E->printError(std::cerr);
        //There has been a failure to solve a problem with Ipopt.
        //And we will output file with information on what has been changed in the problem to make it fail.
        //Now depending on what algorithm has been called (B-BB or other) the failed problem may be at different place.
        //    const OsiSolverInterface &si1 = (algo > 0) ? nlpSolver : *model.solver();

        osresult->setGeneralMessage("Ipopt has failed to solve a problem");
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }

    catch(OsiTMINLPInterface::SimpleError &E)
    {
        ostringstream outStr;
        outStr << E.className() << "::"<< E.methodName() << std::endl << E.message() << std::endl;

        osresult->setGeneralMessage(outStr.str());
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }

    catch(CoinError &E)
    {
        ostringstream outStr;
        outStr << E.className() << "::"<< E.methodName() << std::endl << E.message() << std::endl;

        osresult->setGeneralMessage(outStr.str());
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl);
    }

    catch (Ipopt::OPTION_INVALID &E)
    {
        ostringstream outStr;
        outStr << "Ipopt exception : " << E.Message() << std::endl;

        osresult->setGeneralMessage(outStr.str());
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl);
    }
    catch (int generic_error)
    {
        if (generic_error == infeasible)
        {
            osresult->setGeneralMessage("generic error: problem infeasible");
            osresult->setGeneralStatusType("error");
            osrl = osrlwriter->writeOSrL( osresult);
            throw ErrorClass( osrl);
        }
    }

}//end solve()


void CouenneSolver::writeResult()
{
    double *x = NULL;
    double *z = NULL;
    int i = 0;
    int solIdx = 0;
    std::string solutionDescription = "";
    std::string message = "Couenne solver finishes to the end.";


    try
    {
        if(osinstance->getVariableNumber()  > 0) x = new double[osinstance->getVariableNumber() ];
        z = new double[1];

        // resultHeader information
        if(osresult->setSolverInvoked( "COIN-OR Couenne") != true)
            throw ErrorClass("OSResult error: setSolverInvoked");
        if(osresult->setServiceName( OSgetVersionInfo()) != true)
            throw ErrorClass("OSResult error: setServiceName");
        if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
            throw ErrorClass("OSResult error: setInstanceName");

        // set basic problem parameters
        if(osresult->setVariableNumber( osinstance->getVariableNumber()) != true)
            throw ErrorClass("OSResult error: setVariableNumer");
        if(osresult->setObjectiveNumber( 1) != true)
            throw ErrorClass("OSResult error: setObjectiveNumber");
        if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
            throw ErrorClass("OSResult error: setConstraintNumber");
        if(osresult->setSolutionNumber(  1) != true)
            throw ErrorClass("OSResult error: setSolutionNumer");
        if(osresult->setGeneralMessage( message) != true)
            throw ErrorClass("OSResult error: setGeneralMessage");

        switch( status)
        {
        case  TMINLP::SUCCESS:
            solutionDescription = "SUCCESS[COUENNE]: Algorithm terminated normally at a locally optimal point, satisfying the convergence tolerances.";
            osresult->setSolutionStatus(solIdx,  "locallyOptimal", solutionDescription);

            if(osinstance->getObjectiveNumber() > 0)
            {
                /* Retrieve the solution */
                *(z + 0)  =  osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(bb.bestSolution()), true)[ 0];
                // okay if equal to 9999000000000 we are probably unbounded
                if(fabs(*(z + 0)) == 9.999e+12)
                {
                    solutionDescription = "CONTINUOUS_UNBOUNDED [COUENNE]: Continuous relaxation is unbounded, the MINLP may or may not be 		unbounded.";
                    osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
                    break;
                }
                osresult->setObjectiveValuesDense(solIdx, z);
            }


            if(osinstance->getVariableNumber() > 0)
            {
                for(i=0; i < osinstance->getVariableNumber(); i++)
                {
                    *(x + i) = bb.bestSolution()[i];
                }
                osresult->setPrimalVariableValuesDense(solIdx, x);
            }

            break;

        case TMINLP::LIMIT_EXCEEDED:
            solutionDescription = "LIMIT_EXCEEDED[COUENNE]: A resource limit was exceeded, we provide the current solution.";
            osresult->setSolutionStatus(solIdx,  "other", solutionDescription);
            /* Retrieve the solution */
            if(osinstance->getObjectiveNumber() > 0)
            {
                *(z + 0)  =  osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(bb.model().getColSolution()), true)[ 0];
                osresult->setObjectiveValuesDense(solIdx, z);
            }

            if(osinstance->getVariableNumber() > 0)
            {
                for(i=0; i < osinstance->getVariableNumber(); i++)
                {
                    *(x + i) = bb.model().getColSolution()[i];
                }
                osresult->setPrimalVariableValuesDense(solIdx, x);
            }
            break;

        case TMINLP::MINLP_ERROR:
            solutionDescription = "MINLP_ERROR [COUENNE]: Algorithm stopped with unspecified error.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);

            break;

        case TMINLP::CONTINUOUS_UNBOUNDED:
            solutionDescription = "CONTINUOUS_UNBOUNDED [COUENNE]: The continuous relaxation is unbounded, the MINLP may or may not be unbounded.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);

            break;

        case TMINLP::INFEASIBLE:
            solutionDescription = "INFEASIBLE [COUENNE]: Problem may be infeasible.";
            osresult->setSolutionStatus(solIdx,  "infeasible", solutionDescription);
            break;

        default:
            solutionDescription = "OTHER[COUENNE]: other unknown solution status from Couenne solver";
            osresult->setSolutionStatus(solIdx,  "other", solutionDescription);
        }//switch end

        osresult->setGeneralStatusType("normal");
        osrl = osrlwriter->writeOSrL( osresult);
        if(osinstance->getVariableNumber()  > 0) delete[] x;
        x = NULL;
        delete[] z;
        z = NULL;
    }//end try


    catch(const ErrorClass& eclass)
    {
        delete[] x;
        x = NULL;
        delete[] z;
        z = NULL;
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }

}// end writeResult()

