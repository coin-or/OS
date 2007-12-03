# Copyright (C) 2006 International Business Machines.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: configure.ac 786 2006-06-01 04:10:46Z andreasw $

# Author:  Andreas Waechter            IBM    2006-04-13

#############################################################################
#                       Names and other basic things                        #
#############################################################################

AC_PREREQ(2.59)

AC_INIT([OS],[0.1],[coin-os@list.coin-or.org])

AC_COPYRIGHT([
Copyright 2006 International Business Machines and others.
All Rights Reserved.
This file is part of the open source package Coin which is distributed
under the Common Public License.])

# List one file in the package so that the configure script can test
# whether the package is actually there
AC_CONFIG_SRCDIR(src/OSUtils/ErrorClass.cpp)

# Where should everything be installed by default?  Here, we want it
# to be installed directly in 'bin', 'lib', 'include' subdirectories
# of the directory where configure is run.  The default would be
# /usr/local.
AC_PREFIX_DEFAULT([`pwd`])

#############################################################################
#                         Standard build tool stuff                         #
#############################################################################

# Get the system type
AC_CANONICAL_BUILD

# Initialise ADDLIBS and FADDLIBS
AC_COIN_PROJECTDIR_INIT

LIBS_without_ADDLIBS="$LIBS"

# Check if user wants to produce debugging code
AC_COIN_DEBUG_COMPILE(OS)

# Get the name of the C++ compiler and appropriate compiler options
coin_opt_cxxflags="-O3"
AC_COIN_PROG_CXX

# Check if we have a Fortran compiler; if we do, acquire the appropriate
# options. This has to be done before we call AC_COIN_INIT_AUTO_TOOLS, else
# it will helpfully set FFLAGS to an incorrect value.
AC_COIN_FIND_F77
if test "$F77" != unavailable ; then
  AC_COIN_PROG_F77
  AC_COIN_F77_WRAPPERS
fi

# Initialize automake and libtool
AC_COIN_INIT_AUTO_TOOLS

#############################################################################
#                              COIN components                              #
#############################################################################

AC_COIN_HAS_PROJECT(OS)
AC_COIN_HAS_PROJECT(CoinUtils)
AC_COIN_HAS_PROJECT(Osi)
AC_COIN_HAS_PROJECT(Clp)
AC_COIN_HAS_PROJECT(Cbc)
AC_COIN_HAS_PROJECT(Cgl)
AC_COIN_HAS_PROJECT(SYMPHONY)
AC_COIN_HAS_PROJECT(DyLP)
AC_COIN_HAS_PROJECT(Vol)
AC_COIN_HAS_PROJECT(Ipopt)
AC_COIN_HAS_PROJECT(cppad)



  
  case $coin_has_cppad in
     unavailable|skipping)
         AC_MSG_ERROR([cannot find CppAD which is necessary to build OS]) ;;
  esac

if test $coin_has_coinutils != unavailable &&
   test $coin_has_coinutils != skipping; then
  case $CXX in
    cl*)
       coinutilslib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libCoinUtils.lib';;
     *)
       coinutilslib="-L\$(INSTALLIBDIR) -lCoinUtils";;
  esac
  AC_SUBST(coinutilslib) 
  else
    AC_MSG_ERROR([cannot find CoinTuils which is necessary to build OS])   
fi

if test $coin_has_clp != unavailable &&
   test $coin_has_clp != skipping; then
  case $CXX in
    cl*)
       clplib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libClp.lib'
       osiclplib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libOsiClp.lib';;
     *)
       clplib="-L\$(INSTALLIBDIR) -lClp"
       osiclplib="-L\$(INSTALLIBDIR) -lOsiClp";;
  esac
  AC_SUBST(clplib)
  AC_SUBST(osiclplib) 
  else
    AC_MSG_ERROR([cannot find Clp which is necessary to build OS])   
fi

if test $coin_has_cbc != unavailable &&
   test $coin_has_cbc != skipping; then
  case $CXX in
    cl*)
       cbclib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libCbc.lib'
       osicbclib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libOsiCbc.lib';;
     *)
       cbclib="-L\$(INSTALLIBDIR) -lCbc"
       osicbclib="-L\$(INSTALLIBDIR) -lOsiCbc";;
  esac
  AC_SUBST(cbclib) 
  AC_SUBST(osicbclib)
  else
    AC_MSG_ERROR([cannot find Cbc which is necessary to build OS])   
