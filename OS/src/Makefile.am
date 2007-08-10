# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 756 2006-06-26 19:43:41Z ladanyi $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign


########################################################################
#                           libOS  -- Optimization Services Library                               #
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

# Name of the executable compiled in this directory.  We want it to be
# installed in the 'bin' directory
bin_PROGRAMS = OSSolverService

# List all source files for this executable, including headers
OSSolverService_SOURCES = OSSolverService.cpp 





# List all additionally required COIN libraries

OSSolverService_LDADD =  \
	libOS.la \
	$(OSIOBJDIR)/src/OsiCbc/libOsiCbc.la 

LIBS += `cat $(OSIOBJDIR)/osi_addlibs.txt`

if COIN_HAS_SYMPHONY
 OSSolverService_LDADD += $(OSIOBJDIR)/src/OsiSym/libOsiSym.la 
endif

 OSSolverService_LDADD += $(OSIOBJDIR)/src/OsiClp/libOsiClp.la 

if COIN_HAS_DYLP
 OSSolverService_LDADD += $(OSIOBJDIR)/src/OsiDylp/libOsiDylp.la 
endif

if COIN_HAS_VOL
 OSSolverService_LDADD += $(OSIOBJDIR)/src/OsiVol/libOsiVol.la 
endif

 OSSolverService_LDADD += $(CBCOBJDIR)/src/libCbc.la 
 LIBS += `cat $(CBCOBJDIR)/cbc_addlibs.txt`

if COIN_HAS_SYMPHONY
 OSSolverService_LDADD += $(SYMPHONYOBJDIR)/src/libSym.la 
 LIBS += `cat $(SYMPHONYOBJDIR)/sym_addlibs.txt`
endif

 OSSolverService_LDADD += $(CGLOBJDIR)/src/libCgl.la 
 LIBS += `cat $(CGLOBJDIR)/cgl_addlibs.txt`

 OSSolverService_LDADD += $(OSIOBJDIR)/src/libOsi.la 
 LIBS += `cat $(OSIOBJDIR)/osi_addlibs.txt`

 OSSolverService_LDADD += $(CLPOBJDIR)/src/libClp.la 
 LIBS += `cat $(CLPOBJDIR)/clp_addlibs.txt`

if COIN_HAS_DYLP
 OSSolverService_LDADD += $(DYLPOBJDIR)/src/Dylp/libDylp.la 
 LIBS += `cat $(DYLPOBJDIR)/dylp_addlibs.txt`
endif

if COIN_HAS_VOL
 OSSolverService_LDADD += $(VOLOBJDIR)/src/libVol.la 
 LIBS += `cat $(VOLOBJDIR)/vol_addlibs.txt`
endif


if COIN_HAS_GLPK
 OSSolverService_LDADD += $(OSIOBJDIR)/src/OsiGlpk/libOsiGlpk.la
 OSSolverService_LDADD += $(GLPKLIB)
endif

 OSSolverService_LDADD += $(COINUTILSOBJDIR)/src/libCoinUtils.la  
 LIBS += `cat $(COINUTILSOBJDIR)/coinutils_addlibs.txt`

 OSSolverService_LDADD += $(ADDLIBS) 

if USEWSOCKLIB
  OSSolverService_LDADD += $(WINSOCKLIB)
endif




########################################################################
#                            Additional flags                          #
########################################################################


# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(COINUTILSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(COINUTILSOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(CBCSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CBCOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(CLPSRCDIR)/src` \
	-I`$(CYGPATH_W) $(CLPOBJDIR)/inc` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src` \
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

# The -rpath flag is used by libtool to make sure that the shared
# library is found (in the lib install directory) when we are using dynamic
# libraries.
OSSolverService_LDFLAGS = -rpath $(libdir)

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
    -I`$(CYGPATH_W) $(SYMPHONYOBJDIR)/include` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiSym`
endif


if COIN_HAS_VOL
  AM_CPPFLAGS += \
    -I`$(CYGPATH_W) $(VOLSRCDIR)/include` \
 -I`$(CYGPATH_W) $(VOLOBJDIR)/include` \
    -I`$(CYGPATH_W) $(VOLSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiVol`
endif



if COIN_HAS_CPX
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(CPXINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiCpx`
	OSSolverService_LDADD += $(OSIOBJDIR)/src/OsiCpx/libOsiCpx.la
endif




if COIN_HAS_GLPK
  AM_CPPFLAGS += \
	-I`$(CYGPATH_W) $(GLPKINCDIR)` \
	-I`$(CYGPATH_W) $(OSISRCDIR)/src/OsiGlpk`
endif



if COIN_HAS_LINDO
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(LINDOINCDIR)` 
  OSSolverService_LDADD += $(LINDOLIB)
endif

if COIN_HAS_IPOPT
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(IPOPTINCDIR)` 
  OSSolverService_LDADD += $(IPOPTLIB)
endif

if COIN_HAS_KNITRO
  AM_CPPFLAGS += 	-I`$(CYGPATH_W) $(KNITROINCDIR)` 
  OSSolverService_LDADD += $(KNITROLIB)
if USEMULTIPLYDEFINED
	OSSolverService_LDFLAGS += -multiply_defined suppress
endif
endif


if COIN_HAS_ASL
  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
  OSSolverService_LDADD += $(ASLLIB)
endif



if USEWSOCKLIB
# ADDLIBS += $(WINSOCKLIB)
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
	OSConfig.h \
	../inc/config_os.h 



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
	$(install_sh_DATA) bla $(DESTDIR)$(includedir)/$(ConfigHeader)
	rm -f bla

uninstall-local:
	rm -f $(DESTDIR)$(includedir)/$(ConfigHeader)
