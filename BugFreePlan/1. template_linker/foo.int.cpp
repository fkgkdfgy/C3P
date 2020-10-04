/*
 * @Author: Liu Weilong
 * @Date: 2020-10-02 22:37:31
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-02 22:50:38
 * @Description: explicit 实例化，这么写之后，template 就不在具有隐式示例化的功能了
 */

#include "foo.cpp"


template void print<int>(const int &msg);
template void C::print<int>(const int &);
template void CTemplate<int>::print(const int &);