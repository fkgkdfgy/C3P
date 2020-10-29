/*
 * @Author: Liu Weilong
 * @Date: 2020-10-02 09:12:22
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-27 17:16:15
 * @Description: 主要是用于探究Big Five 在传递参数的时候 经历了什么
 *               1. 函数传参的构造方式
 *               2. for_each 的构造方式
 */
#include <iostream>
#include <vector>
using namespace std;
class printf1
{
    public:
    printf1(){
        cout<<"the ctor is called"<<endl;
        static int i =0;
        index = i;
        i++;
        ShowIndex();
    }

    printf1(const printf1 & tmp){
        cout<<"lvalue copy ctor is called"<<endl;
        ShowIndex();
    }

    // 刚刚发现自己的移动构造写的有问题
    // 移动构造的主要的目的是 减少 拷贝构造的时候 tmp 对象的构造 析构消耗
    printf1( printf1 && tmp)
    {
        cout<<"rvalue copy ctor is called"<<endl;
        ShowIndex();
    }

    printf1 & operator=(const printf1 & tmp)
    {
        cout<< "lvablue assign is called"<<endl;
        ShowIndex();
    }

    // 这个右值的移动赋值实际上是没有意义的，因为右值是可以直接被 const & 承接的
    // 所以最终还是Big Five
    // 2020.10.27 是意义的  可以防止深度拷贝
    printf1 & operator=( printf1 && tmp)
    {
        cout<<"rvalue assign is called"<<endl;
    }
    
    void ShowIndex(){cout<<"the index in the obj is "<<index<<endl;}

    ~printf1(){cout<<"dtor is used"<<endl;
    ShowIndex();}
    
    int index;
};


void PassByValue(printf1 tmp)
{
    cout<<"pass by value "<<endl;
}

void PassByLrefer(printf1 & tmp)
{
    cout<<"pass by lrefer"<<endl;
}

void PassByRrefer(printf1 && tmp)
{
    cout<<"pass by rref"<<endl;
}

void PassByConstLrefer(const printf1 &tmp)
{
    cout<<"pass by const lrefer"<<endl;
}

int main()
{
    printf1 tmp;
    cout<<"=================================="<<endl;
    PassByValue(tmp); // 只有一个 copy ctor 进行构造
    cout<<"=================================="<<endl;
    PassByLrefer(tmp);// 不进行构造
    cout<<"=================================="<<endl;
    PassByRrefer(printf1()); // 不进行构造
    cout<<"=================================="<<endl;
    PassByConstLrefer(tmp); // 不进行构造
    cout<<"=================================="<<endl;

    std::vector<printf1> print_array(8,printf1());
    cout<<"=================================="<<endl;
    // 不加 & 就会是 左值拷贝构造一直在进行
    // 加上 & 就不会使用任何构造
    for(auto  element:print_array)
    {
        
    }
    


}