#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Add(int a, int b, int* sub, int* mul, int* div)
{
	*sub = a - b;
	*mul = a * b;
	if (b != 0)
	{
		*div = a / b;
	}
	else
	{
		*div = 0;
		printf("除数不能为零!\n");
	}
	return a + b;
}

int main()
{
	printf("输入两个整数并进行加减乘除:>");
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	int sub = 0, mul = 0, div = 0;

	int sum = Add(a, b, &sub, &mul, &div);
	printf("相加为:%d\n", sum);
	printf("相减为:%d\n", sub);
	printf("相乘为:%d\n", mul);
	printf("相除为:%d\n", div);

	return 0;
}