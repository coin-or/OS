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
	$(OSOBJDIR)/src/libOS.la \
	$(OSIOBJDIR)/src/OsiCbc/libOsiCbc.la \
	$(OSIOBJDIR)/src/OsiClp/libOsiClp.la \
	$(CBCOBJDIR)/src/libCbc.la \
	$(CGLOBJDIR)/src/libCgl.la \
	$(OSIOBJDIR)/src/libOsi.la \
	$(CLPOBJDIR)/src/libClp.la \
	$(COINUTILSOBJDIR)/src/libCoinUtils.la 



# Here we add additional libraries
# Kipp add the others here
LIBS += $(ADDLIBS) `cat $(COINUTILSOBJDIR)/coinutils_addlibs.txt`
LIBS  += `cat $(OSOBJDIR)/os_addlibs.txt`




########################################################################
#                            Additional flags                          #
########################################################################


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
  OSSolverService_LDADD += $(OSIOBJDIR)/src/OsiGlpk/libOsiGlpk.la
endif

if COIN_HAS_LINDO
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(LINDOINCDIR)` 
  OSSolverService_LDADD += $(LINDOLIB)
endif

if COIN_HAS_IPOPT
  AM_CPPFLAGS += -I`$(CYGPATH_W) $(IPOPTINCDIR)` 
  OSSolverService_LDADD += $(IPOPTLIB)
endif


if COIN_HAS_ASL
  AM_CPPFLAGS += $(ASL_CPPFLAGS) 
  OSSolverService_LDADD += $(ASLLIB)
endif



if USEWSOCKLIB
  ADDLIBS += $(WINSOCKLIB)
endif


OSSolverService_LDFLAGS = -rpath $(libdir)



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
