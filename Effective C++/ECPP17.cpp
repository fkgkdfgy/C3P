/*
 * @Author: Liu Weilong
 * @Date: 2020-09-14 16:18:38
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-15 11:17:30
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

// 产生的顺序 可能是 test_funch new Widget 然后make_share
// 也可能是 new Widge 然后test_func 最后make_shared 
// 结果就是如果 中间位置进行test_func 的时间abort()
// new Widge 就没有了delete 与之对应 -> 内存泄漏

int main(int argc,char **argv)
{
    print(shared_ptr<Widget>(new Widget),test_func());
    return 0;
}