/* $Id$ */
/** @file BonminSolver.cpp
 *
 * \brief This file defines the BonminSolver class.
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

#include "OSBonminSolver.h"
#include "OSGeneral.h"
#include "OSOutput.h"
#include "OSParameters.h"
#include "OSMathUtil.h"
#include "CoinFinite.hpp"
#include "CoinTime.hpp"
#include "BonOsiTMINLPInterface.hpp"
#include "BonTMINLP.hpp"

using namespace Bonmin;
using namespace Ipopt;

using std::endl;
using std::ostringstream;

BonminSolver::BonminSolver()
{
    osrlwriter = new OSrLWriter();
    osresult = new OSResult();
    m_osilreader = NULL;
    m_osolreader = NULL;
    bonminErrorMsg = "";
}

BonminSolver::~BonminSolver()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "inside BonminSolver destructor\n");
#endif
    if(m_osilreader != NULL) delete m_osilreader;
    m_osilreader = NULL;
    if(m_osolreader != NULL) delete m_osolreader;
    m_osolreader = NULL;

    if(osrlwriter != NULL )delete osrlwriter;
    osrlwriter = NULL;
    if(osresult != NULL )
    {
        delete osresult;
        osresult = NULL;
    }
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, "leaving BonminSolver destructor\n");
#endif
}


bool BonminProblem::get_variables_types(Index n, VariableType* var_types)
{
    int i = 0;
    char *varType;
    varType = osinstance->getVariableTypes();
    n = osinstance->getVariableNumber();
    for(i = 0; i < n;   i++)
    {
        if( varType[i] == 'B')
        {
            var_types[i] = BINARY;
        }
        else
        {
            if( varType[i] == 'I')
            {
                var_types[i] = INTEGER;
            }
            else
            {
                if( varType[i] == 'C')
                {
                    var_types[i] = CONTINUOUS;
                }
                else
                {
                    throw ErrorClass("variable type not yet implemented");
                }
            }
        }
    }
    return true;
}


bool BonminProblem::get_variables_linearity(Index n, Ipopt::TNLP::LinearityType* var_types)
{
    std::ostringstream outStr;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, "Initialize Nonlinear Structures\n");
    try
    {
        osinstance->initForAlgDiff( );
    }
    catch(const ErrorClass& eclass)
    {
        bonminErrorMsg = eclass.errormsg;
        throw;
    }
    /**
     * get an index map of the nonlinear variables
     * and see which variable are in <nonlinearExpressions>
     * element
     */
    std::map<int, int> varIndexMap;
    std::map<int, int>::iterator posVarIndexMap;
    varIndexMap = osinstance->getAllNonlinearVariablesIndexMap( );
    /* first make all continuous */

    int i;

    for(i = 0; i < n; i++)
    {
        var_types[ i] = Ipopt::TNLP::LINEAR;
    }
    /**
     * iterate through and get an index of all variables that
     * are in <nonlinearExpressions> element
     */
    outStr.str("");
    outStr.clear();
    for(posVarIndexMap = varIndexMap.begin(); posVarIndexMap != varIndexMap.end(); ++posVarIndexMap)
    {
        outStr <<  "Variable Index = "   << posVarIndexMap->first  << std::endl ;
        var_types[ posVarIndexMap->first] = Ipopt::TNLP::NON_LINEAR;
    }
    outStr << "Number of nonlinear variables =  " << varIndexMap.size() << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());

    return true;
}

bool BonminProblem::get_constraints_linearity(Index m, Ipopt::TNLP::LinearityType* const_types)
{
    std::ostringstream outStr;
    int i;

    for(i  = 0; i < m; i++)
    {
        const_types[ i] = Ipopt::TNLP::LINEAR;
    }

    int mm = osinstance->getNumberOfNonlinearExpressionTreeModIndexes();

    outStr.str("");
    outStr.clear();
    for(i = 0; i < mm; i++)
    {
        if(osinstance->getNonlinearExpressionTreeModIndexes()[ i] >= 0)
        {
            outStr << osinstance->getNonlinearExpressionTreeModIndexes()[ i] << std::endl;
            const_types[ osinstance->getNonlinearExpressionTreeModIndexes()[ i] ] = Ipopt::TNLP::NON_LINEAR;
        }
    }
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());

    return true;
}

