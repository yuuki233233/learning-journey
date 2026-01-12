#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket() { cout << "全价" << endl; };
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "半价" << endl; };
//};
//
//void Func(Person* ptr)
//{
//	// 这里可以看到虽然都是Person指针Ptr在调用BuyTicket
//	// 但是跟ptr没关系，而是由ptr指向的额对象决定的
//	ptr->BuyTicket();
//}
//
//
//class animal
//{
//public:
//	virtual void a() { cout << "a" << endl; };
//};
//
//class cat : public animal
//{
//public:
//	virtual void a() { cout << "miao~" << endl; };
//};
//
//class dog : public animal 
//{
//public:
//	virtual void a() { cout << "wang~" << endl; };
//};
//
//void test(animal* a)
//{
//	a->a();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//
//	Func(&p);
//	Func(&s);
//
//	cat c;
//	dog d;
//
//	test(&c);
//	test(&d);
//
//	return 0;
//}