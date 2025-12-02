#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class A
{
public:
	void Print()
	{
		cout << _ch << endl;
	}

private:
	char _ch;
	int _i;
};

class B
{
	void Print() {};
};

class C
{
};

int main()
{
	A a;
	B b;
	C c;

	cout << sizeof(a) << endl; //8
	cout << sizeof(b) << endl; //1
	cout << sizeof(c) << endl; //1

	return 0;
}