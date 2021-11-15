    -module(aflie_server). 
    %%模块命名必须和文件名一致
    
    -export([start/1,loop/1]). 
    %%函数定义,函数名/参数数量

    start(Dir) -> spawn(afile_server, loop,[Dir]). 
    %%创建应用程序(模块名,调用函数,调用函数传入参数)

    loop(Dir) ->
        %%等待指令
        receive
            {Client, list_dir} ->
            %%需要做什么
            %%当收到一个进程给他发送信息{客户端进程号,list_dir}他就会执行下面代码.
                Client ! {self(),file:list_dir(Dir)};
            %%向客户端进程号发送信息{当前调用进程号,文件模块下的文件目录函数}
            {Client,{get_file,File}} ->
            %%当收到信息{客户端进程号,File}他会执行以下代码.
                Full = filename:join(Dir, File),
            %%给Full赋值为File的完整目录
                Client ! {self(), file:read_file(Full)}
            %%然后给客户端发信息{当前调用进程号,文件内容(完整路径)}
        end,
        loop(Dir). 
        %%重复运行,死循环