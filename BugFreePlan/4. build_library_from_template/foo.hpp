/*
 * @Author: Liu Weilong
 * @Date: 2020-10-14 16:44:31
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-15 07:53:20
 * @FilePath: /C3P/BugFreePlan/4. build_library_from_template/foo.hpp
 * @Description: 一个简单的 template 生成库的尝试
 *               1. 测试template 生成库文件
 *                  结果就是 template 是一个pattern 它没有实体 所以并不能使用一个template 来生成一个库文件
 *               2. 学习cmake 用于库生成的方法
 */

#include <iostream>
using namespace std;

template<typename T>
void print(T msg)
{
    cout<<"in print(function)"<<endl;
}