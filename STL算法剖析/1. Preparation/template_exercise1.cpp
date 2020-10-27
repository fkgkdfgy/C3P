/*
 * @Author: Liu Weilong
 * @Date: 2020-10-27 15:19:37
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-27 16:37:55
 * @FilePath: /C3P/STL算法剖析/1. Preparation/template_exercise1.cpp
 * @Description: 跟着文档重新复习一下 template
 *               1. 类模板实例化时并不是每个成员函数都实例化了, 而是使用到了哪个成员函数, 那个成员函数才实例化。
 *               2. 可以把类模板和函数模板结合起来, 定义一个含有成员函数模板的类模板.
 *  
 *                  注：在类模板外对函数模板进行定义的 方式 模板参数 放置顺序有讲究
 * 
 *               3. 类模板中可以声明static成员, 在类外定义的时候要增加template相关的关键词, 并且需要注意每个不同的模板实例都会有一个独有的static成员对象.
 */

#include <iostream>
using namespace std;

// ============================= 1 ===========================

template <typename T>
class point
{
    public:
    point(T x, T y):x_(x),y_(y){}
    point() = default;
    void setValue(T x,T y) const // 错误的定义不应该通过
    {
        x_ = x;
        y_ = y;
    }

    private:
    T x_;
    T y_;
};

using T = int;
class point1
{
    public:
    point1(T x, T y):x_(x),y_(y){}
    point1() = default;

    // 非模板 编译器就进行了实例化
    // 有以下函数，所以编译器就无法通过
    // void setValue(T x,T y) const // 错误的定义不应该通过
    // {
    //     x_ = x;
    //     y_ = y;
    // }

    private:
    T x_;
    T y_;
};

// ============================= 2 =============================

template<typename S>
class point2
{
    public:
    point2(S x, S y):x_(x),y_(y){}
    point2() = default;

    // 非模板 编译器就进行了实例化
    // 有以下函数，所以编译器就无法通过
    template<class U>
    void setValue(U x,U y); // 错误的定义不应该通过
 
    private:
    S x_;
    S y_;
};

template<class S> // 这里的上下顺序也是有讲究的
template<class U>
void point2<S>::setValue(U x,U y)
{
    x_ = x;
    y_ = y;
}

int main(int argc,char **argv)
{
    point<double> p; // 有错误的函数 结果编译通过
    // p.setValue(1.0,1.0); 加上这句就会报错
    return 0;
}