fi 


if test $coin_has_cgl != unavailable &&
   test $coin_has_cgl != skipping; then
  case $CXX in
    cl*)
       cgllib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libCgl.lib';;
     *)
       cgllib="-L\$(INSTALLIBDIR) -lCgl";;
  esac
  AC_SUBST(cgllib) 
  else
    AC_MSG_ERROR([cannot find Cgl which is necessary to build OS])   
fi


if test $coin_has_osi != unavailable &&
   test $coin_has_osi != skipping; then
  case $CXX in
    cl*)
       osilib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libOsi.lib';;
     *)
       osilib="-L\$(INSTALLIBDIR) -lOsi";;
  esac
  AC_SUBST(osilib) 
  else
    AC_MSG_ERROR([cannot find Osi which is necessary to build OS])   
fi


if test $coin_has_dylp != unavailable &&
   test $coin_has_dylp != skipping; then
  case $CXX in
    cl*)
       dylplib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libDylp.lib'
       osidylplib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libOsiDylp.lib';;
     *)
       dylplib="-L\$(INSTALLIBDIR) -lDylp"
       osidylplib="-L\$(INSTALLIBDIR) -lOsiDylp";;
  esac
  AC_SUBST(dylplib) 
  AC_SUBST(osidylplib) 
fi


if test $coin_has_vol != unavailable &&
   test $coin_has_vol != skipping; then
  case $CXX in
    cl*)
       vollib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libVol.lib'
       osivollib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libVol.lib';;
     *)
       vollib="-L\$(INSTALLIBDIR) -lVol"
       osivollib="-L\$(INSTALLIBDIR) -lOsiVol";;
  esac
  AC_SUBST(vollib)
  AC_SUBST(osivollib)  
fi


if test $coin_has_symphony != unavailable &&
   test $coin_has_symphony != skipping; then
  case $CXX in
    cl*)
       symphonylib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libSym.lib'
       osisymphonylib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libOsiSym.lib';;
     *)
       symphonylib="-L\$(INSTALLIBDIR) -lSym"
       osisymphonylib="-L\$(INSTALLIBDIR) -lOsiSym";;
  esac
  AC_SUBST(symphonylib) 
  AC_SUBST(osisymphonylib)  
fi

if test $coin_has_ipopt != unavailable &&
   test $coin_has_ipopt != skipping; then
  case $CXX in
    cl*)
       ipoptlib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libipopt.lib';;
     *)
       ipoptlib="-L\$(INSTALLIBDIR) -lipopt";;
  esac
  AC_SUBST(ipoptlib)  
fi

#############################################################################
#                             Third party solvers                           #
#############################################################################

AC_COIN_HAS_USER_LIBRARY([Cplex],[CPX],[cplex.h],[])
AC_COIN_HAS_USER_LIBRARY([Lindo],[LINDO],[lindo.h],[])
#AC_COIN_HAS_USER_LIBRARY([Ipopt],[IPOPT],[IpoptConfig.h],[])
AC_COIN_HAS_USER_LIBRARY([Knitro],[KNITRO],[knitro.h],[])

AC_COIN_HAS_GLPK(Glpk)
AC_COIN_HAS_ASL

#############################################################################
#                         OS-specific configuration                         #
#############################################################################

  case $build in
     *-mingw*)
         AC_DEFINE([WIN_],[1],[use if OS is Windows]) ;;
      *-cygwin*)
         AC_DEFINE([WIN_],[1],[use if OS is Windows])
         AC_DEFINE([NOMINMAX],[1],[use if OS is Cygwin]) ;;
       *-win*)
         AC_DEFINE([WIN_],[1],[use if OS is Windows]) ;;
    *-linux-*)
	 ;;
    *-darwin*)
        AC_DEFINE([MACOSX_],[1],[use if OS is MACOSX])
        mac_osx=yes ;;
    *-ibm-*)
         ;;
    *-hp-*)
         ;;
    *-sun-*)
	 ;;
    *)
	 ;;
  esac

############################################################################
############################################################################
#                   Stuff that we need for C++ programs                    #
############################################################################
############################################################################

AC_LANG_PUSH(C++)

################
# Header Files #
################


