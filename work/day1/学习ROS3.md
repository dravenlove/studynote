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