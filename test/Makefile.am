# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.


# Author:  Andreas Waechter           IBM    2006-04-13

########################################################################
#                          unitTest  program                           #
########################################################################

# Name of the executable compiled in this directory.  We do not want it
# to be installed.
noinst_PROGRAMS = unitTest

# List all source files for this executable, including headers
unitTest_SOURCES = unitTest.cpp 

# List all additionally required libraries
unitTest_LDADD =  ../src/libOS.la $(OSLIB_LFLAGS)

########################################################################
#                            Additional flags                          #
########################################################################

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = \
	-I$(srcdir)/../src \
	-I$(srcdir)/../src/OSAgent \
	-I$(srcdir)/../src/OSParsers \
	-I$(srcdir)/../src/OSUtils \
	-I$(srcdir)/../src/OSSolverInterfaces \
	-I$(srcdir)/../src/OSModelInterfaces \
	-I$(srcdir)/../src/OSCommonInterfaces \
	$(OSLIB_CFLAGS)
	
	
if COIN_HAS_CSDP
  AM_CPPFLAGS += -DNOSHORTS
endif

DISTCLEANFILES = ipopt.out bonmin.out

test: unitTest$(EXEEXT)
	./unitTest$(EXEEXT)

alltests: unitTest$(EXEEXT)
	./unitTest$(EXEEXT) nb

.PHONY: test
