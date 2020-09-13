/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-04 18:28:46 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-05 10:45:17
 */



/**
 * @brief 这个文件主要是为了测试模板包的使用
 */


#include <iostream>

#include <string>

template<typename T,typename... args>
class A
{
    public:
    A(){}
    virtual void print(T,args... args_) =0;
};

class B:public A<int,float,float,float>
{
    public:
    B(){}
    void print(int a,float b,float c,float d) override{
        std::cout<<a<<b<<c<<d<<std::endl;
    }
};

// 想要取出的话就只能顺序取出 疯狂递归
// template<typename T,typename... args>
// void print(T a,args... b)
// {
//     std::cout<<a<<std::endl;
//     for(int i = 0;i<sizeof...(args);i++)
//     {
//         std::cout<<b<<std::endl;
//     }
// }
// Wrong! 


int main()
{

    B b;
    b.print(1,0.5,0.1,0.7);
    
    return 0;

}