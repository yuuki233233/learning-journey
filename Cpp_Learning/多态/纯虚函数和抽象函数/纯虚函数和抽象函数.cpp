#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void talk() = 0; // 纯虚函数，Animal成为抽象类
};

class Cat :public Animal
{
public:
	virtual void talk() override // 重写纯虚函数
	{
		cout << "miao~" << endl;
	}
};

class Dog :public Animal
{
public:
	virtual void talk() override // 重写纯虚函数
	{
		cout << "wang~" << endl;
	}
};

int main()
{
	// Animal animal; // 编译报错：抽象类无法实例化
	Animal* pCat = new Cat;
	pCat->talk(); // 输出miao~

	Animal* pDog = new Dog;
	pDog->talk(); // 输出wang~

	delete pCat;
	delete pDog;
	return 0;
}