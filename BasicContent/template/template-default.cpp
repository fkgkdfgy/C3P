/*
 * @Author: Liu Weilong
 * @Date: 2020-09-11 12:41:01
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-09-11 12:53:47
 * @Description: 模板 默认值
 */

#include <iostream>
using namespace std;

template <typename Scalar,uint n=3>
class vector
{
    public:
    vector(){ps = new Scalar[n];cout<<"ctor is used"<<endl;}
    ~vector(){delete []ps; cout<<"dtor is used"<<endl;}    
    Scalar * ps;
};

int main()
{
    vector<float> v;

}