
# AC_COIN_OS_SOCKET_LIBS
# -----------------------------------------------------
# Determines configuration (headers and libraries) for socket functions.
# Winsock (winsock.h) is preferred if present, otherwise we go for BSD
# (socket.h) Why? Well, Cygwin provides both styles, but OS is set up to
# prefer Winsock in all Windows environments. You can't mix them. To avoid
# being fooled, check for Winsock first.
# Currently the macro understands these possibilities:
#   * no libraries (GCC environments)
#   * -lsocket -lnsl (Solaris)
#   * -L<something> -lwsock32 (Cygwin or MinGW)
#   * wsock32.lib (cl syntax in Windows land)
# To add a new option, augment the choices in the for loop, or add a new
# clause. Command line syntax for cl is completely different, hence it gets
# a separate clause.
# It seems that when trying to link to w32api libraries, there needs to be
# a correct declaration and call --- even in C, we're looking for something
# like _socket@12, some sort of mangling. Worse, the usual program fragment
# with an implicit declaration will compile *and link* without -lwsock32 in
# Cygwin, but real code with a winsock.h header *will fail*. Hence the care
# to check for presence with headers, and check winsock first (as noted above).
# And then there's -pedantic-errors, which causes no end of grief. Drop it.
# -----------------------------------------------------

AC_DEFUN([AC_COIN_OS_SOCKET_LIBS],
[ 
  AC_COIN_CHECK_HEADER([sys/socket.h])
  AC_COIN_CHECK_HEADER([winsock.h])

  AC_MSG_CHECKING([for library flags required for network functions])
  AC_MSG_RESULT()
  AC_LANG_PUSH(C)
  saveLIBS="$LIBS"
  saveCFLAGS="$CFLAGS"
  CFLAGS=`echo $CFLAGS | sed -e 's/-pedantic-errors//'`
  ac_coin_found_socket_libraries=no
  case "$CC" in
    cl* | */cl* | CL* | */CL* | icl*)
      if test x$ac_cv_header_winsock_h = xyes ; then
	LIBS="wsock32.lib"
	AC_MSG_CHECKING(with "$LIBS")
	AC_LINK_IFELSE(
	  [AC_LANG_PROGRAM([[#include <winsock.h>]],[[socket(0,0,0)]])],
	  [WINSOCKLIBS="$LIBS"
	   ac_coin_found_socket_libraries=yes
	   AC_MSG_RESULT(yes)],
	  [AC_MSG_RESULT(no)])
      fi
      ;;
    *)
      if test x$ac_cv_header_winsock_h = xyes ; then
	for LIBS in "-lwsock32" \
		    "-L/lib -lwsock32" \
		    "-L/lib/w32api -lwsock32" \
		    "-L/mingw/lib -lwsock32" ; do
	  AC_MSG_CHECKING([with "$LIBS"])
	  AC_LINK_IFELSE(
	    [AC_LANG_PROGRAM([[#include <winsock.h>]],[[socket(0,0,0)]])],
	    [WINSOCKLIBS="$LIBS"
	     ac_coin_found_socket_libraries=yes
	     AC_MSG_RESULT(yes)
	     break],
	    [AC_MSG_RESULT(no)])
	done
      fi
      if test x$ac_coin_found_socket_libraries = xno &&
         test x$ac_cv_header_sys_socket_h = xyes ; then
	for LIBS in "" \
		    "-lsocket -lnsl" ; do
	  AC_MSG_CHECKING([with "$LIBS"])
	  AC_LINK_IFELSE(
	    [AC_LANG_PROGRAM([[#include <sys/socket.h>]],[[socket(0,0,0)]])],
	    [WINSOCKLIBS="$LIBS"
	     ac_coin_found_socket_libraries=yes
	     AC_MSG_RESULT(yes)
	     break],
	    [AC_MSG_RESULT(no)])
	done
      fi
      ;;
  esac
  AC_LANG_POP(C)
  # Warn if we didn't find anything.
  if test x$ac_coin_found_socket_libraries = xno} ; then
    AC_MSG_WARN([Can't determine network libraries!])
  fi
  LIBS="$saveLIBS"
  CFLAGS="$saveCFLAGS"
])
