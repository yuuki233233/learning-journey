#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int a = 10;

	//编译报错：“ra”必须初始化引用
	//int& b;

	//正确引用
	int& b = a;

	int c = 20;
	//这里并非让b引用c，因为C++引用不能改变指向
	//这里是一个赋值
	b = c;

	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;

	return 0;
}