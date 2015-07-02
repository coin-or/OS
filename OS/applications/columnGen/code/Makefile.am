# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.

## $Id: Makefile.am 806 2006-06-12 01:47:32Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign


########################################################################
#                          OSColGenMain program                        #
########################################################################

# Name of the executable compiled in this directory. 
noinst_PROGRAMS = OSColGenMain

# List all source files for this executable, including headers
OSColGenMain_SOURCES = OSColGenMain.cpp OSColGenApp.cpp OSColGenApp.h 
OSColGenMain_SOURCES += OSNode.cpp OSNode.h OSDecompParam.h
OSColGenMain_SOURCES += OSDecompSolver.cpp OSDecompSolver.h
OSColGenMain_SOURCES += OSDecompSolverFactory.cpp OSDecompSolverFactory.h OSDecompFactoryInitializer.h
OSColGenMain_SOURCES += OSBearcatSolverXij.cpp  OSBearcatSolverXij.h



# List all additionally required COIN libraries

	
OSColGenMain_LDADD = ../../../src/libOS.la $(OSLIB_LIBS)

OSColGenMain_DEPENDENCIES = ../../../src/libOS.la $(OSLIB_DEPENDENCIES)

# Now add the include paths for compilation

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = \
	-I`$(CYGPATH_W) $(top_srcdir)/src` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSAgent` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSParsers` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSUtils` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSModelInterfaces` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSCommonInterfaces` \
	$(OSLIB_CFLAGS)
	

# This line is necessary to allow VPATH compilation
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/src
