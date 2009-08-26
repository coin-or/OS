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
libOSModelInterfaces_la_SOURCES +=  OSnl2osil.cpp \
	 OSnl2osil.h
endif

# should be another if
if COIN_HAS_GAMSUTILS
if COIN_HAS_GAMSIO
libOSModelInterfaces_la_SOURCES +=  OSgams2osil.cpp OSosrl2gams.cpp
libOSModelInterfaces_la_LIBADD  += $(GAMSUTILSOBJDIR)/src/GamsUtils/libGamsUtils.la
libOSModelInterfaces_la_DEPENDENCIES  += $(GAMSUTILSOBJDIR)/src/GamsUtils/libGamsUtils.la
endif
endif

# This is for libtool (on Windows)
libOSModelInterfaces_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces`  \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils`  \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSParsers` \
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(COINUTILSOBJDIR)/inc`







if COIN_HAS_ASL
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(OSSRCDIR)/src/ThirdPartyASL` 
  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
endif

if COIN_HAS_GAMSUTILS
if COIN_HAS_GAMSIO
  AM_CPPFLAGS += $(GAMSIO_CPPFLAGS)
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(GAMSUTILSOBJDIR)/inc`
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(GAMSUTILSSRCDIR)/src`
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(GAMSUTILSSRCDIR)/src/GamsUtils`
endif
endif

if COIN_HAS_CPPAD
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(CPPADSRCDIR)` 
  AM_CPPFLAGS += $(CPPAD_CPPFLAGS) 
endif


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
	 OSmps2osil.h \
	 OSnl2osil.h





