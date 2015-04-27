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
$(srcdir)/OSParse%.cpp: \
                 $(srcdir)/OSParse%.l \
                 $(srcdir)/OSParse%.tab.cpp
	$(LEX) -P$* -o$@ $<

$(srcdir)/OSParse%.tab.cpp $(srcdir)/OSParse%.tab.hpp: \
                $(srcdir)/OSParse%.y
	$(YACC) -ldv -p $* -o $(srcdir)/OSParse$*.tab.cpp $<

$(srcdir)/OSParse%.l: \
		$(srcdir)/OSParse%.l.1 \
		$(srcdir)/OSParseosgl.l.patterns \
		$(srcdir)/OSParseosnl.l.patterns \
		$(srcdir)/OSParse%.l.2
	cat $? >$(srcdir)/OSParse$*.l

$(srcdir)/OSParse%.y: \
		$(srcdir)/OSParse%.y.1 \
		$(srcdir)/OSParseosgl.y.tokens \
		$(srcdir)/OSParseosnl.y.tokens \
		$(srcdir)/OSParse%.y.2   \
		$(srcdir)/OSParseosgl.y.syntax \
		$(srcdir)/OSParseosnl.y.syntax \
		$(srcdir)/OSParse%.y.3
	sed 's/parserObjects/osinstance, parserData, osglData, osnlData/g' $(srcdir)/OSParse$*.y.2      >$*temp.tmp
	sed 's/parserObjects/osinstance, parserData, osglData, osnlData/g' $(srcdir)/OSParseosgl.y.syntax >osgltemp.tmp
	sed 's/parserObjects/osinstance, parserData, osglData, osnlData/g' $(srcdir)/OSParseosnl.y.syntax >osnltemp.tmp
	cat $(srcdir)/OSParse$*.y.1 \
		$(srcdir)/OSParseosgl.y.tokens $(srcdir)/OSParseosnl.y.tokens \
		osiltemp.tmp osgltemp.tmp osnltemp.tmp \
		$(srcdir)/OSParse$*.y.3 >$(srcdir)/OSParse$*.y
	rm -f $*temp.tmp
	rm -f osgltemp.tmp
	rm -f osnltemp.tmp
endif

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

