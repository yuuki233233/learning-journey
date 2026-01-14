#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	virtual void func() { cout << "A" << endl; }
};

class B : public A // 派生类B继承基类A
{
public:
	virtual void func() { cout << "B" << endl; } // 符合重写规则：虚函数+返回值/函数名/参数列表一致
};

void test(A* a) // 基类指针作为函数参数
{
	a->func();
}

int main()
{
	A a;
	B b;
	test(&a); // 传入基类对象地址，调用A::func
	test(&b); // 传入派生类对象地址，调用B::func
	return 0;
}