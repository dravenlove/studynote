    -module(afile_client). 
    -export([ls/1,get_file/2]). 
    
    start(Dir) -> spawn(afile_server, loop,[Dir]); 
    
    loop(Dir) ->
        %%等待指令
        receive
            {Client, list_dir} ->
            %%需要做什么
                Client ! {self(),file:list_dir(Dir)};
            {Client,{get_file,File}} ->
                Full = filename:join(Dir, File),
                Client ! {self(), file:read_file(Full)}
        end,
        loop(Dir). 
    
    ls(Server) ->
        Server ! {self(), list_dir},
        receive
            {Server,FileList} ->
                FileList
        end. 

    get_file(Server,File) ->
        Server ! {self(),{get_file,File}},

        receive
            {Server, Content} ->
                Content
        end. 

