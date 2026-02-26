#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
T Add(const T& x, const T& y)
{
    return x + y;
}

int main()
{
    int a = 10;
    double c = 1.5;
    Add<int>(a, c);    // 显式指定T为int，将c隐式转换为int
    Add<double>(a, c); // 显式指定T为double，将a隐式转换为double
    return 0;
}

template<class T>
T Add(const T& x, const T& y)
{
	return x + y;
}

int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.1, d2 = 20.2;
	Add(a1, a2);
	Add(d1, d2);

	// 显示实例化
	cout << Add<int>(a1, d1) << endl;
	cout << Add<double>(a1, d1) << endl;

	//cout << Add(a1, d1) << endl;
	//double* p1 = func1<double>(10);

	return 0;
}
