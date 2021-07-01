# 虚拟机ubuntu的安装 #
1、百度搜索需要安装的Ubuntu镜像，根据电脑的配置和使用需求选择Ubuntu的版本。

2、安装虚拟机软件VMware Workstation Pro，根据使用需求选择虚拟机配置。

3、给虚拟机安装VMware Tools软件，这样软件就可以在屏幕上全屏显示，并且可以把window上的文件直接拖进虚拟机，反之亦然。

4、给虚拟机添加清华大学的下载源，这样在国内也可以享受国内安装国外的软件的带宽。

5、将虚拟机默认语言选择为简体中文或者自己适用的语言。

6、添加中文输入法。

7、安装谷歌浏览器或者Microsoft edge浏览器并安装所需的服务插件。

# 第一天遇到的问题 #

1、利用ibus输入法不好用，可以给ibus添加搜狗输入法词库。

2、安装ROS时可能会有出现：

``draven@ubuntu:~$ sudo rosdep init
``

``[sudo] draven 的密码： 
``
``ERROR: cannot download default sources list from:https://raw.github.com/ros/rosdistro/master/rosdep/sources.list.d/20-default.list
Website may be down.
``

这个时候需要手动创建20-default.list文件，然后把别人的内容复制进去。

解决方法：https://blog.csdn.net/qq_36498362/article/details/107187006

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

#ROS学习2#

##ROS文件系统导览##

1、``$ rospack find （package_name）``

这个命令可以在输出流中得到软件包的路径。

2、``$ roscd （locationname[/subdir]）``

这个命令可以切换当前路径为软件包的路径。

3、``$ echo $ROS_PACKAGE_PATH``

这个命令的作用是显示ROS软件包的环境。

4、``roscd``

这个命令作用是切换当前目录为ROS的软件包或者软件包集目录中。

5、``roscd log``

这个命令的作用是进入到存储ROS日志文件的目录中。

6、``rosls``

``$ rosls [locationname[/subdir]]``  

这个命令和ls差不多，不过这个命令不需要绝对路径，他会像ls一样在相对目录显示目录里面的内容。

7、tab按键可以补全ROS的专用名词。

# 学习ROS3 #
## catkin软件包的组成 ##
1、符合catkin的package.xml文件（提供软件包源信息）。

2、catkin版本的CMakeLists.txt文件。

3、每个包都有自己单独的目录。

开发catkin软件包的方法是使用catkin工作空间：

``workspace_folder/        -- WORKSPACE//工作空间主目录``

``src/                   -- SOURCE SPACE//源空间``

``CMakeLists.txt       -- 'Toplevel' CMake file, provided by catkin
			//高等级CMake文件，由catkin提供。``

``package_1/
``

``CMakeLists.txt     -- CMakeLists.txt file for package_1//软件包1的CMake清单。``

``package.xml        -- Package manifest for package_1//软件包1的软件包XML描述文件。``

``...``

``package_n/``

``CMakeLists.txt     -- CMakeLists.txt file for package_n``

``package.xml        -- Package manifest for package_n``

4、``catkin_create_pkg``
这个命令的作用是创建一个软件包。

``$ catkin_create_pkg <软件包名称> <std_msgs rospy roscpp>//创建的这个软件包依赖这三个标准``
``# catkin_creat_pkg <package_name> [depend1] [depend2] [depend3]``
创建一个文件夹，这个文件夹的名称为软件包名称，这个软件包的依赖标准在后面用空格间隔开。

5、catkin_make
这个命令的作用是构建一个工作空间，构建完要记得source配置文件，配置文件在生成的目录下的/devel/setup.bash里面。

6、catkin_depend1
可以用这个命令看一级依赖包，depend2为二级依赖包，如此类推。
这些关系储存在package.xml中。

7、剖析catkin_create_pkg里面的每个文件。
7.1、package.xml的每个元素:1、描述标签description。2、维护者标签maintainer(这个标签里面能让其他人联系到软件包的制作人员并含有联系信息。)3、许可证标签license里面插放协议，如BSD、MIT协议。4、依赖标签。


