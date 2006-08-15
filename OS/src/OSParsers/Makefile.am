# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 506 2006-06-01 20:11:24Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSParsers                         #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
noinst_LTLIBRARIES = libOSParsers.la

# List all source files for this library, including headers
libOSParsers_la_SOURCES = \
		externalvars.h \
		lexyaccparser.h \
		osilparservariables.h \
		osrlparservariables.h \
		osssparservariables.h \
		parseosil.cpp \
		parseosil.tab.cpp \
		parseosil.tab.cpp.h \
		parseosol.cpp \
		parseosrl.cpp \
		parseosrl.tab.cpp \
		parseosrl.tab.cpp.h \
		parseosss.cpp			

# This is for libtool (on Windows)
libOSParsers_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces` 

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
	externalvars.h \
	lexyaccparser.h \
	osilparservariables.h \
	osrlparservariables.h \
	osssparservariables.h \
	parseosil.tab.hpp \
	parseosrl.tab.hpp 


