# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.


# Author:  Andreas Waechter           IBM    2006-04-13


########################################################################
#                          OSFileUpload  program                               #
########################################################################

# Name of the executable compiled in this directory. 
noinst_PROGRAMS = OSFileUpload


# List all source files for this executable, including headers
OSFileUpload_SOURCES = OSFileUpload.cpp 

# List all additionally required COIN libraries

OSFileUpload_LDADD = ../../src/libOS.la $(OSLIB_LFLAGS)


# Now add the include paths for compilation

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = \
	-I$(srcdir)/.. \
	-I$(top_srcdir)/src \
	-I$(top_srcdir)/src/OSAgent \
	-I$(top_srcdir)/src/OSParsers \
	-I$(top_srcdir)/src/OSUtils \
	-I$(top_srcdir)/src/OSSolverInterfaces \
	-I$(top_srcdir)/src/OSModelInterfaces \
	-I$(top_srcdir)/src/OSCommonInterfaces \
	$(OSLIB_CFLAGS)

########################################################################
#                            Additional flags                          #
########################################################################

