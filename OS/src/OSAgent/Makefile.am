# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.


# Author:  Andreas Waechter           IBM    2006-04-13

########################################################################
#                             libOSAgent                               #
########################################################################

# Name of the library compiled in this directory.
noinst_LTLIBRARIES = libOSAgent.la

# List all source files for this library, including headers
libOSAgent_la_SOURCES = \
	OShL.cpp OShL.h OSSolverAgent.cpp \
	OSSolverAgent.h OSWSUtil.cpp OSWSUtil.h

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows.
AM_CPPFLAGS = \
	-I$(srcdir)/.. \
	-I$(srcdir)/../OSCommonInterfaces \
	-I$(srcdir)/../OSUtils \
	$(OSLIB_CFLAGS)

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'include/coin'
includecoindir = $(includedir)/coin-or
includecoin_HEADERS = \
	OShL.h OSSolverAgent.h OSWSUtil.h
