#===========================================================================#
# This file is part of the Decomp Solver Framework.                         #
#                                                                           #
# Decomp is distributed under the Common Public License as part of the      #
# COIN-OR repository (http://www.coin-or.org).                              #
#                                                                           #
# Author: Matthew Galati, SAS Institute Inc. (matthew.galati@sas.com)       #
#                                                                           #
# Copyright (C) 2002-2009, Lehigh University, Matthew Galati, and Ted Ralphs#
# All Rights Reserved.                                                      #
#===========================================================================#

#===========================================================================#
EXEDECOMP = decomp_bearcat

# source files
OBJS          = Bearcat_Main.o
OBJS         += OS_DipInterface.o
OBJS         += Bearcat_DecompApp.o



#===========================================================================#
# additional include and linnk flags
ADDLIBS      += 
ADDINCFLAGS  += 

#===========================================================================#
# directory to the source files

SRCDIR = ./
VPATH  = ./

#===========================================================================#
# C++ compiler command
CXX = g++
# C++ compiler options
CXXFLAGS = -O3 -fomit-frame-pointer -pipe -DNDEBUG -Wimplicit -Wparentheses -Wreturn-type -Wcast-qual -Wall -Wpointer-arith -Wwrite-strings -Wconversion -Wno-unknown-pragmas  -DHAVE_CONFIG_H
# C++ compiler options for linking
CXXLINKFLAGS = 

#===========================================================================#
# directory with COIN header files
#COININCDIR = /Users/kmartin/coin/dip-trunk/vpath/include
COININCDIR = /Users/kmartin/coin/dip-trunk/vpath/include/coin
OSINCDIR = /Users/kmartin/coin/os-trunk/vpath/include/coin
# directory with COIN libraries
COINLIBDIR = /Users/kmartin/coin/dip-trunk/vpath/lib
OSLIBDIR = /Users/kmartin/coin/os-trunk/vpath/lib

# includes, use the CYGPATH_W variables to allow compilation with win
INCL =  -I`$(CYGPATH_W) $(COININCDIR)` $(ADDINCFLAGS)

#===========================================================================#
# include COIN flags and library options
#include ../Makefile.Examples




###########################################################################
# define DECOMP libs
###########################################################################
LIBS = -L$(COINLIBDIR) \
	-lDecomp       \
	-lm 

ADDINCFLAGS += -DCOIN_ASSERT

###########################################################################
#define vars for ALPS
###########################################################################
LIBS += -lAlps `cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Alps/alps_addlibs.txt`

###########################################################################
# define the directory for LP/IP solver determined at configure
###########################################################################
CPXINCDIR  = 

###########################################################################
# define vars for which IP solver was chosen in configure
###########################################################################
CBC_IP_SOLVER    = TRUE
CPLEX_IP_SOLVER  = #TRUE

ifeq ($(CBC_IP_SOLVER),TRUE)
LIBS += -lOsiCbc -lCbcSolver -lCbc `cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Cbc/cbc_addlibs.txt`
ADDINCFLAGS += -D__DECOMP_IP_CBC__
endif

ifeq ($(CPLEX_IP_SOLVER),TRUE)
INCL += -I`$(CYGPATH_W) $(CPXINCDIR)`
LIBS += -lOsiCpx -lcplex
ADDINCFLAGS += -D__DECOMP_IP_CPX__
endif

###########################################################################
# define vars for which LP solver was chosen in configure
###########################################################################
CLP_LP_SOLVER    = TRUE
CPLEX_LP_SOLVER  = #TRUE

ifeq ($(CLP_LP_SOLVER),TRUE)
LIBS += -lOsiClp -lClp `cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Clp/clp_addlibs.txt`
ADDINCFLAGS += -D__DECOMP_LP_CLP__
endif

ifeq ($(CPLEX_LP_SOLVER),TRUE)
INCL += -I`$(CYGPATH_W) $(CPXINCDIR)`
LIBS += -lOsiCpx -lcplex
ADDINCFLAGS += -D__DECOMP_LP_CPX__
endif


