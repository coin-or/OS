# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.

## $Id: Makefile.am 506 2006-06-01 20:11:24Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSUtils                               #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
noinst_LTLIBRARIES = libOSUtils.la

# List all source files for this library, including headers
libOSUtils_la_SOURCES = \
		OSBase64.cpp \
		OSBase64.h \
		OSErrorClass.cpp \
		OSErrorClass.h \
		OSFileUtil.cpp \
		OSFileUtil.h \
		OSReferenced.hpp \
		OSSmartPtr.hpp \
		OSOutput.cpp \
		OSOutput.h \
                OSStringUtil.h\
                OSStringUtil.cpp\
		OSMathUtil.cpp \
		OSMathUtil.h \
		OSDataStructures.h \
		OSParameters.cpp \
		OSParameters.h \
		OSdtoa.h \
		OSdtoa.cpp

# This is for libtool (on Windows)
libOSUtils_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = \
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(srcdir)/../OSCommonInterfaces`   \
	$(OSLIB_CFLAGS)


#if USE_DTOA
#AM_CPPFLAGS += -DUSE_DTOA=1
#endif

# This line is necessary to allow VPATH compilation
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I..

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'include/coin'
includecoindir = $(includedir)/coin
includecoin_HEADERS = \
	OSBase64.h \
	OSErrorClass.h \
	OSFileUtil.h \
	OSReferenced.hpp \
	OSSmartPtr.hpp \
	OSOutput.h \
        OSStringUtil.h\
	OSMathUtil.h \
	OSDataStructures.h \
	OSParameters.h \
	OSdtoa.h
