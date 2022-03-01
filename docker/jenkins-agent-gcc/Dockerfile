ARG ALPINE_TAG=3.13.7
FROM alpine:$ALPINE_TAG

RUN apk add --update --no-cache curl bash git git-lfs openjdk11 build-base cmake cppcheck zip unzip

WORKDIR /root

# install sonar scanner
ARG SONAR_SCANNER_CLI_VERSION=4.6.2.2472
RUN set -x &&\
  curl --insecure -o ./sonarscanner.zip -L https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-$SONAR_SCANNER_CLI_VERSION-linux.zip &&\
  unzip sonarscanner.zip &&\
  rm sonarscanner.zip &&\
  rm sonar-scanner-$SONAR_SCANNER_CLI_VERSION-linux/jre -rf &&\
#   ensure Sonar uses the provided Java for musl instead of a borked glibc one
  sed -i 's/use_embedded_jre=true/use_embedded_jre=false/g' /root/sonar-scanner-$SONAR_SCANNER_CLI_VERSION-linux/bin/sonar-scanner

ENV SONAR_RUNNER_HOME=/root/sonar-scanner-$SONAR_SCANNER_CLI_VERSION-linux
ENV PATH $PATH:/root/sonar-scanner-$SONAR_SCANNER_CLI_VERSION-linux/bin