/*
 * @Author: Liu Weilong
 * @Date: 2020-10-10 16:22:54
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-10 16:39:10
 * @FilePath: /C3P/CPP-Concourrency-in-Action/baseline/thread_pool_complex_1.cpp
 * @Description: 一个稍微复杂一些的线程池
 *               主要内容：
 *               1. 无限存储的方法
 */

#include <iostream>
#include <functional>
#include <thread>
#include <queue>
#include <future>
#include <vector>
#include <memory>
using namespace std;

class FunctionWrapper
{
   private:

    struct FunctionBase
    {
        public:
        virtual void call() = 0;
        virtual ~FunctionBase() = default; 
    };
    template<typename F>
    struct FunctionImpl :public FunctionBase
    {
        public:
        F f;
        virtual void call() override{f()};
    };

    unique_ptr<FunctionBase> f;
    public:
    template <typename T>
    FunctionWrapper(T&& t):f(std::move(t))

    void operator()(){f->call();}


}



