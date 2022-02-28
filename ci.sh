#!/bin/sh
set -e

BASEDIR=$(dirname "$0")
cd $BASEDIR

check() {
  # code check
  cppcheck --xml-version=2 . 2> report.xml

  # sonar report
  sonar-scanner -Dsonar.login=57e10da238ad6c9308ec444eacd03ba8c25ca735
}

case $1 in
check | test | build | deploy)
  $1
  ;;
*)
  echo "not support!!! example: go <check | test | build | deploy>"
  exit 1
  ;;
esac
