#!/bin/sh

TOMCAT=../Servers/tomcat6

if [ ! -d ${TOMCAT} ] ; then
  echo "install tomcat6"
  install -d $(dirname ${TOMCAT})
  tomcat6-instance-create $TOMCAT
  ln -s /usr/share/tomcat6/bin/bootstrap.jar $TOMCAT/bin
  cat /etc/tomcat6/policy.d/* > $TOMCAT/conf/catalina.policy
  ln -s /usr/share/tomcat6/lib $TOMCAT
  echo @@@ "install complete"
fi
