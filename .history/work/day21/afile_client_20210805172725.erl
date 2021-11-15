    -module(afile_client). 
    %%模块名声明
    
    -export([ls/1,get_file/2,put_file/2]). 
    %%函数调用声明

    ls(Server) ->
    %%函数ls定义
        Server ! {self(),list_dir},
        %%向服务端发送信息{当前调用端口号,list_dir}
        receive
        %%当收到以下信息执行
            {Server,FileList} ->
                FileList
        end. 

    get_file(Server,File) ->
        Server ! {self(),{get_file,File}},
        %%向服务端发送信息{当前调用端口号,给File赋值为传入值}
        receive
            {Server, Content} ->
                Content
            %%收到{Server端口号,信息}输出Content的内容.
        end. 
    put_file(Server,File) ->
        Server ! {self(),{put_file,File}},
        %%向服务端发送信息{当前调用端口号,给File赋值为传入值}
        receive
            {Server, Content} ->
                Content
            %%收到{Server端口号,信息}输出Content的内容.
        end. 