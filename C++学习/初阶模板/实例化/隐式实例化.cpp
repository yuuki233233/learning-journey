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
	int a1 = 10, a2 = 20;
	double d1 = 10.1, d2 = 20.2;
	Add(a1, a2);  //推导出T为int
	Add(d1, d2);  //推导出T为double

	/*该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
Add(a1, d1);
*/
// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化编译器无法确定此处到底该将T确定为int 或者 double类型而报错

	// 推导实例化
	cout << Add(a1, (int)d1) << endl;
	cout << Add((double)a1, d1) << endl;

	return 0;
}