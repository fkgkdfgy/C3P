/*
 * @Author: Liu Weilong
 * @Date: 2020-10-10 09:21:14
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-10 13:19:39
 * @FilePath: /C3P/CPP-Concourrency-in-Action/baseline/condition_variable_and_mutex.cpp
 * @Description: Condition_Variable 和mutex 综合使用             condition_variable_and_mutex
 *               生产消费模型，这里使用SLAM的前后端初始化值的传递模型
 *               主要目的 1. 理解condition_variable 的优势
 *                       2. 理解 mutex和condition_variable 实现的差别
 *               cond_var 的优势    1. CPU 小 如果是mutex 的版本占用率100
 *               目前问题：1. 存在多次调用的问题
 */

#include <iostream>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <memory>
#include <queue>
#include <random>
using namespace std;

// 这里也就是一个消费生产模型 
class BackEnd
{
    public:
    BackEnd()
    {
        // 这里的make_unqiue 是 C++14 的新内容
        // 在CmakeLists.txt 需要进行设置成C++14 而不是C++11
         thread_ptr = std::make_unique<thread>(&BackEnd::Process,this);
        // thread_ptr = std::make_unique<thread>(&BackEnd::ProcessWithoutCondVar,this);
        i_queue_.push(12);
        i_queue_.push(13);
        
    }

    ~BackEnd()
    {
        if(thread_ptr->joinable())
        thread_ptr->join();
    }

    void Process()
    {
        thread_running_.store(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        while(thread_running_.load())
        {   
            
            {
                unique_lock<mutex> tmp(queue_lock_);
                // 需要notify才会被触发
                // queue_cond_var_.wait(tmp);
                // 经过阅读 结论就是：
                // 这里的wait 是在收到notify_ 之后进行唤醒，如果条件满足就返回并持有锁，
                // 如果条件不满足就会解锁然后挂载(休眠)
                // 使用 unique_lock 是因为可以多次解锁和上锁
                // 但是为什么没有notify 的情况下 wait 没有进行堵塞 的问题还是不明白
                queue_cond_var_.wait(tmp,[this]{return !i_queue_.empty();});
                cout<<"the size of the queue is "<<i_queue_.size()<<endl;
                auto data = i_queue_.front();
                i_queue_.pop();
                cout<<"[READ] the front data is "<<data<<endl; 
            }
            
        }
    }

    
    void ProcessWithoutCondVar()
    {
        thread_running_.store(true);
        while(thread_running_.load())
        {   
            if(!i_queue_.empty())
            {
                std::lock_guard<mutex> tmp(queue_lock_);
                auto data = i_queue_.front();
                i_queue_.pop();
                cout<<"[READ] the front data is "<<data<<endl; 
            }
        }
    }

    void AddElement(const int msg)
    {
        {
            lock_guard<mutex> tmp(queue_lock_);
            i_queue_.push(msg);
            
            cout<<"[WRITE] a new element has been put into queue :"<<msg<<endl;
        }
        queue_cond_var_.notify_one();
        cout<<"notify"<<endl;

    }

    private:
    
    atomic<bool> thread_running_;
    condition_variable queue_cond_var_;
    mutex queue_lock_;
    std::queue<int> i_queue_;
    std::unique_ptr<thread> thread_ptr;
};


int main(int argc,char **argv)
{
    std::default_random_engine gen;
    std::uniform_int_distribution<> int_random(2,100);
    BackEnd be_;
    for(unsigned int i =0;i<100;i++)
    {
        int msg = int_random(gen);
        be_.AddElement(msg);
        //std::cout << "[FrontEnd]: Add var " << msg << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    


    return 0;
}