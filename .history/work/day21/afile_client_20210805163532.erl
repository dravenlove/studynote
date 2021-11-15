    -module(afile_client). 
    -export([ls/1,get_file/2,exchange/1]). 
    

    exchange(File) ->
        %%等待指令
        receive 
            {Server,{get_file,File}} ->
                io:format("thanks"),

        end, 
        exchange(File).  
    
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

