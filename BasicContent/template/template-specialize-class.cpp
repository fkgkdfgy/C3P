/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-02 15:01:52 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-02 15:17:01
 */

#include <iostream>

// 类模板是可以偏特化的，函数模板只能全特化

template<typename T1,typename T2>
class Compare<T1,T2>
{
    public:
    int compare(const T1 & a,const T2& b)
    {
        std::cout<<" A common template"<<std::endl;
        return 1;
    }
};

template<typename T>
class Compare<T,int>
{
    public:
    int compare(const T1 & a,const int& b)
    {
        std::cout<<" A common template"<<std::endl;
        return 1;
    }
}

