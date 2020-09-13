/*
 * @Author: Liu Weilong 
 * @Date: 2020-08-31 10:03:38 
 * @Last Modified by: Liu Weilong
 * @Last Modified time: 2020-09-01 12:57:43
 */

#pragma once

#include <iostream>
#include <functional>
#include <memory>

namespace LwlSLAM
{
    template <typename TypeInput, typename TypeOutput>
    class DownSamplingInterface
    {
        public:
        
        DownSamplingInterface(std::function<std::shared_ptr<TypeOutput>(const TypeInput &)> typeTransFunction){
        typeTransFunction_ = typeTransFunction;
        }

        std::shared_ptr<TypeOutput> downSample(const TypeInput & msg) const  = 0;

        std::function<std::shared_ptr<TypeOutput>(const TypeInput &)> typeTransFunction_;
        
    };
    
}