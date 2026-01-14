#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Car
{
public:
	virtual void Drive() // 注意：原代码笔误为Dirve，修正为Drive
	{
	}
};

class Benz : public Car
{
public:
	virtual void Drive() override // 检测是否重写Car::Drive，写错则报错
	{
		cout << "Benz" << endl;
	}
};

class BMW : public Car
{
public:
	void Drive() override // 即使不加virtual，override也会检测重写规则
	{
		cout << "BMW" << endl;
	}
};

void func(Car* c)
{
	c->Drive();
}

int main()
{
	Benz b1;
	BMW b2;
	func(&b1); // 输出Benz
	func(&b2); // 输出BMW
	return 0;
}