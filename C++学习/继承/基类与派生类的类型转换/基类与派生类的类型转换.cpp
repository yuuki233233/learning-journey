#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person // 基类
{
    virtual void func() {} // 虚函数（为dynamic_cast做准备）
protected:
    string _name;
    int _age;
};

class Student : public Person // 派生类
{
public:
    int _stuid;
};

int main()
{
    Student sobj;
    // 1. 派生类对象 → 基类指针/引用（切片）
    Person* pp = &sobj;
    Person& rp = sobj;
    Person pobj = sobj; // 切片赋值

    // 2. 基类对象 → 派生类对象（报错）
    // sobj = pobj; 

    // 3. 基类指针 → 派生类指针（安全场景）
    Student* ps1 = dynamic_cast<Student*>(pp); // pp指向sobj，转换成功
    cout << ps1 << endl; // 非空地址

    // 3. 基类指针 → 派生类指针（不安全场景）
    Person pobj2;
    pp = &pobj2;
    Student* ps2 = dynamic_cast<Student*>(pp); // pp指向基类对象，转换失败
    cout << ps2 << endl; // 空地址

    return 0;
}