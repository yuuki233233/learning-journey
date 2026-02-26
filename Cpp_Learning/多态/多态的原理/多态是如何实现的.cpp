#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	virtual void BuyTicket() { cout << "全价" << endl; }
private:
	string _name;
};

class Student : public Person
{
public:
	virtual void BuyTicket() { cout << "打折" << endl; }
private:
	string _id;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket() { cout << "优先" << endl; }
private:
	string _codename;
};

void Func(Person* ptr)
{
	// 动态绑定：运行时根据ptr指向的对象，从虚表中找BuyTicket的地址
	ptr->BuyTicket();
}

int main()
{
	Person ps;
	Func(&ps); // 调用Person::BuyTicket（基类虚表）

	Student d;
	Func(&d); // 调用Student::BuyTicket（派生类虚表，覆盖基类地址）

	Soldier s;
	Func(&s); // 调用Soldier::BuyTicket（派生类虚表，覆盖基类地址）

	return 0;
}