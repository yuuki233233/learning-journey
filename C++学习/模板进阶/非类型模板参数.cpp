#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

// 1. 浮点数、类对象以及字符串是不允许作为非类型模板参数的。
// 2. 非类型的模板参数必须在编译期就能确认结果。
namespace yuuki
{
	// 定义一个模板类型的静态数组
	template<class T, size_t N = 10>
	class array
	{
	public:
		T& operator[](size_t index)
		{
			assert(index < N);
			return _array[index];
		}

		const T& operator[](size_t index) const
		{
			assert(index < N);
			return _array[index];
		}

		size_t size()
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

	private:
		T* _array[N]; // 用非类型模板确定大小
		size_t _size; // 静态数组的大小
	};
}