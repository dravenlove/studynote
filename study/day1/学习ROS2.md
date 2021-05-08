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
