/*
 * @Author: Liu Weilong
 * @Date: 2020-09-25 16:15:44
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-25 16:22:06
 * @FilePath: /C3P/CPP-Concourrency-in-Action/include/common.hpp
 * @Description: Common 函数 防止多次编写 相同的内容
 */

#include <iostream>

using namespace std;
void print()
{
    cout<<"========= print start =================="<<endl;
    for(int i =0;i<20;i++)
    {
        cout<<i<<endl;
    }
}