#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char a = 10;
	printf("修改前,变量a的值:%d\n", a);

	char* p = &a;
	*p = 20;
	printf("修改后,变量a的值:%d\n", a);

	return 0;
}
