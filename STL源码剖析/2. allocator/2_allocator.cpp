/*
 * @Author: Liu Weilong
 * @Date: 2020-10-29 09:11:05
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-29 10:14:42
 * @FilePath: /C3P/STL源码剖析/2. allocator/2_allocator.cpp
 * @Description:  学习一下 allocator
 * 
 *                从 gcc::new_allocator 里面可以看到主要是
 *                allocate(size_type n,const void *)进行内存分配
 *                
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyAllocator
{
    public:
    typedef size_t       size_type;
    typedef ptrdiff_t    difference_type;
    typedef T*           pointer;
    typedef const T*     const_pointer;
    typedef T&           reference;
    typedef const T&     const_reference;
    typedef T            value_type;

    MyAllocator() noexcept {}

    MyAllocator(const MyAllocator &) noexcept {}

    // 目前不知道有什么用
    template <typename T1>
    MyAllocator(const MyAllocator<T1> & ) noexcept {}

    // 返回地址
    pointer
    address(reference __x) const noexcept
    { return std::__addressof(__x); }

    const_pointer
    address(const_reference __x) const noexcept
    { return std::__addressof(__x); }

    // 内存分配  传参的void 并没有用到
    pointer
    allocate(size_type n, const void * = static_cast<void *>(0))
    {
        cout<<"here we allocate "<< n <<" * "<<sizeof(T)<<" free space"<<endl;
        return static_cast<pointer>(::operator new(sizeof(T)*n));
    }

    // 摧毁内存
    void 
    deallocate(pointer p,size_type)
    {
        ::operator delete(p);
    }
    
    // 这个是c++ 11之前的版本
    void 
    construct(pointer p,const T&val)
    {::new(static_cast<void *>(p)) T(val);}

    void 
    destroy(pointer p ){p->~T();}
};

class MyStruct
{
    public:
    MyStruct()=default;
    MyStruct(const MyStruct&)noexcept
    {
        // cout<<" copy cotr is called"<<endl;
    }
    int i;
    double d;
    float f;
    
};

int main()
{
    vector<MyStruct,MyAllocator<MyStruct>> temp;

    for(int i =0; i<30;i++)
    {
        temp.push_back(MyStruct());
    }
}