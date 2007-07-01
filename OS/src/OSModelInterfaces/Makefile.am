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

# List all source files for this library, including headers
libOSModelInterfaces_la_SOURCES = \
	OSMatlab.cpp \
	OSMatlab.h \
	OSmps2osil.cpp \
	OSmps2osil.h 

if COIN_HAS_ASL
libOSModelInterfaces_la_SOURCES += OSnl2osil.cpp \
				OSnl2osil.h 
endif

# This is for libtool (on Windows)
libOSModelInterfaces_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/inc` \
	-I`$(CYGPATH_W) $(COINUTILSOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(CBCSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CBCSRCDIR)/inc` \
	-I`$(CYGPATH_W) $(CBCOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(CLPSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CLPSRCDIR)/inc` \
	-I`$(CYGPATH_W) $(CLPOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/inc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCbc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiClp` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)/..` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)/..` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSAgent`  \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces`  \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSSolverInterfaces`	\
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` 


if COIN_HAS_ASL
AM_CPPFLAGS += 	$(ASL_CPPFLAGS)
endif


if COIN_HAS_CPX
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(CPXINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCpx`
endif


if COIN_HAS_GLPK
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(GLPKINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiGlpk`
endif

if COIN_HAS_DYLP
  AM_CPPFLAGS += \
    -I`$(CYGPATH_W) $(DYLPOBJDIR)/inc` \
    -I`$(CYGPATH_W) $(DYLPSRCDIR)/src/Dylp` \
    -I`$(CYGPATH_W) $(DYLPSRCDIR)/src/DylpStdLib` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiDylp` 
endif


if COIN_HAS_SYMPHONY
  AM_CPPFLAGS += \
    -I`$(CYGPATH_W) $(SYMPHONYSRCDIR)/include` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiSym` 
endif

if COIN_HAS_VOL
  AM_CPPFLAGS += \
    -I`$(CYGPATH_W) $(VOLSRCDIR)/include` \
    -I`$(CYGPATH_W) $(VOLSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiVol`
endif


if COIN_HAS_LINDO
  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(LINDOINCDIR)` 
endif

if COIN_HAS_KNITRO
  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(KNITROINCDIR)` 
endif

if COIN_HAS_IPOPT
  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(IPOPTINCDIR)` 
endif


# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'install'
include_HEADERS = \
	../../inc/config_os.h \
	 OSmps2osil.h \
	 OSMatlab.h

if COIN_HAS_ASL
include_HEADERS += OSnl2osil.h 
endif



