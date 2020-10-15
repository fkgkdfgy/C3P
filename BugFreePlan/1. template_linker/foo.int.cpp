/*
 * @Author: Liu Weilong
 * @Date: 2020-10-02 22:37:31
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-15 16:44:50
 * @Description: explicit 实例化，这么写之后，template 就不在具有隐式示例化的功能了
 *               I will do it， though it is confusing
 */

#include "foo.cpp"

// 函数模板
// template void print<int>(const int &msg); 注释会报错
template void C::print<int>(const int &);

// 类模板
template void CTemplate<int>::print(const int &);
