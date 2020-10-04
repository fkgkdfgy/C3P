/*
 * @Author: Liu Weilong
 * @Date: 2020-10-04 11:39:20
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-04 22:21:07
 * @Description: 
 */

#include "foo.hpp"

int foo::b = 20;

int & foo::getA()
{
    static int a =10;
    cout<<"the address of a is "<< &a<<endl;
    return a;
}

void foo::showBA()
{
    cout<<b<<endl;
    cout<<getA()<<endl;
}