/*
 * @Author: Liu Weilong
 * @Date: 2020-09-23 18:26:33
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-23 18:38:25
 * @FilePath: /C3P/Effective C++/ECPP33. name-scope-in-inherit.cpp
 * @Description: 主要是为了验证 在继承当中， Derived 的expression 是嵌套在Base 里的
 *               Base 中的同名 member function，如果Derived 想要使用，就需要virtual 或者使用 using 改变可访问性
 *
 */

#include <iostream>
using namespace std;

class Base
{
    public:
    virtual void mf1(){}
    virtual void mf1(int x){}
    void mf2(){cout<<"in Derived mf2"<<endl;}
    void mf2(int x){}
};
class Derived :public Base
{
    public:
    using Base::mf1; // 让Base 内容所有名为mf1 的内容在 Derived 内可见
    void mf1(){}
    void mf2(){cout<<"in Derived mf2"<<endl;}
};

int main(int argc,char **argv)
{
    Derived D;
    D.mf1(1); // 调用会报错
    D.mf2(1); // 调用会报错


    return 0;
}
