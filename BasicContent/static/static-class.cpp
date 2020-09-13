/*
 * @Author: Liu Weilong
 * @Date: 2020-09-07 12:57:23
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-09-07 13:07:10
 * @Description:
 */
#include "static-class.hpp"

using namespace std;

int A::a_; // 这一条必不可少  必须要加
void A::setA(int a)
{
    a_ =a;
};

int main(int argc, const char** argv) { 

    A::setA(4);
    
    cout<<A::a_<<endl;
    return 0;
}