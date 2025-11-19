#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n = 0, m = 0;
	printf("请分别输入数组A与数组B的个数\n");
	int arrA[1000], arrB[1000];
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		printf("数组A的第%d值为:> ",i + 1);
		scanf("%d", &arrA[i]);
	}

	for (int i = 0; i < m; i++)
	{
		printf("数组B的第%d值为:> ", i + 1);
		scanf("%d", &arrB[i]);
	}

	printf("\n数组A的值为:> ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arrA[i]);
	}

	printf("\n数组B的值为:> ");
	for (int i = 0; i < m; i++)
	{
		printf("%d ", arrB[i]);
	}
	printf("\n");

	printf("合并后的数组为:> ");
	int a = 0, b = 0;
	while (a < n && b < m)
	{
		if (arrA[a] < arrB[b])
		{
			printf("%d ", arrA[a]);
			a++;
		}
		else
		{
			printf("%d ", arrB[b]);
			b++;
		}
	}

	while (a < n)
	{
		printf("%d ", arrA[a]);
		a++;
	}

	while (b < m)
	{
		printf("%d ", arrB[b]);
		b++;
	}
	return 0;
}