# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 756 2006-06-26 19:43:41Z ladanyi $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign


########################################################################
#                           libOS  -- Optimization Services Library    #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
lib_LTLIBRARIES = libOS.la

# List all source files for this library, including headers
libOS_la_SOURCES = 

# This is for libtool (on Windows)
libOS_la_LDFLAGS = $(LT_LDFLAGS)


# We want to have all the OS objects in this library
libOS_la_LIBADD = ./OSUtils/libOSUtils.la \
		./OSCommonInterfaces/libOSCommonInterfaces.la \
		./OSAgent/libOSAgent.la \
		./OSModelInterfaces/libOSModelInterfaces.la \
		./OSParsers/libOSParsers.la \
		./OSSolverInterfaces/libOSSolverInterfaces.la 
# Since automake is not doing this on its own, we need to declare the
# dependencies to the subdirectory libraries here
libOS_la_DEPENDENCIES = $(libOS_la_LIBADD)



# Now we check into which directories to recurse, and which subdirectory
# libraries to include
SUBDIRS =
  SUBDIRS += OSUtils
  SUBDIRS += OSAgent
  SUBDIRS += OSCommonInterfaces
  SUBDIRS += OSModelInterfaces
  SUBDIRS += OSParsers
  SUBDIRS += OSSolverInterfaces




########################################################################
#                    OSSolverService program                               #
########################################################################

LDADD =
ALLLDADD =
LIBS = 
OSSolverService_DEPENDENCIES =

# Name of the executable compiled in this directory.  We want it to be
# installed in the 'bin' directory
bin_PROGRAMS = OSSolverService

# List all source files for this executable, including headers
OSSolverService_SOURCES = OSSolverService.cpp 


if COIN_HAS_COUENNE
     OSSolverService_SOURCES += $(COUENNESRCDIR)/src/main/BonCouenneInfo.cpp $(COUENNESRCDIR)/src/main/BonCouenneInfo.hpp
endif


# List all additionally required COIN libraries

OSSolverService_LDADD =  \
	libOS.la $(OS_LIBS)
	

#OSSolverService_DEPENDENCIES += libOS.la





if COIN_HAS_COUENNE
OSSolverService_LDADD +=  $(COUENNE_LIBS)
#   OSSolverService_LDADD += $(COUENNEOBJDIR)/src/main/libBonCouenne.la
#   parsingTest_LDADD += $(COUENNEOBJDIR)/src/main/libBonCouenne.la
if COIN_HAS_ASL
#   OSSolverService_LDADD += $(COUENNEOBJDIR)/src/readnl/libCouenneReadnl.la
#   parsingTest_LDADD += $(COUENNEOBJDIR)/src/readnl/libCouenneReadnl.la
endif
#   OSSolverService_LDADD += $(COUENNEOBJDIR)/src/libCouenne.la
#   parsingTest_LDADD += $(COUENNEOBJDIR)/src/libCouenne.la
if COIN_HAS_ASL
#   OSSolverService_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonminampl.la
#   parsingTest_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonminampl.la
endif
endif

if COIN_HAS_BONMIN
OSSolverService_LDADD +=  $(BONMIN_LIBS)
#   OSSolverService_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonmin.la 
#   parsingTest_LDADD += $(BONMINOBJDIR)/src/CbcBonmin/libbonmin.la 
#	$(BONMINOBJDIR)/src/Interfaces/libbonmininterfaces.la 
endif


if COIN_HAS_IPOPT
  OSSolverService_LDADD +=  $(IPOPT_LIBS)
if COIN_HAS_ASL
#      OSSolverService_LDADD += $(IPOPTOBJDIR)/src/Apps/AmplSolver/#libamplinterface.la 
endif
#  OSSolverService_LDADD +=  $(IPOPTOBJDIR)/src/Interfaces/libipopt.la
#  parsingTest_LDADD +=  $(IPOPTOBJDIR)/src/Interfaces/libipopt.la
#  LIBS += `cat $(IPOPTOBJDIR)/src/Interfaces/ipopt_addlibs_cpp.txt`
endif
	
	
OSSolverService_LDADD +=  $(CBC_LIBS)


OSSolverService_LDADD += $(CLP_LIBS) 



if COIN_HAS_SYMPHONY
 OSSolverService_LDADD += $(SYMPHONY_LIBS) 
endif

if COIN_HAS_DYLP
 OSSolverService_LDADD += $(DYLP_LIBS)
endif

if COIN_HAS_VOL
 OSSolverService_LDADD += $(VOL_LIBS)
endif

#if COIN_HAS_CPX
# OSSolverService_LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
# parsingTest_LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
#endif

 OSSolverService_LDADD += $(CBC_LIBS)


 OSSolverService_LDADD +=  $(CGL_LIBS)


if COIN_HAS_GLPK
OSSolverService_LDADD += $(GLPK_LIBS)
endif

if COIN_HAS_ASL
#  AM_CPPFLAGS += -I`$(CYGPATH_W) $(OSSRCDIR)/src/ThirdPartyASL` 
#  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
  OSSolverService_LDADD += $(ASL_LIBS) 
endif



# The -rpath flag is used by libtool to make sure that the shared
# library is found (in the lib install directory) when we are using dynamic
# libraries.
#unitTest_LDFLAGS = -rpath $(libdir) 



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









# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

ALLLDADD += $(LDADD) 



#OSSolverService_LDADD = $(ALLLDADD) $(ADDLIBS)  
########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'install/coin'
includecoindir = $(includedir)/coin
includecoin_HEADERS = \
	OSConfig.h \
	../inc/config_os.h 

if MSCL_
#   includecoin_HEADERS += $(OSSRCDIR)/../BuildTools/headers/configall_system.h
#   includecoin_HEADERS += $(OSSRCDIR)/../BuildTools/headers/configall_system_msc.h
endif


#############################################################################
# Create the Config.h file that always defines HAVE_CONFIG_H and install it #
#############################################################################

# You only need to adapt the following line
ConfigHeader = OSConfig.h

install-exec-local:
	echo "#ifndef HAVE_CONFIG_H" >bla
	echo "#define HAVE_CONFIG_H" >>bla
	echo "#endif" >> bla
	cat $(srcdir)/$(ConfigHeader) >> bla
	$(install_sh_DATA) bla $(DESTDIR)$(includecoindir)/$(ConfigHeader)
	rm -f bla

uninstall-local:
	rm -f $(DESTDIR)$(includecoindir)/$(ConfigHeader)
