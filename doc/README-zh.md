# 文档

## 1. 流水线基础设施搭建

常用的流水线基础设施有：

1. CI 平台：Jenkins 
2. 质量分析：Sonarqube
3. 代码管理：Gitlab
4. 制品库：Nexus 

在 Linux 上本地启动可以使用 Docker Compose，参考 cicd 目录中的配置文件即可启动，如果已经有相关环境略过。

### Windows 节点配置方法

在 Windows 运行构建任务可以配置 Windows 节点。



1） 开通防火墙


- Slave →  Master 默认 50000（全局安全配置→代理 查看）
- Master → Slave 和 Jenkins web 端口一致，比如 80、443

建议互通，也就是相互端口都开

2）创建节点

进入 Dashboard → 节点列表 → 新建节点。

![image-20220224101745039](./README-zh/image-20220224101745039.png)

3 ） 填写相关参数

有两个需要注意：

1. 远程工作目录
2. 启动方式应该使用 Java Web 启动代理

远程工作目录在 Window 下使用类似 c:\jenkins 的路径即可。

操作完成，保存然后下一步。

4 ）连接代理

**进入代理机** 安装 JDK 8，登录 Jenkins 进入节点管理详情，详情中会展示两种启动连接方式，推荐使用 “在命令行中启动节点”。

![image-20220224102331214](./README-zh/image-20220224102331214.png)

首先点击 agent.jar 下载文件，放到合适的目录后。运行后面的命令启动即可。

## 2. 包管理

C++ 有两种包，一种进静态库需要和源码一起编译，一种是编译完成了的包。

包管理有下面几种方法

1. Conan
2. 放到代码库中 
3. 放到单独的代码库，使用 git submodule，根据 C++ 的实际情况，推荐这种做法。

如果使用 submodule 可以使用下面的命令：

> ```console
> git submodule add [仓库地址]
> ```

## 3. Sonar C++ 插件安装

Sonar 上提供了一些商业插件比如 SonarCFamily 可以使用，也可以使用开源插件。

我们可以使用 sonar-cxx，为社区版添加 C++支持，也可以使用 Sonar Cloud，但是 Sonar Cloud 需要单独配置。

插件安装文档见：https://github.com/SonarOpenCommunity/sonar-cxx/wiki/Install-the-Plugin  特别注意兼容性清单。

如果使用 Docker 启动，可以下载相关插件后使用下面的命令，将插件拷贝到 Sonar 的对应目录中。（操作前最好备份一下 sonar 的数据库）。

>  docker cp [插件位置]   [容器 ID]:/opt/sonarqube/extensions/plugins

安装完成后，可以在 Administration → Marketplace → Plugins 找到。

![image-20220224115434701](./README-zh/image-20220224115434701.png)

## 4. 静态扫描



##### 创建 Sonar 项目

进入 projects → Create Project，设置相关的 ID、Key，在上报 Sonar 的时候需要用到。

![image-20220301093758404](./README-zh/image-20220301093758404.png)

##### 使用 sonar-scanner 

上报报告需要先安装，在 Mac 上测试可以使用 Brew，如果使用构建机或者镜像相关软件已经配置好。：

> Brew install sonar-scanner

**clang-format**

代码风格检查

TODO 

##### 使用 cppcheck 扫描

 cppcheck 可以检测 cxx 代码潜在的问题，生成 xml 报告，然后使用 sonar-scanner 上报。

安装地址：https://cppcheck.sourceforge.io/

使用方式：

```
# code check
cppcheck --xml-version=2 . 2> report.xml

# sonar report
sonar-scanner -Dsonar.login=57e10da238ad6c9308ec444eacd03ba8c25ca735
```

##### Sonar 的规则配置

安装完成 Sonar CXX 后，Sonar 平台上会出现很多的规则，这些规则可以在 profiles 中找到。

但是这些内置的规则可能没有激活，所以即使上传了扫描结果也不能看到。

可以在 profiles 页面右上角进行创建一个自定义规则，并根据内置的 CXX 语言作为基础。

![image-20220301093417042](./README-zh/image-20220301093417042.png)

配置完成后，在相关的项目中也需要配置。

![image-20220301093856295](./README-zh/image-20220301093856295.png)

