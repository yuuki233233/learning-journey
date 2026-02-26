#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void f(int a, char b)
{
	cout << "f(int a, char b)" << endl;
}

void f(char b, int a)
{
	cout << "f(char b, int a)" << endl;
}

int main()
{
	f(1, 'a'); //f(int a, char b)
	f('a', 1); //f(char b, int a)

	return 0;
}