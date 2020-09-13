/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-05 10:42:16 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-05 12:10:54
 */

#include <iostream>

using namespace std;

// 测试 default ctor
class B
{
    public:
    B() =delete;

    B(int a):a_(a){}
    int a_;
};

// 测试 拷贝和赋值给 引用 和 const 成员

class A
{
    public:
    
    A(int a):ra(a){ ra = 1000;}
    
    private:

    int &ra;
};



int main()
{
    B b(12);
    cout<<b.a_<<endl;
    // B c; 这个会报错 因为 default ctor 已经被删除
    
    int tmp = 10;
    A a(10);  
    A a_t(tmp); // 均没有报错，不过因为是值传入，所以没有关联关系，在类内进行的更改不会对类外数值有影响
    
    cout<<tmp<<endl;
    // a = a_t; 
    // a(a_t);  以上两行均会报错



}