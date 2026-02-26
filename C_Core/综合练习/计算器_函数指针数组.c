#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void menu()
{
	printf("1. add   2. sub\n");
	printf("3. mul   4. div\n");
	printf("0. exit        \n");
}

int add(int x, int y)
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

int div(int x, int y)
{
	return x / y;
}

int main()
{
	int input = 0;
	int x = 0, y = 0, z = 0;
	int(*parr[5])(int, int) = { 0, add,sub,mul,div };
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);

		if (input >= 1 && input <= 4)
		{
			printf("请输入两个整数:");
			scanf("%d%d", &x, &y);
			z = parr[input](x, y);
			printf("%d\n", z);
		}
		else if (input == 0)
		{
			printf("退出计算器\n");
		}
		else
		{
			printf("请重新输入\n");
		}

	} while (input);
	return 0;
}