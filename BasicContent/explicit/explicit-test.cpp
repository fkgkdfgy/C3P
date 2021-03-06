/*
 * @Author: Liu Weilong
 * @Date: 2020-09-14 19:31:40
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-09-16 19:12:26
 * @Description: 这个文件用于测试explicit 的作用 主要是限制隐式的类型转换
 *               explicit仅仅适用于单参数的情况
 */
#include <iostream>
using namespace std;

class test1
{
    public:
    explicit test1(int a):a_(a){cout<<"ctor test 1 int used "<<endl;}
    operator int(){return a_;} // 类型转换函数没有 返回类型
    int a_;
};
class test2
{
    public:
    //explicit test2(int a):a_(a){cout<<"using ctor int"<<endl;}
    test2(test1 a):a_(a.a_){cout<<"using ctor test1 "<<endl;}
    int a_;
};

 
int main(int argc,char **argv)
{
    test1 tmp1(10);
    //test2 tmp2(100); // 给test1 加上explicit 之后 就不能隐式地实现 int -> test1 的转换
    test2 tmp3(tmp1);
   // tmp1 = 10; // tmp1 可以使用这种方式进行，因为这里 先把10 利用test(int a) 的构造函数把自己
               // 构造成了一个test1的单位，然后使用 assign function 进行拷贝赋值
               // 这里的 转换很明显是隐式的
    //tmp3 = 1;  // 这里因为 test2(int a) 加上了explicit(清晰的) 的关键字，所以这种转化就只能
               // 显式的进行。
               // 需要注意的是，explicit 仅适用于单参数的ctor
               // 且需要注意的是
    
    return 0;
}