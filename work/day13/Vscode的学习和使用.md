#Vscode的学习和使用 #
1.创建一个项目文件夹,它用来存放所有项目.
2.这个文件夹下会生成.vscode.
3.文件夹.vscode存放tasks.josn(生成说明)、launch.json(调试设置)、c_cpp_properties.json(编译器路径和智能感觉设置).
4.要在vs code使用MSCV,需要在菜单搜索Develop Command,点开输入cl来查看他所在的目录和版本信息.
5.按下F5调试程序会在.vscode文件里生成一个tasks.json文件.
6.在这里可以断点调试，设置断点后按F5即可使用。
7.程序执行到断点处会停下。
8.顶部第一个按钮为继续执行到下一个断点。
第二个为执行下一条语句，遇到函数会执行完而不会跳进函数。
第三个执行下一条语句，遇到函数会跳进函数。
第四个为跳出当前函数，如果当前函数为主函数的话会直接结束程序。
第五个，重新启动调试。
第六个结束调试。
9.设置powershell为Vscode的默认终端，ctrl+shift+p搜索select default shell选择powershell为默认终端。