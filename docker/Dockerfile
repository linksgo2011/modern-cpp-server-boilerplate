FROM gcc:11

ARG CMAKE_VERSION=3.20.5
ARG LLVM_VERSION=13.0.0
ARG SONAR_SCANNER_CLI_VERSION=4.6.2.2472

RUN wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-Linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /usr/bin/cmake \
      && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
      && rm /tmp/cmake-install.sh \
      && ln -s /usr/bin/cmake/bin/ccmake /usr/local/bin/ccmake \
      && ln -s /usr/bin/cmake/bin/cmake /usr/local/bin/cmake \
      && ln -s /usr/bin/cmake/bin/cpack /usr/local/bin/cpack \
      && ln -s /usr/bin/cmake/bin/ctest /usr/local/bin/ctest

# TODO add more tools

