/*
 * @Author: Liu Weilong
 * @Date: 2020-09-13 17:00:20
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-09-13 20:15:53
 * @Description: 主要是用于解决 ceres 当中参数调用的时候判断成引用的问题
 *              最后发现原因是 operator () 没有添加 const 关键字限制
 */


#include <iostream>
#include <typeinfo>
using namespace std;

// 第一部分仿函数
class CostFunctor
{
    public:
    template<typename T>
    bool operator()(const T* const pT,T* residual)const{
        cout<<typeid(T).name()<<endl;
        cout<<"the pT is "<<*pT<<endl;
        *residual = *pT;
        return true;
    }
};

// 第二部分pointer-like-class
template <class C>
class easyPtr
{
    public:
    easyPtr(C* pT):pC(pT){}
    C& operator*()const {return *pC;}
    private:
    C* pC;
};

int main(int argc, char const *argv[])
{
    /**
     * @brief pointer 基础内容  
     */ 
    // 多级指针
    double a =10;
    double * dptr = &a;
    double ** dpptr = &dptr;

    // 动态指针
    int size = 10;
    double dArray[10];
    double dyndArray[size]; // 可能是编译器的原因，并没有报错

    // 指针数组
    // 一个数组里面有很多的指针
    double *Arrayp[5]{};
    Arrayp[0] = new double();
    Arrayp[1] = new double();

    
    // 数组指针
    

    // 指针数组
    


    

    return 0;
}

