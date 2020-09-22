/*
 * @Author: Liu Weilong
 * @Date: 2020-09-22 09:19:47
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-22 09:26:54
 * @FilePath: /C3P/BasicContent/inherit/inherit-derived-ctor.cpp
 * @Description: 用于实践继承时的一些问题：
 *               1. Base 的ctor 在private 的时候，Derived 是否可以正确的ctor  -> 结论是访问不到
 *               2. Base 的ctor 应该放在public里面，不然真的很尴尬，Derived 创建的时候调用不到Base 的ctor 导致
 *                  Derived 也创建不了
 */              


#include <iostream>
using namespace std;

class Base;

Base createBase()
{
    return Base();
}

class Base
{
    friend Base createBase();
    private:
    Base() =default;
};
class Derived :public Base
{
    public:
    Derived():Base(createBase()){}

};




int main(int argc,char **argv)
{

    return 0;
}
