/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-04 12:58:05 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-04 13:45:29
 */
#include "Config.h"
#include "macro.hpp"

#ifdef US_B
void B::get()
{
    cout<<"GET AAAAAAA"<<endl;
}

#else
void B::get()
{
    cout<<"GET BBBBBB"<<endl;
}
#endif
