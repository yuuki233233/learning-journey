#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
    Person(const char* name = "yuuki") : _name(name) {}
    // 基类拷贝构造
    Person(const Person& p) : _name(p._name) {
        cout << "Person拷贝构造" << endl;
    }
    // 基类赋值重载
    Person& operator=(const Person& p) {
        if (this != &p) _name = p._name;
        cout << "Person赋值重载" << endl;
        return *this;
    }
protected:
    string _name;
};

class Student : public Person
{
public:
    // 派生类拷贝构造
    Student(const Student& s)
        : Person(s) // 拷贝基类部分
        , _stuid(s._stuid)
    {
        cout << "Student拷贝构造" << endl;
    }
    // 派生类赋值重载
    Student& operator=(const Student& s) {
        if (this != &s) {
            Person::operator=(s); // 调用基类赋值重载
            _stuid = s._stuid;
        }
        cout << "Student赋值重载" << endl;
        return *this;
    }
protected:
    int _stuid = 1001;
};

int main()
{
    Student s1;
    Student s2 = s1; // 拷贝构造：Person拷贝构造 → Student拷贝构造
    Student s3;
    s3 = s1; // 赋值重载：Person赋值重载 → Student赋值重载
    return 0;
}