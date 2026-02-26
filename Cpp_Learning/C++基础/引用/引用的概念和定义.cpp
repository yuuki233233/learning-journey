#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int a = 0;

	// 引用：b和c是a的别名
	int& b = a;
	int& c = a;

	// 也可以给别名b取别名，d相当于还是a的别名
	int& d = b;

	cout << "a = " << a << " b = " << b << endl;
	cout << "c = " << c << " d = " << d << endl;

	d++;

	cout << "&a = " << &a << endl;
	cout << "&b = " << &b << endl;
	cout << "&c = " << &c << endl;
	cout << "&d = " << &d << endl;

	cout << "a = " << a << " b = " << b << endl;
	cout << "c = " << c << " d = " << d << endl;

	return 0;
}