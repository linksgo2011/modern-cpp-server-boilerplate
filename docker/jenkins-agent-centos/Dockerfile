FROM centos:centos7

RUN yum update -y && yum -y install centos-release-scl epel-release git zip unzip java-11-openjdk-devel &&\
    gcc gcc-c++  make kernel-devel &&\
	cmake cppcheck python3-pip gcovr conan

WORKDIR /root

# install sonar scanner
ARG SONAR_SCANNER_CLI_VERSION=4.6.2.2472
RUN set -x &&\
  curl --insecure -o ./sonarscanner.zip -L https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-$SONAR_SCANNER_CLI_VERSION-linux.zip &&\
  unzip sonarscanner.zip &&\
  rm sonarscanner.zip &&\
  rm sonar-scanner-$SONAR_SCANNER_CLI_VERSION-linux/jre -rf

ENV SONAR_RUNNER_HOME=/root/sonar-scanner-$SONAR_SCANNER_CLI_VERSION-linux
ENV PATH $PATH:/root/sonar-scanner-$SONAR_SCANNER_CLI_VERSION-linux/bin