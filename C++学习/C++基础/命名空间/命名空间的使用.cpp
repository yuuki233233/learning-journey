#define _CRT_SECURE_NO_WARNINGS
// 指定命名空间访问
#include<stdio.h>
namespace N
{
	int a = 10;
	int b = 20;
}

int main()
{
	printf("%d\n", N::a); //10
	return 0;
}