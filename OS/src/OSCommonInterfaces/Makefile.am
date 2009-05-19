# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 506 2006-06-01 20:11:24Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSCommonInterfaces                           #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
noinst_LTLIBRARIES = libOSCommonInterfaces.la

# List all source files for this library, including headers
libOSCommonInterfaces_la_SOURCES = \
	OSExpressionTree.cpp \
	OSExpressionTree.h \
	OSInstance.cpp \
	OSInstance.h \
	OSResult.cpp \
	OSResult.h \
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
	OSrLWriter.h \
    OSDefaultSolver.cpp \
	OSDefaultSolver.h 

# This is for libtool (on Windows)
libOSCommonInterfaces_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSSolverInterfaces`	\
	-I`$(CYGPATH_W) $(CPPADSRCDIR)` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSParsers`	\
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/inc` \
	-I`$(CYGPATH_W) $(COINUTILSOBJDIR)/inc` 
	
	
	
if COIN_HAS_ASL
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(OSSRCDIR)/src/ThirdPartyASL` 
  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
endif



AM_CPPFLAGS += -DLindo_Off 

#if USE_DTOA
#AM_CPPFLAGS += -DUSE_DTOA=1
#endif


# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'install/coin'
includecoindir = $(includedir)/coin
includecoin_HEADERS = \
	../../inc/config_os.h \
	OSExpressionTree.h \
	OSInstance.h \
	OSResult.h \
	OSiLReader.h \
	OSiLWriter.h \
	OSnLNode.h \
	OSrLReader.h \
	OSrLWriter.h \
	OSDefaultSolver.h \
        OSoLWriter.h \
        OSoLReader.h \
        OSOption.h 


