# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Eclipse Public License.

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
		OSnLParserData.h \
		OSnLParserData.cpp \
		OSoLParserData.h \
		OSoLParserData.cpp \
		OSrLParserData.h \
		OSrLParserData.cpp


########################################################################
#                           Extra Targets                              #
########################################################################
run_parsers: osil osol osrl osss

osil: $(srcdir)/OSParseosil.cpp \
      $(srcdir)/OSParseosil.tab.cpp

osol: $(srcdir)/OSParseosol.cpp \
      $(srcdir)/OSParseosol.tab.cpp

osrl: $(srcdir)/OSParseosrl.cpp \
      $(srcdir)/OSParseosrl.tab.cpp

osss: $(srcdir)/OSParseosss.cpp 


if HAVE_LEXYACC

# Some preparatory file manipulations
# Needs special rules to ensure nested dependencies are handled successfully
$(srcdir)/OSParseosil.l: \
		$(srcdir)/OSParseosil.l.1 \
		$(srcdir)/OSParseosgl.l.patterns \
		$(srcdir)/OSParseosnl.l.patterns \
		$(srcdir)/OSParseosil.l.2
	cat $(srcdir)/OSParseosil.l.1 \
		$(srcdir)/OSParseosgl.l.patterns $(srcdir)/OSParseosnl.l.patterns \
		$(srcdir)/OSParseosil.l.2 >$(srcdir)/OSParseosil.l

$(srcdir)/OSParseosil.y: \
		$(srcdir)/OSParseosil.y.1 \
		$(srcdir)/OSParseosgl.y.tokens \
		$(srcdir)/OSParseosnl.y.tokens \
		$(srcdir)/OSParseosil.y.2   \
		$(srcdir)/OSParseosgl.y.syntax \
		$(srcdir)/OSParseosnl.y.syntax \
		$(srcdir)/OSParseosil.y.3
	sed 's/parserObjects/osinstance, parserData, osglData, osnlData/g' $(srcdir)/OSParseosil.y.2      >osiltemp.tmp
	sed 's/parserObjects/osinstance, parserData, osglData, osnlData/g' $(srcdir)/OSParseosgl.y.syntax >osgltemp.tmp
	sed 's/parserObjects/osinstance, parserData, osglData, osnlData/g' $(srcdir)/OSParseosnl.y.syntax >osnltemp.tmp
	cat $(srcdir)/OSParseosil.y.1 \
		$(srcdir)/OSParseosgl.y.tokens $(srcdir)/OSParseosnl.y.tokens \
		osiltemp.tmp osgltemp.tmp osnltemp.tmp \
		$(srcdir)/OSParseosil.y.3 >$(srcdir)/OSParseosil.y
	rm -f osiltemp.tmp
	rm -f osgltemp.tmp
	rm -f osnltemp.tmp

$(srcdir)/OSParseosol.l: \
		$(srcdir)/OSParseosol.l.1 \
		$(srcdir)/OSParseosgl.l.patterns \
		$(srcdir)/OSParseosnl.l.patterns \
		$(srcdir)/OSParseosol.l.2
	cat $(srcdir)/OSParseosol.l.1 \
		$(srcdir)/OSParseosgl.l.patterns $(srcdir)/OSParseosnl.l.patterns \
		$(srcdir)/OSParseosol.l.2 >$(srcdir)/OSParseosol.l

$(srcdir)/OSParseosol.y: \
		$(srcdir)/OSParseosol.y.1 \
		$(srcdir)/OSParseosgl.y.tokens \
		$(srcdir)/OSParseosnl.y.tokens \
		$(srcdir)/OSParseosol.y.2   \
		$(srcdir)/OSParseosgl.y.syntax \
		$(srcdir)/OSParseosnl.y.syntax \
		$(srcdir)/OSParseosol.y.3
	sed 's/parserObjects/osoption, parserData, osglData, osnlData/g' $(srcdir)/OSParseosol.y.2      >osoltemp.tmp
	sed 's/parserObjects/osoption, parserData, osglData, osnlData/g' $(srcdir)/OSParseosgl.y.syntax >osgltemp.tmp
	sed 's/parserObjects/osoption, parserData, osglData, osnlData/g' $(srcdir)/OSParseosnl.y.syntax >osnltemp.tmp
	cat $(srcdir)/OSParseosol.y.1 \
		$(srcdir)/OSParseosgl.y.tokens $(srcdir)/OSParseosnl.y.tokens \
		osoltemp.tmp osgltemp.tmp osnltemp.tmp \
		$(srcdir)/OSParseosol.y.3 >$(srcdir)/OSParseosol.y
	rm -f osoltemp.tmp
	rm -f osgltemp.tmp
	rm -f osnltemp.tmp

