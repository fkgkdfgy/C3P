/*
 * @Author: Liu Weilong
 * @Date: 2020-09-24 17:59:20
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-24 18:09:26
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter2 managing thraeds/create-thread.cpp
 * @Description: 创建线程的方法
 */

#include <thread>
#include <iostream>
using namespace std;

void do_something()
{
    cout<<"do something in thread"<<endl;
}

class C_do_something
{
    public:
    void operator()(){
        cout<<"do something in thread (C_do_something)"<<endl;
    }
};

int main(int argc,char **argv)
{
    thread t1(do_something);
    C_do_something c;
    thread t2(c);
    // 测试用右值创建的情况,这里相当于是在给创建一个thread进行传参
    thread t3(C_do_something());
    thread t4{C_do_something()}; // 用于避免t3的请款出现
    // 使用lamda 进行 thread 创建
    thread t5([](){
        cout<<"do something in lamda"<<endl;
    });
    return 0;
}
