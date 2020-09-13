/*
 * @Author: Liu Weilong 
 * @Date: 2020-08-31 16:22:26 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-08-31 16:26:40
 */

/** @brief 主要是用于实验Variadic Template 在递归中的作用
 * 
 * 
*/


#include <iostream>
#include <bitset>

using namespace std; 

/**
 * @brief: ... 是一个pack
 */


/** 用于处理sizeof...(args)==0 的情况
 *  一个print重载
*/
void print()
{
    
}

template<typename T,typename... Types>
void print(const T & firstArg, const Types&... args)
{
    // sizeof...(args) 用于显示 args 剩下的数量
    cout<<"now there are "<<sizeof...(args)<<" args remained"<<endl; 
    cout<<"the firstArg is "<<firstArg<<endl;
    // 继续使用args的时候需要使用args...,而不只是args
    print(args...);
}


int main()
{
    print(7.5,"hello",bitset<16>(377),43);
    return 0;
}