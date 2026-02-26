#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

inline int Add(int x, int y)
{
	int ret = x + y;
	ret += 1;
	ret += 1;
	ret += 1;

	return ret; //6
}

int main()
{
	//可以通过汇编观察程序是否展开
	//有call Add语句就是没有展开
	int ret = Add(1, 2);
	cout << Add(1, 2) * 5 << endl; //30

	return 0;
}