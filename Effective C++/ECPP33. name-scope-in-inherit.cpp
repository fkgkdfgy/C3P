/*
 * @Author: Liu Weilong
 * @Date: 2020-09-23 18:26:33
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-27 19:12:52
 * @FilePath: /C3P/Effective C++/ECPP33. name-scope-in-inherit.cpp
 * @Description: 主要是为了验证 在继承当中， Derived 的expression 是嵌套在Base 里的
 *               Base 中的同名 member function，如果Derived 想要使用，就需要virtual 或者使用 using 改变可访问性
 *               2020/9/27 添加新的内容：就是今天在自己写代码的时候发现的问题
 *                                     这个文件中所展示的 namescope 覆盖的问题，其实不单单是function、object 也是一样的
 */

#include <iostream>
using namespace std;

class Base
{
    public:
    explicit Base(float Content):Content_(Content){}
    virtual void mf1(){ cout<< "in Base mf1"<<endl;}
    virtual void mf1(int x){}
    void mf2(){cout<<"in Derived mf2"<<endl;}
    void mf2(int x){}
    float Content_;
};
class Derived :public Base
{
    public:
    Derived(float Content):Base(Content){}

    using Base::mf1; // 让Base 内容所有名为mf1 的内容在 Derived 内可见
    void mf1(){cout<<"in Base mf1"<<endl;}
    void mf2(){cout<<"in Derived mf2"<<endl;}

    float Content_;
};

int main(int argc,char **argv)
{
    Derived D(0.3); // 这里使用的也是Base 的mf1 而不是 Derived 的mf1
    cout<<D.Content_<<endl; // 马上就会呈现出惊人的一幕，也就是Content_ 并没有被初始化
    D.mf1(1); // 没有using mf1 调用会报错
    D.mf1();
    //D.mf2(1); // 调用会报错


    return 0;
}
