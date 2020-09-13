/*
 * @Author: Liu Weilong 
 * @Date: 2020-08-31 16:42:23 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-08-31 16:44:37
 */

/**
 * @brief 所有的初始化都使用大括号进行初始化
 */
#include <iostream>
#include <memory>


class A
{
    public:
    A(int a, int b){ a_ =a; b_ =b};
    int a_,b_;
};


int main()
{
    std::shared_ptr<A> a_ptr{new A{3,40}};
    return 0;
}