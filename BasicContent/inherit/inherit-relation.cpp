/*
 * @Author: Liu Weilong
 * @Date: 2020-09-11 13:47:36
 * @LastEditors: Liu Weilong
 * @LastEditTime: 2020-09-11 14:49:36
 * @Description:  继承关系的测试
 */

#include <iostream>
using namespace std;

class Base
{
    public:
        Base(){priBaseContent = 100; pubBaseContent = 1;proBaseContent = 10;}
        int pubBaseContent;
        int getPriBaseContent(){return priBaseContent;}

    protected:
        int proBaseContent;
    private:
        int priBaseContent;
};

class PubDerived: public Base
{
    public:
        PubDerived(){}
    private:
    using Base::pubBaseContent;
            
};

class PriDerived: private Base
{
    public:
    
};

int main()
{
    PubDerived pubd;
  //cout<<pubd.pubBaseContent<<endl;      // public 继承可以直接调用 基类public 的成员
    cout<<pubd.getPriBaseContent()<<endl; // 需要调用基类的成员函数才能得到priBaseContent

    PriDerived prid;
  //cout<<prid.pubBaseContent<<endl;      // private 继承
                                          // 报错：因为pubBaseContent并没有访问
  //cout<<prid.getPriBaseContent()<<endl; // 报错：因为getPriBaseContent并没有访问

    
}
