/*
 * @Author: Liu Weilong
 * @Date: 2020-10-27 15:38:42
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-27 16:38:58
 * @FilePath: /C3P/STL算法剖析/1. Preparation/template_exercise2.cpp
 * @Description: 
 *              1. 非类型参数模板
 *                 非类型参数, 可用在模板中自定义为整型类型, 指针或引用, 不能定义为浮点数等其他类型.
 *                 非类型模板参数在编译期间就已经实例化, 所以其模板实参必须是常量表达式.
 *                 + 学习一下 函数参数是数组的情况
 *              2. 
 */

// ========================== 1 =============================


#include <iostream>
using namespace std;
// 正常传递的情况s
// 如果没有 & a 会被int a[] 会被当作指针处理
// (&a) 当作数组引入的时候 () 是必须的
// 且当传引用的时候 [] 内不可以为空
void getSize_unknownSize(int (&a) [3])
{
    cout<< " in getSize_unknownSize "<<endl;
}

void getSize_knownSize(int (&a)[10])
{
    cout<< " in getSize_knownSize "<<endl;
}

// 以下是正文
// 如果没有 & a会被当作 指针传入 
// 且出于parser 的解析顺序的考虑 需要添加 () -> 最后写作 (& a)
template <typename T,size_t N>
void getSize( T (&a)[N])
{
    cout<<" the size is "<<N<<endl;
}


int main()
{
    int a[10]= {};
    getSize(a);
    getSize_knownSize(a);
    // getSize_unknownSize(a); // 类型不对这里会报错 int [] 并不能和 int[const N ] 相对应

    return 0;
}