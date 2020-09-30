/*
 * @Author: Liu Weilong
 * @Date: 2020-09-24 08:45:30
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-24 08:48:50
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter1 hellowrold/hello-world.cpp
 * @Description: CPPCA 第一章 hello world
 */

#include <thread>
#include <iostream>

using namespace std;

void print()
{
    cout<<"hello world!"<<endl;
}

int main()
{
    // 新的线程从这里开始
    thread t(print);
    // 等待别的线程
    t.join();
    return 0;
}