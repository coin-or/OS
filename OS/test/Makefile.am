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
noinst_PROGRAMS = unitTest parsingTest

# List all source files for this executable, including headers
unitTest_SOURCES = unitTest.cpp 

# List all additionally required COIN libraries
unitTest_LDADD =  \
	$(OSOBJDIR)/src/libOS.la 


# List all source files for this executable, including headers
parsingTest_SOURCES = parsingTest.cpp 

# List all additionally required COIN libraries
parsingTest_LDADD =  \
	$(OSOBJDIR)/src/libOS.la $(OS_LIBS)
	
	
	
	
if COIN_HAS_COUENNE
   unitTest_LDADD += $(COUENNEOBJDIR)/src/main/libBonCouenne.la
   parsingTest_LDADD += $(COUENNEOBJDIR)/src/main/libBonCouenne.la
if COIN_HAS_ASL
   unitTest_LDADD += $(COUENNEOBJDIR)/src/readnl/libCouenneReadnl.la
   parsingTest_LDADD += $(COUENNEOBJDIR)/src/readnl/libCouenneReadnl.la
endif
   unitTest_LDADD += $(COUENNEOBJDIR)/src/libCouenne.la
   parsingTest_LDADD += $(COUENNEOBJDIR)/src/libCouenne.la
if COIN_HAS_ASL
   unitTest_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonminampl.la
   parsingTest_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonminampl.la
endif
endif

if COIN_HAS_BONMIN
   unitTest_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonmin.la 
   parsingTest_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonmin.la 
#	$(BONMINOBJDIR)/src/Interfaces/libbonmininterfaces.la 
endif


if COIN_HAS_IPOPT
if COIN_HAS_ASL
#      unitTest_LDADD += $(IPOPTOBJDIR)/src/Apps/AmplSolver/#libamplinterface.la 
endif
  unitTest_LDADD +=  $(IPOPTOBJDIR)/src/Interfaces/libipopt.la
  parsingTest_LDADD +=  $(IPOPTOBJDIR)/src/Interfaces/libipopt.la
  LIBS += `cat $(IPOPTOBJDIR)/src/Interfaces/ipopt_addlibs_cpp.txt`
endif
	
	
unitTest_LDADD +=  $(OSIOBJDIR)/src/OsiCbc/libOsiCbc.la 
parsingTest_LDADD +=  $(OSIOBJDIR)/src/OsiCbc/libOsiCbc.la 


if COIN_HAS_SYMPHONY
 unitTest_LDADD += $(OSIOBJDIR)/src/OsiSym/libOsiSym.la 
 parsingTest_LDADD += $(OSIOBJDIR)/src/OsiSym/libOsiSym.la 
endif

 unitTest_LDADD += $(OSIOBJDIR)/src/OsiClp/libOsiClp.la 
 parsingTest_LDADD += $(OSIOBJDIR)/src/OsiClp/libOsiClp.la 

if COIN_HAS_DYLP
 unitTest_LDADD += $(OSIOBJDIR)/src/OsiDylp/libOsiDylp.la
 parsingTest_LDADD += $(OSIOBJDIR)/src/OsiDylp/libOsiDylp.la  
endif

if COIN_HAS_VOL
 unitTest_LDADD += $(OSIOBJDIR)/src/OsiVol/libOsiVol.la
 parsingTest_LDADD += $(OSIOBJDIR)/src/OsiVol/libOsiVol.la  
endif

if COIN_HAS_CPX
 unitTest_LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
 parsingTest_LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
endif

 unitTest_LDADD += $(CBCOBJDIR)/src/libCbcSolver.la 
 unitTest_LDADD += $(CBCOBJDIR)/src/libCbc.la 
 parsingTest_LDADD += $(CBCOBJDIR)/src/libCbcSolver.la 
 parsingTest_LDADD += $(CBCOBJDIR)/src/libCbc.la 

if COIN_HAS_SYMPHONY
 unitTest_LDADD += $(SYMPHONYOBJDIR)/src/libSym.la
 parsingTest_LDADD += $(SYMPHONYOBJDIR)/src/libSym.la  
endif

 unitTest_LDADD += $(CGLOBJDIR)/src/libCgl.la 
 parsingTest_LDADD += $(CGLOBJDIR)/src/libCgl.la

 unitTest_LDADD += $(OSIOBJDIR)/src/libOsi.la
 parsingTest_LDADD += $(OSIOBJDIR)/src/libOsi.la 

 unitTest_LDADD += $(CLPOBJDIR)/src/libClp.la
 parsingTest_LDADD += $(CLPOBJDIR)/src/libClp.la 

if COIN_HAS_DYLP
 unitTest_LDADD += $(DYLPOBJDIR)/src/Dylp/libDylp.la
 parsingTest_LDADD += $(DYLPOBJDIR)/src/Dylp/libDylp.la 
endif

if COIN_HAS_VOL
 unitTest_LDADD += $(VOLOBJDIR)/src/libVol.la
 parsingTest_LDADD += $(VOLOBJDIR)/src/libVol.la 
endif

if COIN_HAS_GLPK
 unitTest_LDADD += $(OSIOBJDIR)/src/OsiGlpk/libOsiGlpk.la
 unitTest_LDADD += $(GLPKLIB)
 parsingTest_LDADD += $(OSIOBJDIR)/src/OsiGlpk/libOsiGlpk.la
 parsingTest_LDADD += $(GLPKLIB)
