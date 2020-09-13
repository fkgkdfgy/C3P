/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-04 12:54:18 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-04 13:33:24
 */


#include <iostream>
using namespace std;

#ifdef US_B
class B
{
    public:
    void print(){cout<<"print out AAAAAAA"<<endl;}
    void get();
};
#else
class B
{
    public:
    void print(){cout<<"print out BBBBBBB"<<endl;}
    void get();
};
#endif

