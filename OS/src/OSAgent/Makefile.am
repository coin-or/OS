# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 719 2006-06-01 20:11:40Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSAgent                               #
########################################################################

# Name of the library compiled in this directory.
noinst_LTLIBRARIES = libOSAgent.la

# List all source files for this library, including headers
libOSAgent_la_SOURCES = \
	OShL.cpp OShL.h OSSolverAgent.cpp \
	OSSolverAgent.h OSWSUtil.cpp OSWSUtil.h

# This is for libtool (on Windows)
libOSAgent_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows.
# "top_srcdir" refers to the basic directory for the main package that is
# being compiled.
AM_CPPFLAGS = \
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(CLPSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/inc` \
	-I`$(CYGPATH_W) $(COINUTILSOBJDIR)/inc`
	
	
#AM_CPPFLAGS += -I`$(CYGPATH_W) /usr/include/w32api` \
#  				  -I ../include \
#  				  -I ../PlatformSDK/include

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
	OShL.h OSSolverAgent.h OSWSUtil.h
