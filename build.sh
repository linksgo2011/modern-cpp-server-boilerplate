#!/bin/bash

# cmake build
# TODO

# code check
cppcheck --xml-version=2 . 2> report.xml

# sonar report
sonar-scanner -Dsonar.login=57e10da238ad6c9308ec444eacd03ba8c25ca735