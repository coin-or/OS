# Copyright (C) 2006 International Business Machines.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.

#############################################################################
#                       Names and other basic things                        #
#############################################################################

AC_INIT([OS],[devel],[https://github.com/coin-or/OS/issues/new],[coin-or-os],[https://github.com/coin-or/OS])

AC_COPYRIGHT([
Copyright 2006 International Business Machines and others.
All Rights Reserved.
This file is part of the open source package Coin which is distributed
under the Eclipse Public License.])

# List one file in the package so that the configure script can test
# whether the package is actually there
AC_CONFIG_SRCDIR(src/OSConfig.h)

# Do some initialization work (version numbers, change prefix default, ...)
AC_COIN_INITIALIZE

#############################################################################
#                         Standard build tool stuff                         #
#############################################################################

# Get the name of the C++ compiler and appropriate compiler options
AC_COIN_PROG_CXX

# This is a C++ package, set the language accordingly.
AC_LANG_PUSH(C++)

# Initialize libtool
AC_COIN_PROG_LIBTOOL

# set RPATH_FLAGS to the compiler link flags required to hardcode location
# of the shared objects (expanded_libdir is set somewhere in configure before)
AC_COIN_RPATH_FLAGS([$expanded_libdir])

# Determine whether we're big-endian or little-endian. This defines
# WORDS_BIGENDIAN on a big-endian machine, which the David Gay dtoa needs.
AC_C_BIGENDIAN

AC_CHECK_SIZEOF([int])
AC_CHECK_SIZEOF([double])
AC_CHECK_SIZEOF([long])

#############################################################################
#                           COIN-OR components                              #
#############################################################################

# The COIN-OR solver interface (OSCoinSolver) uses Cbc, Cgl, Clp, and Osi
# unconditionally.
m4_foreach_w([myvar],[CoinUtils Osi Clp Cgl Cbc],
  [ AC_COIN_CHK_PKG(myvar,[OSLib],m4_case(myvar,[Clp],[osi-clp]))
    if test $coin_has_[]m4_tolower(myvar) != yes ; then
      AC_MSG_ERROR([Required package myvar is not available.])
    fi
  ])

# OS computes the derivatives for its nonlinear solver interfaces (Ipopt,
# Bonmin, Couenne) with CppAD, so these are skipped if CppAD isn't available.
# OS uses only the headers of CppAD, so only the compiler flags from cppad.pc
# are used: linking with CppAD's library is not needed, and in static builds
# it would fail if only a shared library of CppAD is available.
AC_COIN_CHK_PKG(CppAD,    [],[cppad])
if test $coin_has_cppad = yes ; then
  OSLIB_CFLAGS="`PKG_CONFIG_PATH="$COIN_PKG_CONFIG_PATH" $PKG_CONFIG --cflags cppad` $OSLIB_CFLAGS"
else
  AC_MSG_NOTICE([CppAD is not available, so Ipopt, Bonmin, and Couenne are skipped.])
  COIN_SKIP_PROJECTS="$COIN_SKIP_PROJECTS ipopt bonmin couenne"
fi
AC_COIN_CHK_PKG(Ipopt,    [OSLib],[ipopt])
AC_COIN_CHK_PKG(Bonmin,   [OSLib],[bonmin])
AC_COIN_CHK_PKG(Couenne,  [OSLib],[couenne])
AC_COIN_CHK_PKG(DyLP,     [OSLib],[osi-dylp])
AC_COIN_CHK_PKG(Vol,      [OSLib],[osi-vol])
AC_COIN_CHK_PKG(SYMPHONY, [OSLib],[osi-sym])
AC_COIN_CHK_PKG(Glpk,     [OSLib],[osi-glpk])
AC_COIN_CHK_PKG(Cpx,      [OSLib],[osi-cplex])
AC_COIN_CHK_PKG(Grb,      [OSLib],[osi-gurobi])
AC_COIN_CHK_PKG(Msk,      [OSLib],[osi-mosek])
AC_COIN_CHK_PKG(SoPlex,   [OSLib],[osi-soplex])
AC_COIN_CHK_PKG(Xpr,      [OSLib],[osi-xpress])
AC_COIN_CHK_PKG(ASL,      [OSLib],[coinasl])

# Bonmin and Couenne are used through their Ipopt interface.
if test $coin_has_bonmin = yes && test $coin_has_ipopt != yes ; then
  AC_MSG_ERROR([Found Bonmin, but not Ipopt.])
fi
if test $coin_has_couenne = yes && test $coin_has_bonmin != yes ; then
  AC_MSG_ERROR([Found Couenne, but not Bonmin.])
fi

#############################################################################
#                             Third party solvers                           #
#############################################################################

AC_COIN_CHK_LIBHDR(Lindo, [OSLib],[],[],[],[],[#include "lindo.h"],[default_skip])
AC_COIN_CHK_LIBHDR(Knitro,[OSLib],[],[],[],[],[#include "knitro.h"],[default_skip])
AC_COIN_CHK_LIBHDR(Csdp,  [OSLib],[],[],[],[],[#include "blockmat.h"],[default_skip])

#############################################################################
#                         OS-specific configuration                         #
#############################################################################

case $host in
  *-mingw* | *-win*)
    AC_DEFINE([WIN_],[1],[use if OS is Windows])
    ;;
  *-cygwin*)
    AC_DEFINE([WIN_],[1],[use if OS is Windows])
    case $CXX in
      g*)
        AC_DEFINE([USE_OLD_UNISTD],[1],[use if OS is Cygwin and compiler is gnu])
        ;;
      *)
        AC_MSG_WARN("DONT HAVE GCC COMPILER WITH GYGWIN")
        ;;
    esac
    AC_DEFINE([NOMINMAX],[1],[use if OS is Cygwin])
    ;;
  *-darwin*)
    AC_DEFINE([MACOSX_],[1],[use if OS is MACOSX])
    ;;
esac

###########################################################################
# check to see if we turn off dtoa
###########################################################################

AC_ARG_ENABLE([nodtoa],
[AS_HELP_STRING([--enable-nodtoa],
                [do not use dtoa use the C and C++ for string to decimal and back])],
[case "${enableval}" in
  yes) nodtoa=true ;;
  no)  nodtoa=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-nodtoa) ;;
esac],[nodtoa=false])

