# Copyright (C) 2006 International Business Machines.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.

## $Id$

#############################################################################
#                       Names and other basic things                        #
#############################################################################

AC_PREREQ(2.59)

# use this to provide a package name, version number --- make sure it is "trunk" for trunk versions
# an email address for bug reports, and a shortened version of the package name for the tarball
# Note that there is a second configure.ac file in root directory --- make sure to synchronize!
AC_INIT([OS],[2.8.0],[coin-os@lists.coin-or.org])

AC_COPYRIGHT([
Copyright 2006 International Business Machines and others.
All Rights Reserved.
This file is part of the open source package Coin which is distributed
under the Eclipse Public License.])

# List one file in the package so that the configure script can test
# whether the package is actually there
AC_CONFIG_SRCDIR(src/OSConfig.h)

# Where should everything be installed by default?  Here, we want it
# to be installed directly in 'bin', 'lib', 'include' subdirectories
# of the directory where configure is run.  The default would be
# /usr/local.
AC_PREFIX_DEFAULT([`pwd`])

############################################################################
#                         Standard build tool stuff                         #
#############################################################################

# Get the system type
AC_CANONICAL_BUILD

# Initialise projectdir
AC_COIN_PROJECTDIR_INIT(OS,14:0:8)

# Check if user wants to produce debugging code
AC_COIN_DEBUG_COMPILE(OS)

# Get the name of the C++ compiler and appropriate compiler options
AC_COIN_PROG_CXX

# Initialize automake and libtool
AC_COIN_INIT_AUTO_TOOLS

# And determine whether we're big-endian or little-endian. This is necessary to
# define the correct patterns for IEEE infinity and quiet_nan, in the event
# that we can't get them any other way. This will define WORDS_BIGENDIAN if
# we're on a big-endian machine, and do nothing otherwise. Also necessary for
# the David Gay dtoa

AC_C_BIGENDIAN

# We also need to worry about long long 
# if -pedantic used for OSdtoa then we crash without
# the following was added to autoconf 2.60 -- put in when build tools switches over
# this will define HAVE_LONG_LONG_INT
#AC_TYPE_LONG_LONG_INT 
#for now assume C++
#AC_DEFINE([SIZEOF_LONG_LONG],[0],[in C++ make sure SIZEOF_LONG_LONG is less than 8])
#KIPP deal with the above

AC_LANG_PUSH(C)

# the following does not work for cached variables
#AC_CHECK_SIZEOF( long long)
AC_CHECK_SIZEOF( int)
AC_CHECK_SIZEOF( double)
AC_CHECK_SIZEOF( long)

AC_LANG_POP(C)

#############################################################################
#                           COIN-OR components                              #
#############################################################################

AC_COIN_CHECK_PACKAGE(CoinUtils,[coinutils],[OSLib])
if test $coin_has_coinutils != yes ; then
  AC_MSG_ERROR([Required package CoinUtils not available.])
fi
AC_COIN_CHECK_PACKAGE(Ipopt,    [ipopt cppad],  [OSLib])
AC_COIN_CHECK_PACKAGE(Clp,      [osi-clp],      [OSLib])
AC_COIN_CHECK_PACKAGE(DyLP,     [osi-dylp],     [OSLib])
AC_COIN_CHECK_PACKAGE(Vol,      [osi-vol],      [OSLib])
AC_COIN_CHECK_PACKAGE(SYMPHONY, [osi-sym],      [OSLib])
AC_COIN_CHECK_PACKAGE(Cpx,      [osi-cplex],    [OSLib])
AC_COIN_CHECK_PACKAGE(Glpk,     [osi-glpk],     [OSLib])
AC_COIN_CHECK_PACKAGE(Grb,      [osi-gurobi],   [OSLib])
AC_COIN_CHECK_PACKAGE(Msk,      [osi-mosek],    [OSLib])
AC_COIN_CHECK_PACKAGE(SoPlex,   [osi-soplex],   [OSLib])
AC_COIN_CHECK_PACKAGE(Xpr,      [osi-xpress],   [OSLib])
AC_COIN_CHECK_PACKAGE(Cbc,      [cbc],          [OSLib])
AC_COIN_CHECK_PACKAGE(Bonmin,   [bonmin cppad], [OSLib])
AC_COIN_CHECK_PACKAGE(Couenne,  [couenne cppad],[OSLib])
AC_COIN_CHECK_PACKAGE(Bcp,      [bcp],          [OSLib])
AC_COIN_CHECK_PACKAGE(ASL,      [coinasl],      [OSLib])
AC_COIN_CHECK_PACKAGE(cppad,    [cppad],        [OSLib])

