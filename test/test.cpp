/*
 * @Author: Liu Weilong
 * @Date: 2020-10-09 18:07:56
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-09 18:21:37
 * @FilePath: /C3P/test/test.cpp
 * @Description:  
 */

#include <array>
#include <algorithm>

using namespace std;
int main()
{
    array<int,8> a1{1,1,2,5,34,0,0,0};
    array<int,3> a2{1,12,23};
    for(int i  = 0;i<n;i++)
    {
        a1[m]= a1[i];
        m++;
    }
    auto end = a1.begin()+n;
    std::sort(a1.begin(),end,std::greater<int>());
}