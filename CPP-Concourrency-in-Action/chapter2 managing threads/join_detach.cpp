/*
 * @Author: Liu Weilong
 * @Date: 2020-09-25 16:14:39
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-20 13:56:01
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter2 managing threads/join_detach.cpp
 * @Description: thread join 和detach 操作
 *               经过这段时间的多线程的使用
 *               还是对多线程有了一些了解
 *               t.join() 就是会在这里对这行代码一直等待 t 运行结束
 *               t.detach() 就是说明不用继续等待
 * 
 * 
 * 
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

// 此处会直接调用print 
void no_decision()
{
    thread t(print);
    print();
}


void join_later()
{
    thread t(print);
    cout<<"=============="<<endl;
    print();
    t.join(); // 线程并没有把之后的print() 一起跑完，最后只是运行了print 两遍
}
int main(int argc,char **argv)
{
    // cout<<"join"<<endl;
    // join();

    //cout<<"detach"<<endl;
    //detach();

    //cout<<"no decision"<<endl;
    //no_decision(); // 会直接调用 terminate 尽量避免这种情况出现

    cout<<"join_later"<<endl;
    join_later();
    return 0;
}