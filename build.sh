#!/bin/bash

# cmake build
# TODO

# code check
cppcheck --xml-version=2 . 2> report.xml

