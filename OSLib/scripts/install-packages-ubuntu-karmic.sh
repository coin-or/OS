#!/bin/sh

## Copyright 2010 Timothy Middelkoop.  
## Licensed under the Common Public License Version 1.0 or later.

## Install JAR files for Ubuntu karmic
## Note this installs tomcat6 which web server

ARCH="$(uname -s)-$(uname -m)"

JAVA_PACKAGES="
openjdk-6-jre-headless
tomcat6
tomcat6-user
libservlet2.4-java
libxerces2-java
libcommons-fileupload-java
libcommons-logging-java
libcommons-io-java
libcommons-discovery-java
libcommons-codec-java
libaxis-java
libsaxonb-java
liblog4j1.2-java
"

BUILD_PACKAGES="
build-essential
file
"

OS_PACKAGES="
gfortran
libatlas-base-dev
liblapack-dev
libpopt-dev
"

case "${ARCH}" in
  Linux-i686)
    OS_ARCH_PACKAGES="libatlas-sse2-dev"
    ;;
esac

echo Script must be run as root.

echo @@@ Java Packages
apt-get $* install $JAVA_PACKAGES
echo @@@ COIN-OR OS Packages
apt-get $* install $OS_PACKAGES $OS_ARCH_PACKAGES
echo @@@ Compiler Packages
apt-get $* install $BUILD_PACKAGES

echo @@@ Disable system tomcat6
rm -vf /etc/rc?.d/S??tomcat6
/etc/init.d/tomcat6 stop
echo @@@ done
