#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void f()
{
	cout << "f()" << endl;
}

void f(int a)
{
	cout << "f(int a)" << endl;
}

int main()
{
	f();   //f()
	f(1);  //f(int a)

	return 0;
}