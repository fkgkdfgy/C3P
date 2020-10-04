/*
 * @Author: Liu Weilong
 * @Date: 2020-09-10 15:22:24
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-10-02 09:13:58
 * @Description: 文件用于测试，函数参数是一个引用的使用，在创建临时对象对其赋值的时候，会不会出问题
 *               2020-09-11 09::06::57 第二次添加： 这个.cpp 文件是一个右值学习文件
 *               left value == locator value， right value == read value
 *               左值存在内存中可以进行寻址操作 -> 可以用于指针和引用 右值不能进行寻址 -> 无法对接指针和引用 
 */

#include <iostream>
#include <vector>
using namespace std;

class printf1;
// 已经报错：initial value of reference to non-const must be an lvalue
// ScanMatcher 没有报错的因为可能是代码过多，反映慢
void print(int & h )
{
    cout<<h<<endl;   
}
void printfff(printf1 & a)
{
    cout <<" print a printf1"<<endl;
}
void printfff(printf1 && a)
{
    cout <<" print a printf1"<<endl;
}

class printf1
{
    public:
    printf1(){
        cout<<"the ctor is called"<<endl;
        seq = i;
        cout<<seq<<endl;
        i++;
    }

    // printf1( printf1 tmp)
    // {
    //     cout<<" value copy ctor is called"<<endl;
    // }

    printf1(const printf1 & tmp){
        cout<<"lvalue copy ctor is called"<<endl;
    }

    printf1(const printf1 && tmp)
    {
        cout<<"rvalue copy ctor is called"<<endl;
    }

    printf1 & operator=(const printf1 & tmp)
    {
        cout<< "lvablue assign is called"<<endl;
    }

    printf1 & operator=(const printf1 && tmp)
    {
        cout<<"rvalue assign is called"<<endl;
    }
    
    ~printf1(){cout<<"dtor is used"<<endl;}
    int seq;
    static int i;
};
int printf1::i =0;

int main()
{
    // int & a = 10; 报错因为给引用赋值了一个右值

    // print(10); 报错因为给参数赋值的是一个右值

    printf1 tmp_1;

    printf1 tmp_2;

    printf1 tmp3(tmp_2); // 调用左值拷贝

    cout<<tmp3.seq<<endl; // seq 没有进行初始化 打印值为 -347295312 又一次说明了变量初始化的重要性

    printf1 tmp4(printf1()); // 这里的tmp4 并没有被构造出来，并没有按照所想的调用左值构造函数
                             // 这句没有打印任何信息
                             // TODO 这个很明显是一个右值 奇怪........

    // cout<<tmp4.seq<<endl; 会报错 说找不到tmp4对应的类型

    printf1 tmp5(std::move(tmp_1)); // 使用move 把tmp_1 从左值转换成右值，然assign 给tmp5 调用右值构造，
                                    // 但是因为使用了move  也就是说 tmp_1 已经不在内存中了。tmp_1 无法再被正常使用
                                    
    cout<<tmp_1.seq<<endl;          // 试了一下感觉没啥问题啊，但是既然说不要再用 就先记着不要再用好了

    printf1 tmp6 = tmp_2; // 因为这里还是在对象实例化，所以编译器还是使用拷贝构造来进行

    printf1 tmp7 =std::move(tmp_2); // 因为这里还是在对象实例化，所以编译器还是使用拷贝构造来进行

    printf1 tmp8,tmp9;

    tmp8 = tmp6;            // 以下两句调用assign
    tmp9 = std::move(tmp7);

    printfff(printf1()); //  这里vector pushback可以pushback的原因是因为已经定义好了 右值为形参的函数
                         //  这里的printfff 补充上&& 的参数之后也就可以正常使用了

    std::vector<printf1> printfPool;

    printfPool.push_back(printf1());
    return 0;
}