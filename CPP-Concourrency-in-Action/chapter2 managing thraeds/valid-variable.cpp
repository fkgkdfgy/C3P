/*
 * @Author: Liu Weilong
 * @Date: 2020-09-24 18:14:13
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-09-24 18:24:51
 * @FilePath: /C3P/CPP-Concourrency-in-Action/chapter2 managing thraeds/valid-variable.cpp
 * @Description: 要保证一个线程正在使用的变量到这个线程结束的时候一致有效
 */
#include <thread>
#include <iostream>
using namespace std;
class  func
{
    public:
    func(int & tmp):Content(tmp){}
    
    void operator()()
    {
        for(int i =0;i<Content;i++)
        {
            cout<<"pint aaaaaaaaa"<<endl;
        }
        
    }

    int& Content;
};


void oops()
{
    int count =50;
    thread my_thread{func(count)};
    my_thread.detach();
}

int main()
{
    oops();
}
