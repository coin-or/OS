# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.


# Author:  Andreas Waechter           IBM    2006-04-13

########################################################################
#                             libOSCommonInterfaces                           #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
noinst_LTLIBRARIES = libOSCommonInterfaces.la

# List all source files for this library, including headers
libOSCommonInterfaces_la_SOURCES = \
	OSCommandLine.cpp \
	OSCommandLine.h \
	OSCommandLineReader.cpp \
	OSCommandLineReader.h \
	OSExpressionTree.cpp \
	OSExpressionTree.h \
	OSGeneral.cpp \
	OSGeneral.h \
	OSInstance.cpp \
	OSInstance.h \
	OSMatrix.cpp \
	OSMatrix.h \
	OSResult.cpp \
	OSResult.h \
	OSgLWriter.cpp \
	OSgLWriter.h \
	OSiLReader.cpp \
	OSiLReader.h \
	OSiLWriter.cpp \
	OSiLWriter.h \
        OSoLWriter.h \
        OSoLWriter.cpp \
        OSoLReader.h \
        OSoLReader.cpp \
        OSOption.h \
        OSOption.cpp \
	OSnLNode.cpp \
	OSnLNode.h \
	OSrLReader.cpp \
	OSrLReader.h \
	OSrLWriter.cpp \
	OSrLWriter.h

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = \
	-I$(srcdir)/.. \
	-I$(srcdir)/../OSUtils \
	-I$(srcdir)/../OSSolverInterfaces \
	-I$(srcdir)/../OSParsers \
	$(OSLIB_CFLAGS)
	
AM_CPPFLAGS += -DLindo_Off 

#if USE_DTOA
#AM_CPPFLAGS += -DUSE_DTOA=1
#endif


########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'include/coin'
includecoindir = $(includedir)/coin-or
includecoin_HEADERS = \
	OSCommandLine.h \
	OSCommandLineReader.h \
	OSExpressionTree.h \
        OSGeneral.h \
	OSInstance.h \
	OSMatrix.h \
        OSOption.h \
	OSResult.h \
	OSgLWriter.h \
	OSiLReader.h \
	OSiLWriter.h \
	OSnLNode.h \
	OSrLReader.h \
	OSrLWriter.h \
        OSoLWriter.h \
        OSoLReader.h

