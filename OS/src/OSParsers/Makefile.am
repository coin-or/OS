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

$(srcdir)/OSParseosrl.tab.cpp : $(srcdir)/OSParseosrl.y
	$(YACC) -ldv -p osrl -o $@ $<
	
$(srcdir)/OSParseosrl.cpp : $(srcdir)/OSParseosrl.l
	$(LEX) -Posrl -o$@ $<

$(srcdir)/OSParseosil.tab.cpp : $(srcdir)/OSParseosil.y
	$(YACC) -ldv -p osil -o $@ $<
	
$(srcdir)/OSParseosil.cpp : $(srcdir)/OSParseosil.l
	$(LEX) -Posil -o$@ $<

$(srcdir)/OSParseosol.tab.cpp : $(srcdir)/OSParseosol.y
	$(YACC) -ldv -p osol -o $@ $<
	
$(srcdir)/OSParseosol.cpp : $(srcdir)/OSParseosol.l
	$(LEX) -Posol -o$@ $<

$(srcdir)/OSParseosss.cpp : $(srcdir)/OSParseosss.l
	$(LEX) -Posss -o$@ $<

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
