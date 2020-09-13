/*
 * @Author: Liu Weilong 
 * @Date: 2020-08-31 11:03:45 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-03 16:15:58
 */



#pragma once
#include <iostream>
#include <functional>
#include <assert.h>
// 融合functional 和模板类
int transfer(float a)
{
    std::cout<<"transform the float to int"<<std::endl;
    return a;
}

int downsampling(int msg)
{
    std::cout<<"downsampling complete "<<msg<<std::endl;
    return msg;
}

template<typename T1,typename T2>
T2 noNeedtransfer(T1 msg)
{
    assert(typeid(T1)==typeid(T2));
    std::cout<<"Do not need to transfer"<<std::endl;
    return msg;
}

template<typename T1,typename T2>
class A
{
    public:
    
    A(std::function<T2(T1)> transfer){transfer_ = transfer;}

    virtual T2 get(T1 msg) const  = 0;

    std::function<T2(T1)> transfer_;
}
;

// 融合模板基类 + functional + 虚函数
// 继承不需要class

/**
 * 新添加的内容： 给function 参数添加默认function
 * 
 */
template <typename T1,typename T2>
class B :public A<T1,T2>
{
    public:
    B(std::function<T2(T2)> downsampling,
    std::function<T2(T1)> transfer = noNeedtransfer<T1,T2>):A<T1,T2>(transfer){
        downsampling_ = downsampling;
    }
    
    T2 get(T1 msg) const;

    std::function<T2(T2)> downsampling_;
};

template<typename T1,typename T2>
T2 B<T1,T2>::get(T1 msg) const
{
    // 继承类  不使用this -> 找不到基类的类成员
    T2 temp = this->transfer_(msg);
    T2 result = downsampling_(temp);
    return result;
}

int main()
{
    B<int,float> a(transfer,downsampling);
    B<int,int> b(downsampling);
    a.get(35.23);
    b.get(70);
}