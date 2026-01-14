#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student; // 前向声明

class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name = "yuuki";
};

class Student : public Person
{
public:
	friend void Display(const Person& p, const Student& s); // 重新声明友元
protected:
	int _stuid = 1001;
};

// 友元函数：可访问Person和Student的保护成员
void Display(const Person& p, const Student& s) {
	cout << p._name << endl;
	cout << s._stuid << endl;
}

int main()
{
	Person p;
	Student s;
	Display(p, s); // 输出：yuuki → 1001
	return 0;
}