#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Add(int a, int b, int* sub, int* mul, int* div)
{
	*sub = a - b;
	*mul = a * b;
	*div = a / b;
	return a + b;
}

int main()
{
	int a = 6;
	int b = 3;
	int sub = 0, mul = 0, div = 0;

	int sum = Add(a, b, &sub, &mul, &div);
	printf("%d %d %d %d", sum, sub, mul, div);
	return 0;
}