/*
 * @Author: Liu Weilong
 * @Date: 2020-10-10 08:40:29
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-10 09:20:58
 * @FilePath: /C3P/CPP-Concourrency-in-Action/baseline/thread_create_and_mutex.cpp
 * @Description: 多线程的创建和mutex 锁
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>
using namespace std;

double content = 0;
std::mutex variable_lock_;


void Thread()
{
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> real_random(0,100);
    
    for(unsigned int i = 0;i<100;i++)
    {
        double random = real_random(gen);
        // 之前在这里没有添加大括号
        // 所以tmp 没有释放，就直接sleep_for，唤醒之后继续进行循环，
        // 所以才没有跳到别的线程上去
        {
        lock_guard<mutex> tmp(variable_lock_);
        cout<<"[READ] the content : "<<content<<"   the thread id is "<<std::this_thread::get_id()<<endl;
        content = random;
        cout<<"[WRITE] the content : "<<content<<"  the thread id is "<<std::this_thread::get_id()<<endl;
        }
        // 这里的沉睡还是厉害啊
        std::this_thread::sleep_for(chrono::milliseconds(500));
    }
    
}

int main()
{
    thread t1(Thread);
    thread t2(Thread);
    
    t1.join();
    t2.join();
    return 0;
}