-module(hello). 
-export([start/0,io/1]).

start() ->
        io:format("hello world-n"). 

Hello="Hello". 
io(File) ->
        File ! {self(), Hello},
        receive
              {File},Hello} ->
               io:format("hello world-n"). 

        end.   

