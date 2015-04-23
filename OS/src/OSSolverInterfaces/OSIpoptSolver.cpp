/* $Id$ */
/** @file IpoptSolver.cpp
 *
 * \brief This file defines the IpoptSolver class.
 * \detail Read an OSInstance object and convert to Ipopt data structures
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

#include "OSIpoptSolver.h"
#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSMathUtil.h"
#include "CoinFinite.hpp"
#include "OSOutput.h"


using std::cout;
using std::endl;
using std::ostringstream;
using namespace Ipopt;


IpoptSolver::IpoptSolver()
{
    osrlwriter = new OSrLWriter();
    osresult = new OSResult();
    m_osilreader = NULL;
    m_osolreader = NULL;
    ipoptErrorMsg = new std::string("");
}

IpoptSolver::~IpoptSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "inside IpoptSolver destructor\n");
#endif
    if(m_osilreader != NULL) delete m_osilreader;
    m_osilreader = NULL;
    if(m_osolreader != NULL) delete m_osolreader;
    m_osolreader = NULL;
    delete osresult;
    osresult = NULL;
    delete osrlwriter;
    osrlwriter = NULL;
    //delete osinstance;
    //osinstance = NULL;
    delete ipoptErrorMsg;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, "Leaving IpoptSolver destructor\n");
#endif
}

// returns the size of the problem
bool IpoptProblem::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                                Index& nnz_h_lag, IndexStyleEnum& index_style)
{
    std::ostringstream outStr;
    try
    {
        //if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Ipopt NEEDS AN OBJECTIVE FUNCTION");
        if( (osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables()) > 0 )
            throw ErrorClass("Ipopt does not solve integer programs -- please try Bonmin or Couenne");
        // number of variables
        n = osinstance->getVariableNumber();
        // number of constraints
        m = osinstance->getConstraintNumber();
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "number variables  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << n << endl;
        outStr << "number constraints  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << m << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
        try
        {
            osinstance->initForAlgDiff( );
        }
        catch(const ErrorClass& eclass)
        {
            outStr.str("");
            outStr.clear();
            outStr << "error in OSIpoptSolver, line 78:\n" << eclass.errormsg << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, outStr.str());
            *ipoptErrorMsg = eclass.errormsg;
            throw;
        }
        // use the OS Expression tree for function evaluations instead of CppAD
        osinstance->bUseExpTreeForFunEval = true;
        SparseJacobianMatrix *sparseJacobian = NULL;
        try
        {
            sparseJacobian = osinstance->getJacobianSparsityPattern();
        }
        catch(const ErrorClass& eclass)
        {
            outStr.str("");
            outStr.clear();
            outStr << "error in OSIpoptSolver, line 91:\n" << eclass.errormsg << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, outStr.str());
            *ipoptErrorMsg = eclass.errormsg;
            throw;
        }
        if (sparseJacobian != NULL)
        {
            nnz_jac_g = sparseJacobian->valueSize;
        }
        else
        {
            nnz_jac_g = 0;
        }

#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "nnz_jac_g  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << nnz_jac_g << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
        // nonzeros in upper hessian

        if( (osinstance->getNumberOfNonlinearExpressions() == 0) && (osinstance->getNumberOfQuadraticTerms() == 0) )
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "This is a linear program\n");
#endif
            nnz_h_lag = 0;
        }
        else
        {
            SparseHessianMatrix *sparseHessian = osinstance->getLagrangianHessianSparsityPattern();
            if(sparseHessian != NULL)
            {
                nnz_h_lag = sparseHessian->hessDimension;
            }
            else
            {
                nnz_h_lag = 0;
            }
        }
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "print nnz_h_lag (OSIpoptSolver.cpp)" << endl;
        outStr << "nnz_h_lag  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << nnz_h_lag << endl;
        outStr << "set index_style (OSIpoptSolver.cpp)" << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
        // use the C style indexing (0-based)
        index_style = TNLP::C_STYLE;
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "return from get_nlp_info (OSIpoptSolver.cpp)" << nnz_h_lag << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

        /////

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        *ipoptErrorMsg = eclass.errormsg;
        throw;
    }

}//get_nlp_info


bool  IpoptProblem::get_bounds_info(Index n, Number* x_l, Number* x_u,
                                    Index m, Number* g_l, Number* g_u)
{
    int i;
    double * mdVarLB = osinstance->getVariableLowerBounds();
    // variables upper bounds
    double * mdVarUB = osinstance->getVariableUpperBounds();

    for(i = 0; i < n; i++)
    {
        x_l[ i] = mdVarLB[ i];
        x_u[ i] = mdVarUB[ i];
    }
    // Ipopt interprets any number greater than nlp_upper_bound_inf as
    // infinity. The default value of nlp_upper_bound_inf and nlp_lower_bound_inf
    // is 1e19 and can be changed through ipopt options.
    // e.g. g_u[0] = 2e19;

    //constraint lower bounds
    double * mdConLB = osinstance->getConstraintLowerBounds();
    //constraint upper bounds
    double * mdConUB = osinstance->getConstraintUpperBounds();

    for(int i = 0; i < m; i++)
    {
        g_l[ i] = mdConLB[ i];
        g_u[ i] = mdConUB[ i];
    }
    return true;
}//get_bounds_info


// returns the initial point for the problem
bool IpoptProblem::get_starting_point(Index n, bool init_x, Number* x,
                                      bool init_z, Number* z_L, Number* z_U, Index m, bool init_lambda,
                                      Number* lambda)
{
    std::ostringstream outStr;

    // Here, we assume we only have starting values for x, if you code
    // your own NLP, you can provide starting values for the dual variables
    // if you wish
    assert(init_x == true);
    assert(init_z == false);
    assert(init_lambda == false);
    int i, m1, n1;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "get initial values !!!!!!!!!!!!!!!!!!!!!!!!!!\n");
#endif

    //now set initial values
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "get number of initial values !!!!!!!!!!!!!!!!!!!!!!!!!!\n");
#endif
    int k;
    if (osoption != NULL)
        m1 = osoption->getNumberOfInitVarValues();
    else
        m1 = 0;
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "number of variables initialed: " << m1 << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    n1 = osinstance->getVariableNumber();
    bool* initialed;
    initialed = new bool[n1];
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "number of variables in total: " << n1 << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    for(k = 0; k < n1; k++)
        initialed[k] = false;

    if (m1 > 0)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "get initial values\n");
#endif

        InitVarValue**  initVarVector = osoption->getInitVarValuesSparse();
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "done\n");
#endif
        try
        {
            double initval;
            for(k = 0; k < m1; k++)
            {
                i = initVarVector[k]->idx;
                if (initVarVector[k]->idx > n1)
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

                x[initVarVector[k]->idx] = initval;
                initialed[initVarVector[k]->idx] = true;
            }
        }
        catch(const ErrorClass& eclass)
        {
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, 
                "Error in IpoptProblem::get_starting_point (see OSIpoptSolver.cpp)\n"+eclass.errormsg+"\n\n");
        }
    }  //  end if (m1 > 0)

    double default_initval;
    default_initval = 1.7171;
    //default_initval = 0;

    for(k = 0; k < n1; k++)
    {
        if (!initialed[k])
        {
            if (osinstance->instanceData->variables->var[k]->ub == OSDBL_MAX)
                if (osinstance->instanceData->variables->var[k]->lb <= default_initval)
                    x[k] = default_initval;
                else
                    x[k] = osinstance->instanceData->variables->var[k]->lb;
            else if (osinstance->instanceData->variables->var[k]->lb == -OSDBL_MAX)
                if (osinstance->instanceData->variables->var[k]->ub >= default_initval)
                    x[k] = default_initval;
                else
                    x[k] = osinstance->instanceData->variables->var[k]->ub;
            else if ((osinstance->instanceData->variables->var[k]->lb <= default_initval) &&
                     (osinstance->instanceData->variables->var[k]->ub >= default_initval))
                x[k] = default_initval;
            else if (osinstance->instanceData->variables->var[k]->lb > default_initval)
                x[k] = osinstance->instanceData->variables->var[k]->lb;
            else
                x[k] = osinstance->instanceData->variables->var[k]->ub;
        }
    }

#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    for(i = 0; i < n1; i++)
    {
        outStr << "INITIAL VALUE !!!!!!!!!!!!!!!!!!!!  " << x[ i] << std::endl;
    }
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
    //make sure objvalue is initialized
    osinstance->calculateAllObjectiveFunctionValues( x, true);
    delete[] initialed;

    return true;
}//get_starting_point

// returns the value of the objective function
bool IpoptProblem::eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{
    try
    {
        if(osinstance->getObjectiveNumber() > 0)
        {
            //the following is a kludge for ipopt, new_x does not seem to get initialized if there are no constraints.
            //if(osinstance->getConstraintNumber() <= 0) new_x = true;
            if (new_x == false) 
                obj_value = osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(x), false)[ 0];
            else 
                obj_value = osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(x), NULL, NULL, true, 0 )[ 0];
            //if( CoinIsnan( (double)obj_value) ) return false;
            //if( CoinIsnan( obj_value ) )return false;
        }
    }
    catch(const ErrorClass& eclass)
    {
        *ipoptErrorMsg = eclass.errormsg;
        throw;
    }

    return true;
}

bool IpoptProblem::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
    std::ostringstream outStr;
    int i;
    double *objGrad = NULL;
    if(osinstance->getObjectiveNumber() > 0)
    {
        try
        {
            //objGrad = osinstance->calculateAllObjectiveFunctionGradients( const_cast<double*>(x), NULL, NULL,  new_x, 1)[ 0];
            objGrad = osinstance->calculateObjectiveFunctionGradient( const_cast<double*>(x), NULL, NULL, -1,  new_x, 1);
        }
        catch(const ErrorClass& eclass)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "error in IpoptProblem::eval_grad_f (see OSIpoptSolver.cpp)\n" << eclass.errormsg << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            *ipoptErrorMsg = eclass.errormsg;
            throw;
        }
        for(i = 0; i < n; i++)
        {
            grad_f[ i]  = objGrad[ i];
        }
    }
    return true;
}//eval_grad_f

// return the value of the constraints: g(x)
bool IpoptProblem::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{
    std::ostringstream outStr;
    try
    {
        double *conVals = osinstance->calculateAllConstraintFunctionValues( const_cast<double*>(x), NULL, NULL, new_x, 0 );
        int i;
        for(i = 0; i < m; i++)
        {
            if( CoinIsnan( (double)conVals[ i] ) ) return false;
            g[i] = conVals[ i]  ;
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "error in IpoptProblem::eval_grad_g (see OSIpoptSolver.cpp)\n" << eclass.errormsg << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
        *ipoptErrorMsg = eclass.errormsg;
        throw;
    }
}//eval_g


// return the structure or values of the jacobian
bool IpoptProblem::eval_jac_g(Index n, const Number* x, bool new_x,
                              Index m, Index nele_jac, Index* iRow, Index *jCol,
                              Number* values)
{
    std::ostringstream outStr;
    SparseJacobianMatrix *sparseJacobian;
    if (values == NULL)
    {
        // return the structure of the jacobian
        try
        {
            sparseJacobian = osinstance->getJacobianSparsityPattern();
        }
        catch(const ErrorClass& eclass)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "error in IpoptProblem::eval_jac_g (see OSIpoptSolver.cpp)\n" << eclass.errormsg << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            *ipoptErrorMsg =  eclass.errormsg;
            throw;
        }
        int i = 0;
        int k, idx;
        for(idx = 0; idx < m; idx++)
        {
            for(k = *(sparseJacobian->starts + idx); k < *(sparseJacobian->starts + idx + 1); k++)
            {
                iRow[i] = idx;
                jCol[i] = *(sparseJacobian->indexes + k);
                i++;
            }
        }
    }
    else
    {
        try
        {
            sparseJacobian = osinstance->calculateAllConstraintFunctionGradients( const_cast<double*>(x), NULL, NULL,  new_x, 1);
        }
        catch(const ErrorClass& eclass)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "error in IpoptProblem::eval_jac_g (see OSIpoptSolver.cpp)\n" << eclass.errormsg << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            *ipoptErrorMsg = eclass.errormsg;
            throw;
        }
        //osinstance->getIterateResults( (double*)x, 0.0, NULL, -1, new_x,  1);
        for(int i = 0; i < nele_jac; i++)
        {
            values[ i] = sparseJacobian->values[i];
        }
    }
    return true;
}//eval_jac_g

//return the structure or values of the hessian
bool IpoptProblem::eval_h(Index n, const Number* x, bool new_x,
                          Number obj_factor, Index m, const Number* lambda,
                          bool new_lambda, Index nele_hess, Index* iRow,
                          Index* jCol, Number* values)
{
    std::ostringstream outStr;

//////
    SparseHessianMatrix *sparseHessian;

    int i;
    if (values == NULL)
    {
        // return the structure. This is a symmetric matrix, fill the lower left triangle only.
        try
        {
            sparseHessian = osinstance->getLagrangianHessianSparsityPattern( );
        }
        catch(const ErrorClass& eclass)
        {

            *ipoptErrorMsg = eclass.errormsg;
            throw;
        }
        for(i = 0; i < nele_hess; i++)
        {
            iRow[i] = *(sparseHessian->hessColIdx + i);
            jCol[i] = *(sparseHessian->hessRowIdx + i);
        }
    }
    else
    {
        // return the values. This is a symmetric matrix, fill the lower left triangle only
        double* objMultipliers = new double[1];
        objMultipliers[0] = obj_factor;
        try
        {
            sparseHessian = osinstance->calculateLagrangianHessian( const_cast<double*>(x), objMultipliers, const_cast<double*>(lambda) ,  new_x, 2);
            delete[]  objMultipliers;
        }
        catch(const ErrorClass& eclass)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "error in OSIpoptSolver, line 444:\n" << eclass.errormsg << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            *ipoptErrorMsg = eclass.errormsg;
            delete[]  objMultipliers;
            throw;
        }
        for(i = 0; i < nele_hess; i++)
        {
            values[ i]  = *(sparseHessian->hessValues + i);
        }
    }
///////
    return true;
}//eval_h

bool IpoptProblem::get_scaling_parameters(Number& obj_scaling,
        bool& use_x_scaling, Index n,
        Number* x_scaling,
        bool& use_g_scaling, Index m,
        Number* g_scaling)
{
    if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") != 0)
    {
        obj_scaling = -1;
    }
    else obj_scaling = 1;
    use_x_scaling = false;
    use_g_scaling = false;
    return true;
}//get_scaling_parameters

void IpoptProblem::finalize_solution(SolverReturn status,
                                     Index n, const Number* x, const Number* z_L, const Number* z_U,
                                     Index m, const Number* g, const Number* lambda, Number obj_value,
                                     const IpoptData* ip_data, IpoptCalculatedQuantities* ip_cq)
{
    // here is where we would store the solution to variables, or write to a file, etc
    // so we could use the solution.
    // For this example, we write the solution to the console
    if(osinstance->getObjectiveNumber() > 0)
        obj_value = osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(x), true)[ 0];
    OSrLWriter *osrlwriter ;
    osrlwriter = new OSrLWriter();

    ostringstream outStr;
#ifdef DEBUG

    outStr << std::endl << std::endl << "Solution of the primal variables, x" << std::endl;
    for (Index i=0; i<n; i++)
    {
        outStr << "x[" << i << "] = " << x[i] << std::endl;
    }

    outStr << std::endl << std::endl << "Solution of the bound multipliers, z_L and z_U" << std::endl;
    for (Index i=0; i<n; i++)
    {
        outStr << "z_L[" << i << "] = " << z_L[i] << std::endl;
    }
    for (Index i=0; i<n; i++)
    {
        outStr << "z_U[" << i << "] = " << z_U[i] << std::endl;
    }
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
    outStr.str("");
    outStr.clear();
#endif
    if(osinstance->getObjectiveNumber() > 0)   
    {
        outStr << std::endl << "Objective value f(x*) = " << os_dtoa_format(obj_value) << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_summary, outStr.str());
    }
    int solIdx = 0;
    int numberOfOtherVariableResults;
    int otherIdx;
    int numCon = osinstance->getConstraintNumber();

    //make sure the sign on the dual values is correct
    double *dualValue = NULL;
    std::string *rcost = NULL;
    int* idx = NULL;
    double*  mdObjValues = NULL;
    if(osinstance->getObjectiveNumber() > 0)
    {
        mdObjValues = new double[1];
    }

    std::string message = "Ipopt solver finishes to the end.";
    std::string solutionDescription = "";

    try
    {
        // resultHeader information
        if(osresult->setSolverInvoked( "COIN-OR Ipopt") != true)
            throw ErrorClass("OSResult error: setSolverInvoked");
        if(osresult->setServiceName( OSgetVersionInfo()) != true)
            throw ErrorClass("OSResult error: setServiceName");
        if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
            throw ErrorClass("OSResult error: setInstanceName");

        //if(osresult->setJobID( osoption->jobID) != true)
        //    throw ErrorClass("OSResult error: setJobID");

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
        case SUCCESS:
            solutionDescription = "SUCCESS[IPOPT]: Algorithm terminated normally at a locally optimal point, satisfying the convergence tolerances.";
            osresult->setSolutionStatus(solIdx,  "locallyOptimal", solutionDescription);

            if(osinstance->getVariableNumber() > 0) osresult->setPrimalVariableValuesDense(solIdx, const_cast<double*>(x));

            if(numCon > 0)
            {
                dualValue = new double[ numCon];
                for (Index i=0; i < numCon; i++)
                {
                    dualValue[ i] = -lambda[ i];
                }
                //osresult->setDualVariableValuesDense(solIdx, const_cast<double*>(lambda));
                osresult->setDualVariableValuesDense(solIdx, dualValue);
            }

            if(osinstance->getObjectiveNumber() > 0)
            {



                mdObjValues[0] = obj_value ;
                osresult->setObjectiveValuesDense(solIdx, mdObjValues);
            }
            // set other

            if(osinstance->getVariableNumber() > 0)
            {
                numberOfOtherVariableResults = 1;
                osresult->setNumberOfOtherVariableResults(solIdx, numberOfOtherVariableResults);
                rcost = new std::string[ osinstance->getVariableNumber()];
                idx = new int[ osinstance->getVariableNumber()];
                for (Index i = 0; i < n; i++)
                {
                    rcost[ i] =  os_dtoa_format( z_L[i] - z_U[i]);
                    idx[ i] = i;
                }
                otherIdx = 0;
                osresult->setAnOtherVariableResultSparse(solIdx, otherIdx, "reduced_costs", "", "the variable reduced costs",
                        idx, rcost, osinstance->getVariableNumber(), "", "double", "");
            }
            //set dual values on variable upper and lower bounds
            /*
            for (Index i = 0; i < n; i++) {
                rcost[ i] =  os_dtoa_format( z_L[i]);
                idx[ i] = i;
             }
            otherIdx = 0;
            osresult->setAnOtherVariableResultSparse(solIdx, otherIdx, "varL", "", "Lagrange Multiplier on the Variable Lower Bound",  idx,  rcost,  osinstance->getVariableNumber() );


            for (Index i = 0; i < n; i++) {
                rcost[ i] =  os_dtoa_format( z_U[i]);
             }
            otherIdx = 1;
            osresult->setAnOtherVariableResultSparse(solIdx, otherIdx, "varU", "", "Lagrange Multiplier on the Variable Upper Bound", idx,  rcost, osinstance->getVariableNumber() );
            */
            if(osinstance->getVariableNumber() > 0) delete[] rcost;
            if(osinstance->getVariableNumber() > 0) delete[] idx;
            if(osinstance->getConstraintNumber() > 0) delete[] dualValue;

            // done with other


            break;
        case MAXITER_EXCEEDED:
            solutionDescription = "MAXITER_EXCEEDED[IPOPT]: Maximum number of iterations exceeded.";
            osresult->setSolutionStatus(solIdx,  "stoppedByLimit", solutionDescription);
            if(x != NULL) osresult->setPrimalVariableValuesDense(solIdx, const_cast<double*>(x));
            if(lambda != NULL) osresult->setDualVariableValuesDense(solIdx, const_cast<double*>( lambda));
            if(osinstance->getObjectiveNumber() > 0)
            {
                mdObjValues[0] = obj_value ;
                osresult->setObjectiveValuesDense(solIdx, mdObjValues);
            }
            break;
        case STOP_AT_TINY_STEP:
            solutionDescription = "STOP_AT_TINY_STEP[IPOPT]: Algorithm proceeds with very little progress.";
            osresult->setSolutionStatus(solIdx,  "stoppedByLimit", solutionDescription);
            if(x != NULL) osresult->setPrimalVariableValuesDense(solIdx, const_cast<double*>( x));
            if(lambda != NULL) osresult->setDualVariableValuesDense(solIdx, const_cast<double*>( lambda));
            if(osinstance->getObjectiveNumber() > 0)
            {
                mdObjValues[0] = obj_value ;
                osresult->setObjectiveValuesDense(solIdx, mdObjValues);
            }
            break;
        case STOP_AT_ACCEPTABLE_POINT:
            solutionDescription = "STOP_AT_ACCEPTABLE_POINT[IPOPT]: Algorithm stopped at a point that was converged, not to _desired_ tolerances, but to _acceptable_ tolerances";
            osresult->setSolutionStatus(solIdx,  "IpoptAccetable", solutionDescription);
            if(lambda != NULL) osresult->setDualVariableValuesDense(solIdx, const_cast<double*>( lambda));
            if(x != NULL)osresult->setPrimalVariableValuesDense(solIdx, const_cast<double*>(x));
            if(osinstance->getObjectiveNumber() > 0)
            {
                mdObjValues[0] = obj_value ;
                osresult->setObjectiveValuesDense(solIdx, mdObjValues);
            }
            break;
        case LOCAL_INFEASIBILITY:
            solutionDescription = "LOCAL_INFEASIBILITY[IPOPT]: Algorithm converged to a point of local infeasibility. Problem may be infeasible.";
            osresult->setSolutionStatus(solIdx,  "infeasible", solutionDescription);
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
            break;
        case USER_REQUESTED_STOP:
            solutionDescription = "USER_REQUESTED_STOP[IPOPT]: The user call-back function  intermediate_callback returned false, i.e., the user code requested a premature termination of the optimization.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
            break;
        case DIVERGING_ITERATES:
            solutionDescription = "DIVERGING_ITERATES[IPOPT]: It seems that the iterates diverge.";
            osresult->setSolutionStatus(solIdx,  "unbounded", solutionDescription);
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
            break;
        case RESTORATION_FAILURE:
            solutionDescription = "RESTORATION_FAILURE[IPOPT]: Restoration phase failed, algorithm doesn't know how to proceed.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
            break;
        case ERROR_IN_STEP_COMPUTATION:
            solutionDescription = "ERROR_IN_STEP_COMPUTATION[IPOPT]: An unrecoverable error occurred while IPOPT tried to compute the search direction.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
            break;
        case INVALID_NUMBER_DETECTED:
            solutionDescription = "INVALID_NUMBER_DETECTED[IPOPT]: Algorithm received an invalid number (such as NaN or Inf) from the NLP; see also option check_derivatives_for_naninf.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
            break;
        case INTERNAL_ERROR:
            solutionDescription = "INTERNAL_ERROR[IPOPT]: An unknown internal error occurred. Please contact the IPOPT authors through the mailing list.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");

            break;
        default:
            solutionDescription = "OTHER[IPOPT]: other unknown solution status from Ipopt solver";
            osresult->setSolutionStatus(solIdx,  "other", solutionDescription);
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
        }

        osresult->setGeneralStatusType("normal");
        delete osrlwriter;
        osrlwriter = NULL;
        if(osinstance->getObjectiveNumber() > 0)
        {
            delete[] mdObjValues;
        }

        return;
    }
    catch(const ErrorClass& eclass)
    {
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "error trap in OSIpoptSolver:\n" << eclass.errormsg << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        std::string osrl = osrlwriter->writeOSrL( osresult);
        delete osrlwriter;
        osrlwriter = NULL;
        if(osinstance->getObjectiveNumber() > 0)
        {
            delete[] mdObjValues;
        }
        mdObjValues = NULL;
        throw ErrorClass(  osrl) ;
    }
