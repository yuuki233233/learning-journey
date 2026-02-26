#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

int main()
{
	cout << Add(1, 2) << endl;      //3
	cout << Add(1.1, 2.2) << endl;  //3.3
}
