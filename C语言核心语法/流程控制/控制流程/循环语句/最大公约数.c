#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int input = 0;
	int a = 0, b = 0;
	printf("输入两个整数,可查看最大公约数:");
	scanf("%d%d", &a, &b);

	while (b != 0)
	{
		input++;
		int temp = b;
		b = a % b;
		a = temp;
	}
	printf("最大公约数为%d\n且转化的次数为%d", a, input);
	return 0;
}