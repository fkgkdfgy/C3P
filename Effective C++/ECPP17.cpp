/*
 * @Author: Liu Weilong
 * @Date: 2020-09-14 16:18:38
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-14 16:48:07
 * @FilePath: /C3P/Effective C++/ECPP17.cpp
 * @Description: 对应ECPP 第17条 使用独立语句将newd 对象放置入智能指针
 */

#include <iostream>
#include <memory>
using namespace std;

int test_func()
{
    cerr<<"There is something wrong"<<endl;
    return 0;
}

class Widget
{
    public:
    Widget(){cout<<"ctor is called "<<endl;}
    ~Widget(){cout<<"dtor is called "<<endl;}
};

void print(shared_ptr<Widget> tmp,int tmp_i)
{
    
}

// 顺序 test_func()

int main(int argc,char **argv)
{
    print(shared_ptr<Widget>(new Widget),test_func());
    return 0;
}