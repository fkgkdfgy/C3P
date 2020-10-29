/*
 * @Author: Liu Weilong
 * @Date: 2020-10-27 16:39:51
 * @LastEditors: Liu Weilong 
 * @LastEditTime: 2020-10-28 14:26:20
 * @FilePath: /C3P/STL算法剖析/1. Preparation/template_exercise3.cpp
 * @Description: 
 *              1. 虚函数和函数模板能否进行套用？ 不能
 *                 为什么虚函数不能是模板函数？
 *                 编译器在编译类的定义的时候就必须确定该类的虚表大小.
 *                 模板只有在运行调用时才能确认其大小, 两者冲突. 结果显而易见
 *              2. 模板拷贝构造函数 
 *                 结合类模板进行使用
 * 
 * 
 */

template<class T>
class tmp
{
	public:
		tmp() : x(0) {}
		template<class U>
			tmp(const tmp<U>& t)
			{
				x = t.x;
			}
	private:
		T x;
};

int main()
{
	tmp<int> t1;
	tmp<char> t2;
	t1 = t2;

}
