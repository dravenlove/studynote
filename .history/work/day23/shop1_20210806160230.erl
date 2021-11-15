-module(shop1). 
-export([total/1]). 

total([{What,N}|T]) -> shop:cost(What) * N + total(T);
%%传入列表,提取列表第一个元组,将元组的第一个元素参数用函数shop:cost()获取商品价格计算再乘以元组第二个元素(数量),最后传入除第一个元组的后面元组导入total函数,直到没有元组.
total([])   -> 0. 