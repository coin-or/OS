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
# in the 'lib/coin' directory

coinlibdir = ${libdir}/coin
coinlib_LTLIBRARIES = libOS.la

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
#                    OSSolverService program                           #
########################################################################

# Name of the executable compiled in this directory.  We want it to be
# installed in the 'bin' directory
bin_PROGRAMS = OSSolverService

# List all source files for this executable, including headers
OSSolverService_SOURCES = OSSolverService.cpp 

OSSolverService_LDADD = libOS.la $(OSLIB_LIBS)

OSSolverService_DEPENDENCIES = libOS.la $(OSLIB_DEPENDENCIES)

# TODO? the following will not work with the new buildsystem anymore
#if COIN_HAS_COUENNE
#     OSSolverService_SOURCES += $(COUENNESRCDIR)/src/main/BonCouenneInfo.cpp $(COUENNESRCDIR)/src/main/BonCouenneInfo.hpp
#endif


# The -rpath flag is used by libtool to make sure that the shared
# library is found (in the lib install directory) when we are using dynamic
# libraries.
OSSolverService_LDFLAGS = -rpath $(coinlibdir) 



########################################################################
#                            Additional flags                          #
########################################################################


# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = $(OSLIB_CFLAGS) \
	-I`$(CYGPATH_W) $(srcdir)/OSAgent` \
	-I`$(CYGPATH_W) $(srcdir)/OSParsers` \
	-I`$(CYGPATH_W) $(srcdir)/OSUtils` \
	-I`$(CYGPATH_W) $(srcdir)/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/OSModelInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/OSCommonInterfaces` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)`

# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc


########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'include/coin'
includecoindir = $(includedir)/coin
includecoin_HEADERS = \
	OSConfig.h \
	../inc/config_os.h 

if MSCL_
   includecoin_HEADERS += $(abs_source_dir)/../BuildTools/headers/configall_system.h
   includecoin_HEADERS += $(abs_source_dir)/../BuildTools/headers/configall_system_msc.h
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
