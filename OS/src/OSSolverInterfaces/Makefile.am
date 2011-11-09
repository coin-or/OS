# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 506 2006-06-01 20:11:24Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSSolverInterfaces                           #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
noinst_LTLIBRARIES = libOSSolverInterfaces.la

# List all source files for this library, including headers
libOSSolverInterfaces_la_SOURCES = \
	OSCoinSolver.cpp \
	OSCoinSolver.h  \
	OSMatlabSolver.cpp \
	OSMatlabSolver.h \
	OSRunSolver.cpp \
	OSRunSolver.h 


if COIN_HAS_LINDO
libOSSolverInterfaces_la_SOURCES += 	OSLindoSolver.cpp \
	OSLindoSolver.h
endif

if COIN_HAS_IPOPT
libOSSolverInterfaces_la_SOURCES += 	OSIpoptSolver.cpp \
	OSIpoptSolver.h
endif


if COIN_HAS_BONMIN
libOSSolverInterfaces_la_SOURCES += 	OSBonminSolver.cpp \
	OSBonminSolver.h
endif



if COIN_HAS_COUENNE
libOSSolverInterfaces_la_SOURCES += 	OSCouenneSolver.cpp \
	OSCouenneSolver.h
endif




if COIN_HAS_KNITRO
libOSSolverInterfaces_la_SOURCES += 	OSKnitroSolver.cpp \
	OSKnitroSolver.h
endif

# This is for libtool (on Windows)
libOSSolverInterfaces_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = \
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(srcdir)/../OSCommonInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/../OSParsers` \
	-I`$(CYGPATH_W) $(srcdir)/../OSUtils` \
	-I`$(CYGPATH_W) $(srcdir)/../OSAgent` \
	$(OSLIB_CFLAGS)
	
if COIN_HAS_LINDO
#  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(LINDOINCDIR)` 
endif

#if COIN_HAS_KNITRO
#  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(KNITROINCDIR)` 
#endif

# This line is necessary to allow VPATH compilation
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I..

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'include/coin'
includecoindir = $(includedir)/coin
includecoin_HEADERS = \
	OSCoinSolver.h \
	OSMatlabSolver.h \
	OSRunSolver.h 

if COIN_HAS_LINDO
includecoin_HEADERS += OSLindoSolver.h
endif

if COIN_HAS_KNITRO
includecoin_HEADERS += OSKnitroSolver.h
endif

if COIN_HAS_IPOPT
includecoin_HEADERS += OSIpoptSolver.h
endif

if COIN_HAS_BONMIN
includecoin_HEADERS += OSBonminSolver.h
endif

if COIN_HAS_COUENNE
includecoin_HEADERS += OSCouenneSolver.h
endif
