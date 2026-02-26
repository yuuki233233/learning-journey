#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
protected:
	int _b = 1;
	char _ch = 'x';
}

int main()
{
	Base b;
	cout << sizeof(b) << endl;

	return 0;
}