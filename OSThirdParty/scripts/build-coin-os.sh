#!/bin/sh
## Copyright (c) 2008,2010 Timothy Middelkoop, All rights reserved.
## Licenced under the Common Public License (CPL) version 1.0 or later.

## Build COIN-OS from SVN, based on build COIN-OR from build-ps3

## Defaults
VERSION=trunk
BRANCH=trunk
OPTIONS="--enable-static --disable-shared"

## Composite variables
COINSRC=build/CoinOS-${VERSION}
COINTGZ=download/CoinOS-${VERSION}.tar.gz

## Arch

ARCH="$(uname -s)-$(uname -m)"
case ${ARCH} in
Darwin-i386)
    ARCH=mac-osx-x86_64
    OPTIONS="${OPTIONS} ADD_FFLAGS=-mmacosx-version-min=10.4"
    ;;
Linux-x86_64)
    ARCH=linux-x86_64
    ;;
Linux-i?86)
    ARCH=linux-x86
    ;;
esac

## DO NOT REDISTRUBTE BINARIES THAT CONTAIN GPL CODE (GLPK)
## Default to redistributable code
OPTIONS="${OPTIONS} COIN_SKIP_PROJECTS=ThirdParty/Glpk"

set -e
install -dv build download

if [ ! -d $COINSRC ] && [ -r $COINTGZ ] ; then
  echo @@@ unpack
  tar -xzf $COINTGZ
fi

if [ ! -d $COINSRC ] ; then
  echo @@@ checkout
  svn checkout https://projects.coin-or.org/svn/OS/${BRANCH} ${COINSRC}
fi

if [ ! -r $COINTGZ ] ; then
  echo @@@ create mirror
  tar -czf $COINTGZ $COINSRC
fi

echo @@@ third party
(cd $COINSRC ; ./get.AllThirdParty )

echo @@@ configure
(cd $COINSRC ; ./configure ${OPTIONS} )

echo @@@ make
(cd $COINSRC ; make )

echo @@@ install
install -dv lib/coin-or
install -v build/CoinOS-trunk/OS/src/OSSolverService lib/coin-or/OSSolverService
install -v build/CoinOS-trunk/OS/src/OSSolverService lib/coin-or/OSSolverService-${ARCH}

echo @@@ cleanup
rm -rf ${COINSRC}

echo @@@ build-coin-os.sh done for ${ARCH}
