/*
 * @Author: Liu Weilong
 * @Date: 2020-10-02 19:07:55
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-03 10:25:48
 * @Description: 用于测试模板声明和定义分离的问题
 *               结论： 1.  分离的定义需要添加特殊的 explicit instantiate 语句
 *                     2.  如果不想添加，请把声明和定义写在一起把
 *           
 */

#include <iostream>
using namespace std;

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

