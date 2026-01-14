#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 学生类
class Student
{
public:
	void identity() { /* 身份验证逻辑 */ } // 重复
	void study() { /* 学习逻辑 */ }        // 独有
protected:
	string _name; string _address; string _tel; int _age; // 重复
	int _stuid; // 独有
};

// 教师类
class Teacher
{
public:
	void identity() { /* 身份验证逻辑 */ } // 重复
	void teaching() { /* 授课逻辑 */ }     // 独有
protected:
	string _name; string _address; string _tel; int _age; // 重复
	string _title; // 独有
};