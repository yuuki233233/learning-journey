#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

double divide(double x, double y)
{
	if (y == 0)
	{
		printf("错误:除数不能为零!\n");
		return -1;
	}
	return x / y;
}
int main()
{
	int a = 0, b = 0;
	printf("请输入a与b的值:> ");
	scanf("%d %d", &a, &b);

	printf("相加:>%d\n", Add(a, b));
	printf("相减:>%d\n", sub(a, b));
	printf("相乘:>%d\n", mul(a, b));
	printf("相除:>%.2lf\n", divide(a, b));
	return 0;
}