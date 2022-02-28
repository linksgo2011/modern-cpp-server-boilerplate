ARG ALPINE_TAG=3.13.7
FROM alpine:$ALPINE_TAG

ARG VERSION=4.12
ARG user=jenkins
ARG group=jenkins
ARG uid=1000
ARG gid=1000
ARG SONAR_SCANNER_CLI_VERSION=4.6.2.2472

RUN addgroup -g ${gid} ${group}
RUN adduser -h /home/${user} -u ${uid} -G ${group} -D ${user}
LABEL Description="This is a base image, which provides the Jenkins agent executable (slave.jar)" Vendor="Jenkins project" Version="${VERSION}"

ARG AGENT_WORKDIR=/home/${user}/agent

# grant access to user
RUN chmod -R g+swrx /root/

RUN apk add --update --no-cache build-base
RUN apk add --update --no-cache cmake
RUN apk add --update --no-cache cppcheck
RUN apk add --update --no-cache zip unzip

RUN wget https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-${SONAR_SCANNER_CLI_VERSION}-linux.zip -q -O /tmp/sonar-scanner.zip \
    && unzip /tmp/sonar-scanner.zip -d /opt \
    && ln -s "/opt/sonar-scanner-${SONAR_SCANNER_CLI_VERSION}-linux/bin/sonar-scanner" /usr/local/bin/sonar-scanner \
    && rm /tmp/sonar-scanner.zip

RUN apk add --update --no-cache curl bash git git-lfs musl-locales openjdk8-jre-base openssh-client openssl procps \
  && curl --create-dirs -fsSLo /usr/share/jenkins/agent.jar https://repo.jenkins-ci.org/public/org/jenkins-ci/main/remoting/${VERSION}/remoting-${VERSION}.jar \
  && chmod 755 /usr/share/jenkins \
  && chmod 644 /usr/share/jenkins/agent.jar \
  && ln -sf /usr/share/jenkins/agent.jar /usr/share/jenkins/slave.jar

USER ${user}
ENV AGENT_WORKDIR=${AGENT_WORKDIR}
RUN mkdir /home/${user}/.jenkins && mkdir -p ${AGENT_WORKDIR}

VOLUME /home/${user}/.jenkins
VOLUME ${AGENT_WORKDIR}
WORKDIR /home/${user}