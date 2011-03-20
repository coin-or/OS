# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 806 2006-06-12 01:47:32Z andreasw $ 

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                          unitTest  program                           #
########################################################################

# Name of the executable compiled in this directory.  We want it to be
# installed in the 'bin' directory
noinst_PROGRAMS = unitTest

# List all source files for this executable, including headers
unitTest_SOURCES = unitTest.cpp 

# List all additionally required libraries
unitTest_LDADD =  ../src/libOS.la $(OSLIB_LIBS)
unitTest_DEPENDENCIES =  ../src/libOS.la $(OSLIB_DEPENDENCIES)

# The -rpath flag is used by libtool to make sure that the shared
# library is found (in the lib install directory) when we are using dynamic
# libraries.
unitTest_LDFLAGS = -rpath $(libdir)/coin

########################################################################
#                            Additional flags                          #
########################################################################

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = $(OSLIB_CFLAGS) \
	-I`$(CYGPATH_W) $(srcdir)/../src` \
	-I`$(CYGPATH_W) $(srcdir)/../src/OSAgent` \
	-I`$(CYGPATH_W) $(srcdir)/../src/OSParsers` \
	-I`$(CYGPATH_W) $(srcdir)/../src/OSUtils` \
	-I`$(CYGPATH_W) $(srcdir)/../src/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/../src/OSModelInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/../src/OSCommonInterfaces` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)`

# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

DISTCLEANFILES = ipopt.out

test: unitTest$(EXEEXT)
	./unitTest$(EXEEXT)

alltests: unitTest$(EXEEXT)
	./unitTest$(EXEEXT) nb

.PHONY: test
