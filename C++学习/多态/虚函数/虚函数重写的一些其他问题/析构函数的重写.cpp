#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	virtual ~A() // 基类析构函数设为虚函数
	{
		cout << "~A" << endl;
	}
};

class B : public A
{
public:
	~B() // 自动与基类析构函数构成重写
	{
		cout << "~B()->delete:" << _p << endl;
		delete _p;
	}

protected:
	int* _p = new int(10); // 动态分配内存
};

int main()
{
	A* p1 = new A;
	A* p2 = new B;

	delete p1; // 调用A::~A
	delete p2; // 调用B::~B + A::~A，避免内存泄漏
	return 0;
}