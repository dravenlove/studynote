#include<iostream>

int Output();

int main(int argc,char* argv[])
{   
    return Output();
}

int Output()
{
    std::cout<<"例子"<<std::endl;
    std::cout<<"输出5:"<<5<<std::endl;
    std::cout<<"计算10*5:"<<10*5<<std::endl;
    std::cout<<"计算22*7:"<<22*7<<std::endl;
    std::cout<<"计算22.0*7:"<<22.0*7<<std::endl;

    return 0;
}