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
		OSOptionsStruc.h \
		OSParseosil.cpp \
		OSParseosil.tab.cpp \
		OSParseosil.tab.hpp \
		OSParseosol.cpp \
		OSParseosol.tab.cpp \
		OSParseosol.tab.hpp \
		OSParseosrl.cpp \
		OSParseosrl.tab.cpp \
		OSParseosrl.tab.hpp \
		OSParseosss.cpp	\
		OSgLParserData.h \
		OSgLParserData.cpp \
		OSiLParserData.h \
		OSiLParserData.cpp \
		OSrLParserData.h \
		OSrLParserData.cpp \
                OSoLParserData.h \
                OSoLParserData.cpp
		

# This is for libtool (on Windows)
libOSParsers_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(srcdir)/../OSUtils` \
	-I`$(CYGPATH_W) $(srcdir)/../OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/../OSCommonInterfaces` 
	
	
if COIN_HAS_ASL
#  AM_CPPFLAGS += -I`$(CYGPATH_W) $(OSSRCDIR)/src/ThirdPartyASL` 
#  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
AM_CPPFLAGS += $(ASL_CFLAGS) 
endif


if COIN_HAS_CPPAD
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(CPPADSRCDIR)` 
  AM_CPPFLAGS += $(CPPAD_CPPFLAGS) 
endif

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
	OSOptionsStruc.h \
	OSParseosil.tab.hpp \
	OSParseosrl.tab.hpp \
        OSParseosol.tab.hpp \
	OSgLParserData.h \
	OSiLParserData.h \
	OSrLParserData.h \
        OSoLParserData.h