## 5. 构建运行节点方案

由于每个项目不同，需要不同的构建方案。

1. Linux 可以使用配置不同的 docker 来进行构建
2. Win 使用 Windows 节点即可

Linux 构建节点工具清单

- cmake
- g++/clang 
- Cppcheck
- SonarQube Scanner
- 其他依赖文件



##### Docker 镜像构建

准备 Dockerfile 如下：

```dockerfile
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
```

使用命令：

>  docker build -t  builder/gcc:latest   .

##### 添加 Docker 构建节点

将 Docker 镜像制作好后，可以作为 Jenkins 的 Slave 使用，使用 Docker 的 2375 端口配置好相关容器执行的 Host 机器。 Jenkins 会自动到目标机上启动这个镜像，然后在容器中进行构建。

需要安装 Docker 插件。

![image-20220301094903457](./README-zh/image-20220301094903457.png)

需要配置相关的参数：

![image-20220301094940349](./README-zh/image-20220301094940349.png)

目标机的配置，本地练习可以使用 sock 来和 Docker 服务通信。

![image-20220301095051095](./README-zh/image-20220301095051095.png)

这里需要提示的是如果 Docker 是通过 colima  启动的，需要使用 Colima 中的 sock。

启动参数可以配置Agent 标签、使用的镜像、拉取规则和进入容器的方式。

##### 注意事项

1. 必须使用 Centos 作为镜像基础，不能使用 Alpine 作为基础镜像，没有 glibc
2. 相关依赖也需要在同样的平台上编译，并且使用相同的版本

##### 在本地调试的方法

在本地可以通过映射磁盘文件的方式使用 Docker 中的虚拟环境构建宿主机的代码，以及调试。例如：

> docker run -it -v /Users/nlin/www/cgsc/dma_domestic:/home/jenkins/myapp da8b6e855d3a  /bin/sh

## 6. Gtest



构建 gtest 包 

https://codeload.github.com/google/googletest/zip/refs/tags/release-1.11.0

##### gtest 版本问题

1. gtest 1.8 后的版本不支持 c11 前的编译器，要求使用 G++ 5 以上编译

##### ctest 技巧

1. 打印出相关错误日志 ctest -VV
2. c++ 不能使用依赖注入，因此需要手动管理相关的 mock 对象



## 7. C++ 制品管理

使用 Nexus OSS 即可进行管理，直接使用 CURL 编写制品上传脚本即可实现制品管理，制品格式为 ZIP 包。

##### 创建制品库

包管理可以使用 Conan 但是制品在发布时并不需要 Conan 的构建脚本以及源代码，因此可以直接使用二进制文件即可。

![image-20220307164443252](./README-zh/image-20220307164443252.png)

创建完成后，可以获取制品库地址：http://10.4.6.232:8081/repository/cxx-artifact/

##### 上传制品

如果使用了特定的格式，比如 npm、mvn 可以用这些工具，如果是无格式的制品，可以使用 curl 上传。

cxx 项目可以使用 curl 上传 zip 包管理制品。

参考下面的代码：

```
   zip dma_rootnet_acess_0.0.1.zip  dma_rootnet_access/build/dma_rootnet_access.so
   curl -v -u admin:**** --upload-file dma_rootnet_acess_0.0.1.zip  http://10.4.6.232:8081/repository/cxx-artifact/
```



## 技术选型清单



|             |   推荐方案   |  工具    |  备选   |   备注   |      |
| ----------- | ---- | ---- | ---- | ---- | ---- |
| 代码管理 | 使用现存的 Gitlab 作为代码管理方案 | Gitlab | SVN |      |      |
| 包管理 | 由于 C++ 的包管理现状使用 Git submodule 比较合适 | Git | conan/nexus |      |      |
| 构建平台    | 使用现存构建平台，参考之前的默认实现和风格 | Jenkins |      |      |      |
| 构建环境    | Windows: 复用存在的环境作为 |      |      |      |      |
| 代码检查    |      |      |      |      |      |
| 测试        |      |      |      |      |      |
| 制品        |      |      |      |      |      |
| 发布        |      |      |      |      |      |
|             |      |      |      |      |      |
|             |      |      |      |      |      |

