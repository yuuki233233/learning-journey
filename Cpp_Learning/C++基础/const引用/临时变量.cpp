#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


int main()
{
	int a = 10;

	const int& ra = 30;

	//编译报错：无法从int转换为int&
	//int& rb = a * 3;
	const int& rb = a * 3;//因为a*3要创建临时对象

	double d = 12.34;
	//编译报错：无法从int转换为int&
	//int& rd = d;
	const int& rd = d;//因为类型的转变，需要创建临时变量

	return 0;
}