# The COIN_HAS_CPPAD symbol should not go into the public configuration
# header file (config_os.h).
# However, we need to distinguish in OS' public headers files whether
# CppAD is available or not, so we define an additional symbol.
if test $coin_has_cppad = yes ; then
  AC_DEFINE(OS_HAS_CPPAD, [1], [Define to 1 if OS uses CppAD])
fi

# Ipopt is available or not, so we define an additional symbol.
if test $coin_has_ipopt = yes ; then
  AC_DEFINE(OS_HAS_IPOPT, [1], [Define to 1 if OS uses Ipopt])
fi

# Bonmin is available or not, so we define an additional symbol.
if test $coin_has_bonmin = yes ; then
  AC_DEFINE(OS_HAS_BONMIN, [1], [Define to 1 if OS uses Bonmin])
fi

# Couenne is available or not, so we define an additional symbol.
if test $coin_has_couenne = yes ; then
  AC_DEFINE(OS_HAS_COUENNE, [1], [Define to 1 if OS uses Couenne])
fi

# SYMPHONY is available or not, so we define an additional symbol.
if test $coin_has_couenne = yes ; then
  AC_DEFINE(OS_HAS_SYMPHONY, [1], [Define to 1 if OS uses SYMPHONY])
fi

# Vol is available or not, so we define an additional symbol.
if test $coin_has_vol = yes ; then
  AC_DEFINE(OS_HAS_VOL, [1], [Define to 1 if OS uses Vol])
fi

# Glpk is available or not, so we define an additional symbol.
if test $coin_has_glpk = yes ; then
  AC_DEFINE(OS_HAS_GLPK, [1], [Define to 1 if OS uses Glpk])
fi

#Dylp is available or not, so we define an additional symbol.
if test $coin_has_dylp = yes ; then
  AC_DEFINE(OS_HAS_DYLP, [1], [Define to 1 if OS uses DyLP])
fi

# ASL is available or not, so we define an additional symbol.
if test $coin_has_asl = yes ; then
  AC_DEFINE(OS_HAS_ASL, [1], [Define to 1 if OS uses ASL])
fi

#############################################################################
#                             Third party solvers                           #
#############################################################################

AC_COIN_CHECK_USER_LIBRARY([Lindo], [LINDO], [lindo.h], [OSLib])
AC_COIN_CHECK_USER_LIBRARY([Knitro],[KNITRO],[knitro.h],[OSLib])


#############################################################################
#                         OS-specific configuration                         #
#############################################################################


  case $build in
     *-mingw*)
         AC_DEFINE([WIN_],[1],[use if OS is Windows]) ;;
      *-cygwin*)
         AC_DEFINE([WIN_],[1],[use if OS is Windows])
		   case $CXX in
		    g*)
		      AC_DEFINE([USE_OLD_UNISTD],[1],[use if OS is Cygwin and compiler is gnu]);;
		     *)
		     AC_MSG_WARN("DONT HAVE GCC COMPILER WITH GYGWIN");;   
		  esac   
		  AC_DEFINE([NOMINMAX],[1],[use if OS is Cygwin]);;
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

##############################################################################
#                            OPENMP defs                                     #
##############################################################################


AC_ARG_ENABLE([openmp],
[AC_HELP_STRING([--enable-openmp],
                [compile in OpenMP features])],
[case "${enableval}" in
   yes) os_openmp=true
   ;;
   no)  os_openmp=false
   ;;
   *) AC_MSG_ERROR(Bad value ${enableval} for --enable-openmp)
   ;;
esac],
[os_openmp=false])

if test $os_openmp = true; then
   AC_MSG_CHECKING([G++ version])
   fopenmp_version=4.2
   gcc_required_version=`echo ${fopenmp_version} | sed -e 's/\./0/g'`
   get_gcc_version=`$CXX -dumpversion`
   gcc_version=`echo ${get_gcc_version} | sed -e 's/\./0/g'`
   major_gcc_version=`echo ${gcc_version:0:3}`
   AC_MSG_RESULT([$get_gcc_version])
   if test ${major_gcc_version} -lt ${gcc_required_version}; then
       AC_MSG_ERROR(OpenMP feautures are supported by G++ 4.2.0 or higher.)
   fi
