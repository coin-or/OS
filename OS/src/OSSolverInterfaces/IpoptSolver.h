/** @file IpoptSolver.h
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
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
 
#ifndef IPOPTSOLVER_H 
#define IPOPTSOLVER_H

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

#ifdef COIN_HAS_ASL
#include "IpTNLP.hpp"
#else
#include "IpTNLP.hpp"
#undef COIN_HAS_ASL
#endif


using namespace Ipopt;

class IpoptSolver : public DefaultSolver, public TNLP{  
	
public:

	IpoptSolver();
	~IpoptSolver();
	//virtual void  solve() throw(ErrorClass);
	virtual void  solve() throw (ErrorClass) ;
	void dataEchoCheck();

	/** IPOpt specific methods for defining the nlp problem */
	virtual bool get_nlp_info(Index& n, Index& m, Index& nnz_jac_g,
                            Index& nnz_h_lag, IndexStyleEnum& index_style);

	/** Method to return the bounds for my problem */
	virtual bool get_bounds_info(Index n, Number* x_l, Number* x_u,
								Index m, Number* g_l, Number* g_u);

	/** Method to return the starting point for the algorithm */
	virtual bool get_starting_point(Index n, bool init_x, Number* x,
									bool init_z, Number* z_L, Number* z_U,
									Index m, bool init_lambda,
									Number* lambda);

	/** Method to return the objective value */
	virtual bool eval_f(Index n, const Number* x, bool new_x, Number& obj_value);

	/** Method to return the gradient of the objective */
	virtual bool eval_grad_f(Index n, const Number* x, bool new_x, Number* grad_f);

	/** Method to return the constraint residuals */
	virtual bool eval_g(Index n, const Number* x, bool new_x, Index m, Number* g);

	/** Method to return:
	*   1) The structure of the jacobian (if "values" is NULL)
	*   2) The values of the jacobian (if "values" is not NULL)
	*/
	virtual bool eval_jac_g(Index n, const Number* x, bool new_x,
							Index m, Index nele_jac, Index* iRow, Index *jCol,
							Number* values);

	/** Method to return:
	*   1) The structure of the hessian of the lagrangian (if "values" is NULL)
	*   2) The values of the hessian of the lagrangian (if "values" is not NULL)
	*/
	virtual bool eval_h(Index n, const Number* x, bool new_x,
						Number obj_factor, Index m, const Number* lambda,
						bool new_lambda, Index nele_hess, Index* iRow,
						Index* jCol, Number* values);

	//@}
	
	
	virtual bool get_scaling_parameters(Number& obj_scaling,
                                    bool& use_x_scaling, Index n,
                                    Number* x_scaling,
                                    bool& use_g_scaling, Index m,
                                    Number* g_scaling);

	/** @name Solution Methods */
	//@{
	/** This method is called when the algorithm is complete so the TNLP can store/write the solution */
	virtual void finalize_solution(SolverReturn status,
									Index n, const Number* x, const Number* z_L, const Number* z_U,
									Index m, const Number* g, const Number* lambda,
									Number obj_value,
                                   const IpoptData* ip_data,
                                   IpoptCalculatedQuantities* ip_cq);
	//@}

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
	//  IpoptSolver();
	IpoptSolver(const IpoptSolver&);
	IpoptSolver& operator=(const IpoptSolver&);
	//@}
	std::string ipoptErrorMsg;
};

#endif /*IPOPTSOLVER_H*/
