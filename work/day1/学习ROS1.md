#学习ROS1#

1、我的教程是根据ROSWiKi来学习的。

2、登录ROS官网，根据自己的ubuntu系统版本下载安装ROS。

3、根据官网指示配置环境。

4、创建ROS的工作空间。

5、mkdir -p ~/catkin_ws/src ——创建工作空间命令。

6、cd ~/catkin_ws/ ——挂载当前盘符为catkin_ws。

7、catkin_make编译处理。

8、保证工作区被安装脚本正确覆盖，，确定ROS_PACKAGE_PACK环境变量包含你当前工作空间目录。

9、
`echo $ROS_PACKAGE_PACK`
`
/home/<username>/catkin_ws/src:/opt/ros/<distro>/share
`
