/*
 * @Author: Liu Weilong 
 * @Date: 2020-09-04 10:40:59 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-04 10:44:38
 */

#include <iostream>

#include <bitset>

using namespace std;

int main(int argc, const char** argv) {
    using KeyType = std::bitset<32*2>;

    int32_t x = -25;
    int32_t y = -49;

    KeyType x_bit = static_cast<uint32_t>(x);
    KeyType y_bit = static_cast<uint32_t>(y);

    KeyType result = (x_bit<<32|y_bit);

    cout<< x_bit.to_string()<<endl;
    cout<< y_bit.to_string()<<endl;
    cout<< result.to_string()<<endl;




    return 0;
}