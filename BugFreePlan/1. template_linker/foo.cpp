/*
 * @Author: Liu Weilong
 * @Date: 2020-10-02 22:12:36
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-02 22:49:47
 * @Description: 函数实现
 */
#include "foo.hpp"

// function template 
// 往常写法 分离式 在linker的时候会直接 报错 未定义的引用
// 修改方法一： 将定义放到.hpp 的代码中
// 修改方法二： 添加一个实例化文件 i.e. foo.int.cpp

template<typename T>
void print(const T & msg)
{
    cout<<"call the function template"<<endl;
}
// 真的是神奇  如果 没有 成员函数的部分 下面这一句根本通过不了
// 那么以后就规定都要写到.int.cpp 文件内好了
// template void print<int>(const int &);

// member function template
template <typename T>
void C::print(const T & msg)
{
    cout<<"call the member function template"<<endl;
}

// template void C::print<int>(const int &);

// class template
template<typename T>
void CTemplate<T>::print(const T &msg)
{
    cout<<"call the class template"<<endl;
}