fi

AM_CONDITIONAL(OPENMP, [test $os_openmp = true])


###########################################################################
# check to see if we turn off dtoa
###########################################################################
 	

AC_ARG_ENABLE([nodtoa],
[AC_HELP_STRING([--enable-nodtoa],
                [do not use dtoa use the C and C++ for string to decimal and back])],
[case "${enableval}" in
  yes) nodtoa=true ;;
  no)  nodtoa=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-nodtoa) ;;
esac],[nodtoa=false])

if test $nodtoa = false; then
   AC_DEFINE([USE_DTOA],[1],[use to get lossless IO])
fi

#the above make the below unnecessary
#AM_CONDITIONAL(USE_DTOA, test x$nodtoa = xfalse)


############################################################################
############################################################################
#                   Stuff that we need for C++ programs                    #
############################################################################
############################################################################

################
# Header Files #
################

AC_LANG_PUSH(C++)

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
AC_COIN_CHECK_HEADER(stdint.h)

#AC_CHECK_HEADERS([windows.h])

AC_LANG_POP(C++)

###################
# Function isnan  #
###################

AC_COIN_CHECK_ISNAN

###################
# Sockets library #
###################

# Check for the sockets library. Check for the presence of
# header files, then see what we need in the way of libraries.
AC_COIN_OS_SOCKET_LIBS
if test x$ac_coin_found_socket_libraries = xno ; then
  AC_MSG_ERROR([Can't build OS without socket libraries!])
fi
  
AM_CONDITIONAL(USEMULTIPLYDEFINED, test x$mac_osx = xyes)
 
#############################################################################
#                                 Parser stuff                              #
#############################################################################

AC_PROG_YACC
AM_PROG_LEX

#############################################################################
# Define the root of the OS project                                         #
#############################################################################

AC_SUBST(OSROOT_DIR)
OSROOT_DIR=`pwd`
AC_DEFINE_UNQUOTED([OSROOT_DIR], ["$OSROOT_DIR"],
    [Define the path to the OS root])

# The following one is for the example makefiles
case $CXX in
  cl*)
    oslib='`$(CYGPATH_W) $(INSTALLIBDIR)`\\libOS.lib';;
  g++* | *\g++* | */g++*)
     if test $os_openmp = true; then
         CXXFLAGS="$CXXFLAGS -fopenmp"
     fi
     oslib="-L\$(INSTALLIBDIR) -lOS"
  ;;
  *)
   ;;
esac
AC_SUBST(oslib)

#############################################################################
#  See if we are disabling shared libs                                      #
#############################################################################

##
## the help file
##
#AC_COIN_VPATH_LINK(src/help.txt)

