#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int sum_factorial(int n)
{
	int a = 0;
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
		a += ret;
	}
	return a;
}

void test()
{
	int n = 0;
	scanf("%d", &n);
	int sum =sum_factorial(n);
	printf("%d", sum);
}

int main()
{
	test();
	return 0;
}