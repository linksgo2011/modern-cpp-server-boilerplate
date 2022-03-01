FROM gcc:11

ARG CMAKE_VERSION=3.20.5
ARG LLVM_VERSION=13.0.0
ARG SONAR_SCANNER_CLI_VERSION=4.6.2.2472
ARG ARM_GCC_VERSION=10.3-2021.10

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

RUN apt-get update && apt-get install -y lcov gcovr python

RUN wget https://github.com/llvm/llvm-project/releases/download/llvmorg-${LLVM_VERSION}/clang+llvm-${LLVM_VERSION}-x86_64-linux-gnu-ubuntu-20.04.tar.xz \
    -q -O /tmp/llvm.tar.xz \
    && tar -xf /tmp/llvm.tar.xz -C /opt \
    && ln -s "/opt/clang+llvm-${LLVM_VERSION}-x86_64-linux-gnu-ubuntu-20.04/bin/clang-tidy" /usr/local/bin/clang-tidy \
    && rm /tmp/llvm.tar.xz

RUN wget https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-${SONAR_SCANNER_CLI_VERSION}-linux.zip \
    -q -O /tmp/sonar-scanner.zip \
    && unzip /tmp/sonar-scanner.zip -d /opt \
    && ln -s "/opt/sonar-scanner-${SONAR_SCANNER_CLI_VERSION}-linux/bin/sonar-scanner" /usr/local/bin/sonar-scanner \
    && rm /tmp/sonar-scanner.zip

RUN apt install -y ruby-dev \
    && gem install cucumber -v 7.0.0 \
    && ln -s /var/lib/gems/2.7.0/gems/cucumber-7.0.0/bin/cucumber /usr/bin/cucumber

RUN wget https://bootstrap.pypa.io/pip/2.7/get-pip.py \
    -q -O /tmp/get-pip.py \
    && python /tmp/get-pip.py \
    && pip install pyyaml \
    && rm /tmp/get-pip.py \
    && apt-get install -y python-dev \
    && pip install regex==2021.11.10