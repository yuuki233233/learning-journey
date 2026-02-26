#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A {}; // 基类A
class B : public A {}; // 派生类B继承A

class Animal
{
public:
	virtual A* func()
	{
		return nullptr;
	}
};

class Cat : public Animal
{
public:
	virtual B* func() // 协变：返回值为派生类指针，仍构成重写
	{
		cout << "miao~" << endl;
		return nullptr;
	}
};

class Dog : public Animal
{
public:
	virtual B* func() // 协变：返回值为派生类指针，仍构成重写
	{
		cout << "wang~" << endl;
		return nullptr;
	}
};

void test(Animal* a)
{
	a->func();
}

int main()
{
	Cat cat;
	Dog dog;
	test(&cat); // 输出miao~
	test(&dog); // 输出wang~
	return 0;
}