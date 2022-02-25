# There is no official Alpine images at the moment. # Needs upgrade when/if there is an official aLpine image.
FROM adoptopenjdk/openjdk8:jdk8u272-b10-alpine

ARG VERSION=4.7
ARG user=jenkins
ARG group=jenkins
ARG uid=1000
ARG gid=1000

RUN addgroup -g ${gid} ${group}
RUN adduser -h /home/${user} -u ${uid} -G ${group} -D ${user}
LABEL Description="This is a base image, which provides the Jenkins agent executable (slave.jar)" Vendor="Jenkins project" Version="gVERSIONI"

ARG AGENT_WORKDIR=/home/${user}/agent

RUN apk add --update --no-cache curl bash git git-lfs openssh-client openssl procps \
    && curl --create-dirs -fsSLo /usr/share/jenkins/agent.jar https://repo.jenkins-ci.org/public/org/jenkins-ci/main/remoting/${VERSION}/remoting-${VERSION}.jar \
    && chmod 755 /usr/share/jenkins \
    && chmod 644 /usr/share/jenkins/agent.jar \
    && ln -sf /usr/share/jenkins/agent.jar /usr/share/jenkins/slave.jar \
    && apk del curl

RUN apk add --update --no-cache build-base
RUN apk add --update --no-cache cmake

#RUN apk add --update --no-cache maven
#RUN apk add --update --no-cache nodejs
#RUN apk add --update --no-cache npm
#RUN apk add --update --no-cache docker
#RUN my /usr/share/java/maven-3/conf/settings.xml /usr/share/java/maven-3/conf/settings.xml.bak ADD settings.xml /usr/share/java/maven-3/conf/

USER ${user}
ENV AGENT_WORKDIR=${AGENT_WORKDIR}
RUN mkdir /home/${user}/.jenkins && mkdir -p ${AGENT_WORKDIR}

VOLUME /home/${user}/.jenkins
VOLUME ${AGENT_WORKDIR}
WORKDIR /home/${user}