//////////
}


void IpoptSolver::setSolverOptions() throw (ErrorClass)
{
    std::ostringstream outStr;
    try
    {
        if(osinstance->getObjectiveNumber() <= 0) 
            throw ErrorClass("Ipopt NEEDS AN OBJECTIVE FUNCTION\n(For pure feasibility problems, use zero function.)");
        this->bSetSolverOptions = true;
        /* set the default options */
        //app->Options()->SetNumericValue("tol", 1e-9);
        app->Options()->SetIntegerValue("print_level", 0);
        app->Options()->SetIntegerValue("max_iter", 20000);
        app->Options()->SetNumericValue("bound_relax_factor", 0, true, true);
        app->Options()->SetStringValue("mu_strategy", "adaptive", true, true);
        //app->Options()->SetStringValue("output_file", "ipopt.out");
        app->Options()->SetStringValue("check_derivatives_for_naninf", "yes");
        // hessian constant for an LP
        if( (osinstance-> getNumberOfNonlinearExpressions() <= 0) && (osinstance->getNumberOfQuadraticTerms() <= 0) )
        {
            app->Options()->SetStringValue("hessian_constant", "yes", true, true);
        }
        if(osinstance->getObjectiveNumber() > 0)
        {
            if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") != 0)
            {
                app->Options()->SetStringValue("nlp_scaling_method", "user-scaling");
            }
        }
        /* end of the default options, now get options from OSoL */


        if(osoption == NULL && osol.length() > 0)
        {
            m_osolreader = new OSoLReader();
            osoption = m_osolreader->readOSoL( osol);
        }

        if( osoption != NULL  &&  osoption->getNumberOfSolverOptions() > 0 )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "number of solver options ";
            outStr << osoption->getNumberOfSolverOptions();
            outStr << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            std::vector<SolverOption*> optionsVector;
            optionsVector = osoption->getSolverOptions( "ipopt",true);
            char *pEnd;
            int i;
            int num_ipopt_options = optionsVector.size();
            for(i = 0; i < num_ipopt_options; i++)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "ipopt solver option  ";
                outStr << optionsVector[ i]->name;
                outStr << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                if(optionsVector[ i]->type == "numeric" )
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "FOUND A NUMERIC OPTION  ";
                    outStr << os_strtod( optionsVector[ i]->value.c_str(), &pEnd );
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                    app->Options()->SetNumericValue(optionsVector[ i]->name, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );
                }
                else if(optionsVector[ i]->type == "integer" )
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "FOUND AN INTEGER OPTION  ";
                    outStr << atoi( optionsVector[ i]->value.c_str() );
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                    app->Options()->SetIntegerValue(optionsVector[ i]->name, atoi( optionsVector[ i]->value.c_str() ) );
                }
                else if(optionsVector[ i]->type == "string" )
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "FOUND A STRING OPTION  ";
                    outStr << optionsVector[ i]->value.c_str();
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
                    app->Options()->SetStringValue(optionsVector[ i]->name, optionsVector[ i]->value);
                }
            }
        }
        return;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, "Error while setting options in IpoptSolver\n");
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//end setSolverOptions()



