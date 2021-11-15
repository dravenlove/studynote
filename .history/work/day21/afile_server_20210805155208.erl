    -module(afile_server). 
    -export([start/1,loop/1,put_file/2]). 

    start(Dir) -> spawn(afile_server, loop,[Dir]). 

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

    put_file(Filename,Client) ->
        Client ! {self(),Filename},
        
        receive 
            {}
        