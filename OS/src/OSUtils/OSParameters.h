/* $Id$ */
/** @file OSParameters.h
 * 
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 *
 * \remarks
 * Copyright (C) 2005, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 
 
//kipp fix up the infinity issue
//kipp define OSINFINITY to COIN_DBL_MAX

#ifndef OSPARAMETERS
#define OSPARAMETERS

#include "OSConfig.h"

#include <string>
#include <limits>

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

#define OS_E_VALUE exp(1.0)
#define OS_PI_VALUE 2*asin(1.0)

#define OS_SCHEMA_VERSION "2.0"

/**
 * we use OS_NEAR_EQUAL in unitTest to see if we 
 * are close to the optimal obj value
 */
#define OS_NEAR_EQUAL 1e-2

#define OS_EPS 1e-12

const double OSDBL_MAX = std::numeric_limits<double>::max();
const int    OSINT_MAX = std::numeric_limits<int>::max();

/** checks whether a given double is NaN */
bool OSIsnan(double x);
/** returns the value for NaN used in OS */
double OSNaN();

std::string OSgetVersionInfo();

#endif
