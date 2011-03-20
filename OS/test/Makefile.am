# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 806 2006-06-12 01:47:32Z andreasw $ 

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                          unitTest  program                           #
########################################################################

# Name of the executable compiled in this directory.  We do not want it
# to be installed.
noinst_PROGRAMS = unitTest

# List all source files for this executable, including headers
unitTest_SOURCES = unitTest.cpp 

# List all additionally required libraries
unitTest_LDADD =  ../src/libOS.la $(OSLIB_LIBS)
unitTest_DEPENDENCIES =  ../src/libOS.la $(OSLIB_DEPENDENCIES)

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
	-I`$(CYGPATH_W) $(srcdir)/../src/OSCommonInterfaces`

# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

DISTCLEANFILES = ipopt.out bonmin.out

test: unitTest$(EXEEXT)
	./unitTest$(EXEEXT)

alltests: unitTest$(EXEEXT)
	./unitTest$(EXEEXT) nb

.PHONY: test
