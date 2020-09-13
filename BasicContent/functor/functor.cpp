/*
 * @Author: Liu Weilong
 * @Date: 2020-09-13 19:09:32
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-09-13 19:23:41
 * @Description: Functor 的模板成员函数调用
 */

#include <iostream>
#include <typeinfo>

using namespace std;

struct Functor
{
    template <typename T>
    bool operator()(T&& tmp)
    {
        cout<<typeid(T).name()<<endl;
        cout<<tmp<<endl;
        return true;
    }
};

int main()
{
    // 同一个模板可以实例化出多个成员函数
    Functor cfor;
    cfor(double(10.0));
    cfor(float(10.0));
    return 0;
}
