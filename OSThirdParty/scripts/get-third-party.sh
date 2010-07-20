#!/bin/sh

## Copyright 2010 Timothy Middelkoop.  
## Licensed under the Common Public License Version 1.0 or later.
##
## This file unpacks external libraries.
## Consult individual jar files for license information.
##
## This is not a script, it's executable documentation.
## Feel free to apply some script-foo on it.

## Preliminaries.
install -d download/
install -d lib/
: ${WGET:=wget -c}

echo "scripts/get-third-party.sh"
set -e

## COIN-OR OS
DEST=lib/coin-or
install -d ${DEST}

## Fastutil
URL=http://fastutil.dsi.unimi.it/
JAR=fastutil-5.1.5
DEST=lib/fastutil
MIRROR=http://fastutil.dsi.unimi.it/${JAR}-bin.tar.gz
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${JAR}-bin.tar.gz ] ; then
    echo "Downloading ${JAR} from ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  tar -xzf download/${JAR}-bin.tar.gz --strip-components 1 -C ${DEST} \
    ${JAR}/COPYING.LIB \
    ${JAR}/README \
    ${JAR}/CHANGES \
    ${JAR}/fastutil-5.1.5.jar
fi

## Xerces
URL=http://xerces.apache.org/xerces2-j/install.html
DOWNLOAD=Xerces-J-bin.2.10.0
VERSION=xerces-2_10_0
JAR=xercesImpl
DEPENDENTJAR=xml-apis
DEST=lib/xerces
MIRROR=http://apache.cyberuse.com/xerces/j/${DOWNLOAD}.zip
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Downloading ${JAR} from ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  unzip -jq -d ${DEST} download/${DOWNLOAD}.zip ${VERSION}/${JAR}.jar ${VERSION}/${DEPENDENTJAR}.jar "${VERSION}/LICENSE*" "${VERSION}/NOTICE*" 
fi

## Apache Commons Codec
URL=http://commons.apache.org/codec/
DOWNLOAD=commons-codec-1.4-bin
JAR=commons-codec-1.4
DEST=lib/commons-codec
MIRROR=http://apache.deathculture.net/commons/codec/binaries/${DOWNLOAD}.zip
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Downloading ${JAR} from ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  unzip -jq -d ${DEST} download/${DOWNLOAD}.zip ${JAR}/${JAR}.jar "${JAR}/*.txt"
fi

## Apache Commons Fileupload
URL=http://commons.apache.org/fileupload/
DOWNLOAD=commons-fileupload-1.2.1-bin
JAR=commons-fileupload-1.2.1
DEST=lib/commons-fileupload
MIRROR=http://www.fightrice.com/mirrors/apache/commons/fileupload/binaries/${DOWNLOAD}.zip
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Downloading ${JAR} from ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  unzip -jq -d ${DEST} download/${DOWNLOAD}.zip ${JAR}/lib/${JAR}.jar "${JAR}/*.txt"
fi

## Apache Commons Logging
URL=http://commons.apache.org/logging/
DOWNLOAD=commons-logging-1.1.1-bin
JAR=commons-logging-1.1.1
DEST=lib/commons-logging
MIRROR=http://www.ecoficial.com/apachemirror/commons/logging/binaries/${DOWNLOAD}.zip
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Downloading ${JAR} from  ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  unzip -jq -d ${DEST} download/${DOWNLOAD}.zip ${JAR}/${JAR}.jar "${JAR}/*.txt" -x "${JAR}/site/*"
fi

## Apache Commons Mail
URL=http://commons.apache.org/email/
DOWNLOAD=commons-email-1.2-bin
JAR=commons-email-1.2
DEST=lib/commons-email
MIRROR=http://apache.securedservers.com/commons/email/binaries/${DOWNLOAD}.zip
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Downloading ${JAR} from  ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  unzip -jq -d ${DEST} download/${DOWNLOAD}.zip ${JAR}/${JAR}.jar "${JAR}/*.txt"
fi

## Apache Commons Discovery
URL=http://commons.apache.org/discovery/
DOWNLOAD=commons-discovery-0.4
JAR=commons-discovery-0.4
DEST=lib/commons-discovery
MIRROR=http://apache.cyberuse.com/commons/discovery/binaries/${DOWNLOAD}.zip
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Downloading ${JAR} from  ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  unzip -jq -d ${DEST} download/${DOWNLOAD}.zip ${JAR}/${JAR}.jar "${JAR}/*.txt"
fi

## Apache log4j
URL=http://logging.apache.org/log4j/1.2/
VERSION=1.2.15
DOWNLOAD=apache-log4j-${VERSION}
JAR=log4j-${VERSION}
DEST=lib/log4j
MIRROR=http://mirror.cloudera.com/apache/logging/log4j/${VERSION}/${DOWNLOAD}.zip
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Downloading ${JAR} from  ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  unzip -jq -d ${DEST} download/${DOWNLOAD}.zip ${DOWNLOAD}/${JAR}.jar "${DOWNLOAD}/LICENSE*" "${DOWNLOAD}/NOTICE*"
fi


NAME='SaxonB v9'
URL=http://saxon.sourceforge.net/
DOWNLOAD=saxonb9-1-0-8j
JAR=saxon9
DEST=lib/saxon
MIRROR='http://downloads.sourceforge.net/project/saxon/Saxon-B/9.1.0.8/saxonb9-1-0-8j.zip?use_mirror=superb-sea2'
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Downloading ${JAR} from  ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  unzip -jq -d ${DEST} download/${DOWNLOAD}.zip ${JAR}.jar ${JAR}-xpath.jar  "notices/*"
fi

NAME='Java Axis 1.4'
URL=http://ws.apache.org/axis/
DOWNLOAD=axis-bin-1_4
VERSION=axis-1_4
JAR=axis
DEST=lib/axis
MIRROR=http://www.reverse.net/pub/apache/ws/axis/1_4/${DOWNLOAD}.zip
if [ ! -r ${DEST}/${JAR}.jar ] ; then
  if [ ! -r download/${DOWNLOAD}.zip ] ; then
    echo "Downloading ${JAR} from  ${URL}"
    ${WGET} ${MIRROR} -P download
  fi
  echo "Installing ${DEST}"
  install -d ${DEST}
  unzip -jq -d ${DEST} download/${DOWNLOAD}.zip ${VERSION}/lib/${JAR}.jar ${VERSION}/lib/jaxrpc.jar ${VERSION}/lib/saaj.jar ${VERSION}/lib/wsdl4j-*.jar "${VERSION}/LICENSE*" "${VERSION}/NOTICE*"
fi

echo "scripts/get-third-party.sh successful"
