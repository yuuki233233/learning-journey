#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void talk() const
	{
	}
};

class Cat : public Animal
{
public:
	virtual void talk() const
	{
		cout << "miao~" << endl;
	}
};

class Dog : public Animal
{
public:
	virtual void talk() const
	{
		cout << "wang~" << endl;
	}
};

void func(Animal* a) // 基类指针作为函数参数
{
	a->talk();
}

int main()
{
	Cat cat;
	Dog dog;
	func(&cat); // 调用Cat::talk，输出miao~
	func(&dog); // 调用Dog::talk，输出wang~
	return 0;
}