AC_COIN_CHECK_CXX_CHEADER(math)
AC_COIN_CHECK_CXX_CHEADER(ctype)
AC_COIN_CHECK_CXX_CHEADER(assert)
AC_COIN_CHECK_CXX_CHEADER(stdio)
AC_COIN_CHECK_CXX_CHEADER(stdlib)
AC_COIN_CHECK_CXX_CHEADER(stdarg)
AC_COIN_CHECK_CXX_CHEADER(string)
AC_COIN_CHECK_CXX_CHEADER(float)
AC_COIN_CHECK_CXX_CHEADER(time)
AC_COIN_CHECK_CXX_CHEADER(ieeefp)




###################
# Function isnan #  -- this is copied directly from CoinUtils
###################
MY_C_ISNAN=
AC_CHECK_DECL([isnan],[MY_C_ISNAN=isnan],,[
#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
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
#endif])

# It appears that for some systems (e.g., Mac OSX), cmath will provide only
# std::isnan, and bare isnan will be unavailable. Typically we need a parameter
# in the test to allow C++ to do overload resolution.

if test -z "$MY_C_ISNAN"; then
  AC_CHECK_DECL([std::isnan(42.42)],[MY_C_ISNAN=std::isnan],,[
#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
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
#endif])
fi

if test -z "$MY_C_ISNAN"; then
  AC_CHECK_DECL([_isnan],[MY_C_ISNAN=_isnan],,[
#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
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
#endif])
fi
if test -z "$MY_C_ISNAN"; then
  AC_CHECK_DECL([isnand],[MY_C_ISNAN=isnand],,[
#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
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
#endif])
fi
if test -z "$MY_C_ISNAN"; then
  AC_MSG_WARN(Cannot find C-function for checking NaN. Check will return false)
else
  AC_DEFINE_UNQUOTED([MY_C_ISNAN],[$MY_C_ISNAN],
                     [Define to be the name of C-function for NaN check])
fi



# Set ADDLIBS appropriately for socket libraries. Check for the presence of
# header files, then see what we need in the way of libraries.
AC_COIN_OS_SOCKET_LIBS
if test x$ac_coin_found_socket_libraries = xno ; then
  AC_MSG_ERROR([Can't build OS without socket libraries!])
fi
ADDLIBS="$WINSOCKLIBS   $ADDLIBS"
  
AM_CONDITIONAL(USEMULTIPLYDEFINED, test x$mac_osx = xyes)


 
#############################################################################
#                     Parser stuff                         #
#############################################################################

AC_PROG_YACC

#############################################################################
# Define the root of the OS project###
#############################################################################

AC_SUBST(OSROOT_DIR)
OSROOT_DIR=`pwd`
AC_DEFINE_UNQUOTED([OSROOT_DIR], ["$OSROOT_DIR"],
    [Define the path to the OS root])

# The following one is for the example makefiles
case $CXX in
  cl*)
    oslib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libOS.lib';;
  *)
    oslib="-L\$(INSTALLIBDIR) -lOS";;
esac
AC_SUBST(oslib)


##############################################################################
#                   VPATH links for example input files                      #
##############################################################################

# In case this is a VPATH configuration we need to make sure that the
# input files for the examples are available in the VPATH directory.
##
## osil test files
##
AC_COIN_VPATH_LINK(data/osilFiles/parincLinear.osil)
AC_COIN_VPATH_LINK(data/osilFiles/parincQuadratic.osil)
AC_COIN_VPATH_LINK(data/osilFiles/HS071_NLP.osil)
AC_COIN_VPATH_LINK(data/osilFiles/HS071_NLPMod.osil)
AC_COIN_VPATH_LINK(data/osilFiles/rosenbrockmod.osil)
AC_COIN_VPATH_LINK(data/osilFiles/avion2.osil)
AC_COIN_VPATH_LINK(data/osilFiles/lindoapiaddins.osil)
AC_COIN_VPATH_LINK(data/osilFiles/volumeTest.osil)
AC_COIN_VPATH_LINK(data/osilFiles/p0033.osil)
AC_COIN_VPATH_LINK(data/osilFiles/CppADTestLag.osil)
AC_COIN_VPATH_LINK(data/osilFiles/testOperators.osil)
AC_COIN_VPATH_LINK(data/osilFiles/wayneQuadratic.osil)
AC_COIN_VPATH_LINK(data/osilFiles/callBackTest.osil)
AC_COIN_VPATH_LINK(data/osilFiles/callBackTestRowMajor.osil)
##
## osol test files
##
AC_COIN_VPATH_LINK(data/osolFiles/demo.osol)
AC_COIN_VPATH_LINK(data/osolFiles/remotegsbkip.osol)
AC_COIN_VPATH_LINK(data/osolFiles/remoteosil.osol)
AC_COIN_VPATH_LINK(data/osolFiles/retrieve.osol)
AC_COIN_VPATH_LINK(data/osolFiles/send.osol)
AC_COIN_VPATH_LINK(data/osolFiles/sendWithJobID.osol)
AC_COIN_VPATH_LINK(data/osolFiles/kill.osol)
AC_COIN_VPATH_LINK(data/osolFiles/remoteSolve1.osol)
AC_COIN_VPATH_LINK(data/osolFiles/remoteSolve2.osol)
AC_COIN_VPATH_LINK(data/osolFiles/demopassword.osol)
AC_COIN_VPATH_LINK(data/osolFiles/demopasswordjobID.osol)
##
## ospl test files
##
AC_COIN_VPATH_LINK(data/osplFiles/demo.ospl)
##
## osrl test files
##
AC_COIN_VPATH_LINK(data/osrlFiles/parincLinear.osrl)
AC_COIN_VPATH_LINK(data/osrlFiles/reducedcost.osrl)
AC_COIN_VPATH_LINK(data/osrlFiles/rosenbrockmod.osrl)
##
## configure test files
##
AC_COIN_VPATH_LINK(data/configFiles/kill.config)
AC_COIN_VPATH_LINK(data/configFiles/testlocal.config)
AC_COIN_VPATH_LINK(data/configFiles/testbrowser.config)
AC_COIN_VPATH_LINK(data/configFiles/testlocalclp.config)
AC_COIN_VPATH_LINK(data/configFiles/testlocalosol.config)
AC_COIN_VPATH_LINK(data/configFiles/testmps.config)
AC_COIN_VPATH_LINK(data/configFiles/testnl.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemoteKnock.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemotegetJobID.config)
AC_COIN_VPATH_LINK(data/configFiles/testremote.config)
AC_COIN_VPATH_LINK(data/configFiles/testremoteBIG.config)
AC_COIN_VPATH_LINK(data/configFiles/testremoteRetrieve.config)
AC_COIN_VPATH_LINK(data/configFiles/testremoteSend.config)

##
## ampl test files
##
AC_COIN_VPATH_LINK(data/amplFiles/hs71.mod)
AC_COIN_VPATH_LINK(data/amplFiles/hs71.nl)
AC_COIN_VPATH_LINK(data/amplFiles/parinc.mod)
AC_COIN_VPATH_LINK(data/amplFiles/parinc.dat)
AC_COIN_VPATH_LINK(data/amplFiles/parinc.nl)
##
## mps test files
##
AC_COIN_VPATH_LINK(data/mpsFiles/parinc.mps)
##
## MATLAB test files
##
AC_COIN_VPATH_LINK(data/matlabFiles/markowitz.m)
AC_COIN_VPATH_LINK(data/matlabFiles/parincLinear.m)
AC_COIN_VPATH_LINK(data/matlabFiles/template.m)
##
## XSLT FILE
##
AC_COIN_VPATH_LINK(stylesheets/OSrL.xslt)
##
## CSS FILE
##
AC_COIN_VPATH_LINK(stylesheets/OSrL.css)
##










##############################################################################
#                   Finishing up by writing all the output                   #
##############################################################################

# Here list all the files that configure should create (except for the
# configuration header file)
AC_CONFIG_FILES([Makefile
          src/Makefile
          src/OSAgent/Makefile
          src/OSUtils/Makefile
          src/OSCommonInterfaces/Makefile
          src/OSSolverInterfaces/Makefile
          src/OSModelInterfaces/Makefile
          src/OSParsers/Makefile
          test/Makefile
          examples/instanceGenerator/Makefile
          examples/osTestCode/Makefile
          examples/algorithmicDiff/Makefile
          applications/Makefile
          applications/amplClient/Makefile
          applications/fileUpload/Makefile
          os_addlibs.txt])

# Here put the location and name of the configuration header file
AC_CONFIG_HEADER([inc/config_os.h])

# Finally, we let configure write all the output...
AC_COIN_FINALIZE
