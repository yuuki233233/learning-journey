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

void calc(int(*ps)(int, int))
{
	printf("请输入两个整数\n");
	int x = 0, y = 0, z = 0;
	scanf("%d%d", &x, &y);
	z = ps(x, y);
	printf("%d\n", z);

}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			calc(add);
			break;
		case 2:
			calc(sub);
			break;
		case 3:
			calc(mul);
			break;
		case 4:
			calc(div);
			break;
		case 0:
			printf("退出计算器\n");
			break;
		default:
			printf("输入错误!请重新选择\n");
		}
	} while (input);
	return 0;
}