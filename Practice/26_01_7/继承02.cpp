#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// ---------------------------？？？？？？？？？？？？？
//class Base // final
//{
//public:
//	void func() { cout << "Base::func()" << endl; }
//protected:
//	int a = 1;
//private:
//	// C++98的方法
//	//Base() {};
//};
//
//class Derive : public Base
//{
//	void func2() { cout << "Derive::func4" << endl; }
//protected:
//	int b = 2;
//};
//
//int main()
//{
//	Base b;
//	b.func();
//
//	Derive d;
//	d.func();
//
//	return 0;
//}


// -----------------------？？？？？？？？？？

//// 为了节省时间，编译器是向上找的。所以要把派生类的匿名放上面，不然找不到Student
//class Student;
//
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name = "yuuki";
//};
//
//class Student : public Person
//{
//	// 解决方案：也要在派生类中写入友元函数
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuid = 18;
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl; 
//	cout << s._stuid << endl;
//}
//
//int main()
//{
//	Person p;
//	Student s;
//
//	// 因为Display是Person的友元，所以可以访问p
//	// Display变成Student的友元就可以访问s
//	Display(p, s);
//
//	return 0;
//}


// -------------------------？？？？？？？？？？？？？
class Person
{
public:
	string _name;
	static int _count;
};

int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuid;
};

int main()
{
	Person p;
	Student s;

	// 这里的运行结果可以看到非静态成员_name的地址是不一样的
	// 说明派生类继承下来了，基类和派生类各有一份
	cout << &p._name << endl; // 00000019F479F608
	cout << &s._name << endl; // 00000019F479F648

	// 这里的运行结果可以看到静态成员_count的地址是一样的
	// 说明派生类和基类共同用一份静态成员
	cout << &p._count << endl; // 00007FF6F6C334D0
	cout << &p._count << endl; // 00007FF6F6C334D0

	// 公有情况下，基类、派生类指定类域都可以访问静态成员
	cout << Person::_count << endl;  // 0
	cout << Student::_count << endl; // 0

	return 0;
}