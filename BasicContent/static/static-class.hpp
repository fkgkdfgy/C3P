/*
 * @Author: Liu Weilong
 * @Date: 2020-09-07 12:56:50
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-09-07 13:06:01
 * @Description: 用于测试类中的static
 */
#pragma once // 不加上这一条会导致找不到 A 的声明
#include <iostream>

class A
{
    public:
    static void setA(int a);
    static int a_;
};