/* $Id$ */
/** @file OSParameters.h
 * 
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
 
// CoinFinite includes <cmath> (I think) which causes a problem 
//#include<CoinFinite.hpp>

//kipp fix up the infinity issue
//kipp define OSINFINITY to COIN_DBL_MAX



#ifndef OSPARAMETERS
#define OSPARAMETERS

#include "OSConfig.h"


#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
# else
#  error "don't have header file for math"
# endif
#endif
#ifdef HAVE_CFLOAT
# include <cfloat>
#else
# ifdef HAVE_FLOAT_H
#  include <float.h>
# endif
#endif
#ifdef HAVE_CIEEEFP
# include <cieeefp>
#else
# ifdef HAVE_IEEEFP_H
#  include <ieeefp.h>
# endif
#endif

#ifdef HAVE_CSTRING
# include <cstring>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  error "don't have header file for string"
# endif
#endif


#ifdef HAVE_CSTDLIB
# include <cstdlib>
#else
# ifdef HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif

#define OS_PLUS 1001
#define	OS_SUM  1002
#define	OS_MINUS  1003
#define	OS_NEGATE  1004
#define	OS_TIMES  1005
#define	OS_DIVIDE  1006
#define	OS_POWER  1009
#define	OS_PRODUCT  1010
#define	OS_ABS  2001
#define	OS_SQUARE  2005
#define	OS_SQRT  2006
#define	OS_LN  2007
#define	OS_EXP  2010
#define	OS_SIN  3001
#define	OS_COS  3002
#define	OS_MIN  4010
#define	OS_MAX  4011
#define	OS_ERF  4625
#define	OS_NUMBER  5001
#define	OS_PI  5003
#define	OS_E  5004
#define	OS_VARIABLE  6001
#define	OS_IF  7001
#define	OS_ALLDIF  7016



//#include <limits.h>
//#ifdef INFINITY //This is the definition in the ISO C99 standard.
//	#define OSINFINITY INFINITY
//#else
//	#define OSINFINITY 1e20
//#endif

//#define OSINFINITY 1e30

#define OS_E_VALUE exp(1.0)
#define OS_PI_VALUE 2*asin(1.0)

#define OS_SCHEMA_VERSION "2.0"
#define OS_RELEASE_MESSAGE "Optimization Services Release 2.1.0"

/**
 * we use OS_NEAR_EQUAL in unitTest to see if we 
 * are close to the optimal obj value
 */
#define OS_NEAR_EQUAL 1e-2

#define OS_EPS 1e-12

inline double nanKludge(){
	double zero = 0.0;
	return 0.0/zero;
}

#ifdef NAN 
#define OSNAN NAN
#elif defined NaN
#define OSNAN NaN
#elif defined nan
#define OSNAN nan
#elif defined (_MSC_VER)
#include <ymath.h>
#define OSNAN _Nan._Double
#else
#define OSNAN nanKludge() // wow, what a last resort, I don't like this!
#endif





#ifdef DBL_MAX
	#define OSDBL_MAX DBL_MAX
#elif defined HUGE_VAL
	//#define OSDBL_MAX OSINFINITY
	#define OSDBL_MAX HUGE_VAL
#else
	#define OSDBL_MAX 1e30
#endif


#ifdef INT_MAX
#define OSINT_MAX INT_MAX
#else
#define OSINT_MAX 2147483647
#endif

#ifndef XSLT_LOCATION
#define XSLT_LOCATION  OSSRCDIR;
#endif

#endif




