#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("请输入正方形的大小:> ");
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == 0 || i == n - 1) || (j == 0 || j == n - 1))
			{
				printf("* ");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	return 0;
}