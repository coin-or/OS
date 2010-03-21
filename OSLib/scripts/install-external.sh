#!/bin/sh

## Copyright 2010 Timothy Middelkoop.  
## Licensed under the Common Public License Version 1.0 or later.

## This file retrieves external jar files.
## Consult individual jar files for license information.

## Download packages to the 'download' directory
install -d download/
install -d lib/

## Fastutil: http://fastutil.dsi.unimi.it/
JAR=fastutil-5.1.5
DEST=lib/fastutil
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${JAR}-bin.tar.gz ] ; then
    echo "Please download the 'binary tarball' ${JAR}-bin.tar.gz to download from"
    echo "  http://fastutil.dsi.unimi.it/"
    #@ wget -c http://fastutil.dsi.unimi.it/${JAR}-bin.tar.gz -P download
  else
    echo "installing ${DEST}"
    install -d ${DEST}
    tar -xzf download/${JAR}-bin.tar.gz --strip-components 1 -C ${DEST} \
      ${JAR}/COPYING.LIB \
      ${JAR}/README \
      ${JAR}/CHANGES \
      ${JAR}/fastutil-5.1.5.jar
  fi
fi

## Opsresearch
## http://opsresearch.com/OR-Objects/download/license.html
## http://opsresearch.com/cgi-bin/freeware.cgi/or124.jar

JAR=or124
DEST=lib/opsresearch
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${JAR}.jar ] ; then
    echo "Please download ${JAR}.jar to download from"
    echo "  http://opsresearch.com/cgi-bin/freeware.cgi/or124.jar"
    #@ wget -c http://opsresearch.com/OR-Objects/download/license.html -P ${DEST}
    #@ wget -c "http://opsresearch.com/cgi-bin/freeware.cgi/${JAR}.jar?Download=Download" -O download/${JAR}.jar
  else
    echo "installing ${DEST}"
    install -d ${DEST}
    cp -a download/${JAR}.jar ${DEST}/${JAR}.jar
  fi
fi

## Java Mail
# http://java.sun.com/products/javamail/downloads/index.html

DOWNLOAD=javamail-1.4.3
JAR=mail
DEST=lib/javamail
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Please download ${DOWNLOAD}.zip to download from"
    echo "  http://java.sun.com/products/javamail/downloads/index.html"
  else
    echo "installing ${DEST}"
    install -d ${DEST}
    unzip -jWq -d ${DEST} download/${DOWNLOAD}.zip ${DOWNLOAD}/mail.jar "${DOWNLOAD}/*.txt"
  fi
fi

## JAXB: https://jaxb.dev.java.net/
# wget -P lib/jaxb https://jaxb.dev.java.net/2.1.12/JAXB2_20090708.jar 
# (cd lib/jaxb ; java -jar JAXB2_20090708.jar )
