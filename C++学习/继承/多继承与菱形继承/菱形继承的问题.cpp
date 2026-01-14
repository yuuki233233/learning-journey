#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person { public: string _name; }; // 基类
					 class Student : public Person { public: int _stuid; }; // 派生类1
					 class Teacher : public Person { public: string _title; }; // 派生类2
					 class Assistant : public Student, public Teacher { public: int _id; }; // 菱形顶点

					 int main()
					 {
						 Assistant a;
						 // a._name = "Tom"; // 报错！二义性：_name来自Student还是Teacher？
						 a.Student::_name = "Tom"; // 显式指定，解决二义性（但数据冗余仍存在）
						 a.Teacher::_name = "Jerry";
						 return 0;
					 }