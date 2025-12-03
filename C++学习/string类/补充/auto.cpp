#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int func1()
{
	return 10;
}

int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = func1();


	//auto必须初始化
	//auto e;


	//识别auto类型
	cout << typeid(b).name() << endl; //int
	cout << typeid(c).name() << endl; //char
	cout << typeid(d).name() << endl; //int

	return 0;
}