// returns the size of the problem
bool BonminProblem::get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                                 Index& nnz_h_lag, TNLP::IndexStyleEnum& index_style)
{
    std::ostringstream outStr;
    //if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Bonmin NEEDS AN OBJECTIVE FUNCTION");
    // number of variables
    n = osinstance->getVariableNumber();
    // number of constraints
    m = osinstance->getConstraintNumber();
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "Bonmin number variables  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << n << endl;
    outStr << "Bonmin number constraints  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << m << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
    try
    {
        osinstance->initForAlgDiff( );
    }
    catch(const ErrorClass& eclass)
    {
        bonminErrorMsg = eclass.errormsg;
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
        bonminErrorMsg = eclass.errormsg;
        throw;
    }
    nnz_jac_g = sparseJacobian->valueSize;
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "nnz_jac_g  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << nnz_jac_g << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
    // nonzeros in upper hessian

    if( (osinstance->getNumberOfNonlinearExpressions() == 0) && (osinstance->getNumberOfQuadraticTerms() == 0) )
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_warning, "This is a linear program\n");
        nnz_h_lag = 0;
    }
    else
    {
        SparseHessianMatrix *sparseHessian = osinstance->getLagrangianHessianSparsityPattern();
        nnz_h_lag = sparseHessian->hessDimension;
    }
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "nnz_h_lag  !!!!!!!!!!!!!!!!!!!!!!!!!!!" << nnz_h_lag << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
    // use the C style indexing (0-based)
    index_style = TNLP::C_STYLE;

    return true;
}//get_nlp_info


bool  BonminProblem::get_bounds_info(Index n, Number* x_l, Number* x_u,
                                     Index m, Number* g_l, Number* g_u)
{
    std::ostringstream outStr;
    int i;

    double * mdVarLB = osinstance->getVariableLowerBounds();
    // variables upper bounds
    double * mdVarUB = osinstance->getVariableUpperBounds();

    for(i = 0; i < n; i++)
    {
        x_l[ i] = mdVarLB[ i];
        x_u[ i] = mdVarUB[ i];
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "x_l !!!!!!!!!!!!!!!!!!!!!!!!!!!" << x_l[i] << endl;
        outStr << "x_u !!!!!!!!!!!!!!!!!!!!!!!!!!!" << x_u[i] << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
    }
    // Bonmin interprets any number greater than nlp_upper_bound_inf as
    // infinity. The default value of nlp_upper_bound_inf and nlp_lower_bound_inf
    // is 1e19 and can be changed through bonmin options.
    // e.g. g_u[0] = 2e19;

    //constraint lower bounds
    double * mdConLB = osinstance->getConstraintLowerBounds();
    //constraint upper bounds
    double * mdConUB = osinstance->getConstraintUpperBounds();

    for(int i = 0; i < m; i++)
    {
        g_l[ i] = mdConLB[ i];
        g_u[ i] = mdConUB[ i];
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "lower !!!!!!!!!!!!!!!!!!!!!!!!!!!" << g_l[i] << endl;
        outStr << "upper !!!!!!!!!!!!!!!!!!!!!!!!!!!" << g_u[i] << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
    }
    return true;
}//get_bounds_info


// returns the initial point for the problem
bool BonminProblem::get_starting_point(Index n, bool init_x, Number* x,
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, 
            "get initial values !!!!!!!!!!!!!!!!!!!!!!!!!!\n");
#endif

    //now set initial values
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, 
            "get number of initial values !!!!!!!!!!!!!!!!!!!!!!!!!!\n");
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

        double initval;
        try
        {
            for(k = 0; k < m1; k++)
            {
                i = initVarVector[k]->idx;
                if (initVarVector[k]->idx > n1)
                    throw ErrorClass ("Illegal index value in variable initialization");

                initval = initVarVector[k]->value;
                if (osinstance->instanceData->variables->var[i]->ub == OSDBL_MAX)
                {
                    if (osinstance->instanceData->variables->var[i]->lb > initval)
                        throw ErrorClass ("Initial value outside of bounds");
                }
                else if (osinstance->instanceData->variables->var[i]->lb == -OSDBL_MAX)
                {
                    if (osinstance->instanceData->variables->var[i]->ub < initval)
                        throw ErrorClass ("Initial value outside of bounds");
                }
                else
                {
                    if ((osinstance->instanceData->variables->var[i]->lb > initval) ||
                            (osinstance->instanceData->variables->var[i]->ub < initval))
                        throw ErrorClass ("Initial value outside of bounds");
                }

                x[initVarVector[k]->idx] = initval;
                initialed[initVarVector[k]->idx] = true;
            }
        }
        catch(const ErrorClass& eclass)
        {
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_error, 
                "Error in BonminProblem::get_starting_point (OSBonminSolver.cpp)\n\n\n");
        }
    }  //  end if (m1 > 0)

    double default_initval;
    default_initval = 1.7171;


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

    osinstance->calculateAllObjectiveFunctionValues( x, true);
    delete[] initialed;
    return true;
}//get_starting_point


