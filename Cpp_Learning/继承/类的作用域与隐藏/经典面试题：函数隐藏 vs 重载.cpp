#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	void func() { cout << "func()" << endl; }
};

class B : public A
{
public:
	void func(int i) { cout << "func(int i): " << i << endl; }
};

int main()
{
	B b;
	b.func(10); // 正常调用B::func(int)
	// b.func(); // 报错！A::func()被B::func(int)隐藏，无法直接访问
	b.A::func(); // 正确：显式访问基类被隐藏的函数
	return 0;
}