void IpoptSolver::buildSolverInstance() throw (ErrorClass)
{
    std::ostringstream outStr;
    try
    {
        if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
        if(osinstance == NULL)
        {
            m_osilreader = new OSiLReader();
            osinstance = m_osilreader->readOSiL( osil);
        }

        // Can't handle multiobjective problems properly --- especially nonlinear ones
        if (osinstance->getObjectiveNumber() > 1)
            throw ErrorClass("Solver cannot handle multiple objectives --- please delete all but one");

        // Create a new instance of your nlp
        nlp = new IpoptProblem( osinstance, osoption, osresult, ipoptErrorMsg);
        app = new IpoptApplication();

        this->bCallbuildSolverInstance = true;
        return;
    }
    catch(const ErrorClass& eclass)
    {
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "error in OSIpoptSolver, line 722:\n" << eclass.errormsg << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//end buildSolverInstance()



void IpoptSolver::solve() throw (ErrorClass)
{
    std::ostringstream outStr;

    if( this->bCallbuildSolverInstance == false) buildSolverInstance();
    if( this->bSetSolverOptions == false) setSolverOptions();
    try
    {
        app->Initialize();
        ApplicationReturnStatus status = app->OptimizeTNLP( nlp);
        osrl = osrlwriter->writeOSrL( osresult);
        if (status < -2)
        {
            throw ErrorClass("Ipopt FAILED TO SOLVE THE PROBLEM: " + *ipoptErrorMsg);
        }
        return;
    }
    catch(const ErrorClass& eclass)
    {
        outStr.str("");
        outStr.clear();
        outStr << "error in OSIpoptSolver routine solve():\n" << eclass.errormsg << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, outStr.str());

        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//solve


void IpoptSolver::dataEchoCheck()
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
            if(osinstance->getVariableNames() != NULL)
                cout << "variable Names  " << osinstance->getVariableNames()[i]  << endl;
            if(osinstance->getVariableTypes() != NULL)
                cout << "variable Types  " << osinstance->getVariableTypes()[i]  << endl;
            if(osinstance->getVariableLowerBounds() != NULL)
                cout << "variable Lower Bounds  " << osinstance->getVariableLowerBounds()[i] << endl;
            if(osinstance->getVariableUpperBounds() != NULL)
                cout << "variable Upper Bounds  " << osinstance->getVariableUpperBounds()[i] << endl;
        }
    }

    // print out objective function information
    if(osinstance->getVariableNumber() > 0 || osinstance->instanceData->objectives->obj != NULL || osinstance->instanceData->objectives->numberOfObjectives > 0)
    {
        if( osinstance->getObjectiveMaxOrMins()[0] == "min")
            cout <<  "problem is a minimization" << endl;
        else 
            cout <<  "problem is a maximization" << endl;
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
    cout << endl;
    cout << "number of nonzeros =  " << osinstance->getLinearConstraintCoefficientNumber() << endl;
    for(i = 0; i <= osinstance->getVariableNumber(); i++)
    {
        cout << "Start Value =  " << osinstance->getLinearConstraintCoefficientsInColumnMajor()->starts[ i] << endl;
    }
    cout << endl;
    for(i = 0; i < osinstance->getLinearConstraintCoefficientNumber(); i++)
    {
        cout << "Index Value =  " << osinstance->getLinearConstraintCoefficientsInColumnMajor()->indexes[i] << endl;
        cout << "Nonzero Value =  " << osinstance->getLinearConstraintCoefficientsInColumnMajor()->values[i] << endl;
    }

    // print out quadratic data
    cout << "number of qterms =  " <<  osinstance->getNumberOfQuadraticTerms() << endl;
    for(int i = 0; i <  osinstance->getNumberOfQuadraticTerms(); i++)
    {
        cout << "Row Index = " <<  osinstance->getQuadraticTerms()->rowIndexes[i] << endl;
        cout << "Var Index 1 = " << osinstance->getQuadraticTerms()->varOneIndexes[ i] << endl;
        cout << "Var Index 2 = " << osinstance->getQuadraticTerms()->varTwoIndexes[ i] << endl;
        cout << "Coefficient = " << osinstance->getQuadraticTerms()->coefficients[ i] << endl;
    }
    return;
} // end dataEchoCheck


IpoptProblem::IpoptProblem(OSInstance *osinstance_,  OSOption *osoption_, OSResult *osresult_, std::string* ipoptErrorMsg_)
{
    osinstance = osinstance_;
    osoption = osoption_;
    osresult = osresult_;
    ipoptErrorMsg = ipoptErrorMsg_;
}

IpoptProblem::~IpoptProblem()
{

}

