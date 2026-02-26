#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person { public: string _name; };
					 class Student : virtual public Person { public: int _stuid; }; // 虚继承
					 class Teacher : virtual public Person { public: string _title; }; // 虚继承
					 class Assistant : public Student, public Teacher { public: int _id; };

					 int main()
					 {
						 Assistant a;
						 a._name = "Tom"; // 正常访问（仅一份_name）
						 return 0;
					 }