# Copyright (C) 2006 International Business Machines and others.
# All Rights Reserved.
# This file is distributed under the Common Public License.

## $Id: Makefile.am 756 2006-06-26 19:43:41Z ladanyi $

# Author:  Andreas Waechter           IBM    2006-04-13

AUTOMAKE_OPTIONS = foreign


########################################################################
#                           libOSCommon  -- Optimization Services Library    #
########################################################################

# Name of the library compiled in this directory.  We want it to be installed
# in the 'lib' directory
lib_LTLIBRARIES = libOSCommon.la

# List all source files for this library, including headers
libOSCommon_la_SOURCES = 

# This is for libtool (on Windows)
libOSCommon_la_LDFLAGS = $(LT_LDFLAGS)


# We want to have all the OS objects in this library
libOSCommon_la_LIBADD = ./OSUtils/libOSUtils.la \
		./OSCommonInterfaces/libOSCommonInterfaces.la \
		./OSAgent/libOSAgent.la \
		./OSParsers/libOSParsers.la 
# Since automake is not doing this on its own, we need to declare the
# dependencies to the subdirectory libraries here
libOSCommon_la_DEPENDENCIES = $(libOSCommon_la_LIBADD)



# Now we check into which directories to recurse, and which subdirectory
# libraries to include
SUBDIRS =
  SUBDIRS += OSUtils
  SUBDIRS += OSAgent
  SUBDIRS += OSCommonInterfaces
  SUBDIRS += OSParsers





########################################################################
#                            Additional flags                          #
########################################################################


# Here list all include flags, relative to this "srcdir" directory.  This
# "cygpath" stuff is necessary to compile with native compilers on Windows
AM_CPPFLAGS =\
	-I`$(CYGPATH_W) $(OSSRCDIR)/src` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSAgent` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSParsers` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSUtils` \
	-I`$(CYGPATH_W) $(OSSRCDIR)/src/OSCommonInterfaces` \
	-I`$(CYGPATH_W) $(CPPADSRCDIR)` 





########################################################################
#                Headers that need to be installed                     #
########################################################################

# Here list all the header files that are required by a user of the library,
# and that therefore should be installed in 'install'
include_HEADERS = \
	OSConfig.h \
	../inc/config_os.h 

includecoindir = $(includedir)/coin
includecoin_HEADERS = \
	../../inc/config_os.h \
	OSConfig.h 


#############################################################################
# Create the Config.h file that always defines HAVE_CONFIG_H and install it #
#############################################################################

# You only need to adapt the following line
ConfigHeader = OSConfig.h

install-exec-local:
	echo "#ifndef HAVE_CONFIG_H" >bla
	echo "#define HAVE_CONFIG_H" >>bla
	echo "#endif" >> bla
	cat $(srcdir)/$(ConfigHeader) >> bla
	$(install_sh_DATA) bla $(DESTDIR)$(includedir)/$(ConfigHeader)
	rm -f bla

uninstall-local:
	rm -f $(DESTDIR)$(includedir)/$(ConfigHeader)
