# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 806 2006-06-12 01:47:32Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign


########################################################################
#                          OSFileUpload  program                               #
########################################################################

# Name of the executable compiled in this directory. 
noinst_PROGRAMS = OSFileUpload


# List all source files for this executable, including headers
OSFileUpload_SOURCES = OSFileUpload.cpp 

# List all additionally required COIN libraries

OSFileUpload_LDADD =  \
	../../src/libOS.la $(OSLIB_LIBS)

# Now add the include paths for compilation

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = $(OSLIB_CFLAGS) \
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(top_srcdir)/src` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSAgent` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSParsers` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSUtils` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSModelInterfaces` \
	-I`$(CYGPATH_W) $(top_srcdir)/src/OSCommonInterfaces` 

########################################################################
#                            Additional flags                          #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'include/coin'
includecoindir = $(includedir)/coin
includecoin_HEADERS =
#	OSConfig.h \
#	../inc/config_os.h 

if COIN_CXX_IS_CL
   includecoin_HEADERS += $(top_srcdir)/../BuildTools/headers/configall_system.h
   includecoin_HEADERS += $(top_srcdir)/../BuildTools/headers/configall_system_msc.h
endif


# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc
