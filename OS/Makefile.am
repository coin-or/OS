# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 505 2006-06-01 18:46:31Z andreasw $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign

###########

CXXFLAGS = -O3  -pipe -DNDEBUG -pedantic-errors -Wimplicit -Wparentheses -Wreturn-type -Wcast-qual -Wall -Wpointer-arith -Wwrite-strings -Wconversion

########################################################################
#                          Subdirectories                              #
########################################################################

SUBDIRS = src
#  SUBDIRS += test
#  SUBDIRS += applications

# We don't want to compile the test subdirectory, unless the test target is
# specified.  But we need to list it as subdirectory to make sure that it is
# included in the tarball

if ALWAYS_FALSE
  SUBDIRS += test
endif

########################################################################
#             Additional files to be included in tarball               #
########################################################################

# Here we need include all files that are not mentioned in other Makefiles

EXTRA_DIST =
 

########################################################################
#                           Extra Targets                              #
########################################################################

test: all
	cd test; make test


unitTest: test

clean-local:
	if test -r test/Makefile; then cd test; make clean; fi

distclean-local:
	if test -r test/Makefile; then cd test; make distclean; fi

.PHONY: test unitTest

run_parsers:
	$(YACC) -ldv -p osrl -o ${abs_source_dir}/src/OSParsers/OSParseosrl.tab.cpp ${abs_source_dir}/src/OSParsers/OSParseosrl.y
	flex  -Posrl  -o${abs_source_dir}/src/OSParsers/OSParseosrl.cpp ${abs_source_dir}/src/OSParsers/OSParseosrl.l
	$(YACC) -ldv -p osil  -o ${abs_source_dir}/src/OSParsers/OSParseosil.tab.cpp ${abs_source_dir}/src/OSParsers/OSParseosil.y
	flex  -Posil -o${abs_source_dir}/src/OSParsers/OSParseosil.cpp ${abs_source_dir}/src/OSParsers/OSParseosil.l
	$(YACC) -ldv -p osol  -o ${abs_source_dir}/src/OSParsers/OSParseosol.tab.cpp ${abs_source_dir}/src/OSParsers/OSParseosol.y
	flex  -Posol -o${abs_source_dir}/src/OSParsers/OSParseosol.cpp ${abs_source_dir}/src/OSParsers/OSParseosol.l
	flex  -Posss -o${abs_source_dir}/src/OSParsers/OSParseosss.cpp ${abs_source_dir}/src/OSParsers/OSParseosss.l
	make

########################################################################
#                  Installation of the addlibs file                    #
########################################################################


pkgconfiglibdir = $(libdir)/pkgconfig
pkgconfiglib_DATA = os.pc 

addlibsdir = $(DESTDIR)$(datadir)/coin/doc/OS
	
install-data-hook:
	@$(mkdir_p) "$(addlibsdir)"
if COIN_HAS_PKGCONFIG
	PKG_CONFIG_PATH=@COIN_PKG_CONFIG_PATH@ \
	$(PKG_CONFIG) --libs os > $(addlibsdir)/os_addlibs.txt
else
if COIN_CXX_IS_CL
	echo "/libpath:`$(CYGPATH_W) @abs_lib_dir@` libOS.lib @OSLIB_LIBS_INSTALLED@" > $(addlibsdir)/os_addlibs_cpp.txt
else
	echo -L@abs_lib_dir@ -lOS @OSLIB_LIBS_INSTALLED@ > $(addlibsdir)/os_addlibs.txt
endif
endif

uninstall-hook:
	rm -f $(addlibsdir)/os_addlibs.txt

########################################################################
#                         Maintainer Stuff                             #
########################################################################

# Files that are generated and should be cleaned with make distclean
DISTCLEANFILES =

include BuildTools/Makemain.inc
