/*
 * @Author: Liu Weilong
 * @Date: 2020-09-22 10:19:18
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-22 10:21:02
 * @FilePath: /C3P/BasicContent/include-error/header.hpp
 * @Description: 用于浮现include multiple definition 的error
 */

#pragma once

#include <iostream>
using namespace std;
void print_A()
{
    cout<<"A"<<endl;
}

void print_B()
{
    cout<<"B"<<endl;
}
