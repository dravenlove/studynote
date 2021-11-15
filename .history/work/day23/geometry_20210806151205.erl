-module(geometry). 
%%模板声明,模板声明必须和文件名一样.
-export([area/1,test/0]). 
%%导出声明,带有1个参数的area函数.
%%没有在函数中导出的函数只能在模板内部使用,导出后相当于public大家都可以用.

%%area有两个子句,他们有;来隔开,每条子句都有一个头部和一个主体,头部和主体用(->)分隔.
%%头部半酣函数名,后面接零个或多个模式,主体包含表达式,他们会在头部模式与调用参数成功匹配时执行,子句根据函数定义出现的顺序进行匹配.

area({rectangle,Width,Height}) -> Width * Height;
%%当执行函数geometry:area({rectangle,5,5})会自动执行主体语句,并返回主体最后一条表达式的值,这里会返回25.
area({square,Side})             -> Side  * Side.

test() -> 
    12 = area({rectangle,3,4}), 
    %%这是一行代码测试.如果它没有返回12,会返回一条错误信息.
    144 = area({square,12}),
    %%同理.
    tests_worked.
    %%当返回这个信息,表示测试全部通过.