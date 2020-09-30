/*
 * @Author: Liu Weilong
 * @Date: 2020-09-30 13:25:01
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-30 16:11:18
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter2 managing threads/thread_guard.cpp
 * @Description: RAII管理thread 样例
 */

#include <thread>
#include <iostream>
#include <utility>
#include "common.hpp"

using namespace std;

class ThreadGuardSelf
{
    public:
    explicit ThreadGuardSelf(thread t):t_(std::move(t))
    {
        cout<<"thread guard grub the ownership of "<<t_.get_id()<<endl;
        if(!t_.joinable())
        {
            cout<<"however,this thread is not joinable!"<<endl;
        }
    }

    // copy ctor 和 copy assign 竟然写错了 太丢人了
    ThreadGuardSelf(const ThreadGuardSelf & t) =delete;
    ThreadGuardSelf & operator=(const ThreadGuardSelf & t) = delete;
    
    ~ThreadGuardSelf(){
        if(t_.joinable())
        t_.join();
    }
    private:
    std::thread t_;
};

void oops()
{   
    std::thread t(print);
    ThreadGuardSelf t_guard(std::move(t)); // 这里可以看成两次move 的传递 

    // 第二种写法
    // ThreadGuardSelf t_guard2(thread(print)); 使用小括号的写法有些问题 无法进行初始化，
                                            //  所以这种右值thread 还是要用大括号的initializer list 进行初始化
    ThreadGuardSelf t_guard2{thread(print)}; // 这里让我们需要重新思考传参的逻辑
    cout<<"now there is not a join()"<<endl;
}

int main()
{
    oops();
    return 0;
}