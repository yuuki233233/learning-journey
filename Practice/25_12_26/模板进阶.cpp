#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include"Date.h"
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

//template<class T>
//bool my_less(T left, T right)
//{
//	return left < right;
//}
//
//// 模板特化
//template<>
//bool my_less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}


//-----------------------------------------------------
// 正常来说都要加上const和&
template<class T>
bool my_less(const T& left, const T& right)
{
	return left < right;
}

// 普通类型的形参有const，就要特化就要成下面
template<> // const要修饰left而非*，所以要放在*右边，不然报错
bool my_less<Date*>(Date* const & left, Date* const & right)
{
	return *left < *right;
}


//-----------------------------------------------------

// 如果是const类型，就要特化就要成下面
//template<> // const要修饰left而非*，所以要放在*右边，不然报错
//bool my_less<const Date*>(const Date* const& left, const Date* const& right)
//{
//	return *left < *right;
//}

//-----------------------------------------------------

// 函数(编译器先走现成的)
//template<>
//bool my_less(Date* left, Date* right)
//{
//	return *left < *right;
//}

//int main()
//{
//	cout << my_less(1, 2) << endl; // 1
//	
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << my_less(d1, d2) << endl; // 可以比较，结果正确
//
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << my_less(p1, p2) << endl; // 可以比较，结果错误
//
//
//	const Date* p3 = &d1;
//	const Date* p4 = &d2;
//	cout << my_less(p3, p4) << endl; // 可以比较，结果错误
//
//	return 0;
//}


//// 类模板全特化
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl;}
//};
//
//template<>
//class Data<int, char> // 这里指定了类型
//{
//public:
//	Data() { cout << "Data<int, char>" << endl;}
//};
//
//// 类模板半特化
//// 部分特化(将模板参数类列表中的一部分参数特化)
//template<class T>
//class Data<T&, int>
//{
//public:
//	Data() { cout << "Data<T&, int>" << endl;}
//};
//
//// 两个参数偏特化为指针类型
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//};
//
//// 两个参数偏特化为引用类型
//template<class T1, class T2>
//class Data<T1*, T2&>
//{
//public:
//	Data() { cout << "Data<T1*, T2&>" << endl; }
//};
//
//int main()
//{
//	Data<int, int> d1;	// Data<T1, T2>
//	Data<int, char> d2; // Data<int, char>
//	cout << endl;
//
//	Data<char, int> p1;		// Data<T1, T2>
//	Data<double, int> p2;	// Data<T1, T2>
//	cout << endl;
//
//	Data<int*, int*> p3;		// Data<T1*, T2*>
//	Data<double*, short*> p4;	// Data<T1*, T2*>
//	Data<int*, int&> p5;		// Data<T1*, T2&>
//	cout << endl;
//	return 0;
//}


#include<vector>
#include<algorithm>
template<class T>
struct Less
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};

int main()
{
	Date d1(2022, 7, 7);
	Date d2(2022, 7, 6);
	Date d3(2022, 7, 8);

	vector<Date> v1;
	v1.push_back(d1);
	v1.push_back(d2);
	v1.push_back(d3);

	// 可以直接排序，结果是日期升序
	sort(v1.begin(), v1.end(), Less<Date>());

	vector<Date*> v2;
	v2.push_back(&d1);
	v2.push_back(&d2);
	v2.push_back(&d3);

	// 可以直接排序，结果错误日期还不是升序，而v2中放的地址是升序
	// 此处需要在排序过程中，让sort比较v2中存放地址指向的日期对象
	// 但是走Less模板，sort在排序时实际比较的是v2中指针的地址，因此无法达到预期
	sort(v2.begin(), v2.end(), Less<Date*>());

	return 0;
}