/*
 * @Author: Liu Weilong
 * @Date: 2020-10-15 15:43:36
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-15 16:22:05
 * @FilePath: /C3P/BugFreePlan/5. relative_path/foo.cpp
 * @Description:  如何正确使用relative path
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc,char ** argv)
{
    // 1. 也就是说这里的relative path 的起始地址是
    //    调用可执行文件 的 终端(terminal) 的地址

    // 2. 经过实验 argv 存储的是 可执行文件 相对于调用终端(terminal)的相对路径
    string relative_path = "../file/aaaa";

    cout<<"show the executable path: "<<argv[0]<<endl;

    fstream fstr_(relative_path);     

    if(!fstr_.is_open())
    cerr<<"there must be something wrong with the file path"<<endl;
}