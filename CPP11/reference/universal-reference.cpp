/*
 * @Author: Liu Weilong
 * @Date: 2020-09-11 10:46:51
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-18 08:54:56
 * @Description: 这里主要讨论C++11 的万能引用
 */

#include <iostream>
#include <math.h>
using namespace std;


// 真相大白了: rvalue can be binded to rvalue reference 
//                                 or const lvalue referecne
//            lvalue can be binded to lvalue reference
// 且模板类中，万能引用并不生效。
// 但如果模板类中定义函数模板是能继续用万能引用的，因为类模板实例化后就是一个普通的类了

// 万能引用只对 T&& 有效  对于 const T&& 无效
// T&& 只有在函数模板中 万能引用会生效，在T已经具体化的函数中，还是代表右值引用
template <typename T>
void printUniversal( T&& a)
{   
    cout<<"using the universal reference"<<endl;
    cout<<a<<endl;
}

template <typename T>
void printCommon(T & a)
{
    cout<<"using the left reference"<<endl;
    cout<< a<<endl;
}

template <typename T>
void printCommon(T&& a)
{
    cout<<"using the right reference"<<endl;
    cout<< a<<endl;
}

int main()
{
    int a = 10;
    printCommon(a);
    printCommon(10);
    printUniversal(a); // 单模板，左值右值均可绑定 加上const 之后万能引用失效
    printUniversal(10);
}