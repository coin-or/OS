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

# If this project depends on external projects, the Externals file in
# the source root directory contains definition of where to find those
# externals.  The following macro ensures that those externals are
# retrieved by svn if they are not there yet.
AC_COIN_PROJECTDIR_INIT

# Check if user wants to produce debugging code
AC_COIN_DEBUG_COMPILE

# Get the name of the C++ compiler and appropriate compiler options
AC_COIN_PROG_CXX

# Initialize automake and libtool
AC_COIN_INIT_AUTO_TOOLS

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

#############################
AC_COIN_HAS_ASL

#############################################################################
#                             Other dependencies                            #

# Check which third party solvers are available ToDo!
AC_COIN_HAS_USER_LIBRARY([Cplex],[CPX],[cplex.h],[CPXgetstat])
AC_COIN_HAS_USER_LIBRARY([Glpk],[GLPK],[glpk.h],[glp_lpx_simplex])
AC_COIN_HAS_USER_LIBRARY([Lindo],[LINDO],[lindo.h],[LScreateEnv])




#############################################################################

AC_COIN_CHECK_GNU_READLINE

##############################################################################
#                   VPATH links for example input files                      #
##############################################################################

# In case this is a VPATH configuration we need to make sure that the
# input files for the examples are available in the VPATH directory.

#AC_COIN_VPATH_LINK(examples/hello.mps)
#AC_COIN_VPATH_LINK(examples/input.130)

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
          os_addlibs.txt])

# Here put the location and name of the configuration header file
AC_CONFIG_HEADER([inc/config_os.h])

# Finally, we let configure write all the output...
AC_COIN_FINALIZE
