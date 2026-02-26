#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person // 基类
{
protected:
	string _name = "yuuki";
	int _num = 18; // 身份证号
};

class Student : public Person // 派生类
{
public:
	void Print() {
		cout << "姓名：" << _name << endl; // 复用基类_name
		cout << "学生编号：" << _num << endl; // 访问派生类_num（隐藏基类）
		cout << "身份证号：" << Person::_num << endl; // 访问被隐藏的基类_num
	}
protected:
	int _num = 999; // 学生编号（与基类_num同名）
};

int main()
{
	Student s;
	s.Print();
	return 0;
}