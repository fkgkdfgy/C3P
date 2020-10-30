/*
 * @Author: Liu Weilong
 * @Date: 2020-10-10 13:22:46
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-29 15:23:59
 * @FilePath: /C3P/CPP-Concourrency-in-Action/baseline/future_and_async.cpp
 * @Description: 为了学习 async 和 future 的使用
 *               thread 没有一个返回值的机制
 *               async 就可以这样返回一个值 当需要async 返回一个值的时候
 *               async 会一直堵塞到状态达成 
 *               感觉是可以用于并行计算
 */
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

double do_something(double a)
{
    std::this_thread::sleep_for(chrono::milliseconds(1000));
    return a;
}

int main(int argc,char **argv)
{
    auto start = chrono::steady_clock::now();
    future<double> f1 = async(do_something,1);
    future<double> f2 = async(do_something,1);
    future<double> f3 = async(do_something,1);
    
    double result = do_something(1.)+ f1.get()+f2.get()+f3.get(); // 如果没有计算好，会一直在这里等待，直到有结果
    
    auto duration = chrono::steady_clock::now() - start;
    
    cout<<"the time is "<<duration.count()<<endl;

    return 0;
}
