# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 506 2006-06-01 20:11:24Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

########################################################################
#                             libOSParsers                         #
########################################################################

# Name of the library compiled in this directory.  We do not want it to be installed.
noinst_LTLIBRARIES = libOSParsers.la

# List all source files for this library, including headers
libOSParsers_la_SOURCES = \
		OSParseosil.cpp \
		OSParseosil.tab.cpp \
		OSParseosil.tab.hpp \
		OSParseosol.cpp \
		OSParseosol.tab.cpp \
		OSParseosol.tab.hpp \
		OSParseosrl.cpp \
		OSParseosrl.tab.cpp \
		OSParseosrl.tab.hpp \
		OSParseosss.cpp	\
		OSgLParserData.h \
		OSgLParserData.cpp \
		OSiLParserData.h \
		OSiLParserData.cpp \
		OSrLParserData.h \
		OSrLParserData.cpp \
		OSoLParserData.h \
		OSoLParserData.cpp


########################################################################
#                           Extra Targets                              #
########################################################################

run_parsers: osil osol osrl osss

osil: OSParseosil.cpp OSParseosil.tab.cpp

OSParseosil.cpp: OSParseosil.l OSParseosil.tab.cpp
	$(LEX) -Posil -o$@ $<

OSParseosil.tab.cpp: OSParseosil.y
	$(YACC) -ldv -p osil -o $@ $<

osol: OSParseosol.cpp OSParseosol.tab.cpp

OSParseosol.cpp: OSParseosol.l OSParseosol.tab.cpp
	$(LEX) -Posol -o$@ $<

OSParseosol.tab.cpp: OSParseosol.y
	$(YACC) -ldv -p osol -o $@ $<

osrl: OSParseosrl.cpp OSParseosrl.tab.cpp

OSParseosrl.cpp: OSParseosrl.l OSParseosrl.tab.cpp
	$(LEX) -Posrl -o$@ $<

OSParseosrl.tab.cpp: OSParseosrl.y
	$(YACC) -ldv -p osrl -o $@ $<

osss: OSParseosrl.cpp 

OSParseosss.cpp: OSParseosss.l 
	$(LEX) -Posss -o$@ $<

.PHONY: run_parsers osil osol osrl osss


libOSParsers_la_LDFLAGS = $(LT_LDFLAGS)

# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS = \
	-I`$(CYGPATH_W) $(srcdir)/..` \
	-I`$(CYGPATH_W) $(srcdir)/../OSUtils` \
	-I`$(CYGPATH_W) $(srcdir)/../OSSolverInterfaces` \
	-I`$(CYGPATH_W) $(srcdir)/../OSCommonInterfaces` \
	$(OSLIB_CFLAGS)

#if USE_DTOA
#AM_CPPFLAGS += -DUSE_DTOA=1
#endif

# This line is necessary to allow VPATH compilation
DEFAULT_INCLUDES = -I. -I`$(CYGPATH_W) $(srcdir)` -I..

########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'include/coin'
includecoindir = $(includedir)/coin
includecoin_HEADERS = \
	OSParseosil.tab.hpp \
	OSParseosrl.tab.hpp \
	OSParseosol.tab.hpp \
	OSgLParserData.h \
	OSiLParserData.h \
	OSrLParserData.h \
	OSoLParserData.h
