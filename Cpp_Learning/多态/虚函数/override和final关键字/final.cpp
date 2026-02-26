#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Car
{
public:
	virtual void Drive() final // 禁止派生类重写Drive
	{
		cout << "Car::Drive" << endl;
	}
};

class Benz :public Car
{
public:
	// 编译报错：无法重写被final修饰的虚函数Car::Drive
	virtual void Drive() { cout << "Benz" << endl; }
};

int main()
{
	return 0;
}