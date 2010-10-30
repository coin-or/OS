# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 806 2006-06-12 01:47:32Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign


########################################################################
#                          OSColGenMain program                               #
########################################################################

# Name of the executable compiled in this directory. 
noinst_PROGRAMS = OSColGenMain

# List all source files for this executable, including headers
OSColGenMain_SOURCES = OSColGenMain.cpp OSColGenApp.cpp OSColGenApp.h OSRouteSolver.cpp OSRouteSolver.h 


# List all additionally required COIN libraries

OSColGenMain_LDADD =  \
	../../../src/libOS.la $(OS_LIBS)
	


if COIN_HAS_COUENNE
OSColGenMain_LDADD +=  $(COUENNE_LIBS)
#   OSColGenMain_LDADD += $(COUENNEOBJDIR)/src/main/libBonCouenne.la
#   parsingTest_LDADD += $(COUENNEOBJDIR)/src/main/libBonCouenne.la
if COIN_HAS_ASL
#   OSColGenMain_LDADD += $(COUENNEOBJDIR)/src/readnl/libCouenneReadnl.la
#   parsingTest_LDADD += $(COUENNEOBJDIR)/src/readnl/libCouenneReadnl.la
endif
#   OSColGenMain_LDADD += $(COUENNEOBJDIR)/src/libCouenne.la
#   parsingTest_LDADD += $(COUENNEOBJDIR)/src/libCouenne.la
if COIN_HAS_ASL
#   OSColGenMain_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonminampl.la
#   parsingTest_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonminampl.la
endif
endif

if COIN_HAS_BONMIN
OSColGenMain_LDADD +=  $(BONMIN_LIBS)
#   OSColGenMain_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonmin.la 
#   parsingTest_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonmin.la 
#	$(BONMINOBJDIR)/src/Interfaces/libbonmininterfaces.la 
endif


if COIN_HAS_IPOPT
  OSColGenMain_LDADD +=  $(IPOPT_LIBS)
if COIN_HAS_ASL
#      OSColGenMain_LDADD += $(IPOPTOBJDIR)/src/Apps/AmplSolver/#libamplinterface.la 
endif
#  OSColGenMain_LDADD +=  $(IPOPTOBJDIR)/src/Interfaces/libipopt.la
#  parsingTest_LDADD +=  $(IPOPTOBJDIR)/src/Interfaces/libipopt.la
#  LIBS += `cat $(IPOPTOBJDIR)/src/Interfaces/ipopt_addlibs_cpp.txt`
endif
	
	
OSColGenMain_LDADD +=  $(CBC_LIBS)


OSColGenMain_LDADD += $(CLP_LIBS) 



if COIN_HAS_SYMPHONY
 OSColGenMain_LDADD += $(SYMPHONY_LIBS) 
endif

if COIN_HAS_DYLP
 OSColGenMain_LDADD += $(DYLP_LIBS)
endif

if COIN_HAS_VOL
 OSColGenMain_LDADD += $(VOL_LIBS)
endif

#if COIN_HAS_CPX
# OSColGenMain_LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
# parsingTest_LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
#endif

 OSColGenMain_LDADD += $(CBC_LIBS)


 OSColGenMain_LDADD +=  $(CGL_LIBS)


if COIN_HAS_GLPK
OSColGenMain_LDADD += $(GLPK_LIBS)
endif

if COIN_HAS_ASL
#  AM_CPPFLAGS += -I`$(CYGPATH_W) $(OSSRCDIR)/src/ThirdPartyASL` 
#  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
  OSColGenMain_LDADD += $(ASL_LIBS) 
endif



# Now add the include paths for compilation

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows



########################################################################
#                            Additional flags                          #
########################################################################


# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(top_srcdir)/src` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSAgent` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSParsers` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSUtils` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSModelInterfaces` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSCommonInterfaces` 
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


AM_CPPFLAGS += $(COINDEPEND_CFLAGS) $(COINUTILS_CFLAGS) $(OSI_CFLAGS) $(CLP_CFLAGS)  $(CGL_CFLAGS) $(CBC_CFLAGS) 



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



#if COIN_HAS_CPX
#  AM_CPPFLAGS += \
#	-I`$(CYGPATH_W) $(CPXINCDIR)` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCpx`
#AM_CPPFLAGS += $(CPX_CFLAGS)
#endif




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
endif




# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc










