/*
 * @Author: Liu Weilong
 * @Date: 2020-09-23 13:17:08
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-23 13:23:03
 * @FilePath: /C3P/BasicContent/template/member-function-member-specialize.cpp
 * @Description: 用于测试之前, ceres 当中成员函数模特特化不通过的情况
 */

#include <iostream>
using namespace std;

class A
{
    public:

    template <typename T>
    void print( T msg)
    {
        
        cout<< msg<<<endl;
    }

    // 成员函数模板的特化不能放在 类内部进行

    // template<>
    // void print<int>(int msg)
    // {
    //         cout<<msg<<endl;
    // }
    private:

};
// 这样定义就是可以通过的了
template<>
void A::print<int>(int msg)
{
        cout<<msg<<endl;
}

int main(int argc,char **argv)
{


    return 0;
}