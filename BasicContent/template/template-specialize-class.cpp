/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-02 15:01:52 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-02 15:17:01
 */

#include <iostream>
#include <vector>
#include <string>

// 类模板是可以偏特化的，函数模板只能全特化
// 而且类模板的实例化并不能是隐式的，必须是显式的


// 这里需要注意没有特化 类模板  名字后面是不能加<T1,T2>的   刚刚实测会报错
template<typename T1,typename T2>
class Compare
{
    public:
    int compare(const T1 && a,const T2&& b)
    {
        std::cout<<a<<std::endl;
        std::cout<<" A common template， T1 ==template  T2== template"<<std::endl;
        return 1;
    }
    template<typename T3,typename T4>
    int test_reference( T3&&c , T4&& d);
};

template<typename T1,typename T2>
template<typename T3,typename T4>
int Compare<T1,T2>::test_reference( T3 && c, T4&&d)
{
    std::cout<<"member funtion template of a class template"<<std::endl;
    return 1;
}

// 第一版本的偏特化， 第二个参数变为了int
template<typename T>
class Compare<T,int>
{
    public:
    int compare(const T & a,const int& b)
    {
        std::cout<<a<<std::endl;
        std::cout<<" A common template T1 == template， T2 == int"<<std::endl;
        return 1;
    }
};

// 第二个版本的偏特化， 只接受第一参数是指针或者引用的情况
template<typename T>
class Compare<T*,int>
{
    public:
    int compare(const T& a,const int& b)
    {
        std::cout<<a<<std::endl;
        std::cout<<" A common template T1 == pointer T2 == int"<<std::endl;
        return 1;
    }
};

template<typename T>
class Compare<T&,int>
{
    public:
    int compare(const T& a,const int& b)
    {
        std::cout<<a<<std::endl;
        std::cout<<" A common template T1 == pointer T2 == int"<<std::endl;
        return 1;
    }
};

template<typename T>
class Compare<std::vector<T>,int>
{
    public:
    int compare(const T& a,const int& b)
    {
        std::cout<<a<<std::endl;
        std::cout<<" A common template T1 == pointer T2 == int"<<std::endl;
        return 1;
    }
};


int main(int argc, char const *argv[])
{
    Compare<double,float> tmp1; // 最普通的版本
    double num1 =10;
    float num2 = 20;
    std::string tmp_str = "sds ";
    tmp1.test_reference(10,20); // 真相大白了: rvalue can be binded to rvalue reference 
                                //                                 or const lvalue referecne
                                //            lvalue can be binded to lvalue reference
                                // 且模板类中，万能引用并不生效。
                                // 且且如果模板类中定义函数模板也不能继续用万能引用
    return 0;
}

