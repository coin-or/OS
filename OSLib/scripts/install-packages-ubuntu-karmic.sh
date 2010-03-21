#!/bin/sh

## Copyright 2010 Timothy Middelkoop.  
## Licensed under the Common Public License Version 1.0 or later.

## Install JAR files for Ubuntu karmic
## Note this installs tomcat6 which web server

PACKAGES="
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

sudo apt-get install $PACKAGES;
