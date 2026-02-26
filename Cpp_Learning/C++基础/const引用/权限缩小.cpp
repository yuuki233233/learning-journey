#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	const int a = 10;
	// 编译报错：error C2440: “初始化”: 无法从“const int”转换为“int &”
	// 这里的引用是对a访问权限的放大
	//int& ra = a;
	const int& ra = a;

	//编译器报错：不能给常量赋值
	//ra++;

	//这里的引用时对b访问权限的缩小
	int b = 20;
	const int& rb = b;

	//编译报错：不能给常量赋值
	//rb++;

	return 0;
}