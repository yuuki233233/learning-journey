#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void f(int x)
{
	cout << "f(int x)" << endl;
}

void f(int* ptr)
{
	cout << "f(int* ptr)" << endl;
}

int main()
{
	f(0);//f(int x)

	//本想通过f(NULL)调用指针版本的f(int*)函数，但是由于NULL被定义成0，
	f(NULL);//f(int x)

	f((int*)NULL);//f(int* ptr)

	//error:2个重载中没有一个可以转换所有参数类型
	//f((void*)NULL);

	f(nullptr); //f(int* ptr)
	return 0;
}
