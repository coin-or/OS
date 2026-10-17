/* $Id: OSParameters.cpp 4234 2011-07-29 12:45:13Z Gassmann $ */
/** @file OSParameters.cpp
 *
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#include "OSConfig.h"
#include "OSParameters.h"

#include <cstdlib>

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

#include <sstream>

using std::ostringstream;

// this is taken directly from COINUTILS
bool OSIsnan(double x)
{
#ifdef COIN_C_ISNAN
    return COIN_C_ISNAN( x)!=0;
#else
    return (x != x);
#endif
}

double OSNaN()
{
#ifdef OSNAN
    return OSNAN;
#else
    // wow, what a last resort, I don't like this!
    double zero = 0.0;
    return 0.0/zero;
#endif
}

std::string OSgetVersionInfo()
{
    ostringstream versionInfo;
    versionInfo << std::endl << std::endl;
    versionInfo << "Optimization Services Solver";
    versionInfo << std::endl;
    versionInfo << "Main Authors: Horand Gassmann, Jun Ma, and Kipp Martin";
    versionInfo << std::endl;
    versionInfo << "Distributed under the Eclipse Public License" ;
    versionInfo << std::endl;

//  OS_VERSION is not an environment variable, so to inspect it requires a bit of care
    ostringstream temp_version;
    temp_version << OS_VERSION;

    versionInfo << "OS Version:  ";
    if (temp_version.str() == "trunk")
    {
        versionInfo << "trunk";
#ifdef OS_SVN_REV
        versionInfo << std::endl;
        versionInfo << "SVN Version: ";
        versionInfo << OS_SVN_REV;
#endif
    }
    else
        versionInfo << OS_VERSION;
    versionInfo << std::endl;

    versionInfo << "Build Date: ";
    versionInfo << __DATE__;

    versionInfo << std::endl << std::endl;
    return versionInfo.str() ;
}
