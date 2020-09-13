/*
 * @Author: Liu Weilong
 * @Date: 2020-09-08 14:00:35
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-09-11 09:31:30
 * @Description: 用于测试 内置的类型 uchar
 */

#include <iostream>
using namespace std;


int main()
{
    using uchar = unsigned char;
    unsigned char a =10;
    unsigned char b = 3;

    unsigned char c = 10;
    unsigned char d = 12;
    
    uchar e = a+b;
    uchar f = c-d;

    cout<<" "<<endl;
    cout<<f<<endl;
    return 0;
}