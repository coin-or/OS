# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 806 2006-06-12 01:47:32Z andreasw $ 

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign


########################################################################
#                          unitTest  program                               #
########################################################################

# Name of the executable compiled in this directory.  We want it to be
# installed in the 'bin' directory
noinst_PROGRAMS = unitTest

# List all source files for this executable, including headers
unitTest_SOURCES = unitTest.cpp 

# List all additionally required COIN libraries
unitTest_LDADD =  \
	$(OSOBJDIR)/src/libOS.la \
	$(OSIOBJDIR)/src/OsiCbc/libOsiCbc.la 
	
if COIN_HAS_SYMPHONY
 unitTest_LDADD += $(OSIOBJDIR)/src/OsiSym/libOsiSym.la 
endif

 unitTest_LDADD += $(OSIOBJDIR)/src/OsiClp/libOsiClp.la 
	
if COIN_HAS_DYLP
 unitTest_LDADD += $(OSIOBJDIR)/src/OsiDylp/libOsiDylp.la 
endif

if COIN_HAS_VOL
 unitTest_LDADD += $(OSIOBJDIR)/src/OsiVol/libOsiVol.la 
endif

 unitTest_LDADD += $(CBCOBJDIR)/src/libCbc.la 
	
if COIN_HAS_SYMPHONY
 unitTest_LDADD += $(SYMPHONYOBJDIR)/src/libSym.la 
endif

 unitTest_LDADD += $(CGLOBJDIR)/src/libCgl.la 
	
 unitTest_LDADD += $(OSIOBJDIR)/src/libOsi.la 
	
 unitTest_LDADD += $(CLPOBJDIR)/src/libClp.la 
	
if COIN_HAS_DYLP
 unitTest_LDADD += $(DYLPOBJDIR)/src/Dylp/libDylp.la 
endif

if COIN_HAS_VOL
 unitTest_LDADD += $(VOLOBJDIR)/src/libVol.la 
endif

if COIN_HAS_GLPK
 unitTest_LDADD += $(OSIOBJDIR)/src/OsiGlpk/libOsiGlpk.la
 unitTest_LDADD += $(GLPKLIB)
endif

 unitTest_LDADD += $(COINUTILSOBJDIR)/src/libCoinUtils.la  
	
#unitTest_LDADD += $(ADDLIBS) 

if USEWSOCKLIB
  unitTest_LDADD += $(WINSOCKLIB)
endif








# Now add the include paths for compilation

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
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
	-I`$(CYGPATH_W) $(OSIOBJDIR)/inc` \
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
#LIBS += $(ADDLIBS) `cat $(COINUTILSOBJDIR)/coinutils_addlibs.txt`
#LIBS  += `cat $(OSOBJDIR)/os_addlibs.txt`

if COIN_HAS_IPOPT
#LIBS += -l$(F77)
endif

# The -rpath flag is used by libtool to make sure that the shared
# library is found (in the lib install directory) when we are using dynamic
# libraries.
unitTest_LDFLAGS = -rpath $(libdir) 



if COIN_HAS_DYLP
  AM_CPPFLAGS += \
  	-I`$(CYGPATH_W) $(DYLPOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(DYLPSRCDIR)/inc` \
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


if COIN_HAS_CPX
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(CPXINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCpx`
  	unitTest_LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
endif


if COIN_HAS_GLPK
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(GLPKINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiGlpk`
endif

if COIN_HAS_LINDO
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(LINDOINCDIR)` 
  unitTest_LDADD += $(LINDOLIB)
endif

if COIN_HAS_IPOPT
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(IPOPTINCDIR)` 
  unitTest_LDADD += $(IPOPTLIB) 
endif


if COIN_HAS_KNITRO
  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(KNITROINCDIR)` 
  unitTest_LDADD += $(KNITROLIB)
if USEMULTIPLYDEFINED
  unitTest_LDFLAGS +=  -multiply_defined suppress  
endif
endif


if COIN_HAS_ASL
  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
  unitTest_LDADD += $(ASLLIB) 
endif


# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc





test: unitTest$(EXEEXT)
	./unitTest$(EXEEXT)

.PHONY: test






