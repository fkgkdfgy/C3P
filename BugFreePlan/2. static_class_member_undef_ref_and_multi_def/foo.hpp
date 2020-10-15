/*
 * @Author: Liu Weilong
 * @Date: 2020-10-04 11:17:52
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-15 16:45:53
 * @Description: 主要是检测 static class member undef ref 和multiple definition 的问题
 *               对应Carto-self 当中，static member variable 有的在template(.hpp) 里面使用
 *                                                          有的在 .cpp 中使用情况
 *               报错形式： multiple defintion "a"              
 * 
 * 
 */
#ifndef FOO
#define FOO
#include <iostream>
using namespace std;


/**
 * showA 和 showBA是用于 undef ref 的函数
 */
class foo
{
    public:
    // 为了保证showA的隐式instaniate 这里把showA写作一个member function template 
    template<typename T>
    static void showA(T msg);
    static void showBA();
    
    // 为了防止a 的多次定义 采用这样的一种定义方法 完全避免掉了member variable多次定义的问题
    // 而且不会造成任何不便 这个写法太优秀了 并且可以进行分离式定义
    static int & getA();
    // {
    //     static int a = 10;
    //     cout<<"the address of a is "<< &a<<endl;
    //     return a;
    // }

    // static int a;
    static int b;
};
// 这里的 a 存在多次定义的情况，一次在foo.cpp 一次在undef_ref.cpp
// int foo::a = 10;

template<typename T>
void foo::showA( T msg)
{
    int & a_ = getA();
    cout<<a_<<endl;
    cout<<&a_<<endl;
    cout<<msg<<endl;
}
#endif