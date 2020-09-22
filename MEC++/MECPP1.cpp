/*
 * @Author: Liu Weilong
 * @Date: 2020-09-18 09:49:10
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-21 09:25:09
 * @FilePath: /C3P/MEC++/MECPP1.cpp
 * @Description: 类型推断 主要内容： 1. template 推断数组大小
 */


#include <iostream>
using namespace std;

// 为什么需要括号现在还是想不明白
template<typename T,std::size_t N>
unsigned int arraySize(const T(&)[N] )
{
    return N;
}

int main(int argc,char **argv)
{
    
    char * tmp = new char [50]();
    char tmparray[20]{};
    arraySize(tmparray);
    return 0;
}