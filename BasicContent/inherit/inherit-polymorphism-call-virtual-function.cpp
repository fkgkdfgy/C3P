/*
 * @Author: Liu Weilong
 * @Date: 2020-10-06 11:22:17
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-06 11:29:31
 * @Description:  这个文件主要是用于测试  多态时一些神奇的规律
 *                1. 使用动态绑定也就是多态的时候，虚指针可以去访问Derived 中已经变成 private 的 member function，
 *                   猜想这里的原因是函数指针的传递，绕过了public private 的查验
 */

#include <iostream>
using namespace std;

class Base
{
    public:
    virtual void print(){cout<<"in Base print"<<endl;}
};

class Derived :public Base
{
    private:
    virtual void print() override{cout<<"in Derived print"<<endl;}  
};



int main(int argc,char **argv)
{
    Base * p_b = new Derived();

    p_b->print();
    return 0;
}