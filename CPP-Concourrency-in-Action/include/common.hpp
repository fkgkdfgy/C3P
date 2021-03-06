/*
 * @Author: Liu Weilong
 * @Date: 2020-09-25 16:15:44
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-02 09:09:45
 * @FilePath: /C3P/CPP-Concourrency-in-Action/include/common.hpp
 * @Description: Common 函数 防止多次编写 相同的内容
 */
#pragma once
#include <iostream>

using namespace std;
void print()
{
    cout<<"========= print start =================="<<endl;
    for(int i =0;i<20;i++)
    {
        cout<<i<<endl;
    }
}

void PrintWithArguments_noConst( int & a)
{
    cout<<"call the lref function, the value now will be 500 "<<endl;
    a = 500;
}

void PrintWithArguments(const int &a)
{
    cout<<"call the lref function, the value now will be 1000 "<<endl;
    cout<<"oops,  the value can not be changed "<<endl;
}


class mf_class
{
    public:

    void do_something_1(const int & a)
    {
        cout<<"in mf_class "<<"show the content of a is "<<a<<endl;
        PrintWithArguments(a);
    }
};  