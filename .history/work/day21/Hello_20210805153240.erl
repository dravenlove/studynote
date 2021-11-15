-module(hello). 
-export([start/0,io/1]).

start() ->
        io:format("hello world-n"). 

io(File) ->
        File ! {self(), "hello world-n"},
        receive
              {File},"hello world-n"} ->
               "hello world-n"
        end.   

