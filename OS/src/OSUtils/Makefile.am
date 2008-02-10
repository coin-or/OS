# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 506 2006-06-01 20:11:24Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSUtils                           #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
noinst_LTLIBRARIES = libOSUtils.la

# List all source files for this library, including headers
libOSUtils_la_SOURCES = \
		OSBase64.cpp \
		OSBase64.h \
		OSCommonUtil.cpp \
		OSCommonUtil.h \
		OSErrorClass.cpp \
		OSErrorClass.h \
		OSFileUtil.cpp \
		OSFileUtil.h \
		OSMathUtil.cpp \
		OSMathUtil.h \
		OSDataStructures.cpp \
		OSDataStructures.h \
		OSParameters.h \
		OSdtoa.h \
		OSdtoa.cpp

# This is for libtool (on Windows)
libOSUtils_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(srcdir)/..` 


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
	OSBase64.h \
	OSCommonUtil.h \
	OSErrorClass.h \
	OSFileUtil.h \
	OSMathUtil.h \
	OSDataStructures.h \
	OSParameters.h \
	OSdtoa.h

if COIN_HAS_ASL
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(OSSRCDIR)/src/ThirdPartyASL` 
  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
endif

