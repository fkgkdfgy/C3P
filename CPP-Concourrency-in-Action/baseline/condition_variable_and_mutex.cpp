/*
 * @Author: Liu Weilong
 * @Date: 2020-10-10 09:21:14
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-29 15:15:59
 * @FilePath: /C3P/CPP-Concourrency-in-Action/baseline/condition_variable_and_mutex.cpp
 * @Description: Condition_Variable 和mutex 综合使用             condition_variable_and_mutex
 *               生产消费模型，这里使用SLAM的前后端初始化值的传递模型
 *               主要目的 1. 理解condition_variable 的优势
 *                       2. 理解 mutex和condition_variable 实现的差别
 *               cond_var 的优势    1. CPU 小 如果是mutex 的版本占用率100
 *               目前问题：1. 存在多次调用的问题
 *                          目前的猜测是 
 *                          通过第一次调用结束之后，因为没有等待，所以就直接进入下一次循环
 *                          unique_lock 再次锁定，因为持有锁 condition_var 的wait 会直接进行条件判断
 *               condition_var 比mutex 是在进行循环上查看的时候CPU 的占用率
 *               例子就是：
 *               一个蛋糕流水线，mutex 的循环查看，相当于人要一直看着轨道，如果有蛋糕来了，
 *                            人把机器停下来(lock)，把蛋糕拿下来，人非常累(CPU高)
 *                            condition_var的循环查看，相当于在轨道上按了一个蛋糕检查装置，如果有蛋糕来了，
 *                            就给人发警示信号,人把机器人停下来，把蛋糕拿下来，人轻松了很多(CPU低)
 *               
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
                // 2020.10.29 当天第一次补充
                // 每一次进入这个code block 都是先对mutex 进行上锁
                // 之后将锁传递给condition var (解锁然后进行信号等待)   （）内部为猜测 书上感觉没有在细节上进行讲述
                // 这里的wait 是在收到notify_ 之后进行唤醒进行上锁尝试，中间会进行堵塞，如果条件满足就返回并持有锁，
                // 如果条件不满足就会解锁然后挂载(休眠)
                // 使用 unique_lock 是因为可以多次解锁和上锁
                // 但是为什么没有notify 的情况下 wait 没有进行堵塞 的问题还是不明白
                queue_cond_var_.wait(tmp,[this]{return !i_queue_.empty();});
                // 按道理讲以下两句效果应该完全一样
                // 但是目前发现完全不是这样
                // 2020.10.29 当天第二次补充
                // 经过品味这个过程我大概是明白了
                // 这里的休眠是真的进行休眠，线程在激活之后就会一直进行动作，知道下次满足休眠的条件，wait(mutex,condition)
                // 内部的实现是while(condition)。 也就是说持有锁之后，知道conditon满足就会一直干活
                // 直到condition不再满足，线程进行休眠，进入叫醒队列排队。
                // 也就是说 wait() 休眠 是类似于 人睡过去了 不能工作了 只能等下次唤醒之后才能工作 而不是一个类似堵塞的逻辑
                // 这里应该是直接和底层对接
                // 所以才会下面代码表现不同的情况
                // queue_cond_var_.wait(tmp,[this]{return true;});
                // queue_cond_var_.wait(tmp);
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