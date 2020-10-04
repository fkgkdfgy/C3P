/*
 * @Author: Liu Weilong
 * @Date: 2020-09-30 13:47:12
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-02 09:22:20
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter2 managing threads/arguments_pass_for_thread.cpp
 * @Description:  总结：1. by default 参数传递给线程的时候，是先进行参数复制，然后右值传递给可调用的函数指针
 *                     2. 想要传递ref 需要在参数处使用std::ref
 *                     3. 参数传递要小心 指针和引用 防止出现非法空间的调用
 *                     4. member function 的bind 调用需要使用 placeholder进行占位操作
 */

#include <thread>
#include <iostream>
#include "common.hpp"

using namespace std;

int main()
{
    // rvalue
    int rvalue = 5;
    thread t(PrintWithArguments_noConst,std::ref(rvalue));
    t.join();

    // lvalue
    int tmp =5;
    thread t1(PrintWithArguments,tmp);
    t1.join();
    cout<<"now show the tmp's value"<<endl;
    cout<<tmp<<endl;

    mf_class c;
    // c 没有一个 operator 所以才会不通过
    // 之前一直不同过的原因是 do_something_1 有一个参数是需要进行绑定参数的
    thread t2(std::bind(&mf_class::do_something_1,&c,std::placeholders::_1),5);
    t2.join();
    return 0;

}

