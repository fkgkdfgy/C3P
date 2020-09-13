/*
 * @Author: Liu Weilong
 * @Date: 2020-09-11 10:46:51
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-09-11 14:50:46
 * @Description: 这里主要讨论C++11 的万能引用
 */

#include <iostream>
#include <math.h>
using namespace std;


// T&& 只有在模板中 万能引用会生效，在T已经具体化的函数中，还是代表右值引用
template <typename T>
void printUniversal(T&& a)
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
    printUniversal(a); // 单模板，左值右值均可绑定
    printUniversal(10);
}