// returns the value of the objective function
bool BonminProblem::eval_f(Index n, const Number* x, bool new_x, Number& obj_value)
{

    try
    {
        if(osinstance->getObjectiveNumber() > 0)
        {
            if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") == 0)
            {
                obj_value  = osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(x), NULL, NULL, new_x, 0 )[ 0];
            }
            else  // we have a max
            {
                obj_value  = -osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(x), NULL, NULL, new_x, 0 )[ 0];
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        bonminErrorMsg = eclass.errormsg;
        throw;
    }
    if( CoinIsnan( (double)obj_value) ) return false;
    return true;
}

bool BonminProblem::eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f)
{
    int i;
    double *objGrad = NULL;
    if(osinstance->getObjectiveNumber() > 0)
    {
        try
        {
            // we assume we are doing the objective function indexed by -1
            objGrad = osinstance->calculateObjectiveFunctionGradient( const_cast<double*>(x), NULL, NULL, -1,  new_x, 1);
        }
        catch(const ErrorClass& eclass)
        {
            bonminErrorMsg = eclass.errormsg;
            throw;
        }

        for(i = 0; i < n; i++)
        {
            if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") == 0)
            {
                grad_f[ i]  = objGrad[ i];
            }
            else
            {
                grad_f[ i]  = -objGrad[ i];
            }
        }
    }
    return true;
}//eval_grad_f

// return the value of the constraints: g(x)
bool BonminProblem::eval_g(Index n, const Number* x, bool new_x, Index m, Number* g)
{
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
        bonminErrorMsg = eclass.errormsg;
        throw;
    }
}//eval_g


// return the structure or values of the jacobian
bool BonminProblem::eval_jac_g(Index n, const Number* x, bool new_x,
                               Index m, Index nele_jac, Index* iRow, Index *jCol,
                               Number* values)
{
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
            bonminErrorMsg =  eclass.errormsg;
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
            bonminErrorMsg = eclass.errormsg;
            throw;
        }
        //osinstance->getIterateResults( (double*)x, 0.0, NULL, -1, new_x,  1);
        for(int i = 0; i < nele_jac; i++)
        {
            values[ i] = sparseJacobian->values[i];
            //values[ i] = osinstance->m_mdJacValue[ i];
        }
    }
    return true;
}//eval_jac_g

