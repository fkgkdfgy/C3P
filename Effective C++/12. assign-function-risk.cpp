/*
 * @Author: Liu Weilong
 * @Date: 2020-09-14 14:10:40
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-14 14:33:53
 * @FilePath: /C3P/Effective C++/12. assign-function-risk.cpp
 * @Description: 对应Effective C++ 第12条 ： 如果是自己定义copy ctor 、copy assignment function 
 *               请肩负起copy所有内容的责任
 */


/**
 * @brief 需要注意的一共四个点: Base 的copy ctor、copy assignment                            
 *                           Derived的 copy ctor 、copy assignment
 * 
*/
#include <iostream>

using namespace std;



// 如果自定义的assign Function 忘记进行赋值的话，编译器不会进行提醒
class Base
{
    public:
    Base()=default;
    Base(int rc,int lc):rememberContent_(rc),leftContent_(lc){}
    Base & operator=(const Base & tmp)
    {
        cout<<"the self-defined assign function is used "<<endl
        << "then the left Content is forgotton"<<leftContent_<<endl;;
    }
    private:
    int rememberContent_;
    int leftContent_;
};


// 在继承中的巨大危机
class DerivedFragile :public Base
{
    public:
    DerivedFragile(int a,int b,int c):derivedContent(c),Base(a,b){}

    // 这个时候copy ctor 会出问题 Base 如果这个时候 Base()=default; 很容易出现 只有derivedContent的内容被修改的情况
    DerivedFragile(const DerivedFragile &tmp):derivedContent(tmp.derivedContent){} 

    
    DerivedFragile & operator=(const DerivedFragile &tmp){
        derivedContent = tmp.derivedContent;
        // Base::operator=(tmp); 如果没有这句那么Base 的成员对象不会被修改

    }


    private:
    int derivedContent;
};



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

    
