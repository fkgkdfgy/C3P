/*
 * @Author: Liu Weilong
 * @Date: 2020-10-10 13:45:22
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-11-06 16:34:39
 * @FilePath: /C3P/CPP-Concourrency-in-Action/baseline/thread_pool_simple.cpp
 * @Description: 一个简单的线程池，没有用到 future 等内容
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>
using namespace std;

class ParamWrapperBase
{
    public: 
    
};

class ThreadPool
{
    public:
    ThreadPool(unsigned int thread_num){

        done_.store(false);
        thread_pool_.emplace_back(&ThreadPool::ShowRemianTaskNum,this);
        for (unsigned int i =0;i<thread_num;i++)
        {
            thread_pool_.emplace_back(&ThreadPool::Thread,this);
        }
    }

    void SubmitTask(function<void()> fun_ptr)
    {
        {
            lock_guard<mutex> tmp(work_queue_lock_);
            work_queue_.push(fun_ptr);
        }
        work_queue_cond_var_.notify_all();
    }

    ~ThreadPool()
    {
        done_.store(true);
        work_queue_cond_var_.notify_all();
        for(unsigned int i=0;i<thread_pool_.size();i++)
        {
            thread_pool_.at(i).join();
        }
    }
    private:

    void Thread()
    {
        while(!done_.load())
        {
            function<void()> work;
            {
                unique_lock<mutex> tmp(work_queue_lock_);
                work_queue_cond_var_.wait(tmp,[this]{return !work_queue_.empty();});
                if(done_)
                {
                    break;
                }
                work = work_queue_.front();
                work_queue_.pop();
            }
            work();
        }
    }

    void ShowRemianTaskNum()
    {
        while(!done_.load())
        {   
            uint size_task;
            {
                lock_guard<mutex> tmp(work_queue_lock_);    
                size_task = work_queue_.size();
            }  
            cout<<"now the queue size is "<<size_task<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        };
    }

    atomic<bool> done_;
    mutex work_queue_lock_;
    condition_variable work_queue_cond_var_;
    queue<function<void()>> work_queue_;
    vector<thread> thread_pool_;
};





void Task()
{
    cout<<"Ah here is " << this_thread::get_id()<<endl;
    this_thread::sleep_for(chrono::milliseconds(100));
}

int main(int argc,char **argv)
{
    ThreadPool tp_(4);
    for(unsigned int i=0;i<100;i++)
    {
        tp_.SubmitTask(Task);
        cout<<"[ADD] here we add a new task into the thread pool"<<endl;
        this_thread::sleep_for(chrono::milliseconds(30));
    }

    this_thread::sleep_for(chrono::milliseconds(50000));
    return 0;
}
