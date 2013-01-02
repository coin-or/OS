/* $Id$ */
/** @file LindoSolver.h
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#ifndef LINDOSOLVER_H
#define LINDOSOLVER_H

#include "OSDefaultSolver.h"
#include "OSInstance.h"
#include "lindo.h"
#include "OSrLWriter.h"
#include "OSiLWriter.h"
#include "OSiLReader.h"
#include "OSConfig.h"
#include <string>

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif

/*! \class LindoSolver
 *  \brief the LindoSolver class solves problems using Lindo.
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 *
 * \remarks
 * this class takes an OSiL instance and optimizes it using
 * the Lindo API
 *
 */
class LindoSolver : public DefaultSolver
{

public:

    /** the LindoSolver class constructor */
    LindoSolver();

    /** the LindoSolver class destructor */
    ~LindoSolver();

    /** solve results in an instance being read into the Lindo
     * data structures and optimized */
    virtual void  solve() ;

    /*! \fn void CoinSolver::buildSolverInstance()
     *  \brief The implementation of the virtual functions.
     *  \return void.
     */
    virtual void  buildSolverInstance() throw(ErrorClass);

    /*! \fn void setSolverOptions()
     *  \brief The implementation of the virtual functions.
     *  \return void.
     */
    virtual void  setSolverOptions() throw(ErrorClass);

    // Lindo specific methods

    /**
     * invoke the Lindo API solver
     * @return true if an exception is not thrown.
     */
    bool optimize();

    /**
     * read the OSiL instance variables and put these
     * into the LINDO API variables
     * @return true if an exception is not thrown.
     */
    bool processVariables();

    /**
     * read the OSiL instance constraints and put these
     * into the LINDO API constraints
     * @return true if an exception is not thrown.
     */
    bool processConstraints();

    /**
     * create the LINDO environment and read the problem into
     * the internal LINDO data structures
     * @return true if an exception is not thrown.
     */
    bool generateLindoModel();

    /**
     * LINDO does not handle constraints with upper and lower bounds
     * this method is part of kludge where we add a new variable
     * to handle the bounds
     * @return true if an exception is not thrown.
     */
    bool addSlackVars();

    /**
     * read the quadratic terms in the model
     * @return true if an exception is not thrown.
     */
    bool processQuadraticTerms();

    /**
     * read the nonlinear terms in the model
     * @return true if an exception is not thrown.
     */
    bool processNonlinearExpressions();

    /**
     * m_osilreader is an OSiLReader object used to create an osinstance from an
     * osil string if needed
     */
    OSiLReader *m_osilreader;

    /**
     * use this for debugging, print out the instance that
     * the solver thinks it has and compare this with the OSiL
     * file
     */
    void dataEchoCheck();



private:

    /** declare an instance of the LINDO environment object */
    pLSenv pEnv_;

    /** declare an instance of the LINDO model object */
    pLSmodel pModel_;

    /** m_iErrorCode is a variable for LINDO error codes */
    int m_iLindoErrorCode;

    /** because LINDO API does not take row ranges we need some extra stuff
    * m_miSlackIdx indexes the rows that get additional slack variable*/
    int *m_miSlackIdx;

    /** m_iNumberNewSlacks is the number of slack variables to add */
    int m_iNumberNewSlacks;

    /** m_mdRhsValue is used to the store the constraint rhs if
     * we do not use row upper and lower bounds
     */
    double *m_mdRhsValue;

    /** m_mcRowType  - E for equality, L for less than, G for greater than --
     * used if we do not store rows using upper and lower bounds
     */
    char *m_mcRowType;

    /**
     * m_mdLb holds an array of variable lower bounds.
     */
    double* m_mdVarLB;

    /**
     * m_mdUb holds an array of variable upper bounds.
     */
    double* m_mdVarUB;

    /**
     * m_mdLhs holds an array of the constraint lower bounds.
     */
    double* m_mdConLB;

    /**
     * m_mdRhs holds an array of the constraint upper bounds.
     */
    double* m_mdConUB;

    /**
     * m_mmcVarName holds an array of char arrays.
     */
    char** m_mmcVarName;

    /**
     * m_msVarName holds an array of variable std::string names.
     */
    std::string* m_msVarName;

    /**
     * m_msConName holds an array of constraint std::string names.
     */
    std::string* m_msConName;

    /**
     * m_vcVarType holds an array of variable types (character), e.g. 'C' for continuous
     * type, 'I' for integer type, 'B' for binary type, 'S' for std::string type).
     */
    char* m_mcVarType;
    /**
     * m_mdObjConstant holds an array of objective function constants.
     */
    double m_mdObjConstant; // change to array later

    /** osrlwriter object used to write osrl from an OSResult object */
    OSrLWriter  *osrlwriter;

    double cpuTime;

protected:
    /**
     * Lindo's generalized error Reporting function
     *
     */
    void lindoAPIErrorCheck( std::string errormsg);

};



#endif
