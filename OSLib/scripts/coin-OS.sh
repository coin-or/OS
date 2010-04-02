#!/bin/sh
## Copyright (c) 2008,2010 Timothy Middelkoop, All rights reserved.
## Dual Licensed under the GPL 2.0 and the CPL

## Based on build COIN-OR from build-ps3
## Check scripts/install-packages-* for build dependencies

ARCH="$(uname -s)-$(uname -m)"

## Defaults
VERSION=trunk
BRANCH=trunk
OPTIONS="--enable-static --disable-shared"

## Composite variables
COINSRC=build/CoinOS-${VERSION}
COINTGZ=download/CoinOS-${VERSION}.tar.gz

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
install -v build/CoinOS-trunk/OS/src/OSSolverService-${ARCH} lib/coin-or

echo @@@ cleanup
rm -rf ${COINSRC}

echo @@@ done
