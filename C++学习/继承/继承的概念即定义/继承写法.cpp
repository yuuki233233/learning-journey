#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 基类：封装学生/教师的公共成员
class Person
{
public:
    void identity() {
        cout << "身份验证：" << _name << endl;
    }
protected:
    string _name = "yuuki";
    string _address;
    string _tel;
    int _age = 18;
};

// 派生类：学生（public继承Person）
class Student : public Person
{
public:
    void study() { /* 学习逻辑 */ }
protected:
    int _stuid; // 独有成员
};

// 派生类：教师（public继承Person）
class Teacher : public Person
{
public:
    void teaching() { /* 授课逻辑 */ }
protected:
    string _title; // 独有成员
};

int main()
{
    Student s;
    Teacher t;
    s.identity(); // 复用基类的identity方法
    t.identity(); // 复用基类的identity方法
    return 0;
}