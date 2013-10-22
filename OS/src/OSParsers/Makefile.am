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

osil: ${abs_source_dir}/src/OSParsers/OSParseosil.cpp \
      ${abs_source_dir}/src/OSParsers/OSParseosil.tab.cpp

if HAVE_LEXYACC
${abs_source_dir}/src/OSParsers/OSParseosil.cpp: \
                 ${abs_source_dir}/src/OSParsers/OSParseosil.l \
                 ${abs_source_dir}/src/OSParsers/OSParseosil.tab.cpp
	$(LEX) -Posil -o${abs_source_dir}/src/OSParsers/OSParseosil.cpp \
                        ${abs_source_dir}/src/OSParsers/OSParseosil.l

${abs_source_dir}/src/OSParsers/OSParseosil.tab.cpp: ${abs_source_dir}/src/OSParsers/OSParseosil.y
	$(YACC) -ldv -p osil -o ${abs_source_dir}/src/OSParsers/OSParseosil.tab.cpp \
                                ${abs_source_dir}/src/OSParsers/OSParseosil.y
endif

osol: ${abs_source_dir}/src/OSParsers/OSParseosol.cpp \
      ${abs_source_dir}/src/OSParsers/OSParseosol.tab.cpp

if HAVE_LEXYACC
${abs_source_dir}/src/OSParsers/OSParseosol.cpp: \
                 ${abs_source_dir}/src/OSParsers/OSParseosol.l \
                 ${abs_source_dir}/src/OSParsers/OSParseosol.tab.cpp
	$(LEX) -Posol -o${abs_source_dir}/src/OSParsers/OSParseosol.cpp \
                        ${abs_source_dir}/src/OSParsers/OSParseosol.l

${abs_source_dir}/src/OSParsers/OSParseosol.tab.cpp: ${abs_source_dir}/src/OSParsers/OSParseosol.y
	$(YACC) -ldv -p osol -o ${abs_source_dir}/src/OSParsers/OSParseosol.tab.cpp \
                                ${abs_source_dir}/src/OSParsers/OSParseosol.y
endif

osrl: ${abs_source_dir}/src/OSParsers/OSParseosrl.cpp \
      ${abs_source_dir}/src/OSParsers/OSParseosrl.tab.cpp

if HAVE_LEXYACC
${abs_source_dir}/src/OSParsers/OSParseosrl.cpp: \
                 ${abs_source_dir}/src/OSParsers/OSParseosrl.l \
                 ${abs_source_dir}/src/OSParsers/OSParseosrl.tab.cpp
	$(LEX) -Posil -o${abs_source_dir}/src/OSParsers/OSParseosrl.cpp \
                        ${abs_source_dir}/src/OSParsers/OSParseosrl.l

${abs_source_dir}/src/OSParsers/OSParseosrl.tab.cpp: ${abs_source_dir}/src/OSParsers/OSParseosrl.y
	$(YACC) -ldv -p osrl -o ${abs_source_dir}/src/OSParsers/OSParseosrl.tab.cpp \
                                ${abs_source_dir}/src/OSParsers/OSParseosrl.y
endif

osss: ${abs_source_dir}/src/OSParsers/OSParseosss.cpp 

if HAVE_LEXYACC
${abs_source_dir}/src/OSParsers/OSParseosss.cpp: ${abs_source_dir}/src/OSParsers/OSParseosss.l 
	$(LEX) -Posss -o${abs_source_dir}/src/OSParsers/OSParseosss.cpp \
                        ${abs_source_dir}/src/OSParsers/OSParseosss.l
endif

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
