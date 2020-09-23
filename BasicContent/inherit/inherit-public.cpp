/*
 * @Author: Liu Weilong
 * @Date: 2020-09-18 10:08:29
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-23 18:18:50
 * @FilePath: /C3P/BasicContent/inherit/inherit-public.cpp
 * @Description: 用于探究 public 的继承的一些结论:
 *               1. 用于测试 class 内的public、private 会不会对写成 虚函数造成影响 
 *                  结论：加强了对于函数的认识，父类中 public的虚函数，可以通过动态绑定的方式访问到子类private的虚函数(神奇)
 *                       并且一旦通过动态绑定来调用函数，那么就只能调用父类中的成员函数
 *               2. 
 */
#include <iostream>

using namespace std;

class Base
{
    public:
    Base(){}
    virtual ~Base(){}
    virtual float getContent()const {        
        cout<<"Base get Content"<<endl;     
        return 5.0;
    }

    int getbaseContent(){return baseContent_;}
    void func(){cout<<"this is a public function of base class"<<endl;}
    private:
    void func2(){cout<<"this is a private function of base class"<<endl;} // 这个无法使用using 来改变可访问性
    int baseContent_;
};

class Derived:public Base
{
    public:

    void callGetContent()const{getContent();}

    void printBaseContent(){cout<< getbaseContent()<<endl;} // 可以使用Base public 的成员函数，对Base private的对象进行访问
    void printBaseContent_1(){cout<<baseContent_<<endl;} // 直接访问 Base private 的内容会报错

    private:
    using Base::func;
    // using callGetContent; // 子类本身的成员函数不能使用 using 来改变可访问性
    float getContent()const{
        cout<<"Derived get Content"<<endl;
        Base::getContent();
    
    }
};

int main()
{
    // Test1 
    Base* bptr = new Derived();
    bptr->getContent(); // 不可思议竟然直接访问到了 Derived 的 private member function
    Derived tmp_obj;
    //tmp_obj.func(); // 在using Base::func 声明之后，func 就没有了可访问性
    
    return 0;
}