endif

unitTest_LDADD += $(COINUTILSOBJDIR)/src/libCoinUtils.la  

parsingTest_LDADD += $(COINUTILSOBJDIR)/src/libCoinUtils.la  

unitTest_LDADD += $(ADDLIBS)
parsingTest_LDADD += $(ADDLIBS) 


# The -rpath flag is used by libtool to make sure that the shared
# library is found (in the lib install directory) when we are using dynamic
# libraries.
unitTest_LDFLAGS = -rpath $(libdir) 




########################################################################
#                            Additional flags                          #
########################################################################


# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(OSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSAgent` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSParsers` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSModelInterfaces` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces` 
#	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(COINUTILSOBJDIR)/inc` \
#	-I`$(CYGPATH_W) $(CBCSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(CBCOBJDIR)/inc` \
#	-I`$(CYGPATH_W) $(CLPSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(CLPOBJDIR)/inc` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(CGLOBJDIR)/inc` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src` \
#	-I`$(CYGPATH_W) $(OSIOBJDIR)/inc` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCbc` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiClp` 

# Here we add additional libraries


AM_CPPFLAGS += $(COINDEPEND_CFLAGS) $(COINUTILS_CFLAGS) $(OSI_CFLAGS)   $(CLP_CFLAGS)  $(CGL_CFLAGS) 



if COIN_HAS_DYLP
#  AM_CPPFLAGS += \
#    -I`$(CYGPATH_W) $(DYLPOBJDIR)/inc` \
#    -I`$(CYGPATH_W) $(DYLPSRCDIR)/src/Dylp` \
#    -I`$(CYGPATH_W) $(DYLPSRCDIR)/src/DylpStdLib` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiDylp`
AM_CPPFLAGS += $(DYLP_CFLAGS)
endif

if COIN_HAS_SYMPHONY
#  AM_CPPFLAGS += \
#   -I`$(CYGPATH_W) $(SYMPHONYSRCDIR)/include` \
#    -I`$(CYGPATH_W) $(SYMPHONYOBJDIR)/include` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiSym`
AM_CPPFLAGS += $(SYMPHONY_CFLAGS)
endif


if COIN_HAS_VOL
#  AM_CPPFLAGS += \
#    -I`$(CYGPATH_W) $(VOLSRCDIR)/include` \
# -I`$(CYGPATH_W) $(VOLOBJDIR)/include` \
#    -I`$(CYGPATH_W) $(VOLSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiVol`
AM_CPPFLAGS += $(VOL_CFLAGS)
endif



if COIN_HAS_CPX
#  AM_CPPFLAGS += \
#	-I`$(CYGPATH_W) $(CPXINCDIR)` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCpx`
AM_CPPFLAGS += $(CPX_CFLAGS)
endif




if COIN_HAS_GLPK
#  AM_CPPFLAGS += \
#	-I`$(CYGPATH_W) $(GLPKINCDIR)` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiGlpk`
AM_CPPFLAGS += $(GLPK_CFLAGS)
endif

 

if COIN_HAS_LINDO
#  AM_CPPFLAGS += -I`$(CYGPATH_W) $(LINDOINCDIR)` 
#  LDADD += $(LINDOLIB)
endif

if COIN_HAS_IPOPT
#  AM_CPPFLAGS += \
#	-I`$(CYGPATH_W) $(IPOPTSRCDIR)/src/Interfaces` \
#	-I`$(CYGPATH_W) $(IPOPTSRCDIR)/src/LinAlg` \
#	-I`$(CYGPATH_W) $(IPOPTSRCDIR)/src/Common` \
#	-I`$(CYGPATH_W) $(IPOPTOBJDIR)/inc`
AM_CPPFLAGS += $(IPOPT_CFLAGS)
endif


if COIN_HAS_BONMIN
#  AM_CPPFLAGS += \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Interfaces` \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Interfaces/Ampl` \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Interfaces/Ipopt` \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Interfaces/Filter` \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms` \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms/OaGenerators` \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms/QuadCuts` \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms/Ampl` \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/Algorithms/Branching` \
#	-I`$(CYGPATH_W) $(BONMINSRCDIR)/src/CbcBonmin` \
#	-I`$(CYGPATH_W) $(BONMINOBJDIR)/inc`
AM_CPPFLAGS += $(BONMIN_CFLAGS)
endif


if COIN_HAS_COUENNE
#  AM_CPPFLAGS += \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/bound_tightening` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/branch` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/convex` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/disjunctive` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/expression` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/main` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/problem` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/readnl` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/standardize` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/util` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src` \
#	-I`$(CYGPATH_W) $(COUENNEOBJDIR)/inc`
AM_CPPFLAGS += $(COUENNE_CFLAGS)
endif


if COIN_HAS_ASL
#  AM_CPPFLAGS += -I`$(CYGPATH_W) $(OSSRCDIR)/src/ThirdPartyASL` 
#  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
AM_CPPFLAGS += $(ASL_CFLAGS) 
  unitTest_LDADD += $(ASLLIB) 
  parsingTest_LDADD += $(ASLLIB) 
endif


# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

DISTCLEANFILES = ipopt.out



test: unitTest$(EXEEXT)
	./unitTest$(EXEEXT)

.PHONY: test






