/*
 * @Author: Liu Weilong
 * @Date: 2020-10-20 14:00:28
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-20 14:40:29
 * @FilePath: /C3P/CPP-Concourrency-in-Action/baseline/simple_test_atomic_if.cpp
 * @Description: 主要是用于测试 atomic<bool> 当作条件判断的时候 内存的占用的情况 
 * 
 *               不知道为什么 用了yeild 之后 CPU 占有率还是100
 * 
 *               通过阅读大概知道
 *               yeild 类似是 ktv歌曲打乱 如果就只有两首歌只能不断循环 CPU 打满
 *                           ie. while(condition)
 *                               {
 *                                  yeild(); 这里就只是说 我在这里先不唱了换别人 别人结束之后我再来试试
 *                                           这里是一个timeslice  所以速度非常快 CPU 占用率会比较高
 *                               }
 *                              
 *               sleep_for 相当于 歌曲暂停  但是sleep for 就可以进行休息
 *                               例如使用 std:this_thread::sleep_for(chrono::microseconds(10)); 大概占用在 7%
 */

#include <thread>
#include <atomic>
#include <iostream>
#include <chrono>
using namespace std;

std::atomic<bool> initial(false);

void thread_new()
{
    cout<<"thread starts"<<endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(300000));

    initial = true;
}

void thread_new1()
{
     while(!initial)
    {
        std:this_thread::sleep_for(chrono::microseconds(10));
    }
    cout<<" AAAAAAAAAAA"<<endl;
}

int main()
{
    std::thread t(thread_new);
    std::thread t1(thread_new1);
    t.detach();
    t1.join();
    cout<<" BBBBBBBBB"<<endl;
}