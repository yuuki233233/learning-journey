#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void Swap(int& rx, int& ry)
{
	int tmp = rx;
	rx = ry;
	ry = tmp;
}

int main()
{
	int x = 3, y = 6;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	Swap(x, y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	return 0;
}