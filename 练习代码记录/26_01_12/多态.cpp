#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class A
//{
//public:
//	virtual void func() { cout << "A" << endl; }
//};
//
//class B : public A // 派生类B继承基类A
//{
//public:
//	virtual void func() { cout << "B" << endl; } // 带上虚函数，返回类型、函数名相同
//};
//
//void test(A* a) // 基类的指针或引用
//{
//	a->func();
//}
//
//int main()
//{
//	A a;
//	B b;
//	test(&a); // 函数是基类的指针传引用 - 函数是基类的引用则传变量
//	test(&b); // 函数是基类的指针传引用 - 函数是基类的引用则传变量
//
//	return 0;
//}
//
//
//class Animal
//{
//public:
//	virtual void talk() const
//	{ }
//};
//
//class Cat : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		cout << "miao~" << endl; // 带上虚函数，返回类型、函数名相同
//	}
//};
//
//class Dog : public Animal
//{
//public:
//	virtual void talk() const
//	{
//		cout << "wang~" << endl; // 带上虚函数，返回类型、函数名相同
//	}
//};
//
//void func(Animal* a) // 基类的指针或引用
//{
//	a->talk();
//}
//
//int main()
//{
//	Cat cat;
//	Dog dog;
//	func(&cat); // 函数是基类的指针传引用 - 函数是基类的引用则传变量
//	func(&dog); // 函数是基类的指针传引用 - 函数是基类的引用则传变量
//
//	return 0;
//}


//class A
//{
//public:
//	virtual void func(int val = 1) { cout << "A->" << val << endl; }
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { cout << "B->" << val << endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//
//	return 0;
//}


//————————————————————————————————————————协变

//class A {}; // 基类
//class B : public A {}; // 派生类继承基类
//
//class Animal
//{
//public:
//	virtual A* func()
//	{
//		return nullptr; // 虚函数必须返回一个值
//	}
//};
//
//class Cat : public Animal
//{
//public:
//	virtual B* func()
//	{
//		cout << "miao~" << endl;
//		return nullptr; // 虚函数必须返回一个值
//	}
//};
//
//class Dog : public Animal
//{
//public:
//	virtual B* func()
//	{
//		cout << "wan~" << endl;
//		return nullptr; // 虚函数必须返回一个值
//	}
//};
//
//void test(Animal* a) // 基类的指针或引用
//{
//	a->func();
//}
//
//int main()
//{
//	Cat cat;
//	Dog dog;
//
//	test(&cat); // 引用
//	test(&dog); // 引用
//
//	return 0;
//}


//————————————————————————————————析构函数

//class A
//{
//public:
//	virtual ~A() // 基类中需将A的析构写成虚函数
//	{
//		cout << "~A" << endl;
//	}
//};
//
//class B : public A
//{
//	~B()
//	{
//		cout << "~B()->delete:" << _p << endl;
//		delete _p;
//	}
//
//protected:
//	int* _p;
//};
//
//int main()
//{
//	A* p1 = new A;
//	A* p2 = new B;
//
//	delete p1;
//	delete p2;
//
//	return 0;
//}


//——————————————————————————————————override和final

//class Car
//{
//public:
//	virtual void Dirve()
//	{ }
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Dirve() override
//	{
//		cout << "Benz" << endl;
//	}
//};
//
//class BMW : public Car
//{
//public:
//	void Dirve() override
//	{
//		cout << "BWM" << endl;
//	}
//};
//
//void func(Car* c)
//{
//	c->Dirve();
//}
//
//int main()
//{
//	Benz b1;
//	BMW b2;
//
//	func(&b1);
//	func(&b2);
//
//	return 0;
//}


//class Car
//{
//public:
//	virtual void Dirve()
//	{
//		cout << "Dirve" << endl;
//	}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz" << endl; }
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive() { cout << "BMW" << endl; }
//};
//
//void func(Car* c)
//{
//	c->Dirve();
//}
//
//int main()
//{
//	Benz b1;
//	func(&b1);
//
//	BMW b2;
//	func(&b2);
//
//	return 0;
//}

//————————————————————————————纯虚函数

class Animal
{
public:
	virtual void a() = 0; // 纯虚函数写法(类似于创建，之后要初始化)
};

class Cat :public Animal
{
public:
	virtual void a()
	{
		cout << "miao~" << endl;
	}
};

class Dog :public Animal
{
public:
	virtual void a()
	{
		cout << "wang~" << endl;
	}
};

int main()
{
	// error：无法实例化抽象类
	//Animal animal;

	Animal* pCat = new Cat;
	pCat->a();

	Animal* pDog = new Dog;
	pDog->a();

	return 0;
}