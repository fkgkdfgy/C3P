/*
 * @Author: Liu Weilong
 * @Date: 2020-09-30 13:47:12
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-30 17:14:56
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter2 managing threads/arguments_pass_for_thread.cpp
 * @Description: 
 */

#include <thread>
#include <iostream>
#include "common.hpp"
using namespace std;

int main()
{
    // rvalue
    int rvalue = 5;
    thread t(PrintWithArguments_noConst,rvalue);
    t.join();

    // lvalue
    int tmp =5;
    thread t1(PrintWithArguments,std::ref(tmp));
    t1.join();
    cout<<"now show the tmp's value"<<endl;
    cout<<tmp<<endl;

    thread t2(mf_class(),5);
    t2.join();
    return 0;

}

