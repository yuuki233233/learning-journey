#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	void Print() { cout << _name << endl; } // public成员
protected:
	string _name; // protected成员
private:
	int _age; // private成员
};

// public继承（推荐）
class Student : public Person
{
public:
	void Test() {
		Print(); // 可访问（基类public→派生类public）
		_name = "Tom"; // 可访问（基类protected→派生类protected）
		// _age = 20; // 不可访问（基类private）
	}
protected:
	int _stuid;
};