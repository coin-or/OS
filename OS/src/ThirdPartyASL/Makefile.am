# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 506 2006-06-01 20:11:24Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSModelInterfaces                           #
########################################################################
if COIN_HAS_ASL

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory

lib_LTLIBRARIES = libThirdPartyASL.la

libThirdPartyASL_la_SOURCES = OSnl2osil.cpp \
				OSnl2osil.h 


# This is for libtool (on Windows)
libThirdPartyASL_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
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
	-I`$(CYGPATH_W) $(CPPADSRCDIR)/..` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)/..` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSAgent`  \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces`  \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSSolverInterfaces`	\
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` 



AM_CPPFLAGS += 	$(ASL_CPPFLAGS)




# This line is necessary to allow VPATH compilation with MS compilers
# on Cygwin
#DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I$(top_builddir)/inc

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'install'

include_HEADERS = OSnl2osil.h 
endif



