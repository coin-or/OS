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
  SUBDIRS += test
  SUBDIRS += applications

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
	flex -Posrl  -o${abs_source_dir}/src/OSParsers/OSParseosrl.cpp ${abs_source_dir}/src/OSParsers/OSParseosrl.l
	$(YACC) -ldv -p osil  -o ${abs_source_dir}/src/OSParsers/OSParseosil.tab.cpp ${abs_source_dir}/src/OSParsers/OSParseosil.y
	flex -Posil -o${abs_source_dir}/src/OSParsers/OSParseosil.cpp ${abs_source_dir}/src/OSParsers/OSParseosil.l
	flex -Posol -o${abs_source_dir}/src/OSParsers/OSParseosol.cpp ${abs_source_dir}/src/OSParsers/OSParseosol.l
	flex -Posss -o${abs_source_dir}/src/OSParsers/OSParseosss.cpp ${abs_source_dir}/src/OSParsers/OSParseosss.l
	make

########################################################################
#                  Installation of the addlibs file                    #
########################################################################

addlibsfile = os_addlibs.txt
addlibsdir = $(prefix)/share/doc/coin/$(PACKAGE_NAME)/

install-exec-local: install-doc
	$(install_sh_DATA) $(addlibsfile) $(addlibsdir)/$(addlibsfile)

uninstall-local: uninstall-doc
	rm -f $(DESTDIR)$(libdir)/$(addlibsfile)




########################################################################
#                         Maintainer Stuff                             #
########################################################################

# Files that are generated and should be cleaned with make distclean
DISTCLEANFILES =

include ../BuildTools/Makemain.inc
