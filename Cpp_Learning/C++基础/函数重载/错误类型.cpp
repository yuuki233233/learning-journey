#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 下⾯两个函数构成重载
void Func()
{
	cout << "Func()" << endl;
}

//缺省参数 + 函数重载
void Func(int a = 10)
{
	cout << "Func(int a = 10)" << endl;
}

int main()
{
	// f()但是调用时，会报错，存在歧义，编译器不知道调用谁
	//Func();

	//调用Func(int a = 10)
	Func(1);
	return 0;
}