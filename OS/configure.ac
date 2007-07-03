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

  case $build in
     *-mingw*)
         AC_DEFINE([WIN_],[1],[use if OS is Windows])      
         win_sock=yes;; 
      *-cygwin*)
         AC_DEFINE([WIN_],[1],[use if OS is Windows])
         AC_DEFINE([NOMINMAX],[1],[use if OS is Cygwin])
         win_sock=yes;; 
       *-win*)
         AC_DEFINE([WIN_],[1],[use if OS is Windows])
         win_sock=yes;; 
    *-linux-*)
		 ;;
    *-darwin*)
        AC_DEFINE([MACOSX_],[1],[use if OS is MACOSX])
        mac_osx=yes;;
    *-ibm-*)
         ;;
    *-hp-*)
         ;;
    *-sun-*)
    ;;
    *)
    ;;
  esac
  


# If this project depends on external projects, the Externals file in
# the source root directory contains definition of where to find those
# externals.  The following macro ensures that those externals are
# retrieved by svn if they are not there yet.
AC_COIN_PROJECTDIR_INIT

# Check if user wants to produce debugging code
AC_COIN_DEBUG_COMPILE

# Get the name of the C++ compiler and appropriate compiler options
AC_COIN_PROG_CXX


  # Determine the name of the winsock library
case "$CXX" in
  cl* | */cl*)
    wsock32=wsock32.lib ;;
  *)
    wsock32="-L/lib -L/mingw/lib -lwsock32" ;;
esac
  
 AM_CONDITIONAL(USEWSOCKLIB, test $win_sock = yes)
 AM_CONDITIONAL(USEMULTIPLYDEFINED, test $mac_osx = yes)
 
 AC_SUBST(WINSOCKLIB)
 
 WINSOCKLIB="$wsock32"

# Initialize automake and libtool
AC_COIN_INIT_AUTO_TOOLS
coin_opt_cxxflags="-O3"
#############################################################################
#                     Parser stuff                         #
#############################################################################
AC_PROG_YACC


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
AC_COIN_HAS_PROJECT(cppad)

#############################
AC_COIN_HAS_ASL

#############################################################################
#                             Other dependencies                            #

# Check which third party solvers are available ToDo!
AC_COIN_HAS_USER_LIBRARY([Cplex],[CPX],[cplex.h],[CPXgetstat])
AC_COIN_HAS_USER_LIBRARY([Glpk],[GLPK],[glpk.h],[])
AC_COIN_HAS_USER_LIBRARY([Lindo],[LINDO],[lindo.h],[])
AC_COIN_HAS_USER_LIBRARY([Ipopt],[IPOPT],[IpoptConfig.h],[])
AC_COIN_HAS_USER_LIBRARY([Knitro],[KNITRO],[knitro.h],[])



#############################################################################
# Define the root of the OS project###
#############################################################################

AC_SUBST(OSROOT_DIR)
OSROOT_DIR=`pwd`
AC_DEFINE_UNQUOTED([OSROOT_DIR], ["$OSROOT_DIR"],
    [Define the path to the OS root])


##############################################################################
#                   VPATH links for example input files                      #
##############################################################################

# In case this is a VPATH configuration we need to make sure that the
# input files for the examples are available in the VPATH directory.
##
## osil test files
##
AC_COIN_VPATH_LINK(data/parincLinear.osil)
AC_COIN_VPATH_LINK(data/parincQuadratic.osil)
AC_COIN_VPATH_LINK(data/HS071_NLP.osil)
AC_COIN_VPATH_LINK(data/rosenbrockmod.osil)
AC_COIN_VPATH_LINK(data/avion2.osil)
AC_COIN_VPATH_LINK(data/lindoapiaddins.osil)
AC_COIN_VPATH_LINK(data/volumeTest.osil)
AC_COIN_VPATH_LINK(data/p0033.osil)
AC_COIN_VPATH_LINK(data/CppADTestLag.osil)
AC_COIN_VPATH_LINK(data/testOperators.osil)
AC_COIN_VPATH_LINK(data/wayneQuadratic.osil)
AC_COIN_VPATH_LINK(data/testCallBack.osil)
AC_COIN_VPATH_LINK(data/testCallBackRowMajor.osil)
##
## osol test files
##
AC_COIN_VPATH_LINK(data/remotegsbkip.osol)
AC_COIN_VPATH_LINK(data/remoteosil.osol)
AC_COIN_VPATH_LINK(data/retrieve.osol)
AC_COIN_VPATH_LINK(data/send.osol)
AC_COIN_VPATH_LINK(data/demo.osol)
AC_COIN_VPATH_LINK(data/sendWithJobID.osol)
AC_COIN_VPATH_LINK(data/kill.osol)
AC_COIN_VPATH_LINK(data/remoteSolve1.osol)
AC_COIN_VPATH_LINK(data/remoteSolve2.osol)
AC_COIN_VPATH_LINK(data/remoteSolve3.osol)
AC_COIN_VPATH_LINK(data/demopassword.osol)
AC_COIN_VPATH_LINK(data/demopasswordjobID.osol)
##
## ospl test files
##
AC_COIN_VPATH_LINK(data/demo.ospl)
##
## osrl test files
##
AC_COIN_VPATH_LINK(data/parincLinear.osrl)
AC_COIN_VPATH_LINK(data/reducedcost.osrl)
AC_COIN_VPATH_LINK(data/rosenbrockmod.osrl)
##
## configure test files
##
AC_COIN_VPATH_LINK(data/testRemoteKnock.config)
AC_COIN_VPATH_LINK(data/testRemotegetJobID.config)
AC_COIN_VPATH_LINK(data/testremoteRetrieve.config)
AC_COIN_VPATH_LINK(data/testremoteSend.config)
AC_COIN_VPATH_LINK(data/testmps.config)
AC_COIN_VPATH_LINK(data/testnl.config)
AC_COIN_VPATH_LINK(data/testlocalclp.config)
AC_COIN_VPATH_LINK(data/testlocalosol.config)
AC_COIN_VPATH_LINK(data/kill.config)
AC_COIN_VPATH_LINK(data/testlocal.config)
AC_COIN_VPATH_LINK(data/testremote.config)
AC_COIN_VPATH_LINK(data/testremoteBIG.config)
##
## ampl test files
##
AC_COIN_VPATH_LINK(data/hs71.nl)
AC_COIN_VPATH_LINK(data/parinclinear.nl)
AC_COIN_VPATH_LINK(data/parincnonlinear.nl)
##
## mps test files
##
AC_COIN_VPATH_LINK(data/parinc.mps)
##
## MATLAB test files
##
AC_COIN_VPATH_LINK(data/markowitz.m)
AC_COIN_VPATH_LINK(data/parincLinear.m)
AC_COIN_VPATH_LINK(data/template.m)
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
          examples/Makefile
          examples/instanceGenerator/Makefile
          examples/amplClient/Makefile
          examples/osTestCode/Makefile
          examples/CppAD/Makefile
          examples/fileUpload/Makefile
          os_addlibs.txt])

# Here put the location and name of the configuration header file
AC_CONFIG_HEADER([inc/config_os.h])

# Finally, we let configure write all the output...
AC_COIN_FINALIZE
