/*
 * @Author: Liu Weilong
 * @Date: 2020-09-30 14:03:09
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-02 09:55:12
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter2 managing threads/parallel_accumulate.cpp
 * @Description: 一个并行计算模块编写
 */

#include <thread>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

template<typename Iter,typename T>
class ActionModule
{
    public:
    void operator()(Iter begin,Iter end,T&result)
    {
        result = std::accumulate(begin,end,0);
    }
    
};

class ParallelAccumulate
{
    public:
    template <typename T>
    T Run(const std::vector<T> & data_array,T init)
    {
        auto diff = std::distance(data_array.begin(),data_array.end());
        if(diff ==0)
        return init;
        unsigned int min_per_thread = 10;
        unsigned int calculated_threads = diff/min_per_thread + 1;

        // 决定线程数
        cout<<"the hardware concurrency is "<<std::thread::hardware_concurrency()<<endl;
        unsigned int thread_number = min(calculated_threads,
        std::thread::hardware_concurrency()==0?2:std::thread::hardware_concurrency());

        std::vector<std::thread> thread_array(thread_number-1);
        std::vector<T> results_(thread_number);
        auto begin_tmp = data_array.begin();
        auto stride = diff/(thread_number-1);
        unsigned int count = 0;
        for(int i =0; i< (thread_number-1) ;i++)
        {   
            // 进行添加线程
            auto end_tmp = begin_tmp;
            std::advance(end_tmp,stride);
            ActionModule<decltype(data_array.begin()),T> tmp_c; 
            thread_array[i] = std::thread(tmp_c,begin_tmp,end_tmp,std::ref(results_[i]));
            begin_tmp = end_tmp;
        }
        ActionModule<decltype(data_array.begin()),T> c;
        c(begin_tmp,data_array.end(),results_.back());
        
        for(int i =0 ;i<thread_array.size();i++)
        {
           thread_array[i].join();
        }
        
        // 因为这里的 不加 & 是使用左值构造 但那是thread 左值构造已经  =delete所以会调用失败
        // 所以 单个auto 还是会进行构造
        // 但是 auto & 就不会进行构造
        // 这直接和 auto 的推导有关系
        for(auto &element:thread_array)
        {
            if(element.joinable())
            element.join();
        }

        return std::accumulate(results_.begin(),results_.end(),init);
    }
};

int main()
{
    std::vector<float> data_array_;
    float init = 0;
    data_array_.reserve(600);
    for (int i = 0;i<600;i++)
    {
        data_array_.push_back(float(i));
    }
    ParallelAccumulate pa;
    auto result = pa.Run(data_array_,init);
    cout<< result<<endl;
    cout<<std::accumulate(data_array_.begin(),data_array_.end(),0)<<endl;
    return 0;
}