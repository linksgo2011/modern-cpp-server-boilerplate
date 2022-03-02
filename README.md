# modern-cpp-server-boilerplate
Modern C++ boilerplate project for server side. 

# how to run 

Install all dependencies and rebuild.

> conan install .. --settings compiler="clang" --settings compiler.version=11 --build=missing
Generate make file with coverage flag
> cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="--coverage" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
or 
> make 

run test

> ctest

Generate test coverage

>  gcovr --root .. . --exclude third_parts --sonarqube > ../coverage.xml

## demo description

Provide md5 calculation  via http.

## feature

- Cmake
- Gcc
- conan
- Google Test
- cppcheck & sonar 
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
8. Static check https://baptiste-wicht.com/posts/2017/03/clang-tidy-static-analysis-integration-in-sonarqube.html
9. https://github.com/google/googletest
10. https://github.com/jhbell/cmake-gcov
11. https://github.com/google/styleguide
12. https://cmake.org/cmake/help/latest/guide/tutorial/index.html
13. https://blog.csdn.net/u013187057/article/details/85222007

## troubles

** sonar bin issue  **

https://stackoverflow.com/questions/70117670/sonar-scanner-cli-4-2-does-not-find-jre-bin-java


** max virtual memory areas vm.max_map_count [65530] is too **

> colima ssh
> sysctl -w vm.max_map_count=262144
> 

** Sonar need openjdk11 **

Sonar scanner need jdk11, otherwise will get some jdk issue.

** gcov need define output format **

if you give --xml parameter to gcov, gcov will build standard cobertura report. 

if yuo give --sonarqube parameter, gcov will build special report for sonar.

but if you installed sonar cxx plugin and use --sonarqube parameter, sonar cxx plugin will still deal report with cobertura format.

