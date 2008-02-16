/** @file KnitroSolver.h
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 05/01/2007
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 
 
#ifndef KNITROSOLVER_H 
#define KNITROSOLVER_H

#include "OSConfig.h" 



#ifndef NLPPROBLEMDEF_H__
#include  "nlpProblemDef.h"
#endif

#include "OSConfig.h" 
#include "OSDefaultSolver.h"
#include "OSrLWriter.h"
#include "OSiLWriter.h"
#include "OSInstance.h"
#include "OSParameters.h"
#include "OSnLNode.h"
#include "OSiLReader.h"
#include "OSInstance.h"
#include "OSExpressionTree.h"
#include "OSnLNode.h"
#include "OSDataStructures.h"
#include "OSFileUtil.h"  
#include "OSErrorClass.h"

#ifndef KNITRO_H__
#include  "knitro.h"
#endif

# include <cstddef>
# include <cstdlib>
# include <cctype>
# include <cassert>
# include <stack>
#include <string>
# include <cppad/cppad.hpp>
#include<iostream>




#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif

 
#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
# else
#  error "don't have header file for math"
# endif
#endif



#include<vector>
#include <map>  



class KnitroProblem : public NlpProblemDef {
public:
	
	/** the IpoptProblemclass constructor */
	KnitroProblem(OSInstance *osinstance_ , OSResult *osresult_);
	
	/** the IpoptProblem class destructor */
	virtual ~KnitroProblem();
	
	OSResult *osresult;
	
	OSInstance *osinstance;
	
	//Knitro specific methods
	//++ Declare virtual base class methods that are implemented here.
    //++ See NlpProblemDef.h for descriptions.
    int   getN (void);
    int   getM (void);
    void  getInitialX (double * const  daX);
    bool  loadProblemIntoKnitro (KTR_context_ptr  kc);
    bool  areDerivativesImplemented
              (const DerivativesImplementedType  nWhichDers);

    int  evalFC (const double * const  daX,
                       double * const  dObj,
                       double * const  daC,
                       void   *        userParams);
    int  evalGA (const double * const  daX,
                       double * const  daG,
                       double * const  daJ,
                       void   *        userParams);
    int  evalH (const double * const  daX,
                const double * const  daLambda,
                      double * const  daH,
                      void   *        userParams);
    int  evalHV (const double * const  daX,
                 const double * const  daLambda,
                       double * const  daHV,
                       void   *        userParams);

	std::string knitroErrorMsg;
};


/*! \class KnitroSolver
 *  \brief the KnitroSolver class solves problems using Knitro.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * 
 * 
 *
 * 
 * \remarks
 * this class takes an OSiL instance and optimizes it using
 * the Knitro solver
 * 
 */
class KnitroSolver : public DefaultSolver {  
	
	
public:
	
	/** the KnitroSolver class constructor */
	KnitroSolver();

	/** the KnitroSolver class constructor */
	~KnitroSolver();
	
	/** solve results in an instance being read into the Knitro
	 * data structrues and optimized */ 
	virtual void  solve() throw (ErrorClass) ;
	
   	/**
   	 * use this for debugging, print out the instance that
   	 * the solver thinks it has and compare this with the OSiL
   	 * file
   	 */		
	void dataEchoCheck(); 
	


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
	//  KnitroSolver();
	KnitroSolver(const KnitroSolver&);
	KnitroSolver& operator=(const KnitroSolver&);
	//@}
	std::string knitroErrorMsg;

};


#endif
