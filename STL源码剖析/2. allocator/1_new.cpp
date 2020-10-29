/*
 * @Author: Liu Weilong
 * @Date: 2020-10-28 14:28:40
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-29 09:48:30
 * @FilePath: /C3P/STL源码剖析/2. allocator/1_new.cpp
 * @Description: 本篇来分析new是怎么实现的,
 *               使用c++进行在申请对象的时候用到new,
 *               但是为什么申请对象要用到new, 而不能用malloc, 
 *               而有时申请数组的用new或者malloc似乎又都可以, 这里就来分析一下new实现.
 * 
 *               new operator: 1. 向堆申请内存 调用malloc
 *                             2. 调用构造函数 
 *               
 *               operator new: 1. 只是分配内存其他什么都不做
 *                                          
 * 
 *               placement new  1. 在已经分配的内存上进行构造实例
 * 
 *               仿照实现一下
 */

#include <iostream>

using namespace std;


int main()
{   
    // 第一步 malloc 申请内存
    void * test_ptr = malloc(1*sizeof(double));
    cout<<*(static_cast<double *>(test_ptr))<<endl;
    // placement new 放置数据
    new(test_ptr) double(10);

    void * test_ptr_without_malloc;
    new(test_ptr_without_malloc) double(10);
    cout<<*(static_cast<double *>(test_ptr_without_malloc))<<endl;
    
    cout<<*(static_cast<double *>(test_ptr))<<endl;

    double * offical_new = new double (10);
    cout<< * offical_new<<endl;
    

    return 0;
}