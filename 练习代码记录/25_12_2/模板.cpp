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

template<class T>
T Add(const T& x, const T& y)
{
	return x + y;
}

template<class T1, class T2>
T1 Add(const T1& x, const T2& y)
{
	return x + y;
}


int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.1, d2 = 20.2;
	Add(a1, a2);
	Add(d1, d2);

	// 推导实例化
	cout << Add(a1, (int)d1) << endl;
	cout << Add((double)a1, d1) << endl;

	// 显示实例化
	cout << Add<int>(a1, d1) << endl;
	cout << Add<double>(a1, d1) << endl;

	cout << Add(a1, d1) << endl;


	return 0;
}