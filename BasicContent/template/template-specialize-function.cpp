/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-02 14:48:09 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-02 15:01:10
 */


#include <iostream>
#include <string>

// 函数模板的特化
template <typename T>
int compare(const T & a,const T &b)
{
    std::cout<<"Comparing in template function!"<<std::endl;

    return(a-b);
}

// 进行特化
template<>
int compare(const std::string &a,const std::string & b)
{
    std::cout<<"Specialization for compare template function !"<<std::endl;

    return 5;
}

// 一个函数重载
int compare(const std::string &a,const std::string & b)
{
    std::cout<<"function override!"<<std::endl;

    return 6;
}

int main()
{
    std::string a = "23";
    std::string b = "45";

    std::cout<<compare(a,b)<<std::endl; // 结果就是选取更倾向于重载 > 模板特化 > 模板
    std::cout<<compare(5,5)<<std::endl; 
    return 0;
}