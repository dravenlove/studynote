#Github的学习和使用 #
1.首先在github上创建一个仓库。
2.复制Clone里面的HTTPS地址。
3.在本地电脑创建本地仓库。
4.给VScode设置代理，设置可能会代理失败，需要到快捷方式处加入代理地址。
5.安装git bash。
6.在源代码管理右上角点+选择本地仓库作为工作区文件夹。
7.在Vscode上登录github账号。
8.搜索添加远程库添加到所选远程库。
9.为git bash添加代理代码.
10.出现ssl报错的时候输入以下代码:
    ```git config http.sslVerify "false" ```
11.在源代码管理处添加远程库。
12.更新完代码后要在源代码的地方保存更改需要提交信息,这一步是给存储库也即是本地文件夹提交更改申请.
13.提交代码更新后需要把代码同步到github才是正确上传到github,这一步才是把本地库代码上传到github.

##github的内容同步更新到我的服务器  ##
1.安装git依赖,利用一下代码:
    ```yum install curl-devel expat-devel gettext-devel openssl-devel zlib-devel perl-devel
    ```
2.给服务器安装git.
3.安装git完成后用代码```git --version```验证安装是否成功.
4.给git创建专门的用户组和用户.
5.创建用户组命令```groupadd groupname```groupname为用户组名字.
6.给用户组创建子用户```adduser username -g groupname```groupname为要添加用户组的名字,username为子用户名字.
7.给git用户添加密码利用以下命令```passwd username```.
8.在服务器上创建GIT仓库.先cd到指定目录然后输入命令```chown 用户组:用户名 目录```来把该目录所属用户改成指定用户.
9.git init指定目录即可.
10.在本地仓库目录输入``git remote add 名字 连接地址``地址为之前创建好复制的那一个,名字为推送的时候的名字.
11.使用命令``git remote -v``快速添加推送克隆配置.
12.下拉仓库命令```git pull 仓库地址 远程分支名:本地分支名 ```.下拉是将远程主机的某个分支的更新和本地指定分支合并起来.
13.文件克隆```git clone 仓库地址 ```克隆是整个仓库克隆下来.
14.```git branch [新分支]```报错且```git branch -a```无分支显示的原因是因为没有master的提交对象，所以要先进行一次commit提交操作才能建立master,所以新建仓库完成后先建立一个文件用```git add .```存放到暂存区,用```git status```命令查看,最后用```git commit```提交暂存区到仓库.运行10和11.
15.```git fetch "地址或链接别名"```命令从远程仓库获取新分支和数据.
16.```git merge "地址或链接名/分支名"```合并服务器更新到当前分支.
17.```git branch "分支名"```为创建分支命令.```git checkout "分支名"```为切换分支命令.


#同步脚本#
1.创建脚本文件.
```
time=$(date "+%Y-%m-%d %H:%M:%S")
cd "需要同步的分支所在的目录."
git fetch "远程仓库地址"
git merge "远程仓库地址/分支名"
```
2.用命令```chmod 777 "文件名"```添加可执行权限.