# modern-cpp-server-boilerplate
Modern C++ boilerplate project for server side. 

# how to run 

Install all dependencies and rebuild.

> conan install .. --settings compiler="clang" --settings compiler.version=11 --build=missing

> cmake --build build
or 
> make 

run test

> ctest

## demo description

Provide md5 calculation  via http.

## feature

- Cmake
- Gcc
- conan
- Google Test <<<<<<
- gcov
- CppLint
- Docker file
- Jenkins file
- Sonar Qube

## reference 

**template project**

1. https://github.com/imefisto/cpp-server-boilerplat
2. https://github.com/bsamseth/cpp-project

**real project**

1. https://github.com/thoughtworks-hpc/cdcf
2. https://github.com/shenfeng/tiny-web-server
3. https://github.com/eidheim/Simple-Web-Server

**reading list**

1. https://seisman.github.io/how-to-write-makefile/
2. E-Book about Cmake https://cliutils.gitlab.io/modern-cmake
3. https://docs.conan.io/en/latest/getting_started.html
4. https://conan.io/center 
5. https://cmake.org/
6. https://github.com/google/googletest
7. https://github.com/google/styleguide
8. https://cmake.org/cmake/help/latest/guide/tutorial/index.html
9. https://blog.csdn.net/u013187057/article/details/85222007