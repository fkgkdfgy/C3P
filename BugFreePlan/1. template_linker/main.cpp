/*
 * @Author: Liu Weilong
 * @Date: 2020-10-02 22:15:20
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-04 11:49:42
 * @Description: 
 */
#include "foo.hpp"

int main()
{   
    
    print(int(5));
    // print<float>(float(5)); 会报错， 最方便还是直接把模板的定义和声明直接写在一起
    C c;
    c.print(5);

    CTemplate<int> ct;
    ct.print(5);

    // 写在一个文件内，不论是直接定义还是  定义+声明 的形式 都是可以正常使用的
    CDefInHpp d;
    d.print(float(5));

}
