/*
 * @Author: Liu Weilong
 * @Date: 2020-09-24 09:15:28
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-24 09:24:43
 * @FilePath: /C3P/BasicContent/using/using-rename_function.cpp
 * @Description: 用于测试 使用using 重命名一个函数
 */

#include <iostream>
using namespace std;

template<typename T>
void print(T msg)
{
    cout<<msg<<endl;
}

template <typename T>
class print_1
{
    public:
    void operator()(T msg)
    {
        cout<<msg<<endl;
    }
};

int main(int argc,char **argv)
{
    // using 只能应用于一个类 或者 namespace 或者 class template
    // using ptstr = print<string>(string); 对于一个函数模板使用template 会报错
    using ptstr = print_1<string>; // 写一个仿函数则可以通过

    ptstr a;
    a("sssss");
     

    return 0;
}
