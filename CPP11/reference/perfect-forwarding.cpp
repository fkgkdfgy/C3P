/*
 * @Author: Liu Weilong
 * @Date: 2020-09-11 11:09:59
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-29 09:18:32
 * @Description: 这里主要讨论1. C++11 的完美转发
 *                         2. 在对象被实例化时候，会使用什么样的Big Five 
 */

#include <iostream>

using namespace std;

class A
{
    public:
    A(){cout<<"ctor "<<endl;}
    A(const A & ){cout<<"copy ctor"<<endl;}
    A(const A &&){cout<<"move ctor"<<endl;}
    A& operator=(const A & ){cout<<"lvalue assign"<<endl;}
    A& operator=(const A &&){cout<<"rvalue assign"<<endl;} //const T& 的操作符可以处理右值
    //
    ~A(){cout<<"dtor"<<endl;}
};


template <typename T>
void warp(T&& a)
{
    printCommon(forward<T>(a)); // 没有forward<T>的话  warp的调用都会变成 lvalue 的调用，因为a 是一个实参了
}

template <typename T>
void printCommon(T & a)
{
    cout<<"using the left reference"<<endl;
}

template <typename T>
void printCommon(T&& a)
{
    cout<<"using the right reference"<<endl;

}

int main()
{
    A a; // default ctor
    A b; // default ctor
    a = std::move(b); //  rvalue assign
                      //  if the rvalue assign is commented , move(b) will be binded to a const lvalue reference
                      //  then call the lvalue assign 
    warp(a); // lvalue reference warp
    warp(A()); // rvalue referecne warp
    
    return 0;
}