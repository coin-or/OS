/* $Id$ */
/** @file OSParameters.h
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
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
#define	OS_ERF  2023
#define	OS_SIN  3001
#define	OS_COS  3002
#define	OS_MIN  4010
#define	OS_MAX  4011
#define	OS_NUMBER  5001
#define	OS_PI  5003
#define	OS_E  5004
#define	OS_VARIABLE  6001
#define	OS_IF  7001
#define	OS_ALLDIFF  7016

#define	OS_MATRIX_DETERMINANT  8001
#define	OS_MATRIX_TRACE  8002
#define	OS_MATRIX_PLUS	8501
#define	OS_MATRIX_SUM	8502
#define	OS_MATRIX_MINUS	8503
#define	OS_MATRIX_NEGATE	8504
#define	OS_MATRIX_TIMES	8505
#define	OS_MATRIX_INVERSE	8510
#define	OS_MATRIX_TRANSPOSE	8515
#define	OS_MATRIX_SCALARTIMES	8518
#define	OS_MATRIX_DOTTIMES	8520
#define	OS_MATRIX_IDENTITY	8536
#define	OS_MATRIX_LOWERTRIANGLE	8537
#define	OS_MATRIX_UPPERTRIANGLE	8538
#define	OS_MATRIX_DIAGONAL	8539
#define	OS_VECTOR_TO_DIAGONAL_MATRIX	8540
#define	OS_MATRIX_REFERENCE  8541



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
extern "C" bool OSIsnan(double x);
/** returns the value for NaN used in OS */
extern "C" double OSNaN();

std::string OSgetVersionInfo();

#endif
