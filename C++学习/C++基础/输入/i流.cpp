#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	double b = 0.1;
	char c = 'x';

	cout << a << " " << b << " " << c << endl;
	std::cout << a << " " << b << " " << c << std::endl;

	// 可以⾃动识别变量的类型
	cin >> a >> b >> c;
	cout << a << " " << b << " " << c << endl;
	return 0;
}
