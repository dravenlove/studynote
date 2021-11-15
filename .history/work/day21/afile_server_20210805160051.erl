    -module(afile_server). 
    -export([start/2,loop/1,put_file/2]). 

    start(Dir,Filename) -> spawn(afile_server, loop,put_file,[Dir],Filename). 

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

    put_file(Client,Filename) ->
        Client ! {self(),{put_file,Filename}},
        
        receive 
            {Client,Content} ->
                Content
        end.
        