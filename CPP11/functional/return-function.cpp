/*
 * @Author: Liu Weilong
 * @Date: 2020-09-08 18:48:17
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-14 16:43:53
 * @Description: 用于测试返回function 的函数如何使用
 */

#include  <iostream>
#include  <functional>
#include  <math.h>
#include  <string>
using namespace std;



// 
template<typename T>
function<int(T)> integralType(int i=1)
{
   return ceil;
}

template <typename T>
void printaa(T a){
    cout<<a<<endl;
}



int main(){
    
    auto f_1 = integralType<float>();
    function<int(double)> f_2 = integralType<double>();
    auto f_3 = integralType<u_char>();
    // auto f_4 = integralType<string>(); 还是有良心会报错的
    cout<<f_1(1.7)<<endl;
    cout<<f_2(1.7)<<endl;
    cout<<f_3(1.7)<<endl;
    // cout<<f_4("1.7")<<endl;

    // 函数模板 隐式实例化

    printaa("sasdasd");
    return 0;
}