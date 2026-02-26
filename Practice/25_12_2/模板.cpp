#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////交换模板
//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//
//	cout << "a1=" << a1 << "\t";
//	cout << "a2=" << a2 << endl;
//
//	cout << "d1=" << d1 << "\t";
//	cout << "d2=" << d2 << endl << endl;
//
//	Swap(a1, a2);
//	Swap(d1, d2);
//
//	cout << "a1=" << a1 << "\t";
//	cout << "a2=" << a2 << endl;
//
//	cout << "d1=" << d1 << "\t";
//	cout << "d2=" << d2 << endl << endl;
//
//	return 0;
// }


//-----------------------------------------------------
//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//
//template<class T1, class T2>
//T1 Add(const T1& x, const T2& y)
//{
//	return x + y;
//}
//
//template<class T>
//T* func1(int n)
//{
//	return new T[n];
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.2;
//	Add(a1, a2);
//	Add(d1, d2);
//
//	// 推导实例化
//	cout << Add(a1, (int)d1) << endl;
//	cout << Add((double)a1, d1) << endl;
//
//	// 显示实例化
//	cout << Add<int>(a1, d1) << endl;
//	cout << Add<double>(a1, d1) << endl;
//
//	cout << Add(a1, d1) << endl;
//
//	double* p1 = func1<double>(10);
//
//	return 0;
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}


//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}

//-----------------------------------------------------
//template<class T>
//class Stack
//{
//public:
//	Stack(int n = 4)
//		:_arr(new T[n])
//		,_size(0)
//		,_capacity(n)
//	{ }
//
//	~Stack()
//	{
//		delete[] _arr;
//		_arr = nullptr;
//		_size = _capacity = 0;
//	}
//
//	void Push(const T& x);
//
//	void func(const T& x)
//	{
//		++x;
//	}
//
//private:
//	T* _arr;
//	int _size;
//	int _capacity;
//};
//
//// 模版不建议声明和定义分离到两个文件.h 和.cpp会出现链接错误
//template<class T>
//void Stack<T>::Push(const T& x)
//{
//	if (_size == _capacity)
//	{
//		//C++中栈的内存申请方式
//		T* tmp = new T[_capacity * 2];
//		memcpy(tmp, _arr, sizeof(T) * _size);
//		delete[] _arr;
//
//		_arr = tmp;
//		_capacity *= 2;
//	}
//
//	_arr[_size++] = x;
//}
//
//int main()
//{
//	Stack<int> st1;
//	st1.Push(1);
//	st1.Push(1);
//	st1.Push(1);
//	st1.Push(1);
//
//	Stack<double> st2;
//	st2.Push(1.1);
//	st2.Push(1.1);
//	st2.Push(1.1);
//	st2.Push(1.1);
//
//	return 0;
//}

#include<string>

int main()
{
	string s1;
	string s2("hello world");
	string s3(s2);
	cout << s2 << endl;
	cout << s3 << endl;

	cin >> s1;
	cout << s1 << endl;

	return 0;
}