if test $nodtoa = false; then
   AC_DEFINE([USE_DTOA],[1],[use to get lossless IO])
fi

################
# Header Files #
################

AC_CHECK_HEADERS([cassert cctype cfloat cieeefp cmath cstdarg cstdio cstdlib cstring ctime])
AC_CHECK_HEADERS([assert.h ctype.h float.h ieeefp.h math.h stdarg.h stdint.h stdio.h stdlib.h string.h time.h])

###################
# Sockets library #
###################

# Check for the sockets library. Check for the presence of
# header files, then see what we need in the way of libraries.
AC_COIN_OS_SOCKET_LIBS
if test x$ac_coin_found_socket_libraries = xno ; then
  AC_MSG_ERROR([Can't build OS without socket libraries!])
fi

#############################################################################
#                                 Parser stuff                              #
#############################################################################

AC_PROG_YACC
# if bison and byacc are not found, YACC is set to yacc
# so check also if yacc is present, if set
if test "x$YACC" = xyacc ; then
  AC_CHECK_PROG(YACC, yacc, yacc)
fi

AC_PROG_LEX([noyywrap])
# if lex and flex are not found, LEX is set to :

AC_MSG_CHECKING([whether user wants to run flex and bison])
AC_ARG_WITH([flex-bison],
[AS_HELP_STRING([--with-flex-bison],
                [use flex and bison])],
		[os_flex_bison=$withval],[os_flex_bison=no])
AC_MSG_RESULT([$os_flex_bison])

AM_CONDITIONAL(HAVE_LEXYACC, test -n "`$LEX --version`" && test -n "$YACC" &&
			     test $os_flex_bison = yes)

AC_MSG_CHECKING([whether to use 64-bit integers in XML parser])
AC_ARG_ENABLE([xml-long-integer],
[AS_HELP_STRING([--enable-xml-long-integer],
                [use 64 bit integers])],
		[os_xml_long_integer=$enableval],[os_xml_long_integer=no])
AC_MSG_RESULT([$os_xml_long_integer])

# make sure that OS and compilers support 64-bit integers
if test x$os_xml_long_integer = xyes ; then
  OsXmlInt64=
  OsXmlUInt64=

# try int64_t
  AC_CHECK_TYPE([int64_t],[OsXmlInt64=int64_t ; OsXmlUInt64=uint64_t],[],[#include <cstdint>])

# try int_least64_t
  if test x"$OsXmlInt64" = x; then
    AC_CHECK_TYPE([int_least64_t],[OsXmlInt64=int_least64_t ; OsXmlUInt64=uint_least64_t],
      [],[#include <cstdint>])
  fi

# try long long
  if test x"$OsXmlInt64" = x; then
    AC_CHECK_SIZEOF([long long])
    case $ac_cv_sizeof_long_long in
      8 | 8?) OsXmlInt64="long long"
              OsXmlUInt64="unsigned long long"
              ;;
    esac
  fi

# try long
  if test x"$OsXmlInt64" = x; then
    case $ac_cv_sizeof_long in
      8 | 8?) OsXmlInt64="long"
              OsXmlUInt64="unsigned long"
              ;;
    esac
  fi

# try int
  if test x"$OsXmlInt64" = x; then
    case $ac_cv_sizeof_int in
      8 | 8?) OsXmlInt64="int"
              OsXmlUInt64="unsigned int"
              ;;
    esac
  fi

  if test x"$OsXmlInt64" != x; then
    AC_DEFINE(OS_USE_XML_LONG_INTEGER, [1], [use 64 bit integers])
    AC_DEFINE_UNQUOTED([OS_XML_INT64],[$OsXmlInt64],[Define to 64-bit integer type])
    AC_DEFINE_UNQUOTED([OS_XML_UINT64],[$OsXmlUInt64],
                       [Define to 64-bit unsigned integer type])
  else
    AC_MSG_ERROR([Can't use 64-bit integers without architecture support!])
  fi
fi

#############################################################################
#  Create links for VPATH config of certain files                           #
#############################################################################

AC_COIN_CHECK_VPATH

##
## osil test files
##
AC_COIN_VPATH_LINK(data/osilFiles/avion2.osil)
AC_COIN_VPATH_LINK(data/osilFiles/bonminEx1.osil)
AC_COIN_VPATH_LINK(data/osilFiles/bonminEx1_Nonlinear.osil)
AC_COIN_VPATH_LINK(data/osilFiles/callBackTest.osil)
AC_COIN_VPATH_LINK(data/osilFiles/callBackTestRowMajor.osil)
AC_COIN_VPATH_LINK(data/osilFiles/CppADTestLag.osil)
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
AC_COIN_VPATH_LINK(data/osilFiles/SDPA_ex.osil)
AC_COIN_VPATH_LINK(data/osilFiles/testOperators.osil)
AC_COIN_VPATH_LINK(data/osilFiles/testMatricesAndCones.osil)
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
AC_COIN_VPATH_LINK(data/osolFiles/SDPA_ex.osol)
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
AC_COIN_VPATH_LINK(data/configFiles/testlocalclp.config)
AC_COIN_VPATH_LINK(data/configFiles/testlocalosol.config)
AC_COIN_VPATH_LINK(data/configFiles/testmps.config)
AC_COIN_VPATH_LINK(data/configFiles/testnl.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemoteKnock.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemotegetJobID.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemote.config)
AC_COIN_VPATH_LINK(data/configFiles/testRemote1.config)
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
AC_COIN_VPATH_LINK(data/mpsFiles/parincQuadratic.mps)
AC_COIN_VPATH_LINK(data/mpsFiles/IP_unbounded.mps)

##
## MATLAB test files
##
AC_COIN_VPATH_LINK(data/matlabFiles/markowitz.m)
AC_COIN_VPATH_LINK(data/matlabFiles/parincLinear.m)
AC_COIN_VPATH_LINK(data/matlabFiles/template.m)
AC_COIN_VPATH_LINK(data/matlabFiles/OSCallMatlabSolver.m)

##
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
## Miscellaneous files for testing
##
AC_COIN_VPATH_LINK(test/data/IP_infeasible.osil)
AC_COIN_VPATH_LINK(test/data/IP_noconstraint.mps)
AC_COIN_VPATH_LINK(test/data/IP_noconstraint.osil)
AC_COIN_VPATH_LINK(test/data/IP_unbounded.mps)
AC_COIN_VPATH_LINK(test/data/IP_unbounded.osil)
AC_COIN_VPATH_LINK(test/data/LP_infeasible.osil)
AC_COIN_VPATH_LINK(test/data/LP_nobasis.osil)
AC_COIN_VPATH_LINK(test/data/LP_noconstraint.mps)
AC_COIN_VPATH_LINK(test/data/LP_noconstraint.osil)
AC_COIN_VPATH_LINK(test/data/LP_unbounded.osil)
AC_COIN_VPATH_LINK(test/data/NaNTest2.osil)
AC_COIN_VPATH_LINK(test/data/nanTest.osil)
AC_COIN_VPATH_LINK(test/data/nonconvex2.osil)
AC_COIN_VPATH_LINK(test/data/nonconvex_D.osil)
AC_COIN_VPATH_LINK(test/data/nonconvex.osil)
AC_COIN_VPATH_LINK(test/data/parsertestWithErrors.osol)
AC_COIN_VPATH_LINK(test/data/qptest2.osil)
AC_COIN_VPATH_LINK(test/data/qptest.osil)
AC_COIN_VPATH_LINK(test/data/reallyEmpty.osil)
AC_COIN_VPATH_LINK(test/data/share2qp.mps)

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

#############################################################################
#                  Check for doxygen                                        #
#############################################################################

AC_COIN_DOXYGEN([CoinUtils Osi Clp Cgl Cbc Vol DyLP SYMPHONY Ipopt Bonmin Couenne])

##############################################################################
#                   Finishing up by writing all the output                   #
##############################################################################

AC_COIN_FINALIZE_FLAGS([OSLib])

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
                 os.pc])
AC_CONFIG_FILES([doxydoc/doxygen.conf])

# Here put the location and name of the configuration header file
AC_CONFIG_HEADERS([src/config.h src/config_os.h])

# Finally, we let configure write all the output...
AC_COIN_FINALIZE
