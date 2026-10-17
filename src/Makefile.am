# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.

# Author:  Andreas Waechter           IBM    2006-04-13

# Modifications by Horand Gassmann, Jun Ma and Kipp Martin

# Now we check into which directories to recurse, and which subdirectory
# libraries to include
SUBDIRS = \
	OSUtils \
	OSAgent \
	OSCommonInterfaces \
	OSModelInterfaces \
	OSParsers \
	OSSolverInterfaces

########################################################################
#                           libOS  -- Optimization Services Library    #
########################################################################

# Name of the library compiled in this directory.
lib_LTLIBRARIES = libOS.la

# List all source files for this library, including headers
libOS_la_SOURCES =

# Dummy C++ source to cause C++ linking
nodist_EXTRA_libOS_la_SOURCES = dummy.cpp

# We want to have all the OS objects in this library
libOS_la_LIBADD = \
	OSUtils/libOSUtils.la \
	OSCommonInterfaces/libOSCommonInterfaces.la \
	OSAgent/libOSAgent.la \
	OSModelInterfaces/libOSModelInterfaces.la \
	OSParsers/libOSParsers.la \
	OSSolverInterfaces/libOSSolverInterfaces.la \
	$(OSLIB_LFLAGS)

# This is for libtool
libOS_la_LDFLAGS = $(LT_LDFLAGS)

########################################################################
#                    OSSolverService program                           #
########################################################################

# Name of the executable compiled in this directory.  We want it to be
# installed in the 'bin' directory
bin_PROGRAMS = OSSolverService

# List all source files for this executable, including headers
OSSolverService_SOURCES = OSSolverService.cpp

OSSolverService_LDADD = libOS.la $(OSLIB_LFLAGS)

########################################################################
#                            Additional flags                          #
########################################################################

# Here list all include flags, relative to this "srcdir" directory.
AM_CPPFLAGS = \
	-I$(srcdir)/OSAgent \
	-I$(srcdir)/OSParsers \
	-I$(srcdir)/OSUtils \
	-I$(srcdir)/OSSolverInterfaces \
	-I$(srcdir)/OSModelInterfaces \
	-I$(srcdir)/OSCommonInterfaces \
	$(OSLIB_CFLAGS)

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'include/coin-or'
includecoindir = $(includedir)/coin-or

install-exec-local:
	$(install_sh_DATA) config_os.h $(DESTDIR)$(includecoindir)/OSConfig.h

uninstall-local:
	rm -f $(DESTDIR)$(includecoindir)/OSConfig.h
