#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 前置声明，都则A的友元函数声明编译器不认识B
class B;

class A
{
	// 友元声明
	friend class B;
private:
	int _a1 = 1;
	int _a2 = 2;
};

class B
{
public:
	void Print(const A& aa)
	{
		cout << aa._a1 << endl;
		cout << _b1 << endl;
	}

private:
	int _b1 = 3;
	int _b2 = 4;
};

int main()
{
	A a;
	B b;

	b.Print(a);

	return 0;
}