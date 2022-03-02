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

build(){
    mkdir build && cd build
    conan install .. --build missing
    cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="--coverage" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
    make
}

unitTest(){
   ctest
   gcovr --root .. . --exclude third_parts --sonarqube > ../coverage.xml

   # report coverage to sonar
  echo 'return to root path and run sonar-scanner report'
  cd ..
  sonar-scanner -Dsonar.login=57e10da238ad6c9308ec444eacd03ba8c25ca735 -Dsonar.cxx.cobertura.reportPaths=coverage.xml
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
