/*
 * @Author: Liu Weilong 
 * @Date: 2020-08-31 14:15:56 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-08-31 14:25:45
 */

#include <iostream>
#include <memory>

// 测试用于测试using 在继承的过程中的作用域

/**
 * @brief: 结果就是 public 里的 using 在子类中是可以直接调用的 
 *         但是 private 的using 在子类中是不可以直接调用的 
 */


class A
{
    public:
    using int_ptr = std::shared_ptr<int>;
    virtual void show(int_ptr a ){ std::cout<<"the content of ptr is "<<*a<<std::endl;}

};

class B: public A
{
    public:
    void show(int_ptr a){std::cout<<"the content of ptr is "<<*a + int(1000)<<std::endl;}
};


int main()
{
    A a;
    B b;
    std::shared_ptr<int> a_ptr = std::make_shared<int>(90);
    a.show(a_ptr);
    b.show(a_ptr);
}