//return the structure or values of the hessian
bool BonminProblem::eval_h(Index n, const Number* x, bool new_x,
                           Number obj_factor, Index m, const Number* lambda,
                           bool new_lambda, Index nele_hess, Index* iRow,
                           Index* jCol, Number* values)
{

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
            bonminErrorMsg = eclass.errormsg;
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
            bonminErrorMsg = eclass.errormsg;
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

bool BonminProblem::get_scaling_parameters(Number& obj_scaling,
        bool& use_x_scaling, Index n,
        Number* x_scaling,
        bool& use_g_scaling, Index m,
        Number* g_scaling)
{
    /*
     * Bonmin assumes problems cast as a min
     * if( osinstance->instanceData->objectives->obj[ 0]->maxOrMin.compare("min") != 0){
    	obj_scaling = -1;
    }
    else obj_scaling = 1;
    use_x_scaling = false;
    use_g_scaling = false;
    */
    return true;
}//get_scaling_parameters




void BonminProblem::finalize_solution(TMINLP::SolverReturn status_,
                                      Index n, const Number* x, Number obj_value)
{
    std::ostringstream outStr;

    status = status_;
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "FINALIZE OBJ SOLUTION VALUE = " << obj_value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

}


void BonminSolver::buildSolverInstance() throw (ErrorClass)
{
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
        tminlp = new BonminProblem( osinstance, osoption);
        this->bCallbuildSolverInstance = true;
        //Now initialize from tminlp
        //bonminSetup.initialize( GetRawPtr(tminlp) );
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



void BonminSolver::setSolverOptions() throw (ErrorClass)
{
    std::ostringstream outStr;
    try
    {
        this->bSetSolverOptions = true;
        bonminSetup.initializeOptionsAndJournalist();
        //Register an additional option -- just an example
        bonminSetup.roptions()->AddStringOption2("print_solution","Do we print the solution or not?",
                "yes",
                "no", "No, we don't.",
                "yes", "Yes, we do.",
                "A longer comment can be put here");

        // Here we can change the default value of some Bonmin or Ipopt option
        bonminSetup.options()->SetNumericValue("bonmin.time_limit", 5000); //changes bonmin's time limit
        //bonminSetup.options()->SetIntegerValue("bonmin.num_resolve_at_node", 3);
        //bonminSetup.options()->SetIntegerValue("bonmin.num_resolve_at_root", 3);
        //bonminSetup.options()->SetIntegerValue("bonmin.num_retry_unsolved_random_point", 30);
        //bonminSetup.options()->SetIntegerValue("print_level", 12);
        //bonminSetup.options()->SetIntegerValue("bonmin.bb_log_level", 4);
        //bonminSetup.options()->SetStringValue("bonmin.nlp_failure_behavior", "fathom");
        //bonminSetup.options()->SetNumericValue("bonmin.allowable_gap", -1);
        //bonminSetup.options()->SetNumericValue("bonmin.allowable_fraction_gap", -.1);
        //bonminSetup.options()->SetNumericValue("bonmin.cutoff_decr", -1);
        //bonminSetup.options()->SetStringValue("mu_oracle","loqo");


        //Here we read several option files
        //bonminSetup.readOptionsFile("Mybonmin.opt");
        //bonminSetup.readOptionsFile();// This reads the default file "bonmin.opt"

        // Options can also be set by using a string with a format similar to the bonmin.opt file
        bonminSetup.readOptionsString("bonmin.algorithm B-BB\n");

        //turn off a lot of output -- this can be overridden by using OSOptions
        bonminSetup.options()->SetIntegerValue("bonmin.bb_log_level", 0 );
        bonminSetup.options()->SetIntegerValue("bonmin.nlp_log_level", 0 );

        // Now we can obtain the value of the new option
        int printSolution;
        bonminSetup.options()->GetEnumValue("print_solution", printSolution,"");
        if(printSolution == 1)
        {
            tminlp->printSolutionAtEndOfAlgorithm();
        }
        //
        if(osoption == NULL && osol.length() > 0)
        {
            m_osolreader = new OSoLReader();
            osoption = m_osolreader->readOSoL( osol);
        }

        if(osoption != NULL && osoption->getNumberOfSolverOptions() > 0 )
        {
            char *pEnd;
            int i;
            std::vector<SolverOption*> optionsVector;
            optionsVector = osoption->getSolverOptions( "bonmin",true);
            int num_bonmin_options = optionsVector.size();
            for(i = 0; i < num_bonmin_options; i++)
            {
                if(optionsVector[ i]->type == "numeric" )
                {
                    outStr.str("");
                    outStr.clear();
                    outStr  << "FOUND A  NUMERIC OPTION  "  
                            << os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) 
                            << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
                    if(optionsVector[ i]->category == "ipopt")
                    {
                        bonminSetup.options()->SetNumericValue(optionsVector[ i]->name, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );
                    }
                    else
                    {
                        if(optionsVector[ i]->category == "cbc" )
                        {
                            bonminSetup.options()->SetNumericValue("milp_solver."+optionsVector[ i]->name, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );
                        }
                        else
                        {
                            bonminSetup.options()->SetNumericValue("bonmin."+optionsVector[ i]->name, os_strtod( optionsVector[ i]->value.c_str(), &pEnd ) );
                        }
                    }
                }
                else if(optionsVector[ i]->type == "integer" )
                {
                    outStr.str("");
                    outStr.clear();
                    outStr  << "FOUND AN INTEGER OPTION  " << optionsVector[ i]->name << std::endl;  
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
                    if(optionsVector[ i]->category == "ipopt")
                    {
                        bonminSetup.options()->SetIntegerValue(optionsVector[ i]->name, atoi( optionsVector[ i]->value.c_str() ) );
                    }
                    else
                    {
                        if(optionsVector[ i]->category == "cbc" )
                        {
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, 
                                    "SETTING INTEGER CBC OPTION\n");
                            bonminSetup.options()->SetIntegerValue("milp_solver."+optionsVector[ i]->name, atoi( optionsVector[ i]->value.c_str() ));
                        }
                        else
                        {
                            bonminSetup.options()->SetIntegerValue("bonmin."+optionsVector[ i]->name, atoi( optionsVector[ i]->value.c_str() )  );
                        }
                    }
                }
                else if(optionsVector[ i]->type == "string" )
                {
                    outStr.str("");
                    outStr.clear();
                    outStr << "FOUND A STRING OPTION  " << optionsVector[ i]->name << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
                    if(optionsVector[ i]->category == "ipopt")
                    {
                        bonminSetup.options()->SetStringValue(optionsVector[ i]->name, optionsVector[ i]->value );
                    }
                    else
                    {
                        if(optionsVector[ i]->category == "cbc" )
                        {
                            bonminSetup.options()->SetStringValue("milp_solver."+optionsVector[ i]->name, optionsVector[ i]->value);
                        }
                        else
                        {
                            bonminSetup.options()->SetStringValue("bonmin."+optionsVector[ i]->name, optionsVector[ i]->value);
                        }
                    }
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


//void BonminSolver::solve() throw (ErrorClass) {
void BonminSolver::solve() throw (ErrorClass)
{
    if( this->bCallbuildSolverInstance == false) buildSolverInstance();
    if( this->bSetSolverOptions == false) setSolverOptions();
    try
    {
        try
        {
            bonminSetup.initialize( GetRawPtr(tminlp) );
            // bb is a Bonmin BonCbc object;;
            bb(  bonminSetup);  //process parameter file using Ipopt and do branch and bound using Cbc
        }
        catch(TNLPSolver::UnsolvedError *E)
        {
            //There has been a failure to solve a problem with Ipopt.
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

        if(( bb.model().isContinuousUnbounded() == true) && (osinstance->getNumberOfIntegerVariables() + osinstance->getNumberOfBinaryVariables() <= 0) )
        {
            std::string solutionDescription = "";
            std::string message = "Success";
            int solIdx = 0;

            if(osresult->setServiceName( "Bonmin solver service") != true)
                throw ErrorClass("OSResult error: setServiceName");
            if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
                throw ErrorClass("OSResult error: setInstanceName");
            if(osresult->setVariableNumber( osinstance->getVariableNumber()  ) != true)
                throw ErrorClass("OSResult error: setVariableNumber");
            if(osresult->setObjectiveNumber( 1) != true)
                throw ErrorClass("OSResult error: setObjectiveNumber");
            if(osresult->setConstraintNumber( osinstance->getConstraintNumber()) != true)
                throw ErrorClass("OSResult error: setConstraintNumber");
            if(osresult->setSolutionNumber(  1) != true)
                throw ErrorClass("OSResult error: setSolutionNumer");
            if(osresult->setGeneralMessage( message) != true)
                throw ErrorClass("OSResult error: setGeneralMessage");
            solutionDescription = "The problem is unbounded";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);
            osresult->setGeneralStatusType("normal");
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
            osrl = osrlwriter->writeOSrL( osresult);
            return;
        }


        if(( bb.model().isProvenInfeasible() == true)  )
        {
            std::string solutionDescription = "";
            std::string message = "Success";
            int solIdx = 0;


            if(osresult->setServiceName( "Bonmin solver service") != true)
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
                throw ErrorClass("OSResult error: setSolutionNumber");
            if(osresult->setGeneralMessage( message) != true)
                throw ErrorClass("OSResult error: setGeneralMessage");
            solutionDescription = "The problem is infeasible";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);

            osresult->setGeneralStatusType("normal");
            if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(solIdx, "Warning: this problem has zero decision variables!");
            osrl = osrlwriter->writeOSrL( osresult);
            return;
        }
        status = tminlp->status;
        writeResult();

    }
    catch(const ErrorClass& eclass)
    {
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}//solve


void BonminSolver::writeResult()
{
    double *x = NULL;
    double *z = NULL;
    int i = 0;
    int solIdx = 0;
    std::string solutionDescription = "";
    std::string message = "Bonmin solver finishes to the end.";
    if( osinstance->getVariableNumber() == 0) osresult->setSolutionMessage(0, "Warning: this problem has zero decision variables!");


    try
    {
        if(osinstance->getVariableNumber()  > 0) x = new double[osinstance->getVariableNumber() ];
        z = new double[1];
        // resultHeader information
        if(osresult->setServiceName( OSgetVersionInfo()) != true)
            throw ErrorClass("OSResult error: setServiceName");
        if(osresult->setSolverInvoked( "COIN-OR Bonmin") != true)
            throw ErrorClass("OSResult error: setSolverInvoked");
        if(osresult->setInstanceName(  osinstance->getInstanceName()) != true)
            throw ErrorClass("OSResult error: setInstanceName");
        //if(osresult->setJobID( osoption->jobID) != true)
        //	throw ErrorClass("OSResult error: setJobID");
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
            solutionDescription = "SUCCESS[BONMIN]: Algorithm terminated normally at a locally optimal point, satisfying the convergence tolerances.";
            osresult->setSolutionStatus(solIdx,  "locallyOptimal", solutionDescription);
            /* Retrieve the solution */
            if(osinstance->getObjectiveNumber() > 0)
            {
                *(z + 0)  =  osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(bb.bestSolution()), true)[ 0];
                osresult->setObjectiveValuesDense(solIdx, z);
            }
            if( osinstance->getVariableNumber() > 0)
            {
                for(i=0; i < osinstance->getVariableNumber(); i++)
                {
                    *(x + i) = bb.bestSolution()[i];
                }
                osresult->setPrimalVariableValuesDense(solIdx, x);
            }
            break;

        case TMINLP::LIMIT_EXCEEDED:
            solutionDescription = "LIMIT_EXCEEDED[BONMIN]: A resource limit was exceeded, we provide the current solution.";
            osresult->setSolutionStatus(solIdx,  "other", solutionDescription);
            //osresult->setPrimalVariableValuesDense(solIdx, const_cast<double*>(x));
            //osresult->setDualVariableValuesDense(solIdx, const_cast<double*>( lambda));
            /* Retrieve the solution */
            if(osinstance->getObjectiveNumber() > 0)
            {
                *(z + 0)  =  osinstance->calculateAllObjectiveFunctionValues( const_cast<double*>(bb.bestSolution()), true)[ 0];
                osresult->setObjectiveValuesDense(solIdx, z);
            }
            if( osinstance->getVariableNumber() > 0)
            {
                for(i=0; i < osinstance->getVariableNumber(); i++)
                {
                    *(x + i) = bb.bestSolution()[i];
                }
                osresult->setPrimalVariableValuesDense(solIdx, x);
            }
            break;

        case TMINLP::MINLP_ERROR:
            solutionDescription = "MINLP_ERROR [BONMIN]: Algorithm stopped with unspecified error.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);

            break;

        case TMINLP::CONTINUOUS_UNBOUNDED:
            solutionDescription = "CONTINUOUS_UNBOUNDED [BONMIN]: The continuous relaxation is unbounded, the MINLP may or may not be unbounded.";
            osresult->setSolutionStatus(solIdx,  "error", solutionDescription);

            break;


        case TMINLP::INFEASIBLE:
            solutionDescription = "INFEASIBLE [BONMIN]: Problem may be infeasible.";
            osresult->setSolutionStatus(solIdx,  "infeasible", solutionDescription);
            break;


        default:
            solutionDescription = "OTHER[BONMIN]: other unknown solution status from Bonmin solver";
            osresult->setSolutionStatus(solIdx,  "other", solutionDescription);
        }//switch end
        osresult->setGeneralStatusType("normal");
        osrl = osrlwriter->writeOSrL( osresult);
        if(osinstance->getVariableNumber() > 0 ) delete[] x;
        x = NULL;
        delete[] z;
        z = NULL;
    }//end try


    catch(const ErrorClass& eclass)
    {
        if(osinstance->getVariableNumber()  > 0) delete[] x;
        x = NULL;
        delete[] z;
        z = NULL;
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        throw ErrorClass( osrl) ;
    }
}// end writeResult()


void BonminSolver::dataEchoCheck()
{
    std::ostringstream outStr;

    int i;

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

    // print out quadratic data
    outStr << "number of qterms =  " <<  osinstance->getNumberOfQuadraticTerms() << endl;
    for(int i = 0; i <  osinstance->getNumberOfQuadraticTerms(); i++)
    {
        outStr << "Row Index = " <<  osinstance->getQuadraticTerms()->rowIndexes[i] << endl;
        outStr << "Var Index 1 = " << osinstance->getQuadraticTerms()->varOneIndexes[ i] << endl;
        outStr << "Var Index 2 = " << osinstance->getQuadraticTerms()->varTwoIndexes[ i] << endl;
        outStr << "Coefficient = " << osinstance->getQuadraticTerms()->coefficients[ i] << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSSolverInterfaces, ENUM_OUTPUT_LEVEL_info, outStr.str());
    }
} // end dataEchoCheck


BonminProblem::BonminProblem(OSInstance *osinstance_,  OSOption *osoption_)
{
    osinstance = osinstance_;
    osoption = osoption_;
    printSol_ = false;
}

BonminProblem::~BonminProblem()
{

}



