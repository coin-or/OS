# Copyright (C) 2006 International Business Machines.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: configure.ac 371 2006-06-14 18:46:19Z andreasw $

# Author:  Andreas Waechter            IBM    2006-04-13

#############################################################################
#                       Names and other basic things                        #
#############################################################################

AC_PREREQ(2.59)

AC_INIT([OS],[trunk],[coin-os@lists.coin-or.org])

AC_COPYRIGHT([
Copyright 2006 International Business Machines and others.
All Rights Reserved.
This file is part of the open source package Coin which is distributed
under the Common Public License.])

AC_REVISION(0.9)

# List one file in the package so that the configure script can test
# whether the package is actually there
AC_CONFIG_SRCDIR(configure.ac)

# Where should everything be installed by default?  Here, we want it
# to be installed directly in 'bin', 'lib', 'include' subdirectories
# of the directory where configure is run.  The default would be
# /usr/local.
AC_PREFIX_DEFAULT([`pwd`])

#############################################################################
#  Do the tests necessary to configure compilers and initialise autotools   #
#############################################################################

AC_COIN_CREATE_LIBTOOL

#############################################################################
#             Check which ThirdParty sources are available                  #
#############################################################################

AC_COIN_MAIN_PACKAGEDIR([ASL],   [ThirdParty],[solvers/asl.h])
AC_COIN_MAIN_PACKAGEDIR([Blas],  [ThirdParty],[daxpy.f])
AC_COIN_MAIN_PACKAGEDIR([Lapack],[ThirdParty],[LAPACK/SRC/dlarf.f])
AC_COIN_MAIN_PACKAGEDIR([Glpk],  [ThirdParty],[glpk/src/glplpx01.c])
AC_COIN_MAIN_PACKAGEDIR([Metis], [ThirdParty],[metis-4.0/Lib/balance.c])
AC_COIN_MAIN_PACKAGEDIR([HSL],   [ThirdParty],[configure.ac])
AC_COIN_MAIN_PACKAGEDIR([Mumps], [ThirdParty],[MUMPS/src/dmumps_part1.F])

#############################################################################
#                  Check which subprojects are there                        #
#############################################################################

AC_COIN_MAIN_PACKAGEDIR(Data/Sample)
AC_COIN_MAIN_PACKAGEDIR(CoinUtils)
AC_COIN_MAIN_PACKAGEDIR(Osi)
AC_COIN_MAIN_PACKAGEDIR(Vol)
AC_COIN_MAIN_PACKAGEDIR(DyLP)
AC_COIN_MAIN_PACKAGEDIR(Clp)
AC_COIN_MAIN_PACKAGEDIR(Cgl)
AC_COIN_MAIN_PACKAGEDIR(SYMPHONY)
AC_COIN_MAIN_PACKAGEDIR(Cbc)
AC_COIN_MAIN_PACKAGEDIR(Ipopt)
AC_COIN_MAIN_PACKAGEDIR(cppad)
AC_COIN_MAIN_PACKAGEDIR(Bonmin)
AC_COIN_MAIN_PACKAGEDIR(Couenne)
AC_COIN_MAIN_PACKAGEDIR(Bcp)
AC_COIN_MAIN_PACKAGEDIR(GamsUtils)
AC_COIN_MAIN_PACKAGEDIR(ApplicationTemplates)
AC_COIN_MAIN_PACKAGEDIR(OS)


##############################################################################
#                   Finishing up by writing all the output                   #
##############################################################################

# Here list all the files that configure should create (except for the
# configuration header file)
AC_CONFIG_FILES([Makefile]) 




##############################################################################
# Finally, we let configure write all the output...
AC_COIN_FINALIZE
