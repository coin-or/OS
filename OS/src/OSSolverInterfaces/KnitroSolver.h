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

#ifndef KNITRO_H__
#include  "knitro.h"
#endif
#ifndef NLPPROBLEMDEF_H__
#include  "nlpProblemDef.h"
#endif

#include "OSConfig.h" 
#include "DefaultSolver.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSParameters.h"
#include "OSnLNode.h"
#include "OSiLReader.h"
#include "OSInstance.h"
#include "OSExpressionTree.h"
#include "OSnLNode.h"
#include "OSDataStructures.h"
#include "FileUtil.h"  
#include "ErrorClass.h"

# include <cstddef>
# include <cstdlib>
# include <cctype>
# include <cassert>
# include <stack>
#include <string>
# include <cppad/cppad.hpp>
#include<iostream>
#include <time.h>   
#include<math.h>
#include<vector>
#include <map>  



class KnitroSolver : public DefaultSolver, public NlpProblemDef {  
	
public:

	KnitroSolver();
	
	~KnitroSolver();
	
	//virtual void  solve() throw(ErrorClass);
	virtual void  solve() throw (ErrorClass) ;
	void dataEchoCheck(); 
	
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
	//  KnitroSolver();
	KnitroSolver(const KnitroSolver&);
	KnitroSolver& operator=(const KnitroSolver&);
	//@}
	std::string knitroErrorMsg;

};
#endif
