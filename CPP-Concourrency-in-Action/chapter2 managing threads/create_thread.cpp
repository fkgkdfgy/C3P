/*
 * @Author: Liu Weilong
 * @Date: 2020-09-24 17:59:20
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-30 16:10:36
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter2 managing threads/create_thread.cpp
 * @Description: 创建线程的方法
 */

#include <thread>
#include <iostream>
#include <functional>

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

class mf_class
{
    public:
    void do_something_1()
    {
        cout<<"in mf_class"<<endl;
        do_something();
    }
};  


int main(int argc,char **argv)
{
    // 1. function ptr 方法创建
    thread t1(do_something);
    t1.join();

    // 2. mf 创建 实际上还是函数指针
    mf_class tmp;
    thread t3(std::bind(&mf_class::do_something_1,&tmp));
    t3.join();
    
    // 3. functor 方法创建
    C_do_something c;
    thread t2(c);
    t2.join();

    // 测试用右值创建的情况,这里相当于是在给创建一个thread进行传参
    //thread t3(C_do_something());
    thread t4{C_do_something()}; // 用于避免t3的请款出现
    t4.join();

    
    // 4. 使用lamda 进行 thread 创建
    thread t5([](){
        cout<<"do something in lamda"<<endl;
    });
    t5.join();
    return 0;
}
