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

![image-20220224101745039](/Users/nlin/www/modern-cpp-server-boilerplate/doc/README-zh/image-20220224101745039.png)

3 ） 填写相关参数

有两个需要注意：

1. 远程工作目录
2. 启动方式应该使用 Java Web 启动代理

远程工作目录在 Window 下使用类似 c:\jenkins 的路径即可。

操作完成，保存然后下一步。

4 ）连接代理

**进入代理机** 安装 JDK 8，登录 Jenkins 进入节点管理详情，详情中会展示两种启动连接方式，推荐使用 “在命令行中启动节点”。

![image-20220224102331214](/Users/nlin/www/modern-cpp-server-boilerplate/doc/README-zh/image-20220224102331214.png)

首先点击 agent.jar 下载文件，放到合适的目录后。运行后面的命令启动即可。

## 2. 包管理

包管理有下面几种方法

1. Conan
2. 放到代码库中
3. 放到单独的代码库，使用 git submodule