$(srcdir)/OSParseosrl.l: \
		$(srcdir)/OSParseosrl.l.1 \
		$(srcdir)/OSParseosgl.l.patterns \
		$(srcdir)/OSParseosnl.l.patterns \
		$(srcdir)/OSParseosrl.l.2
	cat $(srcdir)/OSParseosrl.l.1 \
		$(srcdir)/OSParseosgl.l.patterns $(srcdir)/OSParseosnl.l.patterns \
		$(srcdir)/OSParseosrl.l.2 >$(srcdir)/OSParseosrl.l

$(srcdir)/OSParseosrl.y: \
		$(srcdir)/OSParseosrl.y.1 \
		$(srcdir)/OSParseosgl.y.tokens \
		$(srcdir)/OSParseosnl.y.tokens \
		$(srcdir)/OSParseosrl.y.2   \
		$(srcdir)/OSParseosgl.y.syntax \
		$(srcdir)/OSParseosnl.y.syntax \
		$(srcdir)/OSParseosrl.y.3
	sed 's/parserObjects/osresult, parserData, osglData, osnlData/g' $(srcdir)/OSParseosrl.y.2      >osrltemp.tmp
	sed 's/parserObjects/osresult, parserData, osglData, osnlData/g' $(srcdir)/OSParseosgl.y.syntax >osgltemp.tmp
	sed 's/parserObjects/osresult, parserData, osglData, osnlData/g' $(srcdir)/OSParseosnl.y.syntax >osnltemp.tmp
	cat $(srcdir)/OSParseosrl.y.1 \
		$(srcdir)/OSParseosgl.y.tokens $(srcdir)/OSParseosnl.y.tokens \
		osrltemp.tmp osgltemp.tmp osnltemp.tmp \
		$(srcdir)/OSParseosrl.y.3 >$(srcdir)/OSParseosrl.y
	rm -f osrltemp.tmp
	rm -f osgltemp.tmp
	rm -f osnltemp.tmp

# use lex/flex to generate the scanner and tokens. 
# Needs special rules to ensure nested dependencies are handled successfully

$(srcdir)/OSParseosil.cpp: \
                 $(srcdir)/OSParseosil.l \
                 $(srcdir)/OSParseosil.tab.cpp
	$(LEX) -Posil -o$(srcdir)/OSParseosil.cpp \
                        $(srcdir)/OSParseosil.l

$(srcdir)/OSParseosol.cpp: \
                 $(srcdir)/OSParseosol.l \
                 $(srcdir)/OSParseosol.tab.cpp
	$(LEX) -Posol -o$(srcdir)/OSParseosol.cpp \
                        $(srcdir)/OSParseosol.l

$(srcdir)/OSParseosrl.cpp: \
                 $(srcdir)/OSParseosrl.l \
                 $(srcdir)/OSParseosrl.tab.cpp
	$(LEX) -Posrl -o$(srcdir)/OSParseosrl.cpp \
                        $(srcdir)/OSParseosrl.l

# bison generates the grammars. Since there are multiple targets, use a pattern rule

$(srcdir)/OSParse%.tab.cpp $(srcdir)/OSParse%.tab.hpp: \
                $(srcdir)/OSParse%.y
	$(YACC) -ldv -p $* -o $(srcdir)/OSParse$*.tab.cpp $<

endif

# the command line parser does not use a grammar

if HAVE_LEXYACC
$(srcdir)/OSParseosss.cpp: $(srcdir)/OSParseosss.l 
	$(LEX) -Posss -o$(srcdir)/OSParseosss.cpp \
                        $(srcdir)/OSParseosss.l
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
	OSnLParserData.h \
	OSoLParserData.h \
	OSrLParserData.h

