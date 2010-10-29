# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 506 2006-06-01 20:11:24Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSSolverInterfaces                           #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
noinst_LTLIBRARIES = libOSSolverInterfaces.la

# List all source files for this library, including headers
libOSSolverInterfaces_la_SOURCES = \
	OSCoinSolver.cpp \
	OSCoinSolver.h  \
	OSMatlabSolver.cpp \
	OSMatlabSolver.h 


if COIN_HAS_LINDO
libOSSolverInterfaces_la_SOURCES += 	OSLindoSolver.cpp \
	OSLindoSolver.h
endif

if COIN_HAS_IPOPT
libOSSolverInterfaces_la_SOURCES += 	OSIpoptSolver.cpp \
	OSIpoptSolver.h
endif


if COIN_HAS_BONMIN
libOSSolverInterfaces_la_SOURCES += 	OSBonminSolver.cpp \
	OSBonminSolver.h
endif



if COIN_HAS_COUENNE
libOSSolverInterfaces_la_SOURCES += 	OSCouenneSolver.cpp \
	OSCouenneSolver.h
endif




if COIN_HAS_KNITRO
libOSSolverInterfaces_la_SOURCES += 	OSKnitroSolver.cpp \
	OSKnitroSolver.h
endif

# This is for libtool (on Windows)
libOSSolverInterfaces_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)` \
	-I`$(CYGPATH_W) $(srcdir)/../OSCommonInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/../OSParsers` \
	-I`$(CYGPATH_W) $(srcdir)/../OSUtils` \
	-I`$(CYGPATH_W) $(srcdir)/../OSAgent` 
	
	
#	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/inc` \
#	-I`$(CYGPATH_W) $(COINUTILSOBJDIR)/inc` \
#	-I`$(CYGPATH_W) $(CBCSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(CBCSRCDIR)/inc` \
#	-I`$(CYGPATH_W) $(CBCOBJDIR)/inc` \
#	-I`$(CYGPATH_W) $(CLPSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(CLPOBJDIR)/inc` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglClique` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglDuplicateRow` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglFlowCover` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglGomory` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglKnapsackCover` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglSimpleRounding` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglMixedIntegerRounding` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglMixedIntegerRounding2` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglOddHole` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglPreProcess` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglProbing` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglRedSplit` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglTwomir` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglLandP` \
#	-I`$(CYGPATH_W) $(CGLSRCDIR)/src/CglResidualCapacity` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/inc` \
#	-I`$(CYGPATH_W) $(OSIOBJDIR)/inc` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCbc` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiClp` 
 

AM_CPPFLAGS += $(COINDEPEND_CFLAGS) $(COINUTILS_CFLAGS) $(OSI_CFLAGS)   $(CLP_CFLAGS)  $(CGL_CFLAGS) 
	
	
if COIN_HAS_ASL
#  AM_CPPFLAGS += -I`$(CYGPATH_W) $(OSSRCDIR)/src/ThirdPartyASL` 
#  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
AM_CPPFLAGS += $(ASL_CFLAGS)
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
#    -I`$(CYGPATH_W) $(SYMPHONYSRCDIR)/include` \
#    -I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiSym` \
# 	-I`$(CYGPATH_W) $(SYMPHONYOBJDIR)/include`  
AM_CPPFLAGS += $(SYMPHONY_CFLAGS)
endif

if COIN_HAS_VOL
#  AM_CPPFLAGS += \
#    -I`$(CYGPATH_W) $(VOLSRCDIR)/include` \
#    -I`$(CYGPATH_W) $(VOLSRCDIR)/src` \
#	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiVol`
AM_CPPFLAGS += $(VOL_CFLAGS)
endif

if COIN_HAS_LINDO
#  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(LINDOINCDIR)` 
endif

#if COIN_HAS_KNITRO
#  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(KNITROINCDIR)` 
#endif

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
#       -I`$(CYGPATH_W) $(COUENNESRCDIR)/src/expression/operators` \
#        -I`$(CYGPATH_W) $(COUENNESRCDIR)/src/expression/simplify` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/main` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/problem` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/readnl` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/standardize` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src/util` \
#	-I`$(CYGPATH_W) $(COUENNESRCDIR)/src` \
#	-I`$(CYGPATH_W) $(COUENNEOBJDIR)/inc`
AM_CPPFLAGS += $(COUENNE_CFLAGS)
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
	OSCoinSolver.h \
	OSMatlabSolver.h

if COIN_HAS_LINDO
includecoin_HEADERS += OSLindoSolver.h
endif

if COIN_HAS_KNITRO
includecoin_HEADERS += OSKnitroSolver.h
endif

if COIN_HAS_IPOPT
includecoin_HEADERS += OSIpoptSolver.h
endif

if COIN_HAS_BONMIN
includecoin_HEADERS += OSBonminSolver.h
endif

if COIN_HAS_COUENNE
includecoin_HEADERS += OSCouenneSolver.h
endif



