/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-03 14:31:08 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-03 15:24:23
 */


#pragma once

template <typename T>
class A
{
    public:
    A(){}
    virtual void get(const T & t_1,T & t_2) =0; 
};
