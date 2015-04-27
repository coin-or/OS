/* $Id: OSCsdpSolver.h 4562 2013-01-02 12:31:12Z Gassmann $ */
/** @file OSCsdpSolver.h
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#ifndef CSDPSOLVER_H
#define CSDPSOLVER_H

#include "OSConfig.h"
#include "OSDefaultSolver.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSParameters.h"
#include "OSnLNode.h"
#include "OSiLReader.h"
#include "OSoLReader.h"
#include "OSInstance.h"
#include "OSExpressionTree.h"
#include "OSnLNode.h"
#include "OSGeneral.h"
#include "OSFileUtil.h"
#include "OSErrorClass.h"

#include "OSResult.h"
#include "OSInstance.h"
#include "OSOption.h"

/*
 * Include CSDP declarations so that we'll know the calling interfaces.
 */

extern "C"
{
#include "declarations.h"
}


#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <map>


/*! \class CsdpSolver
 *  \brief The CsdpSolver class solves problems using Csdp.
 *
 * @author Jun Ma, Kipp Martin, Horand Gassmann
 * @version 1.0, 05/26/2014
 * @since OS 2.8
 *
 * \remarks
 * this class takes an OSiL instance and optimizes it using
 * the COIN-OR Csdp solver
 *
 */

class CsdpSolver : public DefaultSolver
{
// These declarations are taken from the main method csdp.c
  int nC_rows;                            // number of rows/columns in each matrix
  int nC_blks;                            // number of blocks per matrix
  struct blockmatrix *C_matrix;           // the matrix in the objective, A0
  double *rhsValues;                      // the right-hand side values of the constraints
  struct constraintmatrix **mconstraints; // the collection of matrices in the constraints (A_i)
  struct blockmatrix *X,*Z;               // for the primal and dual matrix values, respectively
  double *y;                              // dual variables of the constraints
  double pobj,dobj;                       // primal and dual objective values

public:

    /** the CsdpSolver class constructor */
    CsdpSolver();

    /** the CsdpSolver class destructor */
    virtual ~CsdpSolver();

    /** solve results in an instance being read into the Csdp
     * data structures and optimize */
    virtual void  solve() throw (ErrorClass) ;

    /*! \fn void buildSolverInstance()
     *  \brief The implementation of the virtual functions.
     *  \return void.
     */
    virtual void  buildSolverInstance() throw(ErrorClass);

    /*! \fn void setSolverOptions()
     *  \brief The implementation of the virtual functions.
     *  \return void.
     */
    virtual void  setSolverOptions() throw(ErrorClass);

    /*! \fn  verifyForm()
     *  \brief Use to verify that the solver is appropriate. 
     *         CSDP requires a very special type of problem 
     *  \return void.
     */
    //void verifyForm() throw(ErrorClass);

    /**
     * use this for debugging, print out the instance that
     * the solver thinks it has and compare this with the OSiL
     * file
     */
    void dataEchoCheck();

    /**
     * m_osilreader is an OSiLReader object used to create an osinstance from an
     * osil string if needed
     */
    OSiLReader *m_osilreader;

    /**
     * m_osolreader is an OSoLReader object used to create an osoption from an
     * osol string if needed
     */
    OSoLReader *m_osolreader;


private:
    OSrLWriter  *osrlwriter;

    /**@name Methods to block default compiler methods.
    * The compiler automatically generates the following three methods.
    *  Since the default compiler implementation is generally not what
    *  you want (for all but the most simple classes), we usually
    *  put the declarations of these methods in the private section
    *  and never implement them. This prevents the compiler from
    *  implementing an incorrect "default" behavior without us
    *  knowing. (See Scott Meyers book, "Effective C++")
    *
    */
    //@{
    //  CsdpSolver();
    //CsdpSolver(const CsdpSolver&);
    //CsdpSolver& operator=(const CsdpSolver&);
    //@}
    //std::string csdpErrorMsg;
    std::string *csdpErrorMsg;
};


#endif /*CSDPSOLVER_H*/
