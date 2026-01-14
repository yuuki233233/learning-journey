#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:

	/*默认构造第一种情况*/

	//// 默认构造(有初始化)
	//Person(const char* name = "YUUKI")
	//	:_name(name)
	//{
	//	cout << "Person()" << endl;
	//}


	/*默认构造第二种情况,需要子类帮助*/

	// 默认构造(无初始化)
	Person(const char* name)
		:_name(name)
	{
		cout << "Person()" << endl;
	}

	// 拷贝构造
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	// 赋值运算符重载
	Person& operator=(const Person& p)
	{
		cout << "Person& operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	// 析构函数
	~Person()
	{
		cout << "~Person" << endl;
	}
protected:
	string _name;
};

class Student : public Person
{
public:
	// 默认生成的构造函数的行为
	// 1、内置类型->不确定
	// 2、自定义类型->调用默认构造
	// 3、继承父类成员看做一个整体对象，调用父类的默认构造

	// 子类默认构造函数,
	Student(const char* name, int num, const char* addrss)
		// 将Person看做一个整体
		:Person(name)// 错误写法  ->  :_name(name)
		, _num(num)
		, _addrss(addrss)
	{
	}

	// 报错：因为父类和子类改成隐藏，因重复调用子类，导致栈溢出
	/*Student& operator=(const Student& s)
	{
		operator=(s);
	}*/

	~Student()
	{
		// 错误写法: ~Person();
		// 原因:
		// 1. 语法定义，先子类后父类。如果写成上面，就成了先父类再子类
		// 2. 子类析构完后，编译器会自动掉用父类的析构
	}
protected:
	// 无缺省值
	/*int _num;
	string _addrss;*/

	// 有缺省值
	int _num = 18;
	string _addrss = "广东佛山市"; // 自定义类型会调用自动生成的构造
};

int main()
{
	Student s1("yuuki", 18, "广东佛山市");
	Student s2(s1);

	Student s3("YUUKI", 28, "广东深圳市");
	s1 = s3; // 不需要在子类写赋值运算符,只需要父类里写即可

	return 0;
}