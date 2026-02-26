#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
    // 基类无默认构造（必须传参）
    Person(const char* name) : _name(name) {
        cout << "Person构造" << endl;
    }
protected:
    string _name;
};

class Student : public Person
{
public:
    // 派生类构造：先调用Person(name)，再初始化_stuid
    Student(const char* name, int stuid)
        : Person(name) // 显式调用基类构造（必须）
        , _stuid(stuid)
    {
        cout << "Student构造" << endl;
    }
protected:
    int _stuid;
};

int main()
{
    Student s("Tom", 1001); // 输出：Person构造 → Student构造
    return 0;
}