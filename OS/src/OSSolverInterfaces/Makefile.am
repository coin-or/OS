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
	DefaultSolver.cpp \
	DefaultSolver.h \
	CoinSolver.cpp \
	CoinSolver.h 


if COIN_HAS_LINDO
libOSSolverInterfaces_la_SOURCES += 	LindoSolver.cpp \
	LindoSolver.h
endif

# This is for libtool (on Windows)
libOSSolverInterfaces_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CBCSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CLPSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CLPOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCbc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiClp` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces` 
	
	
if COIN_HAS_CPX
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(CPXINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCpx`
endif


if COIN_HAS_GLPK
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(GLPKINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiGlpk`
endif

if COIN_HAS_LINDO
  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(LINDOINCDIR)` 
endif

# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'install'
include_HEADERS = \
	../../inc/config_os.h \
	DefaultSolver.h \
	CoinSolver.h 

if COIN_HAS_LINDO
include_HEADERS += LindoSolver.h
endif


