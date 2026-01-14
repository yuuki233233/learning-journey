#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	static int _count; // 静态成员：统计对象数量
};
int Person::_count = 0; // 静态成员类外初始化

class Student : public Person {};
class Teacher : public Person {};

int main()
{
	Person::_count++;
	Student::_count++;
	Teacher::_count++;
	cout << Person::_count << endl; // 输出：3（三者共享_count）
	return 0;
}