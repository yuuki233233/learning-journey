#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//定义int类型的变量
	int num = 10;

	//定义一个指针变量p
	//并将变量num的地址赋值给指针变量p,使用指针变量p指向变量num
	int* p = &num;

	printf("%d\n", *p);
	return 0;