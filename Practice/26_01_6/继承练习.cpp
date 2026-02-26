#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	A(const char* name = "YUUKI")
		:_name(name)
	{
		cout << "A()" << endl;
	}

	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
		if (this != &a)
			_name = a._name;
	}

	~A()
	{ }
protected:
	string _name;
};

class B : public A
{
public:
    B(const char* name, int age, const char* address)
        :A(name)
        ,_age(age)
        ,_address(address)
    {
        cout << "B()" << endl;
    }

    ~B()
    {};
protected:
    int _age = 18;
    string _address = "德国柏林";
};

int main()
{
	B b1("YUUKI", 18, "广东佛山");

	B b2(b1);

	B b3("YUUKI", 23, "德国");

	b1 = b3;

	return 0;
}