###########################################################################
# define OS libs
###########################################################################
LIBS += -L$(OSLIBDIR) -lOS
###########################################################################
# define COIN libs
###########################################################################
LIBS += -L$(COINLIBDIR) -lCgl -lOsi -lCoinUtils \
	`cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Cgl/cgl_addlibs.txt` \
	`cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Osi/osi_addlibs.txt` \
	`cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../CoinUtils/coinutils_addlibs.txt`
#NOTE: CGL depends on CLP
LIBS += -lOsiClp -lClp -lCoinUtils `cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Clp/clp_addlibs.txt`
INCL += -I/Users/kmartin/coin/os-trunk/vpath/include/coin
INCL += -I/Users/kmartin/coin/os-trunk/vpath/include



###########################################################################
# define DECOMP libs
###########################################################################
LIBS = -L$(COINLIBDIR) \
	-lDecomp       \
	-lm 

ADDINCFLAGS += -DCOIN_ASSERT

###########################################################################
#define vars for ALPS
###########################################################################
LIBS += -lAlps `cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Alps/alps_addlibs.txt`

###########################################################################
# define the directory for LP/IP solver determined at configure
###########################################################################
CPXINCDIR  = 

###########################################################################
# define vars for which IP solver was chosen in configure
###########################################################################
CBC_IP_SOLVER    = TRUE
CPLEX_IP_SOLVER  = #TRUE

ifeq ($(CBC_IP_SOLVER),TRUE)
LIBS += -lOsiCbc -lCbcSolver -lCbc `cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Cbc/cbc_addlibs.txt`
ADDINCFLAGS += -D__DECOMP_IP_CBC__
endif

ifeq ($(CPLEX_IP_SOLVER),TRUE)
INCL += -I`$(CYGPATH_W) $(CPXINCDIR)`
LIBS += -lOsiCpx -lcplex
ADDINCFLAGS += -D__DECOMP_IP_CPX__
endif

###########################################################################
# define vars for which LP solver was chosen in configure
###########################################################################
CLP_LP_SOLVER    = TRUE
CPLEX_LP_SOLVER  = #TRUE

ifeq ($(CLP_LP_SOLVER),TRUE)
LIBS += -lOsiClp -lClp `cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Clp/clp_addlibs.txt`
ADDINCFLAGS += -D__DECOMP_LP_CLP__
endif

ifeq ($(CPLEX_LP_SOLVER),TRUE)
INCL += -I`$(CYGPATH_W) $(CPXINCDIR)`
LIBS += -lOsiCpx -lcplex
ADDINCFLAGS += -D__DECOMP_LP_CPX__
endif


###########################################################################
# define OS libs
###########################################################################
LIBS += -L$(OSLIBDIR) -lOS
###########################################################################
# define COIN libs
###########################################################################
LIBS += -L$(COINLIBDIR) -lCgl -lOsi -lCoinUtils \
	`cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Cgl/cgl_addlibs.txt` \
	`cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Osi/osi_addlibs.txt` \
	`cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../CoinUtils/coinutils_addlibs.txt`
#NOTE: CGL depends on CLP
LIBS += -lOsiClp -lClp -lCoinUtils `cat /Users/kmartin/coin/dip-trunk/vpath/Dip/../Clp/clp_addlibs.txt`
#INCL += -I/Users/kmartin/coin/dip-trunk/vpath/include

#===========================================================================#
# The following is necessary under cygwin, if native compilers are used
CYGPATH_W = echo

#===========================================================================#
all: $(EXEDECOMP)

.SUFFIXES: .cpp .c .o .obj

$(EXEDECOMP):  $(OBJS)
	bla=;\
	for file in $(OBJS); do bla="$$bla `$(CYGPATH_W) $$file`"; done; \
	$(CXX) $(CXXLINKFLAGS) $(CXXFLAGS) -o $@ $$bla $(ADDLIBS) $(LIBS)

clean:
	rm -rf $(EXE) $(OBJS)



.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCL) -c -o $@ `test -f '$<' || echo '$(SRCDIR)/'`$<

.cpp.obj:
	$(CXX) $(CXXFLAGS) $(INCL) -c -o $@ `if test -f '$<'; then $(CYGPATH_W) '$<'; else $(CYGPATH_W) '$(SRCDIR)/$<'; fi`
