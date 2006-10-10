# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 806 2006-06-12 01:47:32Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign


########################################################################
#                         CppADTest Example  program                               #
########################################################################

# Name of the executable compiled in this directory.  We want it to be
# installed in the 'bin' directory
noinst_PROGRAMS = CppADTest

# List all source files for this executable, including headers
CppADTest_SOURCES = CppADTest.cpp 

# List all additionally required COIN and OSlibraries
CppADTest_LDADD =  \
	$(OSOBJDIR)/src/libOS.la \
	$(OSIOBJDIR)/src/OsiCbc/libOsiCbc.la \
	$(OSIOBJDIR)/src/OsiClp/libOsiClp.la \
	$(CBCOBJDIR)/src/libCbc.la \
	$(CGLOBJDIR)/src/libCgl.la \
	$(OSIOBJDIR)/src/libOsi.la \
	$(CLPOBJDIR)/src/libClp.la \
	$(COINUTILSOBJDIR)/src/libCoinUtils.la 


# Now add the include paths for compilation

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/inc` \
	-I`$(CYGPATH_W) $(CBCSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CBCSRCDIR)/inc` \
	-I`$(CYGPATH_W) $(CLPSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CLPSRCDIR)/inc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/inc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCbc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiClp` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSAgent` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSParsers` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSModelInterfaces` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)/..` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces` 


# Here we add additional libraries
# Kipp add the others here
LIBS += $(ADDLIBS) `cat $(COINUTILSOBJDIR)/coinutils_addlibs.txt`
LIBS  += `cat $(OSOBJDIR)/os_addlibs.txt`



if COIN_HAS_CPX
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(CPXINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCpx`
  	CppADTest_LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
endif


if COIN_HAS_GLPK
  AM_CPPFLAGS += \
    -I`$(CYGPATH_W) $(GLPKINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiGlpk`
     CppADTest_LDADD += $(OSIOBJDIR)/src/OsiGlpk/libOsiGlpk.la
endif

if COIN_HAS_LINDO
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(LINDOINCDIR)` 
  CppADTest_LDADD += $(LINDOLIB)
endif




# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

# Finally, the -rpath flag is used by libtool to make sure that the shared
# library is found (in the lib install directory) when we are using dynamic
# libraries.
CppADTest_LDFLAGS = -rpath $(libdir)








