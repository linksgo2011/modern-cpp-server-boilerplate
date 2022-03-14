FROM centos:centos7

RUN yum update -y && yum -y install centos-release-scl epel-release wget git zip unzip java-11-openjdk-devel \
gcc gcc-c++ make kernel-devel cmake python3-pip
RUN yum install -y cppcheck
RUN pip3 install gcovr conan
WORKDIR /root

# install sonar scanner
ARG SONAR_SCANNER_CLI_VERSION=4.6.2.2472
RUN wget https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-${SONAR_SCANNER_CLI_VERSION}-linux.zip \
    -q -O /tmp/sonar-scanner.zip \
    && unzip /tmp/sonar-scanner.zip -d /opt \
    && ln -s "/opt/sonar-scanner-${SONAR_SCANNER_CLI_VERSION}-linux/bin/sonar-scanner" /usr/local/bin/sonar-scanner \
    && rm /tmp/sonar-scanner.zip

ENV SONAR_RUNNER_HOME=/root/sonar-scanner-$SONAR_SCANNER_CLI_VERSION-linux
ENV PATH $PATH:/root/sonar-scanner-$SONAR_SCANNER_CLI_VERSION-linux/bin