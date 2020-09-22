/*
 * @Author: Liu Weilong
 * @Date: 2020-09-22 10:22:45
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-22 11:14:18
 * @FilePath: /C3P/BasicContent/include-error/include-main.cpp
 * @Description: 最后那个multiple definition of function 也没有复现出来，但是找到了解决的方法
 *               就是 declare 和definition 彻底分离，一个在.hpp 一个在.cpp 就可以遏制这种问题的出现
 */
#include "include-A.hpp"
#include "include-B.hpp"

class C
{
    public:
    void print()
    {
        a.print();
        b.print();
    }
    A a;
    B b;
};


int main()
{
    C c;
    c.print();
    return 0;
}