##
## osil test files
##
AC_COIN_VPATH_LINK(data/osilFiles/avion2.osil)
AC_COIN_VPATH_LINK(data/osilFiles/bonminEx1.osil)
AC_COIN_VPATH_LINK(data/osilFiles/bonminEx1_Nonlinear.osil)
AC_COIN_VPATH_LINK(data/osilFiles/callBackTest.osil)
AC_COIN_VPATH_LINK(data/osilFiles/callBackTestRowMajor.osil)
AC_COIN_VPATH_LINK(data/osilFiles/CppADTestLag.osil)
AC_COIN_VPATH_LINK(data/osilFiles/finplan1.osil)
AC_COIN_VPATH_LINK(data/osilFiles/gamstrnsport.osil)
AC_COIN_VPATH_LINK(data/osilFiles/genAssign.osil)
AC_COIN_VPATH_LINK(data/osilFiles/HS071_NLP.osil)
AC_COIN_VPATH_LINK(data/osilFiles/HS071_feas.osil)
AC_COIN_VPATH_LINK(data/osilFiles/HS071_no-obj.osil)
AC_COIN_VPATH_LINK(data/osilFiles/HS071_NLPMod.osil)
AC_COIN_VPATH_LINK(data/osilFiles/IP_infeasible.osil)
AC_COIN_VPATH_LINK(data/osilFiles/IP_noconstraint.osil)
AC_COIN_VPATH_LINK(data/osilFiles/IP_unbounded.osil)
AC_COIN_VPATH_LINK(data/osilFiles/lindoapiaddins.osil)
AC_COIN_VPATH_LINK(data/osilFiles/LP_nobasis.osil)
AC_COIN_VPATH_LINK(data/osilFiles/LP_noconstraint.osil)
AC_COIN_VPATH_LINK(data/osilFiles/LP_infeasible.osil)
AC_COIN_VPATH_LINK(data/osilFiles/LP_unbounded.osil)
AC_COIN_VPATH_LINK(data/osilFiles/muer.osil)
AC_COIN_VPATH_LINK(data/osilFiles/nanTest.osil)
AC_COIN_VPATH_LINK(data/osilFiles/nonconvex.osil)
AC_COIN_VPATH_LINK(data/osilFiles/nonconvex_D.osil)
AC_COIN_VPATH_LINK(data/osilFiles/parincInteger.osil)
AC_COIN_VPATH_LINK(data/osilFiles/parincLinear.osil)
AC_COIN_VPATH_LINK(data/osilFiles/parincLinearByRow.osil)
AC_COIN_VPATH_LINK(data/osilFiles/parincLinearEmpty.osil)
AC_COIN_VPATH_LINK(data/osilFiles/parincLinearZeroVar.osil)
AC_COIN_VPATH_LINK(data/osilFiles/parincQuadratic.osil)
AC_COIN_VPATH_LINK(data/osilFiles/p0033.osil)
AC_COIN_VPATH_LINK(data/osilFiles/p0033MULT.osil)
AC_COIN_VPATH_LINK(data/osilFiles/p0201.osil)
AC_COIN_VPATH_LINK(data/osilFiles/reallyEmpty.osil)
AC_COIN_VPATH_LINK(data/osilFiles/rosenbrockmod.osil)
AC_COIN_VPATH_LINK(data/osilFiles/rosenbrockorig.osil)
AC_COIN_VPATH_LINK(data/osilFiles/rosenbrockorigInt.osil)
AC_COIN_VPATH_LINK(data/osilFiles/testOperators.osil)
AC_COIN_VPATH_LINK(data/osilFiles/test24locR1.osil)
AC_COIN_VPATH_LINK(data/osilFiles/test48locR1.osil)
AC_COIN_VPATH_LINK(data/osilFiles/smallIPBook.osil)
AC_COIN_VPATH_LINK(data/osilFiles/spl1.osil)
AC_COIN_VPATH_LINK(data/osilFiles/spl2.osil)
AC_COIN_VPATH_LINK(data/osilFiles/volumeTest.osil)
AC_COIN_VPATH_LINK(data/osilFiles/wayneQuadratic.osil)
##
## osol test files
##
AC_COIN_VPATH_LINK(data/osolFiles/demo.osol)
AC_COIN_VPATH_LINK(data/osolFiles/demo1.osol)
AC_COIN_VPATH_LINK(data/osolFiles/knock.osol)
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
AC_COIN_VPATH_LINK(data/osolFiles/avion2_ipopt.osol)
AC_COIN_VPATH_LINK(data/osolFiles/bonminEx1_Bonmin.osol)
AC_COIN_VPATH_LINK(data/osolFiles/bonminEx1_Couenne.osol)
AC_COIN_VPATH_LINK(data/osolFiles/callBackTestRowMajor_ipopt.osol)
AC_COIN_VPATH_LINK(data/osolFiles/callBackTest_ipopt.osol)
AC_COIN_VPATH_LINK(data/osolFiles/callBackTest_knitro.osol)
AC_COIN_VPATH_LINK(data/osolFiles/genAssign.osol)
AC_COIN_VPATH_LINK(data/osolFiles/HS071_NLPMod_ipopt.osol)
AC_COIN_VPATH_LINK(data/osolFiles/HS071_NLP_knitro.osol)
AC_COIN_VPATH_LINK(data/osolFiles/lindoapiaddins_lindo.osol)
AC_COIN_VPATH_LINK(data/osolFiles/nonconvex.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parincInteger_cbc.osol)
AC_COIN_VPATH_LINK(data/osolFiles/p0033_cbc.osol)
AC_COIN_VPATH_LINK(data/osolFiles/p0033_cpx.osol)
AC_COIN_VPATH_LINK(data/osolFiles/p0033_glpk.osol)
AC_COIN_VPATH_LINK(data/osolFiles/p0033_sym.osol)
AC_COIN_VPATH_LINK(data/osolFiles/p0201_cbc.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parincLinearByRow_clp.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parincLinear_dylp.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parincLinear_ipopt.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parincQuadratic_ipopt.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parincQuadratic_knitro.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parincQuadratic_lindo.osol)
AC_COIN_VPATH_LINK(data/osolFiles/rosenbrockmod_ipopt.osol)
AC_COIN_VPATH_LINK(data/osolFiles/rosenbrockmod_knitro.osol)
AC_COIN_VPATH_LINK(data/osolFiles/rosenbrockmod_lindo.osol)
AC_COIN_VPATH_LINK(data/osolFiles/smallIPBook.osol)
AC_COIN_VPATH_LINK(data/osolFiles/spl1.osol)
AC_COIN_VPATH_LINK(data/osolFiles/spl1-b.osol)
AC_COIN_VPATH_LINK(data/osolFiles/spl2.osol)
AC_COIN_VPATH_LINK(data/osolFiles/spl2-b.osol)
AC_COIN_VPATH_LINK(data/osolFiles/suffixTest.osol)
AC_COIN_VPATH_LINK(data/osolFiles/volumeTest_vol.osol)
AC_COIN_VPATH_LINK(data/osolFiles/wayneQuadratic_Bonmin1.osol)
AC_COIN_VPATH_LINK(data/osolFiles/wayneQuadratic_Bonmin2.osol)
AC_COIN_VPATH_LINK(data/osolFiles/wayneQuadratic_Couenne.osol)
AC_COIN_VPATH_LINK(data/osolFiles/wayneQuadratic_lindo.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parsertest.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parsertest2.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parsertest3.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parsertestWithErrors.osol)
AC_COIN_VPATH_LINK(data/osolFiles/parsertestWithErrors.result)
##
## ospl test files
##
AC_COIN_VPATH_LINK(data/osplFiles/demo.ospl)
AC_COIN_VPATH_LINK(data/osplFiles/knock.ospl)
AC_COIN_VPATH_LINK(data/osplFiles/result.ospl)
##
## osrl test files
##
AC_COIN_VPATH_LINK(data/osrlFiles/ipoptResult.osrl)
AC_COIN_VPATH_LINK(data/osrlFiles/parserTest.osrl)
AC_COIN_VPATH_LINK(data/osrlFiles/parincLinear.osrl)
AC_COIN_VPATH_LINK(data/osrlFiles/reducedcost.osrl)
AC_COIN_VPATH_LINK(data/osrlFiles/rosenbrockmod.osrl)
AC_COIN_VPATH_LINK(data/osrlFiles/errorExample.osrl)
##
## configure test files
##
AC_COIN_VPATH_LINK(data/configFiles/kill.config)
AC_COIN_VPATH_LINK(data/configFiles/testLocal.config)
AC_COIN_VPATH_LINK(data/configFiles/testLocalMPS.config)
AC_COIN_VPATH_LINK(data/configFiles/testLocalNL.config)
AC_COIN_VPATH_LINK(data/configFiles/testbrowser.config)
AC_COIN_VPATH_LINK(data/configFiles/testlocalclp.config)
AC_COIN_VPATH_LINK(data/configFiles/testlocalosol.config)
AC_COIN_VPATH_LINK(data/configFiles/testmps.config)
AC_COIN_VPATH_LINK(data/configFiles/testnl.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemoteKnock.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemotegetJobID.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemote.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemoteMPS.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemoteNL.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemoteBIG.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemoteRetrieve.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemoteSend.config)
##
## ampl test files
##
AC_COIN_VPATH_LINK(data/amplFiles/testAmpl.run)
AC_COIN_VPATH_LINK(data/amplFiles/bonminEx1.mod)
AC_COIN_VPATH_LINK(data/amplFiles/bonminEx1.nl)
AC_COIN_VPATH_LINK(data/amplFiles/hs71.mod)
AC_COIN_VPATH_LINK(data/amplFiles/hs71.nl)
AC_COIN_VPATH_LINK(data/amplFiles/muer.mod)
AC_COIN_VPATH_LINK(data/amplFiles/muerdata10.dat)
AC_COIN_VPATH_LINK(data/amplFiles/muer.nl)
AC_COIN_VPATH_LINK(data/amplFiles/nonconvex.mod)
AC_COIN_VPATH_LINK(data/amplFiles/nonconvex.nl)
AC_COIN_VPATH_LINK(data/amplFiles/nonconvex_D.mod)
AC_COIN_VPATH_LINK(data/amplFiles/nonconvex_D.nl)
AC_COIN_VPATH_LINK(data/amplFiles/parinc.mod)
AC_COIN_VPATH_LINK(data/amplFiles/parinc.dat)
AC_COIN_VPATH_LINK(data/amplFiles/parinc.nl)
AC_COIN_VPATH_LINK(data/amplFiles/suffixTest.cmp)
AC_COIN_VPATH_LINK(data/amplFiles/suffixTest.mod)
AC_COIN_VPATH_LINK(data/amplFiles/suffixTest.nl)
AC_COIN_VPATH_LINK(data/amplFiles/volumeTest.mod)
AC_COIN_VPATH_LINK(data/amplFiles/volumeTest.nl)
AC_COIN_VPATH_LINK(data/amplFiles/LP_infeasible.mod)
AC_COIN_VPATH_LINK(data/amplFiles/LP_infeasible.nl)
AC_COIN_VPATH_LINK(data/amplFiles/IP_infeasible.mod)
AC_COIN_VPATH_LINK(data/amplFiles/IP_infeasible.nl)
AC_COIN_VPATH_LINK(data/amplFiles/LP_unbounded.mod)
AC_COIN_VPATH_LINK(data/amplFiles/LP_unbounded.nl)
AC_COIN_VPATH_LINK(data/amplFiles/IP_unbounded.mod)
AC_COIN_VPATH_LINK(data/amplFiles/IP_unbounded.nl)
AC_COIN_VPATH_LINK(data/amplFiles/volumeTest.mod)
AC_COIN_VPATH_LINK(data/amplFiles/volumeTest.nl)
##
## GAMS test files
##
AC_COIN_VPATH_LINK(data/gamsFiles/parincLinear.gms)
AC_COIN_VPATH_LINK(data/gamsFiles/rbrockmod.gms)
AC_COIN_VPATH_LINK(data/gamsFiles/rbrockorig.gms)
AC_COIN_VPATH_LINK(data/gamsFiles/trnsport.gms)
AC_COIN_VPATH_LINK(data/gamsFiles/IP_infeasible.gms)
AC_COIN_VPATH_LINK(data/gamsFiles/IP_unbounded.gms)
AC_COIN_VPATH_LINK(data/gamsFiles/LP_unbounded.gms)
##
## mps test files
##
AC_COIN_VPATH_LINK(data/mpsFiles/parinc.mps)
AC_COIN_VPATH_LINK(data/mpsFiles/IP_unbounded.mps)
##
## MATLAB test files
##
AC_COIN_VPATH_LINK(data/matlabFiles/markowitz.m)
AC_COIN_VPATH_LINK(data/matlabFiles/parincLinear.m)
AC_COIN_VPATH_LINK(data/matlabFiles/template.m)
AC_COIN_VPATH_LINK(data/matlabFiles/OSCallMatlabSolver.m)
###
## columnGen Application files
##
AC_COIN_VPATH_LINK(applications/columnGen/data/colgen10.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/colgen12.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/colgen12b.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2009p40-25-25-25.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2009p50-25-25-25.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2009p60-25-25-25.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2009p70-25-25-25.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2009p95-140-140-140.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2009mean-25-25-25.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p75-40-40-40.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p80-40-40-40.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p85-40-40-40.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p90-40-40-40.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p90-40-40-60.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p90-40-60-40.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p90-60-40-40.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p90-60-20-20-40.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p92-40-40-60.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p92-40-60-40.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p92-60-40-40.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p90-120-120-120.osol)
AC_COIN_VPATH_LINK(applications/columnGen/data/y2010p95-150-150-150.osol)
##
### Python Code
##
AC_COIN_VPATH_LINK(applications/parsingTest/parsingTest.py)
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
          applications/Makefile
          applications/amplClient/Makefile
          applications/fileUpload/Makefile
          applications/columnGen/code/Makefile
          applications/parsingTest/Makefile
          os.pc
	  os-uninstalled.pc])

# Here put the location and name of the configuration header file
AC_CONFIG_HEADER([src/config.h src/config_os.h])

# Finally, we let configure write all the output...
AC_COIN_FINALIZE
