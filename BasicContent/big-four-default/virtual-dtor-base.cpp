/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-05 12:19:45 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-05 13:12:27
 */

#include <iostream>
#include <memory>
using namespace std;
class ContentInBase
{
    public:
    ContentInBase(){cout<<"Content in Base is Created;"<<endl;}
    ~ContentInBase(){cout<<"Content in Base is detroyed;"<<endl;}
};

class ContentInDerived
{
    public:
    ContentInDerived(){cout<<"Content in Derived is Created"<<endl;}
    ~ContentInDerived(){cout<<"Content in Derived is destroyed"<<endl;}
};

class Base
{
    public:
    Base(){}
     ~Base(){}
    ContentInBase cb;
};

class Derived:public Base
{
    public:
    Derived(){}
    ~ Derived(){}
    ContentInDerived cd;
};

int main()
{
    /**
     * @brief 测试结果：
     * 1. 静态绑定  不存在 ContentInDerived 不释放内存的情况 (Base 的析构函数是不是virtual都是一样的)
     * 2. 动态绑定  Base的析构函数 是 virtual的情况会对 ContentInDerived 进行释放
     * 3. 动态绑定  Base的析构函数不是virtual的情况不会对 ContentInDerived 进行释放
     * 
     * 
    */
    Base* pd = new Derived();

    delete pd;
    // 

}