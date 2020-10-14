/*
 * @Author: Liu Weilong
 * @Date: 2020-10-02 19:07:55
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-14 15:04:27
 * @Description: 用于测试模板声明和定义分离的问题
 *               注意  这里的模板 包括 函数模板 和 类模板
 *  
 *               结论： 1.  分离的定义需要添加特殊的 explicit instantiate 语句
 *                     2.  如果不想添加，请把声明和定义写在一起把
 *               
 *               目的：1. 这里主要是展示模板 分离式定义和合并式定义
 */

#include <iostream>
using namespace std;

// 分离式定义  也就是一个一个在.hpp 一个在.cpp 中
//            需要和下面的两个.hpp 的合并式进行区分
// function template

template <typename T>
void print(const T &);


// memebr function template
class C
{
    public:
    template <typename T>
    void print( const T & msg);
};

// class template
template <typename T>
class CTemplate
{
    public:
    void print(const T & msg);
};


//////////////////////////////////////////////////////////////////////////////////////////
// 合并式定义
class CDefInHpp
{
    public:
    template <typename T>
    void print(const T & msg);
};

template <typename T>
void CDefInHpp::print(const T & msg)
{
    cout<<"definition in hpp"<<endl;
}
// 合并式定义
class CDefInAnotherHpp
{
    public:
    template <typename T>
    void print(const T & msg);
};

#include "foo_another.hpp"


