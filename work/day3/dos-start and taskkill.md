# 批处理DOS命令 #
---
##1、start 启动单独的“命令提示符”窗口来运行指定程序或命令。##

###用法：start explorer，启动进程###
---
###语法：start ["title"] [/D Path] [/i] [/min] [/max] [{/separate | /shared}] [{/low | /normal | /high | /realtime | /abovenormal | belownormal}] [/wait] [/b] [FileName] [parameters]###
---
"title" 指定在“命令提示符”窗口标题栏中显示的标题。

/dpatch 指定启动目录。
/i 将 Cmd.exe 启动环境传送到新的“命令提示符”窗口。

/min 启动新的最小化窗口。

/max 启动新的最大化窗口。

/separate 在单独的内存空间启动 16 位程序。

/shared 在共享的内存空间启动 16 位程序。

/low 以空闲优先级启动应用程序。

/normal 以一般优先级启动应用程序。

/high 以高优先级启动应用程序。

/realtime 以实时优先级启动应用程序。

/abovenormal 以超出常规优先级的方式启动应用程序。

/belownormal 以低出常规优先级的方式启动应用程序。

/wait 启动应用程序，并等待其结束。

/b 启动应用程序时不必打开新的“命令提示符”窗口。除非应用程序启用 CTRL+C，否则将忽略 CTRL+C 操作。使用 CTRL+BREAK 中断应用程序。

##注意：##
路径PATH要用/而不能用\,当路径上有空格时候,必须给"title"参数,不然路径将成为cmd的标题.


---

##2、taskkill 用来中止进程的。 ##
### 用法：taskkill /F /IM EXPLORER.exe
### 语法：TASKKILL [/S system [/U username [/P [password]]]]###
/S system 指定要连接到的远程系统。

/U [domain\]user 指定应该在哪个用户上下文
执行这个命令。

/P [password] 为提供的用户上下文指定密码。如果忽略，提示输入。

/F 指定要强行终止的进程。

/FI filter 指定筛选进或筛选出查询的的任务。

/PID process id 指定要终止的进程的PID。

/IM image name 指定要终止的进程的映像名称。通配符 '*'可用来指定所有映像名。

/T Tree kill: 终止指定的进程和任何由此启动的子进程。

/? 显示帮助/用法。

筛选器:

筛选器名 有效运算符 有效值
----------- --------------- --------------

STATUS eq, ne 运行 | 没有响应

IMAGENAME eq, ne 映像名

PID eq, ne, gt, lt, ge, le PID 值

SESSION eq, ne, gt, lt, ge, le 会话编号

CPUTIME eq, ne, gt, lt, ge, le CPU 时间，格式为
hh:mm:ss。

hh - 时，
mm - 钟，ss - 秒

MEMUSAGE eq, ne, gt, lt, ge, le 内存使用，单位为 KB

USERNAME eq, ne 用户名，格式为[domain\]user

MODULES eq, ne DLL 名

SERVICES eq, ne 服务名

WINDOWTITLE eq, ne 窗口标题



# dos命令 #
``taskkill /f /im TIM.exe ``

这个命令的作用是关闭TIM进程。

``start "重启TIM" "C:/Program Files (x86)/Tencent/TIM/Bin/QQScLauncher.exe" ``

这个作用的命令是启动路径下的程序。

