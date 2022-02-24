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
- Google Test
- cppcheck & sonar  <<<<<<
- gcov
- Docker file
- Jenkins file
- Sonar Qube

## reference 

**template project**

1. https://github.com/imefisto/cpp-server-boilerplate
2. https://github.com/bsamseth/cpp-project

**real project**

1. https://github.com/thoughtworks-hpc/cdcf
2. https://github.com/shenfeng/tiny-web-server
3. https://github.com/eidheim/Simple-Web-Server

**reading list**

1. https://www.runoob.com/cplusplus/cpp-environment-setup.html
2. Moder CPP basic https://github.com/hisamuka/a-tour-of-cpp
3. https://seisman.github.io/how-to-write-makefile/
4. E-Book about Cmake https://cliutils.gitlab.io/modern-cmake
5. https://docs.conan.io/en/latest/getting_started.html
6. https://conan.io/center 
7. https://cmake.org/
8.  Static check https://baptiste-wicht.com/posts/2017/03/clang-tidy-static-analysis-integration-in-sonarqube.html
9. https://github.com/google/googletest
10. https://github.com/google/styleguide
11. https://cmake.org/cmake/help/latest/guide/tutorial/index.html
12. https://blog.csdn.net/u013187057/article/details/85222007