/*
 * @Author: Liu Weilong
 * @Date: 2020-09-25 16:14:39
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-25 16:37:02
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter2 managing threads/join-detach.cpp
 * @Description: thread join 和detach 操作
 */
#include <thread>
#include <iostream>
#include "common.hpp"
using namespace std;

void join()
{
    thread t(print);
    cout<<"this thread's id is "<<t.get_id()<<endl; // thread id 需要在detach 和 join 之前调用
    t.join();
    print();
}

void detach()
{
    thread t(print);
    cout<<"this thread's id is "<<t.get_id()<<endl;
    t.detach();
    print();
}

void no_decision()
{
    thread t(print);
    print();
}


void join_later()
{
    thread t(print);
    print();
    t.join(); // 线程还是会把之后的那个print() 一起跑完
}
int main(int argc,char **argv)
{
    cout<<"join"<<endl;
    join();

    //cout<<"detach"<<endl;
    //detach();

    //cout<<"no decision"<<endl;
    //no_decision(); // 会直接调用 terminate 尽量避免这种情况出现

    cout<<"join_later"<<endl;
    join_later();
    return 0;
}