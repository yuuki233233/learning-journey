#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	~Person() { cout << "Person析构" << endl; }
};

class Student : public Person
{
public:
	~Student() { cout << "Student析构" << endl; }
};

int main()
{
	Student s; // 析构顺序：Student析构 → Person析构
	return 0;
}