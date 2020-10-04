/*
 * @Author: Liu Weilong
 * @Date: 2020-10-04 22:50:36
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-04 23:02:10
 * @Description: typename 另外的一些使用
 */

#include <iostream>
#include <vector>
using namespace std;

class TypenameOtherThing
{
    public:
    template <typename T1,typename T2>
    void print(const T2<T1> & msg)
    {
        
    }
};

