# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 506 2006-06-01 20:11:24Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSModelInterfaces                           #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
noinst_LTLIBRARIES = libOSModelInterfaces.la
#lib_LTLIBRARIES = libOSModelInterfaces.la

libOSModelInterfaces_la_LIBADD =
libOSModelInterfaces_la_DEPENDENCIES =

# List all source files for this library, including headers
libOSModelInterfaces_la_SOURCES = \
	OSmps2osil.cpp \
	OSmps2osil.h 

if COIN_HAS_ASL
libOSModelInterfaces_la_SOURCES += \
	OSnl2OS.cpp \
	OSnl2OS.h \
	OSosrl2ampl.cpp \
	OSosrl2ampl.h
endif

# should be another if
#if COIN_HAS_GAMSUTILS
#libOSModelInterfaces_la_SOURCES +=  OSgams2osil.cpp OSosrl2gams.cpp
#libOSModelInterfaces_la_LIBADD  += $(GAMSUTILSOBJDIR)/src/GamsUtils/libGamsUtils.la
#libOSModelInterfaces_la_DEPENDENCIES  += $(GAMSUTILSOBJDIR)/src/GamsUtils/libGamsUtils.la
#endif

# This is for libtool (on Windows)
libOSModelInterfaces_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = \
	-I`$(CYGPATH_W) $(srcdir)/../OSUtils` \
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(srcdir)/../OSCommonInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/../OSUtils` \
	-I`$(CYGPATH_W) $(srcdir)/../OSParsers` \
	$(OSLIB_CFLAGS)

#if COIN_HAS_GAMSUTILS
#  AM_CPPFLAGS += -I`$(CYGPATH_W) $(GAMSUTILSOBJDIR)/inc`
#  AM_CPPFLAGS += -I`$(CYGPATH_W) $(GAMSUTILSSRCDIR)/src`
#  AM_CPPFLAGS += -I`$(CYGPATH_W) $(GAMSUTILSSRCDIR)/src/GamsUtils`
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
	OSmps2osil.h \
	OSnl2OS.h \
	OSosrl2ampl.h
