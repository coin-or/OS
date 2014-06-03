# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.

## $Id: Makefile.am 756 2006-06-26 19:43:41Z ladanyi $

# Author:  Andreas Waechter           IBM    2006-04-13

# Modifications by Horand Gassmann, Jun Ma and Kipp Martin

AUTOMAKE_OPTIONS = foreign

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
#                           libOS  -- Optimization Services Library    #
########################################################################

# Name of the library compiled in this directory.
lib_LTLIBRARIES = libOS.la

# List all source files for this library, including headers
libOS_la_SOURCES = 

# Dummy C++ source to cause C++ linking
nodist_EXTRA_libOS_la_SOURCES = dummy.cpp 

# This is for libtool (on Windows)
libOS_la_LDFLAGS = $(LT_LDFLAGS)

# We want to have all the OS objects in this library
libOS_la_LIBADD = ./OSUtils/libOSUtils.la \
		./OSCommonInterfaces/libOSCommonInterfaces.la \
		./OSAgent/libOSAgent.la \
		./OSModelInterfaces/libOSModelInterfaces.la \
		./OSParsers/libOSParsers.la \
		./OSSolverInterfaces/libOSSolverInterfaces.la 
if DEPENDENCY_LINKING
libOS_la_LIBADD += $(OSLIB_LIBS)
endif

########################################################################
#                    OSSolverService program                           #
########################################################################

# Name of the executable compiled in this directory.  We want it to be
# installed in the 'bin' directory
bin_PROGRAMS = OSSolverService

# List all source files for this executable, including headers
OSSolverService_SOURCES = OSSolverService.cpp 

OSSolverService_LDADD = libOS.la $(OSLIB_LIBS)

# Since automake is not doing this on its own, we need to declare the
# dependencies to the subdirectory libraries here
OSSolverService_DEPENDENCIES = libOS.la $(OSLIB_DEPENDENCIES)


########################################################################
#                            Additional flags                          #
########################################################################

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = \
	-I`$(CYGPATH_W) $(srcdir)/OSAgent` \
	-I`$(CYGPATH_W) $(srcdir)/OSParsers` \
	-I`$(CYGPATH_W) $(srcdir)/OSUtils` \
	-I`$(CYGPATH_W) $(srcdir)/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/OSModelInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/OSCommonInterfaces` \
	$(OSLIB_CFLAGS)
	
if COIN_HAS_LINDO
  AM_CPPFLAGS +=   -I`$(CYGPATH_W) $(LINDOINCDIR)` 
endif
	
if COIN_HAS_CSDP
  AM_CPPFLAGS +=   -I`$(CYGPATH_W) $(CSDPINCDIR)` -DNOSHORTS
endif

if COIN_HAS_KNITRO
  AM_CPPFLAGS +=   -I`$(CYGPATH_W) $(KNITROINCDIR)` 
endif

# This line is necessary to allow VPATH compilation
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)`


########################################################################
#                     Installing manifest (MSVC++)                     #
########################################################################

if COIN_CXX_IS_CL
install-exec-hook:
	test -s OSSolverService.exe.manifest && \
	mt -manifest OSSolverService.exe.manifest -outputresource:OSSolverService.exe;\
	cp OSSolverService.exe $(bindir)/OSSolverService.exe
endif

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'include/coin'
includecoindir = $(includedir)/coin

install-exec-local:
	$(install_sh_DATA) config_os.h $(DESTDIR)$(includecoindir)/OSConfig.h

uninstall-local:
	rm -f $(DESTDIR)$(includecoindir)/OSConfig.h
